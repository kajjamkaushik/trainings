//Intro or introspective sort is a sorting weapon used by the STL library in C++ and array sorting in the swift programming language.
//In simple terms, it is currently, the best sorting algorithm.In this article, we dive into the details of the intro sort algorithm and analyze 
//why it is regarded as the best sorting algorithm.
//
//Intro sort is a hybrid comparison - based sorting algorithm that consists of three sorting phases.These three sorting phases or algorithms minimize 
//the run time.The three sorting algorithms used in intro sort are Quicksort, Insertion sort, Heapsort.
//Note: Introsort is not stable.
//This means that two objects with equal values may or may not appear in the same order in sorted output as they appear in the input unsorted array
//Why do we need Intro sort ?
//To understand the importance of intro sort let us briefly understand the drawbacks of other commonly used sorting algorithms.
//
//Quicksort
//Quicksort is one of the efficient algorithms based on the divide and conquer method.It has a complexity of NlogN in its best and average case but 
//has O(N²) in its worst time performance.The complexity of Quicksort depends upon the choice of the pivot element and the depth of the recursion tree.
//It also uses O(N) auxiliary space.
//
//Heapsort
//Heapsort always has a time performance of O(NLogN) which is significantly better than the worst time complexity of quicksort O(N²).So, is heapsort
//the best sorting algorithm ? The answer is no.In quicksort, no swapping of elements occurs if the array is sorted whereas, in heapsort, the swapping 
//of elements is unavoidable.The best thing about heapsort is that the time complexity remains O(nlogn) irrespective of the recursion depth.
//
//Mergesort
//Mergesort is also a divide and conquer algorithm with a time complexity of O(NlogN).Mergesort can be used irrespective of the size of the data sets.
//Mergesort works well with LinkedList whereas quicksort is better with arrays.Generally, with memory constraints, quicksort outperforms merge sort.
//
//Insertion sort
//Insertion sort is simple and easy to implement.Insertion sort is good for small data sets but the performance deteriorates with the increase in the size
//of the data list.It has minimal space requirements but has a time performance of O(N²).
//
//Why is mergesort not used ?
//As stated earlier, mergesort has a space complexity of O(N) and in practical application, quicksort outperforms merge sort on subjected to sorting arrays.
//
//When to switch from quicksort to heapsort ?
//The decision to switch from quicksort to heapsort is based on the depthlimit.The depthlimit represents the maximum
//depth of recursion up to which quicksort runs without moving to its worst time performance of O(N²).This ensures that the time complexity of intro sort
//remains O(nlogn) in all cases.The depthlimit for the intro sort is chosen as 2 * logN(N is the number of elements) based on research.
//Based on the above analysis, the working of intro sort can be summarized as,
//
//Intro sort begins with quicksort and if the recursion depth exceeds the depthlimit of intro sort, switching to heapsort takes place.
//If the number of elements is few, insertion sort takes place.
//Therefore, the first step is to create a partition.After creating a partition, three cases arise,
//If the partition size is greater than the depthlimit i.e 2 * logN, switching to heap sort takes place.
//If the partition size is too small, switching to insertion sort takes place.The constant below which insertion sort is used is chosen to be 16 based on
//research.Therefore, if the size of the partition is less than or equal to 16, insertion sort takes place.
//If the partition size is greater than 16 and less than the depthlimit(2 * logN), quicksort is performed.


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <random>
//#include <iomanip>
//
//// Threshold for switching to insertion sort
//const int INSERTION_SORT_THRESHOLD = 16;
//
//// Insertion Sort for small partitions
//void insertionSort(std::vector<int>& arr, int left, int right) {
//    std::cout << "Using Insertion Sort for range [" << left << ", " << right << "]" << std::endl;
//
//    for (int i = left + 1; i <= right; ++i) {
//        int key = arr[i];
//        int j = i - 1;
//        while (j >= left && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            --j;
//        }
//        arr[j + 1] = key;
//    }
//}
//
//// HeapSort used if recursion depth is too large
//void heapSort(std::vector<int>& arr, int left, int right) {
//    std::cout << "Using Heap Sort for range [" << left << ", " << right << "]" << std::endl;
//
//    std::make_heap(arr.begin() + left, arr.begin() + right + 1);
//    std::sort_heap(arr.begin() + left, arr.begin() + right + 1);
//}
//
//// Partition for QuickSort
//int partition(std::vector<int>& arr, int low, int high) {
//    std::cout << "Using QuickSort partition for range [" << low << ", " << high << "]" << std::endl;
//
//    int pivot = arr[high];
//    int i = low - 1;
//    for (int j = low; j < high; ++j) {
//        if (arr[j] <= pivot) {
//            std::swap(arr[++i], arr[j]);
//        }
//    }
//    std::swap(arr[i + 1], arr[high]);
//    return i + 1;
//}

// Core of IntroSort
//void introSortUtil(std::vector<int>& arr, int low, int high, int depthLimit) {
//    int size = high - low + 1;
//
//    if (size <= INSERTION_SORT_THRESHOLD) {
//        insertionSort(arr, low, high);
//        return;
//    }
//
//    if (depthLimit == 0) {
//        heapSort(arr, low, high);
//        return;
//    }
//
//    int pivot = partition(arr, low, high);
//    introSortUtil(arr, low, pivot - 1, depthLimit - 1);
//    introSortUtil(arr, pivot + 1, high, depthLimit - 1);
//}
//
//// Wrapper for IntroSort
//void introSort(std::vector<int>& arr) {
//    int depthLimit = 2 * log(arr.size());
//    std::cout << "Starting IntroSort with depth limit: " << depthLimit << std::endl;
//    introSortUtil(arr, 0, arr.size() - 1, depthLimit);
//}
//
//// Helper function to print arrays
//void printArray(const std::vector<int>& arr, const std::string& label) {
//    std::cout << label << ": ";
//    if (arr.size() > 20) {
//        // Print first 10 and last 10 elements if array is large
//        for (int i = 0; i < 10; i++) {
//            std::cout << arr[i] << " ";
//        }
//        std::cout << "... ";
//        for (int i = arr.size() - 10; i < arr.size(); i++) {
//            std::cout << arr[i] << " ";
//        }
//    }
//    else {
//        // Print all elements if array is small
//        for (int n : arr) {
//            std::cout << n << " ";
//        }
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    std::cout << "=== CASE 1: Small Array (Should use Insertion Sort) ===" << std::endl;
//    std::vector<int> small_array = { 5, 3, 8, 1, 2, 7, 4, 6, 9, 0 };
//    printArray(small_array, "Original small array");
//    introSort(small_array);
//    printArray(small_array, "Sorted small array");
//    std::cout << std::endl;
//
//    std::cout << "=== CASE 2: Already Sorted Array (May trigger Heap Sort) ===" << std::endl;
//    std::vector<int> already_sorted;
//    for (int i = 0; i < 100; i++) {
//        already_sorted.push_back(i);
//    }
//    printArray(already_sorted, "Original sorted array");
//    introSort(already_sorted);
//    printArray(already_sorted, "Sorted array");
//    std::cout << std::endl;
//
//    std::cout << "=== CASE 3: Reverse Sorted Array (May trigger Heap Sort) ===" << std::endl;
//    std::vector<int> reverse_sorted;
//    for (int i = 100; i > 0; i--) {
//        reverse_sorted.push_back(i);
//    }
//    printArray(reverse_sorted, "Original reverse sorted array");
//    introSort(reverse_sorted);
//    printArray(reverse_sorted, "Sorted array");
//    std::cout << std::endl;
//
//    std::cout << "=== CASE 4: Random Large Array (Should use all three methods) ===" << std::endl;
//    std::vector<int> large_random;
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> dis(1, 1000);
//
//    for (int i = 0; i < 100; i++) {
//        large_random.push_back(dis(gen));
//    }
//    printArray(large_random, "Original random array");
//    introSort(large_random);
//    printArray(large_random, "Sorted random array");
//
//    return 0;
//}


///=== CASE 1: Small Array (Should use Insertion Sort) ===
//Original small array : 5 3 8 1 2 7 4 6 9 0
//Starting IntroSort with depth limit : 4
//Using Insertion Sort for range[0, 9]
//Sorted small array : 0 1 2 3 4 5 6 7 8 9
//
//== = CASE 2 : Already Sorted Array(May trigger Heap Sort) == =
//Original sorted array : 0 1 2 3 4 5 6 7 8 9 ... 90 91 92 93 94 95 96 97 98 99
//Starting IntroSort with depth limit : 9
//Using QuickSort partition for range[0, 99]
//Using QuickSort partition for range[0, 98]
//Using QuickSort partition for range[0, 97]
//Using QuickSort partition for range[0, 96]
//Using QuickSort partition for range[0, 95]
//Using QuickSort partition for range[0, 94]
//Using QuickSort partition for range[0, 93]
//Using QuickSort partition for range[0, 92]
//Using QuickSort partition for range[0, 91]
//Using Heap Sort for range[0, 90]
//Using Insertion Sort for range[92, 91]
//Using Insertion Sort for range[93, 92]
//Using Insertion Sort for range[94, 93]
//Using Insertion Sort for range[95, 94]
//Using Insertion Sort for range[96, 95]
//Using Insertion Sort for range[97, 96]
//Using Insertion Sort for range[98, 97]
//Using Insertion Sort for range[99, 98]
//Using Insertion Sort for range[100, 99]
//Sorted array : 0 1 2 3 4 5 6 7 8 9 ... 90 91 92 93 94 95 96 97 98 99
//
//== = CASE 3 : Reverse Sorted Array(May trigger Heap Sort) == =
//Original reverse sorted array : 100 99 98 97 96 95 94 93 92 91 ... 10 9 8 7 6 5 4 3 2 1
//Starting IntroSort with depth limit : 9
//Using QuickSort partition for range[0, 99]
//Using Insertion Sort for range[0, -1]
//Using QuickSort partition for range[1, 99]
//Using QuickSort partition for range[1, 98]
//Using Insertion Sort for range[1, 0]
//Using QuickSort partition for range[2, 98]
//Using QuickSort partition for range[2, 97]
//Using Insertion Sort for range[2, 1]
//Using QuickSort partition for range[3, 97]
//Using QuickSort partition for range[3, 96]
//Using Insertion Sort for range[3, 2]
//Using QuickSort partition for range[4, 96]
//Using QuickSort partition for range[4, 95]
//Using Insertion Sort for range[4, 3]
//Using Heap Sort for range[5, 95]
//Using Insertion Sort for range[97, 96]
//Using Insertion Sort for range[98, 97]
//Using Insertion Sort for range[99, 98]
//Using Insertion Sort for range[100, 99]
//Sorted array : 1 2 3 4 5 6 7 8 9 10 ... 91 92 93 94 95 96 97 98 99 100
//
//== = CASE 4 : Random Large Array(Should use all three methods) == =
//Original random array : 298 315 672 714 154 309 343 619 225 200 ... 736 305 907 783 623 258 230 212 363 152
//Starting IntroSort with depth limit : 9
//Using QuickSort partition for range[0, 99]
//Using Insertion Sort for range[0, 10]
//Using QuickSort partition for range[12, 99]
//Using Insertion Sort for range[12, 25]
//Using QuickSort partition for range[27, 99]
//Using QuickSort partition for range[27, 81]
//Using Insertion Sort for range[27, 38]
//Using QuickSort partition for range[40, 81]
//Using QuickSort partition for range[40, 73]
//Using QuickSort partition for range[40, 60]
//Using Insertion Sort for range[40, 46]
//Using Insertion Sort for range[48, 60]
//Using Insertion Sort for range[62, 73]
//Using Insertion Sort for range[75, 81]
//Using QuickSort partition for range[83, 99]
//Using Insertion Sort for range[83, 83]
//Using Insertion Sort for range[85, 99]
//Sorted random array : 8 22 57 61 74 79 89 93 116 134 ... 829 854 858 877 907 926 934 959 981 990