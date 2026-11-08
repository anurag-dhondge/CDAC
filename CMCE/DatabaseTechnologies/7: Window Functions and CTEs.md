# Session 7: Window Functions and CTEs

**Course:** CMCE – Database Technologies  
**Batch:** August 2026  
**Theory:** 2 Hours | **Lab:** 2 Hours | **Self-Learning:** 2 Hours

---

## 📌 Topics Covered

1. Introduction to Window Functions
2. Window Functions vs GROUP BY
3. Ranking Functions:
   - `ROW_NUMBER()`
   - `RANK()`
   - `DENSE_RANK()`
   - `NTILE()`
4. Aggregate Window Functions:
   - `SUM() OVER()`
   - `AVG() OVER()`
   - Running Totals
   - Moving Averages
5. `PARTITION BY` and `ORDER BY` in the `OVER()` clause
6. Common Table Expressions (CTEs)
7. Simple and Chained CTEs
8. Recursive CTEs
9. Practical SQL Queries

---

# 1. Introduction to Window Functions

A **Window Function** performs calculations across a set of related rows without combining them into a single result row.

It calculates values using a group of rows called a **window**, while keeping each original row in the output.

### Why do we use Window Functions?

- To rank employees based on salary.
- To calculate running totals.
- To calculate moving averages.
- To compare current and previous rows.
- To perform calculations within departments or categories.
- To analyze data without losing individual records.

### Basic Syntax

```sql
SELECT
    column_name,
    window_function() OVER (
        PARTITION BY column_name
        ORDER BY column_name
    ) AS result
FROM table_name;
```

### Important Components

| Component | Description |
|---|---|
| Window Function | Performs calculation across related rows |
| `OVER()` | Defines the window of rows |
| `PARTITION BY` | Divides rows into groups |
| `ORDER BY` | Defines the order of rows within a window |

---

# 2. Window Functions vs GROUP BY

Both Window Functions and `GROUP BY` perform calculations on multiple rows, but their output is different.

### GROUP BY

`GROUP BY` combines rows having the same values into a single result row.

```sql
SELECT department_id, AVG(salary)
FROM employees
GROUP BY department_id;
```

**Output:** One row per department.

### Window Function

A Window Function calculates the average salary for each department but displays every employee.

```sql
SELECT
    employee_name,
    department_id,
    salary,
    AVG(salary) OVER (
        PARTITION BY department_id
    ) AS department_avg
FROM employees;
```

**Output:** Every employee remains in the result, along with their department's average salary.

### Difference Between GROUP BY and Window Functions

| GROUP BY | Window Function |
|---|---|
| Combines multiple rows | Keeps individual rows |
| Returns one row per group | Returns one row per input row |
| Used for summarization | Used for detailed analysis |
| Does not use `OVER()` | Uses `OVER()` |

---

# 3. Sample Table for Practical Queries

We will use the following `employees` table for examples.

```sql
CREATE TABLE employees (
    emp_id INT PRIMARY KEY,
    employee_name VARCHAR(50),
    department VARCHAR(30),
    salary DECIMAL(10,2)
);
```

### Insert Sample Data

```sql
INSERT INTO employees VALUES
(1, 'Anurag', 'IT', 60000),
(2, 'Rahul', 'IT', 50000),
(3, 'Amit', 'IT', 50000),
(4, 'Sneha', 'HR', 45000),
(5, 'Priya', 'HR', 55000),
(6, 'Karan', 'Finance', 70000),
(7, 'Neha', 'Finance', 65000),
(8, 'Rohit', 'Finance', 60000);
```

### View Records

```sql
SELECT * FROM employees;
```

---

# 4. Ranking Window Functions

Ranking functions assign a position or rank to each row based on a specified order.

## 4.1 ROW_NUMBER()

`ROW_NUMBER()` assigns a unique sequential number to every row.

Even if two employees have the same salary, they receive different row numbers.

### Syntax

```sql
ROW_NUMBER() OVER (
    ORDER BY salary DESC
)
```

### Example: Rank Employees by Salary

```sql
SELECT
    employee_name,
    salary,
    ROW_NUMBER() OVER (
        ORDER BY salary DESC
    ) AS row_num
FROM employees;
```

**Important:** If two employees have the same salary, `ROW_NUMBER()` still assigns different numbers. Add a unique column such as `emp_id` to the `ORDER BY` clause for deterministic ordering.

```sql
ROW_NUMBER() OVER (
    ORDER BY salary DESC, emp_id
)
```

## 4.2 RANK()

`RANK()` assigns the same rank to rows having equal values.

However, it skips the next rank after a tie.

### Example

```sql
SELECT
    employee_name,
    salary,
    RANK() OVER (
        ORDER BY salary DESC
    ) AS employee_rank
FROM employees;
```

Example ranking:

| Employee | Salary | RANK |
|---|---:|---:|
| Karan | 70000 | 1 |
| Neha | 65000 | 2 |
| Anurag | 60000 | 3 |
| Rohit | 60000 | 3 |
| Rahul | 50000 | 5 |
| Amit | 50000 | 5 |

Notice that rank 4 is skipped.

## 4.3 DENSE_RANK()

`DENSE_RANK()` assigns the same rank to equal values but does not skip the next rank.

### Example

```sql
SELECT
    employee_name,
    salary,
    DENSE_RANK() OVER (
        ORDER BY salary DESC
    ) AS dense_rank
FROM employees;
```

Example ranking:

| Employee | Salary | DENSE_RANK |
|---|---:|---:|
| Karan | 70000 | 1 |
| Neha | 65000 | 2 |
| Anurag | 60000 | 3 |
| Rohit | 60000 | 3 |
| Rahul | 50000 | 4 |
| Amit | 50000 | 4 |

## 4.4 NTILE()

`NTILE(n)` divides the ordered rows into approximately equal-sized groups (buckets).

### Syntax

```sql
NTILE(number_of_buckets) OVER (
    ORDER BY column_name
)
```

### Example: Divide Employees into 4 Salary Groups

```sql
SELECT
    employee_name,
    salary,
    NTILE(4) OVER (
        ORDER BY salary DESC
    ) AS salary_group
FROM employees;
```

If there are 8 rows and 4 buckets, each bucket gets 2 rows.

### Difference Between Ranking Functions

| Function | Purpose | Handles Ties | Skips Rank |
|---|---|---|---|
| `ROW_NUMBER()` | Unique sequential number | Different numbers | No |
| `RANK()` | Ranking with gaps | Same rank | Yes |
| `DENSE_RANK()` | Ranking without gaps | Same rank | No |
| `NTILE(n)` | Divides rows into groups | Not a ranking function | Not applicable |

---

# 5. PARTITION BY and ORDER BY

The `OVER()` clause defines the rows on which a Window Function operates.

## 5.1 PARTITION BY

`PARTITION BY` divides the result into separate groups.

Each group is processed independently.

### Example: Rank Employees Within Each Department

```sql
SELECT
    employee_name,
    department,
    salary,
    RANK() OVER (
        PARTITION BY department
        ORDER BY salary DESC
    ) AS department_rank
FROM employees;
```

**Explanation:**

- Employees are divided by department.
- Each department gets its own ranking.
- Salary is sorted in descending order.
- Ranking starts again from 1 in every department.

## 5.2 ORDER BY

`ORDER BY` inside `OVER()` specifies the order in which rows are processed.

```sql
SELECT
    employee_name,
    salary,
    ROW_NUMBER() OVER (
        ORDER BY salary DESC
    ) AS row_num
FROM employees;
```

### Difference Between the Two

| PARTITION BY | ORDER BY |
|---|---|
| Divides rows into groups | Sorts rows within the window |
| Ranking restarts in each partition | Determines processing order |
| Optional | Optional |
| Can be used without ORDER BY | Can be used without PARTITION BY |

---

# 6. Aggregate Window Functions

Aggregate functions can also be used as Window Functions by adding the `OVER()` clause.

Common aggregate window functions:

- `SUM() OVER()`
- `AVG() OVER()`
- `COUNT() OVER()`
- `MAX() OVER()`
- `MIN() OVER()`

## 6.1 SUM() OVER()

Calculates the sum across a window of rows without grouping the output into a single row.

### Example: Total Salary of All Employees

```sql
SELECT
    employee_name,
    salary,
    SUM(salary) OVER () AS total_salary
FROM employees;
```

Every employee row displays the same overall salary total.

## 6.2 SUM() with PARTITION BY

### Example: Total Salary Department-wise

```sql
SELECT
    employee_name,
    department,
    salary,
    SUM(salary) OVER (
        PARTITION BY department
    ) AS department_total
FROM employees;
```

Every employee displays the total salary of their department.

## 6.3 AVG() OVER()

Calculates the average across a window.

### Example: Department-wise Average Salary

```sql
SELECT
    employee_name,
    department,
    salary,
    AVG(salary) OVER (
        PARTITION BY department
    ) AS department_avg
FROM employees;
```

---

# 7. Running Total

A **Running Total** is the cumulative sum of values as we move through an ordered set of rows.

It is also called a cumulative sum.

### Example: Running Total of Employee Salaries

```sql
SELECT
    employee_name,
    salary,
    SUM(salary) OVER (
        ORDER BY emp_id
        ROWS BETWEEN UNBOUNDED PRECEDING
        AND CURRENT ROW
    ) AS running_total
FROM employees;
```

### Explanation

| Clause | Meaning |
|---|---|
| `ORDER BY emp_id` | Defines the row sequence |
| `UNBOUNDED PRECEDING` | Starts from the first row |
| `CURRENT ROW` | Ends at the current row |
| `ROWS BETWEEN` | Defines the frame of rows |

### Running Total Department-wise

```sql
SELECT
    employee_name,
    department,
    salary,
    SUM(salary) OVER (
        PARTITION BY department
        ORDER BY emp_id
        ROWS BETWEEN UNBOUNDED PRECEDING
        AND CURRENT ROW
    ) AS running_total
FROM employees;
```

The running total restarts for every department.

**Note:** Specifying the `ROWS` frame explicitly helps avoid unexpected peer-row behavior when ordering values are tied.

---

# 8. Moving Average

A **Moving Average** calculates the average of a fixed number of recent rows.

It is useful for analyzing trends and smoothing fluctuations.

### Example: Average Salary of Current and Previous Two Employees

```sql
SELECT
    employee_name,
    salary,
    AVG(salary) OVER (
        ORDER BY emp_id
        ROWS BETWEEN 2 PRECEDING
        AND CURRENT ROW
    ) AS moving_avg
FROM employees;
```

### Explanation

- `2 PRECEDING`: Includes two previous rows.
- `CURRENT ROW`: Includes the current row.
- The calculation uses up to three rows.
- At the beginning, fewer than three rows are available.

### Moving Average Department-wise

```sql
SELECT
    employee_name,
    department,
    salary,
    AVG(salary) OVER (
        PARTITION BY department
        ORDER BY emp_id
        ROWS BETWEEN 2 PRECEDING
        AND CURRENT ROW
    ) AS department_moving_avg
FROM employees;
```

---

# 9. Common Table Expressions (CTEs)

A **Common Table Expression (CTE)** is a temporary named result set that can be referenced within a single SQL statement.

CTEs improve query readability and help break complex queries into smaller logical steps.

CTEs are created using the `WITH` clause.

### Why Use CTEs?

- Improve SQL query readability.
- Break complex queries into smaller parts.
- Avoid repeating the same subquery.
- Simplify data analysis.
- Support recursive queries and hierarchical data.

## 9.1 Simple CTE

### Syntax

```sql
WITH cte_name AS (
    SELECT column_name
    FROM table_name
)
SELECT *
FROM cte_name;
```

### Example: Employees Having Salary Greater Than 50000

```sql
WITH high_salary AS (
    SELECT *
    FROM employees
    WHERE salary > 50000
)
SELECT *
FROM high_salary;
```

**Explanation:**

1. `WITH` creates a CTE named `high_salary`.
2. The CTE selects employees earning more than 50000.
3. The main query retrieves records from that CTE.

## 9.2 CTE with Aggregate Function

### Example: Department-wise Average Salary

```sql
WITH department_avg AS (
    SELECT
        department,
        AVG(salary) AS avg_salary
    FROM employees
    GROUP BY department
)
SELECT *
FROM department_avg;
```

## 9.3 CTE with Window Function

### Example: Find Employees with the Highest Salary in Each Department

```sql
WITH ranked_employees AS (
    SELECT
        employee_name,
        department,
        salary,
        RANK() OVER (
            PARTITION BY department
            ORDER BY salary DESC
        ) AS rnk
    FROM employees
)
SELECT *
FROM ranked_employees
WHERE rnk = 1;
```

**Explanation:** The CTE calculates the rank of employees in each department. The outer query selects employees whose rank is 1.

This returns all employees tied for the highest salary in their department.

---

# 10. Chained CTEs

Multiple CTEs can be defined in a single `WITH` clause.

A later CTE can use the result of an earlier CTE.

### Syntax

```sql
WITH
cte1 AS (
    SELECT ...
),
cte2 AS (
    SELECT ...
    FROM cte1
),
cte3 AS (
    SELECT ...
    FROM cte2
)
SELECT *
FROM cte3;
```

### Example: Find Departments Having Above-Average Employee Salaries

```sql
WITH department_avg AS (
    SELECT
        department,
        AVG(salary) AS avg_salary
    FROM employees
    GROUP BY department
),
high_salary_departments AS (
    SELECT *
    FROM department_avg
    WHERE avg_salary > 55000
)
SELECT *
FROM high_salary_departments;
```

**Explanation:**

1. `department_avg` calculates the average salary for every department.
2. `high_salary_departments` filters departments with an average greater than 55000.
3. The final query displays the matching departments.

---

# 11. Recursive CTEs

A **Recursive CTE** is a CTE that refers to itself.

It is useful for working with hierarchical or tree-structured data.

### Common Applications

- Employee-manager hierarchy.
- Organization charts.
- Category-subcategory structures.
- Parent-child relationships.
- Generating sequences of numbers.
- Tree traversal.

### Syntax

```sql
WITH RECURSIVE cte_name AS (

    -- Anchor member
    SELECT ...

    UNION ALL

    -- Recursive member
    SELECT ...
    FROM table_name
    JOIN cte_name
        ON condition

)
SELECT *
FROM cte_name;
```

### Two Main Parts

| Part | Description |
|---|---|
| Anchor Member | Initial query that provides the starting rows |
| Recursive Member | Query that refers to the CTE and generates subsequent rows |

The recursive execution stops when the recursive member produces no more rows or a recursion limit is reached.

## 11.1 Example: Generate Numbers from 1 to 10

```sql
WITH RECURSIVE numbers AS (

    SELECT 1 AS num

    UNION ALL

    SELECT num + 1
    FROM numbers
    WHERE num < 10

)
SELECT *
FROM numbers;
```

**Output:**

| num |
|---:|
| 1 |
| 2 |
| 3 |
| 4 |
| 5 |
| 6 |
| 7 |
| 8 |
| 9 |
| 10 |

## 11.2 Recursive CTE for Employee Hierarchy

Create an employee hierarchy table.

```sql
CREATE TABLE organization (
    emp_id INT PRIMARY KEY,
    employee_name VARCHAR(50),
    manager_id INT NULL
);
```

### Insert Sample Records

```sql
INSERT INTO organization VALUES
(1, 'CEO', NULL),
(2, 'Manager A', 1),
(3, 'Manager B', 1),
(4, 'Employee A1', 2),
(5, 'Employee A2', 2),
(6, 'Employee B1', 3);
```

### Display Complete Organization Hierarchy

```sql
WITH RECURSIVE employee_hierarchy AS (

    -- Anchor: Start from the CEO
    SELECT
        emp_id,
        employee_name,
        manager_id,
        0 AS level
    FROM organization
    WHERE manager_id IS NULL

    UNION ALL

    -- Recursive: Find employees reporting to the previous level
    SELECT
        o.emp_id,
        o.employee_name,
        o.manager_id,
        eh.level + 1
    FROM organization o
    INNER JOIN employee_hierarchy eh
        ON o.manager_id = eh.emp_id

)
SELECT *
FROM employee_hierarchy
ORDER BY level, emp_id;
```

### Expected Output

| emp_id | employee_name | manager_id | level |
|---:|---|---:|---:|
| 1 | CEO | NULL | 0 |
| 2 | Manager A | 1 | 1 |
| 3 | Manager B | 1 | 1 |
| 4 | Employee A1 | 2 | 2 |
| 5 | Employee A2 | 2 | 2 |
| 6 | Employee B1 | 3 | 2 |

**Explanation:**

1. The anchor query selects the CEO.
2. The recursive query finds employees whose `manager_id` matches the previous level's `emp_id`.
3. The process continues until no more employees are found.
4. The `level` column indicates the employee's hierarchy depth.

**Important:** MySQL supports recursive CTEs from version 8.0. Use appropriate recursion limits and prevent cycles in hierarchical data.

---

# 12. Subquery vs CTE

Both subqueries and CTEs can be used to solve complex SQL problems.

### Using a Subquery

```sql
SELECT *
FROM employees
WHERE salary > (
    SELECT AVG(salary)
    FROM employees
);
```

### Using a CTE

```sql
WITH company_avg AS (
    SELECT AVG(salary) AS avg_salary
    FROM employees
)
SELECT e.*
FROM employees e
CROSS JOIN company_avg c
WHERE e.salary > c.avg_salary;
```

### Difference Between Subquery and CTE

| Subquery | CTE |
|---|---|
| Query inside another query | Named result set |
| Can become difficult to read when nested | Improves readability |
| Repeated logic may need to be written again | Can be referenced multiple times in the statement |
| Cannot directly define recursive logic by itself | Supports recursive queries |

**Note:** A CTE is not necessarily stored as a physical temporary table. MySQL may merge or materialize it depending on the query and optimizer.

---

# 13. Important SQL Clauses and Functions – Quick Revision

| Function / Clause | Purpose |
|---|---|
| `OVER()` | Defines a window for calculation |
| `PARTITION BY` | Divides rows into groups |
| `ORDER BY` | Defines row order |
| `ROW_NUMBER()` | Assigns unique sequential numbers |
| `RANK()` | Assigns ranks with gaps after ties |
| `DENSE_RANK()` | Assigns ranks without gaps |
| `NTILE(n)` | Divides rows into approximately equal buckets |
| `SUM() OVER()` | Calculates a window sum |
| `AVG() OVER()` | Calculates a window average |
| `ROWS BETWEEN` | Defines a window frame |
| `WITH` | Defines a CTE |
| `WITH RECURSIVE` | Defines a recursive CTE |
| Anchor Member | Starting rows of recursive query |
| Recursive Member | Generates subsequent rows |

---

# 14. Lab Practicals

## Practical 1: Rank Employees Using ROW_NUMBER()

**Question:** Display employees with unique row numbers based on salary in descending order.

```sql
SELECT
    emp_id,
    employee_name,
    salary,
    ROW_NUMBER() OVER (
        ORDER BY salary DESC, emp_id
    ) AS row_num
FROM employees;
```

## Practical 2: Rank Employees Using RANK()

**Question:** Display employee salary rankings. Equal salaries should receive the same rank.

```sql
SELECT
    employee_name,
    salary,
    RANK() OVER (
        ORDER BY salary DESC
    ) AS rnk
FROM employees;
```

## Practical 3: Rank Employees Using DENSE_RANK()

**Question:** Display salary rankings without skipping rank numbers.

```sql
SELECT
    employee_name,
    salary,
    DENSE_RANK() OVER (
        ORDER BY salary DESC
    ) AS dense_rnk
FROM employees;
```

## Practical 4: Department-wise Employee Ranking

```sql
SELECT
    employee_name,
    department,
    salary,
    DENSE_RANK() OVER (
        PARTITION BY department
        ORDER BY salary DESC
    ) AS department_rank
FROM employees;
```

## Practical 5: Find the Second Highest Distinct Salary

```sql
WITH salary_ranking AS (
    SELECT
        salary,
        DENSE_RANK() OVER (
            ORDER BY salary DESC
        ) AS rnk
    FROM employees
)
SELECT DISTINCT salary
FROM salary_ranking
WHERE rnk = 2;
```

## Practical 6: Find the Top Two Employees in Each Department

```sql
WITH ranked_employees AS (
    SELECT
        employee_name,
        department,
        salary,
        DENSE_RANK() OVER (
            PARTITION BY department
            ORDER BY salary DESC
        ) AS rnk
    FROM employees
)
SELECT *
FROM ranked_employees
WHERE rnk <= 2;
```

## Practical 7: Calculate Running Total

```sql
SELECT
    employee_name,
    salary,
    SUM(salary) OVER (
        ORDER BY emp_id
        ROWS BETWEEN UNBOUNDED PRECEDING
        AND CURRENT ROW
    ) AS running_total
FROM employees;
```

## Practical 8: Calculate Department-wise Running Total

```sql
SELECT
    employee_name,
    department,
    salary,
    SUM(salary) OVER (
        PARTITION BY department
        ORDER BY emp_id
        ROWS BETWEEN UNBOUNDED PRECEDING
        AND CURRENT ROW
    ) AS running_total
FROM employees;
```

## Practical 9: Calculate Moving Average

```sql
SELECT
    employee_name,
    salary,
    AVG(salary) OVER (
        ORDER BY emp_id
        ROWS BETWEEN 2 PRECEDING
        AND CURRENT ROW
    ) AS moving_average
FROM employees;
```

## Practical 10: Rewrite a Subquery Using a CTE

**Question:** Find employees earning more than the company's average salary.

```sql
WITH company_avg AS (
    SELECT AVG(salary) AS avg_salary
    FROM employees
)
SELECT e.*
FROM employees e
CROSS JOIN company_avg c
WHERE e.salary > c.avg_salary;
```

## Practical 11: Chained CTE

**Question:** Find departments where the average salary is greater than 50000.

```sql
WITH department_salary AS (
    SELECT
        department,
        AVG(salary) AS avg_salary
    FROM employees
    GROUP BY department
),
filtered_departments AS (
    SELECT *
    FROM department_salary
    WHERE avg_salary > 50000
)
SELECT *
FROM filtered_departments;
```

## Practical 12: Recursive CTE

**Question:** Generate numbers from 1 to 10.

```sql
WITH RECURSIVE number_series AS (
    SELECT 1 AS num

    UNION ALL

    SELECT num + 1
    FROM number_series
    WHERE num < 10
)
SELECT *
FROM number_series;
```

## Practical 13: Organization Hierarchy

**Question:** Display all employees under the CEO with their hierarchy levels.

Use the `organization` table and recursive CTE query explained in Section 11.2.

---

# 15. Important Interview Questions

**Q1. What is a Window Function?**

A Window Function performs calculations across related rows without combining them into a single row.

**Q2. What is the purpose of the OVER() clause?**

It defines the set of rows on which a Window Function operates.

**Q3. What is the difference between GROUP BY and Window Functions?**

`GROUP BY` combines rows into summary records, whereas Window Functions retain individual rows.

**Q4. Difference between ROW_NUMBER(), RANK(), and DENSE_RANK()?**

- `ROW_NUMBER()`: Gives every row a unique number.
- `RANK()`: Gives equal values the same rank and skips subsequent ranks.
- `DENSE_RANK()`: Gives equal values the same rank without skipping ranks.

**Q5. What is PARTITION BY?**

It divides rows into independent groups for Window Function calculations.

**Q6. What is a Running Total?**

A cumulative sum calculated row by row.

**Q7. What is a Moving Average?**

An average calculated over a fixed-size or specified moving window of rows.

**Q8. What is a CTE?**

A CTE is a named temporary result set defined using the `WITH` clause for a single SQL statement.

**Q9. What is a Recursive CTE?**

A Recursive CTE refers to itself and is used to process hierarchical or repeated data.

**Q10. What are the two parts of a Recursive CTE?**

1. Anchor Member
2. Recursive Member

**Q11. What is the difference between a CTE and a subquery?**

A CTE gives a query a name and makes complex SQL easier to read and reuse within the statement.

**Q12. Can we use Window Functions with CTEs?**

Yes. A CTE can calculate Window Function results, which can then be filtered in the outer query.

**Q13. Can we use a Window Function directly in the WHERE clause?**

No. In MySQL, calculate the Window Function in a CTE or derived table and filter its result in the outer query.

**Q14. What is NTILE(4)?**

It divides ordered rows into four approximately equal-sized buckets.

**Q15. Which MySQL version supports CTEs and Window Functions?**

MySQL 8.0 introduced both CTEs and Window Functions. Recursive CTEs are also supported in MySQL 8.0.

---

# 16. Quick Revision – Important Differences

### Ranking Functions

| Data | ROW_NUMBER | RANK | DENSE_RANK |
|---|---:|---:|---:|
| 100 | 1 | 1 | 1 |
| 90 | 2 | 2 | 2 |
| 90 | 3 | 2 | 2 |
| 80 | 4 | 4 | 3 |
| 70 | 5 | 5 | 4 |

### Window Function vs CTE

| Window Function | CTE |
|---|---|
| Performs calculations across related rows | Defines a named result set |
| Uses `OVER()` | Uses `WITH` |
| Used for ranking and analytical calculations | Used to organize and simplify queries |
| Does not automatically remove rows | Does not automatically remove rows |

---

# 17. Self-Learning Practice Questions

Try solving these questions independently.

- [ ] Display employees with their `ROW_NUMBER()` based on salary.
- [ ] Display employees with `RANK()` based on salary.
- [ ] Display employees with `DENSE_RANK()` based on salary.
- [ ] Divide employees into 3 groups using `NTILE(3)`.
- [ ] Find the highest-paid employee in each department.
- [ ] Find the second-highest distinct salary.
- [ ] Find the top 3 employees in each department.
- [ ] Calculate the total salary of each department using `SUM() OVER()`.
- [ ] Calculate the average salary of each department using `AVG() OVER()`.
- [ ] Calculate the running total of salaries.
- [ ] Calculate department-wise running totals.
- [ ] Calculate a moving average using the previous two rows and current row.
- [ ] Rewrite a nested subquery using a CTE.
- [ ] Create two chained CTEs to filter department-wise salary averages.
- [ ] Generate numbers from 1 to 20 using a Recursive CTE.
- [ ] Display the complete employee-manager hierarchy using a Recursive CTE.

---

# 18. Important Points to Remember

1. Window Functions use the `OVER()` clause.
2. `PARTITION BY` divides rows into groups.
3. `ORDER BY` inside `OVER()` defines the order of calculation.
4. `ROW_NUMBER()` always assigns unique row numbers.
5. `RANK()` skips ranks after ties.
6. `DENSE_RANK()` does not skip ranks after ties.
7. `NTILE(n)` divides rows into approximately equal-sized buckets.
8. `SUM() OVER()` can calculate running totals.
9. `AVG() OVER()` can calculate moving averages.
10. CTEs are defined using the `WITH` clause.
11. Recursive CTEs use `WITH RECURSIVE`.
12. A Recursive CTE has an anchor member and a recursive member.
13. MySQL 8.0 supports Window Functions and CTEs.

---

## 📚 Learning Resources

- [MySQL Window Functions Documentation](https://dev.mysql.com/doc/refman/8.0/en/window-functions.html)
- [MySQL WITH (CTE) Documentation](https://dev.mysql.com/doc/refman/8.0/en/with.html)
- [MySQL Aggregate Functions Documentation](https://dev.mysql.com/doc/refman/8.0/en/aggregate-functions.html)

---

**Happy Learning! 🚀**

*Prepared for CMCE – August 2026 Batch | Database Technologies*
