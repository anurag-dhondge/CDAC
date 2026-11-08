# Session 12: MySQL Functions

**Course:** CMCE – Database Technologies  
**Batch:** August 2026  
**Theory:** 2 Hours | **Lab:** 2 Hours

---

## 📌 Topics Covered

1. Introduction to MySQL Functions
2. User-Defined Functions (UDF)
3. Functions Without Parameters
4. Functions With Parameters
5. Returning Values from Functions
6. MySQL Built-in Functions
   - String Functions
   - Numeric Functions
   - Date and Time Functions
   - Aggregate Functions
   - Conversion Functions
   - NULL Handling Functions
7. Practical SQL Programs

---

# 1. Introduction to MySQL Functions

A **Function** is a database routine that performs a specific operation and returns a value.

Functions are used to perform calculations, manipulate strings, process dates, and retrieve information.

MySQL provides two major categories of functions:

1. Built-in Functions
2. User-Defined Functions

### Types of Functions

| Function Type | Description | Example |
|---|---|---|
| Built-in Functions | Already provided by MySQL | `UPPER()`, `ROUND()` |
| User-Defined Functions | Created by the user | `calculateSquare()` |

### Why Do We Use Functions?

- To perform calculations.
- To manipulate string values.
- To process date and time values.
- To avoid repeating calculations.
- To reuse database logic.
- To simplify SQL queries.

---

# 2. User-Defined Functions

A **User-Defined Function (UDF)** is a function created by a user to perform a specific operation.

In MySQL, stored functions are created using the `CREATE FUNCTION` statement.

### Basic Syntax

```sql
DELIMITER //

CREATE FUNCTION function_name(
    parameter_name datatype
)
RETURNS return_datatype
DETERMINISTIC
BEGIN

    -- SQL statements

    RETURN value;

END //

DELIMITER ;
```

### Important Keywords

| Keyword | Description |
|---|---|
| `CREATE FUNCTION` | Creates a function |
| `RETURNS` | Specifies the return data type |
| `DETERMINISTIC` | Declares that the function returns the same result for the same inputs |
| `BEGIN` | Starts the function body |
| `RETURN` | Returns a value |
| `END` | Ends the function body |
| `DROP FUNCTION` | Deletes a function |

**Note:** `DETERMINISTIC` should only be declared when the function truly returns the same result for the same inputs. Functions that depend on current time, random values, or changing database data may be non-deterministic.

---

# 3. Function Without Parameters

A function without parameters does not accept any input values.

It performs a predefined operation and returns a result.

### Example 1: Return a Fixed Number

```sql
DELIMITER //

CREATE FUNCTION getNumber()
RETURNS INT
DETERMINISTIC
BEGIN

    RETURN 100;

END //

DELIMITER ;
```

Execute:

```sql
SELECT getNumber() AS result;
```

**Output:**

```text
result
100
```

### Example 2: Return a Welcome Message

```sql
DELIMITER //

CREATE FUNCTION welcomeMessage()
RETURNS VARCHAR(100)
DETERMINISTIC
BEGIN

    RETURN 'Welcome to MySQL Programming';

END //

DELIMITER ;
```

Execute:

```sql
SELECT welcomeMessage() AS message;
```

**Output:**

```text
Welcome to MySQL Programming
```

### Example 3: Return Total Employee Count

Assume an `employees` table exists.

```sql
DELIMITER //

CREATE FUNCTION totalEmployees()
RETURNS INT
READS SQL DATA
BEGIN

    DECLARE total INT;

    SELECT COUNT(*)
    INTO total
    FROM employees;

    RETURN total;

END //

DELIMITER ;
```

Execute:

```sql
SELECT totalEmployees() AS employee_count;
```

**Explanation:**

1. The function declares a local variable named `total`.
2. `COUNT(*)` calculates the number of employees.
3. `INTO total` stores the result in the variable.
4. `RETURN total` returns the calculated value.

**Important:** Functions that read table data can use characteristics such as `READS SQL DATA`. This declaration describes the routine; it does not automatically enforce that the function only performs reads.

---

# 4. Function With Parameters

A function with parameters accepts input values and returns a result based on those values.

### Syntax

```sql
DELIMITER //

CREATE FUNCTION function_name(
    parameter_name datatype
)
RETURNS return_datatype
DETERMINISTIC
BEGIN

    -- Logic

    RETURN value;

END //

DELIMITER ;
```

### Example 1: Calculate Square of a Number

```sql
DELIMITER //

CREATE FUNCTION calculateSquare(
    num INT
)
RETURNS INT
DETERMINISTIC
BEGIN

    RETURN num * num;

END //

DELIMITER ;
```

Execute:

```sql
SELECT calculateSquare(5) AS square;
```

**Output:**

```text
square
25
```

### Example 2: Calculate Cube of a Number

```sql
DELIMITER //

CREATE FUNCTION calculateCube(
    num INT
)
RETURNS INT
DETERMINISTIC
BEGIN

    RETURN num * num * num;

END //

DELIMITER ;
```

Execute:

```sql
SELECT calculateCube(3) AS cube;
```

**Output:**

```text
cube
27
```

### Example 3: Add Two Numbers

```sql
DELIMITER //

CREATE FUNCTION addNumbers(
    a INT,
    b INT
)
RETURNS INT
DETERMINISTIC
BEGIN

    RETURN a + b;

END //

DELIMITER ;
```

Execute:

```sql
SELECT addNumbers(10, 20) AS result;
```

**Output:**

```text
30
```

### Example 4: Calculate Employee Annual Salary

```sql
DELIMITER //

CREATE FUNCTION annualSalary(
    monthlySalary DECIMAL(10,2)
)
RETURNS DECIMAL(12,2)
DETERMINISTIC
BEGIN

    RETURN monthlySalary * 12;

END //

DELIMITER ;
```

Execute:

```sql
SELECT annualSalary(50000) AS annual_salary;
```

**Output:**

```text
600000.00
```

---

# 5. Function Using Conditional Statements

Functions can use IF, ELSEIF, ELSE, and CASE statements.

### Example 1: Check Even or Odd

```sql
DELIMITER //

CREATE FUNCTION checkEvenOdd(
    num INT
)
RETURNS VARCHAR(20)
DETERMINISTIC
BEGIN

    IF num % 2 = 0 THEN

        RETURN 'Even Number';

    ELSE

        RETURN 'Odd Number';

    END IF;

END //

DELIMITER ;
```

Execute:

```sql
SELECT checkEvenOdd(10);
```

**Output:**

```text
Even Number
```

### Example 2: Find the Largest of Two Numbers

```sql
DELIMITER //

CREATE FUNCTION findLargest(
    a INT,
    b INT
)
RETURNS INT
DETERMINISTIC
BEGIN

    IF a > b THEN

        RETURN a;

    ELSE

        RETURN b;

    END IF;

END //

DELIMITER ;
```

Execute:

```sql
SELECT findLargest(50, 30) AS largest;
```

**Output:**

```text
50
```

### Example 3: Calculate Student Grade

```sql
DELIMITER //

CREATE FUNCTION calculateGrade(
    marks INT
)
RETURNS VARCHAR(20)
DETERMINISTIC
BEGIN

    IF marks >= 90 THEN

        RETURN 'Grade A';

    ELSEIF marks >= 75 THEN

        RETURN 'Grade B';

    ELSEIF marks >= 60 THEN

        RETURN 'Grade C';

    ELSEIF marks >= 40 THEN

        RETURN 'Grade D';

    ELSE

        RETURN 'Fail';

    END IF;

END //

DELIMITER ;
```

Execute:

```sql
SELECT calculateGrade(85) AS grade;
```

**Output:**

```text
Grade B
```

---

# 6. MySQL Built-in Functions

MySQL provides many built-in functions to perform operations on data.

### Categories of Built-in Functions

| Category | Purpose | Examples |
|---|---|---|
| String Functions | Manipulate text | `UPPER()`, `LOWER()` |
| Numeric Functions | Perform calculations | `ROUND()`, `ABS()` |
| Date Functions | Work with dates and time | `NOW()`, `CURDATE()` |
| Aggregate Functions | Calculate values across rows | `SUM()`, `AVG()` |
| Conversion Functions | Convert data types | `CAST()`, `CONVERT()` |
| NULL Functions | Handle NULL values | `IFNULL()`, `COALESCE()` |
| Control Flow Functions | Return values based on conditions | `IF()`, `CASE` |

---

# 7. String Functions

String Functions are used to manipulate and process text values.

## 7.1 UPPER()

Converts a string into uppercase letters.

```sql
SELECT UPPER('anurag') AS result;
```

Output:

```text
ANURAG
```

## 7.2 LOWER()

Converts a string into lowercase letters.

```sql
SELECT LOWER('ANURAG') AS result;
```

Output:

```text
anurag
```

## 7.3 LENGTH()

Returns the length of a string in bytes.

```sql
SELECT LENGTH('Anurag') AS result;
```

Output:

```text
6
```

**Note:** For character count rather than byte count, use `CHAR_LENGTH()`.

```sql
SELECT CHAR_LENGTH('Anurag') AS result;
```

## 7.4 CONCAT()

Combines two or more strings.

```sql
SELECT CONCAT('Hello', ' ', 'Anurag') AS result;
```

Output:

```text
Hello Anurag
```

## 7.5 CONCAT_WS()

Combines strings using a specified separator.

```sql
SELECT CONCAT_WS('-', '2026', '11', '08') AS result;
```

Output:

```text
2026-11-08
```

## 7.6 SUBSTRING()

Extracts a portion of a string.

```sql
SELECT SUBSTRING('DATABASE', 1, 4) AS result;
```

Output:

```text
DATA
```

## 7.7 LEFT()

Returns characters from the left side of a string.

```sql
SELECT LEFT('DATABASE', 4) AS result;
```

Output:

```text
DATA
```

## 7.8 RIGHT()

Returns characters from the right side of a string.

```sql
SELECT RIGHT('DATABASE', 4) AS result;
```

Output:

```text
BASE
```

## 7.9 TRIM()

Removes leading and trailing spaces.

```sql
SELECT TRIM('  Hello  ') AS result;
```

Output:

```text
Hello
```

## 7.10 LTRIM()

Removes leading spaces.

```sql
SELECT LTRIM('  Hello') AS result;
```

Output:

```text
Hello
```

## 7.11 RTRIM()

Removes trailing spaces.

```sql
SELECT RTRIM('Hello  ') AS result;
```

Output:

```text
Hello
```

## 7.12 REPLACE()

Replaces occurrences of a specified substring.

```sql
SELECT REPLACE('Hello World', 'World', 'MySQL') AS result;
```

Output:

```text
Hello MySQL
```

## 7.13 REVERSE()

Reverses a string.

```sql
SELECT REVERSE('MYSQL') AS result;
```

Output:

```text
LQSYM
```

## 7.14 INSTR()

Returns the position of the first occurrence of a substring.

```sql
SELECT INSTR('DATABASE', 'BASE') AS result;
```

Output:

```text
5
```

## 7.15 LOCATE()

Finds the position of a substring in another string.

```sql
SELECT LOCATE('SQL', 'MYSQL DATABASE') AS result;
```

Output:

```text
3
```

### String Functions – Quick Revision

| Function | Purpose |
|---|---|
| `UPPER()` | Converts to uppercase |
| `LOWER()` | Converts to lowercase |
| `LENGTH()` | Returns byte length |
| `CHAR_LENGTH()` | Returns character count |
| `CONCAT()` | Combines strings |
| `CONCAT_WS()` | Combines strings with a separator |
| `SUBSTRING()` | Extracts part of a string |
| `LEFT()` | Returns left-side characters |
| `RIGHT()` | Returns right-side characters |
| `TRIM()` | Removes leading and trailing spaces |
| `LTRIM()` | Removes leading spaces |
| `RTRIM()` | Removes trailing spaces |
| `REPLACE()` | Replaces text |
| `REVERSE()` | Reverses text |
| `INSTR()` | Finds substring position |
| `LOCATE()` | Finds substring position |

---

# 8. Numeric Functions

Numeric Functions are used to perform mathematical operations.

## 8.1 ABS()

Returns the absolute value of a number.

```sql
SELECT ABS(-25) AS result;
```

Output:

```text
25
```

## 8.2 ROUND()

Rounds a number to the specified number of decimal places.

```sql
SELECT ROUND(12.567, 2) AS result;
```

Output:

```text
12.57
```

## 8.3 CEIL() / CEILING()

Returns the smallest integer greater than or equal to the given number.

```sql
SELECT CEIL(12.3) AS result;
```

Output:

```text
13
```

## 8.4 FLOOR()

Returns the largest integer less than or equal to the given number.

```sql
SELECT FLOOR(12.9) AS result;
```

Output:

```text
12
```

## 8.5 MOD()

Returns the remainder after division.

```sql
SELECT MOD(10, 3) AS result;
```

Output:

```text
1
```

## 8.6 POWER()

Returns a number raised to a specified power.

```sql
SELECT POWER(2, 3) AS result;
```

Output:

```text
8
```

## 8.7 SQRT()

Returns the square root of a number.

```sql
SELECT SQRT(64) AS result;
```

Output:

```text
8
```

## 8.8 RAND()

Returns a random floating-point value between 0 and 1.

```sql
SELECT RAND() AS result;
```

The output changes between calls.

## 8.9 TRUNCATE()

Removes decimal places without rounding.

```sql
SELECT TRUNCATE(12.567, 2) AS result;
```

Output:

```text
12.56
```

### Numeric Functions – Quick Revision

| Function | Purpose |
|---|---|
| `ABS()` | Absolute value |
| `ROUND()` | Rounds a number |
| `CEIL()` | Rounds upward |
| `FLOOR()` | Rounds downward |
| `MOD()` | Returns remainder |
| `POWER()` | Calculates exponent |
| `SQRT()` | Calculates square root |
| `RAND()` | Generates random number |
| `TRUNCATE()` | Removes decimal places without rounding |

---

# 9. Date and Time Functions

Date and Time Functions are used to retrieve, calculate, and manipulate dates and times.

## 9.1 NOW()

Returns the current date and time.

```sql
SELECT NOW() AS result;
```

Example output:

```text
2026-11-08 10:30:00
```

## 9.2 CURDATE()

Returns the current date.

```sql
SELECT CURDATE() AS result;
```

Example output:

```text
2026-11-08
```

## 9.3 CURTIME()

Returns the current time.

```sql
SELECT CURTIME() AS result;
```

Example output:

```text
10:30:00
```

## 9.4 CURRENT_TIMESTAMP()

Returns the current date and time.

```sql
SELECT CURRENT_TIMESTAMP();
```

## 9.5 YEAR()

Extracts the year from a date.

```sql
SELECT YEAR('2026-11-08') AS result;
```

Output:

```text
2026
```

## 9.6 MONTH()

Extracts the month number from a date.

```sql
SELECT MONTH('2026-11-08') AS result;
```

Output:

```text
11
```

## 9.7 DAY()

Returns the day of the month.

```sql
SELECT DAY('2026-11-08') AS result;
```

Output:

```text
8
```

## 9.8 DAYNAME()

Returns the weekday name.

```sql
SELECT DAYNAME('2026-11-08') AS result;
```

## 9.9 MONTHNAME()

Returns the month name.

```sql
SELECT MONTHNAME('2026-11-08') AS result;
```

Output:

```text
November
```

## 9.10 DATEDIFF()

Returns the number of days between two dates.

```sql
SELECT DATEDIFF('2026-11-08', '2026-11-01') AS result;
```

Output:

```text
7
```

## 9.11 DATE_ADD()

Adds an interval to a date.

```sql
SELECT DATE_ADD('2026-11-08', INTERVAL 10 DAY) AS result;
```

Output:

```text
2026-11-18
```

## 9.12 DATE_SUB()

Subtracts an interval from a date.

```sql
SELECT DATE_SUB('2026-11-08', INTERVAL 5 DAY) AS result;
```

Output:

```text
2026-11-03
```

## 9.13 LAST_DAY()

Returns the last day of the month.

```sql
SELECT LAST_DAY('2026-11-08') AS result;
```

Output:

```text
2026-11-30
```

## 9.14 DATE_FORMAT()

Formats a date according to the specified format.

```sql
SELECT DATE_FORMAT(
    '2026-11-08',
    '%d-%m-%Y'
) AS result;
```

Output:

```text
08-11-2026
```

### Common Date Format Specifiers

| Format | Meaning |
|---|---|
| `%d` | Day (01–31) |
| `%m` | Month (01–12) |
| `%Y` | Four-digit year |
| `%y` | Two-digit year |
| `%M` | Full month name |
| `%b` | Abbreviated month name |
| `%W` | Weekday name |
| `%H` | Hour (00–23) |
| `%h` | Hour (01–12) |
| `%i` | Minutes |
| `%s` | Seconds |

### Date Functions – Quick Revision

| Function | Purpose |
|---|---|
| `NOW()` | Current date and time |
| `CURDATE()` | Current date |
| `CURTIME()` | Current time |
| `CURRENT_TIMESTAMP()` | Current timestamp |
| `YEAR()` | Extracts year |
| `MONTH()` | Extracts month |
| `DAY()` | Extracts day |
| `DAYNAME()` | Returns weekday name |
| `MONTHNAME()` | Returns month name |
| `DATEDIFF()` | Difference between dates in days |
| `DATE_ADD()` | Adds date interval |
| `DATE_SUB()` | Subtracts date interval |
| `LAST_DAY()` | Returns last day of month |
| `DATE_FORMAT()` | Formats date |

---

# 10. Aggregate Functions

Aggregate Functions perform calculations on multiple rows and return a single result per group.

Common aggregate functions:

- `COUNT()`
- `SUM()`
- `AVG()`
- `MIN()`
- `MAX()`

### Sample Queries

```sql
SELECT COUNT(*) AS total_employees
FROM employees;
```

```sql
SELECT SUM(salary) AS total_salary
FROM employees;
```

```sql
SELECT AVG(salary) AS average_salary
FROM employees;
```

```sql
SELECT MIN(salary) AS minimum_salary
FROM employees;
```

```sql
SELECT MAX(salary) AS maximum_salary
FROM employees;
```

### Important Difference

| Function | Description |
|---|---|
| `COUNT(*)` | Counts all rows |
| `COUNT(column)` | Counts non-NULL values |
| `SUM(column)` | Calculates sum of non-NULL values |
| `AVG(column)` | Calculates average of non-NULL values |
| `MIN(column)` | Finds minimum non-NULL value |
| `MAX(column)` | Finds maximum non-NULL value |

---

# 11. NULL Handling Functions

NULL represents a missing or unknown value.

MySQL provides functions to handle NULL values.

## 11.1 IFNULL()

Returns an alternative value when the expression is NULL.

```sql
SELECT IFNULL(NULL, 100) AS result;
```

Output:

```text
100
```

Example:

```sql
SELECT
    employee_name,
    IFNULL(bonus, 0) AS bonus
FROM employees;
```

This requires a `bonus` column in the table.

## 11.2 COALESCE()

Returns the first non-NULL value from a list of expressions.

```sql
SELECT COALESCE(NULL, NULL, 50, 100) AS result;
```

Output:

```text
50
```

## 11.3 NULLIF()

Returns NULL if two expressions are equal; otherwise, returns the first expression.

```sql
SELECT NULLIF(10, 10) AS result;
```

Output:

```text
NULL
```

Another example:

```sql
SELECT NULLIF(10, 20) AS result;
```

Output:

```text
10
```

### Difference Between NULL Functions

| Function | Purpose |
|---|---|
| `IFNULL(a,b)` | Returns b if a is NULL |
| `COALESCE(a,b,c)` | Returns first non-NULL value |
| `NULLIF(a,b)` | Returns NULL if a equals b |

---

# 12. Type Conversion Functions

Type Conversion Functions convert values from one data type to another.

## 12.1 CAST()

Converts an expression into a specified data type.

```sql
SELECT CAST('100' AS UNSIGNED) AS result;
```

Output:

```text
100
```

## 12.2 CONVERT()

Converts an expression into a specified data type.

```sql
SELECT CONVERT('2026-11-08', DATE) AS result;
```

Output:

```text
2026-11-08
```

### Difference Between CAST() and CONVERT()

Both functions perform type conversion in MySQL.

```sql
SELECT CAST('123' AS SIGNED);
```

```sql
SELECT CONVERT('123', SIGNED);
```

---

# 13. Built-in Functions with Employee Table

Consider the following sample table:

```sql
CREATE TABLE employees (
    emp_id INT PRIMARY KEY,
    employee_name VARCHAR(50),
    department VARCHAR(30),
    salary DECIMAL(10,2),
    joining_date DATE
);
```

Insert sample data:

```sql
INSERT INTO employees VALUES
(1, 'Anurag', 'IT', 60000, '2025-01-15'),
(2, 'Rahul', 'IT', 50000, '2024-05-10'),
(3, 'Amit', 'HR', 45000, '2025-06-20'),
(4, 'Sneha', 'HR', 55000, '2023-03-12'),
(5, 'Karan', 'Finance', 70000, '2022-09-01');
```

## Example 1: Display Employee Names in Uppercase

```sql
SELECT
    UPPER(employee_name) AS employee_name
FROM employees;
```

## Example 2: Display Employee Name and Name Length

```sql
SELECT
    employee_name,
    CHAR_LENGTH(employee_name) AS name_length
FROM employees;
```

## Example 3: Display Annual Salary

```sql
SELECT
    employee_name,
    salary,
    salary * 12 AS annual_salary
FROM employees;
```

## Example 4: Display Joining Year

```sql
SELECT
    employee_name,
    YEAR(joining_date) AS joining_year
FROM employees;
```

## Example 5: Display Employees Who Joined in 2025

```sql
SELECT *
FROM employees
WHERE YEAR(joining_date) = 2025;
```

## Example 6: Display Current Date with Employee Name

```sql
SELECT
    employee_name,
    CURDATE() AS current_date
FROM employees;
```

## Example 7: Calculate Days Since Joining

```sql
SELECT
    employee_name,
    DATEDIFF(CURDATE(), joining_date) AS days_since_joining
FROM employees;
```

## Example 8: Round Employee Salary

```sql
SELECT
    employee_name,
    ROUND(salary / 12, 2) AS monthly_value
FROM employees;
```

## Example 9: Combine Employee Name and Department

```sql
SELECT
    CONCAT(employee_name, ' - ', department) AS employee_details
FROM employees;
```

## Example 10: Display Department-wise Average Salary

```sql
SELECT
    department,
    ROUND(AVG(salary), 2) AS average_salary
FROM employees
GROUP BY department;
```

---

# 14. Managing Stored Functions

## 14.1 Display Functions

```sql
SHOW FUNCTION STATUS;
```

For a specific database:

```sql
SHOW FUNCTION STATUS
WHERE Db = 'company';
```

## 14.2 Display Function Definition

```sql
SHOW CREATE FUNCTION calculateSquare;
```

## 14.3 Drop a Function

```sql
DROP FUNCTION calculateSquare;
```

## 14.4 Drop Function If Exists

```sql
DROP FUNCTION IF EXISTS calculateSquare;
```

**Important:** To modify a stored function, drop and recreate it with the updated definition.

---

# 15. Stored Procedure vs Stored Function

| Stored Procedure | Stored Function |
|---|---|
| Created using `CREATE PROCEDURE` | Created using `CREATE FUNCTION` |
| Called using `CALL` | Used in SQL expressions |
| Does not require a return value | Must return a value |
| Supports IN, OUT and INOUT | Uses input parameters |
| Can return result sets | Returns a single value |
| Used for database operations | Used for calculations and returning values |

---

# 16. Complete Lab Practicals

## Practical 1: Create a Function Without Parameters

```sql
DELIMITER //

CREATE FUNCTION getCollegeName()
RETURNS VARCHAR(50)
DETERMINISTIC
BEGIN

    RETURN 'PES Modern College';

END //

DELIMITER ;

SELECT getCollegeName();
```

## Practical 2: Function with One Parameter

```sql
DELIMITER //

CREATE FUNCTION squareNumber(
    num INT
)
RETURNS INT
DETERMINISTIC
BEGIN

    RETURN num * num;

END //

DELIMITER ;

SELECT squareNumber(8);
```

## Practical 3: Function with Multiple Parameters

```sql
DELIMITER //

CREATE FUNCTION multiplyNumbers(
    a INT,
    b INT
)
RETURNS INT
DETERMINISTIC
BEGIN

    RETURN a * b;

END //

DELIMITER ;

SELECT multiplyNumbers(5, 4);
```

## Practical 4: Function Using IF-ELSE

```sql
DELIMITER //

CREATE FUNCTION positiveNegative(
    num INT
)
RETURNS VARCHAR(20)
DETERMINISTIC
BEGIN

    IF num > 0 THEN
        RETURN 'Positive';

    ELSEIF num < 0 THEN
        RETURN 'Negative';

    ELSE
        RETURN 'Zero';

    END IF;

END //

DELIMITER ;

SELECT positiveNegative(-5);
```

## Practical 5: Function to Calculate Factorial

```sql
DELIMITER //

CREATE FUNCTION factorialNumber(
    num INT
)
RETURNS BIGINT
DETERMINISTIC
BEGIN

    DECLARE i INT DEFAULT 1;
    DECLARE result BIGINT DEFAULT 1;

    WHILE i <= num DO

        SET result = result * i;

        SET i = i + 1;

    END WHILE;

    RETURN result;

END //

DELIMITER ;

SELECT factorialNumber(5);
```

Expected output:

```text
120
```

**Note:** This example assumes a non-negative input and a result that fits in BIGINT.

## Practical 6: String Function Queries

```sql
SELECT UPPER('anurag');

SELECT LOWER('ANURAG');

SELECT LENGTH('DATABASE');

SELECT CHAR_LENGTH('DATABASE');

SELECT CONCAT('Hello', ' ', 'World');

SELECT REVERSE('MYSQL');

SELECT SUBSTRING('DATABASE', 1, 4);

SELECT REPLACE('Hello World', 'World', 'MySQL');
```

## Practical 7: Numeric Function Queries

```sql
SELECT ABS(-100);

SELECT ROUND(12.567, 2);

SELECT CEIL(12.3);

SELECT FLOOR(12.9);

SELECT MOD(10, 3);

SELECT POWER(2, 3);

SELECT SQRT(81);

SELECT TRUNCATE(12.567, 2);
```

## Practical 8: Date Function Queries

```sql
SELECT NOW();

SELECT CURDATE();

SELECT CURTIME();

SELECT YEAR(CURDATE());

SELECT MONTH(CURDATE());

SELECT DAY(CURDATE());

SELECT DAYNAME(CURDATE());

SELECT MONTHNAME(CURDATE());

SELECT DATE_ADD(CURDATE(), INTERVAL 10 DAY);

SELECT DATE_SUB(CURDATE(), INTERVAL 5 DAY);

SELECT LAST_DAY(CURDATE());
```

## Practical 9: Aggregate Function Queries

```sql
SELECT COUNT(*) FROM employees;

SELECT SUM(salary) FROM employees;

SELECT AVG(salary) FROM employees;

SELECT MAX(salary) FROM employees;

SELECT MIN(salary) FROM employees;
```

## Practical 10: NULL Handling Functions

```sql
SELECT IFNULL(NULL, 100);

SELECT COALESCE(NULL, NULL, 50, 100);

SELECT NULLIF(10, 10);

SELECT NULLIF(10, 20);
```

## Practical 11: Type Conversion Queries

```sql
SELECT CAST('100' AS UNSIGNED);

SELECT CAST('123.45' AS DECIMAL(10,2));

SELECT CONVERT('2026-11-08', DATE);
```

---

# 17. Important Interview Questions

**Q1. What is a Function in MySQL?**

A function is a database routine that performs an operation and returns a value.

**Q2. What are the types of MySQL Functions?**

Built-in Functions and User-Defined Functions.

**Q3. What is a User-Defined Function?**

A function created by a user using `CREATE FUNCTION`.

**Q4. Which command is used to create a function?**

`CREATE FUNCTION`.

**Q5. Which keyword is used to return a value?**

`RETURN`.

**Q6. What is the purpose of RETURNS?**

It specifies the data type of the value returned by a function.

**Q7. Can a function have parameters?**

Yes. A function can accept one or multiple input parameters.

**Q8. Can a function be created without parameters?**

Yes. A function can perform an operation without accepting input values.

**Q9. What is a DETERMINISTIC function?**

A function that returns the same result for the same input values.

**Q10. What is a non-deterministic function?**

A function whose result may change even when its input values remain the same.

**Q11. What is the difference between NOW() and CURDATE()?**

`NOW()` returns the current date and time, whereas `CURDATE()` returns only the current date.

**Q12. What is the difference between LENGTH() and CHAR_LENGTH()?**

`LENGTH()` returns the number of bytes, whereas `CHAR_LENGTH()` returns the number of characters.

**Q13. What is the difference between ROUND() and TRUNCATE()?**

`ROUND()` rounds a number, whereas `TRUNCATE()` removes decimal places without rounding.

**Q14. What is CONCAT()?**

It combines multiple strings into one string.

**Q15. What is DATEDIFF()?**

It returns the difference between two dates in days.

**Q16. What is DATE_ADD()?**

It adds a specified interval to a date.

**Q17. What is IFNULL()?**

It returns an alternative value if the given expression is NULL.

**Q18. What is COALESCE()?**

It returns the first non-NULL expression from a list.

**Q19. What is the difference between Stored Procedure and Stored Function?**

A procedure is called using `CALL` and can return result sets, while a function returns a value and can be used inside SQL expressions.

**Q20. Can we use a function inside a SELECT statement?**

Yes. Stored functions and built-in functions can be used inside SELECT expressions.

---

# 18. Self-Learning Practice Checklist

### User-Defined Functions

- [ ] Create a function without parameters.
- [ ] Create a function with one parameter.
- [ ] Create a function with multiple parameters.
- [ ] Create a function to calculate square.
- [ ] Create a function to calculate cube.
- [ ] Create a function to add two numbers.
- [ ] Create a function to find the largest of two numbers.
- [ ] Create a function to check even or odd.
- [ ] Create a function to calculate factorial.
- [ ] Create a function to calculate student grades.
- [ ] Create a function to calculate annual salary.
- [ ] Create a function to count employees.

### String Functions

- [ ] Convert a string to uppercase.
- [ ] Convert a string to lowercase.
- [ ] Find the length of a string.
- [ ] Combine first name and last name.
- [ ] Extract the first four characters.
- [ ] Reverse a string.
- [ ] Replace a word in a sentence.
- [ ] Remove leading and trailing spaces.

### Numeric Functions

- [ ] Find the absolute value of a number.
- [ ] Round a decimal number.
- [ ] Find ceiling and floor values.
- [ ] Calculate the remainder.
- [ ] Calculate power and square root.
- [ ] Generate a random number.

### Date Functions

- [ ] Display current date and time.
- [ ] Extract year, month and day.
- [ ] Find weekday and month names.
- [ ] Calculate the difference between two dates.
- [ ] Add 10 days to the current date.
- [ ] Subtract 5 days from the current date.
- [ ] Find the last day of a month.
- [ ] Format dates using DATE_FORMAT().

### Other Functions

- [ ] Practise aggregate functions.
- [ ] Practise IFNULL(), COALESCE() and NULLIF().
- [ ] Practise CAST() and CONVERT().
- [ ] Display stored functions using SHOW FUNCTION STATUS.
- [ ] Display function definition using SHOW CREATE FUNCTION.
- [ ] Drop an existing stored function.

---

# 19. Quick Revision – Important Points

1. A function performs an operation and returns a value.
2. MySQL provides built-in and user-defined functions.
3. `CREATE FUNCTION` creates a stored function.
4. `RETURNS` defines the return data type.
5. `RETURN` sends the result to the caller.
6. Functions can have parameters or no parameters.
7. Functions can use IF, CASE, and loops.
8. `UPPER()` converts text to uppercase.
9. `LOWER()` converts text to lowercase.
10. `CONCAT()` combines strings.
11. `SUBSTRING()` extracts part of a string.
12. `LENGTH()` returns byte length.
13. `CHAR_LENGTH()` returns character count.
14. `ROUND()` rounds a number.
15. `ABS()` returns absolute value.
16. `MOD()` returns the remainder.
17. `NOW()` returns current date and time.
18. `CURDATE()` returns current date.
19. `DATEDIFF()` calculates the difference between dates in days.
20. `DATE_ADD()` adds an interval to a date.
21. `IFNULL()` handles NULL values.
22. `COALESCE()` returns the first non-NULL value.
23. `CAST()` and `CONVERT()` perform type conversion.
24. Aggregate functions include SUM, AVG, COUNT, MIN and MAX.
25. Stored functions are called using SELECT or other SQL expressions.

---

# 20. Learning Resources

- [MySQL Built-in Functions and Operators](https://dev.mysql.com/doc/refman/8.0/en/functions.html)
- [MySQL String Functions](https://dev.mysql.com/doc/refman/8.0/en/string-functions.html)
- [MySQL Numeric Functions](https://dev.mysql.com/doc/refman/8.0/en/numeric-functions.html)
- [MySQL Date and Time Functions](https://dev.mysql.com/doc/refman/8.0/en/date-and-time-functions.html)
- [MySQL Aggregate Functions](https://dev.mysql.com/doc/refman/8.0/en/aggregate-functions.html)
- [MySQL Flow Control Functions](https://dev.mysql.com/doc/refman/8.0/en/flow-control-functions.html)
- [MySQL CREATE FUNCTION](https://dev.mysql.com/doc/refman/8.0/en/create-procedure.html)

---

**Happy Learning! 🚀**

*Prepared for CMCE – August 2026 Batch | Database Technologies*
