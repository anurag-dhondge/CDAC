

# Session 10: Enumeration and Java Class Features

**Course:** CDAC CMCE – August 2026 Batch  
**Technology:** Java 17  
**Topics:** Enumeration, Sealed Classes, Final Keyword, Pattern Matching, Inner Classes

---

# 1. Enumeration (enum) in Java

## 1.1 What is an Enumeration?

An enumeration (`enum`) is a special Java type used to define a fixed collection of named constants.

It is useful when a variable should have only a predefined set of possible values.

**Real-world examples:**
- Days of the week
- Months
- Employee departments
- Order status
- Traffic light signals
- Payment status

For example, an employee can belong to departments such as HR, IT, FINANCE or SALES.

Instead of storing department names as ordinary Strings, we can use an enum.

### Syntax

```java
enum EnumName {
    CONSTANT1,
    CONSTANT2,
    CONSTANT3
}
```

### Example 1: Basic Enum

```java
enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
}

public class EnumDemo {
    public static void main(String[] args) {

        Day today = Day.MONDAY;

        System.out.println(today);
    }
}
```

**Output:**

```text
MONDAY
```

### 1.2 Accessing Enum Constants

Enum constants can be accessed using the enum name.

```java
enum Direction {
    NORTH, SOUTH, EAST, WEST
}

public class DirectionDemo {
    public static void main(String[] args) {

        Direction d = Direction.NORTH;

        System.out.println(d);
        System.out.println(Direction.SOUTH);
    }
}
```

**Output:**

```text
NORTH
SOUTH
```

### 1.3 Using Enum with switch

Enums work directly with switch statements.

```java
enum Day {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY
}

public class EnumSwitchDemo {
    public static void main(String[] args) {

        Day day = Day.MONDAY;

        switch (day) {

            case MONDAY:
                System.out.println("Start of the week");
                break;

            case FRIDAY:
                System.out.println("Almost weekend");
                break;

            default:
                System.out.println("Regular working day");
        }
    }
}
```

**Output:**

```text
Start of the week
```

### 1.4 Important Enum Methods

Java provides built-in methods for enum types.

| Method | Description |
|---|---|
| `values()` | Returns an array containing all enum constants |
| `valueOf()` | Returns the enum constant with the specified name |
| `ordinal()` | Returns the zero-based position of a constant |
| `name()` | Returns the exact declared name of a constant |
| `toString()` | Returns the String representation of a constant |

**Example:**

```java
enum Department {
    HR, IT, FINANCE, SALES
}

public class EnumMethodsDemo {
    public static void main(String[] args) {

        // values()
        for (Department d : Department.values()) {
            System.out.println(d);
        }

        // valueOf()
        Department dept = Department.valueOf("IT");

        System.out.println("Selected: " + dept);

        // ordinal()
        System.out.println("Position: " + dept.ordinal());

        // name()
        System.out.println("Name: " + dept.name());
    }
}
```

**Output:**

```text
HR
IT
FINANCE
SALES
Selected: IT
Position: 1
Name: IT
```

**Important:** `ordinal()` starts from zero. Avoid using ordinal positions as permanent database identifiers because changing the declaration order changes their values.

### 1.5 Enum with Fields, Constructor and Methods

An enum can contain:
- Instance variables
- Constructors
- Methods
- Constant-specific values

Example:

```java
enum Department {

    HR("Human Resources"),
    IT("Information Technology"),
    FINANCE("Finance Department"),
    SALES("Sales Department");

    private final String description;

    Department(String description) {
        this.description = description;
    }

    public String getDescription() {
        return description;
    }
}

public class EnumConstructorDemo {
    public static void main(String[] args) {

        Department dept = Department.IT;

        System.out.println(dept);
        System.out.println(dept.getDescription());
    }
}
```

**Output:**

```text
IT
Information Technology
```

**Important points:**
1. Enum constructors cannot be public or protected.
2. Enum constructors are called when enum constants are initialized.
3. Enum types cannot be instantiated using `new`.
4. An enum can implement interfaces.
5. An enum cannot extend another class because it already extends `java.lang.Enum`.

---

# 2. Sealed Classes in Java

## 2.1 What is a Sealed Class?

A sealed class restricts which classes are allowed to extend it.

Normally, a class can be extended by any accessible class unless it is final or otherwise restricted.

A sealed class allows us to explicitly control the permitted subclasses.

Sealed classes were finalized in Java 17.

**Real-world example:**

Consider an Employee Management System.

An employee can be:
- Full-time employee
- Contract employee
- Intern

Suppose the system should allow only these three employee types. A sealed class is useful for enforcing this restriction.

### 2.2 Syntax

```java
sealed class Parent permits Child1, Child2 {
    // Members
}

final class Child1 extends Parent {
    // Members
}

final class Child2 extends Parent {
    // Members
}
```

The `permits` keyword specifies which classes are allowed to extend the sealed class.

### 2.3 Basic Sealed Class Example

```java
sealed class Vehicle permits Car, Bike {
}

final class Car extends Vehicle {
}

final class Bike extends Vehicle {
}

public class SealedDemo {
    public static void main(String[] args) {

        Vehicle v1 = new Car();
        Vehicle v2 = new Bike();

        System.out.println(v1.getClass().getSimpleName());
        System.out.println(v2.getClass().getSimpleName());
    }
}
```

**Output:**

```text
Car
Bike
```

### 2.4 Rules of Sealed Classes

Every direct permitted subclass must declare one of these three modifiers:

| Modifier | Meaning |
|---|---|
| `final` | Cannot be extended further |
| `sealed` | Restricts its own subclasses |
| `non-sealed` | Removes the inheritance restriction for its subclasses |

### 2.5 Using final, sealed and non-sealed Together

```java
sealed class Employee permits PermanentEmployee,
                              TemporaryEmployee,
                              ContractEmployee {
}

final class PermanentEmployee extends Employee {
}

sealed class TemporaryEmployee extends Employee
        permits Intern {
}

final class Intern extends TemporaryEmployee {
}

non-sealed class ContractEmployee extends Employee {
}

class FreelanceEmployee extends ContractEmployee {
}
```

**Explanation:**

- `PermanentEmployee` is final, so nobody can extend it.
- `TemporaryEmployee` is sealed, so only `Intern` can extend it.
- `Intern` is final.
- `ContractEmployee` is non-sealed, so any accessible class can extend it.
- `FreelanceEmployee` extends `ContractEmployee`.

### 2.6 Sealed Class vs Final Class

| Sealed Class | Final Class |
|---|---|
| Restricts permitted subclasses | Does not allow subclasses |
| Uses `sealed` keyword | Uses `final` keyword |
| Can have permitted child classes | Cannot be extended |
| Provides controlled inheritance | Stops inheritance completely |

### 2.7 Sealed Interfaces

Interfaces can also be sealed.

```java
sealed interface Payment permits CashPayment,
                                  CardPayment {
}

final class CashPayment implements Payment {
}

final class CardPayment implements Payment {
}
```

A sealed interface restricts which classes or interfaces may directly extend or implement it.

---

# 3. Final Keyword in Java

The `final` keyword is used to restrict modification or inheritance.

It can be applied to:
1. Variables
2. Methods
3. Classes

## 3.1 Final Variables

A final variable can be assigned only once.

Once initialized, its value cannot be reassigned.

### Example

```java
public class FinalVariableDemo {
    public static void main(String[] args) {

        final int MAX_MARKS = 100;

        System.out.println(MAX_MARKS);

        // MAX_MARKS = 200; // Compilation error
    }
}
```

**Output:**

```text
100
```

### 3.1.1 Final Instance Variable

```java
class Student {

    final int rollNo;

    Student(int rollNo) {
        this.rollNo = rollNo;
    }

    void display() {
        System.out.println("Roll No: " + rollNo);
    }
}

public class FinalInstanceDemo {
    public static void main(String[] args) {

        Student s1 = new Student(101);

        s1.display();
    }
}
```

**Output:**

```text
Roll No: 101
```

A final instance variable must be initialized exactly once, either at declaration, in an instance initializer or in every constructor path.

### 3.1.2 Static Final Variable

A `static final` variable represents a class-level constant.

```java
class College {

    static final String COLLEGE_NAME = "PES Modern College";

}

public class StaticFinalDemo {
    public static void main(String[] args) {

        System.out.println(College.COLLEGE_NAME);
    }
}
```

**Output:**

```text
PES Modern College
```

### 3.1.3 Final Reference Variable

A final reference variable cannot refer to another object after assignment.

However, the object itself may still be mutable.

```java
class FinalReferenceDemo {
    public static void main(String[] args) {

        final StringBuilder sb = new StringBuilder("Java");

        sb.append(" Programming");

        System.out.println(sb);

        // sb = new StringBuilder("Python");
        // Compilation error
    }
}
```

**Output:**

```text
Java Programming
```

**Important interview point:** `final` reference means the reference cannot be reassigned. It does not automatically make the referenced object immutable.

---

## 3.2 Final Methods

A final method cannot be overridden by a subclass.

### Example

```java
class Parent {

    final void display() {
        System.out.println("Parent display method");
    }
}

class Child extends Parent {

    // Cannot override final method
    /*
    void display() {
        System.out.println("Child display method");
    }
    */
}

public class FinalMethodDemo {
    public static void main(String[] args) {

        Child obj = new Child();

        obj.display();
    }
}
```

**Output:**

```text
Parent display method
```

**Important points:**
- A final method can be inherited.
- A subclass can call the final method.
- A final method cannot be overridden.
- A private method cannot be overridden in the normal sense because it is not inherited.

---

## 3.3 Final Classes

A final class cannot be extended by another class.

### Example

```java
final class Security {

    void display() {
        System.out.println("Security class");
    }
}

// Compilation error:
// class AdvancedSecurity extends Security {}

public class FinalClassDemo {
    public static void main(String[] args) {

        Security obj = new Security();

        obj.display();
    }
}
```

**Output:**

```text
Security class
```

Examples of commonly known final classes in Java include:
- `String`
- `Integer`
- `Double`
- `Boolean`

### 3.4 Difference Between Final Variable, Method and Class

| Final Applied To | Meaning |
|---|---|
| Variable | Cannot be reassigned after initialization |
| Method | Cannot be overridden |
| Class | Cannot be extended |

---

# 4. Pattern Matching in Java

## 4.1 What is Pattern Matching?

Pattern matching simplifies checking an object's type and converting it into a reference of that type.

Before pattern matching, we generally used:
1. `instanceof` to check the type.
2. Explicit casting to convert the reference.
3. A separate variable to store the converted reference.

Java 16 finalized pattern matching for `instanceof`.

### 4.2 Traditional instanceof Approach

```java
class Animal {
}

class Dog extends Animal {

    void bark() {
        System.out.println("Dog is barking");
    }
}

public class TraditionalInstanceofDemo {
    public static void main(String[] args) {

        Animal animal = new Dog();

        if (animal instanceof Dog) {

            Dog d = (Dog) animal;

            d.bark();
        }
    }
}
```

**Output:**

```text
Dog is barking
```

Here:
- `instanceof` checks the object type.
- `(Dog)` performs explicit downcasting.
- `d` stores the converted reference.

### 4.3 Pattern Matching with instanceof

Java allows us to combine type checking and casting.

```java
class Animal {
}

class Dog extends Animal {

    void bark() {
        System.out.println("Dog is barking");
    }
}

public class PatternMatchingDemo {
    public static void main(String[] args) {

        Animal animal = new Dog();

        if (animal instanceof Dog d) {

            d.bark();
        }
    }
}
```

**Output:**

```text
Dog is barking
```

**Explanation:**

```java
animal instanceof Dog d
```

This means:

1. Check whether `animal` refers to a Dog object.
2. If true, create pattern variable `d`.
3. Use `d` as a Dog reference inside the applicable scope.

### 4.4 Pattern Matching with Multiple Types

```java
class Employee {
}

class Manager extends Employee {

    void manageTeam() {
        System.out.println("Managing team");
    }
}

class Developer extends Employee {

    void writeCode() {
        System.out.println("Writing code");
    }
}

public class EmployeePatternDemo {
    public static void main(String[] args) {

        Employee e1 = new Manager();
        Employee e2 = new Developer();

        if (e1 instanceof Manager m) {
            m.manageTeam();
        }

        if (e2 instanceof Developer d) {
            d.writeCode();
        }
    }
}
```

**Output:**

```text
Managing team
Writing code
```

### 4.5 Pattern Matching with Logical Conditions

```java
public class PatternConditionDemo {
    public static void main(String[] args) {

        Object obj = "Java Programming";

        if (obj instanceof String s && s.length() > 5) {

            System.out.println(s.toUpperCase());
        }
    }
}
```

**Output:**

```text
JAVA PROGRAMMING
```

The variable `s` is available in the right-hand side of `&&` because that expression is evaluated only when the pattern matches.

**Important Java 17 note:** Pattern matching for `instanceof` is final in Java 17. Pattern matching for `switch` was still a preview feature in Java 17, so this session uses ordinary `instanceof` pattern matching.

---

# 5. Inner Classes in Java

## 5.1 What is an Inner Class?

A class declared inside another class is called a nested class.

A non-static nested class is specifically called an inner class.

Inner and nested classes help organize related code and improve encapsulation.

Java supports these common types:

1. Regular Inner Class (Member Inner Class)
2. Method Local Inner Class
3. Anonymous Inner Class
4. Static Nested Class

---

## 5.2 Regular Inner Class (Member Inner Class)

A regular inner class is declared inside another class but outside its methods.

It can access all members of the outer class, including private members.

### Example

```java
class Outer {

    private String message = "Hello from Outer Class";

    class Inner {

        void display() {
            System.out.println(message);
        }
    }
}

public class RegularInnerDemo {
    public static void main(String[] args) {

        Outer outer = new Outer();

        Outer.Inner inner = outer.new Inner();

        inner.display();
    }
}
```

**Output:**

```text
Hello from Outer Class
```

### How to Create an Inner Class Object?

```java
Outer outer = new Outer();

Outer.Inner inner = outer.new Inner();
```

**Explanation:**
- First, create the outer class object.
- Then create the inner class object using the outer object.
- A regular inner class instance is associated with an enclosing outer class instance.

---

## 5.3 Method Local Inner Class

A class declared inside a method is called a method local inner class.

It can be accessed only within the method or block where it is declared.

### Example

```java
class Outer {

    void display() {

        String message = "Local Inner Class";

        class LocalInner {

            void show() {
                System.out.println(message);
            }
        }

        LocalInner obj = new LocalInner();

        obj.show();
    }
}

public class LocalInnerDemo {
    public static void main(String[] args) {

        Outer outer = new Outer();

        outer.display();
    }
}
```

**Output:**

```text
Local Inner Class
```

**Important points:**
- It is declared inside a method.
- It cannot be instantiated outside that method.
- It can access the outer class members.
- Local variables used by it must be final or effectively final.

---

## 5.4 Anonymous Inner Class

An anonymous inner class is a class without a name.

It is generally used when we need a one-time implementation of an interface or extension of a class.

### Example Using Interface

```java
interface Greeting {

    void sayHello();
}

public class AnonymousInnerDemo {
    public static void main(String[] args) {

        Greeting g = new Greeting() {

            @Override
            public void sayHello() {
                System.out.println("Hello from Anonymous Inner Class");
            }
        };

        g.sayHello();
    }
}
```

**Output:**

```text
Hello from Anonymous Inner Class
```

**Explanation:**

```java
new Greeting() {
    // Implementation
};
```

Here, we create an object of an anonymous class that implements `Greeting`.

### Anonymous Inner Class Using Abstract Class

```java
abstract class Animal {

    abstract void sound();
}

public class AnonymousAnimalDemo {
    public static void main(String[] args) {

        Animal a = new Animal() {

            @Override
            void sound() {
                System.out.println("Animal makes sound");
            }
        };

        a.sound();
    }
}
```

**Output:**

```text
Animal makes sound
```

---

## 5.5 Static Nested Class

A static nested class is declared using the `static` keyword inside another class.

Unlike a regular inner class, it does not require an outer class object to be created.

### Example

```java
class Outer {

    static String college = "PES Modern College";

    static class Inner {

        void display() {
            System.out.println(college);
        }
    }
}

public class StaticNestedDemo {
    public static void main(String[] args) {

        Outer.Inner obj = new Outer.Inner();

        obj.display();
    }
}
```

**Output:**

```text
PES Modern College
```

**Important points:**
- It can access static members of the outer class directly.
- It cannot directly access non-static outer members.
- It does not require an outer object for its creation.
- It can have both static and non-static members.

---

# 6. Difference Between Types of Inner Classes

| Feature | Regular Inner | Method Local | Anonymous | Static Nested |
|---|---|---|---|---|
| Declaration | Inside outer class | Inside method | At object creation | Inside outer class with `static` |
| Name | Has a name | Has a name | No name | Has a name |
| Outer object required | Yes | Depends on enclosing context | Depends on enclosing context | No |
| Access outer instance members | Yes | Yes | Yes, when created in instance context | Not directly |
| Main use | Group related functionality | Method-specific functionality | One-time implementation | Grouped static functionality |

---

# 7. Employee Management System – Complete Lab

## 7.1 Problem Statement

Develop an Employee Management System that:

1. Uses an enum for employee departments.
2. Uses a sealed class hierarchy for employee types.
3. Uses pattern matching to process different employee objects.
4. Uses inner classes to manage employee details and reports.

## 7.2 Concepts Used

| Requirement | Java Feature |
|---|---|
| Employee departments | Enum |
| Employee types | Sealed class |
| Full-time and contract employees | Permitted subclasses |
| Processing employee objects | Pattern matching |
| Employee details | Regular inner class |
| Local report processing | Method local inner class |
| Report formatting | Anonymous inner class |
| Report generation | Static nested class |
| Employee ID | Final variable |
| Common employee display behavior | Final method |

## 7.3 Program Structure

```text
EmployeeManagementSystem
│
├── Department (enum)
│
├── Employee (sealed class)
│   │
│   ├── FullTimeEmployee (final class)
│   │
│   └── ContractEmployee (final class)
│
├── EmployeeDetails (Regular Inner Class)
│
├── ReportGenerator (Static Nested Class)
│
└── Main Method
    ├── Create Employees
    ├── Display Details
    └── Generate Reports
```

## 7.4 Complete Java Program

Save the following code as:

`EmployeeManagementSystem.java`

```java
import java.util.ArrayList;
import java.util.List;

// 1. Enum for Employee Departments
enum Department {

    HR,
    IT,
    FINANCE,
    SALES
}

// 2. Sealed Employee Class
sealed abstract class Employee
        permits FullTimeEmployee, ContractEmployee {

    private final int employeeId;

    private final String name;

    private final Department department;

    Employee(int employeeId, String name, Department department) {

        this.employeeId = employeeId;
        this.name = name;
        this.department = department;
    }

    public int getEmployeeId() {
        return employeeId;
    }

    public String getName() {
        return name;
    }

    public Department getDepartment() {
        return department;
    }

    // Final method
    public final void displayBasicDetails() {

        System.out.println("Employee ID: " + employeeId);
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);
    }

    public abstract double calculateSalary();
}

// 3. Permitted Subclass: Full-Time Employee
final class FullTimeEmployee extends Employee {

    private final double monthlySalary;

    FullTimeEmployee(int id, String name,
                     Department department, double salary) {

        super(id, name, department);

        this.monthlySalary = salary;
    }

    public double calculateSalary() {
        return monthlySalary;
    }

    public double getMonthlySalary() {
        return monthlySalary;
    }
}

// 4. Permitted Subclass: Contract Employee
final class ContractEmployee extends Employee {

    private final double hourlyRate;

    private final int hoursWorked;

    ContractEmployee(int id, String name,
                     Department department,
                     double hourlyRate, int hoursWorked) {

        super(id, name, department);

        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    public double calculateSalary() {

        return hourlyRate * hoursWorked;
    }

    public double getHourlyRate() {
        return hourlyRate;
    }

    public int getHoursWorked() {
        return hoursWorked;
    }
}

// 5. Employee Management System
public class EmployeeManagementSystem {

    private final List<Employee> employees = new ArrayList<>();

    // Regular Inner Class
    class EmployeeDetails {

        void display(Employee employee) {

            System.out.println("\n----- Employee Details -----");

            employee.displayBasicDetails();

            System.out.println(
                "Salary: " + employee.calculateSalary()
            );
        }
    }

    // Static Nested Class
    static class ReportGenerator {

        static void generateReport(List<Employee> employees) {

            System.out.println("\n===== EMPLOYEE REPORT =====");

            for (Employee employee : employees) {

                System.out.println(
                    employee.getEmployeeId() + " | "
                    + employee.getName() + " | "
                    + employee.getDepartment() + " | "
                    + employee.calculateSalary()
                );
            }
        }
    }

    // Method Local Inner Class
    void generateDepartmentReport(Department department) {

        class DepartmentReport {

            void generate() {

                System.out.println(
                    "\nEmployees in Department: " + department
                );

                for (Employee employee : employees) {

                    if (employee.getDepartment() == department) {

                        System.out.println(employee.getName());
                    }
                }
            }
        }

        DepartmentReport report = new DepartmentReport();

        report.generate();
    }

    // Adding employees
    void addEmployee(Employee employee) {

        employees.add(employee);
    }

    // Pattern Matching
    void processEmployee(Employee employee) {

        System.out.println("\nProcessing: " + employee.getName());

        if (employee instanceof FullTimeEmployee fullTime) {

            System.out.println("Type: Full-Time Employee");

            System.out.println(
                "Monthly Salary: " + fullTime.getMonthlySalary()
            );

        } else if (employee instanceof ContractEmployee contract) {

            System.out.println("Type: Contract Employee");

            System.out.println(
                "Hourly Rate: " + contract.getHourlyRate()
            );

            System.out.println(
                "Hours Worked: " + contract.getHoursWorked()
            );
        }
    }

    // Anonymous Inner Class for Report Formatting
    void displayFormattedReport() {

        Runnable report = new Runnable() {

            @Override
            public void run() {

                System.out.println(
                    "\n*** FORMATTED EMPLOYEE REPORT ***"
                );

                for (Employee employee : employees) {

                    System.out.println(
                        employee.getName()
                        + " - "
                        + employee.getDepartment()
                    );
                }
            }
        };

        report.run();
    }

    public static void main(String[] args) {

        EmployeeManagementSystem system =
                new EmployeeManagementSystem();

        // Creating Full-Time Employee
        Employee e1 = new FullTimeEmployee(
            101,
            "Anurag",
            Department.IT,
            50000
        );

        // Creating Contract Employee
        Employee e2 = new ContractEmployee(
            102,
            "Rahul",
            Department.HR,
            500,
            80
        );

        // Adding employees
        system.addEmployee(e1);
        system.addEmployee(e2);

        // Regular Inner Class
        EmployeeManagementSystem.EmployeeDetails details =
                system.new EmployeeDetails();

        details.display(e1);
        details.display(e2);

        // Pattern Matching
        system.processEmployee(e1);
        system.processEmployee(e2);

        // Static Nested Class
        EmployeeManagementSystem.ReportGenerator
                .generateReport(system.employees);

        // Method Local Inner Class
        system.generateDepartmentReport(Department.IT);

        // Anonymous Inner Class
        system.displayFormattedReport();
    }
}
```

## 7.5 Expected Output

```text
----- Employee Details -----
Employee ID: 101
Name: Anurag
Department: IT
Salary: 50000.0

----- Employee Details -----
Employee ID: 102
Name: Rahul
Department: HR
Salary: 40000.0

Processing: Anurag
Type: Full-Time Employee
Monthly Salary: 50000.0

Processing: Rahul
Type: Contract Employee
Hourly Rate: 500.0
Hours Worked: 80

===== EMPLOYEE REPORT =====
101 | Anurag | IT | 50000.0
102 | Rahul | HR | 40000.0

Employees in Department: IT
Anurag

*** FORMATTED EMPLOYEE REPORT ***
Anurag - IT
Rahul - HR
```

## 7.6 Explanation of the Program

### A. Department Enum

```java
enum Department {
    HR, IT, FINANCE, SALES
}
```

We use an enum to restrict departments to predefined values.

For example:

```java
Department.IT
```

This avoids invalid department names such as `"InformationTechnology"` or `"It Department"`.

### B. Sealed Employee Class

```java
sealed abstract class Employee
        permits FullTimeEmployee, ContractEmployee
```

Only the two permitted classes can directly extend `Employee`.

This gives us a controlled employee hierarchy.

### C. Final Variables

```java
private final int employeeId;
private final String name;
```

Employee ID and name are assigned through the constructor and cannot be reassigned afterward.

### D. Final Method

```java
public final void displayBasicDetails()
```

Subclasses inherit this method but cannot override it.

### E. Pattern Matching

```java
if (employee instanceof FullTimeEmployee fullTime)
```

The program checks the actual object type and creates a correctly typed variable.

We use this to access subclass-specific methods.

### F. Regular Inner Class

```java
class EmployeeDetails
```

It displays employee information and can access members of its outer EmployeeManagementSystem instance.

### G. Static Nested Class

```java
static class ReportGenerator
```

It generates a report without requiring an EmployeeManagementSystem object for the nested class itself.

### H. Method Local Inner Class

```java
class DepartmentReport
```

It is declared inside `generateDepartmentReport()` and is used only within that method.

### I. Anonymous Inner Class

```java
Runnable report = new Runnable() {
    @Override
    public void run() {
        // Report logic
    }
};
```

It provides a one-time implementation of the `Runnable` interface for report formatting.

## 7.7 Compile and Run

Open the terminal in the folder containing the file.

Compile:

```bash
javac EmployeeManagementSystem.java
```

Run:

```bash
java EmployeeManagementSystem
```

**Note:** This program uses Java 17 features and should be compiled using JDK 17 or a later compatible JDK.

---

# 8. Important Interview Questions and Answers

### Q1. What is an enum in Java?

An enum is a special type that defines a fixed set of named constants.

### Q2. Can we create an object of an enum using `new`?

No. Enum constants are defined by the enum declaration and cannot be instantiated using `new`.

### Q3. Can an enum have a constructor?

Yes. An enum can have a constructor, fields and methods. Its constructor cannot be public or protected.

### Q4. What does `values()` do?

It returns an array containing all enum constants in declaration order.

### Q5. What is a sealed class?

A sealed class restricts which classes are allowed to extend it.

### Q6. Which keyword is used to define permitted subclasses?

`permits`.

### Q7. Which three modifiers can a permitted subclass use?

`final`, `sealed` and `non-sealed`.

### Q8. What is the difference between sealed and final classes?

A sealed class allows specified subclasses, whereas a final class cannot be extended.

### Q9. What is the purpose of the final keyword?

It restricts reassignment, overriding or inheritance depending on where it is applied.

### Q10. Can we modify a final reference object's contents?

Yes, if the referenced object is mutable. The reference cannot be reassigned, but the object's state may change.

### Q11. Can a final method be overloaded?

Yes. A final method cannot be overridden, but another method with a different parameter list can be overloaded.

### Q12. Can a constructor be final?

No. Constructors cannot be declared final.

### Q13. Can an abstract class be final?

No. An abstract class is designed to be extended, whereas a final class cannot be extended.

### Q14. What is pattern matching?

Pattern matching combines type checking and variable binding, reducing the need for explicit casting.

### Q15. From which Java version is pattern matching for instanceof final?

Java 16.

### Q16. What is an inner class?

A non-static nested class declared inside another class.

### Q17. Can an inner class access private members of its outer class?

Yes.

### Q18. What is a method local inner class?

A class declared inside a method and accessible only within its declaring method or block.

### Q19. What is an anonymous inner class?

A class without a name, generally created for one-time implementation of an interface or abstract class.

### Q20. What is a static nested class?

A nested class declared with `static`. It does not require an instance of the outer class for its creation.

### Q21. What is the difference between an inner class and a static nested class?

A regular inner class is associated with an outer object. A static nested class is not.

### Q22. Can a static nested class access non-static outer variables directly?

No. It needs an instance of the outer class to access non-static members.

### Q23. Can a local inner class access local variables?

Yes, provided those variables are final or effectively final.

### Q24. What is the benefit of sealed classes?

They provide controlled inheritance and make class hierarchies easier to understand and maintain.

### Q25. Can an enum implement an interface?

Yes. An enum can implement one or more interfaces.

---

# 9. Important MCQs for CMCE

**1. Which keyword is used to define an enumeration?**

A. `constant`  
B. `enum`  
C. `final`  
D. `static`

**Answer: B. enum**

**2. Which method returns all enum constants?**

A. `getValues()`  
B. `valueOf()`  
C. `values()`  
D. `getAll()`

**Answer: C. values()**

**3. Which keyword restricts inheritance?**

A. `sealed`  
B. `extends`  
C. `permits`  
D. `implements`

**Answer: A. sealed**

**4. Which modifier allows unrestricted further inheritance from a permitted sealed subclass?**

A. `final`  
B. `sealed`  
C. `non-sealed`  
D. `static`

**Answer: C. non-sealed**

**5. A final variable can be:**

A. Reassigned multiple times  
B. Assigned only once  
C. Overridden  
D. Extended

**Answer: B. Assigned only once**

**6. A final method:**

A. Cannot be called  
B. Cannot be overloaded  
C. Cannot be overridden  
D. Cannot be inherited

**Answer: C. Cannot be overridden**

**7. Which class cannot be extended?**

A. Abstract class  
B. Final class  
C. Sealed class  
D. Normal class

**Answer: B. Final class**

**8. Pattern matching for instanceof became final in:**

A. Java 8  
B. Java 11  
C. Java 16  
D. Java 17

**Answer: C. Java 16**

**9. Which inner class has no name?**

A. Regular inner class  
B. Method local inner class  
C. Anonymous inner class  
D. Static nested class

**Answer: C. Anonymous inner class**

**10. Which inner class can be created without an outer class object?**

A. Regular inner class  
B. Static nested class  
C. Method local inner class  
D. All inner classes

**Answer: B. Static nested class**

**11. Can an inner class access private outer class members?**

A. Yes  
B. No  
C. Only static members  
D. Only public members

**Answer: A. Yes**

**12. Can a constructor be final?**

A. Yes  
B. No  
C. Only in abstract classes  
D. Only in sealed classes

**Answer: B. No**

**13. Which modifier is required for a direct permitted subclass of a sealed class?**

A. `public`  
B. `static`  
C. One of `final`, `sealed` or `non-sealed`  
D. `abstract` only

**Answer: C. One of `final`, `sealed` or `non-sealed`**

**14. Which feature is useful for defining a fixed set of employee departments?**

A. Interface  
B. Enum  
C. Abstract class  
D. Anonymous class

**Answer: B. Enum**

**15. Which Java feature combines type checking and variable binding?**

A. Method overloading  
B. Pattern matching  
C. Encapsulation  
D. Constructor chaining

**Answer: B. Pattern matching**

---

# 10. Output-Based Questions

## Question 1: Enum ordinal()

```java
enum Color {
    RED, GREEN, BLUE
}

public class Test1 {
    public static void main(String[] args) {

        System.out.println(Color.BLUE.ordinal());
    }
}
```

**Answer:**

```text
2
```

Reason: Enum positions start from zero.

## Question 2: Final Variable

```java
public class Test2 {
    public static void main(String[] args) {

        final int x = 10;

        System.out.println(x);
    }
}
```

**Answer:**

```text
10
```

## Question 3: Pattern Matching

```java
public class Test3 {
    public static void main(String[] args) {

        Object obj = "Java";

        if (obj instanceof String s) {
            System.out.println(s.length());
        }
    }
}
```

**Answer:**

```text
4
```

## Question 4: Regular Inner Class

```java
class Outer {

    private int x = 100;

    class Inner {

        void display() {
            System.out.println(x);
        }
    }
}

public class Test4 {
    public static void main(String[] args) {

        Outer obj = new Outer();

        Outer.Inner inner = obj.new Inner();

        inner.display();
    }
}
```

**Answer:**

```text
100
```

## Question 5: Static Nested Class

```java
class Outer {

    static class Inner {

        void display() {
            System.out.println("Static Inner");
        }
    }
}

public class Test5 {
    public static void main(String[] args) {

        Outer.Inner obj = new Outer.Inner();

        obj.display();
    }
}
```

**Answer:**

```text
Static Inner
```

---

# 11. Quick Revision Notes

| Topic | Key Point |
|---|---|
| Enum | Fixed set of constants |
| `values()` | Returns all enum constants |
| `valueOf()` | Converts matching name into enum constant |
| `ordinal()` | Returns zero-based position |
| Sealed Class | Restricts permitted subclasses |
| `permits` | Specifies allowed subclasses |
| `final` | Stops reassignment, overriding or inheritance |
| `non-sealed` | Allows unrestricted further inheritance |
| Final Variable | Cannot be reassigned |
| Final Method | Cannot be overridden |
| Final Class | Cannot be extended |
| Pattern Matching | Type checking with variable binding |
| Regular Inner Class | Member class associated with an outer object |
| Method Local Inner Class | Declared inside a method |
| Anonymous Inner Class | Class without a name |
| Static Nested Class | Nested class that does not require an outer object |

---

# 12. Practice Checklist

- [ ] Understand enum declaration and constants.
- [ ] Practice `values()`, `valueOf()` and `ordinal()`.
- [ ] Create enum with fields, constructor and methods.
- [ ] Understand sealed classes.
- [ ] Practice `sealed`, `permits`, `final` and `non-sealed`.
- [ ] Understand final variables.
- [ ] Understand final methods.
- [ ] Understand final classes.
- [ ] Practice pattern matching with `instanceof`.
- [ ] Create a regular inner class.
- [ ] Create a method local inner class.
- [ ] Create an anonymous inner class.
- [ ] Create a static nested class.
- [ ] Complete the Employee Management System.
- [ ] Solve MCQs and output-based questions.

---

# 13. Additional Practice Assignments

1. Create a `TrafficSignal` enum with RED, YELLOW and GREEN.
2. Create a `PaymentStatus` enum with PENDING, SUCCESS and FAILED.
3. Create a sealed `Shape` class with Circle, Rectangle and Triangle subclasses.
4. Demonstrate final variables using a Student class.
5. Create a final method in a parent class and try to override it.
6. Create a final class and demonstrate that it cannot be extended.
7. Use pattern matching to identify different types of Shape objects.
8. Create a regular inner class to display bank account details.
9. Create a method local inner class to generate a student report.
10. Use an anonymous inner class to implement a sorting or display operation.
11. Create a static nested class for utility operations.
12. Extend the Employee Management System with a new department and employee type.

---

# 14. Suggested GitHub Folder Structure

```text
Java/
└── Session-10-Enumeration-and-Class-Features/
    ├── README.md
    └── programs/
        ├── EnumDemo.java
        ├── EnumMethodsDemo.java
        ├── EnumConstructorDemo.java
        ├── SealedDemo.java
        ├── SealedHierarchyDemo.java
        ├── FinalVariableDemo.java
        ├── FinalMethodDemo.java
        ├── FinalClassDemo.java
        ├── PatternMatchingDemo.java
        ├── RegularInnerDemo.java
        ├── LocalInnerDemo.java
        ├── AnonymousInnerDemo.java
        ├── StaticNestedDemo.java
        └── EmployeeManagementSystem.java
```

---

# 15. Official Java References

- [Java 17 Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/)
- [Enum Class](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/Enum.html)
- [Java Language Specification – Classes](https://docs.oracle.com/javase/specs/jls/se17/html/jls-8.html)
- [Java Language Specification – Enums](https://docs.oracle.com/javase/specs/jls/se17/html/jls-8.html#jls-8.9)
- [Java Language Specification – Pattern Matching](https://docs.oracle.com/javase/specs/jls/se17/html/jls-15.html#jls-15.20.2)

---

**End of Session 10 – Enumeration and Java Class Features**

*Practice each example independently, understand the rules of sealed classes and inner classes, and complete the Employee Management System lab using Java 17.*

