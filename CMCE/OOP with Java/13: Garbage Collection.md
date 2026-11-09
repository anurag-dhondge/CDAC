

# Session 13: Garbage Collection in Java

**Course:** CDAC CMCE – August 2026 Batch  
**Technology:** Java 17  
**Topic:** Garbage Collection and Memory Management

---

# 1. Introduction to Garbage Collection

## 1.1 What is Garbage Collection?

Garbage Collection (GC) is an automatic memory management process in Java.

When we create objects using the `new` keyword, memory is generally allocated on the heap.

When an object is no longer reachable by the running program, it becomes eligible for garbage collection.

The JVM's Garbage Collector identifies and reclaims memory occupied by eligible objects.

**In simple words:**

Garbage Collection automatically removes unused objects from heap memory so that memory can be reused.

### Real-world example

Imagine a classroom:

- Students are objects.
- Classroom seats represent memory.
- When a student leaves permanently, their seat becomes available.
- Another student can use that seat.

Similarly, when an object is no longer reachable, its memory can eventually be reclaimed.

## 1.2 Why Do We Need Garbage Collection?

Garbage Collection helps to:

1. Reclaim memory occupied by unreachable objects.
2. Reduce manual memory management.
3. Reduce the risk of dangling pointers.
4. Reduce memory-related programming errors.
5. Improve application memory management.

### Without Garbage Collection

In languages requiring manual memory management, programmers may need to allocate and release memory explicitly.

For example, C uses functions such as:

```c
malloc();
free();
```

### With Java Garbage Collection

Java automatically manages object memory.

```java
class Student {
    int rollNo;
}

public class GCDemo {

    public static void main(String[] args) {

        Student s = new Student();

        s.rollNo = 101;

        System.out.println(s.rollNo);
    }
}
```

When the method finishes and no other reference points to the Student object, that object may become eligible for garbage collection.

---

# 2. Heap Memory and Garbage Collection

## 2.1 What is Heap Memory?

Heap memory is the runtime memory area generally used for allocating Java objects and arrays.

Example:

```java
Student s = new Student();
```

Conceptually:

- `s` is a reference variable.
- The Student object is allocated on the heap.
- The reference variable refers to that object.

## 2.2 Understanding Object References

Consider:

```java
class Student {
    int rollNo;
}

public class HeapDemo {

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.rollNo = 101;

        System.out.println(s1.rollNo);
    }
}
```

Conceptual memory representation:

```text
          Stack                         Heap

      +-----------+                 +-------------+
      |   s1      |  ------------>  | Student     |
      +-----------+                 | rollNo = 101|
                                    +-------------+
```

The reference `s1` points to the Student object.

As long as the object is reachable through a live reference, it cannot be reclaimed by the garbage collector.

## 2.3 What Makes an Object Eligible for Garbage Collection?

An object becomes eligible for garbage collection when it is no longer reachable from any GC root.

Common GC roots include:
- References in active thread stacks.
- Static fields.
- Active threads.
- Certain JVM internal references.

**Important:** An object being eligible for garbage collection does not mean it will be collected immediately.

The JVM decides when to perform garbage collection.

---

# 3. Different Ways to Make an Object Eligible for Garbage Collection

According to the syllabus, there are three important ways:

1. Nulling a reference variable.
2. Reassigning a reference variable.
3. Island of isolation.

---

## 3.1 Nulling a Reference Variable

When a reference variable is assigned `null`, it no longer refers to its previous object.

If no other live reference points to that object, it becomes eligible for garbage collection.

### Example

```java
class Student {

    int rollNo;

    Student(int rollNo) {
        this.rollNo = rollNo;
    }
}

public class NullReferenceDemo {

    public static void main(String[] args) {

        Student s1 = new Student(101);

        System.out.println("Student created");

        s1 = null;

        System.out.println("Reference assigned null");
    }
}
```

**Output:**

```text
Student created
Reference assigned null
```

### Explanation

Initially:

```text
s1 ------------> Student Object
```

After:

```java
s1 = null;
```

The reference becomes:

```text
s1 ------------> null

                 Student Object
                 (Unreachable)
```

The Student object is now eligible for garbage collection, assuming no other live reference points to it.

**Important:** Assigning `null` to a reference does not immediately destroy the object.

---

## 3.2 Reassigning a Reference Variable

When a reference variable is reassigned to another object, the previous object may become unreachable.

### Example

```java
class Student {

    int rollNo;

    Student(int rollNo) {

        this.rollNo = rollNo;
    }
}

public class ReassignmentDemo {

    public static void main(String[] args) {

        Student s1 = new Student(101);

        System.out.println("First Student: " + s1.rollNo);

        s1 = new Student(102);

        System.out.println("Second Student: " + s1.rollNo);
    }
}
```

**Output:**

```text
First Student: 101
Second Student: 102
```

### Explanation

Initially:

```text
s1 ------------> Student Object 1
                 rollNo = 101
```

After reassignment:

```java
s1 = new Student(102);
```

Memory representation:

```text
s1 ------------> Student Object 2
                 rollNo = 102


                 Student Object 1
                 rollNo = 101
                 (Unreachable)
```

The first Student object becomes eligible for garbage collection if there are no other live references to it.

---

## 3.3 Island of Isolation

An island of isolation occurs when two or more objects refer to each other, but none of them can be reached from any GC root.

Even though these objects have references between themselves, they are eligible for garbage collection.

### Example

```java
class Student {

    Student reference;

    int rollNo;

    Student(int rollNo) {

        this.rollNo = rollNo;
    }
}

public class IslandDemo {

    public static void main(String[] args) {

        Student s1 = new Student(101);

        Student s2 = new Student(102);

        s1.reference = s2;

        s2.reference = s1;

        System.out.println("Objects created");

        s1 = null;

        s2 = null;

        System.out.println("References removed");
    }
}
```

**Output:**

```text
Objects created
References removed
```

### Explanation

Initially:

```text
       s1
        |
        v
   +----------+
   | Student1 |
   +----------+
        |
        | reference
        v
   +----------+
   | Student2 |
   +----------+
        |
        | reference
        +----------> Student1
```

Both objects refer to each other.

After:

```java
s1 = null;
s2 = null;
```

The local references are removed:

```text
       Student1 <------> Student2

       (No external reference)
```

Neither object is reachable from a GC root.

Therefore, both objects are eligible for garbage collection.

**Important interview point:** Java's garbage collector can identify unreachable cycles. Circular references alone do not prevent garbage collection.

---

# 4. Requesting JVM to Run Garbage Collection

Java provides methods to request garbage collection.

The commonly used methods are:

1. `System.gc()`
2. `Runtime.getRuntime().gc()`

## 4.1 System.gc()

The `gc()` method of the System class requests the JVM to perform garbage collection.

### Syntax

```java
System.gc();
```

### Example

```java
public class SystemGCDemo {

    public static void main(String[] args) {

        System.out.println("Before GC request");

        System.gc();

        System.out.println("After GC request");
    }
}
```

**Possible output:**

```text
Before GC request
After GC request
```

The output does not prove that garbage collection actually occurred.

The JVM is free to ignore or delay the request.

## 4.2 Runtime.getRuntime().gc()

Java also provides another way to request garbage collection.

### Example

```java
public class RuntimeGCDemo {

    public static void main(String[] args) {

        Runtime runtime = Runtime.getRuntime();

        System.out.println("Requesting Garbage Collection");

        runtime.gc();

        System.out.println("GC request completed");
    }
}
```

**Possible output:**

```text
Requesting Garbage Collection
GC request completed
```

## 4.3 Difference Between System.gc() and Runtime.gc()

| System.gc() | Runtime.getRuntime().gc() |
|---|---|
| Static method | Instance method |
| Called using System class | Called using Runtime object |
| Requests garbage collection | Requests garbage collection |
| Does not guarantee collection | Does not guarantee collection |

Both are requests, not commands that guarantee immediate collection.

---

# 5. Garbage Collection Demonstration Using finalize()

## 5.1 What is finalize()?

Historically, Java provided a method called `finalize()` in the `Object` class.

The garbage collector could invoke this method before reclaiming an object.

### Syntax

```java
protected void finalize() throws Throwable {
    // Cleanup code
}
```

### Example

```java
class Student {

    int rollNo;

    Student(int rollNo) {

        this.rollNo = rollNo;
    }

    @Override
    protected void finalize() {

        System.out.println(
            "Garbage collection called for Student: " + rollNo
        );
    }
}

public class FinalizeDemo {

    public static void main(String[] args) {

        Student s1 = new Student(101);

        Student s2 = new Student(102);

        s1 = null;

        s2 = null;

        System.gc();

        System.out.println("End of main method");
    }
}
```

**Possible output:**

```text
End of main method
Garbage collection called for Student: 101
Garbage collection called for Student: 102
```

**Important:** This output is only illustrative. The order and execution of `finalize()` are not guaranteed. It may not execute at all before the program terminates.

## 5.2 Important Points About finalize()

1. `finalize()` was historically used for cleanup before garbage collection.
2. It was defined in the `Object` class.
3. It could be overridden by a class.
4. The JVM might invoke it before reclaiming an object.
5. Its execution was not guaranteed.
6. It could execute zero, one or more times depending on object finalization and resurrection behavior.
7. It is deprecated and should not be used in modern Java applications.

## 5.3 Is finalize() Recommended in Java 17?

No.

The `finalize()` method has been deprecated since Java 9 and marked for removal.

It is not recommended for resource management because:
- Execution timing is unpredictable.
- It is not guaranteed to execute.
- It can negatively affect performance.
- It can cause resource-management problems.
- It can allow objects to become reachable again.

### Better Alternatives

Use:
- `try-with-resources`
- `AutoCloseable`
- Explicit `close()` methods
- `Cleaner` for special fallback cleanup requirements

### Example: Try-With-Resources

```java
import java.io.FileWriter;
import java.io.IOException;

public class ResourceManagementDemo {

    public static void main(String[] args) {

        try (FileWriter writer = new FileWriter("demo.txt")) {

            writer.write("Hello Java");

            System.out.println("Data written successfully");

        } catch (IOException e) {

            System.out.println(e.getMessage());
        }
    }
}
```

**Output:**

```text
Data written successfully
```

The FileWriter is automatically closed when the try-with-resources block finishes.

---

# 6. Garbage Collection vs finalize()

| Garbage Collection | finalize() |
|---|---|
| Reclaims memory occupied by unreachable objects | Historically provided a cleanup callback |
| Managed by JVM | Defined in Object class |
| Execution timing is not guaranteed | Execution timing is not guaranteed |
| Automatically manages heap memory | Not a reliable resource-management mechanism |
| Still used in modern Java | Deprecated and marked for removal |

**Remember:** Garbage collection and finalization are not the same thing.

---

# 7. Complete Garbage Collection Demonstration Program

This program demonstrates:
- Object creation.
- Nulling a reference.
- Reassigning a reference.
- Island of isolation.
- Requesting garbage collection.

```java
class Employee {

    int employeeId;

    Employee reference;

    Employee(int employeeId) {

        this.employeeId = employeeId;

        System.out.println(
            "Employee created: " + employeeId
        );
    }
}

public class GarbageCollectionDemo {

    public static void main(String[] args) {

        // 1. Nulling reference
        Employee e1 = new Employee(101);

        e1 = null;

        System.out.println(
            "First object reference set to null"
        );

        // 2. Reassigning reference
        Employee e2 = new Employee(102);

        e2 = new Employee(103);

        System.out.println(
            "Second reference reassigned"
        );

        // 3. Island of isolation
        Employee e3 = new Employee(104);

        Employee e4 = new Employee(105);

        e3.reference = e4;

        e4.reference = e3;

        e3 = null;

        e4 = null;

        System.out.println(
            "Island of isolation created"
        );

        // 4. Request garbage collection
        System.gc();

        System.out.println(
            "Garbage collection requested"
        );
    }
}
```

**Possible output:**

```text
Employee created: 101
First object reference set to null
Employee created: 102
Employee created: 103
Second reference reassigned
Employee created: 104
Employee created: 105
Island of isolation created
Garbage collection requested
```

The program demonstrates object eligibility, not guaranteed collection. The actual garbage collection may happen later or not before the program exits.

---

# 8. Important Concepts: Eligible vs Collected

These two terms are different.

### Eligible for Garbage Collection

An object is eligible when it is no longer reachable from any GC root.

### Collected

An object is collected when the garbage collector actually reclaims its memory.

**Example:**

```java
Student s = new Student();

s = null;
```

After `s = null`:

- The object may become eligible.
- The JVM may collect it later.
- It is not necessarily collected immediately.

---

# 9. Important Interview Questions and Answers

### Q1. What is Garbage Collection in Java?

Garbage Collection is the JVM's automatic memory management process that reclaims memory occupied by unreachable objects.

### Q2. Who performs Garbage Collection in Java?

The JVM performs garbage collection using its garbage collector.

### Q3. Where are Java objects generally allocated?

Objects and arrays are generally allocated on heap memory.

### Q4. When does an object become eligible for garbage collection?

When it is no longer reachable from any GC root.

### Q5. Does assigning null immediately destroy an object?

No. It may make the object eligible for garbage collection.

### Q6. What are the different ways to make an object eligible for garbage collection?

1. Nulling a reference.
2. Reassigning a reference.
3. Creating an island of isolation.

### Q7. What is an island of isolation?

A group of objects that refer to one another but cannot be reached from any GC root.

### Q8. Can Java collect objects having circular references?

Yes. Java can identify unreachable cyclic object graphs.

### Q9. How can we request garbage collection?

Using:

```java
System.gc();
```

or:

```java
Runtime.getRuntime().gc();
```

### Q10. Does System.gc() guarantee garbage collection?

No. It only requests the JVM to perform garbage collection.

### Q11. What is finalize()?

It is a method historically called by the JVM during object finalization before reclaiming memory.

### Q12. Which class contains finalize()?

The `Object` class.

### Q13. Can we override finalize()?

Historically, yes. However, it is deprecated and should not be used in modern Java.

### Q14. Is finalize() guaranteed to execute?

No.

### Q15. Which Java version deprecated finalize()?

Java 9.

### Q16. Is finalize() recommended for closing files?

No. Use try-with-resources or explicit resource management.

### Q17. Can an object become reachable again from finalize()?

Historically, yes. This is called object resurrection.

### Q18. Does garbage collection remove all memory leaks?

No. Objects that are no longer useful but remain reachable can still cause memory leaks.

### Q19. What is the difference between eligible and collected objects?

Eligible objects are unreachable and can be collected; collected objects have actually had their memory reclaimed.

### Q20. Can we force the JVM to run garbage collection?

No. We can request it, but cannot guarantee when it runs.

---

# 10. Important MCQs for CMCE

**1. What is the purpose of Garbage Collection?**

A. Compile Java code  
B. Reclaim memory occupied by unreachable objects  
C. Execute methods  
D. Create objects  

**Answer: B. Reclaim memory occupied by unreachable objects**

**2. Where are Java objects generally allocated?**

A. Stack  
B. Heap  
C. Register  
D. Method parameter area  

**Answer: B. Heap**

**3. Which method requests garbage collection?**

A. `delete()`  
B. `free()`  
C. `System.gc()`  
D. `remove()`  

**Answer: C. System.gc()**

**4. Does System.gc() guarantee immediate garbage collection?**

A. Yes  
B. No  
C. Only for null objects  
D. Only for static objects  

**Answer: B. No**

**5. Which of the following can make an object eligible for GC?**

A. Nulling reference  
B. Reassigning reference  
C. Island of isolation  
D. All of the above  

**Answer: D. All of the above**

**6. What is an island of isolation?**

A. A single static object  
B. Objects referring to each other but unreachable externally  
C. An object inside a loop  
D. A final object  

**Answer: B. Objects referring to each other but unreachable externally**

**7. Which class defines finalize()?**

A. String  
B. System  
C. Object  
D. Runtime  

**Answer: C. Object**

**8. In which Java version was finalize() deprecated?**

A. Java 7  
B. Java 8  
C. Java 9  
D. Java 17  

**Answer: C. Java 9**

**9. Which method can also request garbage collection?**

A. `Runtime.getRuntime().gc()`  
B. `Object.delete()`  
C. `System.delete()`  
D. `Thread.remove()`  

**Answer: A. Runtime.getRuntime().gc()**

**10. Can Java garbage collection handle circular references?**

A. Yes  
B. No  
C. Only two objects  
D. Only static references  

**Answer: A. Yes**

**11. What happens after a reference is set to null?**

A. Object is immediately destroyed  
B. Object may become eligible for GC  
C. Program terminates  
D. Memory is always reclaimed immediately  

**Answer: B. Object may become eligible for GC**

**12. Is finalize() recommended for resource management?**

A. Yes  
B. No  
C. Only for files  
D. Only for database connections  

**Answer: B. No**

---

# 11. Output-Based Questions

## Question 1: Nulling a Reference

```java
class A {
}

public class Test1 {

    public static void main(String[] args) {

        A obj = new A();

        obj = null;

        System.out.println("Hello");
    }
}
```

**Answer:**

```text
Hello
```

The object becomes eligible for GC if no other live reference points to it.

## Question 2: Reassigning a Reference

```java
class A {

    int x;

    A(int x) {
        this.x = x;
    }
}

public class Test2 {

    public static void main(String[] args) {

        A obj = new A(10);

        obj = new A(20);

        System.out.println(obj.x);
    }
}
```

**Answer:**

```text
20
```

The object containing 10 becomes eligible if no other live reference points to it.

## Question 3: Circular References

```java
class A {

    A ref;
}

public class Test3 {

    public static void main(String[] args) {

        A a1 = new A();

        A a2 = new A();

        a1.ref = a2;

        a2.ref = a1;

        a1 = null;

        a2 = null;

        System.out.println("Completed");
    }
}
```

**Answer:**

```text
Completed
```

Both objects become eligible because the cycle is no longer reachable externally.

## Question 4: System.gc()

```java
public class Test4 {

    public static void main(String[] args) {

        System.gc();

        System.out.println("Program completed");
    }
}
```

**Answer:**

```text
Program completed
```

The request does not guarantee that GC executes.

## Question 5: Reference Reassignment

```java
class Student {

    int id;

    Student(int id) {
        this.id = id;
    }
}

public class Test5 {

    public static void main(String[] args) {

        Student s1 = new Student(101);

        Student s2 = s1;

        s1 = null;

        System.out.println(s2.id);
    }
}
```

**Answer:**

```text
101
```

Reason: `s2` still refers to the Student object, so it is reachable.

---

# 12. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Garbage Collection | Automatic memory reclamation |
| JVM | Manages garbage collection |
| Heap | Area where objects are generally allocated |
| GC Eligibility | Object is unreachable from GC roots |
| Nulling Reference | Assigning `null` may make object eligible |
| Reassignment | Previous object may become unreachable |
| Island of Isolation | Unreachable objects referring to each other |
| `System.gc()` | Requests garbage collection |
| `Runtime.gc()` | Another way to request garbage collection |
| `finalize()` | Deprecated cleanup callback |
| Eligible Object | Can be collected |
| Collected Object | Memory has actually been reclaimed |
| Memory Leak | Unneeded objects remain reachable |
| Try-With-Resources | Preferred for closing resources |

---

# 13. Practice Checklist

- [ ] Understand Garbage Collection.
- [ ] Understand heap memory.
- [ ] Understand object references.
- [ ] Understand GC roots and reachability.
- [ ] Demonstrate nulling a reference.
- [ ] Demonstrate reference reassignment.
- [ ] Demonstrate island of isolation.
- [ ] Understand `System.gc()`.
- [ ] Understand `Runtime.getRuntime().gc()`.
- [ ] Understand the `finalize()` method.
- [ ] Understand why finalize() is deprecated.
- [ ] Understand eligible versus collected objects.
- [ ] Solve interview questions and MCQs.

---

# 14. Additional Practice Assignments

1. Create a Student class and make its object eligible for GC using nulling.
2. Create two Student objects and demonstrate reference reassignment.
3. Create two objects that refer to each other and demonstrate island of isolation.
4. Create three objects and keep one object reachable using another reference.
5. Demonstrate that setting one reference to null does not make an object eligible when another reference still points to it.
6. Call `System.gc()` and observe that the request does not guarantee immediate collection.
7. Write a program using `Runtime.getRuntime().gc()`.
8. Study why finalize() is deprecated.
9. Demonstrate resource cleanup using try-with-resources.
10. Research the difference between heap memory and stack memory.

---

# 15. Suggested GitHub Folder Structure

```text
Java/
└── Session-13-Garbage-Collection/
    ├── README.md
    └── programs/
        ├── HeapDemo.java
        ├── NullReferenceDemo.java
        ├── ReassignmentDemo.java
        ├── IslandDemo.java
        ├── SystemGCDemo.java
        ├── RuntimeGCDemo.java
        ├── FinalizeDemo.java
        ├── ResourceManagementDemo.java
        └── GarbageCollectionDemo.java
```

---

# 16. Official Java References

- [Java 17 Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/)
- [Object Class – finalize()](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/Object.html)
- [System Class – gc()](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/System.html)
- [Runtime Class – gc()](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/Runtime.html)
- [Java Language Specification](https://docs.oracle.com/javase/specs/jls/se17/html/index.html)

---

**End of Session 13 – Garbage Collection**

*Remember: Garbage collection is automatic, object eligibility does not guarantee immediate collection, and System.gc() is only a request. Practice all three ways of making objects eligible for GC.*

