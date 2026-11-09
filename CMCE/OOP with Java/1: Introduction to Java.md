# ☕ Session 1: Introduction to Java

**Course:** PGCP-AC / CMCE – August 2026  
**Subject:** Object Oriented Programming with Java  
**Session:** 1  
**Duration:** 2 Theory + 2 Self Learning  
**Java Version:** Java 17 (LTS)

**Topics:** Introduction to Java, Features of Java, JVM Architecture, JDK and Its Usage, Structure of Java Class, Primitive Data Types, Java Tokens (Keywords, Identifiers, Literals).

---

# 1. Introduction to Java

Java is a **high-level, class-based, object-oriented, general-purpose programming language** designed to be platform-independent.

Java was developed by **James Gosling and his team at Sun Microsystems** and officially released in 1995.

Java is now maintained by Oracle and the wider OpenJDK community.

### Important characteristics

- **High-level:** Provides human-readable syntax.
- **Object-oriented:** Supports classes, objects, inheritance, polymorphism, abstraction and encapsulation.
- **Platform-independent:** Compiled bytecode can execute on different operating systems using a compatible JVM.
- **Robust:** Supports exception handling and automatic memory management.
- **Secure:** Provides bytecode verification, access control and other security mechanisms.
- **Multithreaded:** Supports concurrent execution using multiple threads.

## 1.1 History of Java

| Year | Event |
|---|---|
| 1991 | Java development began as the Green Project. |
| 1995 | Java was officially introduced by Sun Microsystems. |
| 1996 | JDK 1.0 was released. |
| 2010 | Oracle acquired Sun Microsystems. |
| 2014 | Java 8 introduced lambda expressions and Stream API. |
| 2017 | Java 9 introduced the module system. |
| 2021 | Java 17 was released as an LTS version. |

**Important:** Java was initially named **Oak** and later renamed Java.

## 1.2 Applications of Java

Java is used in:

1. Enterprise applications
2. Web and backend development
3. Banking and financial systems
4. Android application development
5. Desktop applications
6. Distributed applications
7. Cloud-based services

Examples of Java technologies include Spring Boot, Hibernate, Jakarta EE and JDBC.

## 1.3 How Java Works

Java follows the principle:

**WORA – Write Once, Run Anywhere**

This means Java source code is compiled into platform-independent bytecode, which can run on different platforms with compatible Java runtimes.

### Java Execution Flow

```text
       Java Source Code
          Hello.java
              |
              v
       Java Compiler
            javac
              |
              v
         Bytecode
         Hello.class
              |
              v
       Class Loader
              |
              v
       Bytecode Verifier
              |
              v
        JVM Execution
       /             \
 Interpreter      JIT Compiler
       \             /
        Native Execution
              |
              v
            Output
```

### Example: Hello World

```java
public class Hello {
    public static void main(String[] args) {
        System.out.println("Hello Java");
    }
}
```

**Compile:**

```bash
javac Hello.java
```

**Execute:**

```bash
java Hello
```

**Output:**

```text
Hello Java
```

### Explanation

- `javac` compiles the source file into bytecode.
- `Hello.class` contains compiled bytecode.
- `java Hello` launches the JVM to execute the class.
- `System.out.println()` displays output on the console.

**CMCE Important:** Java is both compiled and interpreted/JIT-compiled.

---

# 2. Features of Java

Java provides several important features that make it suitable for application development.

| Feature | Explanation |
|---|---|
| Simple | Java removes many complex features of C++, such as explicit pointer arithmetic. |
| Object-Oriented | Supports classes, objects and major OOP principles. |
| Platform Independent | Bytecode executes on compatible JVMs across operating systems. |
| Portable | Fixed primitive sizes and standard bytecode improve portability. |
| Secure | Provides bytecode verification and runtime access controls. |
| Robust | Supports exception handling, type checking and garbage collection. |
| Multithreaded | Supports multiple threads executing concurrently. |
| High Performance | JIT compilation optimizes frequently executed code. |
| Distributed | Supports networking and distributed application development. |
| Dynamic | Classes can be loaded dynamically during execution. |
| Architecture Neutral | Bytecode is not tied to one processor architecture. |

## 2.1 Platform Independence

A Java program can execute on Windows, Linux or macOS without recompilation, provided a compatible JVM is available.

```text
            Java Source
                 |
               javac
                 |
             Bytecode
                 |
       ---------------------
       |         |         |
       v         v         v
    Windows    Linux     macOS
      JVM       JVM       JVM
       |         |         |
       v         v         v
     Output    Output    Output
```

**Important Difference:**

- Java source code is compiled into platform-independent bytecode.
- JVM implementations are platform-dependent.
- JVM makes Java bytecode portable across supported platforms.

## 2.2 Why Is Java Robust?

Java is considered robust because it provides:

- Strong type checking
- Exception handling
- Automatic garbage collection
- Array bounds checking
- Runtime verification

### Example: Array Bounds Checking

```java
class Test {
    public static void main(String[] args) {
        int[] arr = {10, 20, 30};

        System.out.println(arr[5]);
    }
}
```

**Result:**

```text
Exception in thread "main"
java.lang.ArrayIndexOutOfBoundsException
```

Java detects invalid array access at runtime instead of allowing unchecked memory access.

## 2.3 Why Is Java Secure?

Java provides:

1. Bytecode verification
2. Class loading controls
3. Access modifiers
4. Type safety
5. No direct pointer arithmetic
6. Security-related libraries and APIs

**CMCE Important:** Java does not support explicit pointer arithmetic like C and C++.

---

# 3. JVM Architecture

**JVM (Java Virtual Machine)** is an abstract machine responsible for loading, verifying and executing Java bytecode.

The JVM provides a runtime environment for Java applications.

## 3.1 Main Components of JVM

```text
                  JVM
                   |
     --------------------------------
     |              |               |
     v              v               v
 Class Loader   Runtime Data    Execution
  Subsystem       Areas          Engine
                    |               |
              -------------    -----------
              |     |     |    |    |    |
             Heap Stack Method INT  JIT  GC
                         Area
                   |
            JNI & Native Libraries
```

The major components are:

1. Class Loader Subsystem
2. Runtime Data Areas
3. Execution Engine
4. Java Native Interface
5. Native Method Libraries

## 3.2 Class Loader Subsystem

The Class Loader Subsystem loads `.class` files into JVM memory.

It performs three major phases:

### A. Loading

Loads class bytecode into JVM memory.

Java provides class loaders such as:

- Bootstrap Class Loader
- Platform Class Loader
- Application Class Loader

### B. Linking

Linking consists of:

**1. Verification**

Checks bytecode validity and safety.

**2. Preparation**

Allocates storage for static fields and assigns their default values.

**3. Resolution**

Converts symbolic references into direct references.

### C. Initialization

Executes class initialization logic, including static field initializers and static initialization blocks.

**CMCE Important:**

```text
Loading → Linking → Initialization

Linking:
Verification → Preparation → Resolution
```

## 3.3 Runtime Data Areas

JVM memory is divided into different runtime areas.

| Memory Area | Purpose | Shared/Thread-Specific |
|---|---|---|
| Method Area | Stores class metadata and runtime constant pools. | Shared |
| Heap | Stores objects and arrays. | Shared |
| JVM Stack | Stores stack frames for method calls. | Per thread |
| PC Register | Tracks the current JVM instruction. | Per thread |
| Native Method Stack | Supports native method execution. | Per thread |

### A. Heap Memory

Heap memory stores objects and arrays.

Example:

```java
Student s1 = new Student();
```

The `Student` object is generally allocated on the heap.

### B. Stack Memory

Each thread has a JVM stack containing frames for active method calls.

A stack frame contains information such as:

- Local variables
- Operand stack
- Method execution information

### Example

```java
class Demo {
    public static void main(String[] args) {
        int x = 10;
        Student s = new Student();
    }
}

class Student {
    int marks = 90;
}
```

Conceptual memory representation:

```text
         Stack                  Heap
    ----------------      ----------------
    | x = 10       |      | Student Object |
    | s = reference|----->| marks = 90     |
    ----------------      ----------------
```

**Important:** Local variables are stored in stack frames, while objects are generally stored in heap memory. JVM optimizations may change physical allocation.

### C. Method Area

Stores information such as:

- Class metadata
- Method metadata
- Runtime constant pools
- Field information

**Note:** In HotSpot JVM, class metadata is commonly stored using Metaspace.

### D. PC Register

Each thread has its own Program Counter register.

It tracks the JVM instruction being executed by that thread.

### E. Native Method Stack

Supports methods implemented using native programming languages such as C and C++.

## 3.4 Execution Engine

The execution engine executes bytecode.

It contains:

### A. Interpreter

Executes bytecode instructions.

**Advantage:** Can begin execution without waiting for native compilation.

**Disadvantage:** Repeated interpretation can be slower than optimized native code.

### B. JIT Compiler

JIT stands for **Just-In-Time Compiler**.

It compiles frequently executed bytecode into optimized native machine code.

**Advantage:** Improves performance for repeatedly executed code.

### C. Garbage Collector

Automatically reclaims memory occupied by objects that are no longer reachable.

Example:

```java
Student s = new Student();
s = null;
```

The object may become eligible for garbage collection if no other reachable references exist.

Garbage collection is automatic, but the exact time of collection is not guaranteed.

## 3.5 Interpreter vs JIT Compiler

| Interpreter | JIT Compiler |
|---|---|
| Executes bytecode instructions. | Compiles bytecode into native code. |
| Can start executing immediately. | Has compilation overhead. |
| Repeated interpretation can be slower. | Optimized native code can execute faster. |
| Does not require compiling the entire method to native code. | Optimizes selected methods or code paths. |

## 3.6 JNI

**JNI – Java Native Interface**

JNI allows Java code to interact with native libraries written in languages such as C and C++.

It is useful when Java applications need access to platform-specific functionality.

---

# 4. JDK and Its Usage

**JDK (Java Development Kit)** is a software development kit used to develop, compile, debug and execute Java applications.

## 4.1 JDK vs JRE vs JVM

| JDK | JRE | JVM |
|---|---|---|
| Java Development Kit | Java Runtime Environment | Java Virtual Machine |
| Used for development and execution. | Provides components needed to run Java applications. | Executes Java bytecode. |
| Contains compiler and development tools. | Contains JVM and runtime libraries. | Provides the bytecode execution environment. |
| Used by developers. | Used for running applications. | Used internally during execution. |

### Conceptual Relationship

```text
             JDK
    ----------------------
    | Development Tools  |
    | javac, jar, jdb    |
    |                    |
    |   Java Runtime     |
    |  ----------------  |
    |  | JVM          |  |
    |  | Libraries    |  |
    |  ----------------  |
    ----------------------
```

**Note:** Modern JDKs such as JDK 17 do not necessarily contain a separate traditional `jre` directory.

## 4.2 Important JDK Tools

| Tool | Purpose |
|---|---|
| `javac` | Compiles Java source code. |
| `java` | Launches Java applications. |
| `javadoc` | Generates API documentation. |
| `jar` | Creates and manages JAR archives. |
| `jdb` | Java debugger. |
| `javap` | Displays compiled class information. |
| `jshell` | Interactive Java REPL. |
| `jlink` | Creates custom runtime images. |
| `jconsole` | Monitors Java applications. |

## 4.3 Check Java Installation

Open Command Prompt or Terminal.

```bash
java -version
```

```bash
javac -version
```

Example output:

```text
javac 17.0.x
```

## 4.4 Compile and Execute a Java Program

Create `Hello.java`:

```java
public class Hello {
    public static void main(String[] args) {
        System.out.println("Welcome to Java");
    }
}
```

Compile:

```bash
javac Hello.java
```

Run:

```bash
java Hello
```

Output:

```text
Welcome to Java
```

**Important:** We use the class name, not the `.class` extension, when launching a class using the `java` command.

---

# 5. Structure of a Java Class

A Java program is organized using classes.

A class can contain:

- Fields
- Constructors
- Methods
- Initialization blocks
- Nested classes

## 5.1 Basic Java Class Structure

```java
package com.example;

import java.util.Scanner;

public class Student {

    // Instance variables
    int rollNo;
    String name;

    // Constructor
    public Student(int rollNo, String name) {
        this.rollNo = rollNo;
        this.name = name;
    }

    // Instance method
    public void display() {
        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
    }

    // Main method
    public static void main(String[] args) {
        Student s1 = new Student(101, "Rahul");
        s1.display();
    }
}
```

Save this file as `Student.java` inside the appropriate `com/example` package directory.

### Explanation

| Component | Purpose |
|---|---|
| `package` | Groups related classes. |
| `import` | Allows convenient use of types from other packages. |
| `class` | Defines a class. |
| `int rollNo` | Instance variable. |
| `Student()` | Constructor used to initialize objects. |
| `display()` | Instance method. |
| `main()` | Entry point for a standard Java application. |
| `new` | Creates a new object. |
| `this` | Refers to the current object. |

## 5.2 Main Method Explained

```java
public static void main(String[] args)
```

| Keyword/Element | Meaning |
|---|---|
| `public` | Makes the method accessible to the Java launcher. |
| `static` | Allows calling the method without creating an object. |
| `void` | Method does not return a value. |
| `main` | Standard entry-point method name. |
| `String[] args` | Stores command-line arguments. |

### Command-Line Arguments Example

```java
class CommandLineDemo {
    public static void main(String[] args) {
        System.out.println(args[0]);
    }
}
```

Compile:

```bash
javac CommandLineDemo.java
```

Execute:

```bash
java CommandLineDemo Anurag
```

Output:

```text
Anurag
```

**Important:** Command-line arguments are stored as strings.

## 5.3 Java Naming Conventions

| Element | Convention | Example |
|---|---|---|
| Class | PascalCase | `StudentDetails` |
| Method | camelCase | `displayDetails()` |
| Variable | camelCase | `studentName` |
| Constant | UPPER_SNAKE_CASE | `MAX_MARKS` |
| Package | lowercase | `com.example` |

---

# 6. Primitive Data Types in Java

A data type determines what kind of value a variable can store.

Java data types are broadly classified into:

```text
             Data Types
                 |
       ---------------------
       |                   |
    Primitive          Reference
       |                   |
  -------------       ------------
  |     |     |       |    |     |
Integer Float Boolean Class Array String
  |
byte, short,
int, long
```

Java provides **8 primitive data types**.

## 6.1 Primitive Data Types Table

| Data Type | Size | Default Value (Fields) | Example |
|---|---|---|---|
| `byte` | 1 byte | `0` | `byte a = 10;` |
| `short` | 2 bytes | `0` | `short b = 100;` |
| `int` | 4 bytes | `0` | `int c = 1000;` |
| `long` | 8 bytes | `0L` | `long d = 10000L;` |
| `float` | 4 bytes | `0.0f` | `float e = 10.5f;` |
| `double` | 8 bytes | `0.0d` | `double f = 20.5;` |
| `char` | 2 bytes | `'\u0000'` | `char g = 'A';` |
| `boolean` | JVM-dependent storage | `false` | `boolean h = true;` |

**Important:** Local variables do not receive automatic default values. They must be definitely assigned before use.

## 6.2 Integer Data Types

### byte

- Size: 8 bits
- Range: -128 to 127
- Used for small integer values.

```java
byte age = 22;
```

### short

- Size: 16 bits
- Range: -32,768 to 32,767

```java
short year = 2026;
```

### int

- Size: 32 bits
- Range: -2,147,483,648 to 2,147,483,647
- Default integer literal type.

```java
int salary = 50000;
```

### long

- Size: 64 bits
- Used for large integer values.

```java
long population = 8000000000L;
```

**Important:** Use `L` for long integer literals when the value is outside the `int` range.

## 6.3 Floating-Point Data Types

### float

- Size: 32 bits
- Single-precision floating-point type.
- Requires `f` or `F` suffix for ordinary decimal literals.

```java
float percentage = 85.5f;
```

### double

- Size: 64 bits
- Double-precision floating-point type.
- Default type for decimal literals.

```java
double price = 999.99;
```

### float vs double

| float | double |
|---|---|
| 32-bit | 64-bit |
| Approximately 6–7 decimal digits of precision | Approximately 15–16 decimal digits of precision |
| Requires `f` suffix for decimal literals | Default decimal literal type |
| Lower precision | Higher precision |

## 6.4 char Data Type

The `char` data type stores a single UTF-16 code unit.

```java
char grade = 'A';
char symbol = '@';
char unicode = '\u0041';
```

Here, `'\u0041'` represents `A`.

**Important:** Java `char` is unsigned and ranges from `'\u0000'` to `'\uffff'`.

## 6.5 boolean Data Type

Stores one of two values:

```java
true
false
```

Example:

```java
boolean isPassed = true;
boolean isFailed = false;
```

**Important:** Java does not allow implicit conversion between `boolean` and integer types.

## 6.6 Program: Demonstrating All Primitive Data Types

```java
public class PrimitiveDemo {
    public static void main(String[] args) {

        byte a = 100;
        short b = 20000;
        int c = 100000;
        long d = 9000000000L;

        float e = 10.5f;
        double f = 99.999;

        char g = 'A';
        boolean h = true;

        System.out.println("byte: " + a);
        System.out.println("short: " + b);
        System.out.println("int: " + c);
        System.out.println("long: " + d);
        System.out.println("float: " + e);
        System.out.println("double: " + f);
        System.out.println("char: " + g);
        System.out.println("boolean: " + h);
    }
}
```

### Output

```text
byte: 100
short: 20000
int: 100000
long: 9000000000
float: 10.5
double: 99.999
char: A
boolean: true
```

## 6.7 Primitive vs Reference Data Types

| Primitive | Reference |
|---|---|
| Stores primitive values directly. | Stores references to objects. |
| Eight predefined types. | Includes classes, interfaces and arrays. |
| Cannot hold `null`. | Can hold `null`. |
| Example: `int`, `char` | Example: `String`, `Student` |

### Example

```java
int age = 22;
String name = "Rahul";
```

Here:

- `age` is a primitive variable.
- `name` is a reference variable.

## 6.8 Type Conversion Overview

Java supports two main types of primitive numeric conversion.

### A. Widening Conversion

Converts a smaller-range numeric type to a wider type automatically.

```java
int a = 100;
double b = a;

System.out.println(b);
```

Output:

```text
100.0
```

Common widening paths include:

```text
byte → short → int → long → float → double
              ^
              |
             char
```

**Note:** Widening conversions are automatic but can still lose precision, such as converting a large `long` to `float`.

### B. Narrowing Conversion

Converts one numeric type to another type with a narrower range or precision.

Explicit casting is generally required.

```java
double a = 99.99;
int b = (int) a;

System.out.println(b);
```

Output:

```text
99
```

**Important:** Narrowing may cause data loss.

---

# 7. Java Tokens

A **token** is the smallest meaningful element of a Java program recognized by the compiler.

Java tokens include:

1. Keywords
2. Identifiers
3. Literals
4. Operators
5. Separators

## 7.1 Keywords

Keywords are reserved words with predefined meanings in Java.

They cannot be used as identifiers.

### Important Java Keywords

| Category | Keywords |
|---|---|
| Access Control | `public`, `private`, `protected` |
| Class and Object | `class`, `new`, `this`, `super` |
| Inheritance | `extends`, `implements` |
| Data Types | `int`, `long`, `float`, `double`, `char`, `boolean`, `byte`, `short` |
| Control Flow | `if`, `else`, `switch`, `case`, `for`, `while`, `do`, `break`, `continue` |
| Exception Handling | `try`, `catch`, `finally`, `throw`, `throws` |
| Modifiers | `static`, `final`, `abstract`, `synchronized`, `volatile`, `transient` |
| Other | `void`, `return`, `package`, `import`, `interface`, `enum`, `instanceof` |

### Example

```java
public class Student {
    private int rollNo;
}
```

Here:

- `public` is a keyword.
- `class` is a keyword.
- `private` is a keyword.
- `int` is a keyword.

### Important CMCE Points

- `true` and `false` are boolean literals, not keywords.
- `null` is a literal, not a keyword.
- `String` is a class name, not a keyword.
- `main` is a method name, not a keyword.
- `const` and `goto` are reserved keywords but are not used in Java.
- `var` is a reserved type name in specific contexts, not an ordinary keyword.
- `record`, `sealed` and `permits` have special contextual roles in modern Java.

## 7.2 Identifiers

Identifiers are names used for:

- Classes
- Methods
- Variables
- Interfaces
- Packages

### Example

```java
class Student {
    int rollNo = 101;

    void displayDetails() {
        System.out.println(rollNo);
    }
}
```

Identifiers:

```text
Student
rollNo
displayDetails
```

### Rules for Identifiers

1. Cannot start with a digit.
2. Cannot contain spaces.
3. Cannot be a reserved keyword.
4. Can contain letters, digits, `_` and `$`.
5. Are case-sensitive.
6. May contain supported Unicode identifier characters.

### Valid Identifiers

```java
studentName
rollNo
_age
$salary
student123
```

### Invalid Identifiers

```text
123student
student name
class
student-name
```

### Case Sensitivity

```java
int age = 20;
int Age = 25;
int AGE = 30;
```

All three are different identifiers.

## 7.3 Literals

Literals are fixed values directly written in source code.

### Types of Literals

| Literal Type | Example |
|---|---|
| Integer | `100`, `200L` |
| Floating-point | `10.5`, `20.5f` |
| Character | `'A'`, `'9'` |
| String | `"Java"` |
| Boolean | `true`, `false` |
| Null | `null` |

### A. Integer Literals

Java supports different number systems.

```java
int decimal = 10;
int binary = 0b1010;
int octal = 012;
int hexadecimal = 0xA;
```

All four represent decimal value 10.

### B. Floating-Point Literals

```java
float a = 10.5f;
double b = 20.5;
double c = 1.5e3;
```

Here, `1.5e3` represents 1500.0.

### C. Character Literals

```java
char a = 'A';
char b = '7';
char c = '\n';
```

Common escape sequences:

| Escape | Meaning |
|---|---|
| `\n` | New line |
| `\t` | Tab |
| `\\` | Backslash |
| `\'` | Single quote |
| `\"` | Double quote |

### D. String Literals

```java
String name = "Anurag";
String language = "Java";
```

String literals are enclosed in double quotes.

### E. Boolean Literals

```java
boolean isActive = true;
boolean isCompleted = false;
```

### F. Null Literal

```java
String name = null;
```

`null` represents the absence of an object reference.

## 7.4 Operators

Operators are symbols used to perform operations.

| Operator Type | Examples |
|---|---|
| Arithmetic | `+`, `-`, `*`, `/`, `%` |
| Relational | `<`, `>`, `<=`, `>=`, `==`, `!=` |
| Logical | `&&`, `||`, `!` |
| Assignment | `=`, `+=`, `-=`, `*=`, `/=` |
| Unary | `++`, `--`, `+`, `-`, `!` |
| Bitwise | `&`, `|`, `^`, `~` |
| Shift | `<<`, `>>`, `>>>` |
| Conditional | `?:` |

### Example

```java
class OperatorDemo {
    public static void main(String[] args) {

        int a = 10;
        int b = 20;

        System.out.println(a + b);
        System.out.println(a > b);
        System.out.println(a == b);
    }
}
```

Output:

```text
30
false
false
```

## 7.5 Separators

Separators are used to organize Java source code.

| Separator | Purpose |
|---|---|
| `()` | Method calls and parameter lists |
| `{}` | Blocks and class bodies |
| `[]` | Arrays |
| `;` | Statement termination |
| `,` | Separates elements |
| `.` | Member access |
| `@` | Annotations |
| `::` | Method references |

---

# 8. Important Java Practical Programs

## Program 1: Print Personal Details

```java
class PersonalDetails {
    public static void main(String[] args) {

        String name = "Anurag";
        int age = 22;
        String course = "PGCP-AC";

        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Course: " + course);
    }
}
```

## Program 2: Addition of Two Numbers

```java
class Addition {
    public static void main(String[] args) {

        int a = 10;
        int b = 20;

        int sum = a + b;

        System.out.println("Sum = " + sum);
    }
}
```

Output:

```text
Sum = 30
```

## Program 3: Display Size of Primitive Types

```java
class SizeDemo {
    public static void main(String[] args) {

        System.out.println(Byte.BYTES);
        System.out.println(Short.BYTES);
        System.out.println(Integer.BYTES);
        System.out.println(Long.BYTES);
        System.out.println(Float.BYTES);
        System.out.println(Double.BYTES);
        System.out.println(Character.BYTES);
    }
}
```

Output:

```text
1
2
4
8
4
8
2
```

## Program 4: Integer Number Systems

```java
class NumberSystem {
    public static void main(String[] args) {

        int a = 10;
        int b = 0b1010;
        int c = 012;
        int d = 0xA;

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
    }
}
```

Output:

```text
10
10
10
10
```

## Program 5: Type Casting

```java
class CastingDemo {
    public static void main(String[] args) {

        int a = 100;
        double b = a;

        double x = 99.99;
        int y = (int) x;

        System.out.println(b);
        System.out.println(y);
    }
}
```

Output:

```text
100.0
99
```

---

# 9. Important CMCE Theory and Interview Questions

**Q1. What is Java?**

Java is a high-level, class-based, object-oriented programming language that supports platform-independent execution through bytecode and the JVM.

**Q2. Who developed Java?**

James Gosling and his team at Sun Microsystems.

**Q3. What was the original name of Java?**

Oak.

**Q4. What is WORA?**

WORA stands for Write Once, Run Anywhere. Java bytecode can run on compatible JVM implementations across different platforms.

**Q5. Why is Java platform-independent?**

Because Java source code is compiled into bytecode, which can execute on different operating systems using a compatible JVM.

**Q6. Is JVM platform-independent?**

No. JVM implementations are platform-specific.

**Q7. Is Java compiled or interpreted?**

Java source code is compiled into bytecode, which the JVM executes using interpretation and/or JIT compilation.

**Q8. What is bytecode?**

Bytecode is the intermediate instruction format generated by the Java compiler and executed by the JVM.

**Q9. What is JVM?**

JVM is the Java Virtual Machine that loads and executes Java bytecode.

**Q10. What are the major components of JVM?**

Class Loader Subsystem, Runtime Data Areas, Execution Engine, JNI and Native Libraries.

**Q11. What are the phases of class loading and initialization?**

Loading, Linking and Initialization.

**Q12. What are the steps of linking?**

Verification, Preparation and Resolution.

**Q13. What is JIT?**

JIT stands for Just-In-Time Compiler. It converts selected bytecode into optimized native machine code during execution.

**Q14. What is the difference between stack and heap?**

Heap stores objects and arrays, while JVM stacks contain method execution frames and local variables.

**Q15. What is garbage collection?**

Garbage collection is the automatic process of reclaiming memory from unreachable objects.

**Q16. What is JDK?**

JDK is the Java Development Kit, which provides tools for developing and executing Java programs.

**Q17. What is JRE?**

JRE is the Java Runtime Environment, which provides the components needed to run Java applications.

**Q18. What is the difference between `javac` and `java`?**

`javac` compiles source code into bytecode, while `java` launches the application.

**Q19. What is the main method in Java?**

The standard entry-point method is `public static void main(String[] args)`.

**Q20. Why is main() static?**

So the Java launcher can invoke it without creating an object of the class.

**Q21. How many primitive data types are available in Java?**

Eight: byte, short, int, long, float, double, char and boolean.

**Q22. What is the default type of an integer literal?**

`int`, when the literal is representable as an int and has no `L` suffix.

**Q23. What is the default type of a decimal floating-point literal?**

`double`, unless suffixed with `f` or `F`.

**Q24. What is the size of char in Java?**

16 bits.

**Q25. Is String a primitive data type?**

No. String is a class and a reference type.

**Q26. What are Java tokens?**

Tokens are the smallest meaningful elements of Java source code.

**Q27. What is a keyword?**

A reserved word with a predefined meaning in Java.

**Q28. What is an identifier?**

A name assigned to a variable, class, method or another program element.

**Q29. What is a literal?**

A fixed value directly written in Java source code.

**Q30. Is `main` a Java keyword?**

No. It is a method name.

**Q31. Is `true` a keyword?**

No. It is a boolean literal.

**Q32. Is Java case-sensitive?**

Yes. `age`, `Age` and `AGE` are different identifiers.

**Q33. What is type casting?**

Type casting explicitly converts a value from one compatible type to another.

**Q34. Can boolean be converted to int in Java?**

No. Java does not permit numeric-boolean conversion.

**Q35. What is the difference between primitive and reference types?**

Primitive variables store primitive values, while reference variables store references to objects.

---

# 10. CMCE Practice MCQs

### Q1. Who is known as the father of Java?

A. Dennis Ritchie  
B. James Gosling  
C. Bjarne Stroustrup  
D. Guido van Rossum

**Answer: B. James Gosling**

### Q2. Which component executes Java bytecode?

A. JDK  
B. JVM  
C. javac  
D. Javadoc

**Answer: B. JVM**

### Q3. Which file is generated after compiling Java source code?

A. `.exe`  
B. `.java`  
C. `.class`  
D. `.txt`

**Answer: C. `.class`**

### Q4. Which memory area generally stores Java objects?

A. Stack  
B. Heap  
C. PC Register  
D. Native Method Stack

**Answer: B. Heap**

### Q5. What is the size of int in Java?

A. 2 bytes  
B. 4 bytes  
C. 8 bytes  
D. Platform-dependent

**Answer: B. 4 bytes**

### Q6. Which is not a primitive data type?

A. int  
B. char  
C. String  
D. boolean

**Answer: C. String**

### Q7. Which is a valid Java identifier?

A. 123name  
B. student-name  
C. studentName  
D. class

**Answer: C. studentName**

### Q8. What is the default value of a boolean instance field?

A. 0  
B. 1  
C. null  
D. false

**Answer: D. false**

### Q9. Which tool compiles Java source code?

A. java  
B. javac  
C. jar  
D. javadoc

**Answer: B. javac**

### Q10. Which is not a Java keyword?

A. static  
B. class  
C. main  
D. public

**Answer: C. main**

### Q11. Which phase assigns default values to static fields?

A. Loading  
B. Verification  
C. Preparation  
D. Initialization

**Answer: C. Preparation**

### Q12. What is the output?

```java
int a = 10;
double b = a;
System.out.println(b);
```

A. 10  
B. 10.0  
C. Compilation error  
D. Runtime exception

**Answer: B. 10.0**

### Q13. Which statement is correct?

A. JVM is platform-independent.  
B. Java bytecode is platform-independent.  
C. Java does not use compilation.  
D. Java does not support multithreading.

**Answer: B. Java bytecode is platform-independent.**

### Q14. Which literal represents binary 10?

A. `010`  
B. `0x10`  
C. `0b1010`  
D. `10b`

**Answer: C. `0b1010`**

### Q15. What is the output?

```java
char ch = 'A';
System.out.println((int) ch);
```

A. A  
B. 65  
C. 97  
D. Compilation error

**Answer: B. 65**

---

# 11. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Java | High-level, class-based, object-oriented language |
| Developer | James Gosling |
| Original Name | Oak |
| WORA | Write Once, Run Anywhere |
| Java Compiler | `javac` |
| Java Launcher | `java` |
| Source File | `.java` |
| Bytecode File | `.class` |
| JVM | Executes Java bytecode |
| JDK | Java Development Kit |
| JRE | Java Runtime Environment |
| Class Loader | Loads class definitions |
| Linking | Verification, Preparation, Resolution |
| Heap | Stores objects and arrays |
| Stack | Contains method execution frames |
| Method Area | Stores class-level metadata |
| PC Register | Tracks JVM instructions |
| JIT | Just-In-Time Compiler |
| GC | Garbage Collector |
| JNI | Java Native Interface |
| Primitive Types | 8 |
| int Size | 4 bytes |
| long Size | 8 bytes |
| char Size | 2 bytes |
| Default Decimal Type | double |
| Keywords | Reserved words |
| Identifiers | Names of program elements |
| Literals | Fixed values |
| String | Reference type |
| boolean | true or false |
| Java | Case-sensitive |

---

# 12. Important Differences for CMCE

## JDK vs JRE vs JVM

| JDK | JRE | JVM |
|---|---|---|
| Development kit | Runtime environment | Virtual machine |
| Includes compiler and tools | Provides runtime components | Executes bytecode |
| Used for development | Used for execution | Core execution engine |

## Stack vs Heap

| Stack | Heap |
|---|---|
| Per-thread memory | Shared memory |
| Contains method frames | Contains objects and arrays |
| Frames are removed when methods return | Objects are reclaimed by garbage collection when eligible |
| Supports method execution | Supports dynamic object allocation |

## Compiler vs Interpreter

| Compiler | Interpreter |
|---|---|
| Translates code into another representation | Executes instructions |
| `javac` produces bytecode | JVM interpreter executes bytecode |
| Compilation errors may be reported before execution | Runtime errors may occur during execution |

## Keyword vs Identifier vs Literal

| Keyword | Identifier | Literal |
|---|---|---|
| Reserved word | Programmer-defined name | Fixed value |
| `class` | `Student` | `100` |
| `int` | `age` | `22` |
| `public` | `display` | `"Java"` |

---

# 13. Lab Practice Checklist

### Java Fundamentals

- [ ] Understand Java history and introduction.
- [ ] Learn the main features of Java.
- [ ] Understand platform independence.
- [ ] Understand WORA.
- [ ] Understand source code, bytecode and machine code.

### JVM Architecture

- [ ] Draw and explain JVM architecture.
- [ ] Understand Class Loader Subsystem.
- [ ] Learn Loading, Linking and Initialization.
- [ ] Understand Heap and Stack.
- [ ] Understand Method Area and PC Register.
- [ ] Understand Interpreter and JIT Compiler.
- [ ] Understand Garbage Collection.
- [ ] Understand JNI.

### JDK and Java Class

- [ ] Install or verify JDK 17.
- [ ] Check `java -version`.
- [ ] Check `javac -version`.
- [ ] Compile a Java program.
- [ ] Execute a Java program.
- [ ] Understand Java class structure.
- [ ] Understand the main method.
- [ ] Practice command-line arguments.

### Primitive Data Types

- [ ] Learn all 8 primitive data types.
- [ ] Remember primitive sizes.
- [ ] Understand primitive ranges.
- [ ] Practice integer and floating-point literals.
- [ ] Understand char and boolean.
- [ ] Practice widening conversions.
- [ ] Practice narrowing conversions.

### Java Tokens

- [ ] Learn important Java keywords.
- [ ] Understand identifier rules.
- [ ] Practice valid and invalid identifiers.
- [ ] Understand integer literals.
- [ ] Understand floating-point literals.
- [ ] Understand character and string literals.
- [ ] Understand boolean and null literals.
- [ ] Revise operators and separators.

### CMCE Exam Preparation

- [ ] Revise all theory definitions.
- [ ] Practice 15 MCQs.
- [ ] Practice output-based Java questions.
- [ ] Revise JDK vs JRE vs JVM.
- [ ] Revise Heap vs Stack.
- [ ] Revise primitive data types.
- [ ] Revise Java tokens.
- [ ] Solve all practical programs.

---

# 14. Useful Java Commands for Revision

```bash
# Check Java version
java -version

# Check compiler version
javac -version

# Compile Java program
javac Hello.java

# Run Java program
java Hello

# Run with command-line arguments
java Hello Anurag

# Inspect compiled class
javap Hello

# Display bytecode instructions
javap -c Hello

# Start Java interactive shell
jshell

# Generate documentation
javadoc Hello.java
```

---

# 15. Final CMCE Revision Summary

**Must Remember:**

1. Java was developed by James Gosling.
2. Java was originally named Oak.
3. Java follows WORA.
4. Java source code is compiled into bytecode.
5. JVM executes bytecode.
6. JVM implementations are platform-dependent.
7. Class loading involves Loading, Linking and Initialization.
8. Linking involves Verification, Preparation and Resolution.
9. Heap stores objects and arrays.
10. JVM stacks store method execution frames.
11. JIT compiles selected bytecode into native code.
12. Garbage Collector reclaims unreachable objects.
13. JDK provides Java development tools.
14. Java has eight primitive data types.
15. `String` is not a primitive data type.
16. `char` uses 16 bits.
17. `float` literals normally require an `f` suffix.
18. Java is case-sensitive.
19. `main` is not a keyword.
20. `true`, `false` and `null` are literals.

---

**End of Session 1 – Introduction to Java**

**Topics Covered:** Introduction to Java, Java Features, JVM Architecture, JDK, Java Class Structure, Primitive Data Types and Java Tokens.

**Preparation Focus:** CMCE Theory, MCQs, Output-Based Questions, Lab Practice and Interviews.

**Reference:** ACTS Pune – Object Oriented Programming with Java, PGCP-AC August 2026 (Java 17).

**Official Java Documentation:** https://docs.oracle.com/en/java/javase/17/

⭐ Keep Learning, Keep Coding and Keep Revising!
