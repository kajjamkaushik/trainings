//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    std::vector<int> Vec;
//
//    //cout << Vec[1000000000000] << endl;  // Unsafe: No bounds check!
//    // (process 15524) exited with code 3 (0x3).
//    ////-------------------------------------------------------------------------------------------------
//    //cout << Vec.at(1000000000000) << endl;
//    ///(process 23828) exited with code -1 (0xffffffff).
//    ///libc++abi: terminating due to uncaught exception of type std::out_of_range: vector
//    ///zsh: abort . / a.out
//
//    ////-------------------------------------------------------------------------------------------------
//    try {
//        cout << Vec.at(1000000000000) << endl;  // Safe: Throws exception if out-of-bounds
//    }
//    catch (...) {
//        cout << "Out of range handled" << endl;
//    }
//    
//    cout << "Hello there I am still alive" << endl;
//    //op : Out of range handled
//        //Hello there I am still alive
//    return 0;
//}
