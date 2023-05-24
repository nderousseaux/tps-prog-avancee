#include "person.h"
#include "student.h"
#include "studentmanager.h"

#include <iostream>

int main(int argc, char** argv)
{
    StudentManager& studManager = StudentManager::getUniqueManager();

    std::cout << "-- Instanciating a student" << std::endl;
    Student* s1 = new Student{ "tutu",  "tyty", Person::Status::Mr, 10.0f, "algebre", 1 };

    std::cout << "-- Print the student" << std::endl;
    s1->print();

    std::cout << "-- Modify the student's mean score thanks to the student manager" << std::endl;
    studManager.updateStudentMeanScore(s1, 20.0f);

    std::cout << "-- Print the modified student" << std::endl;
    s1->print();

    return 0;
}