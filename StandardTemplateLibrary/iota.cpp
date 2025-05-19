// TOPIC: STL ALGORITHM std::iota

// NOTES:
// 0. Fills the range [first, last) with sequentially increasing values,
//    starting with value and repetitively evaluating ++value.

//#include <algorithm>
//#include <iostream>
//#include <list>
//#include <numeric>  ///std::iota() is defined in numeric header file
//#include <vector>
//
//using namespace std;
//int main() {
//    // Create a list with 10 elements, initialized from -1 upwards
//    std::list<int> lst(10);
//    std::iota(lst.begin(), lst.end(), -1); // Start filling values from -1, -1, 0, 1, 2, ...
//
//    // Print the contents of the list
//    std::cout << "Contents of list: ";
//    for (auto& ele : lst) {
//        std::cout << ele << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "List contents pasted into vector as initialization: " << std::endl;
//
//    // Create a vector of iterators pointing to elements in the list
//    std::vector<std::list<int>::iterator> arr(lst.size());
//    std::iota(arr.begin(), arr.end(), lst.begin()); // Initialize vector with iterators from list
//
//    // Print the iterator addresses (not values)
//    for (auto& ele : arr) {
//        std::cout << *ele << " "; // Dereference iterators to print actual values
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
///output :
//Contents of list : -1 0 1 2 3 4 5 6 7 8
//List contents pasted into vector as initialization :
//-1 0 1 2 3 4 5 6 7 8