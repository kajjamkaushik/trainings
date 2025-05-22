#include <sstream>
#include <string>
#include"string_calculator.h"

int add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::stringstream ss(numbers);
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        sum += std::stoi(token);
    }

    return sum;
}