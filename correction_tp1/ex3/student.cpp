#include "student.h"

#include <iostream>
#include <iomanip>

// definition for static data member (which is implemented as external variable)
int Student::numStudents_{ 0 };  // note:  initial value of 0

// Default constructor 
Student::Student() :
    studentId_(numStudents_ + 100)
{
/* Recall that member objects (strings) will be default constructed, so no additional init is necessary (if an empty std::string is our goal)
   Note: since studentId is const, we need to set it at construction.
   Remember, std::string member currentCourse will be default constructed with an empty std::string - it is a member object
   Remember to dynamically allocate memory for any pointer data members here (not needed in this example)
*/
    numStudents_++; // as it is a new student, we have to increment the total number of students
}

/* Alternate constructor
   Notice that the member initialization list is used to select which constructor should be utilized to initialize the Person
   sub-object as well as to pass arguments up to this constructor
*/
Student::Student(const std::string& firstName,
                 const std::string& lastName,
                 Status             status,
                 float              meanScore,
                 const std::string& course,
                 int64_t            id) :
    Person{ firstName, lastName, status },
    meanScore_{ meanScore },
    currentCourse_{ course },
    studentId_{ id }
{
   // Remember to dynamically allocate memory for any pointer data members here (not needed in this example)
    numStudents_++; // as it is a new student, we have to increment the total number of students
}

/* Copy constructor
   Notice that the member initialization list is used to specify
   that the Person copy constructor should be utilized to copy the
   Person sub-object.  Without this secification, the default constructor
   for Person would be invoked (which would be incorrect since part of
   the copied Student object would be Nulled out).  Notice that
   the input parameter "s" is implicitly cast to a Person &
*/
Student::Student(const Student& other) :
    Person(other),
    meanScore_{ other.meanScore_ },
    currentCourse_{ other.currentCourse_ },
    studentId_{ other.studentId_ }
{
   // deep copy any pointer data members of derived class here
    numStudents_++;  // as it is a new student, we have to increment the total number of students
}

// destructor definition
Student::~Student()
{
   // release memory for any dynamically allocated data members
    std::cout << "Student destructor " << getFirstName() << std::endl;

    // Update the number of students
    numStudents_--;
}

void Student::print() const
{
    // Private members of Person are not directly accessible within
    // the scope of Student, hence access functions are utilized
    // to print these members
    Person::print();
    std::cout << "  with id: " << studentId_
        << " and  middleScore: "
        << std::setprecision(3) << meanScore_
        << " in  course: " << currentCourse_
        << std::endl;
}

void Student::earnPhD()
{
   // Protected members defined by the base class are accessible within
   // the scope of the derived class.  EarnPhd() provides a public
   // interface to this functionality for derived class instances. 
    setStatus(Status::Dr);
}