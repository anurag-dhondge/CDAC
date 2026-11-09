# Session 28: Multithreading and Synchronization in Java

**Course:** CDAC – CMCE / PGCP-AC  
**Session:** 28  
**Topics:** Multithreading, Thread Synchronization, Inter-thread Communication, Concurrent Collections, Metadata and Reflection  
**Java Version:** Java 17

---

## Table of Contents

1. [Introduction to Multithreading](#1-introduction-to-multithreading)
2. [Creating Threads Using Thread Class](#2-creating-threads-using-thread-class)
3. [Creating Threads Using Runnable Interface](#3-creating-threads-using-runnable-interface)
4. [Thread Life Cycle](#4-thread-life-cycle)
5. [Thread Methods](#5-thread-methods)
6. [ThreadGroup Class](#6-threadgroup-class)
7. [Synchronization](#7-synchronization)
8. [Inter-thread Communication: wait, notify and notifyAll](#8-inter-thread-communication-wait-notify-and-notifyall)
9. [Concurrent Collections – ConcurrentHashMap](#9-concurrent-collections--concurrenthashmap)
10. [ThreadLocal – Thread-local Data](#10-threadlocal--thread-local-data)
11. [Metadata and Reflection](#11-metadata-and-reflection)
12. [Anonymous Inner Classes and Lambda Expressions](#12-anonymous-inner-classes-and-lambda-expressions)
13. [Practical Lab Programs](#13-practical-lab-programs)
14. [Thread Class vs Runnable Interface](#14-thread-class-vs-runnable-interface)
15. [Interview Questions and Answers](#15-interview-questions-and-answers)
16. [MCQs](#16-mcqs)
17. [Quick Revision Notes](#17-quick-revision-notes)

---

# 1. Introduction to Multithreading

## 1.1 What is a Thread?

A **thread** is the smallest unit of execution within a process.

A Java program can execute multiple threads simultaneously. Each thread performs an independent task while sharing the process's resources.

**Example:** Consider a music application:

- One thread plays music.
- Another thread downloads songs.
- Another thread updates the user interface.

These tasks can progress concurrently.

## 1.2 What is Multithreading?

Multithreading is the process of executing multiple threads within a single program.

It helps applications perform multiple tasks without waiting for one task to finish before starting another.

### Real-world examples

| Application | Threads |
|---|---|
| Web browser | Loading pages, downloading files |
| Music player | Playing music, updating controls |
| Banking application | Processing multiple requests |
| Online shopping | Payment, inventory, notifications |
| Video player | Video playback, audio playback |

## 1.3 Process vs Thread

| Process | Thread |
|---|---|
| Program in execution | Smallest execution unit within a process |
| Has its own memory space | Shares process resources |
| More resource-intensive | Generally lightweight |
| Processes are isolated | Threads can communicate through shared data |
| Communication is comparatively expensive | Communication can be easier through shared memory |

## 1.4 Advantages of Multithreading

1. **Responsiveness:** Applications remain responsive while background tasks execute.
2. **Resource sharing:** Threads share process resources.
3. **Concurrency:** Multiple tasks can make progress.
4. **Better CPU utilization:** Multiple cores can execute threads in parallel.
5. **Efficient applications:** Useful for servers, games and background processing.

## 1.5 Concurrency vs Parallelism

**Concurrency:** Multiple tasks make progress during overlapping periods. They may take turns on one CPU core.

**Parallelism:** Multiple tasks execute at exactly the same time on different CPU cores.

Multithreading can provide concurrency and, on multicore systems, parallelism.

---

# 2. Creating Threads Using Thread Class

Java provides the `Thread` class in the `java.lang` package.

We can create a thread by extending the Thread class and overriding its `run()` method.

### Syntax

```java
class MyThread extends Thread {

    @Override
    public void run() {
        System.out.println("Thread is running");
    }
}
```

### Starting a thread

```java
public class ThreadDemo {

    public static void main(String[] args) {

        MyThread t1 = new MyThread();

        t1.start();
    }
}
```

**Output:**

```text
Thread is running
```

### Important: start() vs run()

| start() | run() |
|---|---|
| Starts a new thread of execution | Executes like a normal method call if called directly |
| JVM schedules the new thread | No new thread is created by a direct call |
| Internally causes run() to execute | Contains the task logic |

Example:

```java
class MyThread extends Thread {

    public void run() {
        System.out.println(
            "Running on: " + Thread.currentThread().getName()
        );
    }
}

public class Main {

    public static void main(String[] args) {

        MyThread t1 = new MyThread();

        t1.start();

        System.out.println(
            "Main: " + Thread.currentThread().getName()
        );
    }
}
```

Possible output:

```text
Main: main
Running on: Thread-0
```

The order may change because thread scheduling is controlled by the JVM and operating system.

**Important:** A Thread object can be started only once. Calling `start()` again on the same Thread object causes `IllegalThreadStateException`.

---

# 3. Creating Threads Using Runnable Interface

`Runnable` is a functional interface in Java.

It contains one abstract method:

```java
public void run();
```

We can implement Runnable and pass its object to a Thread.

### Syntax

```java
class MyTask implements Runnable {

    @Override
    public void run() {
        System.out.println("Runnable task running");
    }
}
```

### Main class

```java
public class RunnableDemo {

    public static void main(String[] args) {

        MyTask task = new MyTask();

        Thread t1 = new Thread(task);

        t1.start();
    }
}
```

**Output:**

```text
Runnable task running
```

### Why use Runnable?

Java does not support multiple inheritance of classes.

If a class extends Thread, it cannot extend another class.

Using Runnable allows a class to extend another class while implementing Runnable.

```java
class Student extends Person implements Runnable {

    @Override
    public void run() {
        System.out.println("Student task running");
    }
}
```

### Multiple threads using the same Runnable task

```java
class MyTask implements Runnable {

    public void run() {

        System.out.println(
            Thread.currentThread().getName() + " is running"
        );
    }
}

public class Main {

    public static void main(String[] args) {

        MyTask task = new MyTask();

        Thread t1 = new Thread(task, "Thread-1");
        Thread t2 = new Thread(task, "Thread-2");
        Thread t3 = new Thread(task, "Thread-3");

        t1.start();
        t2.start();
        t3.start();
    }
}
```

Possible output:

```text
Thread-1 is running
Thread-3 is running
Thread-2 is running
```

The execution order is not guaranteed.

---

# 4. Thread Life Cycle

A Java thread can have the following states:

1. NEW
2. RUNNABLE
3. BLOCKED
4. WAITING
5. TIMED_WAITING
6. TERMINATED

### Thread life-cycle diagram

```text
             NEW
              |
           start()
              |
              v
          RUNNABLE
              |
       CPU / Scheduler
              |
              v
          RUNNING*
          /   |    \
         /    |     \
      wait() sleep() lock unavailable
        |       |          |
        v       v          v
     WAITING  TIMED     BLOCKED
              WAITING
        \       |          /
         \      |         /
          \     |        /
           v    v       v
             RUNNABLE
                |
          run() completes
                |
                v
           TERMINATED
```

*Note:* `RUNNING` is often used conceptually when explaining execution. Java's official `Thread.State` enum does not have a separate RUNNING state. A running thread is represented as `RUNNABLE`.

### Explanation of states

| State | Meaning |
|---|---|
| NEW | Thread object created but not started |
| RUNNABLE | Ready to run or currently running |
| BLOCKED | Waiting to acquire a monitor lock |
| WAITING | Waiting indefinitely for another thread's action |
| TIMED_WAITING | Waiting for a specified time |
| TERMINATED | Execution has completed |

### Checking thread state

```java
public class StateDemo {

    public static void main(String[] args)
            throws InterruptedException {

        Thread t1 = new Thread(() -> {
            System.out.println("Thread executing");
        });

        System.out.println(t1.getState());

        t1.start();

        t1.join();

        System.out.println(t1.getState());
    }
}
```

Output:

```text
NEW
Thread executing
TERMINATED
```

---

# 5. Thread Methods

Important methods provided by the Thread class:

| Method | Purpose |
|---|---|
| `start()` | Starts a new thread |
| `run()` | Contains the task to execute |
| `sleep()` | Pauses the current thread temporarily |
| `join()` | Waits for another thread to finish |
| `yield()` | Hints that the current thread is willing to yield CPU time |
| `setPriority()` | Sets thread priority |
| `getPriority()` | Returns thread priority |
| `getName()` | Returns thread name |
| `setName()` | Changes thread name |
| `currentThread()` | Returns currently executing thread |
| `isAlive()` | Checks whether thread has started and not terminated |
| `interrupt()` | Requests interruption of a thread |

## 5.1 sleep()

The `sleep()` method pauses the currently executing thread for a specified time.

Syntax:

```java
Thread.sleep(1000);
```

The time is in milliseconds.

Example:

```java
public class SleepDemo {

    public static void main(String[] args)
            throws InterruptedException {

        for (int i = 1; i <= 5; i++) {

            System.out.println(i);

            Thread.sleep(1000);
        }
    }
}
```

Output:

```text
1
2
3
4
5
```

There is approximately a one-second delay between iterations.

**Important points:**

- `sleep()` is a static method of Thread.
- It pauses the current thread, not necessarily the thread object on which it is called.
- It throws `InterruptedException`.
- It does not release locks held by the sleeping thread.

## 5.2 join()

The `join()` method makes the current thread wait until another thread completes.

Example:

```java
public class JoinDemo {

    public static void main(String[] args)
            throws InterruptedException {

        Thread t1 = new Thread(() -> {

            for (int i = 1; i <= 3; i++) {
                System.out.println("Child: " + i);
            }

        });

        t1.start();

        t1.join();

        System.out.println("Main thread completed");
    }
}
```

Output:

```text
Child: 1
Child: 2
Child: 3
Main thread completed
```

**Why use join()?**

When one thread depends on the completion of another thread.

Example: A main thread waits for file downloading to complete before processing the downloaded file.

## 5.3 yield()

The `yield()` method gives a hint to the thread scheduler that the current thread is willing to pause and allow another thread to execute.

Example:

```java
public class YieldDemo {

    public static void main(String[] args) {

        Thread t1 = new Thread(() -> {

            for (int i = 1; i <= 5; i++) {

                System.out.println("Thread 1: " + i);

                Thread.yield();
            }
        });

        Thread t2 = new Thread(() -> {

            for (int i = 1; i <= 5; i++) {
                System.out.println("Thread 2: " + i);
            }
        });

        t1.start();
        t2.start();
    }
}
```

The output order may vary.

**Important:** `yield()` is only a scheduler hint. It does not guarantee that another thread will execute next.

## 5.4 setPriority() and getPriority()

Java provides thread priorities to indicate the relative scheduling importance of threads.

Priority range:

| Constant | Value |
|---|---:|
| `Thread.MIN_PRIORITY` | 1 |
| `Thread.NORM_PRIORITY` | 5 |
| `Thread.MAX_PRIORITY` | 10 |

Example:

```java
public class PriorityDemo {

    public static void main(String[] args) {

        Thread t1 = new Thread(() -> {
            System.out.println("Low priority thread");
        });

        Thread t2 = new Thread(() -> {
            System.out.println("High priority thread");
        });

        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.MAX_PRIORITY);

        System.out.println(t1.getPriority());
        System.out.println(t2.getPriority());

        t1.start();
        t2.start();
    }
}
```

Output:

```text
1
10
```

**Important:** Priority does not guarantee execution order. Do not use thread priority as a synchronization mechanism.

---

# 6. ThreadGroup Class

`ThreadGroup` is used to organize multiple threads into a group.

It provides a way to manage related threads together.

### Creating a ThreadGroup

```java
public class ThreadGroupDemo {

    public static void main(String[] args) {

        ThreadGroup group = new ThreadGroup("MyGroup");

        Thread t1 = new Thread(group, () -> {
            System.out.println("Task 1");
        });

        Thread t2 = new Thread(group, () -> {
            System.out.println("Task 2");
        });

        t1.start();
        t2.start();

        System.out.println("Group name: " + group.getName());

        System.out.println(
            "Active threads: " + group.activeCount()
        );
    }
}
```

Possible output:

```text
Group name: MyGroup
Active threads: 2
Task 1
Task 2
```

The active count is approximate and can change while threads execute.

### Important ThreadGroup methods

| Method | Purpose |
|---|---|
| `getName()` | Returns group name |
| `activeCount()` | Estimates active threads |
| `activeGroupCount()` | Estimates active subgroups |
| `getParent()` | Returns parent group |
| `list()` | Prints group information |
| `setMaxPriority()` | Sets maximum priority for the group |

**Note:** ThreadGroup is a legacy thread-management facility. Modern Java applications commonly use ExecutorService and other concurrency utilities for managing tasks.

---

# 7. Synchronization

## 7.1 What is Synchronization?

Synchronization is a mechanism that controls access to shared resources when multiple threads execute simultaneously.

It prevents multiple threads from modifying shared data at the same time when such concurrent access could cause incorrect results.

### What is a Race Condition?

A race condition occurs when multiple threads access and modify shared data concurrently, and the result depends on their execution timing.

Example:

```java
class Counter {

    int count = 0;

    void increment() {
        count++;
    }
}
```

If two threads execute `increment()` many times, the final count may be less than expected.

Why?

`count++` is not one indivisible operation. It involves:

1. Reading the current value.
2. Increasing the value.
3. Writing the updated value.

Two threads may read the same old value and overwrite each other's updates.

## 7.2 Synchronized Method

The `synchronized` keyword allows only one thread at a time to execute a synchronized instance method on the same object.

Example:

```java
class Counter {

    private int count = 0;

    synchronized void increment() {

        count++;
    }

    int getCount() {

        return count;
    }
}

public class SynchronizationDemo {

    public static void main(String[] args)
            throws InterruptedException {

        Counter counter = new Counter();

        Thread t1 = new Thread(() -> {

            for (int i = 0; i < 1000; i++) {
                counter.increment();
            }
        });

        Thread t2 = new Thread(() -> {

            for (int i = 0; i < 1000; i++) {
                counter.increment();
            }
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println(counter.getCount());
    }
}
```

Output:

```text
2000
```

## 7.3 Synchronized Block

Instead of synchronizing an entire method, we can synchronize only a specific block.

Syntax:

```java
synchronized (object) {

    // Critical section
}
```

Example:

```java
class Printer {

    void printData() {

        synchronized (this) {

            System.out.println(
                Thread.currentThread().getName()
                + " is printing"
            );
        }
    }
}
```

### Synchronized Method vs Synchronized Block

| Synchronized Method | Synchronized Block |
|---|---|
| Locks the method's monitor | Locks the specified object's monitor |
| Entire method is protected | Only selected code is protected |
| Simpler syntax | More control over locking |
| May hold lock longer | Can reduce lock duration |

## 7.4 Static Synchronization

A static synchronized method locks the Class object associated with that class.

```java
class Display {

    static synchronized void show() {

        System.out.println("Static synchronized method");
    }
}
```

An instance synchronized method locks the current object (`this`).

A static synchronized method and an instance synchronized method use different locks.

## 7.5 Important Synchronization Points

- Every Java object can act as a monitor lock.
- A thread must acquire the monitor before entering a synchronized block or method.
- A thread releases the monitor when it exits the synchronized region.
- Synchronized access provides visibility guarantees as well as mutual exclusion.
- Synchronization can reduce performance if overused.

---

# 8. Inter-thread Communication: wait, notify and notifyAll

Java provides three important methods for communication between threads:

- `wait()`
- `notify()`
- `notifyAll()`

These methods belong to the `Object` class.

They are used when threads need to coordinate their execution.

## 8.1 wait()

The `wait()` method causes the current thread to wait until another thread notifies it or it is interrupted.

It releases the monitor lock of the object on which it is called.

## 8.2 notify()

The `notify()` method wakes up one thread waiting on the same object's monitor.

The awakened thread cannot continue until it reacquires the monitor.

## 8.3 notifyAll()

The `notifyAll()` method wakes all threads waiting on the same object's monitor.

They compete to reacquire the lock.

### Comparison

| Method | Description |
|---|---|
| `wait()` | Releases the object's monitor and waits |
| `notify()` | Wakes one waiting thread |
| `notifyAll()` | Wakes all waiting threads |

**Important rules:**

1. These methods must be called while holding the same object's monitor.
2. Calling them without owning the monitor causes `IllegalMonitorStateException`.
3. `wait()` releases the monitor; `sleep()` does not.
4. Always use a loop to check the condition after waking up because spurious wakeups are possible.

## 8.4 Example: wait() and notify()

```java
class SharedResource {

    private boolean available = false;

    synchronized void consume()
            throws InterruptedException {

        while (!available) {

            System.out.println("Consumer waiting...");

            wait();
        }

        System.out.println("Consumer received signal");

        available = false;
    }

    synchronized void produce() {

        System.out.println("Producer producing data");

        available = true;

        notify();
    }
}

public class WaitNotifyDemo {

    public static void main(String[] args) {

        SharedResource resource = new SharedResource();

        Thread consumer = new Thread(() -> {

            try {
                resource.consume();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }

        });

        Thread producer = new Thread(() -> {

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }

            resource.produce();
        });

        consumer.start();
        producer.start();
    }
}
```

Possible output:

```text
Consumer waiting...
Producer producing data
Consumer received signal
```

### Understanding the execution

1. Consumer calls `consume()`.
2. It finds `available == false`.
3. Consumer calls `wait()` and releases the resource's monitor.
4. Producer acquires the monitor.
5. Producer sets `available = true`.
6. Producer calls `notify()`.
7. Consumer becomes eligible to resume.
8. Consumer reacquires the monitor, checks the condition and continues.

## 8.5 Example: notifyAll()

```java
class SharedResource {

    synchronized void waitForSignal(String name)
            throws InterruptedException {

        System.out.println(name + " is waiting");

        wait();

        System.out.println(name + " resumed");
    }

    synchronized void sendSignal() {

        System.out.println("Sending signal to all threads");

        notifyAll();
    }
}

public class NotifyAllDemo {

    public static void main(String[] args)
            throws InterruptedException {

        SharedResource resource = new SharedResource();

        Thread t1 = new Thread(() -> {
            try {
                resource.waitForSignal("Thread 1");
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        Thread t2 = new Thread(() -> {
            try {
                resource.waitForSignal("Thread 2");
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        t1.start();
        t2.start();

        Thread.sleep(500);

        resource.sendSignal();
    }
}
```

Possible output:

```text
Thread 1 is waiting
Thread 2 is waiting
Sending signal to all threads
Thread 1 resumed
Thread 2 resumed
```

The order of resumed threads is not guaranteed.

---

# 9. Concurrent Collections – ConcurrentHashMap

## 9.1 What are Concurrent Collections?

Concurrent collections are thread-safe collections designed to support concurrent access by multiple threads.

They are available in the `java.util.concurrent` package.

Examples:

- ConcurrentHashMap
- CopyOnWriteArrayList
- BlockingQueue
- ConcurrentLinkedQueue

## 9.2 What is ConcurrentHashMap?

`ConcurrentHashMap` is a thread-safe implementation of the Map interface.

It allows multiple threads to access and update map entries safely without requiring the application to synchronize the entire map for every operation.

### Syntax

```java
ConcurrentHashMap<Integer, String> map =
        new ConcurrentHashMap<>();
```

### Example

```java
import java.util.concurrent.ConcurrentHashMap;

public class ConcurrentHashMapDemo {

    public static void main(String[] args)
            throws InterruptedException {

        ConcurrentHashMap<Integer, String> map =
                new ConcurrentHashMap<>();

        Thread t1 = new Thread(() -> {

            for (int i = 1; i <= 5; i++) {
                map.put(i, "Student " + i);
            }
        });

        Thread t2 = new Thread(() -> {

            for (int i = 6; i <= 10; i++) {
                map.put(i, "Student " + i);
            }
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println(map);
        System.out.println("Size: " + map.size());
    }
}
```

Output:

```text
{...}
Size: 10
```

The displayed map order is not guaranteed.

### HashMap vs ConcurrentHashMap

| HashMap | ConcurrentHashMap |
|---|---|
| Not thread-safe by itself | Thread-safe |
| Concurrent updates require external coordination | Designed for concurrent access |
| Allows one null key | Does not allow null keys |
| Allows null values | Does not allow null values |
| Iterators are generally fail-fast | Iterators are weakly consistent |
| Suitable for ordinary single-threaded use | Suitable for concurrent access |

### Important features

1. Thread-safe operations.
2. Supports concurrent reads and updates.
3. Does not permit null keys or null values.
4. Provides atomic methods such as `putIfAbsent()`, `compute()` and `merge()`.
5. Iterators are weakly consistent and do not generally throw `ConcurrentModificationException` merely because another thread updates the map.

**Example of putIfAbsent():**

```java
map.putIfAbsent(101, "Anurag");
```

It inserts the value only if the key is not already associated with a value.

**Important:** Thread safety of individual operations does not automatically make a sequence of separate operations atomic. Use suitable atomic methods when the entire operation must be performed together.

---

# 10. ThreadLocal – Thread-local Data

## 10.1 What is ThreadLocal?

`ThreadLocal` allows each thread to maintain its own independent copy of a variable.

Even if multiple threads access the same ThreadLocal object, each thread gets its own value.

It is useful when data should belong to a particular thread rather than be shared among all threads.

### Example

```java
public class ThreadLocalDemo {

    private static final ThreadLocal<String> user =
            ThreadLocal.withInitial(() -> "Guest");

    public static void main(String[] args) {

        Thread t1 = new Thread(() -> {

            user.set("Anurag");

            System.out.println(
                Thread.currentThread().getName()
                + " : " + user.get()
            );
        });

        Thread t2 = new Thread(() -> {

            user.set("Rahul");

            System.out.println(
                Thread.currentThread().getName()
                + " : " + user.get()
            );
        });

        t1.start();
        t2.start();
    }
}
```

Possible output:

```text
Thread-0 : Anurag
Thread-1 : Rahul
```

Each thread sees its own value.

### Important ThreadLocal methods

| Method | Purpose |
|---|---|
| `set(value)` | Stores a value for the current thread |
| `get()` | Retrieves the current thread's value |
| `remove()` | Removes the current thread's value |
| `withInitial()` | Creates a ThreadLocal with an initial-value supplier |

### Why use ThreadLocal?

Examples:

- Request-specific user information.
- Per-thread date formatting state.
- Transaction context.
- Logging or tracing context.

**Important:** ThreadLocal is not a way to share the same data between threads. It gives each thread its own copy. If you need shared thread-safe data, use appropriate synchronization or concurrent collections.

For thread pools, call `remove()` when thread-specific data is no longer needed to avoid accidentally retaining data between tasks.

---

# 11. Metadata and Reflection

## 11.1 What is Metadata?

Metadata means data about data.

In Java, metadata provides information about classes, methods, fields, constructors and other program elements.

Examples:

- Class name
- Method name
- Field name
- Return type
- Parameter types
- Access modifiers
- Annotations

## 11.2 What is Reflection?

Reflection is a Java feature that allows a program to inspect and interact with classes, methods, fields and constructors at runtime.

Reflection is available through the `java.lang.reflect` package.

### Why use Reflection?

- Inspect class information at runtime.
- Access fields and methods dynamically.
- Create objects dynamically.
- Invoke methods dynamically.
- Build frameworks and testing tools.
- Work with dependency injection and serialization frameworks.

## 11.3 Getting Class Information

Java provides three common ways to obtain a Class object.

```java
Class<?> c1 = Student.class;

Student student = new Student();
Class<?> c2 = student.getClass();

Class<?> c3 = Class.forName("Student");
```

`Class.forName()` loads a class using its fully qualified name and initializes it by default.

## 11.4 Reflection Example: Inspecting a Class

```java
import java.lang.reflect.*;

class Student {

    private int rollNo = 101;

    public String name = "Anurag";

    public void display() {
        System.out.println("Student details");
    }
}

public class ReflectionDemo {

    public static void main(String[] args) {

        Class<?> c = Student.class;

        System.out.println("Class: " + c.getName());

        System.out.println("\nFields:");

        for (Field field : c.getDeclaredFields()) {
            System.out.println(field.getName());
        }

        System.out.println("\nMethods:");

        for (Method method : c.getDeclaredMethods()) {
            System.out.println(method.getName());
        }

        System.out.println("\nConstructors:");

        for (Constructor<?> constructor :
                c.getDeclaredConstructors()) {

            System.out.println(constructor);
        }
    }
}
```

Possible output:

```text
Class: Student

Fields:
rollNo
name

Methods:
display

Constructors:
Student()
```

The order of reflection results is not guaranteed.

## 11.5 Invoking a Private Method Using Reflection

Normally, a private method cannot be called directly from outside its class.

Reflection can access a private method by using `getDeclaredMethod()` and, where permitted, `setAccessible(true)`.

Example:

```java
import java.lang.reflect.Method;

class Employee {

    private void showSalary() {

        System.out.println("Salary: 50000");
    }
}

public class PrivateMethodReflection {

    public static void main(String[] args)
            throws Exception {

        Employee employee = new Employee();

        Class<?> c = employee.getClass();

        Method method =
                c.getDeclaredMethod("showSalary");

        method.setAccessible(true);

        method.invoke(employee);
    }
}
```

Output:

```text
Salary: 50000
```

### Understanding the methods

| Reflection API | Purpose |
|---|---|
| `getDeclaredMethods()` | Gets methods declared in the class, including private methods |
| `getMethods()` | Gets public methods, including inherited public methods |
| `getDeclaredFields()` | Gets fields declared in the class |
| `getDeclaredConstructors()` | Gets constructors declared in the class |
| `getDeclaredMethod()` | Gets a declared method by name and parameter types |
| `setAccessible(true)` | Requests access suppression where permitted |
| `invoke()` | Invokes a method dynamically |

**Important reflection notes:**

- `getDeclaredMethod()` includes private methods declared in the class.
- `getMethod()` finds public methods.
- Access suppression can be restricted by Java modules and security boundaries.
- `setAccessible(true)` is not guaranteed to bypass every access restriction.
- Reflection can make code harder to maintain and can weaken encapsulation.
- Use reflection only when there is a genuine need.

---

# 12. Anonymous Inner Classes and Lambda Expressions

Runnable is a functional interface, so it can be implemented using an anonymous inner class or a lambda expression.

## 12.1 Anonymous Inner Class

An anonymous inner class is a class without a name, created and instantiated in one expression.

Example:

```java
public class AnonymousThreadDemo {

    public static void main(String[] args) {

        Thread t1 = new Thread(new Runnable() {

            @Override
            public void run() {

                System.out.println(
                    "Thread using anonymous inner class"
                );
            }
        });

        t1.start();
    }
}
```

Output:

```text
Thread using anonymous inner class
```

## 12.2 Lambda Expression

A lambda expression provides a concise way to implement a functional interface.

Syntax:

```java
(parameters) -> {
    // task
}
```

Example:

```java
public class LambdaThreadDemo {

    public static void main(String[] args) {

        Thread t1 = new Thread(() -> {

            System.out.println(
                "Thread using lambda expression"
            );
        });

        t1.start();
    }
}
```

Output:

```text
Thread using lambda expression
```

### Anonymous Inner Class vs Lambda

| Anonymous Inner Class | Lambda Expression |
|---|---|
| Uses an anonymous class | Implements a functional interface using a lambda |
| More verbose | Concise |
| Can declare additional methods and fields | Cannot declare additional instance methods or fields as a new class |
| `this` refers to the anonymous class instance | `this` refers to the enclosing instance |
| Useful for more complex custom implementations | Ideal for functional interfaces |

---

# 13. Practical Lab Programs

## Lab 1: Create Multiple Threads Using Thread Class and Runnable Interface

### Program A: Using Thread Class

```java
class MyThread extends Thread {

    public void run() {

        for (int i = 1; i <= 5; i++) {

            System.out.println(
                getName() + " : " + i
            );
        }
    }
}

public class ThreadLab {

    public static void main(String[] args) {

        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();

        t1.setName("First Thread");
        t2.setName("Second Thread");

        t1.start();
        t2.start();
    }
}
```

### Program B: Using Runnable Interface

```java
class MyTask implements Runnable {

    public void run() {

        for (int i = 1; i <= 5; i++) {

            System.out.println(
                Thread.currentThread().getName()
                + " : " + i
            );
        }
    }
}

public class RunnableLab {

    public static void main(String[] args) {

        MyTask task = new MyTask();

        Thread t1 = new Thread(task, "Thread A");
        Thread t2 = new Thread(task, "Thread B");

        t1.start();
        t2.start();
    }
}
```

**Learning:** Both approaches create multiple threads. Runnable separates the task from the Thread object.

## Lab 2: Assign Same Task and Different Tasks to Multiple Threads

### Same Task

```java
public class SameTaskDemo {

    public static void main(String[] args) {

        Runnable task = () -> {

            System.out.println(
                Thread.currentThread().getName()
                + " is performing the same task"
            );
        };

        Thread t1 = new Thread(task, "Thread 1");
        Thread t2 = new Thread(task, "Thread 2");
        Thread t3 = new Thread(task, "Thread 3");

        t1.start();
        t2.start();
        t3.start();
    }
}
```

### Different Tasks

```java
public class DifferentTaskDemo {

    public static void main(String[] args) {

        Thread t1 = new Thread(() -> {
            System.out.println("Downloading file");
        });

        Thread t2 = new Thread(() -> {
            System.out.println("Processing data");
        });

        Thread t3 = new Thread(() -> {
            System.out.println("Sending email");
        });

        t1.start();
        t2.start();
        t3.start();
    }
}
```

Possible output:

```text
Downloading file
Processing data
Sending email
```

The order can vary.

## Lab 3: Understand sleep(), join() and yield()

```java
public class ThreadMethodsLab {

    public static void main(String[] args)
            throws InterruptedException {

        Thread t1 = new Thread(() -> {

            for (int i = 1; i <= 3; i++) {

                System.out.println("Thread 1: " + i);

                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    return;
                }

                Thread.yield();
            }
        });

        Thread t2 = new Thread(() -> {

            for (int i = 1; i <= 3; i++) {
                System.out.println("Thread 2: " + i);
            }
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Both threads completed");
    }
}
```

**Learning:**

- `sleep()` pauses the current thread.
- `yield()` provides a scheduling hint.
- `join()` waits for a thread to finish.

## Lab 4: Implement wait(), notify() and notifyAll()

```java
class Message {

    private boolean available = false;

    synchronized void receive()
            throws InterruptedException {

        while (!available) {

            System.out.println(
                Thread.currentThread().getName()
                + " waiting"
            );

            wait();
        }

        System.out.println(
            Thread.currentThread().getName()
            + " received message"
        );

        available = false;
    }

    synchronized void send() {

        System.out.println("Message sent");

        available = true;

        notifyAll();
    }
}

public class CommunicationLab {

    public static void main(String[] args)
            throws InterruptedException {

        Message message = new Message();

        Thread t1 = new Thread(() -> {
            try {
                message.receive();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }, "Receiver 1");

        Thread t2 = new Thread(() -> {
            try {
                message.receive();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }, "Receiver 2");

        t1.start();
        t2.start();

        Thread.sleep(500);

        message.send();
    }
}
```

**Learning:** Both receivers can be awakened by `notifyAll()`, but the shared condition must be designed correctly.

In this particular example, only one message is available. The first receiver consumes it and sets `available` back to false. The other receiver may return to waiting. To release both receivers, the producer would need to provide two messages or use a different shared-state condition.

## Lab 5: Demonstrate ThreadLocal Data

```java
public class ThreadLocalLab {

    private static final ThreadLocal<Integer> threadData =
            ThreadLocal.withInitial(() -> 0);

    public static void main(String[] args) {

        Runnable task = () -> {

            threadData.set(
                (int) (Math.random() * 100)
            );

            System.out.println(
                Thread.currentThread().getName()
                + " : " + threadData.get()
            );

            threadData.remove();
        };

        Thread t1 = new Thread(task, "Thread 1");
        Thread t2 = new Thread(task, "Thread 2");
        Thread t3 = new Thread(task, "Thread 3");

        t1.start();
        t2.start();
        t3.start();
    }
}
```

**Learning:** Every thread has its own independent ThreadLocal value.

## Lab 6: Invoke Private Methods Using Reflection

```java
import java.lang.reflect.Method;

class Bank {

    private void displayBalance() {

        System.out.println("Account Balance: 75000");
    }
}

public class ReflectionLab {

    public static void main(String[] args)
            throws Exception {

        Bank bank = new Bank();

        Class<?> c = bank.getClass();

        Method method =
                c.getDeclaredMethod("displayBalance");

        method.setAccessible(true);

        method.invoke(bank);
    }
}
```

Output:

```text
Account Balance: 75000
```

**Learning:** Reflection can inspect and invoke a private method where access restrictions permit it.

## Lab 7: Create Threads Using Anonymous Inner Classes and Lambda Expressions

### Anonymous Inner Class

```java
public class AnonymousLab {

    public static void main(String[] args) {

        Thread t1 = new Thread(new Runnable() {

            public void run() {

                System.out.println(
                    "Anonymous inner class thread"
                );
            }
        });

        t1.start();
    }
}
```

### Lambda Expression

```java
public class LambdaLab {

    public static void main(String[] args) {

        Thread t1 = new Thread(() -> {

            System.out.println(
                "Lambda expression thread"
            );
        });

        t1.start();
    }
}
```

---

# 14. Thread Class vs Runnable Interface

| Feature | Thread Class | Runnable Interface |
|---|---|---|
| Type | Class | Functional interface |
| Package | `java.lang` | `java.lang` |
| Method | `run()` | `run()` |
| Creation | Extend Thread | Implement Runnable |
| Inheritance | Uses class inheritance | Can extend another class |
| Task separation | Task tied to Thread subclass | Task separated from Thread |
| Reusability | Less flexible | More flexible |
| Lambda support | Not directly as a Thread subclass | Yes, Runnable is functional |

**Recommendation:** Prefer Runnable for simple thread tasks and consider ExecutorService for managing larger numbers of concurrent tasks.

---

# 15. Interview Questions and Answers

### Q1. What is a thread?

A thread is the smallest unit of execution within a process.

### Q2. What is multithreading?

Multithreading allows multiple threads to execute concurrently within one application.

### Q3. How can we create a thread in Java?

By extending the Thread class or implementing Runnable.

### Q4. What is the difference between start() and run()?

`start()` creates a new thread of execution. Calling `run()` directly is an ordinary method call.

### Q5. Why is Runnable preferred over extending Thread?

Runnable separates task logic from thread management and allows the class to extend another class.

### Q6. What is thread scheduling?

Thread scheduling determines which runnable thread gets CPU execution time.

### Q7. What is sleep()?

It pauses the current thread for a specified duration.

### Q8. Does sleep() release a lock?

No. It does not release locks held by the current thread.

### Q9. What is join()?

It makes the current thread wait for another thread to finish.

### Q10. What is yield()?

It is a scheduler hint that the current thread is willing to yield CPU time.

### Q11. What is thread priority?

It is a scheduling hint indicating a thread's relative priority, from 1 to 10.

### Q12. What is ThreadGroup?

It groups related threads for management.

### Q13. What is synchronization?

Synchronization controls concurrent access to shared resources.

### Q14. What is a race condition?

A race condition occurs when the result depends on the timing of concurrent operations.

### Q15. What is a critical section?

A critical section is code that accesses shared data and requires controlled access.

### Q16. What is a synchronized method?

A method protected by the object's monitor lock.

### Q17. What is a synchronized block?

A block of code protected by a specified object's monitor lock.

### Q18. What is inter-thread communication?

It is a mechanism through which threads coordinate their work using methods such as wait(), notify() and notifyAll().

### Q19. What is the difference between wait() and sleep()?

`wait()` releases the object's monitor and waits. `sleep()` pauses the current thread without releasing its locks.

### Q20. What is the difference between notify() and notifyAll()?

`notify()` wakes one waiting thread; `notifyAll()` wakes all threads waiting on that object's monitor.

### Q21. What happens if wait() is called without synchronization?

It throws `IllegalMonitorStateException`.

### Q22. What is ConcurrentHashMap?

It is a thread-safe implementation of Map designed for concurrent access.

### Q23. Can ConcurrentHashMap store null?

No. It does not allow null keys or null values.

### Q24. What is ThreadLocal?

ThreadLocal provides a separate value for each thread.

### Q25. Does ThreadLocal share data between threads?

No. Each thread has its own independent value.

### Q26. What is Reflection?

Reflection allows inspection and interaction with class members at runtime.

### Q27. Which package provides Reflection APIs?

`java.lang.reflect`.

### Q28. Can we access private methods using Reflection?

Yes, using methods such as `getDeclaredMethod()` and `setAccessible(true)`, subject to access restrictions.

### Q29. What is an anonymous inner class?

A class without a name that is declared and instantiated in one expression.

### Q30. Why can Runnable be used with lambda expressions?

Runnable is a functional interface containing one abstract method.

---

# 16. MCQs

**1. Which method starts a new thread?**

A. run()  
B. start()  
C. execute()  
D. begin()

**Answer: B. start()**

**2. Which interface is a functional interface?**

A. Thread  
B. Runnable  
C. Object  
D. String

**Answer: B. Runnable**

**3. Which method pauses the current thread?**

A. join()  
B. yield()  
C. sleep()  
D. notify()

**Answer: C. sleep()**

**4. Which method waits for another thread to finish?**

A. sleep()  
B. join()  
C. wait()  
D. yield()

**Answer: B. join()**

**5. Which is the valid thread priority range?**

A. 0–10  
B. 1–5  
C. 1–10  
D. 0–100

**Answer: C. 1–10**

**6. Which keyword is used for synchronization?**

A. volatile  
B. static  
C. synchronized  
D. final

**Answer: C. synchronized**

**7. Which method releases the monitor lock while waiting?**

A. sleep()  
B. wait()  
C. yield()  
D. join()

**Answer: B. wait()**

**8. Which method wakes all waiting threads on an object's monitor?**

A. notify()  
B. notifyAll()  
C. start()  
D. interrupt()

**Answer: B. notifyAll()**

**9. Which collection is designed for concurrent map operations?**

A. HashMap  
B. TreeMap  
C. ConcurrentHashMap  
D. ArrayList

**Answer: C. ConcurrentHashMap**

**10. Which class provides thread-specific data?**

A. ThreadGroup  
B. ThreadLocal  
C. ThreadPool  
D. Object

**Answer: B. ThreadLocal**

**11. Which package contains Reflection APIs?**

A. java.util  
B. java.io  
C. java.lang.reflect  
D. java.net

**Answer: C. java.lang.reflect**

**12. Which method retrieves methods declared in a class, including private methods?**

A. getMethods()  
B. getDeclaredMethods()  
C. getMethodNames()  
D. getPublicMethods()

**Answer: B. getDeclaredMethods()**

**13. What happens when start() is called twice on the same Thread object?**

A. It starts twice  
B. It restarts the thread  
C. IllegalThreadStateException occurs  
D. Nothing happens

**Answer: C. IllegalThreadStateException**

**14. Which method is a scheduler hint?**

A. wait()  
B. yield()  
C. notify()  
D. join()

**Answer: B. yield()**

**15. Which interface can be implemented using a lambda expression?**

A. Runnable  
B. ThreadGroup  
C. Object  
D. String

**Answer: A. Runnable**

---

# 17. Quick Revision Notes

| Topic | Key Point |
|---|---|
| Thread | Smallest unit of execution |
| Multithreading | Multiple threads in one process |
| Thread class | Extend Thread |
| Runnable | Implement Runnable |
| start() | Starts a new thread |
| run() | Contains task logic |
| sleep() | Pauses current thread |
| join() | Waits for another thread |
| yield() | Scheduling hint |
| Priority | Range 1 to 10 |
| ThreadGroup | Groups related threads |
| Synchronization | Controls shared-resource access |
| Race condition | Timing-dependent shared-data error |
| wait() | Releases monitor and waits |
| notify() | Wakes one waiting thread |
| notifyAll() | Wakes all waiting threads |
| ConcurrentHashMap | Thread-safe map |
| ThreadLocal | Independent value per thread |
| Reflection | Runtime inspection and interaction |
| Anonymous class | Unnamed class implementation |
| Lambda | Concise functional-interface implementation |

## Important Differences to Remember

| Comparison | Main Difference |
|---|---|
| start() vs run() | New thread vs normal method call |
| sleep() vs wait() | Does not release monitor vs releases monitor |
| notify() vs notifyAll() | One waiting thread vs all waiting threads |
| Thread vs Runnable | Class vs functional interface |
| HashMap vs ConcurrentHashMap | Not thread-safe vs designed for concurrent access |
| ThreadLocal vs shared variable | Per-thread values vs shared data |
| Anonymous class vs lambda | Anonymous class implementation vs functional-interface expression |

## Practice Checklist

- [ ] Understand process, thread and multithreading.
- [ ] Create threads using Thread class.
- [ ] Create threads using Runnable interface.
- [ ] Create multiple threads with the same task.
- [ ] Create multiple threads with different tasks.
- [ ] Understand the Java thread life cycle.
- [ ] Practise sleep(), join() and yield().
- [ ] Set and retrieve thread priorities.
- [ ] Create and inspect a ThreadGroup.
- [ ] Understand race conditions and synchronization.
- [ ] Implement synchronized methods and blocks.
- [ ] Practise wait(), notify() and notifyAll().
- [ ] Use ConcurrentHashMap.
- [ ] Understand ThreadLocal.
- [ ] Inspect class metadata using Reflection.
- [ ] Invoke a private method using Reflection.
- [ ] Create threads using anonymous inner classes.
- [ ] Create threads using lambda expressions.

## Additional Practice Assignments

1. Create a ticket-booking application where multiple threads try to book seats. Use synchronization to prevent overbooking.
2. Create a bank account where multiple threads deposit and withdraw money safely.
3. Create a producer-consumer program using wait() and notifyAll().
4. Create a student record system using ConcurrentHashMap.
5. Create a logging example using ThreadLocal to maintain a request ID per thread.
6. Create a reflection utility that prints all fields, methods and constructors of a class.
7. Create a program with five threads and demonstrate their names, priorities and states.

---

**End of Session 28 – Multithreading and Synchronization**

*These notes are prepared for CDAC CMCE / PGCP-AC August 2026 batch learning and practical revision. Examples use Java 17-compatible syntax.*
