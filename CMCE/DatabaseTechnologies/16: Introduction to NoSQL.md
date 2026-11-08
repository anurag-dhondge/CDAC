# Session 16: Introduction to NoSQL and MongoDB

**Course:** PGCP-AC / CMCE – August 2026  
**Subject:** Database Technologies  
**Session:** 16  
**Topics:** NoSQL Databases, CAP Theorem, BASE Model, Types of NoSQL Databases, MongoDB, MongoDB Compass, Documents, Collections, JSON and BSON

---

## 1. Introduction to NoSQL

**NoSQL** stands for **Not Only SQL**.

NoSQL databases are non-relational databases designed to store, manage and retrieve data using flexible data models.

Unlike traditional relational databases, NoSQL databases do not always require a fixed table structure or predefined schema.

They are commonly used for applications that handle:

- Large amounts of data.
- Semi-structured and unstructured data.
- Frequently changing data structures.
- Distributed systems.
- Real-time applications.
- High-volume web applications.

### Why do we need NoSQL?

Traditional RDBMS databases store data in tables containing rows and columns.

However, modern applications generate different types of data, such as:

- Social media posts.
- Images and videos.
- Product information.
- User activity logs.
- IoT sensor data.
- Chat messages.
- Real-time application events.

A fixed relational structure may not always be the most convenient way to manage this data.

NoSQL databases provide flexible data models and different approaches to storing and processing data.

### Examples of NoSQL databases

| Database | Category |
|---|---|
| MongoDB | Document Store |
| Redis | Key-Value Store |
| Apache Cassandra | Wide-Column Store |
| Neo4j | Graph Database |
| Amazon DynamoDB | Key-Value / Document Database |

---

## 2. Features of NoSQL Databases

### 2.1 Flexible Schema

NoSQL databases generally allow records in the same collection to have different fields.

Example:

Document 1:

```json
{
  "name": "Rahul",
  "age": 22
}
```

Document 2:

```json
{
  "name": "Amit",
  "age": 23,
  "city": "Pune"
}
```

Both documents can exist in the same MongoDB collection.

### 2.2 Horizontal Scalability

Horizontal scaling means increasing system capacity by adding more servers or machines.

NoSQL databases are often designed to distribute data across multiple servers.

Example:

- Server 1 stores some customer records.
- Server 2 stores other customer records.
- Server 3 stores additional customer records.

This is useful when applications handle large amounts of data.

### 2.3 High Availability

Many NoSQL databases support replication and distributed architectures.

If one server fails, another replica may continue serving requests.

### 2.4 Distributed Architecture

Data can be distributed across multiple machines or locations.

This helps applications handle large workloads.

### 2.5 High Performance

Many NoSQL databases are optimized for particular access patterns, such as:

- Key-based lookups.
- Document retrieval.
- Graph traversal.
- Large-scale writes.

### 2.6 Flexible Data Models

Different NoSQL databases support different data models:

- Key-Value.
- Document.
- Wide-Column.
- Graph.

### 2.7 Handling Different Data Types

NoSQL databases can handle structured, semi-structured and unstructured data, depending on the database.

### Summary

| Feature | Description |
|---|---|
| Flexible Schema | Data structure can change |
| Horizontal Scaling | Add more servers |
| High Availability | Supports continued service during failures |
| Distributed Architecture | Data distributed across machines |
| Performance | Optimized for specific workloads |
| Flexible Data Models | Supports different storage models |
| Replication | Maintains multiple copies of data |

---

## 3. Types of Data

Data can be classified into three major categories:

1. Structured Data
2. Semi-Structured Data
3. Unstructured Data

### 3.1 Structured Data

Structured data follows a predefined format or schema.

It is generally stored in rows and columns.

Example: Employee table

| Emp_ID | Name | Salary |
|---:|---|---:|
| 1 | Rahul | 30000 |
| 2 | Amit | 40000 |
| 3 | Priya | 45000 |

Characteristics:

- Fixed structure.
- Predefined columns.
- Easy to query using SQL.
- Commonly stored in relational databases.

Examples:

- Employee records.
- Bank transactions.
- Student information.
- Product inventory tables.

### 3.2 Semi-Structured Data

Semi-structured data does not follow a rigid tabular structure but contains some organizational information.

It may use tags, keys or metadata.

Example: JSON

```json
{
  "student_id": 101,
  "name": "Rahul",
  "course": "PGCP-AC",
  "skills": ["Java", "Python", "MongoDB"]
}
```

Characteristics:

- Flexible structure.
- Uses keys and values.
- Fields can vary between records.
- Easier to represent nested data.

Examples:

- JSON.
- XML.
- YAML.
- Email metadata.

### 3.3 Unstructured Data

Unstructured data does not follow a predefined tabular or key-value structure.

Examples:

- Images.
- Videos.
- Audio files.
- PDF documents.
- Text documents.
- Social media media files.

Characteristics:

- No fixed table structure.
- Can contain large amounts of complex information.
- Often requires specialized processing and storage systems.

### Comparison

| Feature | Structured | Semi-Structured | Unstructured |
|---|---|---|---|
| Structure | Fixed | Flexible | No predefined structure |
| Schema | Predefined | Flexible or implicit | No rigid schema |
| Format | Tables | JSON, XML | Images, videos, audio |
| Example | Employee table | JSON document | Photograph |
| Common storage | RDBMS | MongoDB, document stores | Files, object storage |

**Remember:**

- Structured → Tables.
- Semi-structured → JSON / XML.
- Unstructured → Images / Videos / Audio.

---

## 4. RDBMS vs NoSQL Databases

### RDBMS

RDBMS stands for Relational Database Management System.

It stores data in tables consisting of rows and columns.

Examples:

- MySQL.
- PostgreSQL.
- Oracle Database.
- Microsoft SQL Server.

### NoSQL

NoSQL databases store data using non-relational models such as documents, key-value pairs, wide-column structures and graphs.

Examples:

- MongoDB.
- Redis.
- Cassandra.
- Neo4j.

### Comparison

| Feature | RDBMS | NoSQL |
|---|---|---|
| Data Model | Relational tables | Multiple data models |
| Schema | Generally predefined | Often flexible |
| Data Storage | Rows and columns | Documents, key-value, graphs, etc. |
| Relationships | Foreign keys and joins | Embedding, references or graph relationships |
| Scaling | Traditionally vertical | Often horizontal |
| Transactions | Strong ACID support | Depends on database; many support ACID |
| Query Language | SQL | Database-specific query interfaces |
| Data Structure | Usually structured | Structured, semi-structured or unstructured data |
| Examples | MySQL, Oracle | MongoDB, Redis, Neo4j |

### Important clarification

NoSQL does not mean that SQL or transactions are completely absent.

Some NoSQL databases support SQL-like query languages, and modern NoSQL databases can also support ACID transactions.

For example, MongoDB supports multi-document ACID transactions.

### When should we use RDBMS?

- Banking systems.
- Financial applications.
- Payroll systems.
- Applications with complex relationships.
- Applications requiring relational constraints.

### When should we use NoSQL?

- Social networking applications.
- Product catalogs.
- Real-time analytics.
- IoT applications.
- Applications with flexible data structures.
- Distributed systems handling large workloads.

---

## 5. CAP Theorem

The **CAP Theorem** is an important concept in distributed database systems.

It states that when a network partition occurs, a distributed system must choose between:

- Consistency (C)
- Availability (A)

The third property is Partition Tolerance (P).

### Three properties of CAP

### 5.1 Consistency (C)

Every successful read receives the most recent successfully written value, or an error.

Example:

Suppose a bank account balance is ₹50,000.

After withdrawing ₹10,000, the updated balance becomes ₹40,000.

All successful reads should reflect the latest committed value according to the system's consistency guarantee.

### 5.2 Availability (A)

Every request received by a non-failing node receives a response, even if that response may not contain the latest data.

Example:

A user should be able to access a shopping application even when some servers are unavailable.

### 5.3 Partition Tolerance (P)

The system continues operating despite communication failures between different nodes in a distributed system.

Example:

Suppose two database servers cannot communicate because of a network failure.

A partition-tolerant system is designed to handle this situation.

### CAP Theorem explanation

When a network partition happens, the system must choose between:

- Maintaining consistency by rejecting or delaying some requests.
- Maintaining availability by responding to requests, potentially with stale data.

In practical distributed systems, partition tolerance is generally necessary.

Therefore, during a partition, the trade-off is primarily between consistency and availability.

### CAP categories

| Category | Meaning |
|---|---|
| CP | Prioritizes Consistency and Partition Tolerance |
| AP | Prioritizes Availability and Partition Tolerance |
| CA | Consistency and Availability when there is no partition |

### CP System

A CP system prioritizes consistency during a network partition.

It may reject or delay some requests to avoid returning inconsistent data.

### AP System

An AP system prioritizes availability during a network partition.

It may return older data and reconcile differences later.

### CA System

A CA system provides consistency and availability when there is no network partition.

In a distributed environment, it cannot guarantee both during a partition.

**Important:** CAP is not a simple choice of permanently selecting two properties. The trade-off becomes important when a network partition occurs.

---

## 6. BASE Model

BASE is a database design approach commonly associated with highly available distributed systems.

BASE stands for:

- Basically Available.
- Soft State.
- Eventual Consistency.

It represents a different design philosophy from strict ACID transaction guarantees.

### 6.1 Basically Available

The system attempts to remain available even when some components fail.

Example:

An online shopping website remains accessible even if one database replica is unavailable.

### 6.2 Soft State

The system's state may change over time even without new user input because replicas and background processes synchronize data.

Example:

A customer's updated profile information may take some time to appear on every replica.

### 6.3 Eventual Consistency

If no new updates occur and the system continues synchronizing successfully, all replicas will eventually converge to the same value.

Example:

A social media post's like count may temporarily differ across servers but eventually become consistent.

### ACID vs BASE

| ACID | BASE |
|---|---|
| Atomicity | Basically Available |
| Consistency | Soft State |
| Isolation | Eventual Consistency |
| Durability | Focus on availability and eventual synchronization |

**Note:** ACID and BASE are different design approaches, not strict categories that every database must exclusively belong to. Modern databases may support both transactional guarantees and distributed availability features.

---

## 7. Categories of NoSQL Databases

NoSQL databases are divided into four major categories.

1. Key-Value Store.
2. Document Store.
3. Column-Oriented / Wide-Column Store.
4. Graph Database.

### 7.1 Key-Value Store

A Key-Value database stores data in the form of key-value pairs.

Each key uniquely identifies its associated value.

Example:

```text
Key: user:101
Value: Rahul

Key: user:102
Value: Amit

Key: user:103
Value: Priya
```

Representation:

```json
{
  "user:101": "Rahul",
  "user:102": "Amit",
  "user:103": "Priya"
}
```

Characteristics:

- Simple data model.
- Fast key-based retrieval.
- Useful for caching.
- Useful for session management.

Examples:

- Redis.
- Amazon DynamoDB (supports key-value and document models).
- Riak KV.

Real-world applications:

- Shopping cart storage.
- User sessions.
- Caching.
- Login authentication data.

### 7.2 Document Store

A Document Database stores data in document format.

Documents commonly use JSON-like structures.

Example:

```json
{
  "_id": 101,
  "name": "Rahul",
  "age": 22,
  "course": "PGCP-AC",
  "skills": ["Java", "Python", "MongoDB"]
}
```

Characteristics:

- Flexible schema.
- Supports nested documents.
- Supports arrays.
- Stores related information together.
- Suitable for rapidly changing application data.

Examples:

- MongoDB.
- CouchDB.
- Couchbase.

Real-world applications:

- E-commerce product catalogs.
- Content management systems.
- User profiles.
- Blog applications.

### 7.3 Column-Oriented / Wide-Column Store

A Wide-Column database stores data using rows and column families rather than traditional fixed relational tables.

It is designed for distributed data storage and large-scale workloads.

Example:

```text
Row Key: user101

Personal:
    name = Rahul
    age = 22

Education:
    course = PGCP-AC
    college = Pune
```

Characteristics:

- Distributed storage.
- Designed for large datasets.
- Efficient for certain large-scale read/write workloads.
- Supports flexible column structures depending on the database.

Examples:

- Apache Cassandra.
- Apache HBase.
- Google Cloud Bigtable.

Real-world applications:

- Time-series data.
- IoT sensor information.
- Large-scale event logs.
- Distributed analytics.

### 7.4 Graph Database

A Graph Database stores information using nodes, edges and properties.

- Node: Represents an entity.
- Edge: Represents a relationship.
- Property: Stores information about nodes or relationships.

Example:

```text
Rahul ----FRIEND_OF---- Amit
  |
  |
STUDIES_AT
  |
  |
Pune College
```

Characteristics:

- Relationship-focused data model.
- Efficient relationship traversal.
- Useful for connected data.
- Supports complex relationship queries.

Examples:

- Neo4j.
- Amazon Neptune.
- JanusGraph.

Real-world applications:

- Social networking.
- Recommendation systems.
- Fraud detection.
- Network analysis.
- Knowledge graphs.

### Comparison of NoSQL Categories

| Category | Data Model | Example Database | Common Use |
|---|---|---|---|
| Key-Value | Key and Value | Redis | Caching |
| Document | JSON-like Documents | MongoDB | Product catalogs |
| Wide-Column | Rows and Column Families | Cassandra | Large-scale data |
| Graph | Nodes and Edges | Neo4j | Social networks |

---

## 8. Introduction to MongoDB

**MongoDB** is a popular open-source, document-oriented NoSQL database.

It stores data in BSON documents instead of traditional relational tables.

MongoDB provides a flexible data model and supports scalable applications.

### Why MongoDB?

Consider an e-commerce application.

A product may contain:

- Product ID.
- Product Name.
- Price.
- Brand.
- Category.
- Specifications.
- Images.
- Reviews.

Different products may have different specifications.

MongoDB allows these details to be stored as flexible documents.

### Example MongoDB document

```json
{
  "_id": 101,
  "name": "Laptop",
  "brand": "Dell",
  "price": 55000,
  "specifications": {
    "ram": "16GB",
    "storage": "512GB SSD"
  },
  "features": ["Wi-Fi", "Bluetooth", "Webcam"]
}
```

This document stores simple values, nested documents and arrays together.

---

## 9. Features of MongoDB

### 9.1 Document-Oriented

MongoDB stores information in BSON documents.

### 9.2 Flexible Schema

Documents in the same collection can have different fields.

### 9.3 High Performance

MongoDB supports indexing and query optimization for efficient data retrieval.

### 9.4 Horizontal Scalability

MongoDB supports sharding to distribute data across multiple servers.

### 9.5 High Availability

MongoDB supports replica sets to maintain multiple copies of data.

### 9.6 Indexing

MongoDB supports different index types to improve query performance.

Examples:

- Single-field index.
- Compound index.
- Multikey index.
- Text index.
- Geospatial index.

### 9.7 Aggregation Framework

MongoDB provides an aggregation framework for data processing and analysis.

### 9.8 Flexible Documents

Documents can contain:

- Strings.
- Numbers.
- Boolean values.
- Arrays.
- Nested documents.
- Dates.
- ObjectIds.

### Summary

| Feature | Description |
|---|---|
| Document-oriented | Stores BSON documents |
| Flexible schema | Documents can have different fields |
| Indexing | Improves query performance |
| Sharding | Distributes data across servers |
| Replication | Maintains multiple data copies |
| Aggregation | Processes and analyzes data |
| Transactions | Supports ACID transactions |

---

## 10. MongoDB Architecture and Terminology

MongoDB uses a different terminology compared with relational databases.

### RDBMS vs MongoDB terminology

| RDBMS | MongoDB |
|---|---|
| Database | Database |
| Table | Collection |
| Row / Tuple / Record | Document |
| Column | Field |
| Primary Key | `_id` |
| JOIN | `$lookup` or application-side relationships |
| Index | Index |
| SQL | MongoDB Query API |

### Example

**RDBMS Table: Students**

| student_id | name | age |
|---:|---|---:|
| 1 | Rahul | 22 |
| 2 | Amit | 23 |

**MongoDB Collection: students**

Document 1:

```json
{
  "_id": 1,
  "name": "Rahul",
  "age": 22
}
```

Document 2:

```json
{
  "_id": 2,
  "name": "Amit",
  "age": 23
}
```

### Remember

- Database → Database.
- Table → Collection.
- Row → Document.
- Column → Field.
- Primary Key → `_id`.

---

## 11. MongoDB Documents and Collections

### 11.1 Document

A document is the basic unit of data in MongoDB.

It contains field-value pairs.

Example:

```json
{
  "_id": 101,
  "name": "Rahul",
  "age": 22,
  "city": "Pune"
}
```

Here:

- `_id` is the unique document identifier.
- `name` is a field.
- `age` is a field.
- `city` is a field.

A document can also contain nested documents and arrays.

### Nested document example

```json
{
  "_id": 101,
  "name": "Rahul",
  "address": {
    "city": "Pune",
    "state": "Maharashtra",
    "pincode": 411001
  }
}
```

### Array example

```json
{
  "_id": 102,
  "name": "Amit",
  "skills": ["Java", "Python", "MongoDB"]
}
```

### 11.2 Collection

A collection is a group of MongoDB documents.

It is similar to a table in an RDBMS.

Example:

**Collection Name:** students

```json
[
  {
    "_id": 1,
    "name": "Rahul",
    "age": 22
  },
  {
    "_id": 2,
    "name": "Amit",
    "age": 23
  },
  {
    "_id": 3,
    "name": "Priya",
    "age": 21
  }
]
```

All three documents belong to the `students` collection.

### Database structure

```text
MongoDB Server
      |
      |
   Database
      |
      |
  Collection
      |
      |
   Document
      |
      |
    Fields
```

---

## 12. JSON and BSON Documents

### 12.1 JSON

JSON stands for **JavaScript Object Notation**.

It is a lightweight text-based format used to represent and exchange data.

JSON is commonly used in:

- Web APIs.
- Frontend applications.
- Backend communication.
- Configuration files.
- Data exchange.

### Example JSON

```json
{
  "student_id": 101,
  "name": "Rahul",
  "age": 22,
  "is_active": true,
  "skills": ["Java", "Python", "MongoDB"]
}
```

### JSON data types

JSON supports:

1. String.
2. Number.
3. Boolean.
4. Array.
5. Object.
6. Null.

### 12.2 BSON

BSON stands for **Binary JSON**.

It is a binary-encoded serialization format used by MongoDB to store documents.

BSON extends JSON-like data representation with additional data types.

Examples of BSON-specific or extended types include:

- ObjectId.
- Date.
- Binary Data.
- Decimal128.
- Int32.
- Int64.
- Timestamp.

### Example MongoDB document

```javascript
{
    _id: ObjectId("507f1f77bcf86cd799439011"),
    name: "Rahul",
    age: NumberInt(22),
    salary: NumberDecimal("35000.50"),
    joining_date: ISODate("2026-08-01T00:00:00Z")
}
```

### JSON vs BSON

| Feature | JSON | BSON |
|---|---|---|
| Full Form | JavaScript Object Notation | Binary JSON |
| Format | Text-based | Binary-encoded |
| Human Readability | Easily readable | Not directly human-readable in raw binary form |
| Data Types | Basic JSON types | Additional types |
| Date | No native date type | Native date representation |
| ObjectId | No native type | Supported |
| Decimal128 | No native type | Supported |
| Usage | Data exchange | MongoDB storage and communication |

### Why does MongoDB use BSON?

1. Efficient serialization and deserialization.
2. Supports additional data types.
3. Stores documents in a binary representation.
4. Supports efficient data processing.
5. Provides type information within documents.

**Remember:** JSON is a text-based data format, whereas BSON is a binary-encoded format used by MongoDB.

---

## 13. MongoDB Command Interface

MongoDB provides a command-line interface called **MongoDB Shell (`mongosh`)**.

It allows users to interact with MongoDB using commands.

We can use it to:

- Create databases.
- Create collections.
- Insert documents.
- Retrieve documents.
- Update documents.
- Delete documents.
- Perform aggregation operations.

### Open MongoDB Shell

```bash
mongosh
```

Connect to a local MongoDB server:

```bash
mongosh "mongodb://localhost:27017"
```

### Basic MongoDB commands

#### 1. Display databases

```javascript
show dbs
```

#### 2. Create or switch database

```javascript
use college
```

MongoDB creates the database physically when data is first stored in it.

#### 3. Display current database

```javascript
db
```

#### 4. Display collections

```javascript
show collections
```

#### 5. Create a collection

```javascript
db.createCollection("students")
```

#### 6. Insert one document

```javascript
db.students.insertOne({
    name: "Rahul",
    age: 22,
    course: "PGCP-AC"
})
```

#### 7. Insert multiple documents

```javascript
db.students.insertMany([
    {
        name: "Amit",
        age: 23,
        course: "PGCP-AC"
    },
    {
        name: "Priya",
        age: 21,
        course: "PGCP-AC"
    }
])
```

#### 8. Display all documents

```javascript
db.students.find()
```

#### 9. Display formatted documents

```javascript
db.students.find().pretty()
```

#### 10. Find one document

```javascript
db.students.findOne({
    name: "Rahul"
})
```

#### 11. Count documents

```javascript
db.students.countDocuments()
```

#### 12. Drop a collection

```javascript
db.students.drop()
```

#### 13. Drop a database

```javascript
db.dropDatabase()
```

**Warning:** `drop()` and `dropDatabase()` permanently remove the selected data. Use them carefully.

---

## 14. MongoDB Compass

**MongoDB Compass** is the official graphical user interface (GUI) for MongoDB.

It allows users to work with MongoDB without writing every command manually.

### Features of MongoDB Compass

1. Visual database management.
2. Create and manage databases.
3. Create and manage collections.
4. Insert and edit documents.
5. Query documents.
6. Create indexes.
7. Build aggregation pipelines.
8. Analyze query performance.
9. View document structures.

### MongoDB Compass connection

For a local MongoDB server, use:

```text
mongodb://localhost:27017
```

### Steps to connect

1. Open MongoDB Compass.
2. Enter the connection string.
3. Click Connect.
4. View available databases.
5. Select a database.
6. Open a collection.
7. Insert, search, update or delete documents.

### MongoDB Shell vs MongoDB Compass

| Feature | MongoDB Shell | MongoDB Compass |
|---|---|---|
| Interface | Command Line | Graphical Interface |
| Interaction | Commands | Visual operations and query interface |
| Database Creation | Supported | Supported |
| Collection Management | Supported | Supported |
| CRUD Operations | Supported | Supported |
| Aggregation | Supported | Visual pipeline builder and commands |
| Best For | Developers and command practice | Visual database management |

### When to use which?

- MongoDB Shell → Practising commands and scripting.
- MongoDB Compass → Visualizing and managing documents.

---

## 15. RDBMS and MongoDB Analogy

Consider a student management system.

### RDBMS

Database: `college`

Table: `students`

| student_id | name | age | course |
|---:|---|---:|---|
| 1 | Rahul | 22 | PGCP-AC |
| 2 | Amit | 23 | PGCP-AC |

### MongoDB

Database: `college`

Collection: `students`

Document 1:

```json
{
  "_id": 1,
  "name": "Rahul",
  "age": 22,
  "course": "PGCP-AC"
}
```

Document 2:

```json
{
  "_id": 2,
  "name": "Amit",
  "age": 23,
  "course": "PGCP-AC"
}
```

### Terminology mapping

| RDBMS | MongoDB |
|---|---|
| Database | Database |
| Relation / Table | Collection |
| Tuple / Record | Document |
| Attribute / Column | Field |
| Primary Key | `_id` |
| Foreign Key | Reference (application-managed or DB-supported relationship pattern) |
| JOIN | `$lookup` |
| Index | Index |
| SQL Query | MongoDB Query |

**Important:** MongoDB does not enforce relational foreign-key constraints in the same way as MySQL. Relationships are commonly implemented using embedded documents or references.

---

## 16. MongoDB Data Types

MongoDB supports different BSON data types.

| Data Type | Example |
|---|---|
| String | `"Rahul"` |
| Double | `85.5` |
| Int32 | `NumberInt(22)` |
| Int64 | `NumberLong("123456789")` |
| Decimal128 | `NumberDecimal("25000.50")` |
| Boolean | `true` |
| Array | `["Java", "Python"]` |
| Object | `{city: "Pune"}` |
| ObjectId | `ObjectId()` |
| Date | `ISODate()` |
| Null | `null` |
| Binary | Binary data |

### Example

```javascript
db.students.insertOne({
    name: "Rahul",
    age: NumberInt(22),
    salary: NumberDecimal("35000.50"),
    is_active: true,
    skills: ["Java", "Python", "MongoDB"],
    address: {
        city: "Pune",
        state: "Maharashtra"
    },
    joining_date: ISODate("2026-08-01T00:00:00Z")
})
```

---

## 17. Practical: Create a Student Database in MongoDB

### Step 1: Start MongoDB Shell

```bash
mongosh
```

### Step 2: Create a database

```javascript
use college
```

### Step 3: Create a collection

```javascript
db.createCollection("students")
```

### Step 4: Insert one document

```javascript
db.students.insertOne({
    roll_no: 101,
    name: "Rahul",
    age: 22,
    course: "PGCP-AC",
    city: "Pune"
})
```

### Step 5: Insert multiple documents

```javascript
db.students.insertMany([
    {
        roll_no: 102,
        name: "Amit",
        age: 23,
        course: "PGCP-AC",
        city: "Mumbai"
    },
    {
        roll_no: 103,
        name: "Priya",
        age: 21,
        course: "PGCP-AC",
        city: "Pune"
    },
    {
        roll_no: 104,
        name: "Sneha",
        age: 22,
        course: "PGCP-BDA",
        city: "Pune"
    }
])
```

### Step 6: Display all students

```javascript
db.students.find()
```

### Step 7: Find a particular student

```javascript
db.students.findOne({
    roll_no: 101
})
```

### Step 8: Verify the collection

```javascript
show collections
```

### Step 9: Count students

```javascript
db.students.countDocuments()
```

---

## 18. Advantages and Limitations of NoSQL

### Advantages

1. Flexible data models.
2. Supports horizontal scalability.
3. Suitable for distributed applications.
4. Handles semi-structured data effectively.
5. Supports different storage models.
6. Can provide high availability.
7. Useful for large-scale applications.

### Limitations

1. Different databases have different query languages.
2. Data duplication may occur due to denormalization.
3. Complex relationships can be harder to manage in some NoSQL models.
4. Migration between different NoSQL databases may be difficult.
5. Consistency and transaction guarantees vary by database.
6. Flexible schemas require careful application-level validation.

---

## 19. Important Interview Questions and Answers

**Q1. What is NoSQL?**

NoSQL stands for Not Only SQL. It refers to non-relational databases that support different data models such as key-value, document, wide-column and graph.

**Q2. Why do we use NoSQL databases?**

We use NoSQL databases for flexible data structures, distributed storage, horizontal scalability and applications handling large or rapidly changing datasets.

**Q3. What are the main features of NoSQL?**

Flexible schema, horizontal scalability, distributed architecture, replication and support for different data models.

**Q4. What is structured data?**

Structured data follows a predefined schema and is generally stored in rows and columns.

**Q5. What is semi-structured data?**

Semi-structured data does not follow a rigid table structure but uses keys, tags or metadata. JSON and XML are examples.

**Q6. What is unstructured data?**

Unstructured data does not have a predefined tabular structure. Images, videos and audio files are examples.

**Q7. What is the difference between RDBMS and NoSQL?**

RDBMS stores data in relational tables, while NoSQL supports different data models such as documents, key-value pairs, wide-column structures and graphs.

**Q8. What is CAP Theorem?**

CAP Theorem explains the trade-off between Consistency and Availability when a network partition occurs in a distributed system. Partition Tolerance is the third property.

**Q9. What is Consistency?**

Consistency means successful reads return the latest successfully written value according to the system's consistency guarantees.

**Q10. What is Availability?**

Availability means every request to a non-failing node receives a response, even if the response may contain stale data.

**Q11. What is Partition Tolerance?**

Partition Tolerance means a distributed system can continue operating despite communication failures between nodes.

**Q12. What is the BASE model?**

BASE stands for Basically Available, Soft State and Eventual Consistency.

**Q13. What are the four categories of NoSQL databases?**

Key-Value, Document, Wide-Column and Graph databases.

**Q14. What is a Key-Value database?**

It stores data as key-value pairs, where each key identifies its associated value.

**Q15. What is a Document Database?**

It stores data in document formats such as JSON-like documents. MongoDB is an example.

**Q16. What is a Wide-Column Database?**

It stores data using rows and flexible column families. Cassandra and HBase are examples.

**Q17. What is a Graph Database?**

It stores data using nodes, edges and properties. Neo4j is an example.

**Q18. What is MongoDB?**

MongoDB is a document-oriented NoSQL database that stores data as BSON documents.

**Q19. What is BSON?**

BSON stands for Binary JSON. It is a binary-encoded serialization format used by MongoDB.

**Q20. What is JSON?**

JSON stands for JavaScript Object Notation. It is a lightweight text-based data interchange format.

**Q21. What is the difference between JSON and BSON?**

JSON is text-based, whereas BSON is binary-encoded and supports additional data types such as ObjectId and Date.

**Q22. What is a MongoDB document?**

A document is the basic unit of data in MongoDB. It stores field-value pairs.

**Q23. What is a collection?**

A collection is a group of MongoDB documents. It is similar to a table in an RDBMS.

**Q24. What is `_id` in MongoDB?**

`_id` is the unique identifier of a document. MongoDB automatically generates an ObjectId if one is not provided.

**Q25. What is MongoDB Compass?**

MongoDB Compass is a graphical user interface used to manage MongoDB databases and documents.

**Q26. What is MongoDB Shell?**

MongoDB Shell, also called mongosh, is a command-line interface used to interact with MongoDB.

**Q27. What is horizontal scaling?**

Horizontal scaling means increasing system capacity by adding more machines or servers.

**Q28. What is sharding?**

Sharding is a method of distributing data across multiple servers.

**Q29. What is replication?**

Replication maintains multiple copies of data across database servers to support availability and fault tolerance.

**Q30. Does MongoDB support transactions?**

Yes. MongoDB supports ACID transactions, including multi-document transactions.

---

## 20. Quick Revision Notes

| Topic | Important Point |
|---|---|
| NoSQL | Not Only SQL |
| Structured Data | Fixed schema |
| Semi-Structured Data | Flexible structure, such as JSON |
| Unstructured Data | Images, videos and audio |
| RDBMS | Relational tables |
| CAP | Consistency, Availability, Partition Tolerance |
| BASE | Basically Available, Soft State, Eventual Consistency |
| Key-Value | Stores key-value pairs |
| Document Store | Stores JSON-like documents |
| Wide-Column | Stores rows and column families |
| Graph | Stores nodes and edges |
| MongoDB | Document-oriented NoSQL database |
| MongoDB Shell | Command-line interface |
| MongoDB Compass | Graphical interface |
| Collection | Group of documents |
| Document | Group of field-value pairs |
| BSON | Binary JSON |
| JSON | JavaScript Object Notation |
| `_id` | Unique document identifier |
| Sharding | Distributes data across servers |
| Replication | Maintains multiple copies of data |

### Important points to remember

- NoSQL means Not Only SQL.
- NoSQL databases support different data models.
- MongoDB is a document-oriented database.
- MongoDB stores BSON documents.
- A collection is similar to a relational table.
- A document is similar to a relational row.
- A field is similar to a relational column.
- `_id` uniquely identifies a MongoDB document.
- MongoDB supports nested documents and arrays.
- MongoDB Compass is a GUI.
- `mongosh` is a command-line interface.
- CAP trade-offs matter during network partitions.
- BASE stands for Basically Available, Soft State and Eventual Consistency.

---

## 21. Practical Preparation Checklist

- [ ] Understand the features of NoSQL databases.
- [ ] Differentiate structured, semi-structured and unstructured data.
- [ ] Compare RDBMS and NoSQL.
- [ ] Understand CAP Theorem.
- [ ] Understand the BASE model.
- [ ] Study all four NoSQL database categories.
- [ ] Understand MongoDB architecture.
- [ ] Install or access MongoDB Server.
- [ ] Connect using MongoDB Shell.
- [ ] Connect using MongoDB Compass.
- [ ] Create a database.
- [ ] Create a collection.
- [ ] Insert documents.
- [ ] Retrieve documents.
- [ ] Understand nested documents and arrays.
- [ ] Study JSON and BSON differences.
- [ ] Understand RDBMS and MongoDB terminology mapping.

---

## 22. Useful MongoDB Commands

```javascript
// Display databases
show dbs

// Create or switch database
use college

// Display current database
db

// Create collection
db.createCollection("students")

// Display collections
show collections

// Insert one document
db.students.insertOne({
    name: "Rahul",
    age: 22
})

// Insert multiple documents
db.students.insertMany([
    {name: "Amit", age: 23},
    {name: "Priya", age: 21}
])

// Display all documents
db.students.find()

// Find one document
db.students.findOne({name: "Rahul"})

// Count documents
db.students.countDocuments()

// Drop collection
db.students.drop()

// Drop database
db.dropDatabase()
```

---

**End of Session 16 – Introduction to NoSQL**

**Topics covered:** NoSQL Features, Structured and Unstructured Data, RDBMS vs NoSQL, CAP Theorem, BASE Model, Key-Value Store, Document Store, Wide-Column Store, Graph Database, MongoDB, MongoDB Compass, Collections, Documents, JSON and BSON.
