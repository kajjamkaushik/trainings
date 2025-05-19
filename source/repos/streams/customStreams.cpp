//#include <iostream>
//#include <fstream>
//#include <streambuf>
//
//// Custom stream buffer to redirect output to console and file
//class CustomBuffer : public std::streambuf {
//private:
//    std::ostream& console;   // Reference to standard output (cout)
//    std::ofstream file;      // File stream for logging
//
//public:
//    // Constructor: Initialize console output and open the log file
//    CustomBuffer(std::ostream& c, const std::string& filename)
//        : console(c), file(filename, std::ios::app) {
//        if (!file.is_open()) {
//            throw std::runtime_error("Failed to open log file.");
//        }
//    }
//
//    // Override the overflow function to handle character output
//    int overflow(int c) override {
//        if (c == EOF) return EOF;
//
//        // Write character to the console
//        console.put(static_cast<char>(c));
//
//        // Write character to the file
//        file.put(static_cast<char>(c));
//
//        // Flush the output so it's immediately written
//        console.flush();
//        file.flush();
//
//        return c;
//    }
//};
//
//// Custom output stream class using CustomBuffer
//class CustomStream : public std::ostream {
//private:
//    CustomBuffer buffer;  // Custom buffer for redirection
//
//public:
//    CustomStream(std::ostream& c, const std::string& filename)
//        : std::ostream(&buffer), buffer(c, filename) {}
//};
//
//int main() {
//    try {
//        // Create a custom stream that logs to both console and file
//        CustomStream logStream(std::cout, "log.txt");
//
//        // Redirect standard output (cout) to custom stream
//        std::ostream& out = logStream;
//
//        // Writing to custom stream
//        out << "This is a custom stream example!" << std::endl;
//        out << "Logging this message to both console and file." << std::endl;
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
