// TOPIC: STL ALGORITHM copy and copy_if

// NOTES:
// 0. copy Copies the elements in the range, defined by [first, last), to another range beginning at d_first.
// 1. copy_if only copies if predicate returns true.
// 2. if source and destination range are overlapping then the behavior is undefined.

//#include<iostream>
//#include<vector>
//#include<numeric>
////#include<iterator>
//#include<algorithm>
//using namespace std;
//void print(vector<int>& vec)
//{
//	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
//	cout << endl;
//}
//int main()
//{
//	vector<int> from_vector(10);
//	std::iota(from_vector.begin(),from_vector.end(),0);
//	vector<int> to_vector(from_vector.size());
//	copy(from_vector.begin(), from_vector.end(), to_vector.begin());
//	print(to_vector);
//
//	//OR ,altrenatively
//	vector<int> to_vector2;
//	copy(from_vector.begin(), from_vector.end(), back_inserter(to_vector2));
//	print(to_vector2);
//
//
//	///either way si equivalent to 
//	vector<int> tovector = from_vector;
//	//what is the benefits of copy functions if we cna do this ..
//	//Actually you can partially copy elements using copy() function ..
//	cout << endl;
//	copy(from_vector.begin()+2, from_vector.end()-1, back_inserter(to_vector2));
//	print(to_vector2); //copy from 3rd element to last before element
//
//	cout << " Odd numbers in to_vector are : ";
//	vector<int> to_vector3;
//	copy_if(from_vector.begin(), from_vector.end(), back_inserter(to_vector3), [](int x) {
//		return (x % 2) == 1;
//		});
//	print(to_vector3);
//
//
//	return 0;
//}
//output :
//0 1 2 3 4 5 6 7 8 9
//0 1 2 3 4 5 6 7 8 9
//
//0 1 2 3 4 5 6 7 8 9
//2 3 4 5 6 7 8
//Odd numbers in to_vector are : 1 3 5 7 9