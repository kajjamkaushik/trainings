/*
Types of Iterators in C++:

1. Input Iterator:
   - Reads elements sequentially from a container.
   - Cannot modify elements.
   - Example: istream_iterator (used for reading input from streams), std::find().
   - Pros: Can read from input sources like files or standard input, requires minimal memory.
   - Cons: Cannot move backward, cannot modify elements.

2. Output Iterator:
   - Writes values sequentially to a container.
   - Cannot read elements.
   - Example: ostream_iterator (used to write output to streams), std::copy().
   - Pros: Useful for inserting or writing elements, efficient for output operations.
   - Cons: Cannot read elements, cannot move backward.

3. Forward Iterator:
   - Supports reading and writing, moves forward only.
   - Can be used multiple times (unlike input iterator).
   - Example: std::forward_list.
   - Pros: Allows both reading and writing.
   - Cons: Cannot move backward.

4. Bidirectional Iterator:
   - Allows both forward and backward movement.
   - Example: std::list, std::map.
   - Pros: Can iterate both forward and backward, useful for ordered data structures.
   - Cons: Cannot perform direct access (random access is not possible), slower than random access iterators.

5. Random Access Iterator:
   - Provides full access to container elements.
   - Allows forward, backward traversal, and direct access using indexing.
   - Example: std::vector, std::array, std::deque.
   - Pros: Fastest iteration type, supports random access (it + n, it - n).
   - Cons: Consumes more memory, not available for all container types (e.g., list, map).

Comparison Table:
| Iterator Type         | Read | Write | Move Forward | Move Backward | Random Access |
|----------------------|------|------|--------------|--------------|--------------|
| Input Iterator      | ✅   | ❌   | ✅           | ❌           | ❌           |
| Output Iterator     | ❌   | ✅   | ✅           | ❌           | ❌           |
| Forward Iterator    | ✅   | ✅   | ✅           | ❌           | ❌           |
| Bidirectional Iterator | ✅   | ✅   | ✅           | ✅           | ❌           |
| Random Access Iterator | ✅   | ✅   | ✅           | ✅           | ✅           |
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <forward_list>

// Input Iterator Example
int inputIteratorExample() {
    std::vector<int> v = { 10, 20, 30, 40 };
    std::vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        std::cout << *it << " ";
        ++it;
    }
    return 0;
}

// Output Iterator Example
int outputIteratorExample() {
    std::vector<int> v = { 1, 2, 3, 4 };
    std::ostream_iterator<int> out_it(std::cout, " ");
    std::copy(v.begin(), v.end(), out_it);
    return 0;
}

// Forward Iterator Example
int forwardIteratorExample() {
    std::forward_list<int> fl = { 10, 20, 30, 40 };
    for (auto it = fl.begin(); it != fl.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}

// Bidirectional Iterator Example
int bidirectionalIteratorExample() {
    std::list<int> lst = { 10, 20, 30, 40 };
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nReverse order: ";
    for (auto rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    return 0;
}

// Random Access Iterator Example
int randomAccessIteratorExample() {
    std::vector<int> vec = { 10, 20, 30, 40, 50 };
    std::vector<int>::iterator it = vec.begin();
    std::cout << "First element: " << *it << "\n";
    it += 2; // Move forward by 2 positions
    std::cout << "Third element: " << *it << "\n";
    return 0;
}

int main() {
    std::cout << "\nInput Iterator:\n";
    inputIteratorExample();

    std::cout << "\n\nOutput Iterator:\n";
    outputIteratorExample();

    std::cout << "\n\nForward Iterator:\n";
    forwardIteratorExample();

    std::cout << "\n\nBidirectional Iterator:\n";
    bidirectionalIteratorExample();

    std::cout << "\n\nRandom Access Iterator:\n";
    randomAccessIteratorExample();

    return 0;
}
