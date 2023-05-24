# TP5 - SFINAE (Substitution Failure Is Not An Error)

SFINAE is important because, usage of templates does not ensure that the actual types used are what we expect. That can lead to unexpected behavior, suboptimal performance, and even buggy, unreliable code.

### Purpose

In this TP, our goal is to demystify SFINAE and understand how to use it in your own code.

> **Note:**  
> In this context:
> - SFINAE allows us to be explicit about what types we are expecting in our template
> - SFINAE provides us with a means to change the behavior of our templates, based on the types we are provided

---

## Exercice 1

### Purpose 

Understand what SFINAE is and how to use it in your own code. 

> **Reminder:**  
> when a template type is being substituted, if a failure occurs the compiler will not generate an error as a result.
> An error would occur, if the compiler cannot find a suitable substitution.

This exercise is a classical example of SFINAE application: use SFINAE for choosing appropriate overloads of function templates based on properties of the passed in type(s).

### Task 1

#### Purpose

Undestanding the motivation for using SFINAE.

#### Task 1 details

In the files `ex1/customprint.h` and `ex1/customprint.hpp`:

1. implement two versions of a function named `print`
    - this function is templated on a type `T`
    - this function takes a variable of type `T` as single argument
    - this function is intended to print either integers or floats
        - define one version for integers and one for floats
        - each vertsion will print something different along with the value of the argument
2. you have use SFINAE to select the correct template version for a given type of argument.

> **Note: **
> - you have to include the header <type_traits>
> - you have to use `std::enable_if_t` (C++17) in the template function specializations, in order to define a type if its parameter is true (otherwise, it will generate a substitution error, forcing the compiler to pick a different version of the template.
> - `std::enable_if_t` returns `void` by default.
> - you have to use `std::is_integral_v` and `std::is_floating_point_v` in order to check the types that are provided by the standard library, which has a a big list of different versions of these functions including different types and properties.

In this exercice, SFINAE is used to allow the compiler to pick the most suitable version of the function (print) based on the type that was provided (int or float).


#### Tests for task 1

For testing you code, you have to run the function `testTask1()` from `tests.cpp` and check that SFINAE works and picks the right template in each case.
The output has to be as follows:

```cpp
========== TP4 - Exercice 1 - Task 1 ==========
Printing int : 15
Printing int : 15
Printing float : 15.123
```

### Task 2

This task is another example of using SFINAE to pick a function overload depending on trails.

#### Purpose

Consolidate your previous experience with one more practical exercice with `std::enable_if_t`. 

#### Task 2 details

In the file `ex1/isb.h`:
1. define 2 empty classes `A` and `B`
2. implement a structure, called `is_B`, which can detect whether a given types mathes the class B interface:
    - this structure is templated on a type `T`
    - provide two version of function template, called `check`, where:
        1. the first version print the message `check: class B` and returns `true`, if the given type is the class `B`;
        2. the second version prints `check: class is not B` and returns `false`, if the given type is not a class `B`.

> **Note:**  
> - you have to include the header <type_traits>
> - you have to use std::enable_if_t (C++17) in the template function specializations,
> - you have to use std::is_same. 

#### Tests for task 2

For testing, you have to use given test cases in function testTask2() of `ex1/tests.cpp`. You have to make sure that your SFINAE works and picks the right template in each case.
The output has to be as follows:

```cpp
========== TP4 - Exercice 1 - Task 2 ==========
check: class is not B
check: class B
It works!
```