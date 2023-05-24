#include "university.h"

#include <iostream>

int main()
{
    std::cout << "-- Instanciating objects" << std::endl;

    // Use of default constructor
    University u0;

    // These initializations invoke alternate constructor
    University  u1{ "University of Strasbourg", 2 };
    University* u2 = new University("University of Saint-Petersbourg", 4);
    University  u3{ "University of Paris", 8 };

    // These initializations implicitly invoke copy constructor
    University  u4{ u1 };
    University  u5{ *u2 };
    University  u6 = u3;

    // But not this one (it is only an pointer affectation : u7 points to the same element as u2)
    University* u7 = u2;

    // Use the print method
    std::cout << "-- Print after instanciations" << std::endl;
    u0.print();
    u1.print();
    u2->print();
    u3.print();
    u4.print();
    u5.print();
    u6.print();
    u7->print();
    std::cout << "--" << std::endl;

    // Modify the objects u4 and u5
    u2->setName("Aix-Marseille University");
    u4.setName("University of Nancy");
    u5.setName("University of Moskou");

    // Use the print method after modifications
    std::cout << "-- Print after modifications" << std::endl;
    u2->print();
    u4.print();
    u5.print();
    u7->print();
    std::cout << "--" << std::endl;

    // Use the output stream operator
    std::cout << "-- Print using output stream operator" << std::endl;
    std::cout << u1 << std::endl;
    std::cout << *u2 << std::endl;
    std::cout << "--" << std::endl;

    // Manage memory to avoid memory leaks: everything that has been created with 'new' must be deleted
    delete u2;   // destructor will be called before delete()
                 // destructor for u1 will be called before
    // No need to delete u7 because the object has already been destructed when delete u2 was called
    // writing "delete u7;" here would cose a segmentation fault "double free" error

    return 0;
}