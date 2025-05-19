// TOPIC: Condition Variable In C++ Threading

// IMPORTANT POINT: CV are used for two purpose
//    A. Notify other threads
//    B. Waiting for some conditions

// 1. Condition Variable allows running threads to wait on some conditions and once those conditions are met the waiting thread is notified using :
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable.
// 3. If some thread want to wait on some condition then it has to do these things:
//    a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);
//    b. Execute wait, wait_for, or wait_until. The wait operations atomically release the mutex 
//       and suspend the execution of the thread.
//    c. When the condition variable is notified, the thread is awakened, and the mutex is atomically reacquired.
//       The thread should then check the condition and resume waiting if the wake up was spurious.

// NOTE:
// 1. Condition variables are used to synchronize two or more threads.
// 2. Best use case of condition variable is Producer/Consumer problem.

//#include<mutex>
//#include<iostream>
//#include<condition_variable>
//#include<thread>
//
//using namespace std;
//std::condition_variable cv;
//std::mutex m;
//long balance = 0;
//void addMoney(int money)
//{
//	std::lock_guard<mutex> lg(m);
//	balance += money;
//	cout << "Amount added Current Balance : " << balance << endl;
//	cv.notify_one();
//}
//void withdrowMoney(int money)
//{
//	std::unique_lock<mutex> ul(m);
//	cv.wait(ul, [] { return (balance != 0) ? true : false;});
//	if (balance >= money)
//	{
//		balance -= money;
//		cout << "Amount Deducted : " << money << endl;
//	}
//	else
//	{
//		cout << "Amount Can't Be Deducted ,Current Balance is Less than " << money << endl;
//	}
//	cout << "Current Balance is : " << balance << endl;
//}
//int main()
//{
//	std::thread t1(withdrowMoney, 500);
//	std::thread t2(addMoney, 600);
//	t1.join();
//	t2.join();
//
//	return 0;
//}

//op :
//Amount added Current Balance : 500
//Amount Deducted : 500
//Current Balance is : 0
