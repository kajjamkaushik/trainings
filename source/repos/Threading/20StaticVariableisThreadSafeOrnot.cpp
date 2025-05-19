//#include<iostream>
//#include<thread>
//#include<chrono>
//#include<mutex>
//using namespace std;
//static int s = 0;
//mutex m;
//void fun()
//{
//	int count = 100000;
//	while (count--)
//	{
//		m.lock();
//		++s;
//		m.unlock();
//	}
//	cout << s << endl;
//}
//int main()
//{
//	thread t1(fun);
//	thread t2(fun);
//	t1.join();
//	t2.join();
//	return 0;
//}
////op: 100000	114429    100000 //after 	187007
////	  187717	193979    200000 //after 	200000
//// we can observe different values of s each time beacause fetch modify and store cycle since no lock then different threads trying 
//// to access at same time gives error !!!!!
///// after using mutex lock() and unlock() we can see it to be not safe
//
//// so we can conclude that static variable is THread Safe - NO 
