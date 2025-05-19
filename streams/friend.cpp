#include<iostream>
#include<fstream>
using namespace std;
class Sample
{
	int x;
	int y;
public:
	Sample(int a, int b) :x(10), y(20)
	{
		x = a;
	}
	int getx()
	{
		return x;
	}
	void showvalues()
	{
		cout << "using friend class " << endl;
		cout << "x = " << x << "y = " << y << endl;
	}
	friend void showclassValues(Sample& s);
	friend class FriendToSample;
};
void showclassValues(Sample& s)
{
	cout << "using friend function " << endl;
	cout << "x = " << s.x << "y = " << s.y << endl;

}
class FriendToSample
{
public:
	void displaySampleVariables(Sample& s)
	{
		cout << "using friend class " << endl;
		cout << "x = " << s.x << "y = " << s.y << endl;
	}
};


/// custom or my own example 
// forward declaration
class ClassB;

class ClassA {
private:
	int numA;

	// friend class declaration
	friend class ClassB;

public:
	// constructor to initialize numA to 12
	ClassA() : numA(12) {}
};

class ClassB {
private:
	int numB;

public:
	// constructor to initialize numB to 1
	ClassB() : numB(1) {}

	// member function to add numA
	// from ClassA and numB from ClassB
	int add() {
		ClassA objectA;
		return objectA.numA + numB;
	}
};

int main() {

	Sample obj(40, 50);
	cout << obj.getx() << endl;
	obj.showvalues();
	///using friend functions we can access the private members of an object
	showclassValues(obj);

	/// friend class examples
	FriendToSample fs;
	fs.displaySampleVariables(obj);

	///friend class my example 
	ClassB objectB;
	cout << "Sum: " << objectB.add();

	return 0;
}
