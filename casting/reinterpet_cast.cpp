//reinterpret_cast is a type of casting operator used in C++.
//It is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different.
//It does not check if the pointer type and data pointed by the pointer is same or not.
//Syntax :
//data_type * var_name =reinterpret_cast <data_type*>(pointer_variable);
//
//Return Type
//It doesn�t have any return type.It simply converts the pointer type.
//
//Parameters
//It takes only one parameter i.e., the source pointer variable(p in above example).

// CPP program to demonstrate working of reinterpret_cast
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int* p = new int(65);
//	char* ch = reinterpret_cast<char*>(p);
//	cout << *p << endl;		//65
//	cout << *ch << endl;	//A
//	cout << p << endl;		//000002EFF8B75270
//	cout << ch << endl;		//A
//	return 0;
//}


//Purpose for using reinterpret_cast
//1.reinterpret_cast is a very special and dangerous type of casting operator. And is suggested to use it using proper data type i.e., (pointer data type should be same as original data type).
//2.It can typecast any pointer to any other data type.
//3.It is used when we want to work with bits.
//4.If we use this type of cast then it becomes a non - portable product.So, it is suggested not to use this concept unless required.
//5.It is only used to typecast any pointer to its original type.
//6.Boolean value will be converted into integer value i.e., 0 for false and 1 for true.

// CPP code to illustrate using structure
//#include <iostream>
//using namespace std;
//
//// creating structure mystruct
//struct mystruct {
//	int x;
//	int y;
//	char c;
//	bool b;
//};
//int main()
//{
//	mystruct s;
//
//	// Assigning values
//	s.x = 5;
//	s.y = 10;
//	s.c = 'a';
//	s.b = true;
//
//	// data type must be same during casting
//	// as that of original
//
//	// converting the pointer of 's' to,
//	// pointer of int type in 'p'.
//	int* p = reinterpret_cast<int*>(&s);
//
//	cout << sizeof(s) << endl;// op :12
//
//	// printing the value currently pointed by *p
//	cout << *p << endl; //op : 5 p is pointing to s.x
//
//	// incrementing the pointer by 1
//	p++;
//	// printing the next integer value
//	cout << *p << endl; //op : 10 p is pointing to s.y
//	p++;
//
//	// we are casting back char * pointed
//	// by p using char *ch.
//	char* ch = reinterpret_cast<char*>(p);  
//
//	// printing the character value
//	// pointed by (*ch)
//	cout << *ch << endl;   //op : a p is pointing to s.c
//
//	ch++;
//
//	/* since, (*ch) now points to boolean value,
//	so it is required to access the value using
//	same type conversion.so, we have used
//	data type of *n to be bool. */
//															
//									///***************************** check this line below ******** Important **************/
//
//	bool* n = reinterpret_cast<bool*>(ch);  
//	cout << *n << endl; //op : 1 n is pointing to s.d
//
//	// we can also use this line of code to
//	// print the value pointed by (*ch).
//	cout << *(reinterpret_cast<bool*>(ch));  //op : 1 ch  is pointing to s.d
//	return 0;
//}


// CPP code to illustrate the pointer reinterpret
#include <iostream>
using namespace std;
class A {
public:
	void fun_a()
	{
		cout << " In class A\n";
	}
};
class B {
public:
	void fun_b()
	{
		cout << " In class B\n";
	}
};
int main()
{
	// creating object of class B
	B* x = new B();
	// converting the pointer to object
	// referenced of class B to class A
	A* new_a = reinterpret_cast<A*>(x);
	// accessing the function of class A
	new_a->fun_a(); 
					//op : In class A
	return 0;
}
