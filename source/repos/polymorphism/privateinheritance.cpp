//#include <iostream>
//using namespace std;
//
////////////////////////////////////////////////
//// Example 1: Restricting Access to Base Class
////////////////////////////////////////////////
//class Base {
//public:
//    void show() { cout << "Base class function\n"; }
//};
//
//class Derived : private Base { // Private Inheritance
//public:
//    void display() {
//        cout << "Derived class function\n";
//        show();  // Allowed inside Derived class
//    }
//};
//
////////////////////////////////////////////////
//// Example 2: Private Inheritance to Hide Functionality
////////////////////////////////////////////////
//class Logger {
//public:
//    void log(string message) { cout << "Log: " << message << endl; }
//};
//
//class Application : private Logger { // Private Inheritance
//public:
//    void run() {
//        log("Application started");  // Using base class method internally
//        cout << "Running application...\n";
//        log("Application running smoothly");
//    }
//};
//
////////////////////////////////////////////////
//// Example 3: Preventing Unwanted Function Overriding
////////////////////////////////////////////////
//class Parent {
//public:
//    void commonFunction() { cout << "Parent Function\n"; }
//};
//
//class Child : private Parent { // Private Inheritance
//public:
//    void specificFunction() {
//        commonFunction();  // Allowed within Child
//        cout << "Child-specific function\n";
//    }
//};
//
////////////////////////////////////////////////
//// Example 4: Using Composition Instead of Private Inheritance
////////////////////////////////////////////////
//class Logger2 {
//public:
//    void log(string message) { cout << "Log: " << message << endl; }
//};
//
//class Application2 {
//private:
//    Logger2 logger;  // Composition (Has-a relationship)
//public:
//    void run() {
//        logger.log("Application started");
//        cout << "Running application...\n";
//        logger.log("Application running smoothly");
//    }
//};
//
////////////////////////////////////////////////
//// Main Function: Testing All Examples
////////////////////////////////////////////////
//int main() {
//    cout << "Example 1: Private Inheritance - Restricting Access\n";
//    Derived d;
//    d.display();  // Works fine
//    // d.show();  // Error: show() is private in Derived
//
//    cout << "\nExample 2: Private Inheritance - Hiding Functionality\n";
//    Application app;
//    app.run();
//    // app.log("Test");  // Error: log() is private in Application
//
//    cout << "\nExample 3: Private Inheritance - Preventing Overriding\n";
//    Child obj;
//    obj.specificFunction();
//    // obj.commonFunction();  // Error: commonFunction is private in Child
//
//    cout << "\nExample 4: Composition Instead of Private Inheritance\n";
//    Application2 app2;
//    app2.run();
//
//    return 0;
//}
