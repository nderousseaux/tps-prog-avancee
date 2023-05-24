#include "person.h"
#include "student.h"

#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "-- Instanciating students and persons" << std::endl;
    Person* p1 = new Person{ "toto",   "titi", Person::Status::Dr };
    Person* p2 = new Person{ "tata",   "tete", Person::Status::Ms };
    Student* s1 = new Student{ "tutu",  "tyty", Person::Status::Mr, 10.0f, "algebre",      1 };
    Student* s2 = new Student{ "pouet", "puit", Person::Status::Dr, 11.0f, "biochemistry", 2 };

    std::array<Person*, 4> myArray{ p1, p2, s1, s2 };
    std::cout << "-- Print all objects in array of Person pointers" << std::endl;
    for( auto p : myArray )
    {
        p->print();
    }

    std::cout << "-- Free memory using virtual destructors" << std::endl;
    for( auto p : myArray )
    {
        delete p;
    }

    return 0;
}