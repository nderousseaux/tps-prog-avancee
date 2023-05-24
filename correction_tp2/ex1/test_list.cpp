#include <list>
#include <iostream>

void testList()
{
	std::list<int> myList;

    // Add three elements at the end of the list
	myList.push_back(0);
	auto prem = myList.begin(); // Keep track of this element using an iterator
	myList.push_back(1);
	myList.push_back(2);

    // Print the list using std::list<int>::const_iterator
    for( std::list<int>::const_iterator it = myList.begin(); it != myList.end(); ++it )
    {
		std::cout << *it << " / ";
    }
	std::cout << std::endl;

    // Iterator for loop using the auto keyword
    for( auto it = myList.begin(); it != myList.end(); ++it )
    {
        // Increment the element and print it
        (*it)++;
        std::cout << *it << " / ";
    }
    std::cout << std::endl;

    // Add three elements at the begining of the list
	myList.push_front(4);
	myList.push_front(5);
	myList.push_front(6);

    // Print the list using a ranged-based for loop
	for(auto e: myList )
    {
		std::cout << e << " / ";
    }
	std::cout << std::endl;

    // Insert three times the element "10"
	myList.insert(++prem, 3, 10); // ++ car insert insert avant

    for(auto e: myList )
    {
		std::cout << e << " / ";
    }
	std::cout << std::endl;

    // Print the list using a reverse iterator
	for (std::list<int>::const_reverse_iterator it = myList.rbegin(); it != myList.rend(); ++it)
    {
		std::cout << *it << " / ";
    }
	std::cout << std::endl;
}