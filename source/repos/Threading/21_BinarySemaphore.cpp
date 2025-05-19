//#include<iostream>
//#include<chrono>
//#include<semaphore>
//#include<thread>
//using namespace std;
///*Binary Semaphore : is used to for
//* 1. Signaling : is like work is done with me you can start (whereas in mutex ownership ,mutex has i am owner now i can start the work)
//* or when  u are done tell me then i willl start
//*/
//
////global binary semaphore instances
//// object counts are set to zero
//// objects are in non-signaled state 
//
//std::binary_semaphore smphSignalMainToThread{ 0 }, smphSignalThreadToMain{ 0 };
//
//void ThreadProc()
//{
//    //wait for a signal from the main proc
//    //by attempting to decrement the semaphore 
//    smphSignalMainToThread.acquire();
//
//    //this call blocks until the semaphore's count
//    //is increased from the main proc
//    cout << "[thread] Got the signal \n";
//    using namespace std::literals;
//    std::this_thread::sleep_for(3s);
//    cout << "[thread] send the signal \n";
//    smphSignalThreadToMain.release();
//}
//
//int main()
//{
//    //create some worker thread
//    thread thrWorker(ThreadProc);
//    cout << "[main] Send the Signal \n";
//
//    //signal the worker thread to start working
//    //by increasing the semaphore's count
//    smphSignalMainToThread.release();
//
//    //wait until the worker thread is done doing the worker
//    //by attempting to decrement the semaphore's count
//    smphSignalThreadToMain.acquire();  // Fixed the typo here (was smphsignalThreadToMain)
//
//    std::cout << "[main] Got the signal \n"; //response message 
//
//    // Make sure to join the thread before exiting
//    thrWorker.join();
//
//    return 0;
//}
//
///* Output: 
//* [main] Send the Signal 
//  [thread] Got the signal 
//  [thread] send the signal 
//  [main] Got the signal 
//
//
//
//  comments :
//    The execution flow would be:
//    Main thread prints "[main] Send the Signal"
//    Main thread releases the semaphore to signal the worker thread
//    Worker thread acquires the semaphore and prints "[thread] Got the signal"
//    Worker thread sleeps for 3 seconds
//    Worker thread prints "[thread] send the signal" and releases the semaphore
//    Main thread acquires the semaphore and prints "[main] Got the signal"
//    Main thread joins the worker thread and the program exits
//*/