//#include <iostream>
//#include <memory>
//#include <cstdlib> // For malloc and free
//#include <cstdio>  // For FILE*, fopen, fclose
//struct CustomDeleter
//{
//    // Custom deleter for malloc-allocated memory
//    void operator()(int* ptr)
//    {
//        if (ptr) {
//            std::cout << "Freeing malloc-allocated memory" << std::endl;
//            free(ptr); // Correct way to free malloc memory
//        }
//    }
//    // Custom deleter for FILE*
//    void operator()(FILE* fptr)
//    {
//        if (fptr) {
//            std::cout << "Closing file in custom deleter" << std::endl;
//            fclose(fptr); // Correct way to close a file
//        }
//    }
//};
//
//int main()
//{
//    // Using malloc with a custom deleter
//    int* var = (int*)malloc(sizeof(int));
//    if (!var) {
//        std::cerr << "Memory allocation failed!" << std::endl;
//        return 1;
//    }
//    *var = 42;
//    std::cout << "Value: " << *var << std::endl;
//    // Using FILE* with a custom deleter
//    FILE* fptr = fopen("sample.txt", "r");
//    if (!fptr) {
//        std::cerr << "Failed to open file!" << std::endl;
//        free(var); // Manually freeing malloc in case of early return
//        return 1;
//    }
//    // Create smart pointers with the same custom deleter
//    std::unique_ptr<int, CustomDeleter> intPtr(var, CustomDeleter{});
//    std::unique_ptr<FILE, CustomDeleter> filePtr(fptr, CustomDeleter{});
//    // Memory and file will be automatically managed and freed when going out of scope
//    return 0;
//}
