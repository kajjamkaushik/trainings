#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;

/// Creating Deamon threads and using
//void Daemon()
//{
//	while (1)
//	{
//		cout << "I am Daemon THread ,no one can kill me until the process terminated"<<endl;
//		std::this_thread::sleep_for(1000ms);
//	}
//}
//
//int main()
//{
//	std::thread t1(Daemon);
//	t1.detach();
//	std::this_thread::sleep_for(5000ms);
//	return 0;
//}


///move threads ownership in multithreading in cpp
//void worker(int num)
//{
//	cout << "i am worker thread no "<<num << endl;
//}
//int main()
//{
//	vector<std::thread> workers;
//	for (int i = 0;i < 10;i++)
//	{
//		std::thread t = std::thread(worker, i);
//		workers.push_back(std::move(t));
//	}
//	std::for_each(workers.begin(), workers.end(), [](std::thread& t)
//		{
//			assert(t.joinable());
//			t.join();
//		});
//	return 0;
//}
///identifying threads at runtime 
void worker()
{
	cout << "Actual Thread and its ID: " << std::this_thread::get_id() << endl;
}
int main() {
	vector<std::thread> workers;
	for (int i = 0;i < 3;i++)
	{
		cout << endl;
		workers.emplace_back(std::thread(worker));
		std::this_thread::sleep_for(std::chrono::seconds(1));
		cout << "Created thread and its ID : " << workers[i].get_id() << endl;
	}
	for_each(workers.begin(), workers.end(), [](std::thread& t) {
		assert(t.joinable());
		t.join();
		});
	return 0;
}



