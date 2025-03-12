#include<iostream>
using namespace std;
// Template class for shared pointer implementation
template<typename T>
class sharedptr {
private:
    T* res;         // Pointer to the resource
    int* counter;   // Pointer to reference counter
    // Increment the reference counter
    void incrementcounter()
    {
        if (counter)
        {
            (*counter)++;
        }
    }
    // Decrement the reference counter and clean up if needed
    void decrementcounter()
    {
        if (counter)
        {
            (*counter)--;
            if ((*counter) == 0)
            {
                if (res)
                {
                    delete res;
                    delete counter;
                    res = nullptr;
                    counter = nullptr;
                }
            }
        }
    }
public:
    // Default constructor
    sharedptr() : res(nullptr), counter(nullptr) {
        cout << "Default constructor was called" << endl;
    }
    // Constructor with resource pointer
    sharedptr(T* ptr) : res(ptr), counter(nullptr) {
        if (ptr) {
            counter = new int(1);
        }
        cout << "Constructor with resource was called" << endl;
    }
    // Copy constructor
    sharedptr(const sharedptr<T>& ptr)
    {
        res = ptr.res;
        counter = ptr.counter;
        incrementcounter();
        cout << "Copy constructor was called" << endl;
    }
    // Copy assignment operator
    sharedptr<T>& operator= (const sharedptr<T>& ptr)
    {
        if (this != &ptr)  // Fixed: compare addresses, not objects
        {
            decrementcounter();
            res = ptr.res;
            counter = ptr.counter;
            incrementcounter();
        }
        cout << "Copy assignment operator was called" << endl;
        return *this;
    }
    // Move constructor
    sharedptr(sharedptr<T>&& ptr) noexcept
    {
        res = ptr.res;
        counter = ptr.counter;
        ptr.res = nullptr;
        ptr.counter = nullptr;
        cout << "Move constructor was called" << endl;
    }
    // Move assignment operator
    sharedptr<T>& operator= (sharedptr<T>&& ptr) noexcept  // Fixed: removed const
    {
        if (this != &ptr)  // Fixed: compare addresses
        {
            decrementcounter();
            res = ptr.res;
            counter = ptr.counter;
            ptr.res = nullptr;
            ptr.counter = nullptr;
        }
        cout << "Move assignment operator was called" << endl;
        return *this;
    }
    // Reset with no arguments - release current resource
    void reset()
    {
        decrementcounter();
        res = nullptr;
        counter = nullptr;
    }
    // Reset with new resource
    void reset(T* ptr)
    {
        decrementcounter();
        res = ptr;
        counter = ptr ? new int(1) : nullptr;
    }
    // Get reference count
    int get_count() const
    {
        if (counter)
            return (*counter);
        return 0;  // Changed from -1 to 0 as a more logical default
    }
    // Arrow operator for accessing members
    T* operator->() const
    {
        return res;
    }
    // Dereference operator
    T& operator*() const
    {
        return (*res);
    }

    // Get raw pointer
    T* get() const
    {
        return res;
    }

    // Destructor
    ~sharedptr()
    {
        decrementcounter();
        cout << "Destructor was called" << endl;
    }
};

int main()
{
    // Default constructor
    sharedptr<int> ptr1;

    // Parameterized constructor
    sharedptr<int> ptr2(new int(20));

    // Copy constructor
    sharedptr<int> ptr3(ptr2);

    // Copy assignment operator
    ptr3 = ptr2;

    // Move constructor
    sharedptr<int> ptr4(std::move(ptr1));

    // Move assignment operator
    ptr2 = std::move(ptr3);

    // Reset to nullptr
    ptr1.reset();

    // Reset with new resource
    ptr1.reset(new int(100));

    // Dereference operator
    cout << "Value: " << *ptr1 << endl;

    // Get raw pointer
    int* raw_ptr = ptr1.get();

    // Get reference count
    cout << "Reference count: " << ptr1.get_count() << endl;

    return 0;
}