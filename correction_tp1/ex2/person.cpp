#include "person.h"

#include <iostream>

const std::array<std::string, 5> Person::status_str_{ "Mr","Ms","Dr", "Other" };

Person::Person(const std::string& firstName,
               const std::string& lastName,
               Status             status) :
    firstName_{ firstName },
    lastName_{ lastName },
    status_{ status }
{
   // dynamically allocate memory for any pointer data members here
}

// copy constructor
Person::Person(const Person& other) :
    firstName_(other.firstName_),
    lastName_(other.lastName_),
    status_(other.status_)
{
   // deep copy any pointer data members here
}

/* We don't need to write the destructor ourselves and can use the default desctructor, since we have no heap memory to release,
   but we just add it for providing the final message
*/
Person::~Person()
{
    std::cout << "Person destructor " << firstName_ << " " << lastName_ << std::endl;
   // release memory for any dynamically allocated data members if you have them
}