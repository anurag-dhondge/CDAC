# Session 17: Object Class & Date Time API in Java

**Course:** CMCE – August 2026 Batch  
**Subject:** Core Java  
**Topics:** LocalDate, LocalDateTime, Date Conversion, Object Class, toString(), equals(), hashCode()

---

# 1. Introduction to Date and Time API

Java provides the Date and Time API in the `java.time` package.

It was introduced in **Java 8** to provide a modern and easier way to work with dates, times, durations, and time zones.

Earlier Java applications commonly used:
- `java.util.Date`
- `java.util.Calendar`
- `java.text.SimpleDateFormat`

The modern Date and Time API provides classes such as:

| Class | Purpose |
|---|---|
| LocalDate | Represents date without time |
| LocalTime | Represents time without date |
| LocalDateTime | Represents date and time without time zone |
| ZonedDateTime | Represents date and time with time zone |
| Instant | Represents a point on the UTC timeline |
| Period | Represents date-based differences |
| Duration | Represents time-based differences |
| DateTimeFormatter | Formats and parses date/time values |

### Import Statement

```java
import java.time.*;
import java.time.format.*;
```

### Important Features

- Immutable objects.
- Thread-safe date and time classes.
- Easy date and time calculations.
- Clear separation between date, time, and time zone.
- Supports formatting and parsing.
- Avoids many problems of the older Date and Calendar APIs.

**Important:** `LocalDate` and `LocalDateTime` are immutable. Methods such as `plusDays()` return new objects instead of modifying the existing object.

---

# 2. LocalDate Class

`LocalDate` represents a date without a time or time zone.

It stores:

- Year
- Month
- Day

Example:

```text
2026-11-09
```

### Import

```java
import java.time.LocalDate;
```

### Creating LocalDate Objects

**1. Using now()**

Returns the current date according to the system's default time zone.

```java
LocalDate today = LocalDate.now();

System.out.println(today);
```

**Example Output:**

```text
2026-11-09
```

**2. Using of()**

Creates a date by specifying year, month, and day.

```java
LocalDate date = LocalDate.of(2026, 11, 9);

System.out.println(date);
```

**Output:**

```text
2026-11-09
```

**3. Using parse()**

Creates a LocalDate from a date string in ISO format.

```java
LocalDate date = LocalDate.parse("2026-11-09");

System.out.println(date);
```

**Output:**

```text
2026-11-09
```

### Important LocalDate Methods

| Method | Description |
|---|---|
| `now()` | Returns current date |
| `of(year, month, day)` | Creates a date |
| `parse(String)` | Converts String into LocalDate |
| `getYear()` | Returns year |
| `getMonth()` | Returns Month enum |
| `getMonthValue()` | Returns month number |
| `getDayOfMonth()` | Returns day of month |
| `getDayOfWeek()` | Returns day of week |
| `getDayOfYear()` | Returns day number within year |
| `isLeapYear()` | Checks whether year is leap year |
| `lengthOfMonth()` | Returns number of days in month |
| `lengthOfYear()` | Returns 365 or 366 |
| `plusDays()` | Adds days |
| `minusDays()` | Subtracts days |
| `plusMonths()` | Adds months |
| `minusMonths()` | Subtracts months |
| `plusYears()` | Adds years |
| `minusYears()` | Subtracts years |
| `isBefore()` | Checks whether date is earlier |
| `isAfter()` | Checks whether date is later |
| `isEqual()` | Checks date equality |

### Example: LocalDateDemo.java

```java
import java.time.LocalDate;

public class LocalDateDemo {

    public static void main(String[] args) {

        LocalDate today = LocalDate.now();

        LocalDate joiningDate =
                LocalDate.of(2022, 7, 15);

        System.out.println("Today: " + today);

        System.out.println("Joining Date: " + joiningDate);

        System.out.println("Year: " + today.getYear());

        System.out.println("Month: " + today.getMonth());

        System.out.println("Month Value: " +
                today.getMonthValue());

        System.out.println("Day: " +
                today.getDayOfMonth());

        System.out.println("Day of Week: " +
                today.getDayOfWeek());

        System.out.println("Leap Year: " +
                today.isLeapYear());

        System.out.println("After 10 Days: " +
                today.plusDays(10));

        System.out.println("Before 2 Months: " +
                today.minusMonths(2));
    }
}
```

**Example Output (when run on 9 November 2026):**

```text
Today: 2026-11-09
Joining Date: 2022-07-15
Year: 2026
Month: NOVEMBER
Month Value: 11
Day: 9
Day of Week: MONDAY
Leap Year: false
After 10 Days: 2026-11-19
Before 2 Months: 2026-09-09
```

---

# 3. LocalTime Class

`LocalTime` represents time without a date or time zone.

Example:

```text
14:30:45
```

It stores:

- Hour
- Minute
- Second
- Nanosecond

### Example

```java
import java.time.LocalTime;

public class LocalTimeDemo {

    public static void main(String[] args) {

        LocalTime currentTime = LocalTime.now();

        LocalTime time = LocalTime.of(10, 30, 45);

        System.out.println("Current Time: " + currentTime);

        System.out.println("Custom Time: " + time);

        System.out.println("Hour: " + time.getHour());

        System.out.println("Minute: " + time.getMinute());

        System.out.println("Second: " + time.getSecond());

        System.out.println("After 2 Hours: " +
                time.plusHours(2));
    }
}
```

**Example Output:**

```text
Custom Time: 10:30:45
Hour: 10
Minute: 30
Second: 45
After 2 Hours: 12:30:45
```

---

# 4. LocalDateTime API

`LocalDateTime` represents both date and time without a time zone.

Example:

```text
2026-11-09T14:30:45
```

It combines:

- LocalDate
- LocalTime

### Import

```java
import java.time.LocalDateTime;
```

### Creating LocalDateTime Objects

**1. Using now()**

```java
LocalDateTime currentDateTime =
        LocalDateTime.now();

System.out.println(currentDateTime);
```

**2. Using of()**

```java
LocalDateTime dateTime =
        LocalDateTime.of(2026, 11, 9, 14, 30, 45);

System.out.println(dateTime);
```

**Output:**

```text
2026-11-09T14:30:45
```

**3. Using parse()**

```java
LocalDateTime dateTime =
        LocalDateTime.parse("2026-11-09T14:30:45");

System.out.println(dateTime);
```

### Important LocalDateTime Methods

| Method | Description |
|---|---|
| `now()` | Returns current date and time |
| `of()` | Creates date and time |
| `parse()` | Converts String into LocalDateTime |
| `toLocalDate()` | Extracts LocalDate |
| `toLocalTime()` | Extracts LocalTime |
| `getYear()` | Returns year |
| `getMonth()` | Returns month |
| `getDayOfMonth()` | Returns day |
| `getHour()` | Returns hour |
| `getMinute()` | Returns minute |
| `plusDays()` | Adds days |
| `minusDays()` | Subtracts days |
| `plusHours()` | Adds hours |
| `minusHours()` | Subtracts hours |

### Example: LocalDateTimeDemo.java

```java
import java.time.LocalDateTime;

public class LocalDateTimeDemo {

    public static void main(String[] args) {

        LocalDateTime current =
                LocalDateTime.now();

        LocalDateTime meeting =
                LocalDateTime.of(
                        2026, 11, 10, 10, 30
                );

        System.out.println("Current: " + current);

        System.out.println("Meeting: " + meeting);

        System.out.println("Date: " +
                meeting.toLocalDate());

        System.out.println("Time: " +
                meeting.toLocalTime());

        System.out.println("Hour: " +
                meeting.getHour());

        System.out.println("After 3 Days: " +
                meeting.plusDays(3));

        System.out.println("After 2 Hours: " +
                meeting.plusHours(2));
    }
}
```

### LocalDate vs LocalTime vs LocalDateTime

| Feature | LocalDate | LocalTime | LocalDateTime |
|---|---|---|---|
| Stores date | Yes | No | Yes |
| Stores time | No | Yes | Yes |
| Stores time zone | No | No | No |
| Example | 2026-11-09 | 10:30:00 | 2026-11-09T10:30:00 |
| Use | Joining date | Office entry time | Attendance timestamp |

**Important:** LocalDateTime does not represent a globally unique instant. For applications involving different time zones, consider `ZonedDateTime` or `Instant`.

---

# 5. Converting LocalDate to String

Sometimes we need to convert a LocalDate object into a String.

Java provides the `toString()` method for the default ISO date representation.

### Example

```java
import java.time.LocalDate;

public class DateToStringDemo {

    public static void main(String[] args) {

        LocalDate date =
                LocalDate.of(2026, 11, 9);

        String dateString = date.toString();

        System.out.println("LocalDate: " + date);

        System.out.println("String: " + dateString);

        System.out.println("Type: " +
                dateString.getClass().getSimpleName());
    }
}
```

**Output:**

```text
LocalDate: 2026-11-09
String: 2026-11-09
Type: String
```

### Converting Date into a Custom String Format

Use `DateTimeFormatter`.

```java
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class DateFormattingDemo {

    public static void main(String[] args) {

        LocalDate date =
                LocalDate.of(2026, 11, 9);

        DateTimeFormatter formatter =
                DateTimeFormatter.ofPattern("dd-MM-yyyy");

        String formattedDate =
                date.format(formatter);

        System.out.println(formattedDate);
    }
}
```

**Output:**

```text
09-11-2026
```

### Common Date Formatting Patterns

| Pattern | Meaning | Example |
|---|---|---|
| `dd` | Day | 09 |
| `MM` | Month number | 11 |
| `MMM` | Short month name | Nov |
| `MMMM` | Full month name | November |
| `yyyy` | Four-digit year | 2026 |
| `yy` | Two-digit year | 26 |
| `EEEE` | Full weekday | Monday |
| `EEE` | Short weekday | Mon |

**Important:** Uppercase `MM` means month, while lowercase `mm` means minute.

---

# 6. Converting String to LocalDate

Use the `LocalDate.parse()` method to convert a date String into a LocalDate object.

### Example: Default ISO Format

```java
import java.time.LocalDate;

public class StringToDateDemo {

    public static void main(String[] args) {

        String dateString = "2026-11-09";

        LocalDate date =
                LocalDate.parse(dateString);

        System.out.println("String: " + dateString);

        System.out.println("LocalDate: " + date);
    }
}
```

**Output:**

```text
String: 2026-11-09
LocalDate: 2026-11-09
```

### Example: Custom Date Format

If the String is in `dd-MM-yyyy` format, use a formatter.

```java
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class CustomStringToDateDemo {

    public static void main(String[] args) {

        String dateString = "09-11-2026";

        DateTimeFormatter formatter =
                DateTimeFormatter.ofPattern("dd-MM-yyyy");

        LocalDate date =
                LocalDate.parse(dateString, formatter);

        System.out.println(date);
    }
}
```

**Output:**

```text
2026-11-09
```

### What Happens with Invalid Dates?

```java
LocalDate date =
        LocalDate.parse("2026-15-40");
```

This throws `DateTimeParseException` because the date is invalid.

### LocalDate to String vs String to LocalDate

| Conversion | Method |
|---|---|
| LocalDate → String | `toString()` or `format()` |
| String → LocalDate | `parse()` |
| Custom format | `DateTimeFormatter` |

---

# 7. Date Calculations Using Period

`Period` represents a date-based amount of time in years, months, and days.

It is useful for calculating employee experience, age, and date differences.

### Example

```java
import java.time.LocalDate;
import java.time.Period;

public class PeriodDemo {

    public static void main(String[] args) {

        LocalDate joiningDate =
                LocalDate.of(2020, 7, 15);

        LocalDate today =
                LocalDate.of(2026, 11, 9);

        Period experience =
                Period.between(joiningDate, today);

        System.out.println("Years: " +
                experience.getYears());

        System.out.println("Months: " +
                experience.getMonths());

        System.out.println("Days: " +
                experience.getDays());

        System.out.println("Total Months: " +
                experience.toTotalMonths());
    }
}
```

**Output:**

```text
Years: 6
Months: 3
Days: 25
Total Months: 75
```

### Understanding Period.between()

```java
Period.between(startDate, endDate);
```

It calculates the period from the start date to the end date.

For employee experience:

```java
Period experience =
        Period.between(joiningDate, LocalDate.now());
```

**Important:** `Period` is suitable for date-based differences. For elapsed hours, minutes, and seconds, use `Duration`.

---

# 8. Object Class in Java

The `Object` class is the root class of the Java class hierarchy.

Every Java class directly or indirectly inherits from `Object`, unless it is the Object class itself.

This means every Java class gets access to methods defined in the Object class.

### Object Class Hierarchy

```text
                  Object
                    |
          +---------+---------+
          |         |         |
        String   Employee   Student
                    |
                 Manager
```

Example:

```java
class Employee {
    int id;
    String name;
}
```

The Employee class automatically inherits from Object.

It is equivalent to:

```java
class Employee extends Object {
    int id;
    String name;
}
```

### Important Object Class Methods

| Method | Description |
|---|---|
| `toString()` | Returns a String representation of an object |
| `equals(Object obj)` | Checks logical equality |
| `hashCode()` | Returns an integer hash code |
| `getClass()` | Returns the runtime class of an object |
| `clone()` | Creates a field-by-field copy when cloning is supported |
| `wait()` | Causes the current thread to wait |
| `notify()` | Wakes one waiting thread |
| `notifyAll()` | Wakes all waiting threads |

For this session, focus mainly on:

1. `toString()`
2. `equals()`
3. `hashCode()`

---

# 9. Overriding toString() Method

The `toString()` method returns a String representation of an object.

The default implementation from Object generally returns a class name followed by `@` and a hexadecimal hash code representation.

### Without Overriding toString()

```java
class Employee {

    int id;
    String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

public class ToStringDemo {

    public static void main(String[] args) {

        Employee e1 =
                new Employee(101, "Anurag");

        System.out.println(e1);
    }
}
```

**Possible Output:**

```text
Employee@5acf9800
```

The hexadecimal portion can differ between executions.

### With Overriding toString()

```java
class Employee {

    int id;
    String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public String toString() {

        return "Employee ID: " + id +
                ", Name: " + name;
    }
}

public class ToStringDemo {

    public static void main(String[] args) {

        Employee e1 =
                new Employee(101, "Anurag");

        System.out.println(e1);
    }
}
```

**Output:**

```text
Employee ID: 101, Name: Anurag
```

### Why Override toString()?

- Provides meaningful object information.
- Makes debugging easier.
- Makes console output readable.
- Useful when displaying objects in logs and collections.

**Remember:** `System.out.println(object)` automatically invokes the object's `toString()` method.

---

# 10. Overriding equals() Method

The `equals()` method is used to compare two objects for logical equality.

By default, the Object class implementation behaves like reference identity comparison.

If we want to compare object contents, we should override `equals()`.

### Example: Without Overriding equals()

```java
class Employee {

    int id;
    String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

public class EqualsDemo {

    public static void main(String[] args) {

        Employee e1 =
                new Employee(101, "Anurag");

        Employee e2 =
                new Employee(101, "Anurag");

        System.out.println(e1.equals(e2));
    }
}
```

**Output:**

```text
false
```

Although the data is identical, they are two different objects.

### Example: With Overriding equals()

```java
import java.util.Objects;

class Employee {

    int id;
    String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj) {
            return true;
        }

        if (!(obj instanceof Employee)) {
            return false;
        }

        Employee other = (Employee) obj;

        return id == other.id &&
                Objects.equals(name, other.name);
    }
}

public class EqualsDemo {

    public static void main(String[] args) {

        Employee e1 =
                new Employee(101, "Anurag");

        Employee e2 =
                new Employee(101, "Anurag");

        Employee e3 =
                new Employee(102, "Rahul");

        System.out.println(e1.equals(e2));

        System.out.println(e1.equals(e3));
    }
}
```

**Output:**

```text
true
false
```

### Explanation

**1. Check same reference**

```java
if (this == obj) {
    return true;
}
```

If both references point to the same object, they are equal.

**2. Check object type**

```java
if (!(obj instanceof Employee)) {
    return false;
}
```

If the supplied object is not an Employee, return false.

**3. Type casting**

```java
Employee other = (Employee) obj;
```

Convert the Object reference into an Employee reference.

**4. Compare fields**

```java
return id == other.id &&
        Objects.equals(name, other.name);
```

Compare the employee's actual data.

---

# 11. Overriding hashCode() Method

`hashCode()` returns an integer value representing an object's hash code.

It is mainly used by hash-based collections such as:

- HashMap
- HashSet
- Hashtable

### Example

```java
class Employee {

    int id;
    String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public int hashCode() {
        return id;
    }
}

public class HashCodeDemo {

    public static void main(String[] args) {

        Employee e1 =
                new Employee(101, "Anurag");

        Employee e2 =
                new Employee(102, "Rahul");

        System.out.println(e1.hashCode());

        System.out.println(e2.hashCode());
    }
}
```

**Output:**

```text
101
102
```

This is a simple demonstration. Real-world implementations should use fields consistent with `equals()`.

### Important Rule: equals() and hashCode()

Java follows an important contract:

1. If two objects are equal according to `equals()`, they must have the same hash code.
2. If two objects have the same hash code, they are not necessarily equal.
3. If two objects are not equal, they may still have the same hash code.

### Example: Correct equals() and hashCode()

```java
import java.util.Objects;

class Employee {

    private int id;
    private String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj) {
            return true;
        }

        if (!(obj instanceof Employee)) {
            return false;
        }

        Employee other = (Employee) obj;

        return id == other.id &&
                Objects.equals(name, other.name);
    }

    @Override
    public int hashCode() {

        return Objects.hash(id, name);
    }
}
```

### Why Override Both?

Suppose two Employee objects have identical IDs and names.

If `equals()` returns true but `hashCode()` returns different values, hash-based collections may behave incorrectly.

Therefore, whenever you override `equals()`, you should also override `hashCode()`.

---

# 12. Difference Between == and equals()

| `==` | `equals()` |
|---|---|
| Operator | Method |
| Compares primitive values | Compares object equality |
| For references, checks whether both point to the same object | Depends on the class implementation |
| Cannot be overridden | Can be overridden |

### Example

```java
public class CompareDemo {

    public static void main(String[] args) {

        String s1 = new String("Java");

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

Explanation:

- `==` checks reference identity.
- String overrides `equals()` to compare character content.

---

# 13. Lab: Employee Attendance System

## Problem Statement

Develop an Employee Attendance System that:

1. Stores employee details and joining dates.
2. Calculates employee experience using LocalDate.
3. Overrides `toString()`.
4. Overrides `equals()`.
5. Overrides `hashCode()`.

## 13.1 Application Design

We will create an Employee class with the following fields:

| Field | Data Type | Description |
|---|---|---|
| employeeId | int | Unique employee ID |
| name | String | Employee name |
| department | String | Employee department |
| joiningDate | LocalDate | Date of joining |

### Application Flow

```text
             Employee Attendance System
                        |
                        v
                  Create Employee
                        |
                        v
                 Store Employee Data
                        |
                        v
                  Joining Date
                        |
                        v
              Calculate Experience
                        |
                        v
              Period.between()
                        |
                        v
                 Display Details
                        |
              +---------+---------+
              |         |         |
              v         v         v
           toString   equals   hashCode
```

## 13.2 Step 1: Create Employee Class

**File: Employee.java**

```java
import java.time.LocalDate;
import java.time.Period;
import java.util.Objects;

public class Employee {

    private int employeeId;
    private String name;
    private String department;
    private LocalDate joiningDate;

    public Employee(int employeeId,
                    String name,
                    String department,
                    LocalDate joiningDate) {

        this.employeeId = employeeId;
        this.name = name;
        this.department = department;
        this.joiningDate = joiningDate;
    }

    // Calculate employee experience
    public Period calculateExperience() {

        return Period.between(
                joiningDate,
                LocalDate.now()
        );
    }

    // Display employee details
    @Override
    public String toString() {

        return "Employee ID: " + employeeId +
                "\nName: " + name +
                "\nDepartment: " + department +
                "\nJoining Date: " + joiningDate;
    }

    // Compare employee objects
    @Override
    public boolean equals(Object obj) {

        if (this == obj) {
            return true;
        }

        if (!(obj instanceof Employee)) {
            return false;
        }

        Employee other = (Employee) obj;

        return employeeId == other.employeeId;
    }

    // Generate hash code
    @Override
    public int hashCode() {

        return Objects.hash(employeeId);
    }

    public int getEmployeeId() {
        return employeeId;
    }

    public String getName() {
        return name;
    }

    public String getDepartment() {
        return department;
    }

    public LocalDate getJoiningDate() {
        return joiningDate;
    }
}
```

### Explanation

**1. LocalDate**

```java
private LocalDate joiningDate;
```

Stores the employee's joining date without time or time zone.

**2. Period.between()**

```java
Period.between(joiningDate, LocalDate.now());
```

Calculates the employee's experience from joining date to today's date.

**3. toString()**

Returns employee information in a readable format.

**4. equals()**

Two Employee objects are considered equal when they have the same employee ID.

**5. hashCode()**

Uses the employee ID to generate the hash code, matching the equality rule.

## 13.3 Step 2: Create Main Application

**File: EmployeeAttendanceSystem.java**

```java
import java.time.LocalDate;
import java.time.Period;
import java.util.HashSet;
import java.util.Set;

public class EmployeeAttendanceSystem {

    public static void main(String[] args) {

        Employee e1 = new Employee(
                101,
                "Anurag",
                "AIML",
                LocalDate.of(2022, 7, 15)
        );

        Employee e2 = new Employee(
                102,
                "Rahul",
                "Development",
                LocalDate.of(2023, 5, 10)
        );

        Employee e3 = new Employee(
                101,
                "Anurag",
                "AIML",
                LocalDate.of(2022, 7, 15)
        );

        // Display employee details
        System.out.println("----- Employee Details -----");

        System.out.println(e1);

        System.out.println();

        System.out.println(e2);

        // Calculate experience
        System.out.println("\n----- Employee Experience -----");

        Period experience = e1.calculateExperience();

        System.out.println("Employee: " + e1.getName());

        System.out.println("Experience: " +
                experience.getYears() + " Years, " +
                experience.getMonths() + " Months, " +
                experience.getDays() + " Days");

        // Compare employees
        System.out.println("\n----- Equality Check -----");

        System.out.println("e1 equals e2: " +
                e1.equals(e2));

        System.out.println("e1 equals e3: " +
                e1.equals(e3));

        // Hash code
        System.out.println("\n----- Hash Codes -----");

        System.out.println("e1: " + e1.hashCode());

        System.out.println("e2: " + e2.hashCode());

        System.out.println("e3: " + e3.hashCode());

        // HashSet demonstration
        System.out.println("\n----- HashSet Demonstration -----");

        Set<Employee> employees = new HashSet<>();

        employees.add(e1);
        employees.add(e2);
        employees.add(e3);

        System.out.println("Total Employees: " +
                employees.size());
    }
}
```

## 13.4 Expected Output

The experience output depends on the date when the program is executed.

For example, if run on 9 November 2026:

```text
----- Employee Details -----
Employee ID: 101
Name: Anurag
Department: AIML
Joining Date: 2022-07-15

Employee ID: 102
Name: Rahul
Department: Development
Joining Date: 2023-05-10

----- Employee Experience -----
Employee: Anurag
Experience: 4 Years, 3 Months, 25 Days

----- Equality Check -----
e1 equals e2: false
e1 equals e3: true

----- Hash Codes -----
e1: 101
e2: 102
e3: 101

----- HashSet Demonstration -----
Total Employees: 2
```

**Note:** Hash codes in this example are generated from employee IDs, so the displayed values are deterministic.

## 13.5 Understanding HashSet Demonstration

```java
Set<Employee> employees = new HashSet<>();

employees.add(e1);
employees.add(e2);
employees.add(e3);
```

We created three Employee objects.

| Object | Employee ID | Equality |
|---|---:|---|
| e1 | 101 | First employee |
| e2 | 102 | Different employee |
| e3 | 101 | Equal to e1 |

Since `e1` and `e3` have the same employee ID, the overridden `equals()` returns true and their hash codes match.

Therefore, HashSet stores only two distinct employees.

**Important:** HashSet uses both `hashCode()` and `equals()` to determine duplicates.

---

# 14. Additional Lab: Attendance Date Conversion

This program demonstrates converting a joining date from String to LocalDate and back to a formatted String.

```java
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class AttendanceDateDemo {

    public static void main(String[] args) {

        String joiningDateString = "15-07-2022";

        DateTimeFormatter formatter =
                DateTimeFormatter.ofPattern("dd-MM-yyyy");

        // String to LocalDate
        LocalDate joiningDate =
                LocalDate.parse(joiningDateString, formatter);

        // LocalDate to String
        String formattedDate =
                joiningDate.format(formatter);

        System.out.println("Joining Date: " + joiningDate);

        System.out.println("Formatted Date: " +
                formattedDate);
    }
}
```

**Output:**

```text
Joining Date: 2022-07-15
Formatted Date: 15-07-2022
```

---

# 15. Important Interview Questions and Answers

**Q1. What is the Java Date and Time API?**

It is a modern API introduced in Java 8 in the `java.time` package for working with dates and times.

**Q2. What is LocalDate?**

LocalDate represents a date without time or time zone.

**Q3. What is LocalTime?**

LocalTime represents time without a date or time zone.

**Q4. What is LocalDateTime?**

LocalDateTime represents both date and time without a time zone.

**Q5. Which package contains LocalDate?**

`java.time`.

**Q6. Is LocalDate mutable or immutable?**

LocalDate is immutable.

**Q7. How do you get the current date?**

```java
LocalDate.now();
```

**Q8. How do you create a custom date?**

```java
LocalDate.of(2026, 11, 9);
```

**Q9. How do you convert LocalDate into String?**

Use `toString()` or `format()`.

**Q10. How do you convert String into LocalDate?**

Use `LocalDate.parse()`.

**Q11. What is DateTimeFormatter?**

It is used to format and parse date/time values.

**Q12. What is Period?**

Period represents a date-based amount of time in years, months, and days.

**Q13. What is the Object class?**

Object is the root class of the Java class hierarchy.

**Q14. Why is Object class important?**

Every Java class inherits its methods directly or indirectly.

**Q15. What is toString()?**

It returns a String representation of an object.

**Q16. Why override toString()?**

To display meaningful object information.

**Q17. What is equals()?**

It checks logical equality between objects according to the implementation.

**Q18. What is hashCode()?**

It returns an integer hash code used by hash-based collections.

**Q19. What is the difference between == and equals()?**

`==` compares reference identity for objects, while `equals()` checks logical equality according to the class implementation.

**Q20. What is the relationship between equals() and hashCode()?**

If two objects are equal according to `equals()`, they must have the same hash code.

**Q21. Can two unequal objects have the same hash code?**

Yes. Hash collisions are possible.

**Q22. What happens if we override equals() but not hashCode()?**

Hash-based collections may behave incorrectly for logically equal objects.

**Q23. Which collections use hashCode()?**

HashMap, HashSet, and Hashtable.

**Q24. What is the purpose of Period.between()?**

It calculates the date-based difference between two dates.

**Q25. Can LocalDate store time?**

No. LocalDate stores only year, month, and day.

---

# 16. MCQs

**1. Which package contains LocalDate?**

A. java.util  
B. java.io  
C. java.time  
D. java.lang  

**Answer: C. java.time**

**2. LocalDate was introduced in which Java version?**

A. Java 5  
B. Java 7  
C. Java 8  
D. Java 11  

**Answer: C. Java 8**

**3. Which method returns the current date?**

A. getDate()  
B. now()  
C. currentDate()  
D. today()  

**Answer: B. now()**

**4. Which class represents date and time without time zone?**

A. LocalDate  
B. LocalTime  
C. LocalDateTime  
D. Instant  

**Answer: C. LocalDateTime**

**5. Which method converts a String into LocalDate?**

A. toString()  
B. parse()  
C. format()  
D. convert()  

**Answer: B. parse()**

**6. Which class formats dates?**

A. DateTimeFormatter  
B. LocalTime  
C. Period  
D. Calendar  

**Answer: A. DateTimeFormatter**

**7. Which class represents date-based differences?**

A. Duration  
B. Period  
C. Instant  
D. LocalTime  

**Answer: B. Period**

**8. Which is the root class of Java?**

A. String  
B. Object  
C. Class  
D. System  

**Answer: B. Object**

**9. Which method returns an object representation as String?**

A. equals()  
B. hashCode()  
C. toString()  
D. getClass()  

**Answer: C. toString()**

**10. Which method is used to compare logical object equality?**

A. ==  
B. equals()  
C. hashCode()  
D. compare()  

**Answer: B. equals()**

**11. What is the return type of hashCode()?**

A. String  
B. boolean  
C. int  
D. long  

**Answer: C. int**

**12. If two objects are equal according to equals(), what must be true?**

A. Their references must be identical  
B. Their hash codes must be equal  
C. Their hash codes must be different  
D. They must belong to different classes  

**Answer: B. Their hash codes must be equal**

**13. Which collection uses hashCode() and equals() to identify duplicates?**

A. ArrayList  
B. LinkedList  
C. HashSet  
D. Vector  

**Answer: C. HashSet**

**14. Which method calculates the difference between two LocalDate objects?**

A. compare()  
B. Period.between()  
C. Duration.between()  
D. difference()  

**Answer: B. Period.between()**

**15. Is LocalDate mutable?**

A. Yes  
B. No  
C. Only in Java 17  
D. Depends on the operating system  

**Answer: B. No**

---

# 17. Output-Based Questions

### Question 1: LocalDate

```java
import java.time.LocalDate;

public class Test {
    public static void main(String[] args) {

        LocalDate date =
                LocalDate.of(2026, 11, 9);

        System.out.println(date.plusDays(5));
    }
}
```

**Output:**

```text
2026-11-14
```

### Question 2: LocalDate Conversion

```java
import java.time.LocalDate;

public class Test {
    public static void main(String[] args) {

        String date = "2026-11-09";

        LocalDate d = LocalDate.parse(date);

        System.out.println(d.getMonth());
    }
}
```

**Output:**

```text
NOVEMBER
```

### Question 3: Object Equality

```java
class Student {

    int id;

    Student(int id) {
        this.id = id;
    }
}

public class Test {

    public static void main(String[] args) {

        Student s1 = new Student(101);

        Student s2 = new Student(101);

        System.out.println(s1 == s2);

        System.out.println(s1.equals(s2));
    }
}
```

**Output:**

```text
false
false
```

Reason: The Student class does not override equals(), so the inherited Object implementation compares reference identity.

### Question 4: String Equality

```java
public class Test {

    public static void main(String[] args) {

        String s1 = new String("Java");

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

### Question 5: LocalDate Immutability

```java
import java.time.LocalDate;

public class Test {

    public static void main(String[] args) {

        LocalDate date =
                LocalDate.of(2026, 11, 9);

        date.plusDays(10);

        System.out.println(date);
    }
}
```

**Output:**

```text
2026-11-09
```

Reason: `plusDays()` returns a new LocalDate object. The original reference was not updated.

---

# 18. Quick Revision Notes

| Concept | Key Point |
|---|---|
| java.time | Date and Time API package |
| LocalDate | Date only |
| LocalTime | Time only |
| LocalDateTime | Date and time |
| now() | Current date/time |
| of() | Create custom date/time |
| parse() | String to date/time |
| toString() | Date to String |
| format() | Custom date formatting |
| DateTimeFormatter | Date formatting and parsing |
| Period | Date-based difference |
| Object | Root class of Java |
| toString() | String representation of object |
| equals() | Logical object comparison |
| hashCode() | Integer hash code |
| == | Reference identity comparison for objects |
| HashSet | Uses hashCode() and equals() |
| Period.between() | Calculates difference between dates |

### Important Syntax

**Create LocalDate**

```java
LocalDate date = LocalDate.now();
```

**Create LocalDateTime**

```java
LocalDateTime dateTime = LocalDateTime.now();
```

**Convert LocalDate to String**

```java
String str = date.toString();
```

**Convert String to LocalDate**

```java
LocalDate date = LocalDate.parse("2026-11-09");
```

**Custom Date Format**

```java
DateTimeFormatter formatter =
        DateTimeFormatter.ofPattern("dd-MM-yyyy");

String str = date.format(formatter);
```

**Calculate Experience**

```java
Period experience =
        Period.between(joiningDate, LocalDate.now());
```

**Override toString()**

```java
@Override
public String toString() {
    return "Employee: " + name;
}
```

**Override equals()**

```java
@Override
public boolean equals(Object obj) {
    // Compare object data
}
```

**Override hashCode()**

```java
@Override
public int hashCode() {
    return Objects.hash(id);
}
```

---

# 19. Practice Checklist

- [ ] Understand Java Date and Time API.
- [ ] Create LocalDate objects.
- [ ] Create LocalTime objects.
- [ ] Create LocalDateTime objects.
- [ ] Practice date calculations.
- [ ] Convert LocalDate into String.
- [ ] Convert String into LocalDate.
- [ ] Practice DateTimeFormatter.
- [ ] Understand Period.between().
- [ ] Understand the Object class.
- [ ] Override toString().
- [ ] Override equals().
- [ ] Override hashCode().
- [ ] Understand the equals() and hashCode() contract.
- [ ] Practice == vs equals().
- [ ] Complete Employee Attendance System.

---

# 20. Additional Practice Assignments

1. **Student Age Calculator:** Store date of birth using LocalDate and calculate age using Period.
2. **Library Management:** Store book issue dates and calculate overdue days.
3. **Employee Experience Calculator:** Display employee experience in years, months, and days.
4. **Event Management System:** Store event dates and compare upcoming events.
5. **Product Management:** Override toString(), equals(), and hashCode() in Product.
6. **Student Management System:** Use HashSet to avoid duplicate students based on roll number.

---

## References

- [Oracle Java Date and Time API](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/time/package-summary.html)
- [Oracle Object Class Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/Object.html)
- [Java 17 DateTimeFormatter Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/time/format/DateTimeFormatter.html)

**Note:** This README is prepared for the CMCE August 2026 Batch and covers Session 17 – Object Class & Date Time API.
