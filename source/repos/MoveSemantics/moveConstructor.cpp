#include <iostream>
using namespace std;

class A {
    int* p;
public:
    A() {
        p = new int[100];
        cout << "Default Constructor" << endl;
    }

    // Copy Constructor
    A(const A& obj) {
        p = new int[100];
        for (int i = 0; i < 100; i++) {
            p[i] = obj.p[i];
        }
        cout << "Copy Constructor" << endl;
    }

    // Move Constructor
    A(A&& obj) noexcept : p(obj.p) {  // Remove 'const' from parameter
        obj.p = nullptr;  // Transfer ownership
        cout << "Move Constructor" << endl;
    }

    // Copy Assignment Operator
    A& operator=(const A& obj) {
        if (this == &obj) {
            return *this;
        }
        delete[] p;
        p = new int[100];
        for (int i = 0; i < 100; i++) {
            p[i] = obj.p[i];
        }
        cout << "Copy Assignment Operator" << endl;
        return *this;
    }

    // Move Assignment Operator
    A& operator=(A&& obj) noexcept {
        if (this == &obj) {
            return *this;
        }
        delete[] p;
        p = obj.p;
        obj.p = nullptr;
        cout << "Move Assignment Operator" << endl;
        return *this;
    }

    // Destructor
    ~A() {
        delete[] p;
        cout << "Destructor" << endl;
    }
};

int main() {
    A a;                 // Default Constructor
    A b = a;             // Copy Constructor
    A c = std::move(a);  // Move Constructor
    A d(b);              // Copy Constructor
    return 0;
}
