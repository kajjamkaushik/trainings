//// C++ program to demonstate the use of try,catch and throw
//// in exception handling.
//#include <iostream>
//#include <stdexcept>
//using namespace std;
//int main()
//{
//    // try block
//    try {
//        int numerator = 10;
//        int denominator = 0;
//        int res;
//        // check if denominator is 0 then throw runtime
//        // error.
//        if (denominator == 0) {
//            throw runtime_error(
//                "Division by zero not allowed!");
//        }
//        // calculate result if no exception occurs
//        res = numerator / denominator;
//        //[printing result after division
//        cout << "Result after division: " << res << endl;
//    }
//    // catch block to catch the thrown exception
//    catch (const exception& e) {
//        // print the exception
//        cout << "Exception " << e.what() << endl;
//    }
//    return 0;
//}
////op : Exception Division by zero not allowed!

//// program to expain the throw an primitve type exception and flow of program after throw block is never executed!!!!
//#include <iostream>
//using namespace std;
//int main()
//{
//    int x = -1;
//    cout << "Before try \n";
//    try {
//        cout << "Inside try \n";
//        if (x < 0) {
//            // throwing an exception
//            throw x;
//            cout << "After throw (Never executed) \n";
//        }
//    }
//    catch (int x) {
//        cout << "Exception Caught \n";
//    }
//    cout << "After catch (Will be executed) \n";
//    return 0;
//}

////In the following program, an int is thrown as an exception, but there is no catch block for int, 
//// so the catch (…) block will be executed.
//#include <iostream>
//using namespace std;
//int main()
//{
//    try {
//        throw 10;
//    }
//    catch (char* excp) {
//        cout << "Caught " << excp;
//    }
//    catch (...) {
//        cout << "Default Exception since no appropiate handler for int here \n";
//        //output: Default Exception since no appropiate handler for int here 
//    }
//    return 0;
//}

//// implicit converison doesnt happen for primitive types
//// C++ program to demonstate property 2: Implicit type
/// conversion doesn't happen for primitive types.
//// in exception handling.
//#include <iostream>
//using namespace std;
//int main()
//{
//    try {
//        throw 'a';
//    }
//    catch (int x) {
//        cout << "Caught " << x;
//    }
//    catch (...) {
//        cout << "Default Exception\n"; //op Default Exception
//    }
//    return 0;
//}
////In the following program, ‘a’ is not implicitly converted to int. 



//If an exception is thrown and not caught anywhere, the program terminates abnormally.

// C++ program to demonstate property 3: If an exception is
// thrown and not caught anywhere, the program terminates
// abnormally in exception handling.

//#include <iostream>
//using namespace std;
//int main()
//{
//    try {
//        throw 'a';
//    }
//    catch (int x) {
//        cout << "Caught ";
//    }
//    return 0;
//}
//// no output program terminated.....


///program to explain how rethrow of an exception works
// C++ program to demonstrate try/catch blocks can be nested
// in C++
//#include <iostream>
//using namespace std;
//int main()
//{
//    try {
//        try {
//            throw 20;
//        }
//        catch (int n) {
//            cout << "Handle Partially \n";
//            throw; // Re-throwing an exception
//        }
//    }
//    catch (int n) {
//        cout << "Handle remaining \n";
//    }
//    return 0;
//}
//ouptut :Handle Partially
/// Handle remaining


//// Important Property:
//When an exception is thrown, 
//all objects created inside the enclosing try block are destroyed before the control is transferred to the catch block.



//#include <iostream>
//using namespace std;
// Define a class named Test
//class Test {
//public:
//    // Constructor of Test
//    Test() { cout << "Constructor of Test " << endl; }
//    // Destructor of Test
//    ~Test() { cout << "Destructor of Test " << endl; }
//};
//int main()
//{
//    try {
//        // Create an object of class Test
//        Test t1;
//
//        // Throw an integer exception with value 10
//        throw 10;
//    }
//    catch (int i) {
//        // Catch and handle the integer exception
//        cout << "Caught " << i << endl;
//    }
//}
//output: 
//Constructor of Test
//Destructor of Test
//Caught 10


//Exceptions are run - time anomalies or abnormal conditions that a program encounters during its execution.
//There are two types of exceptions :
//Synchronous Exception
//Asynchronous Exception(Ex : which are beyond the program’s control, Disc failure, etc).

//#include<iostream>
//using namespace std;
//class Number {
//private:
//	int a, b;
//public:
//	Number(int x,int y):a(x),b(y)
//	{
//	}
//	int gcd()
//	{
//		while (a != b)
//		{
//			if (a > b)a = a - b;
//			else b = b - a;
//		}
//		return a;
//	}
//	bool isPrime(int n)
//	{
//		if (n <= 1)return false;
//		for (int i = 2;i * i <= n;++i)
//		{
//			if (n % i == 0)
//				return false;
//		}
//		return true;
//	}
//};
//class MyPrimeException
//{
//
//};
//int main()
//{
//	int x = 13, y = 56;
//	Number n1(x, y);
//	cout << "gcd of " << x << " " << y << " : " << n1.gcd() << endl;
//	if (n1.isPrime(x))cout << x << " is a prime number " << endl;
//	if (n1.isPrime(y))cout << y << " is a prime number " << endl;
//	if (n1.isPrime(x) || n1.isPrime(y))
//	{
//		try {
//			throw MyPrimeException();
//		}
//		catch (MyPrimeException t)
//		{
//			cout << "caught custom exception of MyPrimeException type " << endl;
//		}
//	}
//	return 0;
//}



/////			rethrowing without catch handler
//#include<iostream>
//using namespace std;
//int main()
//{
//	try {
//		try {
//			int x = 10;
//			throw x;
//		}
//		catch (int a)
//		{
//			cout << "caught exception x=" << a << "\n";
//			cout << "Rethrowing the caughted excception";
//			throw;
//		}
//	}
//	catch (char b)
//	{
//		cout << "inaprroipate handler" << endl;
//	}
//	return 0;
//}
///since in this case there is no proper handler catch block for rethrown exception 
///program terminated abruptly 
/// caught exception x=10
/*
Rethrowing the caughted excception
C : \Users\kajjam_kaushik\source\repos\exceptionHandling\x64\Debug\exceptionHandling.exe(process 23068) 
exited with code - 1 (0xffffffff).*/

//					rethrow exception in chain of multiple functions
#include<iostream>
using namespace std;
void f1()
{
	try {
		throw 100;
	}
	catch (int x)
	{
		cout << "caught excpetion value " << x << " rethrowing it :" << endl;
		throw;
	}
}
void f2()
{
	try {
		f1();
	}
	catch (int x)
	{
		cout << "caught excpetion  2nd time value " << x << " rethrowing it :" << endl;
		throw;
	}
}
void f3()
{
	try {
		f2();
	}
	catch (int x)
	{
		cout << "caught excpetion  3rd time value " << x << " rethrowing it :" << endl;
		throw;
	}
}
int main()
{
	try {
		f3();
	}
	catch (int a)
	{
		cout << "caught excpetion inside main value " << a << " and handled at final" << endl;
		throw;
	}
	return 0;
}
//outptu:
//caught excpetion value 100 rethrowing it :
//caught excpetion  2nd time value 100 rethrowing it :
//caught excpetion  3rd time value 100 rethrowing it :
//caught excpetion inside main value 100 and handled at final
//
//C : \Users\kajjam_kaushik\source\repos\exceptionHandling\x64\Debug\exceptionHandling.exe(process 22820) exited with code - 1 (0xffffffff).