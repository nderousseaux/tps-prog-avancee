# TP3 - Templates

### Purpose

In this TP, we will learn how to use templates.

> **Reminder:**
>
> A template is a mechanism for generic programming to provide a placeholders to represent the structure of an entity
> - Templates are compile-time functionality to represent functions and classes
> - Templates are a way to make code more reusable and faster (computation can be done at compile-time)

---

## Exercice 1

### Purpose

Understand how to create and use template function (not a member of a class).

**Q:** Do you know the role of template functions?

> **Reminder:**
>
> - template functions parameterize the types of arguments in a function in addition to the arguments themselfs.
> - template functions require the body of the function to be applicable to most any data types (independent of any particular type)

### Tasks

This exercice is divided into the 3 small tasks below.

#### Task 1

In the files `ex1/task1.h` and `ex1/task1.hpp`:

1. Define a template function `add` returning the sum of two variables of the same type:
    - this function takes two parameters passed as constant references
    - this function is templated by the type `T` of the parameters
    - this function returns a value of the same type (`T`) as the parameters

2. Define a template function `incrementTwoVars` that increments two variables regardless of their type:
    - this function has two parameters passed by reference
    - this function is templated by the two types `T1` and `T2` of the two parameters
    - this function returns nothing

3. **OPTIONNAL:** Define a template function `scalarProduct` that computes the scalar product of two vectors (*mathematical* vectors) of any dimension stored in *STL* sequential containers (`std::vector`, `std::list`, etc). This function must be able to compute the scalar product of vectors regardless the container they are stored in. E.g. compute the scalar product of a vector stored in a `std::vector` with a vector stored in a `std::list`.
    - this function has two parameters passed as constant references
    - this function returns a value of the same type as the vectors components
    - this function is templated by three template parameters
        1. the data type stored in the vectors (both vectors must store values of identical type)
        2. the type of container of the first vector (which is itself templated!)
        3. the type of container of the second vector (which is itself templated!)
        > **Note:**
        >
        > Sequential containers are templated on the type of the data they contain, and the allocator of such data type
        > You can use the following :
        ```cpp
        template<class DataT,
                 template< class... > class ContainerT1,
                 template< class... > class ContainerT2>
         ```
         > See the sequential containers documentation for more information on how to write your function parameters, or ask your supervisor.

> **Note:**
>
> your function must call only methods common to all (or almost all) sequential **STL** containers in order to be fully generic.

#### Tests 1

In the function `testTask11`:

1. declare two integers `int`, two `double` and two `std::string`
2. add them with your custom `add` function
    - try to add an `int` and a `std::string`, it should not work
    - try to add an `double` and a `int`, it should not work
    - **Q:** why can't you do this?

#### Task 2

In the files `ex1/task2.h` and `ex1/task2.hpp`:

Define 3 function templates, `mult`, which multiply an integer (`int`) input number n by an input variable of any type for 3 cases:

1. Define a template function `mult` which multiply an integer (`int`) *n* by an input variable of any type
    - this function has two parameters:
        1. an integer
        2. a constant reference to another variable
    - this function is templated on the type of the second parameter
    - this function returns a value of the same type as the second parameter

2. Specialize this template function for `std::string` so that when `mult` is called with a second parameter of type `std::string`, the function return the concatenation of *n* times the input string. E.g. `mult(3, "Toc"s)` should return the string `"TocTocToc"`.

3. Overload the `mult` function so that when the second parameter is of type `std::vector`, the function returns the concatenation of *n* times the input `std::vector`. E.g. `mult(3, std::vector{1, 2, 3})` should return a `std::vector` containing the elements `1, 2, 3, 1, 2, 3, 1, 2, 3`.

#### Tests 2

In the function `testTask12`:

1. declare two integers `int`, a `float`, and a `double`
2. increment these four variables with your custom `incrementTwoVariables`
    - **Q:** can you call `incrementTwoVariables` with a `std::string` parameter? If so, why? If not... why ?

#### Task 3

In the files `ex1/task3.h` and `ex1/task3.hpp`:

Implement a variadic template function (it can handle any number of arguments greater than one), `myMin` returning the minimum value from a variable number of arguments of the same type. We will use a recursive approach since : min(a,b,c,d) = min( a, min(b, min( c, d) ) )".

1. Implement the recursive-ending case (i.e. find the min of a single value) of the function:
    - this function takes a single constant reference as parameter
    - it is templated on the type of this parameter
    - it returns a variable of the same type as the parameter
    - it returns... the value of the parameter itself since "min(a) = a"

2. Implement the general case function:
    - this function takes two arguments:
        1. a constant reference to a value
        2. a constant reference to a set of arguments (with the "..." syntax)
    - this function is templated by two types:
        1. the type `T` of the first argument
        2. the type `Args` of the variadics arguments (with the "..." syntax)
            - you will need to use the following syntax:
            ```cpp
            template< class T, class... Args >
            T myMin(const T& v, const Args&... args);
            ```
    - this function returns a value of the same type `T` as the first argument
    > **Note:**
    >
    > you will use the `std::min` function from the *STL*.

#### Tests 3

In the function `testTask13`:

1. declare and initialise (use `{}`)
    - a `std::vector` of three `int`
    - a `std::list` of three `int`
    - a `std::forward_list` of three `int`
    - a `std::dequeue` of three `int`
2. compute the scalar product of these containers
3. repeat the operation with `double` this time

---

## Exercice 2

### Purpose

Understand how to create and use template classes.

> **Reminder:**
>
> - template classes parameterize the ultimate type of a class definition, and will additionally require template member functions for any methods that need to know the core data type being manipulated.

### Introduction

A ring buffer is (among other) a smart way to implement double ended queues when we know in advance its maximum size.

> **Reminder:**
>
> A double ended queue (see std::deque) is a data structure based on the *FIFO* (First In First Out) principle.
> On a classical queue, one can only insert/remove elements on one end of the queue.
> On a double ended queue, these operations can be done from both endings.

A buffer ring keeps track of two indices: the begining of the list in the array, and the end of the list in the array. Each of them is updated accordingly when elements are inserted or removed at the respective end.

### Tasks

In the files `ex2/ringbuffer.h` and `ex2/ringbuffer.hpp`:

1. Declare a class `RingBufferDeque` able to store any data type with a fixed defined capacity:
    - this class is templated on the type `T` of data it will store
    - its maximum capacity `maxCapacity` of type `size_t`
    - its maximum capacity has a default value of 10
> **Note:**
>
> The capacity and the size of a container are not the same:
> - the size is the actual number of items in the container
> - the capacity is the maximum size

2. Complete your class declaration with the following:
    - Data members:
        - `buffer_`: the buffer for data storage with the defined capacity as a template parameter (use a `std::aray`);
        - `head_`: the index of the head (use a `size_t`);
        - `tail_`: the index of the tail (use a `size_t`);
        - `size_`: the size of the dequeue (use a `size_t`);
    - Method members:
        - default constructor;
        - `size`: returning the current size of the dequeue
        - `isEmpty`: returns true if the ring buffer is empty (no elements inside) and false otherwise
        - `isFull`: returns true, if the buffer is full (number of elements equal to the capacity) and false otherwise
        - `clear`: that clears the dequeue (remove all elements inside the dequeue)
            > **Note:**
            >
            > you only have to modify `tail_` and `size_`
        - `inDataBufferIndex`: converts the index of an element in the dequeue (in the `BufferRing`) into the index of this element in the actual data buffer (in the internal `std::array`)
        - `opertaor[](size_t i)`: providing access to the *ith* element of the ring buffer;
            > **Note:**
            >
            > - use `assert` to check if the querry index is valid
            > - you will have two versions of this operator:
            >    1. one callable from a non-const object which returns a reference to the element
            >    2. one callable from a const object which returns a constant reference to the element
        - `head`/`tail`: return the value of the element at the head/tail of the ring buffer
            > **Note:**
            >
            > use `assert` to ensure such element exist
        - `incrementTail`, `decrementTail`, `incrementHead`, `decrementHead`: respectively incrementing of decrementing the tail or the head of the dequeue
        - `push_back` and `push_front`: inserting the input parameter at the head/tail of the ring buffer. These method return a boolean set to false if the operation failed, true otherwise.
            > **Note:**
            >
            > - use assert to ensure the operation is allowed
        - `pop_back` and `pop_front`: removing the element at the head/tail of the ring buffer while returning its value.
            > **Note:**
            >
            > - use assert to ensure the operation is allowed
3. Overload the output stream operator `operator<<` to be able to stream a `RingBufferDeque` object.

### Tests

1. In the function `test`, declare a `RingBufferDeque` of `int`.
2. Check the return values of `isEmpty`, `isFull` and `size`
3. Insert 5 elements with `pushBack`, and five elements with `pushFront`
4. Check the return values of `isEmpty`, `isFull` and `size`
5. Print the buffer
6. Print the return of 4 calls to `popFront`
7. Print the buffer
8. Insert four new elements with `pushBack`
9. Print the buffer
10. Clear the buffer
11. Print the buffer
12. Repeat these operations with a `RingBufferDeque` of `std::string`.

--- 

## Exercice 3
  
### Purpose

Put all together: to use template functions, template classes and friends

### Introduction

In this exercice we will create a single linked list (as opposed to double linked lists) allowing for insertion at both ends of the list.

### Tasks

1. Define a template class `LinkListElement`
   - this class is templated on the type `T` of data it will store
   - this class has two data members:
        1.  `data_`: an object of the templated type (`T`)
        2.  `next_`: a pointer to the next `LinkListElement` of the list
        > **Note:**
        > 
        > You should to make the access to the data members as private !
    - the class has the following methods:
        - default constructor;
        - alternate constructor;
        - destructor;
2. Define a template class `LinkList`
    - this class is templated on the type `T` of data it will store
    - this class has two data members:
        1. `tail_`: a pointer to the first `LinkListElement` of the list
        2. `head_`: a pointer to the last `LinkListElement` of the list
    - the class has the following methods:
        - default constructor
        - destructor (**Important:** this destructor must free the allocated memory)
        - `isEmpty`: indicates if the list is empty
        - `insertAtTail`: inserts an element of the generic type at the tail of the list
        - `insertAtHead`: inserts an element of the generic type at the head of the list
        - `removeAtTail`: returns the value of, and removes the first element of the list
3. Overload the output stream operator `<<` to be able to print in the cycle all elements of the list.
> **Note:**
> 
> Use the `friend` keyword to gain access to the private data members of `LinkListElement` and `LinkList` in the operator function

### Tests

Fill the `main` function in `tp3/ex3/main.cpp`:
1. Declare a `LinkedList` of `std::string`
2. Insert `"Hello"`, `"world`, and `"!"` at head
3. Insert `"!"`, `"world`, and `"Hello"` at tail
4. Print the list
5. Remove an element from the tail and print again

---

## Exercice 4

For this exercice, you need the following classes:
- `Person` and `Student` from tp1/ex2
- `LinkList` and `LinkListElement` from tp3/ex3

### Tasks

Instead of `int`, `float`, `std::string` (etc.) types, you can now create a `LinkedList` containing `Student` objects !
- overload the output stream operator `<<` for `Student`
- in function `main`:
    - instanciate a `LinkList` of `Students`
    - insert two elements
    - print the list

---

### Exercice 5

### Purpose

Understand what a functor is and enumeration templating.

> **Reminder:**
>
> A functor is a class that acts like a function: its main feature is to provide the `operator()` method.

### Introduction

In this exercice you will create a functor able to compute the mean of two numeric variables.
Your functor class must be able to handle both definitions of mean: algebraic and geometric.

> **Reminder:**
>
> The geometric mean $g_m$ of two variables $\lambda_1$ and $\lambda_2$ is defined as :
> $g_m = \sqrt{\lambda_1 \times \lambda_2}$

### Task

1. Define an enumeration named `MeanDefinition` with the possible values:
    1. Algebraic
    2. Geometric
2. Define a `MeanFunctor` class with the following as public (alternatively you may simply declare a `MeanFunctor` struct):
    - it is templated on the value of a `MeanDefinition`
    - it has no data member
    - it has a single function member: the `operator()`
        - this operator takes two constant references as parameters
        - this operator is templated on the type `T` of the parameters
        - this operator returns the algebraic/gemetric mean (as a `double` in order to be valid) of the parameters according to the `MeanDefinition` on which the class is templated

### Tests

1. In you main function, instanciate to `MeanFunctor` variables:
    1. one `MeanFunctor< MeanDefinition::Algebraic >`
    2. one `MeanFunctor< MeanDefinition::Geometric >`
2. Use them to compute the different means of two numbers