//#include <iostream>
//#include <memory>
//using namespace std;
//
////class Sample {
////public:
////    Sample() {
////        cout << "Default Constructor" << endl;
////    }
////    ~Sample() {
////        cout << "Sample Destructor" << endl;
////    }
////};
////
////void fun() {
////    // Sample *sam = new Sample(); // Raw pointer (Not recommended)
////    std::shared_ptr<Sample> sam(new Sample()); // Smart pointer (Automatic memory management)
////    throw std::runtime_error("Runtime Error");
////    cout << "After exception " << endl; // Control never reaches here
////}
//
//class smartPointer {
//    int* intptr; 
//public:
//    explicit smartPointer(int* ptr) : intptr(ptr) { 
//    }
//    ~smartPointer() {
//        delete intptr;
//    }
//};
//
//int main() {
//    /*try {
//        cout << "Hello World!!!" << endl;
//        fun();
//    }
//    catch (const std::exception& e) { 
//        cout << e.what() << endl;
//    }*/
//
//    return 0;
//}
