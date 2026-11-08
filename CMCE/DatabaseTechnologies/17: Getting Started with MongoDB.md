# Session 17: Getting Started with MongoDB

**Course:** PGCP-AC / CMCE – August 2026  
**Subject:** Database Technologies  
**Session:** 17  
**Topics:** CRUD Operations, UPSERT, Query Operators, Update Operators, Projection, Sorting, Pagination, Indexes and Aggregation Pipeline

---

## 1. Introduction to MongoDB CRUD Operations

CRUD stands for:

- **C – Create:** Insert new documents.
- **R – Read:** Retrieve documents.
- **U – Update:** Modify existing documents.
- **D – Delete:** Remove documents.

MongoDB provides different methods to perform CRUD operations on collections.

| Operation | MongoDB Methods |
|---|---|
| Create | `insertOne()`, `insertMany()` |
| Read | `find()`, `findOne()` |
| Update | `updateOne()`, `updateMany()`, `replaceOne()` |
| Delete | `deleteOne()`, `deleteMany()` |

### Basic syntax

```javascript
// CREATE
db.collection.insertOne({ name: "Rahul" })

// READ
db.collection.find()

// UPDATE
db.collection.updateOne(
    { name: "Rahul" },
    { $set: { age: 22 } }
)

// DELETE
db.collection.deleteOne({ name: "Rahul" })
```

---

## 2. Creating a Database and Collection

Before performing CRUD operations, we need a database and a collection.

### Step 1: Open MongoDB Shell

```bash
mongosh
```

Connect to a local MongoDB server:

```bash
mongosh "mongodb://localhost:27017"
```

### Step 2: Create or switch database

```javascript
use college
```

MongoDB switches to the `college` database. The database is physically created when data is first stored or a collection is created.

### Step 3: Create collection

```javascript
db.createCollection("students")
```

### Step 4: Display collections

```javascript
show collections
```

### Step 5: Display databases

```javascript
show dbs
```

**Note:** An empty database may not appear in `show dbs` until it contains data.

---

## 3. Sample Collection for Practical Sessions

We will use a `students` collection throughout this session.

```javascript
use college
```

Insert sample documents:

```javascript
db.students.insertMany([
    {
        roll_no: 101,
        name: "Rahul",
        age: 22,
        city: "Pune",
        course: "PGCP-AC",
        marks: 85,
        fees: 75000,
        skills: ["Java", "Python", "MongoDB"],
        active: true
    },
    {
        roll_no: 102,
        name: "Amit",
        age: 23,
        city: "Mumbai",
        course: "PGCP-AC",
        marks: 72,
        fees: 75000,
        skills: ["C++", "Java"],
        active: true
    },
    {
        roll_no: 103,
        name: "Priya",
        age: 21,
        city: "Pune",
        course: "PGCP-BDA",
        marks: 90,
        fees: 80000,
        skills: ["Python", "SQL"],
        active: true
    },
    {
        roll_no: 104,
        name: "Sneha",
        age: 22,
        city: "Nashik",
        course: "PGCP-AC",
        marks: 65,
        fees: 75000,
        skills: ["JavaScript", "React"],
        active: false
    },
    {
        roll_no: 105,
        name: "Rohan",
        age: 24,
        city: "Pune",
        course: "PGCP-BDA",
        marks: 55,
        fees: 80000,
        skills: ["Python", "MongoDB"],
        active: true
    }
])
```

Display all records:

```javascript
db.students.find()
```

Format the output:

```javascript
db.students.find().pretty()
```

---

# 4. CREATE Operations

CREATE operations are used to insert new documents into a collection.

MongoDB provides two important methods:

1. `insertOne()`
2. `insertMany()`

## 4.1 insertOne()

The `insertOne()` method inserts a single document into a collection.

### Syntax

```javascript
db.collection.insertOne(
    { field1: value1, field2: value2 }
)
```

### Example

```javascript
db.students.insertOne({
    roll_no: 106,
    name: "Karan",
    age: 23,
    city: "Pune",
    course: "PGCP-AC",
    marks: 78,
    fees: 75000,
    active: true
})
```

### Output

MongoDB returns an acknowledgement and the inserted document's ID.

```javascript
{
    acknowledged: true,
    insertedId: ObjectId("...")
}
```

### Verify

```javascript
db.students.find({ roll_no: 106 })
```

## 4.2 insertMany()

The `insertMany()` method inserts multiple documents into a collection.

### Syntax

```javascript
db.collection.insertMany([
    { field1: value1 },
    { field1: value2 }
])
```

### Example

```javascript
db.students.insertMany([
    {
        roll_no: 107,
        name: "Pooja",
        age: 21,
        city: "Mumbai",
        course: "PGCP-AC",
        marks: 88
    },
    {
        roll_no: 108,
        name: "Sagar",
        age: 22,
        city: "Pune",
        course: "PGCP-BDA",
        marks: 76
    }
])
```

### Verify

```javascript
db.students.find()
```

### insertOne vs insertMany

| Feature | insertOne() | insertMany() |
|---|---|---|
| Documents | One | Multiple |
| Input | Single document | Array of documents |
| Use | Insert one record | Insert multiple records |
| Return | Inserted ID | Inserted IDs |

---

# 5. READ Operations

READ operations are used to retrieve documents from a collection.

MongoDB provides:

1. `find()`
2. `findOne()`

## 5.1 find()

The `find()` method retrieves all documents or documents matching a specified filter.

### Syntax

```javascript
db.collection.find()
```

### Example: Display all students

```javascript
db.students.find()
```

### Find students from Pune

```javascript
db.students.find({
    city: "Pune"
})
```

### Find students studying PGCP-AC

```javascript
db.students.find({
    course: "PGCP-AC"
})
```

## 5.2 findOne()

The `findOne()` method returns the first matching document.

### Syntax

```javascript
db.collection.findOne(
    { field: value }
)
```

### Example

```javascript
db.students.findOne({
    roll_no: 101
})
```

### Find a student by name

```javascript
db.students.findOne({
    name: "Rahul"
})
```

### find() vs findOne()

| Feature | find() | findOne() |
|---|---|---|
| Result | Cursor containing matching documents | One matching document |
| Multiple Records | Yes | No |
| No Filter | Returns all documents | Returns one document |
| Use | Retrieve multiple records | Retrieve a single record |

**Important:** `find()` returns a cursor, which can be further modified using methods such as `sort()`, `skip()` and `limit()`.

---

# 6. QUERY OPERATORS

Query operators are used to retrieve documents based on specific conditions.

MongoDB provides two major categories:

1. Comparison Operators.
2. Logical Operators.

## 6.1 Comparison Operators

Comparison operators compare field values.

| Operator | Meaning |
|---|---|
| `$eq` | Equal to |
| `$gt` | Greater than |
| `$lt` | Less than |
| `$gte` | Greater than or equal to |
| `$lte` | Less than or equal to |
| `$ne` | Not equal to |
| `$in` | Matches any value in an array |
| `$nin` | Does not match any value in an array |

### 1. $eq – Equal To

Find students whose city is Pune.

```javascript
db.students.find({
    city: { $eq: "Pune" }
})
```

Equivalent query:

```javascript
db.students.find({
    city: "Pune"
})
```

### 2. $gt – Greater Than

Find students whose marks are greater than 75.

```javascript
db.students.find({
    marks: { $gt: 75 }
})
```

### 3. $lt – Less Than

Find students whose marks are less than 70.

```javascript
db.students.find({
    marks: { $lt: 70 }
})
```

### 4. $gte – Greater Than or Equal To

Find students whose age is greater than or equal to 22.

```javascript
db.students.find({
    age: { $gte: 22 }
})
```

### 5. $lte – Less Than or Equal To

Find students whose marks are less than or equal to 75.

```javascript
db.students.find({
    marks: { $lte: 75 }
})
```

### 6. $ne – Not Equal To

Find students who are not from Pune.

```javascript
db.students.find({
    city: { $ne: "Pune" }
})
```

### 7. $in – Matches Any Value

Find students from Pune or Mumbai.

```javascript
db.students.find({
    city: {
        $in: ["Pune", "Mumbai"]
    }
})
```

### 8. $nin – Does Not Match Any Value

Find students who are neither from Pune nor Mumbai.

```javascript
db.students.find({
    city: {
        $nin: ["Pune", "Mumbai"]
    }
})
```

### Comparison operator summary

| Operator | Example | Meaning |
|---|---|---|
| `$eq` | `{marks: {$eq: 85}}` | Marks equal to 85 |
| `$gt` | `{marks: {$gt: 75}}` | Marks greater than 75 |
| `$lt` | `{marks: {$lt: 75}}` | Marks less than 75 |
| `$gte` | `{age: {$gte: 22}}` | Age at least 22 |
| `$lte` | `{age: {$lte: 22}}` | Age at most 22 |
| `$ne` | `{city: {$ne: "Pune"}}` | City not Pune |
| `$in` | `{city: {$in: ["Pune","Mumbai"]}}` | City matches either |
| `$nin` | `{city: {$nin: ["Pune","Mumbai"]}}` | City matches neither |

---

## 6.2 Logical Operators

Logical operators combine multiple conditions.

| Operator | Meaning |
|---|---|
| `$and` | All conditions must be true |
| `$or` | At least one condition must be true |
| `$not` | Negates a condition |
| `$nor` | None of the conditions should be true |

### 1. $and

Find students whose marks are greater than 70 AND age is greater than 21.

```javascript
db.students.find({
    $and: [
        { marks: { $gt: 70 } },
        { age: { $gt: 21 } }
    ]
})
```

MongoDB also supports implicit AND.

```javascript
db.students.find({
    marks: { $gt: 70 },
    age: { $gt: 21 }
})
```

Both queries represent the same logical condition.

### 2. $or

Find students who belong to Pune OR Mumbai.

```javascript
db.students.find({
    $or: [
        { city: "Pune" },
        { city: "Mumbai" }
    ]
})
```

### 3. $not

Find students whose marks are NOT greater than 75.

```javascript
db.students.find({
    marks: {
        $not: { $gt: 75 }
    }
})
```

**Note:** `$not` is generally used with field-level operators. It can also match documents where the field is missing, so it is not always identical to a simple numeric comparison.

### 4. $nor

Find students who are neither from Pune nor Mumbai.

```javascript
db.students.find({
    $nor: [
        { city: "Pune" },
        { city: "Mumbai" }
    ]
})
```

### Logical operator examples

| Operator | Example | Meaning |
|---|---|---|
| `$and` | Marks > 70 AND age > 21 | Both conditions true |
| `$or` | City Pune OR Mumbai | Any condition true |
| `$not` | Marks NOT greater than 75 | Negates field condition |
| `$nor` | Neither Pune nor Mumbai | All listed conditions false |

---

## 7. Complex Read Queries

We can combine comparison and logical operators to create complex queries.

### Example 1: Students with marks above 70 and age above 21

```javascript
db.students.find({
    $and: [
        { marks: { $gt: 70 } },
        { age: { $gt: 21 } }
    ]
})
```

### Example 2: Students from Pune or Mumbai with marks above 70

```javascript
db.students.find({
    $and: [
        {
            city: {
                $in: ["Pune", "Mumbai"]
            }
        },
        {
            marks: {
                $gt: 70
            }
        }
    ]
})
```

### Example 3: Students enrolled in PGCP-AC or PGCP-BDA

```javascript
db.students.find({
    course: {
        $in: ["PGCP-AC", "PGCP-BDA"]
    }
})
```

### Example 4: Students with marks between 60 and 90

```javascript
db.students.find({
    marks: {
        $gte: 60,
        $lte: 90
    }
})
```

### Example 5: Active students with marks above 80

```javascript
db.students.find({
    active: true,
    marks: {
        $gt: 80
    }
})
```

---

# 8. UPDATE Operations

UPDATE operations modify existing documents.

MongoDB provides:

1. `updateOne()`
2. `updateMany()`
3. `replaceOne()`

## 8.1 updateOne()

The `updateOne()` method updates the first document matching the filter.

### Syntax

```javascript
db.collection.updateOne(
    { filter },
    { update_operator: { field: value } }
)
```

### Example: Update one student's city

```javascript
db.students.updateOne(
    { roll_no: 101 },
    {
        $set: {
            city: "Mumbai"
        }
    }
)
```

### Verify

```javascript
db.students.findOne({
    roll_no: 101
})
```

### Update marks

```javascript
db.students.updateOne(
    { roll_no: 102 },
    {
        $set: {
            marks: 80
        }
    }
)
```

## 8.2 updateMany()

The `updateMany()` method updates all documents matching the filter.

### Example: Increase marks by 5

```javascript
db.students.updateMany(
    { course: "PGCP-AC" },
    {
        $inc: {
            marks: 5
        }
    }
)
```

This increases the marks of every student enrolled in PGCP-AC by 5.

### Example: Set active status

```javascript
db.students.updateMany(
    { city: "Pune" },
    {
        $set: {
            active: true
        }
    }
)
```

## 8.3 replaceOne()

The `replaceOne()` method replaces the entire existing document, except for its `_id` value.

### Syntax

```javascript
db.collection.replaceOne(
    { filter },
    { replacement_document }
)
```

### Example

```javascript
db.students.replaceOne(
    { roll_no: 101 },
    {
        roll_no: 101,
        name: "Rahul",
        age: 23,
        city: "Pune",
        course: "PGCP-AC",
        marks: 90
    }
)
```

Fields not included in the replacement document are removed.

**Important:** `replaceOne()` is different from `$set`. `$set` modifies selected fields, whereas `replaceOne()` replaces the document's contents.

### Comparison

| Method | Purpose |
|---|---|
| `updateOne()` | Updates one matching document |
| `updateMany()` | Updates all matching documents |
| `replaceOne()` | Replaces one matching document |

---

# 9. UPSERT Operation

**UPSERT = UPDATE + INSERT**

Upsert means:

- If the matching document exists → Update it.
- If the matching document does not exist → Insert a new document.

MongoDB provides the `upsert: true` option.

### Syntax

```javascript
db.collection.updateOne(
    { filter },
    { $set: { field: value } },
    { upsert: true }
)
```

### Example 1: Existing document

```javascript
db.students.updateOne(
    { roll_no: 101 },
    {
        $set: {
            city: "Pune"
        }
    },
    {
        upsert: true
    }
)
```

If roll number 101 exists, its city is updated.

### Example 2: Non-existing document

```javascript
db.students.updateOne(
    { roll_no: 109 },
    {
        $set: {
            name: "Kiran",
            age: 22,
            city: "Pune",
            course: "PGCP-AC",
            marks: 75
        }
    },
    {
        upsert: true
    }
)
```

If roll number 109 does not exist, MongoDB inserts a new document.

### Verify

```javascript
db.students.find({
    roll_no: 109
})
```

### UPSERT with $setOnInsert

`$setOnInsert` sets fields only when a new document is inserted through an upsert operation.

```javascript
db.students.updateOne(
    { roll_no: 110 },
    {
        $set: {
            city: "Pune"
        },
        $setOnInsert: {
            name: "Meera",
            age: 21,
            course: "PGCP-BDA"
        }
    },
    {
        upsert: true
    }
)
```

### Important points

- `upsert` is false by default.
- `upsert: true` enables insertion when no matching document exists.
- It is supported by methods such as `updateOne()`, `updateMany()` and `replaceOne()`.
- `$setOnInsert` applies only when an upsert inserts a new document.

---

# 10. DELETE Operations

DELETE operations remove documents from a collection.

MongoDB provides:

1. `deleteOne()`
2. `deleteMany()`

## 10.1 deleteOne()

Deletes the first document matching the filter.

### Syntax

```javascript
db.collection.deleteOne({
    field: value
})
```

### Example

```javascript
db.students.deleteOne({
    roll_no: 108
})
```

Verify:

```javascript
db.students.find({
    roll_no: 108
})
```

## 10.2 deleteMany()

Deletes all documents matching the specified filter.

### Example: Delete inactive students

```javascript
db.students.deleteMany({
    active: false
})
```

### Example: Delete students with marks below 40

```javascript
db.students.deleteMany({
    marks: {
        $lt: 40
    }
})
```

### Delete all documents

```javascript
db.students.deleteMany({})
```

**Warning:** An empty filter `{}` matches all documents. Therefore, `deleteMany({})` removes every document from the collection.

### deleteOne vs deleteMany

| Feature | deleteOne() | deleteMany() |
|---|---|---|
| Documents deleted | One matching document | All matching documents |
| Filter | Required for selective deletion | Required for selective deletion |
| Use | Delete one record | Delete multiple records |

---

# 11. UPDATE OPERATORS

Update operators are used to modify document fields without replacing the entire document.

Important operators:

- `$set`
- `$unset`
- `$inc`
- `$push`
- `$pull`
- `$addToSet`

## 11.1 $set

The `$set` operator creates or updates a field.

### Syntax

```javascript
{
    $set: {
        field: value
    }
}
```

### Example

```javascript
db.students.updateOne(
    { roll_no: 101 },
    {
        $set: {
            city: "Mumbai",
            active: true
        }
    }
)
```

If the field exists, its value is updated. Otherwise, a new field is created.

## 11.2 $unset

The `$unset` operator removes a field from a document.

### Syntax

```javascript
{
    $unset: {
        field: ""
    }
}
```

### Example

```javascript
db.students.updateOne(
    { roll_no: 101 },
    {
        $unset: {
            fees: ""
        }
    }
)
```

The `fees` field is removed from the matching document.

## 11.3 $inc

The `$inc` operator increments or decrements a numeric field.

### Syntax

```javascript
{
    $inc: {
        field: value
    }
}
```

### Example: Increase marks by 5

```javascript
db.students.updateOne(
    { roll_no: 101 },
    {
        $inc: {
            marks: 5
        }
    }
)
```

### Example: Decrease marks by 2

```javascript
db.students.updateOne(
    { roll_no: 101 },
    {
        $inc: {
            marks: -2
        }
    }
)
```

## 11.4 $push

The `$push` operator adds an element to an array.

It allows duplicate values.

### Example

```javascript
db.students.updateOne(
    { roll_no: 101 },
    {
        $push: {
            skills: "React"
        }
    }
)
```

Before:

```json
{
    "skills": ["Java", "Python", "MongoDB"]
}
```

After:

```json
{
    "skills": ["Java", "Python", "MongoDB", "React"]
}
```

## 11.5 $pull

The `$pull` operator removes all array elements matching a specified condition.

### Example

```javascript
db.students.updateOne(
    { roll_no: 101 },
    {
        $pull: {
            skills: "Java"
        }
    }
)
```

The value `"Java"` is removed from the skills array.

## 11.6 $addToSet

The `$addToSet` operator adds an element to an array only if it does not already exist.

It prevents duplicate values.

### Example

```javascript
db.students.updateOne(
    { roll_no: 101 },
    {
        $addToSet: {
            skills: "Python"
        }
    }
)
```

If Python already exists in the array, MongoDB does not add it again.

### Update operator comparison

| Operator | Purpose |
|---|---|
| `$set` | Add or modify a field |
| `$unset` | Remove a field |
| `$inc` | Increase or decrease a numeric value |
| `$push` | Add an element to an array |
| `$pull` | Remove matching elements from an array |
| `$addToSet` | Add an array element only if it is not already present |

### $push vs $addToSet

| $push | $addToSet |
|---|---|
| Allows duplicates | Prevents duplicate values |
| Always adds the supplied element | Adds only if the value is not already present |
| Used for normal array insertion | Used for unique array values |

---

# 12. PROJECTION IN MONGODB

Projection means selecting specific fields from documents.

It helps retrieve only the required information instead of displaying every field.

MongoDB supports projection using the second argument of `find()`.

### Syntax

```javascript
db.collection.find(
    { filter },
    { field: 1, another_field: 0 }
)
```

### 12.1 Include Specific Fields

Find only student name and city.

```javascript
db.students.find(
    {},
    {
        name: 1,
        city: 1
    }
)
```

Here:

- `1` means include the field.
- Other fields are excluded.

By default, `_id` is included.

### Exclude _id

```javascript
db.students.find(
    {},
    {
        name: 1,
        city: 1,
        _id: 0
    }
)
```

### 12.2 Exclude Specific Fields

Display all fields except fees.

```javascript
db.students.find(
    {},
    {
        fees: 0
    }
)
```

### Important projection rule

You generally cannot mix inclusion and exclusion in the same projection, except for excluding `_id`.

Valid:

```javascript
db.students.find(
    {},
    {
        name: 1,
        city: 1,
        _id: 0
    }
)
```

Invalid:

```javascript
db.students.find(
    {},
    {
        name: 1,
        city: 0
    }
)
```

### Projection summary

| Value | Meaning |
|---|---|
| `1` | Include field |
| `0` | Exclude field |
| `_id: 0` | Exclude document ID |

---

# 13. SORTING IN MONGODB

Sorting arranges documents in ascending or descending order.

MongoDB provides the `sort()` method.

### Syntax

```javascript
db.collection.find().sort({
    field: 1
})
```

- `1` → Ascending order.
- `-1` → Descending order.

## 13.1 Ascending Order

Find students ordered by marks from lowest to highest.

```javascript
db.students.find().sort({
    marks: 1
})
```

## 13.2 Descending Order

Find students ordered by marks from highest to lowest.

```javascript
db.students.find().sort({
    marks: -1
})
```

## 13.3 Sorting by Multiple Fields

First sort by city in ascending order and then by marks in descending order.

```javascript
db.students.find().sort({
    city: 1,
    marks: -1
})
```

MongoDB uses the second sort field when documents have equal values for the first sort field.

### Sorting summary

| Value | Sorting |
|---|---|
| `1` | Ascending |
| `-1` | Descending |

**Tip:** Add a unique field such as `_id` as a final sort key when deterministic ordering is important.

---

# 14. PAGINATION USING skip() AND limit()

Pagination means dividing a large result set into smaller pages.

It is commonly used in:

- Websites.
- E-commerce applications.
- Student management systems.
- Admin dashboards.
- Search result pages.

MongoDB provides:

- `skip()`
- `limit()`

## 14.1 limit()

The `limit()` method restricts the number of documents returned.

### Syntax

```javascript
db.collection.find().limit(number)
```

### Example

Display only the first three students.

```javascript
db.students.find().limit(3)
```

## 14.2 skip()

The `skip()` method skips a specified number of documents.

### Syntax

```javascript
db.collection.find().skip(number)
```

### Example

Skip the first two students.

```javascript
db.students.find().skip(2)
```

## 14.3 Pagination Example

Suppose each page should contain three students.

Formula:

\[
skip = (pageNumber - 1) \times pageSize
\]

Where:

- `pageNumber` = Current page.
- `pageSize` = Number of documents per page.

### Page 1

```javascript
db.students.find()
    .sort({ roll_no: 1 })
    .skip(0)
    .limit(3)
```

### Page 2

```javascript
db.students.find()
    .sort({ roll_no: 1 })
    .skip(3)
    .limit(3)
```

### Page 3

```javascript
db.students.find()
    .sort({ roll_no: 1 })
    .skip(6)
    .limit(3)
```

### Pagination summary

| Method | Purpose |
|---|---|
| `skip()` | Skips documents |
| `limit()` | Restricts returned documents |
| `sort()` | Arranges document order |

**Important:** Use a stable sort when implementing pagination. Large `skip()` values can become inefficient; range-based pagination is often preferable for very large datasets.

---

# 15. INDEXES IN MONGODB

An **Index** is a data structure that helps MongoDB find documents more efficiently.

Without an appropriate index, MongoDB may need to scan every document in a collection.

This is called a collection scan.

Indexes improve query performance for suitable queries.

### Why do we need indexes?

Suppose a collection contains one million student records.

If we frequently search by `roll_no`, scanning every document can be expensive.

Creating an index on `roll_no` helps MongoDB locate matching documents more efficiently.

### Advantages

1. Faster data retrieval for suitable queries.
2. Improves sorting for supported query patterns.
3. Supports uniqueness constraints.
4. Can improve query performance.

### Disadvantages

1. Requires additional storage.
2. Increases the cost of INSERT operations.
3. Increases the cost of UPDATE and DELETE operations affecting indexed fields.
4. Too many indexes can reduce write performance.

---

## 15.1 createIndex()

The `createIndex()` method creates an index on a collection.

### Syntax

```javascript
db.collection.createIndex({
    field: 1
})
```

- `1` → Ascending index.
- `-1` → Descending index.

### Example: Single-Field Index

Create an index on student name.

```javascript
db.students.createIndex({
    name: 1
})
```

### Verify indexes

```javascript
db.students.getIndexes()
```

### Drop an index

```javascript
db.students.dropIndex("name_1")
```

---

## 15.2 Unique Index

A unique index ensures that indexed values do not have duplicate entries.

### Example

Create a unique index on `roll_no`.

```javascript
db.students.createIndex(
    { roll_no: 1 },
    { unique: true }
)
```

Now MongoDB will reject duplicate roll numbers.

### Test

```javascript
db.students.insertOne({
    roll_no: 101,
    name: "Duplicate Student",
    age: 22
})
```

If roll number 101 already exists, the insertion fails with a duplicate key error.

**Important:** A unique index cannot be created if existing documents already contain duplicate indexed values. Also, unique indexes on optional fields require care because missing and null values can conflict with uniqueness rules.

---

## 15.3 Compound Index

A compound index is an index created on multiple fields.

### Syntax

```javascript
db.collection.createIndex({
    field1: 1,
    field2: -1
})
```

### Example

Create an index on city and marks.

```javascript
db.students.createIndex({
    city: 1,
    marks: -1
})
```

This index is ordered by:

1. City ascending.
2. Marks descending within each city.

### Why use compound indexes?

They can improve queries that filter or sort using multiple fields in a suitable order.

Example:

```javascript
db.students.find({
    city: "Pune"
}).sort({
    marks: -1
})
```

The compound index on `{city: 1, marks: -1}` is suitable for this query pattern.

### Single-field vs Compound Index

| Feature | Single-Field Index | Compound Index |
|---|---|---|
| Fields | One | Multiple |
| Example | `{name: 1}` | `{city: 1, marks: -1}` |
| Purpose | Search one field | Search or sort using multiple fields |
| Storage | Usually less | Depends on indexed fields and data |

### Important: Compound Index Order

A compound index follows the **Leftmost Prefix Rule**.

For this index:

```javascript
db.students.createIndex({
    city: 1,
    marks: -1,
    age: 1
})
```

The index can support queries using suitable prefixes such as:

- `city`
- `city` and `marks`
- `city`, `marks` and `age`

It is not generally an efficient direct substitute for an index on `marks` alone.

---

## 15.4 explain() – Checking Query Execution Plans

The `explain()` method provides information about how MongoDB executes a query.

It helps us understand whether a query uses an index or scans the entire collection.

### Syntax

```javascript
db.collection.find({
    field: value
}).explain()
```

### Example

```javascript
db.students.find({
    city: "Pune"
}).explain("executionStats")
```

### Important execution statistics

| Field | Meaning |
|---|---|
| `queryPlanner` | Shows the selected query plan |
| `winningPlan` | Shows the selected execution plan |
| `stage` | Shows the execution stage |
| `COLLSCAN` | Collection scan |
| `IXSCAN` | Index scan |
| `executionStats` | Actual execution statistics |
| `totalDocsExamined` | Number of documents examined |
| `totalKeysExamined` | Number of index keys examined |
| `nReturned` | Number of documents returned |

### COLLSCAN

COLLSCAN means MongoDB scans documents in the collection to find matching results.

### IXSCAN

IXSCAN means MongoDB uses an index to locate matching results.

**Remember:**

- COLLSCAN → Collection Scan.
- IXSCAN → Index Scan.

### Practical comparison

Before creating an index:

```javascript
db.students.find({
    city: "Pune"
}).explain("executionStats")
```

Create an index:

```javascript
db.students.createIndex({
    city: 1
})
```

Run the query again:

```javascript
db.students.find({
    city: "Pune"
}).explain("executionStats")
```

Compare the winning plan and execution statistics.

**Note:** MongoDB's query optimizer chooses the execution plan. An index does not guarantee that every query will use it, especially for very small collections or queries where a collection scan is cheaper.

---

# 16. AGGREGATION PIPELINE OVERVIEW

The **Aggregation Pipeline** is a MongoDB framework used to process and transform documents through multiple stages.

It is commonly used for:

- Grouping records.
- Calculating totals.
- Finding averages.
- Filtering documents.
- Sorting data.
- Generating reports.
- Performing data analysis.

### Basic syntax

```javascript
db.collection.aggregate([
    { stage1 },
    { stage2 },
    { stage3 }
])
```

Each stage processes documents and passes its output to the next stage.

### Aggregation pipeline diagram

```text
      Collection
          |
          v
      $match
          |
          v
      $group
          |
          v
      $sort
          |
          v
      $project
          |
          v
       Output
```

## 16.1 Important Aggregation Stages

| Stage | Purpose |
|---|---|
| `$match` | Filters documents |
| `$project` | Selects or transforms fields |
| `$group` | Groups documents |
| `$sort` | Sorts documents |
| `$limit` | Limits output |
| `$skip` | Skips documents |
| `$count` | Counts documents |
| `$unwind` | Deconstructs an array into separate documents |

### Example 1: $match

Find students with marks greater than 75.

```javascript
db.students.aggregate([
    {
        $match: {
            marks: { $gt: 75 }
        }
    }
])
```

### Example 2: $project

Display only name and marks.

```javascript
db.students.aggregate([
    {
        $project: {
            name: 1,
            marks: 1,
            _id: 0
        }
    }
])
```

### Example 3: $group

Calculate the average marks for each course.

```javascript
db.students.aggregate([
    {
        $group: {
            _id: "$course",
            averageMarks: {
                $avg: "$marks"
            }
        }
    }
])
```

### Example 4: $sort

Sort students by marks in descending order.

```javascript
db.students.aggregate([
    {
        $sort: {
            marks: -1
        }
    }
])
```

### Example 5: $count

Count students in the collection.

```javascript
db.students.aggregate([
    {
        $count: "totalStudents"
    }
])
```

### Example 6: Multiple stages

Find students with marks above 70, group them by course and calculate average marks.

```javascript
db.students.aggregate([
    {
        $match: {
            marks: { $gt: 70 }
        }
    },
    {
        $group: {
            _id: "$course",
            averageMarks: {
                $avg: "$marks"
            },
            totalStudents: {
                $sum: 1
            }
        }
    },
    {
        $sort: {
            averageMarks: -1
        }
    }
])
```

### Important aggregation operators

| Operator | Purpose |
|---|---|
| `$sum` | Calculates sum |
| `$avg` | Calculates average |
| `$min` | Finds minimum |
| `$max` | Finds maximum |
| `$first` | Returns first value in a group |
| `$last` | Returns last value in a group |
| `$push` | Adds values to an array |
| `$addToSet` | Adds unique values to an array |

---

# 17. MongoDB Compass Practical

MongoDB Compass provides a graphical interface for performing database operations.

### Step 1: Connect to MongoDB

Open MongoDB Compass and use the local connection string:

```text
mongodb://localhost:27017
```

Click Connect.

### Step 2: Create a database

1. Click Create Database.
2. Enter database name: `college`.
3. Enter collection name: `students`.
4. Click Create Database.

### Step 3: Insert documents

1. Open the `college` database.
2. Select the `students` collection.
3. Open the Documents tab.
4. Click Add Data.
5. Select Insert Document.
6. Enter JSON document data.
7. Click Insert.

### Step 4: Query documents

Use the Filter field:

```json
{
    "city": "Pune"
}
```

### Step 5: Apply projection

Use the Project field:

```json
{
    "name": 1,
    "marks": 1,
    "_id": 0
}
```

### Step 6: Apply sorting

Use the Sort field:

```json
{
    "marks": -1
}
```

### Step 7: Create an index

1. Open the Indexes tab.
2. Click Create Index.
3. Select the required field.
4. Choose ascending or descending order.
5. Enable Unique if required.
6. Create the index.

### Step 8: Aggregation

1. Open the Aggregations tab.
2. Add a pipeline stage.
3. Select `$match`, `$group`, `$sort` or another stage.
4. Enter the stage expression.
5. View the output.

---

# 18. Important Practical Query Collection

Use these queries for quick lab revision.

### CREATE

```javascript
db.students.insertOne({
    roll_no: 111,
    name: "Kiran",
    age: 22
})
```

```javascript
db.students.insertMany([
    { roll_no: 112, name: "Meera", age: 21 },
    { roll_no: 113, name: "Nikhil", age: 23 }
])
```

### READ

```javascript
db.students.find()
```

```javascript
db.students.findOne({
    roll_no: 101
})
```

### COMPARISON

```javascript
db.students.find({
    marks: { $gt: 75 }
})
```

```javascript
db.students.find({
    marks: { $lt: 70 }
})
```

```javascript
db.students.find({
    city: { $in: ["Pune", "Mumbai"] }
})
```

### LOGICAL

```javascript
db.students.find({
    $and: [
        { age: { $gt: 21 } },
        { marks: { $gt: 70 } }
    ]
})
```

```javascript
db.students.find({
    $or: [
        { city: "Pune" },
        { city: "Mumbai" }
    ]
})
```

### UPDATE

```javascript
db.students.updateOne(
    { roll_no: 101 },
    { $set: { city: "Pune" } }
)
```

```javascript
db.students.updateMany(
    { course: "PGCP-AC" },
    { $inc: { marks: 5 } }
)
```

### UPSERT

```javascript
db.students.updateOne(
    { roll_no: 120 },
    {
        $set: {
            name: "New Student",
            age: 22
        }
    },
    {
        upsert: true
    }
)
```

### DELETE

```javascript
db.students.deleteOne({
    roll_no: 120
})
```

```javascript
db.students.deleteMany({
    marks: { $lt: 40 }
})
```

### PROJECTION

```javascript
db.students.find(
    {},
    {
        name: 1,
        marks: 1,
        _id: 0
    }
)
```

### SORTING

```javascript
db.students.find().sort({
    marks: -1
})
```

### PAGINATION

```javascript
db.students.find()
    .skip(2)
    .limit(3)
```

### INDEX

```javascript
db.students.createIndex({
    name: 1
})
```

```javascript
db.students.getIndexes()
```

### EXPLAIN

```javascript
db.students.find({
    city: "Pune"
}).explain("executionStats")
```

---

# 19. Important Interview Questions and Answers

**Q1. What is CRUD in MongoDB?**

CRUD stands for Create, Read, Update and Delete. It represents the four basic operations used to manage documents.

**Q2. What is the difference between insertOne() and insertMany()?**

`insertOne()` inserts one document, whereas `insertMany()` inserts multiple documents.

**Q3. What is the difference between find() and findOne()?**

`find()` returns a cursor containing matching documents, whereas `findOne()` returns a single matching document.

**Q4. What is the difference between updateOne() and updateMany()?**

`updateOne()` updates one matching document, whereas `updateMany()` updates all matching documents.

**Q5. What is replaceOne()?**

It replaces the contents of one matching document while retaining its `_id`.

**Q6. What is UPSERT?**

UPSERT means UPDATE + INSERT. If a matching document exists, it is updated; otherwise, a new document is inserted.

**Q7. What is upsert: true?**

It enables insertion when no document matches the update filter.

**Q8. What is the difference between $set and $unset?**

`$set` creates or modifies a field, whereas `$unset` removes a field.

**Q9. What is the use of $inc?**

`$inc` increases or decreases a numeric field.

**Q10. What is the difference between $push and $addToSet?**

`$push` allows duplicate array values, whereas `$addToSet` adds a value only if it does not already exist.

**Q11. What is $pull?**

`$pull` removes all array elements matching a specified condition.

**Q12. What are comparison operators?**

Comparison operators compare field values. Examples include `$eq`, `$gt`, `$lt`, `$gte`, `$lte`, `$ne`, `$in` and `$nin`.

**Q13. What are logical operators?**

Logical operators combine or negate query conditions. Examples are `$and`, `$or`, `$not` and `$nor`.

**Q14. What is projection?**

Projection selects or excludes specific fields from query results.

**Q15. What does 1 and 0 mean in projection?**

`1` includes a field, while `0` excludes a field.

**Q16. Can we mix inclusion and exclusion in projection?**

Generally no, except for excluding `_id` in an inclusion projection.

**Q17. What is sorting in MongoDB?**

Sorting arranges documents in ascending or descending order using the `sort()` method.

**Q18. What is the difference between ascending and descending sorting?**

Ascending uses `1`, while descending uses `-1`.

**Q19. What is pagination?**

Pagination divides query results into smaller pages using methods such as `skip()` and `limit()`.

**Q20. What is an index?**

An index is a data structure that improves query performance by helping MongoDB locate documents efficiently.

**Q21. What is a unique index?**

A unique index prevents duplicate indexed values.

**Q22. What is a compound index?**

A compound index is created on two or more fields.

**Q23. What is the Leftmost Prefix Rule?**

A compound index can support queries using suitable prefixes beginning with its first indexed field.

**Q24. What is explain() in MongoDB?**

`explain()` provides details about the query execution plan and helps analyze query performance.

**Q25. What is COLLSCAN?**

COLLSCAN means MongoDB scans documents in a collection to find matching records.

**Q26. What is IXSCAN?**

IXSCAN means MongoDB uses an index to retrieve matching records.

**Q27. What is an aggregation pipeline?**

It is a framework that processes documents through multiple stages to filter, group, transform and analyze data.

**Q28. What is $match?**

`$match` filters documents based on specified conditions.

**Q29. What is $group?**

`$group` groups documents based on a specified expression and can calculate aggregate values.

**Q30. What is the difference between find() and aggregate()?**

`find()` retrieves documents based on query conditions, whereas `aggregate()` processes documents through multiple pipeline stages.

---

# 20. Quick Revision Notes

| Topic | Important Point |
|---|---|
| CRUD | Create, Read, Update, Delete |
| insertOne() | Inserts one document |
| insertMany() | Inserts multiple documents |
| find() | Retrieves matching documents |
| findOne() | Retrieves one matching document |
| updateOne() | Updates one document |
| updateMany() | Updates multiple documents |
| replaceOne() | Replaces a document |
| deleteOne() | Deletes one document |
| deleteMany() | Deletes multiple documents |
| UPSERT | Update if found, insert otherwise |
| `$eq` | Equal to |
| `$gt` | Greater than |
| `$lt` | Less than |
| `$in` | Matches any listed value |
| `$nin` | Matches none of the listed values |
| `$and` | All conditions true |
| `$or` | Any condition true |
| `$not` | Negates a field condition |
| `$nor` | None of the conditions true |
| `$set` | Add or update a field |
| `$unset` | Remove a field |
| `$inc` | Increment or decrement |
| `$push` | Add array element |
| `$pull` | Remove matching array elements |
| `$addToSet` | Add unique array element |
| Projection | Select required fields |
| sort() | Sort documents |
| skip() | Skip documents |
| limit() | Limit output |
| createIndex() | Create index |
| Unique Index | Prevent duplicate indexed values |
| Compound Index | Index multiple fields |
| explain() | Analyze query execution |
| COLLSCAN | Collection scan |
| IXSCAN | Index scan |
| aggregate() | Execute aggregation pipeline |

### Important formulas and syntax

**Pagination formula:**

\[
skip = (pageNumber - 1) \times pageSize
\]

**Ascending sort:**

```javascript
.sort({ marks: 1 })
```

**Descending sort:**

```javascript
.sort({ marks: -1 })
```

**UPSERT:**

```javascript
{ upsert: true }
```

**Create index:**

```javascript
db.students.createIndex({ name: 1 })
```

---

# 21. Lab Practice Checklist

### MongoDB Setup

- [ ] Open MongoDB Shell.
- [ ] Connect to MongoDB Server.
- [ ] Open MongoDB Compass.
- [ ] Create a database.
- [ ] Create a collection.
- [ ] Insert sample documents.

### CRUD Operations

- [ ] Practise `insertOne()`.
- [ ] Practise `insertMany()`.
- [ ] Practise `find()`.
- [ ] Practise `findOne()`.
- [ ] Practise `updateOne()`.
- [ ] Practise `updateMany()`.
- [ ] Practise `replaceOne()`.
- [ ] Practise `deleteOne()`.
- [ ] Practise `deleteMany()`.

### Query Operators

- [ ] Practise `$eq`.
- [ ] Practise `$gt` and `$lt`.
- [ ] Practise `$gte` and `$lte`.
- [ ] Practise `$in` and `$nin`.
- [ ] Practise `$and`.
- [ ] Practise `$or`.
- [ ] Practise `$not`.
- [ ] Practise `$nor`.
- [ ] Write complex queries combining operators.

### Update Operators

- [ ] Practise `$set`.
- [ ] Practise `$unset`.
- [ ] Practise `$inc`.
- [ ] Practise `$push`.
- [ ] Practise `$pull`.
- [ ] Practise `$addToSet`.
- [ ] Perform UPSERT using `upsert: true`.

### Projection and Sorting

- [ ] Include selected fields using projection.
- [ ] Exclude fields using projection.
- [ ] Sort in ascending order.
- [ ] Sort in descending order.
- [ ] Sort using multiple fields.
- [ ] Practise pagination using `skip()` and `limit()`.

### Indexes and Aggregation

- [ ] Create a single-field index.
- [ ] Create a unique index.
- [ ] Create a compound index.
- [ ] Display indexes using `getIndexes()`.
- [ ] Drop an index.
- [ ] Analyze query plans using `explain("executionStats")`.
- [ ] Understand COLLSCAN and IXSCAN.
- [ ] Practise `$match`.
- [ ] Practise `$project`.
- [ ] Practise `$group`.
- [ ] Practise `$sort` and `$count`.

---

# 22. Useful MongoDB Commands for Revision

```javascript
// Database
show dbs
use college
db
show collections

// CREATE
db.students.insertOne({name: "Rahul", age: 22})

db.students.insertMany([
    {name: "Amit", age: 23},
    {name: "Priya", age: 21}
])

// READ
db.students.find()
db.students.findOne({name: "Rahul"})

// UPDATE
db.students.updateOne(
    {name: "Rahul"},
    {$set: {age: 23}}
)

db.students.updateMany(
    {city: "Pune"},
    {$inc: {marks: 5}}
)

// REPLACE
db.students.replaceOne(
    {name: "Amit"},
    {name: "Amit", age: 24}
)

// UPSERT
db.students.updateOne(
    {name: "Kiran"},
    {$set: {age: 22}},
    {upsert: true}
)

// DELETE
db.students.deleteOne({name: "Rahul"})
db.students.deleteMany({active: false})

// PROJECTION
db.students.find(
    {},
    {name: 1, age: 1, _id: 0}
)

// SORTING
db.students.find().sort({age: 1})
db.students.find().sort({age: -1})

// PAGINATION
db.students.find().skip(2).limit(3)

// INDEXES
db.students.createIndex({name: 1})
db.students.getIndexes()

// QUERY PLAN
db.students.find({name: "Rahul"})
    .explain("executionStats")

// AGGREGATION
db.students.aggregate([
    {$match: {marks: {$gt: 70}}},
    {$group: {_id: "$course", total: {$sum: 1}}},
    {$sort: {total: -1}}
])
```

---

**End of Session 17 – Getting Started with MongoDB**

**Topics covered:** CRUD Operations, insertOne, insertMany, find, findOne, updateOne, updateMany, replaceOne, deleteOne, deleteMany, UPSERT, Comparison Operators, Logical Operators, Update Operators, Projection, Sorting, Pagination, Single-Field Indexes, Compound Indexes, Unique Indexes, explain() and Aggregation Pipeline.
