#include <list>
#include <iostream>


void testList()
{
	// Declare a `std::list` of integers
	std::list<int> l;

	// Insert three integers at the end of the list: 0, 1, 2
	l.push_back(0);
	// On récupère l'itérateur de la liste
	std::list<int>::iterator it_first_elem = l.begin();

	l.push_back(1);
	l.push_back(2);

 	// Print the list using an iterator for loop with `std::list<int>::const_iterator`
	//   > Note:
	//   >
	//   > using a `std::list<int>::const_iterator` you are not able to modify the objects of the list.
	//   > If you were to do so, you would use `std::list<int>::iterator` iterators instead

	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
		std::cout << *it << std::endl;

	// use an iterator for loop combined with the `auto` keyword to have a reference on the list's elements
  // increment the integers in the list
	for (auto it = l.begin(); it != l.end(); ++it)
		*it += 1;

	// print them (should now print: 1, 2, 3)
	for (auto it = l.begin(); it != l.end(); ++it)
		std::cout << *it << std::endl;

	// insert three integers at the begining of the list: 4, 5, 6
	l.push_front(4);
	l.push_front(5);
	l.push_front(6);

	// print the list using a ranged-based for loop (should now print 6, 5, 4, 1, 2, 3)
	for (auto it : l)
		std::cout << it << std::endl;

	// insert three times the integer "10" **after** the first element added (after the element "1" in the list)
	//   > **Note:**
	//   >
	//   > - the `insert` method of `std::list` requires the position where new elements will be inserted.
	//   > - the `insert` method of `std::list` inserts an element **before** the given position.
	//   - keep track of the first element inserted with an iterator before passing it to the `insert` method

	it_first_elem++;
	for(int i = 0; i<3; i++) l.insert(it_first_elem, 10);

	// print the list using a for loop with `std::list<int>::const_reverse_iterator` (should now print 3, 2, 10, 10, 10, 1, 4, 5, 6)
	for (std::list<int>::const_reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		std::cout << *it << std::endl;
}