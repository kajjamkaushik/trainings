//#include<iostream>
//#include<vector>
//using namespace std;
//
//void printVector(vector<vector<int>>& arr)
//{
//	for (auto& ele : arr)
//	{
//		for (int i : ele)
//		{
//			cout << i << " ";
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	// 1st way
//	vector<vector<int>> arr(5, vector<int>(6, 0));
//
//	// 2nd way
//	int cnt = 1;
//	vector<vector<int>> arr2(4, vector<int>(4));  // Resize the 2D vector first
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//			arr2[i][j] = cnt++;
//	}
//
//	// 3rd way
//	vector<vector<int>> arr3{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//
//	// 4th way
//	vector<vector<int>> arr4;
//	for (int i = 0; i < 5; i++)
//	{
//		vector<int> ele;
//		for (int j = 0; j < 4; j++)  // Fixed condition here
//		{
//			ele.push_back(j);
//		}
//		arr4.push_back(ele);
//	}
//	// Print all vectors
//	cout << "arr:" << endl;
//	printVector(arr);
//
//	cout << "arr2:" << endl;
//	printVector(arr2);
//
//	cout << "arr3:" << endl;
//	printVector(arr3);
//
//	cout << "arr4:" << endl;
//	printVector(arr4);
//
//	return 0;
//}
