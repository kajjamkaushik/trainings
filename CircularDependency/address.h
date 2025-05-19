#pragma once
#include <iostream>

class Person; // Forward declaration

class Address
{
public:
    std::string street;
    std::string city;
    Person* person; // Corrected variable name

    void printAddress(); // Declare the function
};
