//#include<iostream>
//using namespace std;
////void func()
////{
////	for (int i = 0;i < 100000;i++)
////	{
////		cout << "Hey !!";
////		int* a = new int(10);
////		delete a;
////	}
////}
//
/////  implementing RAII 
//class Wrapper {
//private:
//	int* mem;
//public:
//	Wrapper(int* a) :mem(a)
//	{
//		cout << "inside a cons\n";
//	}
//	~Wrapper()
//	{
//		cout << "inside destructor \n";
//		delete mem;
//	}
//};
//int main()
//{
//	//func();
//	Wrapper obj(new int(10));
//	return 0;
//}


//#include<iostream>
//#include<memory>
//using namespace std;
//
//template <typename T>
//class uniqueptr
//{
//private:
//    T* res;
//public:
//    uniqueptr(T* a = nullptr) : res(a)
//    {
//        cout << "inside constructor" << endl;
//    }
//
//    // Delete copy constructor
//    uniqueptr(const uniqueptr<T>& ptr) = delete;
//
//    // Delete copy assignment operator
//    uniqueptr& operator=(const uniqueptr<T>& ptr) = delete;
//
//    // Move constructor
//    uniqueptr(uniqueptr<T>&& ptr) noexcept
//    {
//        res = ptr.res;
//        ptr.res = nullptr;
//        cout << "inside move constructor" << endl;
//    }
//
//    // Move assignment operator
//    uniqueptr& operator=(uniqueptr<T>&& ptr) noexcept
//    {
//        if (this != &ptr)
//        {
//            if (res) delete res;
//            res = ptr.res;
//            ptr.res = nullptr;
//        }
//        cout << "inside move assignment" << endl;
//        return *this;
//    }
//
//    T* operator->()
//    {
//        return res;
//    }
//
//    T& operator*()
//    {
//        return *res;
//    }
//
//    T* get()
//    {
//        return res;  // Fixed: was returning *res
//    }
//
//    void reset(T* newres = nullptr)
//    {
//        if (res) delete res;
//        res = newres;
//    }
//
//    ~uniqueptr()
//    {
//        if (res) delete res;  // Added null check
//        cout << "inside destructor" << endl;
//    }
//};
//
//int main()
//{
//    uniqueptr<int> ptr1(new int(2));
//
//    // These lines would give compilation errors as expected
//    // uniqueptr<int> ptr2(ptr1);   // copy constructor not allowed
//    // uniqueptr<int> ptr3 = ptr1;  // copy constructor not allowed
//
//    uniqueptr<int> ptr4(new int(500));
//    // ptr4 = ptr1;  // copy assignment not allowed
//
//    // Transfer of ownership using move semantics
//    uniqueptr<int> ptr5 = std::move(ptr1);  // Move constructor
//
//    // At this point, ptr1 is in a valid but unspecified state (its res is nullptr)
//
//    ptr4 = std::move(ptr5);  // Move assignment
//
//    // Now ptr5's resource has been moved to ptr4
//
//    // This would cause undefined behavior since ptr1's resource was moved
//    // cout << *ptr1;  // Commented out to prevent undefined behavior
//
//    cout << *ptr4 << endl;  // Should print 2
//
//    int* rawPtr = ptr4.get();
//    cout << "Raw pointer value: " << *rawPtr << endl;
//
//    ptr4.reset(new int(30));
//    cout << "After reset: " << *ptr4 << endl;
//
//    return 0;
//}


///         outputs :::::
//inside constructor
//inside constructor
//inside move constructor
//inside move assignment
//2
//Raw pointer value : 2
//After reset : 30
//inside destructor
//inside destructor
//inside destructor