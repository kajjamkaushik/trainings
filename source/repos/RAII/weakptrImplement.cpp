#include <iostream>
using namespace std;

// Forward declaration
template<typename T>
class WeakPtr;

// Control block for reference counting
struct ControlBlock {
    size_t shared_count = 1;     // Number of SharedPtr instances
    size_t weak_count = 0;       // Number of WeakPtr instances

    void increment_shared() { ++shared_count; }
    void decrement_shared() { --shared_count; }
    void increment_weak() { ++weak_count; }
    void decrement_weak() { --weak_count; }

    bool should_delete_resource() const { return shared_count == 0; }
    bool should_delete_control_block() const { return shared_count == 0 && weak_count == 0; }
};

template<typename T>
class SharedPtr {
    friend class WeakPtr<T>;

private:
    T* resource = nullptr;
    ControlBlock* control_block = nullptr;

public:
    // Default constructor
    SharedPtr() : resource(nullptr), control_block(nullptr) {}

    // Constructor with resource
    explicit SharedPtr(T* ptr) : resource(ptr) {
        if (ptr) {
            control_block = new ControlBlock();
        }
    }

    // Constructor from WeakPtr
    explicit SharedPtr(const WeakPtr<T>& weak_ptr) {
        if (!weak_ptr.expired()) {
            resource = weak_ptr.resource;
            control_block = weak_ptr.control_block;
            if (control_block) {
                control_block->increment_shared();
            }
        }
    }

    // Copy constructor
    SharedPtr(const SharedPtr& other) : resource(other.resource), control_block(other.control_block) {
        if (control_block) {
            control_block->increment_shared();
        }
    }

    // Move constructor
    SharedPtr(SharedPtr&& other) noexcept : resource(other.resource), control_block(other.control_block) {
        other.resource = nullptr;
        other.control_block = nullptr;
    }

    // Copy assignment
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();

            resource = other.resource;
            control_block = other.control_block;

            if (control_block) {
                control_block->increment_shared();
            }
        }
        return *this;
    }

    // Move assignment
    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            release();

            resource = other.resource;
            control_block = other.control_block;

            other.resource = nullptr;
            other.control_block = nullptr;
        }
        return *this;
    }

    // Destructor
    ~SharedPtr() {
        release();
    }

    // Release resources
    void release() {
        if (control_block) {
            control_block->decrement_shared();

            if (control_block->should_delete_resource()) {
                delete resource;
                resource = nullptr;

                if (control_block->should_delete_control_block()) {
                    delete control_block;
                    control_block = nullptr;
                }
            }
        }
    }

    // Reset with new resource
    void reset(T* ptr = nullptr) {
        release();

        resource = ptr;
        if (ptr) {
            control_block = new ControlBlock();
        }
        else {
            control_block = nullptr;
        }
    }

    // Get reference count
    size_t use_count() const {
        return control_block ? control_block->shared_count : 0;
    }

    // Get raw pointer
    T* get() const {
        return resource;
    }

    // Dereference operator
    T& operator*() const {
        return *resource;
    }

    // Arrow operator
    T* operator->() const {
        return resource;
    }

    // Boolean conversion
    explicit operator bool() const {
        return resource != nullptr;
    }
};

template<typename T>
class WeakPtr {
    friend class SharedPtr<T>;

private:
    T* resource = nullptr;
    ControlBlock* control_block = nullptr;

public:
    // Default constructor
    WeakPtr() : resource(nullptr), control_block(nullptr) {}

    // Constructor from SharedPtr
    WeakPtr(const SharedPtr<T>& shared_ptr) : resource(shared_ptr.get()), control_block(shared_ptr.control_block) {
        if (control_block) {
            control_block->increment_weak();
        }
    }

    // Copy constructor
    WeakPtr(const WeakPtr& other) : resource(other.resource), control_block(other.control_block) {
        if (control_block) {
            control_block->increment_weak();
        }
    }

    // Move constructor
    WeakPtr(WeakPtr&& other) noexcept : resource(other.resource), control_block(other.control_block) {
        other.resource = nullptr;
        other.control_block = nullptr;
    }

    // Copy assignment
    WeakPtr& operator=(const WeakPtr& other) {
        if (this != &other) {
            release();

            resource = other.resource;
            control_block = other.control_block;

            if (control_block) {
                control_block->increment_weak();
            }
        }
        return *this;
    }

    // Move assignment
    WeakPtr& operator=(WeakPtr&& other) noexcept {
        if (this != &other) {
            release();

            resource = other.resource;
            control_block = other.control_block;

            other.resource = nullptr;
            other.control_block = nullptr;
        }
        return *this;
    }

    // Assignment from SharedPtr
    WeakPtr& operator=(const SharedPtr<T>& shared_ptr) {
        release();

        resource = shared_ptr.get();
        control_block = shared_ptr.control_block;

        if (control_block) {
            control_block->increment_weak();
        }

        return *this;
    }

    // Destructor
    ~WeakPtr() {
        release();
    }

    // Release resources
    void release() {
        if (control_block) {
            control_block->decrement_weak();

            if (control_block->should_delete_control_block()) {
                delete control_block;
            }

            control_block = nullptr;
            resource = nullptr;
        }
    }

    // Reset
    void reset() {
        release();
    }

    // Check if the referenced object still exists
    bool expired() const {
        return !control_block || control_block->shared_count == 0;
    }

    // Get reference count
    size_t use_count() const {
        return control_block ? control_block->shared_count : 0;
    }

    // Create a SharedPtr from this WeakPtr
    SharedPtr<T> lock() const {
        return expired() ? SharedPtr<T>() : SharedPtr<T>(*this);
    }
};

// Example usage
int main() {
    // Demonstration of WeakPtr usage
    cout << "=== WeakPtr Demonstration ===" << endl;

    // Create some objects to work with
    class TestObject {
    public:
        string name;
        explicit TestObject(string n) : name(std::move(n)) {
            cout << "TestObject constructed: " << name << endl;
        }
        ~TestObject() {
            cout << "TestObject destroyed: " << name << endl;
        }
    };

    // Example 1: Basic usage
    {
        cout << "\n--- Example 1: Basic Usage ---" << endl;
        SharedPtr<TestObject> shared(new TestObject("Object1"));
        WeakPtr<TestObject> weak = shared;

        cout << "Shared count: " << shared.use_count() << endl;
        cout << "Is weak expired? " << (weak.expired() ? "Yes" : "No") << endl;

        // Access object through weak pointer
        if (SharedPtr<TestObject> locked = weak.lock()) {
            cout << "Successfully locked weak pointer, object name: " << locked->name << endl;
        }
        else {
            cout << "Failed to lock weak pointer, object no longer exists" << endl;
        }

        // Reset shared pointer, which will destroy the object
        shared.reset();
        cout << "After resetting shared pointer:" << endl;
        cout << "Is weak expired? " << (weak.expired() ? "Yes" : "No") << endl;

        // Try to access object again
        if (SharedPtr<TestObject> locked = weak.lock()) {
            cout << "Successfully locked weak pointer, object name: " << locked->name << endl;
        }
        else {
            cout << "Failed to lock weak pointer, object no longer exists" << endl;
        }
    }

    // Example 2: Breaking circular references
    {
        cout << "\n--- Example 2: Breaking Circular References ---" << endl;

        class Node {
        public:
            string name;
            SharedPtr<Node> next;  // Strong reference
            WeakPtr<Node> prev;    // Weak reference to break the cycle

            explicit Node(string n) : name(std::move(n)) {
                cout << "Node constructed: " << name << endl;
            }

            ~Node() {
                cout << "Node destroyed: " << name << endl;
            }
        };

        // Create a circular linked list with 3 nodes
        SharedPtr<Node> node1(new Node("Node1"));
        SharedPtr<Node> node2(new Node("Node2"));
        SharedPtr<Node> node3(new Node("Node3"));

        // Connect nodes in a circular fashion
        node1->next = node2;
        node2->next = node3;
        node3->next = node1;  // Circular reference

        // Set up weak back-references
        node2->prev = node1;
        node3->prev = node2;
        node1->prev = node3;

        cout << "Nodes created and linked" << endl;
        cout << "node1 use count: " << node1.use_count() << endl;
        cout << "node2 use count: " << node2.use_count() << endl;
        cout << "node3 use count: " << node3.use_count() << endl;

        // Navigate through the list using weak pointers
        if (SharedPtr<Node> prev = node1->prev.lock()) {
            cout << "node1's previous node is: " << prev->name << endl;
        }

        // Break the cycle by resetting one shared pointer
        cout << "\nBreaking the cycle by resetting node1..." << endl;
        node1.reset();

        // The other nodes are still referenced
        cout << "node2 use count: " << node2.use_count() << endl;
        cout << "node3 use count: " << node3.use_count() << endl;

        // Now break remaining references
        cout << "\nBreaking remaining references..." << endl;
        node2.reset();
        node3.reset();
    }

    // Example 3: Observer pattern
    {
        cout << "\n--- Example 3: Observer Pattern ---" << endl;

        class Subject;

        class Observer {
        public:
            string name;
            WeakPtr<Subject> subject;  // Weak reference to subject

            explicit Observer(string n) : name(std::move(n)) {
                cout << "Observer constructed: " << name << endl;
            }

            ~Observer() {
                cout << "Observer destroyed: " << name << endl;
            }

            void notify() {
                cout << "Observer " << name << " notified" << endl;
            }
        };

        class Subject {
        public:
            string name;
            vector<WeakPtr<Observer>> observers;  // Weak references to observers

            explicit Subject(string n) : name(std::move(n)) {
                cout << "Subject constructed: " << name << endl;
            }

            ~Subject() {
                cout << "Subject destroyed: " << name << endl;
            }

            void addObserver(const SharedPtr<Observer>& observer) {
                observers.push_back(WeakPtr<Observer>(observer));
                observer->subject = *this;
            }

            void notifyObservers() {
                cout << "Subject " << name << " notifying observers..." << endl;

                // Clean up expired observers while notifying
                auto it = observers.begin();
                while (it != observers.end()) {
                    if (SharedPtr<Observer> observer = it->lock()) {
                        observer->notify();
                        ++it;
                    }
                    else {
                        cout << "Removing expired observer" << endl;
                        it = observers.erase(it);
                    }
                }
            }
        };

        SharedPtr<Subject> subject(new Subject("MainSubject"));

        // Create some observers
        SharedPtr<Observer> observer1(new Observer("Observer1"));
        SharedPtr<Observer> observer2(new Observer("Observer2"));

        // Register observers with subject
        subject->addObserver(observer1);
        subject->addObserver(observer2);

        // Notify all observers
        subject->notifyObservers();

        // Remove one observer by letting it go out of scope
        cout << "\nLetting observer1 go out of scope..." << endl;
        observer1.reset();

        // Notify again - should only notify observer2
        subject->notifyObservers();
    }

    return 0;
}