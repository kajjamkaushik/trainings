#include <iostream>
#include <vector>
#include <cctype>  // For isspace, tolower, toupper

using namespace std;

class String {
public:
    // Custom string function implementations

    // Custom strlen implementation
    static size_t my_strlen(const char* str) {
        size_t len = 0;
        if (str) {
            while (str[len] != '\0') {
                len++;
            }
        }
        return len;
    }

    // Custom strcpy_s implementation
    static int my_strcpy_s(char* dest, size_t destSize, const char* src) {
        if (dest == nullptr || src == nullptr || destSize == 0) {
            return 1; // Error
        }

        size_t srcLen = my_strlen(src);
        if (srcLen >= destSize) {
            dest[0] = '\0';
            return 1; // Error
        }

        for (size_t i = 0; i <= srcLen; i++) {
            dest[i] = src[i];
        }

        return 0; // Success
    }

    // Custom strncpy_s implementation
    static int my_strncpy_s(char* dest, size_t destSize, const char* src, size_t count) {
        if (dest == nullptr || src == nullptr || destSize == 0) {
            return 1; // Error
        }

        size_t i;
        for (i = 0; i < count && i < destSize - 1 && src[i] != '\0'; i++) {
            dest[i] = src[i];
        }

        if (i < destSize) {
            dest[i] = '\0';
            return 0; // Success
        }
        else {
            dest[0] = '\0';
            return 1; // Error
        }
    }

    // Custom strcat_s implementation
    static int my_strcat_s(char* dest, size_t destSize, const char* src) {
        if (dest == nullptr || src == nullptr || destSize == 0) {
            return 1; // Error
        }

        size_t destLen = my_strlen(dest);
        size_t srcLen = my_strlen(src);

        if (destLen + srcLen >= destSize) {
            return 1; // Error
        }

        for (size_t i = 0; i <= srcLen; i++) {
            dest[destLen + i] = src[i];
        }

        return 0; // Success
    }

    // Custom strcmp implementation
    static int my_strcmp(const char* str1, const char* str2) {
        while (*str1 && (*str1 == *str2)) {
            str1++;
            str2++;
        }
        return *(const unsigned char*)str1 - *(const unsigned char*)str2;
    }

    // Custom strstr implementation
    static int my_strstr(const char* haystack, const char* needle) {
        if (*needle == '\0') return 0;

        size_t needleLen = my_strlen(needle);
        size_t haystackLen = my_strlen(haystack);

        if (needleLen > haystackLen) return -1;

        for (size_t i = 0; i <= haystackLen - needleLen; i++) {
            size_t j;
            for (j = 0; j < needleLen; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needleLen) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }

    // Custom strchr implementation - find first occurrence of a character
    static char* my_strchr(const char* str, int ch) {
        while (*str != '\0' && *str != ch) {
            str++;
        }
        return (*str == ch) ? (char*)str : nullptr;
    }

    // Custom strtok implementation
    static char* my_strtok(char* str, const char* delim) {
        static char* next_token = nullptr;

        // If str is nullptr, use the saved pointer
        char* token_start = (str != nullptr) ? str : next_token;

        // Return nullptr if there are no more tokens
        if (token_start == nullptr || *token_start == '\0') {
            return nullptr;
        }

        // Skip leading delimiters
        token_start += strspn(token_start, delim);
        if (*token_start == '\0') {
            next_token = nullptr;
            return nullptr;
        }

        // Find the end of the token
        char* token_end = token_start + strcspn(token_start, delim);

        // Set up next_token for the next call
        if (*token_end == '\0') {
            next_token = nullptr;
        }
        else {
            *token_end = '\0';
            next_token = token_end + 1;
        }

        return token_start;
    }

    // Helper function: strspn - get length of a substring consisting of specified characters
    static size_t strspn(const char* str, const char* accept) {
        size_t count = 0;
        while (*str != '\0') {
            const char* a = accept;
            while (*a != '\0') {
                if (*str == *a) break;
                a++;
            }
            if (*a == '\0') return count;
            str++;
            count++;
        }
        return count;
    }

    // Helper function: strcspn - get length of a substring not consisting of specified characters
    static size_t strcspn(const char* str, const char* reject) {
        size_t count = 0;
        while (*str != '\0') {
            const char* r = reject;
            while (*r != '\0') {
                if (*str == *r) return count;
                r++;
            }
            str++;
            count++;
        }
        return count;
    }

    // Helper function: check if character is whitespace
    static bool my_isspace(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
    }

    // Helper function: convert to lowercase
    static char my_tolower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
        return c;
    }

    // Helper function: convert to uppercase
    static char my_toupper(char c) {
        if (c >= 'a' && c <= 'z') {
            return c - ('a' - 'A');
        }
        return c;
    }

    // Default constructor
    String() : res(nullptr), len(0) {
        res = new char[1];
        res[0] = '\0';
    }

    // Constructor from C-string
    String(const char* ch) {
        if (ch == nullptr) {
            len = 0;
            res = new char[1];
            res[0] = '\0';
        }
        else {
            len = static_cast<unsigned int>(my_strlen(ch));
            res = new char[len + 1];
            my_strcpy_s(res, len + 1, ch);
        }
    }

    // Copy constructor
    String(const String& str) {
        len = str.len;
        res = new char[len + 1];
        my_strcpy_s(res, len + 1, str.res);
    }

    // Move constructor
    String(String&& str) noexcept {
        len = str.len;
        res = str.res;
        str.res = nullptr;
        str.len = 0;
    }

    // Destructor
    ~String() {
        if (res) {
            delete[] res;
            res = nullptr;
            len = 0;
        }
    }

    // Copy assignment operator
    String& operator=(const String& str) {
        if (this != &str) {
            char* temp = new char[str.len + 1];
            my_strcpy_s(temp, str.len + 1, str.res);

            delete[] res;
            res = temp;
            len = str.len;
        }
        return *this;
    }

    // Move assignment operator
    String& operator=(String&& str) noexcept {
        if (this != &str) {
            delete[] res;

            res = str.res;
            len = str.len;

            str.res = nullptr;
            str.len = 0;
        }
        return *this;
    }

    // Swap function
    void swap(String& other) noexcept {
        std::swap(res, other.res);
        std::swap(len, other.len);
    }

    // Return the length of the string
    unsigned int length() const {
        return len;
    }

    // Return C-string representation
    const char* c_str() const {
        return res;
    }

    // Concatenation operator
    String operator+(const String& str) const {
        String result;
        result.len = len + str.len;
        delete[] result.res;
        result.res = new char[result.len + 1];

        my_strcpy_s(result.res, result.len + 1, res);
        my_strcat_s(result.res, result.len + 1, str.res);

        return result;
    }

    // Append operator
    String& operator+=(const String& str) {
        *this = *this + str;
        return *this;
    }

    // Comparison operators
    bool operator==(const String& str) const {
        return my_strcmp(res, str.res) == 0;
    }

    bool operator!=(const String& str) const {
        return !(*this == str);
    }

    // Subscript operator for non-const objects
    char& operator[](unsigned int index) {
        if (index >= len) {
            throw std::out_of_range("String index out of range");
        }
        return res[index];
    }

    // Subscript operator for const objects
    const char& operator[](unsigned int index) const {
        if (index >= len) {
            throw std::out_of_range("String index out of range");
        }
        return res[index];
    }

    // Find substring
    int find(const String& substr) const {
        return my_strstr(res, substr.res);
    }

    // Extract substring
    String substr(unsigned int pos, unsigned int count = -1) const {
        if (pos >= len) {
            throw std::out_of_range("String position out of range");
        }

        unsigned int actual_count = (count == -1 || pos + count > len) ? len - pos : count;

        char* temp = new char[actual_count + 1];
        my_strncpy_s(temp, actual_count + 1, res + pos, actual_count);
        temp[actual_count] = '\0';

        String result(temp);
        delete[] temp;
        return result;
    }

    // NEW FUNCTIONS

    // Check if string is empty
    bool isEmpty() const {
        return len == 0;
    }

    // Clear the string contents
    void clear() {
        delete[] res;
        res = new char[1];
        res[0] = '\0';
        len = 0;
    }

    // Reserve memory for future growth
    void reserve(unsigned int capacity) {
        if (capacity > len) {
            char* temp = new char[capacity + 1];
            my_strcpy_s(temp, capacity + 1, res);
            delete[] res;
            res = temp;
            // Note: len doesn't change, only the capacity
        }
    }

    // Trim whitespace from beginning and end
    String trim() const {
        if (isEmpty()) return *this;

        // Find first non-whitespace character
        unsigned int start = 0;
        while (start < len && my_isspace(res[start])) {
            start++;
        }

        // If string is all whitespace
        if (start == len) {
            return String();
        }

        // Find last non-whitespace character
        unsigned int end = len - 1;
        while (end > start && my_isspace(res[end])) {
            end--;
        }

        // Extract the trimmed substring
        return substr(start, end - start + 1);
    }

    // Convert to lowercase
    String toLower() const {
        String result(*this);
        for (unsigned int i = 0; i < len; i++) {
            result.res[i] = my_tolower(res[i]);
        }
        return result;
    }

    // Convert to uppercase
    String toUpper() const {
        String result(*this);
        for (unsigned int i = 0; i < len; i++) {
            result.res[i] = my_toupper(res[i]);
        }
        return result;
    }

    // Replace occurrences of a substring
    String replace(const String& oldStr, const String& newStr) const {
        if (oldStr.isEmpty() || oldStr == *this) {
            return newStr;
        }

        // Find all occurrences
        String result;
        unsigned int searchStart = 0;
        int foundPos;

        while ((foundPos = my_strstr(res + searchStart, oldStr.res)) != -1) {
            // Add the part before the match
            result += substr(searchStart, foundPos);

            // Add the replacement
            result += newStr;

            // Move search position
            searchStart += foundPos + oldStr.len;
        }

        // Add the remaining part
        if (searchStart < len) {
            result += substr(searchStart);
        }

        return result.isEmpty() ? *this : result;
    }

    // Split string into a vector of strings based on a delimiter
    std::vector<String> split(const String& delimiter) const {
        std::vector<String> result;

        if (isEmpty()) {
            return result;
        }

        if (delimiter.isEmpty()) {
            // If no delimiter, return the whole string as a single element
            result.push_back(*this);
            return result;
        }

        unsigned int start = 0;
        int foundPos;

        while ((foundPos = my_strstr(res + start, delimiter.res)) != -1) {
            result.push_back(substr(start, foundPos));
            start += foundPos + delimiter.len;
        }

        // Add the last part
        if (start < len) {
            result.push_back(substr(start));
        }

        return result;
    }
    // Join a vector of strings with a delimiter
    static String join(const std::vector<String>& strings, const String& delimiter) {
        if (strings.empty()) {
            return String();
        }

        String result = strings[0];

        for (size_t i = 1; i < strings.size(); i++) {
            result += delimiter + strings[i];
        }

        return result;
    }

    // Check if string starts with a specific substring
    bool startsWith(const String& prefix) const {
        if (prefix.len > len) {
            return false;
        }

        for (unsigned int i = 0; i < prefix.len; i++) {
            if (res[i] != prefix.res[i]) {
                return false;
            }
        }

        return true;
    }

    // Check if string ends with a specific substring
    bool endsWith(const String& suffix) const {
        if (suffix.len > len) {
            return false;
        }

        unsigned int start = len - suffix.len;
        for (unsigned int i = 0; i < suffix.len; i++) {
            if (res[start + i] != suffix.res[i]) {
                return false;
            }
        }

        return true;
    }

    // Convert string to integer
    int parseInt() const {
        if (isEmpty()) {
            return 0;
        }

        int result = 0;
        int sign = 1;
        unsigned int i = 0;

        // Handle sign
        if (res[0] == '-') {
            sign = -1;
            i = 1;
        }
        else if (res[0] == '+') {
            i = 1;
        }

        // Process digits
        for (; i < len && res[i] >= '0' && res[i] <= '9'; i++) {
            result = result * 10 + (res[i] - '0');
        }

        return result * sign;
    }

    // Convert string to float
    float parseFloat() const {
        if (isEmpty()) {
            return 0.0f;
        }

        float result = 0.0f;
        float fraction = 0.0f;
        int sign = 1;
        unsigned int i = 0;

        // Handle sign
        if (res[0] == '-') {
            sign = -1;
            i = 1;
        }
        else if (res[0] == '+') {
            i = 1;
        }

        // Process integer part
        for (; i < len && res[i] >= '0' && res[i] <= '9'; i++) {
            result = result * 10.0f + (res[i] - '0');
        }

        // Process decimal part
        if (i < len && res[i] == '.') {
            float factor = 0.1f;
            i++;

            for (; i < len && res[i] >= '0' && res[i] <= '9'; i++) {
                fraction += (res[i] - '0') * factor;
                factor *= 0.1f;
            }
        }

        return (result + fraction) * sign;
    }

    // Stream operators
    friend ostream& operator<<(ostream& out, const String& str);
    friend istream& operator>>(istream& in, String& str);

private:
    char* res;          // Pointer to character array
    unsigned int len;   // Length of the string (excluding null terminator)
};

// Output stream operator
ostream& operator<<(ostream& out, const String& str) {
    if (str.res) {
        out << str.res;
    }
    return out;
}

// Input stream operator
istream& operator>>(istream& in, String& str) {
    char buffer[1024]; // Temporary buffer for input
    in >> buffer;

    delete[] str.res;
    str.len = static_cast<unsigned int>(String::my_strlen(buffer));
    str.res = new char[str.len + 1];
    String::my_strcpy_s(str.res, str.len + 1, buffer);

    return in;
}

int main() {
    // Test our custom string functions and new functionality
    cout << "Testing String class with additional functions:" << endl << endl;

    // Test trim()
    String str1 = "  Hello, world!  ";
    cout << "Original string: \"" << str1 << "\"" << endl;
    cout << "After trim(): \"" << str1.trim() << "\"" << endl << endl;

    // Test toLower() and toUpper()
    String str2 = "Hello, World!";
    cout << "Original string: \"" << str2 << "\"" << endl;
    cout << "toLower(): \"" << str2.toLower() << "\"" << endl;
    cout << "toUpper(): \"" << str2.toUpper() << "\"" << endl << endl;

    // Test replace()
    String str3 = "Hello, world! Hello, universe!";
    cout << "Original string: \"" << str3 << "\"" << endl;
    cout << "replace(\"Hello\", \"Hi\"): \"" << str3.replace("Hello", "Hi") << "\"" << endl << endl;

    // Test split() and join()
    String str4 = "apple,banana,cherry,date";
    cout << "Original string: \"" << str4 << "\"" << endl;

    std::vector<String> fruits = str4.split(",");
    cout << "After split(\",\"):" << endl;
    for (size_t i = 0; i < fruits.size(); i++) {
        cout << "  [" << i << "]: \"" << fruits[i] << "\"" << endl;
    }

    String joined = String::join(fruits, " - ");
    cout << "join with \" - \": \"" << joined << "\"" << endl << endl;

    // Test startsWith() and endsWith()
    String str5 = "Hello, world!";
    cout << "String: \"" << str5 << "\"" << endl;
    cout << "startsWith(\"Hello\"): " << (str5.startsWith("Hello") ? "true" : "false") << endl;
    cout << "startsWith(\"Hi\"): " << (str5.startsWith("Hi") ? "true" : "false") << endl;
    cout << "endsWith(\"world!\"): " << (str5.endsWith("world!") ? "true" : "false") << endl;
    cout << "endsWith(\"planet!\"): " << (str5.endsWith("planet!") ? "true" : "false") << endl << endl;

    // Test parseInt() and parseFloat()
    String str6 = "123";
    String str7 = "-45.67";
    cout << "parseInt(\"" << str6 << "\"): " << str6.parseInt() << endl;
    cout << "parseFloat(\"" << str7 << "\"): " << str7.parseFloat() << endl << endl;

    // Test isEmpty() and clear()
    String str8 = "Not empty";
    cout << "String: \"" << str8 << "\"" << endl;
    cout << "isEmpty(): " << (str8.isEmpty() ? "true" : "false") << endl;
    str8.clear();
    cout << "After clear(), isEmpty(): " << (str8.isEmpty() ? "true" : "false") << endl;

    return 0;
}


///output ::
//Testing String class with additional functions :
//
//Original string : "  Hello, world!  "
//After trim() : "Hello, world!"
//
//Original string : "Hello, World!"
//toLower() : "hello, world!"
//toUpper() : "HELLO, WORLD!"
//
//Original string : "Hello, world! Hello, universe!"
//replace("Hello", "Hi") : "Hi, world! Hi, universe!"
//
//Original string : "apple,banana,cherry,date"
//After split(",") :
//    [0] : "apple"
//    [1] : "banana"
//    [2] : "cherry"
//    [3] : "date"
//    join with " - " : "apple - banana - cherry - date"
//
//    String : "Hello, world!"
//    startsWith("Hello") : true
//    startsWith("Hi") : false
//    endsWith("world!") : true
//    endsWith("planet!") : false
//
//    parseInt("123") : 123
//    parseFloat("-45.67") : -45.67
//
//    String : "Not empty"
//    isEmpty() : false
//    After clear(), isEmpty() : true

