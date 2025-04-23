//#include<iostream>
//#include<algorithm>
//#include<numeric>
//#include<functional>
//#include<vector>
//using namespace std;
//
//// Function to print vector contents with a message
//void printVector(const vector<int>& nums, const string& msg) {
//    cout << msg << " : ";
//    for (int ele : nums) cout << ele << " ";
//    cout << endl;
//}
//
//int main() {
//    // Basic sorting example
//    vector<int> nums = { 5, 4, 7, 8, 1, 2, 9, 3, 6, 0 };
//    printVector(nums, "Before Sorting");
//
//    sort(nums.begin(), nums.end());
//    printVector(nums, "After Sorting");
//
//    // Fill example - setting all elements to 0
//    std::fill(nums.begin(), nums.end(), 0);
//    cout << "After filling with 0: ";
//    for (int num : nums) std::cout << num << " ";
//    std::cout << std::endl;
//
//    // Transform example - adding 5 to first 3 elements
//    std::transform(nums.begin(), nums.begin() + 3, nums.begin(), [](int n) { return n + 5; });
//    std::cout << "After adding 5 to first 3 elements: ";
//    for (int num : nums) std::cout << num << " ";
//    std::cout << std::endl;
//
//    // Find example
//    vector<int> st = { 5, 4, 7, 8, 1, 2, 9, 3, 6, 0 };
//    auto it = std::find(st.begin(), st.end(), 3); // Find the value 3
//    if (it != st.end()) { // Note: comparing with st.end(), not nums.end()
//        cout << "Found 3 at Position " << distance(st.begin(), it) << endl;
//    }
//    else {
//        cout << "3 not found" << endl;
//    }
//
//    // Set operations example
//    std::vector<int> set1 = { 1, 2, 3, 4 };
//    std::vector<int> set2 = { 3, 4, 8, 9, 6, 5, 7 };
//
//    // Sort the vectors before set_union
//    std::sort(set1.begin(), set1.end());
//    std::sort(set2.begin(), set2.end());
//
//    // Create a vector to store the result of the union
//    std::vector<int> union_result(set1.size() + set2.size());
//
//    // Perform set union
//    auto union_it = std::set_union(
//        set1.begin(), set1.end(),
//        set2.begin(), set2.end(),
//        union_result.begin()
//    );
//
//    // Resize result to actual size
//    union_result.resize(union_it - union_result.begin());
//
//    // Print the union result
//    std::cout << "Set Union: ";
//    for (int num : union_result)
//        std::cout << num << " ";
//    std::cout << std::endl;
//
//    // Accumulate example
//    std::vector<int> nums2 = { 1, 2, 3, 4, 5 };
//
//    // Sum of elements
//    int sum = std::accumulate(nums2.begin(), nums2.end(), 0);
//    std::cout << "Sum of elements: " << sum << std::endl;
//
//    // Reverse the vector
//    std::reverse(nums2.begin(), nums2.end());
//    std::cout << "Reversed: ";
//    for (int num : nums2)
//        std::cout << num << " ";
//    std::cout << std::endl;
//
//    // Unique example - removing duplicates
//    vector<int> nums3 = { 1, 1, 2, 3, 3, 4, 4 };
//    auto unique_it = std::unique(nums3.begin(), nums3.end());
//    nums3.erase(unique_it, nums3.end());
//    cout << "After removing duplicates: ";
//    for (int num : nums3) std::cout << num << " ";
//    std::cout << std::endl;
//
//    // Code to print duplicates
//    vector<int> nums_with_dups = { 1, 2, 2, 3, 4, 4, 5, 5, 5 };
//    cout << "Original vector with duplicates: ";
//    for (int num : nums_with_dups) std::cout << num << " ";
//    std::cout << std::endl;
//
//    cout << "Duplicates: ";
//    vector<bool> seen(10, false); // Assuming numbers are between 0-9
//    for (int num : nums_with_dups) {
//        if (seen[num]) {
//            cout << num << " ";
//        }
//        else {
//            seen[num] = true;
//        }
//    }
//    cout << endl;
//
//    // For_each example - multiplying elements by 3
//    vector<int> nums4 = { 1, 2, 3, 4, 5 };
//    cout << "Before multiplication: ";
//    for (int num : nums4) std::cout << num << " ";
//    std::cout << std::endl;
//
//    // Multiply elements from index 2 to second-to-last by 3
//    for_each(nums4.begin() + 2, nums4.end() - 1, [](int& n) { n *= 3; });
//
//    cout << "After multiplication: ";
//    for (int num : nums4) std::cout << num << " ";
//    std::cout << std::endl;
//
//    // ---- Factorial implementations ----
//
//    // Method 1: Calculate factorial using for_each
//    cout << "\n--- Factorial using for_each ---\n";
//    int n = 5;
//    int factorial_result = 1;
//
//    // Create a vector of numbers from 1 to n
//    vector<int> numbers(n);
//    iota(numbers.begin(), numbers.end(), 1); // Fill with 1, 2, 3, ..., n
//
//    // Use for_each to multiply each element with the running product
//    for_each(numbers.begin(), numbers.end(), [&factorial_result](int x) {
//        factorial_result *= x;
//        });
//
//    cout << n << "! = " << factorial_result << endl;
//
//    // Method 2: Calculate factorial using transform
//    cout << "\n--- Factorial using transform ---\n";
//    n = 6;
//    numbers.resize(n);
//    iota(numbers.begin(), numbers.end(), 1); // Fill with 1, 2, 3, ..., n
//
//    // Create a vector to store partial products
//    vector<int> partial_products(n);
//    partial_products[0] = 1; // First element is 1
//
//    // Use transform to calculate partial products
//    transform(numbers.begin(), numbers.end() - 1,
//        partial_products.begin(), partial_products.begin() + 1,
//        [](int x, int prev_product) { return x * prev_product; });
//
//    cout << "Partial products: ";
//    for (int prod : partial_products) cout << prod << " ";
//    cout << endl;
//
//    cout << n << "! = " << partial_products.back() << endl;
//
//    // Method 3: Calculate factorial using accumulate
//    cout << "\n--- Factorial using accumulate ---\n";
//    n = 7;
//    numbers.resize(n);
//    iota(numbers.begin(), numbers.end(), 1); // Fill with 1, 2, 3, ..., n
//
//    int factorial_accum = accumulate(numbers.begin(), numbers.end(), 1,
//        [](int product, int x) { return product * x; });
//
//    cout << n << "! = " << factorial_accum << endl;
//
//    return 0;
//}

//output :
//Before Sorting : 5 4 7 8 1 2 9 3 6 0
//After Sorting : 0 1 2 3 4 5 6 7 8 9
//After filling with 0 : 0 0 0 0 0 0 0 0 0 0
//After adding 5 to first 3 elements : 5 5 5 0 0 0 0 0 0 0
//Found 3 at Position 7
//Set Union : 1 2 3 4 5 6 7 8 9
//Sum of elements : 15
//Reversed : 5 4 3 2 1
//After removing duplicates : 1 2 3 4
//Original vector with duplicates : 1 2 2 3 4 4 5 5 5
//Duplicates : 2 4 5 5
//Before multiplication : 1 2 3 4 5
//After multiplication : 1 2 9 12 5
//
//-- - Factorial using for_each-- -
//5!= 120
//
//-- - Factorial using transform-- -
//Partial products : 1 1 2 6 24 120
//6!= 120
//
//-- - Factorial using accumulate-- -
//7!= 5040