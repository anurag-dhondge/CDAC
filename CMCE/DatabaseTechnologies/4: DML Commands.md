# Session 4: DML Commands

## Database Technologies | PGCP-AC | CMCE | August 2026

**Institute:** ACTS, Pune  
**Course:** PGCP-AC  
**Subject:** Database Technologies  
**Session:** 04 – DML Commands  
**Duration:** 2 Theory + 2 Lab + 2 Self Learning Hours

---

## Table of Contents

1. [Introduction to DML](#1-introduction-to-dml)
2. [DML Commands](#2-dml-commands)
3. [DDL vs DML](#3-ddl-vs-dml)
4. [INSERT Statement](#4-insert-statement)
5. [UPDATE Statement](#5-update-statement)
6. [DELETE Statement](#6-delete-statement)
7. [DELETE vs TRUNCATE](#7-delete-vs-truncate)
8. [Data Integrity](#8-data-integrity)
9. [Lab Practicals](#9-lab-practicals)
10. [Important Interview Questions](#10-important-interview-questions)
11. [Important MCQs](#11-important-mcqs)
12. [Quick Revision](#12-quick-revision)
13. [Practice Checklist](#13-practice-checklist)

---

# 1. Introduction to DML

### What is DML?

DML stands for **Data Manipulation Language**.

DML is a category of SQL commands used to insert, modify and delete records stored inside database tables.

DML works with the data stored in tables rather than changing the table structure.

### Why Do We Need DML?

DML is used to:

1. Insert new records into tables.
2. Update existing records.
3. Delete unwanted records.
4. Maintain current and accurate information.
5. Manage data in database applications.

### Example

Consider a Student table:

| Student_ID | Name | Age | City |
|---|---|---|---|
| 101 | Anurag | 22 | Pune |
| 102 | Rahul | 23 | Mumbai |

Using DML, we can:

- Add a new student using INSERT.
- Change a student's city using UPDATE.
- Remove a student using DELETE.

---

# 2. DML Commands

The three important DML commands are:

| Command | Purpose |
|---|---|
| INSERT | Adds new records |
| UPDATE | Modifies existing records |
| DELETE | Removes records |

### 2.1 INSERT

Used to insert new records into a table.

```sql
INSERT INTO student
VALUES (103, 'Amit', 21, 'Nashik');
```

### 2.2 UPDATE

Used to modify existing records.

```sql
UPDATE student
SET city = 'Pune'
WHERE student_id = 102;
```

### 2.3 DELETE

Used to remove records from a table.

```sql
DELETE FROM student
WHERE student_id = 103;
```

---

# 3. DDL vs DML

### DDL – Data Definition Language

DDL commands are used to define and modify the structure of database objects.

Examples:
- CREATE
- ALTER
- DROP
- TRUNCATE
- RENAME

### DML – Data Manipulation Language

DML commands are used to manipulate records stored inside tables.

Examples:
- INSERT
- UPDATE
- DELETE

### Difference Between DDL and DML

| Feature | DDL | DML |
|---|---|---|
| Full Form | Data Definition Language | Data Manipulation Language |
| Purpose | Defines database structure | Manipulates table data |
| Works On | Database objects | Records |
| Commands | CREATE, ALTER, DROP | INSERT, UPDATE, DELETE |
| WHERE Clause | Generally not applicable | Used with UPDATE and DELETE |
| Rollback | DDL causes implicit commit in MySQL | Transactional DML can be rolled back before COMMIT |
| Example | CREATE TABLE | INSERT INTO |

**Important:** In MySQL, TRUNCATE is classified as DDL, although it removes records. DELETE is DML.

---

# 4. INSERT Statement

The INSERT statement is used to add new records into an existing table.

## 4.1 Insert a Single Record

### Syntax

```sql
INSERT INTO table_name
VALUES (value1, value2, value3);
```

### Example

```sql
INSERT INTO student
VALUES (101, 'Anurag', 22, 'Pune');
```

**Explanation:**

- 101 → Student ID
- Anurag → Student Name
- 22 → Age
- Pune → City

## 4.2 Insert Data into Specific Columns

We can specify the column names explicitly.

### Syntax

```sql
INSERT INTO table_name (column1, column2)
VALUES (value1, value2);
```

### Example

```sql
INSERT INTO student (student_id, name, city)
VALUES (102, 'Rahul', 'Mumbai');
```

The age column receives its default value or NULL if it has no default and allows NULL.

**Advantage:** We do not need to provide values for every column if omitted columns have suitable defaults or permit NULL.

## 4.3 Insert Multiple Records

Multiple records can be inserted using a single INSERT statement.

### Syntax

```sql
INSERT INTO table_name
VALUES
(value1, value2),
(value3, value4);
```

### Example

```sql
INSERT INTO student
VALUES
(103, 'Amit', 21, 'Nashik'),
(104, 'Sneha', 22, 'Pune'),
(105, 'Priya', 23, 'Mumbai');
```

**Advantage:** Reduces the number of SQL statements required.

## 4.4 INSERT Using SELECT

We can insert records into one table using the results of another SELECT query.

```sql
INSERT INTO student_backup
SELECT * FROM student;
```

The source and destination columns must have compatible structures and ordering.

A safer approach is:

```sql
INSERT INTO student_backup
(student_id, name, age, city)
SELECT student_id, name, age, city
FROM student;
```

## 4.5 Insert Using DEFAULT

The DEFAULT keyword inserts the default value defined for a column.

```sql
INSERT INTO student
(student_id, name, age, city)
VALUES
(106, 'Karan', 22, DEFAULT);
```

## 4.6 View Inserted Records

```sql
SELECT * FROM student;
```

---

# 5. UPDATE Statement

The UPDATE statement is used to modify existing records in a table.

### Syntax

```sql
UPDATE table_name
SET column_name = value
WHERE condition;
```

## 5.1 Update a Single Record

```sql
UPDATE student
SET city = 'Mumbai'
WHERE student_id = 101;
```

This changes the city of student 101 to Mumbai.

## 5.2 Update Multiple Columns

```sql
UPDATE student
SET age = 23,
    city = 'Pune'
WHERE student_id = 101;
```

This updates both age and city for the selected student.

## 5.3 Update Multiple Records

```sql
UPDATE student
SET city = 'Pune'
WHERE age >= 22;
```

All students aged 22 or above will have their city changed to Pune.

## 5.4 Update Without WHERE

```sql
UPDATE student
SET city = 'Pune';
```

**Important:** This updates every record in the table.

Always check your WHERE condition before executing UPDATE.

## 5.5 Update Using Arithmetic Operations

```sql
UPDATE employee
SET salary = salary + 5000
WHERE emp_id = 101;
```

This increases the salary by 5000.

## 5.6 Update Using CASE

```sql
UPDATE student
SET grade =
    CASE
        WHEN marks >= 90 THEN 'A'
        WHEN marks >= 75 THEN 'B'
        WHEN marks >= 60 THEN 'C'
        ELSE 'D'
    END;
```

This assigns grades based on marks for every record.

## 5.7 Verify Updated Records

```sql
SELECT * FROM student;
```

---

# 6. DELETE Statement

The DELETE statement is used to remove existing records from a table.

### Syntax

```sql
DELETE FROM table_name
WHERE condition;
```

## 6.1 Delete a Specific Record

```sql
DELETE FROM student
WHERE student_id = 101;
```

Only the record with student_id 101 is deleted.

## 6.2 Delete Multiple Records

```sql
DELETE FROM student
WHERE city = 'Mumbai';
```

All records belonging to Mumbai are deleted.

## 6.3 Delete Records Using Conditions

```sql
DELETE FROM student
WHERE age < 18;
```

Deletes students whose age is below 18.

## 6.4 Delete All Records

```sql
DELETE FROM student;
```

This removes every record from the student table.

**Important:**

- The table structure remains.
- Columns remain.
- Indexes remain.
- DELETE triggers execute for deleted rows.
- AUTO_INCREMENT is not reset by deleting all rows.

## 6.5 Delete Using LIMIT

MySQL supports LIMIT in single-table DELETE statements.

```sql
DELETE FROM student
ORDER BY student_id
LIMIT 2;
```

This deletes two records based on the specified ordering.

## 6.6 Verify Deleted Records

```sql
SELECT * FROM student;
```

---

# 7. DELETE vs TRUNCATE

This is an important topic for CDAC theory examinations, practicals and interviews.

### DELETE

DELETE is a DML command used to remove selected or all records from a table.

```sql
DELETE FROM student
WHERE student_id = 101;
```

### TRUNCATE

TRUNCATE is a DDL command used to remove all records from a table while retaining its structure.

```sql
TRUNCATE TABLE student;
```

### Difference Between DELETE and TRUNCATE

| Feature | DELETE | TRUNCATE |
|---|---|---|
| Category | DML | DDL |
| WHERE Clause | Supported | Not supported |
| Selected Records | Yes | No |
| All Records | Yes | Yes |
| Table Structure | Retained | Retained |
| AUTO_INCREMENT | Not reset | Reset |
| Rollback | Possible before COMMIT for InnoDB | Not possible in MySQL |
| DELETE Triggers | Executed | Not executed |
| Execution | Row-based deletion | Efficient table-level operation |
| Implicit Commit | No | Yes |

### Important Questions

**Q1. Can DELETE remove all records?**

Yes.

```sql
DELETE FROM student;
```

**Q2. Can TRUNCATE delete selected records?**

No. TRUNCATE always removes all records.

**Q3. Can DELETE be rolled back?**

Yes, if the table uses InnoDB and the transaction has not been committed.

```sql
START TRANSACTION;

DELETE FROM student
WHERE student_id = 101;

ROLLBACK;
```

The deleted record is restored.

**Q4. Can TRUNCATE be rolled back in MySQL?**

No. TRUNCATE causes an implicit commit, so ROLLBACK cannot undo it.

**Q5. Does DELETE reset AUTO_INCREMENT?**

No, DELETE does not reset the AUTO_INCREMENT counter when deleting all rows.

---

# 8. Data Integrity

### What is Data Integrity?

Data integrity refers to the accuracy, consistency and reliability of data stored in a database.

It ensures that data remains valid and meaningful throughout its lifecycle.

### Types of Data Integrity

## 8.1 Entity Integrity

Entity integrity ensures that every record can be uniquely identified.

It is maintained using PRIMARY KEY.

Example:

```sql
CREATE TABLE student (
    student_id INT PRIMARY KEY,
    name VARCHAR(50)
);
```

A primary key cannot contain duplicate or NULL values.

## 8.2 Referential Integrity

Referential integrity ensures that relationships between tables remain valid.

It is maintained using FOREIGN KEY.

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

An employee cannot reference a department that does not exist, unless the foreign key permits NULL.

## 8.3 Domain Integrity

Domain integrity ensures that values entered into columns belong to valid domains.

It can be maintained using:
- Data types.
- NOT NULL.
- CHECK.
- DEFAULT.
- Other constraints.

Example:

```sql
CREATE TABLE student (
    student_id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    age INT CHECK (age >= 18)
);
```

## 8.4 User-Defined Integrity

User-defined integrity consists of business-specific rules.

Example:

An employee's salary must be greater than zero.

```sql
CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    salary DECIMAL(10,2)
        CHECK (salary > 0)
);
```

### Data Integrity Considerations While Modifying Data

1. Use WHERE conditions carefully in UPDATE and DELETE.
2. Do not insert duplicate primary keys.
3. Maintain foreign key relationships.
4. Follow datatype restrictions.
5. Do not insert NULL into NOT NULL columns.
6. Follow CHECK constraints.
7. Use transactions for critical modifications.
8. Verify changes using SELECT.
9. Take backups before major modifications.
10. Avoid accidental deletion of important records.

### Transaction Example

```sql
START TRANSACTION;

UPDATE employee
SET salary = salary + 5000
WHERE emp_id = 101;

SELECT * FROM employee
WHERE emp_id = 101;

COMMIT;
```

If the changes are incorrect and the transaction is still uncommitted:

```sql
ROLLBACK;
```

---

# 9. Lab Practicals

## Practical 1: Create Database

```sql
CREATE DATABASE dml_practice;

USE dml_practice;
```

## Practical 2: Create Student Table

```sql
CREATE TABLE student (
    student_id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    age INT,
    city VARCHAR(50),
    email VARCHAR(100) UNIQUE
);
```

## Practical 3: Insert Single Record

```sql
INSERT INTO student
VALUES
(101, 'Anurag', 22, 'Pune', 'anurag@gmail.com');
```

## Practical 4: Insert Multiple Records

```sql
INSERT INTO student
VALUES
(102, 'Rahul', 23, 'Mumbai', 'rahul@gmail.com'),
(103, 'Amit', 21, 'Nashik', 'amit@gmail.com'),
(104, 'Sneha', 22, 'Pune', 'sneha@gmail.com'),
(105, 'Priya', 24, 'Mumbai', 'priya@gmail.com');
```

## Practical 5: Display All Records

```sql
SELECT * FROM student;
```

## Practical 6: Update Specific Record

```sql
UPDATE student
SET city = 'Nagpur'
WHERE student_id = 103;
```

## Practical 7: Update Multiple Columns

```sql
UPDATE student
SET age = 23,
    city = 'Pune'
WHERE student_id = 104;
```

## Practical 8: Delete Selected Records

```sql
DELETE FROM student
WHERE student_id = 105;
```

## Practical 9: Delete Records Using Condition

```sql
DELETE FROM student
WHERE age < 22;
```

## Practical 10: Delete All Records

```sql
DELETE FROM student;
```

## Practical 11: Insert Records Again

```sql
INSERT INTO student
VALUES
(106, 'Karan', 22, 'Pune', 'karan@gmail.com'),
(107, 'Rohit', 23, 'Mumbai', 'rohit@gmail.com');
```

## Practical 12: Truncate Table

```sql
TRUNCATE TABLE student;
```

## Practical 13: Compare DELETE and TRUNCATE

Perform these operations separately and observe:

1. Insert sample records.
2. Execute DELETE FROM student.
3. Check table structure using DESC student.
4. Insert new records.
5. Execute TRUNCATE TABLE student.
6. Check table structure again.
7. Compare AUTO_INCREMENT behavior if you use an AUTO_INCREMENT column.

---

# 10. Important Interview Questions

**Q1. What is DML?**

DML stands for Data Manipulation Language. It is used to insert, update and delete records in database tables.

**Q2. What are the main DML commands?**

INSERT, UPDATE and DELETE.

**Q3. What is the difference between DDL and DML?**

DDL modifies database structures, whereas DML manipulates records stored inside tables.

**Q4. How do you insert multiple records in one SQL statement?**

Using multiple VALUES clauses in a single INSERT statement.

**Q5. What happens if UPDATE is executed without WHERE?**

All records in the table are updated.

**Q6. What happens if DELETE is executed without WHERE?**

All records in the table are deleted, but the table structure remains.

**Q7. Can we rollback DELETE?**

Yes, if using a transactional engine such as InnoDB and the transaction is not committed.

**Q8. What is the difference between DELETE and TRUNCATE?**

DELETE is DML and supports WHERE. TRUNCATE is DDL and removes all records without WHERE.

**Q9. What is referential integrity?**

It ensures that foreign key references point to valid records in related tables.

**Q10. What is entity integrity?**

It ensures that each table record has a unique, non-NULL primary key.

**Q11. What is domain integrity?**

It ensures that values entered into columns follow their defined datatype and validation rules.

**Q12. Why should we use transactions?**

Transactions help maintain database consistency and allow uncommitted changes to be rolled back.

---

# 11. Important MCQs

**Q1. Which command is used to insert records?**

A. UPDATE  
B. DELETE  
C. INSERT  
D. ALTER  

**Answer: C**

**Q2. Which command modifies existing records?**

A. CREATE  
B. UPDATE  
C. DROP  
D. TRUNCATE  

**Answer: B**

**Q3. Which clause is used to specify conditions in UPDATE?**

A. ORDER BY  
B. GROUP BY  
C. WHERE  
D. HAVING  

**Answer: C**

**Q4. What happens when UPDATE is executed without WHERE?**

A. One record is updated  
B. No record is updated  
C. All records are updated  
D. Table is deleted  

**Answer: C**

**Q5. Which command supports selective deletion?**

A. TRUNCATE  
B. DELETE  
C. DROP  
D. CREATE  

**Answer: B**

**Q6. Which command resets AUTO_INCREMENT in MySQL?**

A. DELETE  
B. UPDATE  
C. TRUNCATE  
D. SELECT  

**Answer: C**

**Q7. Which constraint maintains referential integrity?**

A. UNIQUE  
B. CHECK  
C. FOREIGN KEY  
D. DEFAULT  

**Answer: C**

**Q8. Which command is DDL?**

A. INSERT  
B. UPDATE  
C. DELETE  
D. TRUNCATE  

**Answer: D**

**Q9. Which command can be rolled back before COMMIT in an InnoDB transaction?**

A. TRUNCATE  
B. DELETE  
C. DROP TABLE  
D. ALTER TABLE  

**Answer: B**

**Q10. Which constraint prevents duplicate primary key values?**

A. DEFAULT  
B. NOT NULL  
C. PRIMARY KEY  
D. CHECK  

**Answer: C**

---

# 12. Quick Revision

| Concept | Remember |
|---|---|
| DML | Manipulates records |
| INSERT | Adds records |
| UPDATE | Modifies records |
| DELETE | Removes records |
| WHERE | Specifies conditions |
| INSERT Multiple | Multiple VALUES clauses |
| DELETE Without WHERE | Deletes all records |
| UPDATE Without WHERE | Updates all records |
| TRUNCATE | Removes all rows |
| Entity Integrity | Primary Key |
| Referential Integrity | Foreign Key |
| Domain Integrity | Valid column values |
| COMMIT | Saves transaction changes |
| ROLLBACK | Cancels uncommitted changes |

---

# 13. Practice Checklist

- [ ] Understand DML commands.
- [ ] Differentiate between DDL and DML.
- [ ] Create a database and student table.
- [ ] Insert a single record.
- [ ] Insert multiple records.
- [ ] Insert records using specific columns.
- [ ] Insert records using SELECT.
- [ ] Update a specific record.
- [ ] Update multiple columns.
- [ ] Update multiple records using conditions.
- [ ] Delete selected records using WHERE.
- [ ] Delete all records using DELETE.
- [ ] Use TRUNCATE to remove all records.
- [ ] Compare DELETE and TRUNCATE.
- [ ] Understand entity integrity.
- [ ] Understand referential integrity.
- [ ] Understand domain integrity.
- [ ] Practice COMMIT and ROLLBACK.
- [ ] Solve MCQs and interview questions.

---

## Recommended Learning Resources

1. MySQL Documentation: https://dev.mysql.com/doc/
2. W3Schools SQL Tutorial: https://www.w3schools.com/sql/
3. GeeksforGeeks DBMS: https://www.geeksforgeeks.org/dbms/
4. SQL Practice: https://www.sql-practice.com/

---

**End of Session 4 – DML Commands**

*Database Technologies | PGCP-AC | CMCE | August 2026*

**Learning Goal:** Understand DML commands, perform INSERT, UPDATE and DELETE operations, maintain data integrity and understand the practical differences between DELETE and TRUNCATE.
