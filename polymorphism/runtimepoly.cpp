//#include<iostream>
//using namespace std;
//class Base {
//public:
//	void display(){
//	cout << "this is base class function "<<endl;
//	}
//	virtual void print()
//	{
//		cout << "this is base print" << endl;
//	}
//	Base()
//	{
//		cout << "Base class Constructor" << endl;
//	}
//};
///// explore the use of private inheritance and why it is useful in cpp
//class Derive : public Base
//{
//public:
//	virtual void display()
//	{
//		cout << "this is derive class function "<< endl;
//	}
//};
//class Derive1 : virtual public Base {
//public:
//	Derive1()
//	{
//		cout << "this is derive class 1 constructor" << endl;
//	}
//};
//class Derive2 : virtual public Base
//{
//public:
//	Derive2()
//	{
//		cout << "This is Derive Class 2 constructor" << endl;
//	}
//};
//class child :public Derive1, Derive2
//{
//public:
//	child() { cout << "child class constructor" << endl; }
//};
//int main()
//{
//	Derive obj;
//	obj.display();
//	Base* base = &obj;
//	obj.display();
//
//	Base* b = new Derive();
//	b->display(); // base class virtual if there points to derive class def else base class def 
//	b->print();
//	cout << "\n\n\n";
//
//	child obj1;
//	return 0;
//}