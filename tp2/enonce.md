# TP2 - Standard Templare Library (*STL*) containers.

## Purpose

- understand how to use essential *STL* containers;
- customize *STL* containers.

> #### Reminder
> - *STL* has a full line of container classes, which can be classified by several categories:
>    1. Sequential containers (provide sequential acess to their elements); `std::list`, `std::stack`;
>    2. Associative containers (can be searched quickly to retrieve an element): `std::set`, `std::map`;
>    3. Unordered containers (can be searched reasonaly quickly): `std::unordered_set`, `std::unordered_map`.
> - STL provides a full complement of iterators that allow us to walk through containers;
> - STL contains a supply of useful algorithms.

**Q:** Do you know the differences between different sequential containers ?

### Exercice 1

## Purpose

Understand and use the container `std::list`.

## Tasks

- declare a `std::list` of integers
- insert three integers at the end of the list: 0, 1, 2
- print the list using an iterator for loop with `std::list<int>::const_iterator`
    > **Note:**
    >
    > using a `std::list<int>::const_iterator` you are not able to modify the objects of the list.
    > If you were to do so, you would use `std::list<int>::iterator` iterators instead
- use an iterator for loop combined with the `auto` keyword to have a reference on the list's elements
    - increment the integers in the list
    - print them (should now print: 1, 2, 3)
- insert three integers at the begining of the list: 4, 5, 6
- print the list using a ranged-based for loop (should now print 6, 5, 4, 1, 2, 3)
- insert three times the integer "10" **after** the first element added (after the element "1" in the list)
    > **Note:**
    >
    > - the `insert` method of `std::list` requires the position where new elements will be inserted.
    > - the `insert` method of `std::list` inserts an element **before** the given position.
    - keep track of the first element inserted with an iterator before passing it to the `insert` method
- print the list using a for loop with `std::list<int>::const_reverse_iterator` (should now print 3, 2, 10, 10, 10, 1, 4, 5, 6)

---

## Exercice 2

### Purpose

- understand the keyword `using`
- manipulate `std::pair` of
- use the `std::vector` container
- understand how to use the algorithms from the *STL* library

### Tasks

> **Reminder:**
>
> the `using` keyword allows you to declare aliases and simplify code writing and readability

- use the `using` keyword to create an alias for a pair of (`std::string` and `float`)
- use the `using` keyword to create an alias for a vector of pair of (`std::string` and `float`)
- instanciate two pairs p1 and p2 using the pair constructor
- instanciate two pairs p3 and p4 using `std::make_pair`
- create two pairs p5 and p6 with the `auto` keyword as type with values (`"two", 2.0`) and (`"two", 2`)
- what is the type of these pairs ?
    - print the types of their content using `typeid( variable ).name()` on the content of these pairs if you are unsure
- declare a vector (in the sense of *container*, not geometrical vectors) of pairs and use `reserve` to reserve the memory for 8 elements
    - print the size, capacity and the content of the vector
        > **Note:** `reserve` doest not allocate elements in the vector
- use `resize` to resize the vector to 2 elements
    - print the size, capacity and the content of the vector
        > **Note:** `resize` actually instanciates elements using default constructors
- fill the rest of the vector with 6 additionnal pairs:
    - add three pairs using the `push_back` method (you can use the previously instanciated pairs)
    - add three pairs using the `emplace_back` method
    - **Q:** what is the difference between these two methods ?
- print the content of the vector
    - using an index-based for loop
    - using an iterator-based for loop
    - using an ranged-based for loop
    - using a reverse-iterator-based for loop
- sort the vector in **increasing** order of the floatting value of the pair elements
    - use `std::sort` from the *STL* algorithms
    - use a custom defined comparison function
    - print the result
- sort the vector in **decreasing** order of the floatting value of the pair elements
    - use `std::sort` from the *STL* algorithms
    - use a *lambda* function for comparison
    - print the result
- use `std::Find_if` to find the first pair which value is close to 2.0 +/- 0.2 (i.e. in the range [1.8, 2.2])
    - use a lambda function as predicate
    - check if such an element has been found
        - if such an element has been found print the corresponding pair
        - otherwise print "not found"
- Check the behaviour of the `stde::vector` class
    - store the vector begin iterator in a variable `begIt`
    - add an additional pairs in the vector
    - print the element under `begIt`
    - **Q:** you should encounter an error, why ?

---

## Exercice 3

### Purpose

- discover the associative container `std::map`
- discover the associative container `std::multimap`

### Tasks

#### std::map

- declare a `std::map` with an integer as key and the previously defined pairs as data
- insert three elements in your map using the `insert` method:
    1. key: `7`, data: (`"One", 1.0f`)
    2. key: `5`, data: (`"Two", 2.0f`)
    3. key: `5`, data: (`"Five", 5.0f`)
- print the elements of the map
- insert three elements in your map using the `operator[]`:
    1. key: `3`, data: (`"Three", 1.0f`)
    2. key: `2`, data: (`"Seven", 7.0f`)
    3. key: `2`, data: (`"Nine", 9.0f`)
- print the elements of the map
- **Q:** what is the difference bewteen inserting elements with the same key using `insert` and using `operator[]` ?

#### std::multimap

- repeat the previous operations with a `std::multimap` instead
    > **Warning:** `std::multimap` has no `operator[]`
- **Q:** why does `std::multimap` has no `operator[]` ?

---

## Exercice 4

### Purpose

- understand the *unorered* containers
- manipulate the `std::unordered_set` container

### Tasks

- declare a `std::unordered_set` of `std::string`
- insert five elements in the set using `insert`, ignore the return value of the insertion:
    1. "Hello"
    2. "world"
    3. "!"
    4. "Hello"
    5. "!!"
- print the elements in the set
    > **Note:** a set cannot contain duplicated elements!
- now consider the return value of `insert`:
    - create a function `void insertInSetAndCheck(std::unordered_set<std::string>& set, const std::string& value)` that inserts the element `value` in the set `set` and print a message on the standard error whenever an insertion failed because the element already existed in the set        
        - get the return value of the `insert` method using the `auto` keyword
    - insert five additional elements in the set using your custom function
        1. "My"
        2. "name"
        3. "is"
        4. "Bryan"
        5. "Bryan"
- print the elements in the set

### Optional:

The unordered containers require a hash function.
- try to instanciate an unordered set of pair (`std::string` and `float`) similar to exercice 2.
    - **Q:** you encounter a problem, which one ?

We don't want to define a custom hash function for our pairs, instead we will simply use the system-provided hash function for `std::string` and use it as the hash function for our pairs.
- define a `struct` with:
    - a single attribute:
        1. a `std::hash<std::string>` (a `struct` which `operator()` provides a system-provided hash function for `std::string`) named `hs_`
    - a single inline method:
        1. the constant `operator()` which takes one pair (`std::string` and `float`) in parameter and returns the result of the hash function of the `string` element of the pair
- declare an unordered set of pair (`std::string` and `float`) providing your custom hash structure
- insert elements in this set
- print the elements of this set