// TOPIC: forward_List In STL

// 1. This is single linked list what we know from C prgramming language.
// 2. Why forward_list not single_list ?
// 3. We should use this class instead of traditional single linked list because
//    a. Well tested
//    b. Bunch of available function
// 4. Few Available Operations
//    operator =, assign, front, empty, max_size, clear, insert_after, emplace_after, reverse, sort, merge
//    splice_after, unique, remove, remove_if, resize

//#include <iostream>
//#include <forward_list>
//
//using namespace std;
//
//int main() {
//    // Creating two forward lists
//    forward_list<int> list1 = { 5, 4, 6, 2 };
//    forward_list<int> list2 = { 7, 6, 1, 9 };
//
//    // Display list function
//    auto display = [](forward_list<int>& fl, const string& msg) {
//        cout << msg;
//        for (int val : fl) cout << val << " ";
//        cout << endl;
//        };
//
//    display(list1, "Initial List1: ");
//    display(list2, "Initial List2: ");
//
//    // 1. operator= : Assigning list2 to list1
//    list1 = list2;
//    display(list1, "After list1 = list2: ");
//
//    // 2. assign() : Assign new values to list1
//    list1.assign({ 10, 20, 30 });
//    display(list1, "After assign({10, 20, 30}): ");
//
//    // 3. front() : Get first element
//    cout << "Front of list1: " << list1.front() << endl;
//
//    // 4. empty() : Check if list is empty
//    cout << "Is list1 empty? " << (list1.empty() ? "Yes" : "No") << endl;
//
//    // 5. max_size() : Get max possible size (Platform dependent)
//    cout << "Max size of list1: " << list1.max_size() << endl;
//
//    // 6. insert_after() : Insert element after first position
//    list1.insert_after(list1.begin(), 15);
//    display(list1, "After insert_after(begin(), 15): ");
//
//    // 7. emplace_after() : Construct and insert after first element
//    list1.emplace_after(list1.begin(), 25);
//    display(list1, "After emplace_after(begin(), 25): ");
//
//    // 8. reverse() : Reverse the list
//    list1.reverse();
//    display(list1, "After reverse(): ");
//
//    // 9. sort() : Sort the list
//    list1.sort();
//    display(list1, "After sort(): ");
//
//    // 10. merge() : Merge two sorted lists
//    list2.sort(); // Sorting list2 before merging
//    list1.merge(list2);
//    display(list1, "After merging with sorted list2: ");
//
//    // 11. splice_after() : Move elements from one list to another
//    forward_list<int> list3 = { 50, 60, 70 };
//    list1.splice_after(list1.begin(), list3);
//    display(list1, "After splice_after(begin(), list3): ");
//
//    // 12. unique() : Remove consecutive duplicate elements
//    list1.unique();
//    display(list1, "After unique(): ");
//
//    // 13. remove() : Remove all occurrences of a value
//    list1.remove(6);
//    display(list1, "After remove(6): ");
//
//    // 14. remove_if() : Remove elements based on condition
//    list1.remove_if([](int x) { return x < 20; });
//    display(list1, "After remove_if(< 20): ");
//
//    // 15. clear() : Clear all elements
//    list1.clear();
//    cout << "After clear(), is list1 empty? " << (list1.empty() ? "Yes" : "No") << endl;
//
//    return 0;
//}
//output :
/*
* Initial List1: 5 4 6 2
Initial List2: 7 6 1 9
After list1 = list2: 7 6 1 9
After assign({10, 20, 30}): 10 20 30
Front of list1: 10
Is list1 empty? No
Max size of list1: 1152921504606846975
After insert_after(begin(), 15): 10 15 20 30
After emplace_after(begin(), 25): 10 25 15 20 30
After reverse(): 30 20 15 25 10
After sort(): 10 15 20 25 30
After merging with sorted list2: 1 6 7 9 10 15 20 25 30
After splice_after(begin(), list3): 1 50 60 70 6 7 9 10 15 20 25 30
After unique(): 1 50 60 70 6 7 9 10 15 20 25 30
After remove(6): 1 50 60 70 7 9 10 15 20 25 30
After remove_if(< 20): 50 60 70 20 25 30
After clear(), is list1 empty? Yes
*/