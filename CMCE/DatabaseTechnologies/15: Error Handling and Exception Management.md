# Session 15: Error Handling and Exception Management in MySQL

**Course:** PGCP-AC / CMCE – August 2026  
**Subject:** Database Technologies  
**Session:** 15  
**Topics:** Error Handling, Exceptions, Handler Actions, Writing Handlers, SIGNAL, RESIGNAL, Exception Handling in Stored Procedures and Functions

---

## 1. Introduction to Error Handling

**Error Handling** is a mechanism used to detect, manage and respond to errors that occur during program execution.

In MySQL, error handling is commonly implemented using **HANDLERS** inside stored procedures, stored functions and other stored programs.

### Why do we need error handling?

Consider an employee management application.

Suppose we try to insert an employee with an existing primary key.

```sql
INSERT INTO employees
VALUES (1, 'Rahul', 'IT', 30000);
```

If employee ID 1 already exists, MySQL generates a duplicate key error.

Without proper error handling, the procedure may terminate unexpectedly.

With error handling, we can:

- Display a meaningful error message.
- Continue execution when appropriate.
- Exit the current block safely.
- Roll back a transaction when required.
- Handle missing records.
- Prevent unexpected application failures.

### Advantages of error handling

1. Improves application reliability.
2. Prevents unexpected termination.
3. Makes errors easier to understand.
4. Helps maintain database consistency.
5. Supports transaction management.
6. Makes stored procedures and functions more robust.

---

## 2. What Is an Exception?

An **Exception** is an error or unusual condition that occurs during program execution and interrupts the normal execution flow.

### Common examples

| Situation | Description |
|---|---|
| Duplicate entry | Inserting an existing primary key |
| Record not found | SELECT query returns no row |
| Division by zero | Performing division by zero |
| Invalid data | Inserting data that violates a constraint |
| Foreign key error | Referencing a non-existing parent record |
| SQL syntax error | Writing an invalid SQL statement |

### Error handling flow

```text
       Start Procedure
              |
              v
        Execute SQL
              |
              v
       Error Occurs?
         /       \
       No         Yes
       |           |
       v           v
 Continue       Handler Executes
       |           |
       |      CONTINUE / EXIT
       |           |
       +-----+-----+
             |
             v
          End
```

---

## 3. Types of Conditions in MySQL

MySQL provides three important condition classes for handling SQL conditions.

### 3.1 SQLEXCEPTION

`SQLEXCEPTION` handles SQL errors that are not in the SQLWARNING or NOT FOUND classes.

Examples:

- Duplicate primary key.
- Foreign key constraint violation.
- Other SQL execution errors.

**Syntax:**

```sql
DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
BEGIN
    -- Error handling statements
END;
```

### 3.2 SQLWARNING

`SQLWARNING` handles SQL warnings.

Warnings indicate that something unusual happened during execution, but the statement did not necessarily fail.

**Syntax:**

```sql
DECLARE CONTINUE HANDLER FOR SQLWARNING
BEGIN
    -- Warning handling statements
END;
```

### 3.3 NOT FOUND

`NOT FOUND` handles situations where no data is found.

Common examples:

- Cursor FETCH reaches the end of the result set.
- SELECT ... INTO returns no row.

**Syntax:**

```sql
DECLARE CONTINUE HANDLER FOR NOT FOUND
BEGIN
    -- Handle missing data
END;
```

### Comparison

| Condition | Purpose | SQLSTATE Class |
|---|---|---|
| SQLEXCEPTION | Handles SQL errors | Other error classes |
| SQLWARNING | Handles SQL warnings | 01 |
| NOT FOUND | Handles missing data | 02 |

---

## 4. Types of Handler Actions

MySQL provides three handler action types in its syntax:

1. CONTINUE
2. EXIT
3. UNDO

However, MySQL supports only CONTINUE and EXIT. UNDO is not supported.

### 4.1 CONTINUE Handler

A `CONTINUE` handler handles the condition and continues execution after the statement that caused the condition.

**Syntax:**

```sql
DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
BEGIN
    SELECT 'Error occurred' AS Message;
END;
```

**Example:**

```sql
DELIMITER //

CREATE PROCEDURE continue_handler_demo()
BEGIN
    DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
    BEGIN
        SELECT 'An error occurred' AS Message;
    END;

    INSERT INTO employees
    VALUES (1, 'Rahul', 'IT', 30000);

    SELECT 'Procedure continues' AS Status;
END //

DELIMITER ;
```

Execute:

```sql
CALL continue_handler_demo();
```

If the INSERT generates a SQL exception, the handler executes and the procedure continues with the next statement.

**Use:** When an error should be handled without terminating the current block.

### 4.2 EXIT Handler

An `EXIT` handler handles the condition and exits the BEGIN...END block in which the handler is declared.

**Syntax:**

```sql
DECLARE EXIT HANDLER FOR SQLEXCEPTION
BEGIN
    SELECT 'Error occurred. Exiting block.' AS Message;
END;
```

**Example:**

```sql
DELIMITER //

CREATE PROCEDURE exit_handler_demo()
BEGIN
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        SELECT 'An error occurred' AS Message;
    END;

    INSERT INTO employees
    VALUES (1, 'Rahul', 'IT', 30000);

    SELECT 'This statement may not execute' AS Status;
END //

DELIMITER ;
```

Execute:

```sql
CALL exit_handler_demo();
```

If the INSERT generates an exception, the EXIT handler executes and the current block terminates. The statement after the failed INSERT is skipped.

**Use:** When an error should stop execution of the current block.

### 4.3 UNDO Handler

An `UNDO` handler is intended to undo operations when a condition occurs.

However, MySQL does not support UNDO handlers.

**Remember:** MySQL supports CONTINUE and EXIT handlers, not UNDO handlers.

### Handler comparison

| Handler | Action | MySQL Support |
|---|---|---|
| CONTINUE | Handles condition and continues | Yes |
| EXIT | Handles condition and exits current block | Yes |
| UNDO | Intended to undo operations | No |

---

## 5. Writing Handlers in MySQL

A handler is declared using the `DECLARE HANDLER` statement.

### General syntax

```sql
DECLARE handler_action HANDLER
FOR condition_value
BEGIN
    -- Handler statements
END;
```

Where:

- `handler_action`: CONTINUE or EXIT.
- `condition_value`: SQLEXCEPTION, SQLWARNING, NOT FOUND, SQLSTATE or MySQL error code.
- Handler statements: SQL statements executed when the condition occurs.

### Example

```sql
DELIMITER //

CREATE PROCEDURE handler_demo()
BEGIN

    DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
    BEGIN
        SELECT 'SQL Error Handled' AS Message;
    END;

    -- Executable SQL statements

END //

DELIMITER ;
```

### Important declaration order

Inside a MySQL stored program, declarations must follow this order:

1. Variables and named conditions.
2. Cursors.
3. Handlers.
4. Executable statements.

**Remember:** DECLARE statements must appear at the beginning of their respective BEGIN...END blocks.

---

## 6. Handling Specific MySQL Errors

Instead of handling every SQL exception, we can handle a particular error using its MySQL error code or SQLSTATE.

### Example 1: Duplicate Entry Error

MySQL error code:

```text
1062 - Duplicate entry
```

**Procedure:**

```sql
DELIMITER //

CREATE PROCEDURE duplicate_error_demo()
BEGIN

    DECLARE CONTINUE HANDLER FOR 1062
    BEGIN
        SELECT 'Duplicate employee ID' AS Message;
    END;

    INSERT INTO employees
    VALUES (1, 'Rahul', 'IT', 30000);

    SELECT 'Execution completed' AS Status;

END //

DELIMITER ;
```

Execute:

```sql
CALL duplicate_error_demo();
```

If employee ID 1 already exists, the handler handles the duplicate entry error.

### Example 2: Handling Using SQLSTATE

SQLSTATE is a five-character code used to identify SQL conditions.

```sql
DECLARE CONTINUE HANDLER FOR SQLSTATE '23000'
BEGIN
    SELECT 'Integrity constraint violation' AS Message;
END;
```

SQLSTATE `23000` represents an integrity constraint violation class, which includes errors such as duplicate key violations.

### Error handling comparison

| Method | Example | Purpose |
|---|---|---|
| MySQL error code | `1062` | Handles a specific MySQL error |
| SQLSTATE | `'23000'` | Handles a SQL condition class/state |
| SQLEXCEPTION | `SQLEXCEPTION` | Handles general SQL exceptions |
| SQLWARNING | `SQLWARNING` | Handles SQL warnings |
| NOT FOUND | `NOT FOUND` | Handles missing data |

---

## 7. Defining Custom Conditions

MySQL allows us to define a named condition using `DECLARE CONDITION`.

It makes stored procedures easier to read and understand.

### Syntax

```sql
DECLARE condition_name CONDITION
FOR SQLSTATE '45000';
```

### Example

```sql
DELIMITER //

CREATE PROCEDURE custom_condition_demo()
BEGIN

    DECLARE invalid_salary CONDITION
    FOR SQLSTATE '45000';

    DECLARE EXIT HANDLER FOR invalid_salary
    BEGIN
        SELECT 'Invalid salary detected' AS Message;
    END;

    IF 5000 < 10000 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Salary must be at least 10000';
    END IF;

    SELECT 'Valid salary' AS Status;

END //

DELIMITER ;
```

Execute:

```sql
CALL custom_condition_demo();
```

### Explanation

- `DECLARE CONDITION` defines a named condition.
- `invalid_salary` is the condition name.
- `SQLSTATE '45000'` represents a user-defined exception.
- `SIGNAL` raises the exception.
- The EXIT handler handles it.

---

## 8. SIGNAL Statement

The `SIGNAL` statement is used to generate an error or warning condition manually.

It is commonly used to enforce business rules in stored procedures, functions and triggers.

### Syntax

```sql
SIGNAL SQLSTATE '45000'
SET MESSAGE_TEXT = 'Custom error message';
```

### Example: Invalid Salary

```sql
DELIMITER //

CREATE PROCEDURE check_salary(IN p_salary DECIMAL(10,2))
BEGIN

    IF p_salary <= 0 THEN

        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Salary must be greater than zero';

    ELSE

        SELECT 'Valid salary' AS Message;

    END IF;

END //

DELIMITER ;
```

Execute:

```sql
CALL check_salary(30000);
```

Output:

```text
Valid salary
```

Execute:

```sql
CALL check_salary(-5000);
```

The procedure raises an error:

```text
Salary must be greater than zero
```

### Important points

- `SIGNAL` manually raises a condition.
- `SQLSTATE '45000'` is commonly used for user-defined errors.
- `MESSAGE_TEXT` specifies the error message.
- It can be used to enforce business rules.

---

## 9. RESIGNAL Statement

The `RESIGNAL` statement is used inside a handler to pass the handled condition back to the caller or to propagate it with modified information.

It is useful when we want to log an error and then allow the original error to be reported.

### Syntax

```sql
DECLARE EXIT HANDLER FOR SQLEXCEPTION
BEGIN

    -- Handle or log error

    RESIGNAL;

END;
```

### Example

```sql
DELIMITER //

CREATE PROCEDURE resignal_demo()
BEGIN

    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN

        SELECT 'Error detected in procedure' AS Message;

        RESIGNAL;

    END;

    INSERT INTO employees
    VALUES (1, 'Rahul', 'IT', 30000);

END //

DELIMITER ;
```

Execute:

```sql
CALL resignal_demo();
```

If the INSERT fails due to a duplicate key, the handler executes and RESIGNAL passes the original error back to the caller.

### SIGNAL vs RESIGNAL

| SIGNAL | RESIGNAL |
|---|---|
| Raises a new condition | Re-raises or propagates a handled condition |
| Can be used to generate custom errors | Used inside a handler |
| Commonly uses SQLSTATE 45000 | Can preserve the original error |
| Used for validation | Used for error propagation |

---

## 10. Practical 1: Exception Handling in Stored Procedure

**Objective:** Create a stored procedure that handles duplicate employee IDs.

### Step 1: Create the table

```sql
CREATE TABLE employee_details (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50),
    salary DECIMAL(10,2)
);
```

### Step 2: Insert sample records

```sql
INSERT INTO employee_details
VALUES
(1, 'Rahul', 30000),
(2, 'Amit', 40000);
```

### Step 3: Create the procedure

```sql
DELIMITER //

CREATE PROCEDURE insert_employee(
    IN p_id INT,
    IN p_name VARCHAR(50),
    IN p_salary DECIMAL(10,2)
)
BEGIN

    DECLARE EXIT HANDLER FOR 1062
    BEGIN
        SELECT 'Employee ID already exists' AS Message;
    END;

    INSERT INTO employee_details
    VALUES (p_id, p_name, p_salary);

    SELECT 'Employee inserted successfully' AS Message;

END //

DELIMITER ;
```

### Step 4: Execute the procedure

Valid insertion:

```sql
CALL insert_employee(3, 'Priya', 45000);
```

Duplicate insertion:

```sql
CALL insert_employee(1, 'Rohan', 35000);
```

The second call activates the duplicate key handler.

### Step 5: Verify records

```sql
SELECT * FROM employee_details;
```

---

## 11. Practical 2: CONTINUE Handler

**Objective:** Handle an exception and continue procedure execution.

```sql
DELIMITER //

CREATE PROCEDURE continue_demo()
BEGIN

    DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
    BEGIN
        SELECT 'Error handled successfully' AS Message;
    END;

    INSERT INTO employee_details
    VALUES (1, 'Rahul', 30000);

    SELECT 'Procedure execution continues' AS Status;

END //

DELIMITER ;
```

Execute:

```sql
CALL continue_demo();
```

If employee ID 1 already exists:

1. INSERT generates a duplicate key error.
2. CONTINUE handler executes.
3. The next SELECT statement executes.

**Learning:** CONTINUE does not terminate the current block.

---

## 12. Practical 3: EXIT Handler

**Objective:** Stop the current block when an SQL exception occurs.

```sql
DELIMITER //

CREATE PROCEDURE exit_demo()
BEGIN

    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        SELECT 'Error occurred. Exiting procedure block.' AS Message;
    END;

    INSERT INTO employee_details
    VALUES (1, 'Rahul', 30000);

    SELECT 'This statement will be skipped' AS Status;

END //

DELIMITER ;
```

Execute:

```sql
CALL exit_demo();
```

If the INSERT fails, the EXIT handler executes and the current block terminates.

---

## 13. Practical 4: Exception Handling with NOT FOUND

**Objective:** Handle a situation where an employee record does not exist.

```sql
DELIMITER //

CREATE PROCEDURE get_employee(
    IN p_id INT
)
BEGIN

    DECLARE v_name VARCHAR(50);
    DECLARE v_salary DECIMAL(10,2);

    DECLARE CONTINUE HANDLER FOR NOT FOUND
    BEGIN
        SELECT 'Employee not found' AS Message;
    END;

    SELECT emp_name, salary
    INTO v_name, v_salary
    FROM employee_details
    WHERE emp_id = p_id;

    SELECT v_name AS Employee_Name,
           v_salary AS Salary;

END //

DELIMITER ;
```

Execute with an existing employee:

```sql
CALL get_employee(1);
```

Execute with a non-existing employee:

```sql
CALL get_employee(100);
```

The NOT FOUND handler handles the missing record.

**Note:** Because this example uses a CONTINUE handler, execution continues after the missing-row condition. The variables may remain NULL, so the final SELECT can also display NULL values. For cleaner output, use a flag to control whether the employee details should be displayed.

---

## 14. Practical 5: Transaction Handling with Exception

**Objective:** Roll back a transaction if an SQL exception occurs.

Transactions help maintain database consistency.

### Step 1: Create a table

```sql
CREATE TABLE bank_accounts (
    account_id INT PRIMARY KEY,
    account_holder VARCHAR(50),
    balance DECIMAL(10,2)
) ENGINE = InnoDB;
```

### Step 2: Insert sample records

```sql
INSERT INTO bank_accounts
VALUES
(101, 'Rahul', 50000),
(102, 'Amit', 30000);
```

### Step 3: Create a transfer procedure

```sql
DELIMITER //

CREATE PROCEDURE transfer_money(
    IN p_from INT,
    IN p_to INT,
    IN p_amount DECIMAL(10,2)
)
BEGIN

    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        ROLLBACK;
        RESIGNAL;
    END;

    IF p_amount <= 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Transfer amount must be positive';
    END IF;

    START TRANSACTION;

    UPDATE bank_accounts
    SET balance = balance - p_amount
    WHERE account_id = p_from
      AND balance >= p_amount;

    IF ROW_COUNT() = 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Insufficient balance or invalid sender';
    END IF;

    UPDATE bank_accounts
    SET balance = balance + p_amount
    WHERE account_id = p_to;

    IF ROW_COUNT() = 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Receiver account not found';
    END IF;

    COMMIT;

    SELECT 'Transfer successful' AS Message;

END //

DELIMITER ;
```

### Step 4: Execute the procedure

```sql
CALL transfer_money(101, 102, 5000);
```

### Step 5: Verify balances

```sql
SELECT * FROM bank_accounts;
```

### Explanation

- `START TRANSACTION` starts the transaction.
- UPDATE deducts money from the sender.
- UPDATE adds money to the receiver.
- `COMMIT` saves both changes.
- If an SQL exception occurs, the EXIT handler executes ROLLBACK.
- `RESIGNAL` passes the error back to the caller.

**Important:** This example uses InnoDB tables so that transaction rollback works. For production banking systems, additional validation, locking and concurrency controls are required.

---

## 15. Exception Handling in Stored Functions

MySQL also supports condition handlers inside stored functions.

A stored function returns a value using the `RETURN` statement.

### Example: Function with Exception Handling

**Objective:** Create a function that calculates the percentage of marks.

```sql
DELIMITER //

CREATE FUNCTION calculate_percentage(
    p_obtained DECIMAL(10,2),
    p_total DECIMAL(10,2)
)
RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN

    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        RESIGNAL;
    END;

    IF p_total <= 0 THEN

        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Total marks must be greater than zero';

    END IF;

    RETURN (p_obtained / p_total) * 100;

END //

DELIMITER ;
```

### Execute

Valid input:

```sql
SELECT calculate_percentage(450, 500);
```

Output:

```text
90.00
```

Invalid input:

```sql
SELECT calculate_percentage(450, 0);
```

The function raises a custom exception.

### Important points

- Functions can declare handlers.
- Functions can use SIGNAL and RESIGNAL.
- Functions return values using RETURN.
- Stored functions have restrictions on operations such as transaction control.
- A function should handle errors according to its business requirements.

---

## 16. Handler Precedence in MySQL

When multiple handlers match the same condition, MySQL applies handler precedence.

The general priority is:

1. MySQL error code handler – highest priority.
2. Specific SQLSTATE handler.
3. General condition class handler such as SQLEXCEPTION.

### Example

```sql
DECLARE CONTINUE HANDLER FOR 1062
    SELECT 'Duplicate entry' AS Message;

DECLARE CONTINUE HANDLER FOR SQLSTATE '23000'
    SELECT 'Integrity constraint error' AS Message;

DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
    SELECT 'General SQL error' AS Message;
```

If error 1062 occurs, the handler for error code 1062 takes precedence over the broader handlers.

**Note:** Avoid declaring overlapping handlers unnecessarily. Clear, specific handlers make procedures easier to understand.

---

## 17. Important MySQL Error Codes and SQLSTATE

| Error Code | Meaning |
|---:|---|
| 1062 | Duplicate entry |
| 1048 | Column cannot be NULL |
| 1451 | Cannot delete or update a parent row |
| 1452 | Cannot add or update a child row |
| 1054 | Unknown column |
| 1146 | Table doesn't exist |
| 1364 | Field doesn't have a default value |
| 1366 | Incorrect value for column |

### Important SQLSTATE values

| SQLSTATE | Meaning |
|---|---|
| 23000 | Integrity constraint violation |
| 02000 | No data / NOT FOUND |
| 01000 | Warning |
| 45000 | User-defined exception |

---

## 18. Important Interview Questions and Answers

**Q1. What is error handling in MySQL?**

Error handling is a mechanism used to detect and manage errors during stored program execution.

**Q2. What is an exception?**

An exception is an error or unusual condition that interrupts normal program execution.

**Q3. What is a handler?**

A handler is a block of code that executes when a specified SQL condition occurs.

**Q4. What are the types of handler actions in MySQL?**

CONTINUE, EXIT and UNDO are handler actions in the syntax, but MySQL supports only CONTINUE and EXIT. UNDO is not supported.

**Q5. What is a CONTINUE handler?**

It handles the condition and continues execution after the statement that generated the condition.

**Q6. What is an EXIT handler?**

It handles the condition and exits the BEGIN...END block in which the handler is declared.

**Q7. What is SQLEXCEPTION?**

It handles SQL errors that are not in the SQLWARNING or NOT FOUND classes.

**Q8. What is SQLWARNING?**

It handles SQL warning conditions.

**Q9. What is NOT FOUND?**

It handles situations where no data is found, such as a cursor reaching the end of its result set.

**Q10. What is SIGNAL?**

SIGNAL is used to raise an error or warning condition manually.

**Q11. What is RESIGNAL?**

RESIGNAL is used inside a handler to re-raise or propagate a handled condition.

**Q12. What is SQLSTATE?**

SQLSTATE is a five-character code used to identify SQL conditions.

**Q13. What is SQLSTATE 45000?**

It represents a user-defined exception condition, commonly used with SIGNAL.

**Q14. What is DECLARE CONDITION?**

It defines a named condition that can be used when declaring a handler.

**Q15. Can we use exception handling in stored functions?**

Yes. MySQL stored functions support handlers, SIGNAL and RESIGNAL.

**Q16. What is the difference between SIGNAL and RESIGNAL?**

SIGNAL raises a new condition, whereas RESIGNAL propagates a condition already being handled.

**Q17. Can a handler manage duplicate key errors?**

Yes. We can use error code 1062 or an appropriate SQLSTATE handler.

**Q18. Why do we use ROLLBACK in an EXIT handler?**

ROLLBACK reverses uncommitted transactional changes when an error occurs.

**Q19. What is handler precedence?**

It determines which handler executes when multiple handlers match a condition.

**Q20. Where should handlers be declared?**

After variable and condition declarations and after cursor declarations, but before executable statements in the same block.

---

## 19. Quick Revision Notes

| Concept | Key Point |
|---|---|
| Exception | Error or unusual condition |
| Handler | Manages a SQL condition |
| CONTINUE | Handles error and continues |
| EXIT | Handles error and exits current block |
| UNDO | Not supported by MySQL |
| SQLEXCEPTION | Handles SQL errors |
| SQLWARNING | Handles warnings |
| NOT FOUND | Handles missing data |
| SIGNAL | Raises a new condition |
| RESIGNAL | Propagates a handled condition |
| SQLSTATE | Five-character condition code |
| 45000 | User-defined exception |
| 1062 | Duplicate entry |
| ROLLBACK | Reverses uncommitted changes |
| COMMIT | Saves transactional changes |

### Important points to remember

- MySQL supports CONTINUE and EXIT handlers.
- UNDO handlers are not supported.
- Handlers are declared before executable statements.
- Variables and conditions are declared before cursors.
- Cursors are declared before handlers.
- SIGNAL is used to generate custom errors.
- RESIGNAL is used inside a handler.
- NOT FOUND handles missing rows and cursor exhaustion.
- Functions can also use handlers.
- Transaction rollback requires a transactional storage engine such as InnoDB.

---

## 20. Lab Practice Checklist

- [ ] Create a stored procedure with a CONTINUE handler.
- [ ] Create a stored procedure with an EXIT handler.
- [ ] Handle duplicate entry errors.
- [ ] Handle NOT FOUND conditions.
- [ ] Handle SQLWARNING conditions.
- [ ] Handle general SQL exceptions.
- [ ] Define a custom condition using DECLARE CONDITION.
- [ ] Raise a custom error using SIGNAL.
- [ ] Use RESIGNAL inside a handler.
- [ ] Implement transaction rollback on error.
- [ ] Create a stored function with exception handling.
- [ ] Practise MySQL error codes and SQLSTATE values.
- [ ] Understand handler precedence.

---

## 21. Useful SQL Commands for Revision

```sql
-- Display stored procedures
SHOW PROCEDURE STATUS;

-- Display a procedure definition
SHOW CREATE PROCEDURE insert_employee;

-- Execute a stored procedure
CALL insert_employee(3, 'Priya', 45000);

-- Drop a stored procedure
DROP PROCEDURE IF EXISTS insert_employee;

-- Display stored functions
SHOW FUNCTION STATUS;

-- Display a function definition
SHOW CREATE FUNCTION calculate_percentage;

-- Execute a stored function
SELECT calculate_percentage(450, 500);

-- Drop a function
DROP FUNCTION IF EXISTS calculate_percentage;

-- Check employee records
SELECT * FROM employee_details;

-- Check bank account balances
SELECT * FROM bank_accounts;
```

---

**End of Session 15 – Error Handling and Exception Management**

**Topics covered:** Exceptions, Handler Actions, CONTINUE Handler, EXIT Handler, SQLEXCEPTION, SQLWARNING, NOT FOUND, DECLARE CONDITION, SIGNAL, RESIGNAL, Transaction Rollback and Exception Handling in Stored Procedures and Functions.
