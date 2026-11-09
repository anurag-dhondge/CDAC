# Session 5: Static Members and Object References in Java

**Course:** CMCE – August 2026 Batch  
**Subject:** Java Programming  
**Session:** 5  
**Duration:** 2 Theory + 2 Lab Hours

---

## 📚 Table of Contents

1. [Static Members in Java](#1-static-members-in-java)
2. [Static Variables](#2-static-variables)
3. [Static Methods](#3-static-methods)
4. [Accessing Static Members of Another Class](#4-accessing-static-members-of-another-class)
5. [Introduction to Reference Data Types](#5-introduction-to-reference-data-types)
6. [Reference Variables and Methods](#6-reference-variables-and-methods)
7. [Primitive Data Types vs Reference Data Types](#7-primitive-data-types-vs-reference-data-types)
8. [Reference Variable vs Static Variable](#8-reference-variable-vs-static-variable)
9. [Lab Practical 1: Student Class](#9-lab-practical-1-student-class)
10. [Lab Practical 2: BankAccount Class](#10-lab-practical-2-bankaccount-class)
11. [Important Interview Questions](#11-important-interview-questions)
12. [MCQs](#12-multiple-choice-questions)
13. [Quick Revision Notes](#13-quick-revision-notes)

---

# 1. Static Members in Java

## What is the `static` keyword?

In Java, the `static` keyword is used to define members that belong to the **class rather than individual objects**.

A static member is shared among all objects of that class.

Normally, instance variables and instance methods belong to individual objects. However, static variables and static methods belong to the class itself.

### Example from real life

Consider a college with 100 students.

Each student has:
- Different roll number.
- Different name.
- Same college name.

Instead of storing the college name separately for every student, we can declare it as a static variable.

### Types of static members

| Static Member | Description |
|---|---|
| Static Variable | A single shared variable for all objects. |
| Static Method | A method that belongs to the class. |
| Static Block | A block executed once when the class is initialized. |
| Static Nested Class | A nested class declared using `static`. |

**For this session, our main focus is static variables and static methods.**

---

# 2. Static Variables

## What is a Static Variable?

A static variable is a variable declared using the `static` keyword inside a class but outside methods, constructors, and blocks.

It is also called:
- Class Variable
- Static Data Member

### Syntax

```java
class ClassName {
    static dataType variableName;
}
```

### Example

```java
class Student {

    int rollNo;
    String name;

    static String collegeName = "IACSD";

}
```

Here:
- `rollNo` is an instance variable.
- `name` is an instance variable.
- `collegeName` is a static variable.

### Memory Concept

Suppose we create three Student objects.

```java
Student s1 = new Student();
Student s2 = new Student();
Student s3 = new Student();
```

Each object has its own instance variables, but all objects share the same static variable.

```text
                  Student Class
              ---------------------
              static collegeName
                    "IACSD"
                       |
          -------------|-------------
          |            |            |
       Student s1   Student s2   Student s3
       ---------    ---------    ---------
       rollNo       rollNo       rollNo
       name         name         name
```

### Important Characteristics

1. A static variable belongs to the class.
2. Only one shared copy exists per class loader.
3. All objects share the same static variable.
4. It can be accessed using the class name.
5. It can be accessed without creating an object.
6. It receives a default value if not explicitly initialized.

### Example: Static Variable

```java
class Student {

    int rollNo;
    String name;

    static String collegeName = "IACSD";

    void display() {

        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("College: " + collegeName);

    }
}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();
        s1.rollNo = 101;
        s1.name = "Anurag";

        Student s2 = new Student();
        s2.rollNo = 102;
        s2.name = "Rahul";

        s1.display();
        System.out.println();

        s2.display();

    }
}
```

### Output

```text
Roll No: 101
Name: Anurag
College: IACSD

Roll No: 102
Name: Rahul
College: IACSD
```

Notice that both objects display the same college name.

---

# 3. Static Methods

## What is a Static Method?

A static method is a method declared using the `static` keyword.

It belongs to the class rather than an individual object.

A static method can be called directly using the class name without creating an object.

### Syntax

```java
class ClassName {

    static void methodName() {

        // Statements

    }

}
```

### Example

```java
class Student {

    static String collegeName = "IACSD";

    static void displayCollege() {

        System.out.println("College Name: " + collegeName);

    }
}

public class Main {

    public static void main(String[] args) {

        Student.displayCollege();

    }
}
```

### Output

```text
College Name: IACSD
```

### Important Rules of Static Methods

1. Static methods belong to the class.
2. They can be called using the class name.
3. They can directly access static variables.
4. They cannot directly access instance variables.
5. They cannot directly call instance methods.
6. They cannot use `this` or `super` directly because these refer to an object or parent-object context.

### Why can't a static method access instance variables directly?

Consider:

```java
class Student {

    int rollNo = 101;

    static void display() {

        // System.out.println(rollNo); // Error

    }

}
```

**Reason:** An instance variable belongs to an object. A static method can execute without any object being created, so Java cannot determine which object's `rollNo` should be accessed.

### Correct Approach

Pass an object reference to the static method.

```java
class Student {

    int rollNo = 101;

    static void display(Student s) {

        System.out.println("Roll No: " + s.rollNo);

    }

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();

        Student.display(s1);

    }
}
```

### Output

```text
Roll No: 101
```

---

# 4. Accessing Static Members of Another Class

Static variables and methods of another class can be accessed using the class name.

### Syntax

```java
ClassName.staticVariable;

ClassName.staticMethod();
```

### Example

```java
class College {

    static String collegeName = "IACSD";

    static void displayCollege() {

        System.out.println(collegeName);

    }
}

public class Main {

    public static void main(String[] args) {

        System.out.println(College.collegeName);

        College.displayCollege();

    }
}
```

### Output

```text
IACSD
IACSD
```

### Explanation

- `College.collegeName` accesses the static variable.
- `College.displayCollege()` calls the static method.
- No College object is required.

### Accessing static members using an object

Java also permits static members to be accessed through an object reference.

```java
College c1 = new College();

System.out.println(c1.collegeName);
c1.displayCollege();
```

However, this is not recommended because static members belong to the class.

**Best practice: Always use the class name to access static members.**

---

# 5. Introduction to Reference Data Types

## What is a Reference Data Type?

A reference data type is a data type that stores a reference to an object rather than directly storing the object's actual data.

When we create an object using the `new` keyword, Java creates the object and returns a reference that can be stored in a reference variable.

### Example

```java
class Student {

    int rollNo;
    String name;

}

public class Main {

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

### Understanding the statement

```java
Student s1 = new Student();
```

It has three important parts:

| Part | Meaning |
|---|---|
| `Student` | Reference data type |
| `s1` | Reference variable |
| `new Student()` | Creates a Student object |

The variable `s1` holds a reference to the created Student object.

### Types of Reference Data Types

Common reference types include:

1. Class
2. Interface
3. Array
4. String
5. Enum
6. Record

### Examples

```java
// Class reference
Student s1 = new Student();

// String reference
String name = "Anurag";

// Array reference
int[] numbers = {10, 20, 30};

// Interface reference
Runnable r;

// Enum reference
Day today = Day.MONDAY;
```

---

# 6. Reference Variables and Methods

## What is a Reference Variable?

A reference variable is a variable that stores a reference to an object.

It allows us to access the object's variables and methods.

### Example

```java
class Student {

    int rollNo = 101;

    void display() {

        System.out.println("Roll No: " + rollNo);

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
Roll No: 101
```

Here:
- `s1` is a reference variable.
- `s1.display()` calls the object's method.
- `s1.rollNo` accesses the object's instance variable.

## Multiple Reference Variables Pointing to the Same Object

Java allows multiple reference variables to refer to the same object.

### Example

```java
class Student {

    int rollNo = 101;

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();

        Student s2 = s1;

        s2.rollNo = 200;

        System.out.println(s1.rollNo);
        System.out.println(s2.rollNo);

    }
}
```

### Output

```text
200
200
```

### Explanation

```java
Student s1 = new Student();

Student s2 = s1;
```

Both `s1` and `s2` refer to the same Student object.

Changing the object's data using `s2` is visible through `s1` as well.

```text
       s1 --------\
                   \
                    ---> Student Object
                   /       rollNo = 200
       s2 --------/
```

**Important:** `s2 = s1` does not create a new object. It copies the reference.

## Reference Variable with null

A reference variable can hold `null`, which means it does not currently refer to any object.

```java
Student s1 = null;
```

If we try to access a method through a null reference:

```java
s1.display();
```

Java throws a `NullPointerException` at runtime.

---

# 7. Primitive Data Types vs Reference Data Types

Java data types are broadly classified into two categories.

1. Primitive Data Types
2. Reference Data Types

### Primitive Data Types

Primitive data types store simple values directly.

Java has eight primitive data types:

| Data Type | Example |
|---|---|
| `byte` | `byte a = 10;` |
| `short` | `short b = 100;` |
| `int` | `int c = 1000;` |
| `long` | `long d = 10000L;` |
| `float` | `float e = 10.5f;` |
| `double` | `double f = 20.5;` |
| `char` | `char g = 'A';` |
| `boolean` | `boolean h = true;` |

### Reference Data Types

Reference types hold references to objects.

Examples:

```java
String name = "Anurag";

Student s1 = new Student();

int[] arr = {10, 20, 30};
```

### Comparison

| Primitive Data Types | Reference Data Types |
|---|---|
| Store primitive values. | Store references to objects. |
| Have eight built-in types. | Include classes, arrays, interfaces, etc. |
| Cannot be assigned `null`. | Can be assigned `null`. |
| Cannot call methods directly on the primitive value. | Can access object methods through a reference. |
| Have fixed sizes defined by Java. | Object sizes depend on the object and JVM implementation. |
| Examples: `int`, `char`, `double`. | Examples: `String`, `Student`, arrays. |

### Example

```java
public class Main {

    public static void main(String[] args) {

        int a = 10;
        int b = a;

        b = 20;

        System.out.println(a);
        System.out.println(b);

    }
}
```

Output:

```text
10
20
```

Each primitive variable has its own value.

Now consider reference variables:

```java
class Box {

    int value;

}

public class Main {

    public static void main(String[] args) {

        Box b1 = new Box();

        b1.value = 10;

        Box b2 = b1;

        b2.value = 20;

        System.out.println(b1.value);
        System.out.println(b2.value);

    }
}
```

Output:

```text
20
20
```

Both references point to the same object.

---

# 8. Reference Variable vs Static Variable

These two concepts are different.

A reference variable stores a reference to an object, whereas a static variable is a class-level variable shared by all objects.

### Comparison

| Reference Variable | Static Variable |
|---|---|
| Stores a reference to an object. | Stores a class-level value. |
| Can refer to an object. | Belongs to the class. |
| Can hold `null`. | Can hold `null` if its declared type permits it. |
| Declared using a reference type. | Declared using the `static` keyword. |
| Used to access object members. | Used to store shared class-level information. |
| Example: `Student s1;` | Example: `static String collegeName;` |

### Example

```java
class Student {

    int rollNo;

    static String collegeName = "IACSD";

}

public class Main {

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.rollNo = 101;

        System.out.println(s1.rollNo);

        System.out.println(Student.collegeName);

    }
}
```

Output:

```text
101
IACSD
```

Here:
- `s1` is a reference variable.
- `collegeName` is a static variable.

---

# 9. Lab Practical 1: Student Class

## Problem Statement

Create a class `Student` with:

- Instance variables: `rollNo`, `name`
- Static variable: `collegeName`

Demonstrate that all objects share the same static variable.

Create a static method to display the college name.

## Program

**StudentDemo.java**

```java
class Student {

    // Instance variables
    int rollNo;
    String name;

    // Static variable
    static String collegeName = "IACSD";

    // Instance method
    void displayStudent() {

        System.out.println("Roll Number: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("College Name: " + collegeName);

    }

    // Static method
    static void displayCollegeName() {

        System.out.println("College: " + collegeName);

    }

}

public class StudentDemo {

    public static void main(String[] args) {

        // First student
        Student s1 = new Student();

        s1.rollNo = 101;
        s1.name = "Anurag";

        // Second student
        Student s2 = new Student();

        s2.rollNo = 102;
        s2.name = "Rahul";

        // Third student
        Student s3 = new Student();

        s3.rollNo = 103;
        s3.name = "Amit";

        System.out.println("Student Details:");

        s1.displayStudent();

        System.out.println();

        s2.displayStudent();

        System.out.println();

        s3.displayStudent();

        System.out.println();

        // Access static method using class name
        Student.displayCollegeName();

        System.out.println("\nChanging College Name...");

        // Change static variable
        Student.collegeName = "CDAC Pune";

        System.out.println();

        // All objects now show the updated college name
        s1.displayStudent();

        System.out.println();

        s2.displayStudent();

        System.out.println();

        s3.displayStudent();

    }

}
```

## Output

```text
Student Details:
Roll Number: 101
Name: Anurag
College Name: IACSD

Roll Number: 102
Name: Rahul
College Name: IACSD

Roll Number: 103
Name: Amit
College Name: IACSD

College: IACSD

Changing College Name...

Roll Number: 101
Name: Anurag
College Name: CDAC Pune

Roll Number: 102
Name: Rahul
College Name: CDAC Pune

Roll Number: 103
Name: Amit
College Name: CDAC Pune
```

## Explanation

- `rollNo` and `name` are instance variables.
- Every Student object gets its own `rollNo` and `name`.
- `collegeName` is static, so it is shared by all Student objects.
- `displayCollegeName()` is static and can be called using `Student.displayCollegeName()`.
- When we change `Student.collegeName`, the updated value is visible through all objects.

### Important Observation

```java
Student.collegeName = "CDAC Pune";
```

This modifies the single shared static variable. It does not modify three separate copies.

---

# 10. Lab Practical 2: BankAccount Class

## Problem Statement

Create a class `BankAccount` with:

- Account number and balance as instance variables.
- Bank name as a static variable.

Demonstrate that changing the bank name affects all account objects.

## Program

**BankAccountDemo.java**

```java
class BankAccount {

    // Instance variables
    long accountNumber;
    double balance;

    // Static variable
    static String bankName = "State Bank of India";

    // Constructor
    BankAccount(long accountNumber, double balance) {

        this.accountNumber = accountNumber;
        this.balance = balance;

    }

    // Instance method
    void displayAccountDetails() {

        System.out.println("Account Number: " + accountNumber);
        System.out.println("Balance: " + balance);
        System.out.println("Bank Name: " + bankName);

    }

    // Static method
    static void displayBankName() {

        System.out.println("Bank Name: " + bankName);

    }

}

public class BankAccountDemo {

    public static void main(String[] args) {

        // Creating bank account objects
        BankAccount a1 = new BankAccount(123456789, 50000);
        BankAccount a2 = new BankAccount(987654321, 75000);

        System.out.println("Account Details:");

        a1.displayAccountDetails();

        System.out.println();

        a2.displayAccountDetails();

        System.out.println();

        // Display static variable using static method
        BankAccount.displayBankName();

        System.out.println("\nChanging Bank Name...");

        // Updating static variable
        BankAccount.bankName = "HDFC Bank";

        System.out.println();

        // Display updated details
        a1.displayAccountDetails();

        System.out.println();

        a2.displayAccountDetails();

    }

}
```

## Output

```text
Account Details:
Account Number: 123456789
Balance: 50000.0
Bank Name: State Bank of India

Account Number: 987654321
Balance: 75000.0
Bank Name: State Bank of India

Bank Name: State Bank of India

Changing Bank Name...

Account Number: 123456789
Balance: 50000.0
Bank Name: HDFC Bank

Account Number: 987654321
Balance: 75000.0
Bank Name: HDFC Bank
```

## Explanation

| Variable | Type | Reason |
|---|---|---|
| `accountNumber` | Instance | Each account has a different account number. |
| `balance` | Instance | Each account has a different balance. |
| `bankName` | Static | All accounts share the same bank name. |

### Key Statement

```java
BankAccount.bankName = "HDFC Bank";
```

Changing the static variable through the class name updates the value shared by all BankAccount objects.

---

# 11. Important Interview Questions

### Q1. What is the static keyword in Java?

The `static` keyword makes a member belong to the class instead of individual objects.

### Q2. What is a static variable?

A static variable is a class-level variable shared by all objects of a class.

### Q3. What is another name for a static variable?

Class variable.

### Q4. How do we access a static variable?

Using the class name.

```java
Student.collegeName;
```

### Q5. What is a static method?

A method that belongs to the class and can be called without creating an object.

### Q6. Can a static method access an instance variable directly?

No. It needs an object reference to access an instance variable.

### Q7. Can a static method access another static method?

Yes. A static method can directly call another static method of the same class.

### Q8. Can we use `this` inside a static method?

No. The `this` keyword refers to the current object, but a static method does not have a current object.

### Q9. What is a reference variable?

A variable that stores a reference to an object.

### Q10. What is a reference data type?

A non-primitive type used to refer to objects, such as classes, arrays, and interfaces.

### Q11. Can a reference variable store null?

Yes. A reference variable can store `null`.

### Q12. What happens when we access a method using a null reference?

A `NullPointerException` occurs at runtime.

### Q13. Can two reference variables point to the same object?

Yes. Both references can refer to the same object.

### Q14. What is the difference between instance and static variables?

Instance variables have separate copies for each object, while static variables are shared by all objects of the class.

### Q15. Can we call a static method using an object?

Yes, Java permits it, but using the class name is recommended.

### Q16. When is a static variable initialized?

It is initialized as part of class initialization, before the class is actively used for the first time.

### Q17. What is the default value of a static variable?

It depends on its data type. For example, numeric types default to zero, boolean to false, and reference types to null.

### Q18. Is the main method static? Why?

Yes. The JVM can invoke the `main` method without creating an object of the class.

---

# 12. Multiple Choice Questions

### Q1. Which keyword is used to declare a static variable?

A. final  
B. static  
C. public  
D. void  

**Answer: B. static**

### Q2. A static variable belongs to:

A. Object  
B. Constructor  
C. Class  
D. Method  

**Answer: C. Class**

### Q3. How many shared copies of a static variable normally exist per class loader?

A. One  
B. Two  
C. Every object gets one  
D. Zero  

**Answer: A. One**

### Q4. Which statement is correct?

A. Static methods can directly access instance variables.  
B. Static methods can directly access static variables.  
C. Static methods always require an object.  
D. Static methods can use `this`.

**Answer: B. Static methods can directly access static variables.**

### Q5. Which is the recommended way to access a static variable?

A. Object name  
B. Class name  
C. Constructor  
D. `this` keyword  

**Answer: B. Class name**

### Q6. Which of the following is a reference data type?

A. int  
B. char  
C. boolean  
D. String  

**Answer: D. String**

### Q7. What does `null` represent?

A. Zero  
B. Empty string  
C. No object reference  
D. False  

**Answer: C. No object reference**

### Q8. What happens when a method is called through a null reference?

A. Compile-time error  
B. NullPointerException  
C. ArithmeticException  
D. No error  

**Answer: B. NullPointerException**

### Q9. What happens in the following code?

```java
Student s1 = new Student();
Student s2 = s1;
```

A. Two objects are created.  
B. No object is created.  
C. Both variables refer to the same object.  
D. Compilation fails.

**Answer: C. Both variables refer to the same object.**

### Q10. Which method can be called without creating an object?

A. Instance method  
B. Static method  
C. Constructor  
D. Abstract instance method  

**Answer: B. Static method**

---

# 13. Quick Revision Notes

| Concept | Remember |
|---|---|
| `static` | Belongs to the class. |
| Static variable | Shared by all objects. |
| Static method | Can be called using the class name. |
| Instance variable | Separate for each object. |
| Instance method | Called through an object reference. |
| Reference variable | Holds a reference to an object. |
| `new` | Creates an object (and returns its reference). |
| `null` | No object is currently referenced. |
| `this` | Refers to the current object. |
| Primitive type | Stores a primitive value. |
| Reference type | Refers to an object. |
| `ClassName.variable` | Accesses a static variable. |
| `ClassName.method()` | Calls a static method. |

## Static vs Instance Members

| Feature | Static | Instance |
|---|---|---|
| Belongs to | Class | Object |
| Copies | Shared per class loader | One per object |
| Access | Class name recommended | Object reference |
| Object required | No | Yes |
| Direct access from static method | Yes, for static members | No, needs an object |

## Practice Checklist

- [ ] Understand the `static` keyword.
- [ ] Understand static variables and their shared nature.
- [ ] Understand static methods.
- [ ] Access static members from another class.
- [ ] Understand reference data types.
- [ ] Understand reference variables.
- [ ] Understand multiple references to one object.
- [ ] Differentiate primitive and reference data types.
- [ ] Differentiate reference and static variables.
- [ ] Complete the Student practical.
- [ ] Complete the BankAccount practical.
- [ ] Practice MCQs and interview questions.

## Additional Practice Assignments

1. Create an `Employee` class with instance variables `empId` and `empName`, and static variable `companyName`.
2. Create three Employee objects and demonstrate that changing the company name affects all objects.
3. Create a `Car` class with instance variables `model` and `price`, and a static variable `numberOfCars`. Increment the static variable whenever a new car object is created.
4. Create two reference variables pointing to the same object and demonstrate how changes through one reference affect the other.
5. Create a static method that accepts an object reference and displays its instance variables.

---

**End of Session 5 – Static Members and Object References**

Happy Learning! 🚀
