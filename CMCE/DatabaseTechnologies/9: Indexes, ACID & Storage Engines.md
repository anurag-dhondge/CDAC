# Session 9: Indexes, ACID & Storage Engines

**Course:** CMCE – Database Technologies  
**Batch:** August 2026  
**Theory:** 1 Hour | **Lab:** 1 Hour

---

## 📌 Topics Covered

1. Introduction to Indexes
2. Benefits of Indexes
3. Types of Indexes
4. Clustered and Non-Clustered Indexes
5. Composite Indexes
6. Temporary Tables
7. ACID Properties
8. Database Instance and Schema
9. MySQL Storage Engines
   - InnoDB
   - MyISAM
   - MEMORY
   - CSV
   - ARCHIVE
10. SQL Commands Revision

---

# 1. Introduction to Indexes

An **Index** is a database object or data structure used to improve the speed of data retrieval operations.

It works similarly to an index in a book. Instead of searching every page, we can use the index to find the required information quickly.

### Example

Consider an employee table containing 1,00,000 records.

Without an index, MySQL may need to scan many rows to find a particular employee.

With a suitable index on `employee_name`, MySQL can locate matching records more efficiently.

### Syntax

```sql
CREATE INDEX index_name
ON table_name(column_name);
```

### Example

```sql
CREATE INDEX idx_employee_name
ON employees(employee_name);
```

Query using the indexed column:

```sql
SELECT *
FROM employees
WHERE employee_name = 'Anurag';
```

MySQL's query optimizer decides whether using the index is beneficial for this query.

---

# 2. Benefits of Indexes

Indexes provide several benefits:

1. **Faster Searching:** Helps retrieve records faster.
2. **Improved Query Performance:** Can improve queries using `WHERE`.
3. **Faster Joins:** Can improve joins when suitable join columns are indexed.
4. **Sorting:** Can help with `ORDER BY` operations.
5. **Grouping:** Can improve some `GROUP BY` operations.
6. **Uniqueness:** Unique indexes prevent duplicate indexed values.
7. **Efficient Data Retrieval:** Reduces the need for full table scans in suitable queries.

### Disadvantages of Indexes

1. Requires additional storage space.
2. Can slow down INSERT operations.
3. Can slow down UPDATE operations.
4. Can slow down DELETE operations.
5. Too many indexes increase database maintenance overhead.

**Important:** Indexes improve read performance in suitable cases, but they are not guaranteed to make every query faster.

---

# 3. Types of Indexes

## 3.1 Primary Key Index

A Primary Key uniquely identifies every record in a table.

- Does not allow duplicate values.
- Does not allow NULL values.
- MySQL InnoDB automatically creates a clustered index for the primary key.

### Example

```sql
CREATE TABLE students (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    age INT
);
```

## 3.2 Unique Index

A Unique Index prevents duplicate values in the indexed column or combination of columns.

### Example

```sql
CREATE UNIQUE INDEX idx_unique_email
ON students(email);
```

This requires an `email` column in the table.

**Note:** MySQL UNIQUE indexes permit multiple NULL values in a nullable column.

## 3.3 Normal (Non-Unique) Index

A normal index improves searching but allows duplicate values.

### Example

```sql
CREATE INDEX idx_student_name
ON students(student_name);
```

## 3.4 Composite Index

A Composite Index is an index created on two or more columns.

### Example

```sql
CREATE INDEX idx_student_name_age
ON students(student_name, age);
```

This index can help queries such as:

```sql
SELECT *
FROM students
WHERE student_name = 'Anurag';
```

It can also help:

```sql
SELECT *
FROM students
WHERE student_name = 'Anurag'
AND age = 22;
```

### Leftmost Prefix Principle

For a composite index:

```sql
CREATE INDEX idx_dept_salary
ON employees(department, salary);
```

The index can generally help queries using:

- `department`
- `department` and `salary`

But it generally cannot be used as an efficient lookup index for a query filtering only by `salary`.

## 3.5 Full-Text Index

A Full-Text Index is used for text searching in supported text columns.

### Example

```sql
CREATE TABLE articles (
    article_id INT PRIMARY KEY,
    title VARCHAR(100),
    content TEXT,
    FULLTEXT(title, content)
);
```

Search text:

```sql
SELECT *
FROM articles
WHERE MATCH(title, content)
AGAINST('database');
```

## 3.6 Spatial Index

A Spatial Index is used for spatial or geographical data.

It is commonly used with geometry data types.

### Example

```sql
CREATE TABLE locations (
    location_id INT PRIMARY KEY,
    position POINT NOT NULL,
    SPATIAL INDEX idx_position(position)
);
```

---

# 4. Clustered and Non-Clustered Indexes

## 4.1 Clustered Index

A Clustered Index determines how table records are organized in the storage structure.

In MySQL InnoDB, the table data is stored in the clustered index structure.

- Primary key is the clustered index by default.
- Only one clustered index exists per InnoDB table.
- Secondary indexes contain the primary key value as the row locator.

## 4.2 Non-Clustered Index

A Non-Clustered Index is a separate index structure that stores indexed values and references to the corresponding records.

In InnoDB, secondary indexes store the indexed column values along with the primary key.

### Difference Between Clustered and Non-Clustered Indexes

| Clustered Index | Secondary (Non-Clustered) Index |
|---|---|
| Organizes the table's data | Separate index structure |
| InnoDB primary key is clustered by default | Created on other indexed columns |
| One per InnoDB table | Multiple can exist |
| Stores the actual row data in its leaf pages | Stores indexed values and primary key references |

**Note:** Clustered and non-clustered index terminology is commonly used in database theory. MySQL InnoDB specifically implements a clustered primary-key index and secondary indexes.

---

# 5. Other Index Operations

## 5.1 Create an Index

```sql
CREATE INDEX idx_salary
ON employees(salary);
```

## 5.2 Create a Unique Index

```sql
CREATE UNIQUE INDEX idx_email
ON students(email);
```

## 5.3 Create a Composite Index

```sql
CREATE INDEX idx_department_salary
ON employees(department, salary);
```

## 5.4 Display Indexes

```sql
SHOW INDEXES FROM employees;
```

## 5.5 Drop an Index

```sql
DROP INDEX idx_salary
ON employees;
```

## 5.6 Check Query Execution Plan

```sql
EXPLAIN
SELECT *
FROM employees
WHERE salary > 50000;
```

`EXPLAIN` displays the execution plan chosen by the MySQL optimizer.

It helps us understand:

- Which table is accessed.
- Which indexes are considered.
- Whether an index is used.
- How many rows may be examined.
- The join or access method.

---

# 6. Temporary Tables

A **Temporary Table** is a table used to store temporary data during a database session.

### Characteristics

- Created using `CREATE TEMPORARY TABLE`.
- Visible only within the current session.
- Automatically dropped when the session ends.
- Can be manually deleted.
- Different sessions can have temporary tables with the same name.

## 6.1 Create Temporary Table

```sql
CREATE TEMPORARY TABLE temp_employees (
    emp_id INT,
    employee_name VARCHAR(50),
    salary DECIMAL(10,2)
);
```

## 6.2 Insert Records

```sql
INSERT INTO temp_employees
VALUES
(1, 'Anurag', 60000),
(2, 'Rahul', 50000),
(3, 'Amit', 45000);
```

## 6.3 Display Records

```sql
SELECT *
FROM temp_employees;
```

## 6.4 Create Temporary Table Using SELECT

```sql
CREATE TEMPORARY TABLE high_salary_employees AS
SELECT *
FROM employees
WHERE salary > 50000;
```

## 6.5 Drop Temporary Table

```sql
DROP TEMPORARY TABLE temp_employees;
```

### Temporary Table vs Normal Table

| Temporary Table | Normal Table |
|---|---|
| Session-specific | Persistent |
| Automatically dropped when session ends | Exists until dropped |
| Used for intermediate operations | Used for permanent data storage |
| Can have the same name in different sessions | Table names are shared within the schema |

---

# 7. ACID Properties

ACID is a set of four important properties that ensure reliable database transactions.

ACID stands for:

- A – Atomicity
- C – Consistency
- I – Isolation
- D – Durability

## 7.1 Atomicity

Atomicity means a transaction is treated as a single unit.

Either all operations are completed successfully or none of them are applied.

### Example: Bank Transfer

Suppose Anurag transfers ₹1,000 to Rahul.

Two operations are required:

1. Deduct ₹1,000 from Anurag's account.
2. Add ₹1,000 to Rahul's account.

If the second operation fails, the first operation should also be rolled back.

```sql
START TRANSACTION;

UPDATE accounts
SET balance = balance - 1000
WHERE account_id = 1;

UPDATE accounts
SET balance = balance + 1000
WHERE account_id = 2;

COMMIT;
```

If an error occurs before committing:

```sql
ROLLBACK;
```

## 7.2 Consistency

Consistency ensures that a transaction takes the database from one valid state to another valid state.

All defined constraints and rules must remain satisfied.

### Example

A bank account should not have a negative balance if the business rules prohibit it.

```sql
CREATE TABLE accounts (
    account_id INT PRIMARY KEY,
    balance DECIMAL(10,2) CHECK (balance >= 0)
);
```

A transaction must preserve this constraint.

## 7.3 Isolation

Isolation ensures that concurrent transactions do not interfere with each other in a way that violates the required transaction isolation rules.

It controls how transactions access data while other transactions are running.

### Example

Two users try to update the same bank account at the same time.

Isolation helps prevent incorrect results caused by conflicting concurrent operations.

### MySQL InnoDB Isolation Levels

1. READ UNCOMMITTED
2. READ COMMITTED
3. REPEATABLE READ
4. SERIALIZABLE

MySQL InnoDB uses REPEATABLE READ by default.

## 7.4 Durability

Durability ensures that committed transaction changes survive failures such as a server restart, subject to the database's durability configuration and underlying storage reliability.

### Example

After a bank transfer is committed successfully, the updated balances should remain saved even if the database server restarts.

### ACID Summary

| Property | Meaning | Example |
|---|---|---|
| Atomicity | All or nothing | Both bank transfer operations succeed or roll back |
| Consistency | Maintains valid data | Account balance follows business rules |
| Isolation | Controls concurrent transactions | Simultaneous updates are handled safely |
| Durability | Committed changes persist | Data remains after server restart |

---

# 8. Database Instance and Schema

## 8.1 Database Schema

A **Database Schema** is the logical structure or design of a database.

It defines how database objects are organized.

It includes:

- Tables
- Columns
- Data types
- Constraints
- Relationships
- Views
- Indexes
- Stored procedures

### Example

```sql
CREATE DATABASE college;
```

Create a table inside the schema:

```sql
USE college;

CREATE TABLE students (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    age INT
);
```

Here, `college` is the database/schema name, and `students` is a table.

## 8.2 Database Instance

A **Database Instance** generally refers to the running database environment and its current state at a particular time.

It includes the data currently stored in the database and, in a database system such as MySQL, the running server processes and memory structures that manage access to that data.

### Example

Consider a college database:

**Schema:**

```text
College
 ├── Students
 ├── Teachers
 ├── Courses
 └── Departments
```

**Instance:**

The actual records currently stored in these tables at a particular time.

### Schema vs Instance

| Database Schema | Database Instance |
|---|---|
| Logical structure/design | Current database state |
| Changes less frequently | Changes frequently |
| Defines tables and relationships | Contains current records |
| Similar to a blueprint | Similar to the actual data at a given time |

**Important:** In database theory, schema means the database's logical structure, while instance means its data at a particular point in time. In MySQL administration, the term database instance is also commonly used for a running MySQL server environment.

---

# 9. MySQL Storage Engines

A **Storage Engine** is the component responsible for managing how MySQL stores, retrieves, and processes table data.

MySQL supports multiple storage engines.

Different storage engines provide different features and performance characteristics.

### Common MySQL Storage Engines

1. InnoDB
2. MyISAM
3. MEMORY
4. CSV
5. ARCHIVE

---

# 10. InnoDB Storage Engine

InnoDB is the default storage engine in modern MySQL.

It is widely used for transactional applications.

### Features

- Supports ACID properties.
- Supports transactions.
- Supports COMMIT and ROLLBACK.
- Supports foreign keys.
- Supports row-level locking.
- Supports crash recovery.
- Uses clustered indexes.
- Supports MVCC (Multi-Version Concurrency Control).

### Example

```sql
CREATE TABLE students (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50)
) ENGINE = InnoDB;
```

### When to Use InnoDB?

- Banking applications.
- E-commerce websites.
- College management systems.
- Applications requiring transactions.
- Applications requiring foreign key constraints.

---

# 11. MyISAM Storage Engine

MyISAM is an older MySQL storage engine.

It is designed primarily for read-heavy workloads but does not provide the transactional features of InnoDB.

### Features

- Does not support transactions.
- Does not support COMMIT and ROLLBACK.
- Does not support foreign keys.
- Uses table-level locking.
- Supports indexes.
- Does not provide InnoDB-style crash recovery.

### Example

```sql
CREATE TABLE old_records (
    id INT PRIMARY KEY,
    name VARCHAR(50)
) ENGINE = MyISAM;
```

### When to Use MyISAM?

It may be useful for certain legacy or read-heavy workloads where transactional features are not required.

For most new general-purpose MySQL applications, InnoDB is preferred.

---

# 12. Other MySQL Storage Engines

## 12.1 MEMORY

The MEMORY engine stores table data in memory.

### Features

- Uses memory for data storage.
- Provides fast data access.
- Data is lost when the MySQL server stops.
- Uses table-level locking.
- Useful for temporary or intermediate data.

### Example

```sql
CREATE TABLE temp_data (
    id INT,
    name VARCHAR(50)
) ENGINE = MEMORY;
```

**Note:** MEMORY tables are different from `CREATE TEMPORARY TABLE`. A MEMORY table is a normal table using the MEMORY engine, whereas a temporary table is session-specific. A MEMORY table's data is lost on server restart, but its table definition remains.

## 12.2 CSV

The CSV engine stores table data in CSV format.

### Features

- Stores data as comma-separated values.
- Useful for data exchange.
- Does not support indexes like InnoDB.
- Does not support transactions.

### Example

```sql
CREATE TABLE csv_students (
    id INT,
    name VARCHAR(50)
) ENGINE = CSV;
```

## 12.3 ARCHIVE

The ARCHIVE engine is designed for storing large amounts of archived data.

### Features

- Uses compressed storage.
- Suitable for historical or archived data.
- Does not support transactions.
- Does not support indexes like InnoDB.

### Example

```sql
CREATE TABLE archived_logs (
    id INT,
    log_message TEXT
) ENGINE = ARCHIVE;
```

---

# 13. InnoDB vs MyISAM

| Feature | InnoDB | MyISAM |
|---|---|---|
| Transactions | Supported | Not supported |
| ACID | Supported | Not fully supported |
| COMMIT | Supported | Not supported |
| ROLLBACK | Supported | Not supported |
| Foreign Keys | Supported | Not supported |
| Locking | Row-level and other locks | Table-level |
| Crash Recovery | Supported | Limited |
| MVCC | Supported | Not supported |
| Clustered Index | Supported | Not supported |
| Default Engine | Yes, in modern MySQL | No |
| Recommended Use | Most transactional applications | Certain legacy/read-heavy workloads |

### Important Interview Point

**Which storage engine should be preferred for a banking application?**

InnoDB, because it supports transactions, ACID properties, foreign keys, and crash recovery.

---

# 14. Check and Change Storage Engine

## Check Default Storage Engine

```sql
SHOW VARIABLES LIKE 'default_storage_engine';
```

## Check Table Storage Engine

```sql
SHOW TABLE STATUS
WHERE Name = 'students';
```

## Change Storage Engine

```sql
ALTER TABLE students ENGINE = InnoDB;
```

## Display Supported Storage Engines

```sql
SHOW ENGINES;
```

---

# 15. Lab Practicals

## Practical 1: Create an Index

```sql
CREATE INDEX idx_student_name
ON students(student_name);
```

## Practical 2: Create a Unique Index

```sql
CREATE UNIQUE INDEX idx_unique_student
ON students(student_id);
```

## Practical 3: Create a Composite Index

```sql
CREATE INDEX idx_name_age
ON students(student_name, age);
```

## Practical 4: Display Indexes

```sql
SHOW INDEXES FROM students;
```

## Practical 5: Drop an Index

```sql
DROP INDEX idx_student_name
ON students;
```

## Practical 6: Check Query Execution Plan

```sql
EXPLAIN
SELECT *
FROM students
WHERE student_name = 'Anurag';
```

## Practical 7: Create a Temporary Table

```sql
CREATE TEMPORARY TABLE temp_students (
    id INT,
    name VARCHAR(50)
);
```

## Practical 8: Insert Records into Temporary Table

```sql
INSERT INTO temp_students
VALUES
(1, 'Anurag'),
(2, 'Rahul');
```

## Practical 9: Display Temporary Table Records

```sql
SELECT *
FROM temp_students;
```

## Practical 10: Drop Temporary Table

```sql
DROP TEMPORARY TABLE temp_students;
```

## Practical 11: Create an InnoDB Table

```sql
CREATE TABLE innodb_students (
    id INT PRIMARY KEY,
    name VARCHAR(50)
) ENGINE = InnoDB;
```

## Practical 12: Create a MyISAM Table

```sql
CREATE TABLE myisam_students (
    id INT PRIMARY KEY,
    name VARCHAR(50)
) ENGINE = MyISAM;
```

## Practical 13: Display Storage Engines

```sql
SHOW ENGINES;
```

## Practical 14: Check Table Storage Engine

```sql
SHOW TABLE STATUS
WHERE Name = 'innodb_students';
```

---

# 16. SQL Commands – Complete Revision

This section covers the important SQL commands from previous sessions.

## 16.1 DDL – Data Definition Language

DDL commands are used to define or modify database structures.

| Command | Purpose |
|---|---|
| CREATE | Creates database objects |
| ALTER | Modifies database objects |
| DROP | Deletes database objects |
| TRUNCATE | Removes all rows from a table |
| RENAME | Renames a database object |

Examples:

```sql
CREATE DATABASE college;

USE college;

CREATE TABLE students (
    id INT PRIMARY KEY,
    name VARCHAR(50)
);

ALTER TABLE students
ADD age INT;

RENAME TABLE students TO student_details;

TRUNCATE TABLE student_details;

DROP TABLE student_details;
```

## 16.2 DML – Data Manipulation Language

DML commands are used to manipulate table data.

| Command | Purpose |
|---|---|
| INSERT | Adds records |
| UPDATE | Modifies records |
| DELETE | Deletes records |

Examples:

```sql
INSERT INTO students
VALUES (1, 'Anurag', 22);
```

```sql
UPDATE students
SET age = 23
WHERE id = 1;
```

```sql
DELETE FROM students
WHERE id = 1;
```

## 16.3 DQL – Data Query Language

DQL is commonly used to refer to commands used to retrieve data.

```sql
SELECT *
FROM students;
```

## 16.4 DCL – Data Control Language

DCL manages database privileges.

```sql
GRANT SELECT
ON college.students
TO 'user1'@'localhost';
```

```sql
REVOKE SELECT
ON college.students
FROM 'user1'@'localhost';
```

## 16.5 TCL – Transaction Control Language

TCL manages database transactions.

```sql
START TRANSACTION;

UPDATE students
SET age = 24
WHERE id = 1;

COMMIT;
```

```sql
START TRANSACTION;

UPDATE students
SET age = 25
WHERE id = 1;

ROLLBACK;
```

---

# 17. Important SQL Topics for Revision

| Topic | Important Commands / Functions |
|---|---|
| Database Operations | CREATE DATABASE, USE, DROP DATABASE |
| Table Operations | CREATE, ALTER, DROP, TRUNCATE, RENAME |
| Data Manipulation | INSERT, UPDATE, DELETE |
| Data Retrieval | SELECT, WHERE, DISTINCT |
| Sorting | ORDER BY |
| Grouping | GROUP BY, HAVING |
| Aggregate Functions | SUM, AVG, COUNT, MIN, MAX |
| Constraints | PRIMARY KEY, FOREIGN KEY, UNIQUE, NOT NULL, CHECK, DEFAULT |
| Joins | INNER, LEFT, RIGHT, CROSS, SELF |
| Set Operations | UNION, UNION ALL, INTERSECT, EXCEPT |
| Subqueries | IN, NOT IN, ANY, ALL |
| Correlated Queries | EXISTS, NOT EXISTS |
| Window Functions | ROW_NUMBER, RANK, DENSE_RANK, NTILE |
| Window Aggregates | SUM OVER, AVG OVER |
| CTEs | WITH, WITH RECURSIVE |
| Transactions | COMMIT, ROLLBACK, SAVEPOINT |
| Views | CREATE VIEW, DROP VIEW |
| Indexes | CREATE INDEX, DROP INDEX |
| Temporary Tables | CREATE TEMPORARY TABLE |
| User Permissions | GRANT, REVOKE |

---

# 18. Important Interview Questions

**Q1. What is an Index?**

An Index is a database structure that helps retrieve records faster.

**Q2. Why do we use Indexes?**

To improve searching, filtering, joining, and sorting performance in suitable queries.

**Q3. What are the disadvantages of Indexes?**

They require additional storage and can slow down INSERT, UPDATE, and DELETE operations.

**Q4. What is a Primary Key Index?**

It is an index that supports the uniqueness and identification of primary key records.

**Q5. What is a Unique Index?**

An index that prevents duplicate indexed values.

**Q6. What is a Composite Index?**

An index created on multiple columns.

**Q7. What is a Clustered Index?**

An index structure that determines how table data is organized. In InnoDB, the primary key is clustered by default.

**Q8. What is a Non-Clustered Index?**

A separate index structure that stores indexed values and references to the actual records.

**Q9. What is a Temporary Table?**

A table that exists only during the current database session.

**Q10. What are ACID properties?**

Atomicity, Consistency, Isolation, and Durability.

**Q11. What is Atomicity?**

A transaction is treated as a single unit. Either all operations succeed or none are applied.

**Q12. What is Consistency?**

A transaction maintains database rules and constraints.

**Q13. What is Isolation?**

It controls how concurrent transactions interact with each other.

**Q14. What is Durability?**

Committed changes persist even after failures, subject to durability configuration.

**Q15. What is a Database Schema?**

The logical structure or design of a database.

**Q16. What is a Database Instance?**

The current state of the database at a particular time; in MySQL administration, it can also refer to the running database server environment.

**Q17. What is a Storage Engine?**

A component that manages how MySQL stores and retrieves table data.

**Q18. Which is the default MySQL Storage Engine?**

InnoDB.

**Q19. What is InnoDB?**

A transactional MySQL storage engine that supports ACID, foreign keys, row-level locking, and crash recovery.

**Q20. What is MyISAM?**

An older MySQL storage engine that does not support transactions or foreign keys and uses table-level locking.

**Q21. Difference between InnoDB and MyISAM?**

InnoDB supports transactions, ACID, and foreign keys, whereas MyISAM does not.

**Q22. Which storage engine is suitable for banking applications?**

InnoDB because it supports reliable transactions and ACID properties.

**Q23. What is MEMORY Engine?**

A storage engine that stores table data in memory.

**Q24. What is the purpose of EXPLAIN?**

It displays the query execution plan and helps analyze index usage and query performance.

**Q25. Does an index always improve query performance?**

No. Indexes help suitable queries but add storage and maintenance overhead.

---

# 19. Self-Learning Practice Checklist

### Indexes

- [ ] Create a normal index on the student name.
- [ ] Create a unique index on email.
- [ ] Create a composite index on name and age.
- [ ] Display all indexes using SHOW INDEXES.
- [ ] Drop an existing index.
- [ ] Compare query plans using EXPLAIN.

### Temporary Tables

- [ ] Create a temporary table.
- [ ] Insert records into it.
- [ ] Retrieve records.
- [ ] Create a temporary table using SELECT.
- [ ] Drop a temporary table.
- [ ] Verify that the temporary table is unavailable in another session.

### ACID and Transactions

- [ ] Demonstrate Atomicity using a bank transfer.
- [ ] Understand Consistency using constraints.
- [ ] Understand Isolation using concurrent transactions.
- [ ] Understand Durability after COMMIT.
- [ ] Practise COMMIT and ROLLBACK.
- [ ] Practise SAVEPOINT.

### Storage Engines

- [ ] Display supported engines using SHOW ENGINES.
- [ ] Create an InnoDB table.
- [ ] Create a MyISAM table.
- [ ] Check the default storage engine.
- [ ] Change a table's storage engine.
- [ ] Compare InnoDB and MyISAM.

### SQL Revision

- [ ] Practise DDL commands.
- [ ] Practise DML commands.
- [ ] Practise SELECT queries.
- [ ] Practise constraints.
- [ ] Practise aggregate functions.
- [ ] Practise GROUP BY and HAVING.
- [ ] Practise all types of JOINs.
- [ ] Practise subqueries and correlated subqueries.
- [ ] Practise EXISTS and NOT EXISTS.
- [ ] Practise Window Functions.
- [ ] Practise CTEs and Recursive CTEs.
- [ ] Practise Views.
- [ ] Practise GRANT and REVOKE.
- [ ] Practise TCL commands.

---

# 20. Quick Revision – Important Points

1. An Index improves data retrieval performance.
2. Indexes require additional storage.
3. A Primary Key in InnoDB uses a clustered index.
4. A Unique Index prevents duplicate indexed values.
5. A Composite Index contains multiple columns.
6. The leftmost-prefix principle applies to composite indexes.
7. `EXPLAIN` displays the query execution plan.
8. Temporary Tables are session-specific.
9. ACID stands for Atomicity, Consistency, Isolation, and Durability.
10. Schema defines database structure.
11. Instance refers to the current database state in database theory.
12. InnoDB is the default MySQL storage engine in modern MySQL.
13. InnoDB supports transactions and foreign keys.
14. MyISAM does not support transactions or foreign keys.
15. MEMORY stores table data in memory.
16. CSV stores table data in CSV format.
17. ARCHIVE is designed for archived data.
18. Indexes do not guarantee faster execution for every query.
19. InnoDB is generally preferred for transactional applications.
20. Regular SQL revision is important for practical exams and interviews.

---

# 21. Learning Resources

- [MySQL Indexes Documentation](https://dev.mysql.com/doc/refman/8.0/en/mysql-indexes.html)
- [MySQL CREATE INDEX](https://dev.mysql.com/doc/refman/8.0/en/create-index.html)
- [MySQL ACID Model](https://dev.mysql.com/doc/refman/8.0/en/mysql-acid.html)
- [MySQL InnoDB Storage Engine](https://dev.mysql.com/doc/refman/8.0/en/innodb-storage-engine.html)
- [MySQL MyISAM Storage Engine](https://dev.mysql.com/doc/refman/8.0/en/myisam-storage-engine.html)
- [MySQL Storage Engines](https://dev.mysql.com/doc/refman/8.0/en/storage-engines.html)
- [MySQL Temporary Tables](https://dev.mysql.com/doc/refman/8.0/en/create-temporary-table.html)

---

**Happy Learning! 🚀**

*Prepared for CMCE – August 2026 Batch | Database Technologies*
