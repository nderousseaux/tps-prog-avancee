#include "test_vector.h"

#include <iostream>
#include <algorithm>

bool fcomp(const StringFloatPair& p, const StringFloatPair& q)
{
	return p.second < q.second; 
}

void testVector()
{
    // instanciate two pairs using the constructor
	StringFloatPair p1{ "one", 1.0f };
    StringFloatPair p2{ "two", 2.0f };

    // instanciate two pairs using 'std::make_pair'
    StringFloatPair p3 = std::make_pair("threeFromDouble", 3.0);       // Note: implicit conversion from std::pair<std::string,double>
    StringFloatPair p4 = std::make_pair("threeFromInt",    3);           // Note: implicit conversion from std::pair<std::string,int>

    // instanciate two additional pairs with 'wrong' type
    auto            wrongPair3 = std::make_pair("threeFromDouble", 3.0); // Note: returns a std::pair<std::string,double>
    auto            wrongPair4 = std::make_pair("threeFromInt",    3);   // Note: returns a std::pair<std::string,int>

    // Print the types of content
    std::cout << "p1:         " << typeid(p1.second).name() << std::endl;
    std::cout << "wrongPair3: " << typeid(wrongPair3.second).name() << std::endl;
    std::cout << "wrongPair4: " << typeid(wrongPair4.second).name() << std::endl;

    // declare a vector of StringFloatPair
	StringFloatVector vec;

    // reserve the memory storage for 8 pairs
	vec.reserve(8);

    // Print the size and content of the vector to see the effect of reserve
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;
    std::cout << "Vector content:" << std::endl;
    for( const auto& e : vec )
    {
        std::cout << "(" << e.first << ", " << e.second << ") / ";
    }
    std::cout << std::endl;

    // resize actually instanciate elements (calling default constructor) in the vector
	vec.resize(2);
    
    // Print the size and content of the vector to see the effect of resize
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;
    std::cout << "Vector content:" << std::endl;
    for( const auto& e : vec )
    {
        std::cout << "(" << e.first << ", " << e.second << ") / ";
    }
    std::cout << std::endl;

    // Add three elements using 'push_back'
    vec.push_back(StringFloatPair{"zero", 0.0f});
    vec.push_back(p1);
    vec.push_back(p2);
	
    // Add three elements using 'emplace_back'
    vec.emplace_back(StringFloatPair{"zero", 0.0f});
    vec.emplace_back(p1);
    vec.emplace_back(p2);

    // Print content of the vector with an index-based for loop
    for( size_t i = 0 ; i < vec.size() ; ++i )
    {
        std::cout << "(" << vec[i].first << ", " << vec[i].second << ") / ";
    }
    std::cout << std::endl;

    // Print content of the vector with an iterator-based for loop
    for( StringFloatVector::iterator it = vec.begin() ; it != vec.end() ; ++it )
    {
        std::cout << "(" << it->first << ", " << it->second << ") / ";
    }
    std::cout << std::endl;

    // Print content of the vector with an range-based for loop
    for( const auto & e : vec )
    {
        std::cout << "(" << e.first << ", " << e.second << ") / ";
    }
    std::cout << std::endl;

    // Print content of the vector with an iterator-based for loop
    for( auto it = vec.rbegin() ; it != vec.rend() ; ++it )
    {
        std::cout << "(" << it->first << ", " << it->second << ") / ";
    }
    std::cout << std::endl;

    // Sort the vector according to the floatting values using a defined function
    std::sort(vec.begin(), vec.end(), fcomp);
    
    // Print the result
    for( const auto & e : vec )
    {
        std::cout << "(" << e.first << ", " << e.second << ") / ";
    }
    std::cout << std::endl;

    // Sort the vector in decreasing order with a lambda comparison function
    std::sort(vec.begin(), vec.end(), [](const StringFloatPair& p, const StringFloatPair& q) { return p.second > q.second; });
	
    // Print the result
    for( const auto & e : vec )
    {
        std::cout << "(" << e.first << ", " << e.second << ") / ";
    }
    std::cout << std::endl;

    // Find the first pair in the range [1.8, 2.2]
	auto itf = std::find_if(vec.begin(), vec.end(), [](const StringFloatPair& p) { return std::abs(p.second - 2.0f) < 0.2f; });
    if( itf == vec.end() )
    {
        std::cout << "Not found" << std::endl;
    }
    else
    {
	    std::cout << "Found " << itf->first << " " << itf->second << std::endl;
    }

	// Store the begin iterator
	auto begIt = vec.begin();

    // Add 4 additional pairs
	vec.push_back(p2); // Insertion in a already full vector (more than the reserved size)

	std::cout << begIt->first << " " << begIt->second << std::endl; // => Seg Fault !
    // begIt is invalid because vec has been reallocated
}