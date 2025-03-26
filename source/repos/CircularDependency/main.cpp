#include "person.h"
#include "address.h"
#include <iostream>

int main()
{
    Address address = { "22 Baker Street", "London" };
    Person person = { "John Doe", &address };

    address.person = &person;

    person.printInfo();

    return 0;
}

///op:
//Name: John Doe
//Street : 22 Baker Street
//City : London
//Name : John Doe
