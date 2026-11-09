

# Session 24: Sorting Collections in Java

**Course:** CDAC CMCE – August 2026 Batch  
**Subject:** Core Java  
**Topic:** Sorting Collections  
**Duration:** 2 Theory + 2 Lab + 2 Self-Learning Hours  
**Java Version:** Java 17

---

## Table of Contents

1. Introduction to Sorting
2. Natural Sorting
3. Comparable Interface
4. Custom Sorting
5. Comparator Interface
6. Anonymous Class Implementation
7. Comparator Using Lambda Expressions
8. Sorting Objects Based on Multiple Attributes
9. Comparator Helper Methods (Java 8+)
10. Comparable vs Comparator
11. Lab: Student Merit List System
12. Interview Questions
13. MCQ Practice
14. Quick Revision Notes
15. Practice Assignments

---

# 1. Introduction to Sorting in Collections Framework

## 1.1 What is Sorting?

Sorting is the process of arranging elements in a particular order.

In Java Collections, sorting is commonly performed in two ways:

1. Natural Sorting using the `Comparable` interface.
2. Custom Sorting using the `Comparator` interface.

### Types of Sorting

**Ascending Order:**

Arranging elements from smallest to largest.

Example:

```text
10, 20, 30, 40, 50
```

**Descending Order:**

Arranging elements from largest to smallest.

Example:

```text
50, 40, 30, 20, 10
```

### Real-Life Examples

- Students sorted by roll number.
- Students ranked according to marks.
- Employees sorted by salary.
- Products sorted by price.
- Books sorted alphabetically by title.

## 1.2 Sorting Methods in Java

Java provides different methods for sorting collections.

| Method | Description |
|---|---|
| `Collections.sort(list)` | Sorts a List using natural ordering |
| `Collections.sort(list, comparator)` | Sorts using a Comparator |
| `list.sort(comparator)` | Sorts a List using a Comparator |
| `Arrays.sort(array)` | Sorts an array |
| `Comparator.comparing()` | Creates a Comparator based on a field |
| `Comparator.reversed()` | Reverses a Comparator's ordering |

### Basic Example

```java
import java.util.*;

public class SortingDemo {

    public static void main(String[] args) {

        List<Integer> numbers = new ArrayList<>();

        numbers.add(50);
        numbers.add(10);
        numbers.add(40);
        numbers.add(20);
        numbers.add(30);

        System.out.println("Original List: " + numbers);

        // Ascending order
        Collections.sort(numbers);

        System.out.println("Ascending: " + numbers);

        // Descending order
        Collections.sort(numbers, Comparator.reverseOrder());

        System.out.println("Descending: " + numbers);
    }
}
```

**Output:**

```text
Original List: [50, 10, 40, 20, 30]
Ascending: [10, 20, 30, 40, 50]
Descending: [50, 40, 30, 20, 10]
```

---

# 2. Natural Sorting

## 2.1 What is Natural Sorting?

Natural sorting is the default sorting order defined by a class.

For example:

- Integer: ascending numerical order.
- String: lexicographical (dictionary-like) order.
- Character: Unicode value order.

Java uses the `Comparable` interface to define natural ordering.

### Example

```java
import java.util.*;

public class NaturalSortingDemo {

    public static void main(String[] args) {

        List<String> names = new ArrayList<>();

        names.add("Sushant");
        names.add("Anurag");
        names.add("Rahul");
        names.add("Jayraj");

        Collections.sort(names);

        System.out.println(names);
    }
}
```

**Output:**

```text
[Anurag, Jayraj, Rahul, Sushant]
```

Here, String already implements Comparable, so Java knows how to sort String objects.

---

# 3. Comparable Interface

## 3.1 Introduction

`Comparable` is an interface available in the `java.lang` package.

It is used to define the natural sorting order of objects.

A class implements Comparable and overrides the `compareTo()` method.

### Syntax

```java
class Student implements Comparable<Student> {

    @Override
    public int compareTo(Student other) {

        return this.rollNo - other.rollNo;
    }
}
```

**Recommended:** Use `Integer.compare()` instead of subtraction to avoid integer overflow.

### compareTo() Method

The `compareTo()` method returns an integer.

| Return Value | Meaning |
|---|---|
| Negative | Current object is smaller |
| Zero | Both objects are equal according to ordering |
| Positive | Current object is greater |

### Example

```java
import java.util.*;

class Student implements Comparable<Student> {

    int rollNo;
    String name;

    Student(int rollNo, String name) {
        this.rollNo = rollNo;
        this.name = name;
    }

    @Override
    public int compareTo(Student other) {

        return Integer.compare(this.rollNo, other.rollNo);
    }

    @Override
    public String toString() {
        return rollNo + " " + name;
    }
}

public class ComparableDemo {

    public static void main(String[] args) {

        List<Student> students = new ArrayList<>();

        students.add(new Student(103, "Sushant"));
        students.add(new Student(101, "Anurag"));
        students.add(new Student(102, "Rahul"));

        Collections.sort(students);

        System.out.println("Students Sorted by Roll Number:");

        for (Student student : students) {
            System.out.println(student);
        }
    }
}
```

### Output

```text
Students Sorted by Roll Number:
101 Anurag
102 Rahul
103 Sushant
```

### Explanation

1. Student implements `Comparable<Student>`.
2. The `compareTo()` method compares roll numbers.
3. `Collections.sort()` calls the natural ordering defined by `compareTo()`.
4. Students are arranged in ascending order of roll number.

### Descending Natural Ordering

```java
@Override
public int compareTo(Student other) {
    return Integer.compare(other.rollNo, this.rollNo);
}
```

This reverses the natural ordering.

### Important Points

- Comparable belongs to `java.lang`.
- Its method is `compareTo()`.
- It defines natural ordering.
- The class itself implements Comparable.
- It is useful when a class has one meaningful default sorting order.

---

# 4. Custom Sorting

## 4.1 What is Custom Sorting?

Custom sorting means arranging objects according to a requirement that differs from their natural ordering.

For example, the same Student list may need to be sorted by:

- Name.
- Marks.
- Department.
- Roll number.
- Department followed by marks.
- Marks followed by roll number.

We use the `Comparator` interface for custom sorting.

---

# 5. Comparator Interface

## 5.1 Introduction

`Comparator` is a functional interface available in the `java.util` package.

It is used to define custom sorting logic without modifying the original class.

### Syntax

```java
class StudentComparator implements Comparator<Student> {

    @Override
    public int compare(Student s1, Student s2) {

        return Integer.compare(s1.rollNo, s2.rollNo);
    }
}
```

### compare() Method

The `compare()` method accepts two objects.

```java
compare(object1, object2)
```

| Return Value | Meaning |
|---|---|
| Negative | First object comes before second |
| Zero | Both are equal according to comparator ordering |
| Positive | First object comes after second |

## 5.2 Example: Sort Students by Marks

```java
import java.util.*;

class Student {

    int rollNo;
    String name;
    double marks;

    Student(int rollNo, String name, double marks) {
        this.rollNo = rollNo;
        this.name = name;
        this.marks = marks;
    }

    @Override
    public String toString() {
        return rollNo + " " + name + " " + marks;
    }
}

class MarksComparator implements Comparator<Student> {

    @Override
    public int compare(Student s1, Student s2) {

        return Double.compare(s1.marks, s2.marks);
    }
}

public class ComparatorDemo {

    public static void main(String[] args) {

        List<Student> students = new ArrayList<>();

        students.add(new Student(103, "Sushant", 85));
        students.add(new Student(101, "Anurag", 95));
        students.add(new Student(102, "Rahul", 90));

        Collections.sort(students, new MarksComparator());

        System.out.println("Sorted by Marks:");

        for (Student student : students) {
            System.out.println(student);
        }
    }
}
```

**Output:**

```text
Sorted by Marks:
103 Sushant 85.0
102 Rahul 90.0
101 Anurag 95.0
```

### Descending Marks

```java
Collections.sort(
    students,
    new MarksComparator().reversed()
);
```

---

# 6. Anonymous Class Implementation of Comparator

## 6.1 What is an Anonymous Class?

An anonymous class is a class without a name.

It is useful when we need to implement an interface or extend a class for a one-time operation.

Instead of creating a separate Comparator class, we can implement Comparator directly where sorting is performed.

### Example

```java
import java.util.*;

class Student {

    int rollNo;
    String name;
    double marks;

    Student(int rollNo, String name, double marks) {
        this.rollNo = rollNo;
        this.name = name;
        this.marks = marks;
    }

    @Override
    public String toString() {
        return rollNo + " " + name + " " + marks;
    }
}

public class AnonymousComparatorDemo {

    public static void main(String[] args) {

        List<Student> students = new ArrayList<>();

        students.add(new Student(103, "Sushant", 85));
        students.add(new Student(101, "Anurag", 95));
        students.add(new Student(102, "Rahul", 90));

        Collections.sort(students, new Comparator<Student>() {

            @Override
            public int compare(Student s1, Student s2) {

                return Double.compare(s2.marks, s1.marks);
            }
        });

        for (Student student : students) {
            System.out.println(student);
        }
    }
}
```

**Output:**

```text
101 Anurag 95.0
102 Rahul 90.0
103 Sushant 85.0
```

### Explanation

```java
new Comparator<Student>() {

    @Override
    public int compare(Student s1, Student s2) {
        return Double.compare(s2.marks, s1.marks);
    }
}
```

- Creates an anonymous class implementing Comparator.
- Overrides the `compare()` method.
- Compares student marks.
- Uses descending order.

---

# 7. Comparator Using Lambda Expressions

## 7.1 Introduction

A lambda expression is a shorter way to implement a functional interface.

Since Comparator is a functional interface, we can use lambda expressions instead of anonymous classes.

### General Syntax

```java
(parameters) -> expression
```

### Comparator Syntax

```java
Comparator<Student> comparator =
    (s1, s2) -> Double.compare(s1.marks, s2.marks);
```

### Example: Sort by Marks

```java
import java.util.*;

class Student {

    int rollNo;
    String name;
    double marks;

    Student(int rollNo, String name, double marks) {
        this.rollNo = rollNo;
        this.name = name;
        this.marks = marks;
    }

    @Override
    public String toString() {
        return rollNo + " " + name + " " + marks;
    }
}

public class LambdaComparatorDemo {

    public static void main(String[] args) {

        List<Student> students = new ArrayList<>();

        students.add(new Student(103, "Sushant", 85));
        students.add(new Student(101, "Anurag", 95));
        students.add(new Student(102, "Rahul", 90));

        // Ascending marks
        students.sort(
            (s1, s2) -> Double.compare(s1.marks, s2.marks)
        );

        System.out.println("Ascending Marks:");

        students.forEach(System.out::println);

        // Descending marks
        students.sort(
            (s1, s2) -> Double.compare(s2.marks, s1.marks)
        );

        System.out.println("\nDescending Marks:");

        students.forEach(System.out::println);
    }
}
```

**Output:**

```text
Ascending Marks:
103 Sushant 85.0
102 Rahul 90.0
101 Anurag 95.0

Descending Marks:
101 Anurag 95.0
102 Rahul 90.0
103 Sushant 85.0
```

### Advantages of Lambda Expressions

- Less code.
- Easier to read.
- No separate Comparator class required.
- Useful for one-time sorting.
- Works with Java 8 and later.

---

# 8. Sorting Objects Based on Multiple Attributes

## 8.1 Introduction

Sometimes sorting based on a single field is insufficient.

For example, consider the following students:

| Roll No | Name | Department | Marks |
|---:|---|---|---:|
| 101 | Anurag | AIML | 95 |
| 102 | Rahul | CSE | 90 |
| 103 | Sushant | AIML | 85 |
| 104 | Jayraj | CSE | 95 |

Suppose we want to sort:

1. By Department ascending.
2. Then by Marks descending.
3. Then by Name ascending.

We can use multiple Comparator conditions.

### Traditional Approach

```java
Comparator<Student> comparator = (s1, s2) -> {

    int result = s1.department.compareTo(s2.department);

    if (result == 0) {
        result = Double.compare(s2.marks, s1.marks);
    }

    if (result == 0) {
        result = s1.name.compareTo(s2.name);
    }

    return result;
};
```

### Explanation

- First, compare department.
- If departments are equal, compare marks in descending order.
- If marks are also equal, compare names alphabetically.

### Example

```java
students.sort(comparator);
```

This is called multi-level sorting or compound sorting.

---

# 9. Comparator Helper Methods (Java 8+)

Java 8 introduced useful Comparator methods that make sorting easier and more readable.

Important methods:

1. `comparing()`
2. `thenComparing()`
3. `reversed()`
4. `comparingInt()`
5. `comparingDouble()`
6. `comparingLong()`
7. `nullsFirst()`
8. `nullsLast()`
9. `naturalOrder()`
10. `reverseOrder()`

## 9.1 Comparator.comparing()

Used to create a Comparator based on a selected property.

```java
Comparator<Student> byName =
    Comparator.comparing(student -> student.name);
```

A more explicit version:

```java
Comparator<Student> byName =
    Comparator.comparing(Student::getName);
```

## 9.2 thenComparing()

Used when the first sorting condition is equal.

```java
Comparator<Student> comparator =
    Comparator.comparing((Student s) -> s.department)
              .thenComparing(s -> s.name);
```

This sorts by department first and then name.

## 9.3 reversed()

Reverses the ordering of a Comparator.

```java
Comparator<Student> byMarks =
    Comparator.comparingDouble((Student s) -> s.marks)
              .reversed();
```

This sorts marks in descending order.

## 9.4 comparingInt()

Used when sorting by an integer property.

```java
Comparator<Student> byRollNo =
    Comparator.comparingInt(s -> s.rollNo);
```

## 9.5 comparingDouble()

Used when sorting by a double property.

```java
Comparator<Student> byMarks =
    Comparator.comparingDouble(s -> s.marks);
```

## 9.6 comparingLong()

Used when sorting by a long property.

```java
Comparator<Employee> bySalary =
    Comparator.comparingLong(e -> e.salary);
```

## 9.7 nullsFirst() and nullsLast()

These methods define how null values should be handled during sorting.

```java
Comparator<String> comparator =
    Comparator.nullsFirst(Comparator.naturalOrder());
```

Here, null values appear before non-null values.

```java
Comparator<String> comparator =
    Comparator.nullsLast(Comparator.naturalOrder());
```

Here, null values appear after non-null values.

## 9.8 naturalOrder() and reverseOrder()

```java
Comparator<Integer> ascending =
    Comparator.naturalOrder();

Comparator<Integer> descending =
    Comparator.reverseOrder();
```

### Complete Comparator Helper Methods Example

```java
import java.util.*;

public class ComparatorMethodsDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
            new ArrayList<>(Arrays.asList(50, 10, 40, 20, 30));

        numbers.sort(Comparator.naturalOrder());
        System.out.println("Ascending: " + numbers);

        numbers.sort(Comparator.reverseOrder());
        System.out.println("Descending: " + numbers);

        numbers.sort(Comparator.comparingInt(Integer::intValue));
        System.out.println("Using comparingInt: " + numbers);
    }
}
```

**Output:**

```text
Ascending: [10, 20, 30, 40, 50]
Descending: [50, 40, 30, 20, 10]
Using comparingInt: [10, 20, 30, 40, 50]
```

---

# 10. Comparable vs Comparator

This is a very important interview question.

| Feature | Comparable | Comparator |
|---|---|---|
| Package | java.lang | java.util |
| Purpose | Natural sorting | Custom sorting |
| Method | `compareTo()` | `compare()` |
| Arguments | One object | Two objects |
| Implementation | Class implements Comparable | Separate Comparator or lambda |
| Modification | Usually modifies the class | Does not require modifying the class |
| Sorting criteria | Usually one natural order | Multiple custom orders |
| Java 8 helper methods | No comparable helper chain like Comparator | comparing(), thenComparing(), reversed(), etc. |

### Comparable Example

```java
class Student implements Comparable<Student> {

    int rollNo;

    @Override
    public int compareTo(Student other) {
        return Integer.compare(this.rollNo, other.rollNo);
    }
}
```

### Comparator Example

```java
Comparator<Student> byMarks =
    Comparator.comparingDouble(s -> s.marks);
```

### When to Use?

**Comparable:**

Use it when a class should have one meaningful default sorting order.

**Comparator:**

Use it when the same class needs multiple sorting options.

For example, Student can be sorted by roll number, name, department or marks.

---

# 11. Lab: Student Merit List System

## Problem Statement

Create a Student Merit List System using Java Collections.

Generate the following seven reports:

1. Sort by Roll Number (Ascending).
2. Sort by Name (Ascending).
3. Generate a Merit List by Marks (Descending).
4. Sort by Department (Ascending) and then Name (Ascending).
5. Sort by Department (Ascending) and then Marks (Descending).
6. Sort by Marks (Descending) and then Roll Number (Ascending).
7. Sort by Department (Ascending), Marks (Descending), and then Name (Ascending).

## Concepts Used

- Classes and Objects.
- ArrayList.
- Comparable.
- Comparator.
- Lambda Expressions.
- Comparator Helper Methods.
- `comparing()`.
- `comparingInt()`.
- `comparingDouble()`.
- `thenComparing()`.
- `reversed()`.

## Step 1: Create Student Class

Student contains:

- Roll Number.
- Name.
- Department.
- Marks.

## Step 2: Store Student Objects

Use an ArrayList to store Student objects.

## Step 3: Generate Sorting Reports

Use different Comparator definitions to generate all seven reports.

## Complete Java Program

Save as `StudentMeritListSystem.java`.

```java
import java.util.*;

class Student {

    private int rollNo;
    private String name;
    private String department;
    private double marks;

    public Student(int rollNo, String name,
                   String department, double marks) {

        this.rollNo = rollNo;
        this.name = name;
        this.department = department;
        this.marks = marks;
    }

    public int getRollNo() {
        return rollNo;
    }

    public String getName() {
        return name;
    }

    public String getDepartment() {
        return department;
    }

    public double getMarks() {
        return marks;
    }

    @Override
    public String toString() {

        return String.format(
            "Roll No: %d | Name: %-10s | Department: %-5s | Marks: %.2f",
            rollNo, name, department, marks
        );
    }
}

public class StudentMeritListSystem {

    public static void main(String[] args) {

        List<Student> students = new ArrayList<>();

        // Adding student records
        students.add(new Student(105, "Sushant", "AIML", 85));
        students.add(new Student(101, "Anurag", "AIML", 95));
        students.add(new Student(103, "Rahul", "CSE", 90));
        students.add(new Student(102, "Jayraj", "CSE", 95));
        students.add(new Student(104, "Rudresh", "AIML", 85));
        students.add(new Student(106, "Amit", "CSE", 80));
        students.add(new Student(107, "Karan", "AIML", 90));

        // 1. Roll Number Ascending
        Comparator<Student> byRollNo =
            Comparator.comparingInt(Student::getRollNo);

        // 2. Name Ascending
        Comparator<Student> byName =
            Comparator.comparing(Student::getName);

        // 3. Marks Descending
        Comparator<Student> byMarks =
            Comparator.comparingDouble(Student::getMarks)
                      .reversed();

        // 4. Department Ascending, Name Ascending
        Comparator<Student> byDepartmentThenName =
            Comparator.comparing(Student::getDepartment)
                      .thenComparing(Student::getName);

        // 5. Department Ascending, Marks Descending
        Comparator<Student> byDepartmentThenMarks =
            Comparator.comparing(Student::getDepartment)
                      .thenComparing(
                          Comparator.comparingDouble(Student::getMarks)
                                    .reversed()
                      );

        // 6. Marks Descending, Roll Number Ascending
        Comparator<Student> byMarksThenRollNo =
            Comparator.comparingDouble(Student::getMarks)
                      .reversed()
                      .thenComparingInt(Student::getRollNo);

        // 7. Department Ascending,
        //    Marks Descending, Name Ascending
        Comparator<Student> byDepartmentMarksName =
            Comparator.comparing(Student::getDepartment)
                      .thenComparing(
                          Comparator.comparingDouble(Student::getMarks)
                                    .reversed()
                      )
                      .thenComparing(Student::getName);

        // Generate all reports
        displayReport("1. SORT BY ROLL NUMBER (ASCENDING)",
                      students, byRollNo);

        displayReport("2. SORT BY NAME (ASCENDING)",
                      students, byName);

        displayReport("3. MERIT LIST BY MARKS (DESCENDING)",
                      students, byMarks);

        displayReport("4. DEPARTMENT ASCENDING, NAME ASCENDING",
                      students, byDepartmentThenName);

        displayReport("5. DEPARTMENT ASCENDING, MARKS DESCENDING",
                      students, byDepartmentThenMarks);

        displayReport("6. MARKS DESCENDING, ROLL NUMBER ASCENDING",
                      students, byMarksThenRollNo);

        displayReport(
            "7. DEPARTMENT ASCENDING, MARKS DESCENDING, NAME ASCENDING",
            students, byDepartmentMarksName
        );
    }

    private static void displayReport(
            String title,
            List<Student> students,
            Comparator<Student> comparator) {

        // Copy the original list to avoid changing its order
        List<Student> sortedStudents =
            new ArrayList<>(students);

        sortedStudents.sort(comparator);

        System.out.println("\n==============================================");
        System.out.println(title);
        System.out.println("==============================================");

        for (Student student : sortedStudents) {
            System.out.println(student);
        }
    }
}
```

## Sample Output

```text
==============================================
1. SORT BY ROLL NUMBER (ASCENDING)
==============================================
Roll No: 101 | Name: Anurag     | Department: AIML  | Marks: 95.00
Roll No: 102 | Name: Jayraj     | Department: CSE   | Marks: 95.00
Roll No: 103 | Name: Rahul      | Department: CSE   | Marks: 90.00
Roll No: 104 | Name: Rudresh    | Department: AIML  | Marks: 85.00
Roll No: 105 | Name: Sushant    | Department: AIML  | Marks: 85.00
Roll No: 106 | Name: Amit       | Department: CSE   | Marks: 80.00
Roll No: 107 | Name: Karan      | Department: AIML  | Marks: 90.00

==============================================
2. SORT BY NAME (ASCENDING)
==============================================
Roll No: 106 | Name: Amit       | Department: CSE   | Marks: 80.00
Roll No: 101 | Name: Anurag     | Department: AIML  | Marks: 95.00
Roll No: 102 | Name: Jayraj     | Department: CSE   | Marks: 95.00
Roll No: 107 | Name: Karan      | Department: AIML  | Marks: 90.00
Roll No: 103 | Name: Rahul      | Department: CSE   | Marks: 90.00
Roll No: 104 | Name: Rudresh    | Department: AIML  | Marks: 85.00
Roll No: 105 | Name: Sushant    | Department: AIML  | Marks: 85.00

==============================================
3. MERIT LIST BY MARKS (DESCENDING)
==============================================
Roll No: 101 | Name: Anurag     | Department: AIML  | Marks: 95.00
Roll No: 102 | Name: Jayraj     | Department: CSE   | Marks: 95.00
Roll No: 103 | Name: Rahul      | Department: CSE   | Marks: 90.00
Roll No: 107 | Name: Karan      | Department: AIML  | Marks: 90.00
Roll No: 104 | Name: Rudresh    | Department: AIML  | Marks: 85.00
Roll No: 105 | Name: Sushant    | Department: AIML  | Marks: 85.00
Roll No: 106 | Name: Amit       | Department: CSE   | Marks: 80.00
```

The remaining four reports follow the Comparator definitions in the program.

## Understanding the Seven Sorting Conditions

### Report 1: Roll Number Ascending

```java
Comparator.comparingInt(Student::getRollNo);
```

Example:

```text
101, 102, 103, 104, 105
```

### Report 2: Name Ascending

```java
Comparator.comparing(Student::getName);
```

Example:

```text
Amit, Anurag, Jayraj, Karan, Rahul
```

### Report 3: Marks Descending

```java
Comparator.comparingDouble(Student::getMarks)
          .reversed();
```

Example:

```text
95, 95, 90, 90, 85, 85, 80
```

### Report 4: Department Ascending and Name Ascending

```java
Comparator.comparing(Student::getDepartment)
          .thenComparing(Student::getName);
```

First sorts departments alphabetically, then names alphabetically within each department.

### Report 5: Department Ascending and Marks Descending

```java
Comparator.comparing(Student::getDepartment)
          .thenComparing(
              Comparator.comparingDouble(Student::getMarks)
                        .reversed()
          );
```

First sorts departments alphabetically, then sorts marks in descending order inside each department.

### Report 6: Marks Descending and Roll Number Ascending

```java
Comparator.comparingDouble(Student::getMarks)
          .reversed()
          .thenComparingInt(Student::getRollNo);
```

First sorts marks from highest to lowest. If marks are equal, lower roll number comes first.

### Report 7: Department Ascending, Marks Descending and Name Ascending

```java
Comparator.comparing(Student::getDepartment)
          .thenComparing(
              Comparator.comparingDouble(Student::getMarks)
                        .reversed()
          )
          .thenComparing(Student::getName);
```

This applies three sorting conditions in order:

1. Department ascending.
2. Marks descending.
3. Name ascending.

**Important:** `thenComparing()` applies the next condition only when the preceding comparison considers the two objects equal.

---

# 12. Important Sorting Concepts

## 12.1 Stable Sorting

A stable sorting algorithm preserves the relative order of elements that compare as equal.

Java's List sorting methods are stable.

For example, if two students have the same marks, their relative order from the original list is preserved when sorting only by marks.

## 12.2 Comparator Chaining

Comparator chaining means combining multiple sorting conditions.

```java
Comparator<Student> comparator =
    Comparator.comparing(Student::getDepartment)
              .thenComparing(Student::getName);
```

## 12.3 Method References

Method references provide a shorter way to refer to an existing method.

```java
Student::getName
```

Equivalent lambda expression:

```java
student -> student.getName()
```

## 12.4 Sorting Does Not Require Comparable

A class does not need to implement Comparable if we provide a Comparator explicitly.

```java
students.sort(
    Comparator.comparingDouble(Student::getMarks)
);
```

---

# 13. Interview Questions

### Basic Questions

**1. What is sorting?**

Sorting is arranging elements in ascending or descending order.

**2. What is natural sorting?**

Natural sorting is the default ordering defined by a class using Comparable.

**3. What is Comparable?**

Comparable is an interface used to define natural ordering.

**4. Which method is defined in Comparable?**

`compareTo()`.

**5. What is Comparator?**

Comparator is an interface used to define custom sorting logic.

**6. Which method is defined in Comparator?**

`compare()`.

**7. Which package contains Comparator?**

`java.util`.

**8. Which package contains Comparable?**

`java.lang`.

### Intermediate Questions

**9. What is the difference between Comparable and Comparator?**

Comparable defines natural sorting inside the class; Comparator defines external custom sorting.

**10. Can a class implement both Comparable and Comparator?**

Yes, although Comparator is usually implemented in a separate class or supplied as a lambda.

**11. Can we sort objects without implementing Comparable?**

Yes, by providing a Comparator.

**12. What is an anonymous Comparator?**

An unnamed class implementation of Comparator created directly where needed.

**13. What is a lambda expression?**

A concise way to implement a functional interface.

**14. Why is Comparator a functional interface?**

Because it has one abstract method, `compare()`.

**15. What is the purpose of reversed()?**

It reverses the ordering defined by a Comparator.

### Advanced Questions

**16. What is thenComparing()?**

It adds another sorting condition when the preceding comparison is equal.

**17. What is Comparator.comparing()?**

It creates a Comparator using a selected property.

**18. What is comparingInt()?**

A helper method for creating a Comparator based on an integer property.

**19. What is comparingDouble()?**

A helper method for creating a Comparator based on a double property.

**20. What is stable sorting?**

Stable sorting preserves the relative order of elements considered equal by the comparator.

**21. Can Comparator sort objects using multiple attributes?**

Yes, using `thenComparing()`.

**22. What happens when compare() returns zero?**

The comparator considers the two objects equal for ordering purposes.

**23. Does compare() returning zero always mean equals() returns true?**

No. Comparator ordering and object equality are separate concepts.

**24. Can we use lambda expressions with Comparable?**

A lambda can implement a functional interface, but Comparable is not normally used as a lambda target for sorting because its `compareTo()` belongs to the object itself. Comparator is the standard lambda-based sorting approach.

**25. What is the difference between Collections.sort() and List.sort()?**

Both sort a List. `List.sort()` is an instance method, while `Collections.sort()` is a static utility method.

---

# 14. MCQ Practice

**1. Which interface is used for natural sorting?**

A. Comparator  
B. Comparable  
C. Collection  
D. Iterable  

**Answer:** B. Comparable

**2. Which method belongs to Comparable?**

A. compare()  
B. compareTo()  
C. sort()  
D. equalsTo()  

**Answer:** B. compareTo()

**3. Which interface is used for custom sorting?**

A. Comparable  
B. Comparator  
C. List  
D. Set  

**Answer:** B. Comparator

**4. Which method belongs to Comparator?**

A. compareTo()  
B. compare()  
C. sort()  
D. reverse()  

**Answer:** B. compare()

**5. Which Comparator method reverses sorting order?**

A. reverse()  
B. reversed()  
C. descending()  
D. reverseOrderBy()  

**Answer:** B. reversed()

**6. Which method is used for multiple sorting conditions?**

A. comparing()  
B. thenComparing()  
C. compareTo()  
D. equals()  

**Answer:** B. thenComparing()

**7. Which Java feature was introduced in Java 8 for concise Comparator implementations?**

A. Constructors  
B. Lambda expressions  
C. Packages  
D. Inheritance  

**Answer:** B. Lambda expressions

**8. Which method is used to sort an ArrayList?**

A. Collections.sort()  
B. Collections.reverse()  
C. Collections.max()  
D. Collections.swap()  

**Answer:** A. Collections.sort()

**9. Which Comparator helper method is suitable for an integer property?**

A. comparingDouble()  
B. comparingInt()  
C. comparingLong()  
D. comparingString()  

**Answer:** B. comparingInt()

**10. Which interface belongs to java.util?**

A. Comparable  
B. Comparator  
C. Runnable  
D. Serializable  

**Answer:** B. Comparator

**11. What does compare() returning a negative value mean?**

A. First object comes before second  
B. First object comes after second  
C. Both are equal  
D. Sorting fails  

**Answer:** A. First object comes before second

**12. Can a Comparator sort by department and then marks?**

A. No  
B. Yes, using thenComparing()  
C. Only using Comparable  
D. Only using TreeSet  

**Answer:** B. Yes, using thenComparing()

---

# 15. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Sorting | Arranging elements in an order |
| Natural Sorting | Default sorting order |
| Comparable | Defines natural ordering |
| `compareTo()` | Comparable method |
| Comparator | Defines custom sorting |
| `compare()` | Comparator method |
| Anonymous Class | Unnamed class implementation |
| Lambda | Short implementation of functional interface |
| `Collections.sort()` | Sorts List |
| `List.sort()` | Sorts List |
| `comparing()` | Sorts using a selected property |
| `comparingInt()` | Integer-based sorting |
| `comparingDouble()` | Double-based sorting |
| `thenComparing()` | Adds another sorting condition |
| `reversed()` | Reverses Comparator ordering |
| `nullsFirst()` | Places null values first |
| `nullsLast()` | Places null values last |
| Stable Sorting | Preserves relative order of equal elements |

---

# 16. Practical Checklist

- [ ] Understand sorting in Java Collections.
- [ ] Learn natural sorting.
- [ ] Implement Comparable.
- [ ] Understand compareTo().
- [ ] Implement Comparator.
- [ ] Understand compare().
- [ ] Practice anonymous Comparator implementation.
- [ ] Practice Comparator using lambda expressions.
- [ ] Learn Comparator.comparing().
- [ ] Learn thenComparing().
- [ ] Learn reversed().
- [ ] Practice comparingInt() and comparingDouble().
- [ ] Understand multiple-attribute sorting.
- [ ] Complete Student Merit List System.
- [ ] Generate all seven sorting reports.
- [ ] Revise interview questions and MCQs.

---

# 17. Additional Practice Assignments

1. Create an Employee Management System and sort employees by salary.
2. Sort employees by department and then salary.
3. Create a Product List and sort products by price.
4. Sort books alphabetically by title.
5. Sort students by marks and then name.
6. Sort employees by joining date.
7. Implement custom sorting using an anonymous Comparator.
8. Implement the same sorting using a lambda expression.
9. Sort strings by length.
10. Sort students by marks descending and roll number ascending.

---

## Recommended Folder Structure

```text
Java/
└── Session-24-Sorting-Collections/
    ├── README.md
    └── programs/
        ├── SortingDemo.java
        ├── NaturalSortingDemo.java
        ├── ComparableDemo.java
        ├── ComparatorDemo.java
        ├── AnonymousComparatorDemo.java
        ├── LambdaComparatorDemo.java
        ├── ComparatorMethodsDemo.java
        └── StudentMeritListSystem.java
```

---

**End of Session 24 – Sorting Collections in Java**

*These notes cover the CMCE August 2026 syllabus, Java 8+ Comparator features, Java 17 examples and the Student Merit List practical assignment.*

