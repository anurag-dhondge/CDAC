# Session 13: Cursors in MySQL

**Course:** PGCP-AC / CMCE – August 2026  
**Subject:** Database Technologies  
**Session:** 13  
**Topics:** Introduction to Cursors, Cursor Lifecycle, Cursor Types, Stored Procedures, Loops and Handlers

---

## 1. Introduction to Cursors

A **Cursor** is a database object used to process query results **one row at a time**.

Normally, SQL statements work with multiple rows together. However, sometimes we need to process each record separately. In such situations, we use cursors.

### Why do we need cursors?

Suppose an employee table contains 100 employees, and we want to:

- Calculate a bonus for every employee.
- Check each employee's salary individually.
- Generate personalized messages for employees.
- Update records based on individual conditions.
- Process records using loops and conditional statements.

A cursor allows us to fetch and process records one by one.

### Without a cursor

SQL processes multiple records together using statements such as:

```sql
UPDATE employees
SET salary = salary * 1.10;
```

This increases the salary of every employee by 10%.

### With a cursor

We can fetch each employee's record individually and apply different conditions.

For example:

- Salary below ₹30,000 → Increase by 15%.
- Salary between ₹30,000 and ₹50,000 → Increase by 10%.
- Salary above ₹50,000 → Increase by 5%.

This type of row-by-row processing can be implemented using a cursor.

### Important points

1. Cursors are generally used inside stored procedures.
2. They process query results one row at a time.
3. Cursors are useful when row-by-row processing is required.
4. Cursors require more processing than many set-based SQL operations.
5. A cursor must be declared, opened, fetched and closed.

---

## 2. Cursor Lifecycle

The cursor lifecycle consists of four main steps:

1. DECLARE
2. OPEN
3. FETCH
4. CLOSE

### Cursor lifecycle diagram

```text
       DECLARE
          |
          v
         OPEN
          |
          v
         FETCH
          |
          v
    Process the row
          |
          v
     More rows?
       /     \
     YES      NO
      |        |
      |        v
      |       CLOSE
      |        |
      +--------+
       Fetch again
```

### 2.1 DECLARE

The `DECLARE` statement creates a cursor and associates it with a SELECT query.

**Syntax:**

```sql
DECLARE cursor_name CURSOR FOR
SELECT column1, column2
FROM table_name;
```

**Example:**

```sql
DECLARE emp_cursor CURSOR FOR
SELECT emp_id, emp_name, salary
FROM employees;
```

Here:

- `emp_cursor` is the cursor name.
- The SELECT query specifies which records will be fetched.
- The cursor is declared but not yet opened.

### 2.2 OPEN

The `OPEN` statement executes the cursor's SELECT query and makes its result available for fetching.

**Syntax:**

```sql
OPEN cursor_name;
```

**Example:**

```sql
OPEN emp_cursor;
```

Important: We must open a cursor before fetching records from it.

### 2.3 FETCH

The `FETCH` statement retrieves the next row from the cursor result and stores its column values into variables.

**Syntax:**

```sql
FETCH cursor_name
INTO variable1, variable2, variable3;
```

**Example:**

```sql
FETCH emp_cursor
INTO v_id, v_name, v_salary;
```

Here:

- `v_id` stores the employee ID.
- `v_name` stores the employee name.
- `v_salary` stores the employee salary.

The number and order of variables must match the selected columns.

### 2.4 CLOSE

The `CLOSE` statement closes the cursor and releases its associated resources.

**Syntax:**

```sql
CLOSE cursor_name;
```

**Example:**

```sql
CLOSE emp_cursor;
```

Important: Always close the cursor after completing its processing.

---

## 3. Types of Cursors

Cursors can be classified based on their sensitivity to changes, modification capabilities and navigation.

### 3.1 Asensitive Cursor

An asensitive cursor does not guarantee whether it uses a copy of the result set or accesses the underlying data directly.

The database system decides how to handle the cursor internally.

**Example:**

```sql
DECLARE emp_cursor CURSOR FOR
SELECT emp_id, emp_name
FROM employees;
```

MySQL supports asensitive cursors.

### 3.2 Insensitive Cursor

An insensitive cursor works with a fixed copy of the result set.

Changes made to the original table after opening the cursor are not reflected in that cursor's result.

**Example (conceptual):**

A cursor fetches employee records at 10 AM. If another transaction updates an employee's salary at 10:05 AM, the cursor continues working with its original result set.

MySQL does not provide a separate `INSENSITIVE` cursor declaration option.

### 3.3 Read-Only Cursor

A read-only cursor allows records to be retrieved but does not allow rows to be directly updated or deleted through the cursor.

**Example:**

```sql
DECLARE emp_cursor CURSOR FOR
SELECT emp_id, emp_name
FROM employees;
```

MySQL cursors are read-only.

If records need to be updated, we can execute a separate UPDATE statement inside the procedure using the fetched values.

### 3.4 Non-scrollable Cursor

A non-scrollable cursor allows records to be fetched only in the forward direction.

We cannot move backward or jump directly to a particular row.

**Example:**

```sql
FETCH emp_cursor INTO v_id, v_name;
```

MySQL cursors are non-scrollable.

### Cursor types summary

| Cursor Type | Meaning | MySQL Support |
|---|---|---|
| Asensitive | Sensitivity to underlying data is not guaranteed | Yes |
| Insensitive | Uses a fixed result-set copy | No separate option |
| Read-only | Cannot directly modify rows through cursor | Yes |
| Non-scrollable | Fetches rows only in forward direction | Yes |

**Important for exams:** MySQL cursors are asensitive, read-only and non-scrollable.

---

## 4. Cursor Declaration Rules in MySQL

Inside a stored procedure, declarations must follow a specific order.

1. Local variables
2. Conditions
3. Cursors
4. Handlers

**Example:**

```sql
DELIMITER //

CREATE PROCEDURE cursor_demo()
BEGIN
    -- 1. Declare variables
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(50);

    -- 2. Declare cursor
    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, emp_name
        FROM employees;

    -- 3. Declare handler
    DECLARE EXIT HANDLER FOR NOT FOUND
        SET v_id = NULL;

    -- Executable statements
    OPEN emp_cursor;

    FETCH emp_cursor INTO v_id, v_name;

    CLOSE emp_cursor;
END //

DELIMITER ;
```

**Remember:** All DECLARE statements must appear at the beginning of their respective BEGIN...END blocks, before executable statements.

---

## 5. NOT FOUND Handler

A cursor may contain multiple records. We need to know when all records have been fetched.

For this purpose, MySQL provides the `NOT FOUND` condition.

A `NOT FOUND` condition occurs when a FETCH operation has no more rows to retrieve.

We use a handler to detect this situation.

### Syntax

```sql
DECLARE CONTINUE HANDLER FOR NOT FOUND
SET done = 1;
```

Explanation:

- `CONTINUE HANDLER`: Handles the condition and continues execution.
- `NOT FOUND`: Specifies the condition to handle.
- `done = 1`: Sets a flag indicating that no more rows are available.

### Why do we need a handler?

Suppose a cursor contains five employee records.

After fetching the fifth employee, the next FETCH operation finds no more records.

The handler sets `done = 1`, allowing the loop to terminate safely.

---

## 6. Creating a Sample Table for Cursor Practicals

We will use an `employees` table for the following examples.

```sql
CREATE DATABASE cursor_db;

USE cursor_db;

CREATE TABLE employees (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50),
    department VARCHAR(50),
    salary DECIMAL(10,2)
);
```

### Insert sample records

```sql
INSERT INTO employees
VALUES
(1, 'Rahul', 'IT', 25000),
(2, 'Amit', 'HR', 35000),
(3, 'Priya', 'IT', 45000),
(4, 'Sneha', 'Finance', 55000),
(5, 'Rohan', 'IT', 60000);
```

### Display records

```sql
SELECT * FROM employees;
```

### Sample output

| emp_id | emp_name | department | salary |
|---:|---|---|---:|
| 1 | Rahul | IT | 25000 |
| 2 | Amit | HR | 35000 |
| 3 | Priya | IT | 45000 |
| 4 | Sneha | Finance | 55000 |
| 5 | Rohan | IT | 60000 |

---

## 7. Practical 1: Simple Cursor-Based Stored Procedure

**Objective:** Create a stored procedure that declares, opens, fetches and closes a cursor.

```sql
DELIMITER //

CREATE PROCEDURE display_employees()
BEGIN
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(50);
    DECLARE v_salary DECIMAL(10,2);

    DECLARE done INT DEFAULT 0;

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, emp_name, salary
        FROM employees;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    FETCH emp_cursor
    INTO v_id, v_name, v_salary;

    SELECT
        v_id AS Employee_ID,
        v_name AS Employee_Name,
        v_salary AS Salary;

    CLOSE emp_cursor;
END //

DELIMITER ;
```

### Execute the procedure

```sql
CALL display_employees();
```

**Note:** This example fetches only the first row. The next practical demonstrates how to process all rows using a loop.

---

## 8. Practical 2: Process Records One Row at a Time Using a Cursor

**Objective:** Fetch all employee records using a cursor and display them one by one.

```sql
DELIMITER //

CREATE PROCEDURE display_all_employees()
BEGIN
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(50);
    DECLARE v_salary DECIMAL(10,2);

    DECLARE done INT DEFAULT 0;

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, emp_name, salary
        FROM employees;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    read_loop: LOOP

        FETCH emp_cursor
        INTO v_id, v_name, v_salary;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        SELECT
            v_id AS Employee_ID,
            v_name AS Employee_Name,
            v_salary AS Salary;

    END LOOP;

    CLOSE emp_cursor;
END //

DELIMITER ;
```

### Execute

```sql
CALL display_all_employees();
```

### Explanation

1. Declare the required variables.
2. Declare the cursor with a SELECT query.
3. Declare a NOT FOUND handler.
4. Open the cursor.
5. Start the loop.
6. Fetch one employee record.
7. Check whether all records are fetched.
8. Process the current employee.
9. Repeat until no more records are available.
10. Close the cursor.

---

## 9. Practical 3: Cursor with Conditional Statements

**Objective:** Process employee salaries using IF and ELSEIF conditions.

Business requirement:

- Salary below 30,000 → Low Salary
- Salary between 30,000 and 50,000 → Average Salary
- Salary above 50,000 → High Salary

```sql
DELIMITER //

CREATE PROCEDURE check_employee_salary()
BEGIN
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(50);
    DECLARE v_salary DECIMAL(10,2);

    DECLARE done INT DEFAULT 0;

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, emp_name, salary
        FROM employees;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    read_loop: LOOP

        FETCH emp_cursor
        INTO v_id, v_name, v_salary;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        IF v_salary < 30000 THEN

            SELECT v_name, v_salary, 'Low Salary' AS Status;

        ELSEIF v_salary <= 50000 THEN

            SELECT v_name, v_salary, 'Average Salary' AS Status;

        ELSE

            SELECT v_name, v_salary, 'High Salary' AS Status;

        END IF;

    END LOOP;

    CLOSE emp_cursor;
END //

DELIMITER ;
```

### Execute

```sql
CALL check_employee_salary();
```

### Expected classification

| Employee | Salary | Status |
|---|---:|---|
| Rahul | 25000 | Low Salary |
| Amit | 35000 | Average Salary |
| Priya | 45000 | Average Salary |
| Sneha | 55000 | High Salary |
| Rohan | 60000 | High Salary |

**Learning:** A cursor can be combined with IF, ELSEIF, ELSE, CASE and loops to implement business logic.

---

## 10. Practical 4: Cursor with UPDATE Statement

**Objective:** Increase employee salaries based on their existing salary.

Business requirement:

- Salary below 30,000 → Increase by 15%.
- Salary between 30,000 and 50,000 → Increase by 10%.
- Salary above 50,000 → Increase by 5%.

```sql
DELIMITER //

CREATE PROCEDURE increase_employee_salary()
BEGIN
    DECLARE v_id INT;
    DECLARE v_salary DECIMAL(10,2);

    DECLARE done INT DEFAULT 0;

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, salary
        FROM employees;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    read_loop: LOOP

        FETCH emp_cursor INTO v_id, v_salary;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        IF v_salary < 30000 THEN

            UPDATE employees
            SET salary = salary * 1.15
            WHERE emp_id = v_id;

        ELSEIF v_salary <= 50000 THEN

            UPDATE employees
            SET salary = salary * 1.10
            WHERE emp_id = v_id;

        ELSE

            UPDATE employees
            SET salary = salary * 1.05
            WHERE emp_id = v_id;

        END IF;

    END LOOP;

    CLOSE emp_cursor;
END //

DELIMITER ;
```

### Execute

```sql
CALL increase_employee_salary();
```

### Verify updated records

```sql
SELECT * FROM employees;
```

**Important:** This procedure changes the original table. Run it only when you want to update the sample records. Calling it again will increase the already-updated salaries again.

---

## 11. Practical 5: Cursor with WHILE Loop

**Objective:** Process employee records using a WHILE loop.

```sql
DELIMITER //

CREATE PROCEDURE display_employees_while()
BEGIN
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(50);

    DECLARE done INT DEFAULT 0;

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, emp_name
        FROM employees;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    FETCH emp_cursor INTO v_id, v_name;

    WHILE done = 0 DO

        SELECT v_id AS Employee_ID,
               v_name AS Employee_Name;

        FETCH emp_cursor INTO v_id, v_name;

    END WHILE;

    CLOSE emp_cursor;
END //

DELIMITER ;
```

### Execute

```sql
CALL display_employees_while();
```

**Explanation:** The first FETCH happens before the WHILE loop. This ensures that the loop does not process uninitialized variables when the cursor has no records.

---

## 12. Practical 6: Cursor with REPEAT Loop

**Objective:** Process employee records using a REPEAT loop.

```sql
DELIMITER //

CREATE PROCEDURE display_employees_repeat()
BEGIN
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(50);

    DECLARE done INT DEFAULT 0;

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, emp_name
        FROM employees;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    REPEAT

        FETCH emp_cursor INTO v_id, v_name;

        IF done = 0 THEN

            SELECT v_id AS Employee_ID,
                   v_name AS Employee_Name;

        END IF;

    UNTIL done = 1
    END REPEAT;

    CLOSE emp_cursor;
END //

DELIMITER ;
```

### Execute

```sql
CALL display_employees_repeat();
```

**Remember:** REPEAT executes its body before checking the UNTIL condition. Therefore, we must check `done = 0` before processing the fetched variables.

---

## 13. Practical 7: Cursor with Exception / Handler Support

**Objective:** Handle the situation when the cursor has no more records.

In MySQL, handlers are used to manage conditions that occur during stored procedure execution.

### Types of handlers

| Handler | Description |
|---|---|
| CONTINUE | Handles the condition and continues execution |
| EXIT | Handles the condition and exits the current BEGIN...END block |
| UNDO | Intended to undo operations, but not supported by MySQL |

### Common conditions

| Condition | Meaning |
|---|---|
| NOT FOUND | No data found |
| SQLEXCEPTION | General SQL exception |
| SQLWARNING | SQL warning |

### Example: Cursor with NOT FOUND Handler

```sql
DELIMITER //

CREATE PROCEDURE cursor_handler_demo()
BEGIN
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(50);

    DECLARE done INT DEFAULT 0;

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, emp_name
        FROM employees;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    read_loop: LOOP

        FETCH emp_cursor INTO v_id, v_name;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        SELECT v_id AS Employee_ID,
               v_name AS Employee_Name;

    END LOOP;

    CLOSE emp_cursor;
END //

DELIMITER ;
```

### Execute

```sql
CALL cursor_handler_demo();
```

### Explanation

- The cursor fetches one row at a time.
- When no more records are available, the NOT FOUND handler executes.
- The `done` variable becomes 1.
- The IF condition detects this situation.
- `LEAVE` terminates the loop.
- The cursor is closed.

**Important:** A cursor's FETCH operation normally raises NOT FOUND when there are no more rows. Without a suitable handler, the procedure may terminate with an error.

---

## 14. Practical 8: Cursor with SQLEXCEPTION Handler

**Objective:** Handle SQL exceptions during procedure execution and close the cursor.

```sql
DELIMITER //

CREATE PROCEDURE safe_cursor_demo()
BEGIN
    DECLARE v_id INT;
    DECLARE v_name VARCHAR(50);

    DECLARE done INT DEFAULT 0;

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_id, emp_name
        FROM employees;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        CLOSE emp_cursor;
        RESIGNAL;
    END;

    OPEN emp_cursor;

    read_loop: LOOP

        FETCH emp_cursor INTO v_id, v_name;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        SELECT v_id, v_name;

    END LOOP;

    CLOSE emp_cursor;
END //

DELIMITER ;
```

### Explanation

- `NOT FOUND` handles the end of the cursor result.
- `SQLEXCEPTION` handles an SQL exception.
- The EXIT handler closes the cursor if an SQL exception occurs.
- `RESIGNAL` passes the original error back to the caller.

**Note:** In this example, the EXIT handler is declared after the cursor, following MySQL's declaration-order rules. If the error occurs before the cursor is opened, a defensive implementation should account for the cursor's open state before closing it.

---

## 15. Real-World Cursor Examples

Cursors can be useful in situations where each record requires separate processing.

### Example 1: Employee Bonus Processing

Requirement:

- Employees earning below ₹30,000 get a 15% bonus.
- Employees earning ₹30,000–₹50,000 get a 10% bonus.
- Employees earning above ₹50,000 get a 5% bonus.

A cursor can fetch each employee and calculate the applicable bonus.

### Example 2: Student Result Processing

Suppose a student table contains:

| Student ID | Name | Marks |
|---:|---|---:|
| 1 | Rahul | 85 |
| 2 | Amit | 45 |
| 3 | Priya | 72 |

A cursor can process each student:

- Marks 75 or above → Distinction
- Marks 60–74 → First Class
- Marks 40–59 → Pass
- Marks below 40 → Fail

### Example 3: Bank Account Processing

A cursor can process account records individually to:

- Calculate interest.
- Check minimum balance.
- Apply service charges.
- Generate account-wise reports.

### Example 4: Order Processing

A cursor can process customer orders individually to:

- Calculate discounts.
- Calculate tax.
- Check order status.
- Generate invoices.

### Example 5: Email Notification Processing

A cursor can fetch customer records one by one and prepare personalized notifications.

**Practical recommendation:** Prefer set-based SQL operations for tasks that can be completed using a single UPDATE, INSERT or SELECT. Use cursors when individual row-by-row processing is genuinely necessary.

---

## 16. Cursor vs Normal SELECT

| Feature | Normal SELECT | Cursor |
|---|---|---|
| Processing | Returns a result set | Fetches rows one at a time |
| Row processing | Set-based | Row-by-row |
| Complexity | Usually simpler | More procedural code |
| Performance | Often faster for bulk operations | Can be slower |
| Usage | General data retrieval | Individual record processing |
| Loops | Not required for normal retrieval | Commonly used |

---

## 17. Important MySQL Cursor Syntax

### Declare cursor

```sql
DECLARE cursor_name CURSOR FOR
SELECT column_name
FROM table_name;
```

### Open cursor

```sql
OPEN cursor_name;
```

### Fetch cursor

```sql
FETCH cursor_name INTO variable_name;
```

### Close cursor

```sql
CLOSE cursor_name;
```

### Declare NOT FOUND handler

```sql
DECLARE CONTINUE HANDLER FOR NOT FOUND
SET done = 1;
```

### Leave loop

```sql
IF done = 1 THEN
    LEAVE read_loop;
END IF;
```

### Complete loop structure

```sql
OPEN cursor_name;

read_loop: LOOP

    FETCH cursor_name INTO variable_name;

    IF done = 1 THEN
        LEAVE read_loop;
    END IF;

    -- Process the fetched record

END LOOP;

CLOSE cursor_name;
```

---

## 18. Important Interview Questions and Answers

**Q1. What is a cursor in MySQL?**

A cursor is a database object used to retrieve and process query results one row at a time.

**Q2. Why do we use cursors?**

We use cursors when individual records need separate processing using conditions and loops.

**Q3. What are the four steps in the cursor lifecycle?**

1. DECLARE
2. OPEN
3. FETCH
4. CLOSE

**Q4. What is the purpose of DECLARE?**

It defines the cursor and associates it with a SELECT query.

**Q5. What is the purpose of OPEN?**

It executes the cursor query and makes the result available for fetching.

**Q6. What is the purpose of FETCH?**

It retrieves the next row from the cursor result into variables.

**Q7. What is the purpose of CLOSE?**

It closes the cursor and releases its associated resources.

**Q8. What is a NOT FOUND handler?**

It handles the condition when a FETCH operation has no more rows to retrieve.

**Q9. Why do we use a done variable?**

It is a flag used to identify when all cursor records have been fetched.

**Q10. What is the difference between CONTINUE and EXIT handlers?**

- CONTINUE handles the condition and continues execution.
- EXIT handles the condition and exits the current BEGIN...END block.

**Q11. Are MySQL cursors scrollable?**

No. MySQL cursors are non-scrollable and fetch rows in the forward direction.

**Q12. Are MySQL cursors read-only?**

Yes. MySQL cursors are read-only. Separate SQL statements can be used to modify the underlying table.

**Q13. Can we use cursors inside stored procedures?**

Yes. MySQL cursors are declared and used inside stored programs, such as stored procedures.

**Q14. Can we use IF and LOOP with cursors?**

Yes. Cursors can be combined with IF, ELSEIF, ELSE, LOOP, WHILE and REPEAT.

**Q15. What happens if we do not close a cursor?**

The cursor's associated resources may remain allocated until the routine or its execution context ends. It is good practice to close it explicitly.

**Q16. What is the difference between a cursor and a loop?**

A cursor retrieves records from a query result. A loop repeatedly executes statements. They are commonly used together for row-by-row processing.

**Q17. What is an asensitive cursor?**

An asensitive cursor does not guarantee whether the database uses a copy of the result set or accesses the underlying data directly.

**Q18. Should we always use cursors for multiple records?**

No. Set-based SQL is generally more efficient. Cursors are useful when individual row processing is required.

---

## 19. Quick Revision Notes

| Concept | Key Point |
|---|---|
| Cursor | Processes records one row at a time |
| DECLARE | Defines the cursor |
| OPEN | Opens and executes the cursor query |
| FETCH | Retrieves the next row |
| CLOSE | Closes the cursor |
| NOT FOUND | Indicates no more rows |
| CONTINUE Handler | Handles a condition and continues |
| EXIT Handler | Handles a condition and exits the block |
| LOOP | Repeats until explicitly terminated |
| LEAVE | Exits a loop or labelled block |
| Asensitive | Sensitivity to underlying data is not guaranteed |
| Read-only | Cannot directly update rows through cursor |
| Non-scrollable | Fetches only in the forward direction |

### Remember these points

- MySQL cursors are asensitive.
- MySQL cursors are read-only.
- MySQL cursors are non-scrollable.
- A cursor must be opened before fetching.
- A cursor should be closed after processing.
- Declare variables before cursors.
- Declare cursors before handlers.
- Use a NOT FOUND handler to detect the end of the result set.
- Use a `done` flag to terminate the loop.
- Prefer normal SQL operations when row-by-row processing is unnecessary.

---

## 20. Lab Practice Checklist

Use this checklist to track your practical preparation.

- [ ] Create an employees table with sample records.
- [ ] Declare a simple cursor.
- [ ] Open the cursor.
- [ ] Fetch a single record.
- [ ] Close the cursor.
- [ ] Create and execute a cursor-based stored procedure.
- [ ] Process all employee records using LOOP.
- [ ] Use a NOT FOUND handler.
- [ ] Use IF and ELSEIF with a cursor.
- [ ] Update employee salaries using a cursor.
- [ ] Process records using WHILE.
- [ ] Process records using REPEAT.
- [ ] Implement an SQLEXCEPTION handler.
- [ ] Practise cursor-related interview questions.

---

## 21. Useful Commands for Revision

```sql
-- Display all procedures
SHOW PROCEDURE STATUS
WHERE Db = 'cursor_db';

-- Display procedure definition
SHOW CREATE PROCEDURE display_all_employees;

-- Execute a procedure
CALL display_all_employees();

-- Drop a procedure
DROP PROCEDURE IF EXISTS display_all_employees;

-- Display employee records
SELECT * FROM employees;
```

---

**End of Session 13 – Cursors**

**Topics covered:** Cursor Introduction, Lifecycle, Cursor Types, DECLARE, OPEN, FETCH, CLOSE, Loops, Conditional Statements, NOT FOUND Handler, Exception Handling and Real-World Applications.
