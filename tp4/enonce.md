# TP4 - Lambda functions, smart pointers and patterns

[Go to exercice 1](#exercice-1)  
[Go to exercice 2](#exercice-2)  
[Go to exercice 3](#exercice-3)  
[Go to exercice 4](#optional-exercice-4)  

### Purpose

In this TP, we will study 3 different subjects:
1. lambda functions
2. smart pointers
3. some design patterns

> **Note:**  
> Patterns are optional part of this TP, but can be useful in your future projects.

---

> **Reminder:**  
> A lambda function is an anonymous function object that you create inline.
> It is useful for short snippets of code that are neither reusable nor worth naming.
>
> **Syntax:**  
> ```cpp
> [value] (int x) -> bool { return x > value; }
> ```
> - captured parameters are first indicated within brackets []
> - lambda function arguments are indicated within parentheses ()
> - return type is indicated after the arrow ->
> - the lambda body is written between curly brackets {}
>
> **Example of trivial lambda:**  
> ```cpp
> []() -> void { std::cout << "Hello world!"; }
> ```
> This lambda does not capture any parameter nor does it takes any argument. It return `void` and its purpose is to print *Hello world!* on the standard output.

---

**Q1:**
When would you use lambda?  
**A:**
It is particularly useful when you want to pass an operation as an argument to an algorithm.

**Q2:**
What class of problems do lambdas solve that wasn't possible prior to their introduction?

---

## Exercice 1

[Go to top](#tp4---lambda-functions-smart-pointers-and-patterns) 

This exercise is divided into 4 tasks.

### Task 1: lambdas for predicates

#### Purpose

Undestand some of the motivations for using lambdas.

#### Introduction

We would like:

1. to define the function `printWithPredicate` that prints to the standard output all elements of a container which satisfy a predicate given as a boolean lambda function
    > **Example:**  
    > Calling `printWithPredicate` on the set of integers {1, 2, 3, 4, 5, 6} with the predicate function "*if x is even return true, else return false*" should print:
    > ```cpp
    > 2, 4, 6
    > ```
2. to be able to compute the sum of all elements in a container which satisfy a predicate given as a boolean lambda function
    > **Example:**  
    > the sum of all elements in the set of integers `{1, 2, 3, 4, 5, 6}` considering the following predicate function "*if x is less or equal to three*" should evaluate to:
    > ```cpp
    > 6 // since: 1 + 2 + 3 = 6
    > ```

#### Task 1 details

In the files `ex1/printWithPredicate.h` and `ex1/printWithPredicate.hpp`:
1. define the `printWithPredicate` function:
    - this function is templated on two parameters
        1. the type `ContainerT` of a container
        2. the type `PredicateT` of a function
    - this function takes two arguments:
        1. a reference to a constant container `container` of type `ContainerT`
        2. a function `predicateFunc` of type `PredicateT`
    - this function must print the elements of `container` satisfying the predicate given by `predicateFunc`

#### Tests for task 1

In the file `ex1/tests.cpp`, in function `testTask1`:
1. Test your `printWithPredicate` function:
    1. create a `std::vector` of integers `vec` and initialize it with integer values
    2. declare an integer variable `threshold` and initialize it to a value of your choice
    3. call `printFiltered` on `vec` with a lambda function as second parameter:
        - this lambda captures the variable `threshold` by copy 
        - this lambda takes a single integer `x` in argument
        - this lambda returns `true` if `x` is greater than `threshold`, `false` else
        > **Note:**  
        > As the result this call will print all elements of `vec` which are greater than `threshold`
    4. run your program and check the results
2. Use `std::for_each` in combination with a lambda function to compute the sum of all elements in a container which are lesser than a threshold:
    1. declare an integer variable `sum` and initialize it to 0
    2. use `std::for_each`:
        - the first and second parameters will be the begin and end iterators of your vector `vec`
        - the third argument will be a lambda function:
            - this lambda captures its environment by copy, except `sum` which is captured by reference
            - this lambda takes a single integer parameter `x`
            - this lambda updates `sum` if `x` is lesser than `threshold`
    3. run your program and check the results

### Task 2: lambda captures and mutable

#### Purpose

Understanding lambda captures (by copy, by reference) and mutable lambdas.

> **Note:**  
> You cannot modify variables captured by copy inside the body of the lambda.
> If you wand to change this behavior, you need to use `mutable` keyword after the parameter list.
> For example:
> ```cpp
> [value] (int x) mutable -> bool { x += value; std::cout << "New value for x " <<  x << std::endl; }
> ```
> This lambda updates the parameter x captured by copy and prints it to the standard output.

#### Task 2 details

There is no task separated from the tests in this task.
See the tests section below.

#### Tests for task 2

In `ex1/tests.cpp`, in function `testTask2`:

1. declare two integer variables `x` and `y` and initialize them
2. define a classical (as opposed to *mutable*) lambda function called `printIncrementedXyNaive`
    - this lambda captures the two variables `x` and `y` **by copy**
    - this lambda increments both variables and prints the new values of `x` and `y`
    - you should encounter a compilation error !
    - **Q:** Why? After this question, delete your lambda.
3. define a lambda function called `printIncrementedXyMutable`
    - this lambda captures the two variables `x` and `y` **by copy**
    - this lambda must be able to change the values of variables captured by copy (use `mutable`)
    - this lambda increments both variables and prints the new values of `x` and `y`
    - now your code compiles!
4. print the values of `x` and `y`
5. call `printIncrementedXyMutable`
6. print the values of `x` and `y` again, observe the results
    - **Q:** have the values of `x` and `y` variables cahnged?
7. define a classical lambda function called `incrementXY`
    - this lambda captures the two variables `x` and `y` **by reference**
    - this lambda increments both variables and prints the new values of `x` and `y`
8. repeat steps 4, 5, and 6 by calling `incrementXY` instead of `printIncrementedXyMutable`
9. **Q:** What happens if the value of `x` changes between the declaration of `printIncrementedXyMutable`, and its call ?
10. **Q:** Same question with `incrementXY`?

> **Note:**  
> The use of `mutable` is often **not advised**. In the vast majority of usage cases, one would simply copy the value of the parameter captured by copy into a local variable.

### Task 3: parallel between captured parameters and functors

#### Purpose

Understand what is a functor and illustrate a similar way of capturing variables.

> **Reminder:**  
> A functor is a class acting like a function in the sense that it defines the operator `()` which is called in a very similar way to functions.

#### Task 3 details

In `ex1/functorgreaterpredicate.h`:

1. declare a class named `FonctorGreaterThanPredicate`
    - this class has a single attribute `value_` which is a constant integer
    - implement an alternate constructor taking an integer as argument
    - implement the operator() with one integer argument `x`
        - this operator returns true if `x` is greater than `value_`

In `ex1/functorlesserthansum.h`:

1. declare a class named `FonctorLesserThanSum`
    - this class has two attributes:
        1. an integer `threshold_`
        2. **a reference** to an integer `sum_`
    - implement an alternate constructor taking an integer and **a reference** to an integer as arguments
    - implement the operator() with one integer argument `x`
        - this operator does not return a value (`void`)
        - this operator adds `x` to the attribute `sum_` if `x` is lesser than `threshold`

#### Tests for task 3

In `ex1/tests.cpp`, in function `testTask3`:

1. create a `std::vector` of integers `vec` and initialize it with integer values
2. declare an integer variable `threshold` and initialize it to a value of your choice
3. declare an integer variable `sum` and initialize it to 0
4. instanciate a `FonctorGreaterThanPredicate` object named `greaterThanSevenPredicate`
5. instanciate a `FonctorLesserThanSum` object named `lesserThanSevendSum`
6. call your previously defined `printWithPredicate` function with `vec` and `greaterThanSevenPredicate` in parameters
7. call `std::for_each` from the begin iterator of `vec` to its end iterator and with `lesserThanSevendSum` as third parameter
8. print the value of `sum`
9. run your program and check the results
    - **Note:** These functors highlight the difference between capturing parameters **by copy** (which is the case for `FonctorGreaterThanPredicate`) and **by reference** (which id the case for the `sum_` attribute of the `FonctorLesserThanSum` class).

### Task 4: higher-order returning lambda

#### Purpose

Understanding a *higher-order returning lambda* function.

> **Note:**  
> A *higher-order returning lambda* function is a lambda function returning another lambda function (you may see it as a *function factory*).
> It offers many possibilities for customizing your code and enhance its compactibility.

#### Introduction

We want to create a higher-order returning lambda returning the *greater than* boolean predicate function according to a threshold value.

#### Task 4 details

In the file `ex1/tests.cpp`, in function `testTask4`:

1. define a lambda function named `larger_than`
    - this lambda does not capture its environment
    - this lambda takes a single argument `x` (use `auto` for the type of `x`)
    - this lambda returns the following lambda:
        - the returned lambda captures `x` by copy
        - the returned lambda takes a single argument `y` (use `auto` for the type of `y`)
        - the returned lambda returns `true` if `y` is greater than `x`

#### Tests for task 4

1. use your lambda named `larger_than` to instanciate several thresholding functions, for example:
    > ```cpp
    > auto larger_than_seven = larger_than(7);
    > auto larger_than_ten   = larger_than(10);
    > ```
2. print the results for 2 following expressions:
    > ```cpp
    > std::cout << larger_than_seven(3)  << std::endl; // should return 0
    > std::cout << larger_than_seven(13) << std::endl; // should return 1
    > std::cout << larger_than_ten(3)    << std::endl; // should return 0
    > std::cout << larger_than_ten(13)   << std::endl; // should return 1
    > ```

---

## Exercice 2

[Go to top](#tp4---lambda-functions-smart-pointers-and-patterns) 

### Purpose

Understand *smart pointers* (`std::unique_ptr` and `std::shared_prt` in the Standard C++ Library).

**Q:** DO you know the role of smart pointers?

> **Reminder (*smart pointers*):**  
> Overall, a *smart pointer* is a small wrapper class that encapsulates a *raw* pointer (for dynamically allocated memory), ensuring that the pointed object is automatically deleted when the wrapper object goes out of scope.
> A *smart pointer* can alleviate many of the problems with *raw* pointers, mainly forgetting to delete the object or memory leaks!

> **Reminder (`std::unique_ptr` and `std::shared_ptr`):**  
> - `std::unique_ptr` is to enforce a single owner for dynamically allocated objects
> - `std::shared_ptr` allows for multiple owners of dynamically allocated types
>
> Both pointers allow the user to **move** the contents of a pointer type from one instantiation to another, but only `std::shared_ptr` allows the user to make a **copy** of the pointer (as copying the pointer would create more than one owner).
> A `std::unique_ptr` cannot be duplicated and the owner of a `std::unique_ptr` will have sole use of that pointer.

> **Usage:**  
> So, how to kwow, which smart pointer should you use in which cases?"
> - use `std::unique_ptr` when you want your object to live just as long as a single owning reference to it lives.
> For example, use it for a pointer to memory which gets allocated on entering some scope and deallocated on exiting the scope.
> There are two operations that you cannot perform with unique pointers: copy and assignment.
> - use `std::shared_ptr` when you do want to refer to your object from multiple places and do not want your object to be deallocated until all these references are themselves gone.
> Shared pointers store something called a **reference count**, which keeps track of the number of pointers to an object (manager object to be specific).
> As we create more copies of the pointer and they exit scope, the reference count is incremented and decremented accordingly. 
> Finally, when the reference count reaches zero, the underlying memory is freed.

> **Note:**  
> You must #include <memory> to use smart pointers.

### Task 1

#### Purpose

Understanding `std::unique_ptr`.

#### Task 1 details

In file `ex2/tests.h`

1. declare an inline function `foo`
    - this function takes a `std::unique_pointer` of `BaseClass` in argument (**not a reference**)
    - this function call the print method of the object under the pointer

In `ex2/baseclass.h`:

1. define a base class named `BaseClass`
    - this class has a **pure virtual** method `void print()`
    - this class has a virtual destructor in which a message is printed out

In `ex2/derivedclass1.h` and `ex2/derivedclass2.h`

1. define two derived classes names `DerivedClass1` and `DerivedClass2`
    - these classes derive from `BaseClass`
    - each class overrides the virtual `print` function which prints something different
    - each class overrides the virtual destructor in which a different message is printed out

#### Tests for task 1

In `ex2/tests.cpp`, in function `testTask1`:

1. declare two unique pointers (`std::unique_ptr`) named `up1` and `up2` to `BaseClass` objects:
    - one pointing on a dynamically allocated instance of `DerivedClass1`
    - one pointing on a dynamically allocated instance of `DerivedClass2`
        > **Reminder:**  
        > It is **strongly** advised to use `std::make_unique<T>` to instanciate a `std::unique_ptr`
2. use `up1` and `up2` to call the `print` method of each object
3. declare a unique pointer of `BaseClass` named `up3` by calling the copy constructor (with `up1` in parameters)
    - you should encounter a compilation error
    - **Q:** Why is this not allowed?
4. declare a unique pointer of `BaseClass` named `up4` using the default constructor and try to affect `up1` to `up4`
    - you should encounter a compilation error
    - **Q:** Why is this not allowed?
5. try a call to `foo(up_1)`
    - you should encounter an error
    - **Q:** Why is this not allowed?
6. you can however move the ownership from a unique pointer to another: use `std::move` to move `up1` to `up2`
7. try to call `foo` passing `std::move(up2)` in parameter
    - **Q:** What happens to `up2` ?

> **Note:**  
> As you can see the ownership of objects can be transferred, but always remains in a single place at a time.

### Task 2

#### Purpose

Understanding `std::shared_ptr`.

#### Task 2 details

This task does not require any code before testing the behaviour of `std::shared_ptr`. See tests section below.

#### Tests for task 2

In `ex2/tests.cpp`, in function `testTask2`:

1. understand the reference counter of *shared pointers*
   1. create a `std::shared_ptr` named `sp1` pointing on a integer variable
       > **Note:**  
       > It is strongly recommended to use `std::make_shared` and pass it the integer value you want to be stored under the pointer
   2. print the reference counter of `sp1` with the `use_count` method
   3. in a block (write this code between curly brackets `{}`):
      1. create a `std::shared_ptr` named `sp2` pointing on the same object as `sp1` using copy constructor 
      2. print the reference counter of `sp1` and `sp2`
      3. create a `std::shared_ptr` named `sp3` usinig default constructor
      4. use copy affectation operator (`=`) so that `sp3` points on the same object as `sp1`
      5. print the reference counter of `sp1`, `sp2` and `sp3`
   4. after this block (after the closing curly bracket):
    1. print again the reference count of `sp1`
2. understand the creation of, and the management of objects by *shared pointers*
   1. declare a `DerivedClass1` object named `myObject`
   2. print the address of `myObject`
   3. in a block:
      1. create two `std::shared_ptr` named `sp4` and `sp5` and pass `myObject` as parameter of `std::make_shared`
      2. print the reference counter and the actual adress of the pointer stored in `sp4`and `sp5` (use the `get` method of the `std::shared_ptr` class)
   4. after the block, call the `print` method on `myObject` (`myObject` has not been destructed)
   5. **Q:** What happened here? To be sure, explicitly delete the copy constructor of `DerivedClass1`, you should encouter a compilation error
3. understand the object manager of *shared pointers* and the call to destructors
    1. in a first block:
       1. create a `std::shared_ptr<BaseClass>` named `sp6` pointing on a new `DerivedClass1` instance
    2. in a second block:
       1. create a `std::unique_ptr<BaseClass>` named `up7` pointing on a new `DerivedClass1` instance
    3. run your program and check the calls to destructors thanks to printed messages
    4. make the destructor of `BaseClass` non virtual and re run your program
    5. **Q:** Which destructor is called, when and why?
    6. **Q:** What differences exist between *unique pointers* and *shared pointers*?
    > **Note:**  
    > Remember, when you use pointers of a base class object pointing on derived class object (upcast is performed), you should implement the destructors as virtual to avoid potential memory leaks due to incomplete destruction of objects.

## Exercice 3

[Go to top](#tp4---lambda-functions-smart-pointers-and-patterns)  

### Purpose

First steps with threads and more details on the difference between `std::unique_ptr` and `std::shared_ptr` in practice.

### Task 1

#### Purpose

Familiarize yourself with threads creation, execution, and synchronization.

#### Task 1 details

This task does not require any code before testing the creation of threads. See tests section below.

#### Tests for task 1

In `ex3/tests.cpp`, in function `testTask1`:

1. store the maximum number of concurrent threads on your computer in a variable named `nConcurrentThreads` using the static method `std::thread::hardware_concurrency()`
2. print the value of `nConcurrentThreads`
3. use a classical for loop (*C style* `for(size_t i{0} ; ...`) from `0` to `nConcurrentThreads`
    - at each iteration, instanciate a thread executing a lambda function
        - this lambda function captures the iteration `i` by copy
        - this lambda function prints both the thread identifier (use `std::this_thread::get_id()`) and the iteration `i` to the standard output, it then calls `std::this_thread::sleep_for` before printing a final message including the thread identifier
4. test your program
    - you should encounter a runtime error, if it is not the case, re-run your program until you encounter the runtime error
    - **Q:** Why do you encounter this error?
    - **A:** Your main thread terminated before some child threads, resulting in an error
5. imagine you don't mind having a task runnning in background regardless of the state of your program. Detach (using the `detach()` method of `std::thread`) each created thread from its parent thread after the threads instanciation
6. test your program again and observe the results
    - on Windows: some prints should happen after your program terminates (visible by the prompt) because some children threads terminated after your main thread
    - on Linux: the prints may not be all displayed in your terminal for the same reason (but the terminal handles differently the outputs).
    > **Note:**  
    > It is **not a good practice** to detach a thread if you do not intend to manage thread completion on your own!
    > This task was only intended to illustrate errors due to unmanaged threads.
7. instead of calling `detach()` on the created threads, call `join()` and run your program
    > **Reminder:**  
    > - `join` forces the parent thread to wait for the child thread to finish its execution
    > - `detach` permits the child thread to be executed independently from the parent thread handle. **ONLY USE WITH CAUTION!**
8. observe that the main thread waited for each child thread at each iteration (visible since the prints are done *in order*)
9. **Q:** Observing these results, did we gain some execution time?

### Task 2

#### Purpose

Good practice regarding threads creation and synchronization.

#### Task 2 details

This task does not require any code before testing the creation of threads. See tests section below.

#### Tests for task 2

In `ex3/tests.cpp`, in function `testTask2`:

1. declare an array named `threadsArray` (use `std::array`) of 10 threads
2. loop through `threadsArray` and for each thread:
    1. use move affectation (with `=`) (note that this affectation **is not the copy affectation** since threads are not copyable) so that the thread will execute a lambda function identical to that of Task 1
3. loop again through `threadsArray` and for each thread:
    1. call the `join` method
4. run your program and observe:
    - the main thread **did wait** for all threads to finish before finishing itself
    - the child threads were effectively executed in parallel

### Task 3: threads, pointers and memory access

#### Task 3 details

In `ex3/tests.cpp`:

1. declare a global variable `count` of type `std::atomic<int>` and initialize it to 0
    > **Note:**  
    > The use of `std::atomic` ensures that if one thread writes to an atomic object while another thread reads from it, the behavior is well-defined. It ensures that the variable is thread-race-safe.

In `ex3/tests.h` and `ex3/tests.cpp`:

1. define the function `incrementFromRawPtr`
    - this function has a single argument `val` which is a (raw) pointer to an integer
    - this function adds the value pointed by `val` to the global variable `count`
    > **Note:**  
    > You will use the `extern` keyword to indicate that the `count` variable is extern to this function and the functions declared in the following tasks.

#### Tests for task 3

In `tests.cpp`, in function `testTask3`:

1. declare an array named `threadsArray` (use `std::array`) of 10 threads
2. in a block:
    1. create a `std::unique_ptr` of integer named `uptr` using `std::make_unique`
    2. iterate over the threads of `threadsArray`, and, for each thread:
        - use the move affectation so that the thread calls `incrementFromRawPtr` on the pointer managed by `ptr` (use the `get` method to gain access to the pointer managed by the *unique pointer*)
3. after the block:
    1. loop through all threads in `threadsArray` and
        1. call `join` on each thread
4. print the value of the global variable `count`
    - the output should not be as expected
    - **Q:** Why?
    - **A:** Because the unique pointer `uptr` only lives in the block it is defined. At the end of the block, it destructs the integer it points to, while some threads have not yet read its value. Therefore, some threads attempt to read from some memory that has been deleted, and read garbage instead.
5. try with a `std::shared_ptr` named `sptr` instead
    - the output should not be as expected
    - **Q:** Why?
    - **A:** Same answer as with `std::unique_ptr`: the problem remains since we use the `get` method to access to the raw pointer!

Let us make it work ! Three solutions for that:

1. obviously, move the declaration of the *unique pointer* outside the defined block if you intend to use it again later (or remove that block). This is satisfactory
2. obviously, the same solution stands for *shared pointers*
3. go further with *shared pointers*:
    1. in `ex3/tests.h` define the function `incrementFromSharedPtr` and use it instead of `incrementFromRawPtr` in your threads:
        - this function has a single argument `val` which is a `std::shared_ptr` to an integer
        - this function adds the value pointed by `val` to the global variable `count`
    2. run your program, this time you get the expected behaviour! That is because a copy of `sptr` is created when calling `incrementFromSharedPtr` in each thread. Therefore, in each thread exists a *shared pointer* that co-owns the integer which liberates its ownership only when the thread finishes.
4. try to go further with *unique pointers*:
    - you should soon realise that you cannot because unique pointers are not copyable and you will encouter a compilation error. Even moving the unique pointer from an instance to another will not solve our problem.
  
## Optional exercice 4

[Go to top](#tp4---lambda-functions-smart-pointers-and-patterns) 

### Purpose

Understand the design pattern *factory*.

> **Reminder:**
> Design patterns provide a common approach for solving different types of problems properly.
> They are important, because mastering patterns gives you the ability to tackle hard problems based on already existing approaches.
> The *factory* pattern create objects without exposing the creation logic to the client, and refer to newly created object using a common interface.

### Tasks

In `ex4/shape.h`:

1. create a `Shape` class:
    - this class has no data member
    - this class has a single pure virtual const method `draw` returning `void`

In `ex4/circle.h`, `ex4/rectangle.h` and `ex4/triangle.h`:

1. create the classes `Circle`, `Rectangle` and `Triangle`
    - they all derive from `Shape`
    - they all override the virtual `draw` function which print the name of the shape to the standard output

In `ex4/shapefactory.h`:

1. create a class `ShapeFactory`
    - this class has a default constructor (use the one provided by the compiler)
    - this class has a default destructor (use the one provided by the compiler)
    - this class has a method `createCircle`
        - the type of return of this method is `Shape*`
        - this method returns a new `Circle` object dynamically allocated
    - this class has similar methods `createRectangle` and `createTriangle`
    > **Note:**  
    > The *factory* pattern can also be implemented via static methods instead of member methods.

### Tests

In `ex4/tests.cpp`, in function `testTask1`:

1. instanciate a `ShapeFactory` object named `myFactory`
2. store in a variable named `obj1` the return of `myFactory.createCircle()`
3. store in a variable named `obj2` the return of `myFactory.createRectangle()`
4. store in a variable named `obj3` the return of `myFactory.createTriangle()`
5. call the `draw` method on each object
6. check the output