#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

/*
   Student is derived from Person using public inheritance.
   Private inheritance is the default for classes (public is the default for inherited structures).
*/
class Student : public Person
{
// --------------------------------------------------------------------
// Private static members
// --------------------------------------------------------------------
private:
    static int numStudents_; // static data member is initialized outside of class (see below)

 // --------------------------------------------------------------------
 // Private data members
 // --------------------------------------------------------------------
private:
    float            meanScore_{ 0.0f };   // mean score of the student
    const int64_t    studentId_;         // studentId is not modifiable thanks to the const keyword
    std::string      currentCourse_{ "" }; // the current course of the student

 // --------------------------------------------------------------------
 // Constructors and destructor
 // --------------------------------------------------------------------
public:
    Student();                              // default constructor

    Student(const std::string& firstName,
            const std::string& lastName,
            Status              status,
            float               meanScore,
            const std::string& course,
            int64_t             id);        // alternate constructor

    Student(const Student& other);          // copy constructor

    ~Student();                             // destructor

// --------------------------------------------------------------------
// Getters and setters
// --------------------------------------------------------------------
public:
    inline float getScore() const
    {
        return meanScore_;
    }

    inline const std::string& getCurrentCourse() const
    {
        return currentCourse_;
    }

    inline int64_t getStudentId() const
    {
        return studentId_;
    }

    inline void setCurrentCourse(const std::string& c)
    {
        currentCourse_ = c;
    };

    inline static int getNumberStudents()
    {
        return numStudents_;
    };

// --------------------------------------------------------------------
// Tools
// --------------------------------------------------------------------
public:
    void print() const;

    void earnPhD();     // public interface to inherited protected member
};

#endif // STUDENT_H