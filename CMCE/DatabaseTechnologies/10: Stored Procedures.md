# Session 10: Stored Procedures

**Course:** CMCE – Database Technologies  
**Batch:** August 2026  
**Theory:** 2 Hours | **Lab:** 2 Hours

---

## 📌 Topics Covered

1. Introduction to MySQL Programming
2. Use of MySQL Programs
3. Introduction to Stored Procedures
4. Benefits of Stored Procedures
5. Stored Procedure Syntax
6. DELIMITER Command
7. Procedure Without Parameters
8. Procedure with Parameters
   - IN Parameter
   - OUT Parameter
   - INOUT Parameter
9. Calling Stored Procedures
10. Practical SQL Programs

---

# 1. Introduction to MySQL Programming

**MySQL Programming** refers to writing SQL statements and database programs to perform database operations and automate tasks.

MySQL provides programming features such as:

- Stored Procedures
- Stored Functions
- Triggers
- Cursors
- Conditional Statements
- Looping Statements
- Variables
- Transactions
- Error Handling

### Why Do We Use MySQL Programming?

1. To automate repetitive database operations.
2. To perform complex database calculations.
3. To implement business logic inside the database.
4. To reduce repeated SQL code.
5. To improve database application management.
6. To perform multiple database operations together.

### Example

Instead of writing the same employee salary update query repeatedly, we can create a stored procedure and call it whenever required.

---

# 2. Introduction to Stored Procedures

A **Stored Procedure** is a collection of SQL statements stored inside the database and executed whenever required.

It is created using the `CREATE PROCEDURE` statement.

### Why Are Stored Procedures Used?

Suppose we frequently need to display all employee records.

Instead of writing:

```sql
SELECT * FROM employees;
```

every time, we can create a stored procedure.

```sql
DELIMITER //

CREATE PROCEDURE getEmployees()
BEGIN
    SELECT * FROM employees;
END //

DELIMITER ;
```

Call the procedure:

```sql
CALL getEmployees();
```

### Explanation

1. `CREATE PROCEDURE` creates a stored procedure.
2. `getEmployees` is the procedure name.
3. `BEGIN` starts the procedure body.
4. `SELECT` retrieves employee records.
5. `END` marks the end of the procedure.
6. `CALL` executes the procedure.

---

# 3. Benefits of Stored Procedures

| Benefit | Description |
|---|---|
| Code Reusability | Write once and execute multiple times |
| Automation | Automates repetitive database operations |
| Maintainability | Business logic can be maintained centrally |
| Reduced Network Traffic | Multiple SQL statements can execute through one procedure call |
| Security | Users can be granted permission to execute procedures without direct access to underlying tables, when configured appropriately |
| Performance | MySQL can reuse stored routine execution structures, although procedures are not automatically faster than equivalent SQL |

### Example

A company may need to calculate employee bonuses every month.

Instead of writing the calculation query repeatedly, a stored procedure can perform the calculation whenever required.

---

# 4. Stored Procedure Syntax

### Basic Syntax

```sql
DELIMITER //

CREATE PROCEDURE procedure_name()
BEGIN

    -- SQL statements

END //

DELIMITER ;
```

### Important Keywords

| Keyword | Description |
|---|---|
| `DELIMITER` | Changes the statement delimiter in the MySQL client |
| `CREATE PROCEDURE` | Creates a stored procedure |
| `BEGIN` | Starts the procedure body |
| `END` | Ends the procedure body |
| `CALL` | Executes a stored procedure |
| `DROP PROCEDURE` | Deletes a stored procedure |

**Important:** `DELIMITER` is a command understood by MySQL command-line clients such as MySQL Monitor. It is not an SQL statement sent to the MySQL server. Some GUI tools and application interfaces handle delimiters differently.

---

# 5. Creating a Procedure Without Parameters

A procedure without parameters does not accept any input values.

It performs a predefined operation whenever called.

### Example 1: Display All Employees

```sql
DELIMITER //

CREATE PROCEDURE getEmployees()
BEGIN
    SELECT * FROM employees;
END //

DELIMITER ;
```

### Calling the Procedure

```sql
CALL getEmployees();
```

### Example 2: Display IT Employees

```sql
DELIMITER //

CREATE PROCEDURE getITEmployees()
BEGIN
    SELECT *
    FROM employees
    WHERE department = 'IT';
END //

DELIMITER ;
```

Execute:

```sql
CALL getITEmployees();
```

### Example 3: Count Total Employees

```sql
DELIMITER //

CREATE PROCEDURE countEmployees()
BEGIN
    SELECT COUNT(*) AS total_employees
    FROM employees;
END //

DELIMITER ;
```

Execute:

```sql
CALL countEmployees();
```

---

# 6. Procedure Parameters

Parameters allow us to pass values to a stored procedure and receive results from it.

MySQL supports three parameter modes:

1. `IN`
2. `OUT`
3. `INOUT`

### Difference Between IN, OUT and INOUT

| Parameter | Purpose | Data Flow |
|---|---|---|
| IN | Accepts input value | Caller → Procedure |
| OUT | Returns output value | Procedure → Caller |
| INOUT | Accepts and returns a value | Caller ↔ Procedure |

---

# 7. IN Parameter

An **IN Parameter** is used to pass a value from the calling program to the stored procedure.

It is the default parameter mode in MySQL.

### Syntax

```sql
CREATE PROCEDURE procedure_name(
    IN parameter_name datatype
)
BEGIN
    -- SQL statements
END;
```

### Example 1: Find Employee by ID

```sql
DELIMITER //

CREATE PROCEDURE getEmployeeById(
    IN empId INT
)
BEGIN
    SELECT *
    FROM employees
    WHERE emp_id = empId;
END //

DELIMITER ;
```

### Calling the Procedure

```sql
CALL getEmployeeById(1);
```

### Explanation

1. `empId` is an IN parameter.
2. The value `1` is passed during the procedure call.
3. The procedure searches for the employee whose ID is 1.
4. Matching employee details are displayed.

### Example 2: Find Employees by Department

```sql
DELIMITER //

CREATE PROCEDURE getEmployeesByDepartment(
    IN deptName VARCHAR(30)
)
BEGIN
    SELECT *
    FROM employees
    WHERE department = deptName;
END //

DELIMITER ;
```

Execute:

```sql
CALL getEmployeesByDepartment('IT');
```

### Example 3: Update Employee Salary

```sql
DELIMITER //

CREATE PROCEDURE updateSalary(
    IN empId INT,
    IN incrementAmount DECIMAL(10,2)
)
BEGIN
    UPDATE employees
    SET salary = salary + incrementAmount
    WHERE emp_id = empId;
END //

DELIMITER ;
```

Execute:

```sql
CALL updateSalary(1, 5000);
```

**Result:** Employee ID 1 receives a salary increment of 5000.

---

# 8. OUT Parameter

An **OUT Parameter** is used to return a value from the stored procedure to the calling program.

The procedure assigns a value to the OUT parameter.

### Syntax

```sql
CREATE PROCEDURE procedure_name(
    OUT parameter_name datatype
)
BEGIN
    -- Assign value to OUT parameter
END;
```

### Example 1: Get Total Employee Count

```sql
DELIMITER //

CREATE PROCEDURE getEmployeeCount(
    OUT total INT
)
BEGIN
    SELECT COUNT(*)
    INTO total
    FROM employees;
END //

DELIMITER ;
```

### Calling the Procedure

```sql
CALL getEmployeeCount(@total);
```

Display the result:

```sql
SELECT @total AS total_employees;
```

### Explanation

1. `total` is an OUT parameter.
2. `COUNT(*)` calculates the number of employees.
3. `INTO total` stores the result in the OUT parameter.
4. `@total` is a MySQL user-defined session variable.
5. The result is displayed using `SELECT`.

### Example 2: Get Maximum Salary

```sql
DELIMITER //

CREATE PROCEDURE getMaxSalary(
    OUT maxSal DECIMAL(10,2)
)
BEGIN
    SELECT MAX(salary)
    INTO maxSal
    FROM employees;
END //

DELIMITER ;
```

Execute:

```sql
CALL getMaxSalary(@result);

SELECT @result AS maximum_salary;
```

### Example 3: Get Employee Name by ID

```sql
DELIMITER //

CREATE PROCEDURE getEmployeeName(
    IN empId INT,
    OUT empName VARCHAR(50)
)
BEGIN
    SELECT employee_name
    INTO empName
    FROM employees
    WHERE emp_id = empId;
END //

DELIMITER ;
```

Execute:

```sql
CALL getEmployeeName(1, @name);

SELECT @name AS employee_name;
```

**Note:** If the SELECT statement returns no rows, the OUT variable may remain unchanged. In production procedures, initialize output variables and handle missing records explicitly.

---

# 9. INOUT Parameter

An **INOUT Parameter** is used to accept an input value, modify it inside the procedure, and return the modified value.

It supports both input and output operations.

### Syntax

```sql
CREATE PROCEDURE procedure_name(
    INOUT parameter_name datatype
)
BEGIN
    -- Modify parameter value
END;
```

### Example 1: Increase a Number by 10

```sql
DELIMITER //

CREATE PROCEDURE increaseNumber(
    INOUT num INT
)
BEGIN
    SET num = num + 10;
END //

DELIMITER ;
```

### Calling the Procedure

```sql
SET @value = 20;

CALL increaseNumber(@value);

SELECT @value AS updated_value;
```

**Output:**

```text
updated_value
30
```

### Explanation

1. `@value` contains 20.
2. The value is passed to the INOUT parameter.
3. The procedure adds 10.
4. The modified value is returned.
5. `@value` now contains 30.

### Example 2: Double a Number

```sql
DELIMITER //

CREATE PROCEDURE doubleNumber(
    INOUT num INT
)
BEGIN
    SET num = num * 2;
END //

DELIMITER ;
```

Execute:

```sql
SET @n = 15;

CALL doubleNumber(@n);

SELECT @n AS result;
```

Output:

```text
result
30
```

### Example 3: Apply Bonus to Salary

```sql
DELIMITER //

CREATE PROCEDURE addBonus(
    INOUT salary DECIMAL(10,2)
)
BEGIN
    SET salary = salary + 5000;
END //

DELIMITER ;
```

Execute:

```sql
SET @salary = 60000;

CALL addBonus(@salary);

SELECT @salary AS updated_salary;
```

Output:

```text
updated_salary
65000
```

---

# 10. Using Multiple Parameters

A stored procedure can contain multiple parameters with different modes.

### Example: Employee Salary Calculation

```sql
DELIMITER //

CREATE PROCEDURE calculateSalary(
    IN empId INT,
    IN bonus DECIMAL(10,2),
    OUT finalSalary DECIMAL(10,2)
)
BEGIN
    SELECT salary + bonus
    INTO finalSalary
    FROM employees
    WHERE emp_id = empId;
END //

DELIMITER ;
```

### Execute

```sql
CALL calculateSalary(1, 5000, @result);

SELECT @result AS final_salary;
```

### Explanation

- `empId` accepts the employee ID.
- `bonus` accepts the bonus amount.
- `finalSalary` returns the calculated salary.

---

# 11. User-Defined Variables in MySQL

MySQL user-defined variables are used to store values during a session.

They are frequently used when calling procedures with OUT and INOUT parameters.

### Syntax

```sql
SET @variable_name = value;
```

### Examples

```sql
SET @num = 100;

SELECT @num;
```

Using an OUT parameter:

```sql
CALL getEmployeeCount(@total);

SELECT @total;
```

Using an INOUT parameter:

```sql
SET @value = 50;

CALL increaseNumber(@value);

SELECT @value;
```

### Local Variables vs User-Defined Variables

| Local Variable | User-Defined Variable |
|---|---|
| Declared inside a stored program | Created using `SET @variable` |
| Declared using `DECLARE` | Uses `@` prefix |
| Scope is the stored program block | Scope is the current session |
| Used for internal calculations | Used to pass and store values across SQL statements |

**Example of a Local Variable:**

```sql
DELIMITER //

CREATE PROCEDURE localVariableDemo()
BEGIN
    DECLARE total INT DEFAULT 0;

    SELECT COUNT(*)
    INTO total
    FROM employees;

    SELECT total AS employee_count;
END //

DELIMITER ;
```

Execute:

```sql
CALL localVariableDemo();
```

**Important:** Local variables must be declared at the beginning of their `BEGIN ... END` block, before other executable statements.

---

# 12. Managing Stored Procedures

## 12.1 Display Stored Procedures

```sql
SHOW PROCEDURE STATUS;
```

For the current database:

```sql
SHOW PROCEDURE STATUS
WHERE Db = 'company';
```

## 12.2 Display Procedure Definition

```sql
SHOW CREATE PROCEDURE getEmployees;
```

## 12.3 Drop a Stored Procedure

```sql
DROP PROCEDURE getEmployees;
```

## 12.4 Drop If Exists

```sql
DROP PROCEDURE IF EXISTS getEmployees;
```

## 12.5 Modify a Stored Procedure

MySQL does not provide `CREATE OR REPLACE PROCEDURE` in the same way some other database systems do.

To change a procedure, use:

```sql
DROP PROCEDURE IF EXISTS getEmployees;
```

Then create it again with the updated definition.

---

# 13. Complete Lab Practicals

Use the following sample table:

```sql
CREATE TABLE employees (
    emp_id INT PRIMARY KEY,
    employee_name VARCHAR(50),
    department VARCHAR(30),
    salary DECIMAL(10,2)
);
```

Insert sample records:

```sql
INSERT INTO employees VALUES
(1, 'Anurag', 'IT', 60000),
(2, 'Rahul', 'IT', 50000),
(3, 'Amit', 'HR', 45000),
(4, 'Sneha', 'HR', 55000),
(5, 'Karan', 'Finance', 70000);
```

### Practical 1: Procedure Without Parameters

```sql
DELIMITER //

CREATE PROCEDURE displayEmployees()
BEGIN
    SELECT * FROM employees;
END //

DELIMITER ;

CALL displayEmployees();
```

### Practical 2: Procedure with IN Parameter

```sql
DELIMITER //

CREATE PROCEDURE displayEmployee(
    IN id INT
)
BEGIN
    SELECT *
    FROM employees
    WHERE emp_id = id;
END //

DELIMITER ;

CALL displayEmployee(1);
```

### Practical 3: Procedure with OUT Parameter

```sql
DELIMITER //

CREATE PROCEDURE totalEmployees(
    OUT total INT
)
BEGIN
    SELECT COUNT(*)
    INTO total
    FROM employees;
END //

DELIMITER ;

CALL totalEmployees(@total);

SELECT @total;
```

### Practical 4: Procedure with INOUT Parameter

```sql
DELIMITER //

CREATE PROCEDURE addTen(
    INOUT num INT
)
BEGIN
    SET num = num + 10;
END //

DELIMITER ;

SET @n = 100;

CALL addTen(@n);

SELECT @n;
```

### Practical 5: Procedure with Multiple IN Parameters

```sql
DELIMITER //

CREATE PROCEDURE addNumbers(
    IN a INT,
    IN b INT
)
BEGIN
    SELECT a + b AS result;
END //

DELIMITER ;

CALL addNumbers(10, 20);
```

### Practical 6: Procedure to Find Square Using OUT

```sql
DELIMITER //

CREATE PROCEDURE findSquare(
    IN num INT,
    OUT result INT
)
BEGIN
    SET result = num * num;
END //

DELIMITER ;

CALL findSquare(5, @ans);

SELECT @ans AS square;
```

### Practical 7: Procedure to Find Factorial Using IN and OUT

```sql
DELIMITER //

CREATE PROCEDURE factorial(
    IN num INT,
    OUT result BIGINT
)
BEGIN
    DECLARE i INT DEFAULT 1;

    SET result = 1;

    WHILE i <= num DO
        SET result = result * i;
        SET i = i + 1;
    END WHILE;
END //

DELIMITER ;

CALL factorial(5, @fact);

SELECT @fact AS factorial_result;
```

Expected output:

```text
factorial_result
120
```

**Note:** This example is for non-negative integers and small enough values to fit in BIGINT. It does not include overflow or invalid-input handling.

---

# 14. Important Interview Questions

**Q1. What is MySQL Programming?**

Writing SQL statements and database programs to automate and manage database operations.

**Q2. What is a Stored Procedure?**

A collection of SQL statements stored in the database and executed whenever required.

**Q3. Which command is used to create a stored procedure?**

`CREATE PROCEDURE`.

**Q4. Which command is used to execute a stored procedure?**

`CALL`.

**Q5. What are the benefits of Stored Procedures?**

Code reusability, automation, maintainability, reduced network traffic, and controlled database access.

**Q6. What is DELIMITER?**

A MySQL client command used to change the statement delimiter temporarily while defining routines containing multiple SQL statements.

**Q7. What are the three parameter modes in MySQL?**

IN, OUT, and INOUT.

**Q8. What is an IN parameter?**

It passes an input value from the caller to the procedure.

**Q9. What is an OUT parameter?**

It returns a value from the procedure to the caller.

**Q10. What is an INOUT parameter?**

It accepts an input value, modifies it, and returns the updated value.

**Q11. What is the default parameter mode in MySQL?**

IN.

**Q12. How do we call a procedure with an OUT parameter?**

```sql
CALL procedure_name(@result);

SELECT @result;
```

**Q13. What is the difference between a Stored Procedure and a SQL query?**

A SQL query is an individual statement, whereas a stored procedure is a named database routine that can contain multiple SQL statements and programming logic.

**Q14. Can a stored procedure contain multiple SQL statements?**

Yes. Multiple statements can be written between `BEGIN` and `END`.

**Q15. How do we delete a stored procedure?**

```sql
DROP PROCEDURE procedure_name;
```

**Q16. What is the difference between a local variable and a user-defined variable?**

A local variable is declared inside a stored program using `DECLARE`, whereas a user-defined variable uses the `@` prefix and belongs to the current session.

**Q17. Can a stored procedure return multiple values?**

Yes. It can use multiple OUT or INOUT parameters.

**Q18. Can we use SELECT inside a stored procedure?**

Yes. A procedure can execute SELECT statements and return result sets or assign query results to variables using `SELECT ... INTO`.

---

# 15. Self-Learning Practice Checklist

Try solving these questions independently.

### Procedures Without Parameters

- [ ] Create a procedure to display all employees.
- [ ] Create a procedure to display IT employees.
- [ ] Create a procedure to count total employees.
- [ ] Create a procedure to display employees earning more than 50000.

### Procedures with IN Parameters

- [ ] Create a procedure to find an employee using employee ID.
- [ ] Create a procedure to display employees by department.
- [ ] Create a procedure to update employee salary.
- [ ] Create a procedure to calculate the square of a number.
- [ ] Create a procedure to add two numbers.

### Procedures with OUT Parameters

- [ ] Create a procedure to return total employee count.
- [ ] Create a procedure to return maximum salary.
- [ ] Create a procedure to return minimum salary.
- [ ] Create a procedure to return employee name using employee ID.
- [ ] Create a procedure to calculate the square of a number using OUT.

### Procedures with INOUT Parameters

- [ ] Create a procedure to increase a number by 10.
- [ ] Create a procedure to double a number.
- [ ] Create a procedure to calculate the square of a number.
- [ ] Create a procedure to add a bonus to a salary variable.

### Procedure Management

- [ ] Display all stored procedures.
- [ ] Display the definition of a stored procedure.
- [ ] Drop an existing procedure.
- [ ] Recreate a procedure with updated logic.

---

# 16. Quick Revision – Important Points

1. MySQL Programming allows us to automate database operations.
2. A Stored Procedure is a collection of SQL statements stored in the database.
3. `CREATE PROCEDURE` creates a procedure.
4. `CALL` executes a procedure.
5. `DROP PROCEDURE` deletes a procedure.
6. `BEGIN` starts the procedure body.
7. `END` ends the procedure body.
8. `DELIMITER` changes the delimiter in the MySQL client.
9. IN passes values into a procedure.
10. OUT returns values from a procedure.
11. INOUT accepts and returns values.
12. IN is the default parameter mode.
13. `@variable` represents a user-defined session variable.
14. `DECLARE` creates a local variable.
15. A procedure can contain multiple SQL statements.
16. Procedures can contain conditional and looping statements.
17. Multiple OUT parameters can return multiple values.
18. MySQL procedures can be used to implement reusable database logic.

---

# 17. Learning Resources

- [MySQL Stored Procedures Documentation](https://dev.mysql.com/doc/refman/8.0/en/create-procedure.html)
- [MySQL CREATE PROCEDURE and CREATE FUNCTION](https://dev.mysql.com/doc/refman/8.0/en/create-procedure.html)
- [MySQL Stored Routine Parameters](https://dev.mysql.com/doc/refman/8.0/en/create-procedure.html)
- [MySQL Stored Programs](https://dev.mysql.com/doc/refman/8.0/en/stored-programs.html)
- [MySQL User-Defined Variables](https://dev.mysql.com/doc/refman/8.0/en/user-variables.html)

---

**Happy Learning! 🚀**

*Prepared for CMCE – August 2026 Batch | Database Technologies*
