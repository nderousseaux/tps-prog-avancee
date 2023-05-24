#include "test_unordered_containers.h"

#include <string>
#include <unordered_set>
#include <iostream>

// Students : implements aditionnal functions here

//   - create a function `void insertInSetAndCheck(std::unordered_set<std::string>& set, const std::string& value)` that inserts the element `value` in the set `set` and print a message on the standard error whenever an insertion failed because the element already existed in the set        
//     - get the return value of the `insert` method using the `auto` keyword
void insertInSetAndCheck(std::unordered_set<std::string>& set, const std::string& value)
{
    auto ret = set.insert(value);
    if (!ret.second)
        std::cerr << "Insertion failed for value " << value << std::endl;
}

void testUnorderedSet()
{
    // - declare a `std::unordered_set` of `std::string`
    std::unordered_set<std::string> s;

    // - insert five elements in the set using `insert`, ignore the return value of the insertion:
    //   1. "Hello"
    //   2. "world"
    //   3. "!"
    //   4. "Hello"
    //   5. "!!"
    s.insert("Hello");
    s.insert("world");
    s.insert("!");
    s.insert("Hello");
    s.insert("!!");

    
    // - print the elements in the set
    //   > **Note:** a set cannot contain duplicated elements!
    for (auto it = s.begin(); it != s.end(); ++it)
        std::cout << *it << std::endl;

    // - now consider the return value of `insert`:

    //   - create a function `void insertInSetAndCheck(std::unordered_set<std::string>& set, const std::string& value)` that inserts the element `value` in the set `set` and print a message on the standard error whenever an insertion failed because the element already existed in the set        
    //     - get the return value of the `insert` method using the `auto` keyword
    //   - insert five additional elements in the set using your custom function
    //     1. "My"
    //     2. "name"
    //     3. "is"
    //     4. "Bryan"
    //     5. "Bryan"
    insertInSetAndCheck(s, "My");
    insertInSetAndCheck(s, "name");
    insertInSetAndCheck(s, "is");
    insertInSetAndCheck(s, "Bryan");
    insertInSetAndCheck(s, "Bryan");

    // - print the elements in the set
    for (auto it = s.begin(); it != s.end(); ++it)
        std::cout << *it << std::endl;
}

void testUnorderedSetHashMap()
{
    // The unordered containers require a hash function.

    // - try to instanciate an unordered set of pair (`std::string` and `float`) similar to exercice 2.
    //   - **Q:** you encounter a problem, which one ?

    // We don't want to define a custom hash function for our pairs, instead we will simply use the system-provided hash function for `std::string` and use it as the hash function for our pairs.

    // - define a `struct` with:
    //   - a single attribute:
    //     1. a `std::hash<std::string>` (a `struct` which `operator()` provides a system-provided hash function for `std::string`) named `hs_`
    //   - a single inline method:
    //     1. the constant `operator()` which takes one pair (`std::string` and `float`) in parameter and returns the result of the hash function of the `string` element of the pair
    // - declare an unordered set of pair (`std::string` and `float`) providing your custom hash structure
    // - insert elements in this set
    // - print the elements of this set

}