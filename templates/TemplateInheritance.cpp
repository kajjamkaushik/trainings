#include<iostream>
using namespace std;
class Base
{
public:
	int value;
	Base()
	{
		cout << "inside base default constructor";
	}
	Base(int x):value(x)
	{
		cout << "Inside bASE CLASS parameterised constructor" << endl;
	}
};
template<typename T>
class Test:public Base
{
private:
	
public:
	T a;
	Test(T b,int s) :Base(s),a(b)
	{
		cout << "inside parametirsed constructor" << endl;
	}
	Test()
	{
		cout << "inside default constructor constructor" << endl;
	}
};
int main() {
	Test<int> obj(10,20);
	cout << "value: " << obj.a << endl;
	cout << "base value : " << obj.value << endl;
	
	return 0;
}