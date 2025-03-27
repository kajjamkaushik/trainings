//Static Cast 
/* It is a compile-time cast. It does things like implicit conversions between types (such as int to float, or 
pointer to void*), and it can also call explicit conversion functions.

Syntax of static_cast
static_cast <dest_type> (source);
The return value of static_cast will be of dest_type.
*/
// C++ Program to demonstrate static_cast
//#include <iostream>
//#include<string>
//using namespace std;
//class integer {
//    int x;
//
//public:
//    // constructor
//    integer(int x_in = 0)
//        : x{ x_in }
//    {
//        cout << "Constructor Called" << endl;
//    }
//
//    // user defined conversion operator to string type
//    operator string()
//    {
//        cout << "Conversion Operator Called" << endl;
//        return std::to_string(x);
//    }
//};
//
//class Base
//{
//};
//class Derived : public Base
//{
//};
//
//// Driver code
//int main()
//{
//    float f = 3.5;
//
//    // Implicit type case
//    // float to int
//    int a = f;
//    cout << "The Value of a: " << a;
//
//    // using static_cast for float to int
//    int b = static_cast<int>(f);
//    cout << "\nThe Value of b: " << b;
//
//    // 1. static_cast for primitive data type pointers:
//    int d= 10;
//    char c = 'a';
//
//    // Pass at compile time, 
//    // may fail at run time
//    // int* q = (int*)&c;
//    //int* p = static_cast<int*>(&c); /// error: invalid static_cast from type 'char*' to type 'int*
//
//    ///-------------------------------------------------------------------------------------------------------------------------
//    /// 2. Converting an Object using a User-Defined Conversion Operator
//    integer obj(3);
//    string str = obj;
//    obj = 20;
//
//    // using static_cast for typecasting
//    string str2 = static_cast<string>(obj);
//    obj = static_cast<integer>(30);
//
//    //output : 
//    // Constructor Called
//    /*Conversion Operator Called
//        Constructor Called
//        Conversion Operator Called
//        Constructor Called*/
//    //////---------------------------------------------------------------------------------------------------------------------
//    /*3. static_cast for Inheritance in C++
//        static_cast can provide both upcasting and downcasting in case of inheritance.
//        The following example demonstrates the use of static_cast in the case of upcasting.
//        class Base{};
//        
//        class Derived : public Base 
//        {};
//    */
//
//
//    Derived d1;
//
//    // Implicit cast allowed
//    Base* b1 = (Base*)(&d1);
//
//    // upcasting using static_cast
//    Base* b2 = static_cast<Base*>(&d1);



    /////////----------------------------------------------------------------------------------------------------------------
    /*4. static_cast to Cast ‘to and from’ Void Pointer
        static_cast operator allows casting from any pointer type to void pointer and vice versa.*/
    //but when u converted from any type to void* ptr you cannot access them as void* pointer 


    /*int i = 10;
    void* v = static_cast<void*>(&i);
    int* ip = static_cast<int*>(v);
    cout <<"integer pointer value : " << *ip;


    return 0;*/
//}