#include "university.h"

#include <iostream>

// --------------------------------------------------------------------
// Constructors and destructor
// --------------------------------------------------------------------
// default constructor
University::University()
{
    std::cout << "Default constructor" << std::endl;
}

// alternate constructor
University::University(const std::string& uniName, unsigned int nStudents) :
    name_{ uniName },
    numStudents_{ nStudents }
{
    std::cout << "Alternate constructor " << name_ << std::endl;
}

// copy constructor
University::University(const University& other) :
    name_{ other.name_ },
    numStudents_{ other.numStudents_ }
{
    std::cout << "Copy constructor " << name_ << std::endl;
}

// destructor
University::~University()
{
    std::cout << "Destructor called " << name_ << std::endl;
}

// --------------------------------------------------------------------
// Getters and setters
// --------------------------------------------------------------------
void University::setName(const std::string& name)
{
    name_ = name;
}

// --------------------------------------------------------------------
// Tools
// --------------------------------------------------------------------
void University::print()
{
    std::cout << "University: " << name_ << std::endl;
    std::cout << "  with " << numStudents_ << " students" << std::endl;
}

// --------------------------------------------------------------------
// Friend functions
// --------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const University& u)
{
    os << u.name_ << " " << u.numStudents_;
    return os;
}