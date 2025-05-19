#include<iostream>
//Dynamic Cast
//In C++, dynamic casting is mainly used for safe downcasting at run time.To work on dynamic_cast 
//there must be one virtual function in the base class.
//A dynamic_cast works only polymorphic base class because it uses this information to decide safe downcasting.
//Syntax:
//dynamic_cast <new_type>(Expression)
//Downcasting : Casting a base class pointer(or reference) to a derived class pointer(or reference) is known as downcasting.
//In figure 1  casting from the Base class pointer / reference to the “derived class 1” pointer / reference showing downcasting(Base->Derived class).
//
//Upcasting : Casting a derived class pointer(or reference) to a base class pointer(or reference) is known as upcasting.
//In figure 1 Casting from Derived class 2 pointer / reference to the “Base class” pointer / reference showing Upcasting(Derived class 2->Base Class).

// C++ program demonstrate if there
// is no virtual function used in
// the Base class
using namespace std;
// Base class declaration
//class Base {
//    void print()
//    {
//        cout << "Base" << endl;
//    }
//};
//// Derived Class 1 declaration
//class Derived1 : public Base {
//    void print()
//    {
//        cout << "Derived1" << endl;
//    }
//};
//// Derived class 2 declaration
//class Derived2 : public Base {
//    void print()
//    {
//        cout << "Derived2" << endl;
//    }
//};
//// Driver Code
//int main()
//{
//    Derived1 d1;
//
//    // Base class pointer hold Derived1
//    // class object
//    Base* bp = dynamic_cast<Base*>(&d1);
//
//    // Dynamic casting
//    Derived2* dp2 = dynamic_cast<Derived2*>(bp);
//    if (dp2 == nullptr)
//        cout << "null" << endl;
//
//    return 0;
//}
//As we mention above for dynamic casting there must be one Virtual function.Suppose If we do not use the virtual function,
//then what is the result ?
//In that case, it generates an error message “Source type is not polymorphic”.
//output : 
//. / Solution.cpp: In function 'int main()' :
//    . / Solution.cpp : 42 : 47 : error : cannot dynamic_cast 'bp' (of type 'class Base*') to type 'class Derived2*' 
// (source type is not polymorphic)   Derived2 * dp2 = dynamic_cast<Derived2*>(bp);

// C++ Program demonstrates successful
// dynamic casting and it returns a
// value of type new_type

//// Base Class declaration
//class Base {
//    virtual void print()
//    {
//        cout << "Base" << endl;
//    }
//};
//
//// Derived1 class declaration
//class Derived1 : public Base {
//    void print()
//    {
//        cout << "Derived1" << endl;
//    }
//};
//
//// Derived2 class declaration
//class Derived2 : public Base {
//    void print()
//    {
//        cout << "Derived2" << endl;
//    }
//};
//
//// Driver Code
//int main()
//{
//    Derived1 d1;
//
//    // Base class pointer holding
//    // Derived1 Class object
//    Base* bp = dynamic_cast<Base*>(&d1);
//
//    // Dynamic_casting
//    Derived1* dp2 = dynamic_cast<Derived1*>(bp);
//    if (dp2 == nullptr)
//        cout << "null" << endl;
//    else
//        cout << "not null" << endl;
//    //Op : not null
//
//    //Case 2: Now, If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
//    Derived2* dp_2= dynamic_cast<Derived2*>(bp);
//    if (dp_2 == nullptr)
//        cout << "null" << endl;
//    //op: null
//    //Case 3:Now take one more case of dynamic_cast, If the cast fails and new_type is a reference type, it throws an exception that matches
//    // a handler of type std::bad_cast and gives a warning: dynamic_cast of “Derived d1” to “class  Derived2&” can never succeed. 
//    // Type casting
//    Derived1* dp3 = dynamic_cast<Derived1*>(bp);
//    if (dp3 == nullptr)
//        cout << "null" << endl;
//    else
//        cout << "not null" << endl;
//    //op: not null
//    
//    // Exception handling block
//    try {
//        Derived2& r1 = dynamic_cast<Derived2&>(d1);
//    }
//    catch (std::exception& e) {
//        cout << e.what() << endl; //op : Bad dynamic_cast!
//    }
//    return 0;
//}
