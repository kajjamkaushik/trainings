#include "person.h"
#include <iostream>
#include "address.h"

void Person::printInfo()
{
    std::cout << "Name: " << name << std::endl;
    if (address)
    {
        address->printAddress();
    }
}
