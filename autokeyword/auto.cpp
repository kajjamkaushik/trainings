#include<iostream>
#include<map>
#include<vector>
using namespace std;
// C++ program to demonstrate working of auto
// and type inference
template<typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

int fun1() { return 10; }
char fun2() { return 'g'; }
int main()
{
    // auto a; this line will give error
    // because 'a' is not initialized at
    // the time of declaration
    // a=33;

    // see here x ,y,ptr are
    // initialised at the time of
    // declaration hence there is
    // no error in them
    auto x = 4;
    auto y = 3.37;
    auto z = 3.37f;
    auto c = 'a';
    auto ptr = &x;
    auto pptr = &ptr; //pointer to a pointer
    cout << typeid(x).name() << endl
        << typeid(y).name() << endl
        << typeid(z).name() << endl
        << typeid(c).name() << endl
        << typeid(ptr).name() << endl
        << typeid(pptr).name() << endl;

	map<int,string> list = { {1,"abc"} };
	for (map<int, string> ::iterator itr = list.begin();itr != list.end();itr++)
	{
		cout << itr->second;
	}
	for (auto itr : list)
	{
		cout << itr.second;
	}
    auto k = add(5, 7);
    cout << k << "is of type :" << typeid(k).name() << endl;

    /// preserves the const 
    const int ci = 42;
    decltype(ci) cj = 10;  // cj is const int
    //gives error whehn trying to change cj
    //cj=cj-5; //errror 


    //Note: auto becomes int type if even an integer reference is assigned to it.To make it reference type, we use auto& .


    //Function that returns a ‘reference to int’ type : int& fun() {};
    //m will default to int type instead of int& type : auto m = fun();
    //n will be of int& type because of use of extra& with auto keyword : auto& n = fun();


    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Iterate over the first half using auto
    for (auto it = arr.begin(); it != arr.begin() + arr.size() / 2; ++it) {
        std::cout << *it << " ";
    }

    /*The decltype keyword in C++ inspects the declared type of an entity or the type of an expression.
    ‘auto’ lets you declare a variable with a particular type whereas decltype lets you extract the type from the 
    variable so decltype is sort of an operator that evaluates the type of passed expression.
	*/
    // Data type of v is same as return type of fun1()
   // and type of b is same as return type of fun2()
    decltype(fun1()) v;
    decltype(fun2()) b;

    cout << typeid(v).name() << endl;
    cout << typeid(b).name() << endl;

    return 0;
}


//// C++ program to demonstrate use of decltype in functions
//#include <bits/stdc++.h>
//using namespace std;
//
//// A generic function which finds minimum of two values
//// return type is type of variable which is minimum
//template <class A, class B>
//auto findMin(A a, B b) -> decltype(a < b ? a : b)
//{
//    return (a < b) ? a : b;
//}
//
//// driver function to test various inference
//int main()
//{
//    // This call returns 3.44 of double type
//    cout << findMin(4, 3.44) << endl;
//
//    // This call returns 3 of double type
//    cout << findMin(5.4, 3) << endl;
//
//    return 0;
//}
