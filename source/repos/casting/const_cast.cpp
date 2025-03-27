//1. const_cast
//const_cast is used to cast away the constness of variables.Following are some interesting facts about const_cast.
//
//1) const_cast can be used to change non - const class members inside a const member function.Consider the following 
//code snippet.Inside const member function fun(), ‘this’ is treated by the compiler as ‘const student* const this’,
//i.e.‘this’ is a constant pointer to a constant object, thus compiler doesn’t allow to change the data members through ‘this’ pointer. 
//const_cast changes the type of ‘this’ pointer to ‘student* const this’.
//#include <iostream> 
//using namespace std;
//class student
//{
//private:
//    int roll;
//public:
//    // constructor 
//    student(int r) :roll(r) {}
//    // A const function that changes roll with the help of const_cast 
//    void fun() const //since this function is const we cant change any data inside it 
//    {
//        (const_cast <student*> (this))->roll = 5; // so we are using the const_cast to make it non cast and changeable ..
//    }
//    int getRoll() { return roll; }
//};
//
//int main(void)
//{
//    student s(3);
//    cout << "Old roll number: " << s.getRoll() << endl;
//    s.fun();
//    cout << "New roll number: " << s.getRoll() << endl;
//    return 0;
//}
//op:Old roll number: 3
//   New roll number : 5


//2) const_cast can be used to pass const data to a function that doesn’t receive const.For example, 
//in the following program fun() receives a normal pointer, but a pointer to a const can be passed with the help of const_cast.

//#include <iostream> 
//using namespace std;
//int fun(int* ptr)
//{
//    return (*ptr + 10);
//}
//int main(void)
//{
//    const int val = 10;
//    const int* ptr = &val;
//    ///int* ptr1 = const_cast <int*>(ptr);
//    cout <<"const_cast fun(*ptr) : " << fun(const_cast <int*>(ptr)) << endl; //op : 20
//    cout << "value of *ptr : "<< * ptr << endl;                             //op : 10
//    return 0;
//}


//3) It is undefined behavior to modify a value which is initially declared as const.Consider the following program.
//The output of the program is undefined.The variable ‘val’ is a const variable and the call ‘fun(ptr1)’ tries to
//modify ‘val’ using const_cast.
//#include <iostream> 
//using namespace std;
//int fun(int* ptr)
//{
//    *ptr = *ptr + 10;
//    return (*ptr);
//}
//int main(void)
//{
//    const int val = 10;
//    const int* ptr = &val;
//    int* ptr1 = const_cast <int*>(ptr);
//    cout<<fun(ptr1)<<endl; //op : 20
//    cout << val; //op : 10
//    ///but when  
//    //int val = 10; non const then val becomes 20 when fun(ptr1) 
//    return 0;
//}


//4) const_cast is considered safer than simple type casting.It’safer in the sense that the casting won’t happen 
//if the type of cast is not same as original object.For example, the following program fails in compilation 
//because ‘int* ’ is being typecasted to ‘char* ’
//#include <iostream> 
//using namespace std;
//int main(void)
//{
//    int a1 = 40;
//    const int* b1 = &a1;
//    char* c1 = const_cast <char*> (b1); // compiler error 
//    ///a const_cast can only adjust type qualifiers; it cannot change the underlying type because it trying to convert int to char 
//    *c1 = 'A';
//    return 0;
//}


//5) const_cast can also be used to cast away volatile attribute.For example, in the following program,
//the typeid of b1 is PVKi(pointer to a volatile and constant integer) and typeid of c1 is Pi(Pointer to integer)
//#include <iostream> 
//#include <typeinfo> 
//using namespace std;
//int main(void)
//{
//    int a1 = 40;
//    const volatile int* b1 = &a1;
//    cout << "typeid of b1 " << typeid(b1).name() << '\n';
//    int* c1 = const_cast <int*> (b1);
//    cout << "typeid of c1 " << typeid(c1).name() << '\n';
//    return 0;
//}
//op :
//typeid of b1 int const volatile * __ptr64
//typeid of c1 int* __ptr64