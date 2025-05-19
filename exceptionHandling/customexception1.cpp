//#include <iostream>
//using namespace std;
//class demo1 {
//};
//class demo2 {
//};
//int main()
//{
//	for (int i = 1; i <= 2; i++) {
//		try {
//			if (i == 1)
//				throw demo1();
//
//			else if (i == 2)
//				throw demo2();
//		}
//		catch (demo1 d1) {
//			cout << "Caught exception of demo1 class \n";
//		}
//		catch (demo2 d2) {
//			cout << "Caught exception of demo2 class \n";
//		}
//	}
//}
//outptu::
//Caught exception of demo1 class
//Caught exception of demo2 class

//										Exception handling with inheritance :

//Exception handling can also be implemented with the help of inheritance.In case of inheritance object
//thrown by derived class is caught by the first catch block.
//#include <iostream>
//using namespace std;
//class demo1 {
//};
//class demo2 : public demo1 {
//};
//int main()
//{
//	for (int i = 1; i <= 2; i++) {
//		try {
//			if (i == 1)
//				throw demo1();
//
//			else if (i == 2)
//				throw demo2();
//		}
//		catch (demo1 d1) {
//			cout << "Caught exception of demo1 class \n";
//		}
//		catch (demo2 d2) {
//			cout << "Caught exception of demo2 class \n";
//		}
//	}
//}
//caught both times demo1 becuase demo1 is base class of demo2 and demo1 handler is placed at top 
//Caught exception of demo1 class
//Caught exception of demo1 class


//#include <iostream>
//using namespace std;
//class demo1 {
//};
//class demo2 : public demo1 {
//};
//int main()
//{
//	for (int i = 1; i <= 2; i++) {
//		try {
//			if (i == 1)
//				throw demo1();
//
//			else if (i == 2)
//				throw demo2();
//		}
//		catch (demo2 d2) {
//			cout << "Caught exception of demo2 class \n";
//		}
//		catch (demo1 d1) {
//			cout << "Caught exception of demo1 class \n";
//		}
//	}
//}

//output : becoz demo2 handler is placed at top this time 
//Caught exception of demo1 class
//Caught exception of demo2 class


//#include <iostream>
//using namespace std;
//class demo {
//	int num;
//public:
//	demo(int x)
//	{
//		try {
//			cout << "constructor called " << endl;
//			if (x == 0)
//				// catch block would be called
//				throw "Zero not allowed ";
//			num = x;
//			show();
//		}
//		catch (const char* exp) {
//			cout << "Exception caught \n ";
//			cout << exp << endl;
//		}
//	}
//	~demo()
//	{
//		cout << "destructor called " << endl;
//	}
//	void show()
//	{
//		cout << "Num = " << num << endl;
//	}
//};
//int main()
//{
//	// constructor will be called
//	demo(0);
//	cout << "Again creating object \n";
//	demo(1);
//	return 0;
//}
//output :
//constructor called
//Exception caught
//Zero not allowed
//destructor called
//Again creating object
//constructor called
//Num = 1
//destructor called


