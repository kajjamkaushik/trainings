
/*
* # Mutex vs Semaphore in C++

* *Mutex:**
-A mutex is a locking mechanism that provides mutual exclusion
- It allows only one thread to access a resource at a time
- Mutex is binary in nature(locked or unlocked)
- A mutex is owned by the thread that locks it
- Must be unlocked by the same thread that locked it
- In C++11, implemented as `std::mutex` in the standard library
- Primarily used for protecting critical sections
- Cannot be used for signaling between threads
- No internal counter
- Simpler to use for basic thread safety
- Example: protecting a data structure from concurrent access

* *Semaphore : **
-A semaphore is a signaling mechanism
- Can allow multiple threads to access a resource(depending on count)
- Can have multiple values(counting semaphore)
- Not owned by any specific thread
- Can be signaled by any thread, not just the one that waited on it
- In C++20, implemented as `std::counting_semaphore`
- Used for synchronization and controlling access to limited resources
- Can be used for signaling between threads
- Has an internal counter that can be incremented / decremented
- More flexible for complex synchronization scenarios
- Example: limiting the number of threads accessing a pool of resources

*/
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <vector>
//#include<string>
//#include <chrono>
//#include <semaphore> // Requires C++20
//#include <functional>
//
//// For older compilers without std::semaphore, here's a simple implementation
//#ifndef __cpp_lib_semaphore
//class counting_semaphore {
//private:
//    std::mutex mtx;
//    std::condition_variable cv;
//    int count;
//
//public:
//    explicit counting_semaphore(int initial_count) : count(initial_count) {}
//    void acquire() {
//        std::unique_lock<std::mutex> lock(mtx);
//        cv.wait(lock, [this]() { return count > 0; });
//        count--;
//    }
//    void release() {
//        std::unique_lock<std::mutex> lock(mtx);
//        count++;
//        cv.notify_one();
//    }
//};
//#else
//using counting_semaphore = std::counting_semaphore<>;
//#endif
//
//// Shared resources
//std::mutex print_mutex;
//std::mutex resource_mutex;
//counting_semaphore resource_semaphore(3); // Allow 3 threads to access the resource simultaneously
//
//void print(const std::string& message) {
//    std::lock_guard<std::mutex> lock(print_mutex);
//    std::cout << message << std::endl;
//}
//
//// Function demonstrating mutex usage
//void mutex_worker(int id) {
//    print("Thread " + std::to_string(id) + " wants to access the resource (mutex)");
//
//    // With mutex, only one thread can access the resource at a time
//    std::lock_guard<std::mutex> lock(resource_mutex);
//
//    print("Thread " + std::to_string(id) + " is accessing the resource (mutex)");
//    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
//    print("Thread " + std::to_string(id) + " is releasing the resource (mutex)");
//
//    // The mutex is automatically released when lock goes out of scope
//}
//
//// Function demonstrating semaphore usage
//void semaphore_worker(int id) {
//    print("Thread " + std::to_string(id) + " wants to access the resource (semaphore)");
//    // With semaphore, up to 3 threads can access the resource simultaneously
//    resource_semaphore.acquire();
//    print("Thread " + std::to_string(id) + " is accessing the resource (semaphore)");
//    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
//    print("Thread " + std::to_string(id) + " is releasing the resource (semaphore)");
//    resource_semaphore.release();
//}
//
//int main() {
//    std::cout << "MUTEX DEMONSTRATION (only one thread at a time):" << std::endl;
//    std::cout << "------------------------------------------------" << std::endl;
//
//    std::vector<std::thread> mutex_threads;
//    for (int i = 1; i <= 5; i++) {
//        mutex_threads.emplace_back(mutex_worker, i);
//    }
//
//    for (auto& t : mutex_threads) {
//        t.join();
//    }
//
//    std::cout << "\nSEMAPHORE DEMONSTRATION (up to 3 threads at a time):" << std::endl;
//    std::cout << "----------------------------------------------------" << std::endl;
//
//    std::vector<std::thread> semaphore_threads;
//    for (int i = 1; i <= 5; i++) {
//        semaphore_threads.emplace_back(semaphore_worker, i);
//    }
//    for (auto& t : semaphore_threads) {
//        t.join();
//    }
//    return 0;
//}
//
/* Output:
* MUTEX DEMONSTRATION (only one thread at a time):
------------------------------------------------
Thread 1 wants to access the resource (mutex)
Thread 3 wants to access the resource (mutex)
Thread 2 wants to access the resource (mutex)
Thread 4 wants to access the resource (mutex)
Thread 1 is accessing the resource (mutex)
Thread 5 wants to access the resource (mutex)
Thread 1 is releasing the resource (mutex)
Thread 3 is accessing the resource (mutex)
Thread 3 is releasing the resource (mutex)
Thread 2 is accessing the resource (mutex)
Thread 2 is releasing the resource (mutex)
Thread 4 is accessing the resource (mutex)
Thread 4 is releasing the resource (mutex)
Thread 5 is accessing the resource (mutex)
Thread 5 is releasing the resource (mutex)

SEMAPHORE DEMONSTRATION (up to 3 threads at a time):
----------------------------------------------------
Thread 2 wants to access the resource (semaphore)
Thread 1 wants to access the resource (semaphore)
Thread 1 is accessing the resource (semaphore)
Thread 4 wants to access the resource (semaphore)
Thread 3 wants to access the resource (semaphore)
Thread 5 wants to access the resource (semaphore)
Thread 2 is accessing the resource (semaphore)
Thread 4 is accessing the resource (semaphore)
Thread 4 is releasing the resource (semaphore)
Thread 2 is releasing the resource (semaphore)
Thread 1 is releasing the resource (semaphore)
Thread 3 is accessing the resource (semaphore)
Thread 5 is accessing the resource (semaphore)
Thread 3 is releasing the resource (semaphore)
Thread 5 is releasing the resource (semaphore)
*/