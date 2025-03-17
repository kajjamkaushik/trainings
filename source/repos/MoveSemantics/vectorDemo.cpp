//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Test
//{
//    int* val;
//public:
//    Test() {
//        val = nullptr;
//        cout << "Default constructor" << endl;
//    }
//    Test(int a)
//    {
//        val = new int(a);  // Allocate memory for int pointer
//        cout << "Parameterized constructor" << endl;
//    }
//    Test(const Test& obj) // const is needed to ensure the source object isn't modified 
//    {
//        cout << "Copy constructor" << endl;
//        if (obj.val != nullptr)
//            val = new int(*obj.val); // Deep copy - allocate new memory
//        else
//            val = nullptr;
//    }
//    Test(Test&& obj)
//    {
//        cout << "Move constructor" << endl;
//        val = obj.val;
//        obj.val = nullptr; // Set to nullptr since val is a pointer
//    }
//
//    // Destructor to prevent memory leaks
//    ~Test() {
//        delete val;
//    }
//
//    void display()
//    {
//        if (val != nullptr)
//            cout << (*val) << endl;
//        else
//            cout << "nullptr" << endl;
//    }
//};
//Test function()
//{
//    Test t1(10);
//    return t1;
//}
//int main()
//{
//    Test obj(10);
//    Test obj2(obj);
//    Test obj3 = obj;
//    obj.display();
//    obj2.display();
//    obj3.display();
//    Test obj4 = std::move(obj);
//    ///from here obj doesnt exist its moved to obj4
//    
//    obj4.display();
//    ///here
//
//    Test t2 = function();
//
//    return 0;
//}
//
////// C++ program to illustrate lvalue
////#include <iostream>
////using namespace std;
////
////// Creating the references of the
////// parameter passed to the function
////void swap(int& x, int& y)
////{
////	int temp = x;
////	x = y;
////	y = temp;
////}
////
////// Driver Code
////int main()
////{
////	// Given values
////	int a{ 10 }, b{ 20 };
////	cout << "a = " << a
////		<< " b = " << b << endl;
////
////	// Call by Reference
////	swap(a, b);
////
////	// Print the value
////	cout << "a = " << a
////		<< " b = " << b << endl;
////	return 0;
////}
////Uses of the lvalue references :
////
////lvalue references can be used to alias an existing object.
////They can also be used to implement pass - by - reference semantics.
//
////// C++ program to illustrate rvalue
////#include <iostream>
////using namespace std;
////
////// Declaring rvalue reference to the
////// rvalue passed as the parameter
////void printReferenceValue(int&& x)
////{
////	cout << x << endl;
////}
////
////// Driver Code
////int main()
////{
////	// Given value a
////	int a{ 10 };
////
////	// Works fine as the function is
////	// called with rvalue
////	printReferenceValue(100);
////	return 0;
////}
////Uses of rvalue references :
////
////They are used in working with the move constructor and move assignment.
////cannot bind non - const lvalue reference of type ‘int & ‘ to an rvalue of type ‘int’.
////cannot bind rvalue references of type ‘int && ‘ to lvalue of type ‘int’.
//
////void f(int& i) { cout << "l value " << endl; }
////void f(const int& i) { cout << " const l value " << endl; }
////void f(int&& i) { cout << "r value " << endl; }
////int main()
////{
////	int i = 10;
////	f(i);						// lvalue
////	f(10);						// rvalue // const lvalue if void f(int&& i) { cout << "r value " << endl; } is not defined 
////	f(std::move(i));			// rvalue
////	f(static_cast<int&&>(i));	// rvalue
////	return 0;
////}
//
