# TP1 - Classes

### Purpose

in this TP, we will learn how a class in C++ works and how to define your own class in your code.

## Preliminary

You will use the following coding convention:
- each class has a name starting with a capital letter (e.g. `NomDeClasse`).
- each function or method has a name starting with a lower case letter (e.g. `nomDeFonction`).
- variables will use underscore in their name to separate each word (e.g. `table_name`).
- data members will additionnally be postfixed by an underscore as well (e.g. `member_table_name_`).
- you will use `{}` for calling constructors instead of `()` whenever it is possible.
- in your constructors, you will initialize the data members before the actual code of the contructor (i.e. before the opening bracket).
- all your functions and methods will include the name of their parameters (e.g. use `heightOfStackedBox(int nBoxes, float singleBoxHeight)` instead of `heightOfStackedBox(int, float)`)
- you will systematically declare all short functions and methods (one to two lines of code) as inline (and always use inline if you write the function/method implementation in the class definition).

---

## Exercice 1

### Purpose

Understand how constructors and destructors work.

**Q:** Do you know the role of the constructor ?  
**Q:** Do you know the tole of the distructor ?

> **Reminder (constructors):**
>
> - Constructors have the same name as the class.
> - You may not specify return type of constructors.
> - Constructor can be overloaded.
> - The compiler creates a public, default (without arguments) constructor if you have not provided any constructors.

> **Reminder (destructors):**
> - Destructors have the same name as the class with a '~' character prefix.
> - Destructors have no arguments.
> - Destructors cannot be overloaded.
> - The return type for a destructor may not be specified.

Both classes and structures can have constructors and distructors.

### Tasks

Define class `University` composed of the following:
- Two data members:
    - the name of the University;
    - the number of enrolled studients.
- The following member methods:
    - default constructor;
    - alternate constructor;
    - copy constructor;
    - destructor;
    > **Note:** each constructor will print a customized message in order to keep track of their invocation when running a program.
    - method `setName` (will be `inline`) to modify the name of University.
    - method `print` to provide simple output of the data members;

Do not forget to think about the regions of the access (`public`, `private` or `protected`).

### Tests

Create a `main` function where you will use all of the previously implemented methods/functions :
- instanciate several universities objects (cover the use of all constructors)
- instanciate a university object using the `new` operator
- print all these universities with the print method
- modify the name of some of them
- print again all the instanciated universities, but this time use the output stream operator
- do not forget to manage your memory (use `delete` on what was instanciated with `new`)

---

## Exercice 2

### Purpose

Understand inheritance (implementing hierarchies).

**Q:** Do you know the role of the inheritance ?  
**Q:** Do you know the role od static variables and methods ?

> **Reminder (inheritance):**
>
> - Single inheritance is when a given class has exactly one base class;
> - The derived class specifies who its base class is;
> - The base class does not specify that it has any derived classes;
> - Access regions:
>     - `private` members defined in the base class are inaccessible outside the scope of the base class;
>     - `protected` members defined in the base class are accessible in the scope of the derived class or its descendants;
>     - `public` members defined in the base class are accessible from any scope.

Inheritance hierarchies can be build using both classes and structures.

### Tasks

Define two classes:
1. a base class `Person`, which has:
    - three data members:
        > **Note:** you need to think about their access regions !
        1. the first name of the person
        2. the last name of the person
        3. the status of the person: Mr., Ms., Mrs., Miss, Dr., etc. (use an enumeration here to represent these statuses)
    - the following methods:
        - default constructor;
        - alternate constructor;
        - copy constructor;
        - destructor;
    - methods for accessing data members (so called *getters*), in read-only mode:
        > **Note:** they are publicly available for all classes.
        - getFirstName
        - getLastName
        - getStatus
        > **Note:** think about what these methods must return to comply with the read-only access specification.
    - methods for modifying the objects (so called *setters*) in writing-access:
        - setStatus
        - It should be available only for derived classes.
            > **Note:** you need to think about it access region !

1. a derived class `Student`, which has:
    - four data members:
        > **Note:** you need to think about their access regions !
        1. mean score of the student
            - use a `float`
        2. identificator of the student
            - use a `int64_t`
            - must be non-modifiable
        3. current course
            - use a `std::string`
        4. the total number of students
            > **Note:** it has to be shared by all instances of this class, because each new instance has to increment this value !
   - the following methods:
        1. default constructor;
        2. alternate constructor;
        3. copy constructor;
        4. destructor;
            > **Note:** the total number of students has to be updated when a student is created or deleted !
        5. method `print` to provide simple output of the data members;
        6. method `earnPhD` allowing to modify the current status of Person to "Dr.";
        7. method `getScore` (read-only access);
        8. method `getCurrentCourse` (read-only access);
        9. method `getStudentId` (read-only access);
        10. method `setCurrentCourse` (writing access);
        11. method `getNumberStudents` (read-only access)

### Tests

Create a `main` function where you will:
- instanciate two `Students` s1 and s2
- print these students using the `print` method
- modify s1 with `setCurrentCourse` and `earnPhD`
- print s1 to see the results
- print the toal number of students with the static variable of the `Student` class

---

## Exercice 3

### Purpose

Understand the polymorphism in C++ with virtual functions

**Q:** Do you know the role of the polymorphism ?  
**Q:** Do you know the role of virual destructor and virtual functions, and the difference between them?  
**Q:** Are virtual destructor always necessary ?

### Tasks

We want to be able to mix both `Person` objects and `Student` objects in a unique container while maintaining the ablity to call their respective implementation in a transparent manner.
C++ allow us to do that as one example of polymorphism.
In particular, we want to store in the same container some pointers to `Person` objects and `Student` objects and be able to call their respective `print` method.

To do so :
- declare the `print` method of the `Person` class as `virtual`;
- declare the `print` method of the `Student` class as `override`
- implement the `print` method of the `Student` class so it prints students information (score, etc) in addition of the person information (first name, last name, etc)
    > **Note:** you do not need to duplicate the code of the printing method of `Person` class in the printing method of the `Student` class. You can instead call the `print` method of tha base class in the implementation of the `print` method in the derived class.
> **Note:** when we store pointers to a abse class, an up-cast is performed.
If we want to destruct a derived object using the `delete` operator on a pointer to a base object, we must pay attention and declare the base destructor as virtual and implement the derived destructor to ensure the derived object is properly destructed (otherwise, only the base destructor is called on a derived object).
- declare both the destructors of the `Person` and `Student` classes as `virtual`

### Tests

Check the correctness of your code's behaviour in your main function :
- instanciate two `Person` (p1 and p2) and two `Student` (s1 and s2) using the `new` operator
- declare a `std::array` of pointer to `Person` which will store a pointer to the four instanciated objects
- loop through this array and call the `print` method on each object under the pointers
- do not forget tp free the memory
- analyse the results

---

## Exercice 4

### Purpose

Understand friend classes and friend functions.

**Q:** Do you know the role of friend classes and friend functions?

> **Reminder:**
>
> - friends functions are functions that are individually granted extended scope to include the class they are associated with;
> - friends classes are classes in which every member function of the class is a friend function of the associated class;
> - friend classes and functions should be utilized **carefully**, only when breaking encapsulation is a better choice than offering a public interface;
> - the friend class should have a forward declaration in the class definition of the class that is providing it with access to its members;
> - the keywork `friend` should precede the forward declaration of the class gaining access.

## Tasks

We would like to provide an easy way of streaming a `University` object (to the standard output, error output, a file, etc).
- Overload the output stream operator to be able to print an object of the `University` class as:
    ```cpp
    University univ_stras{"Universite de Strasbourg", 1};
    std::cout << univ_stras << std::endl;
    ```
- declare this operator as a `friend` of the `University` class so it can easily access every member of the class.

The tudents identifiers and they score are `private` with no write-access methods in order to make it impossible to modify them from the outside of the class.
However during the year, your mean score evolves.
We would like to delegate the updating operations to a `StudentManager` class that has special writing-access to the attributes of a `Student`.
> **Note (optional):** we require that there exists only one student manager to mimic real life behaviour. We will use the singleton design-pattern for this aim.

Implement the `StudentManager` class:
- this class will be a friend class of the `Student` class
- this class will have no data members
- this class will provide the following member method:
    - `void updateStudentMeanScore(Student* student, float newMeanScore)` updating the mean score of a student
- **optional: implement the singleton design pattern**
    - declare the constructor of the `StudentManager` class as `private` so it cannot be used outside the class itself
    - declare a static `StudentManager` object in the `StudentManager` class
    - declare a static method `StudentManager& getUniqueManager()` providing access to a reference to the static manager member
    - do not forget to initialize the static data member outside of the class

### Tests

Create a `main` function where you will:
- instanciate a `StudentManager` **OR (if you did the optionnal part)** get a reference to the unique `StudentManager` through the static `getUniqueManager` method
- instanciate a student s1 via the operator `new`
- print the student
- let the `StudentManager` modify s1's mean score
- print s1 to see the result