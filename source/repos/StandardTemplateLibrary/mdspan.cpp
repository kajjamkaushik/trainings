//What is mdspan ? (part odf cpp 23))
//    A multi - dimensional view over a contiguous memory block.
//    Part of C++23 (std::mdspan from <mdspan> header).
//    Does not own data—provides a flexible way to access it.
//Why use it ?
//    Efficiently handles multi - dimensional indexing(like 2D / 3D arrays) over flat memory(like vectors).
//    No need to allocate nested containers(vector<vector<>> etc.).
//    Great for scientific computing, graphics, or tensor operations.
//Key Features:
//    Flexible shapes: Easily define views like 2×6, 3×2×2, etc.
//    Access with comma operator: ms[i, j, k]
//    Query dimensions: ms.extent(dim)
//Limitations:
//    Needs a contiguous memory source (like vector.data() or array).
//    Access with operator[] using comma-separated indices (needs parenthesis).

//#include <iostream>
//#include <vector>
//#include <experimental/mdspan>
//
//int main() {
//    std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//
//    using namespace std::experimental;
//
//    // Create 2D and 3D mdspans
//    auto ms2 = mdspan<int, extents<size_t, 2, 6>>(v.data());
//    auto ms3 = mdspan<int, extents<size_t, 2, 3, 2>>(v.data());
//
//    // Fill the 2D mdspan
//    for (size_t i = 0; i < ms2.extent(0); i++)
//        for (size_t j = 0; j < ms2.extent(1); j++)
//            ms2(i, j) = i * 1000 + j;
//
//    // Print the 3D mdspan
//    for (size_t i = 0; i < ms3.extent(0); i++) {
//        std::cout << "slice @ i = " << i << "\n";
//        for (size_t j = 0; j < ms3.extent(1); j++) {
//            for (size_t k = 0; k < ms3.extent(2); k++) {
//                std::cout << ms3(i, j, k) << " ";
//            }
//            std::cout << " ";  // Space between inner groups
//        }
//        std::cout << "\n";
//    }
//}

//output :
//slice @ i = 0
//0 1  2 3  4 5
//slice @ i = 1
//1000 1001  1002 1003  1004 1005