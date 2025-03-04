#include<iostream>
using namespace std;
class Distance
{
	int feet, inches;
public:
	Distance()
	{
		feet = 0;
		inches = 0;
	}
	Distance(int ft, int i)
	{
		feet = ft;
		inches = i;
	}
	void displayDistance()
	{
		cout << "distnace is " << feet << "'" << inches << "``" << endl;
	}
	void operator--()
	{
		if (feet > 0)feet = --feet;
		if (inches > 0)inches = --inches;
	}
};
class Time
{
	int hours, mins, secs;
public:
	Time()
	{
		hours = 0;
		mins = 0;
		secs = 0;
	}
	void setTime()
	{
		cout << "\nEnter hours(0-11) ";
		cin >> hours;
		cout << "\nEnter minutes(0-59)";
		cin >> mins;
		cout << "\n Enter secs (0-59)";
		cin >> secs;
	}
	Time operator+(Time t2)
	{
		Time t;
		int s, m;
		s = (secs + t2.secs);
		t.secs = s % 60;
		m = (s / 60) + mins + t2.mins;
		t.mins = m % 60;
		t.hours = hours + t2.hours + (m/ 60);
		t.hours = t.hours % 12;
		return t;
	}
	void show()
	{
		cout << hours << ":" << mins << ":" << secs<<endl;
	}

};
int main()
{
	Time t1, t2, t3;
	cout << "\nEnter the first Time";
	t1.setTime();
	cout << "\nEnter the second time";
	t2.setTime();
	t3 = t1 + t2;
	cout << "First Time ";
	t1.show();
	cout << "Second Time ";
	t2.show();
	cout << "Third Time ";
	t3.show();


//// predecrement operator overloading
	Distance d1(11, 10);
	d1.displayDistance();
	--d1;
	d1.displayDistance();
	return 0;
}