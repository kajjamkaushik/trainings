////For example, consider the following simple code where we have general template fun() for all data types except int.
////For int, there is a specialized version of fun().
//#include <iostream>
//using namespace std;
//template <class T>
//void fun(T a)
//{
//	cout << "The main template fun(): "
//		<< a << endl;
//}
//template<>
//void fun(int a)
//{
//	cout << "Specialized Template for int type: "
//		<< a << endl;
//}
//int main()
//{
//	fun<char>('a');
//	fun<int>(10);
//	fun<float>(10.14f);
//}



////In the following program, a specialized version of class Test is written for int data type.
//#include <iostream>
//using namespace std;
//template <class T>
//class Test
//{
//	// Data members of test
//public:
//	Test()
//	{
//		// Initialization of data members
//		cout<<typeid(T).name() << "General template object  \n";
//	}
//	// Other methods of Test
//};
//template <>
//class Test <int>
//{
//public:
//	Test()
//	{
//		// Initialization of data members
//		cout << "int - Specialized template object\n";
//	}
//};
//int main()
//{
//	Test<int> a;
//	Test<char> b;
//	Test<float> c;
//	return 0;
//}
//outptu::
//int - Specialized template object
//charGeneral template object
//floatGeneral template object

//How does template specialization work ?
//When we write any template based function or class, compiler creates a copy of that
//function / class whenever compiler sees that being used for a new data type or new set of 
//data types(in case of multiple template arguments).
//If a specialized version is present, compiler first checks with the specialized version and then 
//the main template.Compiler first checks with the most specialized version by matching the passed parameter 
//with the data type(s) specified in a specialized version.