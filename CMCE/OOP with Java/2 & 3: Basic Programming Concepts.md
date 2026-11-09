# ☕ Sessions 2 & 3: Basic Programming Concepts in Java

**Course:** PGCP-AC / CMCE – August 2026 Batch  
**Subject:** Object-Oriented Programming with Java  
**Sessions:** 2 & 3  
**Duration:** 4 Theory + 4 Lab + 2 Self Learning  
**Java Version:** Java 17

---

# 📚 Table of Contents

1. Declaring Variables and Methods
2. Data Type Compatibility
3. Operators in Java
4. Conditional Statements
5. Control Statements
6. Arrays – One-Dimensional and Multidimensional
7. Lab Environment and IDE Setup
8. Practical Programs
   - Total Bill with Discount
   - Menu-Driven Calculator Using Switch Expression
   - Factorial of a Number
   - Armstrong Number
   - Fibonacci Series
   - Asterisk Patterns
   - Principal Diagonal Sum of a Matrix
9. Important Interview Questions
10. CMCE Practice MCQs
11. Quick Revision Notes
12. Practice Checklist

---

# 1. Declaring Variables and Methods

## 1.1 What is a Variable?

A variable is a named memory location used to store data that can be accessed and modified during program execution.

For example:

```java
int age = 22;
```

Here:

- `int` – Data type.
- `age` – Variable name.
- `22` – Value assigned to the variable.
- `=` – Assignment operator.

### Syntax

```java
dataType variableName = value;
```

Examples:

```java
int age = 22;

double salary = 45000.50;

char grade = 'A';

boolean isPassed = true;

String name = "Anurag";
```

## 1.2 Declaration, Initialization and Assignment

These are three important concepts in Java.

### A. Variable Declaration

Creating a variable by specifying its data type and name.

```java
int age;
```

### B. Variable Initialization

Assigning the first value to a variable.

```java
age = 22;
```

### C. Declaration and Initialization Together

```java
int age = 22;
```

### Example

```java
class VariableDemo {

    public static void main(String[] args) {

        int number;       // Declaration

        number = 100;     // Initialization

        number = 200;     // Reassignment

        System.out.println(number);

    }
}
```

Output:

```text
200
```

Explanation:

- Initially, `number` is declared.
- Then it receives the value `100`.
- Later, its value changes to `200`.
- Therefore, the output is `200`.

## 1.3 Types of Variables in Java

Java variables can be classified into three major categories.

### A. Local Variables

Variables declared inside a method, constructor or block.

Example:

```java
class LocalDemo {

    void display() {

        int age = 22;

        System.out.println(age);

    }

    public static void main(String[] args) {

        LocalDemo obj = new LocalDemo();

        obj.display();

    }
}
```

Characteristics:

1. Declared inside methods or blocks.
2. Accessible within their scope.
3. Must be initialized before use.
4. Do not receive automatic default values.

### B. Instance Variables

Variables declared inside a class but outside methods, constructors and blocks, without the `static` keyword.

Each object gets its own instance variables.

Example:

```java
class Student {

    int rollNo;

    String name;

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

Explanation:

- `s1` and `s2` are two different objects.
- Each object has its own `rollNo`.
- Changing one object's instance variable does not directly change the other object's variable.

### C. Static Variables

A static variable belongs to the class rather than to individual objects.

It is declared using the `static` keyword.

Example:

```java
class Student {

    static String college = "PESMCOE";

    int rollNo;

    public static void main(String[] args) {

        Student s1 = new Student();

        Student s2 = new Student();

        s1.rollNo = 101;

        s2.rollNo = 102;

        System.out.println(Student.college);

    }
}
```

Output:

```text
PESMCOE
```

Explanation:

- `college` is shared at the class level.
- It can be accessed using `Student.college`.
- It is not necessary to create an object to access a static variable.

### Local vs Instance vs Static Variables

| Feature | Local | Instance | Static |
|---|---|---|---|
| Declaration | Inside method/block | Inside class | Inside class with static |
| Belongs to | Method/block execution | Object | Class |
| Default value | No | Yes | Yes |
| Memory association | Method frame | Object | Class-level runtime state |
| Access | Within scope | Through object | Through class name |
| Copies | Each declaration/execution | Each object | Shared class variable |

## 1.4 Constants in Java

A constant is a variable whose value cannot be reassigned after initialization.

Java uses the `final` keyword.

Example:

```java
class ConstantDemo {

    public static void main(String[] args) {

        final double PI = 3.14159;

        System.out.println(PI);

        // PI = 3.14;  // Compilation error

    }
}
```

Output:

```text
3.14159
```

Common naming convention:

```java
final int MAX_MARKS = 100;

final double GST_RATE = 0.18;
```

**Important:** A `final` variable cannot be reassigned. If it holds an object reference, the reference cannot be changed, but the object's mutable state may still be modified.

## 1.5 What is a Method?

A method is a block of code that performs a particular task.

Methods help to:

- Reuse code.
- Divide large programs into smaller tasks.
- Improve readability.
- Reduce code duplication.
- Make testing and maintenance easier.

### Method Syntax

```java
accessModifier static returnType methodName(parameters) {

    // Method body

    return value;

}
```

Example:

```java
class MethodDemo {

    static void display() {

        System.out.println("Welcome to Java");

    }

    public static void main(String[] args) {

        display();

    }
}
```

Output:

```text
Welcome to Java
```

Explanation:

- `static` – Method belongs to the class.
- `void` – Method does not return a value.
- `display` – Method name.
- `()` – Parameter list.
- `{}` – Method body.

## 1.6 Types of Methods Based on Return Value and Parameters

### A. No Parameters and No Return Value

```java
static void display() {

    System.out.println("Hello Java");

}
```

Calling:

```java
display();
```

### B. Parameters but No Return Value

```java
static void display(String name) {

    System.out.println("Hello " + name);

}
```

Calling:

```java
display("Anurag");
```

Output:

```text
Hello Anurag
```

### C. No Parameters but Returns a Value

```java
static int getNumber() {

    return 100;

}
```

Calling:

```java
int result = getNumber();

System.out.println(result);
```

Output:

```text
100
```

### D. Parameters and Returns a Value

```java
static int add(int a, int b) {

    return a + b;

}
```

Calling:

```java
int result = add(10, 20);

System.out.println(result);
```

Output:

```text
30
```

## 1.7 Method Parameters and Arguments

Parameters are variables declared in a method definition.

Arguments are actual values passed during a method call.

Example:

```java
static int add(int a, int b) {

    return a + b;

}

public static void main(String[] args) {

    int result = add(10, 20);

}
```

Here:

- `a` and `b` are parameters.
- `10` and `20` are arguments.

## 1.8 Method Overloading

Method overloading means defining multiple methods with the same name but different parameter lists.

The parameter lists must differ by number, types or order of parameters.

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

**Important CMCE Point:** Changing only the return type does not create a valid overloaded method.

## 1.9 Static vs Instance Methods

| Static Method | Instance Method |
|---|---|
| Belongs to class | Belongs to object |
| Declared using static | Declared without static |
| Can be called using class name | Normally called using object |
| Cannot directly access instance members | Can access both static and instance members |
| Example: `Math.sqrt()` | Example: `obj.display()` |

---

# 2. Data Type Compatibility

## 2.1 What is Data Type Compatibility?

Data type compatibility determines whether a value of one data type can be assigned to a variable of another data type.

Example:

```java
int a = 10;

double b = a;
```

This is valid because an `int` can be converted into a `double` automatically.

However:

```java
double x = 10.5;

int y = x;
```

This is invalid because Java does not automatically allow this narrowing conversion.

Correct:

```java
int y = (int) x;
```

## 2.2 Widening Primitive Conversion

Widening means converting a value from a smaller numeric type to a wider numeric type.

It generally happens automatically.

Common conversion paths:

```text
byte → short → int → long → float → double
              ↑
             char
```

Example:

```java
class Widening {

    public static void main(String[] args) {

        int a = 100;

        double b = a;

        System.out.println(a);

        System.out.println(b);

    }
}
```

Output:

```text
100
100.0
```

Explanation:

The integer value `100` is automatically converted into a double value `100.0`.

## 2.3 Narrowing Primitive Conversion

Narrowing means converting a wider numeric type into a narrower numeric type.

It usually requires explicit casting.

Example:

```java
class Narrowing {

    public static void main(String[] args) {

        double a = 99.99;

        int b = (int) a;

        System.out.println(b);

    }
}
```

Output:

```text
99
```

The fractional part is discarded.

### Important: Data Loss During Narrowing

```java
int a = 130;

byte b = (byte) a;

System.out.println(b);
```

Output:

```text
-126
```

Why?

A byte can represent values from -128 to 127. Converting 130 to byte wraps the represented value according to the 8-bit two's-complement representation.

## 2.4 Type Promotion in Expressions

Java automatically promotes certain types when performing arithmetic operations.

For example:

- `byte`, `short` and `char` are generally promoted to `int` in arithmetic expressions.
- If an expression contains a `long`, its integral arithmetic result is generally `long`.
- If an expression contains a `float`, it is generally promoted to `float`, unless a `double` is involved.
- If an expression contains a `double`, the result is generally `double`.

Example:

```java
class PromotionDemo {

    public static void main(String[] args) {

        byte a = 10;

        byte b = 20;

        int result = a + b;

        System.out.println(result);

    }
}
```

Output:

```text
30
```

Why is the result declared as `int`?

Because `byte` operands are promoted to `int` during arithmetic.

This is invalid:

```java
byte result = a + b;
```

Correct:

```java
byte result = (byte) (a + b);
```

## 2.5 Compatibility Between Primitive Types

| Conversion | Allowed Automatically? |
|---|---|
| byte to short | Yes |
| short to int | Yes |
| int to long | Yes |
| int to double | Yes |
| long to float | Yes, but precision may be lost |
| double to int | No, explicit cast required |
| int to byte | No, explicit cast required |
| char to int | Yes |
| boolean to int | No |

## 2.6 Compatibility Between Reference Types

Reference types also have compatibility rules.

### Upcasting

Converting a child-class reference to a parent-class reference is generally allowed automatically.

```java
class Animal {

    void sound() {

        System.out.println("Animal sound");

    }
}

class Dog extends Animal {

    void bark() {

        System.out.println("Dog barks");

    }
}

class Main {

    public static void main(String[] args) {

        Animal a = new Dog();

        a.sound();

    }
}
```

### Downcasting

Converting a parent-class reference back to a child-class reference requires an explicit cast.

```java
Animal a = new Dog();

Dog d = (Dog) a;

d.bark();
```

A downcast can fail at runtime if the object is not actually an instance of the target type.

**Remember:** Primitive casting and reference casting are different concepts.

---

# 3. Operators in Java

## 3.1 What is an Operator?

An operator is a symbol used to perform an operation on one or more operands.

Example:

```java
int result = 10 + 20;
```

Here:

- `10` and `20` are operands.
- `+` is an operator.

Java supports several types of operators.

## 3.2 Arithmetic Operators

Used to perform mathematical calculations.

| Operator | Meaning | Example | Result |
|---|---|---|---|
| + | Addition | 10 + 5 | 15 |
| - | Subtraction | 10 - 5 | 5 |
| * | Multiplication | 10 * 5 | 50 |
| / | Division | 10 / 5 | 2 |
| % | Modulus | 10 % 3 | 1 |

Example:

```java
class ArithmeticDemo {

    public static void main(String[] args) {

        int a = 10;

        int b = 3;

        System.out.println(a + b);

        System.out.println(a - b);

        System.out.println(a * b);

        System.out.println(a / b);

        System.out.println(a % b);

    }
}
```

Output:

```text
13
7
30
3
1
```

**Important:** Integer division removes the fractional part.

```java
System.out.println(10 / 3);
```

Output:

```text
3
```

But:

```java
System.out.println(10.0 / 3);
```

Output:

```text
3.3333333333333335
```

## 3.3 Relational Operators

Relational operators compare two values and return a boolean result.

| Operator | Meaning |
|---|---|
| == | Equal to |
| != | Not equal to |
| > | Greater than |
| < | Less than |
| >= | Greater than or equal to |
| <= | Less than or equal to |

Example:

```java
int a = 10;

int b = 20;

System.out.println(a < b);

System.out.println(a == b);

System.out.println(a != b);
```

Output:

```text
true
false
true
```

## 3.4 Logical Operators

Logical operators combine or reverse boolean expressions.

| Operator | Meaning |
|---|---|
| && | Logical AND |
| \|\| | Logical OR |
| ! | Logical NOT |

### Logical AND (&&)

Returns true only when both conditions are true.

| A | B | A && B |
|---|---|---|
| true | true | true |
| true | false | false |
| false | true | false |
| false | false | false |

Example:

```java
int age = 22;

boolean hasID = true;

System.out.println(age >= 18 && hasID);
```

Output:

```text
true
```

### Logical OR (||)

Returns true when at least one condition is true.

| A | B | A \|\| B |
|---|---|---|
| true | true | true |
| true | false | true |
| false | true | true |
| false | false | false |

### Logical NOT (!)

Reverses a boolean value.

```java
boolean status = true;

System.out.println(!status);
```

Output:

```text
false
```

### Short-Circuit Evaluation

Java's `&&` and `||` operators use short-circuit evaluation.

For `&&`, if the first condition is false, the second condition is not evaluated.

For `||`, if the first condition is true, the second condition is not evaluated.

Example:

```java
int a = 10;

if (a > 5 || a++ > 10) {

    System.out.println(a);

}
```

Output:

```text
10
```

The second condition is skipped because the first condition is already true.

## 3.5 Assignment Operators

Used to assign values to variables.

| Operator | Example | Equivalent |
|---|---|---|
| = | a = 10 | Assign 10 |
| += | a += 5 | a = a + 5 |
| -= | a -= 5 | a = a - 5 |
| *= | a *= 5 | a = a * 5 |
| /= | a /= 5 | a = a / 5 |
| %= | a %= 5 | a = a % 5 |

Example:

```java
int a = 10;

a += 5;

System.out.println(a);
```

Output:

```text
15
```

## 3.6 Unary Operators

Unary operators operate on a single operand.

| Operator | Meaning |
|---|---|
| + | Unary plus |
| - | Unary minus |
| ++ | Increment |
| -- | Decrement |
| ! | Logical NOT |
| ~ | Bitwise complement |

### Increment Operator

Increment increases a variable's value by one.

Two forms:

**Pre-increment:**

```java
int a = 10;

int b = ++a;
```

Result:

```text
a = 11
b = 11
```

**Post-increment:**

```java
int a = 10;

int b = a++;
```

Result:

```text
a = 11
b = 10
```

### Pre vs Post Increment

| Pre-Increment | Post-Increment |
|---|---|
| `++a` | `a++` |
| Increment first | Use old value first |
| Then evaluate expression | Increment after value is used |

## 3.7 Bitwise Operators

Bitwise operators perform operations on individual bits of integral values.

| Operator | Meaning |
|---|---|
| & | Bitwise AND |
| \| | Bitwise OR |
| ^ | Bitwise XOR |
| ~ | Bitwise Complement |

Example:

```java
int a = 5;

int b = 3;

System.out.println(a & b);

System.out.println(a | b);

System.out.println(a ^ b);
```

Binary representation:

```text
5 = 0101
3 = 0011
```

Output:

```text
1
7
6
```

## 3.8 Shift Operators

Shift operators move bits left or right.

| Operator | Meaning |
|---|---|
| << | Left shift |
| >> | Signed right shift |
| >>> | Unsigned right shift |

Example:

```java
int a = 8;

System.out.println(a << 1);

System.out.println(a >> 1);
```

Output:

```text
16
4
```

## 3.9 Ternary Operator

The ternary operator is a shorthand form of an if-else expression.

Syntax:

```java
condition ? expression1 : expression2;
```

Example:

```java
int age = 22;

String result = age >= 18 ? "Eligible" : "Not Eligible";

System.out.println(result);
```

Output:

```text
Eligible
```

## 3.10 instanceof Operator

The `instanceof` operator checks whether an object is an instance of a particular type.

Example:

```java
String name = "Java";

System.out.println(name instanceof String);
```

Output:

```text
true
```

## 3.11 Operator Precedence

Operator precedence determines the order in which operators are evaluated.

Example:

```java
int result = 10 + 5 * 2;

System.out.println(result);
```

Output:

```text
20
```

Multiplication has higher precedence than addition.

Common precedence order, from higher to lower:

1. Postfix operators: `expr++`, `expr--`
2. Unary operators: `++`, `--`, `!`, `~`, unary `+`, unary `-`
3. Multiplicative: `*`, `/`, `%`
4. Additive: `+`, `-`
5. Shift operators
6. Relational and `instanceof`
7. Equality: `==`, `!=`
8. Bitwise AND, XOR, OR
9. Logical AND: `&&`
10. Logical OR: `||`
11. Ternary: `?:`
12. Assignment operators

**Tip:** Use parentheses to make complex expressions easier to understand.

---

# 4. Conditional Statements

Conditional statements allow a program to make decisions based on conditions.

For example:

- Check whether a number is positive or negative.
- Check whether a student has passed.
- Calculate a discount based on purchase amount.
- Check whether a person is eligible to vote.

## 4.1 if Statement

The `if` statement executes a block only when the condition is true.

Syntax:

```java
if (condition) {

    // Statements

}
```

Example:

```java
class IfDemo {

    public static void main(String[] args) {

        int age = 22;

        if (age >= 18) {

            System.out.println("Eligible to vote");

        }

    }
}
```

Output:

```text
Eligible to vote
```

## 4.2 if-else Statement

Used when there are two possible outcomes.

Syntax:

```java
if (condition) {

    // True block

}
else {

    // False block

}
```

Example:

```java
int number = 7;

if (number % 2 == 0) {

    System.out.println("Even");

}
else {

    System.out.println("Odd");

}
```

Output:

```text
Odd
```

## 4.3 else-if Ladder

Used when multiple conditions need to be checked.

Example:

```java
class GradeDemo {

    public static void main(String[] args) {

        int marks = 85;

        if (marks >= 90) {

            System.out.println("Grade A+");

        }
        else if (marks >= 75) {

            System.out.println("Grade A");

        }
        else if (marks >= 60) {

            System.out.println("Grade B");

        }
        else if (marks >= 40) {

            System.out.println("Grade C");

        }
        else {

            System.out.println("Fail");

        }

    }
}
```

Output:

```text
Grade A
```

**Important:** Conditions are checked from top to bottom. Once a condition is true, its block executes and the remaining branches are skipped.

## 4.4 Nested if Statement

An if statement inside another if statement is called a nested if statement.

Example:

```java
int age = 22;

boolean hasID = true;

if (age >= 18) {

    if (hasID) {

        System.out.println("Entry Allowed");

    }

}
```

Output:

```text
Entry Allowed
```

## 4.5 Traditional switch Statement

The switch statement selects one branch from multiple alternatives.

Syntax:

```java
switch (expression) {

    case value1:

        // Statements

        break;

    case value2:

        // Statements

        break;

    default:

        // Default statements

}
```

Example:

```java
class SwitchDemo {

    public static void main(String[] args) {

        int day = 2;

        switch (day) {

            case 1:
                System.out.println("Monday");
                break;

            case 2:
                System.out.println("Tuesday");
                break;

            case 3:
                System.out.println("Wednesday");
                break;

            default:
                System.out.println("Invalid Day");

        }

    }
}
```

Output:

```text
Tuesday
```

### Why is break Used?

In traditional switch statements, `break` exits the switch block.

Without `break`, execution may continue into subsequent case labels. This is called fall-through.

## 4.6 Switch Expression – Java 14+

Switch expressions were finalized in Java 14.

Unlike a traditional switch statement, a switch expression produces a value.

### Example

```java
class SwitchExpressionDemo {

    public static void main(String[] args) {

        int day = 2;

        String result = switch (day) {

            case 1 -> "Monday";

            case 2 -> "Tuesday";

            case 3 -> "Wednesday";

            default -> "Invalid Day";

        };

        System.out.println(result);

    }
}
```

Output:

```text
Tuesday
```

Explanation:

- `switch (day)` evaluates the expression.
- `case 1`, `case 2` and `case 3` represent alternatives.
- `->` is the switch rule arrow.
- Each branch provides a value.
- The resulting value is stored in `result`.

### Advantages of Switch Expression

1. Produces a value.
2. Reduces boilerplate code.
3. Avoids accidental fall-through between arrow rules.
4. Makes code easier to read.
5. Can be used with a variable assignment or return statement.

### Switch Expression Using yield

When a switch rule needs multiple statements, use `yield` to return a value from the switch expression.

Example:

```java
class YieldDemo {

    public static void main(String[] args) {

        int marks = 85;

        String grade = switch (marks / 10) {

            case 10, 9 -> "A";

            case 8 -> {

                System.out.println("Very Good Performance");

                yield "B";

            }

            case 7 -> "C";

            default -> "Needs Improvement";

        };

        System.out.println(grade);

    }
}
```

Output:

```text
Very Good Performance
B
```

### Traditional Switch vs Switch Expression

| Traditional Switch | Switch Expression |
|---|---|
| Statement | Expression |
| Does not directly produce a value | Produces a value |
| Commonly uses break | Arrow rules avoid fall-through |
| Uses colon syntax | Supports arrow syntax |
| Available in earlier Java versions | Finalized in Java 14 |
| Does not use yield to return a value | Can use yield in block rules |

**CMCE Important:** Switch expressions require Java 14 or later. Use Java 17 for the lab.

---

# 5. Control Statements

Control statements determine the flow of program execution.

They are classified into:

1. Selection statements.
2. Iteration statements.
3. Jump statements.

## 5.1 Selection Statements

Used to select a block based on conditions.

Examples:

- if
- if-else
- else-if
- switch

## 5.2 Iteration Statements / Loops

Loops execute a block repeatedly.

Java provides:

1. for loop.
2. while loop.
3. do-while loop.
4. Enhanced for loop.

### A. for Loop

Used when the number of iterations is known or can be controlled using an initialization, condition and update.

Syntax:

```java
for (initialization; condition; update) {

    // Statements

}
```

Example:

```java
class ForDemo {

    public static void main(String[] args) {

        for (int i = 1; i <= 5; i++) {

            System.out.println(i);

        }

    }
}
```

Output:

```text
1
2
3
4
5
```

Execution:

```text
Initialization
      |
      v
   Condition
      |
   True?
   /   \
 Yes    No
  |      |
  v      v
Body    Exit
  |
  v
Update
  |
  --------> Condition
```

### B. while Loop

Checks the condition before executing the loop body.

Syntax:

```java
while (condition) {

    // Statements

}
```

Example:

```java
class WhileDemo {

    public static void main(String[] args) {

        int i = 1;

        while (i <= 5) {

            System.out.println(i);

            i++;

        }

    }
}
```

Output:

```text
1
2
3
4
5
```

Use a while loop when the number of repetitions is not necessarily known beforehand.

### C. do-while Loop

Executes the loop body at least once because the condition is checked after execution.

Syntax:

```java
do {

    // Statements

} while (condition);
```

Example:

```java
class DoWhileDemo {

    public static void main(String[] args) {

        int i = 1;

        do {

            System.out.println(i);

            i++;

        } while (i <= 5);

    }
}
```

Output:

```text
1
2
3
4
5
```

### D. Enhanced for Loop

Also called the for-each loop.

Used to traverse arrays and collections.

Example:

```java
class EnhancedForDemo {

    public static void main(String[] args) {

        int[] numbers = {10, 20, 30, 40, 50};

        for (int number : numbers) {

            System.out.println(number);

        }

    }
}
```

Output:

```text
10
20
30
40
50
```

### for vs while vs do-while

| for | while | do-while |
|---|---|---|
| Initialization, condition and update together | Condition checked first | Condition checked after body |
| Useful for counted iterations | Useful for condition-based repetition | Useful when body must execute at least once |
| May execute zero times | May execute zero times | Executes at least once |

## 5.3 Jump Statements

Jump statements alter the normal flow of execution.

Java provides:

- break
- continue
- return

### A. break

Terminates the nearest enclosing loop or switch statement.

Example:

```java
for (int i = 1; i <= 10; i++) {

    if (i == 5) {

        break;

    }

    System.out.println(i);

}
```

Output:

```text
1
2
3
4
```

### B. continue

Skips the remaining statements of the current loop iteration and proceeds to the next iteration.

Example:

```java
for (int i = 1; i <= 5; i++) {

    if (i == 3) {

        continue;

    }

    System.out.println(i);

}
```

Output:

```text
1
2
4
5
```

### C. return

Terminates a method and optionally returns a value.

Example:

```java
static int add(int a, int b) {

    return a + b;

}
```

Calling:

```java
System.out.println(add(10, 20));
```

Output:

```text
30
```

### break vs continue vs return

| Statement | Purpose |
|---|---|
| break | Terminates nearest loop or switch |
| continue | Skips current loop iteration |
| return | Exits the current method |

---

# 6. Arrays – 1-D and Multidimensional Arrays

## 6.1 What is an Array?

An array is an object that stores a fixed number of elements of the same component type.

Instead of declaring multiple variables, an array allows us to store related values using one variable name and indexes.

Without an array:

```java
int a = 10;

int b = 20;

int c = 30;

int d = 40;
```

Using an array:

```java
int[] numbers = {10, 20, 30, 40};
```

Advantages:

1. Stores multiple values under one variable name.
2. Provides indexed access.
3. Makes loops useful for processing multiple values.
4. Reduces repetitive declarations.

## 6.2 One-Dimensional Array

A one-dimensional array stores elements in a linear sequence.

### Declaration

```java
int[] numbers;
```

### Creation

```java
numbers = new int[5];
```

### Declaration and Creation Together

```java
int[] numbers = new int[5];
```

### Initialization

```java
int[] numbers = {10, 20, 30, 40, 50};
```

### Array Indexing

Array indexing starts from zero.

```text
Index:     0    1    2    3    4
         -------------------------
Array:   | 10 | 20 | 30 | 40 | 50 |
         -------------------------
```

Example:

```java
class ArrayDemo {

    public static void main(String[] args) {

        int[] numbers = {10, 20, 30, 40, 50};

        System.out.println(numbers[0]);

        System.out.println(numbers[2]);

        System.out.println(numbers[4]);

    }
}
```

Output:

```text
10
30
50
```

## 6.3 Access and Update Array Elements

Example:

```java
class ArrayUpdate {

    public static void main(String[] args) {

        int[] numbers = {10, 20, 30};

        numbers[1] = 100;

        System.out.println(numbers[1]);

    }
}
```

Output:

```text
100
```

## 6.4 Array Length

The `length` property returns the number of elements in an array.

Example:

```java
int[] numbers = {10, 20, 30, 40};

System.out.println(numbers.length);
```

Output:

```text
4
```

Remember:

- Array uses `length`.
- String uses `length()`.
- Collection types commonly use `size()`.

## 6.5 Traversing an Array

### Using for Loop

```java
class ArrayTraversal {

    public static void main(String[] args) {

        int[] numbers = {10, 20, 30, 40, 50};

        for (int i = 0; i < numbers.length; i++) {

            System.out.println(numbers[i]);

        }

    }
}
```

### Using Enhanced for Loop

```java
class ArrayTraversal {

    public static void main(String[] args) {

        int[] numbers = {10, 20, 30, 40, 50};

        for (int value : numbers) {

            System.out.println(value);

        }

    }
}
```

## 6.6 Default Values in Arrays

Array elements receive default values automatically.

| Array Type | Default Value |
|---|---|
| int | 0 |
| byte | 0 |
| short | 0 |
| long | 0L |
| float | 0.0f |
| double | 0.0d |
| char | '\u0000' |
| boolean | false |
| Reference types | null |

Example:

```java
class ArrayDefault {

    public static void main(String[] args) {

        int[] numbers = new int[3];

        for (int value : numbers) {

            System.out.println(value);

        }

    }
}
```

Output:

```text
0
0
0
```

## 6.7 Common Array Operations

### A. Find Sum of Array Elements

```java
class ArraySum {

    public static void main(String[] args) {

        int[] arr = {10, 20, 30, 40, 50};

        int sum = 0;

        for (int i = 0; i < arr.length; i++) {

            sum += arr[i];

        }

        System.out.println("Sum = " + sum);

    }
}
```

Output:

```text
Sum = 150
```

### B. Find Maximum Element

```java
class ArrayMaximum {

    public static void main(String[] args) {

        int[] arr = {10, 50, 20, 80, 30};

        int max = arr[0];

        for (int i = 1; i < arr.length; i++) {

            if (arr[i] > max) {

                max = arr[i];

            }

        }

        System.out.println("Maximum = " + max);

    }
}
```

Output:

```text
Maximum = 80
```

### C. Find Minimum Element

```java
class ArrayMinimum {

    public static void main(String[] args) {

        int[] arr = {10, 50, 20, 80, 30};

        int min = arr[0];

        for (int value : arr) {

            if (value < min) {

                min = value;

            }

        }

        System.out.println("Minimum = " + min);

    }
}
```

Output:

```text
Minimum = 10
```

## 6.8 Multidimensional Arrays

A multidimensional array is an array whose components are themselves arrays.

Java supports arrays of arrays.

The most common form is a two-dimensional array, often used to represent a matrix.

### Two-Dimensional Array

Declaration:

```java
int[][] matrix;
```

Creation:

```java
matrix = new int[3][3];
```

Declaration and initialization:

```java
int[][] matrix = {

    {1, 2, 3},

    {4, 5, 6},

    {7, 8, 9}

};
```

### Matrix Representation

```text
        Column
        0  1  2
      ----------
Row 0 | 1  2  3 |
Row 1 | 4  5  6 |
Row 2 | 7  8  9 |
      ----------
```

### Accessing Elements

```java
System.out.println(matrix[0][0]);

System.out.println(matrix[1][2]);

System.out.println(matrix[2][1]);
```

Output:

```text
1
6
8
```

## 6.9 Traversing a 2-D Array

Use nested loops.

Example:

```java
class MatrixDemo {

    public static void main(String[] args) {

        int[][] matrix = {

            {1, 2, 3},

            {4, 5, 6},

            {7, 8, 9}

        };

        for (int i = 0; i < matrix.length; i++) {

            for (int j = 0; j < matrix[i].length; j++) {

                System.out.print(matrix[i][j] + " ");

            }

            System.out.println();

        }

    }
}
```

Output:

```text
1 2 3
4 5 6
7 8 9
```

Explanation:

- Outer loop controls rows.
- Inner loop controls columns.
- `matrix.length` gives the number of rows.
- `matrix[i].length` gives the number of columns in row `i`.

## 6.10 Jagged Arrays

A jagged array is a two-dimensional array in which different rows can have different lengths.

Example:

```java
class JaggedArrayDemo {

    public static void main(String[] args) {

        int[][] arr = new int[3][];

        arr[0] = new int[2];

        arr[1] = new int[3];

        arr[2] = new int[4];

        arr[0][0] = 10;

        arr[0][1] = 20;

        arr[1][0] = 30;

        arr[1][1] = 40;

        arr[1][2] = 50;

        arr[2][0] = 60;

        arr[2][1] = 70;

        arr[2][2] = 80;

        arr[2][3] = 90;

        for (int[] row : arr) {

            for (int value : row) {

                System.out.print(value + " ");

            }

            System.out.println();

        }

    }
}
```

Output:

```text
10 20
30 40 50
60 70 80 90
```

## 6.11 Three-Dimensional Arrays

A three-dimensional array contains arrays of two-dimensional arrays.

Example:

```java
class ThreeDArray {

    public static void main(String[] args) {

        int[][][] arr = new int[2][2][2];

        arr[0][0][0] = 10;

        arr[0][0][1] = 20;

        arr[0][1][0] = 30;

        arr[0][1][1] = 40;

        arr[1][0][0] = 50;

        arr[1][0][1] = 60;

        arr[1][1][0] = 70;

        arr[1][1][1] = 80;

        System.out.println(arr[1][1][1]);

    }
}
```

Output:

```text
80
```

## 6.12 Important Array Concepts

| Concept | Explanation |
|---|---|
| Index | Position of an element, starting from zero |
| length | Number of elements |
| ArrayIndexOutOfBoundsException | Accessing an invalid index |
| Jagged Array | Rows with different lengths |
| 2-D Array | Array of arrays, commonly used as a matrix |
| Array Default Value | Automatically assigned to array elements |

**Important:** Java arrays have fixed length after creation. Their size cannot be changed.

---

# 7. Lab: Java Environment and IDE Setup

## 7.1 What is an IDE?

IDE stands for Integrated Development Environment.

An IDE provides tools for writing, compiling, executing, debugging and managing programs.

Common Java IDEs:

1. Eclipse IDE.
2. IntelliJ IDEA.
3. Spring Tools for Eclipse (STS).
4. NetBeans.

## 7.2 JDK Installation

For this CMCE course, use Java 17 compatibility.

Steps:

1. Download a JDK 17 distribution.
2. Install the JDK.
3. Configure the `JAVA_HOME` environment variable if required.
4. Add the JDK `bin` directory to the system PATH.
5. Open Command Prompt.
6. Verify the installation.

Commands:

```bash
java -version

javac -version
```

**Note:** If you already have JDK 21 installed, most Java 17 programs can also compile and run with it. For course alignment, configure your IDE project language level to Java 17 when required.

## 7.3 IDE Setup

General steps for Eclipse or STS:

1. Install and open the IDE.
2. Select a workspace folder.
3. Open File → New → Java Project.
4. Enter project name: `CMCE_Basic_Programs`.
5. Select the installed JDK.
6. Select Java 17 compliance if available.
7. Create a package such as `session2`.
8. Create a Java class.
9. Select the `public static void main(String[] args)` option if needed.
10. Write and execute the program.

## 7.4 Suggested Project Structure

```text
CMCE_Basic_Programs/
│
└── src/
    │
    └── session2/
        │
        ├── VariableDemo.java
        ├── MethodDemo.java
        ├── OperatorDemo.java
        ├── ConditionalDemo.java
        ├── LoopDemo.java
        ├── BillDiscount.java
        ├── Calculator.java
        ├── Factorial.java
        ├── Armstrong.java
        ├── Fibonacci.java
        ├── PatternDemo.java
        └── MatrixDiagonalSum.java
```

---

# 8. Lab Practical Programs

# Practical 1: Calculate Total Bill After Applying Discount

## Problem Statement

Write a Java program to calculate the total bill amount after applying a discount based on the purchase amount.

## Logic

1. Accept the purchase amount.
2. Check the purchase amount.
3. Determine the discount percentage.
4. Calculate the discount amount.
5. Calculate the final bill.
6. Display the bill details.

## Discount Slab – Illustrative Example

For practice, assume the following discount structure:

| Purchase Amount | Discount |
|---|---:|
| Below ₹1,000 | 0% |
| ₹1,000 to ₹4,999 | 5% |
| ₹5,000 to ₹9,999 | 10% |
| ₹10,000 and above | 15% |

**Note:** These slabs are illustrative because the original assignment does not specify exact discount rates. Replace them with your instructor's rules if different.

## Formula

```text
Discount Amount = Purchase Amount × Discount Rate / 100

Final Bill = Purchase Amount - Discount Amount
```

## Java Program

```java
import java.util.Scanner;

class BillDiscount {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter purchase amount: ");

        double amount = sc.nextDouble();

        double discountRate;

        if (amount < 0) {

            System.out.println("Invalid purchase amount");

        }
        else {

            if (amount >= 10000) {

                discountRate = 15;

            }
            else if (amount >= 5000) {

                discountRate = 10;

            }
            else if (amount >= 1000) {

                discountRate = 5;

            }
            else {

                discountRate = 0;

            }

            double discount = amount * discountRate / 100;

            double finalBill = amount - discount;

            System.out.println("\n----- BILL DETAILS -----");

            System.out.println("Purchase Amount: ₹" + amount);

            System.out.println("Discount Rate: " + discountRate + "%");

            System.out.println("Discount Amount: ₹" + discount);

            System.out.println("Final Bill: ₹" + finalBill);

        }

        sc.close();

    }
}
```

## Sample Output

```text
Enter purchase amount: 6000

----- BILL DETAILS -----
Purchase Amount: ₹6000.0
Discount Rate: 10.0%
Discount Amount: ₹600.0
Final Bill: ₹5400.0
```

## Explanation

For a purchase amount of ₹6,000:

- Discount rate = 10%.
- Discount amount = 6000 × 10 / 100 = ₹600.
- Final bill = 6000 - 600 = ₹5,400.

**Concepts Used:**

- Scanner class.
- Variables.
- if-else ladder.
- Arithmetic operators.
- Double data type.

---

# Practical 2: Menu-Driven Calculator Using Java 14+ Switch Expression

## Problem Statement

Write a menu-driven calculator that performs:

1. Addition.
2. Subtraction.
3. Multiplication.
4. Division.

Use Java 14+ switch expression.

## Logic

1. Accept two numbers.
2. Display the calculator menu.
3. Accept the user's choice.
4. Use a switch expression to perform the selected operation.
5. Check division by zero.
6. Display the result.

## Java Program

```java
import java.util.Scanner;

class Calculator {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first number: ");

        double a = sc.nextDouble();

        System.out.print("Enter second number: ");

        double b = sc.nextDouble();

        System.out.println("\n----- CALCULATOR MENU -----");

        System.out.println("1. Addition");

        System.out.println("2. Subtraction");

        System.out.println("3. Multiplication");

        System.out.println("4. Division");

        System.out.print("Enter your choice: ");

        int choice = sc.nextInt();

        String result = switch (choice) {

            case 1 -> "Result = " + (a + b);

            case 2 -> "Result = " + (a - b);

            case 3 -> "Result = " + (a * b);

            case 4 -> {

                if (b == 0) {

                    yield "Error: Division by zero is not allowed";

                }

                yield "Result = " + (a / b);

            }

            default -> "Invalid Choice";

        };

        System.out.println(result);

        sc.close();

    }
}
```

## Sample Output 1

```text
Enter first number: 20
Enter second number: 10

----- CALCULATOR MENU -----
1. Addition
2. Subtraction
3. Multiplication
4. Division
Enter your choice: 1

Result = 30.0
```

## Sample Output 2

```text
Enter first number: 20
Enter second number: 10

----- CALCULATOR MENU -----
1. Addition
2. Subtraction
3. Multiplication
4. Division
Enter your choice: 4

Result = 2.0
```

## Sample Output 3

```text
Enter first number: 20
Enter second number: 0

Enter your choice: 4

Error: Division by zero is not allowed
```

## Explanation

- `switch (choice)` selects the operation.
- `case 1 ->` performs addition.
- `case 2 ->` performs subtraction.
- `case 3 ->` performs multiplication.
- `case 4 ->` performs division.
- `yield` returns a value from the block rule.
- `default` handles invalid choices.

**Concepts Used:**

- Scanner.
- Switch expression.
- Arrow syntax.
- yield.
- Arithmetic operators.
- Conditional statement.

---

# Practical 3: Factorial of a Number Using a Loop

## Problem Statement

Write a Java program to calculate the factorial of a number using a loop.

## What is Factorial?

Factorial is the product of all positive integers from 1 to a given number.

It is represented using the symbol `!`.

For example:

```text
5! = 5 × 4 × 3 × 2 × 1

5! = 120
```

Special case:

```text
0! = 1
```

## Formula

```text
n! = n × (n-1) × (n-2) × ... × 1
```

## Java Program

```java
import java.util.Scanner;

class Factorial {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");

        int n = sc.nextInt();

        long factorial = 1;

        if (n < 0) {

            System.out.println("Factorial is not defined for negative integers");

        }
        else {

            for (int i = 1; i <= n; i++) {

                factorial = factorial * i;

            }

            System.out.println("Factorial = " + factorial);

        }

        sc.close();

    }
}
```

## Sample Output

```text
Enter a number: 5

Factorial = 120
```

## Dry Run

For `n = 5`:

| Iteration | i | factorial |
|---|---:|---:|
| Initial | - | 1 |
| 1 | 1 | 1 |
| 2 | 2 | 2 |
| 3 | 3 | 6 |
| 4 | 4 | 24 |
| 5 | 5 | 120 |

## Explanation

Initially:

```java
long factorial = 1;
```

The loop starts from 1 and continues up to `n`.

In each iteration:

```java
factorial = factorial * i;
```

The factorial value is multiplied by the current loop variable.

**Important:** A `long` can store factorial values only up to 20! without overflow. Larger factorials require `BigInteger`.

---

# Practical 4: Check Whether a Number Is an Armstrong Number

## Problem Statement

Write a Java program to check whether a given number is an Armstrong number.

## What is an Armstrong Number?

An Armstrong number is a non-negative integer that is equal to the sum of its digits, each raised to the power of the total number of digits.

For a three-digit number:

```text
153 = 1³ + 5³ + 3³

153 = 1 + 125 + 27

153 = 153
```

Therefore, 153 is an Armstrong number.

Other examples:

- 0
- 1
- 153
- 370
- 371
- 407
- 1634

## Algorithm

1. Accept a number.
2. Store the original number.
3. Count the number of digits.
4. Extract each digit using `% 10`.
5. Raise each digit to the digit count.
6. Add the results.
7. Compare the sum with the original number.

## Java Program

```java
import java.util.Scanner;

class Armstrong {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");

        int number = sc.nextInt();

        if (number < 0) {

            System.out.println("Enter a non-negative integer");

        }
        else {

            int original = number;

            int temp = number;

            int digits = 0;

            int sum = 0;

            if (temp == 0) {

                digits = 1;

            }

            while (temp > 0) {

                digits++;

                temp = temp / 10;

            }

            temp = number;

            while (temp > 0) {

                int digit = temp % 10;

                sum += (int) Math.pow(digit, digits);

                temp = temp / 10;

            }

            if (sum == original) {

                System.out.println(original + " is an Armstrong number");

            }
            else {

                System.out.println(original + " is not an Armstrong number");

            }

        }

        sc.close();

    }
}
```

## Sample Output 1

```text
Enter a number: 153

153 is an Armstrong number
```

## Sample Output 2

```text
Enter a number: 123

123 is not an Armstrong number
```

## Dry Run: 153

Number = 153

Number of digits = 3

| Digit | Calculation | Result |
|---|---|---:|
| 3 | 3³ | 27 |
| 5 | 5³ | 125 |
| 1 | 1³ | 1 |

Sum:

```text
27 + 125 + 1 = 153
```

Since the sum equals the original number, 153 is an Armstrong number.

## Important Operators

| Operator | Purpose |
|---|---|
| `%` | Extracts the last digit |
| `/` | Removes the last digit in integer division |
| `Math.pow()` | Calculates the power |

**Additional Practice:** Write the Armstrong program without using `Math.pow()`, by implementing a separate power method.

---

# Practical 5: Generate Fibonacci Series up to N Terms

## Problem Statement

Write a Java program to generate the Fibonacci series up to N terms.

## What is Fibonacci Series?

The Fibonacci series is a sequence in which each term is the sum of the previous two terms.

The sequence commonly starts with 0 and 1.

```text
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
```

## Formula

```text
F(n) = F(n-1) + F(n-2)
```

Initial values:

```text
F(0) = 0

F(1) = 1
```

## Algorithm

1. Accept the number of terms `n`.
2. Initialize `first = 0`.
3. Initialize `second = 1`.
4. Print the first term.
5. Calculate the next term using addition.
6. Update the first and second variables.
7. Repeat until N terms are generated.

## Java Program

```java
import java.util.Scanner;

class Fibonacci {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of terms: ");

        int n = sc.nextInt();

        long first = 0;

        long second = 1;

        if (n <= 0) {

            System.out.println("Enter a positive number of terms");

        }
        else {

            System.out.println("Fibonacci Series:");

            for (int i = 1; i <= n; i++) {

                System.out.print(first + " ");

                long next = first + second;

                first = second;

                second = next;

            }

        }

        sc.close();

    }
}
```

## Sample Output

```text
Enter number of terms: 10

Fibonacci Series:

0 1 1 2 3 5 8 13 21 34
```

## Dry Run

Initial values:

```text
first = 0

second = 1
```

| Iteration | Printed Value | Next Value |
|---|---:|---:|
| 1 | 0 | 1 |
| 2 | 1 | 2 |
| 3 | 1 | 3 |
| 4 | 2 | 5 |
| 5 | 3 | 8 |
| 6 | 5 | 13 |

The next value is calculated by adding the previous two values.

**Important:** `long` eventually overflows for sufficiently large Fibonacci terms. Use `BigInteger` for arbitrarily large terms.

---

# Practical 6: Print Different Asterisk Patterns Using Loops

## Problem Statement

Write Java programs to print different patterns of asterisks using loops.

Patterns are important for understanding:

- Nested loops.
- Row and column logic.
- Loop conditions.
- Increment and decrement operations.

## Pattern 1: Right-Angled Triangle

Expected Output for 5 rows:

```text
*
**
***
****
*****
```

### Java Program

```java
class Pattern1 {

    public static void main(String[] args) {

        int n = 5;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= i; j++) {

                System.out.print("*");

            }

            System.out.println();

        }

    }
}
```

### Explanation

Outer loop:

```java
for (int i = 1; i <= n; i++)
```

Controls the number of rows.

Inner loop:

```java
for (int j = 1; j <= i; j++)
```

Controls the number of stars in each row.

## Pattern 2: Inverted Right-Angled Triangle

Output:

```text
*****
****
***
**
*
```

### Java Program

```java
class Pattern2 {

    public static void main(String[] args) {

        int n = 5;

        for (int i = n; i >= 1; i--) {

            for (int j = 1; j <= i; j++) {

                System.out.print("*");

            }

            System.out.println();

        }

    }
}
```

## Pattern 3: Right-Aligned Triangle

Output:

```text
    *
   **
  ***
 ****
*****
```

### Java Program

```java
class Pattern3 {

    public static void main(String[] args) {

        int n = 5;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n - i; j++) {

                System.out.print(" ");

            }

            for (int j = 1; j <= i; j++) {

                System.out.print("*");

            }

            System.out.println();

        }

    }
}
```

## Pattern 4: Pyramid Pattern

Output:

```text
    *
   ***
  *****
 *******
*********
```

### Java Program

```java
class Pattern4 {

    public static void main(String[] args) {

        int n = 5;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n - i; j++) {

                System.out.print(" ");

            }

            for (int j = 1; j <= (2 * i - 1); j++) {

                System.out.print("*");

            }

            System.out.println();

        }

    }
}
```

## Pattern 5: Diamond Pattern

Output:

```text
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

### Java Program

```java
class Pattern5 {

    public static void main(String[] args) {

        int n = 5;

        // Upper half

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n - i; j++) {

                System.out.print(" ");

            }

            for (int j = 1; j <= 2 * i - 1; j++) {

                System.out.print("*");

            }

            System.out.println();

        }

        // Lower half

        for (int i = n - 1; i >= 1; i--) {

            for (int j = 1; j <= n - i; j++) {

                System.out.print(" ");

            }

            for (int j = 1; j <= 2 * i - 1; j++) {

                System.out.print("*");

            }

            System.out.println();

        }

    }
}
```

## Pattern 6: Square Pattern

Output:

```text
*****
*****
*****
*****
*****
```

### Java Program

```java
class Pattern6 {

    public static void main(String[] args) {

        int n = 5;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n; j++) {

                System.out.print("*");

            }

            System.out.println();

        }

    }
}
```

## Pattern Logic Summary

| Pattern | Outer Loop | Inner Loop |
|---|---|---|
| Right triangle | Rows increase | Stars increase |
| Inverted triangle | Rows decrease | Stars decrease |
| Right-aligned triangle | Rows increase | Spaces then stars |
| Pyramid | Rows increase | Spaces then odd number of stars |
| Diamond | Upper and lower halves | Spaces and stars |
| Square | Fixed rows | Fixed columns |

**Practice Tip:** Before writing a pattern program, draw a row-column table and calculate the number of spaces and stars for every row.

---

# Practical 7: Principal Diagonal Sum of a Matrix

## Problem Statement

Write a Java program to find the sum of the principal diagonal elements of a square matrix.

## What is a Matrix?

A matrix is a rectangular arrangement of elements in rows and columns.

Example:

```text
1  2  3
4  5  6
7  8  9
```

## What is the Principal Diagonal?

The principal diagonal is the diagonal starting from the top-left corner and ending at the bottom-right corner.

For the matrix:

```text
1  2  3
4  5  6
7  8  9
```

Principal diagonal elements:

```text
1, 5, 9
```

Sum:

```text
1 + 5 + 9 = 15
```

### Principal Diagonal Condition

For a square matrix:

```text
row index == column index
```

Therefore:

```java
matrix[i][i]
```

accesses the principal diagonal element at index `i`.

## Java Program

```java
import java.util.Scanner;

class MatrixDiagonalSum {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter matrix size: ");

        int n = sc.nextInt();

        if (n <= 0) {

            System.out.println("Matrix size must be positive");

            sc.close();

            return;

        }

        int[][] matrix = new int[n][n];

        System.out.println("Enter matrix elements:");

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                matrix[i][j] = sc.nextInt();

            }

        }

        System.out.println("Matrix:");

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                System.out.print(matrix[i][j] + "\t");

            }

            System.out.println();

        }

        int sum = 0;

        for (int i = 0; i < n; i++) {

            sum += matrix[i][i];

        }

        System.out.println("Principal Diagonal Sum = " + sum);

        sc.close();

    }
}
```

## Sample Input

```text
Enter matrix size: 3

Enter matrix elements:

1 2 3
4 5 6
7 8 9
```

## Sample Output

```text
Matrix:

1    2    3
4    5    6
7    8    9

Principal Diagonal Sum = 15
```

## Dry Run

| Index | Element | Sum |
|---|---:|---:|
| matrix[0][0] | 1 | 1 |
| matrix[1][1] | 5 | 6 |
| matrix[2][2] | 9 | 15 |

Final result:

```text
Principal Diagonal Sum = 15
```

## Principal Diagonal vs Secondary Diagonal

For the matrix:

```text
1  2  3
4  5  6
7  8  9
```

Principal diagonal:

```text
1, 5, 9
```

Secondary diagonal:

```text
3, 5, 7
```

| Diagonal | Condition |
|---|---|
| Principal | `i == j` |
| Secondary | `i + j == n - 1` |

### Additional Program: Secondary Diagonal Sum

```java
class SecondaryDiagonal {

    public static void main(String[] args) {

        int[][] matrix = {

            {1, 2, 3},

            {4, 5, 6},

            {7, 8, 9}

        };

        int n = matrix.length;

        int sum = 0;

        for (int i = 0; i < n; i++) {

            sum += matrix[i][n - 1 - i];

        }

        System.out.println("Secondary Diagonal Sum = " + sum);

    }
}
```

Output:

```text
Secondary Diagonal Sum = 15
```

---

# 9. Important Interview Questions

### Q1. What is a variable?

A variable is a named storage location used to store data during program execution.

### Q2. What are the types of variables in Java?

Local variables, instance variables and static variables.

### Q3. What is the difference between declaration and initialization?

Declaration specifies the variable's data type and name. Initialization assigns its first value.

### Q4. What is a static variable?

A static variable belongs to the class and is shared at the class level.

### Q5. What is a final variable?

A final variable cannot be reassigned after initialization.

### Q6. What is a method?

A method is a block of code that performs a specific task.

### Q7. What is method overloading?

Defining multiple methods with the same name but different parameter lists.

### Q8. Can methods be overloaded by changing only the return type?

No.

### Q9. What is type casting?

Type casting is the conversion of a value from one data type to another compatible type.

### Q10. What is widening conversion?

Automatic conversion from a narrower numeric type to a wider numeric type.

### Q11. What is narrowing conversion?

Conversion from a wider numeric type to a narrower numeric type, generally requiring explicit casting.

### Q12. What is type promotion?

Automatic promotion of certain smaller numeric types during expression evaluation.

### Q13. What is the difference between == and =?

`==` checks equality, whereas `=` assigns a value.

### Q14. What is the difference between && and &?

`&&` is short-circuit logical AND. `&` can perform bitwise AND and, when used with boolean operands, evaluates both operands.

### Q15. What is the difference between pre-increment and post-increment?

Pre-increment increments before the value is used. Post-increment uses the old value before incrementing.

### Q16. What is a switch expression?

A switch expression is a Java expression that selects a branch and produces a value.

### Q17. In which Java version were switch expressions finalized?

Java 14.

### Q18. What is yield?

`yield` returns a value from a block rule in a switch expression.

### Q19. What is the difference between break and continue?

`break` exits the nearest loop or switch, whereas `continue` skips the current loop iteration.

### Q20. What is the difference between while and do-while?

while checks the condition before executing the body; do-while checks it after executing the body.

### Q21. What is an array?

An array is an object that stores a fixed number of elements of the same component type.

### Q22. What is the starting index of an array?

Zero.

### Q23. What is the difference between length and length()?

Array uses the `length` property, whereas String uses the `length()` method.

### Q24. What is a multidimensional array?

An array whose elements are themselves arrays.

### Q25. What is a jagged array?

A multidimensional array in which rows can have different lengths.

### Q26. What is an Armstrong number?

A non-negative number equal to the sum of its digits raised to the power of the number of digits.

### Q27. What is factorial?

The product of all positive integers from 1 to a given number, with 0! equal to 1.

### Q28. What is the Fibonacci series?

A sequence where each term is the sum of the previous two terms.

### Q29. What is a principal diagonal?

The diagonal running from the top-left to the bottom-right of a square matrix.

### Q30. How do you access a principal diagonal element?

Using `matrix[i][i]`.

---

# 10. CMCE Practice MCQs

### Q1. Which type of variable is shared at the class level?

A. Local  
B. Instance  
C. Static  
D. Parameter

**Answer: C. Static**

### Q2. Which keyword is used to declare a constant?

A. static  
B. final  
C. const  
D. fixed

**Answer: B. final**

### Q3. Which method can return an integer?

A. void display()  
B. int calculate()  
C. static void main()  
D. None

**Answer: B. int calculate()**

### Q4. Which conversion generally requires explicit casting?

A. int to long  
B. int to double  
C. double to int  
D. byte to int

**Answer: C. double to int**

### Q5. What is the result of `10 / 3` using integer operands?

A. 3.33  
B. 3  
C. 4  
D. 0

**Answer: B. 3**

### Q6. Which operator performs logical AND with short-circuit evaluation?

A. &  
B. &&  
C. \|\|  
D. !

**Answer: B. &&**

### Q7. What is the output?

```java
int a = 10;

int b = a++;

System.out.println(b);
```

A. 10  
B. 11  
C. 12  
D. Compilation error

**Answer: A. 10**

### Q8. Which statement executes a loop body at least once?

A. for  
B. while  
C. do-while  
D. None

**Answer: C. do-while**

### Q9. Which Java version finalized switch expressions?

A. Java 8  
B. Java 11  
C. Java 14  
D. Java 17

**Answer: C. Java 14**

### Q10. Which keyword returns a value from a switch expression block?

A. break  
B. return  
C. yield  
D. continue

**Answer: C. yield**

### Q11. What is the starting index of an array?

A. -1  
B. 0  
C. 1  
D. Depends on size

**Answer: B. 0**

### Q12. Which property gives the length of an array?

A. size()  
B. length()  
C. length  
D. count()

**Answer: C. length**

### Q13. Which exception occurs when an invalid array index is accessed?

A. NullPointerException  
B. ArrayIndexOutOfBoundsException  
C. IOException  
D. ArithmeticException

**Answer: B. ArrayIndexOutOfBoundsException**

### Q14. What is the principal diagonal condition?

A. i > j  
B. i < j  
C. i == j  
D. i + j == n

**Answer: C. i == j**

### Q15. What is 5 factorial?

A. 25  
B. 60  
C. 100  
D. 120

**Answer: D. 120**

### Q16. Which of the following is an Armstrong number?

A. 123  
B. 153  
C. 125  
D. 111

**Answer: B. 153**

### Q17. What are the first two terms of the standard Fibonacci series?

A. 1, 2  
B. 0, 1  
C. 2, 3  
D. 1, 3

**Answer: B. 0, 1**

### Q18. Which loop is most commonly used for array traversal when the index is not needed?

A. Enhanced for  
B. do-while only  
C. switch  
D. if

**Answer: A. Enhanced for**

### Q19. What does break do?

A. Skips the current iteration  
B. Exits the nearest loop or switch  
C. Restarts the program  
D. Returns a value

**Answer: B. Exits the nearest loop or switch**

### Q20. What does continue do?

A. Exits the program  
B. Exits the method  
C. Skips the current iteration  
D. Terminates the JVM

**Answer: C. Skips the current iteration**

---

# 11. Important Output-Based Questions

## Question 1

```java
int a = 5;

System.out.println(a++);

System.out.println(++a);
```

Output:

```text
5
7
```

Explanation:

- `a++` prints 5 and then increments to 6.
- `++a` increments to 7 and then prints 7.

## Question 2

```java
int a = 10;

int b = 20;

System.out.println(a + b * 2);
```

Output:

```text
50
```

Explanation:

Multiplication happens before addition.

## Question 3

```java
for (int i = 1; i <= 5; i++) {

    if (i == 3) {

        continue;

    }

    System.out.print(i + " ");

}
```

Output:

```text
1 2 4 5
```

## Question 4

```java
int[] arr = {10, 20, 30};

System.out.println(arr.length);
```

Output:

```text
3
```

## Question 5

```java
int[][] arr = {

    {1, 2},

    {3, 4}

};

System.out.println(arr[1][0]);
```

Output:

```text
3
```

---

# 12. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Variable | Named storage location |
| Local Variable | Declared inside method/block |
| Instance Variable | Belongs to object |
| Static Variable | Belongs to class |
| final | Prevents reassignment |
| Method | Reusable block of code |
| Method Overloading | Same name, different parameters |
| Widening | Generally automatic numeric conversion |
| Narrowing | Generally requires explicit cast |
| Type Promotion | Smaller numeric types promoted in expressions |
| Arithmetic Operators | +, -, *, /, % |
| Relational Operators | ==, !=, >, <, >=, <= |
| Logical Operators | &&, \|\|, ! |
| Assignment Operators | =, +=, -=, *= |
| Increment | ++ |
| Decrement | -- |
| Ternary | condition ? value1 : value2 |
| if | Executes code when condition is true |
| switch | Selects a branch |
| Switch Expression | Produces a value |
| yield | Returns value from switch block rule |
| for | Count-controlled loop |
| while | Entry-controlled loop |
| do-while | Exit-controlled loop |
| break | Exits nearest loop/switch |
| continue | Skips current iteration |
| Array | Fixed-length collection of same component type |
| Array Index | Starts from 0 |
| Array Length | `arr.length` |
| 2-D Array | Array of arrays |
| Jagged Array | Rows with different lengths |
| Factorial | Product from 1 to n |
| Armstrong | Sum of powered digits equals original number |
| Fibonacci | Sum of previous two terms |
| Principal Diagonal | `matrix[i][i]` |

---

# 13. Practice Checklist

## Theory

- [ ] Understand variable declaration and initialization.
- [ ] Learn local, instance and static variables.
- [ ] Understand final variables.
- [ ] Learn method declaration and invocation.
- [ ] Understand method parameters and return types.
- [ ] Practise method overloading.
- [ ] Understand widening and narrowing.
- [ ] Learn type promotion.
- [ ] Revise arithmetic and relational operators.
- [ ] Understand logical and bitwise operators.
- [ ] Practise pre-increment and post-increment.
- [ ] Learn if, if-else and else-if.
- [ ] Understand traditional switch and switch expression.
- [ ] Learn for, while and do-while loops.
- [ ] Understand break, continue and return.
- [ ] Learn one-dimensional and multidimensional arrays.
- [ ] Understand jagged arrays.

## Lab

- [ ] Set up JDK and IDE.
- [ ] Create a Java project.
- [ ] Write a program using variables and methods.
- [ ] Calculate a bill after discount.
- [ ] Create a menu-driven calculator using switch expression.
- [ ] Calculate factorial using a loop.
- [ ] Check an Armstrong number.
- [ ] Generate Fibonacci series.
- [ ] Print at least five star patterns.
- [ ] Calculate the principal diagonal sum of a matrix.
- [ ] Practise secondary diagonal sum as additional work.

## Self Learning

- [ ] Revise all operator precedence rules.
- [ ] Practise dry runs of loops.
- [ ] Solve at least 20 output-based questions.
- [ ] Practise array traversal and matrix operations.
- [ ] Write all seven lab programs without copying.
- [ ] Upload programs to GitHub.

---

# 14. Additional Practice Assignments

After completing the prescribed lab, practise these questions:

1. Check whether a number is prime.
2. Check whether a number is a palindrome.
3. Reverse a given number.
4. Find the sum of digits of a number.
5. Find GCD and LCM of two numbers.
6. Find the largest of three numbers.
7. Print a multiplication table.
8. Find the second-largest element in an array.
9. Search an element in an array.
10. Reverse an array.
11. Add two matrices.
12. Multiply two matrices.
13. Find the transpose of a matrix.
14. Calculate the sum of both diagonals of a square matrix.
15. Print number patterns using nested loops.

---

# 15. References

- Java 17 Documentation: https://docs.oracle.com/en/java/javase/17/
- Java Language Specification: https://docs.oracle.com/javase/specs/jls/se17/html/
- Java Tutorials: https://dev.java/learn/
- OpenJDK: https://openjdk.org/

---

# 🎯 Final CMCE Preparation Focus

For Sessions 2 & 3, give special attention to:

1. Variable types and method overloading.
2. Widening, narrowing and type promotion.
3. Operator precedence and increment/decrement.
4. Traditional switch vs Java 14+ switch expression.
5. for, while and do-while loops.
6. break, continue and return.
7. One-dimensional and multidimensional arrays.
8. Armstrong number and Fibonacci logic.
9. Nested-loop pattern programs.
10. Principal diagonal and matrix operations.

**End of Sessions 2 & 3 – Basic Programming Concepts**

⭐ Keep Learning, Keep Coding and Keep Practising!
