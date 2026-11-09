

# Sessions 22 & 23: Set and Map in Java

**Course:** CDAC CMCE – August 2026 Batch  
**Subject:** Core Java  
**Topics:** Hashing Internals, Set Collection, Map Collection  
**Theory:** 4 Hours | **Lab:** 4 Hours

---

## Table of Contents

1. Introduction to Hashing
2. Hash Functions and `hashCode()`
3. `equals()` and `hashCode()` Contract
4. Internal Bucket Structure (Java 8+)
5. Load Factor, Initial Capacity and Rehashing
6. Set Collection
7. HashSet
8. LinkedHashSet
9. TreeSet
10. Map Collection
11. HashMap
12. LinkedHashMap
13. Hashtable
14. TreeMap
15. Set vs Map
16. Lab 1: Demonstrating Hash Collision
17. Lab 2: Employee HashSet
18. Lab 3: Generics and Wildcards
19. Lab 4: Library Management System Using HashMap
20. Lab 5: Student Ranking System Using TreeMap
21. Lab 6: Unique Visitor Tracker Using HashSet
22. Time Complexity
23. Interview Questions
24. MCQ Practice
25. Quick Revision Notes

---

# 1. Introduction to Hashing

## 1.1 What is Hashing?

Hashing is a technique used to convert an object or key into an integer value using a hash function.

This integer value helps collections locate and organize objects efficiently.

Java uses hashing in collections such as:

- HashMap
- HashSet
- Hashtable
- LinkedHashMap
- LinkedHashSet

### Real-Life Example

Imagine a library containing thousands of books.

Instead of checking every book one by one, the library uses a system to determine where a book should be stored.

Hashing works similarly by calculating a hash value to identify a possible storage location.

### Basic Working

```text
          Object / Key
                |
                v
           hashCode()
                |
                v
           Hash Value
                |
                v
         Bucket Calculation
                |
                v
          Bucket Location
                |
                v
       Store / Search Object
```

### Example

```java
String name = "Anurag";

int hash = name.hashCode();

System.out.println(hash);
```

The `hashCode()` method returns an integer representing the hash code of the object.

**Important:** A hash code is not guaranteed to be unique. Different objects can have the same hash code.

---

# 2. Hash Functions and hashCode()

## 2.1 What is a Hash Function?

A hash function converts input data into a fixed-size integer value.

In Java, every class inherits the `hashCode()` method from the `Object` class.

### Syntax

```java
@Override
public int hashCode() {
    return 100;
}
```

The above method returns the same hash code for every instance of that class.

### Example

```java
class Student {

    int rollNo;

    Student(int rollNo) {
        this.rollNo = rollNo;
    }

    @Override
    public int hashCode() {
        return rollNo;
    }
}

public class HashCodeDemo {

    public static void main(String[] args) {

        Student s1 = new Student(101);
        Student s2 = new Student(102);

        System.out.println(s1.hashCode());
        System.out.println(s2.hashCode());
    }
}
```

**Output:**

```text
101
102
```

## 2.2 Why is hashCode() Important?

Hash-based collections use hash codes to identify where an object or key should be stored.

For example:

- HashMap uses the hash code of keys.
- HashSet uses hashing to manage its elements.
- Hashtable uses hashing for key-value storage.

Without proper hashing, collections may need to compare many objects, reducing performance.

---

# 3. equals() and hashCode() Contract

This is one of the most important topics in Java Collections.

## 3.1 What is equals()?

The `equals()` method compares two objects to determine whether they are logically equal.

By default, the `Object` class implementation compares object identity.

However, we can override it to compare object data.

### Example

```java
class Student {

    int rollNo;

    Student(int rollNo) {
        this.rollNo = rollNo;
    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj) {
            return true;
        }

        if (!(obj instanceof Student)) {
            return false;
        }

        Student other = (Student) obj;

        return this.rollNo == other.rollNo;
    }
}
```

## 3.2 What is the hashCode() Contract?

Java defines important rules for `equals()` and `hashCode()`.

**Rule 1: Equal objects must have equal hash codes.**

If:

```java
obj1.equals(obj2) == true
```

Then:

```java
obj1.hashCode() == obj2.hashCode()
```

**Rule 2: Same hash code does not mean objects are equal.**

Two different objects can have the same hash code.

**Rule 3: Consistency**

If an object's equality-relevant information is not modified, repeated calls to `hashCode()` should return the same value during an execution.

## 3.3 Relationship Between equals() and hashCode()

```text
             Two Objects
                  |
                  v
              hashCode()
                  |
          +-------+-------+
          |               |
      Different         Same
      Hash Codes      Hash Codes
          |               |
          v               v
     Not Equal       equals() Check
                          |
                    +-----+-----+
                    |           |
                   true        false
                    |           |
                    v           v
               Equal Objects  Collision
```

### Important Rule

- If hash codes are different, objects cannot be equal according to a correctly implemented contract.
- If hash codes are equal, `equals()` must be checked.
- Same hash code does not guarantee equality.

## 3.4 Example: Overriding Both Methods

```java
import java.util.Objects;

class Employee {

    int id;
    String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj) {
            return true;
        }

        if (!(obj instanceof Employee)) {
            return false;
        }

        Employee other = (Employee) obj;

        return this.id == other.id;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }
}
```

Here, employee uniqueness depends on employee ID.

Two Employee objects with the same ID are considered equal, even if their names differ.

**Best Practice:** Whenever you override `equals()`, override `hashCode()` consistently.

---

# 4. Internal Bucket Structure (Java 8+)

## 4.1 What is a Bucket?

A bucket is a logical storage location inside a hash-based collection.

HashMap uses an internal array called a table.

Each position in the array represents a bucket.

### Example

```text
HashMap Internal Table

Index       Bucket
  0       -> Node
  1       -> null
  2       -> Node -> Node
  3       -> null
  4       -> Node
  5       -> null
  6       -> Node -> Node -> Node
```

Multiple entries may be stored in the same bucket when collisions occur.

## 4.2 How HashMap Stores Data

Consider:

```java
HashMap<Integer, String> map = new HashMap<>();

map.put(101, "Anurag");
map.put(102, "Rahul");
map.put(103, "Sushant");
```

Conceptually, HashMap performs these operations:

1. Calls `hashCode()` on the key.
2. Applies an internal hash-spreading operation.
3. Calculates a bucket index.
4. Finds the corresponding bucket.
5. Stores the key-value entry.

A simplified Java 8+ bucket index calculation is:

```java
index = (capacity - 1) & hash;
```

The actual HashMap implementation first spreads the hash bits.

### Internal Hash Spreading

Conceptually, Java 8+ HashMap uses:

```java
hash = key.hashCode();

int spreadHash = hash ^ (hash >>> 16);
```

This helps distribute hash bits more effectively.

**Note:** This is an implementation detail of HashMap, not a method application developers normally need to write.

## 4.3 What is Hash Collision?

A collision occurs when two different keys produce the same bucket index.

Example:

```text
Bucket 2

     [Key A | Value A]
              |
              v
     [Key B | Value B]
              |
              v
     [Key C | Value C]
```

Java handles collisions using linked nodes and, under certain conditions, balanced tree nodes.

## 4.4 Linked List and Tree Structure

In Java 8+, HashMap can convert a heavily populated bucket from a linked structure into a balanced red-black tree.

Typical implementation thresholds:

| Constant | Value |
|---|---:|
| TREEIFY_THRESHOLD | 8 |
| UNTREEIFY_THRESHOLD | 6 |
| MIN_TREEIFY_CAPACITY | 64 |

Important details:

- Treeification is considered when a bucket becomes sufficiently populated.
- The table capacity must be at least 64 for treeification.
- Otherwise, HashMap generally resizes instead.
- When tree bins become small enough during certain operations, they may convert back to linked nodes.

### Conceptual Structure

**Linked List Bucket:**

```text
Bucket
  |
  v
[Node] -> [Node] -> [Node] -> [Node]
```

**Tree Bucket:**

```text
             [Node]
             /    \
         [Node]   [Node]
          /          \
       [Node]       [Node]
```

The tree structure improves lookup performance in heavily collided buckets.

---

# 5. Load Factor, Initial Capacity and Rehashing

## 5.1 Initial Capacity

Initial capacity refers to the initial size of the internal hash table.

For a no-argument HashMap, the default initial capacity is 16 when the table is first allocated.

```java
HashMap<Integer, String> map = new HashMap<>();
```

We can also specify capacity:

```java
HashMap<Integer, String> map = new HashMap<>(32);
```

## 5.2 Load Factor

Load factor determines how full a hash table can become before resizing is triggered.

The default load factor of HashMap is `0.75`.

### Formula

```text
Threshold = Capacity × Load Factor
```

Example:

```text
Initial Capacity = 16
Load Factor     = 0.75

Threshold = 16 × 0.75

Threshold = 12
```

When the table reaches its resize threshold, adding another new mapping triggers resizing.

## 5.3 Rehashing and Resizing

Rehashing is the process of redistributing existing entries into a resized hash table.

When HashMap grows, it generally doubles its table capacity.

### Example

```text
Before Resizing

Capacity = 16
Threshold = 12

       16 Buckets
            |
            v
      Resize Triggered
            |
            v
After Resizing

Capacity = 32
Threshold = 24
```

### Why is Resizing Required?

As the number of entries increases, more collisions may occur.

Resizing increases the number of buckets and helps maintain efficient lookup performance.

### Constructor with Capacity and Load Factor

```java
HashMap<Integer, String> map =
        new HashMap<>(32, 0.75f);
```

**Important:** A lower load factor generally reduces collisions but requires more memory. A higher load factor saves memory but can increase collisions.

---

# 6. Set Collection

## 6.1 Introduction

A Set is an interface in Java Collection Framework used to store unique elements.

Unlike List, Set does not allow duplicate elements.

### Features

- Does not allow duplicate elements.
- Supports unique-element storage.
- Ordering depends on implementation.
- Common implementations include HashSet, LinkedHashSet and TreeSet.

### Set Hierarchy

```text
              Iterable
                  |
              Collection
                  |
                 Set
                  |
       +----------+----------+
       |          |          |
    HashSet  LinkedHashSet  SortedSet
                               |
                           NavigableSet
                               |
                            TreeSet
```

---

# 7. HashSet

## 7.1 Introduction

HashSet is an implementation of the Set interface.

It uses hashing internally to store unique elements.

### Features

1. Does not allow duplicates.
2. Allows one null element.
3. Does not guarantee iteration order.
4. Uses hashing internally.
5. Not synchronized.
6. Average O(1) add, remove and contains operations.

### Declaration

```java
HashSet<String> names = new HashSet<>();
```

## 7.2 HashSet Example

```java
import java.util.*;

public class HashSetDemo {

    public static void main(String[] args) {

        HashSet<String> names = new HashSet<>();

        names.add("Anurag");
        names.add("Rahul");
        names.add("Sushant");
        names.add("Anurag");

        System.out.println(names);

        System.out.println("Contains Rahul: " +
                names.contains("Rahul"));

        names.remove("Rahul");

        System.out.println("After Removal: " + names);

        System.out.println("Size: " + names.size());

        for (String name : names) {
            System.out.println(name);
        }
    }
}
```

**Note:** Output order is not guaranteed because HashSet does not maintain insertion order.

### Important Methods

| Method | Description |
|---|---|
| `add()` | Adds element |
| `remove()` | Removes element |
| `contains()` | Checks element |
| `size()` | Returns size |
| `isEmpty()` | Checks empty set |
| `clear()` | Removes all elements |

---

# 8. LinkedHashSet

## 8.1 Introduction

LinkedHashSet is an implementation of Set that maintains insertion order.

It uses hashing for uniqueness and linked connections to maintain iteration order.

### Features

- Does not allow duplicates.
- Maintains insertion order.
- Allows one null element.
- Not synchronized.
- Slightly more memory overhead than HashSet.

### Example

```java
import java.util.*;

public class LinkedHashSetDemo {

    public static void main(String[] args) {

        LinkedHashSet<String> names = new LinkedHashSet<>();

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

The duplicate "Anurag" is ignored, and insertion order is maintained.

---

# 9. TreeSet

## 9.1 Introduction

TreeSet is a sorted implementation of the Set interface.

It stores unique elements in sorted order using a tree-based structure.

It is based on a NavigableSet implementation backed by a TreeMap.

### Features

- Does not allow duplicate elements according to its ordering.
- Maintains sorted order.
- Does not allow null with natural ordering.
- Supports ascending and descending views.
- Operations typically take O(log n).

### Example

```java
import java.util.*;

public class TreeSetDemo {

    public static void main(String[] args) {

        TreeSet<Integer> numbers = new TreeSet<>();

        numbers.add(50);
        numbers.add(10);
        numbers.add(30);
        numbers.add(20);
        numbers.add(10);

        System.out.println("Sorted Set: " + numbers);

        System.out.println("First: " + numbers.first());

        System.out.println("Last: " + numbers.last());

        System.out.println("Lower than 30: " + numbers.lower(30));

        System.out.println("Higher than 30: " + numbers.higher(30));

        System.out.println("Descending: " + numbers.descendingSet());
    }
}
```

**Output:**

```text
Sorted Set: [10, 20, 30, 50]
First: 10
Last: 50
Lower than 30: 20
Higher than 30: 50
Descending: [50, 30, 20, 10]
```

### Important TreeSet Methods

| Method | Description |
|---|---|
| `first()` | Returns smallest element |
| `last()` | Returns largest element |
| `lower()` | Returns greatest element strictly lower |
| `higher()` | Returns smallest element strictly higher |
| `floor()` | Returns greatest element less than or equal |
| `ceiling()` | Returns smallest element greater than or equal |
| `pollFirst()` | Retrieves and removes first element |
| `pollLast()` | Retrieves and removes last element |
| `descendingSet()` | Returns reverse-order view |

---

# 10. Map Collection

## 10.1 Introduction

Map is an interface in Java used to store data in key-value pairs.

Unlike List and Set, Map does not extend the Collection interface.

Each key maps to one value.

### Example

```text
Roll Number     Student Name

101             Anurag
102             Rahul
103             Sushant
```

Here:

- Roll number is the key.
- Student name is the value.

### Features

- Stores key-value pairs.
- Keys must be unique.
- Values can be duplicated.
- Each key maps to at most one value.
- Implementations differ in ordering and null handling.

### Map Hierarchy

```text
                 Map
                  |
       +----------+----------+
       |          |          |
    HashMap   Hashtable   SortedMap
       |                     |
  LinkedHashMap          NavigableMap
                              |
                           TreeMap
```

---

# 11. HashMap

## 11.1 Introduction

HashMap is an implementation of the Map interface that stores key-value pairs using hashing.

### Features

1. Stores key-value pairs.
2. Does not allow duplicate keys.
3. Allows one null key.
4. Allows multiple null values.
5. Does not guarantee iteration order.
6. Not synchronized.
7. Average O(1) put and get operations.

### Declaration

```java
HashMap<Integer, String> students = new HashMap<>();
```

## 11.2 Important HashMap Methods

| Method | Description |
|---|---|
| `put()` | Inserts or updates mapping |
| `get()` | Retrieves value |
| `remove()` | Removes mapping |
| `containsKey()` | Checks key |
| `containsValue()` | Checks value |
| `keySet()` | Returns keys |
| `values()` | Returns values |
| `entrySet()` | Returns key-value entries |
| `getOrDefault()` | Returns value or default |
| `putIfAbsent()` | Inserts only if key is absent |
| `replace()` | Replaces an existing value |
| `size()` | Returns number of mappings |

## 11.3 HashMap Example

```java
import java.util.*;

public class HashMapDemo {

    public static void main(String[] args) {

        HashMap<Integer, String> students = new HashMap<>();

        // Insert
        students.put(101, "Anurag");
        students.put(102, "Rahul");
        students.put(103, "Sushant");

        // Duplicate key updates value
        students.put(101, "Anurag Dhondge");

        System.out.println(students);

        // Retrieve
        System.out.println(students.get(102));

        // Search
        System.out.println(students.containsKey(101));

        // Update
        students.put(102, "Jayraj");

        // Remove
        students.remove(103);

        // Iterate
        for (Map.Entry<Integer, String> entry :
                students.entrySet()) {

            System.out.println(
                    entry.getKey() + " : " + entry.getValue());
        }
    }
}
```

**Note:** HashMap iteration order is not guaranteed, so do not depend on the printed order.

### Important Point

If we insert the same key again, the old value is replaced.

```java
map.put(101, "Anurag");
map.put(101, "Rahul");
```

Now key 101 maps to Rahul.

---

# 12. LinkedHashMap

## 12.1 Introduction

LinkedHashMap is an implementation of HashMap that maintains a predictable iteration order.

By default, it maintains insertion order.

### Features

- Stores key-value pairs.
- Does not allow duplicate keys.
- Allows one null key.
- Allows multiple null values.
- Maintains insertion order by default.
- Not synchronized.

### Example

```java
import java.util.*;

public class LinkedHashMapDemo {

    public static void main(String[] args) {

        LinkedHashMap<Integer, String> students =
                new LinkedHashMap<>();

        students.put(103, "Sushant");
        students.put(101, "Anurag");
        students.put(102, "Rahul");

        for (Map.Entry<Integer, String> entry :
                students.entrySet()) {

            System.out.println(
                    entry.getKey() + " : " + entry.getValue());
        }
    }
}
```

**Output:**

```text
103 : Sushant
101 : Anurag
102 : Rahul
```

Insertion order is maintained.

---

# 13. Hashtable

## 13.1 Introduction

Hashtable is a legacy implementation of the Map interface.

It stores data in key-value pairs and synchronizes its individual methods.

### Features

1. Stores key-value pairs.
2. Does not allow duplicate keys.
3. Does not allow null keys.
4. Does not allow null values.
5. Individual methods are synchronized.
6. Does not guarantee iteration order.
7. Legacy class.

### Example

```java
import java.util.*;

public class HashtableDemo {

    public static void main(String[] args) {

        Hashtable<Integer, String> employees =
                new Hashtable<>();

        employees.put(101, "Anurag");
        employees.put(102, "Rahul");
        employees.put(103, "Sushant");

        System.out.println(employees.get(101));

        employees.remove(102);

        for (Map.Entry<Integer, String> entry :
                employees.entrySet()) {

            System.out.println(
                    entry.getKey() + " : " + entry.getValue());
        }
    }
}
```

### HashMap vs Hashtable

| Feature | HashMap | Hashtable |
|---|---|---|
| Synchronization | No | Yes, individual methods |
| Null key | One allowed | Not allowed |
| Null values | Allowed | Not allowed |
| Legacy | No | Yes |
| Iteration order | Not guaranteed | Not guaranteed |
| Performance | Usually faster without external synchronization | Synchronization overhead |

**Note:** For modern concurrent applications, `ConcurrentHashMap` is generally preferred over Hashtable.

---

# 14. TreeMap

## 14.1 Introduction

TreeMap is a sorted implementation of the Map interface.

It stores key-value pairs in sorted key order.

It uses a Red-Black Tree internally.

### Features

- Stores key-value pairs.
- Does not allow duplicate keys.
- Maintains sorted key order.
- Does not allow null keys with natural ordering.
- Allows null values.
- Not synchronized.
- Operations typically take O(log n).

### Example

```java
import java.util.*;

public class TreeMapDemo {

    public static void main(String[] args) {

        TreeMap<Integer, String> students = new TreeMap<>();

        students.put(103, "Sushant");
        students.put(101, "Anurag");
        students.put(102, "Rahul");

        System.out.println(students);

        System.out.println("First Key: " + students.firstKey());

        System.out.println("Last Key: " + students.lastKey());

        System.out.println("Higher Key: " + students.higherKey(101));

        System.out.println("Descending Map: " +
                students.descendingMap());
    }
}
```

**Output:**

```text
{101=Anurag, 102=Rahul, 103=Sushant}
First Key: 101
Last Key: 103
Higher Key: 102
Descending Map: {103=Sushant, 102=Rahul, 101=Anurag}
```

### Important TreeMap Methods

| Method | Description |
|---|---|
| `firstKey()` | Returns smallest key |
| `lastKey()` | Returns largest key |
| `higherKey()` | Returns next greater key |
| `lowerKey()` | Returns next smaller key |
| `ceilingKey()` | Returns smallest key greater than or equal |
| `floorKey()` | Returns greatest key less than or equal |
| `pollFirstEntry()` | Retrieves and removes first entry |
| `pollLastEntry()` | Retrieves and removes last entry |
| `descendingMap()` | Returns reverse-order view |

---

# 15. Set vs Map

| Feature | Set | Map |
|---|---|---|
| Stores | Individual elements | Key-value pairs |
| Duplicate elements | Not allowed | Keys are unique |
| Values | Elements themselves | Values can repeat |
| Main interface | Set | Map |
| Implementations | HashSet, LinkedHashSet, TreeSet | HashMap, LinkedHashMap, Hashtable, TreeMap |
| Example | Unique student IDs | Student ID → Student details |

### When to Use Which?

**HashSet:** When unique elements are required.

**LinkedHashSet:** When unique elements and insertion order are required.

**TreeSet:** When unique elements must be sorted.

**HashMap:** When key-value lookup is required.

**LinkedHashMap:** When key-value lookup and insertion order are required.

**Hashtable:** When maintaining compatibility with legacy synchronized Map code.

**TreeMap:** When entries must be sorted by key.

---

# 16. Lab 1: Demonstrate Hash Collision

## Problem Statement

Create two different objects having:

- Same hashCode().
- Different equals() results.

Insert both into a HashSet and verify that both objects are stored.

## Concepts Used

- HashSet.
- hashCode().
- equals().
- Hash collision.
- Object class methods.

## Program

```java
import java.util.*;

class Student {

    int rollNo;

    Student(int rollNo) {
        this.rollNo = rollNo;
    }

    @Override
    public int hashCode() {
        return 100;
    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj) {
            return true;
        }

        if (!(obj instanceof Student)) {
            return false;
        }

        Student other = (Student) obj;

        return this.rollNo == other.rollNo;
    }

    @Override
    public String toString() {
        return "Student Roll No: " + rollNo;
    }
}

public class HashCollisionDemo {

    public static void main(String[] args) {

        HashSet<Student> students = new HashSet<>();

        Student s1 = new Student(101);
        Student s2 = new Student(102);

        students.add(s1);
        students.add(s2);

        System.out.println("HashCode S1: " + s1.hashCode());
        System.out.println("HashCode S2: " + s2.hashCode());

        System.out.println("Are Equal: " + s1.equals(s2));

        System.out.println("Set Size: " + students.size());

        System.out.println(students);
    }
}
```

### Output

```text
HashCode S1: 100
HashCode S2: 100
Are Equal: false
Set Size: 2
[Student Roll No: 101, Student Roll No: 102]
```

### Explanation

Both objects return the same hash code, 100.

However, their roll numbers are different, so `equals()` returns false.

HashSet uses hashing to locate the bucket and `equals()` to check whether an equivalent element already exists.

Therefore, both objects are stored.

**Conclusion:** Hash collision does not mean duplicate object.

---

# 17. Lab 2: Employee HashSet with equals() and hashCode()

## Problem Statement

Create an Employee class and store employee objects in a HashSet.

Override `equals()` and `hashCode()` to maintain uniqueness based on employee ID.

## Program

```java
import java.util.*;
import java.util.Objects;

class Employee {

    private int id;
    private String name;
    private double salary;

    public Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj) {
            return true;
        }

        if (!(obj instanceof Employee)) {
            return false;
        }

        Employee other = (Employee) obj;

        return this.id == other.id;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }

    @Override
    public String toString() {
        return id + " " + name + " " + salary;
    }
}

public class EmployeeHashSetDemo {

    public static void main(String[] args) {

        HashSet<Employee> employees = new HashSet<>();

        employees.add(new Employee(101, "Anurag", 45000));
        employees.add(new Employee(102, "Rahul", 50000));
        employees.add(new Employee(101, "Anurag", 45000));
        employees.add(new Employee(103, "Sushant", 55000));

        System.out.println("Employee Records:");

        for (Employee employee : employees) {
            System.out.println(employee);
        }

        System.out.println("Total Employees: " + employees.size());
    }
}
```

### Expected Output

```text
Employee Records:
101 Anurag 45000.0
102 Rahul 50000.0
103 Sushant 55000.0
Total Employees: 3
```

The iteration order is not guaranteed.

### Explanation

- Employee ID is used for equality.
- Two employees with the same ID are considered equal.
- `hashCode()` uses the same ID field.
- HashSet prevents duplicate logical employee entries.

**Important:** Fields used in `equals()` and `hashCode()` should not be changed while an object is stored in a HashSet or used as a HashMap key. Otherwise, lookup and removal may behave unexpectedly.

---

# 18. Lab 3: Generics and Wildcards

## Problem Statement

Create a Sample class to understand generic assignments using:

1. `? extends SomeClass`
2. `? super SomeClass`
3. `?`

## 18.1 Introduction to Wildcards

A wildcard is represented by the question mark `?`.

It is used when the exact generic type is unknown.

There are three important wildcard forms.

### 1. Unbounded Wildcard: ?

```java
List<?> list;
```

It means a List of an unknown type.

You can read elements as Object, but cannot safely add ordinary non-null values.

### 2. Upper Bounded Wildcard: ? extends Type

```java
List<? extends Number> list;
```

It means a List of Number or one of its subclasses.

Examples:

```java
List<Integer> numbers = new ArrayList<>();
List<Double> decimals = new ArrayList<>();
```

Both can be assigned to:

```java
List<? extends Number> values;
```

Useful when you primarily want to read values.

### 3. Lower Bounded Wildcard: ? super Type

```java
List<? super Integer> list;
```

It means a List of Integer or one of its supertypes.

Examples:

```java
List<Integer> a = new ArrayList<>();
List<Number> b = new ArrayList<>();
List<Object> c = new ArrayList<>();
```

All can be assigned to:

```java
List<? super Integer> values;
```

Useful when you want to add Integer values.

## 18.2 PECS Rule

PECS stands for:

**Producer Extends, Consumer Super.**

- Use `? extends T` when a structure produces values that you want to read as T.
- Use `? super T` when a structure consumes values of type T.

## 18.3 Complete Program

```java
import java.util.*;

class Sample {

    // Unbounded wildcard
    public static void display(List<?> list) {

        for (Object obj : list) {
            System.out.println(obj);
        }
    }

    // Upper bounded wildcard
    public static double calculateSum(
            List<? extends Number> numbers) {

        double sum = 0;

        for (Number number : numbers) {
            sum += number.doubleValue();
        }

        return sum;
    }

    // Lower bounded wildcard
    public static void addNumbers(
            List<? super Integer> list) {

        list.add(10);
        list.add(20);
        list.add(30);
    }

    public static void main(String[] args) {

        List<String> names =
                Arrays.asList("Anurag", "Rahul", "Sushant");

        System.out.println("Unbounded Wildcard:");
        display(names);

        List<Integer> numbers =
                Arrays.asList(10, 20, 30);

        System.out.println("\nUpper Bounded Wildcard:");
        System.out.println("Sum: " + calculateSum(numbers));

        List<Number> values = new ArrayList<>();

        System.out.println("\nLower Bounded Wildcard:");
        addNumbers(values);

        System.out.println(values);
    }
}
```

### Output

```text
Unbounded Wildcard:
Anurag
Rahul
Sushant

Upper Bounded Wildcard:
Sum: 60.0

Lower Bounded Wildcard:
[10, 20, 30]
```

### Comparison

| Wildcard | Syntax | Purpose |
|---|---|---|
| Unbounded | `<?>` | Unknown type |
| Upper bounded | `<? extends T>` | T or its subclasses |
| Lower bounded | `<? super T>` | T or its superclasses |

---

# 19. Lab 4: Library Management System Using HashMap

## Problem Statement

Implement a Library Management System using HashMap.

Maintain:

```text
Book ID → Book Details
```

The application should support:

1. Add Book.
2. Search Book.
3. Update Book Details.
4. Delete Book.

## Concepts Used

- HashMap.
- Key-value pairs.
- User-defined classes.
- CRUD operations.
- Searching by key.
- Iteration using entrySet().

## Complete Java Program

```java
import java.util.*;

class Book {

    private int bookId;
    private String title;
    private String author;
    private double price;

    public Book(int bookId, String title,
                String author, double price) {

        this.bookId = bookId;
        this.title = title;
        this.author = author;
        this.price = price;
    }

    public void updateDetails(String title,
                              String author, double price) {

        this.title = title;
        this.author = author;
        this.price = price;
    }

    @Override
    public String toString() {

        return "Book ID: " + bookId +
                ", Title: " + title +
                ", Author: " + author +
                ", Price: " + price;
    }
}

public class LibraryManagementSystem {

    private static final HashMap<Integer, Book> books =
            new HashMap<>();

    private static final Scanner sc = new Scanner(System.in);

    private static void addBook() {

        System.out.print("Enter Book ID: ");
        int id = Integer.parseInt(sc.nextLine());

        if (books.containsKey(id)) {
            System.out.println("Book ID already exists.");
            return;
        }

        System.out.print("Enter Title: ");
        String title = sc.nextLine();

        System.out.print("Enter Author: ");
        String author = sc.nextLine();

        System.out.print("Enter Price: ");
        double price = Double.parseDouble(sc.nextLine());

        Book book = new Book(id, title, author, price);

        books.put(id, book);

        System.out.println("Book added successfully.");
    }

    private static void searchBook() {

        System.out.print("Enter Book ID: ");
        int id = Integer.parseInt(sc.nextLine());

        Book book = books.get(id);

        if (book != null) {
            System.out.println(book);
        } else {
            System.out.println("Book not found.");
        }
    }

    private static void updateBook() {

        System.out.print("Enter Book ID: ");
        int id = Integer.parseInt(sc.nextLine());

        Book book = books.get(id);

        if (book != null) {

            System.out.print("Enter New Title: ");
            String title = sc.nextLine();

            System.out.print("Enter New Author: ");
            String author = sc.nextLine();

            System.out.print("Enter New Price: ");
            double price = Double.parseDouble(sc.nextLine());

            book.updateDetails(title, author, price);

            System.out.println("Book updated successfully.");

        } else {
            System.out.println("Book not found.");
        }
    }

    private static void deleteBook() {

        System.out.print("Enter Book ID: ");
        int id = Integer.parseInt(sc.nextLine());

        if (books.containsKey(id)) {

            books.remove(id);

            System.out.println("Book deleted successfully.");

        } else {
            System.out.println("Book not found.");
        }
    }

    private static void displayBooks() {

        if (books.isEmpty()) {
            System.out.println("No books available.");
            return;
        }

        for (Map.Entry<Integer, Book> entry :
                books.entrySet()) {

            System.out.println(
                    entry.getKey() + " : " + entry.getValue());
        }
    }

    public static void main(String[] args) {

        while (true) {

            System.out.println("\n--- LIBRARY MANAGEMENT ---");
            System.out.println("1. Add Book");
            System.out.println("2. Search Book");
            System.out.println("3. Update Book");
            System.out.println("4. Delete Book");
            System.out.println("5. Display Books");
            System.out.println("6. Exit");

            System.out.print("Enter Choice: ");
            int choice = Integer.parseInt(sc.nextLine());

            switch (choice) {

                case 1:
                    addBook();
                    break;

                case 2:
                    searchBook();
                    break;

                case 3:
                    updateBook();
                    break;

                case 4:
                    deleteBook();
                    break;

                case 5:
                    displayBooks();
                    break;

                case 6:
                    System.out.println("Exiting...");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
```

### Sample Output

```text
--- LIBRARY MANAGEMENT ---
1. Add Book
2. Search Book
3. Update Book
4. Delete Book
5. Display Books
6. Exit

Enter Choice: 1
Enter Book ID: 101
Enter Title: Java Programming
Enter Author: James Gosling
Enter Price: 550

Book added successfully.

Enter Choice: 2
Enter Book ID: 101

Book ID: 101, Title: Java Programming,
Author: James Gosling, Price: 550.0
```

### Explanation

The HashMap stores Book ID as the key and Book object as the value.

```java
HashMap<Integer, Book> books = new HashMap<>();
```

- `put(id, book)` adds a book.
- `get(id)` searches for a book.
- `containsKey(id)` checks whether a book ID exists.
- `remove(id)` deletes a book.
- `entrySet()` iterates over key-value pairs.

---

# 20. Lab 5: Student Ranking System Using TreeMap

## Problem Statement

Implement a Student Ranking System using TreeMap.

Requirements:

1. Store student marks using TreeMap.
2. Display records sorted by roll number.
3. Generate rank list based on marks.

## Concepts Used

- TreeMap.
- SortedMap.
- Key-value pairs.
- Comparator.
- Sorting.
- Ranking logic.

## Complete Java Program

```java
import java.util.*;

public class StudentRankingSystem {

    public static void main(String[] args) {

        TreeMap<Integer, Integer> students = new TreeMap<>();

        // Roll Number -> Marks
        students.put(103, 85);
        students.put(101, 95);
        students.put(105, 75);
        students.put(102, 90);
        students.put(104, 95);

        // Display sorted by roll number
        System.out.println("--- Records by Roll Number ---");

        for (Map.Entry<Integer, Integer> entry :
                students.entrySet()) {

            System.out.println(
                    "Roll No: " + entry.getKey() +
                    ", Marks: " + entry.getValue());
        }

        // Generate rank list by marks descending
        List<Map.Entry<Integer, Integer>> rankList =
                new ArrayList<>(students.entrySet());

        rankList.sort(
                Map.Entry.<Integer, Integer>comparingByValue()
                        .reversed()
        );

        System.out.println("\n--- Student Rank List ---");

        int rank = 0;

        for (Map.Entry<Integer, Integer> entry : rankList) {

            rank++;

            System.out.println(
                    "Rank: " + rank +
                    ", Roll No: " + entry.getKey() +
                    ", Marks: " + entry.getValue());
        }
    }
}
```

### Output

```text
--- Records by Roll Number ---
Roll No: 101, Marks: 95
Roll No: 102, Marks: 90
Roll No: 103, Marks: 85
Roll No: 104, Marks: 95
Roll No: 105, Marks: 75

--- Student Rank List ---
Rank: 1, Roll No: 101, Marks: 95
Rank: 2, Roll No: 104, Marks: 95
Rank: 3, Roll No: 102, Marks: 90
Rank: 4, Roll No: 103, Marks: 85
Rank: 5, Roll No: 105, Marks: 75
```

### Explanation

TreeMap automatically sorts the records according to roll number because roll number is used as the key.

For ranking, we copy the entries into an ArrayList and sort them by marks in descending order.

**Important:** This example assigns sequential positions even when marks are tied. If you need competition ranking (1, 1, 3) or dense ranking (1, 1, 2), additional ranking logic is required.

---

# 21. Lab 6: Unique Visitor Tracker Using HashSet

## Problem Statement

Implement a Unique Visitor Tracker using HashSet.

Requirements:

1. Store unique visitor IDs.
2. Prevent duplicate entries.
3. Display total unique visitors.
4. Display all visitor IDs.

## Program

```java
import java.util.*;

public class UniqueVisitorTracker {

    public static void main(String[] args) {

        HashSet<Integer> visitors = new HashSet<>();

        visitors.add(101);
        visitors.add(102);
        visitors.add(103);
        visitors.add(101);
        visitors.add(104);
        visitors.add(102);

        System.out.println("Unique Visitor IDs:");

        for (Integer id : visitors) {
            System.out.println(id);
        }

        System.out.println(
                "Total Unique Visitors: " + visitors.size());

        // Check visitor
        int visitorId = 101;

        if (visitors.contains(visitorId)) {
            System.out.println("Visitor already exists.");
        } else {
            visitors.add(visitorId);
        }
    }
}
```

### Expected Output

```text
Unique Visitor IDs:
101
102
103
104

Total Unique Visitors: 4
Visitor already exists.
```

**Note:** The actual iteration order of HashSet is not guaranteed.

### Explanation

HashSet automatically prevents duplicate elements.

When an existing visitor ID is added again, it does not create another entry.

The `size()` method returns the number of unique visitor IDs.

---

# 22. Time Complexity

| Collection | Add / Put | Search / Get | Remove | Ordering |
|---|---|---|---|---|
| HashSet | O(1) average | O(1) average | O(1) average | No guaranteed order |
| LinkedHashSet | O(1) average | O(1) average | O(1) average | Insertion order |
| TreeSet | O(log n) | O(log n) | O(log n) | Sorted |
| HashMap | O(1) average | O(1) average | O(1) average | No guaranteed order |
| LinkedHashMap | O(1) average | O(1) average | O(1) average | Insertion order by default |
| Hashtable | O(1) average | O(1) average | O(1) average | No guaranteed order |
| TreeMap | O(log n) | O(log n) | O(log n) | Sorted by key |

**Note:** Hash-based complexity assumes a reasonably distributed hash function. Heavy collisions can degrade performance. Tree bins in modern HashMap help with certain collision-heavy cases.

---

# 23. Interview Questions

## Hashing Internals

**1. What is hashing in Java?**

Hashing converts an object or key into an integer hash value to help locate entries efficiently.

**2. What is hashCode()?**

It is a method of Object that returns an integer hash code for an object.

**3. What is equals()?**

It compares two objects for logical equality.

**4. What is a hash collision?**

A collision occurs when two different keys map to the same bucket.

**5. Can two objects have the same hashCode()?**

Yes. Different objects can have the same hash code.

**6. If two objects are equal, must their hash codes be equal?**

Yes.

**7. If two objects have the same hash code, must they be equal?**

No.

**8. What is a bucket?**

A bucket is a logical storage location in a hash table.

**9. What is the default HashMap initial capacity?**

16 when its internal table is first allocated.

**10. What is the default HashMap load factor?**

0.75.

**11. What is rehashing?**

Redistributing entries after the hash table is resized.

**12. What is a collision-resolution technique used in HashMap?**

Linked-node chains and, under suitable conditions, red-black tree bins.

**13. What is treeification?**

Converting a heavily populated bucket into a tree-based structure.

**14. What is the Java 8 HashMap treeification threshold?**

8 nodes, subject to the table-capacity condition.

**15. What is the minimum capacity for treeification?**

64.

## Set Collection

**16. What is Set?**

Set is an interface that stores unique elements.

**17. What is HashSet?**

A hash-based implementation of Set.

**18. Does HashSet maintain insertion order?**

No.

**19. What is LinkedHashSet?**

A Set implementation that maintains insertion order.

**20. What is TreeSet?**

A sorted Set implementation.

**21. Does HashSet allow null?**

Yes, it allows one null element.

**22. Does TreeSet allow null?**

Not with natural ordering.

**23. How does HashSet maintain uniqueness?**

It uses hashing and equality checking.

## Map Collection

**24. What is Map?**

An interface that stores key-value pairs.

**25. Does Map extend Collection?**

No.

**26. Can HashMap have duplicate keys?**

No. A new value replaces the previous value for an equal key.

**27. Can HashMap contain null?**

It allows one null key and multiple null values.

**28. What is LinkedHashMap?**

A HashMap implementation that maintains insertion order by default.

**29. What is Hashtable?**

A legacy synchronized Map implementation that does not allow null keys or values.

**30. What is TreeMap?**

A sorted Map implementation backed by a Red-Black Tree.

**31. What is the difference between HashMap and TreeMap?**

HashMap does not guarantee order, while TreeMap sorts entries by key.

**32. Which Map is preferred for modern concurrent access?**

ConcurrentHashMap is generally preferred over Hashtable for concurrent applications.

---

# 24. MCQ Practice

**1. Which method returns an integer hash value?**

A. equals()  
B. hashCode()  
C. compareTo()  
D. toString()

**Answer:** B. hashCode()

**2. If two objects are equal, their hash codes must be:**

A. Different  
B. Equal  
C. Null  
D. Zero

**Answer:** B. Equal

**3. Can two unequal objects have the same hash code?**

A. Yes  
B. No  
C. Only in HashMap  
D. Only in HashSet

**Answer:** A. Yes

**4. What is the default HashMap load factor?**

A. 0.25  
B. 0.50  
C. 0.75  
D. 1.00

**Answer:** C. 0.75

**5. Which Set maintains insertion order?**

A. HashSet  
B. TreeSet  
C. LinkedHashSet  
D. SortedSet

**Answer:** C. LinkedHashSet

**6. Which Set stores elements in sorted order?**

A. HashSet  
B. TreeSet  
C. LinkedHashSet  
D. ArrayList

**Answer:** B. TreeSet

**7. Which Map maintains insertion order by default?**

A. HashMap  
B. TreeMap  
C. Hashtable  
D. LinkedHashMap

**Answer:** D. LinkedHashMap

**8. Which Map stores entries sorted by keys?**

A. HashMap  
B. TreeMap  
C. Hashtable  
D. LinkedHashMap

**Answer:** B. TreeMap

**9. Which Map does not allow null keys or values?**

A. HashMap  
B. LinkedHashMap  
C. Hashtable  
D. TreeMap

**Answer:** C. Hashtable

**10. Which collection is best for storing unique visitor IDs?**

A. ArrayList  
B. HashSet  
C. HashMap  
D. Vector

**Answer:** B. HashSet

**11. Which collection is best for storing Book ID → Book Details?**

A. HashMap  
B. HashSet  
C. TreeSet  
D. LinkedList

**Answer:** A. HashMap

**12. Which wildcard accepts a type or its subclasses?**

A. `? super T`  
B. `? extends T`  
C. `?`  
D. `T extends ?`

**Answer:** B. `? extends T`

**13. Which wildcard is useful when adding values of type T?**

A. `? extends T`  
B. `? super T`  
C. `?`  
D. None

**Answer:** B. `? super T`

**14. What is the default initial capacity of a no-argument HashMap?**

A. 8  
B. 10  
C. 16  
D. 32

**Answer:** C. 16

**15. Which data structure backs TreeMap?**

A. Hash Table  
B. Array  
C. Red-Black Tree  
D. Linked List

**Answer:** C. Red-Black Tree

---

# 25. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Hashing | Converts input into a hash value |
| hashCode() | Returns integer hash code |
| equals() | Checks logical equality |
| Collision | Different keys map to same bucket |
| Bucket | Storage location in hash table |
| Load Factor | Controls resizing threshold |
| Default Load Factor | 0.75 |
| Default HashMap Capacity | 16 |
| Rehashing | Redistributing entries after resizing |
| HashSet | Unique elements, no guaranteed order |
| LinkedHashSet | Unique elements, insertion order |
| TreeSet | Unique sorted elements |
| HashMap | Key-value pairs, no guaranteed order |
| LinkedHashMap | Key-value pairs, insertion order by default |
| Hashtable | Legacy synchronized Map |
| TreeMap | Sorted keys |
| `?` | Unbounded wildcard |
| `? extends T` | Upper bounded wildcard |
| `? super T` | Lower bounded wildcard |

---

## Practical Checklist

- [ ] Understand hashing and hash functions.
- [ ] Understand `hashCode()` and `equals()` contract.
- [ ] Understand collision handling.
- [ ] Learn internal bucket structure in Java 8+.
- [ ] Understand initial capacity and load factor.
- [ ] Understand resizing and rehashing.
- [ ] Practice HashSet.
- [ ] Practice LinkedHashSet.
- [ ] Practice TreeSet.
- [ ] Practice HashMap.
- [ ] Practice LinkedHashMap.
- [ ] Practice Hashtable.
- [ ] Practice TreeMap.
- [ ] Complete Hash Collision demonstration.
- [ ] Complete Employee HashSet program.
- [ ] Practice generic wildcards.
- [ ] Complete Library Management System.
- [ ] Complete Student Ranking System.
- [ ] Complete Unique Visitor Tracker.

## Additional Practice Assignments

1. Create a Product Inventory System using HashMap.
2. Store unique email IDs using HashSet.
3. Create a phone directory using LinkedHashMap.
4. Store employee records sorted by employee ID using TreeMap.
5. Find duplicate words in a paragraph using HashMap.
6. Count character frequencies using HashMap.
7. Sort a list of Employee objects by salary using Comparator.
8. Find common elements between two HashSets.
9. Create a student result system with roll number and marks.
10. Demonstrate collision using custom Employee objects.

---

## Recommended Folder Structure

```text
Java/
└── Sessions-22-23-Set-Map/
    ├── README.md
    └── programs/
        ├── HashCodeDemo.java
        ├── HashCollisionDemo.java
        ├── EmployeeHashSetDemo.java
        ├── HashSetDemo.java
        ├── LinkedHashSetDemo.java
        ├── TreeSetDemo.java
        ├── HashMapDemo.java
        ├── LinkedHashMapDemo.java
        ├── HashtableDemo.java
        ├── TreeMapDemo.java
        ├── Sample.java
        ├── LibraryManagementSystem.java
        ├── StudentRankingSystem.java
        └── UniqueVisitorTracker.java
```

---

**End of Sessions 22 & 23 – Set and Map in Java**

*These notes cover the CMCE August 2026 syllabus, Java 8+ hashing internals, Java 17 examples and practical assignments.*

