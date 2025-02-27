#include<iostream>
using namespace std;
class myclass
{
	int x;
	char y;
	int* ptr;

	public:
		//myclass()
		//{

		//}
		myclass(int a)
		{
			x = a;
		}
		void printx() { cout << x << endl; }
		myclass() {
			cout << "Default constructor called " << endl;
		}
		//constrctor overloading
		myclass(int a,char ch)
		{
			x = a;
			y = ch;
		}
		/// <summary>
		/// destructor cant be overloaded called explicitly if not written 
		/// when we have ptrs then we have to write destructor to better keep track of 
		/// </summary>
		/*~myclass()
		{
			cout << "Destructor callled " << endl;
		}*/
		~myclass()
		{
			if(ptr)
			delete ptr;
			cout << "Destructor callled " << endl;
		}
};
int main()
{
	/*myclass obj1;
	myclass obj2(obj1);
	myclass obj3;*/
	/*obj3 = obj2;*/
	myclass obj1(10);
	obj1.printx();
	myclass obj2(20);
	myclass obj3(30);
	myclass obj4;
	///scope and memory 
	{
		int x = 20; ///memory gets free when out of braces
	}
	int y = 30; //goes out of scope when prgm terminated
	//obj1 goes out of scope when destructor is called ,///at last of prgm

	int i = 1;
	myclass obj[12];// cons gets called for 12 times and destructor also calls for 12 times  


	int x; /// compile time // static memory
	int* ptr = new int; /// pointing to memory in heap at run-time

	myclass* objptr=new myclass; /// in stack memory pointing to heap at run-time
	delete objptr;
	return 0;
}