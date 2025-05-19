#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//int main()
//{
//	vector<int> arr{ 5, 4, 8, 9, 3, 2, 1, 7, 6 };
//	sort(arr.begin(), arr.end(), greater<int>());
//	cout << "Output : ";
//	for (auto ele : arr)
//	{
//		cout << ele << " ";
//	}
//	//returns true (1) if its sorted in ascending order i.r arr[i-1]<arr[i] else false (0)
//	cout << "\nDescending : is_sorted() : " << is_sorted(arr.begin(),arr.end()) << endl;
//	sort(arr.begin(), arr.end());
//	for (auto ele : arr)
//	{
//		cout << ele << " ";
//	}
//	cout << "\nAscending : is_sorted() : " << is_sorted(arr.begin(), arr.end()) << endl;
//	return 0;
//}
//Output: 9 8 7 6 5 4 3 2 1
//Descending :  is_sorted() : 0
//1 2 3 4 5 6 7 8 9
//Ascending : is_sorted() : 1


///******************************************************************************************************************************//

// 2. Sort with user defined data types

//class Point
//{
//public:
//	int x, y;
//	Point(int x, int y) :x{ x }, y{ y } {}
//	bool operator < (const Point& p1) const
//	{
//		return (x + y) < (p1.x + p1.y);
//	}
//	bool operator > (const Point& p1) const
//	{
//		return (x + y) > (p1.x + p1.y);
//	}
//};
//int main()
//{
//	vector<Point> vec = { {1,2},{3,1},{0,1} };
//	cout<<"before sorting : is_sorted(vec.begin(),vec.end()) : " << is_sorted(vec.begin(), vec.end()) << endl;
//	sort(vec.begin(), vec.end());
//	cout << "Output : "<<endl;
//	for (auto e : vec)
//	{
//		cout << e.x << " "<<e.y<<endl;
//	}
//	cout << "is_sorted(vec.begin(),vec.end()) : " << is_sorted(vec.begin(), vec.end()) << endl;
//	cout << "after Sorting in Descening Order" << endl;
//	for (auto e : vec)
//	{
//		cout << e.x << " " << e.y << endl;
//	}
//	sort(vec.begin(), vec.end(), greater<Point>());
//	cout << "is_sorted(vec.begin(),vec.end()) : " << is_sorted(vec.begin(), vec.end()) << endl;
//	return 0;
//}
//Output :
//before sorting : is_sorted(vec.begin(), vec.end()) : 0
//	0 1
//	1 2
//	3 1
//	is_sorted(vec.begin(), vec.end()) : 1
//	after Sorting in Descening Order
//	0 1
//	1 2
//	3 1
//	is_sorted(vec.begin(), vec.end()) : 0

///******************************************************************************************************************************//
//3. sort using a function object
//struct
//{
//	bool operator()(int a, int b) const
//	{
//		return a > b;
//	}
//}customGreater;
//struct
//{
//	bool operator()(int a, int b) const
//	{
//		return a < b;
//	}
//}customLess;
//int main()
//{
//	vector<int> arr{ 5,4,6,7,3,8,9,2,1 };
//	sort(arr.begin(), arr.end(), customGreater);
//	cout << "Output : " << endl;
//	for (auto e : arr)
//	{
//		cout << e<<" ";
//	}
//	cout << "is_sorted(): "<<is_sorted(arr.begin(),arr.end())<<endl;
//	sort(arr.begin(),arr.end(), customLess);
//	cout << "Ascending Order :" << endl;
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << "is_sorted(): " << is_sorted(arr.begin(), arr.end()) << endl;
//	return 0;
//}
//Output:
//9 8 7 6 5 4 3 2 1 is_sorted() : 0
//Ascending Order :
//1 2 3 4 5 6 7 8 9 is_sorted() : 1


///******************************************************************************************************************************//
// 4 .sort using a lambda function

//int main()
//{
//	vector<int> arr{ 5,4,6,7,3,8,9,2,1 };
//	sort(arr.begin(), arr.end(), [](int a, int b) {return a < b;});
//	cout << "Output : " << endl;
//	for (auto e : arr)
//	{
//		cout << e<<" ";
//	}
//	cout << "is_sorted() : " << is_sorted(arr.begin(), arr.end());
//	return 0;
//}
//Output:
//1 2 3 4 5 6 7 8 9 
//is_sorted() : 1