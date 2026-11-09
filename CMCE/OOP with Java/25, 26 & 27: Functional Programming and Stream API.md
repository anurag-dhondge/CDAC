

# Sessions 25, 26 & 27: Functional Programming and Stream API in Java

**Course:** CDAC CMCE – August 2026 Batch  
**Subject:** Core Java  
**Topics:** Functional Programming, Functional Interfaces, Lambda Expressions, Method References and Stream API  
**Theory:** 6 Hours | **Lab:** 8 Hours | **Self-Learning:** 2 Hours  
**Java Version:** Java 17 (Java 8+ features)

---

# Table of Contents

1. Introduction to Functional Programming
2. Functional Interfaces
3. Built-in Functional Interfaces
   - Predicate
   - Function
   - Consumer
   - Supplier
4. Lambda Expressions
5. Method References
6. Benefits and Applications of Lambda Expressions
7. Introduction to Stream API
8. Creating Streams from Collections and Arrays
9. Intermediate Operations
   - filter()
   - map()
   - flatMap()
   - sorted()
   - distinct()
   - limit()
   - skip()
10. Terminal Operations
    - forEach()
    - collect()
    - count()
    - reduce()
    - min()
    - max()
    - findFirst()
    - anyMatch()
    - allMatch()
    - noneMatch()
11. Collectors Utility Class
    - toList()
    - toSet()
    - groupingBy()
    - partitioningBy()
    - joining()
12. Parallel Streams
13. Stream API vs Traditional Iteration
14. Lab 1: Custom Functional Interfaces
15. Lab 2: Predicate, Function, Consumer and Supplier
16. Lab 3: Sorting and Searching Using Lambda
17. Lab 4: Method References and Constructor References
18. Lab 5: Creating Streams from Collections and Arrays
19. Lab 6: Filtering and Transformation
20. Lab 7: Aggregate Operations
21. Lab 8: Grouping and Partitioning
22. Lab 9: Employee Management Mini Application
23. Interview Questions
24. MCQ Practice
25. Quick Revision Notes

---

# 1. Introduction to Functional Programming

## 1.1 What is Functional Programming?

Functional Programming is a programming approach in which functions are treated as important building blocks of the program.

It focuses on:

- Using functions to perform operations.
- Passing functions as arguments.
- Returning functions from methods.
- Reducing unnecessary state changes.
- Writing reusable and concise code.
- Using declarative programming.

Java supports functional programming features starting from Java 8.

### Traditional Programming vs Functional Programming

**Traditional Approach:**

```java
import java.util.*;

public class TraditionalDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 20, 30, 40, 50);

        for (Integer number : numbers) {

            if (number > 20) {
                System.out.println(number);
            }
        }
    }
}
```

**Output:**

```text
30
40
50
```

**Functional Programming Approach:**

```java
import java.util.*;

public class FunctionalDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 20, 30, 40, 50);

        numbers.stream()
               .filter(number -> number > 20)
               .forEach(System.out::println);
    }
}
```

**Output:**

```text
30
40
50
```

### Difference

| Traditional Programming | Functional Programming |
|---|---|
| Focuses on how to perform operations | Focuses on what operation is required |
| Uses loops and conditions | Uses functions and expressions |
| Often requires more code | Often produces concise code |
| Uses explicit iteration | Uses declarative operations |
| Can involve mutable state | Encourages reducing unnecessary mutation |

## 1.2 Important Concepts

**1. First-Class Functions**

Functions can be stored in variables, passed as arguments, and returned from other functions.

Java achieves much of this using functional interfaces and lambda expressions.

**2. Higher-Order Functions**

A higher-order function accepts another function as an argument or returns a function.

Example:

```java
numbers.stream().filter(n -> n > 10);
```

Here, `filter()` accepts a Predicate.

**3. Immutability**

Immutability means avoiding unnecessary changes to existing data.

**4. Declarative Programming**

Instead of specifying every iteration step, we describe the required operation.

---

# 2. Functional Interfaces

## 2.1 What is a Functional Interface?

A Functional Interface is an interface that contains exactly one abstract method.

It is also called a Single Abstract Method (SAM) interface.

Functional interfaces can be implemented using lambda expressions.

### Syntax

```java
@FunctionalInterface
interface MyInterface {

    void display();
}
```

### Important Points

- A functional interface has exactly one abstract method.
- It can have multiple default methods.
- It can have multiple static methods.
- It can override methods from Object, such as `toString()`, without violating the single abstract method rule.
- The `@FunctionalInterface` annotation is optional but recommended.
- Lambda expressions can provide the implementation of its abstract method.

## 2.2 Example

```java
@FunctionalInterface
interface Greeting {

    void sayHello();
}

public class FunctionalInterfaceDemo {

    public static void main(String[] args) {

        Greeting greeting = () -> {
            System.out.println("Hello, Welcome to Java!");
        };

        greeting.sayHello();
    }
}
```

**Output:**

```text
Hello, Welcome to Java!
```

### Explanation

1. `Greeting` is a functional interface.
2. It contains one abstract method, `sayHello()`.
3. The lambda expression provides its implementation.
4. Calling `sayHello()` executes the lambda body.

## 2.3 Built-in Functional Interfaces

Java provides several predefined functional interfaces in the `java.util.function` package.

Important interfaces:

| Interface | Abstract Method | Purpose |
|---|---|---|
| Predicate<T> | `test()` | Checks a condition |
| Function<T,R> | `apply()` | Converts input to output |
| Consumer<T> | `accept()` | Consumes a value |
| Supplier<T> | `get()` | Supplies a value |

---

# 3. Built-in Functional Interfaces

## 3.1 Predicate Interface

### Introduction

Predicate is a functional interface used to test a condition.

It accepts an input and returns a boolean value.

**Method:**

```java
boolean test(T t);
```

**Syntax:**

```java
Predicate<Integer> predicate = n -> n > 10;
```

### Example

```java
import java.util.function.Predicate;

public class PredicateDemo {

    public static void main(String[] args) {

        Predicate<Integer> isEven = n -> n % 2 == 0;

        System.out.println(isEven.test(10));
        System.out.println(isEven.test(15));
    }
}
```

**Output:**

```text
true
false
```

### Predicate Helper Methods

| Method | Purpose |
|---|---|
| `and()` | Combines two predicates using AND |
| `or()` | Combines two predicates using OR |
| `negate()` | Reverses the condition |
| `isEqual()` | Creates a predicate checking equality |

**Example:**

```java
import java.util.function.Predicate;

public class PredicateMethodsDemo {

    public static void main(String[] args) {

        Predicate<Integer> greaterThan10 = n -> n > 10;

        Predicate<Integer> lessThan50 = n -> n < 50;

        Predicate<Integer> result =
                greaterThan10.and(lessThan50);

        System.out.println(result.test(25));
        System.out.println(result.test(60));

        Predicate<Integer> notGreaterThan10 =
                greaterThan10.negate();

        System.out.println(notGreaterThan10.test(5));
    }
}
```

**Output:**

```text
true
false
true
```

**Use Cases:**

- Filtering students who passed.
- Checking employee salary conditions.
- Validating input.
- Filtering products by price.

---

## 3.2 Function Interface

### Introduction

Function is a functional interface used to transform an input into an output.

It accepts one argument and returns a result.

**Method:**

```java
R apply(T t);
```

Here:

- T = Input type.
- R = Return type.

### Syntax

```java
Function<Integer, Integer> square = n -> n * n;
```

### Example

```java
import java.util.function.Function;

public class FunctionDemo {

    public static void main(String[] args) {

        Function<Integer, Integer> square =
                n -> n * n;

        System.out.println(square.apply(5));
        System.out.println(square.apply(10));
    }
}
```

**Output:**

```text
25
100
```

### Function Helper Methods

| Method | Purpose |
|---|---|
| `apply()` | Applies the function |
| `andThen()` | Executes another function after the current function |
| `compose()` | Executes another function before the current function |
| `identity()` | Returns a function that returns its input |

**Example:**

```java
import java.util.function.Function;

public class FunctionMethodsDemo {

    public static void main(String[] args) {

        Function<Integer, Integer> multiplyBy2 =
                n -> n * 2;

        Function<Integer, Integer> add10 =
                n -> n + 10;

        System.out.println(
                multiplyBy2.andThen(add10).apply(5)
        );

        System.out.println(
                multiplyBy2.compose(add10).apply(5)
        );
    }
}
```

**Output:**

```text
20
30
```

**Explanation:**

`andThen()`:

```text
5 → Multiply by 2 → 10 → Add 10 → 20
```

`compose()`:

```text
5 → Add 10 → 15 → Multiply by 2 → 30
```

**Use Cases:**

- Converting names to uppercase.
- Calculating salary after adding bonuses.
- Converting data types.
- Transforming records.

---

## 3.3 Consumer Interface

### Introduction

Consumer is a functional interface that accepts an input but does not return a result.

It is commonly used to perform operations on data.

**Method:**

```java
void accept(T t);
```

### Syntax

```java
Consumer<String> print = name -> System.out.println(name);
```

### Example

```java
import java.util.function.Consumer;

public class ConsumerDemo {

    public static void main(String[] args) {

        Consumer<String> display =
                name -> System.out.println("Hello " + name);

        display.accept("Anurag");
        display.accept("Rahul");
    }
}
```

**Output:**

```text
Hello Anurag
Hello Rahul
```

### Consumer Helper Method

`andThen()` executes another Consumer after the current Consumer.

```java
import java.util.function.Consumer;

public class ConsumerMethodsDemo {

    public static void main(String[] args) {

        Consumer<String> first =
                name -> System.out.println("Name: " + name);

        Consumer<String> second =
                name -> System.out.println("Length: " + name.length());

        first.andThen(second).accept("Anurag");
    }
}
```

**Output:**

```text
Name: Anurag
Length: 6
```

**Use Cases:**

- Printing data.
- Displaying student details.
- Logging information.
- Sending notifications.
- Updating external systems.

---

## 3.4 Supplier Interface

### Introduction

Supplier is a functional interface that does not accept any input but returns a value.

**Method:**

```java
T get();
```

### Syntax

```java
Supplier<String> supplier = () -> "Hello Java";
```

### Example

```java
import java.util.function.Supplier;

public class SupplierDemo {

    public static void main(String[] args) {

        Supplier<String> message =
                () -> "Welcome to Functional Programming";

        System.out.println(message.get());
    }
}
```

**Output:**

```text
Welcome to Functional Programming
```

### Example: Generate Random Number

```java
import java.util.Random;
import java.util.function.Supplier;

public class RandomSupplierDemo {

    public static void main(String[] args) {

        Supplier<Integer> randomNumber =
                () -> new Random().nextInt(100);

        System.out.println(randomNumber.get());
    }
}
```

The output will be a random integer between 0 and 99.

**Use Cases:**

- Generating random numbers.
- Providing default values.
- Creating objects.
- Lazy value generation.

---

## 3.5 Comparison of Built-in Functional Interfaces

| Interface | Input | Output | Method |
|---|---|---|---|
| Predicate<T> | T | boolean | test() |
| Function<T,R> | T | R | apply() |
| Consumer<T> | T | void | accept() |
| Supplier<T> | None | T | get() |

### Easy Way to Remember

- **Predicate:** Checks a condition.
- **Function:** Converts data.
- **Consumer:** Accepts and processes data.
- **Supplier:** Supplies data.

---

# 4. Lambda Expressions

## 4.1 Introduction

A Lambda Expression is a concise way to implement a functional interface.

Lambda expressions were introduced in Java 8.

They help reduce boilerplate code and make programs more readable.

### General Syntax

```java
(parameters) -> expression
```

For multiple statements:

```java
(parameters) -> {
    // Statements
};
```

### Examples

**No Parameter:**

```java
() -> System.out.println("Hello Java");
```

**One Parameter:**

```java
name -> System.out.println(name);
```

**Multiple Parameters:**

```java
(a, b) -> a + b;
```

**Multiple Statements:**

```java
(a, b) -> {
    int sum = a + b;
    return sum;
};
```

## 4.2 Traditional Approach vs Lambda

**Without Lambda:**

```java
interface Addition {
    int add(int a, int b);
}

public class WithoutLambda {

    public static void main(String[] args) {

        Addition addition = new Addition() {

            @Override
            public int add(int a, int b) {
                return a + b;
            }
        };

        System.out.println(addition.add(10, 20));
    }
}
```

**With Lambda:**

```java
interface Addition {
    int add(int a, int b);
}

public class WithLambda {

    public static void main(String[] args) {

        Addition addition = (a, b) -> a + b;

        System.out.println(addition.add(10, 20));
    }
}
```

**Output:**

```text
30
```

---

# 5. Method References

## 5.1 Introduction

Method Reference is a shorter form of a lambda expression when the lambda simply calls an existing method.

It uses the `::` operator.

### Syntax

```java
ClassName::methodName
```

There are three important types:

1. Static Method Reference.
2. Instance Method Reference.
3. Constructor Reference.

---

## 5.2 Static Method Reference

A static method reference refers to a static method of a class.

### Syntax

```java
ClassName::staticMethodName
```

### Example

```java
import java.util.*;

public class StaticMethodReferenceDemo {

    public static void display(String name) {
        System.out.println(name);
    }

    public static void main(String[] args) {

        List<String> names =
                Arrays.asList("Anurag", "Rahul", "Sushant");

        names.forEach(StaticMethodReferenceDemo::display);
    }
}
```

**Output:**

```text
Anurag
Rahul
Sushant
```

Equivalent lambda:

```java
names.forEach(name -> StaticMethodReferenceDemo.display(name));
```

---

## 5.3 Instance Method Reference

An instance method reference refers to a non-static method of an existing object.

### Syntax

```java
objectName::methodName
```

### Example

```java
import java.util.*;

class Printer {

    public void print(String message) {
        System.out.println(message);
    }
}

public class InstanceMethodReferenceDemo {

    public static void main(String[] args) {

        List<String> messages =
                Arrays.asList("Java", "Spring Boot", "Stream API");

        Printer printer = new Printer();

        messages.forEach(printer::print);
    }
}
```

**Output:**

```text
Java
Spring Boot
Stream API
```

Equivalent lambda:

```java
messages.forEach(message -> printer.print(message));
```

---

## 5.4 Constructor Reference

A constructor reference refers to a constructor of a class.

It uses the `new` keyword with the `::` operator.

### Syntax

```java
ClassName::new
```

### Example

```java
import java.util.function.Supplier;

class Student {

    Student() {
        System.out.println("Student Object Created");
    }
}

public class ConstructorReferenceDemo {

    public static void main(String[] args) {

        Supplier<Student> supplier = Student::new;

        Student student = supplier.get();
    }
}
```

**Output:**

```text
Student Object Created
```

Equivalent lambda:

```java
Supplier<Student> supplier = () -> new Student();
```

### Constructor Reference with Parameters

```java
import java.util.function.Function;

class Student {

    String name;

    Student(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return name;
    }
}

public class ConstructorReferenceWithParameter {

    public static void main(String[] args) {

        Function<String, Student> creator = Student::new;

        Student student = creator.apply("Anurag");

        System.out.println(student);
    }
}
```

**Output:**

```text
Anurag
```

---

# 6. Benefits and Applications of Lambda Expressions

## Benefits

1. Reduces boilerplate code.
2. Improves code readability.
3. Supports functional programming.
4. Works with functional interfaces.
5. Makes collection processing easier.
6. Supports Stream API.
7. Makes behavior reusable and composable.

## Applications

- Collection sorting.
- Filtering records.
- Searching data.
- Stream processing.
- Event handling.
- Multithreaded programming.
- Spring Boot and modern Java applications.

---

# 7. Introduction to Stream API

## 7.1 What is Stream API?

Stream API was introduced in Java 8.

It provides a declarative way to process collections and other data sources.

It supports operations such as:

- Filtering.
- Mapping.
- Sorting.
- Searching.
- Aggregation.
- Grouping.
- Collecting results.

### Example

Traditional approach:

```java
List<Integer> numbers =
        Arrays.asList(10, 20, 30, 40, 50);

for (Integer number : numbers) {

    if (number > 20) {
        System.out.println(number);
    }
}
```

Using Stream API:

```java
numbers.stream()
       .filter(n -> n > 20)
       .forEach(System.out::println);
```

## 7.2 Stream Pipeline

A Stream pipeline generally contains three stages.

```text
        Data Source
             |
             v
     Intermediate Operations
             |
             v
       Terminal Operation
             |
             v
           Result
```

Example:

```java
numbers.stream()
       .filter(n -> n > 10)
       .map(n -> n * 2)
       .forEach(System.out::println);
```

### Explanation

1. Data Source: `numbers`.
2. Intermediate Operation: `filter()` and `map()`.
3. Terminal Operation: `forEach()`.
4. Result: Printed values.

## 7.3 Important Stream Characteristics

- A Stream does not store elements.
- A Stream processes elements from a data source.
- Stream operations do not normally modify the original collection.
- Intermediate operations are lazy.
- A Stream can be consumed only once.
- Stream operations can be chained.
- Streams support sequential and parallel processing.

---

# 8. Creating Streams from Collections and Arrays

## 8.1 Stream from Collection

```java
import java.util.*;

public class CollectionStreamDemo {

    public static void main(String[] args) {

        List<String> names =
                Arrays.asList("Anurag", "Rahul", "Sushant");

        names.stream()
             .forEach(System.out::println);
    }
}
```

## 8.2 Stream from Array

```java
import java.util.Arrays;

public class ArrayStreamDemo {

    public static void main(String[] args) {

        int[] numbers = {10, 20, 30, 40, 50};

        Arrays.stream(numbers)
              .forEach(System.out::println);
    }
}
```

## 8.3 Stream Using Stream.of()

```java
import java.util.stream.Stream;

public class StreamOfDemo {

    public static void main(String[] args) {

        Stream.of("Java", "Python", "C++")
              .forEach(System.out::println);
    }
}
```

## 8.4 Empty Stream

```java
Stream<String> stream = Stream.empty();
```

---

# 9. Intermediate Operations

Intermediate operations transform or filter a Stream and return another Stream.

They are lazy, which means they execute when a terminal operation is invoked.

Important intermediate operations:

- filter()
- map()
- flatMap()
- sorted()
- distinct()
- limit()
- skip()

---

## 9.1 filter()

### Introduction

`filter()` is used to select elements that satisfy a condition.

It accepts a Predicate.

### Syntax

```java
stream.filter(condition);
```

### Example

```java
import java.util.*;

public class FilterDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 15, 20, 25, 30, 35);

        numbers.stream()
               .filter(n -> n % 2 == 0)
               .forEach(System.out::println);
    }
}
```

**Output:**

```text
10
20
30
```

---

## 9.2 map()

### Introduction

`map()` transforms each element into another value.

It accepts a Function.

### Syntax

```java
stream.map(transformation);
```

### Example

```java
import java.util.*;

public class MapStreamDemo {

    public static void main(String[] args) {

        List<String> names =
                Arrays.asList("anurag", "rahul", "sushant");

        names.stream()
             .map(String::toUpperCase)
             .forEach(System.out::println);
    }
}
```

**Output:**

```text
ANURAG
RAHUL
SUSHANT
```

### Another Example

```java
List<Integer> numbers =
        Arrays.asList(1, 2, 3, 4, 5);

numbers.stream()
       .map(n -> n * n)
       .forEach(System.out::println);
```

**Output:**

```text
1
4
9
16
25
```

---

## 9.3 flatMap()

### Introduction

`flatMap()` is used to flatten nested structures and transform each element into a Stream.

It is useful when working with:

- List of Lists.
- Nested collections.
- Multiple values inside each record.

### Difference Between map() and flatMap()

**map():**

Transforms each element into one result.

**flatMap():**

Transforms each element into a Stream and flattens the resulting Streams into one Stream.

### Example

```java
import java.util.*;
import java.util.stream.*;

public class FlatMapDemo {

    public static void main(String[] args) {

        List<List<Integer>> numbers = Arrays.asList(
                Arrays.asList(1, 2),
                Arrays.asList(3, 4),
                Arrays.asList(5, 6)
        );

        List<Integer> result = numbers.stream()
                .flatMap(list -> list.stream())
                .collect(Collectors.toList());

        System.out.println(result);
    }
}
```

**Output:**

```text
[1, 2, 3, 4, 5, 6]
```

---

## 9.4 sorted()

### Introduction

`sorted()` sorts elements in natural or custom order.

### Natural Sorting

```java
List<Integer> numbers =
        Arrays.asList(50, 10, 40, 20, 30);

numbers.stream()
       .sorted()
       .forEach(System.out::println);
```

**Output:**

```text
10
20
30
40
50
```

### Custom Sorting

```java
numbers.stream()
       .sorted(Comparator.reverseOrder())
       .forEach(System.out::println);
```

**Output:**

```text
50
40
30
20
10
```

---

## 9.5 distinct()

### Introduction

`distinct()` removes duplicate elements from a Stream according to their equality.

### Example

```java
import java.util.*;

public class DistinctDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 20, 10, 30, 20, 40);

        numbers.stream()
               .distinct()
               .forEach(System.out::println);
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

For custom objects, `distinct()` relies on properly implemented `equals()` and `hashCode()`.

---

## 9.6 limit()

### Introduction

`limit()` restricts a Stream to a maximum number of elements.

### Example

```java
import java.util.*;

public class LimitDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 20, 30, 40, 50);

        numbers.stream()
               .limit(3)
               .forEach(System.out::println);
    }
}
```

**Output:**

```text
10
20
30
```

---

## 9.7 skip()

### Introduction

`skip()` skips the first specified number of elements.

### Example

```java
import java.util.*;

public class SkipDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 20, 30, 40, 50);

        numbers.stream()
               .skip(2)
               .forEach(System.out::println);
    }
}
```

**Output:**

```text
30
40
50
```

### Intermediate Operations Summary

| Operation | Purpose | Input |
|---|---|---|
| filter() | Select elements | Predicate |
| map() | Transform elements | Function |
| flatMap() | Flatten nested Streams | Function returning Stream |
| sorted() | Sort elements | Optional Comparator |
| distinct() | Remove duplicates | None |
| limit() | Restrict number of elements | Maximum count |
| skip() | Skip first elements | Number to skip |

---

# 10. Terminal Operations

Terminal operations produce a final result or perform an action.

They trigger execution of the Stream pipeline.

Important terminal operations:

- forEach()
- collect()
- count()
- reduce()
- min()
- max()
- findFirst()
- anyMatch()
- allMatch()
- noneMatch()

---

## 10.1 forEach()

Used to perform an action on every element.

```java
List<String> names =
        Arrays.asList("Anurag", "Rahul", "Sushant");

names.stream()
     .forEach(System.out::println);
```

---

## 10.2 collect()

Used to collect Stream results into a collection or another result container.

```java
import java.util.*;
import java.util.stream.*;

public class CollectDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 20, 30, 40, 50);

        List<Integer> result = numbers.stream()
                .filter(n -> n > 20)
                .collect(Collectors.toList());

        System.out.println(result);
    }
}
```

**Output:**

```text
[30, 40, 50]
```

---

## 10.3 count()

Returns the number of elements in a Stream.

```java
List<Integer> numbers =
        Arrays.asList(10, 20, 30, 40, 50);

long count = numbers.stream()
        .filter(n -> n > 20)
        .count();

System.out.println(count);
```

**Output:**

```text
3
```

---

## 10.4 reduce()

### Introduction

`reduce()` combines multiple elements into a single result.

It is useful for aggregation operations such as:

- Sum.
- Product.
- Finding combined values.

### Syntax

```java
stream.reduce(identity, accumulator);
```

### Example: Sum

```java
import java.util.*;

public class ReduceDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 20, 30, 40, 50);

        int sum = numbers.stream()
                .reduce(0, (a, b) -> a + b);

        System.out.println("Sum: " + sum);
    }
}
```

**Output:**

```text
Sum: 150
```

### Dry Run

```text
Initial Value = 0

0 + 10 = 10
10 + 20 = 30
30 + 30 = 60
60 + 40 = 100
100 + 50 = 150
```

Final result = 150.

### Product Example

```java
int product = numbers.stream()
        .reduce(1, (a, b) -> a * b);
```

---

## 10.5 min()

Returns the minimum element according to the supplied ordering.

```java
List<Integer> numbers =
        Arrays.asList(50, 10, 40, 20, 30);

Optional<Integer> minimum = numbers.stream()
        .min(Integer::compareTo);

System.out.println(minimum.orElse(null));
```

**Output:**

```text
10
```

---

## 10.6 max()

Returns the maximum element.

```java
Optional<Integer> maximum = numbers.stream()
        .max(Integer::compareTo);

System.out.println(maximum.orElse(null));
```

**Output:**

```text
50
```

**Important:** `min()` and `max()` return Optional because the Stream may be empty.

---

## 10.7 findFirst()

Returns the first element of a Stream, if present.

```java
List<Integer> numbers =
        Arrays.asList(10, 20, 30, 40);

Optional<Integer> result = numbers.stream()
        .filter(n -> n > 20)
        .findFirst();

System.out.println(result.orElse(null));
```

**Output:**

```text
30
```

---

## 10.8 anyMatch()

Checks whether at least one element satisfies a condition.

```java
boolean result = numbers.stream()
        .anyMatch(n -> n > 30);

System.out.println(result);
```

**Output:**

```text
true
```

---

## 10.9 allMatch()

Checks whether every element satisfies a condition.

```java
boolean result = numbers.stream()
        .allMatch(n -> n > 0);

System.out.println(result);
```

**Output:**

```text
true
```

---

## 10.10 noneMatch()

Checks whether no element satisfies a condition.

```java
boolean result = numbers.stream()
        .noneMatch(n -> n < 0);

System.out.println(result);
```

**Output:**

```text
true
```

### Terminal Operations Summary

| Operation | Purpose | Return Type |
|---|---|---|
| forEach() | Performs action | void |
| collect() | Collects results | Depends on Collector |
| count() | Counts elements | long |
| reduce() | Combines elements | Optional or result type |
| min() | Minimum value | Optional<T> |
| max() | Maximum value | Optional<T> |
| findFirst() | First element | Optional<T> |
| anyMatch() | At least one match | boolean |
| allMatch() | All elements match | boolean |
| noneMatch() | No element matches | boolean |

---

# 11. Collectors Utility Class

## 11.1 Introduction

`Collectors` is a utility class in the `java.util.stream` package.

It provides predefined Collector implementations used with the `collect()` terminal operation.

Important methods:

- toList()
- toSet()
- groupingBy()
- partitioningBy()
- joining()

---

## 11.2 toList()

Collects Stream elements into a List.

```java
List<Integer> result = Stream.of(10, 20, 30, 40)
        .collect(Collectors.toList());

System.out.println(result);
```

**Output:**

```text
[10, 20, 30, 40]
```

Java 16+ also provides:

```java
List<Integer> result = Stream.of(10, 20, 30)
        .toList();
```

The List returned by `Stream.toList()` is unmodifiable.

---

## 11.3 toSet()

Collects elements into a Set.

```java
Set<Integer> result = Stream.of(10, 20, 10, 30, 20)
        .collect(Collectors.toSet());

System.out.println(result);
```

**Output:** Contains the unique values 10, 20 and 30. Set iteration order is not guaranteed for this collector.

---

## 11.4 groupingBy()

Groups elements according to a selected property.

### Example: Group Names by First Character

```java
import java.util.*;
import java.util.stream.*;

public class GroupingDemo {

    public static void main(String[] args) {

        List<String> names =
                Arrays.asList("Anurag", "Amit", "Rahul",
                              "Rudresh", "Sushant");

        Map<Character, List<String>> result =
                names.stream()
                     .collect(Collectors.groupingBy(
                             name -> name.charAt(0)
                     ));

        System.out.println(result);
    }
}
```

**Output:** A map containing groups for A, R and S. The map's printed iteration order is not guaranteed.

---

## 11.5 partitioningBy()

Divides elements into exactly two groups based on a Predicate:

- true
- false

### Example: Even and Odd Numbers

```java
import java.util.*;
import java.util.stream.*;

public class PartitioningDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(1, 2, 3, 4, 5, 6);

        Map<Boolean, List<Integer>> result =
                numbers.stream()
                       .collect(Collectors.partitioningBy(
                               n -> n % 2 == 0
                       ));

        System.out.println(result);
    }
}
```

**Output:**

```text
{false=[1, 3, 5], true=[2, 4, 6]}
```

---

## 11.6 joining()

Combines String elements into a single String.

### Example

```java
import java.util.*;
import java.util.stream.*;

public class JoiningDemo {

    public static void main(String[] args) {

        List<String> names =
                Arrays.asList("Anurag", "Rahul", "Sushant");

        String result = names.stream()
                .collect(Collectors.joining(", "));

        System.out.println(result);
    }
}
```

**Output:**

```text
Anurag, Rahul, Sushant
```

### Joining with Prefix and Suffix

```java
String result = names.stream()
        .collect(Collectors.joining(", ", "[", "]"));
```

**Output:**

```text
[Anurag, Rahul, Sushant]
```

### Collectors Summary

| Method | Purpose |
|---|---|
| toList() | Collect into List |
| toSet() | Collect into Set |
| groupingBy() | Group by a classification |
| partitioningBy() | Divide into true and false groups |
| joining() | Join Strings |

---

# 12. Parallel Streams

## 12.1 Introduction

A Parallel Stream processes elements using multiple threads, generally through the ForkJoin common pool.

It can help improve performance for suitable large-scale processing tasks.

### Sequential Stream

Processes elements sequentially.

```java
numbers.stream()
       .forEach(System.out::println);
```

### Parallel Stream

Processes elements in parallel.

```java
numbers.parallelStream()
       .forEach(System.out::println);
```

### Example

```java
import java.util.*;
import java.util.stream.*;

public class ParallelStreamDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                IntStream.rangeClosed(1, 10)
                         .boxed()
                         .toList();

        numbers.parallelStream()
               .forEach(number ->
                       System.out.println(
                               number + " : " +
                               Thread.currentThread().getName()
                       )
               );
    }
}
```

**Output:**

The output order and thread names can vary because multiple threads process elements concurrently.

### Sequential vs Parallel Stream

| Feature | Sequential Stream | Parallel Stream |
|---|---|---|
| Execution | One processing thread at a time | Multiple threads may process elements |
| Performance | Suitable for many normal tasks | Can help with suitable CPU-intensive tasks |
| Complexity | Easier to reason about | Requires attention to thread safety |
| Ordering | Encounter order can be preserved | Some operations may not preserve output order |
| Overhead | Usually lower | Has parallelization overhead |

### Important Points

- Parallel streams are not automatically faster.
- Small collections may perform better sequentially.
- Shared mutable variables can cause race conditions.
- Avoid modifying shared collections inside parallel operations.
- Use `forEachOrdered()` when encounter order must be preserved.
- Parallel operations should ideally be stateless and non-interfering.

---

# 13. Advantages of Stream API over Traditional Iteration

| Traditional Iteration | Stream API |
|---|---|
| Uses explicit loops | Uses declarative operations |
| Requires manual filtering | Provides filter() |
| Requires manual transformation | Provides map() |
| Requires manual aggregation | Provides reduce() |
| More boilerplate in many cases | More concise pipelines |
| Parallel processing requires manual thread management | Supports parallel streams |

### Important Stream API Benefits

1. Readable and concise code.
2. Easy filtering and transformation.
3. Supports functional programming.
4. Lazy intermediate operations.
5. Supports parallel processing.
6. Provides grouping and aggregation.
7. Reduces repetitive iteration code.

### Stream API Limitations

- A Stream cannot be reused after a terminal operation.
- Debugging complex pipelines may be difficult.
- Parallel streams are not always faster.
- Stateful operations and side effects can cause problems.
- Streams are not a replacement for every loop.

---

# 14. Lab 1: Create Custom Functional Interfaces Using Lambda Expressions

## Problem Statement

Create custom functional interfaces and implement them using lambda expressions.

### Program

```java
@FunctionalInterface
interface Addition {
    int add(int a, int b);
}

@FunctionalInterface
interface Greeting {
    void greet(String name);
}

@FunctionalInterface
interface Square {
    int calculate(int number);
}

public class CustomFunctionalInterfaceDemo {

    public static void main(String[] args) {

        Addition addition = (a, b) -> a + b;

        Greeting greeting =
                name -> System.out.println("Hello " + name);

        Square square = n -> n * n;

        System.out.println(addition.add(10, 20));

        greeting.greet("Anurag");

        System.out.println(square.calculate(5));
    }
}
```

### Output

```text
30
Hello Anurag
25
```

### Explanation

Three custom functional interfaces are created:

- Addition: Adds two numbers.
- Greeting: Displays a greeting.
- Square: Calculates square of a number.

Each interface is implemented using a lambda expression.

---

# 15. Lab 2: Predicate, Function, Consumer and Supplier

## Program

```java
import java.util.function.*;

public class BuiltInFunctionalInterfaceDemo {

    public static void main(String[] args) {

        // Predicate
        Predicate<Integer> isEven =
                n -> n % 2 == 0;

        System.out.println(isEven.test(10));

        // Function
        Function<Integer, Integer> square =
                n -> n * n;

        System.out.println(square.apply(5));

        // Consumer
        Consumer<String> display =
                name -> System.out.println("Hello " + name);

        display.accept("Anurag");

        // Supplier
        Supplier<String> message =
                () -> "Welcome to Java 17";

        System.out.println(message.get());
    }
}
```

### Output

```text
true
25
Hello Anurag
Welcome to Java 17
```

---

# 16. Lab 3: Sorting and Searching Using Lambda Expressions

## Problem Statement

Sort a list using lambda expressions and search for elements using Stream API.

### Program

```java
import java.util.*;

public class LambdaSortingSearchingDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                new ArrayList<>(
                        Arrays.asList(50, 10, 40, 20, 30)
                );

        // Ascending sort
        numbers.sort((a, b) -> Integer.compare(a, b));

        System.out.println("Ascending: " + numbers);

        // Descending sort
        numbers.sort((a, b) -> Integer.compare(b, a));

        System.out.println("Descending: " + numbers);

        // Search
        boolean found = numbers.stream()
                .anyMatch(n -> n == 30);

        System.out.println("30 Found: " + found);

        // Find first number greater than 20
        Optional<Integer> result = numbers.stream()
                .filter(n -> n > 20)
                .findFirst();

        System.out.println("First Match: " +
                result.orElse(null));
    }
}
```

### Output

```text
Ascending: [10, 20, 30, 40, 50]
Descending: [50, 40, 30, 20, 10]
30 Found: true
First Match: 50
```

---

# 17. Lab 4: Method References and Constructor References

## Program

```java
import java.util.*;
import java.util.function.*;

class Student {

    String name;

    Student() {
        this.name = "Default Student";
    }

    Student(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return name;
    }
}

public class MethodReferenceDemo {

    public static void display(String name) {
        System.out.println(name);
    }

    public void print(String name) {
        System.out.println("Student: " + name);
    }

    public static void main(String[] args) {

        List<String> names =
                Arrays.asList("Anurag", "Rahul", "Sushant");

        // Static method reference
        names.forEach(MethodReferenceDemo::display);

        // Instance method reference
        MethodReferenceDemo obj =
                new MethodReferenceDemo();

        names.forEach(obj::print);

        // Constructor reference without arguments
        Supplier<Student> supplier = Student::new;

        Student s1 = supplier.get();

        // Constructor reference with argument
        Function<String, Student> creator = Student::new;

        Student s2 = creator.apply("Anurag");

        System.out.println(s1);
        System.out.println(s2);
    }
}
```

### Output

```text
Anurag
Rahul
Sushant
Student: Anurag
Student: Rahul
Student: Sushant
Default Student
Anurag
```

---

# 18. Lab 5: Create Streams from Collections and Arrays

## Program

```java
import java.util.*;
import java.util.stream.*;

public class StreamCreationDemo {

    public static void main(String[] args) {

        // From List
        List<String> names =
                Arrays.asList("Anurag", "Rahul", "Sushant");

        System.out.println("List Stream:");

        names.stream().forEach(System.out::println);

        // From Array
        int[] numbers = {10, 20, 30, 40};

        System.out.println("Array Stream:");

        Arrays.stream(numbers)
              .forEach(System.out::println);

        // Using Stream.of()
        System.out.println("Stream.of():");

        Stream.of("Java", "Python", "C++")
              .forEach(System.out::println);
    }
}
```

---

# 19. Lab 6: Filtering and Transformation Using Stream API

## Problem Statement

Perform filtering and transformation operations using Stream API.

### Program

```java
import java.util.*;
import java.util.stream.*;

public class FilteringTransformationDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 15, 20, 25, 30, 35, 40);

        List<Integer> result = numbers.stream()

                // Filter even numbers
                .filter(n -> n % 2 == 0)

                // Square each number
                .map(n -> n * n)

                // Sort
                .sorted()

                // Collect
                .collect(Collectors.toList());

        System.out.println(result);
    }
}
```

### Output

```text
[100, 400, 900, 1600]
```

### Explanation

Original data:

```text
10, 15, 20, 25, 30, 35, 40
```

After filter:

```text
10, 20, 30, 40
```

After map:

```text
100, 400, 900, 1600
```

After sorted:

```text
100, 400, 900, 1600
```

---

# 20. Lab 7: Aggregate Operations

## Problem Statement

Implement aggregate operations using:

- reduce()
- count()
- min()
- max()

### Program

```java
import java.util.*;

public class AggregateOperationsDemo {

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 20, 30, 40, 50);

        // Sum using reduce
        int sum = numbers.stream()
                .reduce(0, Integer::sum);

        System.out.println("Sum: " + sum);

        // Count
        long count = numbers.stream().count();

        System.out.println("Count: " + count);

        // Minimum
        Optional<Integer> min = numbers.stream()
                .min(Integer::compareTo);

        System.out.println("Minimum: " + min.orElse(null));

        // Maximum
        Optional<Integer> max = numbers.stream()
                .max(Integer::compareTo);

        System.out.println("Maximum: " + max.orElse(null));
    }
}
```

### Output

```text
Sum: 150
Count: 5
Minimum: 10
Maximum: 50
```

---

# 21. Lab 8: Grouping and Partitioning Data Using Collectors

## Problem Statement

Use Collectors to group and partition student records.

### Program

```java
import java.util.*;
import java.util.stream.*;

class Student {

    String name;
    String department;
    int marks;

    Student(String name, String department, int marks) {
        this.name = name;
        this.department = department;
        this.marks = marks;
    }

    @Override
    public String toString() {
        return name + " - " + department + " - " + marks;
    }
}

public class GroupingPartitioningDemo {

    public static void main(String[] args) {

        List<Student> students = Arrays.asList(

                new Student("Anurag", "AIML", 90),
                new Student("Rahul", "CSE", 75),
                new Student("Sushant", "AIML", 85),
                new Student("Jayraj", "CSE", 45),
                new Student("Rudresh", "AIML", 60)
        );

        // Group by Department
        Map<String, List<Student>> grouped =
                students.stream()
                        .collect(Collectors.groupingBy(
                                student -> student.department
                        ));

        System.out.println("Grouped by Department:");

        grouped.forEach((department, list) ->
                System.out.println(department + " : " + list)
        );

        // Partition by Pass/Fail
        Map<Boolean, List<Student>> partitioned =
                students.stream()
                        .collect(Collectors.partitioningBy(
                                student -> student.marks >= 50
                        ));

        System.out.println("\nPartitioned Records:");

        System.out.println("Passed: " + partitioned.get(true));

        System.out.println("Failed: " + partitioned.get(false));
    }
}
```

### Output

The grouping result contains separate AIML and CSE groups.

The partitioning result contains:

**Passed:**

```text
Anurag, Rahul, Sushant, Rudresh
```

**Failed:**

```text
Jayraj
```

The exact printed order inside grouping and partitioning maps should not be relied upon.

---

# 22. Lab 9: Employee Management Mini Application Using Stream API

## Problem Statement

Create an Employee Management application using Stream API.

Employee details:

- Employee ID.
- Employee Name.
- Department.
- Salary.

Perform:

1. Display all employees.
2. Filter employees with salary greater than 50,000.
3. Display employee names in uppercase.
4. Sort employees by salary descending.
5. Find highest-paid employee.
6. Calculate total salary.
7. Calculate average salary.
8. Group employees by department.
9. Count employees in each department.
10. Partition employees into high-salary and low-salary groups.

## Complete Java Program

Save as `EmployeeStreamApplication.java`.

```java
import java.util.*;
import java.util.stream.*;

class Employee {

    private int id;
    private String name;
    private String department;
    private double salary;

    public Employee(int id, String name,
                    String department, double salary) {

        this.id = id;
        this.name = name;
        this.department = department;
        this.salary = salary;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getDepartment() {
        return department;
    }

    public double getSalary() {
        return salary;
    }

    @Override
    public String toString() {

        return id + " | " + name + " | " +
                department + " | " + salary;
    }
}

public class EmployeeStreamApplication {

    public static void main(String[] args) {

        List<Employee> employees = Arrays.asList(

                new Employee(101, "Anurag", "AIML", 65000),
                new Employee(102, "Rahul", "CSE", 45000),
                new Employee(103, "Sushant", "AIML", 75000),
                new Employee(104, "Jayraj", "Java", 55000),
                new Employee(105, "Rudresh", "CSE", 40000),
                new Employee(106, "Amit", "Java", 80000)
        );

        // 1. Display all employees
        System.out.println("\n--- All Employees ---");

        employees.stream()
                 .forEach(System.out::println);

        // 2. Salary greater than 50000
        System.out.println("\n--- Salary Greater Than 50000 ---");

        employees.stream()
                 .filter(e -> e.getSalary() > 50000)
                 .forEach(System.out::println);

        // 3. Employee names in uppercase
        System.out.println("\n--- Employee Names ---");

        employees.stream()
                 .map(e -> e.getName().toUpperCase())
                 .forEach(System.out::println);

        // 4. Sort by salary descending
        System.out.println("\n--- Salary Descending ---");

        employees.stream()
                 .sorted(
                     Comparator.comparingDouble(Employee::getSalary)
                               .reversed()
                 )
                 .forEach(System.out::println);

        // 5. Highest-paid employee
        System.out.println("\n--- Highest Paid Employee ---");

        employees.stream()
                 .max(Comparator.comparingDouble(Employee::getSalary))
                 .ifPresent(System.out::println);

        // 6. Total salary
        double totalSalary = employees.stream()
                .mapToDouble(Employee::getSalary)
                .sum();

        System.out.println("\nTotal Salary: " + totalSalary);

        // 7. Average salary
        double averageSalary = employees.stream()
                .mapToDouble(Employee::getSalary)
                .average()
                .orElse(0.0);

        System.out.println("Average Salary: " + averageSalary);

        // 8. Group by department
        System.out.println("\n--- Group By Department ---");

        Map<String, List<Employee>> grouped =
                employees.stream()
                         .collect(Collectors.groupingBy(
                                 Employee::getDepartment
                         ));

        grouped.forEach((department, list) ->
                System.out.println(department + " : " + list)
        );

        // 9. Count employees by department
        System.out.println("\n--- Department-wise Count ---");

        Map<String, Long> countByDepartment =
                employees.stream()
                         .collect(Collectors.groupingBy(
                                 Employee::getDepartment,
                                 Collectors.counting()
                         ));

        System.out.println(countByDepartment);

        // 10. Partition employees by salary
        System.out.println("\n--- Salary Partition ---");

        Map<Boolean, List<Employee>> partitioned =
                employees.stream()
                         .collect(Collectors.partitioningBy(
                                 e -> e.getSalary() >= 50000
                         ));

        System.out.println("High Salary: " +
                partitioned.get(true));

        System.out.println("Low Salary: " +
                partitioned.get(false));
    }
}
```

### Sample Output

```text
--- All Employees ---
101 | Anurag | AIML | 65000.0
102 | Rahul | CSE | 45000.0
103 | Sushant | AIML | 75000.0
104 | Jayraj | Java | 55000.0
105 | Rudresh | CSE | 40000.0
106 | Amit | Java | 80000.0

--- Salary Greater Than 50000 ---
101 | Anurag | AIML | 65000.0
103 | Sushant | AIML | 75000.0
104 | Jayraj | Java | 55000.0
106 | Amit | Java | 80000.0

--- Employee Names ---
ANURAG
RAHUL
SUSHANT
JAYRAJ
RUDRESH
AMIT

--- Highest Paid Employee ---
106 | Amit | Java | 80000.0

Total Salary: 360000.0
Average Salary: 60000.0
```

The grouping, department counts and partitioning sections display the corresponding department-wise results. Map iteration order is not guaranteed.

### Explanation

| Requirement | Stream Operation |
|---|---|
| Display all employees | forEach() |
| Filter by salary | filter() |
| Convert names to uppercase | map() |
| Sort by salary | sorted() |
| Highest-paid employee | max() |
| Total salary | mapToDouble() and sum() |
| Average salary | average() |
| Group by department | groupingBy() |
| Department-wise count | groupingBy() and counting() |
| High/low salary groups | partitioningBy() |

---

# 23. Interview Questions

## Basic Questions

**1. What is Functional Programming?**

It is a programming paradigm that emphasizes functions, function composition and reducing unnecessary state changes.

**2. What is a Functional Interface?**

An interface containing exactly one abstract method.

**3. What is SAM?**

Single Abstract Method.

**4. What is Lambda Expression?**

A concise implementation of a functional interface.

**5. In which Java version were lambda expressions introduced?**

Java 8.

**6. What is Predicate?**

A functional interface used to test conditions and return boolean values.

**7. What is Function?**

A functional interface that accepts an input and returns an output.

**8. What is Consumer?**

A functional interface that accepts an input and returns nothing.

**9. What is Supplier?**

A functional interface that supplies a result without accepting input.

**10. What is Method Reference?**

A shorter form of lambda syntax used to refer to an existing method.

## Intermediate Questions

**11. What is Stream API?**

A Java API for processing data using declarative operations.

**12. Which Java version introduced Stream API?**

Java 8.

**13. What is a Stream Pipeline?**

A sequence of a data source, intermediate operations and terminal operations.

**14. What is filter()?**

An intermediate operation used to select elements satisfying a condition.

**15. What is map()?**

An intermediate operation used to transform elements.

**16. What is flatMap()?**

An operation that maps elements to Streams and flattens them into one Stream.

**17. What is sorted()?**

An intermediate operation used to sort Stream elements.

**18. What is distinct()?**

An operation that removes duplicate elements according to equality.

**19. What is limit()?**

Restricts the maximum number of elements.

**20. What is skip()?**

Skips the first specified number of elements.

## Advanced Questions

**21. What is the difference between map() and flatMap()?**

`map()` transforms each element, whereas `flatMap()` transforms elements into Streams and flattens them.

**22. What are intermediate operations?**

Operations that return another Stream, such as filter(), map() and sorted().

**23. What are terminal operations?**

Operations that produce a result or perform an action, such as collect(), count() and forEach().

**24. What is lazy evaluation?**

Intermediate Stream operations are not executed until a terminal operation triggers the pipeline.

**25. Can a Stream be reused?**

No. A Stream can be consumed only once.

**26. What is reduce()?**

A terminal operation used to combine elements into a single result.

**27. What is Optional?**

A container that may or may not contain a non-null value.

**28. What is Collectors?**

A utility class providing predefined Collector implementations.

**29. Difference between groupingBy() and partitioningBy()?**

groupingBy() can create multiple groups; partitioningBy() always creates two groups based on a boolean condition.

**30. What is a Parallel Stream?**

A Stream that processes data in parallel using multiple threads.

**31. Is Parallel Stream always faster?**

No. Parallelization has overhead and depends on data size, processing cost and environment.

**32. What is the difference between forEach() and forEachOrdered()?**

forEach() does not guarantee encounter order for parallel processing; forEachOrdered() respects encounter order.

**33. What is a method reference operator?**

`::`.

**34. What is a constructor reference?**

A reference to a constructor using `ClassName::new`.

**35. What is PECS?**

A generic wildcard guideline: Producer Extends, Consumer Super.

---

# 24. MCQ Practice

**1. Which Java version introduced Lambda Expressions?**

A. Java 5  
B. Java 7  
C. Java 8  
D. Java 11  

**Answer:** C. Java 8

**2. How many abstract methods can a functional interface contain?**

A. One  
B. Two  
C. Three  
D. Unlimited  

**Answer:** A. One

**3. Which interface returns a boolean value?**

A. Consumer  
B. Supplier  
C. Predicate  
D. Function  

**Answer:** C. Predicate

**4. Which method belongs to Predicate?**

A. apply()  
B. test()  
C. accept()  
D. get()  

**Answer:** B. test()

**5. Which interface transforms input into output?**

A. Predicate  
B. Consumer  
C. Function  
D. Supplier  

**Answer:** C. Function

**6. Which interface does not return a result?**

A. Consumer  
B. Supplier  
C. Function  
D. Predicate  

**Answer:** A. Consumer

**7. Which method belongs to Supplier?**

A. test()  
B. get()  
C. accept()  
D. apply()  

**Answer:** B. get()

**8. Which operator is used for Method References?**

A. ->  
B. ::  
C. .  
D. =>  

**Answer:** B. ::

**9. Which operation filters elements?**

A. map()  
B. filter()  
C. reduce()  
D. collect()  

**Answer:** B. filter()

**10. Which operation transforms elements?**

A. filter()  
B. count()  
C. map()  
D. min()  

**Answer:** C. map()

**11. Which operation flattens nested Streams?**

A. map()  
B. flatMap()  
C. filter()  
D. sorted()  

**Answer:** B. flatMap()

**12. Which is a terminal operation?**

A. filter()  
B. map()  
C. sorted()  
D. collect()  

**Answer:** D. collect()

**13. Which operation counts elements?**

A. size()  
B. count()  
C. length()  
D. frequency()  

**Answer:** B. count()

**14. Which operation combines elements into one result?**

A. reduce()  
B. filter()  
C. skip()  
D. limit()  

**Answer:** A. reduce()

**15. Which Collector groups elements based on a classification?**

A. joining()  
B. partitioningBy()  
C. groupingBy()  
D. toList()  

**Answer:** C. groupingBy()

**16. Which Collector divides elements into two groups?**

A. groupingBy()  
B. partitioningBy()  
C. joining()  
D. toSet()  

**Answer:** B. partitioningBy()

**17. Can a Stream be reused after a terminal operation?**

A. Yes  
B. No  
C. Only parallel streams  
D. Only collections streams  

**Answer:** B. No

**18. Which operation returns Optional?**

A. count()  
B. forEach()  
C. min()  
D. collect()  

**Answer:** C. min()

**19. Which operation checks whether all elements satisfy a condition?**

A. anyMatch()  
B. allMatch()  
C. noneMatch()  
D. findFirst()  

**Answer:** B. allMatch()

**20. Which method is used to create a parallel Stream from a Collection?**

A. stream()  
B. parallelStream()  
C. parallel()  
D. collect()  

**Answer:** B. parallelStream()

---

# 25. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Functional Programming | Function-oriented programming approach |
| Functional Interface | Exactly one abstract method |
| Lambda | Concise functional interface implementation |
| Predicate | Tests a condition |
| Function | Transforms data |
| Consumer | Accepts input, returns nothing |
| Supplier | Supplies a value |
| Method Reference | Uses `::` |
| Static Method Reference | `ClassName::methodName` |
| Instance Method Reference | `object::methodName` |
| Constructor Reference | `ClassName::new` |
| Stream API | Processes data declaratively |
| filter() | Filters elements |
| map() | Transforms elements |
| flatMap() | Flattens nested Streams |
| sorted() | Sorts elements |
| distinct() | Removes duplicates |
| limit() | Restricts elements |
| skip() | Skips elements |
| forEach() | Performs action |
| collect() | Collects results |
| count() | Counts elements |
| reduce() | Aggregates elements |
| min() | Finds minimum |
| max() | Finds maximum |
| findFirst() | Finds first element |
| anyMatch() | Checks at least one |
| allMatch() | Checks all |
| noneMatch() | Checks none |
| groupingBy() | Groups records |
| partitioningBy() | Divides into two groups |
| joining() | Joins Strings |
| parallelStream() | Processes elements in parallel |

---

# Practical Checklist

- [ ] Understand Functional Programming.
- [ ] Understand Functional Interfaces.
- [ ] Create custom functional interfaces.
- [ ] Practice Predicate.
- [ ] Practice Function.
- [ ] Practice Consumer.
- [ ] Practice Supplier.
- [ ] Practice Lambda Expressions.
- [ ] Practice Static Method References.
- [ ] Practice Instance Method References.
- [ ] Practice Constructor References.
- [ ] Create Streams from Collections.
- [ ] Create Streams from Arrays.
- [ ] Practice filter().
- [ ] Practice map().
- [ ] Practice flatMap().
- [ ] Practice sorted().
- [ ] Practice distinct().
- [ ] Practice limit() and skip().
- [ ] Practice forEach() and collect().
- [ ] Practice reduce(), count(), min() and max().
- [ ] Practice findFirst() and matching operations.
- [ ] Practice groupingBy() and partitioningBy().
- [ ] Understand Parallel Streams.
- [ ] Complete Employee Management Mini Application.
- [ ] Revise interview questions and MCQs.

---

# Additional Practice Assignments

1. Filter even and odd numbers using Predicate.
2. Convert a list of names into uppercase using Function.
3. Print employee records using Consumer.
4. Generate random OTP values using Supplier.
5. Sort students by marks using Lambda.
6. Find employees earning more than ₹50,000 using filter().
7. Convert all student names to uppercase using map().
8. Flatten a List of Lists using flatMap().
9. Find the sum of all numbers using reduce().
10. Find the highest-paid employee using max().
11. Group employees by department using groupingBy().
12. Partition students into pass and fail groups using partitioningBy().
13. Join all employee names using joining().
14. Find duplicate elements using groupingBy() and counting().
15. Create a product management application using Stream API.

---

# Recommended Folder Structure

```text
Java/
└── Sessions-25-26-27-Functional-Programming-Stream-API/
    ├── README.md
    └── programs/
        ├── CustomFunctionalInterfaceDemo.java
        ├── PredicateDemo.java
        ├── FunctionDemo.java
        ├── ConsumerDemo.java
        ├── SupplierDemo.java
        ├── LambdaDemo.java
        ├── StaticMethodReferenceDemo.java
        ├── InstanceMethodReferenceDemo.java
        ├── ConstructorReferenceDemo.java
        ├── CollectionStreamDemo.java
        ├── ArrayStreamDemo.java
        ├── FilterDemo.java
        ├── MapStreamDemo.java
        ├── FlatMapDemo.java
        ├── SortingStreamDemo.java
        ├── ReduceDemo.java
        ├── CollectorsDemo.java
        ├── ParallelStreamDemo.java
        └── EmployeeStreamApplication.java
```

---

**End of Sessions 25, 26 & 27 – Functional Programming and Stream API**

*These notes cover the CMCE August 2026 syllabus with Java 8+ functional programming features, Java 17 examples, practical assignments, interview questions and revision material.*

