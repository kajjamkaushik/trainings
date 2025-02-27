/////real world example -a person behaves as son,employee,father at different places but he is same
//#include<iostream>
//using namespace std;
////function overloading and operator overloading are compile time polymorphisms
////function overloading works based on no of parameters and type of paramters 
////not on the return type 
////void fun() { cout << 100 << endl; }
////int func() { return 10; } is compielr error 
//
////based on different type of parameters 
//void func(int a, float b)
//{
//	cout <<" a= " << a <<" b = " << b << endl;
//}
//void func(int a, int b)
//{
//	cout << " a= " << a << " b = " << b << endl;
//}
//
////based on different no of parameters
//int sum(int a,int b)
//{
//	return a + b;
//}
//int sum(int a, int b, int c)
//{
//	return a + b + c;
//}
///// at compile time itself compiler replaces or uses the function in object or assembly code
//class operatorOverload {
//public:
//	int operator+(int a)
//	{
//		return(a);
//	}
//};
//int main()
//{
//	int a = 10;
//	func(10, 25.6f);
//	func(10, 26);
//	cout << sum(1, 2, 3)<<endl;
//	cout << sum(10,25) << endl;
//
//
//	///operator overloading
//	return 0;
//}
//
//
///// name mangling  in C++
//
////Name mangling is the process by which the C++ compiler transforms function and variable names into unique names 
////to support function overloading, namespaces, and other language features.Since C++ allows function 
////overloading(multiple functions with the same name but different parameters), 
////it needs a way to differentiate these functions internally.
////The compiler modifies function names by encoding information like :
////
////1.Function name
////	Number and type of parameters
////	Return type(in some compilers)
////	Namespace or class scope
////2.The transformed names are used in object files and symbol tables to prevent name conflicts.
////void foo() { std::cout << "foo()\n"; }
////void foo(int x) { std::cout << "foo(int)\n"; }
////void foo(double x) { std::cout << "foo(double)\n"; }
////
////int main() {
////	foo();
////	foo(10);
////	foo(10.5);
////	return 0;
////}
//
//
///// object code is like 
////If compiled with g++ and inspected using the nm command :
////0000000000001139 T _Z3foov
////0000000000001149 T _Z3fooi
////0000000000001159 T _Z3food
////Here :
////
////_Z3foov → foo() (no parameters)
////_Z3fooi → foo(int)
////_Z3food → foo(double)
//
////Disabling Name Mangling(Extern "C")
////To interface with C libraries(which do not support name mangling), we use extern "C" to disable name mangling :
////
////extern "C" void foo() { std::cout << "C-style function\n"; }
////This ensures the function retains a simple name(foo) in the compiled binary.
////
////Key Points
////Name mangling enables function overloading and namespaces.
////Each compiler has its own name mangling scheme(GCC, Clang, MSVC differ).
////Use extern "C" for C linkage(no mangling).
//
//
//
//
