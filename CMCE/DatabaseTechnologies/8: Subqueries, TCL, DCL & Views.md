# Session 8: Subqueries, TCL, DCL & Views

**Course:** CMCE – Database Technologies  
**Batch:** August 2026  
**Theory:** 2 Hours | **Lab:** 2 Hours | **Self-Learning:** 2 Hours

---

## 📌 Topics Covered

1. Subqueries
2. Types of Subqueries
3. Correlated Subqueries
4. `EXISTS` and `NOT EXISTS`
5. TCL Commands:
   - `COMMIT`
   - `ROLLBACK`
   - `SAVEPOINT`
6. DCL Commands:
   - `GRANT`
   - `REVOKE`
   - `GRANT OPTION`
7. Views
8. Types of Views
9. Simple and Complex Views
10. Indexes
11. Temporary Tables

---

# 1. Introduction to Subqueries

A **Subquery** is a query written inside another SQL query.

The inner query executes to provide a result that is used by the outer query.

A subquery is also called an **Inner Query** or **Nested Query**.

### Why Do We Use Subqueries?

- To retrieve data based on another query's result.
- To find employees earning above average salary.
- To find the highest or lowest values.
- To filter records using another table.
- To perform complex database operations.

### Basic Syntax

```sql
SELECT column_name
FROM table_name
WHERE column_name OPERATOR (
    SELECT column_name
    FROM another_table
);
```

### Example

Find employees earning more than the average salary.

```sql
SELECT *
FROM employees
WHERE salary > (
    SELECT AVG(salary)
    FROM employees
);
```

**Explanation:**

1. The inner query calculates the average salary.
2. The outer query selects employees whose salary is greater than that average.

---

# 2. Types of Subqueries

Subqueries can be classified based on the number of rows and columns returned and how they are executed.

## 2.1 Single-Row Subquery

A Single-Row Subquery returns only one row.

Common operators:

- `=`
- `>`
- `<`
- `>=`
- `<=`
- `<>`

### Example: Find Employees Earning More Than the Lowest Salary

```sql
SELECT *
FROM employees
WHERE salary > (
    SELECT MIN(salary)
    FROM employees
);
```

## 2.2 Multiple-Row Subquery

A Multiple-Row Subquery returns more than one row.

Common operators:

- `IN`
- `NOT IN`
- `ANY`
- `ALL`

### Example: Find Employees Working in IT or HR

```sql
SELECT *
FROM employees
WHERE department IN (
    SELECT department
    FROM employees
    WHERE department IN ('IT', 'HR')
);
```

### ANY Operator

`ANY` returns TRUE if the comparison is true for at least one value returned by the subquery.

```sql
SELECT *
FROM employees
WHERE salary > ANY (
    SELECT salary
    FROM employees
    WHERE department = 'HR'
);
```

This finds employees whose salary is greater than at least one HR employee's salary.

### ALL Operator

`ALL` returns TRUE if the comparison is true for every value returned by the subquery.

```sql
SELECT *
FROM employees
WHERE salary > ALL (
    SELECT salary
    FROM employees
    WHERE department = 'HR'
);
```

This finds employees whose salary is greater than every HR employee's salary.

## 2.3 Multiple-Column Subquery

A Multiple-Column Subquery returns more than one column.

### Example

```sql
SELECT *
FROM employees
WHERE (department, salary) IN (
    SELECT department, MAX(salary)
    FROM employees
    GROUP BY department
);
```

This finds employees whose salary matches the maximum salary in their department.

## 2.4 Scalar Subquery

A Scalar Subquery returns exactly one value: one row and one column.

### Example

```sql
SELECT
    employee_name,
    salary,
    (SELECT AVG(salary) FROM employees) AS company_avg
FROM employees;
```

The average salary is displayed alongside every employee.

### Subquery Types – Quick Comparison

| Type | Result |
|---|---|
| Single-Row | One row |
| Multiple-Row | Multiple rows |
| Multiple-Column | Multiple columns |
| Scalar | Exactly one value |
| Correlated | Depends on the outer query |

**Note:** These classifications overlap. For example, a scalar subquery is also a single-row, single-column subquery.

---

# 3. Correlated Subqueries

A **Correlated Subquery** is a subquery that depends on values from the outer query.

Unlike a normal independent subquery, it references a column from the outer query.

It is evaluated conceptually for each outer row, although the database optimizer may transform the execution.

### Example: Find Employees Earning More Than Their Department's Average Salary

```sql
SELECT *
FROM employees e
WHERE salary > (
    SELECT AVG(salary)
    FROM employees
    WHERE department = e.department
);
```

### Explanation

1. The outer query selects an employee.
2. The inner query calculates the average salary of that employee's department.
3. The outer query compares the employee's salary with that average.
4. The process is repeated conceptually for each employee.

### Another Example: Find the Highest-Paid Employee in Each Department

```sql
SELECT *
FROM employees e
WHERE salary = (
    SELECT MAX(salary)
    FROM employees
    WHERE department = e.department
);
```

This returns all employees tied for the highest salary in their department.

### Normal Subquery vs Correlated Subquery

| Normal Subquery | Correlated Subquery |
|---|---|
| Independent of outer query | Depends on outer query |
| Does not reference outer query columns | References outer query columns |
| Can execute independently | Cannot execute independently in its correlated form |
| Often calculates a common result | Calculates a result related to each outer row |

---

# 4. EXISTS and NOT EXISTS

`EXISTS` and `NOT EXISTS` are used to check whether a subquery returns any rows.

They are commonly used with correlated subqueries.

## 4.1 EXISTS

`EXISTS` returns TRUE if the subquery returns at least one row.

### Syntax

```sql
SELECT column_name
FROM table_name
WHERE EXISTS (
    SELECT 1
    FROM another_table
    WHERE condition
);
```

### Example: Find Departments Having Employees

```sql
SELECT DISTINCT department
FROM employees e
WHERE EXISTS (
    SELECT 1
    FROM employees e2
    WHERE e2.department = e.department
);
```

This returns departments that have at least one employee.

### Example Using Two Tables

Suppose we have:

**departments table**

| department_id | department_name |
|---:|---|
| 1 | IT |
| 2 | HR |
| 3 | Finance |

**employees table**

| emp_id | employee_name | department_id |
|---:|---|---:|
| 101 | Anurag | 1 |
| 102 | Rahul | 1 |
| 103 | Sneha | 2 |

Find departments having employees:

```sql
SELECT *
FROM departments d
WHERE EXISTS (
    SELECT 1
    FROM employees e
    WHERE e.department_id = d.department_id
);
```

## 4.2 NOT EXISTS

`NOT EXISTS` returns TRUE if the subquery returns no rows.

### Example: Find Departments Having No Employees

```sql
SELECT *
FROM departments d
WHERE NOT EXISTS (
    SELECT 1
    FROM employees e
    WHERE e.department_id = d.department_id
);
```

In the sample data, Finance is returned because no employee belongs to it.

### EXISTS vs NOT EXISTS

| EXISTS | NOT EXISTS |
|---|---|
| Checks whether matching rows exist | Checks whether matching rows do not exist |
| TRUE if subquery returns at least one row | TRUE if subquery returns zero rows |
| Used to find matching records | Used to find missing or unmatched records |

**Important:** `EXISTS` checks whether rows exist; the actual values in the subquery's `SELECT` list are generally irrelevant. Therefore, `SELECT 1` is commonly used.

---

# 5. TCL – Transaction Control Language

**TCL (Transaction Control Language)** is used to manage transactions in a database.

A transaction is a group of SQL operations treated as a logical unit of work.

### Important TCL Commands

1. `COMMIT`
2. `ROLLBACK`
3. `SAVEPOINT`

## 5.1 COMMIT

`COMMIT` permanently saves the changes made in the current transaction.

### Example

```sql
START TRANSACTION;

UPDATE employees
SET salary = salary + 5000
WHERE emp_id = 1;

COMMIT;
```

After `COMMIT`, the change is saved.

## 5.2 ROLLBACK

`ROLLBACK` cancels changes made in the current transaction that have not yet been committed.

### Example

```sql
START TRANSACTION;

UPDATE employees
SET salary = salary + 5000
WHERE emp_id = 1;

ROLLBACK;
```

The salary change is cancelled.

## 5.3 SAVEPOINT

`SAVEPOINT` creates a named point inside a transaction.

We can roll back to a particular savepoint without cancelling the entire transaction.

### Example

```sql
START TRANSACTION;

UPDATE employees
SET salary = salary + 1000
WHERE emp_id = 1;

SAVEPOINT sp1;

UPDATE employees
SET salary = salary + 2000
WHERE emp_id = 2;

SAVEPOINT sp2;

UPDATE employees
SET salary = salary + 3000
WHERE emp_id = 3;

ROLLBACK TO SAVEPOINT sp2;

COMMIT;
```

### Explanation

1. First employee's salary is increased by 1000.
2. `sp1` is created.
3. Second employee's salary is increased by 2000.
4. `sp2` is created.
5. Third employee's salary is increased by 3000.
6. `ROLLBACK TO SAVEPOINT sp2` cancels the changes after `sp2`.
7. `COMMIT` saves the remaining changes.

Therefore:

- Employee 1's change is saved.
- Employee 2's change is saved.
- Employee 3's change is cancelled.

### TCL Commands – Difference

| Command | Purpose |
|---|---|
| `COMMIT` | Saves transaction changes permanently |
| `ROLLBACK` | Cancels uncommitted changes |
| `SAVEPOINT` | Creates a point inside a transaction |
| `ROLLBACK TO SAVEPOINT` | Reverts changes after a savepoint |

### Important Transaction Notes

- Transactions are supported by transactional storage engines such as InnoDB.
- `START TRANSACTION` begins a transaction.
- `COMMIT` ends the current transaction.
- `ROLLBACK` without a savepoint cancels the current uncommitted transaction.
- `ROLLBACK TO SAVEPOINT` does not end the transaction.
- DDL statements such as `CREATE`, `ALTER`, and `DROP` generally cause implicit commits in MySQL. Do not expect ordinary rollback behavior for DDL.
- Autocommit is enabled by default in MySQL unless changed.

### Check Autocommit

```sql
SELECT @@autocommit;
```

Disable autocommit for the session:

```sql
SET autocommit = 0;
```

Enable it again:

```sql
SET autocommit = 1;
```

---

# 6. DCL – Data Control Language

**DCL (Data Control Language)** is used to manage user permissions and access to database objects.

It controls what database users are allowed to do.

### Important DCL Commands

1. `GRANT`
2. `REVOKE`

## 6.1 GRANT

`GRANT` is used to provide privileges to a database user.

### Syntax

```sql
GRANT privilege_name
ON database_name.table_name
TO 'username'@'host';
```

### Example: Grant SELECT Permission

```sql
GRANT SELECT
ON company.employees
TO 'user1'@'localhost';
```

The user can read records from the employees table.

### Grant Multiple Privileges

```sql
GRANT SELECT, INSERT, UPDATE
ON company.employees
TO 'user1'@'localhost';
```

The user can:

- View records.
- Insert records.
- Update records.

### Common Database Privileges

| Privilege | Purpose |
|---|---|
| `SELECT` | Read records |
| `INSERT` | Insert records |
| `UPDATE` | Modify records |
| `DELETE` | Delete records |
| `CREATE` | Create database objects |
| `ALTER` | Modify table structure |
| `DROP` | Delete database objects |
| `INDEX` | Create or drop indexes |
| `EXECUTE` | Execute stored routines |
| `ALL PRIVILEGES` | Grant all applicable privileges at the specified scope |

## 6.2 REVOKE

`REVOKE` removes previously granted privileges from a user.

### Syntax

```sql
REVOKE privilege_name
ON database_name.table_name
FROM 'username'@'host';
```

### Example

```sql
REVOKE INSERT
ON company.employees
FROM 'user1'@'localhost';
```

The user loses permission to insert records into the employees table.

## 6.3 GRANT OPTION

`WITH GRANT OPTION` allows a user to grant the privileges they received to other users.

### Example

```sql
GRANT SELECT
ON company.employees
TO 'user1'@'localhost'
WITH GRANT OPTION;
```

Now `user1` can grant the SELECT privilege on that table to another user, subject to the privilege scope and applicable rules.

### Revoke GRANT OPTION

```sql
REVOKE GRANT OPTION
ON company.employees
FROM 'user1'@'localhost';
```

This removes the ability to pass on the granted privilege.

### Example: Complete User Permission Practical

First, create a user (requires suitable administrative privileges):

```sql
CREATE USER 'user1'@'localhost'
IDENTIFIED BY 'StrongPassword123!';
```

Grant SELECT and INSERT:

```sql
GRANT SELECT, INSERT
ON company.employees
TO 'user1'@'localhost';
```

Check the user's grants:

```sql
SHOW GRANTS FOR 'user1'@'localhost';
```

Revoke INSERT:

```sql
REVOKE INSERT
ON company.employees
FROM 'user1'@'localhost';
```

**Important:**

- Use `CREATE USER` before granting privileges if the user does not exist.
- `GRANT` and `REVOKE` require appropriate administrative privileges.
- MySQL manages privileges through its privilege system; `FLUSH PRIVILEGES` is not normally needed after using `GRANT` or `REVOKE`.
- MySQL does not support granting or revoking privileges on an individual column using the `ALL PRIVILEGES` privilege.

---

# 7. Views

A **View** is a virtual table based on the result of an SQL query.

A view does not normally store the actual result data separately. It stores the query definition and retrieves data from its underlying tables when queried.

### Why Do We Use Views?

- Simplify complex SQL queries.
- Hide sensitive columns.
- Provide controlled access to data.
- Improve query readability.
- Present selected data from multiple tables.

## 7.1 Create a View

### Syntax

```sql
CREATE VIEW view_name AS
SELECT column1, column2
FROM table_name
WHERE condition;
```

### Example: Create a View for IT Employees

```sql
CREATE VIEW it_employees AS
SELECT emp_id, employee_name, salary
FROM employees
WHERE department = 'IT';
```

## 7.2 Query a View

A view can be queried like a normal table.

```sql
SELECT *
FROM it_employees;
```

### Query Specific Columns

```sql
SELECT employee_name, salary
FROM it_employees;
```

## 7.3 Update a View

Some views are updatable.

```sql
UPDATE it_employees
SET salary = 65000
WHERE emp_id = 1;
```

If the view is updatable, this operation modifies the underlying table.

## 7.4 Replace a View

```sql
CREATE OR REPLACE VIEW it_employees AS
SELECT emp_id, employee_name, salary, department
FROM employees
WHERE department = 'IT';
```

## 7.5 Drop a View

```sql
DROP VIEW it_employees;
```

---

# 8. Types of Views

Views can be classified into different types based on their query structure and behavior.

Common categories:

1. Simple View
2. Complex View

## 8.1 Simple View

A Simple View is generally created using a single table without aggregate functions or grouping.

### Example

```sql
CREATE VIEW employee_view AS
SELECT emp_id, employee_name, salary
FROM employees;
```

Characteristics:

- Usually based on one table.
- Does not require joins.
- Does not use aggregate functions.
- Often updatable if it meets MySQL's updatability rules.

## 8.2 Complex View

A Complex View is created using more advanced SQL operations.

It may involve:

- Multiple tables.
- Joins.
- Aggregate functions.
- `GROUP BY`.
- `DISTINCT`.

### Example: Department-wise Average Salary

```sql
CREATE VIEW department_salary_view AS
SELECT
    department,
    AVG(salary) AS average_salary
FROM employees
GROUP BY department;
```

Query the view:

```sql
SELECT *
FROM department_salary_view;
```

Characteristics:

- Can use multiple tables.
- Can contain aggregate functions.
- Can use grouping.
- Generally not directly updatable in MySQL when it contains grouping or aggregate functions.

### Simple View vs Complex View

| Simple View | Complex View |
|---|---|
| Usually based on one table | May use multiple tables |
| Simple SELECT query | Uses joins or advanced operations |
| No aggregate functions or grouping | May use aggregate functions or grouping |
| Often updatable | Generally not directly updatable |
| Easy to maintain | Useful for complex reporting |

**Note:** These are common teaching classifications, not a complete formal definition of every possible view. Actual updatability depends on the view definition and MySQL rules.

---

# 9. Important View Options

## 9.1 WITH CHECK OPTION

`WITH CHECK OPTION` prevents inserts or updates through a view that would make the modified row no longer satisfy the view's `WHERE` condition.

### Example

```sql
CREATE VIEW hr_employees AS
SELECT emp_id, employee_name, department, salary
FROM employees
WHERE department = 'HR'
WITH CHECK OPTION;
```

An update through this view cannot change an employee's department from HR to IT.

## 9.2 WITH CASCADED CHECK OPTION

Checks the conditions of the current view and underlying views.

```sql
CREATE OR REPLACE VIEW hr_employees AS
SELECT emp_id, employee_name, department, salary
FROM employees
WHERE department = 'HR'
WITH CASCADED CHECK OPTION;
```

## 9.3 WITH LOCAL CHECK OPTION

Checks the condition of the current view itself, rather than cascading through underlying views.

```sql
CREATE OR REPLACE VIEW hr_employees AS
SELECT emp_id, employee_name, department, salary
FROM employees
WHERE department = 'HR'
WITH LOCAL CHECK OPTION;
```

---

# 10. Indexes

An **Index** is a database structure that helps retrieve records faster.

It works similarly to an index in a book: instead of scanning every record, the database can use the index to locate relevant records more efficiently.

### Why Do We Use Indexes?

- Improve search performance.
- Speed up filtering using `WHERE`.
- Improve some join operations.
- Help with sorting and grouping in suitable queries.
- Enforce uniqueness through unique indexes.

### Create an Index

**Syntax:**

```sql
CREATE INDEX index_name
ON table_name(column_name);
```

### Example

```sql
CREATE INDEX idx_employee_name
ON employees(employee_name);
```

### Query Using an Indexed Column

```sql
SELECT *
FROM employees
WHERE employee_name = 'Anurag';
```

The MySQL optimizer may use the index if it considers it beneficial.

## 10.1 Unique Index

A Unique Index prevents duplicate indexed values.

```sql
CREATE UNIQUE INDEX idx_unique_email
ON employees(email);
```

This example requires an `email` column to exist in the table.

## 10.2 Composite Index

A Composite Index is created on multiple columns.

```sql
CREATE INDEX idx_dept_salary
ON employees(department, salary);
```

This index is particularly useful for queries filtering by the leading column (`department`) or by both columns.

## 10.3 Drop an Index

```sql
DROP INDEX idx_employee_name
ON employees;
```

## 10.4 Show Indexes

```sql
SHOW INDEXES FROM employees;
```

## 10.5 Check Query Execution Plan

```sql
EXPLAIN
SELECT *
FROM employees
WHERE employee_name = 'Anurag';
```

`EXPLAIN` helps understand how MySQL plans to execute a query, including possible index usage.

### Types of Indexes – Overview

| Index Type | Purpose |
|---|---|
| Primary Key Index | Supports primary key uniqueness |
| Unique Index | Prevents duplicate indexed values |
| Normal Index | Helps speed up searches |
| Composite Index | Indexes multiple columns |
| Full-Text Index | Supports full-text searching |
| Spatial Index | Supports spatial data searches |

### Important Points About Indexes

- Indexes improve read performance in suitable queries.
- Indexes require additional storage.
- Too many indexes can slow down INSERT, UPDATE, and DELETE operations.
- MySQL InnoDB automatically creates an index for a primary key.
- InnoDB requires a suitable index on foreign key columns and may create one automatically.
- A composite index follows the leftmost-prefix principle.
- An index does not guarantee that MySQL will use it for every query.

---

# 11. Temporary Tables

A **Temporary Table** is a table created to store temporary data during a database session.

Temporary tables are useful for intermediate calculations and processing.

### Characteristics

- Created using `CREATE TEMPORARY TABLE`.
- Visible only within the current database session.
- Automatically dropped when the session ends.
- Can be manually dropped using `DROP TEMPORARY TABLE`.
- Different sessions can create temporary tables with the same name.

## 11.1 Create a Temporary Table

### Syntax

```sql
CREATE TEMPORARY TABLE table_name (
    column1 datatype,
    column2 datatype
);
```

### Example

```sql
CREATE TEMPORARY TABLE temp_employees (
    emp_id INT,
    employee_name VARCHAR(50),
    salary DECIMAL(10,2)
);
```

## 11.2 Insert Data

```sql
INSERT INTO temp_employees
VALUES
(1, 'Anurag', 60000),
(2, 'Rahul', 50000);
```

## 11.3 Display Temporary Table Records

```sql
SELECT *
FROM temp_employees;
```

## 11.4 Create a Temporary Table Using SELECT

```sql
CREATE TEMPORARY TABLE high_salary_employees AS
SELECT *
FROM employees
WHERE salary > 50000;
```

## 11.5 Drop a Temporary Table

```sql
DROP TEMPORARY TABLE temp_employees;
```

### Temporary Table vs Normal Table

| Temporary Table | Normal Table |
|---|---|
| Exists only for the current session | Exists permanently until dropped |
| Automatically dropped when session ends | Must be dropped manually |
| Used for temporary processing | Used for persistent data storage |
| Session-specific | Shared according to database permissions |

**Important:** Temporary tables are session-specific, not transaction-specific. A transaction rollback does not necessarily remove a temporary table created earlier.

---

# 12. Lab Practicals

Use the `employees` and `departments` tables from the examples above.

## Practical 1: Find Employees Earning More Than Average Salary

```sql
SELECT *
FROM employees
WHERE salary > (
    SELECT AVG(salary)
    FROM employees
);
```

## Practical 2: Find Employees Earning the Highest Salary

```sql
SELECT *
FROM employees
WHERE salary = (
    SELECT MAX(salary)
    FROM employees
);
```

## Practical 3: Find Employees Earning More Than Their Department Average

```sql
SELECT *
FROM employees e
WHERE salary > (
    SELECT AVG(salary)
    FROM employees
    WHERE department = e.department
);
```

## Practical 4: Find Highest-Paid Employee in Each Department

```sql
SELECT *
FROM employees e
WHERE salary = (
    SELECT MAX(salary)
    FROM employees
    WHERE department = e.department
);
```

## Practical 5: Use EXISTS

Find departments having employees.

```sql
SELECT *
FROM departments d
WHERE EXISTS (
    SELECT 1
    FROM employees e
    WHERE e.department_id = d.department_id
);
```

## Practical 6: Use NOT EXISTS

Find departments having no employees.

```sql
SELECT *
FROM departments d
WHERE NOT EXISTS (
    SELECT 1
    FROM employees e
    WHERE e.department_id = d.department_id
);
```

## Practical 7: Use COMMIT

```sql
START TRANSACTION;

UPDATE employees
SET salary = salary + 1000
WHERE emp_id = 1;

COMMIT;
```

## Practical 8: Use ROLLBACK

```sql
START TRANSACTION;

UPDATE employees
SET salary = salary + 1000
WHERE emp_id = 1;

ROLLBACK;
```

## Practical 9: Use SAVEPOINT

```sql
START TRANSACTION;

UPDATE employees
SET salary = salary + 1000
WHERE emp_id = 1;

SAVEPOINT sp1;

UPDATE employees
SET salary = salary + 2000
WHERE emp_id = 2;

ROLLBACK TO SAVEPOINT sp1;

COMMIT;
```

## Practical 10: GRANT Privileges

```sql
GRANT SELECT, INSERT
ON company.employees
TO 'user1'@'localhost';
```

## Practical 11: REVOKE Privileges

```sql
REVOKE INSERT
ON company.employees
FROM 'user1'@'localhost';
```

## Practical 12: Create and Query a View

```sql
CREATE VIEW high_salary_view AS
SELECT *
FROM employees
WHERE salary > 50000;
```

```sql
SELECT *
FROM high_salary_view;
```

## Practical 13: Create a Complex View

```sql
CREATE VIEW department_avg_view AS
SELECT
    department,
    AVG(salary) AS avg_salary
FROM employees
GROUP BY department;
```

```sql
SELECT *
FROM department_avg_view;
```

## Practical 14: Create an Index

```sql
CREATE INDEX idx_salary
ON employees(salary);
```

```sql
SHOW INDEXES FROM employees;
```

## Practical 15: Create a Temporary Table

```sql
CREATE TEMPORARY TABLE temp_high_salary AS
SELECT *
FROM employees
WHERE salary > 50000;
```

```sql
SELECT *
FROM temp_high_salary;
```

```sql
DROP TEMPORARY TABLE temp_high_salary;
```

---

# 13. Important Interview Questions

**Q1. What is a Subquery?**

A query written inside another SQL query is called a Subquery.

**Q2. What is a Correlated Subquery?**

A subquery that depends on the outer query and references its columns.

**Q3. What is the difference between a normal subquery and a correlated subquery?**

A normal subquery is independent of the outer query, whereas a correlated subquery depends on values from the outer query.

**Q4. What is EXISTS?**

`EXISTS` checks whether a subquery returns at least one row.

**Q5. What is NOT EXISTS?**

`NOT EXISTS` checks whether a subquery returns zero rows.

**Q6. What is the difference between IN and EXISTS?**

`IN` compares a value against values returned by a subquery. `EXISTS` checks whether matching rows exist.

**Q7. What is TCL?**

TCL stands for Transaction Control Language. It manages database transactions.

**Q8. What is COMMIT?**

It permanently saves changes made in the current transaction.

**Q9. What is ROLLBACK?**

It cancels uncommitted transaction changes.

**Q10. What is SAVEPOINT?**

It creates a named point inside a transaction to which we can roll back.

**Q11. What is DCL?**

DCL stands for Data Control Language. It manages user privileges and database access.

**Q12. What is GRANT?**

It provides privileges to database users.

**Q13. What is REVOKE?**

It removes previously granted privileges.

**Q14. What is GRANT OPTION?**

It allows a user to grant eligible privileges they received to other users.

**Q15. What is a View?**

A View is a virtual table based on an SQL query.

**Q16. What is the difference between a table and a view?**

A table stores data, whereas a normal view stores a query definition and retrieves data from underlying tables.

**Q17. What is a Simple View?**

A view generally based on a single table without grouping or aggregate functions.

**Q18. What is a Complex View?**

A view that may contain joins, aggregate functions, grouping, or other advanced SQL operations.

**Q19. Can we update a View?**

Yes, if the view is updatable according to the database's rules.

**Q20. What is WITH CHECK OPTION?**

It prevents modifications through a view that would cause the modified row to violate the view's filtering condition.

**Q21. What is an Index?**

An index is a database structure used to improve data retrieval performance.

**Q22. What is a Composite Index?**

An index created on two or more columns.

**Q23. What is a Temporary Table?**

A table that exists only for the current database session.

**Q24. What is the difference between a Temporary Table and a Normal Table?**

A temporary table is automatically removed when its session ends, whereas a normal table remains until explicitly dropped.

**Q25. Does ROLLBACK undo CREATE TABLE in MySQL?**

Generally, no. MySQL DDL statements such as `CREATE TABLE` cause implicit commits.

---

# 14. Quick Revision – Important Differences

### Subquery vs Correlated Subquery

| Subquery | Correlated Subquery |
|---|---|
| Independent query | Depends on outer query |
| Does not reference outer query columns | References outer query columns |
| Can execute independently | Requires outer-query values |

### COMMIT vs ROLLBACK

| COMMIT | ROLLBACK |
|---|---|
| Saves changes | Cancels uncommitted changes |
| Ends the current transaction | Ends the current transaction when used without a savepoint |
| Changes become permanent | Changes are reverted |

### GRANT vs REVOKE

| GRANT | REVOKE |
|---|---|
| Provides privileges | Removes privileges |
| Gives access | Restricts access |

### View vs Temporary Table

| View | Temporary Table |
|---|---|
| Stores a query definition | Stores temporary rows |
| Retrieves data from underlying tables | Stores its own temporary data |
| Exists until dropped | Exists until dropped or session ends |
| Usually does not store result rows separately | Stores data in a temporary table |

---

# 15. Self-Learning Practice Questions

Try solving these questions independently.

- [ ] Find employees earning more than the company's average salary.
- [ ] Find employees earning less than the company's average salary.
- [ ] Find employees earning the maximum salary.
- [ ] Find employees earning the minimum salary.
- [ ] Find the second-highest salary using a subquery.
- [ ] Find employees earning more than their department's average salary.
- [ ] Find the highest-paid employee in each department using a correlated subquery.
- [ ] Find departments having employees using EXISTS.
- [ ] Find departments having no employees using NOT EXISTS.
- [ ] Demonstrate COMMIT using an UPDATE statement.
- [ ] Demonstrate ROLLBACK using an UPDATE statement.
- [ ] Create two savepoints and roll back to one of them.
- [ ] Create a database user and grant SELECT permission.
- [ ] Grant INSERT and UPDATE permissions to a user.
- [ ] Revoke INSERT permission from a user.
- [ ] Grant SELECT permission using WITH GRANT OPTION.
- [ ] Create a simple view for IT employees.
- [ ] Create a complex view showing department-wise average salary.
- [ ] Update data through an updatable view.
- [ ] Create a view using WITH CHECK OPTION.
- [ ] Create a normal index on the salary column.
- [ ] Create a composite index on department and salary.
- [ ] Display indexes using SHOW INDEXES.
- [ ] Create a temporary table using CREATE TEMPORARY TABLE.
- [ ] Create a temporary table using CREATE TEMPORARY TABLE AS SELECT.

---

# 16. Important Points to Remember

1. A Subquery is a query inside another query.
2. A Correlated Subquery depends on the outer query.
3. `EXISTS` checks whether matching rows exist.
4. `NOT EXISTS` checks whether matching rows do not exist.
5. TCL manages transactions.
6. `COMMIT` saves changes.
7. `ROLLBACK` cancels uncommitted changes.
8. `SAVEPOINT` creates a rollback point.
9. DCL manages database privileges.
10. `GRANT` provides privileges.
11. `REVOKE` removes privileges.
12. `WITH GRANT OPTION` allows eligible privileges to be passed to other users.
13. A View is a virtual table based on a query.
14. A Simple View generally uses one table.
15. A Complex View may use joins and aggregate functions.
16. `WITH CHECK OPTION` enforces the view's filtering condition for modifications made through it.
17. Indexes improve data retrieval in suitable queries.
18. Composite indexes contain multiple columns.
19. Temporary tables are session-specific.
20. MySQL supports transactions with InnoDB.

---

# 17. Learning Resources

- [MySQL Subqueries Documentation](https://dev.mysql.com/doc/refman/8.0/en/subqueries.html)
- [MySQL EXISTS and NOT EXISTS](https://dev.mysql.com/doc/refman/8.0/en/exists-and-not-exists-subqueries.html)
- [MySQL Transaction Statements](https://dev.mysql.com/doc/refman/8.0/en/sql-transactional-statements.html)
- [MySQL Account Management Statements](https://dev.mysql.com/doc/refman/8.0/en/account-management-statements.html)
- [MySQL Views Documentation](https://dev.mysql.com/doc/refman/8.0/en/views.html)
- [MySQL CREATE INDEX Documentation](https://dev.mysql.com/doc/refman/8.0/en/create-index.html)
- [MySQL Temporary Tables](https://dev.mysql.com/doc/refman/8.0/en/create-temporary-table.html)

---

**Happy Learning! 🚀**

*Prepared for CMCE – August 2026 Batch | Database Technologies*
