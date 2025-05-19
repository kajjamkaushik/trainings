// NOTES:
// 0. nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:
//    a. The element at the nth position is the one which should be at that position if we sort the list.
//    b. It does not sort the list, just that all the elements, which precede the nth element are not greater than it,
//       and all the elements after it are not less than it.
// 1. nth_element algorithm is implemented using introselect.
//    a. introselect is a hybrid of quickselect and median of medians algorithm.
//       1. quickselect is used to find kth smallest number in an unsorted array.
//       2. median of medians is a median selection algorithm for better pivot selection mainly used in quickselect.

// SUPPORTS TYPES:
// 1. Sorting integral data types
// 2. Sorting user defined data types
// 3. Sort using a function object
// 4. Sort using lambda expression

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
//using namespace std;
//int main() {
//    std::vector<int> v{ 5, 6, 4, 3, 2, 6, 7, 9, 3 };
//    std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end() - 1);
//    cout << "median of the vector : " << v[v.size() / 2]<<endl;
//    cout << "Array Contents : ";
//    for (auto ele : v)cout << ele << " ";
//
//    ///print the second the largest number 
//    std::nth_element(v.begin(), v.end(), v.end(), greater<int>());
//    cout << "\nSecond Largest element in vector :" << v[1]<<endl;
//    cout << "Array Contents : ";
//    for (auto ele : v)cout << ele << " "; // we can say that vector is undistrubted and unsorted but crct results are giving 
//    return 0;
//}
///output :
//median of the vector : 6
//Array Contents : 2 3 4 5 6 6 7 9 3
//Second Largest element in vector : 3
//Array Contents : 2 3 4 5 6 6 7 9 3