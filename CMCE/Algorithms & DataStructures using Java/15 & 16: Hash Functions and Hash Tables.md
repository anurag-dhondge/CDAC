# Sessions 15 & 16: Hash Functions and Hash Tables

**Course:** Algorithms and Data Structures Using Java  
**Program:** PGCP-AC – August 2026  
**Institute:** ACTS, Pune  
**Duration:** 4 Theory + 4 Lab Hours

---

# 1. Introduction to Hashing

**Hashing** is a technique used to store and retrieve data efficiently by converting a key into an index of an array using a hash function.

Hashing provides fast insertion, searching, and deletion operations.

### Real-Life Applications

- Database indexing
- Password storage (using cryptographic hashing)
- Caching systems
- Dictionaries and maps
- Compiler symbol tables
- Duplicate detection
- Data lookup systems

### Example

Suppose we want to store the following keys:

```text
10, 20, 30, 40, 50
```

A hash function calculates an index for each key.

For example, if the table size is 10:

```text
Key     Index
10      0
20      0
30      0
40      0
50      0
```

This example intentionally produces collisions to illustrate the concept.

---

# 2. Introduction to Hash Tables

A **Hash Table** is a data structure that stores data in an array using a hash function.

It stores data in key-value pairs or stores keys directly, depending on the implementation.

### Basic Structure

```text
        Key
         |
         v
    Hash Function
         |
         v
      Index
         |
         v
    Hash Table
```

### Example

Suppose the hash table size is 7 and the keys are:

```text
10, 20, 15, 7
```

Using a modulo-based hash function:

| Key | Calculated Index |
|---|---:|
| 10 | 3 |
| 20 | 6 |
| 15 | 1 |
| 7 | 0 |

Hash table:

```text
Index      Value
----------------
  0          7
  1          15
  2          -
  3          10
  4          -
  5          -
  6          20
```

### Important Terms

| Term | Meaning |
|---|---|
| Hashing | Converting a key into an array index |
| Hash Table | Array-based data structure used to store keys or key-value pairs |
| Hash Function | Function that calculates the index |
| Key | Value used to identify a record |
| Hash Value | Result produced by the hash function |
| Bucket | Location in the hash table |
| Collision | When different keys map to the same index |
| Load Factor | Ratio of stored elements to table capacity |

### Load Factor

Load factor indicates how full a hash table is.

\[
\text{Load Factor} = \frac{\text{Number of Elements}}{\text{Table Size}}
\]

Example:

- Number of elements = 5
- Table size = 10

Load factor = 5 / 10 = 0.5

A high load factor can increase collisions, especially in open-addressed hash tables.

---

# 3. Hash Functions

A **Hash Function** is a mathematical function that converts a key into an index of a hash table.

A good hash function should:

1. Be fast to calculate.
2. Distribute keys uniformly.
3. Minimize collisions.
4. Always generate a valid table index.
5. Produce the same result for the same key and table configuration.

### General Representation

```text
Key → Hash Function → Hash Index
```

For a table of size `m`, the index must be between `0` and `m - 1`.

---

# 4. Different Types of Hash Functions

## 4.1 Division Method (Modulo Method)

The division method calculates the remainder after dividing the key by the table size.

Formula:

\[
h(k) = k \bmod m
\]

Where:
- `k` = Key
- `m` = Hash table size
- `h(k)` = Hash index

### Example

Let:

```text
Key = 25
Table Size = 7
```

Calculation:

```text
25 % 7 = 4
```

Therefore, the hash index is 4.

### Java Implementation

```java
public class DivisionHash {

    static int hash(int key, int size) {

        return Math.floorMod(key, size);
    }

    public static void main(String[] args) {

        int key = 25;

        int size = 7;

        System.out.println(hash(key, size));
    }
}
```

Output:

```text
4
```

**Note:** `Math.floorMod()` also handles negative integer keys safely.

## 4.2 Multiplication Method

The multiplication method multiplies the key by a constant fractional value and uses the fractional part to calculate the index.

Formula:

\[
h(k) = \lfloor m \times (kA \bmod 1) \rfloor
\]

Where:
- `k` = Key
- `m` = Table size
- `A` = Constant between 0 and 1
- `floor` = Greatest integer less than or equal to the value

### Example

Suppose:

```text
k = 25
m = 10
A = 0.618
```

Calculation:

```text
25 × 0.618 = 15.45

Fractional part = 0.45

10 × 0.45 = 4.5

Floor(4.5) = 4
```

Hash index = 4.

## 4.3 Mid-Square Method

In the Mid-Square method:

1. Square the key.
2. Extract the middle digits.
3. Use the extracted digits as the hash index, adjusting to the table size if required.

### Example

```text
Key = 25

Square = 25 × 25 = 625

Middle digit = 2
```

For a table with a suitable index range, the extracted middle digits are used as the hash value.

## 4.4 Folding Method

In the Folding method, the key is divided into smaller parts.

These parts are added together to generate the hash value.

### Example

Suppose:

```text
Key = 123456789
```

Divide into groups:

```text
123 + 456 + 789 = 1368
```

For a table size of 100:

```text
1368 % 100 = 68
```

Hash index = 68.

## 4.5 Digit Extraction Method

In this method, selected digits from the key are extracted to calculate the hash index.

Example:

```text
Key = 987654
Selected digits = 876
```

The selected digits are converted into a valid table index, usually by applying the table-size constraint.

### Comparison of Hash Functions

| Hash Function | Working Principle |
|---|---|
| Division | Uses remainder after division |
| Multiplication | Multiplies key by a constant |
| Mid-Square | Squares key and extracts middle digits |
| Folding | Divides key into parts and adds them |
| Digit Extraction | Selects specific digits from key |

---

# 5. Collision in Hashing

A **Collision** occurs when two or more different keys generate the same hash table index.

### Example

Suppose the table size is 7.

Consider keys:

```text
10, 17, 24
```

Their calculated indices are:

```text
10 % 7 = 3

17 % 7 = 3

24 % 7 = 3
```

All three keys map to index 3.

This is called a collision.

### Why Do Collisions Occur?

- Limited table size.
- Large number of possible keys.
- Different keys can produce the same hash value.
- Poorly designed hash functions.

### Collision Resolution Techniques

Common collision resolution techniques include:

1. Linear Probing
2. Quadratic Probing
3. Double Hashing
4. Separate Chaining

---

# 6. Linear Probing

**Linear Probing** is an open-addressing collision resolution technique.

When a collision occurs, the next available slot is searched sequentially.

Formula:

\[
h_i(k) = (h(k) + i) \bmod m
\]

Where:
- `h(k)` = Original hash index
- `i` = Probe number (0, 1, 2, ...)
- `m` = Table size

### Example

Table size = 7

Keys:

```text
10, 17, 24
```

Initial hash index:

```text
10 % 7 = 3
17 % 7 = 3
24 % 7 = 3
```

### Insertion Process

**Insert 10**

Index 3 is empty.

```text
Index 3 → 10
```

**Insert 17**

Index 3 is occupied.

Check next index 4.

```text
Index 4 → 17
```

**Insert 24**

Index 3 is occupied.

Check index 4. It is also occupied.

Check index 5.

```text
Index 5 → 24
```

Final Hash Table:

```text
Index      Value
----------------
  0          -
  1          -
  2          -
  3          10
  4          17
  5          24
  6          -
```

### Advantages

- Simple to implement.
- No additional linked-list memory required.
- Good cache performance.

### Disadvantages

- Causes primary clustering.
- Consecutive occupied slots can form long clusters.
- Searching can become slower when the table is crowded.

**Primary Clustering:** Formation of groups of consecutive occupied slots in a hash table.

---

# 7. Quadratic Probing

Quadratic Probing is an open-addressing collision resolution technique that uses a quadratic function to calculate the next position.

Instead of checking consecutive positions, it checks positions based on squared probe numbers.

Formula:

\[
h_i(k) = (h(k) + c_1i + c_2i^2) \bmod m
\]

A common simplified version is:

\[
h_i(k) = (h(k) + i^2) \bmod m
\]

Where:
- `i` = Probe number
- `m` = Table size
- `c1` and `c2` = Constants

### Example

Table size = 7

Keys:

```text
10, 17, 24
```

Original hash index:

```text
10 % 7 = 3
17 % 7 = 3
24 % 7 = 3
```

**Insert 10**

Index 3 is empty.

```text
Index 3 → 10
```

**Insert 17**

Index 3 is occupied.

For `i = 1`:

```text
(3 + 1²) % 7 = 4
```

```text
Index 4 → 17
```

**Insert 24**

Index 3 is occupied.

For `i = 1`:

```text
(3 + 1²) % 7 = 4
```

Index 4 is occupied.

For `i = 2`:

```text
(3 + 2²) % 7 = 0
```

```text
Index 0 → 24
```

Final Hash Table:

```text
Index      Value
----------------
  0          24
  1          -
  2          -
  3          10
  4          17
  5          -
  6          -
```

### Advantages

- Reduces primary clustering compared with linear probing.
- Does not check every consecutive slot.

### Disadvantages

- May cause secondary clustering.
- May not visit every table position.
- Table size and constants must be selected carefully.

**Secondary Clustering:** Different keys with the same initial hash index follow the same probing sequence.

---

# 8. Double Hashing

Double Hashing is an open-addressing collision resolution technique that uses two hash functions.

The first hash function calculates the initial index.

The second hash function calculates the step size when a collision occurs.

Formula:

\[
h_i(k) = (h_1(k) + i \times h_2(k)) \bmod m
\]

Where:
- `h1(k)` = First hash function
- `h2(k)` = Second hash function
- `i` = Probe number
- `m` = Table size

### Example

Suppose:

```text
Table Size = 7

h1(k) = k % 7

h2(k) = 1 + (k % 5)
```

Insert keys:

```text
10, 17, 24
```

**Insert 10**

```text
h1(10) = 3
```

Index 3 is empty.

```text
Index 3 → 10
```

**Insert 17**

```text
h1(17) = 3

h2(17) = 1 + (17 % 5)
       = 3
```

Index 3 is occupied.

For `i = 1`:

```text
(3 + 1 × 3) % 7 = 6
```

```text
Index 6 → 17
```

**Insert 24**

```text
h1(24) = 3

h2(24) = 1 + (24 % 5)
       = 5
```

Index 3 is occupied.

For `i = 1`:

```text
(3 + 1 × 5) % 7 = 1
```

```text
Index 1 → 24
```

Final Hash Table:

```text
Index      Value
----------------
  0          -
  1          24
  2          -
  3          10
  4          -
  5          -
  6          17
```

### Advantages

- Reduces primary and secondary clustering.
- Provides a more independent probing sequence.
- Can distribute keys more uniformly.

### Disadvantages

- More complex to implement.
- Requires two hash functions.
- The second hash function must generate a suitable non-zero step size.
- Poor choices of table size and step size may prevent some slots from being visited.

**Important:** For a table of prime size, a non-zero step smaller than the table size is relatively easy to choose so that the probing sequence can visit every slot.

---

# 9. Comparison of Collision Resolution Techniques

| Technique | Working Principle | Clustering |
|---|---|---|
| Linear Probing | Checks next consecutive slot | Primary clustering |
| Quadratic Probing | Uses quadratic increments | Secondary clustering |
| Double Hashing | Uses a second hash function for step size | Reduces both primary and secondary clustering |
| Separate Chaining | Stores multiple keys in a linked list or bucket | No probing clusters |

### Open Addressing vs Separate Chaining

| Open Addressing | Separate Chaining |
|---|---|
| All keys are stored in the table array. | Each index can hold a collection of keys. |
| Uses probing to resolve collisions. | Uses linked lists or other collections. |
| Load factor is normally kept below 1. | Load factor can exceed 1. |
| Deletion needs special handling. | Deletion removes an item from its bucket. |
| Examples: Linear, Quadratic, Double Hashing. | Example: Linked-list chaining. |

---

# 10. Separate Chaining

Separate Chaining is a collision resolution technique in which each hash table index stores a collection of elements.

A linked list is commonly used for each bucket.

### Example

Table size = 7

Keys:

```text
10, 17, 24
```

All three keys map to index 3.

Using separate chaining:

```text
Index 0 → NULL

Index 1 → NULL

Index 2 → NULL

Index 3 → 10 → 17 → 24 → NULL

Index 4 → NULL

Index 5 → NULL

Index 6 → NULL
```

### Java Implementation

```java
import java.util.LinkedList;

public class ChainingHashTable {

    LinkedList<Integer>[] table;

    @SuppressWarnings("unchecked")
    ChainingHashTable(int size) {

        table = new LinkedList[size];

        for (int i = 0; i < size; i++) {
            table[i] = new LinkedList<>();
        }
    }

    int hash(int key) {

        return Math.floorMod(key, table.length);
    }

    void insert(int key) {

        int index = hash(key);

        if (!table[index].contains(key)) {
            table[index].add(key);
        }
    }

    boolean search(int key) {

        int index = hash(key);

        return table[index].contains(key);
    }

    void delete(int key) {

        int index = hash(key);

        table[index].remove(Integer.valueOf(key));
    }

    void display() {

        for (int i = 0; i < table.length; i++) {

            System.out.println(
                i + " → " + table[i]
            );
        }
    }

    public static void main(String[] args) {

        ChainingHashTable ht =
                new ChainingHashTable(7);

        ht.insert(10);
        ht.insert(17);
        ht.insert(24);

        ht.display();

        System.out.println(ht.search(17));

        ht.delete(17);

        ht.display();
    }
}
```

---

# 11. Inserting an Element into a Hash Table

Insertion means adding a new key into the hash table.

General steps:

1. Accept the key.
2. Apply the hash function.
3. Calculate the index.
4. Check whether the index is empty.
5. If empty, insert the key.
6. If occupied, resolve the collision using the selected technique.

### Example: Linear Probing

```text
Table Size = 7

Key = 17

Initial Index = 17 % 7 = 3
```

If index 3 is occupied:

```text
Check index 4
Check index 5
Check index 6
```

Insert the key into the first available position.

---

# 12. Searching an Element in a Hash Table

Searching finds a particular key in the hash table.

For linear probing:

1. Calculate the original hash index.
2. Check the current position.
3. If the key matches, return true.
4. If the position is occupied by another key, continue probing.
5. If an empty slot is found, the key is absent.
6. Stop after checking at most the table capacity.

**Important:** A deleted slot cannot always be treated as an empty slot in open addressing. Search must continue through deleted slots.

---

# 13. Deleting an Element from a Hash Table

Deletion removes a key from the hash table.

In open addressing, simply setting a deleted slot to empty can break the search sequence.

### Example

Suppose:

```text
Index 3 → 10
Index 4 → 17
Index 5 → 24
```

All keys were inserted using linear probing.

Now delete key 17.

If index 4 is marked as completely empty, searching for 24 may stop at index 4 and incorrectly report that 24 does not exist.

### Solution: Tombstone / Deleted Marker

Instead of marking the slot as empty, mark it as deleted.

```text
Index 3 → 10
Index 4 → DELETED
Index 5 → 24
```

During searching:
- Empty slot means the key was never placed beyond this point in the current probe sequence.
- Deleted slot means continue searching.
- Occupied slot means compare the key.

During insertion, a deleted slot can be reused, but the implementation should first ensure that the key does not already exist later in the probe sequence.

---

# 14. Complete Java Program: Hash Table Using Linear Probing

This program supports:

- Insert
- Search
- Delete
- Display
- Collision handling
- Deleted-slot handling

```java
import java.util.Scanner;

class HashTable {

    private static final int EMPTY = 0;
    private static final int OCCUPIED = 1;
    private static final int DELETED = 2;

    private int[] table;
    private int[] status;
    private int size;

    HashTable(int size) {

        this.size = size;

        table = new int[size];

        status = new int[size];
    }

    // Hash function
    private int hash(int key) {

        return Math.floorMod(key, size);
    }

    // Insert
    void insert(int key) {

        int index = hash(key);

        int firstDeleted = -1;

        for (int i = 0; i < size; i++) {

            int current = (index + i) % size;

            if (status[current] == OCCUPIED) {

                if (table[current] == key) {
                    System.out.println("Duplicate key");
                    return;
                }

            } else if (status[current] == DELETED) {

                if (firstDeleted == -1) {
                    firstDeleted = current;
                }

            } else {

                int position =
                    firstDeleted != -1
                    ? firstDeleted : current;

                table[position] = key;

                status[position] = OCCUPIED;

                System.out.println("Inserted successfully");

                return;
            }
        }

        // Reuse a deleted slot if no empty slot was found
        if (firstDeleted != -1) {

            table[firstDeleted] = key;

            status[firstDeleted] = OCCUPIED;

            System.out.println("Inserted successfully");

        } else {

            System.out.println("Hash table is full");
        }
    }

    // Search
    boolean search(int key) {

        int index = hash(key);

        for (int i = 0; i < size; i++) {

            int current = (index + i) % size;

            if (status[current] == EMPTY) {
                return false;
            }

            if (status[current] == OCCUPIED
                    && table[current] == key) {

                return true;
            }
        }

        return false;
    }

    // Delete
    void delete(int key) {

        int index = hash(key);

        for (int i = 0; i < size; i++) {

            int current = (index + i) % size;

            if (status[current] == EMPTY) {
                System.out.println("Key not found");
                return;
            }

            if (status[current] == OCCUPIED
                    && table[current] == key) {

                status[current] = DELETED;

                System.out.println("Deleted successfully");

                return;
            }
        }

        System.out.println("Key not found");
    }

    // Display
    void display() {

        System.out.println("\nHash Table:");

        for (int i = 0; i < size; i++) {

            System.out.print(i + " : ");

            if (status[i] == EMPTY) {

                System.out.println("EMPTY");

            } else if (status[i] == DELETED) {

                System.out.println("DELETED");

            } else {

                System.out.println(table[i]);
            }
        }
    }
}

public class HashTableDemo {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        HashTable ht = new HashTable(7);

        int choice;

        do {

            System.out.println("\n--- HASH TABLE MENU ---");

            System.out.println("1. Insert");

            System.out.println("2. Search");

            System.out.println("3. Delete");

            System.out.println("4. Display");

            System.out.println("5. Exit");

            System.out.print("Enter choice: ");

            choice = sc.nextInt();

            switch (choice) {

                case 1:

                    System.out.print("Enter key: ");

                    ht.insert(sc.nextInt());

                    break;

                case 2:

                    System.out.print("Enter key: ");

                    int searchKey = sc.nextInt();

                    if (ht.search(searchKey)) {

                        System.out.println("Key found");

                    } else {

                        System.out.println("Key not found");
                    }

                    break;

                case 3:

                    System.out.print("Enter key: ");

                    ht.delete(sc.nextInt());

                    break;

                case 4:

                    ht.display();

                    break;

                case 5:

                    System.out.println("Exiting...");

                    break;

                default:

                    System.out.println("Invalid choice");
            }

        } while (choice != 5);

        sc.close();
    }
}
```

### Important Implementation Details

- The program uses Linear Probing.
- `EMPTY` means the slot has never been occupied since the last table initialization.
- `OCCUPIED` means a key is stored.
- `DELETED` is a tombstone marker.
- Search continues through deleted positions.
- Insert checks for duplicate keys before reusing a deleted slot.

---

# 15. Fibonacci Recursive Algorithm Improvement Using Hash Table

Fibonacci is a mathematical sequence in which each number is the sum of the previous two numbers.

Sequence:

```text
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
```

Mathematical definition:

\[
F(0)=0
\]

\[
F(1)=1
\]

\[
F(n)=F(n-1)+F(n-2)
\]

## 15.1 Normal Recursive Fibonacci

```java
public class FibonacciRecursive {

    static int fibonacci(int n) {

        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        return fibonacci(n - 1)
             + fibonacci(n - 2);
    }

    public static void main(String[] args) {

        System.out.println(fibonacci(10));
    }
}
```

Output:

```text
55
```

### Problem with Normal Recursion

Normal recursive Fibonacci repeatedly calculates the same values.

For example:

```text
fib(5)
       /       \
    fib(4)    fib(3)
    /   \      /   \
 fib(3) fib(2) fib(2) fib(1)
```

Here, `fib(3)` and `fib(2)` are calculated multiple times.

This results in unnecessary repeated calculations.

Time Complexity:

\[
O(2^n)
\]

More precisely, the running time grows exponentially.

Auxiliary Space:

\[
O(n)
\]

Because of the maximum recursion depth.

## 15.2 Optimized Fibonacci Using HashMap (Memoization)

**Memoization** is an optimization technique in which previously calculated results are stored and reused.

A HashMap stores the calculated Fibonacci values.

Before calculating a value:
1. Check whether it is already present in the HashMap.
2. If present, return the stored result.
3. Otherwise, calculate the value recursively.
4. Store the result in the HashMap.
5. Return the result.

### Java Implementation

```java
import java.util.HashMap;
import java.util.Map;

public class FibonacciMemoization {

    static Map<Integer, Long> memo = new HashMap<>();

    static long fibonacci(int n) {

        // Base conditions
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        // Check whether result is already available
        if (memo.containsKey(n)) {
            return memo.get(n);
        }

        // Calculate and store the result
        long result =
            fibonacci(n - 1) + fibonacci(n - 2);

        memo.put(n, result);

        return result;
    }

    public static void main(String[] args) {

        int n = 50;

        System.out.println(
            "Fibonacci(" + n + ") = " + fibonacci(n)
        );
    }
}
```

Output:

```text
Fibonacci(50) = 12586269025
```

### How HashMap Improves Fibonacci

Without memoization:

```text
fib(5)
  |
  |-- fib(4)
  |     |-- fib(3)
  |     |-- fib(2)
  |
  |-- fib(3)
        |-- fib(2)
        |-- fib(1)
```

The same subproblems are calculated repeatedly.

With memoization:

```text
fib(5)
  |
  |-- Calculate fib(4)
  |-- Calculate fib(3)
  |-- Store results in HashMap
  |
  |-- Reuse previously calculated fib(3)
```

### Memoization Table Example

For `Fibonacci(5)`:

| Key (n) | Value (Fibonacci) |
|---|---:|
| 2 | 1 |
| 3 | 2 |
| 4 | 3 |
| 5 | 5 |

The values are stored and reused instead of being recalculated.

### Complexity Comparison

| Feature | Normal Recursion | Memoization with HashMap |
|---|---|---|
| Time Complexity | O(2ⁿ) upper bound | O(n) expected |
| Auxiliary Space | O(n) | O(n) |
| Repeated Calculations | Yes | Avoided |
| Storage | Call stack | Call stack + HashMap |
| Performance | Slow for large n | Much faster |

**Important:** HashMap operations such as `get()` and `put()` take expected O(1) time under normal hashing assumptions. The memoized Fibonacci algorithm therefore takes expected O(n) time.

**Note:** Java's `long` data type can store Fibonacci values only up to F(92). Larger values require `BigInteger`.

---

# 16. Hashing in Previously Solved Programs

The syllabus also mentions implementing hashing techniques in different programs solved earlier.

Hashing can improve programs that repeatedly search for values.

### Example 1: Finding Duplicates in an Array

Without Hashing:

- Compare each element with other elements.
- Time Complexity: O(n²) for the simple nested-loop method.

Using HashSet:

```java
import java.util.HashSet;

public class DuplicateCheck {

    public static void main(String[] args) {

        int[] arr = {10, 20, 30, 20, 40, 10};

        HashSet<Integer> set = new HashSet<>();

        for (int num : arr) {

            if (set.contains(num)) {

                System.out.println(
                    "Duplicate found: " + num
                );

            } else {

                set.add(num);
            }
        }
    }
}
```

Expected Output:

```text
Duplicate found: 20
Duplicate found: 10
```

Expected Time Complexity: O(n).

### Example 2: Frequency Counting

```java
import java.util.HashMap;

public class FrequencyCount {

    public static void main(String[] args) {

        int[] arr = {10, 20, 10, 30, 20, 10};

        HashMap<Integer, Integer> map =
                new HashMap<>();

        for (int num : arr) {

            map.put(
                num,
                map.getOrDefault(num, 0) + 1
            );
        }

        System.out.println(map);
    }
}
```

Possible Output:

```text
{10=3, 20=2, 30=1}
```

Expected Time Complexity: O(n).

---

# 17. Time Complexity of Hash Table Operations

Under normal hashing assumptions, hash table operations are expected to be efficient.

| Operation | Average / Expected | Worst Case |
|---|---|---|
| Insert | O(1) | O(n) |
| Search | O(1) | O(n) |
| Delete | O(1) | O(n) |

**Why can worst-case complexity be O(n)?**

If many keys collide, the algorithm may need to examine many positions or elements.

In open addressing, a search or insertion may examine the entire table.

In separate chaining, many keys may be stored in the same bucket.

### Important Factors Affecting Performance

1. Quality of the hash function.
2. Table size.
3. Load factor.
4. Collision resolution technique.
5. Distribution of input keys.

---

# 18. Important Interview Questions

**Q1. What is hashing?**

Hashing is a technique that converts a key into an index using a hash function.

**Q2. What is a hash table?**

A hash table is a data structure that stores keys or key-value pairs using calculated indices.

**Q3. What is a hash function?**

A hash function calculates the index where a key should be stored.

**Q4. What is a collision?**

A collision occurs when two different keys generate the same hash index.

**Q5. What is the division method?**

It calculates the remainder of the key divided by the table size.

**Q6. What are the different types of hash functions?**

Division, multiplication, mid-square, folding, and digit extraction.

**Q7. What is collision resolution?**

Collision resolution is the process of handling multiple keys that map to the same index.

**Q8. What is Linear Probing?**

Linear Probing checks the next available position sequentially when a collision occurs.

**Q9. What is Quadratic Probing?**

Quadratic Probing calculates the next position using a quadratic function of the probe number.

**Q10. What is Double Hashing?**

Double Hashing uses two hash functions to calculate the initial index and the probing step size.

**Q11. What is primary clustering?**

Primary clustering occurs when consecutive occupied slots form groups in Linear Probing.

**Q12. What is secondary clustering?**

Secondary clustering occurs when keys with the same initial hash index follow the same probing sequence.

**Q13. What is Separate Chaining?**

Separate Chaining stores multiple keys in a bucket, commonly using a linked list.

**Q14. What is Load Factor?**

Load Factor is the ratio of the number of stored elements to the hash table capacity.

**Q15. What is the average time complexity of searching in a hash table?**

Expected O(1), assuming a good hash function and suitable load factor.

**Q16. Why is deletion difficult in Linear Probing?**

Because marking a deleted position as empty may break the probing sequence and cause incorrect search results.

**Q17. What is a Tombstone?**

A tombstone is a special deleted marker used to preserve the probing sequence.

**Q18. What is Memoization?**

Memoization stores previously calculated results and reuses them to avoid repeated calculations.

**Q19. How does HashMap improve Fibonacci recursion?**

It stores previously calculated Fibonacci values and returns them when needed.

**Q20. What is the time complexity of Fibonacci using memoization?**

Expected O(n).

---

# 19. Multiple Choice Questions (MCQs)

**Q1. What is hashing?**

- A. Sorting elements
- B. Converting a key into an index
- C. Searching sequentially
- D. Traversing a tree

**Answer:** B

**Q2. Which data structure is commonly used for hashing?**

- A. Hash Table
- B. Stack
- C. Queue
- D. Tree only

**Answer:** A

**Q3. What is a collision?**

- A. Deleting an element
- B. Two keys generating the same index
- C. Sorting an array
- D. Searching an element

**Answer:** B

**Q4. Which hash function uses the remainder operation?**

- A. Folding
- B. Mid-Square
- C. Division
- D. Multiplication

**Answer:** C

**Q5. Which collision resolution technique checks consecutive positions?**

- A. Quadratic Probing
- B. Linear Probing
- C. Double Hashing
- D. Separate Chaining

**Answer:** B

**Q6. Which technique uses squared probe numbers?**

- A. Linear Probing
- B. Quadratic Probing
- C. Double Hashing
- D. Folding

**Answer:** B

**Q7. Which technique uses two hash functions?**

- A. Linear Probing
- B. Quadratic Probing
- C. Double Hashing
- D. Mid-Square

**Answer:** C

**Q8. Which technique uses linked lists to resolve collisions?**

- A. Linear Probing
- B. Quadratic Probing
- C. Separate Chaining
- D. Double Hashing

**Answer:** C

**Q9. Linear Probing suffers from:**

- A. Primary Clustering
- B. Secondary Clustering only
- C. Stack Overflow
- D. Recursion

**Answer:** A

**Q10. Quadratic Probing helps reduce:**

- A. Primary Clustering
- B. All collisions
- C. Hashing
- D. Load Factor

**Answer:** A

**Q11. What is Load Factor?**

- A. Table Size / Number of Elements
- B. Number of Elements / Table Size
- C. Number of Collisions / Number of Keys
- D. Number of Keys × Table Size

**Answer:** B

**Q12. What is the expected average search complexity of a well-designed hash table?**

- A. O(n)
- B. O(n²)
- C. O(1)
- D. O(log n)

**Answer:** C

**Q13. What is a tombstone in hashing?**

- A. A new hash function
- B. A deleted-slot marker
- C. A collision
- D. A table resizing operation

**Answer:** B

**Q14. Which Java class stores key-value pairs using hashing?**

- A. ArrayList
- B. HashMap
- C. LinkedList
- D. Stack

**Answer:** B

**Q15. Which Java collection stores unique elements using hashing?**

- A. HashSet
- B. ArrayList
- C. LinkedList
- D. Queue

**Answer:** A

**Q16. What is Memoization?**

- A. Sorting data
- B. Storing previously calculated results
- C. Deleting duplicate keys
- D. Creating a hash function

**Answer:** B

**Q17. What is the expected time complexity of Fibonacci using HashMap memoization?**

- A. O(2ⁿ)
- B. O(n²)
- C. O(n)
- D. O(log n)

**Answer:** C

**Q18. Which hash function uses the square of a key?**

- A. Division
- B. Mid-Square
- C. Folding
- D. Digit Extraction

**Answer:** B

**Q19. What is the worst-case search complexity of a hash table?**

- A. O(1)
- B. O(log n)
- C. O(n)
- D. O(n log n)

**Answer:** C

**Q20. Which collision resolution technique uses a second hash function to calculate the probe interval?**

- A. Linear Probing
- B. Quadratic Probing
- C. Double Hashing
- D. Separate Chaining

**Answer:** C

---

# 20. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Hashing | Converts a key into an index |
| Hash Table | Stores keys or key-value pairs |
| Hash Function | Calculates the index |
| Collision | Two keys map to the same index |
| Division Method | Uses remainder |
| Multiplication Method | Uses a fractional constant |
| Mid-Square | Squares the key and extracts middle digits |
| Folding | Divides key into parts and adds them |
| Digit Extraction | Selects particular digits |
| Linear Probing | Checks next available slot |
| Quadratic Probing | Uses quadratic increments |
| Double Hashing | Uses two hash functions |
| Separate Chaining | Uses linked lists or buckets |
| Load Factor | Elements / Table Size |
| Tombstone | Marks a deleted slot |
| Memoization | Stores previously calculated results |
| HashMap | Java key-value collection using hashing |

### Important Formulas

**Division Method:**

\[
h(k) = k \bmod m
\]

**Linear Probing:**

\[
h_i(k) = (h(k) + i) \bmod m
\]

**Quadratic Probing:**

\[
h_i(k) = (h(k) + i^2) \bmod m
\]

**Double Hashing:**

\[
h_i(k) = (h_1(k) + i \times h_2(k)) \bmod m
\]

**Load Factor:**

\[
\alpha = \frac{n}{m}
\]

---

# 21. Suggested GitHub Folder Structure

```text
Algorithms-and-Data-Structures/
│
├── Sessions-01-03/
│   └── README.md
│
├── Sessions-04-06-Linked-Lists/
│   └── README.md
│
├── Sessions-07-08-Recursion/
│   └── README.md
│
├── Sessions-09-11-Trees/
│   └── README.md
│
├── Sessions-12-14-Searching-Sorting/
│   └── README.md
│
└── Sessions-15-16-Hashing/
    │
    ├── README.md
    │
    ├── HashFunctions/
    │   ├── DivisionHash.java
    │   └── ChainingHashTable.java
    │
    ├── CollisionResolution/
    │   ├── LinearProbing.java
    │   ├── QuadraticProbing.java
    │   └── DoubleHashing.java
    │
    ├── HashTable/
    │   └── HashTableDemo.java
    │
    └── Fibonacci/
        ├── FibonacciRecursive.java
        └── FibonacciMemoization.java
```

---

# 22. Learning Outcomes

After completing Sessions 15 & 16, students should be able to:

- Understand hashing and hash tables.
- Explain the purpose of hash functions.
- Implement different types of hash functions.
- Understand collisions and collision resolution.
- Implement Linear Probing.
- Implement Quadratic Probing.
- Implement Double Hashing.
- Understand Separate Chaining.
- Perform insertion, searching, and deletion in a hash table.
- Understand tombstones and load factor.
- Use Java HashMap for storing key-value pairs.
- Optimize recursive Fibonacci using memoization and hashing.

---

**End of Sessions 15 & 16 – Hash Functions and Hash Tables**

*Course: Algorithms and Data Structures Using Java | PGCP-AC August 2026 | ACTS Pune*
