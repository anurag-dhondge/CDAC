# Sessions 29 & 30: JDBC and Transaction Management

**Course:** CDAC – CMCE / PGCP-AC  
**Sessions:** 29 & 30  
**Topics:** JDBC API, JDBC Architecture, JDBC Drivers, CRUD Operations, Stored Procedures, Metadata, SQL Injection, DAO Design Pattern and Transaction Management  
**Java Version:** Java 17  
**Database:** MySQL

---

## Table of Contents

1. [Introduction to JDBC](#1-introduction-to-jdbc)
2. [JDBC Architecture](#2-jdbc-architecture)
3. [JDBC Drivers](#3-jdbc-drivers)
4. [JDBC Classes and Interfaces](#4-jdbc-classes-and-interfaces)
5. [JDBC CRUD Operations](#5-jdbc-crud-operations)
6. [Statement vs PreparedStatement vs CallableStatement](#6-statement-vs-preparedstatement-vs-callablestatement)
7. [Stored Procedures and Functions](#7-stored-procedures-and-functions)
8. [Database Metadata](#8-database-metadata)
9. [SQL Injection and Prevention](#9-sql-injection-and-prevention)
10. [DAO Design Pattern](#10-dao-design-pattern)
11. [Transaction Management](#11-transaction-management)
12. [Complete JDBC Student Management Project](#12-complete-jdbc-student-management-project)
13. [Interview Questions and Answers](#13-interview-questions-and-answers)
14. [MCQs](#14-mcqs)
15. [Quick Revision Notes](#15-quick-revision-notes)

---

# 1. Introduction to JDBC

## 1.1 What is JDBC?

**JDBC stands for Java Database Connectivity.**

JDBC is a Java API that allows Java applications to communicate with relational databases such as:

- MySQL
- Oracle
- PostgreSQL
- SQL Server
- SQLite

Using JDBC, a Java application can:

1. Establish a connection with a database.
2. Execute SQL queries.
3. Insert records.
4. Retrieve records.
5. Update records.
6. Delete records.
7. Execute stored procedures and functions.
8. Manage database transactions.

### Real-world example

Consider a Student Management System.

A student registers through a Java application. The application needs to store the student's details in a MySQL database.

JDBC provides the connection between the Java application and MySQL.

<pre>
Java Application
       |
       v
      JDBC
       |
       v
   JDBC Driver
       |
       v
  MySQL Database
</pre>

## 1.2 Why do we need JDBC?

Without JDBC, Java applications need a database-specific communication mechanism.

JDBC provides a standard API so Java applications can interact with different relational databases using database-specific JDBC drivers.

### Applications of JDBC

- Banking applications
- Student management systems
- Employee management systems
- E-commerce applications
- Inventory management
- Hospital management systems
- Railway reservation systems

## 1.3 JDBC Package

The primary JDBC API is available in:

```java
java.sql
```

Additional JDBC functionality is available in:

```java
javax.sql
```

Important interfaces and classes include:

| Class / Interface | Purpose |
|---|---|
| DriverManager | Creates database connections |
| Driver | Represents a database driver |
| Connection | Represents a database connection |
| Statement | Executes SQL statements |
| PreparedStatement | Executes parameterized SQL |
| CallableStatement | Calls stored procedures |
| ResultSet | Stores query results |
| SQLException | Represents database errors |
| DatabaseMetaData | Provides database information |
| ResultSetMetaData | Provides query-result information |

---

# 2. JDBC Architecture

## 2.1 What is JDBC Architecture?

JDBC architecture explains how a Java application communicates with a database using the JDBC API and a database-specific driver.

### JDBC Architecture Diagram

<pre>
+------------------------------+
|       Java Application       |
+------------------------------+
               |
               v
+------------------------------+
|          JDBC API            |
| Connection, Statement, etc.  |
+------------------------------+
               |
               v
+------------------------------+
|        DriverManager         |
+------------------------------+
               |
               v
+------------------------------+
|         JDBC Driver          |
+------------------------------+
               |
               v
+------------------------------+
|       MySQL Database         |
+------------------------------+
</pre>

### Explanation

**1. Java Application**

The Java application contains the business logic and requests database operations.

**2. JDBC API**

Provides interfaces and classes for database communication.

**3. DriverManager**

Manages available JDBC drivers and helps establish connections.

**4. JDBC Driver**

Translates JDBC calls into the database-specific communication protocol.

**5. Database**

Executes SQL statements and returns results.

## 2.2 Two-Tier Architecture

In two-tier architecture, the Java application communicates directly with the database.

<pre>
+----------------------+
| Java Desktop App     |
+----------------------+
           |
           | JDBC
           v
+----------------------+
| Database Server      |
+----------------------+
</pre>

Example: A desktop-based Java application connected directly to MySQL.

## 2.3 Three-Tier Architecture

In three-tier architecture, an intermediate application or business layer handles requests between the client and database.

<pre>
+----------------------+
| Presentation Layer   |
| Java / Web Client    |
+----------------------+
           |
           v
+----------------------+
| Business Layer       |
| Service / Backend    |
+----------------------+
           |
           v
+----------------------+
| Data Access Layer    |
| JDBC / DAO           |
+----------------------+
           |
           v
+----------------------+
| Database             |
+----------------------+
</pre>

**Advantages:**

- Better separation of responsibilities.
- Easier maintenance.
- Business logic is separated from database logic.
- Better security and scalability options.

---

# 3. JDBC Drivers

## 3.1 What is a JDBC Driver?

A JDBC driver is a software component that enables a Java application to communicate with a particular database.

Different databases may require different JDBC drivers.

For example:

- MySQL → MySQL Connector/J
- PostgreSQL → PostgreSQL JDBC Driver
- Oracle → Oracle JDBC Driver

## 3.2 Types of JDBC Drivers

There are four traditional types of JDBC drivers.

### Type 1: JDBC-ODBC Bridge Driver

<pre>
Java Application
       |
       v
 JDBC-ODBC Bridge
       |
       v
      ODBC
       |
       v
    Database
</pre>

- Converts JDBC calls into ODBC calls.
- Requires ODBC installation.
- Platform dependent.
- Removed from the JDK in Java 8.

### Type 2: Native API Driver

<pre>
Java Application
       |
       v
 JDBC Driver
       |
       v
 Native Database Library
       |
       v
    Database
</pre>

- Uses native database libraries.
- Requires platform-specific installation.
- Less portable.

### Type 3: Network Protocol Driver

<pre>
Java Application
       |
       v
 JDBC Driver
       |
       v
 Middleware Server
       |
       v
    Database
</pre>

- Sends JDBC requests to middleware.
- Middleware communicates with the database.
- Can support multiple database types.

### Type 4: Thin Driver

<pre>
Java Application
       |
       v
 Pure Java JDBC Driver
       |
       v
    Database
</pre>

- Pure Java implementation.
- Directly communicates with the database protocol.
- Platform independent.
- Commonly used in modern applications.

**MySQL Connector/J is a Type 4 JDBC driver.**

## 3.3 MySQL JDBC Driver Dependency

For Maven projects, add this dependency to `pom.xml`:

```xml
<dependency>
    <groupId>com.mysql</groupId>
    <artifactId>mysql-connector-j</artifactId>
    <version>9.5.0</version>
</dependency>
```

Use a Connector/J version compatible with your MySQL server and Java runtime.

For a project without Maven, download the MySQL Connector/J JAR and add it to the project's classpath.

### JDBC URL for MySQL

```java
String url =
    "jdbc:mysql://localhost:3306/college";
```

General format:

```text
jdbc:mysql://hostname:port/database_name
```

| Component | Meaning |
|---|---|
| jdbc | JDBC protocol |
| mysql | Database type |
| localhost | Database server |
| 3306 | Default MySQL port |
| college | Database name |

---

# 4. JDBC Classes and Interfaces

This is one of the most important sections of JDBC.

## 4.1 DriverManager

`DriverManager` is a class that manages JDBC drivers and helps create database connections.

Package:

```java
java.sql.DriverManager
```

Example:

```java
Connection con = DriverManager.getConnection(
    "jdbc:mysql://localhost:3306/college",
    "root",
    "password"
);
```

Important methods:

| Method | Purpose |
|---|---|
| `getConnection()` | Establishes database connection |
| `getDriver()` | Retrieves a suitable registered driver |
| `getDrivers()` | Lists registered drivers |
| `registerDriver()` | Registers a driver |
| `deregisterDriver()` | Deregisters a driver |

## 4.2 Driver

`Driver` is an interface representing a database-specific JDBC driver.

A JDBC driver implements this interface.

Example:

```java
java.sql.Driver
```

Modern JDBC drivers are normally discovered automatically through the service-provider mechanism when their JAR is on the classpath.

Older examples may use:

```java
Class.forName("com.mysql.cj.jdbc.Driver");
```

This explicitly loads the driver class. It is usually unnecessary with a correctly configured modern Connector/J installation.

## 4.3 Connection

`Connection` is an interface representing an active database connection.

Example:

```java
Connection con = DriverManager.getConnection(
    url, username, password
);
```

Important methods:

| Method | Purpose |
|---|---|
| `createStatement()` | Creates Statement |
| `prepareStatement()` | Creates PreparedStatement |
| `prepareCall()` | Creates CallableStatement |
| `setAutoCommit()` | Enables/disables automatic commits |
| `commit()` | Commits a transaction |
| `rollback()` | Rolls back a transaction |
| `close()` | Closes the connection |
| `isClosed()` | Checks whether connection is closed |

## 4.4 Statement

`Statement` is used to execute static SQL statements.

Example:

```java
Statement st = con.createStatement();

ResultSet rs = st.executeQuery(
    "SELECT * FROM student"
);
```

Important methods:

| Method | Purpose |
|---|---|
| `executeQuery()` | Executes a query returning a ResultSet |
| `executeUpdate()` | Executes INSERT, UPDATE, DELETE or suitable DDL |
| `execute()` | Executes general SQL and indicates the type of result |

## 4.5 PreparedStatement

`PreparedStatement` is used to execute parameterized SQL statements.

It supports placeholders (`?`) for values.

Example:

```java
String sql =
    "INSERT INTO student(name, marks) VALUES (?, ?)";

PreparedStatement ps = con.prepareStatement(sql);

ps.setString(1, "Anurag");
ps.setDouble(2, 85.5);

ps.executeUpdate();
```

**Advantages:**

- Helps prevent SQL injection when values are bound as parameters.
- Supports repeated execution with different parameter values.
- Improves readability.
- Can reduce repeated SQL parsing overhead, depending on the driver and database.

Important methods:

| Method | Purpose |
|---|---|
| `setInt()` | Sets an integer parameter |
| `setString()` | Sets a string parameter |
| `setDouble()` | Sets a double parameter |
| `setDate()` | Sets a SQL date parameter |
| `setNull()` | Sets a parameter to SQL NULL |
| `executeQuery()` | Executes a SELECT query |
| `executeUpdate()` | Executes INSERT, UPDATE or DELETE |

Parameter indexes start from **1**, not 0.

## 4.6 ResultSet

`ResultSet` stores the rows returned by a SELECT query.

Example:

```java
ResultSet rs = st.executeQuery(
    "SELECT * FROM student"
);

while (rs.next()) {

    int id = rs.getInt("id");

    String name = rs.getString("name");

    double marks = rs.getDouble("marks");

    System.out.println(id + " " + name + " " + marks);
}
```

Important methods:

| Method | Purpose |
|---|---|
| `next()` | Moves to the next row |
| `getInt()` | Retrieves an integer |
| `getString()` | Retrieves a String |
| `getDouble()` | Retrieves a double |
| `getDate()` | Retrieves SQL Date |
| `getObject()` | Retrieves a value as an object |
| `close()` | Closes the ResultSet |

**Important:** Initially, the ResultSet cursor is positioned before the first row. Call `next()` before reading a row.

## 4.7 executeQuery() vs executeUpdate() vs execute()

| Method | Use | Return Type |
|---|---|---|
| `executeQuery()` | SELECT | ResultSet |
| `executeUpdate()` | INSERT, UPDATE, DELETE and suitable DDL | int |
| `execute()` | General SQL execution | boolean |

Example:

```java
ResultSet rs = st.executeQuery("SELECT * FROM student");

int rows = st.executeUpdate(
    "UPDATE student SET marks = 90 WHERE id = 1"
);

boolean result = st.execute("SELECT * FROM student");
```

---

# 5. JDBC CRUD Operations

CRUD means:

- C – Create
- R – Read
- U – Update
- D – Delete

We will use a Student table for all four operations.

## 5.1 Create Database and Table

Run the following SQL in MySQL:

```sql
CREATE DATABASE college;

USE college;

CREATE TABLE student (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE,
    marks DOUBLE
);
```

Insert sample data:

```sql
INSERT INTO student(name, email, marks)
VALUES
('Anurag', 'anurag@gmail.com', 85.5),
('Rahul', 'rahul@gmail.com', 90.0),
('Priya', 'priya@gmail.com', 92.5);
```

## 5.2 Establishing JDBC Connection

```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {

    private static final String URL =
        "jdbc:mysql://localhost:3306/college";

    private static final String USER = "root";

    private static final String PASSWORD = "password";

    public static Connection getConnection()
            throws SQLException {

        return DriverManager.getConnection(
            URL, USER, PASSWORD
        );
    }
}
```

Replace `password` with your actual MySQL password.

## 5.3 INSERT Operation

```java
import java.sql.Connection;
import java.sql.PreparedStatement;

public class InsertStudent {

    public static void main(String[] args) {

        String sql =
            "INSERT INTO student(name, email, marks) "
            + "VALUES (?, ?, ?)";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql)
        ) {

            ps.setString(1, "Amit");
            ps.setString(2, "amit@gmail.com");
            ps.setDouble(3, 88.5);

            int rows = ps.executeUpdate();

            System.out.println(
                rows + " record inserted successfully"
            );

        } catch (Exception e) {

            e.printStackTrace();
        }
    }
}
```

Output:

```text
1 record inserted successfully
```

## 5.4 SELECT Operation

```java
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class DisplayStudents {

    public static void main(String[] args) {

        String sql = "SELECT * FROM student";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql);

            ResultSet rs = ps.executeQuery()
        ) {

            while (rs.next()) {

                System.out.println(
                    rs.getInt("id") + " "
                    + rs.getString("name") + " "
                    + rs.getString("email") + " "
                    + rs.getDouble("marks")
                );
            }

        } catch (Exception e) {

            e.printStackTrace();
        }
    }
}
```

Possible output:

```text
1 Anurag anurag@gmail.com 85.5
2 Rahul rahul@gmail.com 90.0
3 Priya priya@gmail.com 92.5
```

The exact IDs and records depend on the database contents.

## 5.5 UPDATE Operation

```java
import java.sql.Connection;
import java.sql.PreparedStatement;

public class UpdateStudent {

    public static void main(String[] args) {

        String sql =
            "UPDATE student SET marks = ? WHERE id = ?";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql)
        ) {

            ps.setDouble(1, 95.0);

            ps.setInt(2, 1);

            int rows = ps.executeUpdate();

            System.out.println(
                rows + " record updated"
            );

        } catch (Exception e) {

            e.printStackTrace();
        }
    }
}
```

Output:

```text
1 record updated
```

## 5.6 DELETE Operation

```java
import java.sql.Connection;
import java.sql.PreparedStatement;

public class DeleteStudent {

    public static void main(String[] args) {

        String sql =
            "DELETE FROM student WHERE id = ?";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql)
        ) {

            ps.setInt(1, 3);

            int rows = ps.executeUpdate();

            System.out.println(
                rows + " record deleted"
            );

        } catch (Exception e) {

            e.printStackTrace();
        }
    }
}
```

Output:

```text
1 record deleted
```

---

# 6. Statement vs PreparedStatement vs CallableStatement

These are three important JDBC interfaces.

## 6.1 Statement

Used for executing SQL statements that do not need parameter placeholders.

```java
Statement st = con.createStatement();

ResultSet rs = st.executeQuery(
    "SELECT * FROM student"
);
```

## 6.2 PreparedStatement

Used for parameterized SQL statements.

```java
PreparedStatement ps = con.prepareStatement(
    "SELECT * FROM student WHERE id = ?"
);

ps.setInt(1, 1);

ResultSet rs = ps.executeQuery();
```

## 6.3 CallableStatement

Used to call stored procedures and database functions.

```java
CallableStatement cs =
    con.prepareCall("{CALL getStudents()}");

ResultSet rs = cs.executeQuery();
```

## 6.4 Comparison

| Feature | Statement | PreparedStatement | CallableStatement |
|---|---|---|---|
| Purpose | Static SQL | Parameterized SQL | Stored procedures |
| Parameters | No placeholders | Supports `?` | Supports IN/OUT parameters |
| SQL injection protection | Unsafe if concatenating input | Safer with bound values | Depends on parameterized usage |
| Reusability | Less convenient | Good | Good |
| Typical use | Fixed queries | CRUD operations | Procedures and functions |

**Remember the inheritance relationship:**

```text
Statement
   |
   v
PreparedStatement
   |
   v
CallableStatement
```

More precisely, `PreparedStatement` extends `Statement`, and `CallableStatement` extends `PreparedStatement`.

---

# 7. Stored Procedures and Functions

## 7.1 What is a Stored Procedure?

A stored procedure is a named collection of SQL statements stored inside the database.

It can accept input parameters and return output parameters or result sets.

### Advantages

- Reusable database logic.
- Centralized SQL operations.
- Reduced repeated application-side SQL.
- Can simplify complex database operations.
- Can support database-side permission management.

## 7.2 Creating a Stored Procedure in MySQL

```sql
DELIMITER //

CREATE PROCEDURE getStudents()
BEGIN

    SELECT * FROM student;

END //

DELIMITER ;
```

Call it in MySQL:

```sql
CALL getStudents();
```

## 7.3 Calling Stored Procedure Using JDBC

```java
import java.sql.*;

public class ProcedureDemo {

    public static void main(String[] args) {

        try (
            Connection con = DBConnection.getConnection();

            CallableStatement cs =
                con.prepareCall("{CALL getStudents()}");

            ResultSet rs = cs.executeQuery()
        ) {

            while (rs.next()) {

                System.out.println(
                    rs.getInt("id") + " "
                    + rs.getString("name")
                );
            }

        } catch (Exception e) {

            e.printStackTrace();
        }
    }
}
```

## 7.4 Stored Procedure with IN Parameter

Create procedure:

```sql
DELIMITER //

CREATE PROCEDURE getStudentById(IN studentId INT)
BEGIN

    SELECT * FROM student
    WHERE id = studentId;

END //

DELIMITER ;
```

JDBC code:

```java
CallableStatement cs =
    con.prepareCall("{CALL getStudentById(?)}");

cs.setInt(1, 1);

ResultSet rs = cs.executeQuery();
```

## 7.5 Stored Procedure with OUT Parameter

Create procedure:

```sql
DELIMITER //

CREATE PROCEDURE getStudentCount(OUT total INT)
BEGIN

    SELECT COUNT(*) INTO total
    FROM student;

END //

DELIMITER ;
```

JDBC code:

```java
CallableStatement cs =
    con.prepareCall("{CALL getStudentCount(?)}");

cs.registerOutParameter(1, Types.INTEGER);

cs.execute();

int count = cs.getInt(1);

System.out.println("Total students: " + count);
```

## 7.6 What is a Database Function?

A database function is a stored program that returns a value.

Example MySQL function:

```sql
DELIMITER //

CREATE FUNCTION calculateBonus(salary DOUBLE)
RETURNS DOUBLE
DETERMINISTIC
BEGIN

    RETURN salary * 0.10;

END //

DELIMITER ;
```

Call it using JDBC:

```java
CallableStatement cs =
    con.prepareCall("{? = CALL calculateBonus(?)}");

cs.registerOutParameter(1, Types.DOUBLE);

cs.setDouble(2, 50000);

cs.execute();

double bonus = cs.getDouble(1);

System.out.println("Bonus: " + bonus);
```

For MySQL, JDBC escape syntax for functions is supported by Connector/J. A function can also be invoked using a parameterized SQL expression:

```java
PreparedStatement ps =
    con.prepareStatement(
        "SELECT calculateBonus(?)"
    );

ps.setDouble(1, 50000);

ResultSet rs = ps.executeQuery();

if (rs.next()) {
    System.out.println(rs.getDouble(1));
}
```

### Procedure vs Function

| Stored Procedure | Function |
|---|---|
| Created using PROCEDURE | Created using FUNCTION |
| Called using CALL | Used in an expression or SELECT |
| Can return result sets and OUT parameters | Returns a value |
| May perform database operations | Commonly used to calculate or return values |
| Does not have a required scalar return value | Must declare a return type |

---

# 8. Database Metadata

## 8.1 What is Metadata?

Metadata means data about data.

In JDBC, metadata provides information about the database, tables, columns, SQL query results and supported features.

There are two important metadata interfaces:

1. DatabaseMetaData
2. ResultSetMetaData

## 8.2 DatabaseMetaData

`DatabaseMetaData` provides information about the database and JDBC driver.

Example:

```java
import java.sql.*;

public class DatabaseMetadataDemo {

    public static void main(String[] args) {

        try (
            Connection con = DBConnection.getConnection()
        ) {

            DatabaseMetaData dbmd =
                con.getMetaData();

            System.out.println(
                "Database: " +
                dbmd.getDatabaseProductName()
            );

            System.out.println(
                "Version: " +
                dbmd.getDatabaseProductVersion()
            );

            System.out.println(
                "Driver: " +
                dbmd.getDriverName()
            );

            System.out.println(
                "Username: " +
                dbmd.getUserName()
            );

        } catch (Exception e) {

            e.printStackTrace();
        }
    }
}
```

Possible output:

```text
Database: MySQL
Version: 8.x
Driver: MySQL Connector/J
Username: root@localhost
```

Actual version and username depend on the environment.

Important methods:

| Method | Purpose |
|---|---|
| `getDatabaseProductName()` | Database name |
| `getDatabaseProductVersion()` | Database version |
| `getDriverName()` | JDBC driver name |
| `getDriverVersion()` | JDBC driver version |
| `getUserName()` | Connected database username |
| `getURL()` | Database connection URL |
| `getTables()` | Retrieves table information |
| `getColumns()` | Retrieves column information |

## 8.3 ResultSetMetaData

`ResultSetMetaData` provides information about the columns returned by a query.

Example:

```java
import java.sql.*;

public class ResultSetMetadataDemo {

    public static void main(String[] args) {

        String sql = "SELECT * FROM student";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql);

            ResultSet rs = ps.executeQuery()
        ) {

            ResultSetMetaData rsmd =
                rs.getMetaData();

            int count = rsmd.getColumnCount();

            for (int i = 1; i <= count; i++) {

                System.out.println(
                    "Column: " +
                    rsmd.getColumnName(i)
                );

                System.out.println(
                    "Type: " +
                    rsmd.getColumnTypeName(i)
                );
            }

        } catch (Exception e) {

            e.printStackTrace();
        }
    }
}
```

Possible output:

```text
Column: id
Type: INT
Column: name
Type: VARCHAR
Column: email
Type: VARCHAR
Column: marks
Type: DOUBLE
```

### DatabaseMetaData vs ResultSetMetaData

| DatabaseMetaData | ResultSetMetaData |
|---|---|
| Information about the database | Information about query result columns |
| Database product name/version | Column names and data types |
| Driver details | Column count and column properties |
| Obtained from Connection | Obtained from ResultSet |

---

# 9. SQL Injection and Prevention

## 9.1 What is SQL Injection?

SQL Injection is a security vulnerability in which an attacker manipulates SQL queries by providing malicious input.

It can occur when an application directly concatenates untrusted user input into SQL statements.

### Example of an Unsafe Query

```java
String username = "admin";

String sql =
    "SELECT * FROM users WHERE username = '"
    + username + "'";
```

Suppose an attacker enters:

```text
' OR '1'='1
```

The resulting query may become:

```sql
SELECT * FROM users
WHERE username = '' OR '1'='1';
```

Since `'1'='1'` is true, the query may return unintended records.

The exact impact depends on the surrounding query and database permissions.

## 9.2 Prevent SQL Injection Using PreparedStatement

Use parameterized SQL instead of concatenating input.

```java
String sql =
    "SELECT * FROM users WHERE username = ?";

PreparedStatement ps =
    con.prepareStatement(sql);

ps.setString(1, username);

ResultSet rs = ps.executeQuery();
```

The input is treated as a value rather than executable SQL syntax.

### Additional prevention methods

1. Always use PreparedStatement for user-provided values.
2. Avoid building SQL queries using string concatenation.
3. Validate input according to business rules.
4. Use least-privilege database accounts.
5. Do not expose database error details to end users.
6. Use safe query construction for dynamic identifiers such as table or column names.
7. Keep database drivers and software updated.

**Important:** PreparedStatement placeholders are for values, not SQL identifiers. For example, you cannot safely replace a table name using `?`. Dynamic identifiers should be selected from a strict allowlist.

---

# 10. DAO Design Pattern

## 10.1 What is DAO?

DAO stands for **Data Access Object**.

DAO is a design pattern that separates database access logic from business logic.

It provides a dedicated class responsible for performing database operations.

### Why use DAO?

Without DAO, SQL queries may be written directly inside business classes.

This causes:

- Code duplication.
- Poor maintainability.
- Difficult testing.
- Tight coupling between business logic and database operations.

DAO solves this problem by separating responsibilities.

## 10.2 DAO Architecture

<pre>
+--------------------------+
|     Main / Client        |
+--------------------------+
             |
             v
+--------------------------+
|     Service Layer        |
|     Business Logic       |
+--------------------------+
             |
             v
+--------------------------+
|       DAO Layer          |
| CRUD Database Methods    |
+--------------------------+
             |
             v
+--------------------------+
|      JDBC API            |
+--------------------------+
             |
             v
+--------------------------+
|     MySQL Database       |
+--------------------------+
</pre>

## 10.3 DAO Project Structure

```text
JDBCStudentManagement/
│
├── src/
│   ├── model/
│   │   └── Student.java
│   │
│   ├── util/
│   │   └── DBConnection.java
│   │
│   ├── dao/
│   │   ├── StudentDAO.java
│   │   └── StudentDAOImpl.java
│   │
│   └── main/
│       └── Main.java
│
└── pom.xml
```

## 10.4 Model Class

File: `Student.java`

```java
package model;

public class Student {

    private int id;

    private String name;

    private String email;

    private double marks;

    public Student() {
    }

    public Student(
            int id,
            String name,
            String email,
            double marks) {

        this.id = id;
        this.name = name;
        this.email = email;
        this.marks = marks;
    }

    public Student(
            String name,
            String email,
            double marks) {

        this.name = name;
        this.email = email;
        this.marks = marks;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public double getMarks() {
        return marks;
    }

    public void setMarks(double marks) {
        this.marks = marks;
    }

    @Override
    public String toString() {

        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", marks=" + marks +
                '}';
    }
}
```

## 10.5 Database Connection Class

File: `DBConnection.java`

```java
package util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {

    private static final String URL =
        "jdbc:mysql://localhost:3306/college";

    private static final String USER = "root";

    private static final String PASSWORD = "password";

    public static Connection getConnection()
            throws SQLException {

        return DriverManager.getConnection(
            URL, USER, PASSWORD
        );
    }
}
```

## 10.6 DAO Interface

File: `StudentDAO.java`

```java
package dao;

import model.Student;

import java.util.List;

public interface StudentDAO {

    void addStudent(Student student);

    Student getStudentById(int id);

    List<Student> getAllStudents();

    void updateStudent(Student student);

    void deleteStudent(int id);
}
```

## 10.7 DAO Implementation

File: `StudentDAOImpl.java`

```java
package dao;

import model.Student;
import util.DBConnection;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class StudentDAOImpl implements StudentDAO {

    @Override
    public void addStudent(Student student) {

        String sql =
            "INSERT INTO student(name, email, marks) "
            + "VALUES (?, ?, ?)";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql)
        ) {

            ps.setString(1, student.getName());

            ps.setString(2, student.getEmail());

            ps.setDouble(3, student.getMarks());

            ps.executeUpdate();

            System.out.println("Student inserted");

        } catch (SQLException e) {

            e.printStackTrace();
        }
    }

    @Override
    public Student getStudentById(int id) {

        String sql =
            "SELECT * FROM student WHERE id = ?";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql)
        ) {

            ps.setInt(1, id);

            try (ResultSet rs = ps.executeQuery()) {

                if (rs.next()) {

                    return new Student(
                        rs.getInt("id"),
                        rs.getString("name"),
                        rs.getString("email"),
                        rs.getDouble("marks")
                    );
                }
            }

        } catch (SQLException e) {

            e.printStackTrace();
        }

        return null;
    }

    @Override
    public List<Student> getAllStudents() {

        List<Student> students = new ArrayList<>();

        String sql = "SELECT * FROM student";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql);

            ResultSet rs = ps.executeQuery()
        ) {

            while (rs.next()) {

                Student student = new Student(
                    rs.getInt("id"),
                    rs.getString("name"),
                    rs.getString("email"),
                    rs.getDouble("marks")
                );

                students.add(student);
            }

        } catch (SQLException e) {

            e.printStackTrace();
        }

        return students;
    }

    @Override
    public void updateStudent(Student student) {

        String sql =
            "UPDATE student SET name = ?, "
            + "email = ?, marks = ? WHERE id = ?";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql)
        ) {

            ps.setString(1, student.getName());

            ps.setString(2, student.getEmail());

            ps.setDouble(3, student.getMarks());

            ps.setInt(4, student.getId());

            int rows = ps.executeUpdate();

            System.out.println(
                rows + " record(s) updated"
            );

        } catch (SQLException e) {

            e.printStackTrace();
        }
    }

    @Override
    public void deleteStudent(int id) {

        String sql =
            "DELETE FROM student WHERE id = ?";

        try (
            Connection con = DBConnection.getConnection();

            PreparedStatement ps =
                con.prepareStatement(sql)
        ) {

            ps.setInt(1, id);

            int rows = ps.executeUpdate();

            System.out.println(
                rows + " record(s) deleted"
            );

        } catch (SQLException e) {

            e.printStackTrace();
        }
    }
}
```

## 10.8 Main Class

File: `Main.java`

```java
package main;

import dao.StudentDAO;
import dao.StudentDAOImpl;
import model.Student;

public class Main {

    public static void main(String[] args) {

        StudentDAO dao = new StudentDAOImpl();

        // INSERT
        Student student = new Student(
            "Anurag",
            "anurag@gmail.com",
            90.5
        );

        dao.addStudent(student);

        // SELECT BY ID
        Student result = dao.getStudentById(1);

        System.out.println(result);

        // DISPLAY ALL
        System.out.println("\nAll Students:");

        for (Student s : dao.getAllStudents()) {
            System.out.println(s);
        }

        // UPDATE
        Student updated = new Student(
            1,
            "Anurag Dhondge",
            "anurag@gmail.com",
            95.0
        );

        dao.updateStudent(updated);

        // DELETE
        // dao.deleteStudent(1);
    }
}
```

**DAO Pattern Benefits:**

- Separation of concerns.
- Better code organization.
- Reusable database operations.
- Easier testing and maintenance.
- Database implementation can be changed with less impact on business logic.

**Important design note:** In a production application, it is generally better to let SQL exceptions propagate to a service layer or handle them through a consistent application-level error strategy rather than printing stack traces and returning null.

---

# 11. Transaction Management

## 11.1 What is a Transaction?

A transaction is a group of database operations treated as one logical unit of work.

A transaction should either complete successfully or be rolled back when it fails.

### Real-world example: Bank Transfer

Suppose Anurag transfers ₹1,000 to Rahul.

Two operations are required:

1. Deduct ₹1,000 from Anurag's account.
2. Add ₹1,000 to Rahul's account.

Both operations must succeed together.

If the debit succeeds but the credit fails, the database should undo the debit.

This is where transaction management is required.

## 11.2 ACID Properties

Database transactions follow four important properties called ACID.

| Property | Meaning |
|---|---|
| Atomicity | All operations succeed or none are applied |
| Consistency | Transaction preserves database rules and constraints |
| Isolation | Concurrent transactions are controlled to avoid improper interference |
| Durability | Committed changes survive failures according to database guarantees |

### Atomicity

A transaction is treated as one unit.

Example: A bank transfer should not deduct money without crediting the receiver.

### Consistency

A transaction should preserve database integrity.

Example: Account balance should not violate applicable business rules.

### Isolation

Concurrent transactions should not produce invalid intermediate results.

### Durability

After a successful commit, changes are persisted according to the database's durability guarantees.

## 11.3 Auto-commit Mode

By default, JDBC connections generally use auto-commit mode.

```java
con.getAutoCommit();
```

When auto-commit is true, each SQL statement is committed automatically after successful execution.

To manage transactions manually:

```java
con.setAutoCommit(false);
```

## 11.4 commit()

`commit()` permanently commits the current transaction.

```java
con.commit();
```

## 11.5 rollback()

`rollback()` cancels the current transaction's uncommitted changes.

```java
con.rollback();
```

## 11.6 JDBC Transaction Example

```java
import java.sql.*;

public class TransactionDemo {

    public static void main(String[] args) {

        String debit =
            "UPDATE accounts SET balance = balance - ? "
            + "WHERE account_id = ? AND balance >= ?";

        String credit =
            "UPDATE accounts SET balance = balance + ? "
            + "WHERE account_id = ?";

        try (
            Connection con = DBConnection.getConnection()
        ) {

            con.setAutoCommit(false);

            try (
                PreparedStatement debitPs =
                    con.prepareStatement(debit);

                PreparedStatement creditPs =
                    con.prepareStatement(credit)
            ) {

                double amount = 1000;

                // Debit sender
                debitPs.setDouble(1, amount);
                debitPs.setInt(2, 101);
                debitPs.setDouble(3, amount);

                int debitRows = debitPs.executeUpdate();

                if (debitRows != 1) {
                    throw new SQLException(
                        "Debit failed or insufficient balance"
                    );
                }

                // Credit receiver
                creditPs.setDouble(1, amount);
                creditPs.setInt(2, 102);

                int creditRows = creditPs.executeUpdate();

                if (creditRows != 1) {
                    throw new SQLException(
                        "Credit failed"
                    );
                }

                con.commit();

                System.out.println(
                    "Transaction successful"
                );

            } catch (SQLException e) {

                con.rollback();

                System.out.println(
                    "Transaction rolled back"
                );

                throw e;
            }

        } catch (SQLException e) {

            e.printStackTrace();
        }
    }
}
```

### SQL Table for Banking Example

```sql
CREATE TABLE accounts (
    account_id INT PRIMARY KEY,
    holder_name VARCHAR(100),
    balance DECIMAL(12,2) NOT NULL
);

INSERT INTO accounts
VALUES
(101, 'Anurag', 10000),
(102, 'Rahul', 5000);
```

### Transaction Flow

<pre>
          BEGIN
            |
            v
      Debit Account
            |
            v
      Credit Account
            |
            v
      Both successful?
         /       \
       YES        NO
        |          |
        v          v
      COMMIT     ROLLBACK
        |          |
        v          v
     Success    Undo changes
</pre>

## 11.7 Transaction Management Methods

| Method | Purpose |
|---|---|
| `setAutoCommit(false)` | Starts manual transaction management |
| `commit()` | Commits changes |
| `rollback()` | Reverts uncommitted changes |
| `getAutoCommit()` | Checks auto-commit status |
| `setTransactionIsolation()` | Sets isolation level |
| `getTransactionIsolation()` | Gets isolation level |
| `Savepoint` | Marks a point inside a transaction |
| `rollback(savepoint)` | Rolls back to a savepoint |

## 11.8 Savepoints

A savepoint allows partial rollback within a transaction.

Example:

```java
con.setAutoCommit(false);

Savepoint sp = con.setSavepoint("SAVE_POINT_1");

// Execute SQL operations

con.rollback(sp);

// Continue with other operations

con.commit();
```

A savepoint does not commit the transaction.

## 11.9 Transaction Isolation Levels

JDBC defines standard transaction isolation levels.

| Isolation Level | Value | Description |
|---|---:|---|
| READ_UNCOMMITTED | 1 | May allow dirty reads |
| READ_COMMITTED | 2 | Prevents dirty reads |
| REPEATABLE_READ | 4 | Prevents dirty and non-repeatable reads |
| SERIALIZABLE | 8 | Strongest standard isolation; prevents phantom reads |

### Important Database Problems

**Dirty Read:** A transaction reads data changed by another transaction that has not yet committed.

**Non-repeatable Read:** A transaction reads the same row twice and gets different committed values.

**Phantom Read:** Repeating a range query returns additional or missing rows due to another committed transaction.

Set isolation level:

```java
con.setTransactionIsolation(
    Connection.TRANSACTION_READ_COMMITTED
);
```

The database and storage engine determine which isolation behaviors are actually supported and how they are implemented.

---

# 12. Complete JDBC Student Management Project

## Project Objective

Create a console-based Student Management System using Java JDBC and MySQL.

### Functional Requirements

1. Add Student.
2. Display All Students.
3. Search Student by ID.
4. Update Student.
5. Delete Student.
6. Exit Application.

### Project Architecture

```text
StudentManagement/
│
├── src/
│   ├── model/
│   │   └── Student.java
│   │
│   ├── util/
│   │   └── DBConnection.java
│   │
│   ├── dao/
│   │   ├── StudentDAO.java
│   │   └── StudentDAOImpl.java
│   │
│   └── main/
│       └── Main.java
│
└── pom.xml
```

Use the Model, DBConnection, DAO interface and implementation from Section 10.

### Main Menu Example

```java
package main;

import dao.StudentDAO;
import dao.StudentDAOImpl;
import model.Student;

import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        StudentDAO dao = new StudentDAOImpl();

        int choice;

        do {

            System.out.println("\nSTUDENT MANAGEMENT");

            System.out.println("1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Search Student");
            System.out.println("4. Update Student");
            System.out.println("5. Delete Student");
            System.out.println("0. Exit");

            System.out.print("Enter choice: ");

            choice = sc.nextInt();

            switch (choice) {

                case 1:

                    sc.nextLine();

                    System.out.print("Enter name: ");
                    String name = sc.nextLine();

                    System.out.print("Enter email: ");
                    String email = sc.nextLine();

                    System.out.print("Enter marks: ");
                    double marks = sc.nextDouble();

                    dao.addStudent(
                        new Student(name, email, marks)
                    );

                    break;

                case 2:

                    List<Student> students =
                        dao.getAllStudents();

                    for (Student s : students) {
                        System.out.println(s);
                    }

                    break;

                case 3:

                    System.out.print("Enter ID: ");

                    int id = sc.nextInt();

                    Student student =
                        dao.getStudentById(id);

                    if (student != null) {
                        System.out.println(student);
                    } else {
                        System.out.println(
                            "Student not found"
                        );
                    }

                    break;

                case 4:

                    System.out.print("Enter ID: ");
                    int updateId = sc.nextInt();

                    sc.nextLine();

                    System.out.print("Enter name: ");
                    String updateName = sc.nextLine();

                    System.out.print("Enter email: ");
                    String updateEmail = sc.nextLine();

                    System.out.print("Enter marks: ");
                    double updateMarks = sc.nextDouble();

                    dao.updateStudent(
                        new Student(
                            updateId,
                            updateName,
                            updateEmail,
                            updateMarks
                        )
                    );

                    break;

                case 5:

                    System.out.print("Enter ID: ");

                    int deleteId = sc.nextInt();

                    dao.deleteStudent(deleteId);

                    break;

                case 0:

                    System.out.println("Exiting...");

                    break;

                default:

                    System.out.println("Invalid choice");
            }

        } while (choice != 0);

        sc.close();
    }
}
```

**Note:** This console menu is a learning example. For a robust application, add input validation, check update/delete affected-row counts, and handle database exceptions consistently.

---

# 13. Interview Questions and Answers

### Q1. What is JDBC?

JDBC stands for Java Database Connectivity. It is a Java API used to communicate with relational databases.

### Q2. Which package contains JDBC interfaces?

The main JDBC API is in `java.sql`; additional functionality is in `javax.sql`.

### Q3. What is a JDBC driver?

A JDBC driver enables a Java application to communicate with a specific database.

### Q4. What are the four types of JDBC drivers?

Type 1: JDBC-ODBC Bridge, Type 2: Native API, Type 3: Network Protocol and Type 4: Thin Driver.

### Q5. Which JDBC driver does MySQL use?

MySQL Connector/J is a Type 4 driver.

### Q6. What is DriverManager?

A class that manages JDBC drivers and helps establish database connections.

### Q7. What is Connection?

An interface representing a connection to a database.

### Q8. What is Statement?

An interface used to execute SQL statements.

### Q9. What is PreparedStatement?

An interface used to execute parameterized SQL statements.

### Q10. What is ResultSet?

An interface representing rows returned by a query.

### Q11. What is the difference between executeQuery() and executeUpdate()?

`executeQuery()` returns a ResultSet. `executeUpdate()` returns an integer indicating affected rows or a DDL result.

### Q12. What is CallableStatement?

An interface used to invoke stored procedures and database functions.

### Q13. Why is PreparedStatement preferred?

It safely binds input values and helps prevent SQL injection.

### Q14. What is SQL injection?

A vulnerability where untrusted input manipulates SQL statements.

### Q15. How can SQL injection be prevented?

Use parameterized PreparedStatement queries, validate inputs and follow least-privilege database access.

### Q16. What is DatabaseMetaData?

It provides information about the database and JDBC driver.

### Q17. What is ResultSetMetaData?

It provides information about the columns in a ResultSet.

### Q18. What is DAO?

DAO stands for Data Access Object. It separates database access logic from business logic.

### Q19. What are CRUD operations?

Create, Read, Update and Delete.

### Q20. What is a transaction?

A transaction is a group of database operations treated as one logical unit.

### Q21. What are ACID properties?

Atomicity, Consistency, Isolation and Durability.

### Q22. What is auto-commit?

When enabled, JDBC commits each successful statement automatically.

### Q23. What is commit()?

It commits the current transaction.

### Q24. What is rollback()?

It cancels the current transaction's uncommitted changes.

### Q25. What is a Savepoint?

A marker inside a transaction that allows partial rollback.

### Q26. What is the difference between a procedure and a function?

A procedure is invoked as a database operation; a function returns a value and can be used in expressions.

### Q27. Can PreparedStatement prevent every type of SQL injection?

No. It protects parameterized values, but dynamic SQL identifiers and unsafe query construction still require careful handling.

### Q28. What is the difference between two-tier and three-tier architecture?

Two-tier connects the client directly to the database. Three-tier adds an intermediate business/application layer.

### Q29. What happens if a connection is not closed?

It can consume database resources and lead to connection leaks.

### Q30. What is try-with-resources?

A Java language feature that automatically closes resources implementing AutoCloseable, including JDBC connections, statements and result sets.

---

# 14. MCQs

**1. JDBC stands for:**

A. Java Database Connectivity  
B. Java Data Communication  
C. Java Database Compiler  
D. Java Driver Connectivity  

**Answer: A**

**2. Which package contains the main JDBC API?**

A. java.io  
B. java.sql  
C. java.net  
D. java.util  

**Answer: B**

**3. Which class helps establish a database connection?**

A. ResultSet  
B. DriverManager  
C. Statement  
D. SQLException  

**Answer: B**

**4. Which interface represents a database connection?**

A. Driver  
B. Connection  
C. ResultSet  
D. DatabaseMetaData  

**Answer: B**

**5. Which driver type is MySQL Connector/J?**

A. Type 1  
B. Type 2  
C. Type 3  
D. Type 4  

**Answer: D**

**6. Which interface is used for parameterized SQL queries?**

A. Statement  
B. PreparedStatement  
C. ResultSet  
D. Driver  

**Answer: B**

**7. Which method executes a SELECT query?**

A. executeUpdate()  
B. executeQuery()  
C. commit()  
D. rollback()  

**Answer: B**

**8. Which method is used for INSERT, UPDATE and DELETE?**

A. executeQuery()  
B. executeUpdate()  
C. next()  
D. getConnection()  

**Answer: B**

**9. Which interface is used to invoke stored procedures?**

A. Statement  
B. ResultSet  
C. CallableStatement  
D. Driver  

**Answer: C**

**10. Which method moves the ResultSet cursor to the next row?**

A. move()  
B. next()  
C. getNext()  
D. forward()  

**Answer: B**

**11. Which metadata interface provides database product information?**

A. ResultSetMetaData  
B. DatabaseMetaData  
C. ConnectionMetaData  
D. SQLMetaData  

**Answer: B**

**12. Which metadata interface provides column details?**

A. DatabaseMetaData  
B. ResultSetMetaData  
C. Driver  
D. Statement  

**Answer: B**

**13. Which JDBC interface helps prevent SQL injection through parameter binding?**

A. Statement  
B. PreparedStatement  
C. Driver  
D. ResultSet  

**Answer: B**

**14. DAO stands for:**

A. Data Application Object  
B. Database Access Operation  
C. Data Access Object  
D. Database Application Option  

**Answer: C**

**15. Which ACID property ensures all operations succeed or none are applied?**

A. Consistency  
B. Atomicity  
C. Isolation  
D. Durability  

**Answer: B**

**16. Which method commits a transaction?**

A. execute()  
B. commit()  
C. rollback()  
D. close()  

**Answer: B**

**17. Which method cancels uncommitted transaction changes?**

A. commit()  
B. executeQuery()  
C. rollback()  
D. next()  

**Answer: C**

**18. Which method disables automatic commits?**

A. setAutoCommit(false)  
B. setAutoCommit(true)  
C. commit(false)  
D. rollback(false)  

**Answer: A**

**19. What does try-with-resources do?**

A. Creates a database  
B. Automatically closes resources  
C. Creates SQL queries  
D. Commits every transaction  

**Answer: B**

**20. Which interface is used for a transaction savepoint?**

A. Driver  
B. Savepoint  
C. ResultSet  
D. Statement  

**Answer: B**

---

# 15. Quick Revision Notes

| Topic | Important Point |
|---|---|
| JDBC | Java Database Connectivity |
| JDBC API | `java.sql`, `javax.sql` |
| DriverManager | Establishes connections |
| Driver | Database communication component |
| Connection | Database connection |
| Statement | Static SQL execution |
| PreparedStatement | Parameterized SQL execution |
| CallableStatement | Stored procedure/function invocation |
| ResultSet | Query result rows |
| executeQuery() | Returns ResultSet |
| executeUpdate() | Returns affected-row count or DDL result |
| execute() | Executes general SQL |
| DatabaseMetaData | Database information |
| ResultSetMetaData | Query result column information |
| SQL Injection | Malicious SQL manipulation |
| DAO | Separates database access from business logic |
| Transaction | Logical group of operations |
| ACID | Atomicity, Consistency, Isolation, Durability |
| commit() | Saves transaction changes |
| rollback() | Cancels uncommitted changes |
| Savepoint | Partial rollback marker |
| Auto-commit | Commits each statement automatically |

## Important Differences

| Comparison | Difference |
|---|---|
| Statement vs PreparedStatement | Static SQL vs parameterized SQL |
| PreparedStatement vs CallableStatement | Parameterized SQL vs stored procedure invocation |
| executeQuery vs executeUpdate | ResultSet vs integer result |
| DatabaseMetaData vs ResultSetMetaData | Database details vs query column details |
| Procedure vs Function | Procedure operation vs value-returning function |
| commit vs rollback | Save changes vs undo uncommitted changes |
| Two-tier vs Three-tier | Direct database access vs intermediate application layer |
| JDBC vs DAO | Database API vs database-access design pattern |

## Practical Checklist

- [ ] Understand JDBC and its architecture.
- [ ] Learn the four JDBC driver types.
- [ ] Configure MySQL Connector/J.
- [ ] Establish a database connection using DriverManager.
- [ ] Understand Connection, Statement and PreparedStatement.
- [ ] Retrieve records using ResultSet.
- [ ] Implement INSERT operations.
- [ ] Implement SELECT operations.
- [ ] Implement UPDATE operations.
- [ ] Implement DELETE operations.
- [ ] Invoke stored procedures using CallableStatement.
- [ ] Invoke database functions.
- [ ] Retrieve DatabaseMetaData.
- [ ] Retrieve ResultSetMetaData.
- [ ] Understand and prevent SQL injection.
- [ ] Implement the DAO design pattern.
- [ ] Understand ACID properties.
- [ ] Implement commit() and rollback().
- [ ] Practise transaction management using a bank-transfer example.
- [ ] Understand savepoints and isolation levels.

## Additional Practice Assignments

1. Create an Employee Management System using JDBC CRUD.
2. Create a Library Management System with Book ID, Title, Author and Price.
3. Create a Banking System with deposit and withdrawal transactions.
4. Implement a stored procedure to search employees by department.
5. Implement a function to calculate employee bonus.
6. Display database and table metadata using JDBC.
7. Create a login application using PreparedStatement.
8. Implement a DAO-based Student Management System.
9. Demonstrate transaction rollback when one operation fails.
10. Use Savepoint to perform partial rollback.

---

**End of Sessions 29 & 30 – JDBC and Transaction Management**

*Prepared for CDAC CMCE / PGCP-AC August 2026 batch learning, practical assignments, interview preparation and revision. Examples use Java 17-compatible JDBC APIs and MySQL.*
