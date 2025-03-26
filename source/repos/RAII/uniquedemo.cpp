//#include<iostream>
//#include<memory>
//#include<utility>
//using namespace std;
//void fun(unique_ptr<int>& uptr)
//{
//	unique_ptr<int> ptr = move(uptr);
//}
//int main()
//{
//	unique_ptr<int> uptr(new int(15));
//	unique_ptr<int> uptr1 = std::make_unique<int>(20);
//	fun(uptr);
//	if(uptr==nullptr)
//	{
//		cout << "uptr is nullptr" << endl;
//	}
//	else 
//		cout << "uptr is not null" << endl;
//	uptr.reset();
//	if (uptr == nullptr)
//	{
//		cout << "uptr is nullptr" << endl;
//	}
//	else
//		cout << "uptr is not null" << endl;
//	uptr.reset(new int(30));
//	if (uptr == nullptr)
//	{
//		cout << "uptr is nullptr" << endl;
//	}
//	else
//		cout << "uptr is not null" << endl;
//	return 0;
//}