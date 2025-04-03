//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<chrono>
//#include<functional>
//#include<vector>
//#include<condition_variable>
//#include<queue>
//#include<sstream>
//using namespace std;
//
//class ThreadPool
//{
//public:
//	ThreadPool(size_t numThreads) :stop(false)
//	{
//		for (size_t i = 0;i < numThreads;i++)
//		{
//
//		}
//	}
//};
//
//int main()
//{
//	ThreadPool pool(4);
//	cout << "Thread Pool Created \n";
//	cout << "Enqueue (Assign) some tasks \n";
//	for (int i = 0;i < 8;i++)
//	{
//		pool.enqueue([i] {
//			printf("Task %d %s is executed by thread \n", i, get_thread_id().c_str());
//			std::this_thread::sleep_for(std::chrono::seconds(i)); //simulate  some work 
//			});
//	}
//	//Main thread continues doing other things 
//	//while the tasks are executed in the background
//	return 0;
//}