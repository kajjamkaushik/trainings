//#include<iostream>
//#include<vector>
//using namespace std;
//
///// template function to implement the swap()
//template<typename T>
//void swap(T& a, T& b)
//{
//	T tmp = std::move(a);
//	a = std::move(b);
//	b = std::move(tmp);
//}
//void printVector(vector<int>& arr)
//{
//	cout <<"\nPrint vector:" << endl;
//	for (auto i : arr)cout << i << " ";
//}
//int main()
//{
//	vector<int> v1, v2;
//	for (int i = 0;i < 5;i++)v1.push_back(i);
//	for (int i = 10;i < 15;i++)v2.push_back(i);
//	cout << "Print vector intially" << endl;
//	///printing the vector
//	printVector(v1);	//0 1 2 3 4
//	printVector(v2);    //10 11 12 13 14
//
//	//// assigning the vector v2=v1 
//	//v2 = v1;
//	/////printing again 
//	//printVector(v1);   //0 1 2 3 4
//	//printVector(v2);	//0 1 2 3 4
//	
//	//// using the std::move
//	//v2 = std::move(v1);
//	//printVector(v1);	// blank
//	//printVector(v2);    //0 1 2 3 4
//
//	//swapping the vector using the swap()
//	swap(v1, v2);
//	printVector(v1); //10 11 12 13 14
//	printVector(v2); //0 1 2 3 4
//	return 0;
//}


