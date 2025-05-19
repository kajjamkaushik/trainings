// TOPIC: STL Algorithm Sort

// NOTES:
// 0. In C++ STL we have sort function which can sort in increasing and decreasing order.
// 1. Not only integral but user defined data can be sorted using this function.
// 2. Internally it uses IntroSort which is combination of QuickSort, HeapSort and InsertionSort.
// 2. By default, it uses QuickSort but if QuickSort is doing unfair partitioning and taking more than N*LogN time,
//    it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort.
// 3. We can use parallel execution policy for better performance.

// TYPES:
// 1. Sorting integral data types
// 2. Sorting user defined data types
// 3. Sort using a function object
// 4. Sort using lambda expression

#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
using namespace std;
///******************************************************************************************************************************//
// 1. Sort with integral data types
//int main() {
//    std::vector<int> Vec{ 5,4,6,7,3,2,8,9,1 };
//    std::sort(std::execution::par, Vec.begin(), Vec.end());
//		///std::excution::par is parallel execution 
//    for (auto elm : Vec) {
//        cout << elm << " ";
//    }
//    return 0;
//}
//output : 1 2 3 4 5 6 7 8 9
///******************************************************************************************************************************//

// 2. Sort with user defined data types

//class Point
//{
//public:
//	int x, y;
//	Point(int x, int y) :x{ x }, y{ y } {}
//	bool operator < (const Point& p1)
//	{
//		return (x + y) < (p1.x + p1.y);
//	}
//};
//int main()
//{
//	vector<Point> vec = { {1,2},{3,1},{0,1} };
//	sort(vec.begin(), vec.end());
//	cout << "Output : "<<endl;
//	for (auto e : vec)
//	{
//		cout << e.x << " "<<e.y<<endl;
//	}
//	return 0;
//}
//Output :
//0 1
//1 2
//3 1

///******************************************************************************************************************************//
//sort using a function object
//struct
//{
//	bool operator()(int a, int b) const
//	{
//		return a < b;
//	}
//}customGreater;
//int main()
//{
//	vector<int> arr{ 5,4,6,7,3,8,9,2,1 };
//	sort(arr.begin(), arr.end(), customGreater);
//	cout << "Output : " << endl;
//	for (auto e : arr)
//	{
//		cout << e<<" ";
//	}
//	return 0;
//}
//Output :
//1 2 3 4 5 6 7 8 9


///******************************************************************************************************************************//
//sort using a lambda function

//int main()
//{
//	vector<int> arr{ 5,4,6,7,3,8,9,2,1 };
//	sort(arr.begin(), arr.end(), [](int a, int b) {return a < b;});
//	cout << "Output : " << endl;
//	for (auto e : arr)
//	{
//		cout << e<<" ";
//	}
//	return 0;
//}
//Output :
//1 2 3 4 5 6 7 8 9