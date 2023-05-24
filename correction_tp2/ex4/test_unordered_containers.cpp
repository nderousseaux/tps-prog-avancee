#include "test_unordered_containers.h"

#include <string>
#include <unordered_set>
#include <iostream>

void insertInSetAndCheck(std::unordered_set<std::string>&   set,
                         const std::string&                 value)
{
    auto ret = set.insert(value);
    if( !ret.second )
    {
        std::cerr << "Element \"" << value << "\" already existed in the set" << std::endl;
    }
}

void testUnorderedSet()
{
    // declare an unordered set of strings
    std::unordered_set< std::string > mySet;

    // insert five elements using 'insert' and ignore the return value
	mySet.insert("Hello");
    mySet.insert("world");
    mySet.insert("!");
    mySet.insert("Hello");
    mySet.insert("!!");

    // print the elements inside the set
    for (auto e : mySet )
    {
        std::cout << e << " / ";
    }
	std::cout << std::endl;

    // insert five elements using our custom function
    insertInSetAndCheck(mySet, "My");
    insertInSetAndCheck(mySet, "name");
    insertInSetAndCheck(mySet, "is");
    insertInSetAndCheck(mySet, "Bryan");
    insertInSetAndCheck(mySet, "Bryan");

    // print the elements inside the set
    for (auto e : mySet )
    {
        std::cout << e << " / ";
    }
	std::cout << std::endl;
}

void testUnorderedSetHashMap()
{
    // std::unordered_set< StringFloatPair > mySet; // Not possible since StringFloatPair has no associated hash function
    std::unordered_set< StringFloatPair, StringFloatPairHash > mySet;

	mySet.insert(StringFloatPair{ "One",1.0f });
	mySet.insert(std::make_pair("Two",2.0f));
	mySet.insert(StringFloatPair{ "Two",2.0f });
	mySet.emplace("One",3.0f );
	mySet.insert(StringFloatPair{ "Three",3.0f });

	for (auto e : mySet )
    {
        std::cout << "(" << e.first << ", " << e.second << ") / ";
    }
	std::cout << std::endl;
}