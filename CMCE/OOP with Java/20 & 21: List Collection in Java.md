

# Sessions 20 & 21: List Collection in Java

**Course:** CDAC CMCE – August 2026 Batch  
**Subject:** Core Java  
**Topics:** List, ArrayList, LinkedList, Vector and Collections Class  
**Theory:** 4 Hours | **Lab:** 4 Hours

---

## Table of Contents

1. [Introduction to List Collection](#1-introduction-to-list-collection)
2. [ArrayList](#2-arraylist)
3. [LinkedList](#3-linkedlist)
4. [Vector](#4-vector)
5. [ArrayList vs LinkedList vs Vector](#5-arraylist-vs-linkedlist-vs-vector)
6. [Collections Utility Class](#6-collections-utility-class)
7. [Lab 1: Student Management System](#7-lab-1-student-management-system-using-arraylist)
8. [Lab 2: Task Management System](#8-lab-2-task-management-system-using-linkedlist)
9. [Time Complexity](#9-time-complexity)
10. [Interview Questions](#10-interview-questions)
11. [MCQ Practice](#11-mcq-practice)
12. [Quick Revision Notes](#12-quick-revision-notes)

---

# 1. Introduction to List Collection

The **List** is an interface in the Java Collection Framework. It is used to store a group of objects in an ordered sequence.

A List allows:

- Duplicate elements.
- Null elements in common implementations.
- Maintaining insertion order.
- Accessing elements using indexes.
- Inserting, updating and deleting elements.

### List Hierarchy

```text
                 Iterable
                    |
                Collection
                    |
                   List
                    |
       +------------+------------+
       |            |            |
   ArrayList    LinkedList     Vector
                                  |
                                Stack
```

### Important Points

- `List` is an interface.
- `ArrayList`, `LinkedList` and `Vector` are implementations of List.
- Indexing starts from `0`.
- List maintains insertion order.
- List allows duplicate elements.

### Syntax

```java
List<String> names = new ArrayList<>();

names.add("Anurag");
names.add("Rahul");
names.add("Sushant");

System.out.println(names);
```

**Output:**

```text
[Anurag, Rahul, Sushant]
```

---

# 2. ArrayList

## 2.1 Introduction

`ArrayList` is a resizable-array implementation of the List interface.

Unlike normal arrays, an ArrayList can automatically grow or shrink when elements are added or removed.

### Features

1. Maintains insertion order.
2. Allows duplicate elements.
3. Allows null values.
4. Supports index-based access.
5. Dynamic in size.
6. Not synchronized.
7. Provides fast random access.

### Declaration

```java
import java.util.ArrayList;
import java.util.List;

List<String> names = new ArrayList<>();
```

### Internal Working

An ArrayList internally uses an array.

When its internal storage becomes insufficient, it creates a larger array and transfers the existing elements.

Conceptual representation:

```text
Index:       0        1        2        3
          +--------+--------+--------+--------+
Array:    | Anurag | Rahul  | Sushant| Jayraj |
          +--------+--------+--------+--------+
```

The internal capacity and growth strategy are implementation details.

## 2.2 Important ArrayList Methods

| Method | Description |
|---|---|
| `add(element)` | Adds an element |
| `add(index, element)` | Inserts at an index |
| `get(index)` | Retrieves an element |
| `set(index, element)` | Replaces an element |
| `remove(index)` | Removes by index |
| `remove(object)` | Removes matching object |
| `contains(element)` | Checks whether an element exists |
| `indexOf(element)` | Returns first matching index |
| `lastIndexOf(element)` | Returns last matching index |
| `size()` | Returns number of elements |
| `isEmpty()` | Checks whether list is empty |
| `clear()` | Removes all elements |

## 2.3 ArrayList Program

```java
import java.util.*;

public class ArrayListDemo {
    public static void main(String[] args) {

        ArrayList<String> names = new ArrayList<>();

        // Add elements
        names.add("Anurag");
        names.add("Rahul");
        names.add("Sushant");

        System.out.println("Original List: " + names);

        // Insert at index
        names.add(1, "Jayraj");

        System.out.println("After Insertion: " + names);

        // Access element
        System.out.println("Element at index 2: " + names.get(2));

        // Replace element
        names.set(0, "Rudresh");

        System.out.println("After Replacement: " + names);

        // Search element
        System.out.println("Contains Rahul: " + names.contains("Rahul"));

        // Delete element
        names.remove("Rahul");

        System.out.println("After Deletion: " + names);

        // Iterate
        for (String name : names) {
            System.out.println(name);
        }

        // Size
        System.out.println("Size: " + names.size());
    }
}
```

### Output

```text
Original List: [Anurag, Rahul, Sushant]
After Insertion: [Anurag, Jayraj, Rahul, Sushant]
Element at index 2: Rahul
After Replacement: [Rudresh, Jayraj, Rahul, Sushant]
Contains Rahul: true
After Deletion: [Rudresh, Jayraj, Sushant]
Rudresh
Jayraj
Sushant
Size: 3
```

---

# 3. LinkedList

## 3.1 Introduction

`LinkedList` is a doubly linked-list implementation of the List and Deque interfaces.

Unlike ArrayList, which stores elements in an array, LinkedList stores elements as nodes.

Each node contains:

1. Previous node reference.
2. Data.
3. Next node reference.

### Internal Structure

```text
NULL <- [10] <-> [20] <-> [30] -> NULL
```

Each node is connected to its previous and next nodes.

### Features

- Maintains insertion order.
- Allows duplicate elements.
- Allows null values.
- Supports index-based operations.
- Efficient insertion and deletion at the ends.
- Implements both List and Deque.
- Not synchronized.
- Random access is slower than ArrayList.

## 3.2 Declaration

```java
import java.util.LinkedList;

LinkedList<String> tasks = new LinkedList<>();
```

## 3.3 Important LinkedList Methods

| Method | Description |
|---|---|
| `add(element)` | Adds element at end |
| `addFirst(element)` | Adds at beginning |
| `addLast(element)` | Adds at end |
| `getFirst()` | Retrieves first element |
| `getLast()` | Retrieves last element |
| `removeFirst()` | Removes first element |
| `removeLast()` | Removes last element |
| `peek()` | Retrieves head without removing |
| `poll()` | Retrieves and removes head |
| `size()` | Returns number of elements |

## 3.4 LinkedList Program

```java
import java.util.*;

public class LinkedListDemo {
    public static void main(String[] args) {

        LinkedList<String> tasks = new LinkedList<>();

        // Add elements
        tasks.add("Study Java");
        tasks.add("Practice SQL");

        // Add at beginning
        tasks.addFirst("Attend Lecture");

        // Add at end
        tasks.addLast("Solve MCQs");

        System.out.println("Tasks: " + tasks);

        // Access first and last
        System.out.println("First Task: " + tasks.getFirst());
        System.out.println("Last Task: " + tasks.getLast());

        // Remove first
        tasks.removeFirst();

        System.out.println("After Removal: " + tasks);

        // Iterate
        for (String task : tasks) {
            System.out.println(task);
        }
    }
}
```

### Output

```text
Tasks: [Attend Lecture, Study Java, Practice SQL, Solve MCQs]
First Task: Attend Lecture
Last Task: Solve MCQs
After Removal: [Study Java, Practice SQL, Solve MCQs]
Study Java
Practice SQL
Solve MCQs
```

---

# 4. Vector

## 4.1 Introduction

`Vector` is a legacy resizable-array implementation of the List interface.

It is similar to ArrayList, but Vector synchronizes its individual methods.

### Features

1. Maintains insertion order.
2. Allows duplicate elements.
3. Allows null values.
4. Supports index-based access.
5. Automatically increases capacity.
6. Individual methods are synchronized.
7. It is a legacy collection class.

### Declaration

```java
Vector<Integer> numbers = new Vector<>();
```

## 4.2 Important Vector Methods

| Method | Description |
|---|---|
| `add()` | Adds element |
| `insertElementAt()` | Inserts element at index |
| `remove()` | Removes element |
| `removeElement()` | Removes matching element |
| `elementAt()` | Retrieves element at index |
| `setElementAt()` | Replaces element |
| `contains()` | Searches element |
| `indexOf()` | Finds element index |
| `sort()` | Sorts elements through List sorting |
| `elements()` | Returns Enumeration |
| `capacity()` | Returns current capacity |
| `size()` | Returns current element count |

## 4.3 Vector Program: Insert, Delete, Search, Sort, Iterate and Replace

```java
import java.util.*;

public class VectorDemo {
    public static void main(String[] args) {

        Vector<Integer> numbers = new Vector<>();

        // Insert
        numbers.add(30);
        numbers.add(10);
        numbers.add(20);
        numbers.insertElementAt(40, 1);

        System.out.println("Inserted: " + numbers);

        // Search
        System.out.println("Index of 20: " + numbers.indexOf(20));

        // Replace
        numbers.setElementAt(50, 1);

        System.out.println("Replaced: " + numbers);

        // Sort
        Collections.sort(numbers);

        System.out.println("Sorted: " + numbers);

        // Delete
        numbers.remove(Integer.valueOf(30));

        System.out.println("Deleted: " + numbers);

        // Iterate
        for (Integer number : numbers) {
            System.out.println(number);
        }
    }
}
```

### Output

```text
Inserted: [30, 40, 10, 20]
Index of 20: 3
Replaced: [30, 50, 10, 20]
Sorted: [10, 20, 30, 50]
Deleted: [10, 20, 50]
10
20
50
```

### Important: Vector Capacity vs Size

```java
Vector<Integer> v = new Vector<>();

System.out.println(v.size());
System.out.println(v.capacity());
```

**Output:**

```text
0
10
```

- Size: Number of stored elements.
- Capacity: Current allocated storage capacity.
- Default initial capacity of a no-argument Vector is 10.

---

# 5. ArrayList vs LinkedList vs Vector

| Feature | ArrayList | LinkedList | Vector |
|---|---|---|---|
| Internal structure | Dynamic array | Doubly linked list | Dynamic array |
| Insertion order | Yes | Yes | Yes |
| Duplicates | Yes | Yes | Yes |
| Null values | Yes | Yes | Yes |
| Random access | Fast | Slow | Fast |
| Synchronization | No | No | Yes, individual methods |
| Insertion at beginning | O(n) | O(1) | O(n) |
| Access by index | O(1) | O(n) | O(1) |
| Legacy class | No | No | Yes |

### When to Use Which?

**ArrayList**
- When frequent element access is required.
- When searching by index is common.
- General-purpose List implementation.

**LinkedList**
- When frequent insertion/removal at the beginning or end is required.
- When implementing queue or deque operations.

**Vector**
- When working with legacy code that expects Vector.
- For new applications, ArrayList with suitable synchronization or concurrent collections is usually preferable.

---

# 6. Collections Utility Class

## 6.1 Introduction

`Collections` is a utility class available in the `java.util` package.

It provides static methods to perform common operations on collections.

**Important distinction:**

- `Collection` is an interface.
- `Collections` is a utility class.

## 6.2 Important Methods

| Method | Description |
|---|---|
| `Collections.sort(list)` | Sorts elements in ascending order |
| `Collections.reverse(list)` | Reverses list |
| `Collections.shuffle(list)` | Randomly shuffles elements |
| `Collections.max(list)` | Finds maximum element |
| `Collections.min(list)` | Finds minimum element |
| `Collections.frequency(list, x)` | Counts occurrences |
| `Collections.binarySearch(list, x)` | Searches sorted list |
| `Collections.swap(list, i, j)` | Swaps two elements |
| `Collections.fill(list, x)` | Replaces every element |
| `Collections.copy(dest, src)` | Copies source elements into destination |
| `Collections.synchronizedList(list)` | Creates synchronized List wrapper |

## 6.3 Collections Program

```java
import java.util.*;

public class CollectionsDemo {
    public static void main(String[] args) {

        List<Integer> nums = new ArrayList<>(
                Arrays.asList(40, 10, 30, 20, 10));

        // Sorting
        Collections.sort(nums);
        System.out.println("Sorted: " + nums);

        // Binary Search
        System.out.println("Index of 30: " +
                Collections.binarySearch(nums, 30));

        // Frequency
        System.out.println("Frequency of 10: " +
                Collections.frequency(nums, 10));

        // Reverse
        Collections.reverse(nums);
        System.out.println("Reversed: " + nums);

        // Maximum and Minimum
        System.out.println("Maximum: " + Collections.max(nums));
        System.out.println("Minimum: " + Collections.min(nums));

        // Swap
        Collections.swap(nums, 0, 1);
        System.out.println("After Swap: " + nums);
    }
}
```

### Output

```text
Sorted: [10, 10, 20, 30, 40]
Index of 30: 3
Frequency of 10: 2
Reversed: [40, 30, 20, 10, 10]
Maximum: 40
Minimum: 10
After Swap: [30, 40, 20, 10, 10]
```

**Note:** `binarySearch()` requires the list to be sorted according to the same ordering used for searching.

---

# 7. Lab 1: Student Management System Using ArrayList

## Problem Statement

Create a Student Management System using an ArrayList to store student details.

The application should support:

1. Add Student.
2. Search Student by Roll Number.
3. Update Student Details.
4. Delete Student.
5. Display All Students.

## Concepts Used

- Classes and Objects.
- Encapsulation.
- Constructors.
- ArrayList.
- CRUD operations.
- Loops and switch statements.
- Searching and updating objects.

## Complete Java Program

Save as `StudentManagementSystem.java`.

```java
import java.util.ArrayList;
import java.util.Scanner;

class Student {

    private int rollNo;
    private String name;
    private double marks;

    public Student(int rollNo, String name, double marks) {
        this.rollNo = rollNo;
        this.name = name;
        this.marks = marks;
    }

    public int getRollNo() {
        return rollNo;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setMarks(double marks) {
        this.marks = marks;
    }

    @Override
    public String toString() {
        return "Roll No: " + rollNo +
                ", Name: " + name +
                ", Marks: " + marks;
    }
}

public class StudentManagementSystem {

    private static final ArrayList<Student> students =
            new ArrayList<>();

    private static final Scanner sc = new Scanner(System.in);

    private static Student findStudent(int rollNo) {

        for (Student student : students) {

            if (student.getRollNo() == rollNo) {
                return student;
            }
        }

        return null;
    }

    private static void addStudent() {

        System.out.print("Enter Roll Number: ");
        int rollNo = Integer.parseInt(sc.nextLine());

        if (rollNo <= 0 || findStudent(rollNo) != null) {
            System.out.println("Invalid or duplicate roll number.");
            return;
        }

        System.out.print("Enter Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Marks: ");
        double marks = Double.parseDouble(sc.nextLine());

        students.add(new Student(rollNo, name, marks));

        System.out.println("Student added successfully.");
    }

    private static void searchStudent() {

        System.out.print("Enter Roll Number: ");
        int rollNo = Integer.parseInt(sc.nextLine());

        Student student = findStudent(rollNo);

        if (student != null) {
            System.out.println(student);
        } else {
            System.out.println("Student not found.");
        }
    }

    private static void updateStudent() {

        System.out.print("Enter Roll Number: ");
        int rollNo = Integer.parseInt(sc.nextLine());

        Student student = findStudent(rollNo);

        if (student != null) {

            System.out.print("Enter New Name: ");
            String name = sc.nextLine();

            System.out.print("Enter New Marks: ");
            double marks = Double.parseDouble(sc.nextLine());

            student.setName(name);
            student.setMarks(marks);

            System.out.println("Student updated successfully.");

        } else {
            System.out.println("Student not found.");
        }
    }

    private static void deleteStudent() {

        System.out.print("Enter Roll Number: ");
        int rollNo = Integer.parseInt(sc.nextLine());

        Student student = findStudent(rollNo);

        if (student != null) {
            students.remove(student);
            System.out.println("Student deleted successfully.");
        } else {
            System.out.println("Student not found.");
        }
    }

    private static void displayStudents() {

        if (students.isEmpty()) {
            System.out.println("No students available.");
            return;
        }

        System.out.println("\n--- Student Records ---");

        for (Student student : students) {
            System.out.println(student);
        }
    }

    public static void main(String[] args) {

        while (true) {

            System.out.println("\n--- STUDENT MANAGEMENT SYSTEM ---");
            System.out.println("1. Add Student");
            System.out.println("2. Search Student");
            System.out.println("3. Update Student");
            System.out.println("4. Delete Student");
            System.out.println("5. Display All Students");
            System.out.println("6. Exit");

            System.out.print("Enter Choice: ");
            int choice = Integer.parseInt(sc.nextLine());

            switch (choice) {

                case 1:
                    addStudent();
                    break;

                case 2:
                    searchStudent();
                    break;

                case 3:
                    updateStudent();
                    break;

                case 4:
                    deleteStudent();
                    break;

                case 5:
                    displayStudents();
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

## Sample Output

```text
--- STUDENT MANAGEMENT SYSTEM ---
1. Add Student
2. Search Student
3. Update Student
4. Delete Student
5. Display All Students
6. Exit

Enter Choice: 1
Enter Roll Number: 101
Enter Name: Anurag
Enter Marks: 89

Student added successfully.

Enter Choice: 5

--- Student Records ---
Roll No: 101, Name: Anurag, Marks: 89.0

Enter Choice: 2
Enter Roll Number: 101

Roll No: 101, Name: Anurag, Marks: 89.0
```

## Explanation

**Add Student:** Creates a Student object and stores it using `students.add()`.

**Search Student:** Iterates over the ArrayList and compares the roll number.

**Update Student:** Finds the Student object and modifies its name and marks using setter methods.

**Delete Student:** Finds the matching object and removes it from the ArrayList.

**Display Students:** Iterates over all objects and prints their details.

### CRUD Mapping

| Operation | ArrayList Method / Logic |
|---|---|
| Create | `add()` |
| Read | `get()` / iteration / search |
| Update | `set()` or object setter methods |
| Delete | `remove()` |

---

# 8. Lab 2: Task Management System Using LinkedList

## Problem Statement

Implement a Task Management System using LinkedList.

The system should support:

1. Add Task.
2. Remove Task.
3. Mark Task as Completed.
4. Display Pending Tasks.

## Concepts Used

- LinkedList.
- Classes and Objects.
- Encapsulation.
- Constructors.
- Iteration.
- Searching.
- Boolean status management.

## Complete Java Program

Save as `TaskManagementSystem.java`.

```java
import java.util.LinkedList;
import java.util.Scanner;

class Task {

    private final int taskId;
    private final String description;
    private boolean completed;

    public Task(int taskId, String description) {
        this.taskId = taskId;
        this.description = description;
        this.completed = false;
    }

    public int getTaskId() {
        return taskId;
    }

    public boolean isCompleted() {
        return completed;
    }

    public void markCompleted() {
        completed = true;
    }

    @Override
    public String toString() {
        return "Task ID: " + taskId +
                ", Description: " + description +
                ", Status: " +
                (completed ? "Completed" : "Pending");
    }
}

public class TaskManagementSystem {

    private static final LinkedList<Task> tasks =
            new LinkedList<>();

    private static final Scanner sc = new Scanner(System.in);

    private static int nextTaskId = 1;

    private static Task findTask(int taskId) {

        for (Task task : tasks) {

            if (task.getTaskId() == taskId) {
                return task;
            }
        }

        return null;
    }

    private static void addTask() {

        System.out.print("Enter Task Description: ");
        String description = sc.nextLine();

        if (description.trim().isEmpty()) {
            System.out.println("Description cannot be empty.");
            return;
        }

        Task task = new Task(nextTaskId++, description);

        tasks.addLast(task);

        System.out.println("Task added successfully.");
    }

    private static void removeTask() {

        System.out.print("Enter Task ID: ");
        int taskId = Integer.parseInt(sc.nextLine());

        Task task = findTask(taskId);

        if (task != null) {

            tasks.remove(task);

            System.out.println("Task removed successfully.");

        } else {
            System.out.println("Task not found.");
        }
    }

    private static void completeTask() {

        System.out.print("Enter Task ID: ");
        int taskId = Integer.parseInt(sc.nextLine());

        Task task = findTask(taskId);

        if (task != null) {

            task.markCompleted();

            System.out.println("Task marked as completed.");

        } else {
            System.out.println("Task not found.");
        }
    }

    private static void displayPendingTasks() {

        boolean found = false;

        System.out.println("\n--- Pending Tasks ---");

        for (Task task : tasks) {

            if (!task.isCompleted()) {

                System.out.println(task);
                found = true;
            }
        }

        if (!found) {
            System.out.println("No pending tasks.");
        }
    }

    public static void main(String[] args) {

        while (true) {

            System.out.println("\n--- TASK MANAGEMENT SYSTEM ---");
            System.out.println("1. Add Task");
            System.out.println("2. Remove Task");
            System.out.println("3. Mark Task as Completed");
            System.out.println("4. Display Pending Tasks");
            System.out.println("5. Exit");

            System.out.print("Enter Choice: ");
            int choice = Integer.parseInt(sc.nextLine());

            switch (choice) {

                case 1:
                    addTask();
                    break;

                case 2:
                    removeTask();
                    break;

                case 3:
                    completeTask();
                    break;

                case 4:
                    displayPendingTasks();
                    break;

                case 5:
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

## Sample Output

```text
--- TASK MANAGEMENT SYSTEM ---
1. Add Task
2. Remove Task
3. Mark Task as Completed
4. Display Pending Tasks
5. Exit

Enter Choice: 1
Enter Task Description: Study Java Collections
Task added successfully.

Enter Choice: 1
Enter Task Description: Solve MCQs
Task added successfully.

Enter Choice: 3
Enter Task ID: 1
Task marked as completed.

Enter Choice: 4

--- Pending Tasks ---
Task ID: 2, Description: Solve MCQs, Status: Pending
```

## Explanation

- Each task is represented by a Task object.
- The LinkedList stores multiple Task objects.
- `addLast()` inserts a task at the end.
- `findTask()` searches for a task by ID.
- `markCompleted()` changes its status.
- `remove()` deletes the selected task.
- `displayPendingTasks()` displays only tasks whose completed status is false.

---

# 9. Time Complexity

| Operation | ArrayList | LinkedList | Vector |
|---|---|---|---|
| Access by index | O(1) | O(n) | O(1) |
| Search by value | O(n) | O(n) | O(n) |
| Add at end | O(1) amortized | O(1) | O(1) amortized |
| Insert at beginning | O(n) | O(1) | O(n) |
| Remove first | O(n) | O(1) | O(n) |
| Remove last | O(1) | O(1) | O(1) |

**Note:** These are typical complexity expectations. LinkedList insertion/deletion is O(1) once the required node is located; finding that node may take O(n).

---

# 10. Interview Questions

### Basic Questions

**1. What is List in Java?**

List is an interface in the Collection Framework that maintains insertion order and allows duplicate elements.

**2. Which classes implement List?**

ArrayList, LinkedList and Vector are commonly used List implementations.

**3. Does List allow duplicates?**

Yes, List allows duplicate elements.

**4. Does List maintain insertion order?**

Yes.

**5. What is ArrayList?**

ArrayList is a resizable-array implementation of the List interface.

**6. What is LinkedList?**

LinkedList is a doubly linked-list implementation of List and Deque.

**7. What is Vector?**

Vector is a legacy synchronized resizable-array implementation of List.

### Intermediate Questions

**8. What is the difference between ArrayList and LinkedList?**

ArrayList uses a dynamic array, whereas LinkedList uses doubly linked nodes.

**9. Why is ArrayList faster for accessing elements?**

It supports direct index-based access.

**10. Why is LinkedList efficient for insertion at the beginning?**

It can update its head and node links without shifting an array's elements.

**11. Is ArrayList synchronized?**

No.

**12. Is Vector synchronized?**

Its individual methods are synchronized.

**13. Can LinkedList be used as a Queue?**

Yes. It implements Deque and Queue.

**14. What is the difference between size and capacity?**

Size is the number of elements stored; capacity is the allocated internal storage.

**15. What is Collections class?**

Collections is a utility class providing static methods to manipulate collections.

### Advanced Questions

**16. What is the difference between Collection and Collections?**

Collection is an interface, while Collections is a utility class.

**17. What is `Collections.sort()`?**

It sorts the elements of a list.

**18. What is `Collections.binarySearch()`?**

It searches a sorted list using binary search.

**19. What happens if an invalid index is passed to `get()`?**

It throws IndexOutOfBoundsException.

**20. What is the difference between `remove(1)` and `remove(Integer.valueOf(1))`?**

The first removes the element at index 1; the second removes the matching Integer object.

**21. Can ArrayList store user-defined objects?**

Yes. For example, `ArrayList<Student>` stores Student objects.

**22. What is the default initial capacity of Vector?**

10.

**23. Is LinkedList synchronized?**

No.

**24. Which collection would you use for frequent index access?**

ArrayList.

**25. Which collection would you use for queue operations at both ends?**

LinkedList or ArrayDeque, depending on requirements.

---

# 11. MCQ Practice

**1. Which interface is implemented by ArrayList?**

A. Set  
B. List  
C. Map  
D. Queue  

**Answer:** B. List

**2. Which collection uses a doubly linked list?**

A. ArrayList  
B. Vector  
C. LinkedList  
D. HashSet  

**Answer:** C. LinkedList

**3. Which collection is synchronized?**

A. ArrayList  
B. LinkedList  
C. Vector  
D. HashSet  

**Answer:** C. Vector

**4. Which method is used to replace an element in List?**

A. add()  
B. set()  
C. update()  
D. replace()  

**Answer:** B. set()

**5. Which class provides sorting and searching utility methods?**

A. Collection  
B. Collections  
C. List  
D. ArraysList  

**Answer:** B. Collections

**6. Which method reverses a List?**

A. sort()  
B. reverse()  
C. swap()  
D. shuffle()  

**Answer:** B. reverse()

**7. Which method returns the number of elements?**

A. capacity()  
B. length()  
C. size()  
D. count()  

**Answer:** C. size()

**8. Which method adds an element at the end of LinkedList?**

A. addLast()  
B. getLast()  
C. removeLast()  
D. setLast()  

**Answer:** A. addLast()

**9. What is the time complexity of ArrayList index access?**

A. O(n)  
B. O(log n)  
C. O(1)  
D. O(n²)  

**Answer:** C. O(1)

**10. Which method searches for an element in ArrayList?**

A. contains()  
B. insert()  
C. replace()  
D. sort()  

**Answer:** A. contains()

---

# 12. Quick Revision Notes

| Topic | Important Point |
|---|---|
| List | Ordered collection, allows duplicates |
| ArrayList | Resizable array |
| LinkedList | Doubly linked list |
| Vector | Synchronized legacy List |
| `add()` | Insert element |
| `get()` | Retrieve element |
| `set()` | Replace element |
| `remove()` | Delete element |
| `contains()` | Search element |
| `Collections.sort()` | Sort list |
| `Collections.reverse()` | Reverse list |
| `Collections.max()` | Find maximum |
| `Collections.min()` | Find minimum |
| `Collections.frequency()` | Count occurrences |
| `Collections.binarySearch()` | Search sorted list |

## Practical Checklist

- [ ] Understand List interface and hierarchy.
- [ ] Practice ArrayList operations.
- [ ] Practice LinkedList operations.
- [ ] Practice Vector insert, delete, search, sort, iterate and replace.
- [ ] Understand ArrayList vs LinkedList vs Vector.
- [ ] Practice Collections utility methods.
- [ ] Complete Student Management System.
- [ ] Complete Task Management System.
- [ ] Practice time complexity.
- [ ] Revise interview questions and MCQs.

## Additional Practice Assignments

1. Create an Employee Management System using ArrayList.
2. Store product details and search products by product ID.
3. Sort student records by marks using Comparator.
4. Create a playlist manager using LinkedList.
5. Implement undo operations using a stack.
6. Remove duplicate elements from an ArrayList.
7. Find the second-highest number in an ArrayList.
8. Sort strings alphabetically using Collections.sort().

---

**End of Sessions 20 & 21 – List Collection in Java**

*These notes cover the CMCE August 2026 syllabus topics and associated practical assignments. Examples use Java 17 syntax.*

