

# Session 09: Wrapper Classes and String Class in Java

**Course:** CDAC CMCE – August 2026 Batch  
**Technology:** Java 17  
**Topics:** Wrapper Classes, Constant Pools, String, StringBuffer, StringBuilder

---

## 1. Wrapper Classes in Java

### 1.1 What are Wrapper Classes?

Java provides eight primitive data types:

- `byte`
- `short`
- `int`
- `long`
- `float`
- `double`
- `char`
- `boolean`

Wrapper classes convert primitive values into objects.

A wrapper class is a class that represents a primitive data type as an object.

| Primitive Type | Wrapper Class |
|---|---|
| `byte` | `Byte` |
| `short` | `Short` |
| `int` | `Integer` |
| `long` | `Long` |
| `float` | `Float` |
| `double` | `Double` |
| `char` | `Character` |
| `boolean` | `Boolean` |

**Example:**

```java
public class WrapperDemo {
    public static void main(String[] args) {

        int a = 100;

        Integer obj = Integer.valueOf(a);

        System.out.println("Primitive value: " + a);
        System.out.println("Wrapper object: " + obj);
    }
}
```

**Output:**

```text
Primitive value: 100
Wrapper object: 100
```

### 1.2 Why do we need Wrapper Classes?

Wrapper classes are useful because:

1. Java Collections work with objects, not primitive values.
2. They provide utility methods for converting strings into numbers.
3. They allow primitive values to be represented as objects.
4. They provide constants such as `Integer.MAX_VALUE`.
5. They support operations such as comparison and conversion.

**Example:**

```java
import java.util.ArrayList;

public class WrapperCollectionDemo {
    public static void main(String[] args) {

        ArrayList<Integer> numbers = new ArrayList<>();

        numbers.add(10);
        numbers.add(20);
        numbers.add(30);

        System.out.println(numbers);
    }
}
```

**Output:**

```text
[10, 20, 30]
```

Notice that we use `Integer`, not `int`, as the generic type.

---

## 2. Boxing and Unboxing

### 2.1 Boxing

Boxing means converting a primitive value into its corresponding wrapper object.

**Example:**

```java
public class BoxingDemo {
    public static void main(String[] args) {

        int number = 50;

        Integer obj = Integer.valueOf(number);

        System.out.println(obj);
    }
}
```

**Output:**

```text
50
```

Here:

- `number` is a primitive integer.
- `Integer.valueOf(number)` creates or obtains an Integer object representing the value.
- The object is stored in `obj`.

### 2.2 Unboxing

Unboxing means converting a wrapper object into its corresponding primitive value.

**Example:**

```java
public class UnboxingDemo {
    public static void main(String[] args) {

        Integer obj = Integer.valueOf(100);

        int number = obj.intValue();

        System.out.println(number);
    }
}
```

**Output:**

```text
100
```

### 2.3 Difference Between Boxing and Unboxing

| Boxing | Unboxing |
|---|---|
| Primitive to wrapper object | Wrapper object to primitive |
| `int` → `Integer` | `Integer` → `int` |
| Uses `valueOf()` or constructor in older code | Uses methods such as `intValue()` |
| Converts value into an object | Extracts primitive value |

---

## 3. Autoboxing and Auto-Unboxing

Java automatically performs boxing and unboxing. This feature is available from Java 5.

### 3.1 Autoboxing

Autoboxing is the automatic conversion of a primitive value into a wrapper object.

```java
public class AutoboxingDemo {
    public static void main(String[] args) {

        int a = 10;

        Integer obj = a;

        System.out.println("Primitive: " + a);
        System.out.println("Wrapper: " + obj);
    }
}
```

**Output:**

```text
Primitive: 10
Wrapper: 10
```

Java automatically performs the equivalent of:

```java
Integer obj = Integer.valueOf(a);
```

### 3.2 Auto-Unboxing

Auto-unboxing is the automatic conversion of a wrapper object into a primitive value.

```java
public class AutoUnboxingDemo {
    public static void main(String[] args) {

        Integer obj = 200;

        int number = obj;

        System.out.println("Wrapper: " + obj);
        System.out.println("Primitive: " + number);
    }
}
```

**Output:**

```text
Wrapper: 200
Primitive: 200
```

Java automatically performs the equivalent of:

```java
int number = obj.intValue();
```

### 3.3 Boxing vs Autoboxing

| Boxing | Autoboxing |
|---|---|
| Explicit conversion | Automatic conversion |
| Programmer writes conversion code | Compiler inserts conversion |
| `Integer.valueOf(10)` | `Integer obj = 10;` |

### Important: Null During Auto-Unboxing

```java
public class NullUnboxingDemo {
    public static void main(String[] args) {

        Integer number = null;

        int value = number;

        System.out.println(value);
    }
}
```

**Output:**

```text
Exception in thread "main" java.lang.NullPointerException
```

**Reason:** Java cannot convert `null` into a primitive `int`.

---

## 4. Wrapper Class Utility Methods

Wrapper classes provide several useful static and instance methods.

### 4.1 parseInt()

Converts a numeric string into a primitive `int`.

```java
public class ParseIntDemo {
    public static void main(String[] args) {

        String str = "123";

        int number = Integer.parseInt(str);

        System.out.println(number);
        System.out.println(number + 10);
    }
}
```

**Output:**

```text
123
133
```

Remember:

```java
int a = Integer.parseInt("100");
```

The result is a primitive `int`.

### 4.2 parseDouble()

Converts a numeric string into a primitive `double`.

```java
public class ParseDoubleDemo {
    public static void main(String[] args) {

        String str = "99.50";

        double price = Double.parseDouble(str);

        System.out.println(price);
        System.out.println(price + 10);
    }
}
```

**Output:**

```text
99.5
109.5
```

### 4.3 valueOf()

Converts a primitive value or suitable string into a wrapper object.

```java
public class ValueOfDemo {
    public static void main(String[] args) {

        Integer a = Integer.valueOf(100);

        Integer b = Integer.valueOf("200");

        Double c = Double.valueOf("45.67");

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }
}
```

**Output:**

```text
100
200
45.67
```

### 4.4 toString()

Converts a value into its string representation.

```java
public class ToStringDemo {
    public static void main(String[] args) {

        int number = 500;

        String str = Integer.toString(number);

        System.out.println(str);
        System.out.println(str + 100);
    }
}
```

**Output:**

```text
500
500100
```

The second line performs string concatenation.

### 4.5 compareTo()

Compares two wrapper objects.

```java
public class CompareToDemo {
    public static void main(String[] args) {

        Integer a = 100;
        Integer b = 200;
        Integer c = 100;

        System.out.println(a.compareTo(b));
        System.out.println(b.compareTo(a));
        System.out.println(a.compareTo(c));
    }
}
```

**Output:**

```text
-1
1
0
```

For `Integer.compareTo()`:

- Negative result: first value is smaller.
- Positive result: first value is greater.
- Zero: both values are equal.

Do not depend on the exact negative or positive number for every comparable type. The important meaning is the sign.

### 4.6 Other Useful Wrapper Methods and Constants

```java
public class WrapperConstantsDemo {
    public static void main(String[] args) {

        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.MIN_VALUE);

        System.out.println(Double.MAX_VALUE);
        System.out.println(Double.MIN_VALUE);

        System.out.println(Integer.SIZE);
        System.out.println(Integer.BYTES);
    }
}
```

**Important:** `Double.MIN_VALUE` is the smallest positive non-zero magnitude, not the most negative double value.

---

## 5. Wrapper Class Constant Pool

### 5.1 What is a Constant Pool?

Wrapper classes such as `Integer` cache certain frequently used values.

For `Integer`, the standard guaranteed cache range is:

```text
-128 to 127
```

When `Integer.valueOf()` is used for values within this range, Java reuses cached objects.

This can reduce unnecessary object creation.

### 5.2 Integer Cache Example

```java
public class IntegerCacheDemo {
    public static void main(String[] args) {

        Integer a = 100;
        Integer b = 100;

        Integer x = 200;
        Integer y = 200;

        System.out.println(a == b);
        System.out.println(x == y);

        System.out.println(a.equals(b));
        System.out.println(x.equals(y));
    }
}
```

**Typical output:**

```text
true
false
true
true
```

**Explanation:**

- `a` and `b` represent 100, which is within the guaranteed Integer cache range.
- `x` and `y` represent 200, which is outside the guaranteed range.
- `==` compares object references.
- `equals()` compares the numerical values.

For predictable value comparison, use `equals()` or compare primitive values.

**Important:** Do not confuse the Integer cache with the String Constant Pool. They are different mechanisms.

---

# 6. String Class in Java

### 6.1 What is a String?

A String is a sequence of characters.

Java provides the `String` class in the `java.lang` package.

Example:

```java
String name = "Anurag";
```

A String is an object, even though it can be created using a simple literal.

### 6.2 Important Features of String

1. String is a class.
2. String objects are immutable.
3. String literals can be stored in the String Constant Pool.
4. String provides many methods for text manipulation.
5. String belongs to the `java.lang` package.
6. String is widely used for names, messages, input and data processing.

### 6.3 What is Immutability?

Immutability means an object's state cannot be changed after it is created.

Example:

```java
public class StringImmutableDemo {
    public static void main(String[] args) {

        String str = "Hello";

        str.concat(" Java");

        System.out.println(str);

        str = str.concat(" Java");

        System.out.println(str);
    }
}
```

**Output:**

```text
Hello
Hello Java
```

**Explanation:**

- `concat()` creates a new String.
- It does not modify the original String.
- Assigning the returned String to `str` makes the variable refer to the new String.

---

# 7. String Constant Pool

### 7.1 What is String Constant Pool?

The String Constant Pool is a special area managed by the JVM for sharing String literals.

When the same String literal is used multiple times, Java can reuse the same pooled String object.

This helps save memory.

### 7.2 Creating String Using Literals

```java
public class StringLiteralDemo {
    public static void main(String[] args) {

        String s1 = "Java";
        String s2 = "Java";

        System.out.println(s1 == s2);
        System.out.println(s1.equals(s2));
    }
}
```

**Output:**

```text
true
true
```

**Explanation:**

Both variables refer to the same pooled String object.

### 7.3 Creating String Using new String()

```java
public class StringNewDemo {
    public static void main(String[] args) {

        String s1 = "Java";

        String s2 = new String("Java");

        System.out.println(s1 == s2);
        System.out.println(s1.equals(s2));
    }
}
```

**Output:**

```text
false
true
```

**Explanation:**

- `s1` refers to the pooled literal.
- `s2` refers to a separately created String object.
- `==` compares references.
- `equals()` compares String contents.

### 7.4 String Pool Complete Example

```java
public class StringPoolDemo {
    public static void main(String[] args) {

        String s1 = "Hello";
        String s2 = "Hello";

        String s3 = new String("Hello");
        String s4 = new String("Hello");

        String s5 = s3.intern();

        System.out.println(s1 == s2);
        System.out.println(s1 == s3);
        System.out.println(s3 == s4);
        System.out.println(s1 == s5);

        System.out.println(s1.equals(s3));
    }
}
```

**Output:**

```text
true
false
false
true
true
```

### 7.5 What is intern()?

The `intern()` method returns the canonical pooled String for a given content.

```java
String s1 = "Java";

String s2 = new String("Java");

String s3 = s2.intern();

System.out.println(s1 == s3);
```

**Output:**

```text
true
```

### 7.6 Difference Between `==` and `equals()`

| `==` | `equals()` |
|---|---|
| Compares references for objects | Compares content for String |
| Checks whether references point to the same object | Checks whether String contents are equal |
| Operator | Method |
| May return false for equal-content Strings | Returns true for equal-content Strings |

**Interview point:** Always use `equals()` when you want to compare String contents.

---

# 8. String Class Methods

Let's explore the important String methods from the syllabus.

Consider:

```java
String str = "Hello Java Programming";
```

### 8.1 length()

Returns the number of UTF-16 code units in the String.

```java
String str = "Hello Java";

System.out.println(str.length());
```

**Output:**

```text
10
```

### 8.2 charAt()

Returns the character at a specified index.

Index starts from zero.

```java
String str = "Java";

System.out.println(str.charAt(0));
System.out.println(str.charAt(2));
```

**Output:**

```text
J
v
```

### 8.3 substring()

Extracts a portion of a String.

Syntax:

```java
substring(beginIndex)
substring(beginIndex, endIndex)
```

The ending index is excluded.

```java
String str = "Programming";

System.out.println(str.substring(3));
System.out.println(str.substring(0, 7));
```

**Output:**

```text
gramming
Program
```

### 8.4 indexOf()

Returns the index of the first occurrence of a character or substring.

```java
String str = "Java Programming";

System.out.println(str.indexOf('a'));
System.out.println(str.indexOf("Program"));
System.out.println(str.indexOf('z'));
```

**Output:**

```text
1
5
-1
```

If the element is not found, it returns `-1`.

### 8.5 contains()

Checks whether a String contains a particular sequence of characters.

```java
String str = "Java Programming";

System.out.println(str.contains("Java"));
System.out.println(str.contains("Python"));
```

**Output:**

```text
true
false
```

### 8.6 replace()

Replaces characters or matching character sequences.

```java
String str = "Java Programming";

System.out.println(str.replace('a', 'o'));
System.out.println(str.replace("Java", "Python"));
```

**Output:**

```text
Jovo Progromming
Python Programming
```

Remember: String's `replace()` returns a new String.

### 8.7 split()

Splits a String into an array using a regular expression.

```java
public class SplitDemo {
    public static void main(String[] args) {

        String data = "Java,Python,C++,SQL";

        String[] languages = data.split(",");

        for (String language : languages) {
            System.out.println(language);
        }
    }
}
```

**Output:**

```text
Java
Python
C++
SQL
```

### 8.8 toUpperCase()

Converts letters to uppercase.

```java
String str = "Java Programming";

System.out.println(str.toUpperCase());
```

**Output:**

```text
JAVA PROGRAMMING
```

### 8.9 toLowerCase()

Converts letters to lowercase.

```java
String str = "JAVA PROGRAMMING";

System.out.println(str.toLowerCase());
```

**Output:**

```text
java programming
```

### 8.10 trim()

Removes leading and trailing characters that have a character value less than or equal to U+0020.

```java
String str = "   Hello Java   ";

System.out.println(str.trim());
```

**Output:**

```text
Hello Java
```

Note: `trim()` does not remove spaces between words. Java also provides `strip()` for Unicode-aware whitespace removal.

### 8.11 Combined String Methods Program

```java
public class StringMethodsDemo {
    public static void main(String[] args) {

        String str = "  Hello Java Programming  ";

        System.out.println("Length: " + str.length());

        System.out.println("Character: " + str.charAt(2));

        System.out.println("Substring: " + str.substring(2, 7));

        System.out.println("Index: " + str.indexOf("Java"));

        System.out.println("Contains: " + str.contains("Java"));

        System.out.println("Replace: " + str.replace("Java", "Python"));

        System.out.println("Uppercase: " + str.toUpperCase());

        System.out.println("Lowercase: " + str.toLowerCase());

        System.out.println("Trim: " + str.trim());

        String[] words = str.trim().split(" ");

        for (String word : words) {
            System.out.println(word);
        }
    }
}
```

**Expected output:**

```text
Length: 26
Character: H
Substring: Hello
Index: 8
Contains: true
Replace:   Hello Python Programming
Uppercase:   HELLO JAVA PROGRAMMING
Lowercase:   hello java programming
Trim: Hello Java Programming
Hello
Java
Programming
```

---

# 9. StringBuffer Class

### 9.1 What is StringBuffer?

`StringBuffer` is a mutable sequence of characters.

Mutable means its content can be modified without creating a new object for every operation.

Unlike String, StringBuffer is synchronized and its methods are designed for thread-safe access.

### 9.2 Creating StringBuffer

```java
StringBuffer sb = new StringBuffer("Hello");
```

### 9.3 append()

Adds content at the end.

```java
public class AppendDemo {
    public static void main(String[] args) {

        StringBuffer sb = new StringBuffer("Hello");

        sb.append(" Java");

        System.out.println(sb);
    }
}
```

**Output:**

```text
Hello Java
```

### 9.4 insert()

Inserts content at a specified index.

```java
public class InsertDemo {
    public static void main(String[] args) {

        StringBuffer sb = new StringBuffer("Hello");

        sb.insert(5, " Java");

        System.out.println(sb);
    }
}
```

**Output:**

```text
Hello Java
```

### 9.5 delete()

Deletes characters between the given indexes.

The ending index is excluded.

```java
public class DeleteDemo {
    public static void main(String[] args) {

        StringBuffer sb = new StringBuffer("Hello Java");

        sb.delete(5, 10);

        System.out.println(sb);
    }
}
```

**Output:**

```text
Hello
```

### 9.6 replace()

Replaces a range of characters.

```java
public class ReplaceDemo {
    public static void main(String[] args) {

        StringBuffer sb = new StringBuffer("Hello Java");

        sb.replace(6, 10, "World");

        System.out.println(sb);
    }
}
```

**Output:**

```text
Hello World
```

### 9.7 reverse()

Reverses the character sequence.

```java
public class ReverseDemo {
    public static void main(String[] args) {

        StringBuffer sb = new StringBuffer("Java");

        sb.reverse();

        System.out.println(sb);
    }
}
```

**Output:**

```text
avaJ
```

### 9.8 Combined StringBuffer Program

```java
public class StringBufferDemo {
    public static void main(String[] args) {

        StringBuffer sb = new StringBuffer("Java");

        System.out.println("Original: " + sb);

        sb.append(" Programming");
        System.out.println("Append: " + sb);

        sb.insert(4, " Language");
        System.out.println("Insert: " + sb);

        sb.replace(5, 13, "Core");
        System.out.println("Replace: " + sb);

        sb.delete(4, 9);
        System.out.println("Delete: " + sb);

        sb.reverse();
        System.out.println("Reverse: " + sb);
    }
}
```

**Note:** The indexes in StringBuffer operations are based on the current content at that point in the program.

---

# 10. StringBuilder Class

### 10.1 What is StringBuilder?

`StringBuilder` is a mutable sequence of characters.

It is similar to StringBuffer, but its methods are not synchronized.

Therefore, StringBuilder is generally preferred for string modifications within a single thread.

### 10.2 StringBuilder Example

```java
public class StringBuilderDemo {
    public static void main(String[] args) {

        StringBuilder sb = new StringBuilder("Hello");

        sb.append(" Java");

        System.out.println(sb);

        sb.insert(5, " World");

        System.out.println(sb);

        sb.reverse();

        System.out.println(sb);
    }
}
```

**Output:**

```text
Hello Java
Hello World Java
avaJ dlroW olleH
```

---

# 11. Difference Between String, StringBuffer and StringBuilder

| Feature | String | StringBuffer | StringBuilder |
|---|---|---|---|
| Mutability | Immutable | Mutable | Mutable |
| Modification | Creates a new String | Modifies existing object | Modifies existing object |
| Thread safety | Immutable object is safe to share | Synchronized methods | Not synchronized |
| Performance for repeated modifications | Often less efficient | Generally slower than StringBuilder | Generally faster in single-threaded use |
| Introduced | Java 1.0 | Java 1.0 | Java 5 |
| Common methods | `concat()`, `replace()` | `append()`, `insert()` | `append()`, `insert()` |

### Example to Understand the Difference

```java
public class StringComparisonDemo {
    public static void main(String[] args) {

        String str = "Java";

        str.concat(" Programming");

        System.out.println("String: " + str);

        StringBuffer sb = new StringBuffer("Java");

        sb.append(" Programming");

        System.out.println("StringBuffer: " + sb);

        StringBuilder builder = new StringBuilder("Java");

        builder.append(" Programming");

        System.out.println("StringBuilder: " + builder);
    }
}
```

**Output:**

```text
String: Java
StringBuffer: Java Programming
StringBuilder: Java Programming
```

### When should we use each?

- **String:** When the text should not change frequently.
- **StringBuffer:** When mutable text needs synchronized operations.
- **StringBuilder:** When mutable text is modified frequently in a single-threaded context.

---

# 12. Complete Lab Practice Programs

## Lab 1: Demonstrate Boxing and Unboxing

```java
public class BoxingUnboxingLab {
    public static void main(String[] args) {

        int a = 10;

        // Boxing
        Integer obj = Integer.valueOf(a);

        // Unboxing
        int b = obj.intValue();

        System.out.println("Primitive: " + a);
        System.out.println("Wrapper: " + obj);
        System.out.println("Unboxed: " + b);
    }
}
```

## Lab 2: Demonstrate Autoboxing and Auto-Unboxing

```java
public class AutoBoxingLab {
    public static void main(String[] args) {

        int a = 50;

        // Autoboxing
        Integer obj = a;

        // Auto-unboxing
        int b = obj;

        System.out.println(obj);
        System.out.println(b);
    }
}
```

## Lab 3: Wrapper Utility Methods

```java
public class WrapperUtilityLab {
    public static void main(String[] args) {

        int a = Integer.parseInt("100");

        double b = Double.parseDouble("25.50");

        Integer c = Integer.valueOf("200");

        String d = Integer.toString(a);

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);

        System.out.println(c.compareTo(100));
    }
}
```

**Output:**

```text
100
25.5
200
100
1
```

## Lab 4: Compare String Literals and Objects

```java
public class StringComparisonLab {
    public static void main(String[] args) {

        String s1 = "Java";
        String s2 = "Java";

        String s3 = new String("Java");

        System.out.println(s1 == s2);
        System.out.println(s1 == s3);

        System.out.println(s1.equals(s2));
        System.out.println(s1.equals(s3));
    }
}
```

**Output:**

```text
true
false
true
true
```

## Lab 5: Demonstrate String Constant Pool

```java
public class StringPoolLab {
    public static void main(String[] args) {

        String a = "CDAC";
        String b = "CDAC";

        String c = new String("CDAC");

        String d = c.intern();

        System.out.println(a == b);
        System.out.println(a == c);
        System.out.println(a == d);

        System.out.println(a.equals(c));
    }
}
```

**Output:**

```text
true
false
true
true
```

## Lab 6: Perform String Operations

```java
public class StringOperationsLab {
    public static void main(String[] args) {

        String str = "Java Programming";

        System.out.println(str.length());

        System.out.println(str.charAt(0));

        System.out.println(str.substring(0, 4));

        System.out.println(str.indexOf("Programming"));

        System.out.println(str.contains("Java"));

        System.out.println(str.replace("Java", "Python"));

        System.out.println(str.toUpperCase());

        System.out.println(str.toLowerCase());

        String data = "Java,Python,C++";

        String[] arr = data.split(",");

        for (String s : arr) {
            System.out.println(s);
        }

        String name = "   Anurag   ";

        System.out.println(name.trim());
    }
}
```

## Lab 7: Demonstrate StringBuffer Operations

```java
public class StringBufferLab {
    public static void main(String[] args) {

        StringBuffer sb = new StringBuffer("Hello");

        sb.append(" Java");
        System.out.println("Append: " + sb);

        sb.insert(5, " World");
        System.out.println("Insert: " + sb);

        sb.replace(6, 11, "CDAC");
        System.out.println("Replace: " + sb);

        sb.delete(5, 10);
        System.out.println("Delete: " + sb);

        sb.reverse();
        System.out.println("Reverse: " + sb);
    }
}
```

## Lab 8: Compare String, StringBuffer and StringBuilder

```java
public class StringTypesLab {
    public static void main(String[] args) {

        String s = "Hello";
        s.concat(" Java");

        System.out.println("String: " + s);

        StringBuffer sb = new StringBuffer("Hello");
        sb.append(" Java");

        System.out.println("StringBuffer: " + sb);

        StringBuilder builder = new StringBuilder("Hello");
        builder.append(" Java");

        System.out.println("StringBuilder: " + builder);
    }
}
```

**Output:**

```text
String: Hello
StringBuffer: Hello Java
StringBuilder: Hello Java
```

---

# 13. Important Interview Questions and Answers

### Q1. What is a Wrapper Class?

A wrapper class converts a primitive data type into an object.

Example: `int` → `Integer`.

### Q2. Why do we need Wrapper Classes?

They allow primitive values to be used in collections and provide utility methods for conversion and comparison.

### Q3. What is Boxing?

Converting a primitive value into a wrapper object.

### Q4. What is Unboxing?

Converting a wrapper object into a primitive value.

### Q5. What is Autoboxing?

Automatic conversion of a primitive value into a wrapper object.

### Q6. What is Auto-Unboxing?

Automatic conversion of a wrapper object into a primitive value.

### Q7. What is the Integer Cache?

Integer wrapper objects for values from -128 to 127 are guaranteed to be cached by the standard Integer value-of mechanism.

### Q8. What is String Constant Pool?

It is a JVM-managed pool that allows String literals with the same content to share a canonical String object.

### Q9. Why is String immutable?

String immutability supports safe sharing, predictable behavior and efficient reuse of String literals.

### Q10. What is the difference between `==` and `equals()`?

`==` compares object references, while `equals()` compares String contents.

### Q11. What is `intern()`?

It returns the canonical pooled String for the same content.

### Q12. Is String mutable or immutable?

String is immutable.

### Q13. What is StringBuffer?

StringBuffer is a mutable and synchronized character sequence.

### Q14. What is StringBuilder?

StringBuilder is a mutable, non-synchronized character sequence.

### Q15. Which is faster: StringBuffer or StringBuilder?

StringBuilder is generally faster in single-threaded situations because it does not synchronize its methods.

### Q16. What is the difference between `parseInt()` and `valueOf()`?

- `Integer.parseInt("100")` returns primitive `int`.
- `Integer.valueOf("100")` returns an `Integer` object.

### Q17. What happens when you concatenate a String?

A new String is produced because String is immutable.

### Q18. Does `trim()` remove spaces between words?

No. It removes qualifying leading and trailing characters only.

### Q19. What does `indexOf()` return if an element is not found?

It returns `-1`.

### Q20. Are StringBuffer and StringBuilder immutable?

No. Both are mutable.

---

# 14. Important MCQs for CMCE

**1. Which wrapper class corresponds to `int`?**

A. Int  
B. Integer  
C. Number  
D. Long  

**Answer: B. Integer**

**2. Which method converts String into primitive int?**

A. `valueOf()`  
B. `toString()`  
C. `parseInt()`  
D. `compareTo()`  

**Answer: C. parseInt()**

**3. Which of the following is immutable?**

A. StringBuffer  
B. StringBuilder  
C. String  
D. All are mutable  

**Answer: C. String**

**4. Which operator compares object references?**

A. `equals()`  
B. `==`  
C. `compareTo()`  
D. `!=` only  

**Answer: B. ==**

**5. Which method returns a pooled String?**

A. `trim()`  
B. `intern()`  
C. `split()`  
D. `append()`  

**Answer: B. intern()**

**6. Which class is synchronized?**

A. String  
B. StringBuilder  
C. StringBuffer  
D. Integer  

**Answer: C. StringBuffer**

**7. What does `indexOf()` return when the value is not found?**

A. 0  
B. null  
C. -1  
D. false  

**Answer: C. -1**

**8. Which method converts an integer into String?**

A. `Integer.toString()`  
B. `Integer.parseInt()`  
C. `Integer.compareTo()`  
D. `Integer.intValue()`  

**Answer: A. Integer.toString()**

**9. Which conversion is called autoboxing?**

A. Integer to int  
B. int to Integer automatically  
C. String to int  
D. double to int  

**Answer: B. int to Integer automatically**

**10. Which class is generally preferred for repeated String modifications in single-threaded code?**

A. String  
B. StringBuffer  
C. StringBuilder  
D. Character  

**Answer: C. StringBuilder**

---

# 15. Output-Based Questions

### Question 1

```java
public class Test1 {
    public static void main(String[] args) {

        String a = "Java";
        String b = "Java";

        System.out.println(a == b);
    }
}
```

**Answer:**

```text
true
```

Reason: Both refer to the same pooled literal.

### Question 2

```java
public class Test2 {
    public static void main(String[] args) {

        String a = new String("Java");
        String b = new String("Java");

        System.out.println(a == b);
        System.out.println(a.equals(b));
    }
}
```

**Answer:**

```text
false
true
```

### Question 3

```java
public class Test3 {
    public static void main(String[] args) {

        Integer a = 100;
        Integer b = 100;

        System.out.println(a == b);
    }
}
```

**Answer:**

```text
true
```

Reason: Integer caching.

### Question 4

```java
public class Test4 {
    public static void main(String[] args) {

        String s = "Hello";

        s.concat(" World");

        System.out.println(s);
    }
}
```

**Answer:**

```text
Hello
```

Reason: String is immutable, and the returned String was not assigned.

### Question 5

```java
public class Test5 {
    public static void main(String[] args) {

        StringBuilder sb = new StringBuilder("Java");

        sb.append("17");

        System.out.println(sb);
    }
}
```

**Answer:**

```text
Java17
```

Reason: StringBuilder is mutable.

---

# 16. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Wrapper Class | Primitive represented as object |
| Boxing | Primitive → Wrapper |
| Unboxing | Wrapper → Primitive |
| Autoboxing | Automatic primitive → Wrapper |
| Auto-unboxing | Automatic Wrapper → Primitive |
| `parseInt()` | String → primitive int |
| `parseDouble()` | String → primitive double |
| `valueOf()` | Returns wrapper object for supported input |
| `toString()` | Converts value into String |
| `compareTo()` | Compares values lexicographically or numerically, depending on type |
| Integer Cache | Guaranteed range -128 to 127 |
| String | Immutable |
| String Pool | Reuses canonical String literals |
| `==` | Compares references for objects |
| `equals()` | Compares String contents |
| `intern()` | Returns canonical pooled String |
| StringBuffer | Mutable and synchronized |
| StringBuilder | Mutable and not synchronized |
| `append()` | Adds at the end |
| `insert()` | Adds at a specified index |
| `delete()` | Removes a range |
| `replace()` | Replaces a range or matching content |
| `reverse()` | Reverses character sequence |

---

# 17. Practice Checklist

Use this checklist to track your preparation.

- [ ] Understand all eight wrapper classes.
- [ ] Understand boxing and unboxing.
- [ ] Understand autoboxing and auto-unboxing.
- [ ] Practice `parseInt()` and `parseDouble()`.
- [ ] Practice `valueOf()` and `toString()`.
- [ ] Understand `compareTo()`.
- [ ] Understand the Integer Cache.
- [ ] Understand String immutability.
- [ ] Understand String Constant Pool.
- [ ] Practice String literals and `new String()`.
- [ ] Understand `==` versus `equals()`.
- [ ] Practice `intern()`.
- [ ] Practice all important String methods.
- [ ] Practice StringBuffer methods.
- [ ] Practice StringBuilder methods.
- [ ] Understand the differences between String, StringBuffer and StringBuilder.
- [ ] Solve output-based questions.
- [ ] Complete all lab programs independently.

---

# 18. Additional Practice Assignments

1. Take an integer as a String and convert it into an integer using `parseInt()`.
2. Take two wrapper objects and compare their values using `compareTo()`.
3. Create five String objects and identify which references point to the same pooled object.
4. Count the number of vowels in a String using `charAt()`.
5. Reverse a String using StringBuilder.
6. Check whether a String is a palindrome.
7. Count the number of words in a sentence using `split()`.
8. Replace all occurrences of a particular word in a sentence.
9. Remove leading and trailing spaces from user input.
10. Demonstrate Integer caching using values 100 and 200.
11. Compare StringBuffer and StringBuilder with repeated append operations.
12. Build a simple text editor using StringBuilder operations.

---

## 19. Suggested GitHub Folder Structure

```text
Java/
└── Session-09-Wrapper-Classes-and-String/
    ├── README.md
    └── programs/
        ├── WrapperDemo.java
        ├── BoxingDemo.java
        ├── UnboxingDemo.java
        ├── AutoboxingDemo.java
        ├── AutoUnboxingDemo.java
        ├── WrapperUtilityDemo.java
        ├── IntegerCacheDemo.java
        ├── StringLiteralDemo.java
        ├── StringNewDemo.java
        ├── StringPoolDemo.java
        ├── StringMethodsDemo.java
        ├── StringBufferDemo.java
        ├── StringBuilderDemo.java
        └── StringComparisonDemo.java
```

## 20. Important References

- [Oracle Java Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/)
- [Java String Class](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/String.html)
- [Integer Class](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/Integer.html)
- [StringBuffer Class](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/StringBuffer.html)
- [StringBuilder Class](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/StringBuilder.html)

---

**End of Session 09 – Wrapper Classes and String Class**

*Keep practising the programs, understand the output of each example, and revise the differences between String, StringBuffer and StringBuilder for CMCE practicals and interviews.*

