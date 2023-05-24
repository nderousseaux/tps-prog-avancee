#include "test_map.h"

#include <iostream>

void testMap()
{
    // - declare a `std::map` with an integer as key and the previously defined pairs as data
    std::map<int, std::pair<std::string, float>> m;

    // - insert three elements in your map using the `insert` method:
    // 1. key: `7`, data: (`"One", 1.0f`)
    // 2. key: `5`, data: (`"Two", 2.0f`)
    // 3. key: `5`, data: (`"Five", 5.0f`)
    m.insert(std::make_pair(7, std::make_pair("One", 1.0f)));
    m.insert(std::make_pair(5, std::make_pair("Two", 2.0f)));
    m.insert(std::make_pair(5, std::make_pair("Five", 5.0f)));

    // - print the elements of the map
    for (auto it = m.begin(); it != m.end(); ++it)
        std::cout << it->first << " " << it->second.first << " " << it->second.second << std::endl;

    // - insert three elements in your map using the `operator[]`:
    // 1. key: `3`, data: (`"Three", 1.0f`)
    // 2. key: `2`, data: (`"Seven", 7.0f`)
    // 3. key: `2`, data: (`"Nine", 9.0f`)
    m[3] = std::make_pair("Three", 3.0f);
    m[2] = std::make_pair("Seven", 7.0f);
    m[2] = std::make_pair("Nine", 9.0f);

    // - print the elements of the map
    for (auto it = m.begin(); it != m.end(); ++it)
        std::cout << it->first << " " << it->second.first << " " << it->second.second << std::endl;
}

void testMultimap()
{
    // - declare a `std::multimap` with an integer as key and the previously defined pairs as data
    std::multimap<int, std::pair<std::string, float>> m;

    // - insert three elements in your map using the `insert` method:
    // 1. key: `7`, data: (`"One", 1.0f`)
    // 2. key: `5`, data: (`"Two", 2.0f`)
    // 3. key: `5`, data: (`"Five", 5.0f`)
    m.insert(std::make_pair(7, std::make_pair("One", 1.0f)));
    m.insert(std::make_pair(5, std::make_pair("Two", 2.0f)));
    m.insert(std::make_pair(5, std::make_pair("Five", 5.0f)));

    // - print the elements of the map
    for (auto it = m.begin(); it != m.end(); ++it)
        std::cout << it->first << " " << it->second.first << " " << it->second.second << std::endl;
}