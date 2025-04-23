#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>
using namespace std;
//Question-1 : What happens if a thread is not joined or detached? What are the risks?
int thread1()
{
	cout << "Inside thread 1 " << endl;
	return 0;
}
//int main()
//{
//	cout << "inside main -1 " << endl;
//	std::thread t1(thread1);
//	cout << "inside main at end  " << endl;
//	return 0;
//}
//output : abort() has been called in VS Community -- online 
//inside main 
//inside main at end
//terminate called without an active exception


///notes ::: 
//Thread Detachment and Joining
//Joining : The join() method blocks the calling thread until the child thread finishes execution.
//Detaching : The detach() method allows a thread to run independently.After detaching, 
//			  you can't join the thread anymore.

///  Risks :
// If a thread is neither joined nor detached, it can lead to resource leaks and undefined behavior in some systems.

//1. Resource Leak(Zombie Threads)
//The thread finishes execution, but its resources(like stack memory and thread descriptor) are not reclaimed.
//This is called a zombie thread(similar to zombie processes in OS).
//Over time, creating many such threads will exhaust system resources(memory, thread handles).
//2. std::terminate() in C++
//In C++, if a std::thread object is destroyed without being joined or detached, std::terminate()
//is called, which ends the program immediately.
//	std::thread t([] { /* work */ });
//// if you do not call t.join() or t.detach() before t goes out of scope:
//// std::terminate() is called
//3. Portability Issues
//Not all operating systems handle this situation the same way.Code that works "by chance" on one platform 
//might crash or leak on another.
///--------------------------------------------------------------------------------------------------------------------------------
///Question 2 and 3 :  Write a program that starts two threads, each printing "Hello from thread X" where X is the thread ID.
//						How can you pass arguments to a thread function ? Show this via an example program.

void greet1(int thread_id)
{
	for (int i = 0;i < 5;i++)
	{
		cout << "Hello from thread " << thread_id << endl;
	}
}
//int main()
//{
//	std::thread t1(greet1, 1);
//	std::thread t2(greet1, 2);
//	t1.join();
//	t2.join();
//	cout << "Both Threads have finished" << endl;
//	return 0;
//}
//op :Hello from thread 1
//Hello from thread 1
//Hello from thread 1
//Hello from thread 2
//Hello from thread Hello from thread 21
//Hello from thread
//1Hello from thread
//2
//Hello from thread 2
//Hello from thread 2
//Both Threads have finished
////------------------------------------------------------------------------------------------------------------------------


/// Question - 4: What happens if you call std::thread::join() twice ? Explain.


//The first call to t.join() works as expected and waits for the thread to complete.
//The second call to t.join() will cause undefined behavior, and your program will likely crash or throw 
//an exception depending on the compiler and runtime environment.
void print_message() {
	std::cout << "Hello from the thread!" << std::endl;
}
//int main() {
//	// Create a thread
//	std::thread t(print_message);
//	// First call to join() - valid
//	t.join();
//	// Second call to join() - undefined behavior
//	t.join();  // This will likely cause a runtime error or crash
//	return 0;
//}
// abnormal crash of execution with errror : _Throw_Cpp_error(_INVALID_ARGUMENT);

//Best Practices:
//Always check that the thread is joinable before calling join() again.You can use the joinable() method ofstd::thread to check if a thread can be joined :
//if (t.joinable()) {
//	t.join();
//}
//Once a thread is joined, it is no longer joinable, and any subsequent calls to join() on that thread should be avoided.If you need to check if a thread was already joined,
//you can use a flag or other mechanisms to track its state.

////------------------------------------------------------------------------------------------------------------------------


/// Question - 5:  Write a program to start a thread using a lambda function that prints numbers from 1 to 10.
using namespace std;
//int main()
//{
//	cout << "Hello from main thread : " << endl;
//	std::string message = "Hello from lambda!";
//	int count = 4;
//	// Create a thread using a lambda function
//	std::thread t([message, count]() {
//		for (int i = 0; i < count; ++i)
//			std::cout << message << " (" << i + 1 << ")\n";
//		});
//	t.join(); // Wait for the thread to complete
//	cout << "main thread  printing from 101to 110 " << endl;
//	for (int i = 101;i <= 110;i++)
//		cout << " value : " << i << endl;
//	return 0;
//}
//output : Hello from main thread :
//Hello from lambda!(1)
//Hello from lambda!(2)
//Hello from lambda!(3)
//Hello from lambda!(4)
//main thread  printing from 101to 110
//value : 101
//value : 102
//value : 103
//value : 104
//value : 105
//value : 106
//value : 107
//value : 108
//value : 109
//value : 110


////------------------------------------------------------------------------------------------------------------------------


/// Question : Demonstration of detach()

void task() {
    std::cout << "Task running in detached thread\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    std::cout << "Detached thread finished\n";
}

//int main() {
//    std::thread t(task);
//
//    // Detach the thread
//    t.detach();
//
//    std::cout << "Main thread does not wait for detached thread\n";
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Main thread finishes early
//    return 0;
//}
//output : Main thread does not wait for detached thread
//         Task running in detached thread

///once main exited no more output :[[[[[[ std::cout << "Detached thread finished\n";]]]] not executed

///////////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Basics of Thread Safety
//Thread safety refers to writing code that behaves correctly when accessed by multiple threads concurrently.Race conditions and data corruption can occur if shared resources are 
//accessed by multiple threads without synchronization.
//Example of a race condition :
// 
// 
//int counter = 0;
//
//void increment() {
//    for (int i = 0; i < 1000; ++i) {
//        ++counter; // Shared resource (not thread-safe)
//    }
//}
//
//int main() {
//    std::thread t1(increment);
//    std::thread t2(increment);
//    t1.join();
//    t2.join();
//
//    std::cout << "Counter: " << counter << "\n"; // Output may be incorrect
//    return 0;
//}
///output : Counter: 1672                         which is wrong xxxxxxxxxx
/// 
/// 
///Fixing race conditions using a mutex :

int counter = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        ++counter; // Protected code
    }
}

//int main() {
//    std::thread t1(increment);
//    std::thread t2(increment);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Counter: " << counter << "\n"; // Correct result due to mutex
//    return 0;
//}

///output : Counter: 2000 


///Summary
//std::thread is used for creating and managing threads.
//Threads enable concurrent execution to improve efficiency.
//Use.join() to wait for threads and .detach() for independent threads.
//Pass arguments via thread constructors or lambdas.
//Ensure thread - safe code by protecting shared resources with synchronization mechanisms like mutexes.