# Session 5: Data Types, Constraints and Aggregate Functions

## Database Technologies | PGCP-AC | CMCE | August 2026

**Institute:** ACTS, Pune  
**Course:** PGCP-AC  
**Subject:** Database Technologies  
**Session:** 05 – Data Types, Constraints and Aggregate Functions  
**Duration:** 2 Theory + 2 Lab + 2 Self Learning Hours

---

## Table of Contents

1. [Introduction to MySQL Data Types](#1-introduction-to-mysql-data-types)
2. [MySQL Data Types](#2-mysql-data-types)
3. [Database Constraints](#3-database-constraints)
4. [Creating, Altering and Dropping Constraints](#4-creating-altering-and-dropping-constraints)
5. [Aggregate Functions](#5-aggregate-functions)
6. [GROUP BY Clause](#6-group-by-clause)
7. [HAVING Clause](#7-having-clause)
8. [LIKE Operator](#8-like-operator)
9. [DISTINCT Keyword](#9-distinct-keyword)
10. [ORDER BY Clause](#10-order-by-clause)
11. [BETWEEN AND Operator](#11-between-and-operator)
12. [Comparing NULL Values](#12-comparing-null-values)
13. [IN and NOT IN Operators](#13-in-and-not-in-operators)
14. [WHERE vs HAVING](#14-where-vs-having)
15. [Complete SQL Lab Practicals](#15-complete-sql-lab-practicals)
16. [Important Interview Questions](#16-important-interview-questions)
17. [Important MCQs](#17-important-mcqs)
18. [Quick Revision](#18-quick-revision)
19. [Practice Checklist](#19-practice-checklist)

---

# 1. Introduction to MySQL Data Types

### What are Data Types?

A data type defines the kind of value that can be stored in a database column.

It specifies:
- Type of data.
- Storage requirements.
- Valid range of values.
- Operations that can be performed on the values.

### Why Are Data Types Important?

1. Maintain data accuracy.
2. Prevent invalid values.
3. Optimize storage.
4. Improve query performance.
5. Support calculations and comparisons.
6. Maintain data integrity.

**Example:**

```sql
CREATE TABLE student (
    student_id INT,
    name VARCHAR(50),
    age INT,
    fees DECIMAL(10,2),
    admission_date DATE
);
```

Here:
- student_id → INT
- name → VARCHAR
- age → INT
- fees → DECIMAL
- admission_date → DATE

---

# 2. MySQL Data Types

MySQL data types are mainly classified into the following categories:

1. Numeric Data Types
2. String Data Types
3. Date and Time Data Types
4. Boolean Type
5. Binary Data Types
6. Spatial Data Types
7. JSON Data Type

## 2.1 Numeric Data Types

Numeric data types are used to store numbers.

| Data Type | Description | Example |
|---|---|---|
| TINYINT | Very small integer | 100 |
| SMALLINT | Small integer | 1000 |
| MEDIUMINT | Medium integer | 100000 |
| INT / INTEGER | Standard integer | 50000 |
| BIGINT | Large integer | 9876543210 |
| FLOAT | Approximate decimal number | 12.5 |
| DOUBLE | Double-precision approximate number | 123.456 |
| DECIMAL(M,D) | Exact decimal number | 1250.50 |

### INT

Used to store whole numbers.

```sql
age INT;
```

Example:

```sql
CREATE TABLE student (
    id INT,
    age INT
);
```

### FLOAT

Used to store approximate floating-point values.

```sql
temperature FLOAT;
```

### DOUBLE

Stores approximate floating-point values with greater precision than FLOAT.

```sql
distance DOUBLE;
```

### DECIMAL

Used to store exact decimal values, especially financial amounts.

Syntax:

```sql
DECIMAL(M,D)
```

Where:
- M = Maximum total number of digits.
- D = Number of digits after the decimal point.

Example:

```sql
salary DECIMAL(10,2);
```

It can store values such as:

```text
125000.50
```

**Important:** Prefer DECIMAL for money because FLOAT and DOUBLE store approximate values.

## 2.2 String Data Types

Used to store text, characters and binary data.

| Data Type | Description |
|---|---|
| CHAR(n) | Fixed-length string |
| VARCHAR(n) | Variable-length string |
| TINYTEXT | Small text |
| TEXT | Text data |
| MEDIUMTEXT | Medium-sized text |
| LONGTEXT | Large text |

### CHAR

CHAR stores fixed-length strings.

```sql
gender CHAR(1);
```

Example:

```text
'M'
'F'
```

If the declared length is 10 and the value is 'ABC', MySQL generally pads the stored value to the fixed length, although trailing-space retrieval behavior depends on SQL mode and settings.

### VARCHAR

VARCHAR stores variable-length strings.

```sql
name VARCHAR(50);
```

Example:

```text
'Anurag'
'Rahul'
'Priya'
```

### CHAR vs VARCHAR

| Feature | CHAR | VARCHAR |
|---|---|---|
| Length | Fixed | Variable |
| Storage | Fixed-length allocation | Variable-length |
| Best For | Fixed-size values | Variable-size values |
| Example | Gender code | Student name |

### TEXT

TEXT is used for larger text values.

Example:

```sql
description TEXT;
```

## 2.3 Date and Time Data Types

Used to store dates and time values.

| Data Type | Description | Example |
|---|---|---|
| DATE | Stores date | 2026-11-08 |
| TIME | Stores time | 10:30:00 |
| DATETIME | Stores date and time | 2026-11-08 10:30:00 |
| TIMESTAMP | Stores timestamp | 2026-11-08 10:30:00 |
| YEAR | Stores year | 2026 |

### DATE

```sql
dob DATE;
```

Format:

```text
YYYY-MM-DD
```

### TIME

```sql
start_time TIME;
```

### DATETIME

```sql
created_at DATETIME;
```

### TIMESTAMP

```sql
updated_at TIMESTAMP;
```

### DATE vs DATETIME vs TIMESTAMP

| Feature | DATE | DATETIME | TIMESTAMP |
|---|---|---|---|
| Stores Date | Yes | Yes | Yes |
| Stores Time | No | Yes | Yes |
| Time Zone Conversion | No | No | Yes, session time-zone based |
| Typical Use | Birth date | Event date and time | Creation/update timestamps |

**Important:** MySQL TIMESTAMP has a narrower supported range than DATETIME.

## 2.4 Boolean Data Type

MySQL supports BOOLEAN and BOOL as aliases for TINYINT(1).

```sql
is_active BOOLEAN;
```

Commonly:
- 0 = FALSE
- 1 = TRUE

Example:

```sql
CREATE TABLE users (
    user_id INT,
    is_active BOOLEAN
);
```

## 2.5 Binary Data Types

Used to store binary information.

| Data Type | Description |
|---|---|
| BINARY | Fixed-length binary data |
| VARBINARY | Variable-length binary data |
| TINYBLOB | Small binary object |
| BLOB | Binary large object |
| MEDIUMBLOB | Medium binary object |
| LONGBLOB | Large binary object |

Example:

```sql
profile_image BLOB;
```

## 2.6 JSON Data Type

MySQL supports JSON for storing JSON documents.

Example:

```sql
CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50),
    details JSON
);
```

Insert JSON:

```sql
INSERT INTO employee
VALUES (
    1,
    'Anurag',
    '{"city":"Pune","skill":"Java"}'
);
```

Retrieve a JSON property:

```sql
SELECT
    emp_name,
    details->>'$.city' AS city
FROM employee;
```

---

# 3. Database Constraints

### What are Constraints?

Constraints are rules applied to database columns or tables to maintain data accuracy, validity and integrity.

### Types of Constraints

1. PRIMARY KEY
2. UNIQUE
3. NOT NULL
4. FOREIGN KEY
5. DEFAULT
6. CHECK

## 3.1 PRIMARY KEY

A PRIMARY KEY uniquely identifies every record in a table.

### Properties

- Cannot contain NULL values.
- Cannot contain duplicate values.
- A table has one primary key constraint.
- A primary key can consist of multiple columns.

Example:

```sql
CREATE TABLE student (
    student_id INT PRIMARY KEY,
    name VARCHAR(50)
);
```

### Composite Primary Key

A primary key consisting of multiple columns is called a composite primary key.

```sql
CREATE TABLE enrollment (
    student_id INT,
    course_id INT,
    enrollment_date DATE,
    PRIMARY KEY (student_id, course_id)
);
```

## 3.2 UNIQUE Constraint

The UNIQUE constraint ensures that duplicate values are not allowed in a column or combination of columns.

Example:

```sql
CREATE TABLE student (
    student_id INT PRIMARY KEY,
    email VARCHAR(100) UNIQUE
);
```

Multiple NULL values may be allowed in a UNIQUE column in MySQL.

### PRIMARY KEY vs UNIQUE

| Feature | PRIMARY KEY | UNIQUE |
|---|---|---|
| Duplicate Values | Not Allowed | Not Allowed |
| NULL Values | Not Allowed | Allowed |
| Number per Table | One constraint | Multiple constraints |
| Purpose | Unique identification | Uniqueness |

## 3.3 NOT NULL Constraint

NOT NULL ensures that a column cannot store NULL values.

Example:

```sql
CREATE TABLE student (
    student_id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL
);
```

This prevents inserting a student without a name.

## 3.4 FOREIGN KEY Constraint

A FOREIGN KEY establishes a relationship between two tables.

It maintains referential integrity.

Example:

```sql
CREATE TABLE department (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50)
);

CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50),
    dept_id INT,
    FOREIGN KEY (dept_id)
        REFERENCES department(dept_id)
);
```

Here:
- department.dept_id is the PRIMARY KEY.
- employee.dept_id is the FOREIGN KEY.

### ON DELETE CASCADE

When a referenced parent record is deleted, corresponding child records are automatically deleted.

```sql
CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50),
    dept_id INT,
    FOREIGN KEY (dept_id)
        REFERENCES department(dept_id)
        ON DELETE CASCADE
);
```

### ON UPDATE CASCADE

When a referenced parent key is updated, the corresponding foreign key values are automatically updated.

```sql
FOREIGN KEY (dept_id)
REFERENCES department(dept_id)
ON UPDATE CASCADE
```

Other referential actions include RESTRICT, NO ACTION and SET NULL, subject to the foreign key column definition.

## 3.5 DEFAULT Constraint

DEFAULT provides an automatic value when no value is supplied for a column.

Example:

```sql
CREATE TABLE student (
    student_id INT PRIMARY KEY,
    name VARCHAR(50),
    city VARCHAR(50) DEFAULT 'Pune'
);
```

Insert:

```sql
INSERT INTO student (student_id, name)
VALUES (101, 'Anurag');
```

The city automatically becomes Pune.

## 3.6 CHECK Constraint

CHECK validates whether a value satisfies a specified condition.

Example:

```sql
CREATE TABLE student (
    student_id INT PRIMARY KEY,
    name VARCHAR(50),
    age INT CHECK (age >= 18)
);
```

Now age must be at least 18.

**Important:** MySQL 8.0.16 and later versions enforce CHECK constraints. Earlier versions parsed but ignored CHECK constraints.

---

# 4. Creating, Altering and Dropping Constraints

## 4.1 Create Constraints

Constraints can be defined while creating a table.

```sql
CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    salary DECIMAL(10,2) CHECK (salary > 0),
    city VARCHAR(50) DEFAULT 'Pune'
);
```

## 4.2 Add Constraint Using ALTER

### Add PRIMARY KEY

```sql
ALTER TABLE employee
ADD PRIMARY KEY (emp_id);
```

### Add UNIQUE

```sql
ALTER TABLE employee
ADD CONSTRAINT uq_email UNIQUE (email);
```

### Add CHECK

```sql
ALTER TABLE employee
ADD CONSTRAINT chk_salary
CHECK (salary > 0);
```

### Add FOREIGN KEY

```sql
ALTER TABLE employee
ADD CONSTRAINT fk_department
FOREIGN KEY (dept_id)
REFERENCES department(dept_id);
```

### Add NOT NULL

```sql
ALTER TABLE employee
MODIFY name VARCHAR(50) NOT NULL;
```

### Add DEFAULT

```sql
ALTER TABLE employee
ALTER city SET DEFAULT 'Pune';
```

## 4.3 Drop Constraints

### Drop PRIMARY KEY

```sql
ALTER TABLE employee
DROP PRIMARY KEY;
```

### Drop UNIQUE

```sql
ALTER TABLE employee
DROP INDEX uq_email;
```

### Drop FOREIGN KEY

```sql
ALTER TABLE employee
DROP FOREIGN KEY fk_department;
```

### Drop CHECK

```sql
ALTER TABLE employee
DROP CHECK chk_salary;
```

### Remove DEFAULT

```sql
ALTER TABLE employee
ALTER city DROP DEFAULT;
```

### Remove NOT NULL

```sql
ALTER TABLE employee
MODIFY name VARCHAR(50) NULL;
```

**Note:** Constraint names and existing dependencies must be checked before dropping constraints.

---

# 5. Aggregate Functions

### What are Aggregate Functions?

Aggregate functions perform calculations on a group of rows and return a single result.

They are commonly used for data analysis and reporting.

Important aggregate functions:

1. SUM()
2. AVG()
3. COUNT()
4. MAX()
5. MIN()

Consider the following Employee table:

| emp_id | name | department | salary |
|---|---|---|---:|
| 1 | Anurag | IT | 50000 |
| 2 | Rahul | HR | 40000 |
| 3 | Amit | IT | 60000 |
| 4 | Sneha | HR | 45000 |
| 5 | Priya | Sales | 55000 |

## 5.1 SUM()

SUM() calculates the total of numeric values.

```sql
SELECT SUM(salary)
FROM employee;
```

Output:

```text
250000
```

## 5.2 AVG()

AVG() calculates the average of numeric values.

```sql
SELECT AVG(salary)
FROM employee;
```

Output:

```text
50000
```

## 5.3 COUNT()

COUNT() returns the number of rows or non-NULL values.

### Count All Rows

```sql
SELECT COUNT(*)
FROM employee;
```

Output:

```text
5
```

### Count Non-NULL Values

```sql
SELECT COUNT(department)
FROM employee;
```

Counts rows where department is not NULL.

### Count Distinct Values

```sql
SELECT COUNT(DISTINCT department)
FROM employee;
```

Output:

```text
3
```

## 5.4 MAX()

MAX() returns the highest value.

```sql
SELECT MAX(salary)
FROM employee;
```

Output:

```text
60000
```

## 5.5 MIN()

MIN() returns the lowest value.

```sql
SELECT MIN(salary)
FROM employee;
```

Output:

```text
40000
```

### Aggregate Functions Summary

| Function | Purpose |
|---|---|
| SUM() | Calculates total |
| AVG() | Calculates average |
| COUNT() | Counts rows or non-NULL values |
| MAX() | Finds maximum value |
| MIN() | Finds minimum value |

### Important Points

- Aggregate functions generally ignore NULL values.
- COUNT(*) counts all rows.
- COUNT(column) ignores NULL values.
- SUM() and AVG() work with numeric expressions.
- COUNT(DISTINCT column) counts unique non-NULL values.

---

# 6. GROUP BY Clause

### What is GROUP BY?

GROUP BY is used to arrange rows into groups based on one or more columns.

It is commonly used with aggregate functions.

### Syntax

```sql
SELECT column_name, AGGREGATE_FUNCTION(column_name)
FROM table_name
GROUP BY column_name;
```

### Example: Department-wise Employee Count

```sql
SELECT department, COUNT(*)
FROM employee
GROUP BY department;
```

Output:

| department | COUNT(*) |
|---|---:|
| HR | 2 |
| IT | 2 |
| Sales | 1 |

### Example: Department-wise Total Salary

```sql
SELECT department, SUM(salary)
FROM employee
GROUP BY department;
```

Output:

| department | SUM(salary) |
|---|---:|
| HR | 85000 |
| IT | 110000 |
| Sales | 55000 |

### GROUP BY Multiple Columns

```sql
SELECT department, city, COUNT(*)
FROM employee
GROUP BY department, city;
```

This groups records using both department and city.

**Important:** In MySQL with ONLY_FULL_GROUP_BY enabled, non-aggregated selected columns generally must be included in GROUP BY or be functionally dependent on grouped columns.

---

# 7. HAVING Clause

### What is HAVING?

HAVING is used to filter groups created by GROUP BY.

It is generally used with aggregate functions.

### Syntax

```sql
SELECT column_name, AGGREGATE_FUNCTION(column_name)
FROM table_name
GROUP BY column_name
HAVING condition;
```

### Example: Departments Having More Than One Employee

```sql
SELECT department, COUNT(*)
FROM employee
GROUP BY department
HAVING COUNT(*) > 1;
```

Output:

| department | COUNT(*) |
|---|---:|
| HR | 2 |
| IT | 2 |

### Example: Departments Having Total Salary Greater Than 80000

```sql
SELECT department, SUM(salary)
FROM employee
GROUP BY department
HAVING SUM(salary) > 80000;
```

Output:

| department | SUM(salary) |
|---|---:|
| HR | 85000 |
| IT | 110000 |

---

# 8. LIKE Operator

### What is LIKE?

LIKE is used to search for a specific pattern in a string column.

It is commonly used with the WHERE clause.

Two important wildcard characters:

| Wildcard | Meaning |
|---|---|
| % | Matches zero or more characters |
| _ | Matches exactly one character |

## 8.1 Names Starting With A

```sql
SELECT * FROM employee
WHERE name LIKE 'A%';
```

Matches:
- Anurag
- Amit

## 8.2 Names Ending With A

```sql
SELECT * FROM employee
WHERE name LIKE '%a';
```

## 8.3 Names Containing A

```sql
SELECT * FROM employee
WHERE name LIKE '%a%';
```

## 8.4 Names Having Exactly Five Characters

```sql
SELECT * FROM employee
WHERE name LIKE '_____';
```

Each underscore represents exactly one character.

## 8.5 Names Having A as Second Character

```sql
SELECT * FROM employee
WHERE name LIKE '_a%';
```

**Important:** Case sensitivity of LIKE depends on the column collation and comparison settings.

---

# 9. DISTINCT Keyword

### What is DISTINCT?

DISTINCT is used to retrieve unique values by eliminating duplicate rows from the result.

### Syntax

```sql
SELECT DISTINCT column_name
FROM table_name;
```

### Example

```sql
SELECT DISTINCT department
FROM employee;
```

Output:

| department |
|---|
| IT |
| HR |
| Sales |

### DISTINCT on Multiple Columns

```sql
SELECT DISTINCT department, city
FROM employee;
```

This returns unique combinations of department and city.

### COUNT with DISTINCT

```sql
SELECT COUNT(DISTINCT department)
FROM employee;
```

Output:

```text
3
```

---

# 10. ORDER BY Clause

### What is ORDER BY?

ORDER BY is used to sort query results in ascending or descending order.

### Syntax

```sql
SELECT column_name
FROM table_name
ORDER BY column_name ASC;
```

Two sorting options:

- ASC = Ascending order.
- DESC = Descending order.

### Sort Salary in Ascending Order

```sql
SELECT * FROM employee
ORDER BY salary ASC;
```

### Sort Salary in Descending Order

```sql
SELECT * FROM employee
ORDER BY salary DESC;
```

### Sort Using Multiple Columns

```sql
SELECT * FROM employee
ORDER BY department ASC, salary DESC;
```

First sorts by department, then sorts salary in descending order within each department.

### ORDER BY with LIMIT

```sql
SELECT * FROM employee
ORDER BY salary DESC
LIMIT 3;
```

Returns the three highest-paid employees.

---

# 11. BETWEEN AND Operator

### What is BETWEEN?

BETWEEN is used to select values within a specified range.

It includes both boundary values.

### Syntax

```sql
SELECT *
FROM table_name
WHERE column_name BETWEEN value1 AND value2;
```

### Example: Salary Between 40000 and 55000

```sql
SELECT * FROM employee
WHERE salary BETWEEN 40000 AND 55000;
```

This includes salaries of 40000 and 55000.

### NOT BETWEEN

```sql
SELECT * FROM employee
WHERE salary NOT BETWEEN 40000 AND 55000;
```

Returns salaries outside the specified range.

### BETWEEN with Dates

```sql
SELECT * FROM employee
WHERE joining_date BETWEEN '2025-01-01'
AND '2025-12-31';
```

**Important:** BETWEEN is inclusive of both endpoints.

---

# 12. Comparing NULL Values

### What is NULL?

NULL represents missing, unknown or unavailable information in a database.

NULL is different from:
- Zero (0).
- Empty string ('').
- Space (' ').

### Incorrect NULL Comparison

```sql
SELECT * FROM employee
WHERE department = NULL;
```

This does not correctly identify NULL values.

### IS NULL

Used to retrieve records where a column contains NULL.

```sql
SELECT * FROM employee
WHERE department IS NULL;
```

### IS NOT NULL

Used to retrieve records where a column does not contain NULL.

```sql
SELECT * FROM employee
WHERE department IS NOT NULL;
```

### COALESCE()

COALESCE() returns the first non-NULL value from a list of expressions.

```sql
SELECT
    name,
    COALESCE(department, 'Not Assigned')
FROM employee;
```

### Important Points

- NULL is not equal to zero.
- NULL is not equal to an empty string.
- Use IS NULL to check NULL values.
- Use IS NOT NULL to check non-NULL values.
- Comparisons such as NULL = NULL produce UNKNOWN, not TRUE.

---

# 13. IN and NOT IN Operators

## 13.1 IN Operator

IN is used to check whether a value matches any value in a specified list.

### Syntax

```sql
SELECT *
FROM table_name
WHERE column_name IN (value1, value2, value3);
```

### Example

```sql
SELECT * FROM employee
WHERE department IN ('IT', 'HR');
```

Returns employees belonging to IT or HR.

### IN with Numeric Values

```sql
SELECT * FROM employee
WHERE salary IN (40000, 50000, 60000);
```

## 13.2 NOT IN Operator

NOT IN returns records whose values do not match any value in the specified list.

### Example

```sql
SELECT * FROM employee
WHERE department NOT IN ('IT', 'HR');
```

Returns employees who do not belong to IT or HR.

### IN with Subquery

```sql
SELECT *
FROM employee
WHERE dept_id IN (
    SELECT dept_id
    FROM department
);
```

### Important: NULL with NOT IN

If a NOT IN list or subquery contains NULL, the comparison may evaluate to UNKNOWN and return no expected rows.

Example:

```sql
SELECT *
FROM employee
WHERE dept_id NOT IN (1, 2, NULL);
```

This does not return the expected non-matching rows.

Use NOT EXISTS or filter NULL values from the subquery when appropriate.

---

# 14. WHERE vs HAVING

Both WHERE and HAVING are used to filter data, but they work differently.

| Feature | WHERE | HAVING |
|---|---|---|
| Purpose | Filters individual rows | Filters groups |
| Used With | SELECT, UPDATE, DELETE | SELECT with grouping |
| Aggregate Functions | Cannot directly filter aggregate results | Commonly used with aggregates |
| Execution Concept | Before grouping | After grouping |
| Example | WHERE salary > 40000 | HAVING SUM(salary) > 80000 |

### WHERE Example

```sql
SELECT *
FROM employee
WHERE salary > 40000;
```

### HAVING Example

```sql
SELECT department, AVG(salary)
FROM employee
GROUP BY department
HAVING AVG(salary) > 45000;
```

### Using WHERE and HAVING Together

```sql
SELECT department, AVG(salary)
FROM employee
WHERE salary > 30000
GROUP BY department
HAVING AVG(salary) > 45000;
```

Here:
1. WHERE filters individual employees.
2. GROUP BY groups employees by department.
3. AVG calculates average salary.
4. HAVING filters departments based on average salary.

---

# 15. Complete SQL Lab Practicals

## Practical 1: Create Database

```sql
CREATE DATABASE cmce_session5;

USE cmce_session5;
```

## Practical 2: Create Employee Table Using Different Data Types and Constraints

```sql
CREATE TABLE employee (
    emp_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    age INT CHECK (age >= 18),
    salary DECIMAL(10,2),
    department VARCHAR(50) DEFAULT 'IT',
    joining_date DATE,
    is_active BOOLEAN DEFAULT TRUE
);
```

## Practical 3: Insert Multiple Records

```sql
INSERT INTO employee
(name, email, age, salary, department, joining_date, is_active)
VALUES
('Anurag', 'anurag@gmail.com', 22, 50000, 'IT', '2025-01-10', TRUE),
('Rahul', 'rahul@gmail.com', 23, 40000, 'HR', '2025-02-15', TRUE),
('Amit', 'amit@gmail.com', 25, 60000, 'IT', '2024-05-20', TRUE),
('Sneha', 'sneha@gmail.com', 24, 45000, 'HR', '2025-06-10', TRUE),
('Priya', 'priya@gmail.com', 26, 55000, 'Sales', '2024-08-15', FALSE);
```

## Practical 4: Display All Records

```sql
SELECT * FROM employee;
```

## Practical 5: Aggregate Functions

```sql
SELECT SUM(salary) FROM employee;

SELECT AVG(salary) FROM employee;

SELECT COUNT(*) FROM employee;

SELECT MAX(salary) FROM employee;

SELECT MIN(salary) FROM employee;
```

## Practical 6: GROUP BY

```sql
SELECT department, COUNT(*)
FROM employee
GROUP BY department;
```

## Practical 7: HAVING

```sql
SELECT department, AVG(salary)
FROM employee
GROUP BY department
HAVING AVG(salary) > 45000;
```

## Practical 8: LIKE

```sql
SELECT * FROM employee
WHERE name LIKE 'A%';

SELECT * FROM employee
WHERE name LIKE '%a';

SELECT * FROM employee
WHERE name LIKE '%n%';
```

## Practical 9: DISTINCT

```sql
SELECT DISTINCT department
FROM employee;
```

## Practical 10: ORDER BY

```sql
SELECT * FROM employee
ORDER BY salary ASC;

SELECT * FROM employee
ORDER BY salary DESC;
```

## Practical 11: BETWEEN AND

```sql
SELECT * FROM employee
WHERE salary BETWEEN 40000 AND 55000;
```

## Practical 12: NULL Comparison

```sql
SELECT * FROM employee
WHERE department IS NULL;

SELECT * FROM employee
WHERE department IS NOT NULL;
```

## Practical 13: IN

```sql
SELECT * FROM employee
WHERE department IN ('IT', 'HR');
```

## Practical 14: NOT IN

```sql
SELECT * FROM employee
WHERE department NOT IN ('IT', 'HR');
```

## Practical 15: Alter Constraints

```sql
ALTER TABLE employee
ADD CONSTRAINT chk_salary
CHECK (salary > 0);
```

## Practical 16: Drop Constraint

```sql
ALTER TABLE employee
DROP CHECK chk_salary;
```

---

# 16. Important Interview Questions

**Q1. What is a data type?**

A data type specifies the type of values that can be stored in a database column.

**Q2. Difference between CHAR and VARCHAR?**

CHAR stores fixed-length strings, whereas VARCHAR stores variable-length strings.

**Q3. Difference between FLOAT and DECIMAL?**

FLOAT stores approximate numeric values, whereas DECIMAL stores exact decimal values.

**Q4. What is a constraint?**

A constraint is a rule applied to a column or table to maintain data integrity.

**Q5. Difference between PRIMARY KEY and UNIQUE?**

A primary key does not allow NULL or duplicate values. A UNIQUE constraint prevents duplicates but permits NULL values in MySQL.

**Q6. What is a FOREIGN KEY?**

A foreign key establishes a relationship between tables and maintains referential integrity.

**Q7. What is CHECK?**

CHECK validates whether inserted or updated values satisfy a specified condition.

**Q8. What is an aggregate function?**

An aggregate function performs a calculation on a group of rows and returns a single result.

**Q9. Difference between COUNT(*) and COUNT(column)?**

COUNT(*) counts all rows, while COUNT(column) counts only non-NULL values in that column.

**Q10. Difference between WHERE and HAVING?**

WHERE filters individual rows before grouping, whereas HAVING filters groups after grouping.

**Q11. What is GROUP BY?**

GROUP BY groups records based on one or more columns.

**Q12. What is DISTINCT?**

DISTINCT removes duplicate rows from query results.

**Q13. Difference between ASC and DESC?**

ASC sorts in ascending order, while DESC sorts in descending order.

**Q14. What is the difference between IS NULL and = NULL?**

IS NULL correctly checks for NULL values. Equality comparison with NULL returns UNKNOWN.

**Q15. What are LIKE wildcards?**

% represents zero or more characters, and _ represents exactly one character.

**Q16. Is BETWEEN inclusive?**

Yes, BETWEEN includes both boundary values.

**Q17. Difference between IN and NOT IN?**

IN checks membership in a list, while NOT IN checks non-membership.

---

# 17. Important MCQs

**Q1. Which datatype is suitable for storing salary values accurately?**

A. FLOAT  
B. DOUBLE  
C. DECIMAL  
D. TEXT  

**Answer: C**

**Q2. Which datatype stores variable-length strings?**

A. CHAR  
B. VARCHAR  
C. INT  
D. DATE  

**Answer: B**

**Q3. Which constraint prevents NULL values?**

A. UNIQUE  
B. DEFAULT  
C. NOT NULL  
D. CHECK  

**Answer: C**

**Q4. Which constraint maintains referential integrity?**

A. PRIMARY KEY  
B. FOREIGN KEY  
C. UNIQUE  
D. DEFAULT  

**Answer: B**

**Q5. Which function returns the total of numeric values?**

A. AVG()  
B. MAX()  
C. SUM()  
D. COUNT()  

**Answer: C**

**Q6. Which function counts all rows?**

A. COUNT(*)  
B. COUNT(NULL)  
C. SUM()  
D. AVG()  

**Answer: A**

**Q7. Which clause groups records?**

A. ORDER BY  
B. GROUP BY  
C. WHERE  
D. DISTINCT  

**Answer: B**

**Q8. Which clause filters grouped records?**

A. WHERE  
B. ORDER BY  
C. HAVING  
D. LIMIT  

**Answer: C**

**Q9. Which wildcard represents zero or more characters?**

A. _  
B. %  
C. *  
D. #  

**Answer: B**

**Q10. Which keyword removes duplicate rows?**

A. UNIQUE  
B. REMOVE  
C. DISTINCT  
D. DELETE  

**Answer: C**

**Q11. Which keyword sorts records in descending order?**

A. ASC  
B. DESC  
C. GROUP  
D. SORT  

**Answer: B**

**Q12. BETWEEN includes:**

A. Only starting value  
B. Only ending value  
C. Both boundary values  
D. Neither boundary value  

**Answer: C**

**Q13. Which operator checks for NULL values?**

A. = NULL  
B. IS NULL  
C. == NULL  
D. IN NULL  

**Answer: B**

**Q14. Which operator checks whether a value belongs to a given list?**

A. BETWEEN  
B. LIKE  
C. IN  
D. DISTINCT  

**Answer: C**

**Q15. Which function returns the highest value?**

A. MIN()  
B. SUM()  
C. AVG()  
D. MAX()  

**Answer: D**

---

# 18. Quick Revision

| Topic | Remember |
|---|---|
| INT | Integer values |
| FLOAT | Approximate decimal |
| DECIMAL | Exact decimal |
| CHAR | Fixed-length string |
| VARCHAR | Variable-length string |
| DATE | Date |
| DATETIME | Date and time |
| TIMESTAMP | Time-zone-aware timestamp behavior |
| PRIMARY KEY | Unique identification |
| UNIQUE | No duplicate non-NULL values |
| NOT NULL | Prevents NULL |
| FOREIGN KEY | Relationship between tables |
| DEFAULT | Default value |
| CHECK | Validates condition |
| SUM() | Total |
| AVG() | Average |
| COUNT() | Count |
| MAX() | Highest value |
| MIN() | Lowest value |
| GROUP BY | Groups records |
| HAVING | Filters groups |
| LIKE | Pattern matching |
| DISTINCT | Removes duplicates |
| ORDER BY | Sorting |
| BETWEEN | Inclusive range |
| IS NULL | Checks NULL |
| IS NOT NULL | Checks non-NULL |
| IN | Matches a list |
| NOT IN | Excludes a list |

---

# 19. Practice Checklist

- [ ] Understand numeric data types.
- [ ] Understand string data types.
- [ ] Understand date and time data types.
- [ ] Understand CHAR vs VARCHAR.
- [ ] Understand FLOAT vs DECIMAL.
- [ ] Create tables using different datatypes.
- [ ] Apply PRIMARY KEY.
- [ ] Apply UNIQUE and NOT NULL.
- [ ] Apply FOREIGN KEY.
- [ ] Apply DEFAULT and CHECK.
- [ ] Add and drop constraints using ALTER.
- [ ] Practice SUM(), AVG(), COUNT(), MAX(), MIN().
- [ ] Practice GROUP BY.
- [ ] Practice HAVING.
- [ ] Practice LIKE with % and _.
- [ ] Practice DISTINCT.
- [ ] Practice ORDER BY ASC and DESC.
- [ ] Practice BETWEEN AND.
- [ ] Practice IS NULL and IS NOT NULL.
- [ ] Practice IN and NOT IN.
- [ ] Solve MCQs and interview questions.

---

## Recommended Learning Resources

1. MySQL Documentation: https://dev.mysql.com/doc/
2. MySQL Data Types: https://dev.mysql.com/doc/refman/8.0/en/data-types.html
3. MySQL Aggregate Functions: https://dev.mysql.com/doc/refman/8.0/en/aggregate-functions.html
4. W3Schools SQL: https://www.w3schools.com/sql/
5. GeeksforGeeks DBMS: https://www.geeksforgeeks.org/dbms/

---

**End of Session 5 – Data Types, Constraints and Aggregate Functions**

*Database Technologies | PGCP-AC | CMCE | August 2026*

**Learning Goal:** Understand MySQL data types and constraints, perform aggregate calculations, group and filter records, and efficiently retrieve data using SQL operators.</WritingBlock}

**CMCE exam preparation tip:** Give extra practice to `GROUP BY` with `HAVING`, aggregate functions, `COUNT(*)` vs `COUNT(column)`, PRIMARY KEY vs UNIQUE, and NULL comparisons. These concepts are especially important for SQL practicals and interview questions.

**Recommended GitHub filename:**

```text
Session-05-Data-Types-Constraints-Aggregate-Functions/
└── README.md
```
