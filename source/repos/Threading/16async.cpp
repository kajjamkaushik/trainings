// TOPIC: std::async

// NOTES:
// 1. It runs a function asynchronously (potentially in a new thread) and returns a std::future that will hold the result.
// 2. There are three launch policies for creating a task:
//    a) std::launch::async -> Threads
//    b) std::launch::deferred -> Deferred Execution
//    c) std::launch::async | std::launch::deferred -> Decides at runtime

// HOW IT WORKS:
// 1. It automatically creates a thread (or picks from an internal thread pool) and a promise object for us.
// 2. Then passes the std::promise object to the thread function and returns the associated std::future object.
// 3. When our passed argument function exits, its value will be set in this promise object,
//    so eventually, the return value will be available in std::future object.

// SIDE NOTES:
// 1. We can send a functor and lambda function as a callback to std::async, and it will work the same.

// PROGRAM:
//#include <iostream>
//#include <thread>
//#include <chrono>
//#include <algorithm>
//#include <future>
//
//using namespace std;
//using namespace std::chrono;
//typedef long long int ull;
//ull findOdd(ull start, ull end)
//{
//	ull OddSum = 0;
//	cout << "Thread Id of findOdd: " << std::this_thread::get_id() << endl;
//	for (ull i = start;i <= end;i++)
//	{
//		if (i & 1)
//		{
//			OddSum += i;
//		}
//	}
//	return OddSum;
//}
//int main()
//{
//	/*ull start = 0, end = 1900000000;
//	cout << "Thread Id : " << std::this_thread::get_id() << endl;
//	cout << "Thread Created if policy is std::launch::async !!" << endl;
//	std::future<ull> OddSum = std::async(std::launch::deferred, findOdd, start, end);
//
//	cout << "Waiting For Result !!" << endl;
//	cout << "OddSum : " << OddSum.get() << endl;
//
//	cout << "Completed !!!" << endl;*/
//	//output :
//		/*Thread Id : 2972
//		Thread Created if policy is std::launch::async !!
//		Waiting For Result !!
//		Thread Id of findOdd : 2972
//		OddSum : 902500000000000000
//		Completed !!!*/									/// we can observe same ThreadId because its not eager execution 
//										//findOdd only gets executed when the future gives it a calls whereas in async it gets
//										// executed as and when it encounters the code without waiting for the call
//
//
//	///-----------------------------------------------------------------------------------------------------------///
//	ull start = 0, end = 1900000000;
//	cout << "Thread Id : " << std::this_thread::get_id() << endl;
//	cout << "Thread Created if policy is std::launch::async !!" << endl;
//	std::future<ull> OddSum = std::async(std::launch::deferred, findOdd, start, end);
//
//	cout << "Waiting For Result !!" << endl;
//	cout << "OddSum : " << OddSum.get() << endl;
//
//	cout << "Completed !!!" << endl;
//
//
//	//output :
//		/*Thread Id : 27440
//		Thread Created if policy is std::launch::async !!
//		Waiting For Result !!
//		Thread Id of findOdd : 27401
//		OddSum : 902500000000000000
//		Completed !!!*/
//		/// diferent threadIds because of blocking/eager execution of threads
//
//	return 0;
//}