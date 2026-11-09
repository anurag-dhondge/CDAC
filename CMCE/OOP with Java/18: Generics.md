# Session 18: Generics in Java

**Course:** CMCE – August 2026 Batch  
**Subject:** Core Java  
**Topics:** Introduction to Generics, Generic Classes, Generic Methods, Wildcards (Upper Bound and Lower Bound)

---

# 1. Introduction to Generics

**Generics** in Java allow us to write classes, interfaces, and methods that can work with different data types while maintaining type safety.

Generics were introduced in **Java 5**.

Without generics, we often need to use the `Object` class to store different types of data. This can cause type casting problems and runtime exceptions.

With generics, we specify the data type while creating an object or calling a method.

### Why Do We Need Generics?

Consider a normal ArrayList without generics.

### Example: Without Generics

```java
import java.util.ArrayList;

public class WithoutGenericsDemo {

    public static void main(String[] args) {

        ArrayList list = new ArrayList();

        list.add(100);
        list.add("Java");
        list.add(25.5);

        Integer number = (Integer) list.get(0);

        System.out.println(number);

        // Runtime error:
        // Integer value = (Integer) list.get(1);
    }
}
```

**Output:**

```text
100
```

Here:

- Different types of values can be stored.
- The compiler does not check the intended type of each element.
- Explicit type casting is required.
- Incorrect casting can cause `ClassCastException` at runtime.

### Example: With Generics

```java
import java.util.ArrayList;

public class WithGenericsDemo {

    public static void main(String[] args) {

        ArrayList<Integer> list = new ArrayList<>();

        list.add(100);
        list.add(200);
        list.add(300);

        // Compile-time error:
        // list.add("Java");

        Integer number = list.get(0);

        System.out.println(number);
    }
}
```

**Output:**

```text
100
```

### Advantages of Generics

1. **Type Safety:** Prevents incompatible types from being added.
2. **No Explicit Casting:** Retrieved values have the specified type.
3. **Code Reusability:** One class or method can work with multiple data types.
4. **Compile-Time Checking:** Many type errors are detected by the compiler.
5. **Cleaner Code:** Reduces unnecessary type casting.

### Syntax

```java
ClassName<DataType> reference = new ClassName<>();
```

Examples:

```java
ArrayList<Integer> numbers = new ArrayList<>();

ArrayList<String> names = new ArrayList<>();

ArrayList<Double> prices = new ArrayList<>();
```

### Important Point

Generics work with reference types, not primitive types directly.

Incorrect:

```java
ArrayList<int> numbers = new ArrayList<>();
```

Correct:

```java
ArrayList<Integer> numbers = new ArrayList<>();
```

Java provides wrapper classes for primitive types:

| Primitive Type | Wrapper Class |
|---|---|
| int | Integer |
| char | Character |
| double | Double |
| float | Float |
| long | Long |
| short | Short |
| byte | Byte |
| boolean | Boolean |

Java supports autoboxing and unboxing when working with wrapper classes.

---

# 2. Generic Classes

A **generic class** is a class that can work with different data types using a type parameter.

Instead of creating separate classes for Integer, String, Double, etc., we can create one generic class.

### Syntax

```java
class ClassName<T> {

    T variable;

    void display(T value) {
        System.out.println(value);
    }
}
```

Here:

- `T` is a type parameter.
- It represents the data type that will be supplied when creating an object.
- `T` is not a Java keyword. It is a conventional name.

### Example 1: Simple Generic Class

```java
class Box<T> {

    private T value;

    public void setValue(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }
}

public class GenericClassDemo {

    public static void main(String[] args) {

        Box<Integer> intBox = new Box<>();

        intBox.setValue(100);

        System.out.println("Integer: " +
                intBox.getValue());

        Box<String> stringBox = new Box<>();

        stringBox.setValue("Java Generics");

        System.out.println("String: " +
                stringBox.getValue());

        Box<Double> doubleBox = new Box<>();

        doubleBox.setValue(25.5);

        System.out.println("Double: " +
                doubleBox.getValue());
    }
}
```

**Output:**

```text
Integer: 100
String: Java Generics
Double: 25.5
```

### Explanation

```java
class Box<T>
```

Declares a generic class with one type parameter.

```java
private T value;
```

The variable can store the type specified when the object is created.

```java
Box<Integer> intBox = new Box<>();
```

Creates a Box that stores Integer values.

```java
Box<String> stringBox = new Box<>();
```

Creates a Box that stores String values.

The same class works with multiple data types.

### Example 2: Generic Class with Two Type Parameters

A generic class can contain multiple type parameters.

**Example: KeyValue.java**

```java
class KeyValue<K, V> {

    private K key;
    private V value;

    public KeyValue(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public void display() {
        System.out.println("Key: " + key);
        System.out.println("Value: " + value);
    }
}

public class GenericMultipleDemo {

    public static void main(String[] args) {

        KeyValue<Integer, String> student =
                new KeyValue<>(101, "Anurag");

        student.display();

        KeyValue<String, Double> product =
                new KeyValue<>("Laptop", 55000.0);

        product.display();
    }
}
```

**Output:**

```text
Key: 101
Value: Anurag
Key: Laptop
Value: 55000.0
```

### Common Generic Type Parameter Names

Java developers commonly use the following letters:

| Parameter | Meaning |
|---|---|
| T | Type |
| E | Element |
| K | Key |
| V | Value |
| N | Number |
| R | Return type |

These are naming conventions, not reserved keywords.

### Example: Generic Class with Three Parameters

```java
class StudentData<T, U, V> {

    T name;
    U rollNo;
    V marks;

    StudentData(T name, U rollNo, V marks) {
        this.name = name;
        this.rollNo = rollNo;
        this.marks = marks;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Roll No: " + rollNo);
        System.out.println("Marks: " + marks);
    }
}

public class StudentDataDemo {

    public static void main(String[] args) {

        StudentData<String, Integer, Double> s1 =
                new StudentData<>("Anurag", 101, 85.5);

        s1.display();
    }
}
```

**Output:**

```text
Name: Anurag
Roll No: 101
Marks: 85.5
```

---

# 3. Generic Methods

A **generic method** is a method that declares its own type parameter.

It can be declared inside:

- A normal class.
- A generic class.
- A static method.

A generic method can work with different data types without creating separate methods.

### Syntax

```java
public <T> void methodName(T value) {

    // Method body
}
```

Here:

- `<T>` declares the method's type parameter.
- `T` represents the type of the argument.
- The type parameter is written before the return type.

### Example 1: Simple Generic Method

```java
public class GenericMethodDemo {

    public <T> void display(T value) {

        System.out.println("Value: " + value);

        System.out.println("Type: " +
                value.getClass().getSimpleName());
    }

    public static void main(String[] args) {

        GenericMethodDemo obj =
                new GenericMethodDemo();

        obj.display(100);

        obj.display("Java");

        obj.display(25.5);
    }
}
```

**Output:**

```text
Value: 100
Type: Integer
Value: Java
Type: String
Value: 25.5
Type: Double
```

### Explanation

```java
public <T> void display(T value)
```

- `<T>` declares the generic method.
- `void` is the return type.
- `T` is the parameter type.
- The same method accepts different reference types.

### Example 2: Generic Static Method

A static method can also be generic.

```java
public class StaticGenericMethodDemo {

    public static <T> void print(T value) {

        System.out.println(value);
    }

    public static void main(String[] args) {

        print(100);

        print("Hello Java");

        print(45.6);
    }
}
```

**Output:**

```text
100
Hello Java
45.6
```

Notice:

```java
public static <T> void print(T value)
```

The `<T>` declaration appears before the return type.

### Example 3: Generic Method with Two Parameters

```java
public class GenericTwoParameterDemo {

    public static <T, U> void display(
            T first, U second) {

        System.out.println("First: " + first);

        System.out.println("Second: " + second);
    }

    public static void main(String[] args) {

        display(101, "Anurag");

        display("Price", 2500.50);
    }
}
```

**Output:**

```text
First: 101
Second: Anurag
First: Price
Second: 2500.5
```

### Example 4: Generic Method Returning a Value

```java
public class GenericReturnDemo {

    public static <T> T getValue(T value) {

        return value;
    }

    public static void main(String[] args) {

        Integer number = getValue(100);

        String name = getValue("Java");

        System.out.println(number);

        System.out.println(name);
    }
}
```

**Output:**

```text
100
Java
```

### Generic Class vs Generic Method

| Generic Class | Generic Method |
|---|---|
| Type parameter belongs to the class | Type parameter belongs to the method |
| Declared after class name | Declared before method return type |
| Used across class members | Used within that method's declaration |
| Example: `class Box<T>` | Example: `<T> void display(T value)` |

---

# 4. Bounded Type Parameters

Sometimes we want to restrict which types can be used with a generic class or method.

For this, Java provides **bounded type parameters**.

### Upper-Bounded Type Parameter

Use `extends` to restrict the type parameter to a particular class or its subclasses, or to types implementing a specified interface.

### Syntax

```java
<T extends Number>
```

This means T must be Number or a subclass of Number.

### Example

```java
class Calculator<T extends Number> {

    private T number;

    Calculator(T number) {
        this.number = number;
    }

    public double getDoubleValue() {
        return number.doubleValue();
    }
}

public class BoundedDemo {

    public static void main(String[] args) {

        Calculator<Integer> c1 =
                new Calculator<>(100);

        Calculator<Double> c2 =
                new Calculator<>(25.5);

        System.out.println(c1.getDoubleValue());

        System.out.println(c2.getDoubleValue());

        // Compile-time error:
        // Calculator<String> c3 =
        //         new Calculator<>("Java");
    }
}
```

**Output:**

```text
100.0
25.5
```

### Explanation

```java
<T extends Number>
```

Allowed types include:

- Integer
- Double
- Float
- Long
- Short
- Byte

String is not allowed because String does not extend Number.

### Multiple Bounds

A type parameter can have multiple bounds.

```java
<T extends Number & Comparable<T>>
```

Rules:

- A class bound, if present, must appear first.
- Additional interface bounds follow using `&`.
- Only one class can be specified as a bound.

Example:

```java
class NumberBox<T extends Number & Comparable<T>> {

    private T value;

    NumberBox(T value) {
        this.value = value;
    }

    public int compare(T other) {
        return value.compareTo(other);
    }
}
```

---

# 5. Wildcards in Generics

A **wildcard** is represented by the question mark `?`.

It represents an unknown type.

Wildcards are mainly used when passing generic types as method arguments.

### Syntax

```java
List<?> list;
```

This means the list can have elements of some unknown type.

There are three main wildcard forms:

1. Unbounded wildcard: `?`
2. Upper-bounded wildcard: `? extends Type`
3. Lower-bounded wildcard: `? super Type`

---

## 5.1 Unbounded Wildcard (?)

An unbounded wildcard represents an unknown type.

### Syntax

```java
List<?> list;
```

It can accept lists of different element types.

### Example

```java
import java.util.Arrays;
import java.util.List;

public class UnboundedWildcardDemo {

    public static void display(List<?> list) {

        for (Object value : list) {
            System.out.println(value);
        }
    }

    public static void main(String[] args) {

        List<Integer> numbers =
                Arrays.asList(10, 20, 30);

        List<String> names =
                Arrays.asList("Anurag", "Rahul");

        display(numbers);

        display(names);
    }
}
```

**Output:**

```text
10
20
30
Anurag
Rahul
```

### Important Points

- `?` represents an unknown type.
- Can accept List<Integer>, List<String>, List<Double>, etc.
- You can safely read elements as Object.
- You generally cannot add a non-null element because the actual element type is unknown.
- `null` can be added.

---

## 5.2 Upper-Bounded Wildcard (? extends Type)

An upper-bounded wildcard restricts the unknown type to a specified type or its subclasses/implementations.

### Syntax

```java
List<? extends Number> list;
```

It means the list contains elements of some unknown type that extends Number.

Allowed examples:

```java
List<Integer> numbers;

List<Double> values;

List<Float> decimals;
```

### Example

```java
import java.util.Arrays;
import java.util.List;

public class UpperBoundDemo {

    public static double calculateSum(
            List<? extends Number> list) {

        double sum = 0;

        for (Number number : list) {
            sum += number.doubleValue();
        }

        return sum;
    }

    public static void main(String[] args) {

        List<Integer> integers =
                Arrays.asList(10, 20, 30);

        List<Double> decimals =
                Arrays.asList(10.5, 20.5, 30.5);

        System.out.println(
                calculateSum(integers)
        );

        System.out.println(
                calculateSum(decimals)
        );
    }
}
```

**Output:**

```text
60.0
61.5
```

### Explanation

```java
List<? extends Number>
```

The method accepts a list of Number or its subclasses.

The method can read every element as Number.

However, we cannot safely add an Integer, Double, or another non-null value because the actual list element type is unknown.

For example:

```java
list.add(10); // Compile-time error
```

### When to Use Upper-Bounded Wildcards?

Use upper bounds when a method primarily needs to **read or consume values from a collection**.

---

## 5.3 Lower-Bounded Wildcard (? super Type)

A lower-bounded wildcard restricts the unknown type to a specified type or one of its supertypes.

### Syntax

```java
List<? super Integer> list;
```

It means the list's element type can be:

- Integer
- Number
- Object

### Example

```java
import java.util.ArrayList;
import java.util.List;

public class LowerBoundDemo {

    public static void addNumbers(
            List<? super Integer> list) {

        list.add(10);

        list.add(20);

        list.add(30);
    }

    public static void main(String[] args) {

        List<Integer> integers =
                new ArrayList<>();

        List<Number> numbers =
                new ArrayList<>();

        List<Object> objects =
                new ArrayList<>();

        addNumbers(integers);

        addNumbers(numbers);

        addNumbers(objects);

        System.out.println(integers);

        System.out.println(numbers);

        System.out.println(objects);
    }
}
```

**Output:**

```text
[10, 20, 30]
[10, 20, 30]
[10, 20, 30]
```

### Explanation

```java
List<? super Integer>
```

Accepts a list whose element type is Integer or a superclass of Integer.

We can safely add Integer values:

```java
list.add(100);
```

But when reading elements, the compiler only guarantees that they are Objects.

```java
Object value = list.get(0);
```

### When to Use Lower-Bounded Wildcards?

Use lower bounds when a method primarily needs to **write or add values into a collection**.

---

# 6. Difference Between Upper and Lower Bounded Wildcards

| Feature | Upper Bound | Lower Bound |
|---|---|---|
| Syntax | `? extends Type` | `? super Type` |
| Meaning | Type or its subtype | Type or its supertype |
| Main use | Reading values | Adding values |
| Reading | Can read as the upper-bound type | Safely read as Object |
| Adding non-null values | Generally not allowed | Can add values of the lower-bound type |
| Example | `List<? extends Number>` | `List<? super Integer>` |

### Visual Representation

**Upper Bound:**

```text
? extends Number

        Number
       /      \
  Integer    Double
       \      /
       Accepted
```

**Lower Bound:**

```text
? super Integer

       Object
          |
        Number
          |
       Integer
          |
       Accepted
```

The actual generic type can be the specified type or any compatible type in the indicated inheritance direction.

---

# 7. PECS Principle

PECS stands for:

**Producer Extends, Consumer Super.**

It is a useful rule for choosing wildcard bounds.

### Producer Extends

If a collection produces values for your method to read, use `extends`.

```java
public static double sum(
        List<? extends Number> numbers) {

    double total = 0;

    for (Number n : numbers) {
        total += n.doubleValue();
    }

    return total;
}
```

### Consumer Super

If a collection consumes values that your method adds, use `super`.

```java
public static void addIntegers(
        List<? super Integer> numbers) {

    numbers.add(10);
    numbers.add(20);
}
```

### Remember

| Requirement | Wildcard |
|---|---|
| Read Number values | `? extends Number` |
| Add Integer values | `? super Integer` |
| Accept any unknown type | `?` |

PECS is a guideline for designing APIs, not a rule that every wildcard method must follow.

---

# 8. Generic Class vs Generic Method vs Wildcard

| Feature | Generic Class | Generic Method | Wildcard |
|---|---|---|---|
| Purpose | Generic object/class | Generic operation | Accept unknown compatible types |
| Syntax | `class Box<T>` | `<T> void display(T value)` | `List<?>` |
| Type parameter | Class-level | Method-level | Unknown type |
| Common use | Reusable containers | Reusable methods | Flexible method arguments |

---

# 9. Important Generics Rules

### 1. Generics Cannot Use Primitive Types Directly

Incorrect:

```java
Box<int> box;
```

Correct:

```java
Box<Integer> box;
```

### 2. Generic Types Are Invariant

```java
List<Integer> integers = new ArrayList<>();

// Not allowed:
List<Number> numbers = integers;
```

Even though Integer extends Number, `List<Integer>` is not a subtype of `List<Number>`.

### 3. Cannot Create Objects Directly Using a Type Parameter

Incorrect:

```java
class Box<T> {
    T value = new T();
}
```

The type parameter is not available as a concrete runtime constructor type.

### 4. Cannot Create Generic Arrays Directly

Generally not allowed:

```java
T[] array = new T[10];
```

### 5. Static Fields Cannot Use a Class's Type Parameter

Incorrect:

```java
class Box<T> {
    static T value;
}
```

A static field belongs to the class, not to a particular generic type instantiation.

### 6. Type Erasure

Java implements generics using **type erasure**.

This means generic type information is largely removed during compilation, with appropriate casts and runtime checks inserted where necessary.

For example:

```java
ArrayList<String> names = new ArrayList<>();
```

The generic type argument String is not generally available through ordinary runtime reflection on the collection object.

**Important:** Generics provide compile-time type safety, but they do not create a separate runtime class for every type argument.

---

# 10. Complete Practical Example: Generic Utility Class

This example combines generic classes and generic methods.

```java
class DataContainer<T> {

    private T data;

    public void setData(T data) {
        this.data = data;
    }

    public T getData() {
        return data;
    }

    public static <E> void display(E value) {
        System.out.println("Value: " + value);
    }
}

public class GenericUtilityDemo {

    public static void main(String[] args) {

        DataContainer<String> name =
                new DataContainer<>();

        name.setData("Anurag");

        System.out.println(name.getData());

        DataContainer<Integer> marks =
                new DataContainer<>();

        marks.setData(90);

        System.out.println(marks.getData());

        DataContainer.display(100);

        DataContainer.display("Java Generics");
    }
}
```

**Output:**

```text
Anurag
90
Value: 100
Value: Java Generics
```

---

# 11. Important Interview Questions and Answers

**Q1. What are Generics in Java?**

Generics allow classes, interfaces, and methods to operate on different types while maintaining compile-time type safety.

**Q2. In which Java version were Generics introduced?**

Java 5.

**Q3. What are the advantages of Generics?**

Type safety, code reusability, reduced type casting, and compile-time checking.

**Q4. What is a generic class?**

A class that declares one or more type parameters.

**Q5. What is a generic method?**

A method that declares its own type parameter.

**Q6. What does T represent in Generics?**

T is a conventional name representing a type parameter.

**Q7. What are common type parameter names?**

T, E, K, V, N, and R.

**Q8. Can we use primitive types in Generics?**

No. We use wrapper classes such as Integer and Double.

**Q9. What is a bounded type parameter?**

It restricts the types that can be supplied to a generic class or method.

**Q10. What is the syntax for an upper-bounded type parameter?**

```java
<T extends Number>
```

**Q11. What is a wildcard?**

A wildcard represented by `?` stands for an unknown type.

**Q12. What are the three wildcard types?**

Unbounded, upper-bounded, and lower-bounded.

**Q13. What is an unbounded wildcard?**

`<?>` accepts a generic type with any element type.

**Q14. What is an upper-bounded wildcard?**

`<? extends Number>` accepts Number or its subclasses.

**Q15. What is a lower-bounded wildcard?**

`<? super Integer>` accepts Integer or its supertypes.

**Q16. What is PECS?**

Producer Extends, Consumer Super.

**Q17. Can we add elements to List<?>?**

We cannot safely add non-null elements because its actual type is unknown.

**Q18. Can we add Integer values to List<? super Integer>?**

Yes.

**Q19. Can we add Integer values to List<? extends Number>?**

No, because the actual list might be a List<Double>.

**Q20. What is type erasure?**

It is the compiler process that removes most generic type information from the generated bytecode while preserving necessary type checks and casts.

**Q21. Can a generic class have multiple type parameters?**

Yes.

```java
class Pair<K, V> {
}
```

**Q22. Can a static method be generic?**

Yes. A static method can declare its own type parameter.

**Q23. What is the difference between T and ?**

T is a declared type parameter. `?` is a wildcard representing an unknown type.

**Q24. Is List<Integer> a subtype of List<Number>?**

No. Generic types are invariant.

**Q25. Can we instantiate T using new T()?**

No. The type parameter is not available as a concrete runtime constructor type.

---

# 12. MCQs

**1. In which Java version were Generics introduced?**

A. Java 1.4  
B. Java 5  
C. Java 7  
D. Java 8  

**Answer: B. Java 5**

**2. Which symbol represents a generic type parameter?**

A. ?  
B. #  
C. T  
D. &  

**Answer: C. T**

**3. Which is a valid generic declaration?**

A. `ArrayList<int>`  
B. `ArrayList<Integer>`  
C. `ArrayList<primitive>`  
D. `ArrayList<void>`  

**Answer: B. ArrayList<Integer>**

**4. What is a generic class?**

A. Class that accepts only String  
B. Class with type parameters  
C. Class without methods  
D. Abstract class only  

**Answer: B. Class with type parameters**

**5. Which is the correct syntax for a generic method?**

A. `void <T> display(T value)`  
B. `<T> void display(T value)`  
C. `void display<T>(T value)`  
D. `T void display(T value)`  

**Answer: B. `<T> void display(T value)`**

**6. Which wildcard represents any unknown type?**

A. `? extends Number`  
B. `? super Number`  
C. `?`  
D. `T`  

**Answer: C. ?**

**7. Which is an upper-bounded wildcard?**

A. `? super Integer`  
B. `? extends Number`  
C. `<?>`  
D. `<T>`  

**Answer: B. ? extends Number**

**8. Which is a lower-bounded wildcard?**

A. `? extends Number`  
B. `? super Integer`  
C. `<?>`  
D. `<T extends Number>`  

**Answer: B. ? super Integer**

**9. What does PECS stand for?**

A. Producer Extends Consumer Super  
B. Public Extends Class Super  
C. Producer Equals Consumer String  
D. Private Extends Class Super  

**Answer: A. Producer Extends Consumer Super**

**10. Which collection declaration is valid?**

A. `List<int>`  
B. `List<Integer>`  
C. `List<void>`  
D. `List<primitive>`  

**Answer: B. List<Integer>**

**11. Which type can be used with `List<? extends Number>`?**

A. String  
B. Integer  
C. Boolean  
D. Character  

**Answer: B. Integer**

**12. Which type can be used with `List<? super Integer>`?**

A. Double  
B. String  
C. Number  
D. Boolean  

**Answer: C. Number**

**13. What is type erasure?**

A. Removing objects from memory  
B. Removing most generic type information during compilation  
C. Deleting source code  
D. Removing methods from classes  

**Answer: B. Removing most generic type information during compilation**

**14. Can a generic class have multiple type parameters?**

A. No  
B. Yes  
C. Only two  
D. Only three  

**Answer: B. Yes**

**15. Which of the following is a conventional type parameter name for an element?**

A. E  
B. X  
C. P  
D. Z  

**Answer: A. E**

---

# 13. Output-Based Questions

### Question 1: Generic Class

```java
class Box<T> {

    T value;

    Box(T value) {
        this.value = value;
    }

    void display() {
        System.out.println(value);
    }
}

public class Test {

    public static void main(String[] args) {

        Box<Integer> b1 = new Box<>(100);

        Box<String> b2 = new Box<>("Java");

        b1.display();

        b2.display();
    }
}
```

**Output:**

```text
100
Java
```

### Question 2: Generic Method

```java
public class Test {

    public static <T> void print(T value) {
        System.out.println(value);
    }

    public static void main(String[] args) {

        print(10);

        print("Hello");

        print(20.5);
    }
}
```

**Output:**

```text
10
Hello
20.5
```

### Question 3: Upper-Bounded Wildcard

```java
import java.util.Arrays;
import java.util.List;

public class Test {

    static void display(List<? extends Number> list) {

        for (Number n : list) {
            System.out.println(n);
        }
    }

    public static void main(String[] args) {

        List<Integer> list =
                Arrays.asList(10, 20, 30);

        display(list);
    }
}
```

**Output:**

```text
10
20
30
```

### Question 4: Lower-Bounded Wildcard

```java
import java.util.ArrayList;
import java.util.List;

public class Test {

    static void add(List<? super Integer> list) {

        list.add(100);

        list.add(200);
    }

    public static void main(String[] args) {

        List<Number> numbers = new ArrayList<>();

        add(numbers);

        System.out.println(numbers);
    }
}
```

**Output:**

```text
[100, 200]
```

---

# 14. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Generics | Type-safe reusable code |
| Introduced | Java 5 |
| T | Type parameter |
| E | Element |
| K | Key |
| V | Value |
| Generic Class | `class Box<T>` |
| Generic Method | `<T> void display(T value)` |
| Multiple Parameters | `<K, V>` |
| Bounded Type | `<T extends Number>` |
| Wildcard | `?` |
| Unbounded | `<?>` |
| Upper Bound | `<? extends Number>` |
| Lower Bound | `<? super Integer>` |
| PECS | Producer Extends, Consumer Super |
| Type Erasure | Generic type information largely removed at runtime |
| Wrapper Classes | Used instead of primitive types |

### Important Syntax

**Generic Class**

```java
class Box<T> {
    T value;
}
```

**Generic Class with Two Parameters**

```java
class Pair<K, V> {
    K key;
    V value;
}
```

**Generic Method**

```java
public static <T> void display(T value) {
    System.out.println(value);
}
```

**Upper-Bounded Type Parameter**

```java
<T extends Number>
```

**Unbounded Wildcard**

```java
List<?> list;
```

**Upper-Bounded Wildcard**

```java
List<? extends Number> list;
```

**Lower-Bounded Wildcard**

```java
List<? super Integer> list;
```

---

# 15. Practice Checklist

- [ ] Understand the concept of Generics.
- [ ] Understand why Generics are required.
- [ ] Compare code with and without Generics.
- [ ] Create a generic class.
- [ ] Create a generic class with multiple type parameters.
- [ ] Write generic methods.
- [ ] Write generic static methods.
- [ ] Understand bounded type parameters.
- [ ] Understand unbounded wildcards.
- [ ] Understand upper-bounded wildcards.
- [ ] Understand lower-bounded wildcards.
- [ ] Apply the PECS principle.
- [ ] Understand type erasure.
- [ ] Practice interview questions and MCQs.

---

# 16. Additional Practice Assignments

1. **Generic Calculator:** Create a generic class that stores two Number values and calculates their sum.
2. **Generic Pair:** Create a generic class that stores a key and value.
3. **Generic Array Utility:** Create generic methods to display elements of an array.
4. **Generic Student Container:** Store Student objects in a generic container.
5. **Upper-Bounded Method:** Create a method that calculates the sum of a List of Number subclasses.
6. **Lower-Bounded Method:** Create a method that inserts Integer values into lists of Integer, Number, or Object.
7. **Generic Utility Class:** Create a generic class containing set, get, and display methods.

---

## References

- [Oracle Java Generics Tutorial](https://docs.oracle.com/javase/tutorial/java/generics/)
- [Java 17 Generics Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/util/package-summary.html)
- [Java Language Specification – Types, Values and Variables](https://docs.oracle.com/javase/specs/jls/se17/html/jls-4.html)

**Note:** This README is prepared for the CMCE August 2026 Batch and covers Session 18 – Generics in Core Java.
