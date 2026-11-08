# Session 1: Introduction to DBMS
## Database Technologies | PGCP-AC | CMCE | August 2026

**Institute:** ACTS, Pune  
**Duration:** 1 Theory Hour  
**Subject:** Database Technologies  
**Session:** 01 – Introduction to DBMS

---

## Table of Contents

1. [Introduction to DBMS](#1-introduction-to-dbms)
2. [Basic Database Terminologies](#2-basic-database-terminologies)
3. [Types of DBMS](#3-types-of-dbms)
   - Relational DBMS
   - Object-Relational DBMS
   - NoSQL Database
4. [Introduction to MySQL](#4-introduction-to-mysql)
5. [MySQL Clients](#5-mysql-clients)
6. [Data Models](#6-data-models)
7. [Database Design](#7-database-design)
8. [Entity-Relationship Diagram](#8-entity-relationship-er-diagram)
9. [Important Database Keys](#9-important-database-keys)
10. [ER Diagram Example](#10-er-diagram-example)
11. [DBMS vs RDBMS vs NoSQL](#11-dbms-vs-rdbms-vs-nosql)
12. [Important Interview Questions](#12-important-interview-questions)
13. [Important MCQs](#13-important-mcqs)
14. [Quick Revision Notes](#14-quick-revision-notes)

---

# 1. Introduction to DBMS

### What is Data?

Data refers to raw facts and figures that have not necessarily been processed or organized.

**Examples:**
- Student Name: Anurag
- Roll Number: 101
- Age: 22
- Marks: 85
- City: Pune

### What is a Database?

A database is an organized collection of related data that can be easily stored, accessed, managed, updated and retrieved.

**Example: Student Database**

| Roll_No | Name | Age | City |
|---|---|---|---|
| 101 | Anurag | 22 | Pune |
| 102 | Rahul | 23 | Mumbai |
| 103 | Amit | 21 | Nashik |

Here, student information is organized in a structured format.

### What is DBMS?

DBMS stands for **Database Management System**.

A DBMS is software that allows users to create, store, retrieve, update, delete and manage data in a database.

**Examples:**
- MySQL
- Oracle Database
- Microsoft SQL Server
- PostgreSQL
- Microsoft Access

### Main Functions of DBMS

1. Data Storage: Stores data systematically.
2. Data Retrieval: Retrieves required information.
3. Data Manipulation: Supports INSERT, UPDATE and DELETE operations.
4. Data Security: Controls unauthorized access.
5. Data Integrity: Maintains accuracy and consistency.
6. Backup and Recovery: Helps recover data after failures.
7. Concurrency Control: Allows multiple users to access data safely.
8. Transaction Management: Ensures reliable database transactions.

### Advantages of DBMS

- Reduces data redundancy (duplicate data).
- Improves data consistency.
- Provides data security.
- Supports data sharing.
- Provides backup and recovery.
- Maintains data integrity.
- Supports concurrent access.

### Disadvantages of DBMS

- Installation and maintenance costs.
- Requires technical knowledge.
- Requires storage and computing resources.
- Database failure can affect multiple applications.

### Why Do We Need DBMS?

Consider a college that stores student records in separate Excel files.

Problems:
- Duplicate student records.
- Difficulty updating information.
- Inconsistent data.
- Difficult searching.
- Limited security.

A DBMS solves these problems by providing centralized and systematic data management.

---

# 2. Basic Database Terminologies

These terms are important for theory examinations, MCQs and technical interviews.

| Terminology | Explanation |
|---|---|
| Data | Raw facts and figures. |
| Information | Processed and meaningful data. |
| Database | Organized collection of related data. |
| DBMS | Software used to manage databases. |
| RDBMS | DBMS that organizes data into related tables. |
| Table | Collection of data arranged in rows and columns. |
| Row / Record / Tuple | A single complete entry in a table. |
| Column / Field / Attribute | A property of an entity. |
| Domain | Set of valid values for an attribute. |
| Schema | Logical structure or blueprint of a database. |
| Instance | Actual data stored in a database at a particular time. |
| Query | Request to retrieve or manipulate data. |
| Metadata | Data about data. |
| Constraint | Rule applied to maintain data integrity. |
| Primary Key | Uniquely identifies each record. |
| Foreign Key | Establishes a relationship between tables. |
| Index | Improves data retrieval performance. |
| View | Virtual table based on a SQL query. |
| Transaction | Logical unit of database operations. |
| Normalization | Process of organizing data to reduce redundancy. |

### Example: Student Table

```sql
CREATE DATABASE college;

USE college;

CREATE TABLE student (
    roll_no INT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    city VARCHAR(50)
);
```

Insert records:

```sql
INSERT INTO student
VALUES
(101, 'Anurag', 22, 'Pune'),
(102, 'Rahul', 23, 'Mumbai'),
(103, 'Amit', 21, 'Nashik');
```

Retrieve records:

```sql
SELECT * FROM student;
```

**Understanding the terminology:**

- Database: `college`
- Table: `student`
- Columns: `roll_no`, `name`, `age`, `city`
- Row: One student's complete information.
- Primary Key: `roll_no`
- Schema: Structure of the student table.
- Instance: The actual three records inserted above.

---

# 3. Types of DBMS

Based on how data is organized and managed, databases can be classified into different types.

## 3.1 Relational Database Management System (RDBMS)

An RDBMS stores data in the form of tables consisting of rows and columns.

Tables can be connected using relationships through primary keys and foreign keys.

**Examples:**
- MySQL
- Oracle
- PostgreSQL
- Microsoft SQL Server

### Example

**Student Table**

| Student_ID (PK) | Name | City |
|---|---|---|
| 1 | Anurag | Pune |
| 2 | Rahul | Mumbai |

**Course Table**

| Course_ID (PK) | Course_Name |
|---|---|
| 101 | Java |
| 102 | Python |

**Enrollment Table**

| Enrollment_ID (PK) | Student_ID (FK) | Course_ID (FK) |
|---|---|---|
| 1 | 1 | 101 |
| 2 | 1 | 102 |
| 3 | 2 | 101 |

Here:
- Student_ID identifies a student.
- Course_ID identifies a course.
- Enrollment connects students and courses.

### Features of RDBMS

1. Stores data in tables.
2. Uses SQL (Structured Query Language).
3. Supports primary and foreign keys.
4. Maintains referential integrity.
5. Supports normalization.
6. Supports ACID transactions.
7. Uses predefined schemas.

### Advantages

- Structured data management.
- Strong consistency.
- Easy data retrieval using SQL.
- Supports complex queries and joins.
- Maintains relationships between tables.

### Disadvantages

- Schema changes may require careful migration.
- Horizontal scaling can be more complex.
- Less flexible for highly variable document structures.

---

## 3.2 Object-Relational Database Management System (ORDBMS)

An Object-Relational Database Management System combines relational database features with object-oriented concepts.

It supports traditional relational tables along with advanced data types and object-oriented features.

### Features

1. Supports tables and SQL.
2. Supports user-defined data types.
3. Supports complex data structures.
4. Can support inheritance and object-related features.
5. Extends the capabilities of traditional relational databases.

### Example

PostgreSQL supports object-relational features such as:
- User-defined types.
- Composite types.
- Table inheritance.
- Arrays.
- Custom operators.

### Simple Example

Imagine a database storing employee information.

Instead of storing an address only as a simple string, an advanced database may define an address as a composite type containing:

- House Number
- Street
- City
- PIN Code

This is an example of using richer data types in an object-relational database.

**Remember:** ORDBMS is not the same as an Object-Oriented DBMS. An OODBMS stores data as objects, whereas an ORDBMS extends the relational model.

---

## 3.3 NoSQL Database

NoSQL stands for **Not Only SQL**.

NoSQL databases are designed to store and manage data using flexible models rather than relying exclusively on traditional relational tables.

They are useful for large-scale applications, flexible schemas and distributed systems.

### Types of NoSQL Databases

**1. Document Database**

Stores data in document formats such as JSON-like BSON.

Example: MongoDB.

```json
{
    "_id": 1,
    "name": "Anurag",
    "age": 22,
    "city": "Pune",
    "skills": ["Java", "Python", "SQL"]
}
```

**2. Key-Value Database**

Stores data in the form of key-value pairs.

Example: Redis.

```text
Key: student_name
Value: Anurag
```

**3. Column-Family Database**

Stores data using column families.

Example: Apache Cassandra.

**4. Graph Database**

Stores data using nodes and relationships (edges).

Example: Neo4j.

### Features of NoSQL

- Flexible data models.
- Suitable for semi-structured and unstructured data.
- Designed for distributed environments.
- Supports horizontal scaling.
- Different NoSQL databases provide different consistency and transaction guarantees.

### Advantages

- Flexible schema.
- Suitable for large-scale applications.
- Supports distributed data storage.
- Can handle diverse data structures.

### Disadvantages

- Query languages differ between databases.
- Joins and complex relationships may require additional design.
- Consistency and transaction capabilities vary by database.

---

# 4. Introduction to MySQL

MySQL is an open-source Relational Database Management System (RDBMS).

It uses SQL (Structured Query Language) to store, retrieve, update and manage structured data.

Official Website: https://www.mysql.com/

### Important Features of MySQL

1. Open-source Community Edition.
2. Uses SQL.
3. Supports relational tables.
4. Supports primary and foreign keys.
5. Supports transactions using InnoDB.
6. Provides indexing.
7. Supports stored procedures, functions and triggers.
8. Provides security and user management.
9. Supports backup and recovery mechanisms.
10. Supports client-server architecture.

### Applications of MySQL

- Banking applications.
- E-commerce websites.
- College management systems.
- Hospital management systems.
- Inventory management systems.
- Web applications.

### MySQL Client-Server Architecture

MySQL follows a client-server architecture.

**Client:** Sends SQL queries to the server.

**Server:** Processes queries, manages databases and returns results.

Example:

```text
        User
          |
          v
    MySQL Client
          |
       SQL Query
          |
          v
     MySQL Server
          |
          v
       Database
          |
          v
    Query Result
          |
          v
       Client
```

---

# 5. MySQL Clients

A MySQL client is a tool or application used to communicate with the MySQL server.

The three important clients in this session are:

## 5.1 MySQL Monitor

MySQL Monitor is the traditional command-line client, commonly invoked using the `mysql` command.

It allows users to execute SQL queries directly from the terminal.

### Example

```bash
mysql -u root -p
```

Explanation:

- `mysql`: Starts the MySQL command-line client.
- `-u root`: Specifies the username.
- `-p`: Prompts for the password.

After connecting:

```sql
SHOW DATABASES;

CREATE DATABASE college;

USE college;

SHOW TABLES;
```

### Advantages

- Lightweight.
- Fast execution.
- Useful for SQL practice.
- Suitable for server administration.
- Supports scripting.

---

## 5.2 MySQL Shell

MySQL Shell is an advanced command-line client for MySQL.

It supports three execution modes:

| Mode | Description |
|---|---|
| SQL | Executes SQL statements. |
| JavaScript | Executes JavaScript commands. |
| Python | Executes Python commands. |

### Example

Start MySQL Shell:

```bash
mysqlsh
```

Connect to the server:

```javascript
\connect root@localhost
```

Switch to SQL mode:

```javascript
\sql
```

Execute:

```sql
SHOW DATABASES;
```

Switch to JavaScript mode:

```javascript
\js
```

Switch to Python mode:

```python
\py
```

### Advantages

- Supports SQL, JavaScript and Python.
- Useful for database administration.
- Supports scripting and automation.
- Supports MySQL Shell utilities.

---

## 5.3 MySQL Workbench

MySQL Workbench is a graphical user interface (GUI) tool used for database development, administration and design.

Official Website: https://dev.mysql.com/downloads/workbench/

### Important Features

1. SQL Editor – Write and execute SQL queries.
2. Database Administration – Manage MySQL servers.
3. Visual Database Design – Create ER diagrams.
4. Data Modeling – Design database schemas.
5. Query Execution – Run SQL statements.
6. Database Migration – Supports database migration workflows.

### MySQL Workbench Interface

Common areas include:

- SQL Editor.
- Navigator panel.
- Schema browser.
- Query output.
- Action output.
- Administration panel.

### MySQL Monitor vs Shell vs Workbench

| Feature | Monitor | Shell | Workbench |
|---|---|---|---|
| Interface | CLI | Advanced CLI | GUI |
| SQL Support | Yes | Yes | Yes |
| JavaScript | No | Yes | No |
| Python | No | Yes | No |
| Visual ER Design | No | No | Yes |
| Administration | Basic | Advanced | GUI-based |
| Best For | SQL practice | Scripting | Visual development |

---

# 6. Data Models

A data model defines how data is organized, stored, represented and related within a database.

There are three important levels of data modeling.

## 6.1 Conceptual Data Model

A conceptual data model represents the high-level structure of a database.

It focuses on:
- What data is required?
- Which entities exist?
- How are entities related?

It does not focus on technical implementation details.

### Example

College Management System:

Entities:
- Student
- Course
- Teacher

Relationships:
- Student enrolls in Course.
- Teacher teaches Course.

**Purpose:** To understand business requirements.

**Used by:** Business analysts, clients and database designers.

## 6.2 Logical Data Model

A logical data model describes the detailed structure of the database.

It includes:
- Entities.
- Attributes.
- Primary keys.
- Foreign keys.
- Relationships.
- Constraints.

It is generally independent of a particular database implementation.

### Example

Student:

```text
STUDENT
-------------------------
Student_ID (PK)
Name
Email
Age
```

Course:

```text
COURSE
-------------------------
Course_ID (PK)
Course_Name
Duration
```

Enrollment:

```text
ENROLLMENT
-------------------------
Enrollment_ID (PK)
Student_ID (FK)
Course_ID (FK)
```

**Purpose:** To define how data is logically organized.

## 6.3 Physical Data Model

A physical data model describes how the database is actually implemented in a particular DBMS.

It includes:
- Actual table definitions.
- Column names and data types.
- Primary keys.
- Foreign keys.
- Indexes.
- Constraints.
- Storage-related implementation details.

### Example in MySQL

```sql
CREATE TABLE student (
    student_id INT AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE,
    age INT,
    PRIMARY KEY(student_id)
);
```

**Purpose:** To implement the logical database design in a specific DBMS.

### Difference Between Conceptual, Logical and Physical Models

| Conceptual | Logical | Physical |
|---|---|---|
| High-level design | Detailed logical design | Actual implementation |
| Defines entities | Defines entities and attributes | Defines tables and columns |
| Defines relationships | Defines keys and constraints | Defines indexes and data types |
| No technical details | DBMS-independent in general | DBMS-specific |
| Focuses on what | Focuses on how data is organized | Focuses on how it is implemented |

### Easy Way to Remember

- Conceptual: What data do we need?
- Logical: How is the data structured and related?
- Physical: How will we implement it?

---

# 7. Database Design

Database design is the process of planning and organizing data into an efficient database structure.

A good database design reduces duplication, maintains consistency and improves data retrieval.

### Steps in Database Design

**Step 1: Requirement Analysis**

Understand the requirements of the application.

Example:
A college needs to store student details, courses and enrollment records.

**Step 2: Identify Entities**

Identify the main objects.

Example:
- Student
- Course
- Teacher

**Step 3: Identify Attributes**

Identify the properties of each entity.

Example:

Student:
- Student_ID
- Name
- Email
- Age

**Step 4: Identify Relationships**

Identify how entities are connected.

Example:
- Student enrolls in Course.
- Teacher teaches Course.

**Step 5: Identify Keys**

Select primary keys and foreign keys.

**Step 6: Create ER Diagram**

Represent entities, attributes and relationships visually.

**Step 7: Apply Normalization**

Organize tables to reduce unnecessary data duplication and update anomalies.

**Step 8: Physical Implementation**

Create tables, constraints and indexes using SQL.

### Objectives of Good Database Design

- Minimize data redundancy.
- Maintain data consistency.
- Maintain data integrity.
- Avoid insertion, deletion and update anomalies.
- Improve query performance.
- Ensure data security.

---

# 8. Entity-Relationship (ER) Diagram

An Entity-Relationship Diagram (ER Diagram) is a graphical representation of entities, their attributes and relationships.

It is used during database design.

### 8.1 Entity

An entity is a real-world object or concept about which data is stored.

Examples:
- Student
- Employee
- Department
- Product
- Customer

**Representation:** Rectangle.

### 8.2 Attribute

An attribute describes the properties of an entity.

Example:

Student attributes:
- Student_ID
- Name
- Age
- Email

**Representation:** Oval.

### Types of Attributes

**1. Simple Attribute**

Cannot be divided into smaller meaningful components.

Example: Age.

**2. Composite Attribute**

Can be divided into smaller attributes.

Example:

```text
Name
 ├── First_Name
 ├── Middle_Name
 └── Last_Name
```

**3. Single-Valued Attribute**

Has only one value for an entity.

Example: Date of Birth.

**4. Multivalued Attribute**

Can have multiple values.

Example: Phone Numbers.

**Representation:** Double Oval.

**5. Derived Attribute**

Can be calculated from another attribute.

Example: Age can be calculated using Date of Birth.

**Representation:** Dashed Oval.

**6. Key Attribute**

Uniquely identifies an entity.

Example: Student_ID.

**Representation:** Underlined attribute.

### 8.3 Relationship

A relationship represents an association between two or more entities.

Example:

Student ENROLLS IN Course.

**Representation:** Diamond.

### 8.4 Cardinality

Cardinality describes the number of instances of one entity that can be associated with instances of another entity.

There are four common types:

**1. One-to-One (1:1)**

One record in Entity A is associated with one record in Entity B.

Example: Person and Passport.

**2. One-to-Many (1:N)**

One record in Entity A can be associated with multiple records in Entity B.

Example: Department and Employees.

One department can have many employees.

**3. Many-to-One (N:1)**

Many records in Entity A are associated with one record in Entity B.

Example: Many employees work in one department.

**4. Many-to-Many (M:N)**

Multiple records in Entity A can be associated with multiple records in Entity B.

Example: Students and Courses.

One student can enroll in many courses, and one course can have many students.

A many-to-many relationship is generally implemented using an additional junction table in a relational database.

### 8.5 Participation Constraints

Participation specifies whether every entity instance must participate in a relationship.

**Total Participation:**
Every entity instance must participate in the relationship.

**Partial Participation:**
Participation is optional for some entity instances.

---

# 9. Important Database Keys

Keys help identify records and establish relationships between tables.

### 1. Super Key

A super key is any set of one or more attributes that uniquely identifies a record.

Example:
- Student_ID
- Student_ID + Name

Both can be super keys if Student_ID is unique.

### 2. Candidate Key

A candidate key is a minimal super key.

It uniquely identifies a record and contains no unnecessary attributes.

### 3. Primary Key

A primary key is the candidate key selected to uniquely identify records.

Properties:
- Must be unique.
- Cannot contain NULL values.
- A table has one primary key constraint, which can contain multiple columns.

### 4. Alternate Key

Candidate keys that are not selected as the primary key are called alternate keys.

### 5. Foreign Key

A foreign key is an attribute or set of attributes that references a candidate key, usually the primary key, of another table.

It maintains referential integrity.

### 6. Composite Key

A key formed using two or more attributes.

Example:

```text
ENROLLMENT
-------------------------
Student_ID
Course_ID

PRIMARY KEY(Student_ID, Course_ID)
```

### Example SQL

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

---

# 10. ER Diagram Example

### College Management System

Entities:
- Student
- Course
- Enrollment

Relationships:
- Student enrolls in Course.
- Enrollment connects Student and Course.

Text representation:

```text
STUDENT
----------------
Student_ID (PK)
Name
Email
       |
       | 1
       |
       | N
ENROLLMENT
----------------
Enrollment_ID (PK)
Student_ID (FK)
Course_ID (FK)
       |
       | N
       |
       | 1
COURSE
----------------
Course_ID (PK)
Course_Name
Duration
```

### SQL Implementation

```sql
CREATE DATABASE college_db;

USE college_db;

CREATE TABLE student (
    student_id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100) UNIQUE
);

CREATE TABLE course (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(100),
    duration INT
);

CREATE TABLE enrollment (
    enrollment_id INT PRIMARY KEY,
    student_id INT,
    course_id INT,

    FOREIGN KEY (student_id)
        REFERENCES student(student_id),

    FOREIGN KEY (course_id)
        REFERENCES course(course_id)
);
```

### Insert Sample Data

```sql
INSERT INTO student
VALUES
(1, 'Anurag', 'anurag@gmail.com'),
(2, 'Rahul', 'rahul@gmail.com');

INSERT INTO course
VALUES
(101, 'Java', 6),
(102, 'Python', 4);

INSERT INTO enrollment
VALUES
(1, 1, 101),
(2, 1, 102),
(3, 2, 101);
```

### Retrieve Student and Course Details

```sql
SELECT
    s.student_id,
    s.name,
    c.course_name
FROM student s
JOIN enrollment e
    ON s.student_id = e.student_id
JOIN course c
    ON e.course_id = c.course_id;
```

---

# 11. DBMS vs RDBMS vs NoSQL

| Feature | DBMS | RDBMS | NoSQL |
|---|---|---|---|
| Data Storage | Depends on model | Tables | Documents, key-value, graph, etc. |
| Structure | Varies | Rows and columns | Flexible, model-dependent |
| Relationships | Depends on DBMS | Keys and joins | References, embedding or graph links |
| Schema | Varies | Generally predefined | Often flexible |
| Query Language | Depends on DBMS | SQL | Varies |
| Examples | MS Access | MySQL, Oracle | MongoDB, Redis |

**Important:** RDBMS is a type of DBMS. NoSQL databases are also database management systems, but they do not necessarily follow the relational model.

---

# 12. Important Interview Questions

### Basic Questions

**Q1. What is DBMS?**

DBMS is software used to create, store, retrieve, update and manage data in a database.

**Q2. What is the difference between data and information?**

Data is raw facts, whereas information is processed and meaningful data.

**Q3. What is the difference between DBMS and RDBMS?**

DBMS is a general database management system, whereas RDBMS organizes data into related tables and supports relational concepts.

**Q4. What is a database schema?**

A schema is the logical structure or blueprint of a database.

**Q5. What is metadata?**

Metadata is data about data. Example: Column name, data type and constraints.

### Intermediate Questions

**Q6. What is an ORDBMS?**

An ORDBMS combines relational database capabilities with object-oriented features such as user-defined and complex data types.

**Q7. What is NoSQL?**

NoSQL is a category of non-relational databases designed for flexible data models and distributed data management.

**Q8. What are the four types of NoSQL databases?**

Document, key-value, column-family and graph databases.

**Q9. What is the difference between MySQL Monitor and MySQL Shell?**

MySQL Monitor is a traditional SQL command-line client, while MySQL Shell supports SQL, JavaScript and Python modes.

**Q10. What are the three levels of data models?**

Conceptual, logical and physical.

### ER Diagram Questions

**Q11. What is an entity?**

An entity is a real-world object about which data is stored.

**Q12. What is an attribute?**

An attribute is a property that describes an entity.

**Q13. What is cardinality?**

Cardinality specifies the number of entity instances that can participate in a relationship.

**Q14. What is a weak entity?**

A weak entity cannot be uniquely identified using its own attributes alone and depends on an identifying relationship with an owner entity.

**Q15. What is a many-to-many relationship?**

A relationship where multiple instances of one entity can be associated with multiple instances of another entity.

---

# 13. Important MCQs

**Q1. What is the full form of DBMS?**

A. Database Management Software  
B. Database Management System  
C. Data Backup Management System  
D. Database Monitoring System

**Answer: B**

**Q2. Which of the following is an RDBMS?**

A. MongoDB  
B. Redis  
C. MySQL  
D. Neo4j

**Answer: C**

**Q3. Which database uses document-based storage?**

A. MongoDB  
B. Redis  
C. MySQL  
D. Oracle

**Answer: A**

**Q4. Which MySQL client supports SQL, JavaScript and Python?**

A. MySQL Monitor  
B. MySQL Shell  
C. MySQL Workbench  
D. Notepad

**Answer: B**

**Q5. Which data model represents high-level business requirements?**

A. Physical  
B. Logical  
C. Conceptual  
D. Network

**Answer: C**

**Q6. Which ER diagram symbol represents an entity?**

A. Oval  
B. Rectangle  
C. Diamond  
D. Circle

**Answer: B**

**Q7. Which symbol represents a relationship in a traditional Chen ER diagram?**

A. Rectangle  
B. Oval  
C. Diamond  
D. Triangle

**Answer: C**

**Q8. Which attribute can have multiple values?**

A. Simple  
B. Single-valued  
C. Multivalued  
D. Derived

**Answer: C**

**Q9. Which key uniquely identifies a record?**

A. Foreign Key  
B. Primary Key  
C. Duplicate Key  
D. Non-key

**Answer: B**

**Q10. Which relationship is generally implemented using a junction table?**

A. One-to-One  
B. One-to-Many  
C. Many-to-Many  
D. None

**Answer: C**

---

# 14. Quick Revision Notes

| Topic | Remember |
|---|---|
| DBMS | Software to manage databases |
| RDBMS | Data stored in related tables |
| ORDBMS | Relational + object-oriented features |
| NoSQL | Non-relational database category |
| MySQL | Open-source RDBMS |
| MySQL Monitor | Traditional command-line client |
| MySQL Shell | SQL + JavaScript + Python |
| MySQL Workbench | GUI for database development and administration |
| Conceptual Model | High-level requirements |
| Logical Model | Entities, attributes, keys and relationships |
| Physical Model | Actual implementation |
| Entity | Real-world object |
| Attribute | Property of an entity |
| Relationship | Association between entities |
| Cardinality | Number of related instances |
| Primary Key | Unique identification |
| Foreign Key | References another table's key |
| Normalization | Reduces redundancy and anomalies |

---

## Practice Tasks

Try completing these tasks yourself:

- [ ] Define DBMS and explain its advantages.
- [ ] Differentiate between DBMS, RDBMS and NoSQL.
- [ ] Explain the four types of NoSQL databases.
- [ ] Install MySQL Server and MySQL Workbench.
- [ ] Practice MySQL Monitor commands.
- [ ] Explore SQL, JavaScript and Python modes in MySQL Shell.
- [ ] Explain conceptual, logical and physical data models.
- [ ] Draw an ER diagram for a College Management System.
- [ ] Identify primary keys and foreign keys.
- [ ] Implement Student, Course and Enrollment tables in MySQL.
- [ ] Practice the interview questions and MCQs.

---

## Recommended Learning Resources

1. MySQL Official Documentation: https://dev.mysql.com/doc/
2. MySQL Workbench: https://dev.mysql.com/downloads/workbench/
3. MongoDB Documentation: https://www.mongodb.com/docs/
4. W3Schools SQL Tutorial: https://www.w3schools.com/sql/
5. GeeksforGeeks DBMS: https://www.geeksforgeeks.org/dbms/

---

**End of Session 1 – Introduction to DBMS**

*Prepared for Database Technologies – PGCP-AC / CMCE August 2026 Batch.*

**Learning Goal:** Understand database fundamentals, database types, MySQL clients, data modeling, database design and ER diagrams before moving to SQL programming and database implementation.
