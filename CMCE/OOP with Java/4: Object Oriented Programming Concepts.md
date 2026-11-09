# ☕ Session 4: Object-Oriented Programming Concepts (OOP)

**Course:** PGCP-AC / CMCE – August 2026 Batch  
**Subject:** Object-Oriented Programming with Java  
**Session:** 4  
**Duration:** 2 Theory + 2 Lab + 2 Self Learning  
**Java Version:** Java 17

---

# 📚 Table of Contents

1. Introduction to Object-Oriented Programming
2. Why Do We Need OOP?
3. Procedural Programming vs Object-Oriented Programming
4. Classes and Objects
5. Class Structure in Java
6. Object Creation and Memory Concept
7. Four Major OOP Principles
   - Encapsulation
   - Abstraction
   - Inheritance
   - Polymorphism
8. Real-World Examples of OOP
9. Lab Practical – Student Class
10. Additional Practical Programs
11. Important Interview Questions
12. CMCE Practice MCQs
13. Output-Based Questions
14. Quick Revision Notes
15. Practice Checklist

---

# 1. Introduction to Object-Oriented Programming

## 1.1 What is OOP?

OOP stands for **Object-Oriented Programming**.

It is a programming approach in which software is designed using classes and objects.

In OOP, we represent real-world entities as objects that contain:

- Data (Attributes / Properties).
- Behaviour (Methods / Functions).

For example, consider a Student.

A student has some properties:

- Roll Number
- Name
- Marks
- Age
- Course

A student can perform some actions:

- Display Details
- Calculate Percentage
- Update Marks
- Check Result

In Java, we can represent a student using a class and create multiple student objects from that class.

### Real-World Representation

```text
                 STUDENT
                    |
          ---------------------
          |                   |
          v                   v
       DATA                BEHAVIOUR
     (Attributes)           (Methods)
          |                   |
    ------------          ------------
    |    |     |          |          |
 Roll Name Marks       Display    Calculate
 Number                    Details   Result
```

### Java Representation

```java
class Student {

    // Attributes
    int rollNo;
    String name;
    double marks;

    // Behaviour
    void displayDetails() {

        System.out.println("Roll No: " + rollNo);

        System.out.println("Name: " + name);

        System.out.println("Marks: " + marks);

    }
}
```

Here:

- `Student` is a class.
- `rollNo`, `name` and `marks` are attributes.
- `displayDetails()` is a method.

## 1.2 What is the Main Idea Behind OOP?

OOP organizes a program around objects rather than only a sequence of functions.

Each object represents an entity and combines its data and related operations.

For example, in a banking application:

| Object | Attributes | Behaviour |
|---|---|---|
| Customer | Name, Customer ID | Update Profile |
| BankAccount | Account Number, Balance | Deposit, Withdraw |
| Employee | Employee ID, Salary | Calculate Salary |
| Transaction | Transaction ID, Amount | Process Transaction |

This makes applications easier to organize, maintain, extend and reuse.

## 1.3 Important Terminology in OOP

| Term | Meaning |
|---|---|
| Class | Blueprint used to create objects |
| Object | Instance of a class |
| Attribute | Data or property of an object |
| Method | Behaviour or operation |
| Constructor | Special member used to initialize objects |
| Encapsulation | Bundling data and methods with controlled access |
| Abstraction | Hiding implementation details |
| Inheritance | Acquiring properties and behaviour from another class |
| Polymorphism | One interface or method name supporting different behaviours |

---

# 2. Why Do We Need OOP?

Before OOP, many programs were written using procedural programming.

As applications became larger, managing data and functions separately became difficult.

OOP helps solve several software development problems.

## 2.1 Code Reusability

Inheritance allows us to reuse existing class functionality.

Example:

A `Car` class and a `Bike` class can inherit common properties from a `Vehicle` class.

## 2.2 Data Security

Encapsulation allows us to restrict direct access to sensitive data.

Example:

A bank account balance can be declared private and modified through controlled methods.

## 2.3 Code Maintainability

OOP organizes code into separate classes.

Changes in one class can often be made without modifying the entire application.

## 2.4 Flexibility

Polymorphism allows the same method name or parent reference to work with different object types.

## 2.5 Real-World Modelling

OOP makes it easier to represent real-world entities such as:

- Students
- Employees
- Banks
- Vehicles
- Products
- Customers

## 2.6 Advantages of OOP

1. Code reusability.
2. Modularity.
3. Data protection through encapsulation.
4. Easy maintenance.
5. Extensibility.
6. Better organization.
7. Real-world modelling.
8. Supports polymorphic behaviour.

---

# 3. Procedural Programming vs Object-Oriented Programming

## 3.1 Procedural Programming

Procedural programming organizes programs around functions or procedures.

The program is divided into smaller functions that perform specific operations.

Example:

```java
class ProceduralDemo {

    static void displayStudent(String name, int rollNo) {

        System.out.println(name);

        System.out.println(rollNo);

    }

    public static void main(String[] args) {

        displayStudent("Anurag", 101);

    }
}
```

## 3.2 Object-Oriented Programming

Object-oriented programming organizes data and related behaviour into classes and objects.

Example:

```java
class Student {

    String name;

    int rollNo;

    void display() {

        System.out.println(name);

        System.out.println(rollNo);

    }

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.name = "Anurag";

        s1.rollNo = 101;

        s1.display();

    }
}
```

## 3.3 Difference Between Procedural and OOP

| Procedural Programming | Object-Oriented Programming |
|---|---|
| Organized around functions | Organized around objects |
| Focuses on procedures | Focuses on data and behaviour |
| Data and functions are generally separate | Data and methods are grouped into classes |
| Reusability through functions and other techniques | Supports inheritance and composition |
| Data protection is not inherently provided by the paradigm | Supports encapsulation and access control |
| Suitable for many small, function-oriented programs | Useful for modelling large, complex applications |
| Example: C | Examples: Java, C++ |

**Important:** Java supports OOP, but it also supports procedural-style programming through static methods.

---

# 4. Classes and Objects

Classes and objects are the fundamental building blocks of Java OOP.

## 4.1 What is a Class?

A class is a blueprint or template used to create objects.

It defines the properties and behaviour that its objects can have.

Example:

```java
class Student {

    int rollNo;

    String name;

    double marks;

    void display() {

        System.out.println(rollNo);

        System.out.println(name);

        System.out.println(marks);

    }
}
```

Here:

- `Student` is the class name.
- `rollNo`, `name` and `marks` are instance variables.
- `display()` is an instance method.

**Important:** A class definition describes the structure and behaviour of objects. An object is created when we instantiate the class.

## 4.2 What is an Object?

An object is an instance of a class.

It represents an entity with:

1. State – Data stored in the object.
2. Behaviour – Operations performed by the object.
3. Identity – A distinct identity that differentiates it from other objects.

Example:

```java
class Student {

    int rollNo;

    String name;

    void display() {

        System.out.println("Roll No: " + rollNo);

        System.out.println("Name: " + name);

    }

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.rollNo = 101;

        s1.name = "Anurag";

        s1.display();

    }
}
```

Output:

```text
Roll No: 101
Name: Anurag
```

Explanation:

- `Student` is the class.
- `s1` is a reference variable.
- `new Student()` creates an object.
- `rollNo` and `name` store the object's state.
- `display()` represents the object's behaviour.

## 4.3 Class vs Object

| Class | Object |
|---|---|
| Blueprint or template | Instance of a class |
| Defines attributes and methods | Contains actual instance state |
| Declared using `class` | Created using `new` in typical Java code |
| Logical definition | Runtime entity |
| Example: Student | Example: s1, s2 |

### Real-World Example

Consider a house construction plan.

- Blueprint = Class.
- Actual constructed houses = Objects.

One blueprint can be used to construct multiple houses.

Similarly, one Student class can create multiple student objects.

```text
             STUDENT CLASS
                   |
          -------------------
          |        |        |
          v        v        v
       Object 1  Object 2  Object 3
          |        |        |
       Anurag    Rahul     Priya
       Roll 101  Roll 102  Roll 103
```

## 4.4 How to Create an Object in Java?

Syntax:

```java
ClassName referenceVariable = new ClassName();
```

Example:

```java
Student s1 = new Student();
```

This statement has three parts.

| Part | Meaning |
|---|---|
| `Student` | Reference variable type |
| `s1` | Reference variable name |
| `new Student()` | Creates and initializes an object |

## 4.5 Accessing Object Members

Use the dot (`.`) operator to access accessible members of an object.

Example:

```java
class Employee {

    int empId;

    String empName;

    void display() {

        System.out.println(empId);

        System.out.println(empName);

    }

    public static void main(String[] args) {

        Employee e1 = new Employee();

        e1.empId = 101;

        e1.empName = "Rahul";

        e1.display();

    }
}
```

Output:

```text
101
Rahul
```

## 4.6 Multiple Objects of a Class

One class can create multiple objects.

Each object has its own instance variables.

Example:

```java
class Student {

    int rollNo;

    String name;

    void display() {

        System.out.println("Roll No: " + rollNo);

        System.out.println("Name: " + name);

        System.out.println("----------------");

    }

    public static void main(String[] args) {

        Student s1 = new Student();

        Student s2 = new Student();

        s1.rollNo = 101;

        s1.name = "Anurag";

        s2.rollNo = 102;

        s2.name = "Rahul";

        s1.display();

        s2.display();

    }
}
```

Output:

```text
Roll No: 101
Name: Anurag
----------------
Roll No: 102
Name: Rahul
----------------
```

**Important:** Changing the instance variable of `s1` does not automatically change the corresponding instance variable of `s2`.

---

# 5. Four Major OOP Principles

The four major principles of OOP are:

1. Encapsulation.
2. Abstraction.
3. Inheritance.
4. Polymorphism.

These principles help developers create reusable, secure, maintainable and flexible applications.

## OOP Principles Overview

```text
             OOP PRINCIPLES
                   |
      -----------------------------
      |            |              |
      v            v              v
 Encapsulation  Abstraction   Inheritance
                   |
                   |
               Polymorphism
```

---

# 6. Encapsulation

## 6.1 What is Encapsulation?

Encapsulation is the process of bundling data (variables) and methods that operate on that data into a single unit called a class.

It also allows us to control access to an object's internal data using access modifiers.

In simple words:

**Encapsulation = Data + Methods + Controlled Access**

## 6.2 Why Do We Need Encapsulation?

Suppose a bank account has a balance of ₹10,000.

If the balance is publicly accessible, another part of the program could assign an invalid value directly.

For example:

```java
account.balance = -50000;
```

This may violate banking rules.

Encapsulation helps prevent uncontrolled modification.

## 6.3 How to Implement Encapsulation?

Common steps:

1. Declare instance variables as `private`.
2. Provide public methods to access or modify the variables.
3. Add validation inside setter methods when necessary.

### Example Without Encapsulation

```java
class Student {

    public int marks;

}

class Main {

    public static void main(String[] args) {

        Student s = new Student();

        s.marks = -100;

        System.out.println(s.marks);

    }
}
```

Output:

```text
-100
```

Problem:

Invalid marks can be assigned directly.

### Example With Encapsulation

```java
class Student {

    private int marks;

    public void setMarks(int marks) {

        if (marks >= 0 && marks <= 100) {

            this.marks = marks;

        }
        else {

            System.out.println("Invalid marks");

        }

    }

    public int getMarks() {

        return marks;

    }

}

class Main {

    public static void main(String[] args) {

        Student s = new Student();

        s.setMarks(85);

        System.out.println("Marks: " + s.getMarks());

        s.setMarks(150);

    }
}
```

Output:

```text
Marks: 85
Invalid marks
```

Explanation:

- `private int marks` prevents direct access from unrelated classes.
- `setMarks()` controls modification.
- `getMarks()` provides controlled reading.
- `this.marks` refers to the current object's instance variable.

## 6.4 What is a Getter?

A getter is a method used to retrieve the value of a private variable.

Example:

```java
public int getMarks() {

    return marks;

}
```

## 6.5 What is a Setter?

A setter is a method used to modify the value of a private variable.

Example:

```java
public void setMarks(int marks) {

    this.marks = marks;

}
```

## 6.6 Advantages of Encapsulation

1. Protects internal data.
2. Provides controlled access.
3. Allows validation.
4. Improves maintainability.
5. Reduces unwanted dependencies.
6. Makes implementation changes easier.

## 6.7 Important Terms

| Term | Meaning |
|---|---|
| private | Accessible within the declaring class |
| public | Accessible wherever the declaring type/member is accessible |
| Getter | Reads a value |
| Setter | Modifies a value |
| this | Refers to the current object |

**CMCE Important:** Encapsulation is commonly implemented using private variables and public getter/setter methods.

---

# 7. Abstraction

## 7.1 What is Abstraction?

Abstraction is the process of hiding unnecessary implementation details and exposing only the essential functionality to the user.

In simple words:

**Abstraction = What an object does, without exposing all the details of how it does it.**

### Real-World Example: ATM

When using an ATM:

1. Insert your card.
2. Enter your PIN.
3. Select withdrawal.
4. Enter the amount.
5. Receive cash.

You do not need to know the internal implementation of the banking server, database queries or cash dispenser mechanism.

The ATM exposes the necessary operations while hiding the internal complexity.

## 7.2 How to Achieve Abstraction in Java?

Java commonly supports abstraction using:

1. Abstract classes.
2. Interfaces.

## 7.3 Abstract Class

An abstract class is declared using the `abstract` keyword.

It cannot be instantiated directly.

It can contain:

- Abstract methods.
- Concrete methods.
- Constructors.
- Instance variables.
- Static members.

Example:

```java
abstract class Vehicle {

    abstract void start();

    void stop() {

        System.out.println("Vehicle stopped");

    }

}

class Car extends Vehicle {

    @Override
    void start() {

        System.out.println("Car starts with a key");

    }

}

class Main {

    public static void main(String[] args) {

        Car c = new Car();

        c.start();

        c.stop();

    }
}
```

Output:

```text
Car starts with a key
Vehicle stopped
```

Explanation:

- `Vehicle` is an abstract class.
- `start()` is an abstract method.
- `stop()` is a concrete method.
- `Car` extends `Vehicle`.
- `Car` provides the implementation of `start()`.

### What is an Abstract Method?

An abstract method is a method declared without an implementation.

Example:

```java
abstract void start();
```

A concrete subclass must implement inherited abstract methods unless the subclass is also abstract.

## 7.4 Interface

An interface defines a contract that implementing classes agree to follow.

Example:

```java
interface Payment {

    void pay(double amount);

}

class UpiPayment implements Payment {

    @Override
    public void pay(double amount) {

        System.out.println("UPI Payment: " + amount);

    }

}

class Main {

    public static void main(String[] args) {

        Payment p = new UpiPayment();

        p.pay(500);

    }
}
```

Output:

```text
UPI Payment: 500.0
```

Explanation:

- `Payment` is an interface.
- `pay()` defines the required operation.
- `UpiPayment` implements the interface.
- The implementation is provided inside the class.

## 7.5 Abstract Class vs Interface

| Abstract Class | Interface |
|---|---|
| Declared using `abstract class` | Declared using `interface` |
| A class extends it | A class implements it |
| Can contain instance variables | Fields are implicitly public, static and final |
| Can have constructors | Cannot have constructors |
| Can contain abstract and concrete methods | Can contain abstract, default, static and private methods |
| A class can extend only one class | A class can implement multiple interfaces |

**Important:** Modern Java interfaces can have default, static and private methods. An interface is not limited to abstract methods only.

## 7.6 Advantages of Abstraction

1. Hides unnecessary implementation details.
2. Reduces complexity.
3. Improves code organization.
4. Supports flexible implementations.
5. Makes applications easier to extend.

---

# 8. Inheritance

## 8.1 What is Inheritance?

Inheritance is an OOP mechanism in which one class acquires accessible fields and methods from another class.

It helps achieve code reusability.

In Java:

- Parent class is also called superclass or base class.
- Child class is also called subclass or derived class.

### Real-World Example

Consider a vehicle.

Common properties:

- Brand.
- Speed.
- Fuel Type.

A car and a bike are both vehicles.

Instead of defining common properties separately in both classes, we can create a parent class called `Vehicle`.

```text
                VEHICLE
                   |
          ------------------
          |                |
          v                v
         CAR              BIKE
```

## 8.2 How to Implement Inheritance?

Java uses the `extends` keyword for class inheritance.

Syntax:

```java
class Child extends Parent {

    // Child class members

}
```

Example:

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

class Main {

    public static void main(String[] args) {

        Dog d = new Dog();

        d.eat();

        d.bark();

    }
}
```

Output:

```text
Animal eats food
Dog barks
```

Explanation:

- `Animal` is the parent class.
- `Dog` is the child class.
- `Dog extends Animal` establishes inheritance.
- The Dog object can use the inherited `eat()` method.

## 8.3 Types of Inheritance

### A. Single Inheritance

One child class inherits from one parent class.

```text
       Animal
          |
          v
         Dog
```

Example:

```java
class Animal {

    void eat() {

        System.out.println("Eating");

    }

}

class Dog extends Animal {

    void bark() {

        System.out.println("Barking");

    }

}
```

### B. Multilevel Inheritance

A class inherits from another child class, forming multiple levels.

```text
        Animal
           |
           v
         Mammal
           |
           v
           Dog
```

Example:

```java
class Animal {

    void eat() {

        System.out.println("Eating");

    }

}

class Mammal extends Animal {

    void walk() {

        System.out.println("Walking");

    }

}

class Dog extends Mammal {

    void bark() {

        System.out.println("Barking");

    }

}
```

### C. Hierarchical Inheritance

Multiple child classes inherit from the same parent class.

```text
             Animal
                |
        -----------------
        |       |       |
        v       v       v
       Dog     Cat     Cow
```

Example:

```java
class Animal {

    void eat() {

        System.out.println("Eating");

    }

}

class Dog extends Animal {

    void bark() {

        System.out.println("Dog barking");

    }

}

class Cat extends Animal {

    void meow() {

        System.out.println("Cat meowing");

    }

}
```

### D. Multiple Inheritance

Multiple inheritance means inheriting from more than one parent class.

Java does not support multiple inheritance of classes.

The following is invalid:

```java
class A {

}

class B {

}

// Invalid Java syntax
// class C extends A, B {
//
// }
```

However, Java supports multiple inheritance of type through interfaces.

Example:

```java
interface Camera {

    void clickPhoto();

}

interface MusicPlayer {

    void playMusic();

}

class Smartphone implements Camera, MusicPlayer {

    public void clickPhoto() {

        System.out.println("Photo clicked");

    }

    public void playMusic() {

        System.out.println("Music playing");

    }

}
```

### E. Hybrid Inheritance

Hybrid inheritance combines multiple inheritance structures.

Java does not support arbitrary hybrid inheritance through classes because multiple class inheritance is not allowed.

Some hybrid structures can be achieved using interfaces.

## 8.4 Types of Inheritance Summary

| Type | Meaning | Supported in Java Classes? |
|---|---|---|
| Single | One parent, one child | Yes |
| Multilevel | Inheritance across multiple levels | Yes |
| Hierarchical | Multiple children, one parent | Yes |
| Multiple | One child, multiple parents | No |
| Hybrid | Combination of inheritance types | Possible using interfaces |

## 8.5 Method Overriding

Method overriding occurs when a subclass provides its own implementation of an inherited instance method.

Example:

```java
class Animal {

    void sound() {

        System.out.println("Animal makes sound");

    }

}

class Dog extends Animal {

    @Override
    void sound() {

        System.out.println("Dog barks");

    }

}

class Main {

    public static void main(String[] args) {

        Dog d = new Dog();

        d.sound();

    }
}
```

Output:

```text
Dog barks
```

Explanation:

- `Animal` defines `sound()`.
- `Dog` overrides `sound()`.
- The Dog object's implementation executes.

## 8.6 super Keyword

The `super` keyword refers to the immediate parent class.

It can be used to:

1. Access parent-class fields.
2. Call parent-class methods.
3. Call parent-class constructors.

Example:

```java
class Animal {

    void sound() {

        System.out.println("Animal sound");

    }

}

class Dog extends Animal {

    void sound() {

        super.sound();

        System.out.println("Dog barks");

    }

}

class Main {

    public static void main(String[] args) {

        Dog d = new Dog();

        d.sound();

    }
}
```

Output:

```text
Animal sound
Dog barks
```

---

# 9. Polymorphism

## 9.1 What is Polymorphism?

Polymorphism means **many forms**.

In OOP, polymorphism allows the same method name or common reference type to represent different behaviours depending on the situation.

For example:

A `Payment` operation can be performed using:

- UPI.
- Credit Card.
- Debit Card.
- Net Banking.

The operation is payment, but the implementation differs.

## 9.2 Types of Polymorphism in Java

Two commonly studied forms are:

1. Compile-Time Polymorphism.
2. Runtime Polymorphism.

## 9.3 Compile-Time Polymorphism

Compile-time polymorphism is commonly achieved using method overloading.

The compiler determines which overloaded method to call based on the method arguments.

Example:

```java
class Calculator {

    int add(int a, int b) {

        return a + b;

    }

    int add(int a, int b, int c) {

        return a + b + c;

    }

    double add(double a, double b) {

        return a + b;

    }

    public static void main(String[] args) {

        Calculator c = new Calculator();

        System.out.println(c.add(10, 20));

        System.out.println(c.add(10, 20, 30));

        System.out.println(c.add(10.5, 20.5));

    }
}
```

Output:

```text
30
60
31.0
```

Explanation:

The same method name `add()` performs different operations depending on the arguments.

## 9.4 Runtime Polymorphism

Runtime polymorphism is commonly achieved through method overriding.

The actual overridden method is selected according to the runtime object type.

Example:

```java
class Animal {

    void sound() {

        System.out.println("Animal makes sound");

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

class Main {

    public static void main(String[] args) {

        Animal a;

        a = new Dog();

        a.sound();

        a = new Cat();

        a.sound();

    }
}
```

Output:

```text
Dog barks
Cat meows
```

Explanation:

```java
Animal a;
```

The reference type is `Animal`.

```java
a = new Dog();
```

The runtime object is `Dog`.

```java
a.sound();
```

The overridden `Dog` implementation executes.

Later:

```java
a = new Cat();
```

The same reference variable refers to a Cat object, so the Cat implementation executes.

This is runtime polymorphism.

## 9.5 Method Overloading vs Method Overriding

| Method Overloading | Method Overriding |
|---|---|
| Same method name with different parameter lists | Subclass redefines an inherited method |
| Commonly occurs within the same class | Requires inheritance or an overriding relationship |
| Compile-time polymorphism | Runtime polymorphism |
| Parameters must differ | Parameter list must match the overridden method |
| Return type alone cannot distinguish overloads | Return type must be compatible, including covariant returns |
| Inheritance is not required | Inheritance or an equivalent subtype relationship is required |

## 9.6 Advantages of Polymorphism

1. Code flexibility.
2. Reusability.
3. Easier extension.
4. Supports common interfaces.
5. Reduces dependence on specific implementation classes.

---

# 10. All Four OOP Principles – Comparison

| Principle | Meaning | Main Java Mechanism |
|---|---|---|
| Encapsulation | Bundling data and methods with controlled access | private fields, getters and setters |
| Abstraction | Hiding implementation details | Abstract classes and interfaces |
| Inheritance | Reusing accessible parent-class functionality | extends and implements |
| Polymorphism | One interface or method name, multiple behaviours | Overloading and overriding |

### Easy Way to Remember

- Encapsulation = Protect Data.
- Abstraction = Hide Implementation.
- Inheritance = Reuse Code.
- Polymorphism = Many Forms.

---

# 11. Lab Practical – Create a Student Class

## Problem Statement

Create a `Student` class with attributes such as:

- Roll Number.
- Name.
- Marks.

Create objects of the class and display student details.

## 11.1 Algorithm

1. Create a class named `Student`.
2. Declare instance variables `rollNo`, `name` and `marks`.
3. Create a method named `displayDetails()`.
4. Create objects of the Student class.
5. Assign values to each object.
6. Call `displayDetails()` for each object.
7. Display student information.

## 11.2 Java Program

```java
class Student {

    // Instance variables

    int rollNo;

    String name;

    double marks;

    // Method to display student details

    void displayDetails() {

        System.out.println("Student Details");

        System.out.println("Roll Number: " + rollNo);

        System.out.println("Name: " + name);

        System.out.println("Marks: " + marks);

        System.out.println("----------------------");

    }

    public static void main(String[] args) {

        // Creating first object

        Student s1 = new Student();

        s1.rollNo = 101;

        s1.name = "Anurag";

        s1.marks = 85.5;

        // Creating second object

        Student s2 = new Student();

        s2.rollNo = 102;

        s2.name = "Rahul";

        s2.marks = 90.0;

        // Creating third object

        Student s3 = new Student();

        s3.rollNo = 103;

        s3.name = "Priya";

        s3.marks = 92.5;

        // Displaying details

        s1.displayDetails();

        s2.displayDetails();

        s3.displayDetails();

    }
}
```

## 11.3 Expected Output

```text
Student Details
Roll Number: 101
Name: Anurag
Marks: 85.5
----------------------
Student Details
Roll Number: 102
Name: Rahul
Marks: 90.0
----------------------
Student Details
Roll Number: 103
Name: Priya
Marks: 92.5
----------------------
```

## 11.4 Program Explanation

### Step 1: Create a Class

```java
class Student {
```

Defines a class named Student.

### Step 2: Declare Instance Variables

```java
int rollNo;

String name;

double marks;
```

These variables represent the properties of each student.

### Step 3: Create a Method

```java
void displayDetails() {
```

This method displays student information.

### Step 4: Create Objects

```java
Student s1 = new Student();

Student s2 = new Student();

Student s3 = new Student();
```

Three different Student objects are created.

### Step 5: Assign Values

```java
s1.rollNo = 101;

s1.name = "Anurag";

s1.marks = 85.5;
```

The values are assigned to the first student object.

### Step 6: Call Methods

```java
s1.displayDetails();
```

The method displays the information belonging to `s1`.

## 11.5 Memory Concept

Conceptually, the three objects have separate instance state.

```text
          STACK / REFERENCES             HEAP
          ------------------       -------------------
          | s1             | ----> | Student Object 1 |
          |                |       | rollNo = 101     |
          |                |       | name = Anurag    |
          |                |       | marks = 85.5     |
          ------------------       -------------------

          | s2             | ----> | Student Object 2 |
          |                |       | rollNo = 102     |
          |                |       | name = Rahul     |
          |                |       | marks = 90.0     |
          ------------------       -------------------

          | s3             | ----> | Student Object 3 |
          |                |       | rollNo = 103     |
          |                |       | name = Priya     |
          |                |       | marks = 92.5     |
          ------------------       -------------------
```

Each reference points to a different object.

Therefore, changing `s1.name` does not directly change `s2.name`.

---

# 12. Additional Student Class Practical Using Constructor

The previous practical can be improved by using a constructor.

A constructor initializes an object when it is created.

## Java Program

```java
class Student {

    int rollNo;

    String name;

    double marks;

    // Constructor

    Student(int rollNo, String name, double marks) {

        this.rollNo = rollNo;

        this.name = name;

        this.marks = marks;

    }

    // Display method

    void displayDetails() {

        System.out.println("Roll No: " + rollNo);

        System.out.println("Name: " + name);

        System.out.println("Marks: " + marks);

        System.out.println("----------------");

    }

    public static void main(String[] args) {

        Student s1 = new Student(101, "Anurag", 85.5);

        Student s2 = new Student(102, "Rahul", 90.0);

        s1.displayDetails();

        s2.displayDetails();

    }
}
```

Output:

```text
Roll No: 101
Name: Anurag
Marks: 85.5
----------------
Roll No: 102
Name: Rahul
Marks: 90.0
----------------
```

### Understanding this Keyword

```java
this.rollNo = rollNo;
```

Here:

- `this.rollNo` refers to the instance variable.
- `rollNo` refers to the constructor parameter.

The `this` keyword distinguishes instance variables from local variables or parameters having the same name.

---

# 13. Additional Practical – Student Encapsulation

Create a Student class using private attributes and getter/setter methods.

```java
class Student {

    private int rollNo;

    private String name;

    private double marks;

    public void setRollNo(int rollNo) {

        this.rollNo = rollNo;

    }

    public void setName(String name) {

        this.name = name;

    }

    public void setMarks(double marks) {

        if (marks >= 0 && marks <= 100) {

            this.marks = marks;

        }
        else {

            System.out.println("Invalid Marks");

        }

    }

    public int getRollNo() {

        return rollNo;

    }

    public String getName() {

        return name;

    }

    public double getMarks() {

        return marks;

    }

    public static void main(String[] args) {

        Student s = new Student();

        s.setRollNo(101);

        s.setName("Anurag");

        s.setMarks(88.5);

        System.out.println("Roll No: " + s.getRollNo());

        System.out.println("Name: " + s.getName());

        System.out.println("Marks: " + s.getMarks());

    }
}
```

Output:

```text
Roll No: 101
Name: Anurag
Marks: 88.5
```

**Learning Outcome:** This program demonstrates classes, objects, encapsulation, private variables, getters and setters.

---

# 14. Important Interview Questions

### Q1. What is OOP?

OOP is a programming paradigm that organizes software around classes and objects containing data and behaviour.

### Q2. What are the four pillars of OOP?

Encapsulation, Abstraction, Inheritance and Polymorphism.

### Q3. What is a class?

A class is a blueprint used to create objects.

### Q4. What is an object?

An object is an instance of a class.

### Q5. What are the three characteristics of an object?

State, behaviour and identity.

### Q6. What is encapsulation?

Encapsulation bundles data and related methods into a class and controls access to the internal data.

### Q7. How is encapsulation implemented in Java?

Commonly using private variables and public getter/setter methods.

### Q8. What is abstraction?

Abstraction hides implementation details and exposes essential functionality.

### Q9. How is abstraction achieved in Java?

Using abstract classes and interfaces.

### Q10. Can we create an object of an abstract class?

No, an abstract class cannot be instantiated directly.

### Q11. Can an abstract class have a constructor?

Yes. Its constructor executes as part of subclass object construction.

### Q12. What is an interface?

An interface defines a contract that implementing classes follow.

### Q13. What is inheritance?

Inheritance allows a subclass to acquire accessible members and behaviour from a superclass.

### Q14. Which keyword is used for class inheritance?

`extends`.

### Q15. Does Java support multiple inheritance using classes?

No. A class cannot directly extend multiple classes.

### Q16. Does Java support multiple inheritance using interfaces?

Yes. A class can implement multiple interfaces.

### Q17. What is polymorphism?

Polymorphism allows a common method name or reference type to represent different behaviours.

### Q18. What are the types of polymorphism?

Compile-time and runtime polymorphism.

### Q19. What is method overloading?

Defining methods with the same name but different parameter lists.

### Q20. What is method overriding?

Providing a subclass implementation of an inherited instance method.

### Q21. What is the difference between overloading and overriding?

Overloading changes the parameter list, whereas overriding provides a new implementation of an inherited method.

### Q22. What is the super keyword?

It refers to the immediate parent class.

### Q23. What is the this keyword?

It refers to the current object.

### Q24. Can one class create multiple objects?

Yes. One class can be used to create multiple objects.

### Q25. What happens when two different objects have separate instance variables?

Each object maintains its own instance state.

### Q26. Can a child class override a static method?

Static methods are not overridden in the runtime-polymorphism sense. A subclass can hide an inherited static method.

### Q27. Is Java a purely object-oriented programming language?

No. Java has primitive data types such as int, char and boolean, so it is not purely object-oriented.

### Q28. Can a constructor be inherited?

No. Constructors are not inherited by subclasses.

### Q29. What is code reusability?

Code reusability means using existing code in multiple places rather than writing the same logic repeatedly.

### Q30. What is the difference between abstraction and encapsulation?

Abstraction hides implementation complexity, while encapsulation bundles data and methods and controls access to internal state.

---

# 15. CMCE Practice MCQs

### Q1. What does OOP stand for?

A. Object Operating Program  
B. Object-Oriented Programming  
C. Operational Object Programming  
D. Object Output Programming  

**Answer: B. Object-Oriented Programming**

### Q2. Which is a blueprint for creating objects?

A. Method  
B. Constructor  
C. Class  
D. Variable  

**Answer: C. Class**

### Q3. An object is an instance of which of the following?

A. Method  
B. Class  
C. Package  
D. Operator  

**Answer: B. Class**

### Q4. Which keyword is used to create an object?

A. class  
B. object  
C. new  
D. create  

**Answer: C. new**

### Q5. Which OOP principle provides controlled access to data?

A. Inheritance  
B. Polymorphism  
C. Encapsulation  
D. Abstraction  

**Answer: C. Encapsulation**

### Q6. Which keyword is commonly used to restrict direct access to class members?

A. public  
B. private  
C. static  
D. final  

**Answer: B. private**

### Q7. Which OOP principle hides implementation details?

A. Abstraction  
B. Inheritance  
C. Encapsulation  
D. Overloading  

**Answer: A. Abstraction**

### Q8. Which Java feature supports abstraction?

A. Loops  
B. Interfaces  
C. Operators  
D. Arrays  

**Answer: B. Interfaces**

### Q9. Which keyword is used for class inheritance?

A. implements  
B. extends  
C. inherits  
D. super  

**Answer: B. extends**

### Q10. Does Java support multiple inheritance of classes?

A. Yes  
B. No  
C. Only with static classes  
D. Only with final classes  

**Answer: B. No**

### Q11. Which keyword is used to implement an interface?

A. extends  
B. implements  
C. interface  
D. abstract  

**Answer: B. implements**

### Q12. Polymorphism means:

A. One class only  
B. Data hiding  
C. Many forms  
D. Code compilation  

**Answer: C. Many forms**

### Q13. Method overloading is an example of:

A. Compile-time polymorphism  
B. Runtime polymorphism  
C. Encapsulation  
D. Inheritance  

**Answer: A. Compile-time polymorphism**

### Q14. Method overriding is commonly associated with:

A. Compile-time polymorphism  
B. Runtime polymorphism  
C. Constructor overloading  
D. Variable declaration  

**Answer: B. Runtime polymorphism**

### Q15. Which keyword refers to the current object?

A. super  
B. static  
C. this  
D. final  

**Answer: C. this**

### Q16. Which keyword refers to the immediate parent class?

A. this  
B. super  
C. parent  
D. base  

**Answer: B. super**

### Q17. Which method is used to retrieve a private variable's value?

A. Setter  
B. Getter  
C. Constructor  
D. Main  

**Answer: B. Getter**

### Q18. Which of the following cannot be directly instantiated?

A. Concrete class  
B. Abstract class  
C. Normal class  
D. Public class  

**Answer: B. Abstract class**

### Q19. Which statement is correct?

A. Every class can have multiple parent classes.  
B. An object is a blueprint.  
C. A class can create multiple objects.  
D. Java has no polymorphism.  

**Answer: C. A class can create multiple objects.**

### Q20. Which of these is not one of the four major OOP principles?

A. Encapsulation  
B. Abstraction  
C. Inheritance  
D. Compilation  

**Answer: D. Compilation**

---

# 16. Output-Based Questions

## Question 1: Multiple Objects

```java
class Student {

    int rollNo;

    public static void main(String[] args) {

        Student s1 = new Student();

        Student s2 = new Student();

        s1.rollNo = 101;

        s2.rollNo = 102;

        System.out.println(s1.rollNo);

        System.out.println(s2.rollNo);

    }
}
```

Output:

```text
101
102
```

Reason: Each object maintains its own instance variable.

## Question 2: Method Overloading

```java
class Demo {

    void display(int a) {

        System.out.println("Integer");

    }

    void display(String a) {

        System.out.println("String");

    }

    public static void main(String[] args) {

        Demo d = new Demo();

        d.display(10);

        d.display("Java");

    }
}
```

Output:

```text
Integer
String
```

Reason: The compiler selects the overloaded method based on the argument type.

## Question 3: Method Overriding

```java
class Animal {

    void sound() {

        System.out.println("Animal");

    }

}

class Dog extends Animal {

    @Override
    void sound() {

        System.out.println("Dog");

    }

}

class Main {

    public static void main(String[] args) {

        Animal a = new Dog();

        a.sound();

    }
}
```

Output:

```text
Dog
```

Reason: Runtime method dispatch selects the overridden method of the actual object.

## Question 4: Encapsulation

```java
class Demo {

    private int value = 10;

    int getValue() {

        return value;

    }

    public static void main(String[] args) {

        Demo d = new Demo();

        System.out.println(d.getValue());

    }
}
```

Output:

```text
10
```

Reason: The getter method provides access to the private variable.

## Question 5: Inheritance

```java
class A {

    void display() {

        System.out.println("Class A");

    }

}

class B extends A {

}

class Main {

    public static void main(String[] args) {

        B obj = new B();

        obj.display();

    }
}
```

Output:

```text
Class A
```

Reason: Class B inherits the accessible display method from class A.

---

# 17. Quick Revision Notes

| Topic | Important Point |
|---|---|
| OOP | Object-Oriented Programming |
| Class | Blueprint for creating objects |
| Object | Instance of a class |
| State | Object's data |
| Behaviour | Object's methods |
| Identity | Distinguishes one object from another |
| Encapsulation | Bundling and controlled data access |
| Abstraction | Hiding implementation details |
| Inheritance | Reusing parent-class functionality |
| Polymorphism | Many forms |
| private | Restricts direct access |
| public | Provides accessible members |
| Getter | Retrieves private field value |
| Setter | Modifies private field value |
| Abstract Class | Cannot be instantiated directly |
| Interface | Defines a contract |
| extends | Used for class inheritance |
| implements | Used to implement interfaces |
| this | Refers to current object |
| super | Refers to immediate parent class |
| Overloading | Same name, different parameters |
| Overriding | Subclass implementation of inherited method |
| Compile-Time Polymorphism | Method overloading |
| Runtime Polymorphism | Method overriding |
| Java Multiple Class Inheritance | Not supported |
| Multiple Interface Implementation | Supported |

---

# 18. Practice Checklist

## Theory Preparation

- [ ] Understand the meaning of OOP.
- [ ] Understand why OOP is needed.
- [ ] Learn procedural vs object-oriented programming.
- [ ] Understand classes and objects.
- [ ] Learn object state, behaviour and identity.
- [ ] Understand object creation using `new`.
- [ ] Understand Encapsulation.
- [ ] Understand Abstraction.
- [ ] Learn abstract classes and interfaces.
- [ ] Understand Inheritance.
- [ ] Learn different types of inheritance.
- [ ] Understand Polymorphism.
- [ ] Practise method overloading.
- [ ] Practise method overriding.
- [ ] Understand `this` and `super`.

## Lab Preparation

- [ ] Create a Student class.
- [ ] Declare roll number, name and marks.
- [ ] Create multiple Student objects.
- [ ] Assign values to objects.
- [ ] Display student details.
- [ ] Create a Student class using a constructor.
- [ ] Implement encapsulation using private fields.
- [ ] Write getters and setters.
- [ ] Create an example of inheritance.
- [ ] Create an example of method overriding.

## Self Learning

- [ ] Practise OOP interview questions.
- [ ] Solve all MCQs.
- [ ] Practise output-based questions.
- [ ] Draw class and object diagrams.
- [ ] Explain all four OOP principles using real-world examples.
- [ ] Upload your practical programs to GitHub.

---

# 19. Additional Practice Assignments

1. Create an Employee class with employee ID, name and salary.
2. Create a BankAccount class with deposit and withdraw methods.
3. Create a Rectangle class with length, breadth and area calculation.
4. Create a Vehicle parent class and Car child class.
5. Create an Animal class and override its sound method in Dog and Cat classes.
6. Create a Calculator class demonstrating method overloading.
7. Create an abstract Shape class with an area method.
8. Create a Payment interface with UPI and Card implementations.
9. Create a Student class with private variables and validation in setters.
10. Create a Person class and derive Student and Teacher classes from it.

---

# 20. Final CMCE Preparation Focus

Give special attention to these concepts:

1. Difference between class and object.
2. Object state, behaviour and identity.
3. Object creation using the `new` keyword.
4. Encapsulation using private variables and getter/setter methods.
5. Abstraction using abstract classes and interfaces.
6. Inheritance using `extends`.
7. Multiple inheritance through interfaces.
8. Compile-time vs runtime polymorphism.
9. Method overloading vs method overriding.
10. `this` and `super` keywords.
11. Student class practical with multiple objects.

---

# References

- Java 17 Documentation: https://docs.oracle.com/en/java/javase/17/
- Java Language Specification: https://docs.oracle.com/javase/specs/jls/se17/html/
- Java Learning Resources: https://dev.java/learn/
- OpenJDK: https://openjdk.org/

---

**End of Session 4 – Object-Oriented Programming Concepts**

⭐ Keep Learning, Keep Coding and Keep Practising!

**Next Session:** Session 5 – Static Members and Object References.
