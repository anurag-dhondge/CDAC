# Session 19: Collection Framework in Java

**Course:** CMCE – August 2026 Batch  
**Subject:** Core Java  
**Topics:** Introduction to Collections, Collection Hierarchy, List, Queue, Set and Map

---

# 1. Introduction to Collection Framework

The **Java Collection Framework (JCF)** is a set of interfaces, classes, and algorithms used to store, manage, and manipulate groups of objects.

It is available mainly in the `java.util` package.

Before the Collection Framework, Java developers commonly used arrays to store multiple values.

However, arrays have limitations:

- Fixed size.
- Cannot grow or shrink dynamically.
- Limited built-in operations.
- Manual searching and sorting are often required.

The Collection Framework provides ready-made data structures that make data management easier.

### Example: Using an Array

```java
public class ArrayDemo {

    public static void main(String[] args) {

        int[] numbers = new int[3];

        numbers[0] = 10;
        numbers[1] = 20;
        numbers[2] = 30;

        for (int number : numbers) {
            System.out.println(number);
        }
    }
}
```

**Output:**

```text
10
20
30
```

The array has a fixed size of 3.

### Example: Using ArrayList

```java
import java.util.ArrayList;

public class CollectionDemo {

    public static void main(String[] args) {

        ArrayList<Integer> numbers = new ArrayList<>();

        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        numbers.add(40);

        for (Integer number : numbers) {
            System.out.println(number);
        }
    }
}
```

**Output:**

```text
10
20
30
40
```

Here, the ArrayList can grow dynamically.

### Advantages of Collection Framework

1. Dynamic storage of objects.
2. Ready-made data structures.
3. Provides searching and sorting operations.
4. Reduces programming effort.
5. Supports generics for type safety.
6. Provides reusable interfaces and classes.
7. Supports different ways of storing and accessing data.

---

# 2. Collection Framework Hierarchy

The Collection Framework contains several interfaces and their implementing classes.

The two important root-level interfaces to understand are:

- `Collection`
- `Map`

**Important:** Map is part of the Java Collection Framework, but it does not extend the Collection interface.

### Collection Framework Hierarchy Diagram

```text
                       Iterable
                          |
                      Collection
                          |
          +---------------+---------------+
          |               |               |
         List            Set            Queue
          |               |               |
     +----+----+      +---+------+    +---+------+
     |         |      |          |    |          |
 ArrayList LinkedList HashSet  SortedSet PriorityQueue
     |                |          |       |
   Vector          LinkedHashSet NavigableSet
     |                           |
   Stack                       TreeSet


                       Map
                        |
              +---------+----------+
              |         |          |
           HashMap  LinkedHashMap  SortedMap
              |                    |
        Hashtable              NavigableMap
                                   |
                                TreeMap
```

This is a simplified conceptual hierarchy. Some interfaces and classes have additional inheritance relationships.

### Important Interfaces

| Interface | Purpose |
|---|---|
| Iterable | Allows iteration over elements |
| Collection | Root interface for most collection types |
| List | Ordered collection that allows duplicates |
| Set | Collection that does not allow duplicate elements |
| Queue | Collection designed for holding elements for processing |
| Deque | Double-ended queue |
| Map | Stores key-value pairs |
| SortedSet | Set that maintains sorted order |
| NavigableSet | Provides navigation operations on sorted sets |
| SortedMap | Map that maintains sorted keys |
| NavigableMap | Provides navigation operations on sorted maps |

### Important Classes

| Class | Interface Implemented | Purpose |
|---|---|---|
| ArrayList | List | Dynamic array |
| LinkedList | List, Deque | Doubly linked list |
| Vector | List | Synchronized dynamic array |
| Stack | List | Legacy stack class |
| HashSet | Set | Unique elements using hashing |
| LinkedHashSet | Set | Unique elements with insertion-order iteration |
| TreeSet | NavigableSet | Sorted unique elements |
| PriorityQueue | Queue | Priority-based processing |
| ArrayDeque | Deque | Resizable double-ended queue |
| HashMap | Map | Key-value storage using hashing |
| LinkedHashMap | Map | Maintains predictable iteration order |
| TreeMap | NavigableMap | Sorted key-value storage |
| Hashtable | Map | Legacy synchronized key-value storage |

---

# 3. Collection Interface

The `Collection` interface is the root interface for List, Set, and Queue.

It provides common methods for adding, removing, checking, and accessing elements.

### Important Collection Methods

| Method | Description |
|---|---|
| `add(E e)` | Adds an element |
| `addAll(Collection c)` | Adds all elements from another collection |
| `remove(Object o)` | Removes an element |
| `removeAll(Collection c)` | Removes matching elements |
| `retainAll(Collection c)` | Keeps only common elements |
| `contains(Object o)` | Checks whether an element exists |
| `containsAll(Collection c)` | Checks whether all elements exist |
| `size()` | Returns the number of elements |
| `isEmpty()` | Checks whether the collection is empty |
| `clear()` | Removes all elements |
| `iterator()` | Returns an iterator |
| `toArray()` | Converts collection into an array |

### Example

```java
import java.util.ArrayList;
import java.util.Collection;

public class CollectionInterfaceDemo {

    public static void main(String[] args) {

        Collection<String> names = new ArrayList<>();

        names.add("Anurag");
        names.add("Rahul");
        names.add("Sushant");

        System.out.println(names);

        System.out.println("Size: " + names.size());

        System.out.println("Contains Rahul: " +
                names.contains("Rahul"));

        names.remove("Rahul");

        System.out.println("After removal: " + names);

        System.out.println("Is Empty: " +
                names.isEmpty());

        names.clear();

        System.out.println("After clear: " + names);
    }
}
```

**Output:**

```text
[Anurag, Rahul, Sushant]
Size: 3
Contains Rahul: true
After removal: [Anurag, Sushant]
Is Empty: false
After clear: []
```

---

# 4. List Collection

A **List** is an ordered collection that allows duplicate elements.

It maintains elements in a sequence and supports index-based access.

### Characteristics of List

- Maintains order.
- Allows duplicate elements.
- Allows null elements in common implementations.
- Supports index-based access.
- Elements can be inserted or removed at specific positions.

### List Hierarchy

```text
             List
               |
      +--------+---------+
      |        |         |
  ArrayList LinkedList Vector
                         |
                       Stack
```

### Important List Implementations

1. ArrayList
2. LinkedList
3. Vector
4. Stack

---

## 4.1 ArrayList

`ArrayList` is a resizable array implementation of the List interface.

It automatically grows when elements are added.

### Characteristics

- Maintains insertion order.
- Allows duplicate elements.
- Allows multiple null values.
- Provides fast index-based access.
- Inserting or removing elements in the middle may require shifting elements.
- Not synchronized by default.

### Syntax

```java
ArrayList<Integer> list = new ArrayList<>();
```

### Example: ArrayListDemo.java

```java
import java.util.ArrayList;

public class ArrayListDemo {

    public static void main(String[] args) {

        ArrayList<String> names = new ArrayList<>();

        // Adding elements
        names.add("Anurag");
        names.add("Rahul");
        names.add("Sushant");
        names.add("Anurag");

        System.out.println("List: " + names);

        // Accessing element
        System.out.println("First Element: " +
                names.get(0));

        // Updating element
        names.set(1, "Jayraj");

        System.out.println("After Update: " + names);

        // Removing element
        names.remove("Sushant");

        System.out.println("After Removal: " + names);

        // Size
        System.out.println("Size: " + names.size());

        // Iterating
        for (String name : names) {
            System.out.println(name);
        }
    }
}
```

**Output:**

```text
List: [Anurag, Rahul, Sushant, Anurag]
First Element: Anurag
After Update: [Anurag, Jayraj, Sushant, Anurag]
After Removal: [Anurag, Jayraj, Anurag]
Size: 3
Anurag
Jayraj
Anurag
```

### Important ArrayList Methods

| Method | Description |
|---|---|
| `add(element)` | Adds an element |
| `add(index, element)` | Adds at a specific position |
| `get(index)` | Retrieves an element |
| `set(index, element)` | Replaces an element |
| `remove(index)` | Removes by index |
| `remove(element)` | Removes a matching element |
| `indexOf(element)` | Returns first matching index |
| `lastIndexOf(element)` | Returns last matching index |
| `contains(element)` | Checks whether element exists |
| `size()` | Returns list size |
| `clear()` | Removes all elements |
| `isEmpty()` | Checks whether list is empty |

---

## 4.2 LinkedList

`LinkedList` is a doubly linked list implementation.

Each node stores:

- Data
- Reference to the previous node
- Reference to the next node

### LinkedList Structure

```text
       Node 1             Node 2             Node 3
   +----------+       +----------+       +----------+
   | Prev: null|       | Prev: N1 |       | Prev: N2 |
   | Data: 10  | <-->  | Data: 20 | <-->  | Data: 30 |
   | Next: N2  |       | Next: N3 |       | Next: null|
   +----------+       +----------+       +----------+
```

### Characteristics

- Maintains insertion order.
- Allows duplicates.
- Allows null values.
- Implements both List and Deque.
- Efficient insertion/removal at the ends.
- Accessing an element by index requires traversal.

### Example: LinkedListDemo.java

```java
import java.util.LinkedList;

public class LinkedListDemo {

    public static void main(String[] args) {

        LinkedList<String> names = new LinkedList<>();

        names.add("Anurag");
        names.add("Rahul");
        names.add("Sushant");

        // Add at beginning
        names.addFirst("Jayraj");

        // Add at end
        names.addLast("Rudresh");

        System.out.println(names);

        // First element
        System.out.println("First: " +
                names.getFirst());

        // Last element
        System.out.println("Last: " +
                names.getLast());

        // Remove first
        names.removeFirst();

        // Remove last
        names.removeLast();

        System.out.println("After Removal: " + names);
    }
}
```

**Output:**

```text
[Jayraj, Anurag, Rahul, Sushant, Rudresh]
First: Jayraj
Last: Rudresh
After Removal: [Anurag, Rahul, Sushant]
```

### Important LinkedList Methods

| Method | Description |
|---|---|
| `addFirst()` | Adds at beginning |
| `addLast()` | Adds at end |
| `getFirst()` | Retrieves first element |
| `getLast()` | Retrieves last element |
| `removeFirst()` | Removes first element |
| `removeLast()` | Removes last element |
| `offerFirst()` | Inserts at beginning |
| `offerLast()` | Inserts at end |
| `pollFirst()` | Retrieves and removes first element |
| `pollLast()` | Retrieves and removes last element |

---

## 4.3 Vector

`Vector` is a resizable array implementation of List.

It is a legacy collection class.

### Characteristics

- Maintains insertion order.
- Allows duplicates.
- Allows null elements.
- Grows dynamically.
- Its individual methods are synchronized.
- Often slower than ArrayList in single-threaded use because of synchronization overhead.

### Example: VectorDemo.java

```java
import java.util.Vector;

public class VectorDemo {

    public static void main(String[] args) {

        Vector<Integer> numbers = new Vector<>();

        numbers.add(10);
        numbers.add(20);
        numbers.add(30);

        System.out.println(numbers);

        System.out.println("Capacity: " +
                numbers.capacity());

        numbers.add(40);

        System.out.println("After Add: " + numbers);

        numbers.remove(1);

        System.out.println("After Remove: " + numbers);
    }
}
```

**Output:**

```text
[10, 20, 30]
Capacity: 10
After Add: [10, 20, 30, 40]
After Remove: [10, 30, 40]
```

The default initial capacity is 10. Capacity can grow as elements are added.

---

## 4.4 Stack

`Stack` is a legacy class that represents a Last In, First Out (LIFO) data structure.

### LIFO Principle

**Last In, First Out**

The element inserted last is removed first.

Example:

```text
       PUSH
         |
         v
       +----+
       | 30 |  <- TOP
       +----+
       | 20 |
       +----+
       | 10 |
       +----+
```

After one POP:

```text
       +----+
       | 20 |  <- TOP
       +----+
       | 10 |
       +----+
```

### Important Stack Methods

| Method | Description |
|---|---|
| `push()` | Adds an element |
| `pop()` | Removes and returns the top element |
| `peek()` | Returns the top element without removing it |
| `empty()` | Checks whether stack is empty |
| `search()` | Returns 1-based position from the top |

### Example: StackDemo.java

```java
import java.util.Stack;

public class StackDemo {

    public static void main(String[] args) {

        Stack<Integer> stack = new Stack<>();

        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Stack: " + stack);

        System.out.println("Top: " + stack.peek());

        System.out.println("Removed: " + stack.pop());

        System.out.println("After Pop: " + stack);

        System.out.println("Empty: " + stack.empty());
    }
}
```

**Output:**

```text
Stack: [10, 20, 30]
Top: 30
Removed: 30
After Pop: [10, 20]
Empty: false
```

**Note:** For new stack implementations, `ArrayDeque` is generally preferred over the legacy Stack class.

---

# 5. Queue Collection

A **Queue** is a collection designed to hold elements before processing.

A common queue follows the FIFO principle.

### FIFO Principle

**First In, First Out**

The element inserted first is removed first.

Example:

```text
Insertion                         Removal
   |                                 |
   v                                 v

 FRONT                            REAR
   |                                 |
   v                                 v
+------+-------+-------+-------+
|  10  |  20   |  30   |  40   |
+------+-------+-------+-------+
   |
   v
 First Element Removed
```

### Queue Hierarchy

```text
                 Queue
                   |
          +--------+---------+
          |                  |
    LinkedList          PriorityQueue
          |
         Deque
          |
      ArrayDeque
```

This is a simplified diagram; LinkedList implements both List and Deque, while Deque extends Queue.

### Important Queue Methods

| Method | Description |
|---|---|
| `add()` | Inserts an element; may throw exception if insertion fails |
| `offer()` | Inserts an element; returns false if insertion fails |
| `remove()` | Retrieves and removes the head; throws exception if empty |
| `poll()` | Retrieves and removes the head; returns null if empty |
| `element()` | Retrieves the head without removing; throws exception if empty |
| `peek()` | Retrieves the head without removing; returns null if empty |

### Queue Method Comparison

| Operation | Exception Form | Special-Value Form |
|---|---|---|
| Insert | `add()` | `offer()` |
| Remove | `remove()` | `poll()` |
| Examine | `element()` | `peek()` |

---

## 5.1 PriorityQueue

`PriorityQueue` processes elements according to priority rather than insertion order.

By default, it uses natural ordering.

For numbers, the smallest element is at the head.

### Characteristics

- Implements Queue.
- Does not guarantee insertion-order iteration.
- Does not allow null elements.
- Allows duplicate elements.
- Uses a priority heap internally.
- Elements must be mutually comparable or a Comparator must be supplied.

### Example: PriorityQueueDemo.java

```java
import java.util.PriorityQueue;

public class PriorityQueueDemo {

    public static void main(String[] args) {

        PriorityQueue<Integer> queue =
                new PriorityQueue<>();

        queue.offer(30);
        queue.offer(10);
        queue.offer(40);
        queue.offer(20);

        System.out.println("PriorityQueue: " + queue);

        System.out.println("Head: " + queue.peek());

        System.out.println("Removed: " + queue.poll());

        System.out.println("After Poll: " + queue);

        System.out.println("Processing Elements:");

        while (!queue.isEmpty()) {
            System.out.println(queue.poll());
        }
    }
}
```

**Possible Output:**

```text
PriorityQueue: [10, 20, 40, 30]
Head: 10
Removed: 10
After Poll: [20, 30, 40]
Processing Elements:
20
30
40
```

**Important:** The internal representation and iteration order are not guaranteed to be sorted. Repeatedly removing elements using `poll()` retrieves them according to priority.

---

## 5.2 ArrayDeque

`ArrayDeque` is a resizable array implementation of the Deque interface.

Deque means **Double Ended Queue**.

It supports insertion and removal at both ends.

### Example: ArrayDequeDemo.java

```java
import java.util.ArrayDeque;

public class ArrayDequeDemo {

    public static void main(String[] args) {

        ArrayDeque<Integer> deque = new ArrayDeque<>();

        deque.addFirst(20);
        deque.addLast(30);
        deque.addFirst(10);

        System.out.println(deque);

        System.out.println("First: " + deque.peekFirst());

        System.out.println("Last: " + deque.peekLast());

        deque.removeFirst();

        deque.removeLast();

        System.out.println("After Removal: " + deque);
    }
}
```

**Output:**

```text
[10, 20, 30]
First: 10
Last: 30
After Removal: [20]
```

### Queue vs Deque

| Queue | Deque |
|---|---|
| Generally processes from one end and inserts at the other | Supports both ends |
| Commonly FIFO | Can support FIFO and LIFO |
| `offer()` and `poll()` | `offerFirst()`, `offerLast()`, `pollFirst()`, `pollLast()` |
| Example: PriorityQueue | Example: ArrayDeque |

---

# 6. Set Collection

A **Set** is a collection that does not allow duplicate elements.

It is useful when we want to store unique values.

### Characteristics

- Does not allow duplicate elements.
- Does not provide index-based access.
- Ordering depends on the implementation.
- Common implementations support null differently.

### Set Hierarchy

```text
                    Set
                     |
             +-------+-------+
             |               |
          HashSet        SortedSet
             |               |
       LinkedHashSet    NavigableSet
                             |
                          TreeSet
```

---

## 6.1 HashSet

`HashSet` stores unique elements using hashing.

### Characteristics

- Does not allow duplicates.
- Does not guarantee insertion order.
- Allows one null element.
- Uses `hashCode()` and `equals()` to identify duplicates.
- Offers expected constant-time basic operations with good hash distribution.

### Example: HashSetDemo.java

```java
import java.util.HashSet;

public class HashSetDemo {

    public static void main(String[] args) {

        HashSet<Integer> numbers = new HashSet<>();

        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        numbers.add(10);

        System.out.println(numbers);

        System.out.println("Contains 20: " +
                numbers.contains(20));

        numbers.remove(30);

        System.out.println("After Removal: " + numbers);

        System.out.println("Size: " + numbers.size());
    }
}
```

**Possible Output:**

```text
[20, 10, 30]
Contains 20: true
After Removal: [20, 10]
Size: 2
```

**Important:** HashSet does not guarantee element order. The displayed order can differ.

---

## 6.2 LinkedHashSet

`LinkedHashSet` maintains predictable insertion-order iteration while preventing duplicates.

### Characteristics

- Does not allow duplicates.
- Maintains insertion order.
- Allows one null element.
- Uses hashing and linked ordering.

### Example: LinkedHashSetDemo.java

```java
import java.util.LinkedHashSet;

public class LinkedHashSetDemo {

    public static void main(String[] args) {

        LinkedHashSet<String> names =
                new LinkedHashSet<>();

        names.add("Anurag");
        names.add("Rahul");
        names.add("Sushant");
        names.add("Anurag");

        System.out.println(names);
    }
}
```

**Output:**

```text
[Anurag, Rahul, Sushant]
```

---

## 6.3 TreeSet

`TreeSet` stores unique elements in sorted order.

It implements NavigableSet.

### Characteristics

- Does not allow duplicate elements.
- Maintains sorted order.
- Uses natural ordering by default.
- Can use a Comparator for custom sorting.
- Does not allow null with its natural ordering.

### Example: TreeSetDemo.java

```java
import java.util.TreeSet;

public class TreeSetDemo {

    public static void main(String[] args) {

        TreeSet<Integer> numbers = new TreeSet<>();

        numbers.add(50);
        numbers.add(10);
        numbers.add(40);
        numbers.add(20);
        numbers.add(10);

        System.out.println(numbers);

        System.out.println("First: " + numbers.first());

        System.out.println("Last: " + numbers.last());

        System.out.println("Higher than 20: " +
                numbers.higher(20));

        System.out.println("Lower than 40: " +
                numbers.lower(40));
    }
}
```

**Output:**

```text
[10, 20, 40, 50]
First: 10
Last: 50
Higher than 20: 40
Lower than 40: 20
```

### HashSet vs LinkedHashSet vs TreeSet

| Feature | HashSet | LinkedHashSet | TreeSet |
|---|---|---|---|
| Duplicates | Not allowed | Not allowed | Not allowed |
| Ordering | No guaranteed order | Insertion order | Sorted order |
| Null | One null allowed | One null allowed | Generally not allowed with natural ordering |
| Data structure | Hash table | Hash table + linked ordering | Balanced tree |
| Typical performance | O(1) average basic operations | O(1) average basic operations | O(log n) basic operations |
| Best use | Unique elements | Unique elements in insertion order | Unique sorted elements |

---

# 7. Map Collection

A **Map** stores data in key-value pairs.

Each key maps to a value.

Example:

```text
101 -> Anurag
102 -> Rahul
103 -> Sushant
```

Here:

- 101 is a key.
- Anurag is its value.

### Characteristics of Map

- Stores key-value pairs.
- Keys must be unique.
- Values can be duplicated.
- A key maps to at most one value.
- Updating an existing key replaces its previous value.
- Map does not extend Collection.

### Map Hierarchy

```text
                    Map
                     |
          +----------+----------+
          |          |          |
       HashMap   Hashtable  SortedMap
          |                     |
    LinkedHashMap          NavigableMap
                                |
                             TreeMap
```

---

## 7.1 HashMap

`HashMap` stores key-value pairs using hashing.

### Characteristics

- Does not guarantee iteration order.
- Allows one null key.
- Allows multiple null values.
- Keys must be unique.
- Not synchronized by default.
- Provides expected constant-time basic operations with good hash distribution.

### Syntax

```java
HashMap<Integer, String> map = new HashMap<>();
```

### Important HashMap Methods

| Method | Description |
|---|---|
| `put(key, value)` | Inserts or updates a mapping |
| `get(key)` | Retrieves value using key |
| `remove(key)` | Removes mapping |
| `containsKey(key)` | Checks whether key exists |
| `containsValue(value)` | Checks whether value exists |
| `keySet()` | Returns all keys |
| `values()` | Returns all values |
| `entrySet()` | Returns key-value entries |
| `size()` | Returns number of mappings |
| `isEmpty()` | Checks whether map is empty |
| `clear()` | Removes all mappings |
| `getOrDefault()` | Returns mapped value or default |

### Example: HashMapDemo.java

```java
import java.util.HashMap;
import java.util.Map;

public class HashMapDemo {

    public static void main(String[] args) {

        HashMap<Integer, String> students =
                new HashMap<>();

        // Adding key-value pairs
        students.put(101, "Anurag");
        students.put(102, "Rahul");
        students.put(103, "Sushant");

        System.out.println(students);

        // Accessing value
        System.out.println("Student 101: " +
                students.get(101));

        // Updating value
        students.put(102, "Jayraj");

        System.out.println("After Update: " + students);

        // Checking key
        System.out.println("Contains 103: " +
                students.containsKey(103));

        // Removing entry
        students.remove(103);

        System.out.println("After Removal: " + students);

        // Iterating using entrySet
        for (Map.Entry<Integer, String> entry :
                students.entrySet()) {

            System.out.println(
                    entry.getKey() + " -> " +
                    entry.getValue()
            );
        }
    }
}
```

**Possible Output:**

```text
{101=Anurag, 102=Rahul, 103=Sushant}
Student 101: Anurag
After Update: {101=Anurag, 102=Jayraj, 103=Sushant}
Contains 103: true
After Removal: {101=Anurag, 102=Jayraj}
101 -> Anurag
102 -> Jayraj
```

**Important:** HashMap does not guarantee iteration order. The example order is illustrative.

---

## 7.2 LinkedHashMap

`LinkedHashMap` maintains predictable iteration order.

By default, it maintains insertion order.

### Characteristics

- Stores key-value pairs.
- Keys are unique.
- Maintains insertion order by default.
- Allows one null key and multiple null values.
- Can also be configured for access-order iteration.

### Example: LinkedHashMapDemo.java

```java
import java.util.LinkedHashMap;

public class LinkedHashMapDemo {

    public static void main(String[] args) {

        LinkedHashMap<Integer, String> students =
                new LinkedHashMap<>();

        students.put(101, "Anurag");
        students.put(102, "Rahul");
        students.put(103, "Sushant");

        System.out.println(students);
    }
}
```

**Output:**

```text
{101=Anurag, 102=Rahul, 103=Sushant}
```

---

## 7.3 TreeMap

`TreeMap` stores key-value pairs sorted by keys.

It implements NavigableMap.

### Characteristics

- Keys are unique.
- Keys are sorted by natural ordering or Comparator.
- Does not allow null keys with natural ordering.
- Allows null values.
- Basic operations generally take O(log n) time.

### Example: TreeMapDemo.java

```java
import java.util.TreeMap;

public class TreeMapDemo {

    public static void main(String[] args) {

        TreeMap<Integer, String> students =
                new TreeMap<>();

        students.put(103, "Sushant");
        students.put(101, "Anurag");
        students.put(102, "Rahul");

        System.out.println(students);

        System.out.println("First Key: " +
                students.firstKey());

        System.out.println("Last Key: " +
                students.lastKey());

        System.out.println("Higher Key: " +
                students.higherKey(101));
    }
}
```

**Output:**

```text
{101=Anurag, 102=Rahul, 103=Sushant}
First Key: 101
Last Key: 103
Higher Key: 102
```

### HashMap vs LinkedHashMap vs TreeMap

| Feature | HashMap | LinkedHashMap | TreeMap |
|---|---|---|---|
| Key ordering | No guaranteed order | Insertion order by default | Sorted key order |
| Duplicate keys | Not allowed | Not allowed | Not allowed |
| Null key | One allowed | One allowed | Not allowed with natural ordering |
| Null values | Allowed | Allowed | Allowed |
| Data structure | Hash table | Hash table + linked ordering | Balanced tree |
| Typical performance | O(1) average | O(1) average | O(log n) |
| Best use | Fast key-value lookup | Predictable insertion-order iteration | Sorted key-value data |

---

# 8. Difference Between List, Set, Queue and Map

| Feature | List | Set | Queue | Map |
|---|---|---|---|---|
| Stores | Elements | Unique elements | Elements for processing | Key-value pairs |
| Duplicates | Allowed | Not allowed | Depends on implementation | Keys are unique; values may repeat |
| Ordering | Maintains sequence | Depends on implementation | Depends on implementation | Depends on implementation |
| Index access | Yes | No | No | Access by key |
| Null support | Depends on implementation | Depends on implementation | Depends on implementation | Depends on implementation |
| Main implementations | ArrayList, LinkedList | HashSet, TreeSet | PriorityQueue, ArrayDeque | HashMap, TreeMap |

### When Should You Use Each?

| Requirement | Choose |
|---|---|
| Store ordered student names with duplicates | ArrayList |
| Store unique mobile numbers | HashSet |
| Store unique names in insertion order | LinkedHashSet |
| Store sorted numbers without duplicates | TreeSet |
| Process tasks in FIFO order | ArrayDeque used as Queue |
| Process elements by priority | PriorityQueue |
| Store roll number and student name | HashMap |
| Store sorted employee IDs and details | TreeMap |

---

# 9. Iterating Through Collections

Java provides different ways to iterate through collections.

### 1. Using for Loop

```java
import java.util.ArrayList;

public class ForLoopDemo {

    public static void main(String[] args) {

        ArrayList<String> names = new ArrayList<>();

        names.add("Anurag");
        names.add("Rahul");
        names.add("Sushant");

        for (int i = 0; i < names.size(); i++) {
            System.out.println(names.get(i));
        }
    }
}
```

### 2. Using Enhanced for Loop

```java
for (String name : names) {
    System.out.println(name);
}
```

### 3. Using Iterator

```java
import java.util.ArrayList;
import java.util.Iterator;

public class IteratorDemo {

    public static void main(String[] args) {

        ArrayList<Integer> numbers = new ArrayList<>();

        numbers.add(10);
        numbers.add(20);
        numbers.add(30);

        Iterator<Integer> itr = numbers.iterator();

        while (itr.hasNext()) {

            Integer value = itr.next();

            System.out.println(value);
        }
    }
}
```

**Output:**

```text
10
20
30
```

### Iterator Methods

| Method | Description |
|---|---|
| `hasNext()` | Checks whether another element exists |
| `next()` | Returns the next element |
| `remove()` | Removes the last element returned by next(), if supported |

**Important:** Use `Iterator.remove()` when removing elements during iteration. Directly modifying many collections while using their iterator can cause `ConcurrentModificationException`.

### 4. Using forEach()

```java
names.forEach(name -> System.out.println(name));
```

---

# 10. Collection vs Collections

These two terms are different.

| Collection | Collections |
|---|---|
| Interface | Utility class |
| Root interface for List, Set and Queue | Provides static utility methods |
| Represents a group of objects | Provides operations on collections |
| Part of java.util | Part of java.util |

### Example: Collections Utility Class

```java
import java.util.ArrayList;
import java.util.Collections;

public class CollectionsUtilityDemo {

    public static void main(String[] args) {

        ArrayList<Integer> numbers = new ArrayList<>();

        numbers.add(40);
        numbers.add(10);
        numbers.add(30);
        numbers.add(20);

        System.out.println("Original: " + numbers);

        Collections.sort(numbers);

        System.out.println("Sorted: " + numbers);

        Collections.reverse(numbers);

        System.out.println("Reversed: " + numbers);

        System.out.println("Maximum: " +
                Collections.max(numbers));

        System.out.println("Minimum: " +
                Collections.min(numbers));
    }
}
```

**Output:**

```text
Original: [40, 10, 30, 20]
Sorted: [10, 20, 30, 40]
Reversed: [40, 30, 20, 10]
Maximum: 40
Minimum: 10
```

---

# 11. Important Interview Questions and Answers

**Q1. What is the Java Collection Framework?**

It is a set of interfaces and classes used to store and manipulate groups of objects.

**Q2. Which package contains the Collection Framework?**

`java.util`.

**Q3. What is the root interface of List, Set and Queue?**

Collection.

**Q4. Does Map extend Collection?**

No. Map is a separate interface in the Collection Framework.

**Q5. What is the difference between List and Set?**

List allows duplicates and maintains a sequence. Set prevents duplicate elements.

**Q6. What is ArrayList?**

ArrayList is a resizable array implementation of List.

**Q7. What is LinkedList?**

LinkedList is a doubly linked list implementation of List and Deque.

**Q8. Difference between ArrayList and LinkedList?**

ArrayList provides fast index-based access, while LinkedList supports efficient insertion and removal at its ends.

**Q9. What is Vector?**

Vector is a synchronized, resizable array implementation of List.

**Q10. What is Stack?**

Stack is a LIFO data structure in which the last inserted element is removed first.

**Q11. What is Queue?**

Queue is a collection designed to hold elements before processing, commonly following FIFO order.

**Q12. What is PriorityQueue?**

PriorityQueue processes elements according to their priority rather than insertion order.

**Q13. What is Deque?**

Deque is a double-ended queue that supports insertion and removal at both ends.

**Q14. What is HashSet?**

HashSet stores unique elements using hashing.

**Q15. Difference between HashSet and LinkedHashSet?**

HashSet does not guarantee iteration order, while LinkedHashSet maintains insertion order.

**Q16. What is TreeSet?**

TreeSet stores unique elements in sorted order.

**Q17. What is HashMap?**

HashMap stores key-value pairs using hashing.

**Q18. Can HashMap contain duplicate keys?**

No. A key can map to only one value. Inserting an existing key replaces its previous value.

**Q19. Can HashMap contain null?**

Yes. It permits one null key and multiple null values.

**Q20. Difference between HashMap and TreeMap?**

HashMap does not guarantee key ordering, while TreeMap sorts entries by key.

**Q21. Difference between Collection and Collections?**

Collection is an interface, while Collections is a utility class.

**Q22. What is Iterator?**

Iterator is used to traverse elements of a collection.

**Q23. What is the difference between Iterator and ListIterator?**

Iterator supports forward traversal. ListIterator supports forward and backward traversal and additional List-specific operations.

**Q24. Which collection is best for storing unique sorted elements?**

TreeSet.

**Q25. Which collection is suitable for storing key-value pairs?**

Map implementations such as HashMap.

**Q26. Which collection is best for fast index-based access?**

ArrayList.

**Q27. Which collection is suitable for FIFO processing?**

A Queue implementation such as ArrayDeque.

**Q28. What is the difference between poll() and remove() in Queue?**

Both retrieve and remove the head. `poll()` returns null if the queue is empty, whereas `remove()` throws an exception.

**Q29. What is the difference between peek() and poll()?**

`peek()` retrieves the head without removing it, while `poll()` retrieves and removes it.

**Q30. Which methods help HashSet identify duplicate objects?**

`hashCode()` and `equals()`.

---

# 12. MCQs

**1. Which package contains the Java Collection Framework?**

A. java.io  
B. java.util  
C. java.lang  
D. java.sql  

**Answer: B. java.util**

**2. Which interface is the root of List, Set and Queue?**

A. Map  
B. Iterable  
C. Collection  
D. Iterator  

**Answer: C. Collection**

**3. Which interface allows duplicate elements?**

A. Set  
B. List  
C. Map  
D. None  

**Answer: B. List**

**4. Which collection stores unique elements?**

A. ArrayList  
B. LinkedList  
C. HashSet  
D. Vector  

**Answer: C. HashSet**

**5. Which class maintains insertion order and does not allow duplicates?**

A. HashSet  
B. LinkedHashSet  
C. TreeSet  
D. PriorityQueue  

**Answer: B. LinkedHashSet**

**6. Which collection maintains sorted elements?**

A. ArrayList  
B. HashSet  
C. TreeSet  
D. LinkedHashSet  

**Answer: C. TreeSet**

**7. Which class is based on a resizable array?**

A. ArrayList  
B. TreeSet  
C. HashSet  
D. TreeMap  

**Answer: A. ArrayList**

**8. Which class is a doubly linked list implementation?**

A. ArrayList  
B. LinkedList  
C. HashMap  
D. Vector  

**Answer: B. LinkedList**

**9. Which principle is followed by Stack?**

A. FIFO  
B. LIFO  
C. Random  
D. Sorted  

**Answer: B. LIFO**

**10. Which principle is commonly followed by Queue?**

A. LIFO  
B. FIFO  
C. Sorted  
D. Random  

**Answer: B. FIFO**

**11. Which method inserts an element into a Queue and returns false if insertion fails?**

A. add()  
B. offer()  
C. poll()  
D. peek()  

**Answer: B. offer()**

**12. Which Queue method retrieves and removes the head without throwing an exception when empty?**

A. remove()  
B. element()  
C. poll()  
D. peek()  

**Answer: C. poll()**

**13. Which collection stores key-value pairs?**

A. List  
B. Set  
C. Queue  
D. Map  

**Answer: D. Map**

**14. Which Map maintains insertion order by default?**

A. HashMap  
B. TreeMap  
C. LinkedHashMap  
D. Hashtable  

**Answer: C. LinkedHashMap**

**15. Which Map sorts keys?**

A. HashMap  
B. LinkedHashMap  
C. TreeMap  
D. Hashtable  

**Answer: C. TreeMap**

**16. Can HashMap store duplicate keys?**

A. Yes  
B. No  
C. Only String keys  
D. Only Integer keys  

**Answer: B. No**

**17. Which class is a legacy synchronized List implementation?**

A. ArrayList  
B. Vector  
C. HashSet  
D. TreeSet  

**Answer: B. Vector**

**18. Which utility class provides sort(), reverse(), min() and max()?**

A. Collection  
B. Collections  
C. Comparator  
D. Iterator  

**Answer: B. Collections**

**19. Which method checks whether an element exists in a collection?**

A. find()  
B. search()  
C. contains()  
D. get()  

**Answer: C. contains()**

**20. Which collection is generally preferred over legacy Stack for new stack implementations?**

A. HashSet  
B. ArrayDeque  
C. TreeMap  
D. Vector  

**Answer: B. ArrayDeque**

---

# 13. Output-Based Questions

### Question 1: ArrayList

```java
import java.util.ArrayList;

public class Test {

    public static void main(String[] args) {

        ArrayList<Integer> list = new ArrayList<>();

        list.add(10);
        list.add(20);
        list.add(10);

        System.out.println(list.size());

        System.out.println(list);
    }
}
```

**Output:**

```text
3
[10, 20, 10]
```

### Question 2: HashSet

```java
import java.util.HashSet;

public class Test {

    public static void main(String[] args) {

        HashSet<Integer> set = new HashSet<>();

        set.add(10);
        set.add(20);
        set.add(10);

        System.out.println(set.size());
    }
}
```

**Output:**

```text
2
```

### Question 3: TreeSet

```java
import java.util.TreeSet;

public class Test {

    public static void main(String[] args) {

        TreeSet<Integer> set = new TreeSet<>();

        set.add(50);
        set.add(10);
        set.add(30);

        System.out.println(set);
    }
}
```

**Output:**

```text
[10, 30, 50]
```

### Question 4: HashMap

```java
import java.util.HashMap;

public class Test {

    public static void main(String[] args) {

        HashMap<Integer, String> map = new HashMap<>();

        map.put(101, "Anurag");

        map.put(102, "Rahul");

        map.put(101, "Jayraj");

        System.out.println(map.size());

        System.out.println(map.get(101));
    }
}
```

**Output:**

```text
2
Jayraj
```

Reason: Inserting key 101 again replaces its previous value.

### Question 5: Stack

```java
import java.util.Stack;

public class Test {

    public static void main(String[] args) {

        Stack<Integer> stack = new Stack<>();

        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println(stack.pop());

        System.out.println(stack.peek());
    }
}
```

**Output:**

```text
30
20
```

---

# 14. Quick Revision Notes

| Collection | Duplicates | Ordering | Common Implementation |
|---|---|---|---|
| List | Allowed | Insertion order | ArrayList |
| Set | Not allowed | Depends on implementation | HashSet |
| Queue | Depends on implementation | Processing order | PriorityQueue |
| Map | Keys unique | Depends on implementation | HashMap |

### Important Classes

| Class | Important Point |
|---|---|
| ArrayList | Dynamic array |
| LinkedList | Doubly linked list |
| Vector | Synchronized dynamic array |
| Stack | LIFO |
| PriorityQueue | Priority-based processing |
| ArrayDeque | Double-ended queue |
| HashSet | Unique elements |
| LinkedHashSet | Unique elements in insertion order |
| TreeSet | Sorted unique elements |
| HashMap | Key-value pairs |
| LinkedHashMap | Key-value pairs in insertion order |
| TreeMap | Sorted keys |
| Hashtable | Legacy synchronized Map |

### Important Methods

```java
// List
list.add("Java");
list.get(0);
list.set(0, "Python");
list.remove(0);

// Queue
queue.offer(10);
queue.poll();
queue.peek();

// Stack
stack.push(10);
stack.pop();
stack.peek();

// Set
set.add(10);
set.remove(10);
set.contains(10);

// Map
map.put(101, "Anurag");
map.get(101);
map.remove(101);
map.containsKey(101);
```

---

# 15. Practice Checklist

- [ ] Understand Java Collection Framework.
- [ ] Learn Collection hierarchy.
- [ ] Understand Collection interface methods.
- [ ] Practice ArrayList.
- [ ] Practice LinkedList.
- [ ] Understand Vector and Stack.
- [ ] Understand FIFO and LIFO.
- [ ] Practice Queue and PriorityQueue.
- [ ] Practice ArrayDeque.
- [ ] Understand HashSet.
- [ ] Understand LinkedHashSet.
- [ ] Understand TreeSet.
- [ ] Practice HashMap.
- [ ] Understand LinkedHashMap.
- [ ] Understand TreeMap.
- [ ] Differentiate Collection and Collections.
- [ ] Practice Iterator and forEach().
- [ ] Revise interview questions and MCQs.

---

# 16. Additional Practice Assignments

1. **Student Management System:** Store student names and roll numbers using ArrayList.
2. **Unique Mobile Numbers:** Use HashSet to store unique mobile numbers.
3. **Employee Directory:** Store employee IDs and names using HashMap.
4. **Task Management System:** Use Queue to process tasks in FIFO order.
5. **Browser History:** Use Stack or ArrayDeque to demonstrate LIFO operations.
6. **Product Sorting:** Use TreeSet to store unique sorted product prices.
7. **Student Marks:** Use HashMap to store student names and marks.
8. **Priority Task Scheduler:** Use PriorityQueue to process tasks based on priority.

---

## References

- [Oracle Java Collections Framework Tutorial](https://docs.oracle.com/javase/tutorial/collections/)
- [Java 17 Collection Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/util/package-summary.html)
- [Java 17 Collection Interface](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/util/Collection.html)
- [Java 17 Map Interface](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/util/Map.html)

**Note:** This README is prepared for the CMCE August 2026 Batch and covers Session 19 – Collection Framework in Core Java.
