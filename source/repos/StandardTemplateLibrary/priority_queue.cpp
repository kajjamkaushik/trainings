// TOPIC: std::priority_queue In C++ (Priority Queue)
// WHAT IS IT ??
//0. std::priority_queue is a container adaptor that provides constant time lookup of the largest OR smallest element.
//1. By default std::vector is the container used inside.
//2. Cost of insertion and extraction is logarithmic.
//3. std::priority_queue is implemented using std::make_heap, std::push_heap, std::pop_heap functions.

//#include <functional>
//#include <queue>
//#include <vector>
//#include <iostream>
//using namespace std;
//template<typename T> void print_queue(T& q) {
//    while (!q.empty()) {
//        std::cout << q.top() << " ";
//        q.pop();
//    }
//    std::cout << '\n';
//}
//
//int main() {
//    {
//        std::priority_queue<int> q;
//        for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) { q.push(elm); }
//        print_queue(q);
//    }
//    // 9 8 7 6 5 4 3 2 1 0
//    {
//        std::priority_queue<int, vector<int>, greater<int>> q2;
//        for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) { q2.push(elm); }
//        print_queue(q2);
//    }
//    ///0 1 2 3 4 5 6 7 8 9
//    {
//        //using lambda to compare elements 
//        auto cmp = [](int left, int right) {return (left) < (right);};
//        std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
//        for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) { q3.push(elm); }
//        print_queue(q3);
//    }
//    ///9 8 7 6 5 4 3 2 1 0
//    return 0;
//}

