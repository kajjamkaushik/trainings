// TOPIC: Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section

// Mutex: Mutual Exclusion

// RACE CONDITION:
// 0. Race condition is a situation where two or more threads/process happen to change a common data at the same time.
// 1. If there is a race condition then we have to protect it and the protected section is called critical section/region.

// MUTEX:
// 0. Mutex is used to avoid race condition.
// 1. We use lock(), unlock() on mutex to avoid race condition.

#include <iostream>
#include<mutex>
#include <thread>
using namespace std;
//
//int myAmount = 0;
//std::mutex m;
//void addMoney() {
//    m.lock();
//    ++myAmount;
//    m.unlock();
//}
//
//int main() {
//    std::thread t1(addMoney);
//    std::thread t2(addMoney);
//
//    t1.join();
//    t2.join();
//
//    cout << myAmount << endl;
//    return 0;
//}
// std::mutex::try_lock() On Mutex In C++11 Threading.
/*Few points to remember about the try_lock is as follows :
0. try_lock() Tries to lock the mutex.Returns immediately.On successful lock acquisition returns true otherwise returns false.
1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non - blocking.
2. If try_lock is called again by the same thread which owns the mutex, the behaviour is undefined.
It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)

There are so many try_lock function
1. std::try_lock
2. std::mutex::try_lock
3. std::shared_lock::try_lock
4. std::timed_mutex::try_lock
5. std::unique_lock::try_lock
6. std::shared_mutex::try_lock
7. std::recursive_mutex::try_lock
8. std::shared_timed_mutex::try_lock
9. std::recursive_timed_mutex::try_lock
*/

int counter = 0;
std::mutex mtx;

void increaseTheCounterFor100000Time() {
    for (int i = 0; i < 100000; ++i) {
        if (mtx.try_lock()) {
            ++counter;
            mtx.unlock();
        }
    }
}

int main() {
    std::thread t1(increaseTheCounterFor100000Time);
    std::thread t2(increaseTheCounterFor100000Time);

    t1.join();
    t2.join();

    cout << "counter could increase up to : " << counter << endl;
    ///counter could increase up to : 112128
    return 0;
}

