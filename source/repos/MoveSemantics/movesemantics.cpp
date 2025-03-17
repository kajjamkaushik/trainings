//#include <iostream>
//using namespace std;
////struct multipler {
////    int factor;
////    multipler(int f) : factor(f) {}
////
////    int operator()(int value) const { 
////        return factor * value; // Multiply factor with input value
////    }
////};
////int main() {
////    multipler times(3); // Create an instance with factor 3
////    cout << times(5) << endl; // Output: 15 (3 * 5)
////    return 0;
////}
//
////int func()
////{
////	return 10;
////}
//int func(int& a)
//{
//	return a;
//}
//void display(const string& str)
//{
//	cout << "[lvalue] is : " << str << endl;
//}
//void display(const string&& str)
//{
//	cout << "[rvalue] is : " << str << endl;
//}
//int main()
//{
//	//int b = func();
//	int a = 10;
//	int b = func(a); 
//	//b = func(10);/// gives error ::initial value of reference to non-const must be an lvalue
//	//if we add const then error goes away above like int func(const int& a)
//
//	const int& ref = 10; ///single & means lvalue reference
//	int&& q = 10; /// double& means rvalue ref
//
//
//	string str = "ABc";
//	display(str);
//	display(std::move(str));
//	cout <<"Printing the str after move :" << str << endl; 
//	////Use of a moved from object : ''str'' (lifetime.1).
//
//	display("XYZ");
//	return 0;
//}
//
//////[lvalue] is : ABc
////[rvalue] is : ABc
////Printing the str after move : ABc
////[rvalue] is : XYZ