#include <iostream>
#include "person.h"
#include "address.h"

void Address::printAddress()
{
    std::cout << "Street: " << street << std::endl;
    std::cout << "City: " << city << std::endl;

    if (person)
    {
        std::cout << "Name: " << person->name << std::endl;
    }
}
