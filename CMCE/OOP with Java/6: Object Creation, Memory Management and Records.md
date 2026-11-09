# Session 6: Object Creation, Memory Management and Records in Java

**Course:** CMCE – August 2026 Batch  
**Subject:** Java Programming  
**Session:** 6  
**Duration:** 2 Theory + 2 Lab + 2 Self-Learning Hours

---

## 📚 Table of Contents

1. [Heap Memory and Stack Memory](#1-heap-memory-and-stack-memory)
2. [Constructors in Java](#2-constructors-in-java)
3. [Initializing Reference Variables Using Constructors](#3-initializing-reference-variables-using-constructors)
4. [Pass by Value vs Pass by Reference](#4-pass-by-value-vs-pass-by-reference)
5. [Reassigning a Reference Variable](#5-reassigning-a-reference-variable)
6. [Passing Reference Variables to Methods](#6-passing-reference-variables-to-methods)
7. [Initializing Reference Variables of Different Classes](#7-initializing-reference-variables-of-different-classes)
8. [Records in Java](#8-records-in-java)
9. [Lab: Student Management System](#9-lab-student-management-system)
10. [Important Interview Questions](#10-important-interview-questions)
11. [MCQs](#11-multiple-choice-questions)
12. [Quick Revision Notes](#12-quick-revision-notes)

---

# 1. Heap Memory and Stack Memory

Memory management is an important concept in Java. Whenever a Java program executes, the JVM uses different memory areas to store data and manage program execution.

Two important memory areas are:

1. Stack Memory
2. Heap Memory

## 1.1 Stack Memory

Stack memory is used to manage method execution.

Whenever a method is called, the JVM creates a stack frame for that method.

A stack frame generally contains:
- Local primitive variables.
- Local reference variables.
- Intermediate calculations and method-related information.
- Information needed to return from the method.

When a method finishes execution, its stack frame is removed.

### Example

```java
public class StackDemo {

    public static void main(String[] args) {

        int a = 10;
        int b = 20;

        int result = add(a, b);

        System.out.println(result);

    }

    static int add(int x, int y) {

        int sum = x + y;

        return sum;

    }

}
```

### Output

```text
30
```

### Understanding Stack Memory

When `main()` executes:

```java
int a = 10;
int b = 20;
```

The local variables are associated with the `main()` method's stack frame.

When `add()` is called:

```java
add(a, b);
```

A new stack frame is created for `add()`.

The parameters `x` and `y` receive copies of the argument values.

After the method returns, the `add()` stack frame is removed.

### Stack Memory Diagram

```text
          STACK MEMORY
       -------------------
       |                 |
       |   add() frame   |
       |-----------------|
       | x = 10          |
       | y = 20          |
       | sum = 30        |
       |-----------------|
       |                 |
       |   main() frame  |
       |-----------------|
       | a = 10          |
       | b = 20          |
       | result = 30     |
       |                 |
       -------------------
```

The diagram is conceptual. Actual JVM stack-frame layout is implementation-dependent.

## 1.2 Heap Memory

Heap memory is the runtime memory area where Java objects and arrays are allocated.

Whenever we create an object using the `new` keyword, memory for that object is allocated from the heap.

### Example

```java
class Student {

    int rollNo;
    String name;

}

public class HeapDemo {

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.rollNo = 101;
        s1.name = "Anurag";

        System.out.println(s1.rollNo);
        System.out.println(s1.name);

    }

}
```

### Output

```text
101
Anurag
```

### Understanding Heap Memory

```java
Student s1 = new Student();
```

- `new Student()` creates a Student object in heap memory.
- `s1` is a local reference variable associated with the `main()` stack frame.
- `s1` holds a reference to the object.

### Heap and Stack Diagram

```text
             STACK MEMORY
        -----------------------
        |                     |
        |     main() frame    |
        |---------------------|
        | s1                  |--------+
        |                     |        |
        -----------------------        |
                                       |
                                       v
                                  HEAP MEMORY
                             -------------------
                             |                 |
                             |  Student Object |
                             |-----------------|
                             | rollNo = 101    |
                             | name = "Anurag" |
                             |                 |
                             -------------------
```

**Important:** The object is stored in the heap, while the local reference variable is part of the method's stack frame in this conceptual example.

## 1.3 Difference Between Stack and Heap Memory

| Stack Memory | Heap Memory |
|---|---|
| Manages method execution. | Stores objects and arrays. |
| Contains stack frames. | Contains dynamically allocated objects. |
| Stores local variables and references as part of frames. | Stores instance data of objects. |
| Method frame is removed when execution returns. | Objects remain until they become eligible for garbage collection and are reclaimed. |
| Each thread has its own JVM stack. | Heap is shared among threads. |
| Stack size is limited. | Heap size is managed by the JVM and configured within available limits. |

## 1.4 Garbage Collection

Garbage Collection (GC) is the automatic memory management mechanism provided by Java.

It identifies objects that are no longer reachable and may reclaim their memory.

### Example

```java
class Student {

    int rollNo;

}

public class GCDemo {

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.rollNo = 101;

        s1 = null;

    }

}
```

Initially, `s1` refers to a Student object.

After:

```java
s1 = null;
```

The reference variable no longer points to that object.

If no other references to the object exist, it becomes eligible for garbage collection.

### Important Points

1. Java provides automatic garbage collection.
2. We cannot directly delete an object using a `delete` keyword.
3. An object becomes eligible for GC when it is no longer reachable.
4. Setting a reference to `null` does not guarantee immediate garbage collection.
5. `System.gc()` only requests garbage collection; it does not guarantee that it will happen immediately.

---

# 2. Constructors in Java

## 2.1 What is a Constructor?

A constructor is a special member of a class used to initialize newly created objects.

It is automatically invoked when an object is created using `new`.

### Important Characteristics

1. Constructor name must be the same as the class name.
2. A constructor does not have a return type, not even `void`.
3. It is called automatically during object creation.
4. It can accept parameters.
5. Constructors can be overloaded.
6. Constructors are not inherited.
7. Constructors cannot be declared `static`, `final`, or `abstract`.

### Syntax

```java
class Student {

    Student() {

        // Constructor body

    }

}
```

## 2.2 Types of Constructors

Commonly discussed constructor types include:

1. Default constructor provided by the compiler.
2. No-argument constructor written by the programmer.
3. Parameterized constructor.

### A. Default Constructor

If a class does not declare any constructor, the Java compiler provides a default no-argument constructor.

Example:

```java
class Student {

    int rollNo;
    String name;

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();

        System.out.println(s1.rollNo);
        System.out.println(s1.name);

    }

}
```

Output:

```text
0
null
```

The compiler-generated constructor initializes instance fields to their default values.

**Important:** If we declare any constructor ourselves, the compiler does not automatically provide the default constructor.

### B. No-Argument Constructor

A no-argument constructor is explicitly written by the programmer without parameters.

```java
class Student {

    int rollNo;
    String name;

    Student() {

        rollNo = 101;
        name = "Anurag";

    }

    void display() {

        System.out.println(rollNo);
        System.out.println(name);

    }

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.display();

    }

}
```

Output:

```text
101
Anurag
```

### C. Parameterized Constructor

A parameterized constructor accepts values as arguments to initialize an object.

```java
class Student {

    int rollNo;
    String name;

    Student(int r, String n) {

        rollNo = r;
        name = n;

    }

    void display() {

        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);

    }

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student(101, "Anurag");

        Student s2 = new Student(102, "Rahul");

        s1.display();

        s2.display();

    }

}
```

Output:

```text
Roll No: 101
Name: Anurag
Roll No: 102
Name: Rahul
```

## 2.3 Using `this` Keyword in Constructors

The `this` keyword refers to the current object.

It is useful when instance variable names and constructor parameter names are the same.

### Example

```java
class Student {

    int rollNo;
    String name;

    Student(int rollNo, String name) {

        this.rollNo = rollNo;
        this.name = name;

    }

    void display() {

        System.out.println(rollNo + " " + name);

    }

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student(101, "Anurag");

        s1.display();

    }

}
```

Output:

```text
101 Anurag
```

### Explanation

```java
this.rollNo = rollNo;
```

- `this.rollNo` refers to the instance variable.
- `rollNo` refers to the constructor parameter.

## 2.4 Constructor Overloading

Constructor overloading means defining multiple constructors in the same class with different parameter lists.

### Example

```java
class Student {

    int rollNo;
    String name;

    Student() {

        rollNo = 0;
        name = "Unknown";

    }

    Student(int rollNo) {

        this.rollNo = rollNo;
        name = "Not Assigned";

    }

    Student(int rollNo, String name) {

        this.rollNo = rollNo;
        this.name = name;

    }

    void display() {

        System.out.println(rollNo + " " + name);

    }

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();

        Student s2 = new Student(101);

        Student s3 = new Student(102, "Anurag");

        s1.display();
        s2.display();
        s3.display();

    }

}
```

Output:

```text
0 Unknown
101 Not Assigned
102 Anurag
```

## 2.5 Constructor Chaining

Constructor chaining means calling one constructor from another constructor.

Java provides:

- `this()` – Calls another constructor of the same class.
- `super()` – Calls a constructor of the parent class.

### Example using `this()`

```java
class Student {

    int rollNo;
    String name;

    Student() {

        this(101, "Anurag");

    }

    Student(int rollNo, String name) {

        this.rollNo = rollNo;
        this.name = name;

    }

    void display() {

        System.out.println(rollNo + " " + name);

    }

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.display();

    }

}
```

Output:

```text
101 Anurag
```

**Important:** A call to `this()` or `super()` must be the first statement in a constructor in Java 17.

---

# 3. Initializing Reference Variables Using Constructors

A constructor can initialize reference variables along with primitive instance variables.

This is useful when one object needs to maintain a reference to another object.

### Example

```java
class Address {

    String city;
    String state;

    Address(String city, String state) {

        this.city = city;
        this.state = state;

    }

}

class Student {

    int rollNo;
    String name;

    Address address;

    Student(int rollNo, String name, Address address) {

        this.rollNo = rollNo;
        this.name = name;
        this.address = address;

    }

    void display() {

        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("City: " + address.city);
        System.out.println("State: " + address.state);

    }

}

public class Main {

    public static void main(String[] args) {

        Address a1 = new Address("Pune", "Maharashtra");

        Student s1 = new Student(101, "Anurag", a1);

        s1.display();

    }

}
```

Output:

```text
Roll No: 101
Name: Anurag
City: Pune
State: Maharashtra
```

### Explanation

```java
Address a1 = new Address("Pune", "Maharashtra");
```

Creates an Address object.

```java
Student s1 = new Student(101, "Anurag", a1);
```

Passes the Address reference to the Student constructor.

```java
this.address = address;
```

Stores the received reference in the Student object's `address` instance variable.

### Memory Concept

```text
STACK MEMORY                   HEAP MEMORY

main()
----------------              ---------------------
a1 --------------------------> | Address Object     |
                              | city = Pune        |
                              | state = Maharashtra|
                              ---------------------

s1 --------------------------> | Student Object     |
                              | rollNo = 101       |
                              | name = Anurag      |
                              | address -----------|----+
                              ---------------------     |
                                                        |
                                                        +--> Address Object
```

Both `a1` and `s1.address` refer to the same Address object.

---

# 4. Pass by Value vs Pass by Reference

## 4.1 What is Pass by Value?

Pass by value means a copy of the argument's value is passed to a method.

Java is always **pass by value**.

This applies to both primitive values and object references.

## 4.2 Primitive Data Type Example

```java
public class Main {

    static void change(int x) {

        x = 100;

    }

    public static void main(String[] args) {

        int a = 10;

        change(a);

        System.out.println(a);

    }

}
```

Output:

```text
10
```

### Explanation

- `a` contains 10.
- The method receives a copy of 10 in `x`.
- Changing `x` does not change `a`.

## 4.3 Passing an Object Reference to a Method

When an object reference is passed to a method, Java copies the reference value.

Both the original reference and the parameter can refer to the same object.

Therefore, changes to the object's fields through the parameter are visible through the original reference.

### Example

```java
class Student {

    int rollNo;

}

public class Main {

    static void change(Student s) {

        s.rollNo = 200;

    }

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.rollNo = 101;

        change(s1);

        System.out.println(s1.rollNo);

    }

}
```

Output:

```text
200
```

### Explanation

- `s1` refers to a Student object.
- The method receives a copy of the reference in parameter `s`.
- Both references point to the same object.
- Changing `s.rollNo` changes the object's field.
- The change is visible through `s1`.

### Diagram

```text
       Original Reference
       s1 ------------------+
                            |
                            v
                       Student Object
                       rollNo = 200
                            ^
                            |
       Method Parameter     |
       s  ------------------+
```

## 4.4 Reassigning the Method Parameter

Consider the following example:

```java
class Student {

    int rollNo;

}

public class Main {

    static void change(Student s) {

        s = new Student();

        s.rollNo = 500;

    }

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.rollNo = 101;

        change(s1);

        System.out.println(s1.rollNo);

    }

}
```

Output:

```text
101
```

### Why is the output 101?

The method receives a copy of the reference.

When we execute:

```java
s = new Student();
```

Only the local parameter `s` is changed to refer to a new object.

The original reference `s1` still points to the original Student object.

### Important Conclusion

Java does not support pass by reference for method arguments.

It always passes a copy of the value:
- Primitive argument: copy of primitive value.
- Reference argument: copy of object reference.

---

# 5. Reassigning a Reference Variable

## What is Reference Reassignment?

Reference reassignment means changing a reference variable so that it refers to another object.

### Example

```java
class Student {

    int rollNo;

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.rollNo = 101;

        Student s2 = new Student();

        s2.rollNo = 102;

        System.out.println("Before reassignment:");

        System.out.println(s1.rollNo);
        System.out.println(s2.rollNo);

        s1 = s2;

        System.out.println("After reassignment:");

        System.out.println(s1.rollNo);
        System.out.println(s2.rollNo);

    }

}
```

Output:

```text
Before reassignment:
101
102

After reassignment:
102
102
```

### Explanation

Initially:

```text
s1 ----------> Student Object 1
               rollNo = 101

s2 ----------> Student Object 2
               rollNo = 102
```

After:

```java
s1 = s2;
```

Both references point to the second object.

```text
s1 -----------+
              |
              v
         Student Object 2
         rollNo = 102
              ^
              |
s2 -----------+
```

The first Student object is no longer reachable through these references. If no other references point to it, it becomes eligible for garbage collection.

### Important Points

- Reassignment does not copy the object's fields.
- Reassignment changes which object the reference points to.
- Multiple reference variables can point to the same object.
- An object with no reachable references may become eligible for GC.

---

# 6. Passing Reference Variables to Methods

A reference variable can be passed as an argument to a method.

The receiving method can use the reference to access or modify the object's fields and call its methods.

### Example

```java
class Employee {

    int empId;
    String name;

    Employee(int empId, String name) {

        this.empId = empId;
        this.name = name;

    }

}

public class Main {

    static void display(Employee e) {

        System.out.println("Employee ID: " + e.empId);

        System.out.println("Employee Name: " + e.name);

    }

    public static void main(String[] args) {

        Employee e1 = new Employee(101, "Anurag");

        display(e1);

    }

}
```

Output:

```text
Employee ID: 101
Employee Name: Anurag
```

### Passing a Reference and Modifying the Object

```java
class Employee {

    int salary;

}

public class Main {

    static void increaseSalary(Employee e) {

        e.salary = e.salary + 5000;

    }

    public static void main(String[] args) {

        Employee e1 = new Employee();

        e1.salary = 25000;

        increaseSalary(e1);

        System.out.println(e1.salary);

    }

}
```

Output:

```text
30000
```

### Passing Reference vs Returning Reference

A method can also return an object reference.

```java
class Student {

    int rollNo;

}

public class Main {

    static Student createStudent() {

        Student s = new Student();

        s.rollNo = 101;

        return s;

    }

    public static void main(String[] args) {

        Student s1 = createStudent();

        System.out.println(s1.rollNo);

    }

}
```

Output:

```text
101
```

---

# 7. Initializing Reference Variables of Different Classes

In Java, a reference variable of one class can refer to an object of another class when the type relationship permits it.

Important cases include:

1. Association between classes.
2. Inheritance.
3. Interface implementation.

## 7.1 Association Between Classes

Association means one class maintains a reference to another class.

Example: A Student has an Address.

```java
class Address {

    String city;

    Address(String city) {

        this.city = city;

    }

}

class Student {

    String name;
    Address address;

    Student(String name, Address address) {

        this.name = name;
        this.address = address;

    }

    void display() {

        System.out.println(name);
        System.out.println(address.city);

    }

}

public class Main {

    public static void main(String[] args) {

        Address a1 = new Address("Pune");

        Student s1 = new Student("Anurag", a1);

        s1.display();

    }

}
```

Output:

```text
Anurag
Pune
```

## 7.2 Parent Class Reference and Child Class Object

Java supports assigning a child class object to a parent class reference.

This is called **upcasting**.

### Example

```java
class Animal {

    void sound() {

        System.out.println("Animal makes sound");

    }

}

class Dog extends Animal {

    void bark() {

        System.out.println("Dog barks");

    }

}

public class Main {

    public static void main(String[] args) {

        Animal a = new Dog();

        a.sound();

    }

}
```

Output:

```text
Animal makes sound
```

Here:

```java
Animal a = new Dog();
```

- `Animal` is the reference type.
- `Dog` is the actual object type.
- This assignment is valid because Dog extends Animal.

The parent reference can directly access only members available through the parent type. Overridden instance methods use runtime polymorphism.

To access a child-specific method, an appropriate downcast is required.

## 7.3 Interface Reference and Implementing Class Object

An interface reference can refer to an object of a class that implements that interface.

### Example

```java
interface Printable {

    void print();

}

class Document implements Printable {

    public void print() {

        System.out.println("Printing document");

    }

}

public class Main {

    public static void main(String[] args) {

        Printable p = new Document();

        p.print();

    }

}
```

Output:

```text
Printing document
```

### Remember

```java
Animal a = new Dog();
```

```java
Printable p = new Document();
```

Both are examples of programming using a general reference type.

---

# 8. Records in Java

## 8.1 What is a Record?

A record is a special kind of class introduced in Java 16 to represent data-focused objects with less boilerplate code.

Records are useful when we want to store data in an object without writing repetitive code for constructors, getters, `equals()`, `hashCode()`, and `toString()`.

Records are implicitly final and their component fields are final.

### Syntax

```java
record RecordName(DataType field1, DataType field2) {
}
```

### Example

```java
record Student(int rollNo, String name) {
}
```

This defines a Student record with two components:
- `rollNo`
- `name`

### Creating a Record Object

```java
public class Main {

    public static void main(String[] args) {

        Student s1 = new Student(101, "Anurag");

        System.out.println(s1.rollNo());
        System.out.println(s1.name());

    }

}
```

Output:

```text
101
Anurag
```

Notice that record accessors use the component name as the method name:

```java
s1.rollNo();
s1.name();
```

They are not conventional JavaBean getters like `getRollNo()`.

## 8.2 Features of Records

1. Records are designed to represent data.
2. Record classes are implicitly final.
3. Record components become private final fields.
4. The compiler provides a canonical constructor.
5. Accessor methods are generated automatically.
6. `equals()` is generated automatically.
7. `hashCode()` is generated automatically.
8. `toString()` is generated automatically.
9. Records cannot extend another class.
10. Records can implement interfaces.
11. Records can contain static fields and methods.
12. Records cannot declare additional instance fields.

## 8.3 Normal Class vs Record

### Normal Class

```java
class Student {

    private int rollNo;
    private String name;

    Student(int rollNo, String name) {

        this.rollNo = rollNo;
        this.name = name;

    }

    public int getRollNo() {

        return rollNo;

    }

    public String getName() {

        return name;

    }

}
```

### Record

```java
record Student(int rollNo, String name) {
}
```

The record version requires much less code.

### Comparison

| Normal Class | Record |
|---|---|
| Can be mutable or immutable. | Components are final. |
| Constructor is normally written manually. | Canonical constructor is generated automatically if not declared. |
| Getters must be written manually if required. | Component accessors are generated. |
| `equals()` may need overriding. | Value-based `equals()` is generated. |
| `hashCode()` may need overriding. | `hashCode()` is generated. |
| `toString()` may need overriding. | `toString()` is generated. |
| Can extend another class. | Cannot extend another class. |
| Can declare additional instance fields. | Cannot declare additional instance fields. |

## 8.4 Immutable Nature of Records

Records are shallowly immutable.

Their component fields cannot be reassigned after construction.

### Example

```java
record Student(int rollNo, String name) {
}
```

This is not allowed:

```java
Student s1 = new Student(101, "Anurag");

// s1.rollNo = 200; // Compilation error
```

However, the reference variable itself can be reassigned:

```java
Student s1 = new Student(101, "Anurag");

s1 = new Student(102, "Rahul");
```

This is valid because we are changing the reference variable, not modifying the original record's fields.

**Important:** A record containing a mutable object is not automatically deeply immutable.

For example:

```java
record Team(java.util.List<String> members) {
}
```

The `members` component reference is final, but the list itself may still be modified unless defensive copying or an immutable collection is used.

## 8.5 Custom Constructor in a Record

A record can contain a compact canonical constructor to validate component values.

### Example

```java
record Student(int rollNo, String name) {

    Student {

        if (rollNo <= 0) {

            throw new IllegalArgumentException(
                "Roll number must be positive"
            );

        }

        if (name == null || name.isBlank()) {

            throw new IllegalArgumentException(
                "Name cannot be empty"
            );

        }

    }

}
```

### Main Class

```java
public class Main {

    public static void main(String[] args) {

        Student s1 = new Student(101, "Anurag");

        System.out.println(s1);

    }

}
```

Output:

```text
Student[rollNo=101, name=Anurag]
```

The compact constructor validates the values before the record components are assigned.

## 8.6 Records with Methods

Records can also contain methods.

```java
record Rectangle(double length, double breadth) {

    double area() {

        return length * breadth;

    }

}

public class Main {

    public static void main(String[] args) {

        Rectangle r1 = new Rectangle(10, 5);

        System.out.println("Area: " + r1.area());

    }

}
```

Output:

```text
Area: 50.0
```

## 8.7 Records and Java Versions

| Java Version | Feature |
|---|---|
| Java 14 | Records introduced as preview feature. |
| Java 15 | Second preview. |
| Java 16 | Records became a permanent feature. |
| Java 17 | Records are fully supported. |

For CMCE, you can practice records using Java 17.

---

# 9. Lab: Student Management System

## Problem Statement

Design a simple Student Management System using:

- Classes and constructors.
- Object references.
- Association between classes.
- Records for storing immutable student details.

## 9.1 Application Design

We will create three main components:

| Component | Responsibility |
|---|---|
| `StudentDetails` Record | Stores immutable student information. |
| `Address` Class | Stores student address information. |
| `Student` Class | Maintains a reference to student details and address. |

The application will create multiple students and display their information.

## 9.2 Class Relationship

```text
             StudentManagementApp
                       |
                       |
                       v
                   Student
              -----------------
              - details
              - address
              -----------------
                 /       \
                /         \
               v           v
        StudentDetails    Address
           (Record)       (Class)
        -------------   -------------
        rollNo          city
        name            state
        course          pincode
        -------------   -------------
```

The Student class has references to both StudentDetails and Address objects.

This is an example of association.

## 9.3 Complete Program

**StudentManagementApp.java**

```java
import java.util.ArrayList;
import java.util.List;

// Record for immutable student details
record StudentDetails(
    int rollNo,
    String name,
    String course
) {

    StudentDetails {

        if (rollNo <= 0) {

            throw new IllegalArgumentException(
                "Roll number must be positive"
            );

        }

        if (name == null || name.isBlank()) {

            throw new IllegalArgumentException(
                "Name cannot be empty"
            );

        }

        if (course == null || course.isBlank()) {

            throw new IllegalArgumentException(
                "Course cannot be empty"
            );

        }

    }

}

// Address class
class Address {

    private String city;
    private String state;
    private int pincode;

    Address(String city, String state, int pincode) {

        this.city = city;
        this.state = state;
        this.pincode = pincode;

    }

    void displayAddress() {

        System.out.println("City: " + city);
        System.out.println("State: " + state);
        System.out.println("Pincode: " + pincode);

    }

}

// Student class
class Student {

    private StudentDetails details;
    private Address address;

    Student(StudentDetails details, Address address) {

        this.details = details;
        this.address = address;

    }

    void displayStudent() {

        System.out.println("Roll Number: " + details.rollNo());

        System.out.println("Name: " + details.name());

        System.out.println("Course: " + details.course());

        address.displayAddress();

    }

}

// Main application class
public class StudentManagementApp {

    public static void main(String[] args) {

        List<Student> students = new ArrayList<>();

        // Creating Student 1 details using record
        StudentDetails details1 =
            new StudentDetails(101, "Anurag", "PGCP-AC");

        // Creating Student 1 address
        Address address1 =
            new Address("Pune", "Maharashtra", 411001);

        // Creating Student 1 object
        Student s1 = new Student(details1, address1);

        // Creating Student 2 details
        StudentDetails details2 =
            new StudentDetails(102, "Rahul", "PGCP-AC");

        // Creating Student 2 address
        Address address2 =
            new Address("Mumbai", "Maharashtra", 400001);

        // Creating Student 2 object
        Student s2 = new Student(details2, address2);

        // Adding students to collection
        students.add(s1);
        students.add(s2);

        // Display all student records
        System.out.println("===== STUDENT MANAGEMENT SYSTEM =====");

        for (Student student : students) {

            System.out.println();

            student.displayStudent();

            System.out.println("-------------------------");

        }

    }

}
```

## 9.4 Expected Output

```text
===== STUDENT MANAGEMENT SYSTEM =====

Roll Number: 101
Name: Anurag
Course: PGCP-AC
City: Pune
State: Maharashtra
Pincode: 411001
-------------------------

Roll Number: 102
Name: Rahul
Course: PGCP-AC
City: Mumbai
State: Maharashtra
Pincode: 400001
-------------------------
```

## 9.5 Explanation of the Application

### Step 1: Create StudentDetails Record

```java
record StudentDetails(
    int rollNo,
    String name,
    String course
) {
}
```

The record stores student details.

It automatically provides:
- Constructor.
- Accessor methods.
- `equals()`.
- `hashCode()`.
- `toString()`.

Its components are final.

### Step 2: Create Address Class

```java
class Address {

    private String city;
    private String state;
    private int pincode;

}
```

The Address class stores address information.

### Step 3: Create Student Class

```java
class Student {

    private StudentDetails details;
    private Address address;

}
```

The Student class contains two reference variables:

- `details` refers to a StudentDetails record object.
- `address` refers to an Address object.

### Step 4: Initialize References Using Constructor

```java
Student(StudentDetails details, Address address) {

    this.details = details;
    this.address = address;

}
```

The constructor receives two object references and stores them in the Student object.

### Step 5: Create Objects

```java
StudentDetails details1 =
    new StudentDetails(101, "Anurag", "PGCP-AC");

Address address1 =
    new Address("Pune", "Maharashtra", 411001);

Student s1 = new Student(details1, address1);
```

Three objects are involved:

1. StudentDetails record object.
2. Address object.
3. Student object.

The Student object maintains references to the other two.

### Step 6: Store Student Objects

```java
List<Student> students = new ArrayList<>();

students.add(s1);
students.add(s2);
```

The ArrayList stores references to Student objects.

### Step 7: Display Details

```java
for (Student student : students) {

    student.displayStudent();

}
```

The enhanced for loop iterates through the Student references and displays their details.

## 9.6 Memory Representation of the Application

```text
                    STACK MEMORY
              -----------------------
              |                     |
              | main()               |
              |---------------------|
              | students            |------------------+
              | details1            |------+           |
              | address1            |---+  |           |
              | s1                  |--+|  |           |
              |                     |  ||  |           |
              -----------------------  ||  |           |
                                       ||  |           |
                    HEAP MEMORY        ||  |           |
                                       vv  vv           v
                              ------------------  -------------
                              | Student Object 1|  | ArrayList |
                              |-----------------|  |-----------|
                              | details --------|->| s1 ref    |
                              | address --------|->| s2 ref    |
                              ------------------  -------------
                                      |
                                      |
                        +-------------+-------------+
                        |                           |
                        v                           v
               -------------------          -------------------
               | StudentDetails  |          | Address Object   |
               | Record Object   |          |------------------|
               |-----------------|          | city = Pune      |
               | rollNo = 101    |          | state = MH       |
               | name = Anurag    |          | pincode = 411001 |
               | course = PGCP-AC|          -------------------
               -------------------
```

*Conceptual illustration: the actual JVM memory layout is implementation-dependent.*

## 9.7 How to Compile and Run

Java 17 or later is required because records became a permanent feature in Java 16.

Open the terminal in the directory containing `StudentManagementApp.java`.

Compile:

```bash
javac StudentManagementApp.java
```

Run:

```bash
java StudentManagementApp
```

---

# 10. Important Interview Questions

### Q1. What is heap memory?

Heap memory is the JVM runtime memory area where objects and arrays are allocated.

### Q2. What is stack memory?

Stack memory manages method execution using stack frames containing local variables and method-related information.

### Q3. What is the difference between heap and stack?

Heap stores objects and arrays, whereas stack manages method calls and their local execution data.

### Q4. What is garbage collection?

Garbage collection is Java's automatic mechanism for reclaiming memory occupied by objects that are no longer reachable.

### Q5. What is a constructor?

A constructor is a special class member used to initialize an object when it is created.

### Q6. What is a default constructor?

A default constructor is a no-argument constructor provided by the compiler when no constructor is explicitly declared.

### Q7. What is a parameterized constructor?

A constructor that accepts parameters to initialize object variables.

### Q8. What is constructor overloading?

Defining multiple constructors in the same class with different parameter lists.

### Q9. What is constructor chaining?

Calling one constructor from another using `this()` or `super()`.

### Q10. What is the purpose of `this`?

It refers to the current object.

### Q11. Is Java pass by value or pass by reference?

Java is always pass by value.

### Q12. What happens when an object reference is passed to a method?

A copy of the reference value is passed. The parameter can access and modify the same object, but reassigning the parameter does not reassign the caller's reference.

### Q13. Can two reference variables point to the same object?

Yes. Multiple references can refer to the same object.

### Q14. What is reference reassignment?

Changing a reference variable so that it refers to another object.

### Q15. What is association?

Association is a relationship between two classes in which one class maintains a reference to an object of another class.

### Q16. What is a record in Java?

A record is a special class designed to represent data-focused objects with automatically generated methods.

### Q17. In which Java version were records finalized?

Java 16.

### Q18. Are records immutable?

Record component fields are final, but records are only shallowly immutable. Mutable objects referenced by their components may still be changed.

### Q19. Can a record extend another class?

No. A record implicitly extends `java.lang.Record` and cannot extend another class.

### Q20. Can records implement interfaces?

Yes.

### Q21. Can records have methods?

Yes. Records can contain instance methods, static methods, and constructors.

### Q22. Can we create an object of a record?

Yes, using its constructor.

### Q23. What is upcasting?

Assigning a child-class object to a parent-class reference.

### Q24. Can a method return an object reference?

Yes. A method can return a reference to an object.

### Q25. Does assigning `null` immediately destroy an object?

No. It only removes that reference. The object becomes eligible for garbage collection only if it is no longer reachable through any reference.

---

# 11. Multiple Choice Questions

### Q1. Which memory area stores Java objects?

A. Stack  
B. Heap  
C. Register  
D. Program Counter  

**Answer: B. Heap**

### Q2. Which memory area manages method execution?

A. Heap  
B. Stack  
C. Cache  
D. ROM  

**Answer: B. Stack**

### Q3. When is an object created in Java?

A. When a class is declared  
B. When a reference variable is declared  
C. When an object is instantiated  
D. When a method is declared  

**Answer: C. When an object is instantiated**

### Q4. Which keyword is commonly used to create an object?

A. class  
B. static  
C. new  
D. this  

**Answer: C. new**

### Q5. What is the return type of a constructor?

A. void  
B. int  
C. Object  
D. No return type  

**Answer: D. No return type**

### Q6. Which constructor is provided automatically if no constructor is declared?

A. Parameterized constructor  
B. Default constructor  
C. Copy constructor  
D. Static constructor  

**Answer: B. Default constructor**

### Q7. Which keyword refers to the current object?

A. super  
B. static  
C. this  
D. final  

**Answer: C. this**

### Q8. Java supports:

A. Pass by reference only  
B. Pass by value only  
C. Both pass by value and pass by reference  
D. Neither  

**Answer: B. Pass by value only**

### Q9. What happens when a reference variable is reassigned?

A. The original object is copied.  
B. The reference points to another object.  
C. All object data is deleted.  
D. The class is destroyed.  

**Answer: B. The reference points to another object.**

### Q10. Which method is used to access record components?

A. getRollNo()  
B. setRollNo()  
C. rollNo()  
D. displayRollNo()  

**Answer: C. rollNo()**

### Q11. Records became a permanent feature in:

A. Java 8  
B. Java 11  
C. Java 16  
D. Java 21  

**Answer: C. Java 16**

### Q12. A record is implicitly:

A. Abstract  
B. Final  
C. Static  
D. Interface  

**Answer: B. Final**

### Q13. Can a record extend another user-defined class?

A. Yes  
B. No  
C. Only abstract classes  
D. Only final classes  

**Answer: B. No**

### Q14. What happens when two references point to the same object?

A. Two copies of the object are created.  
B. Both references access the same object.  
C. The object becomes null.  
D. Compilation fails.  

**Answer: B. Both references access the same object.**

### Q15. What does `System.gc()` do?

A. Guarantees immediate garbage collection.  
B. Requests garbage collection.  
C. Deletes all objects.  
D. Clears stack memory.  

**Answer: B. Requests garbage collection.**

---

# 12. Quick Revision Notes

## Memory Management

| Concept | Meaning |
|---|---|
| Stack | Manages method execution and stack frames. |
| Heap | Stores objects and arrays. |
| Garbage Collection | Reclaims memory of unreachable objects. |
| `new` | Allocates a new object or array. |
| `null` | Reference does not point to an object. |

## Constructors

| Concept | Meaning |
|---|---|
| Constructor | Initializes a newly created object. |
| Default constructor | Compiler-provided when no constructor is declared. |
| No-argument constructor | Programmer-defined constructor without parameters. |
| Parameterized constructor | Accepts arguments. |
| `this()` | Calls another constructor in the same class. |
| `super()` | Calls a parent-class constructor. |
| Constructor overloading | Multiple constructors with different parameters. |

## Reference Variables

| Concept | Meaning |
|---|---|
| Reference variable | Holds an object reference. |
| Reassignment | Changes the object referred to by a reference. |
| Passing reference | Passes a copy of the reference value. |
| Association | One class maintains a reference to another class. |
| Upcasting | Child object assigned to parent reference. |

## Records

| Concept | Meaning |
|---|---|
| Record | Data-focused special class. |
| Introduced | Java 14 preview. |
| Finalized | Java 16. |
| Components | Private final fields. |
| Accessors | Generated methods with component names. |
| `equals()` | Generated value-based equality. |
| `hashCode()` | Generated hash code. |
| `toString()` | Generated string representation. |
| Immutability | Shallowly immutable. |

---

# 13. Practice Checklist

- [ ] Understand heap memory.
- [ ] Understand stack memory.
- [ ] Understand garbage collection.
- [ ] Understand default and parameterized constructors.
- [ ] Practice constructor overloading.
- [ ] Practice constructor chaining using `this()`.
- [ ] Initialize reference variables through constructors.
- [ ] Understand pass by value in Java.
- [ ] Understand object references passed to methods.
- [ ] Practice reference reassignment.
- [ ] Understand association between classes.
- [ ] Practice parent and child class references.
- [ ] Understand Java records.
- [ ] Create records with custom validation.
- [ ] Complete the Student Management System practical.
- [ ] Practice MCQs and interview questions.

## Additional Self-Learning Assignments

1. **Employee Management System:** Create Employee and Department classes. An Employee should maintain a reference to a Department object.

2. **Library Management System:** Create Book and Library classes. Use constructors to initialize book details and library information.

3. **Banking Application:** Create Account and Customer classes. Pass Customer references to Account constructors.

4. **Product Record:** Create a `Product` record containing `productId`, `productName`, and `price`. Add validation for positive prices.

5. **Course Registration:** Create a `Course` record and a `Student` class that maintains a reference to a Course object.

6. **Reference Experiment:** Create two objects, assign one reference to another, modify the object, and observe the result.

---

**End of Session 6 – Object Creation, Memory Management and Records**

Happy Learning! 🚀
