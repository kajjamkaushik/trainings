//#include<iostream>
//#include<memory>
//#include<utility>
//using namespace std;
//class Project
//{
//public:
//	Project()
//	{
//		cout << "default project constructor" << endl;
//	}
//};
//class Employee {
//	Project* mptr;
//public:
//	Employee(Project* pptr):mptr(pptr)
//	{
//		cout << "default employee constructor" << endl;
//	}
//};
//int main()
//{
//	shared_ptr<Project> sptr(new Project());
//	cout << "Ref count is : " << sptr.use_count() << endl;
//	shared_ptr<Project> sptr1 = sptr;
//	cout << "Ref count is : " << sptr.use_count() << endl;
//	sptr.reset();
//	cout << "sptr Ref count is : " << sptr.use_count() << endl;
//	cout << "sptr1 Ref count is : " << sptr1.use_count() << endl;
//	return 0;
//}
/////output :
////default project constructor
////Ref count is : 1
////Ref count is : 2
////sptr Ref count is : 0
////sptr1 Ref count is : 1
