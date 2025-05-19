//// C++ Program to implement
//// Bubble sort
//// using template function
//#include <iostream>
//using namespace std;
//
//// A template function to implement bubble sort.
//// We can use this for any data type that supports
//// comparison operator < and swap works for it.
//template <class T> void bubbleSort(T a[], int n)
//{
//    for (int i = 0; i < n - 1; i++)
//        for (int j = n - 1; i < j; j--)
//            if (a[j] < a[j - 1])
//                swap(a[j], a[j - 1]);
//}
//
//// Driver Code
//int main()
//{
//    int a[5] = { 10, 50, 30, 40, 20 };
//    int n = sizeof(a) / sizeof(a[0]);
//
//    // calls template function
//    bubbleSort<int>(a, n);
//
//    cout << " Sorted array : ";
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << endl;
//
//    return 0;
//}



/// class templatesss

//#include<iostream>
//using namespace std;
//template <typename T> class Array {
//private:
//	T* ptr;
//	int size;
//public:
//	Array(T arr[], int s);
//	void print();
//};
//template<typename T> Array<T>::Array(T arr[], int s)
//{
//	ptr = new T[s];
//	size = s;
//	for (int i = 0;i < size;++i)
//	{
//		ptr[i] = arr[i];
//	}
//}
//template<typename T>  void Array<T> ::print()
//{
//	for (int i = 0;i < size;i++)
//	{
//		cout << " " << *(ptr + i);
//	}
//	cout << endl;
//}
//int main()
//{
//	int arr[5] = { 10,1,16,25,7 };
//	Array<int> a1(arr, 5);
//	a1.print();
//	return 0;
//}


//// C++ Program to implement more than one argument for templates 
//// Use of template
//#include <iostream>
//using namespace std;
//template <class T, class U> class A {
//    T x;
//    U y;
//
//public:
//    A() { cout << "Constructor Called" << endl; }
//};
//int main()
//{
//    A<char, char> a;
//    A<int, double> b;
//    return 0;
//}

////specify a default value for template arguments? 
//#include <iostream>
//#include <typeinfo>
//using namespace std;
//template <class T, class U = char>
//class A {
//public:
//    T x;
//    U y;
//    // Parameterized Constructor
//    A(T a, U b) : x(a), y(b) {
//        cout << "Constructor Called" << endl;
//    }
//    // Function to print values
//    void display() {
//        cout << "x: " << x << ", y: " << y << endl;
//    }
//};
//int main()
//{
//    // Creating an object of A<char, char>
//    A<char> a('b', 'c');
//    // Display values
//    a.display();
//    // Display type information
//    cout << "Type of a: " << typeid(a).name() << endl;
//    return 0;
//}
//Both function overloading and templates are examples of polymorphism features of OOP.
//Function overloading is used when multiple functions do quite similar(not identical) operations, 
//templates are used when multiple functions do identical operations.


//Template specialization allows us to have different codes for a particular data type

//We can pass non - type arguments to templates.Non - type parameters are mainly used 
//for specifying max or min values or any other constant value for a particular instance of a template.
//The important thing to note about non - type parameters is, that they must be const.The compiler must 
//know the value of non - type parameters at compile time.Because the compiler needs to create functions / 
//classes for a specified non - type value at compile time.In the below program,
//if we replace 10000 or 256 with a variable, we get a compiler error.


//// C++ program to demonstrate
//// working of non-type parameters
//// to templates in C++
//#include <iostream>
//using namespace std;
//template <class T, int max> int arrMin(T arr[], int n)
//{
//    int m = max;
//    for (int i = 0; i < n; i++)
//        if (arr[i] < m)
//            m = arr[i];
//    return m;
//}
//int main()
//{
//    int arr1[] = { 10, 20, 15, 12 };
//    int n1 = sizeof(arr1) / sizeof(arr1[0]);
//    char arr2[] = { 1, 2, 3 };
//    int n2 = sizeof(arr2) / sizeof(arr2[0]);
//    // Second template parameter
//    // to arrMin must be a
//    // constant
//    cout << arrMin<int, 10000>(arr1, n1) << endl;
//    cout << arrMin<char, 256>(arr2, n2);
//    return 0;
//}
//
//

//// C++ program to show different data types using a
//// constructor and template.
//#include <iostream>
//using namespace std;
//// defining a class template
//template <class T> class info {
//public:
//    // constructor of type template
//    info(T A)
//    {
//        cout << "\n"
//            << "A = " << A
//            << " size of data in bytes:" << sizeof(A);
//    }
//    // end of info()
//}; // end of class
//// Main Function
//int main()
//{
//    // clrscr();
//    // passing character value by creating an objects
//    info<char> p('x');
//    // passing integer value by creating an object
//    info<int> q(22);
//    // passing float value by creating an object
//    info<float> r(2.25);
//    return 0;
//}
//// works well in c++ 17 and above autonatic template type deduction in stl 
//// C++ Program to illustrate template arguments deduction in
//// STL
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    // creating a vector<float> object without specifying
//    // type
//    vector v1{ 1.1, 2.0, 3.9, 4.909 };
//    cout << "Elements of v1 : ";
//    for (auto i : v1) {
//        cout << i << " ";  // op Elements of v1 : 1.1, 2.0, 3.9, 4.909
//    }
//    // creating a vector<int> object without specifying type
//    vector v2{ 1, 2, 3, 4 };
//    cout << endl << "Elements of v2 : ";
//    for (auto i : v2) {
//        cout << i << " ";  // op Elements of v2 : 1, 2, 3, 4
//    }
//}
// 
// 



//// C++ program to illustrate the function template argument
//// deduction
//#include <iostream>
//using namespace std;
//// defining function template
//template <typename t> t multiply(t first, t second)
//{
//    return first * second;
//}
//// driver code
//int main()
//{
//    auto result = multiply(10, 20);
//    std::cout << "Multiplication OF 10 and 20: " << result //op 200
//        << std::endl;
//    return 0;
//}

/*The class template argument deduction was added in C++17 and has since been part of the language.
It allows us to create the class template instances without explicitly definition the types just like function templates.*/


//// C++ Program to implement Class Template Arguments
//// Deduction
//#include <iostream>
//#include <string>
//#include <typeinfo>
//using namespace std;
//// Defining class template
//template <typename T> class student {
//private:
//    string student_name;
//    T total_marks;
//public:
//    // Parameterized constructor
//    student(string n, T m)
//        : student_name(n)
//        , total_marks(m)
//    {
//    }
//    void getinfo()
//    {
//        // printing the details of the student
//        cout << "STUDENT NAME: " << student_name << endl;
//        cout << "TOTAL MARKS: " << total_marks << endl;
//        cout << "Type ID: " << typeid(total_marks).name()
//            << endl;
//    }
//};
//int main()
//{
//    student s1("Vipul", 100); // Deduces student<int>
//    student s2("Yash", 98.5); // Deduces student<double>
//    s1.getinfo();
//    s2.getinfo();
//    return 0;
//}

//output
//STUDENT NAME : Vipul
//TOTAL MARKS : 100
//Type ID : i
//STUDENT NAME : Yash
//TOTAL MARKS : 98.5
//Type ID : d

