// TOPIC: STL ALGORITHM copy_n and copy_backward

// NOTES:
// 0. std::copy_n() function is used to copy given number of elements from source to destination.
// 1. std::copy_backward() function copies the elements from the range, defined by [first, last), 
//    to another range ending at d_last. The elements are copied in reverse order (the last element is copied first)
//    but their relative order is preserved.

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<numeric>
//#include<iterator>
//using namespace std;
//
//void printVector(vector<int>& arr,string str)
//{
//	cout << str << " : ";
//	copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
//	cout << endl;
//}
//int main()
//{
//	vector<int> from_vector(10);
//	iota(from_vector.begin(), from_vector.end(), 10);
//
//	
//	//copy_n
//	vector<int> to_vector(5);
//	copy_n(from_vector.begin(), 4, to_vector.begin());
//	printVector(to_vector, "copy_n Demo");
//
//	//copy_backward
//	vector<int> to_vector2(15);
//	copy_backward(from_vector.begin(), from_vector.end(), to_vector2.end());
//	printVector(to_vector2, "copy_backward()");
//	return 0;
//}
//output :
//copy_n Demo : 10 11 12 13 0
//copy_backward() : 0 0 0 0 0 10 11 12 13 14 15 16 17 18 19