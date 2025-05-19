//#include<iostream>
//using namespace std;
//
//class SharedPtr
//{
//    void* res;
//    int* counter;
//    void(*deleter)(void*);
//
//    void incrementCounter()
//    {
//        if (counter)
//        {
//            (*counter)++;
//        }
//    }
//
//    void decrementCounter()
//    {
//        if (counter)
//        {
//            (*counter)--;
//            if (*counter == 0)
//            {
//                if (res && deleter)
//                {
//                    deleter(res);
//                }
//                delete counter;
//                res = nullptr;
//                counter = nullptr;
//                deleter = nullptr;
//            }
//        }
//    }
//
//public:
//    // Default constructor
//    SharedPtr() : res(nullptr), counter(nullptr), deleter(nullptr) {}
//
//    // Constructor with resource pointer
//    template<typename T>
//    SharedPtr(T* ptr) : res(ptr), counter(nullptr), deleter(nullptr)
//    {
//        if (ptr)
//        {
//            counter = new int(1);
//            deleter = [](void* p) { delete static_cast<T*>(p); };
//        }
//    }
//
//    // Copy constructor
//    SharedPtr(const SharedPtr& other)
//    {
//        res = other.res;
//        counter = other.counter;
//        deleter = other.deleter;
//        incrementCounter();
//    }
//
//    // Copy assignment operator
//    SharedPtr& operator=(const SharedPtr& other)
//    {
//        if (this != &other)
//        {
//            decrementCounter();
//            res = other.res;
//            counter = other.counter;
//            deleter = other.deleter;
//            incrementCounter(); // Fixed: missing function call parentheses
//        }
//        return (*this);
//    }
//
//    // Move constructor
//    SharedPtr(SharedPtr&& other) noexcept
//    {
//        res = other.res;
//        counter = other.counter;
//        deleter = other.deleter;
//        other.res = nullptr;
//        other.counter = nullptr;
//        other.deleter = nullptr;
//    }
//
//    // Move assignment operator
//    SharedPtr& operator=(SharedPtr&& other) noexcept
//    {
//        if (this != &other)
//        {
//            decrementCounter();
//            res = other.res;
//            counter = other.counter;
//            deleter = other.deleter;
//            other.res = nullptr;
//            other.counter = nullptr;
//            other.deleter = nullptr;
//        }
//        return(*this);
//    }
//
//    // Reset method
//    void reset()
//    {
//        decrementCounter();
//        res = nullptr;
//        counter = nullptr;
//        deleter = nullptr;
//    }
//
//    // Get reference count
//    int use_count() const
//    {
//        return counter ? *counter : 0;
//    }
//
//    // Get raw pointer
//    void* get() const
//    {
//        return res;
//    }
//
//    // Destructor
//    ~SharedPtr()
//    {
//        cout << "destructor called " << endl;
//        decrementCounter();
//    }
//};
//
//// Helper function for type-safe access
//template <typename T>
//T* shared_ptr_cast(const SharedPtr& sp) {
//    return static_cast<T*>(sp.get());
//}
//
//int main()
//{
//    // Test default constructor
//    SharedPtr emptyPtr;
//    cout << "Empty pointer count: " << emptyPtr.use_count() << endl;
//
//    // Test constructor with resource
//    SharedPtr sp1(new int(42));
//    cout << "Reference Count: " << sp1.use_count() << endl;
//
//    // Test copy constructor
//    SharedPtr sp2 = sp1;
//    cout << "Reference Count after copy: " << sp1.use_count() << endl;
//
//    // Test type-safe access
//    int* rawPtr = shared_ptr_cast<int>(sp1);
//    cout << "Value: " << *rawPtr << endl;
//
//    // Test copy assignment operator
//    SharedPtr sp3;
//    sp3 = sp2;
//    cout << "Reference Count after assignment: " << sp2.use_count() << endl;
//
//    // Test move constructor
//    SharedPtr sp4(std::move(emptyPtr));
//
//    // Test move assignment
//    SharedPtr sp5;
//    sp5 = std::move(sp4);
//
//    // Test reset
//    sp1.reset();
//    cout << "Reference Count after reset: " << sp2.use_count() << endl;
//
//    // Verify sp2 and sp3 still hold the value
//    cout << "Value from sp2: " << *shared_ptr_cast<int>(sp2) << endl;
//    cout << "Value from sp3: " << *shared_ptr_cast<int>(sp3) << endl;
//
//    return 0;
//}