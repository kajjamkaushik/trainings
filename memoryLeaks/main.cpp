#include <iostream>
#include <cstdlib> 
using namespace std;
struct Allocation {
    void* pointer;
    size_t size;
    const char* file;
    int line;
};
static Allocation allocations[100];
static int allocIndex = 0;
Allocation* getAllocations() {
    return allocations;
}
void* operator new(size_t size, const char* file, int line) {
    cout << "Overloaded new at " << file << ":" << line << endl;
    void* p = malloc(size);
    if (!p) {
        throw std::bad_alloc();
    }
    if (allocIndex < 100) {
        allocations[allocIndex].pointer = p;
        allocations[allocIndex].size = size;
        allocations[allocIndex].file = file;
        allocations[allocIndex].line = line;
        allocIndex++;
    }
    else {
        cout << "Allocation tracking array is full!" << endl;
    }
    return p;
}
void operator delete(void* p) noexcept {
    if (p) {
        bool found = false;
        for (int i = 0; i < allocIndex; ++i) {
            if (allocations[i].pointer == p) {
                for (int j = i; j < allocIndex - 1; ++j) {
                    allocations[j] = allocations[j + 1];
                }
                allocIndex--;
                found = true;
                break;
            }
        }
        if (found) {
            cout << "Overloaded delete at " << p << endl;
        }
        else {
            cout << "Pointer not found in allocation array." << endl;
        }
        free(p);
    }
    else {
        cout << "Null pointer passed to delete." << endl;
    }
}
void* operator new[](size_t size, const char* file, int line) {
    cout << "Overloaded new[] at " << file << ":" << line << endl;

    void* p = malloc(size);
    if (!p) {
        throw std::bad_alloc();
    }
    if (allocIndex < 100) {
        allocations[allocIndex].pointer = p;
        allocations[allocIndex].size = size;
        allocations[allocIndex].file = file;
        allocations[allocIndex].line = line;
        allocIndex++;
    }
    else {
        cout << "Allocation tracking array is full!" << endl;
    }
    return p;
}
void operator delete[](void* p) noexcept {
    if (p) {
        bool found = false;
        for (int i = 0; i < allocIndex; ++i) {
            if (allocations[i].pointer == p) {
                for (int j = i; j < allocIndex - 1; ++j) {
                    allocations[j] = allocations[j + 1];
                }
                allocIndex--;
                found = true;
                break;
            }
        }
        if (found) {
            cout << "Overloaded delete[] at " << p << endl;
        }
        else {
            cout << "Pointer not found in allocation array." << endl;
        }
        free(p);
    }
}
void checkleak() {
    if (allocIndex > 0) {
        cout << "Leak detected!" << endl;
        for (int i = 0; i < allocIndex; ++i) {
            cout << "Leak at address: " << allocations[i].pointer
                << " of size: " << allocations[i].size << " bytes"
                << " allocated at " << allocations[i].file << ":" << allocations[i].line << endl;
        }
    }
    else {
        cout << "No leak detected." << endl;
    }
}
#define new new(__FILE__, __LINE__)
int main() {
    int* x = new int;
    /* int* y = new int[10];*/
    delete x;
    /*  delete[] y;
      checkleak();*/
    return 0;
}