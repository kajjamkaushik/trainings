//#include<iostream>
//#include<memory>
//using namespace std;
////int main()
////{
////	auto sharedPtr = std::make_shared<int>(100);
////	weak_ptr<int> weakPtr(sharedPtr);
////	cout << "weakPtr.use_count() : " << weakPtr.use_count() << endl; //weakPtr.use_count() : 1
////	cout << " sharedPtr.use_count() : " << sharedPtr.use_count() <<endl;//sharedPtr.use_count() : 1
////	cout << "weakPtr.expired() : " << weakPtr.expired() << endl; //weakPtr.expired() : 0
////	if (shared_ptr<int> sharedPtr1 = weakPtr.lock())
////	{
////		cout << "*sharedPtr:" << *sharedPtr << endl; ///* sharedPtr : 100
////		cout << "sharedPtr1.use_count() :" << sharedPtr1.use_count() << endl; //sharedPtr1.use_count() : 2
////	}
////	else
////	{
////		cout << "Don't get the resource" << endl;
////	}
////	weakPtr.reset();
////	if (shared_ptr<int> sharedPtr1 = weakPtr.lock())
////	{
////		cout << "*sharedPtr:" << *sharedPtr << endl;
////		cout << "sharedPtr1.use_count() :" << sharedPtr1.use_count() << endl;
////	}
////	else
////	{
////		cout << "Don't get the resource" << endl; //op : Don't get the resource
////	}
////	return 0;
////}
////
//
//
////struct Son;
////struct Daughter;
////struct Mother
////{
////	~Mother()
////	{
////		cout << "Mother gone " << endl;
////	}
////	shared_ptr<Son> mySon;
////	shared_ptr<Daughter> myDaughter;
////	void setSon(const shared_ptr<Son> s)
////	{
////		mySon = s;
////	}
////	void setDaughter(const shared_ptr<Daughter> d)
////	{
////		myDaughter = d;
////	}
////};
////struct Son
////{
////	shared_ptr<const Mother> myMother;
////	Son(shared_ptr<Mother> m) :myMother(m){}
////	~Son()
////	{
////		cout << "Son gone" << endl;
////	}
////};
////struct Daughter
////{	
////	shared_ptr<Mother> myMother;
////	Daughter(shared_ptr<Mother> m) :myMother(m) {}
////	~Daughter()
////	{
////		cout << "Daughter Gone" << endl;
////	}
////};
//// 
////int main()
////{
////	shared_ptr<Mother> mother = shared_ptr<Mother>(new Mother);
////	shared_ptr<Son> son = shared_ptr<Son>(new Son(mother));
////	shared_ptr<Daughter> daughter = shared_ptr<Daughter>(new Daughter(mother));
////	mother->setSon(son);
////	mother->setDaughter(daughter);
////	return 0;
////}
///// when sharedptr is used as connection from mother to son and mother to daughter
///// we can observe the destructor is not getting called becouase of cyclic dependency so it doesnt expire
///// so memory leak and cyclcic dependecy can be cleared by using weak_ptr
///// as follows
//
//struct Son;
//struct Daughter;
//struct Mother
//{
//	~Mother()
//	{
//		cout << "Mother gone " << endl;
//	}
//	weak_ptr<Son> mySon;
//	weak_ptr<Daughter> myDaughter;
//	void setSon(const shared_ptr<Son> s)
//	{
//		mySon = s;
//	}
//	void setDaughter(const shared_ptr<Daughter> d)
//	{
//		myDaughter = d;
//	}
//};
//struct Son
//{
//	shared_ptr<const Mother> myMother;
//	Son(shared_ptr<Mother> m) :myMother(m){}
//	~Son()
//	{
//		cout << "Son gone" << endl;
//	}
//};
//struct Daughter
//{	
//	shared_ptr<Mother> myMother;
//	Daughter(shared_ptr<Mother> m) :myMother(m) {}
//	~Daughter()
//	{
//		cout << "Daughter Gone" << endl;
//	}
//};
// 
//int main()
//{
//	shared_ptr<Mother> mother = shared_ptr<Mother>(new Mother);
//	shared_ptr<Son> son = shared_ptr<Son>(new Son(mother));
//	shared_ptr<Daughter> daughter = shared_ptr<Daughter>(new Daughter(mother));
//	mother->setSon(son);
//	mother->setDaughter(daughter);
//	return 0;
//}
