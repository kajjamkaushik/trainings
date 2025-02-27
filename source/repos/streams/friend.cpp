//#include<iostream>
//#include<fstream>
//using namespace std;
//class Sample
//{
//	int x;
//	int y;
//public:
//	Sample(int a, int b) :x(10), y(20)
//	{
//		x = a;
//	}
//	int getx()
//	{
//		return x;
//	}
//	void showvalues()
//	{
//		cout << "using friend class " << endl;
//		cout << "x = " << x << "y = " << y << endl;
//	}
//	friend void showclassValues(Sample& s);
//	friend class FriendToSample;
//};
//void showclassValues(Sample& s)
//{
//	cout << "using friend function " << endl;
//	cout << "x = " << s.x << "y = " << s.y << endl;
//
//}
//class FriendToSample
//{
//public:
//	void displaySampleVariables(Sample& s)
//	{
//		cout << "using friend class " << endl;
//		cout << "x = " << s.x << "y = " << s.y << endl;
//	}
//};
//int main() {
//
//	Sample obj(40, 50);
//	cout << obj.getx() << endl;
//	obj.showvalues();
//	///using friend functions we can access the private members of an object
//	showclassValues(obj);
//
//	/// friend class examples
//	FriendToSample fs;
//	fs.displaySampleVariables(obj);
//	return 0;
//}