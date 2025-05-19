// TOPIC: Timed Mutex In C++ Threading (std::timed_mutex)
// We have learned Mutex, Race Condition, Critical Section in previous video.

// NOTES:
// 0. std::timed_mutex is blocked till timeout_time or the lock is acquired and returns true if success 
//    otherwise false.
// 1. Member Function:
//    a. lock
//    b. try_lock
//    c. try_lock_for     ---> These two functions make it different from mutex.
//    d. try_lock_until   ---
//    e. unlock

// EXAMPLE: try_lock_for();
// Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
// On successful lock acquisition returns true, otherwise returns false.

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

//int myAmount = 0;
//std::timed_mutex m;
//
//void increment(int i) {
//    if (m.try_lock_for(std::chrono::seconds(1))) {
//        ++myAmount;
//        std::this_thread::sleep_for(std::chrono::seconds(2));
//        cout << "Thread " << i << " Entered" << endl;
//        m.unlock();
//    }
//    else {
//        cout << "Thread" << i << "Couldn't Enter" << endl;
//    }
//}
//int main()
//{
//    std::thread t1(increment, 1);
//    std::thread t2(increment, 2);
//
//    t1.join();
//    t2.join();
//
//    cout <<"myAmount : " << myAmount << endl;
//    return 0;
//}
//if t2 waittime is 1 second and t1 sleep time is 2 then 
//ouptut:
//Thread2Couldn't Enter
//Thread 1 Entered
//myAmount : 1

//if t2 waittime is 2 second and t1 sleep time is 1 then 
//op :
//Thread 1 Entered
//Thread 2 Entered
//myAmount : 2\


/// Example program for try_lock_until ............
//int myAmount = 0;
//std::timed_mutex m;
//
//void increment(int i) {
//    auto now = std::chrono::steady_clock::now();
//    if (m.try_lock_until(now+std::chrono::seconds(1))) {
//        ++myAmount;
//        std::this_thread::sleep_for(std::chrono::seconds(2));
//        cout << "Thread " << i << " Entered" << endl;
//        m.unlock();
//    }
//    else {
//        cout << "Thread" << i << "Couldn't Enter" << endl;
//    }
//}
//int main()
//{
//    std::thread t1(increment, 1);
//    std::thread t2(increment, 2);
//
//    t1.join();
//    t2.join();
//
//    cout <<"myAmount : " << myAmount << endl;
//    return 0;
//}

//if t2 waittime is 1 second and t1 sleep time is 2 then 
//ouptut:
//Thread2Couldn't Enter
//Thread 1 Entered
//myAmount : 1

//if t2 waittime is 2 second and t1 sleep time is 1 then 
//op :
//Thread 1 Entered
//Thread 2 Entered
//myAmount : 2
