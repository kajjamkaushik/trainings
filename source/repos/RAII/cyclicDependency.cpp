//#include<iostream>
//using namespace std;
//
//class Backend;
//class Frontend
//{
//	shared_ptr<Backend> m_ptr;
//public:
//	Frontend()
//	{
//		cout << "Frontend Constructor" << endl;
//	}
//	~Frontend()
//	{
//	cout << "Frontend Destrcutcor" << endl;
//	}
//	void setBackEndClass(shared_ptr<Backend>& ptr)
//	{
//		m_ptr = ptr;
//	}
//};
//class Backend
//{
//	shared_ptr<Frontend> m_ptr;
//public:
//	Backend(shared_ptr<Frontend>& ptr)
//	{
//		m_ptr = ptr;
//		cout << "Backend Constructor" << endl;
//	}
//	~Backend()
//	{
//		cout << "Backend DEstructor" << endl;
//	}
//};
//
//int main()
//{
//	shared_ptr<Frontend> fptr(new Frontend());
//	shared_ptr<Backend> bptr(new Backend(fptr));
//	fptr->setBackEndClass(bptr);
//	cout << "FrontEnd usecount is :" << fptr.use_count() << endl;
//	cout << "BackEnd usecount is :" << bptr.use_count() << endl;
//	return 0;
//}
//
/////ouptut :
////Frontend Constructor
////Backend Constructor
////FrontEnd usecount is : 2
////BackEnd usecount is : 2
//
//

//#include<iostream>
//using namespace std;
//
//class Backend;
//class Frontend
//{
//	weak_ptr<Backend> m_ptr;
//public:
//	Frontend()
//	{
//		cout << "Frontend Constructor" << endl;
//	}
//	~Frontend()
//	{
//	cout << "Frontend Destrcutcor" << "Backend ptr refcount  " << m_ptr.use_count() << endl;
//	}
//	void setBackEndClass(shared_ptr<Backend>& ptr)
//	{
//		m_ptr = ptr;
//	}
//};
//class Backend
//{
//	weak_ptr<Frontend> m_ptr;
//public:
//	Backend(shared_ptr<Frontend>& ptr)
//	{
//		m_ptr = ptr;
//		cout << "Backend Constructor" << endl;
//	}
//	~Backend()
//	{
//		cout << "Backend DEstructor" <<"Frontend ptr refcount "<<m_ptr.use_count()<< endl;
//	}
//};
//
//int main()
//{
//	shared_ptr<Frontend> fptr(new Frontend());
//	shared_ptr<Backend> bptr(new Backend(fptr));
//	fptr->setBackEndClass(bptr);
//	cout << "FrontEnd usecount is :" << fptr.use_count() << endl;
//	cout << "BackEnd usecount is :" << bptr.use_count() << endl;
//	return 0;
//}
//
/////output ::
////Frontend Constructor
////Backend Constructor
////FrontEnd usecount is : 1
////BackEnd usecount is : 1
////Backend DEstructorFrontend ptr refcount 1
////Frontend DestrcutcorBackend ptr refcount  0
//
//
