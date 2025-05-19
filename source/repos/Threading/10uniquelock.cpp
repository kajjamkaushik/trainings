// TOPIC: unique_lock In C++ (std::unique_lock<mutex> lock(m1))

// NOTES:
// 1. The class unique_lock is a mutex ownership wrapper.
// 2. It Allows:
//    a. Can Have Different Locking Strategies
//    b. Time-constrained attempts at locking (try_lock_for, try_lock_until)
//    c. Recursive locking
//    d. Transfer of lock ownership (move not copy)
//    e. Condition variables. (See this in coming videos)

// Locking Strategies
//		TYPE				EFFECT(S)
// 1. defer_lock  - do not acquire ownership of the mutex.
// 2. try_to_lock - try to acquire ownership of the mutex without blocking.
// 3. adopt_lock  - assume the calling thread already has ownership of the mutex.

//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;
//
//std::mutex m1;
//int buffer = 0;

////EXAMPLE : 1
//void task(const char* threadNumber, int loopFor)
//{
//	std::unique_lock<mutex> lock(m1); //automatically calls lock on mutex m1
//	for (int i = 0;i < loopFor;i++)
//	{
//		buffer++;
//		cout << "threadNumber : " << threadNumber << "buffer : " << buffer << endl;
//	}
//}
//int main()
//{
//	thread t1(task, "1", 10);
//	thread t2(task, "2", 10);
//	t1.join();
//	t2.join();
//	return 0;
//}
//
////output: 
//threadNumber: 2buffer : 1
//threadNumber : 2buffer : 2
//threadNumber : 2buffer : 3
//threadNumber : 2buffer : 4
//threadNumber : 2buffer : 5
//threadNumber : 2buffer : 6
//threadNumber : 2buffer : 7
//threadNumber : 2buffer : 8
//threadNumber : 2buffer : 9
//threadNumber : 2buffer : 10
//threadNumber : 1buffer : 11
//threadNumber : 1buffer : 12
//threadNumber : 1buffer : 13
//threadNumber : 1buffer : 14
//threadNumber : 1buffer : 15
//threadNumber : 1buffer : 16
//threadNumber : 1buffer : 17
//threadNumber : 1buffer : 18
//threadNumber : 1buffer : 19
//threadNumber : 1buffer : 20



//EXAMPLE : 2
//void task(const char* threadNumber, int loopFor)
//{
//	std::unique_lock<mutex> lock(m1,std::defer_lock); //doesnt call lock on mutex m1 immmediatedely just has owned the object to lock
//	/// we can perform sometasks here and then we can lock now 
//	lock.lock(); //but drawback is then we will have to explicitly tell to lock w
//	for (int i = 0;i < loopFor;i++)
//	{
//		buffer++;
//		cout << "threadNumber : " << threadNumber << "buffer : " << buffer << endl;
//	}
//	//lock.unlock() : is not needed as it will be unlocked in destructor of unique_lock 
//}
//int main()
//{
//	thread t1(task, "1", 10);
//	thread t2(task, "2", 10);
//	t1.join();
//	t2.join();
//	return 0;
//}

//output: 
//threadNumber: 1buffer : 1
//threadNumber : 1buffer : 2
//threadNumber : 1buffer : 3
//threadNumber : 1buffer : 4
//threadNumber : 1buffer : 5
//threadNumber : 1buffer : 6
//threadNumber : 1buffer : 7
//threadNumber : 1buffer : 8
//threadNumber : 1buffer : 9
//threadNumber : 1buffer : 10
//threadNumber : 2buffer : 11
//threadNumber : 2buffer : 12
//threadNumber : 2buffer : 13
//threadNumber : 2buffer : 14
//threadNumber : 2buffer : 15
//threadNumber : 2buffer : 16
//threadNumber : 2buffer : 17
//threadNumber : 2buffer : 18
//threadNumber : 2buffer : 19
//threadNumber : 2buffer : 20