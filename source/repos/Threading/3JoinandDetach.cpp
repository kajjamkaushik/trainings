//#include<iostream>
//#include<thread>
//#include<chrono>
//#include<algorithm>
//using namespace std;
//using namespace std::chrono;
//
//
//// TOPIC: Use Of join(), detach() and joinable() In Thread In C++ (C++11)
//
//// JOIN NOTES
//// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
//// 1. Double join will result into program termination.
//// 2. If needed we should check thread is joinable before joining. ( using joinable() function)
//
//// DETACH NOTES
//// 0. This is used to detach newly created thread from the parent thread.
//// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and
////    double detach() will result into program termination.
//// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.
//
//// NOTES:
//// Either join() or detach() should be called on thread object, otherwise during thread object's destructor it will
//// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.
//void run(int count)
//{
//	while(count-->0)
//	cout << "CppNuts" << endl;
//	//std::this_thread::sleep_for(chrono::seconds(3));
//}
//int main()
//{
//	//std::thread t1(run, 5);
//	//t1.join();
//	////t1.join();  Double join will result into program termination.
//	////so we can add somthing joinable for program to not to terminate
//	//if (t1.joinable())
//	//	t1.join(); /// doesnt fails this time
//	//
//	//cout << "main()  after :" << endl;
//	///-------------------------------detach ----------------------------
//	std::thread t1(run, 5);
//	cout << "main()  :" << endl;
//	t1.detach();
//	cout << "main()  after :" << endl;
//	std::this_thread::sleep_for(chrono::seconds(3));
//	///output :
//	/*main() :
//		main()  after :
//		CppNuts
//		CppNuts*/
//	//t1.detach();  Double detach  will result into program termination.
//	//so we can add somthing joinable for program to not to terminate
//	if (t1.joinable())
//		t1.detach(); /// doesnt fails this time
//	
//	return 0;
//}