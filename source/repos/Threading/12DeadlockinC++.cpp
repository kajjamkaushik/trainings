//#include<mutex>
//#include<iostream>
//#include<chrono>
//#include<thread>
//
//using namespace std;
//std::mutex m1;
//std::mutex m2;
//void task1()
//{
//	m1.lock();
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	m2.lock();
//	cout << "Critical Section of Thread thread 1" << endl;
//	m2.unlock();
//	m1.unlock();
//}
//void task2()
//{
//	m2.lock();
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	m1.lock();
//	cout << "Critical Section of Thread Thread two " << endl;
//	m1.unlock();
//	m2.unlock();
//}
//int main()
//{
//	thread t1(task1);
//	thread t2(task2);
//	t1.join();
//	t2.join();
//	return 0;
//}