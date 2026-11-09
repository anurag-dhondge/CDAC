# Sessions 7 & 8: Recursion in Java

**Course:** Algorithms and Data Structures Using Java  
**Program:** PGCP-AC – August 2026  
**Institute:** ACTS, Pune  
**Duration:** 4 Theory + 4 Lab Hours

---

## 1. Introduction to Recursion

Recursion is a programming technique in which a function calls itself to solve a problem.

A recursive function breaks a large problem into smaller subproblems until it reaches a condition where no further recursive call is required.

**Example:** Counting numbers from 1 to 5 using recursion.

```java
public class RecursionExample {

    static void printNumbers(int n) {

        if (n == 0) {
            return;
        }

        printNumbers(n - 1);

        System.out.println(n);
    }

    public static void main(String[] args) {
        printNumbers(5);
    }
}
```

**Output:**
```text
1
2
3
4
5
```

### How recursion works

For `printNumbers(5)`:

```text
printNumbers(5)
    printNumbers(4)
        printNumbers(3)
            printNumbers(2)
                printNumbers(1)
                    printNumbers(0)
```

When `n == 0`, the function returns. The pending function calls then complete in reverse order.

---

## 2. Base Condition in Recursion

A base condition is the condition that stops recursive function calls.

It prevents infinite recursion.

Every recursive function must have a suitable base condition.

**Example: Factorial using recursion**

Factorial of a number:

\[
n! = n \times (n-1) \times \cdots \times 1
\]

Mathematical definition:

\[
0! = 1
\]

\[
n! = n \times (n-1)!
\]

Java implementation:

```java
public class Factorial {

    static int factorial(int n) {

        // Base condition
        if (n == 0 || n == 1) {
            return 1;
        }

        // Recursive call
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {

        int result = factorial(5);

        System.out.println("Factorial: " + result);
    }
}
```

**Output:**
```text
Factorial: 120
```

### Function call sequence

```text
factorial(5)
    5 * factorial(4)
        4 * factorial(3)
            3 * factorial(2)
                2 * factorial(1)
                    return 1
```

Returning values:

```text
factorial(1) = 1
factorial(2) = 2 * 1 = 2
factorial(3) = 3 * 2 = 6
factorial(4) = 4 * 6 = 24
factorial(5) = 5 * 24 = 120
```

**Important:** Without a proper base condition, recursive calls may continue until the Java stack is exhausted, causing `StackOverflowError`.

---

## 3. Direct Recursion

Direct recursion occurs when a function calls itself directly.

**Example:**

```java
public class DirectRecursion {

    static void display(int n) {

        if (n == 0) {
            return;
        }

        System.out.println(n);

        display(n - 1);
    }

    public static void main(String[] args) {
        display(5);
    }
}
```

**Output:**
```text
5
4
3
2
1
```

Function call flow:

```text
display(5)
    ↓
display(4)
    ↓
display(3)
    ↓
display(2)
    ↓
display(1)
    ↓
display(0)
```

Here, the `display()` function directly calls itself.

---

## 4. Indirect Recursion

Indirect recursion occurs when one function calls another function, and that function eventually calls the first function again.

In other words, two or more functions call each other.

**Example:**

```java
public class IndirectRecursion {

    static void functionA(int n) {

        if (n <= 0) {
            return;
        }

        System.out.println("Function A: " + n);

        functionB(n - 1);
    }

    static void functionB(int n) {

        if (n <= 0) {
            return;
        }

        System.out.println("Function B: " + n);

        functionA(n - 1);
    }

    public static void main(String[] args) {
        functionA(5);
    }
}
```

**Output:**
```text
Function A: 5
Function B: 4
Function A: 3
Function B: 2
Function A: 1
```

Function call flow:

```text
functionA(5)
     |
     v
functionB(4)
     |
     v
functionA(3)
     |
     v
functionB(2)
     |
     v
functionA(1)
     |
     v
functionB(0)
```

### Direct vs Indirect Recursion

| Direct Recursion | Indirect Recursion |
|---|---|
| Function calls itself directly. | Functions call each other. |
| Usually involves one function. | Involves two or more functions. |
| Easier to understand. | Can be more complex to trace. |
| Example: `A()` calls `A()`. | Example: `A()` calls `B()`, and `B()` calls `A()`. |

---

## 5. Memory Allocation During Recursive Function Calls

Whenever a function is called, Java creates a new stack frame for that function call.

Each stack frame contains information such as:

- Local variables
- Parameters
- Return address and execution information
- Intermediate values needed to complete the call

Recursive calls create separate stack frames, even when the same function is called repeatedly.

### Example

```java
public class StackMemory {

    static void display(int n) {

        if (n == 0) {
            return;
        }

        System.out.println(n);

        display(n - 1);
    }

    public static void main(String[] args) {
        display(3);
    }
}
```

### Stack frame creation

When `display(3)` is called:

```text
        STACK
    +-------------+
    | display(0)  |
    +-------------+
    | display(1)  |
    +-------------+
    | display(2)  |
    +-------------+
    | display(3)  |
    +-------------+
```

Each function call has its own value of `n`.

### Stack frame removal

When the base condition is reached, function calls return one by one.

```text
display(0) returns
      ↓
display(1) returns
      ↓
display(2) returns
      ↓
display(3) returns
```

This process is called **stack unwinding**.

### Important points

1. Function calls are managed using the call stack.
2. Each recursive call creates a new stack frame.
3. The most recently called function returns first.
4. Recursive calls use additional stack memory.
5. Excessive recursion can cause `StackOverflowError`.

---

## 6. Advantages of Recursion

1. **Simple code:** Some problems can be solved with fewer lines of code.
2. **Easy problem decomposition:** Large problems can be divided into smaller subproblems.
3. **Natural for hierarchical structures:** Useful for trees and graphs.
4. **Useful in divide and conquer:** Algorithms such as Merge Sort and Quick Sort use recursion.
5. **Readable implementation:** Recursive solutions can closely match mathematical definitions.

## 7. Disadvantages of Recursion

1. **Extra memory:** Each recursive call requires a stack frame.
2. **Function call overhead:** Repeated function calls consume processing time.
3. **StackOverflowError:** Too many nested calls may exhaust the call stack.
4. **Difficult debugging:** Tracking multiple recursive calls can be challenging.
5. **Repeated calculations:** Some recursive algorithms perform duplicate work, such as the basic Fibonacci implementation.

### Recursion vs Iteration

| Recursion | Iteration |
|---|---|
| Function calls itself. | Uses loops such as `for` and `while`. |
| Uses the call stack for recursive calls. | Does not require recursive stack frames. |
| May use more memory. | Often uses less memory. |
| Can make some solutions simpler. | Often more efficient for simple repetitions. |
| Requires a base condition. | Requires a loop termination condition. |

---

## 8. Function Complexity During Recursion

Time complexity measures how the execution time of an algorithm grows with input size.

Space complexity measures how much additional memory an algorithm uses.

For recursive functions, complexity depends on:

- Number of recursive calls
- Work performed in each call
- Depth of recursion
- Whether calls are sequential or branching

### Example 1: Print numbers from 1 to N

```java
static void printNumbers(int n) {

    if (n == 0) {
        return;
    }

    System.out.println(n);

    printNumbers(n - 1);
}
```

For input `n = 5`, there are 6 calls, including the base call.

| Complexity | Value |
|---|---|
| Time Complexity | O(n) |
| Auxiliary Space | O(n) |
| Recursion Depth | O(n) |

### Example 2: Factorial

```java
static int factorial(int n) {

    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}
```

Recurrence relation:

\[
T(n) = T(n-1) + O(1)
\]

Therefore:

- Time Complexity: O(n)
- Auxiliary Space: O(n)

### Example 3: Binary Search

Binary Search repeatedly divides the search space into half.

```java
static int binarySearch(int[] arr, int low,
                        int high, int key) {

    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        return mid;
    }

    if (key < arr[mid]) {
        return binarySearch(arr, low, mid - 1, key);
    }

    return binarySearch(arr, mid + 1, high, key);
}
```

Recurrence relation:

\[
T(n) = T(n/2) + O(1)
\]

Therefore:

- Time Complexity: O(log n)
- Auxiliary Space: O(log n)

### Example 4: Fibonacci

Fibonacci sequence:

```text
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```

Mathematical definition:

\[
F(0)=0,\quad F(1)=1
\]

\[
F(n)=F(n-1)+F(n-2)
\]

Java implementation:

```java
public class Fibonacci {

    static int fibonacci(int n) {

        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {

        for (int i = 0; i < 10; i++) {
            System.out.print(fibonacci(i) + " ");
        }
    }
}
```

**Output:**
```text
0 1 1 2 3 5 8 13 21 34
```

Complexity:

- Time Complexity: O(2ⁿ) as a simple upper bound; more tightly, Θ(φⁿ), where φ is the golden ratio.
- Auxiliary Space: O(n), due to maximum recursion depth.

### Complexity comparison

| Problem | Time Complexity | Auxiliary Space |
|---|---|---|
| Print 1 to N | O(n) | O(n) |
| Factorial | O(n) | O(n) |
| Binary Search | O(log n) | O(log n) |
| Naive Fibonacci | O(2ⁿ) upper bound | O(n) |

**Note:** These complexities assume ordinary recursive implementations without compiler optimizations such as tail-call elimination. Java does not guarantee tail-call optimization.

---

## 9. Important Recursion Programs for Lab Practice

### Program 1: Print numbers from N to 1

```java
public class PrintDescending {

    static void print(int n) {

        if (n == 0) {
            return;
        }

        System.out.println(n);

        print(n - 1);
    }

    public static void main(String[] args) {
        print(5);
    }
}
```

### Program 2: Print numbers from 1 to N

```java
public class PrintAscending {

    static void print(int n) {

        if (n == 0) {
            return;
        }

        print(n - 1);

        System.out.println(n);
    }

    public static void main(String[] args) {
        print(5);
    }
}
```

### Program 3: Sum of first N natural numbers

```java
public class SumOfNumbers {

    static int sum(int n) {

        if (n == 0) {
            return 0;
        }

        return n + sum(n - 1);
    }

    public static void main(String[] args) {
        System.out.println(sum(5));
    }
}
```

**Output:**
```text
15
```

### Program 4: Reverse a string using recursion

```java
public class ReverseString {

    static String reverse(String str) {

        if (str.isEmpty()) {
            return str;
        }

        return reverse(str.substring(1))
                + str.charAt(0);
    }

    public static void main(String[] args) {
        System.out.println(reverse("JAVA"));
    }
}
```

**Output:**
```text
AVAJ
```

### Program 5: Check whether a string is palindrome

```java
public class Palindrome {

    static boolean isPalindrome(String str,
                                int start, int end) {

        if (start >= end) {
            return true;
        }

        if (str.charAt(start) != str.charAt(end)) {
            return false;
        }

        return isPalindrome(str, start + 1, end - 1);
    }

    public static void main(String[] args) {

        String str = "MADAM";

        System.out.println(
            isPalindrome(str, 0, str.length() - 1)
        );
    }
}
```

**Output:**
```text
true
```

### Program 6: Find power of a number

```java
public class Power {

    static int power(int base, int exponent) {

        if (exponent == 0) {
            return 1;
        }

        return base * power(base, exponent - 1);
    }

    public static void main(String[] args) {
        System.out.println(power(2, 5));
    }
}
```

**Output:**
```text
32
```

**Complexity:** O(n) time and O(n) auxiliary space for exponent `n`.

---

## 10. Important Interview Questions and Answers

**Q1. What is recursion?**

Recursion is a technique in which a function calls itself to solve a problem.

**Q2. What is a base condition?**

A base condition is the stopping condition that prevents further recursive calls.

**Q3. What happens if a recursive function has no base condition?**

It may continue calling itself until the call stack is exhausted, causing `StackOverflowError`.

**Q4. What is direct recursion?**

When a function calls itself directly, it is called direct recursion.

**Q5. What is indirect recursion?**

When two or more functions call each other, it is called indirect recursion.

**Q6. What is stack unwinding?**

Stack unwinding is the process of returning from recursive function calls in reverse order.

**Q7. Where are recursive function calls stored?**

They are managed using the call stack.

**Q8. What is the difference between recursion and iteration?**

Recursion uses function calls, whereas iteration uses loops.

**Q9. What is the time complexity of factorial using recursion?**

O(n).

**Q10. What is the space complexity of factorial using recursion?**

O(n), because there are O(n) active recursive calls in the deepest part of execution.

**Q11. Can recursion be replaced by iteration?**

Many recursive problems can be implemented using loops, sometimes with an explicit stack.

**Q12. What is stack overflow?**

Stack overflow occurs when the call stack cannot accommodate additional function calls.

---

## 11. Multiple Choice Questions (MCQs)

**Q1. What is recursion?**

- A. A loop
- B. A function calling itself
- C. A variable declaration
- D. An array operation

**Answer:** B

**Q2. What is the purpose of a base condition?**

- A. To increase memory
- B. To stop recursive calls
- C. To create an object
- D. To execute a loop

**Answer:** B

**Q3. Which memory structure manages recursive calls?**

- A. Queue
- B. Heap
- C. Stack
- D. Array

**Answer:** C

**Q4. A function calling itself directly is called:**

- A. Indirect recursion
- B. Direct recursion
- C. Iteration
- D. Looping

**Answer:** B

**Q5. What happens when recursive calls return?**

- A. Stack unwinding
- B. Stack sorting
- C. Queue insertion
- D. Memory expansion

**Answer:** A

**Q6. What is the time complexity of recursive factorial?**

- A. O(1)
- B. O(log n)
- C. O(n)
- D. O(n²)

**Answer:** C

**Q7. What error can occur due to excessive recursion in Java?**

- A. NullPointerException
- B. StackOverflowError
- C. IOException
- D. ArithmeticException

**Answer:** B

**Q8. Which algorithm commonly uses recursion?**

- A. Binary Search
- B. Merge Sort
- C. Quick Sort
- D. All of the above

**Answer:** D

**Q9. What is the auxiliary space complexity of recursive factorial?**

- A. O(1)
- B. O(n)
- C. O(n²)
- D. O(log n)

**Answer:** B

**Q10. Indirect recursion involves:**

- A. Only one function calling itself
- B. Two or more functions calling each other
- C. Only loops
- D. Only arrays

**Answer:** B

---

## 12. Quick Revision Notes

| Concept | Meaning |
|---|---|
| Recursion | Function calling itself |
| Base Condition | Condition to stop recursion |
| Direct Recursion | Function calls itself directly |
| Indirect Recursion | Functions call each other |
| Call Stack | Manages function calls |
| Stack Frame | Information associated with a function call |
| Stack Unwinding | Returning from recursive calls |
| StackOverflowError | Error due to exhausted call stack |
| Time Complexity | Growth in execution time |
| Space Complexity | Growth in additional memory usage |

### Important formulas

**Factorial:**

\[
n! = n \times (n-1)!
\]

**Sum of natural numbers:**

\[
S(n) = n + S(n-1)
\]

**Fibonacci:**

\[
F(n) = F(n-1) + F(n-2)
\]

**Binary Search:**

\[
T(n) = T(n/2) + O(1)
\]

---

## 13. Suggested GitHub Folder Structure

```text
Algorithms-and-Data-Structures/
│
├── Sessions-01-03/
│   └── README.md
│
├── Sessions-04-06/
│   └── README.md
│
└── Sessions-07-08-Recursion/
    │
    ├── README.md
    │
    ├── Basics/
    │   ├── PrintAscending.java
    │   ├── PrintDescending.java
    │   └── DirectRecursion.java
    │
    ├── Mathematical/
    │   ├── Factorial.java
    │   ├── SumOfNumbers.java
    │   ├── Fibonacci.java
    │   └── Power.java
    │
    └── StringProblems/
        ├── ReverseString.java
        └── Palindrome.java
```

---

## 14. Learning Outcomes

After completing Sessions 7 & 8, students should be able to:

- Understand the concept of recursion.
- Identify and implement base conditions.
- Differentiate between direct and indirect recursion.
- Understand memory allocation during recursive calls.
- Explain stack frames and stack unwinding.
- Identify the advantages and disadvantages of recursion.
- Calculate time and auxiliary space complexity of recursive functions.
- Implement mathematical and string-based recursive programs.

---

**End of Sessions 7 & 8 – Recursion**

*Course: Algorithms and Data Structures Using Java | PGCP-AC August 2026 | ACTS Pune*
