/*
* Understanding std::set in C++ STL (Standard Template Library)
What is std::set?
-std::set is an Associative Container that stores unique elements in a sorted order.
-It does not allow duplicate values.
-Elements are stored in a balanced Red-Black Tree, which ensures efficient insertion, deletion, and lookup.
Key Properties of std::set
-Unique Elements
-Every element in set is stored only once (duplicates are automatically removed).
-Sorted Order (Default: Ascending)
-Elements are always sorted in increasing order by default.
-A custom sorting order can be provided using a comparison function.
-Implemented Using Red-Black Tree
-std::set is typically implemented as a Self-balancing Binary Search Tree (Red-Black Tree).
This ensures logarithmic time complexity (O(log N)) for insertion, deletion, and search.

Logarithmic Complexity
-Insertion, Removal, and Search operations take O(log N) time.
-This makes set efficient for managing ordered unique data.
Custom Comparator Support
-If we want to store user-defined data types, we need to provide a compare function.
Allows sorting elements in ascending or descending order.
*/
//#include <iostream>
//#include <set>
//#include<vector>
//#include<algorithm>
//#include<string>
//#include <functional>
//using namespace std;
//
//// Display function template that works with any set type
//template<typename SetType>
//void display(const SetType& s, const string& msg) {
//    cout << msg;
//    for (const auto& val : s) cout << val << " ";
//    cout << endl;
//}
//class Person {
//public:
//    int age;
//    string name;
//    bool operator < (const Person& rhs) const { return age < rhs.age; }
//    bool operator > (const Person& rhs) const { return age > rhs.age; }
//};
//int main() {
//    cout << "===== STD::SET DEMONSTRATION =====" << endl << endl;
//
//    // ===== 1. MODIFIERS =====
//    cout << "===== 1. MODIFIERS =====" << endl;
//
//    set<int> mySet;
//
//    // insert(value)
//    mySet.insert(10);
//    mySet.insert(20);
//    mySet.insert(30);
//    display(mySet, "After insert(value): ");
//
//    // insert with hint
//    auto it = mySet.find(20);
//    mySet.insert(it, 25);  // Insert with hint
//    display(mySet, "After insert with hint: ");
//
//    // insert range
//    vector<int> v = { 40, 50, 60 };
//    mySet.insert(v.begin(), v.end());
//    display(mySet, "After insert(range): ");
//
//    // emplace(value)
//    mySet.emplace(15);
//    display(mySet, "After emplace(15): ");
//
//    // erase(iterator)
//    it = mySet.find(30);
//    if (it != mySet.end())
//        mySet.erase(it);
//    display(mySet, "After erase(iterator to 30): ");
//
//    // erase(value)
//    mySet.erase(50);
//    display(mySet, "After erase(50): ");
//
//    // erase(range)
//    auto first = mySet.find(15);
//    auto last = mySet.find(40);
//    if (first != mySet.end() && last != mySet.end())
//        mySet.erase(first, last);
//    display(mySet, "After erase(range from 15 to 40): ");
//
//    // swap
//    set<int> anotherSet = { 100, 200, 300 };
//    mySet.swap(anotherSet);
//    display(mySet, "After swap - mySet: ");
//    display(anotherSet, "After swap - anotherSet: ");
//
//    // clear
//    anotherSet.clear();
//    display(anotherSet, "After clear: ");
//
//    // ===== 2. LOOKUP =====
//    cout << "\n===== 2. LOOKUP =====" << endl;
//
//    mySet = { 10, 20, 30, 40, 50 };
//    display(mySet, "Current set: ");
//
//    // find(value)
//    it = mySet.find(30);
//    cout << "find(30): " << (it != mySet.end() ? "Found " + to_string(*it) : "Not found") << endl;
//
//    // count(value)
//    cout << "count(20): " << mySet.count(20) << endl;
//    cout << "count(25): " << mySet.count(25) << endl;
//
//    // equal_range(value)
//    auto range = mySet.equal_range(30);
//    cout << "equal_range(30): ";
//    if (range.first != mySet.end())
//        cout << "lower bound: " << *range.first << ", ";
//    if (range.second != mySet.end())
//        cout << "upper bound: " << *range.second;
//    cout << endl;
//
//    // lower_bound(value)
//    it = mySet.lower_bound(25);
//    cout << "lower_bound(25): " << (it != mySet.end() ? to_string(*it) : "end()") << endl;
//
//    // upper_bound(value)
//    it = mySet.upper_bound(30);
//    cout << "upper_bound(30): " << (it != mySet.end() ? to_string(*it) : "end()") << endl;
//
//    // ===== 3. CAPACITY =====
//    cout << "\n===== 3. CAPACITY =====" << endl;
//
//    // size()
//    cout << "size(): " << mySet.size() << endl;
//
//    // empty()
//    cout << "empty(): " << (mySet.empty() ? "true" : "false") << endl;
//
//    // max_size()
//    cout << "max_size(): " << mySet.max_size() << endl;
//
//    // ===== 4. ITERATORS =====
//    cout << "\n===== 4. ITERATORS =====" << endl;
//
//    // begin() and end()
//    cout << "Iterating with begin() and end(): ";
//    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    // rbegin() and rend() (reverse iteration)
//    cout << "Iterating with rbegin() and rend(): ";
//    for (auto it = mySet.rbegin(); it != mySet.rend(); ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    // cbegin() and cend() (const iterators)
//    cout << "Iterating with cbegin() and cend(): ";
//    for (auto it = mySet.cbegin(); it != mySet.cend(); ++it) {
//        cout << *it << " ";
//        // *it = 100;  // This would cause a compilation error
//    }
//    cout << endl;
//
//    // crbegin() and crend() (const reverse iterators)
//    cout << "Iterating with crbegin() and crend(): ";
//    for (auto it = mySet.crbegin(); it != mySet.crend(); ++it) {
//        cout << *it << " ";
//        // *it = 100;  // This would cause a compilation error
//    }
//    cout << endl;
//
//    // ===== 5. CUSTOM COMPARATORS =====
//    cout << "\n===== 5. CUSTOM COMPARATORS =====" << endl;
//
//    // Using std::less (default)
//    set<int, less<int>> ascendingSet = { 5, 3, 1, 4, 2 };
//    display(ascendingSet, "Ascending order set: ");
//
//    // Using std::greater
//    set<int, greater<int>> descendingSet = { 5, 3, 1, 4, 2 };
//    display(descendingSet, "Descending order set: ");
//
//    // Custom comparator for a set of strings (case-insensitive)
//    struct CaseInsensitiveCompare {
//        bool operator()(const string& a, const string& b) const {
//            string lowerA = a, lowerB = b;
//            transform(a.begin(), a.end(), lowerA.begin(), ::tolower);
//            transform(b.begin(), b.end(), lowerB.begin(), ::tolower);
//            return lowerA < lowerB;
//        }
//    };
//
//    set<string, CaseInsensitiveCompare> caseInsensitiveSet = { "Apple", "banana", "Cherry", "date" };
//    display(caseInsensitiveSet, "Case-insensitive set: ");
//
//
//    cout << "= ==== Custom Set of Type Person ===== =" << endl;
//    set<Person> set1 = { {30,"rupesh"},{25,"shivani"},{10,"Kaushik"} };
//    for (const auto& e : set1) {
//        cout << e.age << " " << e.name << endl;
//    }
//    cout << "desceing order implementation" << endl;
//    set<Person,std::greater<>> set2 = { {30,"rupesh"},{25,"shivani"},{10,"Kaushik"} };
//    for (const auto& e : set2) {
//        cout << e.age << " " << e.name << endl;
//    }
//    return 0;
//}

/* Output :
* ===== STD::SET DEMONSTRATION =====

===== 1. MODIFIERS =====
After insert(value): 10 20 30
After insert with hint: 10 20 25 30
After insert(range): 10 20 25 30 40 50 60
After emplace(15): 10 15 20 25 30 40 50 60
After erase(iterator to 30): 10 15 20 25 40 50 60
After erase(50): 10 15 20 25 40 60
After erase(range from 15 to 40): 10 40 60
After swap - mySet: 100 200 300
After swap - anotherSet: 10 40 60
After clear:

===== 2. LOOKUP =====
Current set: 10 20 30 40 50
find(30): Found 30
count(20): 1
count(25): 0
equal_range(30): lower bound: 30, upper bound: 40
lower_bound(25): 30
upper_bound(30): 40

===== 3. CAPACITY =====
size(): 5
empty(): false
max_size(): 576460752303423487

===== 4. ITERATORS =====
Iterating with begin() and end(): 10 20 30 40 50
Iterating with rbegin() and rend(): 50 40 30 20 10
Iterating with cbegin() and cend(): 10 20 30 40 50
Iterating with crbegin() and crend(): 50 40 30 20 10

===== 5. CUSTOM COMPARATORS =====
Ascending order set: 1 2 3 4 5
Descending order set: 5 4 3 2 1
Case-insensitive set: Apple banana Cherry date
= ==== Custom Set of Type Person ===== =
10 Kaushik
25 shivani
30 rupesh
desceing order implementation
30 rupesh
25 shivani
10 Kaushik
*/