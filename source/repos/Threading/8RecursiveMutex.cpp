// TOPIC: Recursive Mutex In C++ (std::recursive_mutex)

// NOTES:
// 0. It is same as mutex but, same thread can lock one mutex multiple times using recursive_mutex.
// 1. If thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1, now 
//    as T1 is running in recursion T1 can call lock/try_lock any number of times there is no issue.
// 2. But if T1 has acquired 10 times lock/try_lock on mutex m1 then thread T1 will have to unlock 
//    it 10 times otherwise no other thread will be able to lock mutex m1.
// 3. It means recursive mutex keeps count how many times it was locked so that many times it should be unlocked.
// 4. How many times we can lock recursive_mutex is not defined but when that number reaches and if we were calling 
//    lock() it will return std::system_error OR if we were calling try_lock() then it will return false.

// BOTTOM LINE:
// 0. It is similar to mutex but has extra facility that it can be locked multiple times by the same thread.
// 1. If we can avoid recursive mutex then we should because it brings overhead to the system.
// 2. It can be used in loops also.


#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

//Example 1 . With Recursion
//std::recursive_mutex m1;
//int buffer = 0;
//void recursion(char c, int loopFor)
//{
//	if (loopFor < 0)
//		return;
//	m1.lock();
//	cout <<"Thread ID: " << c << " buffer val :" << buffer++ << endl;
//	recursion(c, --loopFor);
//	m1.unlock();
//}
//int main()
//{
//	thread t1(recursion, '0', 10);
//	thread t2(recursion, '1', 10);
//	t1.join();
//	t2.join();
//	return 0;
//}
//
////op :
//Thread ID : 1 buffer val : 0
//Thread ID : 1 buffer val : 1
//Thread ID : 1 buffer val : 2
//Thread ID : 1 buffer val : 3
//Thread ID : 1 buffer val : 4
//Thread ID : 1 buffer val : 5
//Thread ID : 1 buffer val : 6
//Thread ID : 1 buffer val : 7
//Thread ID : 1 buffer val : 8
//Thread ID : 1 buffer val : 9
//Thread ID : 1 buffer val : 10
//Thread ID : 0 buffer val : 11
//Thread ID : 0 buffer val : 12
//Thread ID : 0 buffer val : 13
//Thread ID : 0 buffer val : 14
//Thread ID : 0 buffer val : 15
//Thread ID : 0 buffer val : 16
//Thread ID : 0 buffer val : 17
//Thread ID : 0 buffer val : 18
//Thread ID : 0 buffer val : 19
//Thread ID : 0 buffer val : 20
//Thread ID : 0 buffer val : 21
//2. Example with loop

//std::recursive_mutex m1;
//int buffer = 0;
//int main()
//{
//	for (int i = 0;i < 5;i++)
//	{
//		m1.lock();
//		cout << "locked " << i << endl;
//	}
//	for (int i = 0;i < 5;i++)
//	{
//		m1.unlock();
//		cout << "unlocked " << i << endl;
//	}
//	return 0;
//}

////op :
//locked 0
//locked 1
//locked 2
//locked 3
//locked 4
//unlocked 0
//unlocked 1
//unlocked 2
//unlocked 3
//unlocked 4