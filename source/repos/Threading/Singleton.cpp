//#include<iostream>
//#include<thread>
//using namespace std;
//class Singleton
//{
//	int val;
//	Singleton()
//	{
//		cout << "Singleton Constructor" << endl;
//		val = 10;
//	}
//	Singleton(const Singleton&)
//	{
//		cout << "Singleton Copy Constructor" << endl;
//	}
//public:
//	static Singleton* myPtr;
//	static Singleton* getObject()
//	{
//		if (myPtr == nullptr)
//			myPtr = new Singleton();
//
//		return myPtr;
//	}
//	void updateVal(int value)
//	{
//		val = value;
//	}
//	int getVal()
//	{
//		return val;
//	}
//};
//Singleton* Singleton::myPtr = nullptr;
//int main()
//{
//	Singleton* sp = Singleton::getObject();
//	cout << sp->getVal() << endl;
//	sp->updateVal(30);
//	//copy constructor
//	Singleton* sp2 = sp;
//	cout << sp2->getVal() << endl;
//
//	//creating again object but doesn't gets created and val is 30 shows object again not creating
//	Singleton* sp3 = Singleton::getObject();
//	cout << sp3->getVal() << endl;
//	return 0;
//}