// TOPIC: std::multiset<T>

// SYNTAX: std::multiset<T> objectName;

// 1. std::multiset is an Associative Container that contains a sorted set of duplicate objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in multiset then we will have to provide 
//    compare function so that multiset can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// multiset is similar to set except it can have multiple elements with same value.

#include <iostream>
#include <set>
#include <string>
#include <functional>
using namespace std;
// Example

 //int main() {
 //    std::cout << "Descending Order " << std::endl;
 //    std::multiset<int, std::greater<int>> multiSet = {5,2,4,3,2,5};
 //    multiSet.insert(20);
 //    for(const auto& e: multiSet) {
 //        cout << e << " ";
 //    }
 //    std::cout << "\n Ascending Order " << std::endl;
 //    std::multiset<int, std::less<int>> multiSet2 = { 5,2,4,3,2,5 };
 //    multiSet.insert(20);
 //    for (const auto& e : multiSet2) {
 //        cout << e << " ";
 //    }
 //    cout << "after erasing all occurences of 2 from the multiset : "<<endl;
 //    multiSet2.erase(2); // delete all occurences of 50 from the multiset
 //    for (const auto& e : multiSet2) {
 //        cout << e << " ";
 //    }
 //    // check if the multiset is empty
 //    cout <<endl<< "\nEmpty: " << multiSet2.empty() << endl;

 //    // check the size of the multiset
 //    cout << "Size: " << multiSet2.size() << endl;

 //    // delete all values from the multiset
 //    multiSet2.clear();

 //    // multiset after clear
 //    cout << "\nThe multiset after clear: ";
 //    for (int i : multiSet2) {
 //        cout << i << "  ";
 //    }

 //    // use the capacity methods again
 //    cout << "\nEmpty: " << multiSet2.empty() << endl;
 //    cout << "Size: " << multiSet2.size() << endl;
 //    return 0;
 //}
 //output :Descending Order 20 5 5 4 3 2 2 
     /*Ascending Order  2 2 3 4 5 5 
     after erasing all occurences of 2 from the multiset :3 4 5 5
     Empty : 0
     Size : 4
     The multiset after clear :
      Empty: 1
      Size : 0*/


//// Example: User Defined
#include <vector>
#include <algorithm>

//class Person {
//public:
//    std::string name;
//    int age;
//
//    // Constructor
//    Person(int a, const std::string& n) : age(a), name(n) {}
//
//    // Comparison operators
//    bool operator < (const Person& rhs) const { return age < rhs.age; }
//    bool operator > (const Person& rhs) const { return age > rhs.age; }
//    bool operator == (const Person& rhs) const { return age == rhs.age && name == rhs.name; }
//};
//
//// Helper function to print a person
//void printPerson(const Person& p) {
//    std::cout << "Age: " << p.age << ", Name: " << p.name;
//}
//
//// Helper function to print iterator information
//void printIterator(const std::multiset<Person>::iterator& it, const std::multiset<Person>& ms, const std::string& label) {
//    if (it != ms.end()) {
//        std::cout << label << ": ";
//        printPerson(*it);
//        std::cout << std::endl;
//    }
//    else {
//        std::cout << label << ": End iterator" << std::endl;
//    }
//}
//
//int main() {
//    std::cout << "=== DEMONSTRATING std::multiset MEMBER FUNCTIONS ===" << std::endl;
//
//    // ===== CONSTRUCTORS =====
//    std::cout << "\n=== CONSTRUCTORS ===" << std::endl;
//
//    // Default constructor
//    std::multiset<Person> ms1;
//    std::cout << "Default constructor: Empty multiset created" << std::endl;
//
//    // Range constructor
//    std::vector<Person> persons = {
//        Person(25, "Alice"),
//        Person(30, "Bob"),
//        Person(22, "Charlie"),
//        Person(25, "David"),  // Duplicate age
//        Person(40, "Eve")
//    };
//    std::multiset<Person> ms2(persons.begin(), persons.end());
//    std::cout << "Range constructor: Multiset created with " << ms2.size() << " elements" << std::endl;
//
//    // Copy constructor
//    std::multiset<Person> ms3(ms2);
//    std::cout << "Copy constructor: Multiset copied with " << ms3.size() << " elements" << std::endl;
//
//    // Initializer list constructor
//    std::multiset<Person> ms4 = {
//        Person(50, "Frank"),
//        Person(35, "Grace"),
//        Person(50, "Hannah")  // Duplicate age
//    };
//    std::cout << "Initializer list constructor: Multiset created with " << ms4.size() << " elements" << std::endl;
//
//    // With custom comparator
//    std::multiset<Person, std::greater<Person>> ms5 = {
//        Person(25, "Ivan"),
//        Person(30, "Julia")
//    };
//    std::cout << "Custom comparator constructor: Multiset created with " << ms5.size() << " elements (descending order)" << std::endl;
//
//    // ===== ASSIGNMENT =====
//    std::cout << "\n=== ASSIGNMENT ===" << std::endl;
//
//    // Copy assignment
//    ms1 = ms4;
//    std::cout << "Copy assignment: ms1 now has " << ms1.size() << " elements" << std::endl;
//
//    // Initializer list assignment
//    ms1 = { Person(60, "Kevin"), Person(55, "Laura") };
//    std::cout << "Initializer list assignment: ms1 now has " << ms1.size() << " elements" << std::endl;
//
//    // ===== GET_ALLOCATOR =====
//    std::cout << "\n=== GET_ALLOCATOR ===" << std::endl;
//    auto alloc = ms1.get_allocator();
//    std::cout << "get_allocator: Retrieved allocator (no visible output)" << std::endl;
//
//    // ===== ITERATORS =====
//    std::cout << "\n=== ITERATORS ===" << std::endl;
//
//    // Create a multiset for iterator demonstration
//    std::multiset<Person> ms_iter = {
//        Person(10, "One"),
//        Person(20, "Two"),
//        Person(30, "Three"),
//        Person(40, "Four"),
//        Person(50, "Five")
//    };
//
//    // begin/end
//    std::cout << "\nbegin/end: Forward iteration:" << std::endl;
//    for (auto it = ms_iter.begin(); it != ms_iter.end(); ++it) {
//        printPerson(*it);
//        std::cout << std::endl;
//    }
//
//    // cbegin/cend
//    std::cout << "\ncbegin/cend: Const forward iteration:" << std::endl;
//    for (auto it = ms_iter.cbegin(); it != ms_iter.cend(); ++it) {
//        printPerson(*it);
//        std::cout << std::endl;
//    }
//
//    // rbegin/rend
//    std::cout << "\nrbegin/rend: Reverse iteration:" << std::endl;
//    for (auto it = ms_iter.rbegin(); it != ms_iter.rend(); ++it) {
//        printPerson(*it);
//        std::cout << std::endl;
//    }
//
//    // crbegin/crend
//    std::cout << "\ncrbegin/crend: Const reverse iteration:" << std::endl;
//    for (auto it = ms_iter.crbegin(); it != ms_iter.crend(); ++it) {
//        printPerson(*it);
//        std::cout << std::endl;
//    }
//
//    // ===== CAPACITY =====
//    std::cout << "\n=== CAPACITY ===" << std::endl;
//
//    // empty
//    std::multiset<Person> empty_ms;
//    std::cout << "empty: ms_iter is " << (ms_iter.empty() ? "empty" : "not empty") << std::endl;
//    std::cout << "empty: empty_ms is " << (empty_ms.empty() ? "empty" : "not empty") << std::endl;
//
//    // size
//    std::cout << "size: ms_iter has " << ms_iter.size() << " elements" << std::endl;
//
//    // max_size
//    std::cout << "max_size: ms_iter can hold up to " << ms_iter.max_size() << " elements" << std::endl;
//
//    // ===== MODIFIERS =====
//    std::cout << "\n=== MODIFIERS ===" << std::endl;
//
//    // Create a multiset for modifier demonstration
//    std::multiset<Person> ms_mod = {
//        Person(10, "Alpha"),
//        Person(20, "Beta"),
//        Person(30, "Gamma")
//    };
//    std::cout << "Initial ms_mod size: " << ms_mod.size() << std::endl;
//
//    // clear
//    std::multiset<Person> ms_clear = ms_mod;
//    ms_clear.clear();
//    std::cout << "clear: ms_clear size after clear: " << ms_clear.size() << std::endl;
//
//    // insert (value)
//    auto insert_result = ms_mod.insert(Person(15, "Delta"));
//    std::cout << "insert (value): Inserted element with age 15" << std::endl;
//    printIterator(insert_result, ms_mod, "insert returned iterator");
//
//    // insert (hint, value)
//    auto hint = ms_mod.lower_bound(Person(25, ""));
//    auto hint_result = ms_mod.insert(hint, Person(25, "Epsilon"));
//    std::cout << "insert (hint, value): Inserted element with age 25" << std::endl;
//    printIterator(hint_result, ms_mod, "insert with hint returned iterator");
//
//    // insert (range)
//    std::vector<Person> more_persons = {
//        Person(35, "Zeta"),
//        Person(40, "Eta"),
//        Person(35, "Theta")  // Duplicate age
//    };
//    ms_mod.insert(more_persons.begin(), more_persons.end());
//    std::cout << "insert (range): Inserted 3 more elements" << std::endl;
//    std::cout << "ms_mod size after range insert: " << ms_mod.size() << std::endl;
//
//    // insert (initializer_list)
//    ms_mod.insert({ Person(45, "Iota"), Person(50, "Kappa") });
//    std::cout << "insert (initializer_list): Inserted 2 more elements" << std::endl;
//    std::cout << "ms_mod size after initializer_list insert: " << ms_mod.size() << std::endl;
//
//    // emplace
//    auto emplace_result = ms_mod.emplace(55, "Lambda");
//    std::cout << "emplace: Constructed and inserted element with age 55" << std::endl;
//    printIterator(emplace_result, ms_mod, "emplace returned iterator");
//
//    // emplace_hint
//    auto emplace_hint = ms_mod.find(Person(50, ""));
//    auto emplace_hint_result = ms_mod.emplace_hint(emplace_hint, 52, "Mu");
//    std::cout << "emplace_hint: Constructed and inserted element with age 52" << std::endl;
//    printIterator(emplace_hint_result, ms_mod, "emplace_hint returned iterator");
//
//    // erase (position)
//    if (!ms_mod.empty()) {
//        auto erase_pos = ms_mod.begin();
//        printIterator(erase_pos, ms_mod, "erase (position): Erasing");
//        ms_mod.erase(erase_pos);
//        std::cout << "ms_mod size after position erase: " << ms_mod.size() << std::endl;
//    }
//
//    // erase (key)
//    size_t erase_count = ms_mod.erase(Person(35, ""));
//    std::cout << "erase (key): Erased " << erase_count << " elements with age 35" << std::endl;
//    std::cout << "ms_mod size after key erase: " << ms_mod.size() << std::endl;
//
//    // erase (range)
//    auto range_begin = ms_mod.find(Person(25, ""));
//    auto range_end = ms_mod.find(Person(45, ""));
//    if (range_begin != ms_mod.end() && range_end != ms_mod.end()) {
//        std::cout << "erase (range): Erasing elements from age 25 to before age 45" << std::endl;
//        ms_mod.erase(range_begin, range_end);
//        std::cout << "ms_mod size after range erase: " << ms_mod.size() << std::endl;
//    }
//
//    // swap
//    std::multiset<Person> ms_swap = { Person(99, "Swap1"), Person(98, "Swap2") };
//    std::cout << "swap: Before swap, ms_mod has " << ms_mod.size() << " elements and ms_swap has " << ms_swap.size() << " elements" << std::endl;
//    ms_mod.swap(ms_swap);
//    std::cout << "swap: After swap, ms_mod has " << ms_mod.size() << " elements and ms_swap has " << ms_swap.size() << " elements" << std::endl;
//
//    // extract (C++17)
//    std::cout << "\nextract (C++17):" << std::endl;
//    if (!ms_swap.empty()) {
//        auto node = ms_swap.extract(ms_swap.begin());
//        if (!node.empty()) {
//            std::cout << "Extracted node with age: " << node.value().age << std::endl;
//
//            // Modify the node
//            Person& p = const_cast<Person&>(node.value());
//            p.name = "Modified" + p.name;
//
//            // Re-insert the node
//            ms_swap.insert(std::move(node));
//            std::cout << "Re-inserted modified node" << std::endl;
//        }
//    }
//
//    // merge (C++17)
//    std::cout << "\nmerge (C++17):" << std::endl;
//    std::multiset<Person> ms_source = { Person(60, "Source1"), Person(70, "Source2") };
//    std::cout << "Before merge: ms_swap has " << ms_swap.size() << " elements, ms_source has " << ms_source.size() << " elements" << std::endl;
//    ms_swap.merge(ms_source);
//    std::cout << "After merge: ms_swap has " << ms_swap.size() << " elements, ms_source has " << ms_source.size() << " elements" << std::endl;
//
//    // ===== LOOKUP =====
//    std::cout << "\n=== LOOKUP ===" << std::endl;
//
//    // Create a multiset for lookup demonstration
//    std::multiset<Person> ms_lookup = {
//        Person(10, "Look1"),
//        Person(20, "Look2"),
//        Person(30, "Look3"),
//        Person(20, "Look4"),  // Duplicate age
//        Person(20, "Look5"),  // Duplicate age
//        Person(40, "Look6")
//    };
//
//    // count
//    int count_result = ms_lookup.count(Person(20, ""));
//    std::cout << "count: There are " << count_result << " elements with age 20" << std::endl;
//
//    // find
//    auto find_result = ms_lookup.find(Person(30, ""));
//    printIterator(find_result, ms_lookup, "find: Found element");
//
//    // contains (C++20)
//#if __cplusplus >= 202002L
//    bool contains_result = ms_lookup.contains(Person(20, ""));
//    std::cout << "contains: ms_lookup " << (contains_result ? "contains" : "does not contain") << " an element with age 20" << std::endl;
//#else
//    std::cout << "contains: Requires C++20 (not demonstrated)" << std::endl;
//#endif
//
//    // equal_range
//    auto equal_range_result = ms_lookup.equal_range(Person(20, ""));
//    std::cout << "equal_range: Elements with age 20:" << std::endl;
//    for (auto it = equal_range_result.first; it != equal_range_result.second; ++it) {
//        printPerson(*it);
//        std::cout << std::endl;
//    }
//
//    // lower_bound
//    auto lower_bound_result = ms_lookup.lower_bound(Person(20, ""));
//    printIterator(lower_bound_result, ms_lookup, "lower_bound: First element not less than age 20");
//
//    // upper_bound
//    auto upper_bound_result = ms_lookup.upper_bound(Person(20, ""));
//    printIterator(upper_bound_result, ms_lookup, "upper_bound: First element greater than age 20");
//
//    // ===== OBSERVERS =====
//    std::cout << "\n=== OBSERVERS ===" << std::endl;
//
//    // key_comp
//    auto key_comparator = ms_lookup.key_comp();
//    bool comp_result = key_comparator(Person(10, ""), Person(20, ""));
//    std::cout << "key_comp: Person with age 10 is " << (comp_result ? "less than" : "not less than") << " Person with age 20" << std::endl;
//
//    // value_comp
//    auto value_comparator = ms_lookup.value_comp();
//    comp_result = value_comparator(Person(10, ""), Person(20, ""));
//    std::cout << "value_comp: Person with age 10 is " << (comp_result ? "less than" : "not less than") << " Person with age 20" << std::endl;
//
//    return 0;
//}
/*
* === DEMONSTRATING std::multiset MEMBER FUNCTIONS ===

=== CONSTRUCTORS ===
Default constructor: Empty multiset created
Range constructor: Multiset created with 5 elements
Copy constructor: Multiset copied with 5 elements
Initializer list constructor: Multiset created with 3 elements
Custom comparator constructor: Multiset created with 2 elements (descending order)

=== ASSIGNMENT ===
Copy assignment: ms1 now has 3 elements
Initializer list assignment: ms1 now has 2 elements

=== GET_ALLOCATOR ===
get_allocator: Retrieved allocator (no visible output)

=== ITERATORS ===

begin/end: Forward iteration:
Age: 10, Name: One
Age: 20, Name: Two
Age: 30, Name: Three
Age: 40, Name: Four
Age: 50, Name: Five

cbegin/cend: Const forward iteration:
Age: 10, Name: One
Age: 20, Name: Two
Age: 30, Name: Three
Age: 40, Name: Four
Age: 50, Name: Five

rbegin/rend: Reverse iteration:
Age: 50, Name: Five
Age: 40, Name: Four
Age: 30, Name: Three
Age: 20, Name: Two
Age: 10, Name: One

crbegin/crend: Const reverse iteration:
Age: 50, Name: Five
Age: 40, Name: Four
Age: 30, Name: Three
Age: 20, Name: Two
Age: 10, Name: One

=== CAPACITY ===
empty: ms_iter is not empty
empty: empty_ms is empty
size: ms_iter has 5 elements
max_size: ms_iter can hold up to 230584300921369395 elements

=== MODIFIERS ===
Initial ms_mod size: 3
clear: ms_clear size after clear: 0
insert (value): Inserted element with age 15
insert returned iterator: Age: 15, Name: Delta
insert (hint, value): Inserted element with age 25
insert with hint returned iterator: Age: 25, Name: Epsilon
insert (range): Inserted 3 more elements
ms_mod size after range insert: 8
insert (initializer_list): Inserted 2 more elements
ms_mod size after initializer_list insert: 10
emplace: Constructed and inserted element with age 55
emplace returned iterator: Age: 55, Name: Lambda
emplace_hint: Constructed and inserted element with age 52
emplace_hint returned iterator: Age: 52, Name: Mu
erase (position): Erasing: Age: 10, Name: Alpha
ms_mod size after position erase: 11
erase (key): Erased 2 elements with age 35
ms_mod size after key erase: 9
erase (range): Erasing elements from age 25 to before age 45
ms_mod size after range erase: 6
swap: Before swap, ms_mod has 6 elements and ms_swap has 2 elements
swap: After swap, ms_mod has 2 elements and ms_swap has 6 elements

extract (C++17):
Extracted node with age: 15
Re-inserted modified node

merge (C++17):
Before merge: ms_swap has 6 elements, ms_source has 2 elements
After merge: ms_swap has 8 elements, ms_source has 0 elements

=== LOOKUP ===
count: There are 3 elements with age 20
find: Found element: Age: 30, Name: Look3
contains: Requires C++20 (not demonstrated)
equal_range: Elements with age 20:
Age: 20, Name: Look2
Age: 20, Name: Look4
Age: 20, Name: Look5
lower_bound: First element not less than age 20: Age: 20, Name: Look2
upper_bound: First element greater than age 20: Age: 30, Name: Look3

=== OBSERVERS ===
key_comp: Person with age 10 is less than Person with age 20
value_comp: Person with age 10 is less than Person with age 20

*/