#include <string>
#include <iostream>
using namespace std;

class Ibutton {
public:
    virtual void press() = 0;
    virtual ~Ibutton() = default; // Add virtual destructor
};

class ITextbox {
public:
    virtual void settext() = 0;
    virtual ~ITextbox() = default; // Add virtual destructor
};

class MacButton : public Ibutton {
public:
    void press() override {
        cout << "Mac button pressed" << endl;
    }
};

class WinButton : public Ibutton {
public:
    void press() override {
        cout << "Win button pressed" << endl;
    }
};

class MacTextBox : public ITextbox {
public:
    void settext() override {
        cout << "Setting text in Mac Textbox" << endl;
    }
};

class WinTextBox : public ITextbox {
public:
    void settext() override {
        cout << "Setting text in Win Textbox" << endl;
    }
};

class IFactory {
public:
    virtual Ibutton* createbutton() = 0;
    virtual ITextbox* createtextbox() = 0;
    virtual ~IFactory() = default; // Add virtual destructor
};

class WinFactory : public IFactory {
public:
    Ibutton* createbutton() override {
        return new WinButton();
    }
    ITextbox* createtextbox() override {
        return new WinTextBox();
    }
};

class MacFactory : public IFactory {
public:
    Ibutton* createbutton() override {
        return new MacButton();
    }
    ITextbox* createtextbox() override {
        return new MacTextBox();
    }
};

class GUIAbstractfactory {
public:
    static IFactory* createfactory(const string& ostype) {
        if (ostype == "windows") {
            return new WinFactory();
        }
        else if (ostype == "mac") {
            return new MacFactory();
        }
        return nullptr;
    }
};

int main() {
    cout << "Enter machine OS (windows/mac): ";
    string ostype;
    cin >> ostype;

    IFactory* fact = GUIAbstractfactory::createfactory(ostype);

    if (fact == nullptr) {
        cout << "Invalid OS type. Please enter 'windows' or 'mac'." << endl;
        return 1;
    }

    Ibutton* button = fact->createbutton();
    button->press();

    ITextbox* textBox = fact->createtextbox();
    textBox->settext();

    // Clean up allocated memory
    delete button;
    delete textBox;
    delete fact;

    return 0;
}