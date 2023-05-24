#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>

class University
{
// --------------------------------------------------------------------
// Class friendships
// --------------------------------------------------------------------
    friend std::ostream& operator<<(std::ostream& os, const University& u);

// --------------------------------------------------------------------
// Private data members
// --------------------------------------------------------------------
private:
    std::string  name_{ "unknown" };
    unsigned int numStudents_{ 0 };

// --------------------------------------------------------------------
// Constructors and destructor
// --------------------------------------------------------------------
public:
    University();                               // default constructor

    University(const std::string& uniName,
               unsigned  int      nStudents);   // alternate constructor

    University(const University& other);       // copy constructor

    ~University();                              // destructor prototype

// --------------------------------------------------------------------
// Getters and setters
// --------------------------------------------------------------------
public:
    void setName(const std::string& name);

// --------------------------------------------------------------------
// Tools
// --------------------------------------------------------------------
public:
    void print();
};

#endif // UNIVERSITY_H