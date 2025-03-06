//// C++ Program to implement
//// Bubble sort
//// using template function
//#include <iostream>
//using namespace std;
//
//// A template function to implement bubble sort.
//// We can use this for any data type that supports
//// comparison operator < and swap works for it.
//template <class T> void bubbleSort(T a[], int n)
//{
//    for (int i = 0; i < n - 1; i++)
//        for (int j = n - 1; i < j; j--)
//            if (a[j] < a[j - 1])
//                swap(a[j], a[j - 1]);
//}
//
//// Driver Code
//int main()
//{
//    int a[5] = { 10, 50, 30, 40, 20 };
//    int n = sizeof(a) / sizeof(a[0]);
//
//    // calls template function
//    bubbleSort<int>(a, n);
//
//    cout << " Sorted array : ";
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << endl;
//
//    return 0;
//}



/// class templatesss

#include<iostream>
using namespace std;
template <typename T> class Array {
private:
	T* ptr;
	int size;
public:
	Array(T arr[], int s);
	void print();
};
template<typename T> Array<T>::Array(T arr[], int s)
{
	ptr = new T[s];
	size = s;
	for (int i = 0;i < size;++i)
	{
		ptr[i] = arr[i];
	}
}
template<typename T>  void Array<T> ::print()
{
	for (int i = 0;i < size;i++)
	{
		cout << " " << *(ptr + i);
	}
	cout << endl;
}
int main()
{
	int arr[5] = { 10,1,16,25,7 };
	Array<int> a1(arr, 5);
	a1.print();
	return 0;
}