#pragma once
#include <iostream>

class Address; // Forward declaration

class Person
{
public:
    std::string name;
    Address* address;

    void printInfo();
};
