/*
* Understanding pair in C++ STL(Standard Template Library)
	What is a pair in C++ ?
-A pair in C++ is a container defined in the Standard Template Library(STL).
-It allows storing two values(which may be of different types) together as a single unit.
-It is declared in the <utility> header file.

Why Use pair ?
-It is useful when we need to group two pieces of related information.
-Often used in competitive programming and data structures(like maps, graphs).
-Helps store key - value pairs(like a dictionary in Python).


How is pair Implemented?
-Internally, a pair is implemented as a structure containing two members:
*******************************************************************************************************************************
template <class T1, class T2>
struct pair {
    T1 first;
    T2 second;

    pair() : first(T1()), second(T2()) {} // Default constructor
    pair(const T1& a, const T2& b) : first(a), second(b) {} // Parameterized constructor
};
*******************************************************************************************************************************
-This structure allows the storage of two values, which can be accessed as .first and .second.


Use Cases of pair
Key-Value Data Representation (like a dictionary)
Storing Coordinates in Graphs (pair<int, int>)
Storing Min & Max values
Return Multiple Values from a Function
Sorting Data using Pairs (vector<pair<int, string>>)

Summary
pair is a simple yet powerful STL container that stores two values.
It provides efficient ways to group related data without defining a structure.
Used extensively in STL containers like map, vector<pair<T1, T2>>, etc.
make_pair() helps create pairs easily.
It supports operations like access (.first, .second), comparison, and swapping.
This detailed explanation and program should give you a clear understanding of pair in C++.
*/

//#include <iostream>
//#include <utility> // For pair and make_pair
//using namespace std;

//int main() {
//    // 1. Creating pairs
//    pair<int, string> p1(10, "Hello");
//    cout << "Pair 1: " << p1.first << ", " << p1.second << endl;
//
//    // 2. Using make_pair
//    pair<float, double> p2 = make_pair(3.14f, 2.718);
//    cout << "Pair 2: " << p2.first << ", " << p2.second << endl;
//
//    // 3. Pair inside another pair
//    pair<int, pair<string, double>> p3 = { 1, {"Alice", 9.8} };
//    cout << "Pair 3: " << p3.first << ", " << p3.second.first << ", " << p3.second.second << endl;
//
//    // 4. Modifying a pair
//    p1.first = 20;
//    p1.second = "World";
//    cout << "Modified Pair 1: " << p1.first << ", " << p1.second << endl;
//
//    // 5. Comparing pairs
//    pair<int, int> a = { 5, 10 }, b = { 5, 20 };
//    cout << "Comparing pairs: " << (a < b) << endl;  // Output: 1 (true, as 10 < 20)
//
//    // 6. Swapping pairs
//    pair<int, string> p4 = { 100, "SwapTest" };
//    cout << "Before Swap: " << p1.first << ", " << p1.second << " | " << p4.first << ", " << p4.second << endl;
//    p1.swap(p4);
//    cout << "After Swap: " << p1.first << ", " << p1.second << " | " << p4.first << ", " << p4.second << endl;
//
//    // 7. Pair in an array
//    pair<int, string> arr[] = { {1, "One"}, {2, "Two"}, {3, "Three"} };
//    cout << "Array of pairs: " << arr[0].first << ", " << arr[0].second << endl;
//
//    return 0;
//}
/* Output :
* Pair 1: 10, Hello
Pair 2: 3.14, 2.718
Pair 3: 1, Alice, 9.8
Modified Pair 1: 20, World
Comparing pairs: 1
Before Swap: 20, World | 100, SwapTest
After Swap: 100, SwapTest | 20, World
Array of pairs: 1, One
*/