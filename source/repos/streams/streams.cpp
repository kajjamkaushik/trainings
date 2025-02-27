#include <iostream>
#include <fstream>
#include <sstream>  // Added missing header for string streams

using namespace std;

int main() {
    /// 1. Standard I/O using cin and cout
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age is " << age << endl;

    ///  2. File Handling using fstream
    ofstream outFile("example.txt");  // Write to a file
    outFile << "Hello, File 1 !" << endl;
    outFile << "Hello, File 2 !" << endl;
    outFile << "Hello, File 3 !" << endl;
    outFile << "Hello, File 4 !" << endl;
    outFile << "Hello, File 5 !" << endl;
    outFile.close();

    ifstream inFile("example.txt");   // Read from a file
    stringstream buffer;
    buffer << inFile.rdbuf();  // Read entire file into stringstream
    string content = buffer.str();

    cout << "File content:\n" << content << endl;
    inFile.close();

    /// errors
    std::cerr << "high time error no buffer" << endl;

    /// std::clog is used for logging general information
    std::clog << "this is log message will flush out only when buffer is full and file is flush" << endl;

    // 3. String Streams
    // Used to perform I/O operations on strings.

    // istringstream (Input String Stream) → Reads from a string.
    std::istringstream iss("42 3.14 hello");
    int num;
    double d;
    std::string word;
    iss >> num >> d >> word;

    // ostringstream (Output String Stream) → Writes to a string.
    std::ostringstream oss;
    oss << "Hello " << 2024;
    std::string result = oss.str();

    // stringstream (String Stream - Read / Write) → Supports both input and output.
    std::stringstream ssrw;
    ssrw << "Data 123";

    return 0;
}
