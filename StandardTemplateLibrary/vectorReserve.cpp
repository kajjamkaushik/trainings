//#include <iostream>
//#include <vector>
//#include <chrono>

/**
 * std::vector::reserve() Demonstration
 *
 * This program demonstrates the performance benefits of using reserve()
 * with std::vector when adding many elements.
 *
 * Key points about reserve():
 * 1. Pre-allocates memory for a specified number of elements
 * 2. Reduces the number of reallocations during insertions
 * 3. Improves performance by avoiding repeated memory copying
 * 4. Most beneficial when the final size is known in advance
 */

//int main() {
//    const int NUM_ELEMENTS = 10000000;  // 10 million elements
//
//    // ===== WITHOUT RESERVE =====
//    std::cout << "Testing vector without reserve()..." << std::endl;
//
//    auto start1 = std::chrono::high_resolution_clock::now();
//
//    std::vector<int> vec1;
//    // Without reserve(), vector will need to reallocate multiple times
//    // Each reallocation typically:
//    // 1. Allocates a new, larger block of memory (usually 1.5x or 2x the current size)
//    // 2. Copies all existing elements to the new memory
//    // 3. Deallocates the old memory
//    for (int i = 0; i < NUM_ELEMENTS; ++i) {
//        vec1.push_back(i);
//
//        // Uncomment to see capacity changes (but will slow down execution)
//        /*if (i % 1000000 == 0) {
//            std::cout << "Current capacity: " << vec1.capacity() << std::endl;
//        }*/
//    }
//
//    auto end1 = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> elapsed1 = end1 - start1;
//
//    // ===== WITH RESERVE =====
//    std::cout << "Testing vector with reserve()..." << std::endl;
//
//    auto start2 = std::chrono::high_resolution_clock::now();
//
//    std::vector<int> vec2;
//    // reserve() pre-allocates memory without creating any elements
//    // Benefits:
//    // 1. Single allocation instead of multiple reallocations
//    // 2. No need to copy elements during growth
//    // 3. Significantly faster for large numbers of insertions
//    vec2.reserve(NUM_ELEMENTS);
//
//    for (int i = 0; i < NUM_ELEMENTS; ++i) {
//        vec2.push_back(i);
//    }
//
//    auto end2 = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> elapsed2 = end2 - start2;
//
//    // ===== RESULTS =====
//    std::cout << "\n=== Performance Results ===" << std::endl;
//    std::cout << "Without reserve(): " << elapsed1.count() << " seconds" << std::endl;
//    std::cout << "With reserve():    " << elapsed2.count() << " seconds" << std::endl;
//    std::cout << "Speedup factor:    " << elapsed1.count() / elapsed2.count() << "x" << std::endl;
//
//    // ===== MEMORY USAGE =====
//    std::cout << "\n=== Memory Usage ===" << std::endl;
//    // Final capacity may be larger than size due to vector's growth strategy
//    std::cout << "Without reserve() - Final capacity: " << vec1.capacity() << std::endl;
//    std::cout << "With reserve()    - Final capacity: " << vec2.capacity() << std::endl;
//
//    /**
//     * When NOT to use reserve():
//     * 1. When the final size is unknown or unpredictable
//     * 2. For small vectors where the performance gain is negligible
//     * 3. When memory conservation is more important than insertion speed
//     * 4. When you're using the vector in a way that doesn't involve many insertions
//     */
//
//    return 0;
//}


//Testing vector without reserve()...
//Testing vector with reserve()...
//
//== = Performance Results == =
//Without reserve() : 0.539741 seconds
//With reserve() : 0.462381 seconds
//Speedup factor : 1.16731x
//
//== = Memory Usage == =
//Without reserve() - Final capacity : 11958657
//With reserve() - Final capacity : 10000000