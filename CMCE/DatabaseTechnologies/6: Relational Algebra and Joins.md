# Session 6: Relational Algebra and Joins

## Database Technologies | PGCP-AC | CMCE | August 2026

**Institute:** ACTS, Pune  
**Course:** PGCP-AC  
**Subject:** Database Technologies  
**Session:** 06 – Relational Algebra and Joins  
**Duration:** 2 Theory + 2 Lab + 4 Self Learning Hours

---

## Table of Contents

1. [Introduction to Relational Algebra](#1-introduction-to-relational-algebra)
2. [Relational Algebra Operations](#2-relational-algebra-operations)
3. [Selection Operation](#3-selection-operation)
4. [Projection Operation](#4-projection-operation)
5. [Union Operation](#5-union-operation)
6. [Intersection Operation](#6-intersection-operation)
7. [Minus Operation](#7-minus-operation)
8. [Cartesian Product](#8-cartesian-product)
9. [Introduction to Joins](#9-introduction-to-joins)
10. [Equi Join](#10-equi-join)
11. [Inner Join](#11-inner-join)
12. [Outer Join](#12-outer-join)
13. [Natural Join](#13-natural-join)
14. [Cross Join](#14-cross-join)
15. [Old Syntax vs SQL Standard Join Syntax](#15-old-syntax-vs-sql-standard-join-syntax)
16. [UNION and UNION ALL](#16-union-and-union-all)
17. [Copying Table Structure and Data](#17-copying-table-structure-and-data)
18. [AUTO_INCREMENT](#18-auto_increment)
19. [Complete SQL Lab Practicals](#19-complete-sql-lab-practicals)
20. [Important Interview Questions](#20-important-interview-questions)
21. [Important MCQs](#21-important-mcqs)
22. [Quick Revision](#22-quick-revision)
23. [Practice Checklist](#23-practice-checklist)

---

# 1. Introduction to Relational Algebra

### What is Relational Algebra?

Relational Algebra is a procedural query language used to perform operations on relational databases.

It is a mathematical foundation of relational database systems.

It operates on relations (tables) and produces another relation as a result.

### Why Do We Need Relational Algebra?

1. Provides a mathematical foundation for relational databases.
2. Helps understand how SQL queries work.
3. Helps retrieve specific records from tables.
4. Helps combine data from multiple tables.
5. Helps understand query optimization.

### Important Terminologies

| Term | Meaning |
|---|---|
| Relation | A table in a relational database |
| Tuple | A row in a table |
| Attribute | A column in a table |
| Domain | Set of valid values for an attribute |
| Degree | Number of attributes (columns) |
| Cardinality | Number of tuples (rows) |

### Example

Consider the Student relation:

| Student_ID | Name | Age | City |
|---|---|---|---|
| 101 | Anurag | 22 | Pune |
| 102 | Rahul | 23 | Mumbai |
| 103 | Amit | 21 | Nashik |

- Relation: Student
- Attributes: Student_ID, Name, Age, City
- Tuples: 3
- Degree: 4
- Cardinality: 3

---

# 2. Relational Algebra Operations

Relational Algebra operations are divided into two categories.

### 2.1 Basic Operations

1. Selection (σ)
2. Projection (π)
3. Union (∪)
4. Set Difference / Minus (−)
5. Cartesian Product (×)
6. Rename (ρ)

### 2.2 Derived Operations

1. Intersection (∩)
2. Join (⋈)
3. Division (÷)

**Note:** The ACTS syllabus specifically includes Selection, Projection, Union, Intersection, Minus and Cartesian Product.

---

# 3. Selection Operation (σ)

### Definition

Selection is used to retrieve specific rows from a relation based on a given condition.

It is represented by the Greek symbol sigma (σ).

**Notation:**

```text
σ condition (Relation)
```

### Example

Student table:

| Student_ID | Name | Age | City |
|---|---|---|---|
| 101 | Anurag | 22 | Pune |
| 102 | Rahul | 23 | Mumbai |
| 103 | Amit | 21 | Nashik |

Retrieve students whose age is greater than 21.

**Relational Algebra:**

```text
σ Age > 21 (Student)
```

**SQL Query:**

```sql
SELECT *
FROM student
WHERE age > 21;
```

Output:

| Student_ID | Name | Age | City |
|---|---|---|---|
| 101 | Anurag | 22 | Pune |
| 102 | Rahul | 23 | Mumbai |

### Selection with Multiple Conditions

**Relational Algebra:**

```text
σ Age > 21 AND City = 'Pune' (Student)
```

**SQL:**

```sql
SELECT *
FROM student
WHERE age > 21
AND city = 'Pune';
```

### Important Points

- Selection operates on rows.
- It filters records based on conditions.
- It does not remove columns.
- It is similar to the SQL WHERE clause.

**Remember:** Selection = Rows.

---

# 4. Projection Operation (π)

### Definition

Projection is used to retrieve specific columns from a relation.

It is represented by the Greek symbol pi (π).

**Notation:**

```text
π attribute1, attribute2 (Relation)
```

### Example

Retrieve only the student names and cities.

**Relational Algebra:**

```text
π Name, City (Student)
```

**SQL:**

```sql
SELECT name, city
FROM student;
```

Output:

| Name | City |
|---|---|
| Anurag | Pune |
| Rahul | Mumbai |
| Amit | Nashik |

### Projection with DISTINCT

In classical relational algebra, projection eliminates duplicate tuples.

SQL equivalent:

```sql
SELECT DISTINCT city
FROM student;
```

**Remember:** Projection = Columns.

### Selection vs Projection

| Feature | Selection | Projection |
|---|---|---|
| Symbol | σ | π |
| Operation | Filters rows | Selects columns |
| Based On | Conditions | Attributes |
| SQL Equivalent | WHERE | SELECT columns |
| Result | Selected rows | Selected columns |

---

# 5. Union Operation (∪)

### Definition

Union combines the records of two relations and returns all distinct records.

It is represented by the symbol (∪).

### Conditions for Union Compatibility

Two relations must have:

1. The same number of attributes.
2. Corresponding attributes with compatible domains or data types.
3. Corresponding columns in compatible positions.

### Example

**Table A – Students_2025**

| Student_ID | Name |
|---|---|
| 101 | Anurag |
| 102 | Rahul |

**Table B – Students_2026**

| Student_ID | Name |
|---|---|
| 102 | Rahul |
| 103 | Amit |

**Relational Algebra:**

```text
Students_2025 ∪ Students_2026
```

**SQL:**

```sql
SELECT student_id, name
FROM students_2025

UNION

SELECT student_id, name
FROM students_2026;
```

Output:

| Student_ID | Name |
|---|---|
| 101 | Anurag |
| 102 | Rahul |
| 103 | Amit |

Duplicate records are eliminated.

**Remember:** UNION = Combines records + Removes duplicates.

---

# 6. Intersection Operation (∩)

### Definition

Intersection returns only the records that are common to both relations.

It is represented by the symbol (∩).

### Example

**Students_2025**

| Student_ID | Name |
|---|---|
| 101 | Anurag |
| 102 | Rahul |
| 103 | Amit |

**Students_2026**

| Student_ID | Name |
|---|---|
| 102 | Rahul |
| 103 | Amit |
| 104 | Sneha |

**Relational Algebra:**

```text
Students_2025 ∩ Students_2026
```

Output:

| Student_ID | Name |
|---|---|
| 102 | Rahul |
| 103 | Amit |

### SQL Implementation

MySQL 8.0.31 and later supports INTERSECT.

```sql
SELECT student_id, name
FROM students_2025

INTERSECT

SELECT student_id, name
FROM students_2026;
```

### Alternative Using INNER JOIN

For matching student IDs:

```sql
SELECT DISTINCT a.student_id, a.name
FROM students_2025 a
INNER JOIN students_2026 b
ON a.student_id = b.student_id;
```

**Remember:** INTERSECT = Common records.

---

# 7. Minus Operation (−)

### Definition

Minus or Set Difference returns records present in the first relation but not present in the second relation.

It is represented by the symbol (−).

### Example

**Students_2025**

| Student_ID | Name |
|---|---|
| 101 | Anurag |
| 102 | Rahul |
| 103 | Amit |

**Students_2026**

| Student_ID | Name |
|---|---|
| 102 | Rahul |
| 103 | Amit |

**Relational Algebra:**

```text
Students_2025 − Students_2026
```

Output:

| Student_ID | Name |
|---|---|
| 101 | Anurag |

### SQL Implementation

MySQL 8.0.31 and later supports EXCEPT.

```sql
SELECT student_id, name
FROM students_2025

EXCEPT

SELECT student_id, name
FROM students_2026;
```

**Important:** MySQL uses EXCEPT rather than MINUS as the set-difference keyword.

### Alternative Using NOT EXISTS

```sql
SELECT a.student_id, a.name
FROM students_2025 a
WHERE NOT EXISTS (
    SELECT 1
    FROM students_2026 b
    WHERE b.student_id = a.student_id
);
```

**Remember:** A − B = Records in A but not in B.

---

# 8. Cartesian Product (×)

### Definition

Cartesian Product combines every row of the first relation with every row of the second relation.

It is represented by the symbol (×).

### Example

**Student Table**

| Student_ID | Name |
|---|---|
| 101 | Anurag |
| 102 | Rahul |

**Course Table**

| Course_ID | Course_Name |
|---|---|
| C01 | Java |
| C02 | Python |

**Relational Algebra:**

```text
Student × Course
```

Output:

| Student_ID | Name | Course_ID | Course_Name |
|---|---|---|---|
| 101 | Anurag | C01 | Java |
| 101 | Anurag | C02 | Python |
| 102 | Rahul | C01 | Java |
| 102 | Rahul | C02 | Python |

### Formula

If:
- Relation A has M rows.
- Relation B has N rows.

Then:

```text
Total Rows = M × N
```

Here:

```text
2 × 2 = 4 rows
```

### SQL Implementation

```sql
SELECT *
FROM student
CROSS JOIN course;
```

Alternative:

```sql
SELECT *
FROM student, course;
```

**Remember:** Cartesian Product = Every possible combination.

---

# 9. Introduction to Joins

### What is a Join?

A JOIN is used to combine records from two or more tables based on a related column or a specified condition.

Joins are commonly used when data is stored in multiple related tables.

### Why Do We Need Joins?

Suppose we have:

**Employee Table**

| emp_id | emp_name | dept_id |
|---|---|---|
| 1 | Anurag | 101 |
| 2 | Rahul | 102 |
| 3 | Amit | 101 |
| 4 | Sneha | NULL |

**Department Table**

| dept_id | dept_name |
|---|---|
| 101 | IT |
| 102 | HR |
| 103 | Sales |

To retrieve employee names along with department names, we need to join these two tables.

### Types of Joins

1. Equi Join
2. Inner Join
3. Outer Join
   - Left Outer Join
   - Right Outer Join
   - Full Outer Join
4. Natural Join
5. Cross Join

---

# 10. Equi Join

### Definition

An Equi Join is a join that combines records from two tables using the equality (=) operator in the join condition.

### Syntax

```sql
SELECT *
FROM table1, table2
WHERE table1.column = table2.column;
```

### Example

```sql
SELECT
    e.emp_name,
    d.dept_name
FROM employee e, department d
WHERE e.dept_id = d.dept_id;
```

Output:

| emp_name | dept_name |
|---|---|
| Anurag | IT |
| Rahul | HR |
| Amit | IT |

### Important Points

- Uses the equality operator (=).
- Returns matching records.
- Commonly written using old-style join syntax.
- Both matching join columns may appear in SELECT * results.

**Remember:** Equi Join = Equality condition.

---

# 11. Inner Join

### Definition

INNER JOIN returns only those records that have matching values in both tables.

### Syntax

```sql
SELECT columns
FROM table1
INNER JOIN table2
ON table1.column = table2.column;
```

### Example

```sql
SELECT
    e.emp_id,
    e.emp_name,
    d.dept_name
FROM employee e
INNER JOIN department d
ON e.dept_id = d.dept_id;
```

Output:

| emp_id | emp_name | dept_name |
|---|---|---|
| 1 | Anurag | IT |
| 2 | Rahul | HR |
| 3 | Amit | IT |

Sneha is not included because she does not have a matching department.

### Important Points

- Returns matching records.
- Does not return unmatched records.
- Can be used with multiple tables.
- Supports different join conditions.

**Remember:** INNER JOIN = Matching records only.

---

# 12. Outer Join

### Definition

An Outer Join returns matching records along with unmatched records from one or both tables.

There are three main types.

## 12.1 LEFT OUTER JOIN

Returns all records from the left table and matching records from the right table.

If there is no match, NULL values are returned for the right table columns.

### Syntax

```sql
SELECT *
FROM table1
LEFT JOIN table2
ON table1.column = table2.column;
```

### Example

```sql
SELECT
    e.emp_name,
    d.dept_name
FROM employee e
LEFT JOIN department d
ON e.dept_id = d.dept_id;
```

Output:

| emp_name | dept_name |
|---|---|
| Anurag | IT |
| Rahul | HR |
| Amit | IT |
| Sneha | NULL |

### Important Point

All employees are displayed, even if they do not belong to any department.

## 12.2 RIGHT OUTER JOIN

Returns all records from the right table and matching records from the left table.

If there is no match, NULL values are returned for the left table columns.

### Example

```sql
SELECT
    e.emp_name,
    d.dept_name
FROM employee e
RIGHT JOIN department d
ON e.dept_id = d.dept_id;
```

Output:

| emp_name | dept_name |
|---|---|
| Anurag | IT |
| Amit | IT |
| Rahul | HR |
| NULL | Sales |

### Important Point

All departments are displayed, even if no employee belongs to them.

## 12.3 FULL OUTER JOIN

Returns all matching and unmatched records from both tables.

MySQL does not directly support FULL OUTER JOIN syntax.

It can be implemented using LEFT JOIN and RIGHT JOIN with UNION.

### Example

```sql
SELECT
    e.emp_name,
    d.dept_name
FROM employee e
LEFT JOIN department d
ON e.dept_id = d.dept_id

UNION

SELECT
    e.emp_name,
    d.dept_name
FROM employee e
RIGHT JOIN department d
ON e.dept_id = d.dept_id;
```

### Outer Join Summary

| Join | Returns |
|---|---|
| LEFT JOIN | All left table rows + matching right rows |
| RIGHT JOIN | All right table rows + matching left rows |
| FULL OUTER JOIN | All rows from both tables |

---

# 13. Natural Join

### Definition

NATURAL JOIN automatically joins two tables using all columns that have the same names and compatible data types.

It does not require an explicit ON condition.

### Example

Employee Table:

| emp_id | emp_name | dept_id |
|---|---|---|
| 1 | Anurag | 101 |
| 2 | Rahul | 102 |

Department Table:

| dept_id | dept_name |
|---|---|
| 101 | IT |
| 102 | HR |

### SQL Query

```sql
SELECT *
FROM employee
NATURAL JOIN department;
```

Output:

| emp_id | emp_name | dept_id | dept_name |
|---|---|---|---|
| 1 | Anurag | 101 | IT |
| 2 | Rahul | 102 | HR |

### Important Points

- Automatically identifies common column names.
- Uses equality matching on all common columns.
- Displays common columns only once.
- Can produce unexpected results if unrelated columns have the same name.

**Remember:** NATURAL JOIN = Automatic join using common column names.

---

# 14. Cross Join

### Definition

CROSS JOIN returns the Cartesian Product of two tables.

Every row from the first table is combined with every row from the second table.

### Syntax

```sql
SELECT *
FROM employee
CROSS JOIN department;
```

### Example

If:
- Employee has 4 rows.
- Department has 3 rows.

Then:

```text
4 × 3 = 12 rows
```

### Important Points

- Does not require a join condition.
- Produces every possible combination.
- Can generate a large result set.

---

# 15. Old Syntax vs SQL Standard Join Syntax

There are two commonly used ways to write joins.

1. Old-style join syntax.
2. SQL Standard JOIN syntax.

## 15.1 Old Syntax

Uses comma-separated tables in FROM and the join condition in WHERE.

```sql
SELECT
    e.emp_name,
    d.dept_name
FROM employee e, department d
WHERE e.dept_id = d.dept_id;
```

## 15.2 SQL Standard Syntax

Uses explicit JOIN and ON clauses.

```sql
SELECT
    e.emp_name,
    d.dept_name
FROM employee e
INNER JOIN department d
ON e.dept_id = d.dept_id;
```

### Difference Between Old and Standard Syntax

| Feature | Old Syntax | SQL Standard Syntax |
|---|---|---|
| Tables | Comma-separated | JOIN keyword |
| Join Condition | WHERE | ON |
| Readability | Less clear for multiple joins | More readable |
| Outer Joins | Not conveniently supported using portable syntax | Supports LEFT and RIGHT JOIN |
| Recommended | Legacy queries | Modern SQL queries |

### Example: Three Table Join

Suppose we have:
- Employee
- Department
- Location

Old syntax:

```sql
SELECT
    e.emp_name,
    d.dept_name,
    l.city
FROM employee e,
     department d,
     location l
WHERE e.dept_id = d.dept_id
AND d.location_id = l.location_id;
```

Standard syntax:

```sql
SELECT
    e.emp_name,
    d.dept_name,
    l.city
FROM employee e
INNER JOIN department d
ON e.dept_id = d.dept_id
INNER JOIN location l
ON d.location_id = l.location_id;
```

**Recommendation:** Prefer SQL Standard JOIN syntax because it separates join conditions from filtering conditions and makes complex queries easier to understand.

---

# 16. UNION and UNION ALL

### UNION

UNION combines results from two or more SELECT statements and removes duplicate rows.

```sql
SELECT name FROM students_2025
UNION
SELECT name FROM students_2026;
```

### UNION ALL

UNION ALL combines results without removing duplicate rows.

```sql
SELECT name FROM students_2025
UNION ALL
SELECT name FROM students_2026;
```

### Difference Between UNION and UNION ALL

| Feature | UNION | UNION ALL |
|---|---|---|
| Combines Results | Yes | Yes |
| Removes Duplicates | Yes | No |
| Duplicate Records | One copy | All copies |
| Performance | May require duplicate elimination | Usually faster |
| Use Case | Unique combined records | All combined records |

### Important Rules

1. Both SELECT statements must return the same number of columns.
2. Corresponding columns must have compatible data types.
3. Column names in the result are generally taken from the first SELECT.
4. ORDER BY applies to the combined result and is normally written at the end.

Example:

```sql
SELECT student_id, name
FROM students_2025

UNION ALL

SELECT student_id, name
FROM students_2026

ORDER BY student_id;
```

---

# 17. Copying Table Structure and Data

MySQL provides different methods to copy tables.

## 17.1 Copy Only Table Structure

Use CREATE TABLE LIKE.

### Syntax

```sql
CREATE TABLE new_table
LIKE existing_table;
```

### Example

```sql
CREATE TABLE employee_backup
LIKE employee;
```

This copies:
- Column names.
- Datatypes.
- Indexes.
- Primary key and other table structure definitions.

It does not copy existing records.

**Important:** CREATE TABLE LIKE does not copy foreign key definitions or triggers.

## 17.2 Copy Table Structure and Data

Use CREATE TABLE AS SELECT.

### Syntax

```sql
CREATE TABLE new_table AS
SELECT * FROM existing_table;
```

### Example

```sql
CREATE TABLE employee_copy AS
SELECT * FROM employee;
```

This creates a new table with selected columns and copies their data.

**Important:** CTAS does not automatically copy the original table's primary keys, indexes, foreign keys and other constraints.

## 17.3 Copy Only Data into an Existing Table

Use INSERT INTO SELECT.

### Syntax

```sql
INSERT INTO destination_table
SELECT * FROM source_table;
```

### Example

```sql
INSERT INTO employee_backup
SELECT * FROM employee;
```

The destination table must already exist, and the selected columns must be compatible.

## 17.4 Copy Selected Columns

```sql
INSERT INTO employee_backup
(emp_id, emp_name)
SELECT emp_id, emp_name
FROM employee;
```

## 17.5 Copy Selected Records

```sql
INSERT INTO employee_backup
SELECT *
FROM employee
WHERE dept_id = 101;
```

### Comparison of Table Copying Methods

| Command | Structure | Data |
|---|---|---|
| CREATE TABLE LIKE | Yes | No |
| CREATE TABLE AS SELECT | Yes, based on SELECT | Yes |
| INSERT INTO SELECT | Existing destination required | Yes |
| CREATE TABLE LIKE + INSERT | Yes | Yes |

---

# 18. AUTO_INCREMENT

### What is AUTO_INCREMENT?

AUTO_INCREMENT is a MySQL column attribute that automatically generates the next sequential integer value when a new record is inserted without providing that column's value.

It is commonly used with PRIMARY KEY columns.

### Example

```sql
CREATE TABLE student (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    city VARCHAR(50)
);
```

### Insert Records

```sql
INSERT INTO student (name, city)
VALUES ('Anurag', 'Pune');

INSERT INTO student (name, city)
VALUES ('Rahul', 'Mumbai');

INSERT INTO student (name, city)
VALUES ('Amit', 'Nashik');
```

Output:

| student_id | name | city |
|---|---|---|
| 1 | Anurag | Pune |
| 2 | Rahul | Mumbai |
| 3 | Amit | Nashik |

The student_id values are generated automatically.

## 18.1 AUTO_INCREMENT with Multiple Records

```sql
INSERT INTO student (name, city)
VALUES
('Sneha', 'Pune'),
('Priya', 'Mumbai'),
('Rohit', 'Nashik');
```

IDs are automatically generated.

## 18.2 Check AUTO_INCREMENT Value

```sql
SHOW TABLE STATUS LIKE 'student';
```

## 18.3 Set AUTO_INCREMENT Starting Value

```sql
ALTER TABLE student
AUTO_INCREMENT = 100;
```

The next generated value will be at least 100, subject to the existing maximum ID.

## 18.4 Reset AUTO_INCREMENT

For an empty table:

```sql
TRUNCATE TABLE student;
```

MySQL resets the AUTO_INCREMENT counter for the truncated table.

Alternatively:

```sql
ALTER TABLE student
AUTO_INCREMENT = 1;
```

This cannot make the next value lower than the existing maximum ID plus one.

## 18.5 Insert a Custom AUTO_INCREMENT Value

```sql
INSERT INTO student
(student_id, name, city)
VALUES
(50, 'Karan', 'Pune');
```

MySQL allows explicitly supplying an AUTO_INCREMENT value.

The next automatically generated value adjusts based on the current counter and inserted maximum value.

### Important Points

- AUTO_INCREMENT is commonly used with integer columns.
- Only one AUTO_INCREMENT column is allowed per table.
- The AUTO_INCREMENT column must be indexed.
- It is commonly used with PRIMARY KEY.
- Generated values may contain gaps.
- It does not guarantee gap-free numbering.

**Remember:** AUTO_INCREMENT = Automatically generated sequential values.

### Important Clarification: Sequences

A standalone SQL SEQUENCE object is different from AUTO_INCREMENT.

MySQL does not provide standalone CREATE SEQUENCE objects like Oracle or PostgreSQL. In MySQL, AUTO_INCREMENT is the standard mechanism for automatic integer ID generation.

---

# 19. Complete SQL Lab Practicals

## Practical 1: Create Database

```sql
CREATE DATABASE cmce_session6;

USE cmce_session6;
```

## Practical 2: Create Department Table

```sql
CREATE TABLE department (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50)
);
```

## Practical 3: Create Employee Table

```sql
CREATE TABLE employee (
    emp_id INT AUTO_INCREMENT PRIMARY KEY,
    emp_name VARCHAR(50),
    salary DECIMAL(10,2),
    dept_id INT,
    FOREIGN KEY (dept_id)
        REFERENCES department(dept_id)
);
```

## Practical 4: Insert Department Records

```sql
INSERT INTO department
VALUES
(101, 'IT'),
(102, 'HR'),
(103, 'Sales');
```

## Practical 5: Insert Employee Records

```sql
INSERT INTO employee
(emp_name, salary, dept_id)
VALUES
('Anurag', 50000, 101),
('Rahul', 40000, 102),
('Amit', 60000, 101),
('Sneha', 45000, NULL);
```

## Practical 6: INNER JOIN

```sql
SELECT
    e.emp_id,
    e.emp_name,
    d.dept_name
FROM employee e
INNER JOIN department d
ON e.dept_id = d.dept_id;
```

## Practical 7: LEFT JOIN

```sql
SELECT
    e.emp_name,
    d.dept_name
FROM employee e
LEFT JOIN department d
ON e.dept_id = d.dept_id;
```

## Practical 8: RIGHT JOIN

```sql
SELECT
    e.emp_name,
    d.dept_name
FROM employee e
RIGHT JOIN department d
ON e.dept_id = d.dept_id;
```

## Practical 9: CROSS JOIN

```sql
SELECT *
FROM employee
CROSS JOIN department;
```

## Practical 10: NATURAL JOIN

```sql
SELECT *
FROM employee
NATURAL JOIN department;
```

## Practical 11: Equi Join Using Old Syntax

```sql
SELECT
    e.emp_name,
    d.dept_name
FROM employee e, department d
WHERE e.dept_id = d.dept_id;
```

## Practical 12: UNION

Create two sample tables:

```sql
CREATE TABLE students_2025 (
    student_id INT,
    name VARCHAR(50)
);

CREATE TABLE students_2026 (
    student_id INT,
    name VARCHAR(50)
);
```

Insert records:

```sql
INSERT INTO students_2025 VALUES
(1, 'Anurag'),
(2, 'Rahul');

INSERT INTO students_2026 VALUES
(2, 'Rahul'),
(3, 'Amit');
```

Execute UNION:

```sql
SELECT * FROM students_2025
UNION
SELECT * FROM students_2026;
```

## Practical 13: UNION ALL

```sql
SELECT * FROM students_2025
UNION ALL
SELECT * FROM students_2026;
```

## Practical 14: INTERSECT

Requires MySQL 8.0.31 or later.

```sql
SELECT * FROM students_2025
INTERSECT
SELECT * FROM students_2026;
```

## Practical 15: EXCEPT (Minus)

Requires MySQL 8.0.31 or later.

```sql
SELECT * FROM students_2025
EXCEPT
SELECT * FROM students_2026;
```

## Practical 16: Copy Table Structure

```sql
CREATE TABLE employee_backup
LIKE employee;
```

## Practical 17: Copy Table Structure and Data

```sql
CREATE TABLE employee_copy AS
SELECT * FROM employee;
```

## Practical 18: Copy Data into Existing Table

```sql
INSERT INTO employee_backup
SELECT * FROM employee;
```

## Practical 19: AUTO_INCREMENT

```sql
CREATE TABLE product (
    product_id INT AUTO_INCREMENT PRIMARY KEY,
    product_name VARCHAR(100),
    price DECIMAL(10,2)
);

INSERT INTO product (product_name, price)
VALUES
('Laptop', 55000),
('Mobile', 25000),
('Keyboard', 1500);

SELECT * FROM product;
```

---

# 20. Important Interview Questions

**Q1. What is Relational Algebra?**

Relational Algebra is a procedural query language used to perform mathematical operations on relational tables.

**Q2. What is Selection?**

Selection retrieves specific rows based on a condition.

**Q3. What is Projection?**

Projection retrieves specific columns from a relation.

**Q4. Difference between Selection and Projection?**

Selection operates on rows, whereas Projection operates on columns.

**Q5. What is Cartesian Product?**

It combines every row of one relation with every row of another relation.

**Q6. What is Union?**

Union combines records from two compatible relations and removes duplicates.

**Q7. What is Intersection?**

Intersection returns only common records from two compatible relations.

**Q8. What is Minus?**

Minus returns records present in the first relation but absent in the second.

**Q9. What is a Join?**

A Join combines related records from two or more tables.

**Q10. Difference between Equi Join and Inner Join?**

Equi Join uses equality as the join condition. Inner Join returns matching records and can use equality or other comparison conditions.

**Q11. What is Natural Join?**

Natural Join automatically matches columns having the same names and compatible types.

**Q12. Difference between LEFT JOIN and RIGHT JOIN?**

LEFT JOIN returns all records from the left table, whereas RIGHT JOIN returns all records from the right table.

**Q13. Does MySQL support FULL OUTER JOIN?**

No. It can be simulated using LEFT JOIN and RIGHT JOIN combined with UNION.

**Q14. Difference between UNION and UNION ALL?**

UNION removes duplicate rows, whereas UNION ALL retains duplicates.

**Q15. What is AUTO_INCREMENT?**

It automatically generates sequential integer values for a column.

**Q16. Difference between CREATE TABLE LIKE and CREATE TABLE AS SELECT?**

CREATE TABLE LIKE copies table structure and indexes but not data. CREATE TABLE AS SELECT creates a table from a query result and copies the selected data without automatically copying all original constraints and indexes.

**Q17. What is the difference between CROSS JOIN and INNER JOIN?**

CROSS JOIN produces all possible row combinations, whereas INNER JOIN returns matching records based on a join condition.

**Q18. What is an Equi Join?**

It is a join that uses the equality operator to match records between tables.

---

# 21. Important MCQs

**Q1. Which symbol represents Selection in Relational Algebra?**

A. π  
B. σ  
C. ∪  
D. ×  

**Answer: B**

**Q2. Which symbol represents Projection?**

A. σ  
B. π  
C. ∩  
D. −  

**Answer: B**

**Q3. Which operation retrieves selected columns?**

A. Selection  
B. Projection  
C. Union  
D. Cartesian Product  

**Answer: B**

**Q4. Which operation combines every row of two relations?**

A. INNER JOIN  
B. UNION  
C. Cartesian Product  
D. INTERSECT  

**Answer: C**

**Q5. Which SQL command removes duplicate records from combined results?**

A. UNION ALL  
B. UNION  
C. CROSS JOIN  
D. SELECT ALL  

**Answer: B**

**Q6. Which operator returns common records?**

A. UNION  
B. EXCEPT  
C. INTERSECT  
D. CROSS JOIN  

**Answer: C**

**Q7. Which operator returns records present in the first result but not the second?**

A. UNION  
B. INTERSECT  
C. EXCEPT  
D. JOIN  

**Answer: C**

**Q8. Which JOIN returns only matching records?**

A. LEFT JOIN  
B. RIGHT JOIN  
C. INNER JOIN  
D. CROSS JOIN  

**Answer: C**

**Q9. Which JOIN returns all rows from the left table?**

A. INNER JOIN  
B. LEFT JOIN  
C. RIGHT JOIN  
D. CROSS JOIN  

**Answer: B**

**Q10. Which JOIN automatically matches columns with the same names?**

A. CROSS JOIN  
B. NATURAL JOIN  
C. LEFT JOIN  
D. FULL JOIN  

**Answer: B**

**Q11. Which JOIN produces a Cartesian Product?**

A. INNER JOIN  
B. LEFT JOIN  
C. CROSS JOIN  
D. NATURAL JOIN  

**Answer: C**

**Q12. Which operator is used in an Equi Join?**

A. >  
B. <  
C. =  
D. !=  

**Answer: C**

**Q13. Which MySQL operator can simulate set difference?**

A. UNION  
B. EXCEPT  
C. CROSS  
D. NATURAL  

**Answer: B**

**Q14. Which command copies only the table structure and indexes?**

A. CREATE TABLE AS SELECT  
B. CREATE TABLE LIKE  
C. INSERT INTO SELECT  
D. SELECT INTO  

**Answer: B**

**Q15. Which attribute automatically generates integer values in MySQL?**

A. DEFAULT  
B. UNIQUE  
C. AUTO_INCREMENT  
D. CHECK  

**Answer: C**

---

# 22. Quick Revision

| Topic | Remember |
|---|---|
| Relational Algebra | Mathematical query operations |
| Selection (σ) | Selects rows |
| Projection (π) | Selects columns |
| Union (∪) | Combines distinct records |
| Intersection (∩) | Common records |
| Minus (−) | Records in first relation only |
| Cartesian Product (×) | All possible combinations |
| Equi Join | Equality-based join |
| Inner Join | Matching records |
| Left Join | All left records |
| Right Join | All right records |
| Full Outer Join | All records from both sides |
| Natural Join | Automatic common-column join |
| Cross Join | Cartesian Product |
| UNION | Removes duplicates |
| UNION ALL | Keeps duplicates |
| CREATE TABLE LIKE | Copies structure and indexes |
| CREATE TABLE AS SELECT | Copies query-result structure and data |
| INSERT INTO SELECT | Copies data into existing table |
| AUTO_INCREMENT | Generates integer IDs |

---

# 23. Practice Checklist

- [ ] Understand Relational Algebra.
- [ ] Practice Selection (σ).
- [ ] Practice Projection (π).
- [ ] Practice Union.
- [ ] Practice Intersection.
- [ ] Practice Minus / EXCEPT.
- [ ] Practice Cartesian Product.
- [ ] Understand Equi Join.
- [ ] Practice INNER JOIN.
- [ ] Practice LEFT JOIN.
- [ ] Practice RIGHT JOIN.
- [ ] Understand FULL OUTER JOIN implementation in MySQL.
- [ ] Practice NATURAL JOIN.
- [ ] Practice CROSS JOIN.
- [ ] Write joins using old syntax.
- [ ] Write joins using SQL Standard syntax.
- [ ] Practice UNION and UNION ALL.
- [ ] Copy table structure using CREATE TABLE LIKE.
- [ ] Copy structure and data using CREATE TABLE AS SELECT.
- [ ] Copy data using INSERT INTO SELECT.
- [ ] Practice AUTO_INCREMENT.
- [ ] Solve MCQs and interview questions.

---

## Recommended Learning Resources

1. MySQL Documentation: https://dev.mysql.com/doc/
2. MySQL JOINs: https://dev.mysql.com/doc/refman/8.0/en/join.html
3. MySQL UNION: https://dev.mysql.com/doc/refman/8.0/en/union.html
4. MySQL CREATE TABLE: https://dev.mysql.com/doc/refman/8.0/en/create-table.html
5. GeeksforGeeks DBMS: https://www.geeksforgeeks.org/dbms/

---

**End of Session 6 – Relational Algebra and Joins**

*Database Technologies | PGCP-AC | CMCE | August 2026*

**Learning Goal:** Understand relational algebra operations, write different types of SQL joins, combine query results, copy tables and manage automatically generated IDs using AUTO_INCREMENT.
