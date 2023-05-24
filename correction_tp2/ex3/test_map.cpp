#include "test_map.h"

#include <iostream>

void testMap()
{
    // declare a 
	MapCustomPair myMap;

    // insert three elements using 'insert'
	myMap.insert(std::make_pair(7, StringFloatPair{ "One",1.0f }));
	myMap.insert(std::make_pair(5, StringFloatPair{ "Two",2.0f }));
	myMap.insert(std::make_pair(5, StringFloatPair{ "Twelve",12.0f }));

    // print the elements of the map
	for( auto e : myMap )
    {
        int              eKey  = e.first;
        StringFloatPair& eData = e.second;
		std::cout << "Key: " << eKey << " - Data: (" << eData.first << ", " << eData.second << ") / ";
    }
	std::cout << std::endl;

    // insert three elements using 'operator[]'
	myMap[3] = StringFloatPair{ "Three",3.0f };
	myMap[2] = StringFloatPair{ "seven",7.0f };
	myMap[2] = StringFloatPair{ "nine",9.0f };

    // print the elements of the map
	for( auto e : myMap )
    {
        int              eKey  = e.first;
        StringFloatPair& eData = e.second;
		std::cout << "Key: " << eKey << " - Data: (" << eData.first << ", " << eData.second << ") / ";
    }
	std::cout << std::endl;
}

void testMultimap()
{
    std::multimap<int, StringFloatPair>  myMultimap;

    // Insert six elements in the multimap
	myMultimap.insert(std::make_pair(7, StringFloatPair{ "One",1.0f }));
	myMultimap.insert(std::make_pair(5, StringFloatPair{ "Two",2.0f }));
	myMultimap.insert(std::make_pair(5, StringFloatPair{ "Twelve",12.0f }));
    myMultimap.insert(std::make_pair(3, StringFloatPair{ "Three",3.0f }));
    myMultimap.insert(std::make_pair(2, StringFloatPair{ "seven",7.0f }));
    myMultimap.insert(std::make_pair(2, StringFloatPair{ "nine",9.0f }));

    // Print the elements in the multimap
	for (auto e : myMultimap)
    {
		int              eKey  = e.first;
        StringFloatPair& eData = e.second;
		std::cout << "Key: " << eKey << " - Data: (" << eData.first << ", " << eData.second << ") / ";
    }
	std::cout << std::endl;
}