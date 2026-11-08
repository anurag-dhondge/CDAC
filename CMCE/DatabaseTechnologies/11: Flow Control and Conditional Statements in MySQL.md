# Session 11: Flow Control and Conditional Statements in MySQL

**Course:** CMCE – Database Technologies  
**Batch:** August 2026  
**Theory:** 2 Hours | **Lab:** 2 Hours | **Self-Learning:** 2 Hours

---

## 📌 Topics Covered

1. Flow Control Statements in MySQL
2. LOOP Statement
3. WHILE Loop
4. REPEAT Loop
5. Conditional Statements
   - IF
   - IF-ELSE
   - ELSEIF
   - CASE
6. Using Flow Control in Stored Procedures
7. Using Flow Control in Stored Functions
8. Loop Control Statements
   - ITERATE
   - LEAVE
9. Practical SQL Programs

---

# 1. Introduction to Flow Control Statements

**Flow Control Statements** are used to control the execution order of statements in a MySQL stored program.

They allow us to execute statements repeatedly, make decisions, and control program execution based on conditions.

### Why Do We Use Flow Control Statements?

- To execute statements repeatedly.
- To perform calculations.
- To check conditions.
- To automate database operations.
- To implement business logic.
- To stop or skip loop iterations.

### Types of Flow Control Statements

| Category | Statements |
|---|---|
| Loop Statements | LOOP, WHILE, REPEAT |
| Conditional Statements | IF, ELSEIF, ELSE, CASE |
| Loop Control Statements | ITERATE, LEAVE |

**Note:** These statements are primarily used inside stored procedures, functions, triggers, and other MySQL stored programs.

---

# 2. LOOP Statement

The `LOOP` statement executes a block of SQL statements repeatedly until an explicit exit condition is encountered.

It does not have a built-in condition in its syntax.

We generally use `LEAVE` to terminate a LOOP.

### Syntax

```sql
[label:] LOOP

    -- SQL statements

    IF condition THEN
        LEAVE label;
    END IF;

END LOOP [label];
```

### Example 1: Print Numbers from 1 to 5

```sql
DELIMITER //

CREATE PROCEDURE printNumbers()
BEGIN
    DECLARE i INT DEFAULT 1;

    my_loop: LOOP

        SELECT i AS number;

        SET i = i + 1;

        IF i > 5 THEN
            LEAVE my_loop;
        END IF;

    END LOOP my_loop;

END //

DELIMITER ;
```

Execute:

```sql
CALL printNumbers();
```

**Output:**

```text
1
2
3
4
5
```

### Explanation

1. Declare a variable `i` and initialize it to 1.
2. Start the LOOP.
3. Display the current value.
4. Increment `i` by 1.
5. Check whether `i` is greater than 5.
6. If the condition is true, exit the loop using `LEAVE`.

### Important Points

- LOOP does not check a condition automatically.
- It continues until explicitly terminated.
- `LEAVE` is commonly used to exit a LOOP.
- A label identifies the loop that should be exited.

---

# 3. WHILE Loop

The `WHILE` loop executes statements as long as the specified condition is TRUE.

It checks the condition before executing the loop body.

### Syntax

```sql
[label:] WHILE condition DO

    -- SQL statements

END WHILE [label];
```

### Example 1: Print Numbers from 1 to 5

```sql
DELIMITER //

CREATE PROCEDURE printWhile()
BEGIN
    DECLARE i INT DEFAULT 1;

    WHILE i <= 5 DO

        SELECT i AS number;

        SET i = i + 1;

    END WHILE;

END //

DELIMITER ;
```

Execute:

```sql
CALL printWhile();
```

**Output:**

```text
1
2
3
4
5
```

### Explanation

1. Initialize `i = 1`.
2. Check whether `i <= 5`.
3. If TRUE, execute the loop body.
4. Display the value of `i`.
5. Increment `i`.
6. Repeat until the condition becomes FALSE.

### Example 2: Calculate Sum of Numbers from 1 to 10

```sql
DELIMITER //

CREATE PROCEDURE sumNumbers()
BEGIN
    DECLARE i INT DEFAULT 1;
    DECLARE total INT DEFAULT 0;

    WHILE i <= 10 DO

        SET total = total + i;

        SET i = i + 1;

    END WHILE;

    SELECT total AS sum_result;

END //

DELIMITER ;
```

Execute:

```sql
CALL sumNumbers();
```

**Output:**

```text
sum_result
55
```

### Important Points

- Condition is checked before execution.
- If the condition is initially FALSE, the loop body does not execute.
- Used when the number of iterations depends on a condition.

---

# 4. REPEAT Loop

The `REPEAT` loop executes a block of statements repeatedly until the specified condition becomes TRUE.

It checks the condition after executing the loop body.

Therefore, it executes at least once.

### Syntax

```sql
[label:] REPEAT

    -- SQL statements

UNTIL condition

END REPEAT [label];
```

### Example 1: Print Numbers from 1 to 5

```sql
DELIMITER //

CREATE PROCEDURE printRepeat()
BEGIN
    DECLARE i INT DEFAULT 1;

    REPEAT

        SELECT i AS number;

        SET i = i + 1;

    UNTIL i > 5

    END REPEAT;

END //

DELIMITER ;
```

Execute:

```sql
CALL printRepeat();
```

**Output:**

```text
1
2
3
4
5
```

### Example 2: Calculate Sum of Numbers from 1 to 10

```sql
DELIMITER //

CREATE PROCEDURE sumRepeat()
BEGIN
    DECLARE i INT DEFAULT 1;
    DECLARE total INT DEFAULT 0;

    REPEAT

        SET total = total + i;

        SET i = i + 1;

    UNTIL i > 10

    END REPEAT;

    SELECT total AS sum_result;

END //

DELIMITER ;
```

Execute:

```sql
CALL sumRepeat();
```

**Output:**

```text
sum_result
55
```

### Important Points

- Executes the loop body first.
- Checks the condition after execution.
- Executes at least once.
- Stops when the UNTIL condition becomes TRUE.

---

# 5. Difference Between LOOP, WHILE and REPEAT

| Feature | LOOP | WHILE | REPEAT |
|---|---|---|---|
| Condition | No built-in condition | Checks before execution | Checks after execution |
| Minimum Execution | Depends on explicit exit | Zero times | At least once |
| Termination | LEAVE | Condition becomes FALSE | UNTIL condition becomes TRUE |
| Syntax | LOOP ... END LOOP | WHILE ... DO | REPEAT ... UNTIL |
| Common Use | Manual loop control | Condition-based repetition | Execute at least once |

### Easy Way to Remember

- **LOOP:** Repeats until explicitly stopped.
- **WHILE:** Checks first, then executes.
- **REPEAT:** Executes first, then checks.

---

# 6. Conditional Statements

Conditional statements allow a stored program to make decisions based on conditions.

MySQL provides:

1. IF
2. IF-ELSE
3. IF-ELSEIF-ELSE
4. CASE

---

# 7. IF Statement

The `IF` statement executes a block of SQL statements only when a condition is TRUE.

### Syntax

```sql
IF condition THEN

    -- SQL statements

END IF;
```

### Example: Check Whether a Number Is Positive

```sql
DELIMITER //

CREATE PROCEDURE checkPositive(
    IN num INT
)
BEGIN

    IF num > 0 THEN
        SELECT 'Positive Number' AS result;
    END IF;

END //

DELIMITER ;
```

Execute:

```sql
CALL checkPositive(10);
```

**Output:**

```text
Positive Number
```

### Explanation

If the number is greater than zero, the message is displayed.

Otherwise, nothing is displayed by the IF block.

---

# 8. IF-ELSE Statement

The `IF-ELSE` statement executes one block when the condition is TRUE and another block when the condition is FALSE.

### Syntax

```sql
IF condition THEN

    -- Statements if TRUE

ELSE

    -- Statements if FALSE

END IF;
```

### Example: Check Even or Odd Number

```sql
DELIMITER //

CREATE PROCEDURE checkEvenOdd(
    IN num INT
)
BEGIN

    IF num % 2 = 0 THEN

        SELECT 'Even Number' AS result;

    ELSE

        SELECT 'Odd Number' AS result;

    END IF;

END //

DELIMITER ;
```

Execute:

```sql
CALL checkEvenOdd(10);
```

**Output:**

```text
Even Number
```

Execute:

```sql
CALL checkEvenOdd(7);
```

**Output:**

```text
Odd Number
```

---

# 9. IF-ELSEIF-ELSE Statement

The `IF-ELSEIF-ELSE` statement is used when multiple conditions need to be checked.

MySQL uses `ELSEIF` as one word.

### Syntax

```sql
IF condition1 THEN

    -- Statements

ELSEIF condition2 THEN

    -- Statements

ELSEIF condition3 THEN

    -- Statements

ELSE

    -- Default statements

END IF;
```

### Example: Student Grade Calculation

```sql
DELIMITER //

CREATE PROCEDURE calculateGrade(
    IN marks INT
)
BEGIN

    IF marks >= 90 THEN

        SELECT 'Grade A' AS grade;

    ELSEIF marks >= 75 THEN

        SELECT 'Grade B' AS grade;

    ELSEIF marks >= 60 THEN

        SELECT 'Grade C' AS grade;

    ELSEIF marks >= 40 THEN

        SELECT 'Grade D' AS grade;

    ELSE

        SELECT 'Fail' AS grade;

    END IF;

END //

DELIMITER ;
```

Execute:

```sql
CALL calculateGrade(95);
```

**Output:**

```text
Grade A
```

Execute:

```sql
CALL calculateGrade(80);
```

**Output:**

```text
Grade B
```

### Explanation

- Marks 90 or above → Grade A.
- Marks 75 or above → Grade B.
- Marks 60 or above → Grade C.
- Marks 40 or above → Grade D.
- Below 40 → Fail.

**Note:** This example assumes marks are between 0 and 100. A production procedure should also validate the input range.

---

# 10. CASE Statement

The `CASE` statement is used to select one result from multiple conditions.

It is similar to the SWITCH statement available in programming languages such as C, C++, and Java.

MySQL supports two forms of CASE:

1. Simple CASE
2. Searched CASE

## 10.1 Simple CASE

Simple CASE compares one expression against multiple values.

### Syntax

```sql
CASE expression

    WHEN value1 THEN
        statements

    WHEN value2 THEN
        statements

    ELSE
        statements

END CASE;
```

### Example: Display Day Name

```sql
DELIMITER //

CREATE PROCEDURE getDayName(
    IN dayNo INT
)
BEGIN

    CASE dayNo

        WHEN 1 THEN
            SELECT 'Monday' AS day_name;

        WHEN 2 THEN
            SELECT 'Tuesday' AS day_name;

        WHEN 3 THEN
            SELECT 'Wednesday' AS day_name;

        WHEN 4 THEN
            SELECT 'Thursday' AS day_name;

        WHEN 5 THEN
            SELECT 'Friday' AS day_name;

        WHEN 6 THEN
            SELECT 'Saturday' AS day_name;

        WHEN 7 THEN
            SELECT 'Sunday' AS day_name;

        ELSE
            SELECT 'Invalid Day Number' AS day_name;

    END CASE;

END //

DELIMITER ;
```

Execute:

```sql
CALL getDayName(1);
```

**Output:**

```text
Monday
```

## 10.2 Searched CASE

Searched CASE checks multiple Boolean conditions.

### Syntax

```sql
CASE

    WHEN condition1 THEN
        statements

    WHEN condition2 THEN
        statements

    ELSE
        statements

END CASE;
```

### Example: Check Salary Category

```sql
DELIMITER //

CREATE PROCEDURE salaryCategory(
    IN sal DECIMAL(10,2)
)
BEGIN

    CASE

        WHEN sal >= 70000 THEN
            SELECT 'High Salary' AS category;

        WHEN sal >= 40000 THEN
            SELECT 'Medium Salary' AS category;

        ELSE
            SELECT 'Low Salary' AS category;

    END CASE;

END //

DELIMITER ;
```

Execute:

```sql
CALL salaryCategory(75000);
```

**Output:**

```text
High Salary
```

### Important Note: CASE Statement vs CASE Expression

MySQL supports both:

- **CASE statement:** Used in stored programs with `END CASE`.
- **CASE expression:** Returns a value and is commonly used inside SELECT statements.

Example of CASE expression:

```sql
SELECT
    employee_name,
    salary,
    CASE
        WHEN salary >= 70000 THEN 'High'
        WHEN salary >= 40000 THEN 'Medium'
        ELSE 'Low'
    END AS salary_category
FROM employees;
```

The CASE expression does not use `END CASE`; it ends with `END`.

---

# 11. ITERATE Statement

The `ITERATE` statement is used to skip the remaining statements in the current loop iteration and start the next iteration.

It works similarly to the `continue` statement in C, C++, and Java.

### Syntax

```sql
ITERATE label_name;
```

### Example: Print Odd Numbers from 1 to 10

```sql
DELIMITER //

CREATE PROCEDURE printOddNumbers()
BEGIN

    DECLARE i INT DEFAULT 0;

    my_loop: LOOP

        SET i = i + 1;

        IF i > 10 THEN
            LEAVE my_loop;
        END IF;

        IF i % 2 = 0 THEN
            ITERATE my_loop;
        END IF;

        SELECT i AS odd_number;

    END LOOP my_loop;

END //

DELIMITER ;
```

Execute:

```sql
CALL printOddNumbers();
```

**Output:**

```text
1
3
5
7
9
```

### Explanation

1. Increment `i`.
2. If `i` is greater than 10, exit the loop.
3. If `i` is even, skip the current iteration using `ITERATE`.
4. Otherwise, display the number.
5. Continue until the loop ends.

---

# 12. LEAVE Statement

The `LEAVE` statement is used to exit a labelled block or loop.

It works similarly to the `break` statement in C, C++, and Java when used to exit a loop.

### Syntax

```sql
LEAVE label_name;
```

### Example: Stop Loop at 5

```sql
DELIMITER //

CREATE PROCEDURE stopAtFive()
BEGIN

    DECLARE i INT DEFAULT 1;

    my_loop: LOOP

        IF i > 5 THEN
            LEAVE my_loop;
        END IF;

        SELECT i AS number;

        SET i = i + 1;

    END LOOP my_loop;

END //

DELIMITER ;
```

Execute:

```sql
CALL stopAtFive();
```

**Output:**

```text
1
2
3
4
5
```

### ITERATE vs LEAVE

| ITERATE | LEAVE |
|---|---|
| Skips current iteration | Exits the labelled loop or block |
| Starts the next iteration | Terminates the loop or block |
| Similar to continue | Similar to break |

**Important:** Both ITERATE and LEAVE require a label.

---

# 13. Using Flow Control in Stored Functions

A **Stored Function** is a database routine that returns a single value using the `RETURN` statement.

Unlike a procedure, a function can be used inside SQL expressions.

### Basic Syntax

```sql
CREATE FUNCTION function_name(
    parameter_name datatype
)
RETURNS return_datatype
DETERMINISTIC
BEGIN

    -- SQL statements

    RETURN value;

END;
```

### Example 1: Function to Calculate Square

```sql
DELIMITER //

CREATE FUNCTION calculateSquare(
    num INT
)
RETURNS INT
DETERMINISTIC
BEGIN

    RETURN num * num;

END //

DELIMITER ;
```

Execute:

```sql
SELECT calculateSquare(5) AS square;
```

**Output:**

```text
25
```

## Example 2: Function Using IF-ELSE

```sql
DELIMITER //

CREATE FUNCTION checkNumber(
    num INT
)
RETURNS VARCHAR(20)
DETERMINISTIC
BEGIN

    IF num > 0 THEN
        RETURN 'Positive';

    ELSEIF num < 0 THEN
        RETURN 'Negative';

    ELSE
        RETURN 'Zero';

    END IF;

END //

DELIMITER ;
```

Execute:

```sql
SELECT checkNumber(-10);
```

**Output:**

```text
Negative
```

## Example 3: Function Using WHILE Loop

Calculate the sum of numbers from 1 to 10.

```sql
DELIMITER //

CREATE FUNCTION calculateSum()
RETURNS INT
DETERMINISTIC
BEGIN

    DECLARE i INT DEFAULT 1;
    DECLARE total INT DEFAULT 0;

    WHILE i <= 10 DO

        SET total = total + i;

        SET i = i + 1;

    END WHILE;

    RETURN total;

END //

DELIMITER ;
```

Execute:

```sql
SELECT calculateSum();
```

**Output:**

```text
55
```

**Note:** Functions have restrictions that differ from procedures. For example, stored functions cannot return result sets using a normal SELECT statement, and they cannot execute transaction-control statements such as COMMIT or ROLLBACK.

---

# 14. Stored Procedure vs Stored Function

| Stored Procedure | Stored Function |
|---|---|
| Created using CREATE PROCEDURE | Created using CREATE FUNCTION |
| Executed using CALL | Used inside SQL expressions or SELECT |
| Does not require a RETURN value | Must return a value |
| Supports IN, OUT, INOUT parameters | Parameters are input parameters |
| Can return result sets | Returns a single value |
| Used for performing database operations | Used for calculations and returning values |

---

# 15. Complete Lab Practicals

Use the following sample table for employee-related examples.

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

## Practical 1: WHILE Loop

Print numbers from 1 to 10.

```sql
DELIMITER //

CREATE PROCEDURE printTenNumbers()
BEGIN

    DECLARE i INT DEFAULT 1;

    WHILE i <= 10 DO

        SELECT i AS number;

        SET i = i + 1;

    END WHILE;

END //

DELIMITER ;

CALL printTenNumbers();
```

## Practical 2: LOOP Statement

Print numbers from 1 to 10 using LOOP.

```sql
DELIMITER //

CREATE PROCEDURE loopTenNumbers()
BEGIN

    DECLARE i INT DEFAULT 1;

    my_loop: LOOP

        IF i > 10 THEN
            LEAVE my_loop;
        END IF;

        SELECT i AS number;

        SET i = i + 1;

    END LOOP my_loop;

END //

DELIMITER ;

CALL loopTenNumbers();
```

## Practical 3: REPEAT Loop

Print numbers from 1 to 10.

```sql
DELIMITER //

CREATE PROCEDURE repeatTenNumbers()
BEGIN

    DECLARE i INT DEFAULT 1;

    REPEAT

        SELECT i AS number;

        SET i = i + 1;

    UNTIL i > 10

    END REPEAT;

END //

DELIMITER ;

CALL repeatTenNumbers();
```

## Practical 4: Calculate Factorial Using WHILE

```sql
DELIMITER //

CREATE PROCEDURE calculateFactorial(
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

CALL calculateFactorial(5, @fact);

SELECT @fact AS factorial;
```

Expected output:

```text
120
```

## Practical 5: Check Even or Odd

```sql
DELIMITER //

CREATE PROCEDURE evenOdd(
    IN num INT
)
BEGIN

    IF num % 2 = 0 THEN

        SELECT 'Even' AS result;

    ELSE

        SELECT 'Odd' AS result;

    END IF;

END //

DELIMITER ;

CALL evenOdd(15);
```

## Practical 6: Find Largest of Two Numbers

```sql
DELIMITER //

CREATE PROCEDURE largestNumber(
    IN a INT,
    IN b INT
)
BEGIN

    IF a > b THEN

        SELECT a AS largest;

    ELSEIF b > a THEN

        SELECT b AS largest;

    ELSE

        SELECT 'Both are Equal' AS result;

    END IF;

END //

DELIMITER ;

CALL largestNumber(20, 30);
```

## Practical 7: Calculate Student Grade

```sql
DELIMITER //

CREATE PROCEDURE studentGrade(
    IN marks INT
)
BEGIN

    IF marks >= 90 THEN
        SELECT 'A Grade' AS grade;

    ELSEIF marks >= 75 THEN
        SELECT 'B Grade' AS grade;

    ELSEIF marks >= 60 THEN
        SELECT 'C Grade' AS grade;

    ELSEIF marks >= 40 THEN
        SELECT 'D Grade' AS grade;

    ELSE
        SELECT 'Fail' AS grade;

    END IF;

END //

DELIMITER ;

CALL studentGrade(85);
```

## Practical 8: CASE Statement

Display a month name using a month number.

```sql
DELIMITER //

CREATE PROCEDURE monthName(
    IN monthNo INT
)
BEGIN

    CASE monthNo

        WHEN 1 THEN SELECT 'January' AS month_name;
        WHEN 2 THEN SELECT 'February' AS month_name;
        WHEN 3 THEN SELECT 'March' AS month_name;
        WHEN 4 THEN SELECT 'April' AS month_name;
        WHEN 5 THEN SELECT 'May' AS month_name;
        WHEN 6 THEN SELECT 'June' AS month_name;
        WHEN 7 THEN SELECT 'July' AS month_name;
        WHEN 8 THEN SELECT 'August' AS month_name;
        WHEN 9 THEN SELECT 'September' AS month_name;
        WHEN 10 THEN SELECT 'October' AS month_name;
        WHEN 11 THEN SELECT 'November' AS month_name;
        WHEN 12 THEN SELECT 'December' AS month_name;

        ELSE SELECT 'Invalid Month' AS month_name;

    END CASE;

END //

DELIMITER ;

CALL monthName(11);
```

## Practical 9: ITERATE Statement

Print numbers from 1 to 10 but skip multiples of 3.

```sql
DELIMITER //

CREATE PROCEDURE skipMultiples()
BEGIN

    DECLARE i INT DEFAULT 0;

    my_loop: LOOP

        SET i = i + 1;

        IF i > 10 THEN
            LEAVE my_loop;
        END IF;

        IF i % 3 = 0 THEN
            ITERATE my_loop;
        END IF;

        SELECT i AS number;

    END LOOP my_loop;

END //

DELIMITER ;

CALL skipMultiples();
```

Expected output:

```text
1
2
4
5
7
8
10
```

## Practical 10: Function Using Conditional Statement

```sql
DELIMITER //

CREATE FUNCTION salaryStatus(
    sal DECIMAL(10,2)
)
RETURNS VARCHAR(20)
DETERMINISTIC
BEGIN

    IF sal >= 70000 THEN
        RETURN 'High';

    ELSEIF sal >= 40000 THEN
        RETURN 'Medium';

    ELSE
        RETURN 'Low';

    END IF;

END //

DELIMITER ;

SELECT salaryStatus(60000);
```

---

# 16. Important Interview Questions

**Q1. What are Flow Control Statements?**

Statements used to control the execution order of a stored program.

**Q2. What are the loop statements available in MySQL?**

LOOP, WHILE, and REPEAT.

**Q3. What is a LOOP statement?**

A loop that repeats statements until it is explicitly terminated.

**Q4. What is a WHILE loop?**

A loop that executes statements while its condition is TRUE.

**Q5. What is a REPEAT loop?**

A loop that executes statements at least once and continues until its UNTIL condition becomes TRUE.

**Q6. Difference between WHILE and REPEAT?**

WHILE checks the condition before executing the loop body, whereas REPEAT checks it after execution.

**Q7. What is the IF statement?**

It executes statements when a specified condition is TRUE.

**Q8. What is IF-ELSE?**

It executes one block when a condition is TRUE and another block when it is FALSE.

**Q9. What is ELSEIF?**

It checks additional conditions when previous IF or ELSEIF conditions are FALSE.

**Q10. What is a CASE statement?**

A conditional statement used to select one block from multiple alternatives.

**Q11. What is ITERATE?**

It skips the remaining statements of the current loop iteration and starts the next iteration.

**Q12. What is LEAVE?**

It exits a labelled loop or block.

**Q13. Difference between ITERATE and LEAVE?**

ITERATE skips the current iteration, whereas LEAVE exits the loop or labelled block.

**Q14. What is the equivalent of ITERATE in Java?**

`continue`.

**Q15. What is the equivalent of LEAVE in Java?**

`break`, when used to exit a loop.

**Q16. Can we use loops inside stored procedures?**

Yes. LOOP, WHILE, and REPEAT can be used inside stored procedures.

**Q17. Can we use conditional statements inside stored functions?**

Yes. IF, ELSEIF, ELSE, and CASE can be used inside stored functions.

**Q18. What is a Stored Function?**

A database routine that returns a single value.

**Q19. What is the difference between a CASE statement and CASE expression?**

A CASE statement uses `END CASE` and controls program flow. A CASE expression returns a value and ends with `END`.

**Q20. Which loop executes at least once?**

REPEAT.

---

# 17. Self-Learning Practice Checklist

Try solving these programs independently.

### LOOP

- [ ] Print numbers from 1 to 10.
- [ ] Calculate the sum of numbers from 1 to 100.
- [ ] Calculate factorial of a number.
- [ ] Print even numbers from 1 to 50.

### WHILE

- [ ] Print numbers from 1 to 20.
- [ ] Calculate the sum of first N natural numbers.
- [ ] Calculate the multiplication table of a number.
- [ ] Reverse a number.
- [ ] Count the digits of a number.

### REPEAT

- [ ] Print numbers from 1 to 10.
- [ ] Calculate the sum of even numbers.
- [ ] Calculate factorial using REPEAT.
- [ ] Print numbers in reverse order.

### Conditional Statements

- [ ] Check whether a number is positive or negative.
- [ ] Check whether a number is even or odd.
- [ ] Find the largest of two numbers.
- [ ] Find the largest of three numbers.
- [ ] Calculate student grades using IF-ELSEIF.
- [ ] Display month names using CASE.
- [ ] Calculate salary category using CASE.

### ITERATE and LEAVE

- [ ] Print odd numbers from 1 to 50.
- [ ] Skip multiples of 5 using ITERATE.
- [ ] Stop a loop when a number reaches 20 using LEAVE.
- [ ] Print numbers from 1 to 100 but skip even numbers.

### Stored Functions

- [ ] Create a function to calculate square.
- [ ] Create a function to calculate cube.
- [ ] Create a function to check even or odd.
- [ ] Create a function to find the largest of two numbers.
- [ ] Create a function to calculate factorial.
- [ ] Create a function to calculate sum of N natural numbers.

---

# 18. Quick Revision – Important Points

1. Flow Control Statements control program execution.
2. LOOP repeats until explicitly terminated.
3. WHILE checks the condition before execution.
4. REPEAT checks the condition after execution.
5. REPEAT executes at least once.
6. IF executes statements when a condition is TRUE.
7. IF-ELSE provides two execution paths.
8. ELSEIF checks additional conditions.
9. CASE handles multiple alternatives.
10. ITERATE skips the current loop iteration.
11. LEAVE exits a labelled loop or block.
12. ITERATE is similar to continue in Java.
13. LEAVE is similar to break in Java when exiting a loop.
14. Flow control statements can be used inside stored procedures and functions.
15. Stored Functions return a value using RETURN.
16. MySQL uses `END IF` to close IF blocks.
17. MySQL uses `END CASE` to close CASE statements.
18. MySQL uses `END WHILE`, `END LOOP`, and `END REPEAT` to close their respective loops.

---

# 19. Learning Resources

- [MySQL Flow Control Statements](https://dev.mysql.com/doc/refman/8.0/en/flow-control-statements.html)
- [MySQL LOOP Statement](https://dev.mysql.com/doc/refman/8.0/en/loop.html)
- [MySQL WHILE Statement](https://dev.mysql.com/doc/refman/8.0/en/while.html)
- [MySQL REPEAT Statement](https://dev.mysql.com/doc/refman/8.0/en/repeat.html)
- [MySQL ITERATE Statement](https://dev.mysql.com/doc/refman/8.0/en/iterate.html)
- [MySQL LEAVE Statement](https://dev.mysql.com/doc/refman/8.0/en/leave.html)
- [MySQL Stored Programs](https://dev.mysql.com/doc/refman/8.0/en/stored-programs.html)

---

**Happy Learning! 🚀**

*Prepared for CMCE – August 2026 Batch | Database Technologies*
