# 📘 Session 2 – Beginning with C++

<badge-placeholder />

**Course:** PGCP-AC | CMCE August 2026  
**Institute:** ACTS, Pune  
**Duration:** 2 Theory Hours + 4 Lab Hours  
**Standard:** C++17

---

## 🎯 Learning Objectives

- Understand C++ tokens and their types.
- Learn different initialization methods.
- Understand expressions and operators.
- Perform arithmetic and logical operations using C++.
- Set up and configure the C++ development environment.

---

# 1. C++ Tokens

**Definition:** Tokens are the smallest individual units of a C++ program recognized by the compiler.

C++ programs are made up of different types of tokens.

### Types of C++ Tokens

| No. | Token | Description | Example |
|---|---|---|---|
| 1 | Keywords | Reserved words with predefined meanings. | `int`, `if`, `class`, `return` |
| 2 | Identifiers | Names given to variables, functions, classes, etc. | `age`, `student`, `display()` |
| 3 | Constants / Literals | Fixed values used in a program. | `10`, `3.14`, `'A'` |
| 4 | Strings | Sequence of characters enclosed in double quotes. | `"Anurag"` |
| 5 | Operators | Symbols that perform operations. | `+`, `-`, `*`, `/` |
| 6 | Punctuators | Symbols used to structure programs. | `;`, `{}`, `()`, `,` |

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 22;
    cout << "Age: " << age;
    return 0;
}
```

**Understanding the tokens:**

- `int` → Keyword
- `age` → Identifier
- `22` → Integer literal
- `=` → Assignment operator
- `;` → Punctuator
- `"Age: "` → String literal

---

# 2. Initialization in C++

**Definition:** Initialization means assigning an initial value to a variable when it is declared.

C++ supports different ways of initializing variables.

### 2.1 Copy Initialization

```cpp
int a = 10;
float b = 10.5;
```

### 2.2 Direct Initialization

```cpp
int a(10);
float b(10.5);
```

### 2.3 Uniform / Brace Initialization (C++11)

```cpp
int a{10};
double b{10.5};
```

Brace initialization prevents certain narrowing conversions.

### 2.4 Default Initialization

```cpp
int a;          // Local variable: uninitialized
int b{};        // Initialized to 0
```

### 2.5 List Initialization

```cpp
int a = {10};
```

### Comparison

| Type | Syntax |
|---|---|
| Copy Initialization | `int a = 10;` |
| Direct Initialization | `int a(10);` |
| Brace Initialization | `int a{10};` |
| List Initialization | `int a = {10};` |

**Remember:** Prefer brace initialization when you want to prevent accidental narrowing conversions.

---

# 3. Expressions in C++

**Definition:** An expression is a combination of operands and operators that produces a value.

### Types of Expressions

| Expression | Example | Result |
|---|---|---|
| Arithmetic | `10 + 20` | `30` |
| Relational | `10 > 5` | `true` |
| Logical | `10 > 5 && 5 > 2` | `true` |
| Assignment | `a = 10` | Assigns 10 to a |
| Conditional | `a > b ? a : b` | Returns the greater value |

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    int sum = a + b;

    cout << "Sum = " << sum;

    return 0;
}
```

**Output:**
```text
Sum = 30
```

---

# 4. Operators in C++

**Definition:** Operators are special symbols that perform operations on variables and values.

According to the syllabus, the following operators are covered.

## 4.1 Arithmetic Operators

Used to perform mathematical operations.

| Operator | Name | Example | Result |
|---|---|---|---|
| `+` | Addition | `10 + 5` | 15 |
| `-` | Subtraction | `10 - 5` | 5 |
| `*` | Multiplication | `10 * 5` | 50 |
| `/` | Division | `10 / 5` | 2 |
| `%` | Modulus | `10 % 3` | 1 |

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;

    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Modulus: " << a % b << endl;

    return 0;
}
```

**Output:**
```text
Addition: 13
Subtraction: 7
Multiplication: 30
Division: 3
Modulus: 1
```

**Note:** Integer division removes the fractional part.

---

## 4.2 Relational Operators

Used to compare two values.

| Operator | Meaning | Example |
|---|---|---|
| `==` | Equal to | `a == b` |
| `!=` | Not equal to | `a != b` |
| `>` | Greater than | `a > b` |
| `<` | Less than | `a < b` |
| `>=` | Greater than or equal to | `a >= b` |
| `<=` | Less than or equal to | `a <= b` |

**Example:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    cout << (a > b) << endl;
    cout << (a < b) << endl;
    cout << (a == b) << endl;

    return 0;
}
```

**Output:**
```text
0
1
0
```

**Remember:**
- `1` means true.
- `0` means false.

---

## 4.3 Logical Operators

Used to combine or reverse conditions.

| Operator | Name | Meaning |
|---|---|---|
| `&&` | Logical AND | True if both conditions are true. |
| `||` | Logical OR | True if at least one condition is true. |
| `!` | Logical NOT | Reverses the condition. |

### Truth Table

| A | B | A && B | A \|\| B |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 |

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 22;

    cout << (age >= 18 && age <= 60);

    return 0;
}
```

**Output:**
```text
1
```

---

## 4.4 Unary Operators

**Definition:** Unary operators perform operations on a single operand.

| Operator | Name | Example |
|---|---|---|
| `++` | Increment | `a++` |
| `--` | Decrement | `a--` |
| `-` | Unary minus | `-a` |
| `!` | Logical NOT | `!a` |
| `&` | Address of | `&a` |
| `*` | Dereference | `*ptr` |

### Pre-Increment vs Post-Increment

**Pre-Increment (++a):** First increases the value, then uses it.

**Post-Increment (a++):** First uses the value, then increases it.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    cout << ++a << endl;

    int b = 10;

    cout << b++ << endl;
    cout << b << endl;

    return 0;
}
```

**Output:**
```text
11
10
11
```

---

## 4.5 Ternary Operator

**Definition:** The ternary operator is a conditional operator that evaluates a condition and returns one of two values.

**Syntax:**

```cpp
condition ? expression1 : expression2;
```

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    int max = (a > b) ? a : b;

    cout << "Maximum = " << max;

    return 0;
}
```

**Output:**
```text
Maximum = 20
```

**Simple Meaning:** A shorter alternative to a basic if-else statement.

---

## 4.6 Assignment Operators

Used to assign or update variable values.

| Operator | Example | Equivalent To |
|---|---|---|
| `=` | `a = 10` | Assign 10 to a |
| `+=` | `a += 5` | `a = a + 5` |
| `-=` | `a -= 5` | `a = a - 5` |
| `*=` | `a *= 5` | `a = a * 5` |
| `/=` | `a /= 5` | `a = a / 5` |
| `%=` | `a %= 5` | `a = a % 5` |

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    a += 5;
    cout << a << endl;

    a *= 2;
    cout << a << endl;

    return 0;
}
```

**Output:**
```text
15
30
```

---

# 5. Lab Work – Development Environment Setup

**As per ACTS syllabus:**

- Setup the Development Environment.

## 5.1 Required Software

| Software | Purpose |
|---|---|
| MinGW-w64 / GCC | C++ compiler |
| Visual Studio Code | Code editor |
| Visual Studio | C++ IDE (optional) |
| Terminal / CMD | Compile and execute programs |

## 5.2 Verify C++ Compiler

Open CMD or terminal and execute:

```bash
g++ --version
```

This checks whether the GCC C++ compiler is installed.

## 5.3 Write Your First C++ Program

Create a file named:

`hello.cpp`

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!";

    return 0;
}
```

## 5.4 Compile and Run

Compile:

```bash
g++ -std=c++17 hello.cpp -o hello
```

Run on Windows:

```bash
hello.exe
```

Run on Linux:

```bash
./hello
```

**Output:**
```text
Hello World!
```

---

# 📚 Session 2 – Quick Revision

| Topic | Key Point |
|---|---|
| Tokens | Smallest units of a program |
| Initialization | Assigning an initial value |
| Expressions | Combination of operands and operators |
| Arithmetic | Mathematical operations |
| Relational | Comparison of values |
| Logical | Combining conditions |
| Unary | Operation on one operand |
| Ternary | Conditional operator |
| Assignment | Assigning and updating values |

---

# 📝 Practice Questions

1. What are tokens in C++?
2. Explain the different types of C++ tokens.
3. What is initialization? Explain its types.
4. What is an expression?
5. Differentiate between `=` and `==`.
6. Explain arithmetic operators with examples.
7. Differentiate between relational and logical operators.
8. What is the difference between pre-increment and post-increment?
9. Explain the ternary operator with an example.
10. Explain compound assignment operators.

---

# 💻 Practice Programs

1. Print Hello World.
2. Add two numbers.
3. Add two binary numbers.
4. Add two characters.
5. Calculate compound interest.
6. Calculate the power of a number.
7. Swap two numbers.
8. Calculate the area of a rectangle.

---

## 📖 References

1. *Object-Oriented Programming in C++*, 2008 Edition – Rajesh K. Shukla, Wiley.
2. *The C++ Programming Language*, 4th Edition – Bjarne Stroustrup, O'Reilly.
3. *Thinking in C++*, 2nd Edition – Bruce Eckel, Pearson.
4. ACTS Pune – Suggested Teaching Guidelines, PGCP-AC, August 2026.

**C++ Standard:** C++17

---

⭐ **Learn | Practice | Implement | Revise**

*ACTS Pune – PGCP-AC | August 2026*
