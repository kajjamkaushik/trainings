// TOPIC: List In STL

// 1. This is double linked list what we know from C prgramming language.
// 2. List is sequence container that allow non-contiguous memory allocation.
// 3. List is faster compared to other sequence containers (vector, forward_list, deque) in terms of 
//    insertion, removal and moving elements in any position provided we have the iterator of the position.
// 4. We should use this class instead of traditional double linked list because
//    a. Well tested
//    b. Bunch of available function
// 5. Few Available Operations
//    operator =, assign, front, back, empty, size, max_size, clear, insert, emplace, push_back, pop_back, push_front
//    pop_front, reverse, sort, merge, splice, unique, remove, remove_if, resize.

//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	auto display = [](list<int>& l, const string& msg) {
//		cout << msg << endl;
//		for (int val : l)cout << val << " ";
//		cout << endl;
//		};
//	list<int> list1 = { 5, 2, 4, 6, 2 };
//	list<int> list2 = { 7,8,3,0,1,9 };
//	
//	display(list1, "intial list1 :");
//	display(list1, "intial list2 :");
//
//	//1 . operator=: assigning list2 to list1 
//	list1 = list2;
//	display(list1, "After list1=lsit2");
//
//	//2.assign() : asssigning new values to list1 
//	list1.assign({ 10,20,30 });
//	display(list1, "after assign({10,20,30})");
//
//	// front and back 
//	cout << "front : " << list1.front() << endl;
//	cout << "back : " << list1.back() << endl;
//
//	// empty and size and maxsize:
//	cout << "Is List Empty ? : " << (list1.empty()?"Yes":"No") << endl;
//	cout << " List Size : " << list1.size() << endl;
//	cout << " Max Size of list: " << list1.size() << endl;
//
//	//7.insert() :Insert element at specific position 
//	auto it = list1.begin();
//	advance(it, 1);
//	list1.insert(it, 56);
//	display(list1, "after inserting 56 at 2nd position");
//
//	//8.emplace() : construct and insert element at specific position 
//	list1.emplace(it, 25);
//	display(list1, "after emplace 25 at 2nd position");
//
//	//push_back :
//	list1.push_back(7);
//	display(list1, "after push_back 7");
//	
//	//push_front :
//	list1.push_front(15);
//	display(list1, "after push_front 15");
//
//	//pop_back :
//	list1.pop_back();
//	display(list1, "after pop_back");
//
//	//pop_back :
//	list1.pop_front();
//	display(list1, "after pop_back");
//
//	//reverse:
//	list1.reverse();
//	display(list1, "after Reverse :");
//
//	//sort():
//	list1.sort();
//	display(list1, "after sort() list1: ");
//
//	//merge two sorted lists
//	list2.sort();
//	list1.merge(list2);
//	display(list1, "list1 after merging list1 and list2");
//	
//	//splice:
//	list1.splice(list1.begin(), list2);
//	display(list1, "list1 after splice list1 and list2");
//
//	//unique:
//	list1.unique();
//	display(list1, "list1 after unique :");
//
//	//remove
//	list1.remove(7);
//	display(list1, "list1 after remove 7 :");
//
//	//remove_if : accepts a lambda function 
//	list1.remove_if([](int x) {return x >20;});
//	display(list1, "list1 after removing element if greater than 20 :");
//
//	//resize():
//	list1.resize(10);
//	display(list1, "list1 after resizing to 10 :");
//
//	//resize():
//	list1.resize(15);
//	display(list1, "list1 after resizing to 15:");
//
//	//clear():
//	list1.clear();
//	display(list1, "list1 after clearing :");
//	return 0;
//
//};

/* Output : 
* intial list1 :
5 2 4 6 2
intial list2 :
5 2 4 6 2
After list1=lsit2
7 8 3 0 1 9
after assign({10,20,30})
10 20 30
front : 10
back : 30
Is List Empty ? : No
 List Size : 3
 Max Size of list: 3
after inserting 56 at 2nd position
10 56 20 30
after emplace 25 at 2nd position
10 56 25 20 30
after push_back 7
10 56 25 20 30 7
after push_front 15
15 10 56 25 20 30 7
after pop_back
15 10 56 25 20 30
after pop_back
10 56 25 20 30
after Reverse :
30 20 25 56 10
after sort() list1:
10 20 25 30 56
list1 after merging list1 and list2
0 1 3 7 8 9 10 20 25 30 56
list1 after splice list1 and list2
0 1 3 7 8 9 10 20 25 30 56
list1 after unique :
0 1 3 7 8 9 10 20 25 30 56
list1 after remove 7 :
0 1 3 8 9 10 20 25 30 56
list1 after removing element if greater than 20 :
0 1 3 8 9 10 20
list1 after resizing to 10 :
0 1 3 8 9 10 20 0 0 0
list1 after resizing to 15:
0 1 3 8 9 10 20 0 0 0 0 0 0 0 0
list1 after clearing :

*/