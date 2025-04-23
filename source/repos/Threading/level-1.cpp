#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>
using namespace std;
//Question-1 : What happens if a thread is not joined or detached? What are the risks?
int thread1()
{
	cout << "Inside thread 1 " << endl;
}
int main()
{	
	cout << "inside main -1 " << endl;
	std::thread t1(thread1);
	cout << "inside main at end  " << endl;
	return 0;
}
//output : 
//inside main 
//inside main at end
//terminate called without an active exception