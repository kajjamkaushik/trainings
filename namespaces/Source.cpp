//#include <iostream>
//using namespace std;
//// first name space
//namespace first_space
//{
//    void func()
//    {
//        cout << "Inside first_space" << endl;
//    }
//}
//// second name space
//namespace second_space
//{
//    void func()
//    {
//        cout << "Inside second_space" << endl;
//    }
//}
//using namespace first_space;
//int main()
//{
//    // This calls function from first name space.
//    func();
//    return 0;
//}
//
//
///////    NEsted Namespaces
//
//#include <iostream>
//using namespace std;
//
//// first name space
//namespace first_space
//{
//    void func()
//    {
//        cout << "Inside first_space" << endl;
//    }
//    // second name space
//    namespace second_space
//    {
//        void func()
//        {
//            cout << "Inside second_space" << endl;
//        }
//    }
//}
//using namespace first_space::second_space;
//int main()
//{
//    // This calls function from second name space.
//    func();
//  // Calls function from first name space.
//first_space::func();
//// Calls function from second name space.
//second_space::func();
//return 0;
//}
//



//// Creating namespaces
//#include <iostream>
//using namespace std;
//namespace ns1 {
//    int value() { return 5; }
//} // namespace ns1
//namespace ns2 {
//    const double x = 100;
//    double value() { return 2 * x; }
//} // namespace ns2
//
//int main()
//{
//    // Access value function within ns1
//    cout << ns1::value() << '\n'; //5
//
//    // Access value function within ns2
//    cout << ns2::value() << '\n'; ///op : 200
//
//    // Access variable x directly
//    cout << ns2::x << '\n'; //////op : 100
//
//    return 0;
//}
//// A C++ program to demonstrate use of class
//// in a namespace
//#include<iostream>
//using namespace std;
//namespace ns
//{
//    // A Class in a namespace
//    class geek
//    {
//    public:
//        void display()
//        {
//            cout << "ns::geek::display()" << endl;;
//        }
//    };
//}
//int main()
//{
//    // Creating Object of geek Class
//    ns::geek obj;
//    obj.display();
//    return 0;
//}

//// A C++ code to demonstrate that we can define
//// methods outside namespace.
//#include <iostream>
//using namespace std;
//
//// Creating a namespace
//namespace ns {
//    void display();
//    class geek {
//    public:
//        void display();
//    };
//} // namespace ns
//
//// Defining methods of namespace
//void ns::geek::display()
//{
//    cout << "ns::geek::display()\n";
//}
//void ns::display() { cout << "ns::display()\n"; }
//
//// Driver code
//int main()
//{
//    ns::geek obj;
//    ns::display();
//    obj.display();
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//// first name space
//namespace first_space
//{
//    void func()
//    {
//        cout << "Inside first_space" << endl;
//    }
//    // second name space
//    namespace second_space
//    {
//        void func()
//        {
//            cout << "Inside second_space" << endl;
//        }
//    }
//}
//using namespace first_space::second_space;
//int main()
//{
//
//    // This calls function from second name space.
//    func();
//
//    return 0;
//}
//
//// If we compile and run above code, this would produce the following result:
//// Inside second_space


//// C++ program to demonstrate namespace extension
//#include <iostream>
//using namespace std;
//
//// first name space
//namespace first
//{
//	int val1 = 500;
//}
//
//// rest part of the first namespace
//namespace first
//{
//	int val2 = 501;
//}
//
//int main()
//{
//	cout << first::val1 << "\n";
//	cout << first::val2 << "\n";
//	return 0;
//}
// C++ program to demonstrate working of unnamed 
// namespaces
//#include <iostream>
//using namespace std;
//
//// unnamed namespace declaration
//namespace
//{
//	int rel = 300;
//}
//
//int main()
//{
//	cout << rel << "\n"; // prints 300
//	return 0;
//}
//// file1.h 
//namespace foo
//{
//	int value()
//	{
//		return 5;
//	}
//}
//// file2.cpp - Not to be executed online
//#include <iostream>
//#include “file1.h” // Including file1
//using namespace std;
//
//int main()
//{
//	cout << foo::value();
//	return 0;
//}

//// C++ program to demonstrate nesting of namespaces
//#include <iostream>
//using namespace std;
//
//// Nested namespace
//namespace out
//{
//	int val = 5;
//	namespace in
//	{
//		int val2 = val;
//	}
//}
//
//// Driver code
//int main()
//{
//	cout << out::in::val2; // prints 5
//	return 0;
//}
//#include <iostream>
//
//namespace name1
//{
//	namespace name2
//	{
//		namespace name3
//		{
//			int var = 42;
//		}
//	}
//}
//
//// Aliasing 
//namespace alias = name1::name2::name3;
//
//int main()
//{
//	std::cout << alias::var << '\n';
//}



// C++ program to demonstrate working 
// of "using" to get the same effect as 
// inline. 
#include <iostream> 
using namespace std;

namespace ns1 {
	namespace ns2 {
		namespace ns3 {
			int var = 10;
		}
		using namespace ns3;
	} // namespace ns2 

	using namespace ns2;
} // namespace ns1 

int main()
{
	cout << ns1::var;
	return 0;
}
