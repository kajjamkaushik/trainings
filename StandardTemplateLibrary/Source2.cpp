//#include <iostream>
//#include <unordered_map>
//#include <unordered_set>
//using namespace std;
//int main()
//{
//    unordered_map<char, int> original = {
//        {'a', 10},
//        {'b', 20},
//        {'c', 30},
//        {'d', 10},
//        {'p',10},
//        {'e', 40}
//    };
//    unordered_map<int, int> freq;
//    for (auto ele : original)
//    {
//        freq[ele.second]++;
//    }
//    //filtering chesthe 
//    unordered_map<char, int> filterkaro;
//    for (auto ele : original)
//    {
//        if (freq[ele.second]==1)
//        {
//            filterkaro[ele.first] = ele.second;
//        }
//    }
//    for (auto ele : filterkaro)
//    {
//        cout << ele.first << " : " << ele.second<<endl;
//    }
//
//    return 0;
//}
