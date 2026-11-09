# Sessions 14 & 15: Exception Handling in Java

**Course:** CMCE – August 2026 Batch  
**Subject:** Core Java  
**Topics:** Exception Hierarchy, Checked & Unchecked Exceptions, Exception Propagation, try-catch-finally, throw, throws, Multi-catch, User-Defined Exceptions

---

## 1. Introduction to Exception Handling

An **exception** is an unwanted or unexpected event that occurs during program execution and interrupts the normal flow of instructions.

Exception handling is a mechanism in Java that allows us to detect and handle runtime problems so that the application can continue or terminate gracefully.

### Example: Without Exception Handling

```java
public class ExceptionDemo {
    public static void main(String[] args) {
        int a = 10;
        int b = 0;

        int result = a / b;

        System.out.println("Result: " + result);
        System.out.println("Program completed");
    }
}
```

**Output:**

```text
Exception in thread "main" java.lang.ArithmeticException: / by zero
```

The program terminates before executing the remaining statements.

### Example: With Exception Handling

```java
public class ExceptionDemo {
    public static void main(String[] args) {
        int a = 10;
        int b = 0;

        try {
            int result = a / b;
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Cannot divide by zero.");
        }

        System.out.println("Program completed");
    }
}
```

**Output:**

```text
Cannot divide by zero.
Program completed
```

### Why Exception Handling?

- Prevents abnormal program termination where an error can be handled.
- Separates error-handling code from normal application logic.
- Helps maintain the normal flow of an application.
- Provides meaningful error messages.
- Helps build reliable applications.

---

## 2. Exception Hierarchy in Java

In Java, all exceptions and errors are derived from the `Throwable` class.

### Exception Hierarchy Diagram

```text
                    Object
                       |
                   Throwable
                  /         \
              Error       Exception
                           /       \
                  Checked          RuntimeException
                  Exceptions       (Unchecked)
```

A more detailed representation:

```text
Throwable
|
|--- Error
|    |--- OutOfMemoryError
|    |--- StackOverflowError
|    |--- VirtualMachineError
|
|--- Exception
     |
     |--- IOException
     |--- SQLException
     |--- ClassNotFoundException
     |
     |--- RuntimeException
          |--- ArithmeticException
          |--- NullPointerException
          |--- ArrayIndexOutOfBoundsException
          |--- NumberFormatException
          |--- IllegalArgumentException
```

### 2.1 Throwable

`Throwable` is the root class of Java's exception-handling mechanism.

It has two major subclasses:

1. Error
2. Exception

### 2.2 Error

An Error represents a serious problem generally associated with the JVM or runtime environment.

Errors are generally not intended to be handled by normal application code.

Examples:

| Error | Meaning |
|---|---|
| OutOfMemoryError | JVM cannot allocate sufficient memory |
| StackOverflowError | Stack space is exhausted, often due to deep recursion |
| NoClassDefFoundError | A required class definition cannot be found at runtime |
| VirtualMachineError | Serious JVM-related problem |

Example:

```java
public class StackDemo {
    static void display() {
        display();
    }

    public static void main(String[] args) {
        display();
    }
}
```

This recursive method keeps calling itself without a stopping condition and eventually causes `StackOverflowError`.

**Important:** Errors are different from ordinary exceptions. Do not attempt to use exception handling as a general solution for serious JVM failures.

### 2.3 Exception

An Exception represents a condition that an application may want to detect and handle.

Examples:

- IOException
- SQLException
- FileNotFoundException
- ArithmeticException
- NullPointerException

Exceptions are divided into:

1. Checked Exceptions
2. Unchecked Exceptions

---

## 3. Checked and Unchecked Exceptions

### 3.1 Checked Exceptions

Checked exceptions are checked by the Java compiler at compile time.

If a method can throw a checked exception, the programmer must either:

- Handle it using `try-catch`, or
- Declare it using the `throws` clause.

Examples:

| Exception | Description |
|---|---|
| IOException | Input/output operation failure |
| FileNotFoundException | Requested file cannot be found |
| SQLException | Database operation failure |
| ClassNotFoundException | Required class cannot be found |

**Example:**

```java
import java.io.FileReader;
import java.io.IOException;

public class CheckedExceptionDemo {
    public static void main(String[] args) {
        try {
            FileReader reader = new FileReader("data.txt");
            reader.close();

            System.out.println("File opened successfully");
        } catch (IOException e) {
            System.out.println("File operation failed: " + e.getMessage());
        }
    }
}
```

If `data.txt` does not exist, the catch block handles the file-related exception.

### 3.2 Unchecked Exceptions

Unchecked exceptions are not checked by the compiler at compile time.

They generally occur due to programming mistakes or invalid operations.

They are subclasses of `RuntimeException`.

Examples:

| Exception | Description |
|---|---|
| ArithmeticException | Illegal arithmetic operation |
| NullPointerException | Accessing a member using a null reference |
| ArrayIndexOutOfBoundsException | Invalid array index |
| NumberFormatException | Invalid numeric conversion |
| IllegalArgumentException | Invalid method argument |
| ClassCastException | Invalid type casting |

**Example:**

```java
public class UncheckedExceptionDemo {
    public static void main(String[] args) {
        int number = 10;
        int divisor = 0;

        int result = number / divisor;

        System.out.println(result);
    }
}
```

This code compiles, but throws `ArithmeticException` at runtime.

### Checked vs Unchecked Exceptions

| Feature | Checked | Unchecked |
|---|---|---|
| Checking | Compile time | Runtime |
| Parent class | Exception (excluding RuntimeException) | RuntimeException |
| Mandatory handling/declaration | Yes | No |
| Common cause | External or recoverable conditions | Programming mistakes or invalid operations |
| Examples | IOException, SQLException | ArithmeticException, NullPointerException |

**Remember:**

- Checked exceptions must be caught or declared.
- Unchecked exceptions do not require mandatory catching or declaration.
- Both can be handled using `try-catch`.

---

## 4. Exception Propagation

**Exception propagation** means passing an exception from the method where it occurs to its calling method.

If a method does not handle an exception, the exception moves up the call stack until a matching handler is found.

If no handler is found, the thread terminates and the JVM reports the uncaught exception.

### Example

```java
public class ExceptionPropagationDemo {

    static void method3() {
        int result = 10 / 0;
    }

    static void method2() {
        method3();
    }

    static void method1() {
        method2();
    }

    public static void main(String[] args) {
        try {
            method1();
        } catch (ArithmeticException e) {
            System.out.println("Exception handled in main()");
        }

        System.out.println("Program continues");
    }
}
```

**Output:**

```text
Exception handled in main()
Program continues
```

### Explanation

Execution flow:

```text
main()
  |
  v
method1()
  |
  v
method2()
  |
  v
method3()
  |
  v
10 / 0
  |
  v
ArithmeticException
  |
  v
method3() does not handle it
  |
  v
method2() does not handle it
  |
  v
method1() does not handle it
  |
  v
main() catches it
```

### Important Points

- Exception propagation follows the call stack.
- The exception moves from the current method to its caller.
- A method can handle an exception or allow it to propagate.
- Checked exceptions must be caught or declared appropriately.

---

## 5. try-catch-finally Block

Java provides three important blocks for exception handling:

1. `try`
2. `catch`
3. `finally`

### 5.1 try Block

The `try` block contains code that may generate an exception.

```java
try {
    int result = 10 / 0;
}
```

A try block must be followed by at least one catch block or a finally block.

### 5.2 catch Block

The catch block handles an exception thrown from the associated try block.

```java
try {
    int result = 10 / 0;
} catch (ArithmeticException e) {
    System.out.println("Division by zero is not allowed");
}
```

### 5.3 finally Block

The finally block is used for cleanup operations.

It normally executes whether an exception occurs or not, including when a matching catch block handles the exception.

```java
public class FinallyDemo {
    public static void main(String[] args) {

        try {
            int result = 10 / 2;
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Exception occurred");
        } finally {
            System.out.println("Finally block executed");
        }
    }
}
```

**Output:**

```text
Result: 5
Finally block executed
```

### Example: Exception Occurs

```java
public class FinallyDemo {
    public static void main(String[] args) {

        try {
            int result = 10 / 0;
            System.out.println(result);
        } catch (ArithmeticException e) {
            System.out.println("Exception handled");
        } finally {
            System.out.println("Cleanup operation");
        }
    }
}
```

**Output:**

```text
Exception handled
Cleanup operation
```

### Important Points About finally

- Usually executes whether an exception occurs or not.
- Commonly used for cleanup.
- A finally block may not execute if the JVM terminates abruptly, for example through `System.exit()`.
- A return or exception from finally can override an earlier return or exception; avoid such control flow.

**Best practice:** Use try-with-resources for closing resources such as files, streams, and database connections that implement `AutoCloseable`.

---

## 6. throw Keyword

The `throw` keyword is used to explicitly throw an exception from a method or block.

### Syntax

```java
throw new ExceptionType("Error message");
```

### Example

```java
public class ThrowDemo {

    static void validateAge(int age) {
        if (age < 18) {
            throw new IllegalArgumentException("Age must be 18 or above");
        }

        System.out.println("Eligible for registration");
    }

    public static void main(String[] args) {
        try {
            validateAge(16);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

**Output:**

```text
Age must be 18 or above
```

### Explanation

- `throw` explicitly creates or throws an exception.
- It is followed by an exception object.
- It transfers control to an appropriate exception handler.
- It can throw checked or unchecked exceptions.

---

## 7. throws Clause

The `throws` clause is used in a method declaration to indicate that the method may pass one or more exceptions to its caller.

### Syntax

```java
returnType methodName() throws ExceptionType {
    // Method body
}
```

### Example

```java
import java.io.FileReader;
import java.io.IOException;

public class ThrowsDemo {

    static void readFile() throws IOException {
        FileReader reader = new FileReader("data.txt");
        reader.close();
    }

    public static void main(String[] args) {
        try {
            readFile();
        } catch (IOException e) {
            System.out.println("Unable to read file");
        }
    }
}
```

**Output if the file does not exist:**

```text
Unable to read file
```

### throw vs throws

| throw | throws |
|---|---|
| Used to explicitly throw an exception | Used to declare possible exceptions |
| Used inside method or block | Used in method declaration |
| Followed by an exception object | Followed by exception class names |
| Throws one exception object at a time | Can declare multiple exception types |
| Example: `throw new IOException();` | Example: `void read() throws IOException` |

**Remember:**

- `throw` = Actually throwing an exception.
- `throws` = Declaring that a method may pass an exception to its caller.

---

## 8. Multi-catch Block

A multi-catch block allows multiple exception types to be handled by a single catch block.

It was introduced in Java 7.

### Syntax

```java
try {
    // Risky code
} catch (ExceptionType1 | ExceptionType2 e) {
    // Common handling
}
```

### Example

```java
public class MultiCatchDemo {
    public static void main(String[] args) {

        try {
            int[] numbers = {10, 20, 30};

            int result = numbers[5] / 0;

            System.out.println(result);

        } catch (ArithmeticException | ArrayIndexOutOfBoundsException e) {
            System.out.println("Invalid arithmetic or array operation");
        }

        System.out.println("Program completed");
    }
}
```

**Output:**

```text
Invalid arithmetic or array operation
Program completed
```

In this example, the first exception encountered is `ArrayIndexOutOfBoundsException`, because Java evaluates the array access before performing division.

### Multiple catch Blocks vs Multi-catch

**Multiple catch blocks:**

```java
try {
    int number = Integer.parseInt("abc");
} catch (NumberFormatException e) {
    System.out.println("Invalid number format");
} catch (NullPointerException e) {
    System.out.println("Null value found");
}
```

**Multi-catch:**

```java
try {
    int number = Integer.parseInt("abc");
} catch (NumberFormatException | NullPointerException e) {
    System.out.println("Invalid input");
}
```

### Important Rules

- Use `|` to separate exception types.
- Exception types in one multi-catch must not be related by subclassing.
- The multi-catch parameter is implicitly final, so it cannot be reassigned.
- When using separate catch blocks, catch more specific exceptions before more general exceptions.

---

## 9. User-Defined Exceptions

Java allows programmers to create their own exception classes.

These are called **user-defined exceptions** or **custom exceptions**.

They are useful when application-specific conditions need to be represented clearly.

There are two major types:

1. Custom Checked Exception
2. Custom Unchecked Exception

### 9.1 Creating a Custom Checked Exception

To create a checked exception, extend the `Exception` class.

**Example: InsufficientBalanceException.java**

```java
public class InsufficientBalanceException extends Exception {

    public InsufficientBalanceException(String message) {
        super(message);
    }
}
```

This exception must be handled or declared by the calling code.

**Usage:**

```java
public class BankAccount {

    private double balance = 1000;

    public void withdraw(double amount)
            throws InsufficientBalanceException {

        if (amount > balance) {
            throw new InsufficientBalanceException(
                "Insufficient account balance"
            );
        }

        balance -= amount;
        System.out.println("Withdrawal successful");
    }
}
```

### 9.2 Creating a Custom Unchecked Exception

To create an unchecked exception, extend `RuntimeException`.

**Example: InvalidAmountException.java**

```java
public class InvalidAmountException extends RuntimeException {

    public InvalidAmountException(String message) {
        super(message);
    }
}
```

**Usage:**

```java
public class AmountValidator {

    static void validateAmount(double amount) {

        if (amount <= 0) {
            throw new InvalidAmountException(
                "Amount must be greater than zero"
            );
        }

        System.out.println("Valid amount");
    }

    public static void main(String[] args) {

        try {
            validateAmount(-500);
        } catch (InvalidAmountException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

**Output:**

```text
Amount must be greater than zero
```

### Checked vs Unchecked Custom Exceptions

| Feature | Custom Checked | Custom Unchecked |
|---|---|---|
| Parent class | Exception | RuntimeException |
| Compiler checking | Yes | No |
| Must catch or declare | Yes | No |
| Typical usage | Business condition that caller must handle | Invalid arguments or programming misuse |
| Example | InsufficientBalanceException | InvalidAmountException |

---

# 10. Lab: Banking Application Using Exception Handling

## Problem Statement

Develop a simple Banking Application that:

1. Validates account operations.
2. Uses a custom checked exception for insufficient balance.
3. Uses a custom unchecked exception for invalid input.
4. Demonstrates exception propagation.
5. Demonstrates `throw`, `throws`, `try-catch-finally`, and multi-catch blocks.

## 10.1 Application Design

We will create the following classes:

| Class | Responsibility |
|---|---|
| BankAccount | Stores account number and balance |
| InsufficientBalanceException | Custom checked exception |
| InvalidInputException | Custom unchecked exception |
| BankingApplication | Main application and exception handling |

### Program Flow

```text
             BankingApplication
                     |
                     v
                 BankAccount
                     |
          +----------+----------+
          |          |          |
          v          v          v
        Deposit   Withdraw    Check Balance
          |          |
          |          v
          |   Validate amount
          |          |
          |          v
          |   Check balance
          |          |
          |     +----+----+
          |     |         |
          |   Valid    Insufficient
          |     |         |
          v     v         v
        Update balance   throw
                         InsufficientBalanceException
```

## 10.2 Step 1: Create Custom Checked Exception

**File: InsufficientBalanceException.java**

```java
public class InsufficientBalanceException extends Exception {

    public InsufficientBalanceException(String message) {
        super(message);
    }
}
```

**Explanation:**

- Extends `Exception`.
- Therefore, it is a checked exception.
- It represents an insufficient balance condition.
- The message is passed to the parent constructor using `super()`.

## 10.3 Step 2: Create Custom Unchecked Exception

**File: InvalidInputException.java**

```java
public class InvalidInputException extends RuntimeException {

    public InvalidInputException(String message) {
        super(message);
    }
}
```

**Explanation:**

- Extends `RuntimeException`.
- Therefore, it is an unchecked exception.
- It represents invalid banking input, such as a negative or zero transaction amount.

## 10.4 Step 3: Create BankAccount Class

**File: BankAccount.java**

```java
public class BankAccount {

    private int accountNumber;
    private double balance;

    public BankAccount(int accountNumber, double balance) {

        if (accountNumber <= 0) {
            throw new InvalidInputException(
                "Invalid account number"
            );
        }

        if (balance < 0) {
            throw new InvalidInputException(
                "Initial balance cannot be negative"
            );
        }

        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public void deposit(double amount) {

        if (amount <= 0) {
            throw new InvalidInputException(
                "Deposit amount must be greater than zero"
            );
        }

        balance += amount;

        System.out.println("Deposit successful: " + amount);
    }

    public void withdraw(double amount)
            throws InsufficientBalanceException {

        validateAmount(amount);

        if (amount > balance) {
            throw new InsufficientBalanceException(
                "Insufficient balance! Available balance: " + balance
            );
        }

        balance -= amount;

        System.out.println("Withdrawal successful: " + amount);
    }

    private void validateAmount(double amount) {

        if (amount <= 0) {
            throw new InvalidInputException(
                "Transaction amount must be greater than zero"
            );
        }
    }

    public double getBalance() {
        return balance;
    }

    public int getAccountNumber() {
        return accountNumber;
    }

    public void displayBalance() {

        System.out.println("Account Number: " + accountNumber);
        System.out.println("Available Balance: " + balance);
    }
}
```

### Explanation of BankAccount Class

**1. Encapsulation**

```java
private int accountNumber;
private double balance;
```

The account details are private, so they cannot be directly modified from outside the class.

**2. Invalid Input Validation**

```java
if (amount <= 0) {
    throw new InvalidInputException("Invalid amount");
}
```

The `throw` keyword explicitly throws a custom unchecked exception.

**3. Insufficient Balance Validation**

```java
if (amount > balance) {
    throw new InsufficientBalanceException("Insufficient balance");
}
```

The method declares the checked exception using `throws`.

**4. Exception Propagation**

`validateAmount()` throws an unchecked exception. It is not handled inside `withdraw()`, so it propagates to the caller.

Similarly, `withdraw()` declares `InsufficientBalanceException`, allowing the calling method to handle it.

## 10.5 Step 4: Create Main Banking Application

**File: BankingApplication.java**

```java
public class BankingApplication {

    public static void main(String[] args) {

        BankAccount account = null;

        try {

            account = new BankAccount(101, 5000);

            System.out.println("Banking Application Started");

            account.displayBalance();

            System.out.println("\n--- Deposit Operation ---");
            account.deposit(2000);

            System.out.println("\n--- Withdrawal Operation ---");
            account.withdraw(1500);

            System.out.println("\n--- Invalid Input Test ---");
            account.deposit(-500);

            System.out.println("\n--- Insufficient Balance Test ---");
            account.withdraw(10000);

        } catch (InsufficientBalanceException e) {

            System.out.println("Banking Error: " + e.getMessage());

        } catch (InvalidInputException | IllegalArgumentException e) {

            System.out.println("Input Error: " + e.getMessage());

        } finally {

            System.out.println("\n--- Transaction Completed ---");

            if (account != null) {
                account.displayBalance();
            }

            System.out.println("Thank you for using our banking service.");
        }
    }
}
```

## 10.6 Expected Output

For the program exactly as written above:

```text
Banking Application Started
Account Number: 101
Available Balance: 5000.0

--- Deposit Operation ---
Deposit successful: 2000.0

--- Withdrawal Operation ---
Withdrawal successful: 1500.0

--- Invalid Input Test ---
Input Error: Deposit amount must be greater than zero

--- Transaction Completed ---
Account Number: 101
Available Balance: 5500.0
Thank you for using our banking service.
```

**Important:** The negative deposit throws an exception. Therefore, execution skips the later insufficient-balance test in the same try block. To test insufficient balance, run that operation separately or move it before the invalid deposit.

## 10.7 Test Insufficient Balance Separately

Temporarily replace the two test operations with:

```java
System.out.println("\n--- Insufficient Balance Test ---");
account.withdraw(10000);
```

**Expected Output:**

```text
Banking Error: Insufficient balance! Available balance: 5500.0

--- Transaction Completed ---
Account Number: 101
Available Balance: 5500.0
Thank you for using our banking service.
```

## 10.8 Demonstrating Exception Propagation

Consider the following method chain:

```java
public class PropagationDemo {

    static void withdraw()
            throws InsufficientBalanceException {

        throw new InsufficientBalanceException(
            "Insufficient funds"
        );
    }

    static void processTransaction()
            throws InsufficientBalanceException {

        withdraw();
    }

    static void startTransaction()
            throws InsufficientBalanceException {

        processTransaction();
    }

    public static void main(String[] args) {

        try {
            startTransaction();
        } catch (InsufficientBalanceException e) {
            System.out.println("Handled in main: " + e.getMessage());
        }
    }
}
```

**Output:**

```text
Handled in main: Insufficient funds
```

Here, the exception propagates through:

```text
main()
  |
  v
startTransaction()
  |
  v
processTransaction()
  |
  v
withdraw()
  |
  v
InsufficientBalanceException
```

The exception is finally handled in `main()`.

## 10.9 Mapping the Lab Requirements

| Requirement | Implemented In |
|---|---|
| Validate account operations | BankAccount |
| Custom checked exception | InsufficientBalanceException |
| Custom unchecked exception | InvalidInputException |
| Exception propagation | withdraw(), validateAmount(), main() |
| `throw` | Validation and withdrawal methods |
| `throws` | withdraw() |
| `try-catch-finally` | BankingApplication |
| Multi-catch | InvalidInputException \| IllegalArgumentException |

## 10.10 Compile and Run

Keep all four Java files in the same directory.

```text
BankingApplication/
|
|--- BankAccount.java
|--- BankingApplication.java
|--- InsufficientBalanceException.java
|--- InvalidInputException.java
```

Compile:

```bash
javac *.java
```

Run:

```bash
java BankingApplication
```

---

# 11. Important Interview Questions and Answers

### Q1. What is an exception?

An exception is an event that interrupts the normal execution flow of a program.

### Q2. What is exception handling?

Exception handling is a mechanism used to detect and handle runtime problems.

### Q3. What is the root class of the exception hierarchy?

`Throwable` is the root class.

### Q4. What are the two main subclasses of Throwable?

`Error` and `Exception`.

### Q5. What is an Error?

An Error represents a serious JVM or runtime problem, such as `OutOfMemoryError`.

### Q6. What is a checked exception?

A checked exception is checked by the compiler and must be caught or declared.

### Q7. What is an unchecked exception?

An unchecked exception is not checked by the compiler. It is generally a subclass of `RuntimeException`.

### Q8. Give examples of checked exceptions.

`IOException`, `SQLException`, and `ClassNotFoundException`.

### Q9. Give examples of unchecked exceptions.

`ArithmeticException`, `NullPointerException`, and `NumberFormatException`.

### Q10. What is exception propagation?

It is the process of passing an unhandled exception from the current method to its caller.

### Q11. What is the purpose of the try block?

It contains code that may generate an exception.

### Q12. What is the purpose of the catch block?

It handles an exception thrown from the associated try block.

### Q13. What is the purpose of finally?

It is generally used for cleanup operations and normally executes whether an exception occurs or not.

### Q14. Can we write try without catch?

Yes. A try block can be followed by a finally block without a catch block.

### Q15. What is the difference between throw and throws?

`throw` explicitly throws an exception object, whereas `throws` declares possible exceptions in a method signature.

### Q16. Can we throw a checked exception?

Yes. It must be caught or declared using `throws`.

### Q17. Can we create our own exception?

Yes. Extend `Exception` for a checked exception or `RuntimeException` for an unchecked exception.

### Q18. What is a multi-catch block?

It allows multiple unrelated exception types to be handled by one catch block.

### Q19. Can we write multiple catch blocks?

Yes. Multiple catch blocks can handle different exception types.

### Q20. What happens if an exception is not handled?

It propagates up the call stack. If no handler is found, the thread terminates with an uncaught exception.

### Q21. Can finally execute if an exception occurs?

Normally, yes. It may not execute if the JVM terminates abruptly.

### Q22. Can we use throw and throws together?

Yes. A method can throw an exception using `throw` and declare it using `throws`.

### Q23. What is the difference between Exception and RuntimeException?

`RuntimeException` is a subclass of `Exception` and represents unchecked exceptions.

### Q24. Why use custom exceptions?

They represent application-specific error conditions with meaningful names and messages.

### Q25. Can a method declare multiple exceptions using throws?

Yes.

```java
void process() throws IOException, SQLException {
    // Code
}
```

---

# 12. Multiple Choice Questions (MCQs)

**1. Which class is the root of Java's exception hierarchy?**

A. Object  
B. Throwable  
C. Exception  
D. Error  

**Answer: B. Throwable**

**2. Which of the following is a checked exception?**

A. ArithmeticException  
B. NullPointerException  
C. IOException  
D. NumberFormatException  

**Answer: C. IOException**

**3. Which of the following is an unchecked exception?**

A. IOException  
B. SQLException  
C. ClassNotFoundException  
D. ArithmeticException  

**Answer: D. ArithmeticException**

**4. Which keyword is used to explicitly throw an exception?**

A. throws  
B. throw  
C. try  
D. catch  

**Answer: B. throw**

**5. Which keyword declares exceptions in a method signature?**

A. throw  
B. catch  
C. throws  
D. finally  

**Answer: C. throws**

**6. Which block is generally used for cleanup operations?**

A. try  
B. catch  
C. finally  
D. throw  

**Answer: C. finally**

**7. Which class should be extended to create a custom checked exception?**

A. RuntimeException  
B. Exception  
C. Error  
D. Object  

**Answer: B. Exception**

**8. Which class should be extended to create a custom unchecked exception?**

A. Exception  
B. Throwable  
C. RuntimeException  
D. IOException  

**Answer: C. RuntimeException**

**9. Multi-catch was introduced in which Java version?**

A. Java 5  
B. Java 6  
C. Java 7  
D. Java 8  

**Answer: C. Java 7**

**10. What happens when an exception is not handled in a method?**

A. It is ignored  
B. It propagates to the caller  
C. The program always continues normally  
D. It is automatically converted into an Error  

**Answer: B. It propagates to the caller**

---

# 13. Output-Based Questions

### Question 1

```java
public class Test {
    public static void main(String[] args) {
        try {
            System.out.println(10 / 0);
        } catch (ArithmeticException e) {
            System.out.println("Exception");
        }

        System.out.println("End");
    }
}
```

**Output:**

```text
Exception
End
```

### Question 2

```java
public class Test {
    public static void main(String[] args) {
        try {
            System.out.println("Try");
        } finally {
            System.out.println("Finally");
        }
    }
}
```

**Output:**

```text
Try
Finally
```

### Question 3

```java
public class Test {
    public static void main(String[] args) {
        try {
            int number = Integer.parseInt("ABC");
        } catch (NumberFormatException e) {
            System.out.println("Invalid Number");
        } catch (Exception e) {
            System.out.println("General Exception");
        }
    }
}
```

**Output:**

```text
Invalid Number
```

### Question 4

```java
public class Test {
    public static void main(String[] args) {
        try {
            int[] arr = {10, 20};
            System.out.println(arr[5]);
        } catch (Exception e) {
            System.out.println("Exception handled");
        }
    }
}
```

**Output:**

```text
Exception handled
```

---

# 14. Quick Revision Notes

| Concept | Key Point |
|---|---|
| Throwable | Root of exception hierarchy |
| Error | Serious JVM/runtime problem |
| Exception | Application-level exceptional condition |
| Checked Exception | Must catch or declare |
| Unchecked Exception | RuntimeException and its subclasses |
| Exception Propagation | Passing exception to caller |
| try | Contains risky code |
| catch | Handles exception |
| finally | Cleanup block |
| throw | Explicitly throws exception |
| throws | Declares possible exceptions |
| Multi-catch | Handles multiple unrelated exception types |
| Custom Checked | Extends Exception |
| Custom Unchecked | Extends RuntimeException |

### Important Syntax

**try-catch-finally**

```java
try {
    // Risky code
} catch (Exception e) {
    // Handle exception
} finally {
    // Cleanup
}
```

**throw**

```java
throw new ArithmeticException("Invalid operation");
```

**throws**

```java
void display() throws IOException {
    // Code
}
```

**Multi-catch**

```java
catch (IOException | SQLException e) {
    System.out.println(e.getMessage());
}
```

**Custom Checked Exception**

```java
class MyException extends Exception {
    MyException(String message) {
        super(message);
    }
}
```

**Custom Unchecked Exception**

```java
class MyException extends RuntimeException {
    MyException(String message) {
        super(message);
    }
}
```

---

# 15. Practice Checklist

- [ ] Understand the Throwable hierarchy.
- [ ] Differentiate Error and Exception.
- [ ] Understand checked and unchecked exceptions.
- [ ] Practice exception propagation.
- [ ] Write try-catch blocks.
- [ ] Practice finally block.
- [ ] Understand throw and throws.
- [ ] Implement multi-catch.
- [ ] Create custom checked exceptions.
- [ ] Create custom unchecked exceptions.
- [ ] Complete the Banking Application.
- [ ] Practice interview questions and MCQs.

---

# 16. Additional Practice Assignments

1. **ATM Application:** Validate PIN and account balance using custom exceptions.
2. **Student Admission System:** Throw an exception if marks are outside the valid range.
3. **Online Shopping:** Create `InsufficientStockException` for product purchases.
4. **Library Management:** Create `BookNotAvailableException` when a requested book is unavailable.
5. **Employee Management:** Create `InvalidSalaryException` for negative or invalid salary.
6. **File Handling:** Read a file and handle `IOException` using try-catch-finally or try-with-resources.

---

## References

- [Oracle Java Tutorials – Exceptions](https://docs.oracle.com/javase/tutorial/essential/exceptions/)
- [Java 17 Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/)
- [Java Language Specification – Exceptions](https://docs.oracle.com/javase/specs/jls/se17/html/jls-11.html)

**Note:** This README is prepared for CMCE August 2026 Batch and covers Sessions 14 & 15 of the Core Java syllabus.
