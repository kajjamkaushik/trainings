//#include <iostream>
//#include <vector>
//using namespace std;
//bool compareA(int a, int b) 
//{
//    return a > b; // Bubble sort needs a > b for swapping in ascending order
//}
//bool compareD(int a, int b) 
//{
//    return a < b; // Bubble sort needs a < b for swapping in descending order
//}
//void BubbleSort(vector<int>& v, bool (*bubbleCompare)(int, int))
//{
//    int n = v.size();
//    for (int i = 0; i < n - 1; i++)
//    {
//        bool flag = false;
//        for (int j = 0; j < n - i - 1; j++)
//        {
//            if (bubbleCompare(v[j], v[j + 1]))
//            {
//                swap(v[j], v[j + 1]);
//                flag = true;
//            }
//        }
//        if (!flag)
//            break;
//    }
//    for (auto i : v)
//        cout << i << " ";
//    cout << endl;
//}
//int main()
//{
//    vector<int> v = { 5, 8, 3, 17, 1 };
//    cout << "Ascending order sort: ";
//    vector<int> v1 = v; // Copy the original vector
//    BubbleSort(v1, compareA);
//    cout << "Descending order sort: ";
//    vector<int> v2 = v; // Copy the original vector again
//    BubbleSort(v2, compareD);
//    return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include<iostream>
//#include<vector>
//#include <algorithm> 
//using namespace std;
//class IntComparator
//{
//public:
//	bool operator() (const int& a, const int& b)const
//	{
//		return a > b;
//	}
//};
//int main()
//{
//	vector<int> v{ 15,34,1,89 };
//	IntComparator obj;
//	sort(v.begin(), v.end(), obj);
//	for (auto i : v)
//		cout << i << " ";
//	return 0;
//
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Employee
{
	std::string name;
	int age;
	int idnum;
};
struct CompareBy {
	const std::string SORT_FIELD;
	CompareBy(string Sortfield) :SORT_FIELD(Sortfield)
	{

	}
public:
	bool operator()(const Employee& a, const Employee& b)const
	{
		if (SORT_FIELD == "name") {
			return a.name < b.name;
		}
		else if (SORT_FIELD == "nameD") {
			return a.name > b.name;
		}
		else if (SORT_FIELD == "age") {
			return a.age < b.age;
		}
		else if (SORT_FIELD == "ageD") {
			return a.age > b.age;
		}
		else if (SORT_FIELD == "idnum") {
			return a.idnum< b.idnum;
		}
		else if (SORT_FIELD == "idnumD")
		{
			return a.idnum > b.idnum;
		}
		return false;
	}
};
int main()
{
    std::vector<Employee> emps = { {"xyz", 30, 1102}, {"kaushik", 22, 439} ,{"shivani", 21, 312} };
    std::sort(emps.begin(), emps.end(), CompareBy("age"));
    for (auto a : emps) {
        std::cout << a.name << " " << a.age << " " << a.idnum << std::endl;
    }
	std::sort(emps.begin(), emps.end(), CompareBy("named"));
	for (auto a : emps) {
		std::cout << a.name << " " << a.age << " " << a.idnum << std::endl;
	}
    return 0;
}