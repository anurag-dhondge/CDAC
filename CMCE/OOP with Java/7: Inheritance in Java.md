# Session 7: Inheritance in Java

**Course:** CMCE – August 2026 Batch  
**Subject:** Java Programming  
**Session:** 7  
**Duration:** 2 Theory + 2 Lab + 2 Self-Learning Hours

---

## 📚 Table of Contents

1. [Introduction to Inheritance](#1-introduction-to-inheritance)
2. [Types of Inheritance](#2-types-of-inheritance)
   - Single Inheritance
   - Multilevel Inheritance
   - Hierarchical Inheritance
3. [Association, Aggregation and Composition](#3-association-aggregation-and-composition)
4. [Polymorphism](#4-polymorphism)
5. [Method Overloading](#5-method-overloading)
6. [Method Overriding](#6-method-overriding)
7. [Rules of Overloading and Overriding](#7-rules-of-overloading-and-overriding)
8. [`this` and `super` Keywords](#8-this-and-super-keywords)
9. [Lab: Employee Management System](#9-lab-employee-management-system)
10. [Important Interview Questions](#10-important-interview-questions)
11. [MCQs](#11-multiple-choice-questions)
12. [Quick Revision Notes](#12-quick-revision-notes)

---

# 1. Introduction to Inheritance

## 1.1 What is Inheritance?

Inheritance is one of the four fundamental principles of Object-Oriented Programming (OOP).

It is a mechanism in Java through which one class acquires the properties and behaviors of another class.

In simple words, inheritance allows us to reuse the existing code of one class in another class.

### Real-Life Example

Consider the following relationship:

- A Person has a name and age.
- An Employee is a Person and additionally has an employee ID and salary.
- A Manager is an Employee and additionally has a department and team size.

Instead of writing the common properties again and again, we can create a parent class called `Person`.

```text
                 Person
              ------------
              name
              age
              ------------
                  |
                  |
                  v
               Employee
              ------------
              employeeId
              salary
              ------------
                  |
                  |
                  v
                Manager
              ------------
              department
              teamSize
              ------------
```

### Important Terminology

| Term | Meaning |
|---|---|
| Parent Class | The class whose properties and methods are inherited. |
| Child Class | The class that inherits from another class. |
| Superclass | Another name for parent class. |
| Subclass | Another name for child class. |
| `extends` | Keyword used for class inheritance. |

### Syntax

```java
class Parent {

    // Variables and methods

}

class Child extends Parent {

    // Additional variables and methods

}
```

## 1.2 Simple Inheritance Example

```java
class Animal {

    void eat() {

        System.out.println("Animal is eating");

    }

}

class Dog extends Animal {

    void bark() {

        System.out.println("Dog is barking");

    }

}

public class Main {

    public static void main(String[] args) {

        Dog d1 = new Dog();

        d1.eat();

        d1.bark();

    }

}
```

### Output

```text
Animal is eating
Dog is barking
```

### Explanation

- `Animal` is the parent class.
- `Dog` is the child class.
- `Dog extends Animal` means Dog inherits accessible members of Animal.
- The Dog object can call both `eat()` and `bark()`.

### Advantages of Inheritance

1. Code reusability.
2. Reduces code duplication.
3. Supports method overriding.
4. Helps implement runtime polymorphism.
5. Provides a natural class hierarchy.
6. Improves maintainability when relationships are designed appropriately.

### Important Points

- Java uses the `extends` keyword for class inheritance.
- A child class can inherit accessible members from its parent class.
- Constructors are not inherited.
- Private members cannot be accessed directly by a child class, although they remain part of the parent-class object state.
- Java supports single inheritance of classes.
- A class can implement multiple interfaces.

---

# 2. Types of Inheritance

The important types of inheritance in this session are:

1. Single Inheritance
2. Multilevel Inheritance
3. Hierarchical Inheritance

## 2.1 Single Inheritance

### Definition

Single inheritance occurs when one child class inherits from one parent class.

### Diagram

```text
          Parent
             |
             |
             v
          Child
```

### Example

```java
class Person {

    String name = "Anurag";

    void displayName() {

        System.out.println("Name: " + name);

    }

}

class Student extends Person {

    int rollNo = 101;

    void displayRollNo() {

        System.out.println("Roll No: " + rollNo);

    }

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.displayName();

        s1.displayRollNo();

    }

}
```

### Output

```text
Name: Anurag
Roll No: 101
```

### Explanation

- `Person` is the parent class.
- `Student` is the child class.
- Student inherits the accessible members of Person.
- Student also has its own `rollNo` variable and `displayRollNo()` method.

---

## 2.2 Multilevel Inheritance

### Definition

Multilevel inheritance occurs when a class inherits from another child class, forming a chain of inheritance.

In other words, a class inherits from a class that already inherits from another class.

### Diagram

```text
             A
             |
             v
             B
             |
             v
             C
```

Here:

- B inherits from A.
- C inherits from B.
- C can access accessible inherited members from both B and A.

### Example

```java
class Person {

    void displayPerson() {

        System.out.println("I am a Person");

    }

}

class Employee extends Person {

    void displayEmployee() {

        System.out.println("I am an Employee");

    }

}

class Manager extends Employee {

    void displayManager() {

        System.out.println("I am a Manager");

    }

}

public class Main {

    public static void main(String[] args) {

        Manager m1 = new Manager();

        m1.displayPerson();

        m1.displayEmployee();

        m1.displayManager();

    }

}
```

### Output

```text
I am a Person
I am an Employee
I am a Manager
```

### Explanation

The Manager class inherits:

- `displayEmployee()` from Employee.
- `displayPerson()` through Employee from Person.
- `displayManager()` is its own method.

This is an example of multilevel inheritance.

---

## 2.3 Hierarchical Inheritance

### Definition

Hierarchical inheritance occurs when multiple child classes inherit from the same parent class.

### Diagram

```text
                  Parent
                /   |   \
               /    |    \
              v     v     v
           Child1 Child2 Child3
```

### Example

```java
class Animal {

    void eat() {

        System.out.println("Animal eats food");

    }

}

class Dog extends Animal {

    void bark() {

        System.out.println("Dog barks");

    }

}

class Cat extends Animal {

    void meow() {

        System.out.println("Cat meows");

    }

}

class Cow extends Animal {

    void moo() {

        System.out.println("Cow moos");

    }

}

public class Main {

    public static void main(String[] args) {

        Dog d = new Dog();

        d.eat();

        d.bark();

        System.out.println();

        Cat c = new Cat();

        c.eat();

        c.meow();

        System.out.println();

        Cow cw = new Cow();

        cw.eat();

        cw.moo();

    }

}
```

### Output

```text
Animal eats food
Dog barks

Animal eats food
Cat meows

Animal eats food
Cow moos
```

### Explanation

- Dog, Cat and Cow inherit from Animal.
- All three classes can use the inherited `eat()` method.
- Each child class has its own specific behavior.

---

## 2.4 Comparison of Inheritance Types

| Type | Description | Structure |
|---|---|---|
| Single | One child inherits from one parent. | A → B |
| Multilevel | A child inherits through multiple levels. | A → B → C |
| Hierarchical | Multiple children inherit from one parent. | A → B, C, D |

### Note: Multiple Inheritance in Java

Java does not support multiple inheritance through classes.

For example, the following is invalid:

```java
class A {
}

class B {
}

// Invalid Java syntax
// class C extends A, B {
// }
```

However, Java supports multiple inheritance of type through interfaces.

```java
interface A {

    void showA();

}

interface B {

    void showB();

}

class C implements A, B {

    public void showA() {

        System.out.println("A");

    }

    public void showB() {

        System.out.println("B");

    }

}
```

---

# 3. Association, Aggregation and Composition

These concepts describe relationships between classes and objects.

They are important when designing real-world applications.

## 3.1 Association

### Definition

Association is a relationship between two independent classes where objects of one class are connected to objects of another class.

In simple words, one class knows about or uses another class.

### Real-Life Example

A Teacher teaches Students.

- Teacher is a separate entity.
- Student is a separate entity.
- A teacher can teach multiple students.
- Students can exist without a particular teacher.

### Diagram

```text
        Teacher  --------  Student
```

### Example

```java
class Student {

    String name;

    Student(String name) {

        this.name = name;

    }

}

class Teacher {

    String teacherName;

    Teacher(String teacherName) {

        this.teacherName = teacherName;

    }

    void teach(Student student) {

        System.out.println(
            teacherName + " teaches " + student.name
        );

    }

}

public class Main {

    public static void main(String[] args) {

        Teacher t1 = new Teacher("Mr. Sharma");

        Student s1 = new Student("Anurag");

        t1.teach(s1);

    }

}
```

### Output

```text
Mr. Sharma teaches Anurag
```

### Explanation

- Teacher and Student are independent classes.
- The Teacher method accepts a Student reference.
- Both objects can exist independently.

---

## 3.2 Aggregation

### Definition

Aggregation is a special type of association representing a weak HAS-A relationship.

In aggregation, one class contains a reference to another class, but the contained object can exist independently.

### Real-Life Example

Department and Employee.

- A department has employees.
- An employee can exist independently of a department.
- An employee may be transferred to another department.
- Deleting a department does not necessarily mean deleting its employees.

### Diagram

```text
        Department
             |
             |
             o
             |
             |
          Employee
```

The hollow diamond represents aggregation in UML notation.

### Example

```java
import java.util.ArrayList;
import java.util.List;

class Employee {

    int empId;
    String name;

    Employee(int empId, String name) {

        this.empId = empId;
        this.name = name;

    }

}

class Department {

    String departmentName;

    List<Employee> employees;

    Department(String departmentName, List<Employee> employees) {

        this.departmentName = departmentName;

        this.employees = employees;

    }

    void displayEmployees() {

        System.out.println(
            "Department: " + departmentName
        );

        for (Employee e : employees) {

            System.out.println(
                e.empId + " " + e.name
            );

        }

    }

}

public class Main {

    public static void main(String[] args) {

        Employee e1 = new Employee(101, "Anurag");

        Employee e2 = new Employee(102, "Rahul");

        List<Employee> employeeList = new ArrayList<>();

        employeeList.add(e1);

        employeeList.add(e2);

        Department d1 =
            new Department("AI and ML", employeeList);

        d1.displayEmployees();

    }

}
```

### Output

```text
Department: AI and ML
101 Anurag
102 Rahul
```

### Explanation

- Employee objects are created independently.
- The Department constructor receives an existing list of Employee references.
- Department stores those references.
- Employees can exist even if the Department object is no longer referenced.

This demonstrates aggregation.

---

## 3.3 Composition

### Definition

Composition is a strong form of association representing a strong HAS-A relationship.

In composition, one object owns another object as a part of its structure or lifecycle.

### Real-Life Example

Employee and Address (in a simplified ownership model).

- An Employee contains an Address.
- The Employee creates and owns its Address object.
- The Address is treated as part of the Employee in this design.

### Diagram

```text
          Employee
              |
              |
              ◆
              |
              |
            Address
```

The filled diamond represents composition in UML notation.

### Example

```java
class Address {

    String city;
    String state;

    Address(String city, String state) {

        this.city = city;

        this.state = state;

    }

    void displayAddress() {

        System.out.println("City: " + city);

        System.out.println("State: " + state);

    }

}

class Employee {

    int empId;
    String name;

    private Address address;

    Employee(int empId, String name,
             String city, String state) {

        this.empId = empId;

        this.name = name;

        // Employee creates and owns its Address
        this.address = new Address(city, state);

    }

    void displayEmployee() {

        System.out.println("Employee ID: " + empId);

        System.out.println("Name: " + name);

        address.displayAddress();

    }

}

public class Main {

    public static void main(String[] args) {

        Employee e1 =
            new Employee(101, "Anurag", "Pune", "Maharashtra");

        e1.displayEmployee();

    }

}
```

### Output

```text
Employee ID: 101
Name: Anurag
City: Pune
State: Maharashtra
```

### Explanation

```java
this.address = new Address(city, state);
```

The Employee constructor creates the Address object internally and maintains its reference.

The Address is not supplied as an independently created object in this design.

This demonstrates composition-style ownership.

**Important:** Java does not automatically destroy a contained object when the containing object is destroyed. Composition is a design relationship and lifecycle ownership convention, not a special Java memory-management feature.

---

## 3.4 Difference Between Association, Aggregation and Composition

| Feature | Association | Aggregation | Composition |
|---|---|---|---|
| Relationship | General relationship | Weak HAS-A | Strong HAS-A |
| Ownership | No specific ownership implied | Weak ownership | Strong ownership |
| Object independence | Independent | Contained object can exist independently | Part is conceptually owned by whole |
| Lifecycle | Independent | Independent | Usually tied to whole by design |
| UML symbol | Simple line | Hollow diamond | Filled diamond |
| Example | Teacher–Student | Department–Employee | Employee–Address |

### Easy Way to Remember

- Association: Teacher teaches Student.
- Aggregation: Department has Employees.
- Composition: Employee owns an Address as part of its design.

---

# 4. Polymorphism

## 4.1 What is Polymorphism?

Polymorphism is one of the four fundamental principles of OOP.

The word polymorphism means **many forms**.

In Java, polymorphism allows the same method name or common reference type to represent different behaviors depending on the situation.

### Real-Life Example

Consider a person using different payment methods:

- Cash payment.
- UPI payment.
- Card payment.

The action is the same: making a payment.

But the implementation differs.

### Types of Polymorphism

1. Compile-Time Polymorphism.
2. Runtime Polymorphism.

```text
                 Polymorphism
                      |
             -------------------
             |                 |
             v                 v
      Compile-Time         Runtime
       Polymorphism       Polymorphism
             |                 |
             v                 v
        Overloading         Overriding
```

---

## 4.2 Compile-Time Polymorphism

### Definition

Compile-time polymorphism is achieved through method overloading.

Multiple methods have the same name but different parameter lists.

The compiler determines which method to call based on the arguments.

### Example

```java
class Calculator {

    int add(int a, int b) {

        return a + b;

    }

    double add(double a, double b) {

        return a + b;

    }

    int add(int a, int b, int c) {

        return a + b + c;

    }

}

public class Main {

    public static void main(String[] args) {

        Calculator c = new Calculator();

        System.out.println(c.add(10, 20));

        System.out.println(c.add(10.5, 20.5));

        System.out.println(c.add(10, 20, 30));

    }

}
```

### Output

```text
30
31.0
60
```

### Explanation

The same method name `add()` is used with different parameter lists.

- `add(int, int)` is selected for two integers.
- `add(double, double)` is selected for two doubles.
- `add(int, int, int)` is selected for three integers.

The compiler resolves the appropriate overload.

---

## 4.3 Runtime Polymorphism

### Definition

Runtime polymorphism is achieved through method overriding.

A child class provides its own implementation of an inherited instance method.

The actual method implementation is selected at runtime based on the actual object type.

### Example

```java
class Animal {

    void sound() {

        System.out.println("Animal makes a sound");

    }

}

class Dog extends Animal {

    @Override
    void sound() {

        System.out.println("Dog barks");

    }

}

class Cat extends Animal {

    @Override
    void sound() {

        System.out.println("Cat meows");

    }

}

public class Main {

    public static void main(String[] args) {

        Animal a;

        a = new Dog();

        a.sound();

        a = new Cat();

        a.sound();

    }

}
```

### Output

```text
Dog barks
Cat meows
```

### Explanation

```java
Animal a;
```

A parent-class reference is declared.

```java
a = new Dog();
a.sound();
```

The actual object is Dog, so the overridden Dog method executes.

```java
a = new Cat();
a.sound();
```

The actual object is Cat, so the overridden Cat method executes.

### Important Concept

```java
Animal a = new Dog();
```

- Reference type: Animal.
- Actual object type: Dog.
- Overridden instance method: selected using runtime polymorphism.

### Compile-Time vs Runtime Polymorphism

| Compile-Time Polymorphism | Runtime Polymorphism |
|---|---|
| Achieved using overloading. | Achieved using overriding. |
| Same method name, different parameters. | Child class redefines inherited method. |
| Method selection is resolved at compile time. | Overridden method selection occurs at runtime. |
| Inheritance is not compulsory. | Inheritance is required for class-based overriding. |
| Also called static polymorphism. | Also called dynamic polymorphism. |

---

# 5. Method Overloading

## 5.1 What is Method Overloading?

Method overloading means defining multiple methods with the same name but different parameter lists in the same class or in an inheritance hierarchy.

### Rules

Methods can be overloaded by changing:

1. Number of parameters.
2. Data types of parameters.
3. Order of parameter types.

### Example 1: Different Number of Parameters

```java
class Calculator {

    int add(int a, int b) {

        return a + b;

    }

    int add(int a, int b, int c) {

        return a + b + c;

    }

}
```

### Example 2: Different Data Types

```java
class Calculator {

    int add(int a, int b) {

        return a + b;

    }

    double add(double a, double b) {

        return a + b;

    }

}
```

### Example 3: Different Order of Parameters

```java
class Display {

    void show(int a, String b) {

        System.out.println(a + " " + b);

    }

    void show(String a, int b) {

        System.out.println(a + " " + b);

    }

}
```

### Important: Return Type Alone Cannot Overload a Method

Invalid:

```java
class Test {

    int display() {

        return 10;

    }

    // Compilation error:
    // Same method name and same parameter list
    // double display() {
    //     return 10.5;
    // }

}
```

Changing only the return type is not sufficient to overload a method.

---

# 6. Method Overriding

## 6.1 What is Method Overriding?

Method overriding occurs when a subclass provides its own implementation of an inherited instance method with a compatible method signature.

It allows a child class to provide specialized behavior.

### Example

```java
class Person {

    void display() {

        System.out.println("Person Details");

    }

}

class Employee extends Person {

    @Override
    void display() {

        System.out.println("Employee Details");

    }

}

public class Main {

    public static void main(String[] args) {

        Employee e = new Employee();

        e.display();

    }

}
```

### Output

```text
Employee Details
```

### Explanation

- Person contains the `display()` method.
- Employee inherits Person.
- Employee overrides the `display()` method.
- When the Employee object calls `display()`, the Employee implementation executes.

## 6.2 Why Use `@Override`?

`@Override` is an annotation used to indicate that a method is intended to override a method from a superclass or implement an interface method.

Example:

```java
@Override
void display() {

    System.out.println("Employee Details");

}
```

Advantages:

1. Improves code readability.
2. Helps the compiler detect mistakes.
3. Prevents accidental method declarations that do not actually override a superclass method.

---

# 7. Rules of Overloading and Overriding

## 7.1 Method Overloading Rules

1. Method names must be the same.
2. Parameter lists must be different.
3. Return types may be the same or different.
4. Access modifiers may be different.
5. Overloading can happen in the same class.
6. Overloading does not require inheritance.
7. Changing only the return type is not sufficient.

### Example

```java
class Calculator {

    int calculate(int a, int b) {

        return a + b;

    }

    double calculate(double a, double b) {

        return a + b;

    }

    int calculate(int a, int b, int c) {

        return a + b + c;

    }

}
```

## 7.2 Method Overriding Rules

1. Inheritance is required for class-based overriding.
2. The overriding method must have a compatible signature.
3. The return type must be the same or covariant for reference return types.
4. The access level cannot be more restrictive than the overridden method.
5. A `final` method cannot be overridden.
6. A `private` method is not inherited and therefore cannot be overridden.
7. Static methods are hidden, not overridden.
8. Constructors cannot be overridden.
9. The `@Override` annotation is recommended.

### Example: Covariant Return Type

A child class can override a method and return a more specific reference type.

```java
class Animal {
}

class Dog extends Animal {
}

class Parent {

    Animal getAnimal() {

        return new Animal();

    }

}

class Child extends Parent {

    @Override
    Dog getAnimal() {

        return new Dog();

    }

}
```

Here, `Dog` is a subtype of `Animal`, so the return type is valid.

### Overloading vs Overriding

| Feature | Overloading | Overriding |
|---|---|---|
| Method name | Same | Same |
| Parameters | Different | Same compatible signature |
| Inheritance | Not required | Required for class-based overriding |
| Return type | Can differ | Same or covariant |
| Polymorphism | Compile-time | Runtime |
| Access modifier | Can differ | Cannot be more restrictive |
| Static methods | Can be overloaded | Hidden, not overridden |
| Constructors | Can be overloaded | Cannot be overridden |

---

# 8. `super` and `this` Keywords

Both `this` and `super` are important Java keywords used in inheritance and object-oriented programming.

## 8.1 `this` Keyword

### Definition

The `this` keyword refers to the current object.

### Uses of `this`

1. Access current object's instance variables.
2. Call current object's instance methods.
3. Call another constructor in the same class using `this()`.
4. Pass the current object as an argument.
5. Return the current object from a method.

### Example 1: Access Instance Variables

```java
class Student {

    int rollNo;
    String name;

    Student(int rollNo, String name) {

        this.rollNo = rollNo;

        this.name = name;

    }

}
```

### Example 2: Call Another Constructor

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

}
```

---

## 8.2 `super` Keyword

### Definition

The `super` keyword refers to the immediate parent-class part of the current object.

### Uses of `super`

1. Access parent-class variables.
2. Call parent-class methods.
3. Call parent-class constructors using `super()`.

### Example 1: Access Parent Variable

```java
class Person {

    String name = "Person";

}

class Employee extends Person {

    String name = "Employee";

    void display() {

        System.out.println(name);

        System.out.println(super.name);

    }

}

public class Main {

    public static void main(String[] args) {

        Employee e = new Employee();

        e.display();

    }

}
```

### Output

```text
Employee
Person
```

### Explanation

- `name` accesses the Employee class variable.
- `super.name` accesses the Person class variable.

### Example 2: Call Parent Method

```java
class Person {

    void display() {

        System.out.println("Person display method");

    }

}

class Employee extends Person {

    @Override
    void display() {

        super.display();

        System.out.println("Employee display method");

    }

}

public class Main {

    public static void main(String[] args) {

        Employee e = new Employee();

        e.display();

    }

}
```

### Output

```text
Person display method
Employee display method
```

### Example 3: Call Parent Constructor

```java
class Person {

    String name;

    Person(String name) {

        this.name = name;

        System.out.println("Person constructor");

    }

}

class Employee extends Person {

    int empId;

    Employee(String name, int empId) {

        super(name);

        this.empId = empId;

        System.out.println("Employee constructor");

    }

}

public class Main {

    public static void main(String[] args) {

        Employee e = new Employee("Anurag", 101);

    }

}
```

### Output

```text
Person constructor
Employee constructor
```

### Explanation

```java
super(name);
```

Calls the parent class constructor and initializes the inherited `name` field.

In Java 17, an explicit `super()` or `this()` constructor invocation must be the first statement in a constructor.

If no explicit constructor invocation is written, Java inserts an implicit no-argument `super()` when applicable.

## 8.3 Difference Between `this` and `super`

| `this` | `super` |
|---|---|
| Refers to the current object. | Refers to the immediate parent-class part of the current object. |
| Accesses current class members. | Accesses parent-class members. |
| Calls current class constructor using `this()`. | Calls parent constructor using `super()`. |
| Used to resolve current class variable conflicts. | Used to access hidden parent variables or overridden parent methods. |
| Cannot be used in a static context. | Cannot be used in a static context. |

---

# 9. Lab: Employee Management System

## Problem Statement

Design an Employee Management System with the following requirements:

1. Person → Employee → Manager hierarchy.
2. Department–Employee aggregation.
3. Address–Employee composition.
4. Overloaded methods for salary calculation.
5. Overridden methods for displaying employee details.

## 9.1 Application Design

We will create five classes:

| Class | Responsibility |
|---|---|
| Person | Stores common person information. |
| Employee | Extends Person and stores employee information. |
| Manager | Extends Employee and stores manager-specific information. |
| Department | Maintains references to employees using aggregation. |
| Address | Stores an employee's address using composition. |

### Class Hierarchy

```text
                  Person
              -------------
              name
              age
              -------------
                   |
                   v
                Employee
              -------------
              empId
              salary
              address
              -------------
                   |
                   v
                 Manager
              -------------
              department
              teamSize
              -------------
```

### Class Relationships

```text
                 Department
                      |
                      |
                      o
                      |
                      |
                   Employee

                   Employee
                      |
                      |
                      ◆
                      |
                      |
                    Address
```

- Person → Employee → Manager: Multilevel inheritance.
- Department → Employee: Aggregation.
- Employee → Address: Composition.
- `calculateSalary()`: Method overloading.
- `displayDetails()`: Method overriding.

## 9.2 Complete Java Program

**EmployeeManagementSystem.java**

```java
import java.util.ArrayList;
import java.util.List;

// Address class
// Used in composition with Employee
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

// Parent class
class Person {

    protected String name;

    protected int age;

    Person(String name, int age) {

        this.name = name;

        this.age = age;

    }

    void displayDetails() {

        System.out.println("Name: " + name);

        System.out.println("Age: " + age);

    }

}

// Employee class extends Person
class Employee extends Person {

    protected int empId;

    protected double salary;

    private Address address;

    Employee(
        String name,
        int age,
        int empId,
        double salary,
        String city,
        String state,
        int pincode
    ) {

        super(name, age);

        this.empId = empId;

        this.salary = salary;

        // Composition:
        // Employee creates and owns Address
        this.address = new Address(city, state, pincode);

    }

    // Overloaded method 1
    double calculateSalary() {

        return salary;

    }

    // Overloaded method 2
    double calculateSalary(double bonus) {

        return salary + bonus;

    }

    // Overloaded method 3
    double calculateSalary(double bonus, double allowance) {

        return salary + bonus + allowance;

    }

    // Overridden method
    @Override
    void displayDetails() {

        System.out.println("Employee ID: " + empId);

        super.displayDetails();

        System.out.println("Basic Salary: " + salary);

        System.out.println("Address:");

        address.displayAddress();

    }

}

// Manager class extends Employee
class Manager extends Employee {

    private String department;

    private int teamSize;

    Manager(
        String name,
        int age,
        int empId,
        double salary,
        String city,
        String state,
        int pincode,
        String department,
        int teamSize
    ) {

        super(
            name,
            age,
            empId,
            salary,
            city,
            state,
            pincode
        );

        this.department = department;

        this.teamSize = teamSize;

    }

    // Overridden method
    @Override
    void displayDetails() {

        System.out.println("===== MANAGER DETAILS =====");

        super.displayDetails();

        System.out.println("Department: " + department);

        System.out.println("Team Size: " + teamSize);

    }

}

// Department class
// Aggregation with Employee
class Department {

    private String departmentName;

    private List<Employee> employees;

    Department(String departmentName, List<Employee> employees) {

        this.departmentName = departmentName;

        this.employees = employees;

    }

    void displayDepartmentEmployees() {

        System.out.println(
            "\nDepartment: " + departmentName
        );

        for (Employee e : employees) {

            System.out.println(
                "Employee: " + e.name +
                " | ID: " + e.empId
            );

        }

    }

}

// Main application
public class EmployeeManagementSystem {

    public static void main(String[] args) {

        // Creating Employee objects
        Employee e1 = new Employee(
            "Anurag",
            22,
            101,
            40000,
            "Pune",
            "Maharashtra",
            411001
        );

        Employee e2 = new Employee(
            "Rahul",
            23,
            102,
            45000,
            "Mumbai",
            "Maharashtra",
            400001
        );

        // Creating Manager object
        Manager m1 = new Manager(
            "Amit",
            30,
            201,
            80000,
            "Pune",
            "Maharashtra",
            411002,
            "AI and ML",
            10
        );

        // Display Employee details
        System.out.println("===== EMPLOYEE DETAILS =====");

        e1.displayDetails();

        System.out.println();

        e2.displayDetails();

        // Display Manager details
        System.out.println();

        m1.displayDetails();

        // Demonstrating method overloading
        System.out.println("\n===== SALARY CALCULATION =====");

        System.out.println(
            "Basic Salary: " + e1.calculateSalary()
        );

        System.out.println(
            "Salary with Bonus: " +
            e1.calculateSalary(5000)
        );

        System.out.println(
            "Salary with Bonus and Allowance: " +
            e1.calculateSalary(5000, 3000)
        );

        // Department aggregation
        List<Employee> employeeList = new ArrayList<>();

        employeeList.add(e1);

        employeeList.add(e2);

        employeeList.add(m1);

        Department d1 =
            new Department("IT Department", employeeList);

        d1.displayDepartmentEmployees();

    }

}
```

## 9.3 Expected Output

```text
===== EMPLOYEE DETAILS =====
Employee ID: 101
Name: Anurag
Age: 22
Basic Salary: 40000.0
Address:
City: Pune
State: Maharashtra
Pincode: 411001

Employee ID: 102
Name: Rahul
Age: 23
Basic Salary: 45000.0
Address:
City: Mumbai
State: Maharashtra
Pincode: 400001

===== MANAGER DETAILS =====
Employee ID: 201
Name: Amit
Age: 30
Basic Salary: 80000.0
Address:
City: Pune
State: Maharashtra
Pincode: 411002
Department: AI and ML
Team Size: 10

===== SALARY CALCULATION =====
Basic Salary: 40000.0
Salary with Bonus: 45000.0
Salary with Bonus and Allowance: 48000.0

Department: IT Department
Employee: Anurag | ID: 101
Employee: Rahul | ID: 102
Employee: Amit | ID: 201
```

## 9.4 Explanation of the Program

### Step 1: Person Class

```java
class Person {

    protected String name;

    protected int age;

}
```

Person is the parent class.

It contains common properties shared by Employee and Manager.

The `protected` access modifier allows subclasses to access these fields.

### Step 2: Employee Class

```java
class Employee extends Person {
}
```

Employee inherits from Person.

It adds:
- Employee ID.
- Salary.
- Address reference.

### Step 3: Manager Class

```java
class Manager extends Employee {
}
```

Manager inherits from Employee.

It adds:
- Department name.
- Team size.

This demonstrates multilevel inheritance.

### Step 4: Composition

```java
this.address = new Address(city, state, pincode);
```

The Employee constructor creates its own Address object.

Employee maintains and owns this address as part of its design.

### Step 5: Aggregation

```java
Department d1 =
    new Department("IT Department", employeeList);
```

The Department receives an existing list of Employee references.

The Employee objects are created independently, so they can exist without the Department object.

### Step 6: Method Overloading

```java
double calculateSalary()

double calculateSalary(double bonus)

double calculateSalary(double bonus, double allowance)
```

The same method name is used with different parameter lists.

The compiler selects the appropriate method.

### Step 7: Method Overriding

```java
@Override
void displayDetails()
```

Employee overrides the Person method.

Manager overrides the Employee method.

Each class provides its own version of `displayDetails()`.

### Step 8: Using `super`

```java
super(name, age);
```

Calls the Person constructor from Employee.

```java
super.displayDetails();
```

Calls the parent-class implementation of `displayDetails()`.

---

## 9.5 Runtime Polymorphism in Employee Management

We can also demonstrate runtime polymorphism using a Person reference.

Add this code inside `main()`:

```java
System.out.println("\n===== RUNTIME POLYMORPHISM =====");

Person p1 = new Employee(
    "Anurag",
    22,
    101,
    40000,
    "Pune",
    "Maharashtra",
    411001
);

Person p2 = new Manager(
    "Amit",
    30,
    201,
    80000,
    "Pune",
    "Maharashtra",
    411002,
    "AI and ML",
    10
);

p1.displayDetails();

System.out.println();

p2.displayDetails();
```

### Explanation

```java
Person p1 = new Employee(...);
```

The reference type is Person, but the actual object is Employee.

Therefore, Employee's overridden `displayDetails()` method executes.

Similarly:

```java
Person p2 = new Manager(...);
```

The actual object is Manager, so Manager's overridden method executes.

This is runtime polymorphism.

---

## 9.6 Compile and Run

Save the program as:

`EmployeeManagementSystem.java`

Compile:

```bash
javac EmployeeManagementSystem.java
```

Run:

```bash
java EmployeeManagementSystem
```

---

# 10. Important Interview Questions

### Q1. What is inheritance?

Inheritance is an OOP mechanism through which one class acquires accessible members of another class.

### Q2. Which keyword is used for inheritance?

`extends`.

### Q3. What is a parent class?

A parent class is a class whose members are inherited by another class.

### Q4. What is single inheritance?

When one child class inherits from one parent class.

### Q5. What is multilevel inheritance?

When inheritance takes place through multiple levels, such as A → B → C.

### Q6. What is hierarchical inheritance?

When multiple child classes inherit from the same parent class.

### Q7. Does Java support multiple inheritance through classes?

No. Java does not support multiple inheritance of classes, but it supports implementing multiple interfaces.

### Q8. What is association?

A general relationship between two independent classes.

### Q9. What is aggregation?

Aggregation is a weak HAS-A relationship where the contained object can exist independently.

### Q10. What is composition?

Composition is a strong ownership relationship where a contained object is conceptually part of the owning object's lifecycle.

### Q11. What is the difference between aggregation and composition?

In aggregation, the contained object can exist independently. In composition, the whole conceptually owns the part and controls its lifecycle.

### Q12. What is polymorphism?

Polymorphism means many forms. It allows the same method name or reference type to represent different behaviors.

### Q13. What are the types of polymorphism in Java?

Compile-time polymorphism and runtime polymorphism.

### Q14. What is method overloading?

Defining multiple methods with the same name but different parameter lists.

### Q15. What is method overriding?

Providing a specialized implementation of an inherited instance method in a child class.

### Q16. Can we overload methods by changing only the return type?

No. The parameter list must be different.

### Q17. Can static methods be overridden?

No. Static methods are hidden, not overridden.

### Q18. Can constructors be overridden?

No. Constructors are not inherited.

### Q19. Can a private method be overridden?

No. Private methods are not inherited by subclasses.

### Q20. Can a final method be overridden?

No. A final method cannot be overridden.

### Q21. What is the use of `@Override`?

It tells the compiler that the method is intended to override an inherited method.

### Q22. What is the `this` keyword?

It refers to the current object.

### Q23. What is the `super` keyword?

It refers to the immediate parent-class part of the current object.

### Q24. What is the use of `super()`?

It invokes a parent-class constructor.

### Q25. What is runtime polymorphism?

Runtime polymorphism occurs when the JVM selects an overridden instance method based on the actual object type.

### Q26. Can we call an overridden parent method from a child class?

Yes, by using `super.methodName()`.

### Q27. What is the difference between IS-A and HAS-A relationships?

IS-A represents inheritance, whereas HAS-A represents a relationship where one object contains or uses another object.

Examples:
- Manager IS-A Employee.
- Employee HAS-A Address.

### Q28. Does inheritance inherit constructors?

No. Constructors are not inherited, but a child constructor can invoke a parent constructor using `super()`.

### Q29. Can a child class override a method with a more restrictive access modifier?

No. An overriding method cannot reduce the visibility of the overridden method.

### Q30. What is covariant return type?

It allows an overriding method to return a more specific reference type than the overridden method.

---

# 11. Multiple Choice Questions

### Q1. Which keyword is used for class inheritance?

A. implements  
B. extends  
C. inherits  
D. super  

**Answer: B. extends**

### Q2. Which inheritance involves one parent and one child?

A. Single  
B. Multilevel  
C. Hierarchical  
D. Multiple  

**Answer: A. Single**

### Q3. Which inheritance forms a chain?

A. Single  
B. Hierarchical  
C. Multilevel  
D. Multiple  

**Answer: C. Multilevel**

### Q4. Which inheritance has multiple child classes sharing one parent?

A. Single  
B. Hierarchical  
C. Multilevel  
D. Hybrid  

**Answer: B. Hierarchical**

### Q5. Does Java support multiple inheritance using classes?

A. Yes  
B. No  
C. Only with abstract classes  
D. Only with final classes  

**Answer: B. No**

### Q6. Which relationship is known as a weak HAS-A relationship?

A. Inheritance  
B. Aggregation  
C. Composition  
D. Overriding  

**Answer: B. Aggregation**

### Q7. Which relationship represents strong ownership?

A. Association  
B. Aggregation  
C. Composition  
D. Overloading  

**Answer: C. Composition**

### Q8. Which is compile-time polymorphism?

A. Overriding  
B. Overloading  
C. Inheritance  
D. Composition  

**Answer: B. Overloading**

### Q9. Which is runtime polymorphism?

A. Overloading  
B. Overriding  
C. Constructor overloading  
D. Encapsulation  

**Answer: B. Overriding**

### Q10. Can methods be overloaded by changing only the return type?

A. Yes  
B. No  
C. Sometimes  
D. Only in inheritance  

**Answer: B. No**

### Q11. Which annotation is used to indicate method overriding?

A. @Static  
B. @Final  
C. @Override  
D. @Overload  

**Answer: C. @Override**

### Q12. Which keyword refers to the current object?

A. super  
B. this  
C. static  
D. extends  

**Answer: B. this**

### Q13. Which keyword calls the parent-class constructor?

A. this()  
B. super()  
C. parent()  
D. base()  

**Answer: B. super()**

### Q14. Which methods cannot be overridden?

A. Public methods  
B. Protected methods  
C. Final methods  
D. Abstract methods  

**Answer: C. Final methods**

### Q15. What is the output of the following program?

```java
class A {

    void display() {

        System.out.println("A");

    }

}

class B extends A {

    @Override
    void display() {

        System.out.println("B");

    }

}

public class Main {

    public static void main(String[] args) {

        A obj = new B();

        obj.display();

    }

}
```

A. A  
B. B  
C. Compilation error  
D. Runtime error  

**Answer: B. B**

---

# 12. Quick Revision Notes

## Inheritance

| Type | Description |
|---|---|
| Single | One parent, one child. |
| Multilevel | A → B → C. |
| Hierarchical | One parent, multiple children. |
| `extends` | Used for class inheritance. |
| `implements` | Used for implementing interfaces. |

## Class Relationships

| Concept | Relationship | Example |
|---|---|---|
| Association | General relationship | Teacher–Student |
| Aggregation | Weak HAS-A | Department–Employee |
| Composition | Strong HAS-A | Employee–Address |

## Polymorphism

| Type | Mechanism |
|---|---|
| Compile-time | Method overloading |
| Runtime | Method overriding |

## Method Overloading vs Overriding

| Overloading | Overriding |
|---|---|
| Same method name | Same method signature |
| Different parameters | Compatible inherited signature |
| Compile-time | Runtime |
| Inheritance optional | Inheritance required |
| Return type may differ | Same or covariant return type |

## Keywords

| Keyword | Meaning |
|---|---|
| `this` | Current object |
| `super` | Immediate parent-class part |
| `extends` | Inheritance |
| `implements` | Interface implementation |
| `@Override` | Marks intended overriding |

---

# 13. Practice Checklist

- [ ] Understand inheritance and its advantages.
- [ ] Practice single inheritance.
- [ ] Practice multilevel inheritance.
- [ ] Practice hierarchical inheritance.
- [ ] Understand association.
- [ ] Understand aggregation.
- [ ] Understand composition.
- [ ] Differentiate IS-A and HAS-A relationships.
- [ ] Understand compile-time polymorphism.
- [ ] Understand runtime polymorphism.
- [ ] Practice method overloading.
- [ ] Practice method overriding.
- [ ] Learn all overloading and overriding rules.
- [ ] Practice `this` keyword.
- [ ] Practice `super` keyword.
- [ ] Complete Employee Management System.
- [ ] Practice MCQs and interview questions.

## Additional Self-Learning Assignments

1. **Vehicle Management System:** Create Vehicle → Car → ElectricCar using multilevel inheritance.

2. **Hospital Management System:** Create Person → Doctor and Person → Patient using hierarchical inheritance.

3. **College Management System:** Demonstrate Department–Teacher aggregation and Teacher–Address composition.

4. **Payment System:** Create a Payment class with overloaded `pay()` methods for different payment amounts and payment details.

5. **Shape Calculator:** Create a Shape parent class and Circle, Rectangle and Triangle child classes. Override an `area()` method.

6. **Library Management System:** Create Library and Book classes demonstrating aggregation.

7. **Employee Salary Calculator:** Overload salary calculation methods to support basic salary, bonus, and allowances.

---

**End of Session 7 – Inheritance**

Happy Learning! 🚀
