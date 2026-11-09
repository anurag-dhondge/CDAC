# Session 8: Packages, Access Control and Type Casting in Java

**Course:** CMCE – August 2026 Batch  
**Subject:** Java Programming  
**Session:** 8  
**Duration:** 2 Theory + 2 Lab Hours

---

## 📚 Table of Contents

1. [Access Modifiers](#1-access-modifiers)
2. [Packages in Java](#2-packages-in-java)
3. [Import Statements](#3-import-statements)
4. [Static Imports](#4-static-imports)
5. [Constructor Chaining](#5-constructor-chaining)
6. [Accessing Protected Members Outside the Package](#6-accessing-protected-members-outside-the-package)
7. [Upcasting and Downcasting](#7-upcasting-and-downcasting)
8. [instanceof Operator](#8-instanceof-operator)
9. [Lab: University Management System](#9-lab-university-management-system)
10. [Important Interview Questions](#10-important-interview-questions)
11. [Multiple Choice Questions](#11-multiple-choice-questions)
12. [Quick Revision Notes](#12-quick-revision-notes)

---

# 1. Access Modifiers

## 1.1 What are Access Modifiers?

Access modifiers are keywords in Java that control the visibility and accessibility of classes, variables, methods, and constructors.

In simple words, access modifiers decide **where a class member can be accessed from**.

Java provides four access levels:

1. `public`
2. `private`
3. `protected`
4. Default (no modifier)

### Why are Access Modifiers Required?

Consider an Employee class containing:

- Employee ID
- Employee name
- Salary
- Bank account details

We may want:
- Employee ID to be accessible from other classes.
- Salary to be accessible only through controlled methods.
- Internal bank account information to remain private.

Access modifiers help implement these restrictions.

## 1.2 Types of Access Modifiers

### A. Public

The `public` keyword provides the widest accessibility.

A public member can be accessed from any class, including classes in different packages, provided the declaring type itself is accessible.

#### Example

```java
package college;

public class Student {

    public int rollNo = 101;

    public void display() {

        System.out.println("Roll No: " + rollNo);

    }

}
```

Another class can access it:

```java
package application;

import college.Student;

public class Main {

    public static void main(String[] args) {

        Student s = new Student();

        System.out.println(s.rollNo);

        s.display();

    }

}
```

Output:

```text
101
Roll No: 101
```

### B. Private

The `private` keyword restricts access to the declaring top-level class.

Private members cannot be accessed directly from other classes, including subclasses.

They are commonly used to achieve encapsulation.

#### Example

```java
class Student {

    private int rollNo = 101;

    private void display() {

        System.out.println(rollNo);

    }

    public void showDetails() {

        display();

    }

}

public class Main {

    public static void main(String[] args) {

        Student s = new Student();

        // System.out.println(s.rollNo); // Error

        // s.display(); // Error

        s.showDetails();

    }

}
```

Output:

```text
101
```

#### Why use private?

We can protect data and provide controlled access using public getter and setter methods.

Example:

```java
class Student {

    private int rollNo;

    public void setRollNo(int rollNo) {

        if (rollNo > 0) {

            this.rollNo = rollNo;

        }

    }

    public int getRollNo() {

        return rollNo;

    }

}
```

### C. Protected

The `protected` keyword provides access:

1. Within the same class.
2. Within other classes in the same package.
3. In subclasses located in different packages, subject to Java's protected-access rules.

It is commonly used in inheritance.

#### Example

```java
package college;

public class Person {

    protected String name = "Anurag";

}
```

A child class in another package:

```java
package university;

import college.Person;

public class Student extends Person {

    public void display() {

        System.out.println(name);

    }

}
```

Output:

```text
Anurag
```

The Student class can access the protected `name` member because Student extends Person.

**Important:** Cross-package protected access has an additional restriction. A subclass cannot use an arbitrary parent-class reference to access the parent's protected instance member. The access must be through the subclass's own object or an object of its subclass type.

This is explained with a separate practical in Section 6.

### D. Default Access Modifier

When no access modifier is specified, Java uses package-private (default) access.

A default member can be accessed only within the same package.

#### Example

```java
package college;

class Student {

    int rollNo = 101;

    void display() {

        System.out.println(rollNo);

    }

}
```

Another class in the same package can access it.

```java
package college;

public class Main {

    public static void main(String[] args) {

        Student s = new Student();

        s.display();

    }

}
```

However, a class in another package cannot access the package-private Student class or its members.

**Note:** A top-level class can be declared `public` or package-private, but not `private` or `protected`.

## 1.3 Comparison of Access Modifiers

| Access Modifier | Same Class | Same Package | Subclass Outside Package | Other Package (Non-subclass) |
|---|---|---|---|---|
| `public` | Yes | Yes | Yes | Yes |
| `protected` | Yes | Yes | Yes, subject to subclass access rules | No |
| Default | Yes | Yes | No | No |
| `private` | Yes | No | No | No |

### Easy Way to Remember

```text
public       → Everywhere
protected    → Same package + subclasses outside package
default      → Same package only
private      → Same class only
```

---

# 2. Packages in Java

## 2.1 What is a Package?

A package in Java is a mechanism used to group related classes, interfaces, enums, and other types together.

It works like a folder that organizes Java files.

### Real-Life Example

Consider a University Management System.

It may contain:

- Student
- Faculty
- Department
- Examination
- Utility classes

Instead of keeping all classes in one location, we can organize them into packages.

```text
University
    |
    |---- person
    |       |
    |       |---- Person.java
    |
    |---- student
    |       |
    |       |---- Student.java
    |
    |---- faculty
    |       |
    |       |---- Faculty.java
    |
    |---- utility
            |
            |---- UniversityUtils.java
```

## 2.2 Advantages of Packages

1. Organize related classes.
2. Avoid naming conflicts.
3. Improve code maintainability.
4. Provide package-level access control.
5. Support code reuse.
6. Make large applications easier to manage.

## 2.3 Types of Packages

Java packages are commonly discussed in two categories:

### A. Built-in Packages

These are packages provided by Java.

Examples:

| Package | Purpose |
|---|---|
| `java.lang` | Core Java classes such as String, System, Math |
| `java.util` | Collections, Scanner, Random, etc. |
| `java.io` | Input/output operations |
| `java.net` | Networking |
| `java.sql` | Database connectivity |
| `java.time` | Date and time API |

### B. User-Defined Packages

These are packages created by programmers.

Example:

```java
package college;

public class Student {

    public void display() {

        System.out.println("Student Class");

    }

}
```

The statement:

```java
package college;
```

declares that the class belongs to the `college` package.

## 2.4 Creating a Package

### Step 1: Create a Java file

File: `Student.java`

```java
package college;

public class Student {

    public void display() {

        System.out.println("Welcome to College");

    }

}
```

### Step 2: Create another Java file

File: `Main.java`

```java
import college.Student;

public class Main {

    public static void main(String[] args) {

        Student s = new Student();

        s.display();

    }

}
```

### Output

```text
Welcome to College
```

## 2.5 Package Naming Convention

Java package names are generally written in lowercase.

Examples:

```java
package college;
package university;
package com.company.project;
package com.cdac.student;
```

For larger applications, reverse-domain naming is commonly used.

Example:

```java
package com.anurag.university.student;
```

## 2.6 Package Declaration Rules

1. The package declaration must be the first non-comment statement in a Java source file.
2. A source file can have only one package declaration.
3. A class belongs to one package.
4. The directory structure normally mirrors the package name.
5. A package can contain multiple classes and interfaces.

Example:

```java
package university.student;

public class Student {

}
```

Recommended directory:

```text
university/
    student/
        Student.java
```

---

# 3. Import Statements

## 3.1 What is an Import Statement?

An import statement allows us to use accessible classes and types from another package without writing their fully qualified names every time.

### Syntax

```java
import packageName.ClassName;
```

### Example

```java
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter your name: ");

        String name = sc.nextLine();

        System.out.println("Hello " + name);

        sc.close();

    }

}
```

### Output

```text
Enter your name: Anurag
Hello Anurag
```

## 3.2 Types of Import Statements

### A. Single Type Import

Imports a particular type.

```java
import java.util.Scanner;
```

### B. On-Demand Type Import

Imports accessible types declared in a package.

```java
import java.util.*;
```

This does not recursively import classes from subpackages.

For example:

```java
import java.util.*;
```

does not import classes from:

```java
java.util.concurrent
```

### C. Fully Qualified Class Name

We can use a class without an import statement by specifying its complete package name.

```java
public class Main {

    public static void main(String[] args) {

        java.util.Scanner sc =
            new java.util.Scanner(System.in);

        System.out.println("Enter number:");

        int n = sc.nextInt();

        System.out.println(n);

        sc.close();

    }

}
```

### D. Static Import

Static imports are covered in the next section.

## 3.3 Is Import Mandatory?

No.

Java automatically imports the `java.lang` package.

Therefore, we can directly use:

```java
String name = "Anurag";

System.out.println(name);

double result = Math.sqrt(25);
```

We do not need:

```java
import java.lang.String;
import java.lang.System;
import java.lang.Math;
```

---

# 4. Static Imports

## 4.1 What is Static Import?

Static import allows us to access accessible static members of another class without specifying the class name every time.

It was introduced in Java 5.

Normally, we access static methods using the class name.

Example:

```java
Math.sqrt(25);

Math.max(10, 20);
```

Using static import, we can directly call these methods.

### Syntax

```java
import static packageName.ClassName.staticMember;
```

For importing all accessible static members:

```java
import static packageName.ClassName.*;
```

## 4.2 Example Without Static Import

```java
public class Main {

    public static void main(String[] args) {

        System.out.println(Math.sqrt(25));

        System.out.println(Math.max(10, 20));

        System.out.println(Math.PI);

    }

}
```

Output:

```text
5.0
20
3.141592653589793
```

## 4.3 Example With Static Import

```java
import static java.lang.Math.sqrt;
import static java.lang.Math.max;
import static java.lang.Math.PI;

public class Main {

    public static void main(String[] args) {

        System.out.println(sqrt(25));

        System.out.println(max(10, 20));

        System.out.println(PI);

    }

}
```

Output:

```text
5.0
20
3.141592653589793
```

## 4.4 Import All Static Members

```java
import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) {

        System.out.println(sqrt(64));

        System.out.println(pow(2, 3));

        System.out.println(PI);

    }

}
```

Output:

```text
8.0
8.0
3.141592653589793
```

## 4.5 Normal Import vs Static Import

| Normal Import | Static Import |
|---|---|
| Imports accessible types. | Imports accessible static members. |
| Used for classes, interfaces, etc. | Used for static fields and methods. |
| Syntax: `import package.ClassName;` | Syntax: `import static package.ClassName.member;` |
| Example: `import java.util.Scanner;` | Example: `import static java.lang.Math.sqrt;` |

### Important Points

- Static import does not import instance methods.
- Static import does not create an object.
- It only makes static members accessible by their simple names.
- Avoid excessive static imports because they can make code less readable or cause naming ambiguity.

---

# 5. Constructor Chaining

## 5.1 What is Constructor Chaining?

Constructor chaining means calling one constructor from another constructor.

It allows constructors to reuse initialization logic.

Java provides two important constructor invocation statements:

1. `this()` – Calls another constructor in the same class.
2. `super()` – Calls a constructor of the immediate parent class.

## 5.2 Constructor Chaining Using `this()`

### Example

```java
class Student {

    int rollNo;
    String name;

    Student() {

        this(101, "Anurag");

        System.out.println("No-argument constructor");

    }

    Student(int rollNo, String name) {

        this.rollNo = rollNo;

        this.name = name;

        System.out.println("Parameterized constructor");

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

### Output

```text
Parameterized constructor
No-argument constructor
101 Anurag
```

### Explanation

When we execute:

```java
Student s1 = new Student();
```

The no-argument constructor executes.

It calls:

```java
this(101, "Anurag");
```

This invokes the parameterized constructor of the same class.

After that constructor completes, execution continues in the no-argument constructor.

## 5.3 Constructor Chaining Using `super()`

The `super()` statement invokes the parent-class constructor.

### Example

```java
class Person {

    String name;

    Person(String name) {

        this.name = name;

        System.out.println("Person Constructor");

    }

}

class Student extends Person {

    int rollNo;

    Student(String name, int rollNo) {

        super(name);

        this.rollNo = rollNo;

        System.out.println("Student Constructor");

    }

    void display() {

        System.out.println("Name: " + name);

        System.out.println("Roll No: " + rollNo);

    }

}

public class Main {

    public static void main(String[] args) {

        Student s = new Student("Anurag", 101);

        s.display();

    }

}
```

### Output

```text
Person Constructor
Student Constructor
Name: Anurag
Roll No: 101
```

### Explanation

```java
super(name);
```

Calls the parent-class constructor.

The parent constructor initializes `name`, and then the child constructor initializes `rollNo`.

## 5.4 Constructor Chaining Across Multiple Levels

Consider:

```text
Person
   |
   v
Employee
   |
   v
Manager
```

### Example

```java
class Person {

    Person() {

        System.out.println("Person Constructor");

    }

}

class Employee extends Person {

    Employee() {

        System.out.println("Employee Constructor");

    }

}

class Manager extends Employee {

    Manager() {

        System.out.println("Manager Constructor");

    }

}

public class Main {

    public static void main(String[] args) {

        Manager m = new Manager();

    }

}
```

### Output

```text
Person Constructor
Employee Constructor
Manager Constructor
```

### Why?

When a Manager object is created:

1. Manager constructor invokes Employee constructor.
2. Employee constructor invokes Person constructor.
3. Person constructor executes first.
4. Employee constructor executes next.
5. Manager constructor executes last.

If no explicit `super()` or `this()` call is written, Java inserts an implicit no-argument `super()` where applicable.

## 5.5 Constructor Chaining Rules

1. `this()` calls another constructor of the same class.
2. `super()` calls the parent-class constructor.
3. Explicit `this()` or `super()` must be the first statement in a constructor in Java 17.
4. A constructor cannot directly call both `this()` and `super()` because only one can be the first constructor invocation.
5. Constructor chaining can happen across multiple inheritance levels.
6. Constructors are not inherited.
7. If a parent has no accessible no-argument constructor, a child constructor must explicitly invoke an appropriate parent constructor.

---

# 6. Accessing Protected Members Outside the Package

This is an important topic for understanding Java access control and inheritance.

## 6.1 Protected Access Within the Same Package

A protected member can be accessed by any class in the same package.

Example:

**Person.java**

```java
package college;

public class Person {

    protected String name = "Anurag";

}
```

**Student.java**

```java
package college;

public class Student {

    public void display() {

        Person p = new Person();

        System.out.println(p.name);

    }

}
```

This works because both classes belong to the same package.

## 6.2 Protected Access Outside the Package Through Inheritance

A subclass in another package can access protected members inherited from its parent.

**Person.java**

```java
package college;

public class Person {

    protected String name = "Anurag";

    protected void displayName() {

        System.out.println(name);

    }

}
```

**Student.java**

```java
package university;

import college.Person;

public class Student extends Person {

    public void show() {

        System.out.println(name);

        displayName();

    }

}
```

This works because Student extends Person.

## 6.3 Important Restriction

Consider:

```java
package university;

import college.Person;

public class Student extends Person {

    public void show(Person p) {

        // System.out.println(p.name); // Compile-time error

        System.out.println(this.name); // Valid

        System.out.println(name); // Valid

    }

}
```

Why is `p.name` not allowed?

Because Student is in a different package from Person.

For cross-package protected instance access, the reference used must have the accessing subclass type or a subtype of it, not an arbitrary parent-class reference.

### Valid Access

```java
Student s = new Student();

System.out.println(s.name);
```

### Invalid Access

```java
Person p = new Person();

// System.out.println(p.name);
```

### Remember

| Situation | Protected Access |
|---|---|
| Same class | Allowed |
| Same package | Allowed |
| Subclass in another package using inherited member | Allowed |
| Non-subclass in another package | Not allowed |
| Cross-package subclass using arbitrary parent reference | Not allowed |

**Important:** Protected constructors and protected static members have their own access rules. The example above focuses on protected instance members.

---

# 7. Upcasting and Downcasting

## 7.1 What is Type Casting?

Type casting means converting a value or reference from one type to another compatible type.

In Java, reference type casting is commonly used with inheritance.

Two important types are:

1. Upcasting.
2. Downcasting.

## 7.2 Upcasting

### Definition

Upcasting means assigning a child-class object to a parent-class reference.

It is generally performed implicitly.

### Syntax

```java
Parent p = new Child();
```

### Example

```java
class Animal {

    void eat() {

        System.out.println("Animal eats");

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

        a.eat();

    }

}
```

### Output

```text
Animal eats
```

### Explanation

```java
Animal a = new Dog();
```

- `Animal` is the reference type.
- `Dog` is the actual object type.
- A Dog object can be assigned to an Animal reference because Dog extends Animal.

### Important Point

The parent reference can directly access only members available through the parent type.

Therefore:

```java
Animal a = new Dog();

a.eat();

// a.bark(); // Compilation error
```

The `bark()` method is specific to Dog and is not available through the Animal reference type.

## 7.3 Downcasting

### Definition

Downcasting means converting a parent-class reference back into a child-class reference.

It requires an explicit cast.

### Syntax

```java
Child c = (Child) parentReference;
```

### Example

```java
class Animal {

    void eat() {

        System.out.println("Animal eats");

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

        Dog d = (Dog) a;

        d.eat();

        d.bark();

    }

}
```

### Output

```text
Animal eats
Dog barks
```

### Explanation

1. A Dog object is created.
2. Its reference is stored in an Animal variable.
3. The Animal reference is explicitly cast to Dog.
4. The Dog-specific method can now be called.

## 7.4 Invalid Downcasting

Consider:

```java
class Animal {
}

class Dog extends Animal {
}

class Cat extends Animal {
}

public class Main {

    public static void main(String[] args) {

        Animal a = new Cat();

        Dog d = (Dog) a;

    }

}
```

This compiles, but produces a `ClassCastException` at runtime because the actual object is Cat, not Dog.

### Correct Approach

Check the actual object type before downcasting.

```java
if (a instanceof Dog) {

    Dog d = (Dog) a;

    d.bark();

} else {

    System.out.println("Object is not a Dog");

}
```

## 7.5 Upcasting vs Downcasting

| Upcasting | Downcasting |
|---|---|
| Child to parent reference. | Parent reference to child reference. |
| Usually implicit. | Explicit cast required. |
| Generally safe for a valid inheritance relationship. | May throw ClassCastException. |
| Parent members are accessible through the reference. | Child-specific members become accessible through the child reference. |
| Example: `Animal a = new Dog();` | Example: `Dog d = (Dog) a;` |

---

# 8. instanceof Operator

## 8.1 What is the instanceof Operator?

The `instanceof` operator is used to check whether an object is an instance of a particular class, subclass, or compatible interface type.

It returns a boolean value:

- `true`
- `false`

### Syntax

```java
referenceVariable instanceof ClassName
```

### Example

```java
class Animal {
}

class Dog extends Animal {
}

public class Main {

    public static void main(String[] args) {

        Dog d = new Dog();

        System.out.println(d instanceof Dog);

        System.out.println(d instanceof Animal);

    }

}
```

### Output

```text
true
true
```

### Explanation

- `d instanceof Dog` returns true because d refers to a Dog object.
- `d instanceof Animal` returns true because Dog extends Animal.

## 8.2 instanceof with Inheritance

```java
class Person {
}

class Employee extends Person {
}

class Manager extends Employee {
}

public class Main {

    public static void main(String[] args) {

        Manager m = new Manager();

        System.out.println(m instanceof Manager);

        System.out.println(m instanceof Employee);

        System.out.println(m instanceof Person);

    }

}
```

### Output

```text
true
true
true
```

A Manager object is also an Employee and a Person.

## 8.3 instanceof with null

```java
public class Main {

    public static void main(String[] args) {

        String name = null;

        System.out.println(name instanceof String);

    }

}
```

Output:

```text
false
```

If the reference is null, `instanceof` returns false.

## 8.4 Using instanceof Before Downcasting

This is a common practical and interview question.

```java
class Animal {

    void eat() {

        System.out.println("Animal eats");

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

public class Main {

    public static void main(String[] args) {

        Animal a = new Dog();

        if (a instanceof Dog) {

            Dog d = (Dog) a;

            d.bark();

        } else {

            System.out.println("Not a Dog");

        }

    }

}
```

### Output

```text
Dog barks
```

## 8.5 Pattern Matching with instanceof (Java 16+)

Java 16 introduced pattern matching for `instanceof` as a permanent feature.

It allows us to check the type and declare a variable in one statement.

### Traditional Approach

```java
if (a instanceof Dog) {

    Dog d = (Dog) a;

    d.bark();

}
```

### Modern Approach

```java
if (a instanceof Dog d) {

    d.bark();

}
```

Here:
- Java checks whether `a` refers to a Dog object.
- If the condition is true, the variable `d` is available in the relevant scope.
- The explicit cast is not required.

**For your Java 17 course, understand both traditional casting and pattern matching.**

---

# 9. Lab: University Management System

## Problem Statement

Design a University Management System using multiple packages.

Requirements:

1. Create a package for Person, Student and Faculty.
2. Create a package for utility classes.
3. Demonstrate access modifiers.
4. Demonstrate constructor chaining.
5. Demonstrate upcasting and downcasting.
6. Use instanceof checks before casting.

## 9.1 Application Architecture

We will create the following package structure:

```text
UniversityManagementSystem/
│
├── src/
│   │
│   ├── university/
│   │   ├── person/
│   │   │   └── Person.java
│   │   │
│   │   ├── student/
│   │   │   └── Student.java
│   │   │
│   │   ├── faculty/
│   │   │   └── Faculty.java
│   │   │
│   │   ├── utility/
│   │   │   └── UniversityUtils.java
│   │   │
│   │   └── app/
│   │       └── UniversityManagementSystem.java
│
└── bin/
```

### Package Responsibilities

| Package | Class | Responsibility |
|---|---|---|
| `university.person` | Person | Stores common personal information. |
| `university.student` | Student | Stores student-specific information. |
| `university.faculty` | Faculty | Stores faculty-specific information. |
| `university.utility` | UniversityUtils | Provides common utility methods. |
| `university.app` | UniversityManagementSystem | Main application. |

## 9.2 Class Relationship

```text
                  Person
                ----------
                name
                age
                ----------
                   |
             -------------
             |           |
             v           v
          Student      Faculty
          --------     --------
          rollNo       facultyId
          course       department
```

Both Student and Faculty inherit from Person.

## 9.3 Program Implementation

### File 1: Person.java

**Package:** `university.person`

```java
package university.person;

public class Person {

    // Public variable
    public String name;

    // Protected variable
    protected int age;

    // Default variable
    String city;

    // Private variable
    private String email;

    // Constructor
    public Person(String name, int age, String city, String email) {

        this.name = name;

        this.age = age;

        this.city = city;

        this.email = email;

        System.out.println("Person Constructor Called");

    }

    // Public method
    public void displayPerson() {

        System.out.println("Name: " + name);

        System.out.println("Age: " + age);

    }

    // Public getter for private email
    public String getEmail() {

        return email;

    }

}
```

### Explanation

This class demonstrates all four access levels:

| Member | Modifier |
|---|---|
| `name` | public |
| `age` | protected |
| `city` | default |
| `email` | private |

The constructor initializes the common Person information.

---

### File 2: Student.java

**Package:** `university.student`

```java
package university.student;

import university.person.Person;

public class Student extends Person {

    private int rollNo;

    private String course;

    public Student(
        String name,
        int age,
        String city,
        String email,
        int rollNo,
        String course
    ) {

        super(name, age, city, email);

        this.rollNo = rollNo;

        this.course = course;

        System.out.println("Student Constructor Called");

    }

    public void displayStudent() {

        // Public member of parent
        System.out.println("Name: " + name);

        // Protected member of parent
        System.out.println("Age: " + age);

        System.out.println("Roll No: " + rollNo);

        System.out.println("Course: " + course);

        // Access private parent variable through getter
        System.out.println("Email: " + getEmail());

    }

    public void studentMethod() {

        System.out.println("Student-specific method called");

    }

}
```

### Explanation

Student extends Person.

It demonstrates:

- Inheritance across packages.
- Accessing public parent members.
- Accessing protected parent members through inheritance.
- Accessing private parent data through a public getter.
- Constructor chaining using `super()`.

The default member `city` is not directly accessible here because Student is in a different package.

---

### File 3: Faculty.java

**Package:** `university.faculty`

```java
package university.faculty;

import university.person.Person;

public class Faculty extends Person {

    private int facultyId;

    private String department;

    public Faculty(
        String name,
        int age,
        String city,
        String email,
        int facultyId,
        String department
    ) {

        super(name, age, city, email);

        this.facultyId = facultyId;

        this.department = department;

        System.out.println("Faculty Constructor Called");

    }

    public void displayFaculty() {

        System.out.println("Name: " + name);

        System.out.println("Age: " + age);

        System.out.println("Faculty ID: " + facultyId);

        System.out.println("Department: " + department);

        System.out.println("Email: " + getEmail());

    }

    public void facultyMethod() {

        System.out.println("Faculty-specific method called");

    }

}
```

### Explanation

Faculty also inherits from Person.

It has its own:
- Faculty ID.
- Department.
- Faculty-specific method.

---

### File 4: UniversityUtils.java

**Package:** `university.utility`

```java
package university.utility;

import university.person.Person;

public class UniversityUtils {

    public static void displayUniversityName() {

        System.out.println("University: Savitribai Phule Pune University");

    }

    public static void displayPerson(Person p) {

        System.out.println("Person Name: " + p.name);

    }

}
```

### Explanation

This class demonstrates:

- A user-defined utility package.
- A static utility method.
- Passing a parent-class reference as a method argument.
- Accessing public members through a parent reference.

---

### File 5: UniversityManagementSystem.java

**Package:** `university.app`

```java
package university.app;

import university.person.Person;
import university.student.Student;
import university.faculty.Faculty;
import university.utility.UniversityUtils;

import static java.lang.System.out;

public class UniversityManagementSystem {

    public static void main(String[] args) {

        out.println("===== UNIVERSITY MANAGEMENT SYSTEM =====");

        // Static utility method
        UniversityUtils.displayUniversityName();

        out.println();

        // Creating Student object
        Student s1 = new Student(
            "Anurag",
            22,
            "Pune",
            "anurag@example.com",
            101,
            "PGCP-AC"
        );

        out.println();

        // Creating Faculty object
        Faculty f1 = new Faculty(
            "Mr. Sharma",
            40,
            "Pune",
            "sharma@example.com",
            501,
            "Computer Science"
        );

        out.println();

        // Display Student details
        out.println("===== STUDENT DETAILS =====");

        s1.displayStudent();

        out.println();

        // Display Faculty details
        out.println("===== FACULTY DETAILS =====");

        f1.displayFaculty();

        out.println();

        // Demonstrating upcasting
        out.println("===== UPCASTING =====");

        Person p1 = s1;

        Person p2 = f1;

        UniversityUtils.displayPerson(p1);

        UniversityUtils.displayPerson(p2);

        out.println();

        // Demonstrating instanceof
        out.println("===== INSTANCEOF CHECK =====");

        if (p1 instanceof Student) {

            out.println("p1 refers to a Student object");

        }

        if (p2 instanceof Faculty) {

            out.println("p2 refers to a Faculty object");

        }

        out.println();

        // Demonstrating downcasting
        out.println("===== DOWNCASTING =====");

        if (p1 instanceof Student) {

            Student s2 = (Student) p1;

            s2.studentMethod();

        }

        if (p2 instanceof Faculty) {

            Faculty f2 = (Faculty) p2;

            f2.facultyMethod();

        }

    }

}
```

### Explanation of Main Class

#### 1. Importing Classes

```java
import university.person.Person;
import university.student.Student;
import university.faculty.Faculty;
import university.utility.UniversityUtils;
```

These statements import the classes required from different packages.

#### 2. Static Import

```java
import static java.lang.System.out;
```

This allows us to write:

```java
out.println("Hello");
```

instead of:

```java
System.out.println("Hello");
```

#### 3. Constructor Chaining

```java
Student s1 = new Student(...);
```

The Student constructor invokes:

```java
super(name, age, city, email);
```

This calls the Person constructor first.

Similarly, the Faculty constructor also invokes the Person constructor.

#### 4. Upcasting

```java
Person p1 = s1;
```

The Student reference is assigned to a Person reference.

```java
Person p2 = f1;
```

The Faculty reference is assigned to a Person reference.

#### 5. instanceof Check

```java
if (p1 instanceof Student) {
    ...
}
```

This checks whether p1 refers to a Student object.

#### 6. Downcasting

```java
Student s2 = (Student) p1;
```

The Person reference is converted back into a Student reference.

The instanceof check ensures that the actual object is compatible with Student before the cast.

---

## 9.4 Expected Output

```text
===== UNIVERSITY MANAGEMENT SYSTEM =====
University: Savitribai Phule Pune University

Person Constructor Called
Student Constructor Called

Person Constructor Called
Faculty Constructor Called

===== STUDENT DETAILS =====
Name: Anurag
Age: 22
Roll No: 101
Course: PGCP-AC
Email: anurag@example.com

===== FACULTY DETAILS =====
Name: Mr. Sharma
Age: 40
Faculty ID: 501
Department: Computer Science
Email: sharma@example.com

===== UPCASTING =====
Person Name: Anurag
Person Name: Mr. Sharma

===== INSTANCEOF CHECK =====
p1 refers to a Student object
p2 refers to a Faculty object

===== DOWNCASTING =====
Student-specific method called
Faculty-specific method called
```

## 9.5 Demonstrating Access Modifiers in the Practical

The Person class has:

```java
public String name;

protected int age;

String city;

private String email;
```

Their accessibility is:

| Member | Student subclass in another package | Main class in another package |
|---|---|---|
| `name` | Direct access allowed | Direct access allowed |
| `age` | Allowed through subclass inheritance | Not directly allowed |
| `city` | Not directly allowed | Not directly allowed |
| `email` | Not directly allowed | Not directly allowed |
| `getEmail()` | Allowed | Allowed |

The private email is accessed through the public getter:

```java
getEmail();
```

This demonstrates encapsulation.

## 9.6 Compile and Run the Project

Open the terminal inside the `UniversityManagementSystem` directory.

Compile:

```bash
javac -d bin src/university/person/Person.java src/university/student/Student.java src/university/faculty/Faculty.java src/university/utility/UniversityUtils.java src/university/app/UniversityManagementSystem.java
```

Run:

```bash
java -cp bin university.app.UniversityManagementSystem
```

### Understanding the Commands

| Command | Purpose |
|---|---|
| `javac` | Java compiler |
| `-d bin` | Places compiled `.class` files inside bin |
| `-cp bin` | Sets the classpath to bin |
| `university.app.UniversityManagementSystem` | Fully qualified main class name |

**Important:** Package names and directory names are case-sensitive on many operating systems and should match exactly.

---

# 10. Important Interview Questions

### Q1. What are access modifiers in Java?

Access modifiers control the visibility and accessibility of classes and their members.

### Q2. How many access levels are provided by Java?

Four: public, private, protected and default (package-private).

### Q3. What is the difference between private and protected?

Private members are accessible only within their declaring class, whereas protected members are accessible within the same package and through subclass access rules outside the package.

### Q4. What is a default access modifier?

When no modifier is specified, the member has package-private access.

### Q5. Can a top-level class be private?

No. A top-level class can be public or package-private.

### Q6. What is a package?

A package is a mechanism for grouping related Java types and organizing application code.

### Q7. What is the purpose of a package?

It provides code organization, avoids naming conflicts, supports reuse and provides package-level access control.

### Q8. What is a user-defined package?

A package created by the programmer using the package declaration.

### Q9. What is an import statement?

An import statement allows us to use accessible types from another package without writing their fully qualified names repeatedly.

### Q10. Is importing java.lang mandatory?

No. Java automatically imports java.lang.

### Q11. What is static import?

Static import allows direct access to accessible static fields and methods without specifying the declaring class name.

### Q12. What is the difference between import and static import?

Normal import imports types, while static import imports static members.

### Q13. What is constructor chaining?

Calling one constructor from another using this() or super().

### Q14. What is the difference between this() and super()?

`this()` calls another constructor in the same class, whereas `super()` calls a constructor in the immediate parent class.

### Q15. Can this() and super() be used together in the same constructor?

No. In Java 17, both are constructor invocation statements that must be first, so they cannot both appear in one constructor.

### Q16. Can a subclass access a protected member outside its package?

Yes, through inheritance, subject to the protected-access restrictions.

### Q17. What is upcasting?

Assigning a child-class object to a parent-class reference.

### Q18. What is downcasting?

Converting a parent-class reference to a compatible child-class reference using an explicit cast.

### Q19. What happens if downcasting is performed incorrectly?

A ClassCastException can occur at runtime.

### Q20. What is instanceof?

An operator used to check whether an object is compatible with a particular reference type.

### Q21. What does instanceof return for null?

False.

### Q22. Is upcasting implicit?

Yes, for a valid subclass-to-superclass relationship.

### Q23. Is downcasting implicit?

No. It requires an explicit cast.

### Q24. Can a parent reference call child-specific methods?

Not directly. Downcasting or an appropriate polymorphic method design is required.

### Q25. What is the fully qualified name of a Java class?

It is the package name followed by the class name.

Example:

```java
university.student.Student
```

### Q26. Does import copy a class into another package?

No. It only makes the type available for use by its simple name.

### Q27. Can we import all classes from subpackages using `*`?

No. Wildcard imports do not recursively import subpackages.

### Q28. What is pattern matching with instanceof?

A Java feature that combines a type check and a pattern variable declaration.

Example:

```java
if (obj instanceof String s) {
    System.out.println(s.length());
}
```

---

# 11. Multiple Choice Questions

### Q1. Which access modifier provides the widest accessibility?

A. private  
B. protected  
C. default  
D. public  

**Answer: D. public**

### Q2. Which access modifier provides access only within the declaring class?

A. public  
B. protected  
C. private  
D. default  

**Answer: C. private**

### Q3. Which access level is used when no modifier is specified?

A. public  
B. default  
C. private  
D. protected  

**Answer: B. default**

### Q4. Which keyword is used to declare a package?

A. import  
B. package  
C. class  
D. namespace  

**Answer: B. package**

### Q5. Which package is automatically imported?

A. java.util  
B. java.io  
C. java.lang  
D. java.sql  

**Answer: C. java.lang**

### Q6. Which statement imports the Scanner class?

A. `import java.util.*;`  
B. `import java.util.Scanner;`  
C. Both A and B  
D. None  

**Answer: C. Both A and B**

### Q7. Which keyword is used for static import?

A. static  
B. import static  
C. extends  
D. implements  

**Answer: B. import static**

### Q8. Which statement calls another constructor in the same class?

A. super()  
B. this()  
C. parent()  
D. new()  

**Answer: B. this()**

### Q9. Which statement calls the parent-class constructor?

A. this()  
B. super()  
C. parent()  
D. base()  

**Answer: B. super()**

### Q10. Which casting is generally implicit?

A. Downcasting  
B. Upcasting  
C. Both  
D. Neither  

**Answer: B. Upcasting**

### Q11. Which casting requires an explicit cast?

A. Upcasting  
B. Downcasting  
C. Both  
D. Neither  

**Answer: B. Downcasting**

### Q12. Which operator checks an object's type?

A. typeof  
B. instanceof  
C. type  
D. is  

**Answer: B. instanceof**

### Q13. What does instanceof return for a null reference?

A. true  
B. false  
C. null  
D. Compilation error  

**Answer: B. false**

### Q14. What exception can occur due to an invalid downcast?

A. IOException  
B. NullPointerException  
C. ClassCastException  
D. ArithmeticException  

**Answer: C. ClassCastException**

### Q15. Can a subclass in another package access an inherited protected member?

A. Yes  
B. No  
C. Only if it is static  
D. Only through an arbitrary parent reference  

**Answer: A. Yes**

### Q16. Which statement is valid?

```java
class Animal {
}

class Dog extends Animal {
}
```

A. `Dog d = new Animal();`  
B. `Animal a = new Dog();`  
C. `Dog d = (Dog) new Animal();`  
D. `Animal a = (Animal) null;` is invalid  

**Answer: B. Animal a = new Dog();**

---

# 12. Quick Revision Notes

## Access Modifiers

| Modifier | Accessibility |
|---|---|
| public | Everywhere |
| protected | Same package + subclasses outside package |
| default | Same package |
| private | Same class |

## Packages and Imports

| Concept | Syntax |
|---|---|
| Package declaration | `package college;` |
| Import class | `import java.util.Scanner;` |
| Import all types | `import java.util.*;` |
| Static import | `import static java.lang.Math.PI;` |
| Fully qualified name | `java.util.Scanner` |

## Constructor Chaining

| Keyword | Purpose |
|---|---|
| `this()` | Same-class constructor |
| `super()` | Parent-class constructor |

## Type Casting

| Concept | Meaning |
|---|---|
| Upcasting | Child object → Parent reference |
| Downcasting | Parent reference → Child reference |
| `instanceof` | Checks reference type compatibility |
| `ClassCastException` | Invalid runtime cast |

## Important Code Examples

```java
// Upcasting
Person p = new Student();

// Downcasting
Student s = (Student) p;

// instanceof check
if (p instanceof Student) {
    Student s1 = (Student) p;
}

// Static import
import static java.lang.Math.sqrt;

// Constructor chaining
super(name);
this(101, "Anurag");
```

---

# 13. Practice Checklist

- [ ] Understand all four access modifiers.
- [ ] Practise public and private members.
- [ ] Understand protected access within and outside a package.
- [ ] Understand default/package-private access.
- [ ] Create user-defined packages.
- [ ] Practise import statements.
- [ ] Practise wildcard imports.
- [ ] Understand static imports.
- [ ] Practise constructor chaining using this().
- [ ] Practise constructor chaining using super().
- [ ] Create inheritance across multiple packages.
- [ ] Practise upcasting.
- [ ] Practise downcasting.
- [ ] Use instanceof before downcasting.
- [ ] Understand ClassCastException.
- [ ] Complete University Management System.
- [ ] Practise MCQs and interview questions.

## Additional Self-Learning Assignments

1. **Hospital Management System:** Create packages for Person, Doctor, Patient and utility classes.

2. **Bank Management System:** Create Account and Customer classes in separate packages and demonstrate access modifiers.

3. **College Management System:** Create Person, Student and Teacher classes in different packages and demonstrate protected access.

4. **Vehicle Management System:** Create Vehicle, Car and Bike classes in separate packages and demonstrate upcasting and downcasting.

5. **Employee Management System:** Create Employee and Manager classes in separate packages. Use constructor chaining and instanceof.

6. **Math Utility:** Create a custom utility class with static methods and access them using static import.

---

**End of Session 8 – Packages, Access Control and Type Casting**

Happy Learning! 🚀
