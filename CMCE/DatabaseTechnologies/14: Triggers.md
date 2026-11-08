# Session 14: Triggers in MySQL

**Course:** PGCP-AC / CMCE – August 2026  
**Subject:** Database Technologies  
**Session:** 14  
**Topics:** Introduction to Triggers, Types of Triggers, Trigger Variables, BEFORE Triggers, AFTER Triggers and Real-World Examples

---

## 1. Introduction to Triggers

A **Trigger** is a database object that automatically executes when a specified event occurs on a table.

Triggers are commonly used to maintain data consistency, validate records, maintain audit logs and automatically perform certain operations.

Unlike stored procedures, triggers are not called explicitly using `CALL`. They execute automatically when their associated event occurs.

### Why do we use triggers?

Suppose we have an employee table.

Whenever a new employee is inserted, we want to:

- Automatically record the insertion date.
- Validate the employee's salary.
- Maintain an audit log.
- Track changes in employee records.
- Automatically update related information.

We can use triggers to perform these operations.

### Important points

1. Triggers execute automatically.
2. Triggers are associated with database tables.
3. They execute when a specified INSERT, UPDATE or DELETE event occurs.
4. They can execute before or after the triggering operation.
5. Triggers help maintain data consistency and automate database operations.

---

## 2. Types of Triggers

MySQL triggers are classified based on two main aspects:

**Based on execution time:**

1. BEFORE Trigger
2. AFTER Trigger

**Based on execution level:**

1. Row-level Trigger

MySQL supports row-level triggers. It does not support statement-level triggers.

### Trigger events

| Event | Description |
|---|---|
| INSERT | Executes when a new record is inserted |
| UPDATE | Executes when an existing record is updated |
| DELETE | Executes when a record is deleted |

### Trigger timing and events

| Timing | INSERT | UPDATE | DELETE |
|---|---|---|---|
| BEFORE | Yes | Yes | Yes |
| AFTER | Yes | Yes | Yes |

MySQL supports all six combinations.

---

## 3. BEFORE Trigger

A **BEFORE Trigger** executes before the actual INSERT, UPDATE or DELETE operation takes place.

It is commonly used for:

- Validating data.
- Checking business rules.
- Modifying values before insertion.
- Preventing invalid operations.

### Example

Suppose an employee's salary must be greater than zero.

We can create a BEFORE INSERT trigger to validate the salary.

```sql
DELIMITER //

CREATE TRIGGER before_employee_insert
BEFORE INSERT ON employees
FOR EACH ROW
BEGIN
    IF NEW.salary <= 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Salary must be greater than zero';
    END IF;
END //

DELIMITER ;
```

### Explanation

- `CREATE TRIGGER`: Creates a trigger.
- `before_employee_insert`: Trigger name.
- `BEFORE INSERT`: Executes before inserting a record.
- `ON employees`: Trigger is associated with the employees table.
- `FOR EACH ROW`: Executes for every affected row.
- `NEW.salary`: Refers to the salary of the new record.
- `SIGNAL SQLSTATE '45000'`: Raises a user-defined error.

### Test the trigger

Valid insertion:

```sql
INSERT INTO employees
VALUES (6, 'Karan', 'IT', 40000);
```

Invalid insertion:

```sql
INSERT INTO employees
VALUES (7, 'Ravi', 'HR', -5000);
```

**Expected result:** The second INSERT fails with the message:

```text
Salary must be greater than zero
```

---

## 4. AFTER Trigger

An **AFTER Trigger** executes after the triggering INSERT, UPDATE or DELETE operation has taken place successfully.

It is commonly used for:

- Maintaining audit records.
- Logging changes.
- Recording deleted data.
- Tracking employee activity.
- Updating related information.

### Example

Whenever a new employee is inserted, we want to store the employee's details in another table.

First, create an audit table:

```sql
CREATE TABLE employee_audit (
    audit_id INT AUTO_INCREMENT PRIMARY KEY,
    emp_id INT,
    emp_name VARCHAR(50),
    action_type VARCHAR(20),
    action_date DATETIME
);
```

Now create an AFTER INSERT trigger:

```sql
DELIMITER //

CREATE TRIGGER after_employee_insert
AFTER INSERT ON employees
FOR EACH ROW
BEGIN
    INSERT INTO employee_audit
    (emp_id, emp_name, action_type, action_date)
    VALUES
    (NEW.emp_id, NEW.emp_name, 'INSERT', NOW());
END //

DELIMITER ;
```

### Test the trigger

```sql
INSERT INTO employees
VALUES (8, 'Sagar', 'IT', 35000);
```

Check the audit table:

```sql
SELECT * FROM employee_audit;
```

**Expected result:** The new employee's ID and name are automatically recorded in `employee_audit`.

We did not manually insert anything into the audit table. The trigger performed that operation.

---

## 5. Row-Level Trigger

A **Row-Level Trigger** executes once for every row affected by an INSERT, UPDATE or DELETE statement.

MySQL supports only row-level triggers.

It uses:

```sql
FOR EACH ROW
```

### Example

Suppose we execute:

```sql
UPDATE employees
SET salary = salary + 1000
WHERE department = 'IT';
```

If five employees belong to the IT department, an UPDATE trigger defined with `FOR EACH ROW` executes five times.

### Important points

- Executes once for each affected row.
- Uses `FOR EACH ROW`.
- Can access OLD and NEW values depending on the event.
- MySQL does not support statement-level triggers.

---

## 6. Trigger Variables: OLD and NEW

MySQL provides two special trigger references:

1. `OLD`
2. `NEW`

They allow us to access values from the affected row.

### 6.1 OLD

`OLD` refers to the existing row values before an UPDATE or DELETE operation.

### 6.2 NEW

`NEW` refers to the new row values during an INSERT or UPDATE operation.

### OLD and NEW availability

| Trigger Event | OLD | NEW |
|---|---|---|
| BEFORE INSERT | Not available | Available |
| AFTER INSERT | Not available | Available |
| BEFORE UPDATE | Available | Available |
| AFTER UPDATE | Available | Available |
| BEFORE DELETE | Available | Not available |
| AFTER DELETE | Available | Not available |

### Example: OLD and NEW with UPDATE

Suppose an employee's salary changes from ₹30,000 to ₹40,000.

- `OLD.salary` = 30000
- `NEW.salary` = 40000

We can use these values to maintain salary history.

```sql
DELIMITER //

CREATE TRIGGER after_salary_update
AFTER UPDATE ON employees
FOR EACH ROW
BEGIN
    INSERT INTO employee_audit
    (emp_id, emp_name, action_type, action_date)
    VALUES
    (
        NEW.emp_id,
        NEW.emp_name,
        'UPDATE',
        NOW()
    );
END //

DELIMITER ;
```

The trigger records the updated employee details.

**Note:** The above audit table stores the action and employee details, but not the old and new salary values. The next example shows how to record both.

---

## 7. Practical 1: BEFORE INSERT Trigger

**Objective:** Prevent employees from being inserted with a negative or zero salary.

```sql
DELIMITER //

CREATE TRIGGER before_salary_insert
BEFORE INSERT ON employees
FOR EACH ROW
BEGIN
    IF NEW.salary <= 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Invalid salary';
    END IF;
END //

DELIMITER ;
```

### Execute

```sql
INSERT INTO employees
VALUES (9, 'Amit', 'Finance', 45000);
```

This INSERT is allowed.

Try:

```sql
INSERT INTO employees
VALUES (10, 'Rahul', 'HR', -1000);
```

This INSERT is rejected.

### Learning

BEFORE INSERT triggers are useful for validating data before it enters a table.

---

## 8. Practical 2: BEFORE UPDATE Trigger

**Objective:** Prevent an employee's salary from being reduced below ₹10,000.

```sql
DELIMITER //

CREATE TRIGGER before_salary_update
BEFORE UPDATE ON employees
FOR EACH ROW
BEGIN
    IF NEW.salary < 10000 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Salary cannot be below 10000';
    END IF;
END //

DELIMITER ;
```

### Test valid update

```sql
UPDATE employees
SET salary = 30000
WHERE emp_id = 1;
```

### Test invalid update

```sql
UPDATE employees
SET salary = 5000
WHERE emp_id = 1;
```

The second UPDATE is rejected because the new salary is below ₹10,000.

### Learning

BEFORE UPDATE triggers are useful for enforcing business rules when existing records are modified.

---

## 9. Practical 3: AFTER INSERT Trigger

**Objective:** Automatically record every newly inserted employee in an audit table.

Create the audit table:

```sql
CREATE TABLE employee_insert_log (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    emp_id INT,
    emp_name VARCHAR(50),
    created_at DATETIME
);
```

Create the trigger:

```sql
DELIMITER //

CREATE TRIGGER after_insert_employee
AFTER INSERT ON employees
FOR EACH ROW
BEGIN
    INSERT INTO employee_insert_log
    (emp_id, emp_name, created_at)
    VALUES
    (NEW.emp_id, NEW.emp_name, NOW());
END //

DELIMITER ;
```

### Test

```sql
INSERT INTO employees
VALUES (11, 'Pooja', 'HR', 32000);
```

Check the log:

```sql
SELECT * FROM employee_insert_log;
```

The employee details will automatically appear in the log table.

---

## 10. Practical 4: AFTER UPDATE Trigger

**Objective:** Maintain a record of old and new employee salaries.

First, create a salary history table:

```sql
CREATE TABLE salary_history (
    history_id INT AUTO_INCREMENT PRIMARY KEY,
    emp_id INT,
    old_salary DECIMAL(10,2),
    new_salary DECIMAL(10,2),
    changed_at DATETIME
);
```

Create the trigger:

```sql
DELIMITER //

CREATE TRIGGER after_employee_salary_update
AFTER UPDATE ON employees
FOR EACH ROW
BEGIN
    IF OLD.salary <> NEW.salary THEN

        INSERT INTO salary_history
        (emp_id, old_salary, new_salary, changed_at)
        VALUES
        (
            OLD.emp_id,
            OLD.salary,
            NEW.salary,
            NOW()
        );

    END IF;
END //

DELIMITER ;
```

### Test

```sql
UPDATE employees
SET salary = 50000
WHERE emp_id = 2;
```

Check salary history:

```sql
SELECT * FROM salary_history;
```

### Expected example

| emp_id | old_salary | new_salary |
|---:|---:|---:|
| 2 | 35000 | 50000 |

**Learning:** OLD and NEW help us track changes made to existing records.

---

## 11. Practical 5: AFTER DELETE Trigger

**Objective:** Store deleted employee details in a separate table.

Create a deleted employee table:

```sql
CREATE TABLE deleted_employees (
    delete_id INT AUTO_INCREMENT PRIMARY KEY,
    emp_id INT,
    emp_name VARCHAR(50),
    department VARCHAR(50),
    salary DECIMAL(10,2),
    deleted_at DATETIME
);
```

Create the trigger:

```sql
DELIMITER //

CREATE TRIGGER after_employee_delete
AFTER DELETE ON employees
FOR EACH ROW
BEGIN
    INSERT INTO deleted_employees
    (emp_id, emp_name, department, salary, deleted_at)
    VALUES
    (
        OLD.emp_id,
        OLD.emp_name,
        OLD.department,
        OLD.salary,
        NOW()
    );
END //

DELIMITER ;
```

### Test

```sql
DELETE FROM employees
WHERE emp_id = 11;
```

Check deleted records:

```sql
SELECT * FROM deleted_employees;
```

The deleted employee's details are stored automatically.

**Learning:** For DELETE triggers, we use `OLD` because the deleted row's values are available through OLD.

---

## 12. Real-World Trigger Examples

### Example 1: Banking System

When a bank account balance is updated, a trigger can record the previous and updated balances in a transaction history table.

### Example 2: Employee Management System

When an employee's salary changes, a trigger can automatically maintain salary history.

### Example 3: E-Commerce Application

When a new order is inserted, a trigger can automatically create an order audit record.

### Example 4: Student Management System

When a student's marks are updated, a trigger can maintain a history of previous marks.

### Example 5: Inventory Management System

When a product is sold, a trigger can automatically record stock changes.

### Example 6: Hospital Management System

When a patient record is updated or deleted, a trigger can maintain an audit history.

---

## 13. BEFORE vs AFTER Trigger

| Feature | BEFORE Trigger | AFTER Trigger |
|---|---|---|
| Execution | Before the triggering operation | After the triggering operation |
| Main purpose | Validation and value modification | Logging and auditing |
| Can modify NEW values? | Yes, for INSERT and UPDATE | No |
| Can access OLD? | Depends on event | Depends on event |
| Common usage | Validate salary | Maintain salary history |

**Important:** In MySQL, `SET NEW.column_name = value` can be used in a BEFORE INSERT or BEFORE UPDATE trigger. NEW values cannot be modified in an AFTER trigger.

---

## 14. Trigger vs Stored Procedure

| Feature | Trigger | Stored Procedure |
|---|---|---|
| Execution | Automatically | Called explicitly |
| Invocation | INSERT, UPDATE or DELETE event | CALL statement |
| Parameters | Cannot accept parameters | Supports parameters |
| Return value | Does not return a value | Can return result sets and OUT parameters |
| Association | Associated with a table | Stored in the database |
| Main purpose | Automatic actions | Reusable business logic |

---

## 15. Important MySQL Trigger Commands

### Create trigger

```sql
CREATE TRIGGER trigger_name
BEFORE INSERT ON table_name
FOR EACH ROW
BEGIN
    -- Statements
END;
```

### Show triggers

```sql
SHOW TRIGGERS;
```

### Show triggers for a database

```sql
SHOW TRIGGERS FROM cursor_db;
```

### Show trigger definition

```sql
SHOW CREATE TRIGGER trigger_name;
```

### Drop trigger

```sql
DROP TRIGGER IF EXISTS trigger_name;
```

### Important MySQL rules

1. Triggers are associated with tables.
2. MySQL supports BEFORE and AFTER triggers.
3. MySQL triggers are row-level.
4. MySQL does not support statement-level triggers.
5. `OLD` and `NEW` are used to access row values.
6. `OLD` is not available for INSERT.
7. `NEW` is not available for DELETE.
8. `NEW` values can be modified only in BEFORE triggers.
9. A trigger cannot explicitly return a result set to the client.
10. Triggers execute as part of the statement that activates them.

---

## 16. Important Interview Questions and Answers

**Q1. What is a trigger?**

A trigger is a database object that automatically executes when a specified INSERT, UPDATE or DELETE event occurs on a table.

**Q2. Why do we use triggers?**

Triggers are used for data validation, auditing, maintaining history and automating database operations.

**Q3. What are the types of triggers in MySQL?**

MySQL supports BEFORE and AFTER triggers for INSERT, UPDATE and DELETE events.

**Q4. What is a BEFORE trigger?**

A BEFORE trigger executes before the triggering operation takes place.

**Q5. What is an AFTER trigger?**

An AFTER trigger executes after the triggering operation completes successfully.

**Q6. What is a row-level trigger?**

A row-level trigger executes once for every row affected by the triggering statement.

**Q7. Does MySQL support statement-level triggers?**

No. MySQL supports row-level triggers, not statement-level triggers.

**Q8. What is OLD in a trigger?**

OLD refers to the existing row values before an UPDATE or DELETE operation.

**Q9. What is NEW in a trigger?**

NEW refers to the new row values during an INSERT or UPDATE operation.

**Q10. Can we modify NEW values?**

Yes. We can modify NEW column values in BEFORE INSERT and BEFORE UPDATE triggers.

**Q11. Can we modify NEW values in an AFTER trigger?**

No. NEW values are read-only in AFTER triggers.

**Q12. Can we use OLD in an INSERT trigger?**

No. OLD is not available for INSERT triggers.

**Q13. Can we use NEW in a DELETE trigger?**

No. NEW is not available for DELETE triggers.

**Q14. Can we call a trigger manually?**

No. A trigger executes automatically when its associated event occurs.

**Q15. What is the difference between a trigger and a stored procedure?**

A trigger executes automatically on a table event, whereas a stored procedure is executed explicitly using CALL.

**Q16. Can one table have multiple triggers?**

Yes. A table can have multiple triggers for different events and timings. MySQL also permits multiple triggers with the same event and timing, subject to its ordering rules.

**Q17. What is SIGNAL SQLSTATE '45000'?**

It raises a user-defined error, commonly used to reject invalid data in triggers and stored programs.

**Q18. Does TRUNCATE TABLE activate DELETE triggers?**

No. TRUNCATE TABLE does not activate DELETE triggers.

---

## 17. Quick Revision Notes

| Term | Meaning |
|---|---|
| Trigger | Automatically executes on a specified table event |
| BEFORE | Executes before the triggering operation |
| AFTER | Executes after the triggering operation |
| INSERT | New record insertion |
| UPDATE | Existing record modification |
| DELETE | Record deletion |
| FOR EACH ROW | Executes once per affected row |
| OLD | Previous row values |
| NEW | New row values |
| SIGNAL | Raises an error |
| SHOW TRIGGERS | Displays trigger information |
| DROP TRIGGER | Deletes a trigger |

### Remember these points

- A trigger executes automatically.
- MySQL supports BEFORE and AFTER triggers.
- MySQL supports only row-level triggers.
- INSERT uses NEW.
- UPDATE uses OLD and NEW.
- DELETE uses OLD.
- NEW values can be modified in BEFORE triggers.
- AFTER triggers are commonly used for auditing.
- BEFORE triggers are commonly used for validation.
- TRUNCATE does not activate DELETE triggers.

---

## 18. Lab Practice Checklist

- [ ] Create an employees table.
- [ ] Create a BEFORE INSERT trigger.
- [ ] Validate employee salary using a BEFORE trigger.
- [ ] Create a BEFORE UPDATE trigger.
- [ ] Prevent invalid salary updates.
- [ ] Create an AFTER INSERT trigger.
- [ ] Automatically insert records into an audit table.
- [ ] Create an AFTER UPDATE trigger.
- [ ] Maintain old and new salary history.
- [ ] Create an AFTER DELETE trigger.
- [ ] Store deleted employee details.
- [ ] Practise using OLD and NEW.
- [ ] Display triggers using SHOW TRIGGERS.
- [ ] Display trigger definitions using SHOW CREATE TRIGGER.
- [ ] Drop triggers using DROP TRIGGER.

---

## 19. Useful SQL Commands for Revision

```sql
-- Display all triggers
SHOW TRIGGERS;

-- Display triggers from a particular database
SHOW TRIGGERS FROM cursor_db;

-- Display trigger definition
SHOW CREATE TRIGGER after_employee_insert;

-- Drop a trigger
DROP TRIGGER IF EXISTS after_employee_insert;

-- Check employee records
SELECT * FROM employees;

-- Check audit records
SELECT * FROM employee_audit;

-- Check salary history
SELECT * FROM salary_history;

-- Check deleted employee records
SELECT * FROM deleted_employees;
```

---

**End of Session 14 – Triggers**

**Topics covered:** Introduction to Triggers, BEFORE Triggers, AFTER Triggers, Row-Level Triggers, OLD and NEW Variables, INSERT, UPDATE, DELETE Triggers, Audit Logging and Real-World Applications.
