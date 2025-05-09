#include <iostream>
#include <vector>
#include <memory> // For smart pointers
#include <string>
using namespace std;

class FileSystemComponent {
public:
    virtual void listContents() const = 0;
    virtual int getSize() const = 0;
    virtual ~FileSystemComponent() = default; // Virtual destructor for proper cleanup
};

class File : public FileSystemComponent {
private:
    string name;
    int size;

public:
    File(const string& fileName, int fileSize) : name(fileName), size(fileSize) {}

    void listContents() const override {
        cout << "File: " << name << " (" << size << " KB)" << endl;
    }

    int getSize() const override {
        return size;
    }
};

class Directory : public FileSystemComponent {
private:
    string name;
    vector<shared_ptr<FileSystemComponent>> contents;

public:
    Directory(const string& dirName) : name(dirName) {}

    void addComponent(shared_ptr<FileSystemComponent> component) {
        contents.push_back(component);
    }

    void listContents() const override {
        cout << "Directory: " << name << endl;
        for (const auto& component : contents) {
            cout << "  "; // Indent for better readability
            component->listContents();
        }
    }

    int getSize() const override {
        int totalSize = 0;
        for (const auto& component : contents) {
            totalSize += component->getSize();
        }
        return totalSize;
    }
};

int main() {
    // Create the root directory
    auto root = make_shared<Directory>("Root");

    // Create files
    auto file1 = make_shared<File>("Document.txt", 100);
    auto file2 = make_shared<File>("Image.jpg", 200);

    // Create subdirectory
    auto subDir = make_shared<Directory>("Subdirectory");
    auto file3 = make_shared<File>("Data.csv", 150);

    // Build the directory structure
    subDir->addComponent(file3);

    root->addComponent(file1);
    root->addComponent(file2);
    root->addComponent(subDir);

    // List contents and calculate total size for the directory structure
    root->listContents();
    int totalSize = root->getSize();
    cout << "Total Size: " << totalSize << " KB" << endl;

    // No need for manual memory cleanup - smart pointers handle it automatically
    // when they go out of scope or when the reference count reaches zero

    return 0;
}

///output:
//Directory: Root
//File : Document.txt(100 KB)
//File : Image.jpg(200 KB)
//Directory : Subdirectory
//File : Data.csv(150 KB)
//Total Size : 450 KB