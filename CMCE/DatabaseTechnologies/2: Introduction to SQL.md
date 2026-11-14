# Session 2: Introduction to SQL

## Database Technologies | PGCP-AC | CMCE | August 2026

 
**Course:** PGCP-AC  
**Subject:** Database Technologies  
**Session:** 02 – Introduction to SQL  
**Duration:** 1 Theory + 2 Lab + 2 Self Learning Hours

---

## 📚 Table of Contents

1. [Introduction to SQL](#1-introduction-to-sql)
2. [Categories of SQL Commands](#2-categories-of-sql-commands)
3. [Data Definition Language (DDL)](#3-data-definition-language-ddl)
4. [CREATE Statement](#4-create-statement)
5. [ALTER Statement](#5-alter-statement)
6. [DROP Statement](#6-drop-statement)
7. [TRUNCATE Statement](#7-truncate-statement)
8. [DELETE vs TRUNCATE](#8-delete-vs-truncate)
9. [RENAME Statement](#9-rename-statement)
10. [MySQL Clients](#10-mysql-clients)
11. [Lab Practicals](#11-lab-practicals)
12. [Important Questions](#12-important-questions)
13. [Quick Revision](#13-quick-revision)
14. [Practice Checklist](#14-practice-checklist)

---

## 1. Introduction to SQL

**SQL (Structured Query Language)** is a standard language used to communicate with relational database management systems (RDBMS).

It is used to create, retrieve, insert, update, delete and manage data in databases.

**Examples:** MySQL, Oracle, PostgreSQL and Microsoft SQL Server.

### Uses of SQL

- Creating databases and tables.
- Inserting records.
- Retrieving data.
- Updating existing records.
- Deleting records.
- Managing database permissions.
- Managing transactions.

---

## 2. Categories of SQL Commands

SQL commands are classified into the following categories:

| Category | Full Form | Purpose |
|---|---|---|
| DDL | Data Definition Language | Defines database structure |
| DML | Data Manipulation Language | Manipulates table records |
| DQL | Data Query Language | Retrieves records |
| DCL | Data Control Language | Controls database permissions |
| TCL / DTL | Transaction Control Language | Manages transactions |

### 2.1 DDL – Data Definition Language

Used to create and modify database structures.

**Commands:**
- CREATE
- ALTER
- DROP
- TRUNCATE
- RENAME

### 2.2 DML – Data Manipulation Language

Used to manipulate records inside tables.

**Commands:**
- INSERT
- UPDATE
- DELETE

### 2.3 DQL – Data Query Language

Used to retrieve records.

**Command:**
- SELECT

### 2.4 DCL – Data Control Language

Used to manage database permissions.

**Commands:**
- GRANT
- REVOKE

### 2.5 TCL – Transaction Control Language

Used to manage database transactions.

**Commands:**
- COMMIT
- ROLLBACK
- SAVEPOINT

---

## 3. Data Definition Language (DDL)

DDL commands are used to define, modify and remove database objects such as databases and tables.

The important DDL commands are CREATE, ALTER, DROP, TRUNCATE and RENAME.

## 4. CREATE Statement

The `CREATE` statement is used to create database objects such as databases and tables.

### Create Database

```sql
CREATE DATABASE college;

USE college;
```

### Create Table

```sql
CREATE TABLE student (
    roll_no INT,
    name VARCHAR(50),
    age INT,
    city VARCHAR(50)
);
```

### Create Table with Constraints

```sql
CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    salary DECIMAL(10,2),
    city VARCHAR(50) DEFAULT 'Pune'
);
```

### Useful Commands

```sql
SHOW DATABASES;

SHOW TABLES;

DESC student;

SHOW CREATE TABLE student;
```

---

## 5. ALTER Statement

The `ALTER` statement is used to modify the structure of an existing table.

### Add a Column

```sql
ALTER TABLE student
ADD email VARCHAR(100);
```

### Add Multiple Columns

```sql
ALTER TABLE student
ADD phone VARCHAR(15),
ADD course VARCHAR(50);
```

### Modify Column Datatype

```sql
ALTER TABLE student
MODIFY name VARCHAR(100);
```

### Rename a Column

```sql
ALTER TABLE student
RENAME COLUMN name TO student_name;
```

### Change Column Name and Datatype

```sql
ALTER TABLE student
CHANGE student_name name VARCHAR(80);
```

### Drop a Column

```sql
ALTER TABLE student
DROP COLUMN email;
```

### Add Primary Key

```sql
ALTER TABLE student
ADD PRIMARY KEY (roll_no);
```

### Drop Primary Key

```sql
ALTER TABLE student
DROP PRIMARY KEY;
```

### Add Foreign Key

```sql
ALTER TABLE employee
ADD CONSTRAINT fk_dept
FOREIGN KEY (dept_id)
REFERENCES department(dept_id);
```

---

## 6. DROP Statement

The `DROP` statement is used to permanently remove database objects.

### Drop Database

```sql
DROP DATABASE college;
```

### Drop Table

```sql
DROP TABLE student;
```

### Drop If Exists

```sql
DROP TABLE IF EXISTS student;
```

**Remember:** DROP removes both the table structure and its data.

---

## 7. TRUNCATE Statement

The `TRUNCATE` statement removes all records from a table while keeping its structure.

### Syntax

```sql
TRUNCATE TABLE student;
```

**Important Points:**

- Removes all records.
- Retains table structure.
- Does not support WHERE clause.
- Resets AUTO_INCREMENT in MySQL.
- Causes an implicit commit.
- Cannot be rolled back in MySQL.

---

## 8. DELETE vs TRUNCATE

| Feature | DELETE | TRUNCATE |
|---|---|---|
| Category | DML | DDL |
| Purpose | Removes records | Removes all records |
| WHERE clause | Supported | Not supported |
| Selected records | Yes | No |
| Table structure | Retained | Retained |
| AUTO_INCREMENT | Not reset generally | Reset |
| Rollback | Possible before COMMIT with InnoDB | Not possible in MySQL |
| DELETE triggers | Executed | Not executed |
| Implicit commit | No | Yes |

### DELETE Example

```sql
DELETE FROM student
WHERE roll_no = 101;
```

### Delete All Records

```sql
DELETE FROM student;
```

### TRUNCATE Example

```sql
TRUNCATE TABLE student;
```

**Important Interview Question:** Can we use WHERE with TRUNCATE?

**Answer:** No. TRUNCATE removes all records and does not support the WHERE clause.

---

## 9. RENAME Statement

The `RENAME` statement is used to change the name of an existing table.

### Syntax

```sql
RENAME TABLE old_table_name
TO new_table_name;
```

### Example

```sql
RENAME TABLE student
TO students;
```

### Rename Multiple Tables

```sql
RENAME TABLE
student TO students,
employee TO employees;
```

Alternative:

```sql
ALTER TABLE students
RENAME TO student;
```

---

## 10. MySQL Clients

MySQL provides different clients to communicate with the MySQL Server.

### 10.1 MySQL Monitor

A traditional command-line client used to execute SQL statements.

```bash
mysql -u root -p
```

### 10.2 MySQL Shell

An advanced command-line client supporting three modes:

| Mode | Description |
|---|---|
| SQL | Executes SQL statements |
| JavaScript | Executes JavaScript |
| Python | Executes Python |

```bash
mysqlsh
```

Useful commands:

```text
\connect root@localhost
\sql
\js
\py
```

### 10.3 MySQL Workbench

A graphical user interface (GUI) tool used for:

- SQL query execution.
- Database administration.
- Visual database design.
- ER diagram creation.
- Database modeling.

**Comparison:**

| Feature | Monitor | Shell | Workbench |
|---|---|---|---|
| Interface | CLI | CLI | GUI |
| SQL | Yes | Yes | Yes |
| JavaScript | No | Yes | No |
| Python | No | Yes | No |
| Visual ER Diagram | No | No | Yes |

---

## 11. Lab Practicals

### Practical 1: Database Creation

```sql
CREATE DATABASE cmce_db;

USE cmce_db;

SHOW DATABASES;
```

### Practical 2: Table Creation

```sql
CREATE TABLE student (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    city VARCHAR(50)
);
```

### Practical 3: ALTER Operations

```sql
ALTER TABLE student
ADD email VARCHAR(100);

ALTER TABLE student
MODIFY name VARCHAR(100);

ALTER TABLE student
RENAME COLUMN name TO student_name;

ALTER TABLE student
DROP COLUMN email;
```

### Practical 4: RENAME Table

```sql
RENAME TABLE student
TO students;
```

### Practical 5: TRUNCATE Table

```sql
TRUNCATE TABLE students;
```

### Practical 6: DROP Table and Database

```sql
DROP TABLE students;

DROP DATABASE cmce_db;
```

---

## 12. Important Questions

1. What is SQL? Explain its applications.
2. Explain different categories of SQL commands.
3. Differentiate between DDL and DML.
4. Explain CREATE, ALTER, DROP, TRUNCATE and RENAME.
5. Differentiate between DELETE and TRUNCATE.
6. Differentiate between DROP and TRUNCATE.
7. How do you add and remove columns using ALTER?
8. How do you modify a column datatype?
9. Can we use WHERE with TRUNCATE?
10. Explain MySQL Monitor, Shell and Workbench.

---

## 13. Quick Revision

| Command | Purpose |
|---|---|
| CREATE | Create database/table |
| ALTER | Modify table structure |
| ADD | Add a column |
| MODIFY | Change column definition |
| CHANGE | Rename and modify column |
| DROP COLUMN | Remove a column |
| DROP TABLE | Remove complete table |
| TRUNCATE | Remove all records |
| DELETE | Remove selected/all records |
| RENAME | Rename table |
| DESC | Display table structure |
| SHOW DATABASES | Display databases |
| SHOW TABLES | Display tables |
| USE | Select database |

---

## 14. Practice Checklist

- [ ] Understand SQL command categories.
- [ ] Practice CREATE DATABASE.
- [ ] Practice CREATE TABLE.
- [ ] Practice ALTER ADD.
- [ ] Practice ALTER MODIFY.
- [ ] Practice ALTER CHANGE.
- [ ] Practice ALTER DROP COLUMN.
- [ ] Practice DROP DATABASE and DROP TABLE.
- [ ] Understand DELETE vs TRUNCATE.
- [ ] Practice RENAME TABLE.
- [ ] Execute commands using MySQL Monitor.
- [ ] Execute commands using MySQL Shell.
- [ ] Execute commands using MySQL Workbench.
- [ ] Complete all lab practicals.

---

## Recommended Resources

- [MySQL Official Documentation](https://dev.mysql.com/doc/)
- [MySQL Workbench Download](https://dev.mysql.com/downloads/workbench/)
- [W3Schools SQL Tutorial](https://www.w3schools.com/sql/)
- [GeeksforGeeks DBMS](https://www.geeksforgeeks.org/dbms/)

---

**End of Session 2 – Introduction to SQL**

*Database Technologies | PGCP-AC | CMCE | August 2026*

**Note:** These notes are prepared for learning, practical implementation, theory examinations and technical interview preparation.
