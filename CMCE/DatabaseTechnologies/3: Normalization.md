# Session 3: Normalization

## Database Technologies | PGCP-AC | CMCE | August 2026

**Institute:** ACTS, Pune  
**Course:** PGCP-AC  
**Subject:** Database Technologies  
**Session:** 03 – Normalization  
**Duration:** 2 Theory + 2 Self Learning Hours

---

## Table of Contents

1. [Introduction to Normalization](#1-introduction-to-normalization)
2. [Data Redundancy](#2-data-redundancy)
3. [Data Anomalies](#3-data-anomalies)
4. [Functional Dependency](#4-functional-dependency)
5. [Need for Normalization](#5-need-for-normalization)
6. [Normal Forms](#6-normal-forms)
   - First Normal Form (1NF)
   - Second Normal Form (2NF)
   - Third Normal Form (3NF)
   - Boyce-Codd Normal Form (BCNF)
   - Fourth Normal Form (4NF)
   - Fifth Normal Form (5NF)
7. [Comparison of Normal Forms](#7-comparison-of-normal-forms)
8. [SQL Practical Examples](#8-sql-practical-examples)
9. [Important Interview Questions](#9-important-interview-questions)
10. [Important MCQs](#10-important-mcqs)
11. [Quick Revision](#11-quick-revision)
12. [Practice Checklist](#12-practice-checklist)

---

# 1. Introduction to Normalization

### What is Normalization?

Normalization is the process of organizing data in a relational database to reduce data redundancy and eliminate data anomalies.

It involves dividing large tables into smaller, logically related tables and establishing relationships between them using primary keys and foreign keys.

**Example:**

Consider a college database containing student and course information.

An unnormalized table:

| Student_ID | Student_Name | Course |
|---|---|---|
| 101 | Anurag | Java, Python |
| 102 | Rahul | Java |
| 103 | Amit | Python, SQL |

Here, multiple course values are stored in a single column.

Normalization helps organize this data into properly structured tables.

### Objectives of Normalization

1. Reduce data redundancy.
2. Eliminate insertion anomalies.
3. Eliminate update anomalies.
4. Eliminate deletion anomalies.
5. Improve data consistency.
6. Maintain data integrity.
7. Organize data efficiently.

---

# 2. Data Redundancy

### What is Data Redundancy?

Data redundancy means unnecessary duplication or repetition of the same data in a database.

**Example:**

| Student_ID | Student_Name | Course | Instructor |
|---|---|---|---|
| 101 | Anurag | Java | Amit Sir |
| 101 | Anurag | Python | Rahul Sir |
| 102 | Rahul | Java | Amit Sir |
| 102 | Rahul | SQL | Priya Ma'am |

Here:
- Anurag's name is repeated.
- Rahul's name is repeated.
- Amit Sir's details are repeated.

This is an example of data redundancy.

### Problems Caused by Data Redundancy

- Wastage of storage space.
- Increased database size.
- Data inconsistency.
- Difficulty updating records.
- Increased maintenance.
- Data anomalies.

**Solution:** Apply normalization by dividing data into logically related tables.

---

# 3. Data Anomalies

Data anomalies are problems that occur when inserting, updating or deleting records in a poorly designed database.

There are three major types of anomalies.

## 3.1 Insertion Anomaly

An insertion anomaly occurs when we cannot insert certain information into a database without inserting some unrelated information.

**Example:**

Consider this table:

| Student_ID | Student_Name | Course | Instructor |
|---|---|---|---|
| 101 | Anurag | Java | Amit Sir |
| 102 | Rahul | Python | Priya Ma'am |

Suppose a new course called C++ is introduced, but no student has enrolled in it yet.

We cannot insert the course information independently because the table requires student information.

**Problem:** Course information depends on student enrollment.

**Solution:** Create a separate Course table.

## 3.2 Update Anomaly

An update anomaly occurs when the same information is stored in multiple rows and all occurrences are not updated.

**Example:**

| Student_ID | Student_Name | Course | Instructor |
|---|---|---|---|
| 101 | Anurag | Java | Amit Sir |
| 102 | Rahul | Java | Amit Sir |
| 103 | Amit | Java | Amit Sir |

Suppose Amit Sir's name is changed to Amit Sharma.

We must update all three rows.

If only two rows are updated, inconsistent data is created.

**Problem:** Same instructor information is repeated.

**Solution:** Store instructor information separately.

## 3.3 Deletion Anomaly

A deletion anomaly occurs when deleting one record unintentionally removes other important information.

**Example:**

| Student_ID | Student_Name | Course | Instructor |
|---|---|---|---|
| 101 | Anurag | Java | Amit Sir |
| 102 | Rahul | Python | Priya Ma'am |

Suppose Rahul is the only student enrolled in Python.

If we delete Rahul's record, we also lose the only stored information about the Python course and its instructor.

**Problem:** Course information is lost when deleting student information.

**Solution:** Maintain separate Student and Course tables.

### Difference Between Anomalies

| Anomaly | Meaning |
|---|---|
| Insertion | Difficulty inserting new information |
| Update | Same information must be updated in multiple places |
| Deletion | Deleting one record unintentionally removes other information |

---

# 4. Functional Dependency

### What is Functional Dependency?

Functional Dependency (FD) is a relationship between attributes in a relational database where one attribute or a group of attributes determines another attribute.

It is represented as:

**X → Y**

Where:
- X = Determinant.
- Y = Dependent attribute.

It means that the value of X uniquely determines the value of Y.

### Example

Consider the Student table:

| Student_ID | Student_Name | City |
|---|---|---|
| 101 | Anurag | Pune |
| 102 | Rahul | Mumbai |
| 103 | Amit | Nashik |

Functional dependencies:

```text
Student_ID → Student_Name

Student_ID → City
```

Explanation:

If we know Student_ID, we can uniquely identify the student's name and city.

### Types of Functional Dependencies

## 4.1 Trivial Functional Dependency

A functional dependency X → Y is trivial if Y is a subset of X.

Example:

```text
(Student_ID, Name) → Name
```

Here, Name is already part of the left-hand side.

## 4.2 Non-Trivial Functional Dependency

A functional dependency is non-trivial if Y is not a subset of X.

Example:

```text
Student_ID → Student_Name
```

Student_Name is not part of Student_ID.

## 4.3 Full Functional Dependency

An attribute is fully functionally dependent on a composite key if the entire key is required to determine that attribute.

Example:

```text
(Student_ID, Course_ID) → Marks
```

Neither Student_ID alone nor Course_ID alone determines the marks obtained in a particular course.

Both attributes are required.

## 4.4 Partial Functional Dependency

A partial dependency occurs when a non-key attribute depends on only a part of a composite candidate key.

Example:

Consider:

| Student_ID | Course_ID | Student_Name | Course_Name | Marks |
|---|---|---|---|---|
| 101 | C01 | Anurag | Java | 85 |
| 101 | C02 | Anurag | Python | 90 |
| 102 | C01 | Rahul | Java | 78 |

Composite key:

```text
(Student_ID, Course_ID)
```

Dependencies:

```text
Student_ID → Student_Name

Course_ID → Course_Name

(Student_ID, Course_ID) → Marks
```

Student_Name depends only on Student_ID, not on the complete composite key.

Therefore, it is a partial dependency.

Partial dependencies are removed during 2NF.

## 4.5 Transitive Functional Dependency

A transitive dependency occurs when a non-key attribute depends on another non-key attribute through a candidate key.

Example:

| Student_ID | Dept_ID | Dept_Name |
|---|---|---|
| 101 | D01 | AIML |
| 102 | D02 | Computer |
| 103 | D01 | AIML |

Dependencies:

```text
Student_ID → Dept_ID

Dept_ID → Dept_Name
```

Therefore:

```text
Student_ID → Dept_Name
```

This is a transitive dependency.

Transitive dependencies are removed during 3NF.

---

# 5. Need for Normalization

Normalization is required to:

1. Eliminate unnecessary duplicate data.
2. Prevent insertion anomalies.
3. Prevent update anomalies.
4. Prevent deletion anomalies.
5. Maintain data consistency.
6. Improve logical database organization.
7. Simplify database maintenance.
8. Improve data integrity.

### Important Note

Normalization improves data organization, but excessive normalization can require more JOIN operations and may affect query performance.

Database design involves balancing data integrity and performance.

---

# 6. Normal Forms

Normal forms are rules or levels used to organize database tables and reduce redundancy.

The important normal forms are:

1. First Normal Form (1NF)
2. Second Normal Form (2NF)
3. Third Normal Form (3NF)
4. Boyce-Codd Normal Form (BCNF)
5. Fourth Normal Form (4NF)
6. Fifth Normal Form (5NF)

## 6.1 First Normal Form (1NF)

### Definition

A table is in First Normal Form if:

- Each column contains atomic (indivisible for the intended data model) values.
- Each cell contains a single value.
- There are no repeating groups or multivalued fields.
- Each row can be uniquely identified.

### Example: Not in 1NF

| Student_ID | Student_Name | Courses |
|---|---|---|
| 101 | Anurag | Java, Python |
| 102 | Rahul | SQL, C++ |

Problem:

The Courses column contains multiple values in a single cell.

### Convert into 1NF

| Student_ID | Student_Name | Course |
|---|---|---|
| 101 | Anurag | Java |
| 101 | Anurag | Python |
| 102 | Rahul | SQL |
| 102 | Rahul | C++ |

Now every cell contains a single value.

**Remember:** 1NF = Atomic Values + No Repeating Groups.

---

## 6.2 Second Normal Form (2NF)

### Definition

A table is in Second Normal Form if:

1. It is already in 1NF.
2. Every non-prime attribute is fully functionally dependent on every candidate key.

In simpler words, there should be no partial functional dependency of non-prime attributes on a candidate key.

### Example: Table Not in 2NF

Consider the Student_Course table:

| Student_ID | Course_ID | Student_Name | Course_Name | Marks |
|---|---|---|---|---|
| 101 | C01 | Anurag | Java | 85 |
| 101 | C02 | Anurag | Python | 90 |
| 102 | C01 | Rahul | Java | 78 |

Composite Primary Key:

```text
(Student_ID, Course_ID)
```

Functional Dependencies:

```text
Student_ID → Student_Name

Course_ID → Course_Name

(Student_ID, Course_ID) → Marks
```

Problem:

- Student_Name depends only on Student_ID.
- Course_Name depends only on Course_ID.
- Both are partial dependencies.

Therefore, the table is not in 2NF.

### Convert into 2NF

**Student Table**

| Student_ID (PK) | Student_Name |
|---|---|
| 101 | Anurag |
| 102 | Rahul |

**Course Table**

| Course_ID (PK) | Course_Name |
|---|---|
| C01 | Java |
| C02 | Python |

**Enrollment Table**

| Student_ID (PK, FK) | Course_ID (PK, FK) | Marks |
|---|---|---|
| 101 | C01 | 85 |
| 101 | C02 | 90 |
| 102 | C01 | 78 |

Now:
- Student_Name depends completely on Student_ID.
- Course_Name depends completely on Course_ID.
- Marks depends on the complete composite key.

**Remember:** 2NF = 1NF + No Partial Dependency.

---

## 6.3 Third Normal Form (3NF)

### Definition

A table is in Third Normal Form if:

1. It is already in 2NF.
2. It has no transitive dependency of non-prime attributes on candidate keys.

Formal definition:

For every non-trivial functional dependency X → A, at least one condition must hold:

- X is a super key, or
- A is a prime attribute (part of at least one candidate key).

### Example: Table Not in 3NF

Consider the Student table:

| Student_ID | Student_Name | Dept_ID | Dept_Name |
|---|---|---|---|
| 101 | Anurag | D01 | AIML |
| 102 | Rahul | D02 | Computer |
| 103 | Amit | D01 | AIML |

Functional Dependencies:

```text
Student_ID → Student_Name

Student_ID → Dept_ID

Dept_ID → Dept_Name
```

Here:

```text
Student_ID → Dept_ID → Dept_Name
```

Dept_Name depends on Dept_ID, which is a non-key attribute.

This is a transitive dependency.

Therefore, the table is not in 3NF.

### Convert into 3NF

**Student Table**

| Student_ID (PK) | Student_Name | Dept_ID (FK) |
|---|---|---|
| 101 | Anurag | D01 |
| 102 | Rahul | D02 |
| 103 | Amit | D01 |

**Department Table**

| Dept_ID (PK) | Dept_Name |
|---|---|
| D01 | AIML |
| D02 | Computer |

Now Dept_Name is stored separately in the Department table.

**Remember:** 3NF = 2NF + No Transitive Dependency of Non-prime Attributes.

---

## 6.4 Boyce-Codd Normal Form (BCNF)

### Definition

Boyce-Codd Normal Form is a stronger version of Third Normal Form.

A table is in BCNF if, for every non-trivial functional dependency:

```text
X → Y
```

X must be a super key.

In simple words, every determinant must be a super key.

### Example: 3NF but Not in BCNF

Consider the following relation:

**STUDENT_INSTRUCTOR**

| Student | Subject | Instructor |
|---|---|---|
| Anurag | Java | Amit |
| Rahul | Java | Amit |
| Anurag | Python | Priya |

Assume the following business rules:

1. A student can study multiple subjects.
2. Each instructor teaches only one subject.
3. A student has one instructor for each subject.

Functional Dependencies:

```text
(Student, Subject) → Instructor

Instructor → Subject
```

Candidate Keys:

```text
(Student, Subject)

(Student, Instructor)
```

Why is it in 3NF?

For:

```text
Instructor → Subject
```

Instructor is not a super key, but Subject is a prime attribute because it belongs to the candidate key (Student, Subject).

Therefore, the relation satisfies 3NF.

Why is it not in BCNF?

Instructor is not a super key.

Therefore:

```text
Instructor → Subject
```

Violates BCNF.

### Convert into BCNF

Decompose the relation into:

**INSTRUCTOR_SUBJECT**

| Instructor (PK) | Subject |
|---|---|
| Amit | Java |
| Priya | Python |

**STUDENT_INSTRUCTOR**

| Student | Instructor |
|---|---|
| Anurag | Amit |
| Rahul | Amit |
| Anurag | Priya |

Now every non-trivial functional dependency has a super key as its determinant.

**Remember:** BCNF = Every determinant must be a super key.

---

## 6.5 Fourth Normal Form (4NF)

### Definition

A table is in Fourth Normal Form if:

1. It is already in BCNF.
2. It has no non-trivial multivalued dependencies unless the determinant is a super key.

A multivalued dependency is represented as:

```text
X →→ Y
```

It means that for a given X, there can be multiple independent values of Y.

### Example: Not in 4NF

Consider a Student table containing independent hobbies and languages.

| Student | Hobby | Language |
|---|---|---|
| Anurag | Cricket | English |
| Anurag | Cricket | Marathi |
| Anurag | Reading | English |
| Anurag | Reading | Marathi |

Here:

- Anurag has multiple hobbies.
- Anurag knows multiple languages.
- Hobbies and languages are independent of each other.

Multivalued dependencies:

```text
Student →→ Hobby

Student →→ Language
```

This causes unnecessary combinations.

### Convert into 4NF

**STUDENT_HOBBY**

| Student | Hobby |
|---|---|
| Anurag | Cricket |
| Anurag | Reading |

**STUDENT_LANGUAGE**

| Student | Language |
|---|---|
| Anurag | English |
| Anurag | Marathi |

Now independent multivalued facts are stored separately.

**Remember:** 4NF = BCNF + No Non-trivial Multivalued Dependency.

---

## 6.6 Fifth Normal Form (5NF)

### Definition

Fifth Normal Form is also called Project-Join Normal Form (PJNF).

A table is in 5NF if:

1. It is already in 4NF.
2. Every non-trivial join dependency is implied by candidate keys.

It ensures that a table cannot be further decomposed into smaller tables without losing information or introducing spurious tuples when joined back.

### Example

Consider a relation:

```text
SUPPLIER_PART_PROJECT
```

Attributes:

- Supplier
- Part
- Project

Assume the business rules guarantee that a valid supplier-part-project combination can be reconstructed from these three pairwise relationships.

The original table may contain:

| Supplier | Part | Project |
|---|---|---|
| S1 | P1 | J1 |
| S1 | P2 | J1 |
| S2 | P1 | J2 |

It can be decomposed into three relations:

**SUPPLIER_PART**

| Supplier | Part |
|---|---|
| S1 | P1 |
| S1 | P2 |
| S2 | P1 |

**SUPPLIER_PROJECT**

| Supplier | Project |
|---|---|
| S1 | J1 |
| S2 | J2 |

**PART_PROJECT**

| Part | Project |
|---|---|
| P1 | J1 |
| P2 | J1 |
| P1 | J2 |

The original relation can be reconstructed using JOIN operations if the required join dependency holds.

**Important:** This decomposition is valid only when the business rules guarantee the required join dependency. Arbitrarily splitting a three-column table into pairs can create incorrect combinations.

**Remember:** 5NF = 4NF + No non-key join dependencies that permit further lossless decomposition.

---

# 7. Comparison of Normal Forms

| Normal Form | Main Condition |
|---|---|
| 1NF | Atomic values; no repeating groups |
| 2NF | 1NF + no partial dependency of non-prime attributes |
| 3NF | 2NF + no transitive dependency of non-prime attributes |
| BCNF | Every determinant must be a super key |
| 4NF | BCNF + no non-trivial multivalued dependency |
| 5NF | 4NF + join dependencies are implied by candidate keys |

### Easy Way to Remember

```text
1NF  → Atomic Values
2NF  → No Partial Dependency
3NF  → No Transitive Dependency
BCNF → Every Determinant is a Super Key
4NF  → No Independent Multivalued Dependencies
5NF  → No Unnecessary Join Dependencies
```

---

# 8. SQL Practical Examples

## Practical 1: Create Student Table

```sql
CREATE DATABASE normalization_db;

USE normalization_db;

CREATE TABLE student (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    dept_id INT,
    dept_name VARCHAR(50)
);
```

## Practical 2: Insert Records

```sql
INSERT INTO student VALUES
(101, 'Anurag', 1, 'AIML'),
(102, 'Rahul', 2, 'Computer'),
(103, 'Amit', 1, 'AIML');
```

## Practical 3: Create Normalized Tables

**Department Table**

```sql
CREATE TABLE department (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50)
);
```

**Student Table**

```sql
CREATE TABLE student_normalized (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    dept_id INT,
    FOREIGN KEY (dept_id)
        REFERENCES department(dept_id)
);
```

## Practical 4: Insert Data

```sql
INSERT INTO department VALUES
(1, 'AIML'),
(2, 'Computer');

INSERT INTO student_normalized VALUES
(101, 'Anurag', 1),
(102, 'Rahul', 2),
(103, 'Amit', 1);
```

## Practical 5: Retrieve Normalized Data Using JOIN

```sql
SELECT
    s.student_id,
    s.student_name,
    d.dept_name
FROM student_normalized s
JOIN department d
ON s.dept_id = d.dept_id;
```

---

# 9. Important Interview Questions

**Q1. What is normalization?**

Normalization is the process of organizing relational database tables to reduce redundancy and eliminate anomalies.

**Q2. What is data redundancy?**

Unnecessary duplication of data in a database is called data redundancy.

**Q3. What are the three types of anomalies?**

Insertion, Update and Deletion anomalies.

**Q4. What is functional dependency?**

A relationship where one attribute or a set of attributes determines another attribute.

**Q5. What is a partial dependency?**

A non-key attribute depending on only a part of a composite candidate key.

**Q6. What is a transitive dependency?**

A dependency where a non-key attribute depends on another non-key attribute through a candidate key.

**Q7. What is 1NF?**

A relation is in 1NF when its attributes contain atomic values and there are no repeating groups.

**Q8. What is 2NF?**

A relation is in 2NF if it is in 1NF and every non-prime attribute is fully functionally dependent on every candidate key.

**Q9. What is 3NF?**

A relation is in 3NF if, for every non-trivial FD X → A, X is a super key or A is a prime attribute.

**Q10. What is BCNF?**

A relation is in BCNF if every determinant of a non-trivial functional dependency is a super key.

**Q11. What is the difference between 3NF and BCNF?**

3NF permits a non-super-key determinant when the dependent attribute is prime, whereas BCNF requires every determinant to be a super key.

**Q12. What is a multivalued dependency?**

A relationship where one attribute determines multiple independent values of another attribute.

**Q13. What is 4NF?**

A relation in BCNF with no non-trivial multivalued dependency unless its determinant is a super key.

**Q14. What is 5NF?**

A relation in which every non-trivial join dependency is implied by candidate keys.

**Q15. Does normalization always improve query performance?**

No. Normalization improves data integrity and reduces redundancy, but additional JOIN operations may affect query performance.

---

# 10. Important MCQs

**Q1. What is the main purpose of normalization?**

A. Increase redundancy  
B. Reduce redundancy  
C. Delete database  
D. Increase duplication  

**Answer: B**

**Q2. Which anomaly occurs when updating duplicate information in multiple rows?**

A. Insertion  
B. Deletion  
C. Update  
D. None  

**Answer: C**

**Q3. Which normal form removes repeating groups and ensures atomic values?**

A. 1NF  
B. 2NF  
C. 3NF  
D. BCNF  

**Answer: A**

**Q4. Which normal form eliminates partial dependencies?**

A. 1NF  
B. 2NF  
C. 3NF  
D. 4NF  

**Answer: B**

**Q5. Which normal form eliminates transitive dependencies of non-prime attributes?**

A. 1NF  
B. 2NF  
C. 3NF  
D. 5NF  

**Answer: C**

**Q6. In BCNF, every determinant must be a:**

A. Foreign key  
B. Candidate key  
C. Super key  
D. Composite attribute  

**Answer: C**

**Q7. Which normal form deals with multivalued dependencies?**

A. 2NF  
B. 3NF  
C. 4NF  
D. 5NF  

**Answer: C**

**Q8. Fifth Normal Form is also known as:**

A. Atomic Normal Form  
B. Project-Join Normal Form  
C. Functional Normal Form  
D. Composite Normal Form  

**Answer: B**

**Q9. X → Y represents:**

A. Multivalued dependency  
B. Functional dependency  
C. Join dependency  
D. Transitive relationship  

**Answer: B**

**Q10. Which dependency is removed in 2NF?**

A. Transitive dependency  
B. Partial dependency  
C. Multivalued dependency  
D. Join dependency  

**Answer: B**

---

# 11. Quick Revision

| Concept | Remember |
|---|---|
| Normalization | Reduces redundancy |
| Redundancy | Duplicate data |
| Insertion Anomaly | Difficulty inserting information |
| Update Anomaly | Inconsistent updates |
| Deletion Anomaly | Unintended loss of information |
| Functional Dependency | X determines Y |
| Partial Dependency | Depends on part of composite key |
| Transitive Dependency | Non-key attribute depends on another non-key attribute |
| 1NF | Atomic values |
| 2NF | No partial dependency |
| 3NF | No transitive dependency of non-prime attributes |
| BCNF | Every determinant is a super key |
| 4NF | No non-trivial multivalued dependency |
| 5NF | Join dependency based on candidate keys |

---

# 12. Practice Checklist

- [ ] Understand data redundancy.
- [ ] Understand insertion anomaly.
- [ ] Understand update anomaly.
- [ ] Understand deletion anomaly.
- [ ] Practice functional dependency problems.
- [ ] Identify candidate keys and super keys.
- [ ] Understand full functional dependency.
- [ ] Understand partial dependency.
- [ ] Understand transitive dependency.
- [ ] Convert an unnormalized table into 1NF.
- [ ] Convert a 1NF table into 2NF.
- [ ] Convert a 2NF table into 3NF.
- [ ] Understand BCNF decomposition.
- [ ] Understand multivalued dependency and 4NF.
- [ ] Understand join dependency and 5NF.
- [ ] Practice SQL implementation using normalized tables.
- [ ] Solve MCQs and interview questions.

---

## Recommended Learning Resources

1. MySQL Documentation: https://dev.mysql.com/doc/
2. GeeksforGeeks DBMS: https://www.geeksforgeeks.org/dbms/
3. W3Schools SQL: https://www.w3schools.com/sql/
4. TutorialsPoint DBMS: https://www.tutorialspoint.com/dbms/

---

**End of Session 3 – Normalization**

*Database Technologies | PGCP-AC | CMCE | August 2026*

**Learning Goal:** Understand data redundancy, anomalies, functional dependencies and all major normal forms, and learn to design normalized relational database tables.</WritingBlock}

**Important for CMCE:** Focus especially on functional dependencies, candidate keys, partial dependency, transitive dependency, and step-by-step conversion from 1NF to BCNF. Practice identifying the candidate keys before decomposing a relation. These are essential for solving normalization problems in theory examinations and interviews.
