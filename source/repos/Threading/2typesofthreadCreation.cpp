/////ways to create threads in cpp 11
////1. Function Pointers
////2. Lambda Functions
////3. Functors
////4. Member Functions
////5. Static Member Functions
////
//#include<iostream>
//#include<thread>
//#include<chrono>
//#include<algorithm>
//using namespace std;
//using namespace std::chrono;
//typedef unsigned long long ull;
////// 1. Function Pointer
////// this is very basic form of thread creation 
//////* if we create multiple threads at the same time it doesnt gurantee which one will start first.
////void fun(int x)
////{
////	while (x-- > 0)
////	{
////		cout << x << endl;
////	}
////}
////int main()
////{
////	std::thread t1(fun, 11);
////	std::thread t2(fun, 10);
////	t1.join();
////	t2.join();
////	return 0;
////}
//
////// 2. Lambda Functions
////// Example :
////int main()
////{
////	auto fun = [](int x)
////	{
////		while (x-- > 0)
////		{
////			cout << x << endl;
////		}
////	};
////	std::thread t1(fun, 10);
////	t1.join();
////	/// we can directly inject lambda at thread creation time 
////	 
////	std::thread t2([](int x)
////		{
////			while (x-- > 0)
////			{
////				cout << x << endl;
////			}
////		}, 10);
////	t2.join();
////	return 0;
////}
//
/////// 3. Functor 
////class Base
////{
////public:
////	void operator () (int x)
////	{
////		while (x-- > 0)
////		{
////			cout << x << endl;
////		}
////	}
////};
////int main()
////{
////	std::thread t1((Base()), 10);
////	t1.join();
////	return 0;
////}
//
//////4. Non-static member Function
////class Base
////{
////public:
////	void run(int x)
////	{
////		while (x-- > 0)
////		{
////			cout << x<< " ";
////		}
////	}
////};
////int main()
////{
////	Base b;
////	std::thread t1(&Base::run, &b, 10);
////	t1.join();
////	return 0;
////}
///////op: 9 8 7 6 5 4 3 2 1 0
//
////5. Static Member Function 
//class Base
//{
//public:
//	static void run(int x)
//	{
//		while (x-- > 0)
//		{
//			cout << x << " ";
//		}
//	}
//};
//int main()
//{
//	Base b;
//	std::thread t1(&Base::run, 10);
//	t1.join();
//	return 0;
//}
/////op: 9 8 7 6 5 4 3 2 1 0