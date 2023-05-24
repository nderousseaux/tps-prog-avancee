#include "student.h"

#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "-- Instanciating students" << std::endl;

    Student s1("Tom",
               "Sawyer",
               Person::Status::Mr,
               20,
               "C++",
               2019012578);

    Student s2("Huckleberry",
               "Finn",
               Person::Status::Mr,
               20,
               "C++",
               2019012579);

    std::cout << "-- Printing students" << std::endl;
    s1.print();
    s2.print();

    std::cout << "-- Modify student 1" << std::endl;
    s1.setCurrentCourse("Doctoral Thesis");
    s1.earnPhD();

    std::cout << "-- Print student 1" << std::endl;
    s1.print();

    std::cout << "Total number of students: " << Student::getNumberStudents() << std::endl;

    return 0;
}