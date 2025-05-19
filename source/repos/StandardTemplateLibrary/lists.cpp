//#include<iostream>
//#include<list>
//using namespace std;
//
//void printLists(list<int>& l)
//{
//	for (auto i : l)
//		cout << i << " ";
//	cout << endl;
//}
//
//int main()
//{
//	list<int> list1;
//	list<int> list2 = {10,20,30,40,50};
//	//list<int> list3(5, 20);
//	//printLists(list2);
//	//printLists(list3);
//	//list1.assign(4, 20);
//	//printLists(list1);
//
//	list2.push_back(5);
//	list2.push_front(60);
//	list2.emplace_back(56);
//	list2.emplace_front(13);
//
//	printLists(list2);
//
//	//accesing the list 
//	cout<<"front element "<<list2.front()<<endl;
//	cout << "back element " << list2.back() << endl;
//	///removing the elements from the list 
//	list2.pop_back();
//	list2.pop_front();
//
//	///inserting at nth position 
//	list<int>::iterator itr = list2.begin();
//	std::advance(itr,3);
//	list2.insert(itr, 90);
//
//	///cout << *(itr + 2) << endl; this wont work for lists as they are linked lists and cant be accessed directly 
//
//	*itr = 300;
//	list2.front() = 1000;
//
//	//erasing from the list 
//	list2.erase(itr);
//
//	printLists(list2);
//	return 0;
//}