#include "test_vector.h"

#include <iostream>
#include <algorithm>

// Students : add implementations here
bool isSuperiorTo(const std::pair<std::string, float>& p1, const std::pair<std::string, float>& p2)
{
    return p1.second > p2.second;
}

void testVector()
{
    // > **Reminder:**
    // >
    // > the `using` keyword allows you to declare aliases and simplify code writing and readability

    // - use the `using` keyword to create an alias for a pair of (`std::string` and `float`)
    using pair_string_float = std::pair<std::string, float>;

    // - use the `using` keyword to create an alias for a vector of pair of (`std::string` and `float`)
    using vector_pair_string_float = std::vector<pair_string_float>;

    // - instanciate two pairs p1 and p2 using the pair constructor
    pair_string_float p1("one", 1.0);

    // - instanciate two pairs p3 and p4 using `std::make_pair`
    pair_string_float p2 = std::make_pair("one", 1.0);

    // - create two pairs p5 and p6 with the `auto` keyword as type with values (`"two", 2.0`) and (`"two", 2`)
    auto p3 = std::make_pair("two", 2.0);

    // - print the types of their content using `typeid( variable ).name()` on the content of these pairs if you are unsure
    std::cout << typeid(p3.first).name() << std::endl;

    // - declare a vector (in the sense of *container*, not geometrical vectors) of pairs and use `reserve` to reserve the memory for 8 elements
    //     > **Note:** `reserve` doest not allocate elements in the vector
    vector_pair_string_float v;
    v.reserve(8);
    //   - print the size, capacity and the content of the vector
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "content: " << std::endl;
    for (auto& p : v)
        std::cout << p.first << " " << p.second << std::endl;


    // - use `resize` to resize the vector to 2 elements
    //     > **Note:** `resize` actually instanciates elements using default constructors
    v.resize(2);

    //   - print the size, capacity and the content of the vector
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "content: " << std::endl;
    for (auto& p : v)
        std::cout << p.first << " " << p.second << std::endl;



    // - fill the rest of the vector with 6 additionnal pairs:
    //   - add three pairs using the `push_back` method (you can use the previously instanciated pairs)
    //   - add three pairs using the `emplace_back` method
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.emplace_back("four", 4.0);
    v.emplace_back("five", 5.0);
    v.emplace_back("six", 6.0);

    // - print the content of the vector
    //   - using an index-based for loop
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i].first << " " << v[i].second << std::endl;

    //   - using an iterator-based for loop
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;

    //   - using an ranged-based for loop
    for (auto& p : v)
        std::cout << p.first << " " << p.second << std::endl;

    //   - using a reverse-iterator-based for loop
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
    // - sort the vector in **increasing** order of the floatting value of the pair element
    //   - use `std::sort` from the *STL* algorithms
    //   - use a custom defined comparison function
    std::sort(v.begin(), v.end(), isSuperiorTo);

    //   - print the result
    for (auto& p : v)
        std::cout << p.first << " " << p.second << std::endl;



    // - sort the vector in **decreasing** order of the floatting value of the pair elements
    //   - use `std::sort` from the *STL* algorithms
    //   - use a *lambda* function for comparison
    std::sort(v.begin(), v.end(), [](const pair_string_float& p1, const pair_string_float& p2) {
        return p1.second > p2.second;
    }); 

    //   - print the result
    for (auto& p : v)
        std::cout << p.first << " " << p.second << std::endl;

    // - use `std::Find_if` to find the first pair which value is close to 2.0 +/- 0.2 (i.e. in the range [1.8, 2.2])
    //   - use a lambda function as predicate
    //   - check if such an element has been found
    //     - if such an element has been found print the corresponding pair
    //     - otherwise print "not found"
    auto it = std::find_if(v.begin(), v.end(), [](const pair_string_float& p) {
        return p.second > 1.8 && p.second < 2.2;
    });


    // - Check the behaviour of the `stde::vector` class
    //   - store the vector begin iterator in a variable `begIt`
    //   - add an additional pairs in the vector
    //   - print the element under `begIt`

    auto begIt = v.begin();
    v.emplace_back("seven", 7.0);
    std::cout << begIt->first << " " << begIt->second << std::endl;
}