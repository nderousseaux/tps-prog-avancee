#include "test_map.h"

#include <iostream>

int main(int argc, char** argv)
{
    std::cout <<"----- Map -----" << std::endl;
    testMap();

    std::cout <<"----- Multimap -----" << std::endl;
    testMultimap();
    
    return 0;
}