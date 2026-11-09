# Sessions 20 & 21: Introduction to Express

**Course:** CMCE – August 2026 Batch  
**Subject:** Web Programming Technologies  
**Duration:** 4 Theory + 4 Lab + 2 Self-Learning Hours

---

# 1. Introduction to Express

## 1.1 What is Express?

**Express.js** is a lightweight and flexible web application framework built on top of Node.js.

It simplifies the process of creating web servers and web applications.

Using the Node.js HTTP module, we can create a server, handle requests, define routes, and send responses. However, as the application grows, writing everything using the HTTP module becomes complicated.

Express provides a simpler way to perform these operations.

### Definition

Express is a minimal and flexible Node.js web application framework that provides features for building web applications and APIs.

### Why do we need Express?

Consider creating a server using the Node.js HTTP module:

```javascript
const http = require("http");

const server = http.createServer((req, res) => {
    if (req.url === "/") {
        res.end("Home Page");
    } else if (req.url === "/about") {
        res.end("About Page");
    } else {
        res.end("Page Not Found");
    }
});

server.listen(3000);
```

As the application grows, we need to manually handle:
- URL checking
- HTTP methods
- Request data
- Response headers
- Middleware-like functionality
- Error handling

Express makes these operations easier.

### Same example using Express

```javascript
const express = require("express");

const app = express();

app.get("/", (req, res) => {
    res.send("Home Page");
});

app.get("/about", (req, res) => {
    res.send("About Page");
});

app.listen(3000, () => {
    console.log("Server running on port 3000");
});
```

**Observation:** Express provides a clean and organized way to handle HTTP requests.

## 1.2 Features of Express

| Feature | Explanation |
|---|---|
| Routing | Handles different URLs and HTTP methods |
| Middleware | Executes functions during the request-response cycle |
| Request handling | Provides access to request data |
| Response handling | Provides convenient methods to send responses |
| Template engines | Generates dynamic HTML pages |
| Error handling | Supports centralized error-handling middleware |
| REST API development | Makes it easier to create APIs |
| Extensibility | Supports third-party middleware and packages |

## 1.3 Node.js vs Express.js

| Node.js | Express.js |
|---|---|
| JavaScript runtime environment | Web framework |
| Runs JavaScript outside the browser | Runs on Node.js |
| Provides built-in HTTP module | Simplifies HTTP server development |
| Routing must be handled manually | Provides routing methods |
| Middleware must be implemented or integrated | Supports middleware |
| Can build servers without Express | Uses Node.js to build web applications |

**Important:** Express is not a replacement for Node.js. Express runs on top of Node.js.

## 1.4 Installing Express

### Step 1: Create a project folder

```bash
mkdir express-demo
cd express-demo
```

### Step 2: Initialize the Node.js project

```bash
npm init -y
```

This creates a `package.json` file.

### Step 3: Install Express

```bash
npm install express
```

### Step 4: Create `server.js`

```javascript
const express = require("express");

const app = express();

app.get("/", (req, res) => {
    res.send("Welcome to Express");
});

app.listen(3000, () => {
    console.log("Server running at http://localhost:3000");
});
```

### Step 5: Run the application

```bash
node server.js
```

Open:

```text
http://localhost:3000
```

Output:

```text
Welcome to Express
```

---

# 2. Application, Request and Response Objects

Express mainly works with three important concepts:

1. Application object (`app`)
2. Request object (`req`)
3. Response object (`res`)

## 2.1 Application Object (`app`)

The application object represents the Express application.

It is created by calling:

```javascript
const express = require("express");

const app = express();
```

The `app` object provides methods to:
- Define routes.
- Register middleware.
- Configure application settings.
- Start the server.
- Handle errors.

### Important application methods

| Method | Purpose |
|---|---|
| `app.get()` | Handles GET requests |
| `app.post()` | Handles POST requests |
| `app.put()` | Handles PUT requests |
| `app.patch()` | Handles PATCH requests |
| `app.delete()` | Handles DELETE requests |
| `app.use()` | Registers middleware |
| `app.listen()` | Starts the server |
| `app.set()` | Sets application configuration |
| `app.route()` | Groups handlers for a particular route |
| `app.all()` | Handles all HTTP methods for a route |

Example:

```javascript
const express = require("express");

const app = express();

app.get("/", (req, res) => {
    res.send("Home Page");
});

app.post("/student", (req, res) => {
    res.send("Student created");
});

app.listen(3000);
```

## 2.2 Request Object (`req`)

The request object contains information about the incoming HTTP request.

It allows us to access:
- URL
- HTTP method
- Route parameters
- Query parameters
- Request body
- Headers

### Important request properties and methods

| Property / Method | Purpose |
|---|---|
| `req.url` | Requested URL |
| `req.method` | HTTP method |
| `req.params` | Route parameters |
| `req.query` | Query string parameters |
| `req.body` | Submitted request body |
| `req.headers` | Request headers |
| `req.get()` | Reads a particular request header |
| `req.path` | URL path |
| `req.ip` | Request IP address |

### A. req.params – Route Parameters

Route parameters are used to capture values from a URL.

Example:

```javascript
app.get("/student/:id", (req, res) => {
    res.send("Student ID: " + req.params.id);
});
```

URL:

```text
http://localhost:3000/student/101
```

Output:

```text
Student ID: 101
```

Here:
- `:id` is a route parameter.
- `req.params.id` retrieves its value.

Multiple parameters:

```javascript
app.get("/student/:id/:name", (req, res) => {
    res.send(
        `ID: ${req.params.id}, Name: ${req.params.name}`
    );
});
```

URL:

```text
/student/101/Anurag
```

Output:

```text
ID: 101, Name: Anurag
```

### B. req.query – Query Parameters

Query parameters are values passed through the URL after the `?` symbol.

Example:

```javascript
app.get("/search", (req, res) => {
    const name = req.query.name;

    res.send("Searching for: " + name);
});
```

URL:

```text
http://localhost:3000/search?name=Anurag
```

Output:

```text
Searching for: Anurag
```

Multiple query parameters:

```text
/search?name=Anurag&city=Pune
```

Code:

```javascript
app.get("/search", (req, res) => {
    res.json({
        name: req.query.name,
        city: req.query.city
    });
});
```

Output:

```json
{
  "name": "Anurag",
  "city": "Pune"
}
```

### C. req.body – Request Body

The request body contains data sent by the client, commonly through POST, PUT, and PATCH requests.

For JSON request bodies, use:

```javascript
app.use(express.json());
```

Example:

```javascript
app.post("/student", (req, res) => {
    const student = req.body;

    res.json({
        message: "Student received",
        data: student
    });
});
```

Send this JSON using Thunder Client:

```json
{
    "id": 101,
    "name": "Anurag",
    "course": "CMCE"
}
```

Output:

```json
{
    "message": "Student received",
    "data": {
        "id": 101,
        "name": "Anurag",
        "course": "CMCE"
    }
}
```

**Important:** `req.body` is not automatically populated for every request. You must register suitable body-parsing middleware.

For form submissions using URL-encoded data:

```javascript
app.use(express.urlencoded({ extended: true }));
```

## 2.3 Response Object (`res`)

The response object is used to send a response from the server to the client.

### Important response methods

| Method | Purpose |
|---|---|
| `res.send()` | Sends text, HTML, or other supported data |
| `res.json()` | Sends a JSON response |
| `res.status()` | Sets HTTP status code |
| `res.sendStatus()` | Sets status and sends its text |
| `res.redirect()` | Redirects to another URL |
| `res.render()` | Renders a template |
| `res.sendFile()` | Sends a file |
| `res.download()` | Prompts the client to download a file |
| `res.set()` | Sets response headers |
| `res.end()` | Ends the response |

### Example 1: res.send()

```javascript
app.get("/home", (req, res) => {
    res.send("Welcome to Home Page");
});
```

### Example 2: res.json()

```javascript
app.get("/student", (req, res) => {
    res.json({
        id: 101,
        name: "Anurag",
        course: "CMCE"
    });
});
```

### Example 3: res.status()

```javascript
app.get("/error", (req, res) => {
    res.status(404).send("Page Not Found");
});
```

### Example 4: res.redirect()

```javascript
app.get("/old-home", (req, res) => {
    res.redirect("/");
});
```

### Example 5: res.sendFile()

```javascript
const path = require("path");

app.get("/about", (req, res) => {
    res.sendFile(path.join(__dirname, "about.html"));
});
```

### Example 6: res.render()

```javascript
app.set("view engine", "ejs");

app.get("/profile", (req, res) => {
    res.render("profile", {
        name: "Anurag"
    });
});
```

This example is explained in the template engine section.

## 2.4 Complete Request and Response Example

```javascript
const express = require("express");

const app = express();

app.use(express.json());

app.get("/student/:id", (req, res) => {

    const studentId = req.params.id;

    res.status(200).json({
        message: "Student details fetched",
        id: studentId
    });

});

app.post("/student", (req, res) => {

    const student = req.body;

    res.status(201).json({
        message: "Student added successfully",
        student: student
    });

});

app.listen(3000, () => {
    console.log("Server started");
});
```

---

# 3. Routes and Middlewares

## 3.1 What is Routing?

Routing refers to determining how an application responds to a client request for a particular URL and HTTP method.

In simple words:

**Routing decides which function should execute when a user visits a particular URL.**

Example:

| HTTP Method | URL | Purpose |
|---|---|---|
| GET | `/` | Home page |
| GET | `/about` | About page |
| GET | `/students` | Display students |
| POST | `/students` | Add a student |
| PUT | `/students/101` | Update a student |
| DELETE | `/students/101` | Delete a student |

### Basic route syntax

```javascript
app.METHOD(PATH, HANDLER);
```

Where:
- `app` = Express application.
- `METHOD` = HTTP method.
- `PATH` = URL path.
- `HANDLER` = Callback function executed when the route matches.

### Example

```javascript
app.get("/", (req, res) => {
    res.send("Home Page");
});
```

## 3.2 HTTP Methods in Express

### GET

Used to retrieve data.

```javascript
app.get("/students", (req, res) => {
    res.send("All students");
});
```

### POST

Used to create new data.

```javascript
app.post("/students", (req, res) => {
    res.send("Student added");
});
```

### PUT

Used to replace or update an existing resource.

```javascript
app.put("/students/:id", (req, res) => {
    res.send("Student updated: " + req.params.id);
});
```

### PATCH

Used to partially update an existing resource.

```javascript
app.patch("/students/:id", (req, res) => {
    res.send("Student partially updated");
});
```

### DELETE

Used to delete an existing resource.

```javascript
app.delete("/students/:id", (req, res) => {
    res.send("Student deleted: " + req.params.id);
});
```

## 3.3 Multiple Route Handlers

Express allows multiple callback functions for a single route.

```javascript
app.get(
    "/profile",

    (req, res, next) => {
        console.log("First handler");
        next();
    },

    (req, res) => {
        res.send("Profile Page");
    }
);
```

Here:
- The first handler executes.
- `next()` passes control to the next handler.
- The second handler sends the response.

## 3.4 What is Middleware?

**Middleware is a function that executes during the request-response cycle of an Express application.**

It has access to:
- Request object (`req`)
- Response object (`res`)
- Next middleware function (`next`)

### Middleware syntax

```javascript
function middleware(req, res, next) {

    // Perform operations

    next();
}
```

### How middleware works

Consider this flow:

```text
Client Request
      |
      v
Middleware 1
      |
      v
Middleware 2
      |
      v
Route Handler
      |
      v
Response to Client
```

Middleware can:
- Execute code.
- Modify the request object.
- Modify the response object.
- End the request-response cycle.
- Pass control to the next middleware.

**Important:** If middleware neither sends a response nor calls `next()`, the request may remain pending.

## 3.5 Types of Middleware

Express supports several types of middleware.

### 1. Application-level Middleware

Middleware registered using `app.use()` or application route methods.

Example:

```javascript
const express = require("express");

const app = express();

app.use((req, res, next) => {
    console.log("Request received");
    next();
});

app.get("/", (req, res) => {
    res.send("Home Page");
});

app.listen(3000);
```

Whenever a request arrives, the middleware executes.

### 2. Router-level Middleware

Middleware registered using an Express Router instance.

```javascript
const express = require("express");

const router = express.Router();

router.use((req, res, next) => {
    console.log("Student router middleware");
    next();
});

router.get("/", (req, res) => {
    res.send("All Students");
});

app.use("/students", router);
```

### 3. Built-in Middleware

Express provides some middleware functions.

| Middleware | Purpose |
|---|---|
| `express.json()` | Parses incoming JSON request bodies |
| `express.urlencoded()` | Parses URL-encoded form data |
| `express.static()` | Serves static files such as CSS, images and JavaScript |

Example:

```javascript
app.use(express.json());

app.use(express.urlencoded({ extended: true }));

app.use(express.static("public"));
```

### 4. Third-party Middleware

Middleware developed by external developers and installed through npm.

Examples:

| Middleware | Purpose |
|---|---|
| `cors` | Enables Cross-Origin Resource Sharing |
| `morgan` | HTTP request logging |
| `helmet` | Adds security-related HTTP headers |
| `cookie-parser` | Parses cookies |

Install Morgan:

```bash
npm install morgan
```

Use it:

```javascript
const morgan = require("morgan");

app.use(morgan("dev"));
```

### 5. Error-handling Middleware

Used to handle application errors centrally.

It has four parameters:

```javascript
function errorHandler(err, req, res, next) {

    console.error(err.message);

    res.status(500).send("Something went wrong");
}
```

Register it after routes:

```javascript
app.use(errorHandler);
```

The four parameters are important for Express to identify error-handling middleware.

## 3.6 Understanding next()

The `next()` function passes control to the next middleware or route handler.

Example:

```javascript
app.use((req, res, next) => {

    console.log("Middleware executed");

    next();

});

app.get("/", (req, res) => {

    res.send("Home Page");

});
```

When we visit `/`:

```text
Middleware executed
```

Browser:

```text
Home Page
```

### next() vs next(err)

| Function | Purpose |
|---|---|
| `next()` | Passes control to the next middleware |
| `next(err)` | Passes an error to error-handling middleware |

---

# 4. Templates, Template Engines and Rendering Views

## 4.1 What is a Template?

A template is an HTML structure containing placeholders for dynamic data.

Instead of writing separate HTML pages for every user, we can create one template and pass different data to it.

Example:

```html
<h1>Welcome, <%= name %></h1>
```

The value of `name` is inserted when the template is rendered.

## 4.2 What is a Template Engine?

A template engine is a tool that combines an HTML template with dynamic data and generates final HTML.

Popular template engines:

| Template Engine | Description |
|---|---|
| EJS | Embedded JavaScript templates |
| Pug | Indentation-based template engine |
| Handlebars | Uses expressions and placeholders |

For this session, we will use **EJS**.

## 4.3 What is EJS?

EJS stands for Embedded JavaScript.

It allows us to write JavaScript expressions inside HTML templates.

Example:

```html
<h1>Hello <%= name %></h1>
```

If the server passes:

```javascript
{ name: "Anurag" }
```

The generated HTML becomes:

```html
<h1>Hello Anurag</h1>
```

### Important EJS syntax

| Syntax | Purpose |
|---|---|
| `<%= value %>` | Outputs escaped value |
| `<%- value %>` | Outputs unescaped HTML |
| `<% code %>` | Executes JavaScript without output |
| `<%# comment %>` | Adds a template comment |

**Security note:** Prefer `<%= %>` for ordinary user-provided text because it escapes HTML. Use `<%- %>` only for trusted HTML content.

### Example: Displaying a variable

```html
<h1>Welcome <%= name %></h1>
```

### Example: Conditional statement

```html
<% if (marks >= 40) { %>
    <h2>Pass</h2>
<% } else { %>
    <h2>Fail</h2>
<% } %>
```

### Example: Loop

```html
<ul>
    <% students.forEach(student => { %>
        <li><%= student %></li>
    <% }) %>
</ul>
```

## 4.4 Installing EJS

Inside your project folder:

```bash
npm install ejs
```

## 4.5 Configuring EJS in Express

```javascript
const express = require("express");

const app = express();

app.set("view engine", "ejs");

app.listen(3000);
```

By default, Express looks for template files inside the `views` directory.

Project structure:

```text
express-demo/
│
├── server.js
├── package.json
│
└── views/
    └── home.ejs
```

## 4.6 Rendering Views using res.render()

The `res.render()` method renders a template and sends the generated HTML to the client.

Syntax:

```javascript
res.render("viewName", data);
```

Example:

**server.js**

```javascript
const express = require("express");

const app = express();

app.set("view engine", "ejs");

app.get("/", (req, res) => {

    res.render("home", {
        name: "Anurag",
        course: "CMCE"
    });

});

app.listen(3000);
```

**views/home.ejs**

```html
<!DOCTYPE html>
<html>
<head>
    <title>Home Page</title>
</head>
<body>

    <h1>Welcome <%= name %></h1>

    <h2>Course: <%= course %></h2>

</body>
</html>
```

Browser output:

```text
Welcome Anurag

Course: CMCE
```

## 4.7 Passing Arrays to Templates

**server.js**

```javascript
app.get("/students", (req, res) => {

    const students = [
        "Anurag",
        "Rahul",
        "Amit",
        "Sushant"
    ];

    res.render("students", {
        students: students
    });

});
```

**views/students.ejs**

```html
<!DOCTYPE html>
<html>
<body>

    <h1>Student List</h1>

    <ul>
        <% students.forEach(student => { %>

            <li><%= student %></li>

        <% }) %>
    </ul>

</body>
</html>
```

Browser output:

- Anurag
- Rahul
- Amit
- Sushant

## 4.8 Static Files in Express

Static files include:
- CSS files
- JavaScript files
- Images
- Fonts

Create a `public` folder:

```text
express-demo/
│
├── server.js
├── public/
│   ├── style.css
│   └── logo.png
│
└── views/
    └── home.ejs
```

Register static middleware:

```javascript
app.use(express.static("public"));
```

Now CSS can be linked in EJS:

```html
<link rel="stylesheet" href="/style.css">
```

Express serves the file from the `public` directory.

---

# 5. Lab 1 – Build a Simple Express Application with at Least 5 Routes

## Objective

Use Node.js and Express to build a simple web application containing at least five route implementations.

We will create a Student Management application.

## Step 1: Create the project

```bash
mkdir student-express-app
cd student-express-app

npm init -y

npm install express
```

## Step 2: Create server.js

```javascript
const express = require("express");

const app = express();

app.use(express.json());

const students = [
    { id: 1, name: "Anurag", course: "CMCE" },
    { id: 2, name: "Rahul", course: "Java" },
    { id: 3, name: "Amit", course: "Python" }
];

// Route 1: Home Page
app.get("/", (req, res) => {

    res.send("Welcome to Student Management System");

});

// Route 2: Get All Students
app.get("/students", (req, res) => {

    res.json(students);

});

// Route 3: Get Student by ID
app.get("/students/:id", (req, res) => {

    const id = Number(req.params.id);

    const student = students.find(s => s.id === id);

    if (!student) {
        return res.status(404).json({
            message: "Student not found"
        });
    }

    res.json(student);

});

// Route 4: Add Student
app.post("/students", (req, res) => {

    const { name, course } = req.body;

    if (!name || !course) {
        return res.status(400).json({
            message: "Name and course are required"
        });
    }

    const newStudent = {
        id: students.length
            ? Math.max(...students.map(s => s.id)) + 1
            : 1,
        name,
        course
    };

    students.push(newStudent);

    res.status(201).json({
        message: "Student added successfully",
        student: newStudent
    });

});

// Route 5: Update Student
app.put("/students/:id", (req, res) => {

    const id = Number(req.params.id);

    const student = students.find(s => s.id === id);

    if (!student) {
        return res.status(404).json({
            message: "Student not found"
        });
    }

    const { name, course } = req.body;

    if (name) student.name = name;
    if (course) student.course = course;

    res.json({
        message: "Student updated successfully",
        student: student
    });

});

// Route 6: Delete Student
app.delete("/students/:id", (req, res) => {

    const id = Number(req.params.id);

    const index = students.findIndex(s => s.id === id);

    if (index === -1) {
        return res.status(404).json({
            message: "Student not found"
        });
    }

    students.splice(index, 1);

    res.json({
        message: "Student deleted successfully"
    });

});

// Start Server
app.listen(3000, () => {

    console.log("Server running at http://localhost:3000");

});
```

## Step 3: Run the application

```bash
node server.js
```

## Step 4: Test using Thunder Client

| Method | URL | Purpose |
|---|---|---|
| GET | `http://localhost:3000/` | Home page |
| GET | `http://localhost:3000/students` | Get all students |
| GET | `http://localhost:3000/students/1` | Get student by ID |
| POST | `http://localhost:3000/students` | Add student |
| PUT | `http://localhost:3000/students/1` | Update student |
| DELETE | `http://localhost:3000/students/1` | Delete student |

For POST, send JSON:

```json
{
    "name": "Sushant",
    "course": "CMCE"
}
```

For PUT, send JSON:

```json
{
    "name": "Anurag Updated",
    "course": "PGCP-AC"
}
```

**Note:** This lab uses an in-memory array. Changes disappear when the server restarts. A real application should store records in a database such as MySQL or MongoDB.

---

# 6. Lab 2 – Rebuild a Previous Node Assignment Using Express and a Template Engine

## Objective

Rebuild the previous Node.js Student Management application using:
- Node.js
- Express.js
- EJS template engine

In this version, the server will render HTML pages dynamically instead of sending only plain text or JSON.

## Step 1: Create the project

```bash
mkdir student-ejs-app
cd student-ejs-app

npm init -y

npm install express ejs
```

## Step 2: Create the folder structure

```text
student-ejs-app/
│
├── server.js
│
├── views/
│   ├── home.ejs
│   ├── students.ejs
│   └── add-student.ejs
│
└── public/
    └── style.css
```

## Step 3: Create server.js

```javascript
const express = require("express");

const app = express();

app.set("view engine", "ejs");

app.use(express.urlencoded({ extended: true }));

app.use(express.static("public"));

let students = [
    { id: 1, name: "Anurag", course: "CMCE" },
    { id: 2, name: "Rahul", course: "Java" },
    { id: 3, name: "Amit", course: "Python" }
];

// Home Route
app.get("/", (req, res) => {

    res.render("home");

});

// Display Students
app.get("/students", (req, res) => {

    res.render("students", {
        students: students
    });

});

// Show Add Student Form
app.get("/add-student", (req, res) => {

    res.render("add-student");

});

// Handle Form Submission
app.post("/add-student", (req, res) => {

    const { name, course } = req.body;

    if (!name || !course) {
        return res.status(400).send("Name and course are required");
    }

    const newStudent = {
        id: students.length
            ? Math.max(...students.map(s => s.id)) + 1
            : 1,
        name,
        course
    };

    students.push(newStudent);

    res.redirect("/students");

});

// Start Server
app.listen(3000, () => {

    console.log("Server running at http://localhost:3000");

});
```

## Step 4: Create home.ejs

Location: `views/home.ejs`

```html
<!DOCTYPE html>
<html>
<head>
    <title>Student Management</title>
    <link rel="stylesheet" href="/style.css">
</head>
<body>

    <h1>Student Management System</h1>

    <p>Welcome to our Student Management Application.</p>

    <a href="/students">View Students</a>

    <br><br>

    <a href="/add-student">Add New Student</a>

</body>
</html>
```

## Step 5: Create students.ejs

Location: `views/students.ejs`

```html
<!DOCTYPE html>
<html>
<head>
    <title>Students</title>
    <link rel="stylesheet" href="/style.css">
</head>
<body>

    <h1>Student List</h1>

    <table border="1" cellpadding="10">

        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Course</th>
        </tr>

        <% students.forEach(student => { %>

            <tr>
                <td><%= student.id %></td>
                <td><%= student.name %></td>
                <td><%= student.course %></td>
            </tr>

        <% }) %>

    </table>

    <br>

    <a href="/">Home</a>

    <br><br>

    <a href="/add-student">Add Student</a>

</body>
</html>
```

## Step 6: Create add-student.ejs

Location: `views/add-student.ejs`

```html
<!DOCTYPE html>
<html>
<head>
    <title>Add Student</title>
    <link rel="stylesheet" href="/style.css">
</head>
<body>

    <h1>Add New Student</h1>

    <form action="/add-student" method="POST">

        <label>Student Name:</label>

        <input
            type="text"
            name="name"
            required
        >

        <br><br>

        <label>Course:</label>

        <select name="course" required>

            <option value="">Select Course</option>

            <option value="CMCE">CMCE</option>

            <option value="Java">Java</option>

            <option value="Python">Python</option>

            <option value="MERN">MERN</option>

        </select>

        <br><br>

        <button type="submit">Add Student</button>

    </form>

    <br>

    <a href="/students">View Students</a>

</body>
</html>
```

## Step 7: Create style.css

Location: `public/style.css`

```css
body {
    font-family: Arial, sans-serif;
    margin: 40px;
    background-color: #f4f4f4;
}

h1 {
    color: #333;
}

table {
    background-color: white;
    border-collapse: collapse;
}

th {
    background-color: #ddd;
}

input, select, button {
    padding: 8px;
    margin-top: 5px;
}
```

## Step 8: Run the application

```bash
node server.js
```

Open:

```text
http://localhost:3000
```

### Expected application flow

1. Open the home page.
2. Click View Students.
3. See the student records.
4. Click Add Student.
5. Enter student name and select course.
6. Submit the form.
7. Express receives the POST request.
8. The new student is added to the array.
9. Express redirects to `/students`.
10. EJS displays the updated student list.

### What did we learn?

- Express routes handle HTTP requests.
- `express.urlencoded()` reads HTML form data.
- `req.body` accesses submitted form values.
- `res.render()` renders an EJS template.
- EJS displays dynamic data.
- `res.redirect()` redirects the browser after submission.
- Static middleware serves CSS files.

---

# 7. Important Differences for CCEE and Interviews

## 7.1 res.send() vs res.json() vs res.render()

| Method | Purpose | Example |
|---|---|---|
| `res.send()` | Sends a response | `res.send("Hello")` |
| `res.json()` | Sends JSON data | `res.json({name:"Anurag"})` |
| `res.render()` | Renders a template | `res.render("home", data)` |

## 7.2 req.params vs req.query vs req.body

| Feature | req.params | req.query | req.body |
|---|---|---|---|
| Purpose | Route values | Query string values | Submitted data |
| URL example | `/student/101` | `/student?id=101` | Data in request body |
| Access | `req.params.id` | `req.query.id` | `req.body.id` |
| Common use | Fetch by ID | Search and filtering | Create/update data |

## 7.3 Routing vs Middleware

| Routing | Middleware |
|---|---|
| Handles a specific URL and HTTP method | Executes during request processing |
| Usually performs a route-specific operation | Can perform common operations |
| Sends a response or passes control | Can modify request/response or pass control |
| Example: `app.get()` | Example: `app.use()` |

## 7.4 app.use() vs app.get()

| app.use() | app.get() |
|---|---|
| Registers middleware | Defines a GET route |
| Can apply to many HTTP methods | Handles GET requests |
| Can use a path or no path | Requires a route path and handler |
| Example: `app.use(express.json())` | Example: `app.get("/", handler)` |

## 7.5 Static HTML vs Dynamic HTML

| Static HTML | Dynamic HTML |
|---|---|
| Same content is served to users | Content can change based on data |
| Does not require a template engine | Can use a template engine |
| Example: `index.html` | Example: `home.ejs` |

---

# 8. CCEE / Interview Questions

### Basic Questions

1. What is Express.js?
2. Why do we use Express with Node.js?
3. Is Express a programming language?
4. What are the main features of Express?
5. How do you install Express?
6. What is the purpose of the `app` object?
7. What is routing?
8. What is middleware?
9. What is the purpose of `next()`?
10. What are the different types of middleware?

### Application, Request and Response

11. What is the difference between `req` and `res`?
12. What is `req.params`?
13. What is `req.query`?
14. What is `req.body`?
15. What is the purpose of `express.json()`?
16. What is the purpose of `express.urlencoded()`?
17. What is the difference between `res.send()` and `res.json()`?
18. What is `res.status()`?
19. What is `res.redirect()`?
20. What is `res.render()`?

### Middleware and Routing

21. Explain application-level middleware.
22. What is router-level middleware?
23. What is third-party middleware?
24. What is error-handling middleware?
25. Why does error-handling middleware have four parameters?
26. What is the difference between `app.use()` and `app.get()`?
27. What are route parameters?
28. Explain GET, POST, PUT, PATCH and DELETE.
29. What happens if middleware does not call `next()` or send a response?
30. What is Express Router?

### Template Engines

31. What is a template engine?
32. What is EJS?
33. What is the purpose of `app.set("view engine", "ejs")`?
34. What is the purpose of the `views` folder?
35. What is the difference between `<%= %>` and `<%- %>` in EJS?
36. How do you pass data from Express to EJS?
37. What is the purpose of `res.render()`?
38. What is static middleware?
39. What is the difference between static and dynamic pages?
40. Name three popular template engines.

---

# 9. MCQs – Practice for CCEE

**1. Express.js is built on top of which technology?**

A. React  
B. Node.js  
C. Angular  
D. MongoDB  

**Answer: B. Node.js**

**2. Which method creates an Express application?**

A. express.create()  
B. express.server()  
C. express()  
D. express.start()  

**Answer: C. express()**

**3. Which method is used to define a GET route?**

A. app.post()  
B. app.get()  
C. app.use()  
D. app.listen()  

**Answer: B. app.get()**

**4. Which object contains route parameters?**

A. req.body  
B. req.query  
C. req.params  
D. res.params  

**Answer: C. req.params**

**5. Which property accesses query string values?**

A. req.query  
B. req.params  
C. req.body  
D. req.url  

**Answer: A. req.query**

**6. Which middleware parses JSON request bodies?**

A. express.static()  
B. express.json()  
C. express.router()  
D. express.parse()  

**Answer: B. express.json()**

**7. What is the purpose of `next()`?**

A. Stop the server  
B. Pass control to the next middleware  
C. Delete the request  
D. Restart Express  

**Answer: B. Pass control to the next middleware**

**8. Which method sends a JSON response?**

A. res.send()  
B. res.render()  
C. res.json()  
D. res.redirect()  

**Answer: C. res.json()**

**9. Which middleware is used to serve static files?**

A. express.json()  
B. express.static()  
C. express.urlencoded()  
D. express.router()  

**Answer: B. express.static()**

**10. Which method is used to render an EJS page?**

A. res.send()  
B. res.render()  
C. res.json()  
D. res.end()  

**Answer: B. res.render()**

**11. What does EJS stand for?**

A. Embedded JavaScript  
B. External JavaScript  
C. Express Java Server  
D. Extended JSON Syntax  

**Answer: A. Embedded JavaScript**

**12. What does `<%= name %>` do in EJS?**

A. Executes a loop  
B. Outputs an escaped value  
C. Imports a module  
D. Creates a route  

**Answer: B. Outputs an escaped value**

**13. Which middleware is used for URL-encoded form data?**

A. express.json()  
B. express.static()  
C. express.urlencoded()  
D. express.get()  

**Answer: C. express.urlencoded()**

**14. Which HTTP method is generally used to create a resource?**

A. GET  
B. POST  
C. DELETE  
D. OPTIONS  

**Answer: B. POST**

**15. Which method starts the Express server?**

A. app.start()  
B. app.run()  
C. app.listen()  
D. app.open()  

**Answer: C. app.listen()**

---

# 10. Quick Revision Notes

| Topic | Remember |
|---|---|
| Express | Node.js web framework |
| `express()` | Creates application |
| `app.get()` | Handles GET request |
| `app.post()` | Handles POST request |
| `app.put()` | Handles PUT request |
| `app.delete()` | Handles DELETE request |
| `req.params` | Route parameters |
| `req.query` | Query parameters |
| `req.body` | Request body |
| `res.send()` | Sends response |
| `res.json()` | Sends JSON |
| `res.status()` | Sets HTTP status |
| `res.render()` | Renders a view |
| `res.redirect()` | Redirects to another URL |
| `app.use()` | Registers middleware |
| `next()` | Passes control |
| `express.json()` | Parses JSON |
| `express.urlencoded()` | Parses form data |
| `express.static()` | Serves static files |
| EJS | Embedded JavaScript template engine |
| `app.set()` | Configures application settings |

---

# 11. Self-Learning Assignments

1. Create an Express application with routes for Home, About, Contact, Services and Login.
2. Create a route `/employee/:id` and display the employee ID.
3. Create a search route using query parameters.
4. Create a POST route that accepts employee details in JSON format.
5. Create a middleware that logs the request method and URL.
6. Create a middleware that checks whether a user is authenticated.
7. Install and use Morgan middleware.
8. Create an EJS template to display a list of products.
9. Create a form using EJS to add employee records.
10. Rebuild your previous Node.js HTTP assignment using Express and EJS.

---

# 12. Practical Checklist

- [ ] Understand what Express is and why it is used.
- [ ] Install Express using npm.
- [ ] Create an Express application.
- [ ] Understand `app`, `req` and `res`.
- [ ] Implement GET and POST routes.
- [ ] Understand route and query parameters.
- [ ] Handle JSON and form data.
- [ ] Create custom middleware.
- [ ] Use built-in and third-party middleware.
- [ ] Understand error-handling middleware.
- [ ] Install and configure EJS.
- [ ] Render dynamic data using `res.render()`.
- [ ] Serve CSS and image files using static middleware.
- [ ] Complete both practical assignments.

---

# 13. Recommended References

### Books from the Web Programming reference list

1. **Web Development with Node and Express** – Ethan Brown, O'Reilly.
2. **JavaScript: The Definitive Guide, 7th Edition** – David Flanagan, O'Reilly.
3. **React in Depth** – Morten Barklund, O'Reilly (useful for later React topics).

### Official Documentation

- Express.js Guide: https://expressjs.com/en/guide/routing.html
- Express Middleware: https://expressjs.com/en/guide/using-middleware.html
- Express API Reference: https://expressjs.com/en/5x/api.html
- EJS Documentation: https://ejs.co/
- Node.js Documentation: https://nodejs.org/docs/latest/api/

**Study tip:** Practise Lab 1 first using Thunder Client. Then complete Lab 2 and understand how Express routes, form data, middleware and EJS work together. These concepts form the foundation for building REST APIs and full-stack applications using Express and React.
