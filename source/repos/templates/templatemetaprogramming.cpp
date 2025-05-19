//1. What is Template Metaprogramming(TMP) ?
//Template Metaprogramming(TMP) is a technique in C++ that allows computation to be performed at compile - time using templates.TMP uses the C++ template system to generate code based on the provided parameters before the actual compilation starts.
//
//It transforms the C++ compiler into a kind of "compile-time interpreter", where templates can perform calculations, generate specialized code, and optimize the program before execution.
//
//2. Why Use Template Metaprogramming ?
//TMP is primarily used for :
//
//	Performance optimization : Certain computations can be done at compile - time, reducing runtime overhead.
//	Code generation : Eliminates redundancy by automating repetitive tasks.
//	Type safety enforcement : Helps enforce strict type - checking at compile - time.
//	Static polymorphism : Achieves polymorphism without runtime overhead.
//	Mathematical computations : Precompute values such as factorial, Fibonacci series, etc., at compile time.

//(a)Templates: The Foundation of TMP
//Templates in C++ allow generic programming by enabling functions and 
// classes to work with different data types without rewriting the code.
//#include<iostream>
//using namespace std;
//template <typename T>
//T add(T a, T b) {
//    return a + b;
//}
//int main() {
//    cout << add(5, 10) << endl;    // Works with int //op 15
//    cout << add(5.5, 10.3) << endl; // Works with double //op 15.8
//    return 0;
//}



//(b)Recursive Template Instantiation
//TMP heavily relies on recursion at compile - time to process values and types.
//Example: Compile - time Factorial Calculation
//#include <iostream>
//using namespace std;
//template<int N>
//struct Factorial {
//    static const int value = N * Factorial<N - 1>::value;
//};
//// Base case specialization
//template<>
//struct Factorial<0> {
//    static const int value = 1;
//};
//int main() {
//    cout << "Factorial of 5: " << Factorial<5>::value << endl;
//    return 0;
//}

//Explanation:
//Factorial<N> recursively instantiates itself until Factorial<0> is reached.
//The compiler computes the result during compilation itself.
//Compile - time Execution Flow :
//Factorial<5>::value = 5 * Factorial<4>::value
//Factorial<4>::value = 4 * Factorial<3>::value
//Factorial<3>::value = 3 * Factorial<2>::value
//Factorial<2>::value = 2 * Factorial<1>::value
//Factorial<1>::value = 1 * Factorial<0>::value
//Factorial<0>::value = 1
//At compile - time, Factorial<5>::value gets calculated as 120, and no runtime computation is needed.

//(c)SFINAE(Substitution Failure Is Not An Error)
//SFINAE allows templates to be conditionally selected based on available types.
//Example: Enabling template specialization based on type
//#include <iostream>
//using namespace std;
//// Primary template
//template <typename T>
//void printType(T) {
//    cout << "Generic Type" << endl;
//}
//// Specialization for int
//template <>
//void printType<int>(int) {
//    cout << "Integer Type" << endl;
//}
//int main() {
//    printType(5);       // Calls specialized version /// op :Integer Type
//    printType(5.5);     // Calls generic version  /// op : Generic Type
//    return 0;
//}
//
//


//(d)Type Traits(Checking Types at Compile - Time)
//C++ provides the <type_traits> library for type - based metaprogramming.
//Example: Checking if a type is an integer
//#include <iostream>
//#include <type_traits>
//using namespace std;
//template <typename T>
//void checkType() {
//    if constexpr (std::is_integral<T>::value)
//        cout << "Integer Type" << endl;
//    else
//        cout << "Non-Integer Type" << endl;
//}
//int main() {
//    checkType<int>();    // op :Integer Type
//    checkType<double>(); // op: Non-Integer Type
//    return 0;
//}

//4. Advanced TMP Concepts
////(a) Variadic Templates(Handling Multiple Parameters)
////Variadic templates allow arbitrary number of template arguments.
//#include <iostream>
//using namespace std;
//// Base case
//void print() {
//    cout << "End of list" << endl;
//}
//// Variadic template function
//template <typename T, typename... Args>
//void print(T first, Args... rest) {
//    cout << first << " \n";
//    print(rest...); // Recursive call with remaining arguments
//}
//int main() {
//    print(1, 2.5, "Hello", 'A');
//    return 0;
//}
//print takes multiple arguments and recursively processes them.
//output:
//1
//2.5
//Hello
//A
//End of list


//#include <iostream>
//#include <type_traits>
//using namespace std;
//// Function only available for integral types
//template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
//void process(T x) {
//    cout << x << " is an integer." << endl;
//}
//int main() {
//    process(10); // Works
//    // process(10.5); // Error, as it's not an integer
//    return 0;
//}


//5. Applications of Template Metaprogramming
//Compile - time Computation : Perform calculations before execution.
//Optimized Data Structures : Example: std::tuple(type - safe heterogeneous containers).
//Expression Templates : Used in scientific computing for optimizing mathematical expressions.
//Type - Safe Code : Ensures that only valid types are used.
//Policy - Based Design : Separates behavior into reusable components.
//Embedded Systems : Reduces runtime overhead in resource - constrained environments.
//6. Limitations of Template Metaprogramming
//Complex Error Messages : TMP errors are difficult to debug.
//Compilation Overhead : Increases compile time due to heavy template instantiations.
//Code Readability : Metaprogramming techniques make code harder to understand.
//Limited Debugging Support : Since TMP executes at compile - time, traditional debugging tools don't work.
//7. Conclusion
//Template Metaprogramming is a powerful technique that leverages C++ templates to perform computations at compile - time.It is widely used in high - performance computing, optimization, and type - safe programming.While TMP can make code efficient and generic, it also introduces complexity, requiring careful design and debugging.
//
//Key Takeaways
//✅ Compile - time execution improves runtime performance.
//✅ Recursion - based template instantiation is fundamental.
//✅ SFINAE, enable_if, and type traits help control template behavior.
//✅ Variadic templates allow flexible argument handling.
//✅ Trade - off between performance and complexity must be considered.