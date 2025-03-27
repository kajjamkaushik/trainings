// TOPIC: lock_guard In C++ (std::lock_guard<mutex> lock(m);)

// NOTES:
// 0. It is a very lightweight wrapper for owning mutex on a scoped basis.
// 1. It acquires mutex lock the moment you create the object of lock_guard.
// 2. It automatically removes the lock while going out of scope.
// 3. You cannot explicitly unlock the lock_guard.
// 4. You cannot copy lock_guard.

//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;
//
//std::mutex m1;
//int buffer = 0;
//
/////tradiotional way 
////void task(const char* threadNumber, int loopFor) {
////    m1.lock();
////    for (int i = 0; i < loopFor; ++i) {
////        buffer++;
////        cout << threadNumber << buffer << endl;
////    }
////    m1.unlock();
////}
//
////using lock_guard
//void task(const char* threadNumber, int loopFor) {
//    std::lock_guard<mutex> lock(m1);
//    for (int i = 0; i < loopFor; ++i) {
//        buffer++;
//        cout <<"threadNumber : " << threadNumber << "buffer : " << buffer << endl;
//    }
//    m1.unlock();
//}
//int main() {
//    thread t1(task, "T0 ", 10);
//    thread t2(task, "T1 ", 10);
//    t1.join();
//    t2.join();
//    return 0;
//}


//output :::
//threadNumber: T0 buffer : 1
//threadNumber : T0 buffer : 2
//threadNumber : T0 buffer : 3
//threadNumber : T0 buffer : 4
//threadNumber : T0 buffer : 5
//threadNumber : T0 buffer : 6
//threadNumber : T0 buffer : 7
//threadNumber : T0 buffer : 8
//threadNumber : T0 buffer : 9
//threadNumber : T0 buffer : 10
//D : \a\_work\1\s\src\vctools\crt\github\stl\src\mutex.cpp(151) : unlock of unowned mutex
//threadNumber : T1 buffer : 11
//threadNumber : T1 buffer : 12
//threadNumber : T1 buffer : 13
//threadNumber : T1 buffer : 14
//threadNumber : T1 buffer : 15
//threadNumber : T1 buffer : 16
//threadNumber : T1 buffer : 17
//threadNumber : T1 buffer : 18
//threadNumber : T1 buffer : 19
//threadNumber : T1 buffer : 20
//D : \a\_work\1\s\src\vctools\crt\github\stl\src\mutex.cpp(151) : unlock of unowned mutex