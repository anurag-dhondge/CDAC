# 📘 Sessions 1, 2 & 3: Algorithms and Data Structures Using Java

**Course:** CDAC – CMCE / PGCP-AC  
**Batch:** August 2026  
**Institute:** ACTS, Pune  
**Subject:** Algorithms and Data Structures Using Java  
**Sessions:** 1, 2 & 3  
**Duration:** 12 Hours (6 Theory + 6 Lab)  
**Programming Language:** Java

---

# 📑 Table of Contents

1. [Introduction to Problem Solving](#1-introduction-to-problem-solving)
2. [Computational Thinking](#2-computational-thinking)
3. [Introduction to Algorithms](#3-introduction-to-algorithms)
4. [Algorithm Constructs](#4-algorithm-constructs)
5. [Algorithm Complexity Analysis](#5-algorithm-complexity-analysis)
6. [Big O Notation](#6-big-o-notation)
7. [Complexity Analysis of Loops](#7-complexity-analysis-of-loops)
8. [Complexity Analysis of Recursion](#8-complexity-analysis-of-recursion)
9. [Abstract Data Types](#9-abstract-data-types)
10. [Introduction to Data Structures](#10-introduction-to-data-structures)
11. [Arrays in Java](#11-arrays-in-java)
12. [Stack Data Structure](#12-stack-data-structure)
13. [Stack Implementation Using Array](#13-stack-implementation-using-array)
14. [Queue Data Structure](#14-queue-data-structure)
15. [Queue Implementation Using Array](#15-queue-implementation-using-array)
16. [Circular Queue](#16-circular-queue)
17. [Circular Queue Implementation](#17-circular-queue-implementation)
18. [Stack vs Queue vs Circular Queue](#18-stack-vs-queue-vs-circular-queue)
19. [Lab Assignments](#19-lab-assignments)
20. [Interview Questions and Answers](#20-interview-questions-and-answers)
21. [MCQs](#21-mcqs)
22. [Quick Revision Notes](#22-quick-revision-notes)

---

# 1. Introduction to Problem Solving

## 1.1 What is Problem Solving?

Problem solving is the process of identifying a problem, understanding its requirements, and developing a logical sequence of steps to obtain the desired result.

In computer programming, problem solving involves converting a real-world problem into an algorithm that can be implemented using a programming language.

### Steps in Problem Solving

1. **Understand the Problem:** Identify what needs to be solved.
2. **Identify Inputs:** Determine the required input data.
3. **Identify Outputs:** Determine the expected result.
4. **Develop Logic:** Design a step-by-step solution.
5. **Write an Algorithm:** Represent the solution using pseudocode or a flowchart.
6. **Implement the Solution:** Convert the algorithm into Java code.
7. **Test and Debug:** Verify the output and correct errors.
8. **Optimize:** Improve time and space efficiency.

### Example: Find the Largest of Three Numbers

**Problem:** Given three numbers, find the largest.

**Input:**

```text
a = 10
b = 25
c = 15
```

**Output:**

```text
Largest = 25
```

**Algorithm:**

```text
START

READ a, b, c

IF a >= b AND a >= c
    PRINT a

ELSE IF b >= a AND b >= c
    PRINT b

ELSE
    PRINT c

STOP
```

### Java Implementation

```java
public class LargestNumber {

    public static void main(String[] args) {

        int a = 10;
        int b = 25;
        int c = 15;

        if (a >= b && a >= c) {
            System.out.println("Largest: " + a);
        } else if (b >= a && b >= c) {
            System.out.println("Largest: " + b);
        } else {
            System.out.println("Largest: " + c);
        }
    }
}
```

**Output:**

```text
Largest: 25
```

**Time Complexity:** O(1)  
**Space Complexity:** O(1)

The number of comparisons remains constant regardless of the values of the three inputs.

---

# 2. Computational Thinking

## 2.1 What is Computational Thinking?

Computational thinking is a systematic approach to solving problems using concepts from computer science.

It helps programmers develop logical, efficient, and reusable solutions.

## 2.2 Four Pillars of Computational Thinking

### 1. Decomposition

Breaking a complex problem into smaller, manageable problems.

**Example:**

An online shopping application can be divided into:

- User Registration
- Product Management
- Shopping Cart
- Payment Processing
- Order Management

Each module can be developed and tested independently.

### 2. Pattern Recognition

Identifying similarities or repeated patterns in problems.

**Example:**

Searching for a student by roll number and searching for an employee by ID both involve finding a matching record.

A similar searching algorithm can solve both problems.

### 3. Abstraction

Focusing on essential details while ignoring unnecessary information.

**Example:**

A Stack ADT defines operations such as `push()`, `pop()`, and `peek()`.

The user does not need to know whether the stack is implemented using an array or a linked list.

### 4. Algorithm Design

Creating a step-by-step procedure to solve a problem.

**Example:**

To search for an element in an array:

1. Start from the first element.
2. Compare it with the target.
3. If equal, return its index.
4. Otherwise, move to the next element.
5. If no match is found, return -1.

This is called Linear Search.

---

# 3. Introduction to Algorithms

## 3.1 What is an Algorithm?

An algorithm is a finite sequence of well-defined instructions used to solve a particular problem.

### Characteristics of an Algorithm

| Characteristic | Description |
|---|---|
| Input | Accepts zero or more inputs |
| Output | Produces at least one result |
| Definiteness | Every instruction must be clear |
| Finiteness | Must terminate after finite steps |
| Effectiveness | Steps must be executable |
| Correctness | Produces the expected result for valid inputs |

## 3.2 Algorithm vs Program

| Algorithm | Program |
|---|---|
| Logical solution to a problem | Implementation of an algorithm |
| Language-independent | Written in a programming language |
| Expressed using pseudocode or flowcharts | Expressed using source code |
| Focuses on logic | Focuses on execution |

## 3.3 Example: Sum of Array Elements

**Algorithm:**

```text
START

sum = 0

FOR i = 0 TO n - 1
    sum = sum + arr[i]

PRINT sum

STOP
```

**Java Program:**

```java
public class ArraySum {

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

**Output:**

```text
Sum = 150
```

**Time Complexity:** O(n)  
**Auxiliary Space Complexity:** O(1)

---

# 4. Algorithm Constructs

Algorithm constructs are fundamental control structures used to develop algorithms.

There are three primary constructs.

## 4.1 Sequence

Instructions are executed one after another.

```java
int a = 10;
int b = 20;

int sum = a + b;

System.out.println(sum);
```

Output:

```text
30
```

## 4.2 Selection

Selection allows an algorithm to choose different execution paths based on conditions.

Common selection statements:

- if
- if-else
- else-if ladder
- switch

### Example

```java
int marks = 75;

if (marks >= 40) {
    System.out.println("Pass");
} else {
    System.out.println("Fail");
}
```

## 4.3 Iteration

Iteration means executing a set of instructions repeatedly.

Common loops:

- for
- while
- do-while

### Example

```java
for (int i = 1; i <= 5; i++) {
    System.out.println(i);
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

---

# 5. Algorithm Complexity Analysis

## 5.1 What is Algorithm Analysis?

Algorithm analysis is the process of evaluating the resources required by an algorithm as the input size increases.

The two major resources are:

1. Time
2. Memory

## 5.2 Time Complexity

Time complexity describes how the number of basic operations grows with input size.

It does not directly represent execution time in seconds.

### Example

```java
for (int i = 0; i < n; i++) {
    System.out.println(i);
}
```

The loop executes `n` times.

Therefore:

**Time Complexity = O(n)**

## 5.3 Space Complexity

Space complexity describes the memory requirements of an algorithm.

### Example

```java
int a = 10;
int b = 20;
int sum = a + b;
```

Only a constant number of variables are used.

**Auxiliary Space Complexity = O(1)**

### Example: Additional Array

```java
int[] arr = new int[n];
```

The allocated array grows with `n`.

**Space Complexity = O(n)**

## 5.4 Best, Average and Worst Cases

Consider Linear Search.

```java
int[] arr = {10, 20, 30, 40, 50};
```

| Case | Example | Complexity |
|---|---|---|
| Best | Search 10 | O(1) |
| Average | Search a uniformly random existing element | O(n) |
| Worst | Search 50 or missing element | O(n) |

**Important:** Big O describes an asymptotic upper bound. Best-case and worst-case behavior describe different input scenarios. They are not the same concept.

---

# 6. Big O Notation

## 6.1 What is Big O?

Big O notation describes an asymptotic upper bound on the growth rate of an algorithm's resource usage.

It is commonly used to compare algorithms based on their scalability.

## 6.2 Common Complexities

| Notation | Name | Example |
|---|---|---|
| O(1) | Constant | Array element access |
| O(log n) | Logarithmic | Binary Search |
| O(n) | Linear | Linear Search |
| O(n log n) | Linearithmic | Merge Sort |
| O(n²) | Quadratic | Nested loops |
| O(n³) | Cubic | Three nested loops |
| O(2ⁿ) | Exponential | Naive recursive Fibonacci |
| O(n!) | Factorial | Generating all permutations |

## 6.3 Rules for Calculating Big O

### Rule 1: Ignore Constants

```text
O(2n) = O(n)
O(5n) = O(n)
```

### Rule 2: Ignore Lower-Order Terms

```text
O(n² + n + 10) = O(n²)
```

### Rule 3: Sequential Operations Add

```java
for (int i = 0; i < n; i++) {
    System.out.println(i);
}

for (int j = 0; j < n; j++) {
    System.out.println(j);
}
```

Total operations:

```text
n + n = 2n
```

**Complexity = O(n)**

### Rule 4: Nested Loops Multiply

```java
for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

        System.out.println(i + " " + j);
    }
}
```

Total iterations:

```text
n × n = n²
```

**Complexity = O(n²)**

### Rule 5: Keep the Dominant Term

```text
T(n) = 3n² + 5n + 100

O(T(n)) = O(n²)
```

## 6.4 Asymptotic Notations

| Notation | Meaning |
|---|---|
| Big O – O | Asymptotic upper bound |
| Omega – Ω | Asymptotic lower bound |
| Theta – Θ | Asymptotically tight bound |

For example, if an algorithm always performs `3n + 2` operations, its running time is Θ(n), and therefore also O(n) and Ω(n).

---

# 7. Complexity Analysis of Loops

## Example 1: Constant Time

```java
System.out.println("Hello");
```

**Time Complexity:** O(1)

## Example 2: Single Loop

```java
for (int i = 0; i < n; i++) {
    System.out.println(i);
}
```

**Time Complexity:** O(n)

## Example 3: Nested Loop

```java
for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {
        System.out.println(i + j);
    }
}
```

**Time Complexity:** O(n²)

## Example 4: Logarithmic Loop

```java
for (int i = 1; i < n; i *= 2) {
    System.out.println(i);
}
```

For `n = 16`, the loop uses:

```text
1 → 2 → 4 → 8
```

The value doubles in each iteration.

**Time Complexity:** O(log n)

## Example 5: Triangular Nested Loop

```java
for (int i = 0; i < n; i++) {

    for (int j = 0; j <= i; j++) {

        System.out.println(j);
    }
}
```

Total iterations:

```text
1 + 2 + 3 + ... + n

= n(n + 1) / 2
```

**Time Complexity:** O(n²)

## Example 6: Linearithmic Complexity

```java
for (int i = 1; i < n; i *= 2) {

    for (int j = 0; j < n; j++) {

        System.out.println(i + j);
    }
}
```

Outer loop:

```text
O(log n)
```

Inner loop:

```text
O(n)
```

Total:

```text
O(n log n)
```

---

# 8. Complexity Analysis of Recursion

## 8.1 What is Recursion?

Recursion is a programming technique in which a method calls itself directly or indirectly to solve a smaller instance of a problem.

Every recursive algorithm must have a suitable terminating condition.

## 8.2 Components of Recursion

1. Base Case
2. Recursive Case
3. Progress toward the Base Case

## 8.3 Factorial Using Recursion

```java
public class Factorial {

    static long factorial(int n) {

        if (n <= 1) {
            return 1;
        }

        return n * factorial(n - 1);
    }

    public static void main(String[] args) {

        System.out.println(factorial(5));
    }
}
```

**Output:**

```text
120
```

### Dry Run

```text
factorial(5)
= 5 × factorial(4)
= 5 × 4 × factorial(3)
= 5 × 4 × 3 × factorial(2)
= 5 × 4 × 3 × 2 × factorial(1)
= 5 × 4 × 3 × 2 × 1
= 120
```

### Complexity

```text
T(n) = T(n - 1) + O(1)
```

**Time Complexity:** O(n)  
**Auxiliary Space Complexity:** O(n)

The recursive calls occupy stack frames until the base case is reached.

**Note:** The example assumes non-negative input and a result that fits in `long`.

## 8.4 Fibonacci Using Recursion

```java
public class Fibonacci {

    static int fib(int n) {

        if (n <= 1) {
            return n;
        }

        return fib(n - 1) + fib(n - 2);
    }

    public static void main(String[] args) {

        System.out.println(fib(6));
    }
}
```

**Output:**

```text
8
```

### Complexity

```text
T(n) = T(n - 1) + T(n - 2) + O(1)
```

**Time Complexity:** O(2ⁿ) as a loose upper bound  
**Auxiliary Space Complexity:** O(n)

The recursive implementation repeatedly calculates the same Fibonacci values.

## 8.5 Iteration vs Recursion

| Iteration | Recursion |
|---|---|
| Uses loops | Uses method calls |
| Usually has lower call overhead | Has method-call overhead |
| Often uses less auxiliary memory | Uses call-stack memory |
| Terminates using loop condition | Terminates using base condition |
| Suitable for repetitive operations | Suitable for recursively structured problems |

---

# 9. Abstract Data Types

## 9.1 What is an ADT?

ADT stands for **Abstract Data Type**.

An ADT is a logical model that defines the data and supported operations without specifying their internal implementation.

### Example: Stack ADT

A Stack ADT supports operations such as:

```text
push(element)
pop()
peek()
isEmpty()
size()
```

The ADT defines what operations are available.

The implementation defines how those operations work.

## 9.2 ADT vs Data Structure

| ADT | Data Structure |
|---|---|
| Logical specification | Concrete implementation |
| Defines operations and behavior | Defines storage and algorithms |
| Implementation-independent | Implementation-dependent |
| Example: Stack ADT | Array-based Stack |

## 9.3 Stack ADT Using Java Interface

```java
interface StackADT {

    void push(int value);

    int pop();

    int peek();

    boolean isEmpty();
}
```

A class implementing this interface must provide the specified methods.

The interface represents the available operations, while the class provides the actual implementation.

## 9.4 Advantages of ADTs

- Abstraction
- Encapsulation
- Reusability
- Modularity
- Maintainability
- Implementation independence

---

# 10. Introduction to Data Structures

## 10.1 What is a Data Structure?

A data structure is a way of organizing and storing data so that operations can be performed efficiently.

Common operations include:

- Insertion
- Deletion
- Searching
- Traversal
- Updating
- Sorting

## 10.2 Classification of Data Structures

```text
Data Structures
│
├── Primitive
│   ├── int
│   ├── char
│   ├── boolean
│   └── double
│
└── Non-Primitive
    │
    ├── Linear
    │   ├── Array
    │   ├── Linked List
    │   ├── Stack
    │   └── Queue
    │
    └── Non-Linear
        ├── Tree
        └── Graph
```

Primitive types are the basic building blocks used to represent data. Arrays and other data structures organize values into more complex arrangements.

## 10.3 Linear vs Non-Linear Data Structures

| Linear | Non-Linear |
|---|---|
| Elements arranged in a sequence | Elements may have hierarchical or network relationships |
| Often traversed sequentially | May require different traversal strategies |
| Array, Stack, Queue | Tree, Graph |

## 10.4 Static vs Dynamic Data Structures

**Static Data Structure:** Has a fixed capacity after allocation.

Example: Java array.

**Dynamic Data Structure:** Can grow or shrink through its implementation.

Example: Linked List.

---

# 11. Arrays in Java

## 11.1 What is an Array?

An array is a fixed-length, indexed data structure that stores elements of the same declared type.

Java array indexing starts from `0`.

### Example

```java
int[] arr = {10, 20, 30, 40, 50};
```

### Array Representation

```text
Index:   0    1    2    3    4
       +----+----+----+----+----+
Value: | 10 | 20 | 30 | 40 | 50 |
       +----+----+----+----+----+
```

## 11.2 Array Declaration

```java
int[] arr;
```

## 11.3 Array Creation

```java
arr = new int[5];
```

## 11.4 Array Initialization

```java
int[] arr = {10, 20, 30, 40, 50};
```

## 11.5 Array Traversal

```java
public class ArrayTraversal {

    public static void main(String[] args) {

        int[] arr = {10, 20, 30, 40, 50};

        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
```

## 11.6 Array Insertion

Java arrays have fixed lengths. To insert an element into an occupied position, we must maintain a logical size and shift elements when necessary.

```java
public class ArrayInsertion {

    public static void main(String[] args) {

        int[] arr = new int[6];

        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;

        int size = 5;
        int position = 2;
        int value = 25;

        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }

        arr[position] = value;
        size++;

        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
```

**Output:**

```text
10 20 25 30 40 50
```

**Time Complexity:** O(n) in the worst case.

## 11.7 Array Deletion

```java
public class ArrayDeletion {

    public static void main(String[] args) {

        int[] arr = {10, 20, 30, 40, 50};

        int size = arr.length;
        int position = 2;

        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;

        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
```

**Output:**

```text
10 20 40 50
```

## 11.8 Array Operations and Complexity

| Operation | Time Complexity |
|---|---|
| Access by index | O(1) |
| Update by index | O(1) |
| Traversal | O(n) |
| Linear Search | O(n) |
| Insertion at beginning | O(n) |
| Insertion at end with free capacity | O(1) |
| Deletion at beginning | O(n) |
| Deletion at end | O(1) |

---

# 12. Stack Data Structure

## 12.1 What is a Stack?

A Stack is a linear data structure that follows the **LIFO (Last In, First Out)** principle.

The last inserted element is the first element removed.

### Real-World Examples

- Stack of plates
- Undo operation in text editors
- Browser back navigation
- Function call stack
- Expression evaluation

## 12.2 Stack Representation

```text
          TOP
           |
           v
       +-------+
       |  30   |  ← Last inserted
       +-------+
       |  20   |
       +-------+
       |  10   |
       +-------+
```

## 12.3 Stack Operations

| Operation | Description |
|---|---|
| push() | Insert element at top |
| pop() | Remove top element |
| peek() | Read top element |
| isEmpty() | Check if stack is empty |
| isFull() | Check if array-based stack is full |
| display() | Display stack elements |

## 12.4 Stack Overflow

Stack overflow occurs when an attempt is made to push an element into a full, fixed-capacity stack.

## 12.5 Stack Underflow

Stack underflow occurs when an attempt is made to pop an element from an empty stack.

## 12.6 Stack Push Algorithm

```text
PUSH(value)

IF top == capacity - 1
    PRINT "Stack Overflow"
ELSE
    top = top + 1
    stack[top] = value
```

## 12.7 Stack Pop Algorithm

```text
POP()

IF top == -1
    PRINT "Stack Underflow"
ELSE
    value = stack[top]
    top = top - 1
    RETURN value
```

---

# 13. Stack Implementation Using Array

## Complete Java Program

**File:** `ArrayStack.java`

```java
public class ArrayStack {

    private int[] stack;
    private int top;

    public ArrayStack(int capacity) {

        if (capacity <= 0) {
            throw new IllegalArgumentException(
                "Capacity must be positive"
            );
        }

        stack = new int[capacity];
        top = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == stack.length - 1;
    }

    public void push(int value) {

        if (isFull()) {
            System.out.println("Stack Overflow");
            return;
        }

        stack[++top] = value;

        System.out.println(value + " pushed");
    }

    public int pop() {

        if (isEmpty()) {
            throw new IllegalStateException(
                "Stack Underflow"
            );
        }

        return stack[top--];
    }

    public int peek() {

        if (isEmpty()) {
            throw new IllegalStateException(
                "Stack is Empty"
            );
        }

        return stack[top];
    }

    public void display() {

        if (isEmpty()) {
            System.out.println("Stack is Empty");
            return;
        }

        for (int i = top; i >= 0; i--) {
            System.out.println(stack[i]);
        }
    }

    public static void main(String[] args) {

        ArrayStack s = new ArrayStack(5);

        s.push(10);
        s.push(20);
        s.push(30);

        System.out.println("Top: " + s.peek());

        System.out.println("Popped: " + s.pop());

        s.display();
    }
}
```

### Output

```text
10 pushed
20 pushed
30 pushed
Top: 30
Popped: 30
20
10
```

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| push() | O(1) |
| pop() | O(1) |
| peek() | O(1) |
| isEmpty() | O(1) |
| isFull() | O(1) |
| display() | O(n) |

**Space Complexity:** O(n) for a stack of capacity `n`.

---

# 14. Queue Data Structure

## 14.1 What is a Queue?

A Queue is a linear data structure that follows the **FIFO (First In, First Out)** principle.

The first inserted element is the first removed.

### Real-World Examples

- Ticket booking queue
- Printer queue
- CPU scheduling
- Customer service queue
- Breadth First Search

## 14.2 Queue Representation

```text
FRONT                         REAR
  |                            |
  v                            v
+------+------+------+------+
|  10  |  20  |  30  |  40  |
+------+------+------+------+

Deletion → FRONT
Insertion → REAR
```

## 14.3 Queue Operations

| Operation | Description |
|---|---|
| enqueue() | Insert at rear |
| dequeue() | Remove from front |
| peek() | Read front element |
| isEmpty() | Check if queue is empty |
| isFull() | Check if queue is full |
| display() | Display queue |

## 14.4 Queue Overflow

Overflow occurs when an insertion is attempted but the queue has no available capacity.

## 14.5 Queue Underflow

Underflow occurs when a removal is attempted from an empty queue.

## 14.6 Queue Enqueue Algorithm

```text
ENQUEUE(value)

IF rear == capacity - 1
    PRINT "Queue Overflow"

ELSE
    IF front == -1
        front = 0

    rear = rear + 1
    queue[rear] = value
```

## 14.7 Queue Dequeue Algorithm

```text
DEQUEUE()

IF front == -1
    PRINT "Queue Underflow"

ELSE
    value = queue[front]

    IF front == rear
        front = -1
        rear = -1
    ELSE
        front = front + 1

    RETURN value
```

---

# 15. Queue Implementation Using Array

**File:** `ArrayQueue.java`

```java
public class ArrayQueue {

    private int[] queue;
    private int front;
    private int rear;

    public ArrayQueue(int capacity) {

        if (capacity <= 0) {
            throw new IllegalArgumentException(
                "Capacity must be positive"
            );
        }

        queue = new int[capacity];

        front = -1;
        rear = -1;
    }

    public boolean isEmpty() {
        return front == -1;
    }

    public boolean isFull() {
        return rear == queue.length - 1;
    }

    public void enqueue(int value) {

        if (isFull()) {
            System.out.println("Queue Overflow");
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        queue[++rear] = value;

        System.out.println(value + " inserted");
    }

    public int dequeue() {

        if (isEmpty()) {
            throw new IllegalStateException(
                "Queue Underflow"
            );
        }

        int value = queue[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }

        return value;
    }

    public int peek() {

        if (isEmpty()) {
            throw new IllegalStateException(
                "Queue is Empty"
            );
        }

        return queue[front];
    }

    public void display() {

        if (isEmpty()) {
            System.out.println("Queue is Empty");
            return;
        }

        for (int i = front; i <= rear; i++) {
            System.out.print(queue[i] + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {

        ArrayQueue q = new ArrayQueue(5);

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        q.display();

        System.out.println(
            "Deleted: " + q.dequeue()
        );

        q.display();
    }
}
```

### Output

```text
10 inserted
20 inserted
30 inserted
10 20 30
Deleted: 10
20 30
```

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| enqueue() | O(1) |
| dequeue() | O(1) |
| peek() | O(1) |
| display() | O(n) |

**Limitation:** A simple linear array queue cannot reuse freed positions at the beginning until the queue becomes empty and its indices are reset.

This limitation can be solved using a Circular Queue.

---

# 16. Circular Queue

## 16.1 What is a Circular Queue?

A Circular Queue is a queue in which the last array position is logically connected to the first position.

It follows the FIFO principle while allowing empty positions to be reused.

## 16.2 Why Do We Need Circular Queue?

Consider an array of size 5.

Initially:

```text
Index:   0    1    2    3    4
       +----+----+----+----+----+
Value: | 10 | 20 | 30 | 40 | 50 |
       +----+----+----+----+----+

Front = 0
Rear  = 4
```

After removing two elements:

```text
Index:   0    1    2    3    4
       +----+----+----+----+----+
Value: | -- | -- | 30 | 40 | 50 |
       +----+----+----+----+----+

Front = 2
Rear  = 4
```

In a simple linear queue, insertion is not possible at the end because `rear` has reached the final index.

However, positions 0 and 1 are free.

A circular queue can reuse them.

## 16.3 Modulo Operator

Circular queues use the modulo operator `%`.

### Formula for Moving Rear

```text
rear = (rear + 1) % capacity
```

### Formula for Moving Front

```text
front = (front + 1) % capacity
```

### Example

```text
capacity = 5
rear = 4

rear = (4 + 1) % 5
rear = 0
```

The rear index wraps around to the beginning.

## 16.4 Circular Queue Conditions

### Empty Condition

For the implementation using `front = -1` as an empty marker:

```text
front == -1
```

### Full Condition

```text
(rear + 1) % capacity == front
```

This condition applies when `front` and `rear` are initialized and maintained as shown in the next implementation.

## 16.5 Circular Queue Operations

**Enqueue:**

1. Check whether the queue is full.
2. If empty, initialize `front` and `rear` to 0.
3. Otherwise, move `rear` using modulo.
4. Insert the element.

**Dequeue:**

1. Check whether the queue is empty.
2. Retrieve the front element.
3. If only one element remains, reset both indices.
4. Otherwise, move `front` using modulo.

---

# 17. Circular Queue Implementation

**File:** `CircularQueue.java`

```java
public class CircularQueue {

    private int[] queue;
    private int front;
    private int rear;

    public CircularQueue(int capacity) {

        if (capacity <= 0) {
            throw new IllegalArgumentException(
                "Capacity must be positive"
            );
        }

        queue = new int[capacity];

        front = -1;
        rear = -1;
    }

    public boolean isEmpty() {
        return front == -1;
    }

    public boolean isFull() {

        return !isEmpty()
            && (rear + 1) % queue.length == front;
    }

    public void enqueue(int value) {

        if (isFull()) {
            System.out.println("Queue Overflow");
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % queue.length;
        }

        queue[rear] = value;

        System.out.println(value + " inserted");
    }

    public int dequeue() {

        if (isEmpty()) {
            throw new IllegalStateException(
                "Queue Underflow"
            );
        }

        int value = queue[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % queue.length;
        }

        return value;
    }

    public int peek() {

        if (isEmpty()) {
            throw new IllegalStateException(
                "Queue is Empty"
            );
        }

        return queue[front];
    }

    public void display() {

        if (isEmpty()) {
            System.out.println("Queue is Empty");
            return;
        }

        int i = front;

        while (true) {

            System.out.print(queue[i] + " ");

            if (i == rear) {
                break;
            }

            i = (i + 1) % queue.length;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        CircularQueue q = new CircularQueue(5);

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);

        System.out.println(
            "Removed: " + q.dequeue()
        );

        System.out.println(
            "Removed: " + q.dequeue()
        );

        q.enqueue(60);
        q.enqueue(70);

        q.display();
    }
}
```

### Output

```text
10 inserted
20 inserted
30 inserted
40 inserted
50 inserted
Removed: 10
Removed: 20
60 inserted
70 inserted
30 40 50 60 70
```

## 17.1 Dry Run

| Operation | Front | Rear | Logical Queue |
|---|---:|---:|---|
| enqueue(10) | 0 | 0 | 10 |
| enqueue(20) | 0 | 1 | 10, 20 |
| enqueue(30) | 0 | 2 | 10, 20, 30 |
| enqueue(40) | 0 | 3 | 10, 20, 30, 40 |
| enqueue(50) | 0 | 4 | 10, 20, 30, 40, 50 |
| dequeue() | 1 | 4 | 20, 30, 40, 50 |
| dequeue() | 2 | 4 | 30, 40, 50 |
| enqueue(60) | 2 | 0 | 30, 40, 50, 60 |
| enqueue(70) | 2 | 1 | 30, 40, 50, 60, 70 |

## 17.2 Circular Queue Complexity

| Operation | Time Complexity |
|---|---|
| enqueue() | O(1) |
| dequeue() | O(1) |
| peek() | O(1) |
| isEmpty() | O(1) |
| isFull() | O(1) |
| display() | O(n) |

**Space Complexity:** O(n) for capacity `n`.

---

# 18. Stack vs Queue vs Circular Queue

| Feature | Stack | Queue | Circular Queue |
|---|---|---|---|
| Principle | LIFO | FIFO | FIFO |
| Insertion | Top | Rear | Rear |
| Deletion | Top | Front | Front |
| Main Index | Top | Front, Rear | Front, Rear |
| Array Space Reuse | Top moves backward | Limited in simple linear queue | Uses wraparound |
| Insertion Complexity | O(1) | O(1) | O(1) |
| Deletion Complexity | O(1) | O(1) | O(1) |
| Common Application | Undo operations | Task scheduling | Circular buffers |

---

# 19. Lab Assignments

The following assignments cover the practical requirements of Sessions 1, 2 and 3.

## Lab 1: Stack Using Array

**Problem Statement:** Implement a Stack using an array.

### Required Operations

- Push
- Pop
- Peek
- Display
- Check Empty
- Check Full

### Expected Learning

- LIFO principle
- Top index management
- Overflow and underflow
- Constant-time insertion and deletion

## Lab 2: Complexity Analysis of Loops

Find the time complexity of the following programs.

### Program 1

```java
for (int i = 0; i < n; i++) {
    System.out.println(i);
}
```

**Answer:** O(n)

### Program 2

```java
for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {
        System.out.println(i + j);
    }
}
```

**Answer:** O(n²)

### Program 3

```java
for (int i = 1; i < n; i *= 2) {
    System.out.println(i);
}
```

**Answer:** O(log n)

### Program 4

```java
for (int i = 0; i < n; i++) {

    for (int j = 1; j < n; j *= 2) {
        System.out.println(i + j);
    }
}
```

**Answer:** O(n log n)

## Lab 3: Complexity Analysis of Recursion

Analyse the following recursive functions.

### Example 1

```java
static void fun(int n) {

    if (n <= 0) {
        return;
    }

    fun(n - 1);
}
```

**Time Complexity:** O(n) for positive `n`  
**Auxiliary Space:** O(n)

### Example 2

```java
static void fun(int n) {

    if (n <= 1) {
        return;
    }

    fun(n / 2);
}
```

**Time Complexity:** O(log n) for positive `n`  
**Auxiliary Space:** O(log n)

## Lab 4: Queue Operations

**Problem Statement:** Implement a Queue using an array.

### Required Operations

- Enqueue at rear
- Dequeue from front
- Display
- Check Empty
- Check Full

### Additional Practice: Insertion at Front and Rear

A standard queue permits insertion at the rear only.

To support insertion at both front and rear, use a **Deque (Double-Ended Queue)**.

Java provides the `Deque` interface.

```java
import java.util.ArrayDeque;
import java.util.Deque;

public class DequeDemo {

    public static void main(String[] args) {

        Deque<Integer> deque =
            new ArrayDeque<>();

        deque.addFirst(10);
        deque.addLast(20);
        deque.addFirst(5);

        System.out.println(deque);

        System.out.println(
            "Removed First: " + deque.removeFirst()
        );

        System.out.println(
            "Removed Last: " + deque.removeLast()
        );
    }
}
```

**Output:**

```text
[5, 10, 20]
Removed First: 5
Removed Last: 20
```

This demonstrates the front/rear insertion requirement using Java's built-in Deque. For additional practice, implement a Deque manually using a circular array.

## Lab 5: Circular Queue

**Problem Statement:** Implement a Circular Queue using an array.

### Required Operations

- Enqueue
- Dequeue
- Peek
- Display
- Check Empty
- Check Full
- Wraparound using modulo

### Test Cases

1. Insert into an empty queue.
2. Insert until full.
3. Attempt insertion into a full queue.
4. Delete from a full queue.
5. Insert again after deletion.
6. Delete all elements.
7. Attempt deletion from an empty queue.
8. Test a queue with capacity 1.

---

# 20. Interview Questions and Answers

### Q1. What is an algorithm?

An algorithm is a finite sequence of well-defined instructions used to solve a problem.

### Q2. What is computational thinking?

Computational thinking is a systematic problem-solving approach involving decomposition, pattern recognition, abstraction and algorithm design.

### Q3. What are the main algorithm constructs?

Sequence, Selection and Iteration.

### Q4. What is time complexity?

Time complexity describes how the number of operations performed by an algorithm grows with input size.

### Q5. What is space complexity?

Space complexity describes the memory required by an algorithm as input size grows.

### Q6. What is Big O notation?

Big O notation represents an asymptotic upper bound on the growth of a function.

### Q7. What is the difference between O(1) and O(n)?

O(1) means the operation count is bounded by a constant.

O(n) means the operation count grows at most linearly with input size.

### Q8. What is an ADT?

An Abstract Data Type defines data operations and behavior independently of implementation.

### Q9. What is the difference between an ADT and a data structure?

An ADT defines what operations are supported, while a data structure provides a concrete way to store data and implement those operations.

### Q10. What is an array?

An array is a fixed-length, indexed collection of elements of the same declared type.

### Q11. What is a Stack?

A Stack is a linear data structure that follows LIFO.

### Q12. What is LIFO?

LIFO stands for Last In, First Out.

### Q13. What is Stack Overflow?

Stack overflow in an array-based stack occurs when insertion is attempted after the stack reaches its capacity.

### Q14. What is Stack Underflow?

Stack underflow occurs when removal is attempted from an empty stack.

### Q15. What is the time complexity of push() and pop()?

Both are O(1) for a fixed-capacity array stack.

### Q16. What is a Queue?

A Queue is a linear data structure that follows FIFO.

### Q17. What is FIFO?

FIFO stands for First In, First Out.

### Q18. What is the difference between Stack and Queue?

A Stack removes the most recently inserted element, while a Queue removes the earliest inserted element.

### Q19. What is a Circular Queue?

A Circular Queue is a queue that connects the last position logically to the first position using wraparound indexing.

### Q20. Why is Circular Queue better than a simple Linear Queue?

A Circular Queue can reuse array positions freed by dequeue operations without shifting all remaining elements.

### Q21. What is the modulo operator used for in Circular Queue?

It allows indices to wrap from the last array position back to index zero.

### Q22. What is recursion?

Recursion is a technique in which a method calls itself directly or indirectly.

### Q23. What is a base case?

A base case is a terminating condition that prevents further recursive calls.

### Q24. What is the space complexity of recursive factorial?

O(n), because recursive calls consume stack space.

### Q25. What is the difference between Queue and Deque?

A standard Queue inserts at the rear and removes from the front. A Deque supports insertion and removal at both ends.

### Q26. What is the time complexity of array access?

O(1) for valid direct indexing.

### Q27. What is the time complexity of inserting an element at the beginning of an array?

O(n) in the worst case, because existing elements must be shifted.

### Q28. What is the difference between a linear and a circular queue?

A linear array queue advances indices toward the end, while a circular queue wraps indices to reuse freed positions.

### Q29. What is auxiliary space complexity?

It is the additional memory used by an algorithm beyond its input storage.

### Q30. Which data structure is used for function calls?

The runtime call stack stores information about active method calls.

---

# 21. MCQs

### 1. Which principle does a Stack follow?

A. FIFO  
B. LIFO  
C. FILO only  
D. Random Access

**Answer: B. LIFO**

### 2. Which principle does a Queue follow?

A. LIFO  
B. FIFO  
C. Random Access  
D. Priority

**Answer: B. FIFO**

### 3. Which operation inserts an element into a Stack?

A. enqueue()  
B. dequeue()  
C. push()  
D. delete()

**Answer: C. push()**

### 4. Which operation removes an element from a Stack?

A. push()  
B. pop()  
C. enqueue()  
D. insert()

**Answer: B. pop()**

### 5. What is the time complexity of direct array access?

A. O(n)  
B. O(log n)  
C. O(1)  
D. O(n²)

**Answer: C. O(1)**

### 6. What is the complexity of a loop that runs n times?

A. O(1)  
B. O(n)  
C. O(n²)  
D. O(log n)

**Answer: B. O(n)**

### 7. What is the complexity of two nested loops, each running n times?

A. O(n)  
B. O(log n)  
C. O(n²)  
D. O(1)

**Answer: C. O(n²)**

### 8. What is the complexity of repeatedly dividing n by 2?

A. O(n)  
B. O(log n)  
C. O(n²)  
D. O(2ⁿ)

**Answer: B. O(log n)**

### 9. What is the initial top value of an empty array Stack in the common implementation?

A. 0  
B. 1  
C. -1  
D. null

**Answer: C. -1**

### 10. What happens when pop() is performed on an empty Stack?

A. Overflow  
B. Underflow  
C. Sorting  
D. Traversal

**Answer: B. Underflow**

### 11. Which operation inserts an element into a Queue?

A. push()  
B. pop()  
C. enqueue()  
D. peek()

**Answer: C. enqueue()**

### 12. Which operation removes an element from a Queue?

A. enqueue()  
B. dequeue()  
C. push()  
D. peek()

**Answer: B. dequeue()**

### 13. Which operator is commonly used for Circular Queue indexing?

A. +  
B. -  
C. %  
D. /

**Answer: C. %**

### 14. What is the full condition of the Circular Queue implementation shown above?

A. front == -1  
B. rear == -1  
C. (rear + 1) % capacity == front  
D. front == 0

**Answer: C**

### 15. Which data structure supports insertion and deletion at both ends?

A. Stack  
B. Deque  
C. Binary Tree  
D. Hash Table

**Answer: B. Deque**

### 16. Which notation represents an asymptotic upper bound?

A. Omega  
B. Theta  
C. Big O  
D. Sigma

**Answer: C. Big O**

### 17. What is the time complexity of recursive factorial?

A. O(1)  
B. O(log n)  
C. O(n)  
D. O(n²)

**Answer: C. O(n)**

### 18. What is the auxiliary space complexity of recursive factorial?

A. O(1)  
B. O(n)  
C. O(n²)  
D. O(log n)

**Answer: B. O(n)**

### 19. Which of the following is an ADT?

A. Stack  
B. int  
C. char  
D. boolean

**Answer: A. Stack**

### 20. Which data structure is commonly used for undo functionality?

A. Queue  
B. Stack  
C. Graph  
D. Tree

**Answer: B. Stack**

---

# 22. Quick Revision Notes

## Important Definitions

| Term | Definition |
|---|---|
| Problem Solving | Process of developing a solution to a problem |
| Computational Thinking | Systematic approach to problem solving |
| Algorithm | Finite sequence of well-defined instructions |
| Data Structure | Method of organizing and storing data |
| ADT | Logical definition of data and supported operations |
| Time Complexity | Growth of operation count with input size |
| Space Complexity | Growth of memory usage with input size |
| Big O | Asymptotic upper bound |
| Array | Fixed-length indexed collection |
| Stack | LIFO data structure |
| Queue | FIFO data structure |
| Circular Queue | Queue using circular indexing |
| Recursion | Method calling itself directly or indirectly |
| Base Case | Condition that terminates recursion |
| Overflow | Insertion attempted when capacity is exhausted |
| Underflow | Removal attempted when structure is empty |

## Important Formulas

### Array Address Calculation

For a conceptual contiguous array of equally sized elements:

```text
Address(A[i]) = BaseAddress + i × ElementSize
```

This is a conceptual memory-layout formula; Java does not expose raw array addresses.

### Stack Full Condition

```text
top == capacity - 1
```

### Stack Empty Condition

```text
top == -1
```

### Circular Queue Rear Update

```text
rear = (rear + 1) % capacity
```

### Circular Queue Front Update

```text
front = (front + 1) % capacity
```

### Circular Queue Full Condition

```text
(rear + 1) % capacity == front
```

### Circular Queue Empty Condition

```text
front == -1
```

## Important Complexity Table

| Data Structure / Operation | Time Complexity |
|---|---|
| Array Access | O(1) |
| Array Traversal | O(n) |
| Array Insertion at Beginning | O(n) |
| Array Deletion at Beginning | O(n) |
| Stack Push | O(1) |
| Stack Pop | O(1) |
| Stack Peek | O(1) |
| Queue Enqueue | O(1) |
| Queue Dequeue | O(1) |
| Circular Queue Enqueue | O(1) |
| Circular Queue Dequeue | O(1) |
| Recursive Factorial | O(n) |
| Naive Recursive Fibonacci | O(2ⁿ) upper bound |

---

# 📂 Suggested GitHub Repository Structure

```text
CDAC/
│
└── ADS/
    │
    └── Sessions-01-02-03/
        │
        ├── README.md
        │
        ├── Algorithms/
        │   ├── LargestNumber.java
        │   └── ArraySum.java
        │
        ├── Complexity/
        │   ├── LoopComplexity.java
        │   └── RecursiveComplexity.java
        │
        ├── Arrays/
        │   ├── ArrayTraversal.java
        │   ├── ArrayInsertion.java
        │   └── ArrayDeletion.java
        │
        ├── Stack/
        │   └── ArrayStack.java
        │
        ├── Queue/
        │   ├── ArrayQueue.java
        │   └── DequeDemo.java
        │
        └── CircularQueue/
            └── CircularQueue.java
```

---

# 🎯 Learning Outcomes

After completing Sessions 1, 2 and 3, students should be able to:

1. Apply computational thinking to programming problems.
2. Design algorithms using sequence, selection and iteration.
3. Analyse time and space complexity.
4. Understand Big O notation.
5. Analyse iterative and recursive algorithms.
6. Explain Abstract Data Types.
7. Perform basic array operations.
8. Implement Stack using an array.
9. Implement Queue using an array.
10. Understand front and rear insertion using Deque.
11. Implement Circular Queue using modulo indexing.
12. Identify overflow and underflow conditions.
13. Compare data structures based on their operations and complexity.

---

## 📚 References

**Prescribed Textbook:**

- *Object-Oriented Programming and Data Structures Using Java*, 2026 Edition — Cay S. Horstmann, Wiley.

**Reference Books:**

- *Data Structures and Algorithms in Java*, 6th Edition — Michael T. Goodrich, Roberto Tamassia, Michael H. Goldwasser and Subhasish Banerjee, Wiley.
- *Algorithms*, 4th Edition — Robert Sedgewick and Kevin Wayne.

---

## ⭐ About This Repository

This repository contains learning notes, Java programs, lab exercises, MCQs and interview preparation material for the **CDAC CMCE / PGCP-AC August 2026 Batch**.

The material follows the session topics in the ACTS Pune teaching guidelines and includes additional examples for understanding and practice.

**Maintained by:** Anurag Dhondge  
**GitHub:** https://github.com/anurag-dhondge/CDAC

If you find these notes helpful, consider giving the repository a ⭐ star.

**Happy Coding! 🚀**
