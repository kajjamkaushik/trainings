//#include <iostream>
//#include <cstring> // For C-string functions like strlen, strcpy, etc.
//using namespace std;
//class String {
//public:
//    // Default constructor - creates an empty string
//    String() : res(nullptr), len(0) {
//        // Initialize with an empty string
//        res = new char[1];
//        res[0] = '\0';
//    }
//
//    // Constructor from C-string
//    String(const char* ch) {
//        if (ch == nullptr) {
//            // Handle null pointer case
//            len = 0;
//            res = new char[1];
//            res[0] = '\0';
//        }
//        else {
//            len = static_cast<unsigned int>(strlen(ch)); // Cast to prevent warning
//            res = new char[len + 1]; // +1 for null terminator
//            strcpy_s(res, len + 1, ch); // Using secure version
//        }
//    }
//
//    // Copy constructor
//    String(const String& str) {
//        len = str.len;
//        res = new char[len + 1];
//        strcpy_s(res, len + 1, str.res); // Using secure version
//    }
//
//    // Move constructor
//    String(String&& str) noexcept {
//        len = str.len;
//        res = str.res;
//        // Reset the source object
//        str.res = nullptr;
//        str.len = 0;
//    }
//
//    // Destructor
//    ~String() {
//        if (res) {
//            delete[] res;
//            res = nullptr;
//            len = 0;
//        }
//    }
//
//    // Copy assignment operator
//    String& operator=(const String& str) {
//        if (this != &str) { // Self-assignment check
//            char* temp = new char[str.len + 1];
//            strcpy_s(temp, str.len + 1, str.res); // Using secure version
//
//            delete[] res;
//            res = temp;
//            len = str.len;
//        }
//        return *this;
//    }
//
//    // Move assignment operator
//    String& operator=(String&& str) noexcept {
//        if (this != &str) {
//            delete[] res;
//
//            res = str.res;
//            len = str.len;
//
//            str.res = nullptr;
//            str.len = 0;
//        }
//        return *this;
//    }
//
//    // Swap function to efficiently exchange the contents of two strings
//    void swap(String& other) noexcept {
//        std::swap(res, other.res);
//        std::swap(len, other.len);
//    }
//
//    // Return the length of the string
//    unsigned int length() const {
//        return len;
//    }
//
//    // Return C-string representation
//    const char* c_str() const {
//        return res;
//    }
//
//    // Concatenation operator
//    String operator+(const String& str) const {
//        String result;
//        result.len = len + str.len;
//        delete[] result.res;
//        result.res = new char[result.len + 1];
//
//        strcpy_s(result.res, result.len + 1, res); // Using secure version
//        strcat_s(result.res, result.len + 1, str.res); // Using secure version
//
//        return result;
//    }
//
//    // Append operator
//    String& operator+=(const String& str) {
//        *this = *this + str;
//        return *this;
//    }
//
//    // Comparison operators
//    bool operator==(const String& str) const {
//        return strcmp(res, str.res) == 0;
//    }
//
//    bool operator!=(const String& str) const {
//        return !(*this == str);
//    }
//
//    // Subscript operator for non-const objects
//    char& operator[](unsigned int index) {
//        if (index >= len) {
//            throw std::out_of_range("String index out of range");
//        }
//        return res[index];
//    }
//
//    // Subscript operator for const objects
//    const char& operator[](unsigned int index) const {
//        if (index >= len) {
//            throw std::out_of_range("String index out of range");
//        }
//        return res[index];
//    }
//
//    // Find substring, returns position or -1 if not found
//    int find(const String& substr) const {
//        const char* pos = strstr(res, substr.res);
//        if (pos == nullptr) return -1;
//        return static_cast<int>(pos - res);
//    }
//
//    // Extract substring
//    String substr(unsigned int pos, unsigned int count = -1) const {
//        if (pos >= len) {
//            throw std::out_of_range("String position out of range");
//        }
//
//        unsigned int actual_count = (count == -1 || pos + count > len) ? len - pos : count;
//
//        char* temp = new char[actual_count + 1];
//        strncpy_s(temp, actual_count + 1, res + pos, actual_count); // Using secure version
//        temp[actual_count] = '\0';
//
//        String result(temp);
//        delete[] temp;
//        return result;
//    }
//
//    friend ostream& operator<<(ostream& out, const String& str);
//    friend istream& operator>>(istream& in, String& str);
//
//private:
//    char* res;          // Pointer to character array
//    unsigned int len;   // Length of the string (excluding null terminator)
//};
//
//// Output stream operator
//ostream& operator<<(ostream& out, const String& str) {
//    if (str.res) {
//        out << str.res;
//    }
//    return out;
//}
//
//// Input stream operator
//istream& operator>>(istream& in, String& str) {
//    char buffer[1024]; // Temporary buffer for input
//    in >> buffer;
//
//    delete[] str.res;
//    str.len = static_cast<unsigned int>(strlen(buffer)); // Cast to prevent warning
//    str.res = new char[str.len + 1];
//    strcpy_s(str.res, str.len + 1, buffer); // Using secure version
//
//    return in;
//}
//
//// Implementation of strcpy function for educational purposes
//void my_strcpy(char* dest, const char* src, size_t destSize) {
//    // Secure version checks destination buffer size
//    size_t i = 0;
//    // Copy characters from src to dest until null terminator or buffer limit
//    while (src[i] != '\0' && i < destSize - 1) {
//        dest[i] = src[i];
//        i++;
//    }
//    // Add null terminator to dest
//    dest[i] = '\0';
//}
//
//int main() {
//    // Test default constructor
//    String str1;
//    cout << "str1 (default constructor): \"" << str1 << "\"" << endl;
//
//    // Test constructor with C-string
//    String str2 = "Hello";
//    cout << "str2 (C-string constructor): \"" << str2 << "\"" << endl;
//
//    // Test copy constructor
//    String str3 = str2;
//    cout << "str3 (copy of str2): \"" << str3 << "\"" << endl;
//
//    // Test length method
//    int len = str2.length();
//    cout << "Length of str2: " << len << endl;
//
//    // Test input
//    cout << "Enter a string for str1: ";
//    cin >> str1;
//    cout << "str1 after input: \"" << str1 << "\"" << endl;
//
//    // Test copy constructor again
//    String str5(str1);
//    cout << "str5 (copy of str1): \"" << str5 << "\"" << endl;
//
//    // Test move constructor
//    String str6 = std::move(str2);
//    cout << "str6 (moved from str2): \"" << str6 << "\"" << endl;
//    cout << "str2 after move: \"" << str2 << "\"" << endl;
//
//    // Test concatenation
//    String str7 = str1 + String(" World!");
//    cout << "str7 (str1 + \" World!\"): \"" << str7 << "\"" << endl;
//
//    // Test comparison
//    if (str1 == str5) {
//        cout << "str1 and str5 are equal" << endl;
//    }
//
//    // Test substring
//    String str8 = str7.substr(0, 5);
//    cout << "str8 (first 5 chars of str7): \"" << str8 << "\"" << endl;
//
//    // Test swap functionality
//    cout << "Before swap: str1 = \"" << str1 << "\", str5 = \"" << str5 << "\"" << endl;
//    str1.swap(str5);
//    cout << "After swap: str1 = \"" << str1 << "\", str5 = \"" << str5 << "\"" << endl;
//
//    return 0;
//}