//Stack Unwinding is the process of removing function entries from function call stack at run time.
////The local objects are destroyed in reverse order in which they were constructed.
//when an exception occurs, the function call stack is linearly searched for the exception handler, and 
//all the entries before the function with exception handler are removed from the function call stack.
//So, exception handling involves Stack Unwinding if an exception is not handled in the same function(where it is thrown).
//Basically, Stack unwinding is a process of calling
//the destructors(whenever an exception is thrown) for all the automatic objects constructed at run time.
// CPP Program to demonstrate Stack Unwinding 

//#include <iostream> 
//using namespace std;
//// A sample function f1() that throws an int exception 
//void f1() throw(int)
//{
//	cout << "\n f1() Start ";
//	throw 100;
//	cout << "\n f1() End ";
//}
//// Another sample function f2() that calls f1() 
//void f2() throw(int)
//{
//	cout << "\n f2() Start ";
//	f1();
//	cout << "\n f2() End ";
//}
//// Another sample function f3() that calls f2() and handles 
//// exception thrown by f1() 
//void f3()
//{
//	cout << "\n f3() Start ";
//	try {
//		f2();
//	}
//	catch (int i) {
//		cout << "\n Caught Exception: " << i;
//	}
//	cout << "\n f3() End";
//}
//int main()
//{
//	f3();
//	return 0;
//}

//output::
//f3() Start
//f2() Start
//f1() Start
//Caught Exception : 100
//f3() End
