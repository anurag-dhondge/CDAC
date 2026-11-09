# 📘 Sessions 4, 5 & 6: Linked List – Algorithms and Data Structures Using Java

**Course:** CDAC – CMCE / PGCP-AC  
**Batch:** August 2026  
**Institute:** ACTS, Pune  
**Subject:** Algorithms and Data Structures Using Java  
**Sessions:** 4, 5 & 6  
**Duration:** 12 Hours (6 Theory + 6 Lab)  
**Programming Language:** Java

---

# 📑 Table of Contents

1. [Introduction to Linked Lists](#1-introduction-to-linked-lists)
2. [Need for Linked Lists](#2-need-for-linked-lists)
3. [Node Structure](#3-node-structure)
4. [Singly Linked List](#4-singly-linked-list)
5. [Singly Linked List Operations](#5-singly-linked-list-operations)
6. [Complete Singly Linked List Implementation](#6-complete-singly-linked-list-implementation)
7. [Doubly Linked List](#7-doubly-linked-list)
8. [Doubly Linked List Operations](#8-doubly-linked-list-operations)
9. [Complete Doubly Linked List Implementation](#9-complete-doubly-linked-list-implementation)
10. [Circular Linked List](#10-circular-linked-list)
11. [Circular Linked List Implementation](#11-circular-linked-list-implementation)
12. [Node-Based Storage with Arrays](#12-node-based-storage-with-arrays)
13. [Array vs Linked List](#13-array-vs-linked-list)
14. [Circular Queue Using Linked List](#14-circular-queue-using-linked-list)
15. [Stack Using Linked List](#15-stack-using-linked-list)
16. [Complexity Analysis](#16-complexity-analysis)
17. [Lab Assignments](#17-lab-assignments)
18. [Interview Questions and Answers](#18-interview-questions-and-answers)
19. [MCQs](#19-mcqs)
20. [Quick Revision Notes](#20-quick-revision-notes)
21. [GitHub Repository Structure](#21-github-repository-structure)

---

# 1. Introduction to Linked Lists

## 1.1 What is a Linked List?

A Linked List is a linear data structure consisting of a collection of nodes, where each node stores data and a reference (link) to another node.

Unlike arrays, linked list elements are not required to occupy consecutive memory locations.

Each node contains:

1. **Data:** Stores the actual value.
2. **Link / Reference:** Stores the reference to the next node.

### Example

Consider a linked list containing five elements:

```text
HEAD
 |
 v
+------+------+
|  10  |  o---|----+
+------+------+    |
                   v
+------+------+
|  20  |  o---|----+
+------+------+    |
                   v
+------+------+
|  30  |  o---|----+
+------+------+    |
                   v
+------+------+
|  40  |  o---|----+
+------+------+    |
                   v
+------+------+
|  50  | NULL |
+------+------+
```

Here:

- HEAD points to the first node.
- Every node contains data and a reference to the next node.
- The last node points to NULL.
- NULL indicates the end of the list.

## 1.2 Why Do We Need Linked Lists?

Arrays have a fixed length after creation in Java.

For example:

```java
int[] arr = new int[5];
```

The array can store only five elements.

If we need more elements, we must create another array and copy the existing elements.

Linked Lists provide a flexible alternative because nodes can be created and removed dynamically.

### Advantages

- Dynamic size.
- Efficient insertion and deletion when the required node position is known.
- No need for contiguous memory allocation.
- Easy implementation of Stack and Queue.
- Useful for dynamically changing collections.

### Disadvantages

- Additional memory is required for references.
- No direct indexing like arrays.
- Traversal is required to access elements.
- Pointer/reference manipulation can be complex.
- Poorer cache locality than arrays in many implementations.

---

# 2. Need for Linked Lists

Consider inserting an element at the beginning of an array.

```text
Before:

10  20  30  40  50

Insert 5 at beginning:

5  10  20  30  40  50
```

Existing elements must be shifted to the right.

This takes O(n) time.

In a linked list, insertion at the beginning requires only creating a new node and changing the head reference.

```text
Before:

HEAD
 |
 v
10 -> 20 -> 30 -> NULL

Insert 5:

HEAD
 |
 v
5 -> 10 -> 20 -> 30 -> NULL
```

Only the links need to be updated.

**Time Complexity:** O(1)

---

# 3. Node Structure

## 3.1 What is a Node?

A Node is an individual element of a Linked List.

In Java, a node is generally represented using a class.

### Java Node Class

```java
class Node {

    int data;

    Node next;

    Node(int data) {

        this.data = data;

        this.next = null;
    }
}
```

### Explanation

| Component | Description |
|---|---|
| data | Stores the value |
| next | Reference to the next node |
| Node() | Constructor used to initialize a node |
| null | Indicates no next node |

### Creating Nodes

```java
Node n1 = new Node(10);
Node n2 = new Node(20);
Node n3 = new Node(30);

n1.next = n2;
n2.next = n3;
```

Representation:

```text
n1                 n2                 n3
+------+-------+  +------+-------+  +------+------+
|  10  |   o---|->|  20  |   o---|->|  30  | null |
+------+-------+  +------+-------+  +------+------+
```

---

# 4. Singly Linked List

## 4.1 What is a Singly Linked List?

A Singly Linked List is a linear data structure in which each node contains:

- Data
- Reference to the next node

Traversal is possible only in the forward direction.

### Diagram

```text
HEAD
 |
 v
+------+------+
|  10  |  o---|---->
+------+------+
                   |
                   v
              +------+------+
              |  20  |  o---|---->
              +------+------+
                                |
                                v
                           +------+------+
                           |  30  | NULL |
                           +------+------+
```

### Characteristics

1. Contains data and one next reference.
2. Traversal occurs in one direction.
3. Last node points to NULL.
4. Dynamic memory allocation.
5. Insertion and deletion can be efficient when the required position is accessible.

## 4.2 Singly Linked List Java Structure

```java
class Node {

    int data;

    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}
```

---

# 5. Singly Linked List Operations

The important operations are:

1. Insertion
2. Deletion
3. Traversal
4. Searching
5. Updating
6. Counting nodes

## 5.1 Insertion at Beginning

### Algorithm

```text
INSERT_AT_BEGINNING(value)

1. Create a new node.
2. Store value in the node.
3. Set newNode.next = head.
4. Set head = newNode.
```

### Diagram

Before:

```text
HEAD
 |
 v
10 -> 20 -> 30 -> NULL
```

After inserting 5:

```text
HEAD
 |
 v
5 -> 10 -> 20 -> 30 -> NULL
```

### Java Code

```java
Node newNode = new Node(5);

newNode.next = head;

head = newNode;
```

**Time Complexity:** O(1)

## 5.2 Insertion at End

### Algorithm

```text
INSERT_AT_END(value)

1. Create a new node.
2. If head == NULL:
       head = newNode.
3. Otherwise:
       Traverse to the last node.
4. Set last.next = newNode.
```

### Java Code

```java
Node newNode = new Node(40);

if (head == null) {

    head = newNode;

} else {

    Node temp = head;

    while (temp.next != null) {
        temp = temp.next;
    }

    temp.next = newNode;
}
```

**Time Complexity:** O(n) without a maintained tail reference.

## 5.3 Insertion at a Specific Position

Assume positions start from 0.

Before:

```text
10 -> 20 -> 30 -> NULL
```

Insert 25 at position 2:

```text
10 -> 20 -> 25 -> 30 -> NULL
```

### Java Code

```java
Node newNode = new Node(25);

Node temp = head;

for (int i = 0; i < 1; i++) {
    temp = temp.next;
}

newNode.next = temp.next;

temp.next = newNode;
```

The complete implementation must validate the position before performing insertion.

**Time Complexity:** O(n)

## 5.4 Deletion at Beginning

Before:

```text
HEAD
 |
 v
10 -> 20 -> 30 -> NULL
```

After:

```text
HEAD
 |
 v
20 -> 30 -> NULL
```

### Java Code

```java
if (head != null) {
    head = head.next;
}
```

**Time Complexity:** O(1)

## 5.5 Deletion at End

Before:

```text
10 -> 20 -> 30 -> NULL
```

After:

```text
10 -> 20 -> NULL
```

### Java Code

```java
if (head == null) {

    System.out.println("List is Empty");

} else if (head.next == null) {

    head = null;

} else {

    Node temp = head;

    while (temp.next.next != null) {
        temp = temp.next;
    }

    temp.next = null;
}
```

**Time Complexity:** O(n)

## 5.6 Searching an Element

```java
int key = 20;

Node temp = head;

while (temp != null) {

    if (temp.data == key) {

        System.out.println("Element Found");

        break;
    }

    temp = temp.next;
}
```

**Time Complexity:** O(n)

## 5.7 Traversal

Traversal means visiting every node in the linked list.

```java
Node temp = head;

while (temp != null) {

    System.out.print(temp.data + " -> ");

    temp = temp.next;
}

System.out.println("NULL");
```

**Output:**

```text
10 -> 20 -> 30 -> NULL
```

**Time Complexity:** O(n)

---

# 6. Complete Singly Linked List Implementation

**File:** `SinglyLinkedList.java`

```java
public class SinglyLinkedList {

    private static class Node {

        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    private Node head;

    // Insert at beginning
    public void insertAtBeginning(int value) {

        Node newNode = new Node(value);

        newNode.next = head;

        head = newNode;
    }

    // Insert at end
    public void insertAtEnd(int value) {

        Node newNode = new Node(value);

        if (head == null) {
            head = newNode;
            return;
        }

        Node temp = head;

        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = newNode;
    }

    // Insert at position (0-based)
    public void insertAtPosition(int value, int position) {

        if (position < 0) {
            throw new IndexOutOfBoundsException();
        }

        if (position == 0) {
            insertAtBeginning(value);
            return;
        }

        Node temp = head;

        for (int i = 0; i < position - 1; i++) {

            if (temp == null) {
                throw new IndexOutOfBoundsException();
            }

            temp = temp.next;
        }

        if (temp == null) {
            throw new IndexOutOfBoundsException();
        }

        Node newNode = new Node(value);

        newNode.next = temp.next;

        temp.next = newNode;
    }

    // Delete from beginning
    public void deleteFromBeginning() {

        if (head == null) {
            System.out.println("List is Empty");
            return;
        }

        head = head.next;
    }

    // Delete from end
    public void deleteFromEnd() {

        if (head == null) {
            System.out.println("List is Empty");
            return;
        }

        if (head.next == null) {
            head = null;
            return;
        }

        Node temp = head;

        while (temp.next.next != null) {
            temp = temp.next;
        }

        temp.next = null;
    }

    // Search
    public boolean search(int key) {

        Node temp = head;

        while (temp != null) {

            if (temp.data == key) {
                return true;
            }

            temp = temp.next;
        }

        return false;
    }

    // Count nodes
    public int size() {

        int count = 0;

        Node temp = head;

        while (temp != null) {

            count++;

            temp = temp.next;
        }

        return count;
    }

    // Display
    public void display() {

        Node temp = head;

        while (temp != null) {

            System.out.print(temp.data + " -> ");

            temp = temp.next;
        }

        System.out.println("NULL");
    }

    public static void main(String[] args) {

        SinglyLinkedList list = new SinglyLinkedList();

        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);

        list.insertAtBeginning(5);

        list.insertAtPosition(15, 2);

        list.display();

        System.out.println("Size: " + list.size());

        System.out.println("Search 20: " + list.search(20));

        list.deleteFromBeginning();

        list.deleteFromEnd();

        list.display();
    }
}
```

### Expected Output

```text
5 -> 10 -> 15 -> 20 -> 30 -> NULL

Size: 5

Search 20: true

10 -> 15 -> 20 -> NULL
```

---

# 7. Doubly Linked List

## 7.1 What is a Doubly Linked List?

A Doubly Linked List is a linked list in which every node contains three components:

1. Previous reference
2. Data
3. Next reference

It supports traversal in both forward and backward directions.

### Node Structure

```text
+--------+--------+--------+
|  PREV  |  DATA  |  NEXT  |
+--------+--------+--------+
```

### Diagram

```text
NULL <- 10 <-> 20 <-> 30 -> NULL
```

More detailed representation:

```text
        HEAD                         TAIL
          |                           |
          v                           v
NULL <- [10] <------> [20] <------> [30] -> NULL
```

## 7.2 Characteristics

- Every node contains previous and next references.
- Supports forward traversal.
- Supports backward traversal.
- Requires additional memory for the previous reference.
- Deletion of a known node can be performed efficiently.

## 7.3 Doubly Linked List Node in Java

```java
class Node {

    int data;

    Node prev;

    Node next;

    Node(int data) {

        this.data = data;

        this.prev = null;

        this.next = null;
    }
}
```

## 7.4 Insertion at Beginning

Before:

```text
NULL <- 10 <-> 20 <-> 30 -> NULL
```

After inserting 5:

```text
NULL <- 5 <-> 10 <-> 20 <-> 30 -> NULL
```

### Java Code

```java
Node newNode = new Node(5);

if (head == null) {

    head = newNode;
    tail = newNode;

} else {

    newNode.next = head;

    head.prev = newNode;

    head = newNode;
}
```

## 7.5 Insertion at End

```java
Node newNode = new Node(40);

if (tail == null) {

    head = newNode;
    tail = newNode;

} else {

    tail.next = newNode;

    newNode.prev = tail;

    tail = newNode;
}
```

**Time Complexity:** O(1) when a tail reference is maintained.

## 7.6 Deletion at Beginning

```java
if (head != null) {

    head = head.next;

    if (head != null) {

        head.prev = null;

    } else {

        tail = null;
    }
}
```

**Time Complexity:** O(1)

## 7.7 Deletion at End

```java
if (tail != null) {

    tail = tail.prev;

    if (tail != null) {

        tail.next = null;

    } else {

        head = null;
    }
}
```

**Time Complexity:** O(1) when a tail reference is maintained.

## 7.8 Forward Traversal

```java
Node temp = head;

while (temp != null) {

    System.out.print(temp.data + " <-> ");

    temp = temp.next;
}

System.out.println("NULL");
```

## 7.9 Backward Traversal

```java
Node temp = tail;

while (temp != null) {

    System.out.print(temp.data + " <-> ");

    temp = temp.prev;
}

System.out.println("NULL");
```

---

# 8. Doubly Linked List Operations

| Operation | Description |
|---|---|
| Insert at Beginning | Add a node before the current head |
| Insert at End | Add a node after the current tail |
| Insert at Position | Insert a node at a specified position |
| Delete at Beginning | Remove the head node |
| Delete at End | Remove the tail node |
| Delete Specific Node | Remove a selected node |
| Forward Traversal | Traverse using next |
| Backward Traversal | Traverse using prev |
| Search | Find a specific value |

### Important Link Updates

When inserting a node between two nodes:

```text
Before:

10 <-> 30

Insert 20:

10 <-> 20 <-> 30
```

Required link updates:

```java
newNode.prev = current;
newNode.next = current.next;

current.next.prev = newNode;
current.next = newNode;
```

The surrounding nodes must be updated consistently.

---

# 9. Complete Doubly Linked List Implementation

**File:** `DoublyLinkedList.java`

```java
public class DoublyLinkedList {

    private static class Node {

        int data;
        Node prev;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    private Node head;
    private Node tail;

    // Insert at beginning
    public void insertAtBeginning(int value) {

        Node newNode = new Node(value);

        if (head == null) {

            head = tail = newNode;

        } else {

            newNode.next = head;

            head.prev = newNode;

            head = newNode;
        }
    }

    // Insert at end
    public void insertAtEnd(int value) {

        Node newNode = new Node(value);

        if (tail == null) {

            head = tail = newNode;

        } else {

            tail.next = newNode;

            newNode.prev = tail;

            tail = newNode;
        }
    }

    // Delete from beginning
    public void deleteFromBeginning() {

        if (head == null) {
            System.out.println("List is Empty");
            return;
        }

        if (head == tail) {

            head = tail = null;

        } else {

            head = head.next;

            head.prev = null;
        }
    }

    // Delete from end
    public void deleteFromEnd() {

        if (tail == null) {
            System.out.println("List is Empty");
            return;
        }

        if (head == tail) {

            head = tail = null;

        } else {

            tail = tail.prev;

            tail.next = null;
        }
    }

    // Forward display
    public void displayForward() {

        Node temp = head;

        while (temp != null) {

            System.out.print(temp.data + " <-> ");

            temp = temp.next;
        }

        System.out.println("NULL");
    }

    // Backward display
    public void displayBackward() {

        Node temp = tail;

        while (temp != null) {

            System.out.print(temp.data + " <-> ");

            temp = temp.prev;
        }

        System.out.println("NULL");
    }

    public static void main(String[] args) {

        DoublyLinkedList list = new DoublyLinkedList();

        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);

        list.insertAtBeginning(5);

        System.out.println("Forward:");

        list.displayForward();

        System.out.println("Backward:");

        list.displayBackward();

        list.deleteFromBeginning();

        list.deleteFromEnd();

        list.displayForward();
    }
}
```

### Expected Output

```text
Forward:
5 <-> 10 <-> 20 <-> 30 <-> NULL

Backward:
30 <-> 20 <-> 10 <-> 5 <-> NULL

10 <-> 20 <-> NULL
```

---

# 10. Circular Linked List

## 10.1 What is a Circular Linked List?

A Circular Linked List is a linked list in which the last node points back to the first node instead of pointing to NULL.

It can be implemented as a singly circular linked list or a doubly circular linked list.

### Singly Circular Linked List

```text
       +---------------------------+
       |                           |
       v                           |
HEAD -> 10 -> 20 -> 30 -> 40 ------+
```

Here:

```java
last.next = head;
```

The last node points to the first node.

## 10.2 Characteristics

- Last node does not point to NULL.
- Traversal can continue circularly.
- There is no natural NULL termination.
- Useful in cyclic scheduling and round-robin processing.

## 10.3 Difference Between Singly and Circular Linked List

**Singly Linked List:**

```text
10 -> 20 -> 30 -> NULL
```

**Circular Linked List:**

```text
10 -> 20 -> 30
^           |
|___________|
```

## 10.4 Circular Linked List Node

```java
class Node {

    int data;

    Node next;

    Node(int data) {

        this.data = data;

        this.next = null;
    }
}
```

## 10.5 Insertion at Beginning

If the list is empty:

```java
newNode.next = newNode;
head = newNode;
```

If the list is not empty, the last node must also be updated to point to the new head.

With a maintained tail reference:

```java
newNode.next = head;

tail.next = newNode;

head = newNode;
```

## 10.6 Insertion at End

With a maintained tail reference:

```java
newNode.next = head;

tail.next = newNode;

tail = newNode;
```

The empty-list case must initialize both head and tail.

## 10.7 Traversal

In a circular linked list, traversal stops when we reach the head again.

```java
if (head != null) {

    Node temp = head;

    do {

        System.out.print(temp.data + " -> ");

        temp = temp.next;

    } while (temp != head);

    System.out.println("(back to HEAD)");
}
```

A do-while loop is useful because the first node must be visited before checking whether traversal has returned to the head.

---

# 11. Circular Linked List Implementation

**File:** `CircularLinkedList.java`

```java
public class CircularLinkedList {

    private static class Node {

        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    private Node head;
    private Node tail;

    // Insert at beginning
    public void insertAtBeginning(int value) {

        Node newNode = new Node(value);

        if (head == null) {

            head = tail = newNode;

            newNode.next = head;

        } else {

            newNode.next = head;

            tail.next = newNode;

            head = newNode;
        }
    }

    // Insert at end
    public void insertAtEnd(int value) {

        Node newNode = new Node(value);

        if (head == null) {

            head = tail = newNode;

            newNode.next = head;

        } else {

            newNode.next = head;

            tail.next = newNode;

            tail = newNode;
        }
    }

    // Delete from beginning
    public void deleteFromBeginning() {

        if (head == null) {
            System.out.println("List is Empty");
            return;
        }

        if (head == tail) {

            head = tail = null;

        } else {

            head = head.next;

            tail.next = head;
        }
    }

    // Delete from end
    public void deleteFromEnd() {

        if (head == null) {
            System.out.println("List is Empty");
            return;
        }

        if (head == tail) {

            head = tail = null;

            return;
        }

        Node temp = head;

        while (temp.next != tail) {
            temp = temp.next;
        }

        temp.next = head;

        tail = temp;
    }

    // Display
    public void display() {

        if (head == null) {

            System.out.println("List is Empty");

            return;
        }

        Node temp = head;

        do {

            System.out.print(temp.data + " -> ");

            temp = temp.next;

        } while (temp != head);

        System.out.println("(back to HEAD)");
    }

    public static void main(String[] args) {

        CircularLinkedList list = new CircularLinkedList();

        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);

        list.insertAtBeginning(5);

        list.display();

        list.deleteFromBeginning();

        list.deleteFromEnd();

        list.display();
    }
}
```

### Expected Output

```text
5 -> 10 -> 20 -> 30 -> (back to HEAD)

10 -> 20 -> (back to HEAD)
```

---

# 12. Node-Based Storage with Arrays

## 12.1 Introduction

Linked lists are generally implemented using dynamically created node objects and references.

However, linked-list relationships can also be represented using arrays.

In this approach, arrays store:

1. Node data.
2. The index of the next node.

This is also known as an array-based linked list or cursor-based linked list.

## 12.2 Example

Consider:

```text
Data Array:

Index:  0   1   2
Data:  10  20  30
```

Next Array:

```text
Index:  0   1   2
Next:   2  -1   1
```

The starting index is 0.

Traversal:

```text
Index 0 → Index 2 → Index 1 → -1
```

Therefore, the linked list is:

```text
10 -> 30 -> 20 -> NULL
```

Here, `-1` indicates the end of the list.

## 12.3 Java Implementation

```java
public class ArrayBasedLinkedList {

    public static void main(String[] args) {

        int[] data = {10, 20, 30};

        int[] next = {2, -1, 1};

        int head = 0;

        int current = head;

        while (current != -1) {

            System.out.print(data[current] + " -> ");

            current = next[current];
        }

        System.out.println("NULL");
    }
}
```

### Output

```text
10 -> 30 -> 20 -> NULL
```

## 12.4 Advantages

- Can represent linked relationships using array indices.
- Useful in environments where dynamic object allocation is restricted.
- Helps understand how links connect nodes.
- Can use a fixed-size node pool.

## 12.5 Limitations

- Capacity is fixed by the arrays.
- Free-space management is required.
- Insertion and deletion require careful index updates.
- Does not provide automatic object-based memory management.

---

# 13. Array vs Linked List

| Feature | Array | Linked List |
|---|---|---|
| Memory | Contiguous logical storage | Nodes can be separately allocated |
| Size | Fixed length in Java | Dynamically adjustable |
| Access | O(1) by index | O(n) by position |
| Search | O(n) | O(n) |
| Insert at Beginning | O(n) | O(1) |
| Delete at Beginning | O(n) | O(1) |
| Insert at End | O(1) with free capacity | O(1) with tail reference |
| Extra Memory | No link per element | Stores node references |
| Cache Locality | Generally better | Generally poorer |
| Traversal | Index-based | Reference-based |

### When to Use Arrays?

- When frequent indexed access is required.
- When collection size is known.
- When memory overhead should be minimized.
- When cache-friendly traversal is important.

### When to Use Linked Lists?

- When frequent insertion and deletion are required.
- When sequential access is sufficient.
- When the collection size changes dynamically.
- When implementing pointer-based data structures.

---

# 14. Circular Queue Using Linked List

## 14.1 What is a Circular Queue Using Linked List?

A Circular Queue using Linked List is a queue implementation in which nodes are connected in a circular manner.

The last node points back to the first node.

It follows FIFO:

**First In, First Out.**

Unlike an array-based circular queue, a linked-list-based circular queue does not require a predefined array capacity.

## 14.2 Structure

Each node contains:

- Data
- Next reference

Maintain a reference to the rear node.

The front node can be accessed using:

```java
front = rear.next;
```

### Diagram

```text
       FRONT
         |
         v
      +------+
      |  10  |----+
      +------+    |
                  v
      +------+  +------+
      |  20  |  |  40  |
      +------+  +------+
          |       ^
          v       |
        +------+
        |  30  |
        +------+

       REAR = 30
```

The correct logical connection is:

```text
10 -> 20 -> 30 -> 40
^                 |
|_________________|
```

Here, the rear node points back to the front node.

## 14.3 Queue Operations

### Enqueue

1. Create a new node.
2. If the queue is empty, make the new node point to itself.
3. Otherwise, insert the new node after rear.
4. Update rear.
5. Maintain rear.next as the front node.

### Dequeue

1. Check whether the queue is empty.
2. Get the front node using rear.next.
3. If only one node exists, set rear to null.
4. Otherwise, move rear.next to the second node.
5. Return the deleted value.

## 14.4 Java Implementation

**File:** `CircularQueueLinkedList.java`

```java
public class CircularQueueLinkedList {

    private static class Node {

        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    private Node rear;

    // Check empty
    public boolean isEmpty() {
        return rear == null;
    }

    // Insert at rear
    public void enqueue(int value) {

        Node newNode = new Node(value);

        if (isEmpty()) {

            rear = newNode;

            rear.next = rear;

        } else {

            newNode.next = rear.next;

            rear.next = newNode;

            rear = newNode;
        }

        System.out.println(value + " inserted");
    }

    // Delete from front
    public int dequeue() {

        if (isEmpty()) {

            throw new IllegalStateException(
                "Queue Underflow"
            );
        }

        Node front = rear.next;

        int value = front.data;

        if (front == rear) {

            rear = null;

        } else {

            rear.next = front.next;
        }

        return value;
    }

    // Peek
    public int peek() {

        if (isEmpty()) {

            throw new IllegalStateException(
                "Queue is Empty"
            );
        }

        return rear.next.data;
    }

    // Display
    public void display() {

        if (isEmpty()) {

            System.out.println("Queue is Empty");

            return;
        }

        Node front = rear.next;

        Node temp = front;

        do {

            System.out.print(temp.data + " ");

            temp = temp.next;

        } while (temp != front);

        System.out.println();
    }

    public static void main(String[] args) {

        CircularQueueLinkedList q =
            new CircularQueueLinkedList();

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);

        q.display();

        System.out.println(
            "Deleted: " + q.dequeue()
        );

        q.display();

        System.out.println(
            "Front: " + q.peek()
        );
    }
}
```

### Output

```text
10 inserted
20 inserted
30 inserted
40 inserted

10 20 30 40

Deleted: 10

20 30 40

Front: 20
```

## 14.5 Complexity Analysis

| Operation | Time Complexity |
|---|---|
| enqueue() | O(1) |
| dequeue() | O(1) |
| peek() | O(1) |
| isEmpty() | O(1) |
| display() | O(n) |

**Space Complexity:** O(n), where n is the number of stored elements.

---

# 15. Stack Using Linked List

## 15.1 What is Stack Using Linked List?

A Stack can be implemented using a Linked List instead of an array.

The head node represents the top of the stack.

It follows the LIFO principle.

### Diagram

```text
TOP
 |
 v
+------+------+
|  30  |  o---|---->
+------+------+
                   |
                   v
              +------+------+
              |  20  |  o---|---->
              +------+------+
                                |
                                v
                           +------+------+
                           |  10  | NULL |
                           +------+------+
```

## 15.2 Stack Operations

| Operation | Description |
|---|---|
| push() | Insert at head |
| pop() | Delete from head |
| peek() | Read head value |
| isEmpty() | Check whether head is null |
| display() | Traverse all nodes |

## 15.3 Push Operation

### Algorithm

```text
PUSH(value)

1. Create a new node.
2. Set newNode.next = top.
3. Set top = newNode.
```

### Java Code

```java
Node newNode = new Node(value);

newNode.next = top;

top = newNode;
```

**Time Complexity:** O(1)

## 15.4 Pop Operation

### Algorithm

```text
POP()

1. Check if top == NULL.
2. If empty, report underflow.
3. Store top.data.
4. Set top = top.next.
5. Return stored value.
```

### Java Code

```java
if (top == null) {

    System.out.println("Stack Underflow");

} else {

    int value = top.data;

    top = top.next;
}
```

**Time Complexity:** O(1)

## 15.5 Peek Operation

```java
if (top == null) {

    System.out.println("Stack is Empty");

} else {

    System.out.println(top.data);
}
```

**Time Complexity:** O(1)

## 15.6 Complete Java Implementation

**File:** `StackLinkedList.java`

```java
public class StackLinkedList {

    private static class Node {

        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    private Node top;

    // Check empty
    public boolean isEmpty() {
        return top == null;
    }

    // Push
    public void push(int value) {

        Node newNode = new Node(value);

        newNode.next = top;

        top = newNode;

        System.out.println(value + " pushed");
    }

    // Pop
    public int pop() {

        if (isEmpty()) {

            throw new IllegalStateException(
                "Stack Underflow"
            );
        }

        int value = top.data;

        top = top.next;

        return value;
    }

    // Peek
    public int peek() {

        if (isEmpty()) {

            throw new IllegalStateException(
                "Stack is Empty"
            );
        }

        return top.data;
    }

    // Display
    public void display() {

        if (isEmpty()) {

            System.out.println("Stack is Empty");

            return;
        }

        Node temp = top;

        while (temp != null) {

            System.out.println(temp.data);

            temp = temp.next;
        }
    }

    public static void main(String[] args) {

        StackLinkedList stack =
            new StackLinkedList();

        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println(
            "Top: " + stack.peek()
        );

        System.out.println(
            "Popped: " + stack.pop()
        );

        stack.display();
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

## 15.7 Complexity Analysis

| Operation | Time Complexity |
|---|---|
| push() | O(1) |
| pop() | O(1) |
| peek() | O(1) |
| isEmpty() | O(1) |
| display() | O(n) |

**Space Complexity:** O(n)

### Array Stack vs Linked List Stack

| Feature | Array Stack | Linked List Stack |
|---|---|---|
| Storage | Array | Nodes |
| Capacity | Fixed | Dynamic |
| Push | O(1) | O(1) |
| Pop | O(1) | O(1) |
| Extra Memory | No link per element | Reference per node |
| Overflow | When array is full | When memory allocation fails |
| Memory Allocation | One array allocation | Individual node allocations |

---

# 16. Complexity Analysis

## 16.1 Singly Linked List

| Operation | Complexity |
|---|---|
| Access by Position | O(n) |
| Search | O(n) |
| Traversal | O(n) |
| Insert at Beginning | O(1) |
| Insert at End | O(n) without tail |
| Insert at End | O(1) with tail |
| Delete at Beginning | O(1) |
| Delete at End | O(n) |
| Delete Known Node After Previous Node Is Available | O(1) |

## 16.2 Doubly Linked List

| Operation | Complexity |
|---|---|
| Search | O(n) |
| Forward Traversal | O(n) |
| Backward Traversal | O(n) |
| Insert at Beginning | O(1) |
| Insert at End | O(1) with tail |
| Delete at Beginning | O(1) |
| Delete at End | O(1) with tail |
| Delete Known Node | O(1) |

## 16.3 Circular Linked List

| Operation | Complexity |
|---|---|
| Search | O(n) |
| Traversal | O(n) |
| Insert at Beginning | O(1) with tail |
| Insert at End | O(1) with tail |
| Delete at Beginning | O(1) with tail |
| Delete at End | O(n) in singly circular list |

## 16.4 Lab Implementations

| Implementation | Enqueue / Push | Dequeue / Pop |
|---|---:|---:|
| Stack Using Linked List | O(1) | O(1) |
| Circular Queue Using Linked List | O(1) | O(1) |

---

# 17. Lab Assignments

The following practicals directly cover the ACTS Pune syllabus for Sessions 4, 5 and 6.

## Lab 1: Implement Circular Queue Using Linked List

**Objective:** Implement a circular queue using dynamically created nodes.

### Requirements

- Create Node class.
- Maintain rear reference.
- Access front using rear.next.
- Implement enqueue().
- Implement dequeue().
- Implement peek().
- Implement isEmpty().
- Implement display().

### Test Cases

1. Insert an element into an empty queue.
2. Insert multiple elements.
3. Delete the front element.
4. Display all elements.
5. Insert after deletion.
6. Delete all elements.
7. Attempt deletion from an empty queue.

### Expected Learning

- Circular linking.
- FIFO principle.
- Front and rear management.
- Dynamic node allocation.
- Circular traversal.

## Lab 2: Implement Stack Using Linked List

**Objective:** Implement a Stack using a Linked List.

### Requirements

- Create Node class.
- Maintain top reference.
- Implement push().
- Implement pop().
- Implement peek().
- Implement isEmpty().
- Implement display().

### Test Cases

1. Push multiple elements.
2. Display the stack.
3. View the top element.
4. Pop an element.
5. Push another element.
6. Pop all elements.
7. Attempt pop on an empty stack.

### Expected Learning

- LIFO principle.
- Head reference management.
- Dynamic memory allocation.
- Stack overflow and underflow concepts.

## Additional Practice Problems

1. Reverse a Singly Linked List.
2. Find the Middle Node of a Linked List.
3. Find the Nth Node from the End.
4. Detect a Cycle in a Linked List.
5. Remove Duplicates from a Linked List.
6. Merge Two Sorted Linked Lists.
7. Implement a Doubly Linked List with insertion and deletion.
8. Implement a Circular Linked List with traversal.
9. Implement a Deque using a Doubly Linked List.
10. Reverse a Doubly Linked List.

---

# 18. Interview Questions and Answers

### Q1. What is a Linked List?

A Linked List is a linear data structure made up of nodes connected through references.

### Q2. What is a Node?

A Node is an individual unit that stores data and one or more references to other nodes.

### Q3. What is a Singly Linked List?

A list in which each node contains data and a reference to the next node.

### Q4. What is a Doubly Linked List?

A list in which each node contains data, a previous reference and a next reference.

### Q5. What is a Circular Linked List?

A linked list in which the last node points back to the first node.

### Q6. What is the difference between Singly and Doubly Linked Lists?

Singly Linked List supports forward traversal, whereas Doubly Linked List supports both forward and backward traversal.

### Q7. What is the difference between Singly and Circular Linked Lists?

In a Singly Linked List, the last node points to null. In a Circular Linked List, the last node points to the first node.

### Q8. What is the head of a Linked List?

Head is the reference pointing to the first node.

### Q9. What is the tail of a Linked List?

Tail is the reference pointing to the last node.

### Q10. What is the time complexity of insertion at the beginning?

O(1).

### Q11. What is the time complexity of searching in a Linked List?

O(n).

### Q12. Why is random access not possible in a Linked List?

Because nodes are connected through references and there is no direct indexed access to arbitrary nodes.

### Q13. What is the advantage of a Doubly Linked List?

It supports traversal in both directions and efficient deletion when the target node is already known.

### Q14. What is the disadvantage of a Doubly Linked List?

It requires additional memory for the previous reference and more link updates.

### Q15. How do you detect the end of a Singly Linked List?

By checking whether the next reference of the current node is null.

### Q16. How do you traverse a Circular Linked List?

Start from head and continue until the current node points back to head.

### Q17. Can a Linked List contain duplicate elements?

Yes. Linked Lists can contain duplicate values unless additional restrictions are implemented.

### Q18. Can we implement Stack using Linked List?

Yes. The head node can be used as the top of the Stack.

### Q19. Can we implement Queue using Linked List?

Yes. Maintain front and rear references to support efficient insertion and deletion.

### Q20. What is the time complexity of Stack push and pop using Linked List?

Both operations take O(1) time.

### Q21. What is the time complexity of Circular Queue enqueue and dequeue using Linked List?

Both take O(1) time when a rear reference is maintained.

### Q22. What is the difference between Array and Linked List?

An array provides direct indexed access, while a linked list requires traversal to access an element by position.

### Q23. What is node-based storage using arrays?

It is a technique in which arrays store node data and references using array indices.

### Q24. What is a self-referential structure?

A self-referential structure contains a reference to another object of the same type. A linked-list node is a common example.

### Q25. What happens if the head reference becomes null?

The linked list becomes empty or unreachable through that head reference.

---

# 19. MCQs

### 1. What does a Linked List consist of?

A. Only arrays  
B. Nodes  
C. Only variables  
D. Only loops  

**Answer: B. Nodes**

### 2. Which reference points to the first node?

A. Tail  
B. Rear  
C. Head  
D. Prev  

**Answer: C. Head**

### 3. In a Singly Linked List, the last node points to:

A. Head  
B. NULL  
C. Previous node  
D. First array index  

**Answer: B. NULL**

### 4. How many references are present in a basic Singly Linked List node?

A. One  
B. Two  
C. Three  
D. Four  

**Answer: A. One**

### 5. How many references are present in a basic Doubly Linked List node?

A. One  
B. Two  
C. Three  
D. Four  

**Answer: B. Two**

### 6. Which linked list supports backward traversal?

A. Singly Linked List  
B. Doubly Linked List  
C. Basic Stack  
D. Basic Queue  

**Answer: B. Doubly Linked List**

### 7. In a Circular Linked List, the last node points to:

A. NULL  
B. Previous node  
C. First node  
D. Random node  

**Answer: C. First node**

### 8. What is the time complexity of insertion at the beginning of a Singly Linked List?

A. O(n)  
B. O(log n)  
C. O(1)  
D. O(n²)  

**Answer: C. O(1)**

### 9. What is the time complexity of searching in a Linked List?

A. O(1)  
B. O(n)  
C. O(log n)  
D. O(n²)  

**Answer: B. O(n)**

### 10. Which data structure follows LIFO?

A. Queue  
B. Stack  
C. Linked List  
D. Graph  

**Answer: B. Stack**

### 11. Which data structure follows FIFO?

A. Stack  
B. Queue  
C. Tree  
D. Array  

**Answer: B. Queue**

### 12. Which node is used as the top in a Linked List Stack implementation?

A. Tail  
B. Head  
C. Middle  
D. Rear  

**Answer: B. Head**

### 13. Which reference is commonly maintained for efficient insertion in a linked-list-based queue?

A. Previous  
B. Rear  
C. Index  
D. Middle  

**Answer: B. Rear**

### 14. Which operation is O(1) in a Stack implemented using a Linked List?

A. Search  
B. Traversal  
C. Push  
D. Sorting  

**Answer: C. Push**

### 15. Which loop is particularly useful for traversing a Circular Linked List?

A. for only  
B. while only  
C. do-while  
D. switch  

**Answer: C. do-while**

### 16. Which of the following requires additional memory in a Doubly Linked List?

A. Data  
B. Previous reference  
C. Head  
D. Tail  

**Answer: B. Previous reference**

### 17. What is the main advantage of Linked Lists over fixed-size arrays?

A. Faster random access  
B. Dynamic size  
C. No memory usage  
D. Automatic sorting  

**Answer: B. Dynamic size**

### 18. What indicates the end of an array-based linked list?

A. 0  
B. -1  
C. 1  
D. n  

**Answer: B. -1**, in the representation used in these notes.

### 19. Which linked list is suitable for round-robin scheduling?

A. Singly Linear Linked List  
B. Circular Linked List  
C. Array only  
D. Stack  

**Answer: B. Circular Linked List**

### 20. What is the time complexity of deleting the last node in a singly linked list without a tail or previous-node reference?

A. O(1)  
B. O(log n)  
C. O(n)  
D. O(n²)  

**Answer: C. O(n)**

---

# 20. Quick Revision Notes

## Important Definitions

| Term | Definition |
|---|---|
| Linked List | Collection of nodes connected through references |
| Node | Stores data and reference(s) |
| Head | Reference to the first node |
| Tail | Reference to the last node |
| Next | Reference to the next node |
| Prev | Reference to the previous node |
| Singly Linked List | Each node has one next reference |
| Doubly Linked List | Each node has previous and next references |
| Circular Linked List | Last node points to first node |
| Traversal | Visiting nodes sequentially |
| Dynamic Allocation | Creating nodes as required |
| Cursor-Based List | Uses array indices to represent node links |

## Important Diagrams

**Singly Linked List**

```text
10 -> 20 -> 30 -> NULL
```

**Doubly Linked List**

```text
NULL <- 10 <-> 20 <-> 30 -> NULL
```

**Circular Linked List**

```text
10 -> 20 -> 30
^           |
|___________|
```

**Stack Using Linked List**

```text
TOP
 |
 v
30 -> 20 -> 10 -> NULL
```

**Circular Queue Using Linked List**

```text
10 -> 20 -> 30 -> 40
^                 |
|_________________|
```

## Important Complexity Table

| Operation | Singly LL | Doubly LL | Circular LL |
|---|---:|---:|---:|
| Search | O(n) | O(n) | O(n) |
| Traversal | O(n) | O(n) | O(n) |
| Insert Beginning | O(1) | O(1) | O(1) with tail |
| Insert End | O(n) without tail | O(1) with tail | O(1) with tail |
| Delete Beginning | O(1) | O(1) | O(1) with tail |
| Delete End | O(n) | O(1) with tail | O(n) |

## Important Lab Programs

1. Singly Linked List implementation.
2. Doubly Linked List implementation.
3. Circular Linked List implementation.
4. Stack using Linked List.
5. Circular Queue using Linked List.
6. Node-based storage using arrays.

---

# 21. GitHub Repository Structure

```text
CDAC/
│
└── ADS/
    │
    └── Sessions-04-05-06/
        │
        ├── README.md
        │
        ├── SinglyLinkedList/
        │   └── SinglyLinkedList.java
        │
        ├── DoublyLinkedList/
        │   └── DoublyLinkedList.java
        │
        ├── CircularLinkedList/
        │   └── CircularLinkedList.java
        │
        ├── ArrayBasedLinkedList/
        │   └── ArrayBasedLinkedList.java
        │
        ├── StackUsingLinkedList/
        │   └── StackLinkedList.java
        │
        └── CircularQueueUsingLinkedList/
            └── CircularQueueLinkedList.java
```

---

# 🎯 Learning Outcomes

After completing Sessions 4, 5 and 6, students should be able to:

1. Understand the concept of Linked Lists.
2. Explain the structure of a node.
3. Implement Singly Linked Lists.
4. Implement Doubly Linked Lists.
5. Implement Circular Linked Lists.
6. Perform insertion, deletion, searching and traversal.
7. Understand node-based storage using arrays.
8. Implement Stack using Linked List.
9. Implement Circular Queue using Linked List.
10. Analyse the time and space complexity of linked-list operations.
11. Compare arrays and linked lists.
12. Select an appropriate linked-list implementation for different problems.

---

## 📚 References

**Prescribed Textbook:**

- *Object-Oriented Programming and Data Structures Using Java*, 2026 Edition – Cay S. Horstmann, Wiley.

**Reference Books:**

- *Data Structures and Algorithms in Java*, 6th Edition – Michael T. Goodrich, Roberto Tamassia, Michael H. Goldwasser and Subhasish Banerjee, Wiley.
- *Algorithms*, 4th Edition – Robert Sedgewick and Kevin Wayne.

---

## ⭐ About This Repository

This repository contains detailed notes, Java implementations, practical assignments, diagrams, complexity analysis, interview questions and MCQs for the **CDAC CMCE / PGCP-AC August 2026 Batch**.

The content follows the Algorithms and Data Structures teaching guidelines provided by ACTS Pune.

**Maintained by:** Anurag Dhondge  
**GitHub:** https://github.com/anurag-dhondge/CDAC

If you find these notes useful, consider giving the repository a ⭐ star.

**Happy Coding! 🚀**
