/* 
Producer Consumer OR Bounded Buffer Problem

THE PROBLEM STATEMENT :
1.Producer will produce and consumer will consume with synchronization of a common buffer.
2.Until producer thread produces any data, consumer thread can't consume.
3.Threads will use condition_variable to notify each other.
4.We need mutex if we use condition_variable because CV waits on mutex.
5.This is one example of the producer - consumer problem; there are many variations.

PRODUCER thread steps :
1.Lock mutex, if successful then proceed; otherwise, wait for mutex to get free.
2.Check if the buffer is full; if it is full, unlock mutex and sleep, otherwise proceed to produce.
3.Insert item in the buffer.
4.Unlock mutex.
5.Notify consumer.

CONSUMER thread steps :
1.Lock mutex, if successful then proceed; otherwise, wait for mutex to get free.	
2.Check if the buffer is empty; if it is empty, unlock mutex and sleep, otherwise proceed to consume.
3.Consume item from buffer.
4.Unlock mutex.
5.Notify producer.

IMP:
Producer and Consumer have to notify each other upon completion of their job.*/

//#include<iostream>
//#include<thread>
//#include<condition_variable>
//#include<mutex>
//#include<deque>
//
//using namespace std;
//std::mutex mu;
//std::condition_variable cond;
//deque<int> buffer;
//const unsigned int maxBufferSize=50;
//
//void producer(int val)
//{
//	while (val)
//	{
//		std::unique_lock<std::mutex> locker(mu);
//		cond.wait(locker, [] {return buffer.size() < maxBufferSize;});
//		buffer.push_back(val);
//		cout << "Produced : " << val << endl;
//		val--;
//		locker.unlock();
//		cond.notify_one();
//	}
//}
//
//void consumer()
//{
//	while (true)
//	{
//		std::unique_lock<std::mutex> locker(mu);
//		cond.wait(locker, [] {return buffer.size() > 0;});
//		int val = buffer.back();
//		buffer.pop_back();
//		cout << "Consumed : " << val << endl;
//		locker.unlock();
//		cond.notify_one();
//	}
//}
//
//int main()
//{
//	thread t1(producer, 100);
//	thread t2(consumer);
//	t1.join();
//	t2.join();
//	return 0;
//}