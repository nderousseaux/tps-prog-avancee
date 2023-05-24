#include "test_unordered_containers.h"

#include <iostream>

int main(int argc, char** argv)
{
    // Students : nothing to do here
    std::cout << "----- Unorder set -----" << std::endl;
    testUnorderedSet();

    std::cout << "----- Unorder set with hashmap -----" << std::endl;
    testUnorderedSetHashMap();
    
    return 0;
}