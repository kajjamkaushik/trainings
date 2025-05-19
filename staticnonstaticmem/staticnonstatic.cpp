#include<iostream>
using namespace std;
class tempClass
{
public: 
	static int statvar;
	int nonstatvar;
	int p, q;
	static void statfunc()
	{
		statvar++;
		cout << "static var value :" << statvar << endl;
		///cout << "non static var value :" << nonstatvar << endl; //gives error 
	}
	void nonstatfunc()
	{
		statvar++;
		cout << "static var value :" << statvar << endl;
		//can acces the static varibakles inside nonstatic functions reverse is not true
		nonstatvar++;
		cout << "static var value :" << nonstatvar << endl;
	}
	void thisfunc(int x,int y)
	{
		this->p = x;
		this->q = y;
	}
	void constfunc(int x, int y) const
	{
		/*this->p = x;
		this->q = y;*/ /// create error becoz u cant changes the values of any variable
		///ikada compiler will make this object as const ante nonstatic will become the const 
	}
	void constfunc(int x, int y) 
	{
		this->p = x;
		this->q = y;
	}
};
// you can overlaod the function with const qualifier 
int main()
{
	tempClass obj;
	cout << tempClass::statvar++ << endl;
	//const tempClass obj2;
	return 0;
}