//std::span ?
//A lightweight view over a contiguous memory block(like C arrays, std::array, std::vector).
//Does not own the data—just provides access to it.
//Simplifies function interfaces : no need to overload functions for arrays, vectors, etc.
//Helps write generic and type - safe code for iterable containers.
//Offers convenience and performance, without copying.
//
//Supported containers :
//	C - style arrays(int arr[])
//	std::array
//	std::vector
//Capabilities :
//	Can read and modify elements(since it references the data).
//	Cannot resize the underlying container(no ownership).
//Size Template Parameter :
//	std::span<T, Extent> allows specifying fixed size at compile - time.
//	If size isn't known at compile time, use the default dynamic extent:	
//	std::span<int> s(dynamicArray);
//Limitations:
//	Cannot increase or decrease container size.
//	Only works with contiguous containers.

//#include<iostream>
//#include<vector>
//#include<array>
//#include<span>
//using namespace std;
//void printContent(std::span<int> container,string content)
//{
//	cout << content << " : ";
//	for (const auto e : container)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//void modify_content(std::span<int> container)
//{
//	for (auto& e : container)
//	{
//		e *= 2;
//	}
//}
//int main()
//{
//	int a[5]{ 23,57,64,89,10 };
//	printContent(a, "C -style Arrays");
//
//	std::vector<int> v1 = { 1,2,3,4,5,6 };
//	printContent(v1, "Vectors");
//
//	std::array a2{ -14,55,24,67,83 };
//	printContent(a2, "Array");
//
//	///modify the contents 
//	modify_content(v1);
//	printContent(v1, "Vectors");
//
//	modify_content(a2);
//	printContent(a2, "Array");
//
//	modify_content(a);
//	printContent(a, "C -style Arrays");
//	return 0;
//}
//output : 
//C - style Arrays : 23 57 64 89 10
//Vectors : 1 2 3 4 5 6
//Array : -14 55 24 67 83
//Vectors : 2 4 6 8 10 12
//Array : -28 110 48 134 166
//C - style Arrays : 46 114 128 178 20
