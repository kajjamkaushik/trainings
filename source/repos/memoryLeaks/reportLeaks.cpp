//// MemoryLeakDetector.cpp
//#include <iostream>
//#include <map>
//#include <string>
//#include <cstdlib>
//#include <iomanip>
//#include <new>
//
//// Disable the annotation warnings
//#pragma warning(disable: 28251)
//
//// Memory leak detector implementation
//namespace MemoryLeakDetector {
//    // Use function-local static variables to control initialization order
//    std::map<void*, std::pair<size_t, std::string>>& getAllocations() {
//        static std::map<void*, std::pair<size_t, std::string>> allocations;
//        return allocations;
//    }
//
//    size_t& getTotalAllocated() {
//        static size_t totalAllocated = 0;
//        return totalAllocated;
//    }
//
//    size_t& getAllocationCount() {
//        static size_t allocationCount = 0;
//        return allocationCount;
//    }
//
//    bool& getInitialized() {
//        static bool initialized = false;
//        return initialized;
//    }
//
//    // Initialize the leak detector
//    void initialize() {
//        bool& initialized = getInitialized();
//        if (!initialized) {
//            initialized = true;
//            std::cout << "Memory leak detector initialized\n";
//        }
//    }
//
//    // Report memory leaks
//    void reportLeaks() {
//        auto& allocations = getAllocations();
//        auto& totalAllocated = getTotalAllocated();
//        auto& allocationCount = getAllocationCount();
//
//        std::cout << "\n===== MEMORY LEAK REPORT =====\n";
//
//        if (allocations.empty()) {
//            std::cout << "No memory leaks detected. All allocations were properly freed.\n";
//            std::cout << "Total allocations during program execution: " << allocationCount << std::endl;
//        }
//        else {
//            std::cout << "WARNING: " << allocations.size() << " memory leaks detected!\n";
//            std::cout << "Total leaked memory: " << totalAllocated << " bytes\n\n";
//
//            // Table header
//            std::cout << std::left
//                << std::setw(18) << "Address"
//                << std::setw(12) << "Size (bytes)"
//                << "Location\n";
//            std::cout << std::string(60, '-') << "\n";
//
//            // Print each leak with details
//            for (const auto& alloc : allocations) {
//                std::cout << std::left
//                    << std::setw(18) << alloc.first
//                    << std::setw(12) << alloc.second.first
//                    << alloc.second.second << "\n";
//            }
//
//            std::cout << "\nMemory leak summary:\n";
//            std::cout << "- Number of leaks: " << allocations.size() << "\n";
//            std::cout << "- Total bytes leaked: " << totalAllocated << "\n";
//            std::cout << "- Total allocations during execution: " << allocationCount << "\n";
//        }
//
//        std::cout << "==============================\n";
//    }
//}
//
//// Override standard new operator
//void* operator new(size_t size) {
//    void* ptr = std::malloc(size);
//    if (!ptr) throw std::bad_alloc();
//
//    // Only track allocations after main starts
//    if (MemoryLeakDetector::getInitialized()) {
//        auto& allocations = MemoryLeakDetector::getAllocations();
//        auto& totalAllocated = MemoryLeakDetector::getTotalAllocated();
//        auto& allocationCount = MemoryLeakDetector::getAllocationCount();
//
//        allocations[ptr] = std::make_pair(size, "Unknown location");
//        totalAllocated += size;
//        allocationCount++;
//    }
//
//    return ptr;
//}
//
//// Custom new operator with source location information
//void* operator new(size_t size, const char* file, int line) {
//    void* ptr = std::malloc(size);
//    if (!ptr) throw std::bad_alloc();
//
//    // Only track allocations after main starts
//    if (MemoryLeakDetector::getInitialized()) {
//        auto& allocations = MemoryLeakDetector::getAllocations();
//        auto& totalAllocated = MemoryLeakDetector::getTotalAllocated();
//        auto& allocationCount = MemoryLeakDetector::getAllocationCount();
//
//        std::string location = std::string(file) + ":" + std::to_string(line);
//        allocations[ptr] = std::make_pair(size, location);
//        totalAllocated += size;
//        allocationCount++;
//    }
//
//    return ptr;
//}
//
//// Standard delete operator
//void operator delete(void* ptr) noexcept {
//    if (ptr && MemoryLeakDetector::getInitialized()) {
//        auto& allocations = MemoryLeakDetector::getAllocations();
//        auto& totalAllocated = MemoryLeakDetector::getTotalAllocated();
//        auto& allocationCount = MemoryLeakDetector::getAllocationCount();
//
//        auto it = allocations.find(ptr);
//        if (it != allocations.end()) {
//            totalAllocated -= it->second.first;
//            allocations.erase(it);
//            allocationCount--;
//        }
//    }
//    std::free(ptr);
//}
//
//// Matching delete operator for the placement new
//void operator delete(void* ptr, const char*, int) noexcept {
//    operator delete(ptr);
//}
//
//// Array versions
//void* operator new[](size_t size) {
//    return operator new(size);
//}
//
//void* operator new[](size_t size, const char* file, int line) {
//    return operator new(size, file, line);
//}
//
//void operator delete[](void* ptr) noexcept {
//    operator delete(ptr);
//}
//
//void operator delete[](void* ptr, const char* file, int line) noexcept {
//    operator delete(ptr, file, line);
//}
//
//// Macro to capture file and line information
//#define DEBUG_NEW new(__FILE__, __LINE__)
//
//// Only redefine "new" in debug builds
//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif
//
//// Example class that might leak memory
//class ResourceUser {
//private:
//    int* data;
//
//public:
//    ResourceUser() {
//        data = new int[100]; // This allocation will be tracked
//    }
//
//    ~ResourceUser() {
//        // Uncomment to fix the leak
//        // delete[] data;
//    }
//
//    void doSomething() {
//        // Allocate more memory that might leak
//        int* temp = new int[50];
//        // Uncomment to fix the leak
//        // delete[] temp;
//    }
//};
//
//// Main function demonstrating the memory leak detection
//int main() {
//    // Initialize the memory leak detector
//    MemoryLeakDetector::initialize();
//
//    std::cout << "Program started\n";
//
//    // Properly managed memory (no leak)
//    int* properlyManaged = new int[10];
//    delete[] properlyManaged;
//
//    // Create a scope to test object lifetime
//    {
//        ResourceUser* user = new ResourceUser();
//        user->doSomething();
//
//        // Uncomment to fix the leak
//        // delete user;
//    }
//
//    // Another leak
//    float* leakedFloat = new float[25];
//
//    // Register the reportLeaks function to run at program exit
//    std::atexit(MemoryLeakDetector::reportLeaks);
//
//    std::cout << "Program finished\n";
//    return 0;
//}