#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <array>

class Person
{
public:
    enum class Status : int
    {
        Mr = 0,
        Ms,
        Dr,
        Other
    };

// --------------------------------------------------------------------
// Protected static members
// --------------------------------------------------------------------
protected:
    static const std::array<std::string, 5> status_str_;

// --------------------------------------------------------------------
// Private data members
// --------------------------------------------------------------------
private:
    std::string firstName_{ "" };          // first name of parson
    std::string lastName_{ "" };           // last name
    Status      status_{ Status::Other };  // Mr., Ms., Mrs., Miss, Dr., etc.

 // --------------------------------------------------------------------
 // Constructors and destructor
 // --------------------------------------------------------------------
public:
    Person() = default;                  // default constructor :
                                         // "= default" means "use the compiler generated default constructor",
                                         // no need to implement the body of this constructor

    Person(const std::string& firstName,
           const std::string& lastName,
           Status             status);   // alternate constructor

    Person(const Person& other);         // copy constructor

    ~Person();                           // destructor; 

 // --------------------------------------------------------------------
 // Getters and setters
 // --------------------------------------------------------------------
public:
    inline const std::string& getFirstName() const
    {
        return firstName_;
    }

    inline const std::string& getLastName() const
    {
        return lastName_;
    }

    inline Status getStatus() const
    {
        return status_;
    }

protected: //  make the following methods available to derived classes
    inline void setStatus(Status status)
    {
        status_ = status;
    }
};

#endif // PERSON_H