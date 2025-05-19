#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str1 = "Hello";
    string str2 = "World";
    string str3;

    // size, length, and capacity
    cout << "str1 size: " << str1.size() << endl;
    cout << "str1 length: " << str1.length() << endl;
    cout << "str1 capacity: " << str1.capacity() << endl;

    // accessing characters
    cout << "First character of str1: " << str1[0] << endl;
    cout << "Last character of str1 using at(): " << str1.at(str1.length() - 1) << endl;

    // concatenation
    str3 = str1 + " " + str2;
    cout << "Concatenated string: " << str3 << endl;

    // append
    str1.append(" Everyone");
    cout << "Appended str1: " << str1 << endl;

    // insert
    str2.insert(0, "Hello ");
    cout << "Inserted str2: " << str2 << endl;

    // erase
    str2.erase(0, 6);
    cout << "Erased str2: " << str2 << endl;

    // replace
    str1.replace(6, 8, "World");
    cout << "Replaced str1: " << str1 << endl;

    // find
    size_t pos = str1.find("World");
    if (pos != string::npos) {
        cout << "'World' found at position: " << pos << endl;
    }
    else {
        cout << "'World' not found" << endl;
    }

    // substr
    string substr = str1.substr(6, 5);
    cout << "Substring of str1: " << substr << endl;

    // compare
    int result = str1.compare(str2);
    cout << "Compare result: " << result << endl;

    // lower and upper case conversion
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    cout << "Lowercase str1: " << str1 << endl;

    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    cout << "Uppercase str2: " << str2 << endl;

    // swap
    str1.swap(str2);
    cout << "Swapped str1: " << str1 << endl;
    cout << "Swapped str2: " << str2 << endl;

    return 0;
}