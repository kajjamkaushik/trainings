//#include<iostream>
//using namespace std;
//class UniquePtr
//{
//	void* res;
//	void(*deleter)(void*);
//public:
//	UniquePtr() :res(nullptr), deleter(nullptr)
//	{ }
//	///constructor with resource pointer
//	template<typename T>
//	UniquePtr(T* ptr) : res(ptr), deleter(nullptr)
//	{
//		if (ptr)
//		{
//			deleter = [](void* p) { delete static_cast<T*>(p); };
//		}
//	}
//	~UniquePtr()
//	{
//		cout << "Destructor Called"<<endl;
//		if (res && deleter)
//		{
//			deleter(res);
//		}
//	}
//	/// delete copy constructor
//	UniquePtr(const UniquePtr& ptr) = delete;
//
//	///delete copy assignment operator
//	UniquePtr& operator=(const UniquePtr& ptr) = delete;
//
//	// Move constructor
//    UniquePtr(UniquePtr&& other) noexcept : res(other.res), deleter(other.deleter) {
//        other.res = nullptr;
//        other.deleter = nullptr;
//    }
//	
//	//Move assignment operator
//	UniquePtr& operator=(UniquePtr&& other) noexcept
//	{
//		if (this != &other)
//		{
//			if (res && deleter)
//			{
//				deleter(res);
//			}
//			//move resources from other
//			res = other.res;
//			deleter = other.deleter;
//			other.res = nullptr;
//			other.deleter = nullptr;
//		}
//		return (*this);
//	}
//	//Release Ownership
//	template<typename T>
//	T* release()
//	{
//		T* ptr = static_cast<T*>(res);
//		res = nullptr;
//		deleter = nullptr;
//		return ptr;
//	}
//	///Reset with new resource
//	template<typename T>
//	void reset(T* ptr = nullptr)
//	{
//		//cleanup existing resources
//		if (res && deleter)
//		{
//			deleter(res);
//		}
//		res = ptr;
//		if (ptr)
//		{
//			deleter = [](void* p) {delete static_cast<T*>(p);};
//		}
//		else
//		{
//			deleter = nullptr;
//		}
//	}
//	//get raw pointer
//	template<typename T>
//	T* get() const
//	{
//		return static_cast<T*>(res);
//	}
//	//Deference Operator
//	template<typename T>
//	T& operator*() const
//	{
//		return *static_cast<T*>(res);
//	}
//	// Arrow operator
//	template<typename T>
//	T* operator->() const {
//		return static_cast<T*>(res);
//	}
//
//	// Boolean conversion
//	explicit operator bool() const {
//		return res != nullptr;
//	}
//};
//// Example usage
//int main() {
//	// Default constructor
//	UniquePtr emptyPtr;
//
//	// Constructor with resource
//	UniquePtr intPtr(new int(42));
//
//	// Move constructor
//	UniquePtr movedPtr = std::move(intPtr);
//
//	// Check if original pointer is now empty
//	cout << "intPtr is " << (intPtr.get<int>() ? "not empty" : "empty") << endl;
//
//	// Access value through moved pointer
//	cout << "Value: " << *movedPtr.get<int>() << endl;
//
//	// Create a pointer to a custom class
//	class TestClass {
//	public:
//		TestClass() { cout << "TestClass constructed" << endl; }
//		~TestClass() { cout << "TestClass destroyed" << endl; }
//		void sayHello() { cout << "Hello from TestClass" << endl; }
//	};
//
//	UniquePtr classPtr(new TestClass());
//
//	// Call method using arrow operator
//	classPtr.get<TestClass>()->sayHello();
//
//	// Reset with new resource
//	classPtr.reset<TestClass>(new TestClass());
//
//	// Move assignment
//	UniquePtr anotherPtr;
//	anotherPtr = std::move(classPtr);
//
//	// Release ownership
//	TestClass* rawPtr = anotherPtr.release<TestClass>();
//	cout << "Manually deleting released pointer" << endl;
//	delete rawPtr;
//
//	return 0;
//}
//
/////output :
////intPtr is empty
////Value : 42
////TestClass constructed
////Hello from TestClass
////TestClass constructed
////TestClass destroyed
////Manually deleting released pointer
////TestClass destroyed
////Destructor Called
////Destructor Called
////Destructor Called
////Destructor Called
////Destructor Called