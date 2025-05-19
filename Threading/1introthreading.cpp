/////ways to create threads in cpp 11
////1. Function Pointers
////2. Lambda Functions
////3. Functors
////4. Member Functions
////5. Static Member Functions
////
//#include<iostream>
//#include<thread>
//#include<chrono>
//#include<algorithm>
//using namespace std;
//using namespace std::chrono;
//typedef unsigned long long ull;
//
///* Note :
//* if we create multiple threads at the same time it doesnt gurantee which one will start first.
// 1. Function Pointer
// this is very basic form of thread creation 
//*/
//
//
//ull oddSum = 0;
//ull evenSum = 0;
//
//void findEven(ull start, ull end)
//{
//	for (ull i = start;i <= end;i++)
//	{
//		if ((i & 1) == 0)
//			evenSum += i;
//	}
//}
//void findOdd(ull start, ull end)
//{
//	for (ull i = start;i <= end;i++)
//	{
//		if ((i & 1) == 1)
//			oddSum += i;
//	}
//}
//int main()
//{
//	ull start = 0, end =1900000000;
//	auto startTime = high_resolution_clock::now();
//	std::thread t1(findEven, start, end);
//	std::thread t2(findOdd, start, end);
//	t1.join();
//	t2.join();
//	//findOdd(start, end);
//	//findEven(start, end);  duration : 4
//	auto stopTime = high_resolution_clock::now();
//	auto duration = duration_cast<microseconds>(stopTime - startTime);
//	cout << "duration : " << duration.count()/1000000 << endl;
//	cout << "Odd Sum : " << oddSum << endl;
//	cout << "Even Sum : " << oddSum << endl;
//	
//	return 0;
//	///op:
//	//duration: 3
//	//Odd Sum : 902500000000000000
//	//Even Sum : 902500000000000000
//}