// TOPIC: Map In C++

// NOTES:
// 1. Syntax: map<T1, T2> obj;  // where T1 is key type and T2 is value type.
// 2. std::map is associative container that store elements in key value combination
//    where key should be unique, otherwise it overrides the previous value.
// 3. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree).
// 4. It store key value pair in sorted order on the basis of key (assending/decending).
// 5. std::map is generally used in Dictionary type problems.

// EXAMPLE: Dictionary

#include<map>
#include<iostream>
#include<functional>
#include<vector>
#include<string>
using namespace std;

//int main()
//{
//	map<string, int> mpp;
//	mpp["chotu"] = 65789098;
//	mpp["Amit"] = 324567897;
//	mpp.insert(make_pair("bahu", 68576579));
//
//	///loop thorugh map
//	for (auto& ele : mpp)
//	{
//		cout << ele.first << " " << ele.second << endl;
//	}
//	/*Amit 324567897
//		bahu 68576579
//		chotu 65789098
//	*/
//	///access using [] operator 
//	cout << mpp["chotu"] << endl; // already present  65789098
//	// accessing key which is not there then what happens : prints default int value i.e 0 
//	cout << mpp["kaushik"] << endl; // already not present :0
//
//	cout << "=========================================================================================================" << endl;
//	map<string, vector<int>, std::less<>> map;
//	map["chotu"].push_back(9097808);
//	map["Amit"].push_back(3408765);
//	map["Amit"].push_back(1908765);
//	map["Amit"].push_back(798151);
//	map["tetha"].push_back(66793);
//
//	map.insert(make_pair("kasuik", vector<int>{456789}));
//	for (auto& ele : map)
//	{
//		cout << ele.first << " - ";
//		for (auto& ele2 : ele.second)
//			cout << ele2 << " ";
//		cout << endl;
//	}
//	return 0;
//}

// Helper function to print a map
//template<typename K, typename V>
//void printMap(const std::map<K, V>& m, const std::string& name) {
//    std::cout << name << " (size: " << m.size() << "): ";
//    for (const auto& pair : m) {
//        std::cout << "{" << pair.first << ": " << pair.second << "} ";
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    std::cout << "=== std::map Methods Demonstration (up to C++17) ===\n\n";
//
//    // === Constructors ===
//    std::cout << "=== Constructors ===\n";
//
//    // Default constructor
//    std::map<int, std::string> map1;
//    map1[1] = "one";
//    map1[2] = "two";
//    printMap(map1, "Default constructor map");
//
//    // Range constructor
//    std::vector<std::pair<int, std::string>> vec = { {3, "three"}, {4, "four"} };
//    std::map<int, std::string> map2(vec.begin(), vec.end());
//    printMap(map2, "Range constructor map");
//
//    // Copy constructor
//    std::map<int, std::string> map3(map1);
//    printMap(map3, "Copy constructor map");
//
//    // Move constructor
//    std::map<int, std::string> map4(std::move(map3));
//    printMap(map4, "Move constructor map");
//    std::cout << "map3 after move (should be empty): " << map3.size() << std::endl;
//
//    // Initializer list constructor
//    std::map<int, std::string> map5{ {5, "five"}, {6, "six"}, {7, "seven"} };
//    printMap(map5, "Initializer list constructor map");
//
//    // Custom comparator constructor
//    std::map<int, std::string, std::greater<int>> map6{ {1, "one"}, {2, "two"}, {3, "three"} };
//    printMap(map6, "Custom comparator map (descending order)");
//
//    std::cout << "\n=== Assignment ===\n";
//
//    // Copy assignment
//    std::map<int, std::string> map7;
//    map7 = map5;
//    printMap(map7, "Copy assigned map");
//
//    // Move assignment
//    std::map<int, std::string> map8;
//    map8 = std::move(map7);
//    printMap(map8, "Move assigned map");
//    std::cout << "map7 after move assignment (should be empty): " << map7.size() << std::endl;
//
//    // Initializer list assignment
//    map7 = { {10, "ten"}, {20, "twenty"} };
//    printMap(map7, "Initializer list assigned map");
//
//    std::cout << "\n=== Allocator ===\n";
//    auto alloc = map1.get_allocator();
//    std::cout << "Allocator obtained (address): " << &alloc << std::endl;
//
//    std::cout << "\n=== Element Access ===\n";
//
//    // at() method
//    try {
//        std::cout << "map1.at(1): " << map1.at(1) << std::endl;
//        std::cout << "map1.at(99) (non-existent): ";
//        std::cout << map1.at(99) << std::endl;  // This will throw
//    }
//    catch (const std::out_of_range& e) {
//        std::cout << "Exception caught: " << e.what() << std::endl;
//    }
//
//    // operator[]
//    std::cout << "map1[2]: " << map1[2] << std::endl;
//    std::cout << "map1[3] (creates new element): " << map1[3] << std::endl;
//    printMap(map1, "map1 after operator[]");
//
//    std::cout << "\n=== Iterators ===\n";
//
//    std::map<int, std::string> iterMap{ {1, "one"}, {2, "two"}, {3, "three"} };
//
//    // begin/end
//    std::cout << "Forward iteration with begin()/end():\n";
//    for (auto it = iterMap.begin(); it != iterMap.end(); ++it) {
//        std::cout << "  " << it->first << ": " << it->second << std::endl;
//    }
//
//    // cbegin/cend (const iterators)
//    std::cout << "Const forward iteration with cbegin()/cend():\n";
//    for (auto it = iterMap.cbegin(); it != iterMap.cend(); ++it) {
//        std::cout << "  " << it->first << ": " << it->second << std::endl;
//        // it->second = "modified";  // Would cause compilation error
//    }
//
//    // rbegin/rend (reverse iterators)
//    std::cout << "Reverse iteration with rbegin()/rend():\n";
//    for (auto it = iterMap.rbegin(); it != iterMap.rend(); ++it) {
//        std::cout << "  " << it->first << ": " << it->second << std::endl;
//    }
//
//    // crbegin/crend (const reverse iterators)
//    std::cout << "Const reverse iteration with crbegin()/crend():\n";
//    for (auto it = iterMap.crbegin(); it != iterMap.crend(); ++it) {
//        std::cout << "  " << it->first << ": " << it->second << std::endl;
//    }
//
//    std::cout << "\n=== Capacity ===\n";
//
//    // empty
//    std::map<int, std::string> emptyMap;
//    std::cout << "Is emptyMap empty? " << (emptyMap.empty() ? "Yes" : "No") << std::endl;
//    std::cout << "Is map1 empty? " << (map1.empty() ? "Yes" : "No") << std::endl;
//
//    // size
//    std::cout << "Size of map1: " << map1.size() << std::endl;
//
//    // max_size
//    std::cout << "Max size of map1: " << map1.max_size() << std::endl;
//
//    std::cout << "\n=== Modifiers ===\n";
//
//    std::map<int, std::string> modMap{ {1, "one"}, {2, "two"} };
//    printMap(modMap, "Initial modMap");
//
//    // clear
//    std::map<int, std::string> clearMap{ {1, "one"}, {2, "two"} };
//    std::cout << "Before clear, size: " << clearMap.size() << std::endl;
//    clearMap.clear();
//    std::cout << "After clear, size: " << clearMap.size() << std::endl;
//
//    // insert
//    // Single element
//    auto insertResult = modMap.insert({ 3, "three" });
//    std::cout << "Insert {3, \"three\"}: "
//        << (insertResult.second ? "Success" : "Failed")
//        << ", key: " << insertResult.first->first
//        << ", value: " << insertResult.first->second << std::endl;
//
//    // With hint
//    auto it = modMap.begin();
//    modMap.insert(it, { 4, "four" });
//    printMap(modMap, "After hint insert");
//
//    // Range insert
//    std::map<int, std::string> sourceMap{ {5, "five"}, {6, "six"} };
//    modMap.insert(sourceMap.begin(), sourceMap.end());
//    printMap(modMap, "After range insert");
//
//    // Initializer list insert
//    modMap.insert({ {7, "seven"}, {8, "eight"} });
//    printMap(modMap, "After initializer list insert");
//
//    // C++17: insert_or_assign
//    modMap.insert_or_assign(2, "TWO");
//    modMap.insert_or_assign(9, "nine");
//    printMap(modMap, "After insert_or_assign");
//
//    // emplace
//    auto emplaceResult = modMap.emplace(10, "ten");
//    std::cout << "Emplace {10, \"ten\"}: "
//        << (emplaceResult.second ? "Success" : "Failed") << std::endl;
//    printMap(modMap, "After emplace");
//
//    // emplace_hint
//    auto hint = modMap.find(10);
//    modMap.emplace_hint(hint, 11, "eleven");
//    printMap(modMap, "After emplace_hint");
//
//    // C++17: try_emplace
//    modMap.try_emplace(12, "twelve");
//    modMap.try_emplace(1, "ONE");  // Won't replace existing
//    printMap(modMap, "After try_emplace");
//
//    // erase
//    // Erase by iterator
//    auto eraseIt = modMap.find(12);
//    if (eraseIt != modMap.end()) {
//        modMap.erase(eraseIt);
//    }
//    printMap(modMap, "After erase by iterator");
//
//    // Erase by key
//    size_t erased = modMap.erase(11);
//    std::cout << "Erased " << erased << " elements with key 11" << std::endl;
//    printMap(modMap, "After erase by key");
//
//    // Erase by range
//    auto rangeStart = modMap.find(7);
//    auto rangeEnd = modMap.find(10);
//    if (rangeStart != modMap.end() && rangeEnd != modMap.end()) {
//        modMap.erase(rangeStart, rangeEnd);
//    }
//    printMap(modMap, "After erase by range");
//
//    // swap
//    std::map<int, std::string> swapMap1{ {100, "hundred"}, {200, "two hundred"} };
//    std::map<int, std::string> swapMap2{ {300, "three hundred"}, {400, "four hundred"} };
//    printMap(swapMap1, "swapMap1 before swap");
//    printMap(swapMap2, "swapMap2 before swap");
//    swapMap1.swap(swapMap2);
//    printMap(swapMap1, "swapMap1 after swap");
//    printMap(swapMap2, "swapMap2 after swap");
//
//    // C++17: extract
//    std::map<int, std::string> extractMap{ {1, "one"}, {2, "two"}, {3, "three"} };
//    auto extractedNode = extractMap.extract(2);
//    std::cout << "Extracted node: {" << extractedNode.key() << ", " << extractedNode.mapped() << "}" << std::endl;
//    printMap(extractMap, "Map after extraction");
//
//    // Change key of extracted node
//    extractedNode.key() = 20;
//    extractMap.insert(std::move(extractedNode));
//    printMap(extractMap, "Map after reinsertion with modified key");
//
//    // C++17: merge
//    std::map<int, std::string> mergeMap1{ {1, "one"}, {2, "two"} };
//    std::map<int, std::string> mergeMap2{ {2, "TWO"}, {3, "three"} };
//    printMap(mergeMap1, "mergeMap1 before merge");
//    printMap(mergeMap2, "mergeMap2 before merge");
//    mergeMap1.merge(mergeMap2);
//    printMap(mergeMap1, "mergeMap1 after merge");
//    printMap(mergeMap2, "mergeMap2 after merge (duplicate keys remain)");
//
//    std::cout << "\n=== Lookup ===\n";
//
//    std::map<int, std::string> lookupMap{ {1, "one"}, {2, "two"}, {3, "three"}, {3, "THREE"} };
//
//    // count
//    std::cout << "Count of key 2: " << lookupMap.count(2) << std::endl;
//    std::cout << "Count of key 4: " << lookupMap.count(4) << std::endl;
//
//    // find
//    auto findIt = lookupMap.find(2);
//    if (findIt != lookupMap.end()) {
//        std::cout << "Found key 2 with value: " << findIt->second << std::endl;
//    }
//
//    findIt = lookupMap.find(4);
//    if (findIt == lookupMap.end()) {
//        std::cout << "Key 4 not found" << std::endl;
//    }
//
//    // equal_range
//    auto range = lookupMap.equal_range(2);
//    std::cout << "Equal range for key 2:" << std::endl;
//    for (auto it = range.first; it != range.second; ++it) {
//        std::cout << "  " << it->first << ": " << it->second << std::endl;
//    }
//
//    // lower_bound
//    auto lbIt = lookupMap.lower_bound(2);
//    if (lbIt != lookupMap.end()) {
//        std::cout << "Lower bound of key 2: {" << lbIt->first << ", " << lbIt->second << "}" << std::endl;
//    }
//
//    // upper_bound
//    auto ubIt = lookupMap.upper_bound(2);
//    if (ubIt != lookupMap.end()) {
//        std::cout << "Upper bound of key 2: {" << ubIt->first << ", " << ubIt->second << "}" << std::endl;
//    }
//
//    std::cout << "\n=== Observers ===\n";
//
//    // key_comp
//    auto keyComp = lookupMap.key_comp();
//    std::cout << "key_comp(1, 2): " << keyComp(1, 2) << std::endl;
//    std::cout << "key_comp(2, 1): " << keyComp(2, 1) << std::endl;
//
//    // value_comp
//    auto valueComp = lookupMap.value_comp();
//    std::pair<int, std::string> p1(1, "one");
//    std::pair<int, std::string> p2(2, "two");
//    std::cout << "value_comp({1,\"one\"}, {2,\"two\"}): " << valueComp(p1, p2) << std::endl;
//
//    std::cout << "\n=== Non-member functions ===\n";
//
//    std::map<int, std::string> map_a{ {1, "one"}, {2, "two"} };
//    std::map<int, std::string> map_b{ {1, "one"}, {2, "two"} };
//    std::map<int, std::string> map_c{ {1, "one"}, {3, "three"} };
//
//    // Comparison operators
//    std::cout << "map_a == map_b: " << (map_a == map_b) << std::endl;
//    std::cout << "map_a != map_c: " << (map_a != map_c) << std::endl;
//    std::cout << "map_a < map_c: " << (map_a < map_c) << std::endl;
//    std::cout << "map_c > map_a: " << (map_c > map_a) << std::endl;
//    std::cout << "map_a <= map_b: " << (map_a <= map_b) << std::endl;
//    std::cout << "map_a >= map_b: " << (map_a >= map_b) << std::endl;
//
//    // std::swap
//    printMap(map_a, "map_a before std::swap");
//    printMap(map_c, "map_c before std::swap");
//    std::swap(map_a, map_c);
//    printMap(map_a, "map_a after std::swap");
//    printMap(map_c, "map_c after std::swap");
//
//    return 0;
//}