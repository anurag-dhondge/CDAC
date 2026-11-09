# Session 19 – Node.js Modules

**Course:** CMCE – August 2026 Batch  
**Subject:** Web Programming Technologies

# 1. Understanding Node.js Modules

## 1.1 What is a Module?

A module is a reusable block of code that performs a specific task.

In Node.js, modules help developers divide a large application into smaller, manageable files.

Each module can contain:
- Variables
- Functions
- Objects
- Classes
- Business logic

For example, consider a student management application.

Instead of writing the entire application in one file, we can divide it into multiple modules:

```text
Student Management Application
          |
          |
   -------------------
   |        |        |
   v        v        v
 student  course   database
  .js      .js      .js
   |        |        |
   -------------------
          |
          v
       app.js
```

### Why do we use modules?

1. Code reusability.
2. Better organization.
3. Easy maintenance.
4. Separation of concerns.
5. Easier testing and debugging.
6. Avoids writing everything in a single file.

### Definition for exams

A Node.js module is a reusable and independent unit of code that can be exported from one file and imported into another file.

## 1.2 Types of Node.js Modules

Node.js modules can be broadly classified into three categories.

### 1. Core Modules (Built-in Modules)

These modules are provided by Node.js itself.

No separate installation is required.

Examples:

| Module | Purpose |
|---|---|
| `fs` | File system operations |
| `http` | Creating HTTP servers |
| `path` | Working with file paths |
| `os` | Operating system information |
| `url` | URL handling |
| `events` | Event handling |
| `crypto` | Cryptographic operations |
| `stream` | Stream processing |

Example:

```javascript
const fs = require("fs");

console.log("File System Module Loaded");
```

### 2. Local Modules (User-defined Modules)

These are modules created by developers for their own applications.

Example:

```text
project/
    |
    |-- app.js
    |-- math.js
```

`math.js`:

```javascript
function add(a, b) {
    return a + b;
}

module.exports = add;
```

`app.js`:

```javascript
const add = require("./math");

console.log(add(10, 20));
```

Output:

```text
30
```

Here, `math.js` is a user-defined module.

### 3. Third-party Modules

These modules are developed by external developers and made available through package registries such as npm.

Examples:

| Package | Purpose |
|---|---|
| Express | Web application framework |
| Axios | HTTP client |
| Mongoose | MongoDB object modeling |
| Lodash | Utility functions |
| CORS | Cross-Origin Resource Sharing middleware |
| Nodemon | Automatically restarts Node.js applications during development |

Third-party packages are generally installed using npm.

Example:

```bash
npm install express
```

### Comparison of Node.js Modules

| Core Modules | Local Modules | Third-party Modules |
|---|---|---|
| Provided by Node.js | Created by developers | Created by external developers |
| No installation required | No installation required | Usually installed using npm |
| Example: `fs` | Example: `math.js` | Example: `express` |

---

# 2. Understanding Exports and Require

Node.js supports two main module systems:

1. CommonJS
2. ECMAScript Modules (ESM)

This syllabus introduces `exports` and `require`, which are associated with the CommonJS module system.

## 2.1 What is require()?

`require()` is a CommonJS function used to load a module into another JavaScript file.

### Syntax

```javascript
const moduleName = require("module-name");
```

For a local module:

```javascript
const moduleName = require("./module-name");
```

Examples:

Importing a built-in module:

```javascript
const fs = require("fs");
```

Importing a third-party module:

```javascript
const express = require("express");
```

Importing a local module:

```javascript
const math = require("./math");
```

**Remember:** For local files, `./` means the current directory.

## 2.2 What is module.exports?

`module.exports` is used to define what a CommonJS module makes available to other files.

Example:

Create `math.js`:

```javascript
function add(a, b) {

    return a + b;

}

module.exports = add;
```

Create `app.js`:

```javascript
const add = require("./math");

const result = add(10, 20);

console.log(result);
```

Output:

```text
30
```

Explanation:

1. `math.js` defines the add function.
2. `module.exports = add` exports the function.
3. `require("./math")` imports it into `app.js`.
4. The imported function is called.

## 2.3 Exporting Multiple Functions

A module can export multiple functions using an object.

Create `math.js`:

```javascript
function add(a, b) {
    return a + b;
}

function subtract(a, b) {
    return a - b;
}

function multiply(a, b) {
    return a * b;
}

function divide(a, b) {
    if (b === 0) {
        throw new Error("Division by zero");
    }

    return a / b;
}

module.exports = {
    add,
    subtract,
    multiply,
    divide
};
```

Create `app.js`:

```javascript
const math = require("./math");

console.log(math.add(10, 5));

console.log(math.subtract(10, 5));

console.log(math.multiply(10, 5));

console.log(math.divide(10, 5));
```

Output:

```text
15
5
50
2
```

## 2.4 Importing Specific Functions Using Destructuring

Instead of importing the entire object, we can import only the required functions.

```javascript
const {
    add,
    subtract
} = require("./math");

console.log(add(10, 5));

console.log(subtract(10, 5));
```

This uses JavaScript object destructuring.

## 2.5 Difference Between exports and module.exports

This is an important interview and practical question.

Both are related to the CommonJS module system.

Initially:

```javascript
exports === module.exports
```

They refer to the same exported object.

### Using exports

```javascript
exports.name = "Anurag";

exports.course = "CMCE";
```

Import:

```javascript
const student = require("./student");

console.log(student.name);
console.log(student.course);
```

Output:

```text
Anurag
CMCE
```

### Using module.exports

```javascript
module.exports = {

    name: "Anurag",

    course: "CMCE"

};
```

Both approaches can export an object.

### Important difference

| exports | module.exports |
|---|---|
| Initially references `module.exports` | Actual object returned by `require()` |
| Commonly used to add properties | Can replace the entire exported value |
| Cannot safely replace the reference by assigning a new object to `exports` | Can export a function, object, class or other value |

Incorrect example:

```javascript
exports = {
    name: "Anurag"
};
```

This only changes the local `exports` variable. It does not replace `module.exports`.

Correct example:

```javascript
module.exports = {
    name: "Anurag"
};
```

**Important:** Use `module.exports` when you want to export a single function or replace the complete exported object.

## 2.6 How require() Works

When a CommonJS module is loaded using `require()`:

1. Node.js resolves the module.
2. It loads the module if necessary.
3. The module code is wrapped in a function.
4. The module is executed.
5. Its exported value is returned.
6. Node.js normally caches the loaded module.

Simplified module wrapper:

```javascript
(function(exports, require, module, __filename, __dirname) {

    // Module code

});
```

Important variables:

| Variable | Purpose |
|---|---|
| `exports` | Reference to the initial exported object |
| `require` | Loads other CommonJS modules |
| `module` | Represents the current module |
| `__filename` | Absolute filename of the current module |
| `__dirname` | Directory of the current module |

Example:

```javascript
console.log(__filename);

console.log(__dirname);
```

These CommonJS variables are not directly available in the same form inside standard ES modules.

---

# 3. Introduction to npm

## 3.1 What is npm?

npm stands for Node Package Manager.

It is the default package manager distributed with Node.js.

It is used to:
- Install packages.
- Update packages.
- Remove packages.
- Manage project dependencies.
- Execute package scripts.
- Publish and share packages.

### Definition for exams

npm is the default package manager for Node.js used to install, manage and share JavaScript packages and dependencies.

## 3.2 What is a Package?

A package is a collection of reusable code distributed through a package registry.

For example:

Express is a package that provides functionality for building web applications and APIs.

Axios is a package used to make HTTP requests.

### What is a dependency?

A dependency is an external package that an application needs to work.

For example:

If an application uses Express, Express becomes a dependency of that project.

## 3.3 npm Registry

The npm Registry is an online collection of JavaScript packages.

Official website:

https://www.npmjs.com/

Developers can:
- Search packages.
- View package documentation.
- Install packages.
- Check package versions.
- Publish their own packages.

## 3.4 Important npm Commands

| Command | Purpose |
|---|---|
| `npm -v` | Displays npm version |
| `npm init` | Creates package.json |
| `npm init -y` | Creates package.json with default values |
| `npm install` | Installs project dependencies |
| `npm install express` | Installs Express |
| `npm uninstall express` | Removes Express |
| `npm update` | Updates dependencies within allowed version ranges |
| `npm list` | Displays installed packages |
| `npm list -g` | Displays globally installed packages |
| `npm outdated` | Shows outdated packages |
| `npm audit` | Checks for known dependency vulnerabilities |
| `npm run` | Lists available package scripts |

---

# 4. package.json and package-lock.json

These two files are extremely important in Node.js applications.

## 4.1 What is package.json?

`package.json` is the main configuration file of a Node.js project.

It contains information about the application and its dependencies.

It can contain:
- Project name.
- Version.
- Description.
- Entry point.
- Scripts.
- Dependencies.
- Development dependencies.
- Module type.
- Other configuration information.

### Creating package.json

Create a project:

```bash
mkdir myapp
cd myapp
```

Run:

```bash
npm init
```

npm asks questions about your project.

Alternatively:

```bash
npm init -y
```

This automatically creates `package.json` using default values.

### Example package.json

```json
{
    "name": "myapp",
    "version": "1.0.0",
    "description": "My first Node.js application",
    "main": "app.js",
    "scripts": {
        "start": "node app.js"
    },
    "author": "Anurag",
    "license": "ISC"
}
```

### Important properties

| Property | Description |
|---|---|
| `name` | Project name |
| `version` | Project version |
| `description` | Project description |
| `main` | Package entry point |
| `scripts` | Commands that can be executed using npm |
| `dependencies` | Required runtime packages |
| `devDependencies` | Packages used mainly during development |
| `type` | Controls interpretation of `.js` files as CommonJS or ESM |

## 4.2 Dependencies

Dependencies are packages required by an application at runtime.

Example:

```bash
npm install express
```

After installation, package.json may contain:

```json
{
    "dependencies": {
        "express": "^5.1.0"
    }
}
```

The exact version depends on the version available when you install it.

## 4.3 Development Dependencies

Development dependencies are packages used mainly during development, testing or building.

Examples:
- Nodemon
- ESLint
- Jest
- TypeScript

Install Nodemon:

```bash
npm install --save-dev nodemon
```

The package is recorded under `devDependencies`.

Example:

```json
{
    "devDependencies": {
        "nodemon": "^3.1.0"
    }
}
```

### Dependencies vs DevDependencies

| dependencies | devDependencies |
|---|---|
| Required by the application at runtime | Used mainly during development |
| Example: Express | Example: Nodemon |
| Installed using `npm install package` | Installed using `npm install package --save-dev` |

## 4.4 What is package-lock.json?

`package-lock.json` is automatically generated by npm when dependency information is updated.

It records the exact resolved versions of installed packages and their dependency tree.

It helps maintain consistent installations across different systems.

### Why is package-lock.json important?

1. Records exact package versions.
2. Records dependency relationships.
3. Improves reproducibility.
4. Helps avoid unexpected dependency version differences.
5. Supports faster and more predictable installation.

### package.json vs package-lock.json

| package.json | package-lock.json |
|---|---|
| Project configuration file | Dependency lock file |
| Describes dependency requirements | Records exact resolved dependency versions |
| Usually written or modified by developers and npm | Usually generated and updated by npm |
| Contains scripts and metadata | Contains detailed dependency tree |
| Defines version ranges where applicable | Locks resolved versions |

### Important command

```bash
npm install
```

This reads the package configuration and installs the required dependencies.

If a compatible lock file is present, npm uses it to reproduce the locked dependency tree.

For a clean installation based on the lock file, use:

```bash
npm ci
```

`npm ci` is commonly used in CI/CD environments.

---

# 5. Install, Update and Manage Package Dependencies

## 5.1 Installing a Package

Example: Install Express.

```bash
npm install express
```

Short form:

```bash
npm i express
```

This installs Express into the project's `node_modules` directory and records it in package.json.

## 5.2 Installing Multiple Packages

```bash
npm install express axios cors
```

All three packages are installed.

## 5.3 Installing a Specific Version

```bash
npm install express@5
```

This installs a compatible version in the Express 5 major version line.

To install an exact version:

```bash
npm install express@5.1.0
```

## 5.4 Updating a Package

```bash
npm update express
```

This updates Express within the allowed version range defined by the project.

To check outdated packages:

```bash
npm outdated
```

To install a newer version outside the current allowed range, explicitly change the requested version, for example:

```bash
npm install express@latest
```

Always review major-version changes for breaking changes.

## 5.5 Uninstalling a Package

```bash
npm uninstall express
```

This removes Express from the project dependencies.

## 5.6 node_modules Directory

When packages are installed, npm creates a directory named:

```text
node_modules/
```

It contains the installed packages and their dependencies.

Example:

```text
myapp/
    |
    |-- node_modules/
    |      |
    |      |-- express/
    |      |-- body-parser/
    |      |-- ...
    |
    |-- package.json
    |-- package-lock.json
    |-- app.js
```

### Important point

Do not normally upload the `node_modules` directory to GitHub.

Instead, upload:
- package.json
- package-lock.json
- Application source code

Other developers can install the dependencies using:

```bash
npm install
```

## 5.7 npm Scripts

Scripts allow developers to define reusable commands in package.json.

Example:

```json
{
    "scripts": {
        "start": "node app.js",
        "dev": "nodemon app.js",
        "test": "node test.js"
    }
}
```

Run:

```bash
npm start
```

Run:

```bash
npm run dev
```

**Note:** `npm start` is a special built-in script shortcut. Other custom scripts are generally executed using `npm run script-name`.

---

# 6. Local and Global Packages

npm supports two main installation scopes.

## 6.1 Local Packages

A local package is installed inside a particular project.

Example:

```bash
npm install express
```

The package is installed in:

```text
project/
    |
    |-- node_modules/
    |      |
    |      |-- express/
```

Local packages are available to that project and can be imported in its source files.

Example:

```javascript
const express = require("express");
```

### Advantages

- Different projects can use different versions.
- Dependencies are recorded in package.json.
- Easier project management.
- Better reproducibility.

## 6.2 Global Packages

Global packages are installed at the system or user level.

Command:

```bash
npm install -g nodemon
```

The `-g` option means global installation.

After installation, you can execute Nodemon from the terminal:

```bash
nodemon app.js
```

Global packages are generally used for command-line tools.

Examples:
- Nodemon
- TypeScript compiler (`tsc`)
- Angular CLI

### Local vs Global Packages

| Local | Global |
|---|---|
| Installed inside a project | Installed in a global npm location |
| Used mainly as project dependencies | Used mainly as command-line tools |
| Recorded in package.json | Not recorded as a project dependency |
| Different projects can use different versions | Shared global installation |
| Example: Express | Example: Nodemon |

**Best practice:** Prefer local project dependencies for application libraries. Use global installation only when a shared command-line tool is useful.

---

# 7. File I/O – Synchronous and Asynchronous Methods

## 7.1 What is File I/O?

File I/O stands for File Input/Output.

It refers to reading, writing, creating, updating and deleting files.

Node.js provides the built-in `fs` module for file system operations.

Import:

```javascript
const fs = require("fs");
```

Common operations:

1. Create a file.
2. Write data to a file.
3. Read a file.
4. Append data.
5. Rename a file.
6. Delete a file.

## 7.2 Synchronous File Operations

Synchronous file operations block the JavaScript execution thread until the operation finishes.

Examples:

| Method | Purpose |
|---|---|
| `writeFileSync()` | Creates or overwrites a file |
| `readFileSync()` | Reads file contents |
| `appendFileSync()` | Appends content |
| `unlinkSync()` | Deletes a file |
| `renameSync()` | Renames a file |
| `mkdirSync()` | Creates a directory |

### Example: Writing a File Synchronously

```javascript
const fs = require("fs");

fs.writeFileSync(
    "student.txt",
    "Welcome to CMCE"
);

console.log("File created successfully");
```

Output:

```text
File created successfully
```

A file named `student.txt` is created in the current working directory.

If the file already exists, `writeFileSync()` normally replaces its contents.

### Example: Reading a File Synchronously

```javascript
const fs = require("fs");

const data = fs.readFileSync(
    "student.txt",
    "utf8"
);

console.log(data);
```

Output:

```text
Welcome to CMCE
```

Here, `utf8` tells Node.js to return the file contents as a string.

Without an encoding, the method returns a Buffer.

## 7.3 Asynchronous File Operations

Asynchronous file operations allow Node.js to continue executing other work while the file operation is in progress.

Examples:

| Method | Purpose |
|---|---|
| `writeFile()` | Writes a file asynchronously |
| `readFile()` | Reads a file asynchronously |
| `appendFile()` | Appends content asynchronously |
| `unlink()` | Deletes a file asynchronously |
| `rename()` | Renames a file asynchronously |

These traditional callback-based methods are commonly used in Node.js.

### Example: Writing a File Asynchronously

```javascript
const fs = require("fs");

fs.writeFile(
    "student.txt",
    "Learning Node.js",
    (err) => {

        if (err) {
            console.log(err.message);
            return;
        }

        console.log("File written successfully");

    }
);

console.log("Other code executing");
```

The final console message may appear before the file-writing callback executes.

### Example: Reading a File Asynchronously

```javascript
const fs = require("fs");

fs.readFile(
    "student.txt",
    "utf8",
    (err, data) => {

        if (err) {
            console.log(err.message);
            return;
        }

        console.log(data);

    }
);

console.log("Reading started");
```

Possible output:

```text
Reading started
Learning Node.js
```

The callback executes when the file-reading operation completes.

## 7.4 Synchronous vs Asynchronous File I/O

| Synchronous | Asynchronous |
|---|---|
| Blocks JavaScript execution until completion | Allows other work to continue |
| Simpler sequential code | Uses callback, Promise or async/await |
| Uses methods ending in `Sync` | Uses callback or Promise-based methods |
| Useful for simple scripts and startup tasks | Useful for normal server applications |
| Can reduce server responsiveness when used for large operations | Better suited for concurrent I/O workloads |

## 7.5 Promise-Based File I/O

Node.js also provides Promise-based file operations through `fs/promises`.

Example:

```javascript
const fs = require("fs/promises");

async function readStudentFile() {

    try {

        const data = await fs.readFile(
            "student.txt",
            "utf8"
        );

        console.log(data);

    } catch (error) {

        console.log(error.message);

    }

}

readStudentFile();
```

This is particularly useful when working with async/await.

---

# 8. HTTP Module – Building an HTTP Server

## 8.1 What is HTTP?

HTTP stands for Hypertext Transfer Protocol.

It is an application-layer protocol used for communication between clients and servers.

For example:

When you open a website:

1. Browser sends an HTTP request.
2. Server receives the request.
3. Server processes it.
4. Server sends an HTTP response.
5. Browser displays the response.

## 8.2 What is an HTTP Server?

An HTTP server is software that listens for HTTP requests and sends appropriate responses to clients.

Node.js provides a built-in `http` module to create HTTP servers.

No additional npm installation is required.

Import:

```javascript
const http = require("http");
```

## 8.3 Creating a Basic HTTP Server

Create `server.js`:

```javascript
const http = require("http");

const server = http.createServer((req, res) => {

    res.writeHead(200, {
        "Content-Type": "text/plain"
    });

    res.end("Hello from Node.js Server");

});

server.listen(3000, () => {

    console.log("Server running on port 3000");

});
```

Run:

```bash
node server.js
```

Output:

```text
Server running on port 3000
```

Open your browser:

```text
http://localhost:3000
```

You should see:

```text
Hello from Node.js Server
```

## 8.4 Understanding the Code

### 1. Import HTTP Module

```javascript
const http = require("http");
```

Imports Node.js's built-in HTTP module.

### 2. Create Server

```javascript
const server = http.createServer((req, res) => {

});
```

Creates an HTTP server.

The callback receives two important objects:

- `req` – Incoming request.
- `res` – Outgoing response.

### 3. Write Response Header

```javascript
res.writeHead(200, {
    "Content-Type": "text/plain"
});
```

Specifies:
- HTTP status code: 200.
- Content type: plain text.

### 4. Send Response

```javascript
res.end("Hello from Node.js Server");
```

Sends the response and ends the response stream.

### 5. Start Server

```javascript
server.listen(3000);
```

Starts listening for requests on port 3000.

## 8.5 Important HTTP Request Properties

The request object provides information about the incoming request.

| Property | Description |
|---|---|
| `req.method` | HTTP method |
| `req.url` | Request URL |
| `req.headers` | Request headers |
| `req.httpVersion` | HTTP protocol version |
| `req.socket` | Underlying network socket |

Example:

```javascript
const http = require("http");

const server = http.createServer((req, res) => {

    console.log("Method:", req.method);

    console.log("URL:", req.url);

    console.log("Headers:", req.headers);

    res.end("Request received");

});

server.listen(3000);
```

## 8.6 Important Response Methods

| Method | Purpose |
|---|---|
| `res.writeHead()` | Sets status code and response headers |
| `res.setHeader()` | Sets an individual response header |
| `res.write()` | Writes response data |
| `res.end()` | Ends the response |
| `res.statusCode` | Sets the response status code |

---

# 9. HTTP GET and POST Methods

HTTP methods define the action a client wants the server to perform.

Two important methods are GET and POST.

## 9.1 GET Method

GET is used to retrieve data from a server.

Example:

```text
GET /students
```

This requests student information.

### GET Example Using Node.js HTTP Module

```javascript
const http = require("http");

const server = http.createServer((req, res) => {

    if (req.method === "GET" && req.url === "/") {

        res.writeHead(200, {
            "Content-Type": "text/plain"
        });

        res.end("Welcome to Node.js");

    }

});

server.listen(3000, () => {

    console.log("Server started");

});
```

Open:

```text
http://localhost:3000/
```

## 9.2 POST Method

POST is used to send data to a server.

For example, a registration form sends student details to a backend.

POST request:

```text
POST /students
```

The request body can contain JSON data.

### How does Node.js receive POST data?

The incoming HTTP request is a readable stream.

We can collect its data using:
- `data` event
- `end` event

Example:

```javascript
const http = require("http");

const server = http.createServer((req, res) => {

    if (req.method === "POST" && req.url === "/student") {

        let body = "";

        req.on("data", chunk => {

            body += chunk.toString();

        });

        req.on("end", () => {

            const student = JSON.parse(body);

            console.log(student);

            res.writeHead(201, {
                "Content-Type": "application/json"
            });

            res.end(JSON.stringify({
                message: "Student received",
                student: student
            }));

        });

    }

});

server.listen(3000);
```

### Explanation

1. Client sends a POST request.
2. Server checks the HTTP method and URL.
3. `data` event receives incoming chunks.
4. Chunks are combined into a string.
5. `end` event indicates that the request body has been received.
6. `JSON.parse()` converts the JSON string into a JavaScript object.
7. Server sends a response.

For production applications, validate the content type and input, and handle invalid JSON safely.

---

# 10. Developing a Node.js Web Application

A Node.js web application is an application that uses Node.js to handle backend operations and communicate with clients through HTTP.

A simple web application may contain:

1. Server.
2. Routes.
3. Request handling.
4. Business logic.
5. Response generation.

## 10.1 Basic Architecture

```text
        Client / Browser
               |
               |
           HTTP Request
               |
               v
        Node.js HTTP Server
               |
               v
         Request Handling
               |
               v
          Business Logic
               |
               v
        HTTP Response
               |
               v
        Client / Browser
```

## 10.2 Developing a Simple Application Using Core HTTP Module

We will build a student application that supports:

- GET `/` – Home page.
- GET `/students` – Display students.
- POST `/students` – Add a student.

### Step 1 – Create Project

```bash
mkdir student-app
cd student-app
```

Create:

```text
student-app/
    |
    |-- server.js
```

### Step 2 – Write server.js

```javascript
const http = require("http");

const students = [
    {
        id: 1,
        name: "Anurag",
        course: "CMCE"
    },
    {
        id: 2,
        name: "Rahul",
        course: "CMCE"
    }
];

const server = http.createServer((req, res) => {

    // GET Home
    if (req.method === "GET" && req.url === "/") {

        res.writeHead(200, {
            "Content-Type": "text/plain"
        });

        res.end("Welcome to Student Management System");

    }

    // GET Students
    else if (
        req.method === "GET" &&
        req.url === "/students"
    ) {

        res.writeHead(200, {
            "Content-Type": "application/json"
        });

        res.end(JSON.stringify(students));

    }

    // POST Student
    else if (
        req.method === "POST" &&
        req.url === "/students"
    ) {

        let body = "";

        req.on("data", chunk => {

            body += chunk.toString();

        });

        req.on("end", () => {

            try {

                const student = JSON.parse(body);

                const newStudent = {
                    id: students.length + 1,
                    name: student.name,
                    course: student.course
                };

                if (
                    typeof student.name !== "string" ||
                    !student.name.trim() ||
                    typeof student.course !== "string" ||
                    !student.course.trim()
                ) {

                    res.writeHead(400, {
                        "Content-Type": "application/json"
                    });

                    res.end(JSON.stringify({
                        message: "Valid name and course are required"
                    }));

                    return;

                }

                students.push(newStudent);

                res.writeHead(201, {
                    "Content-Type": "application/json"
                });

                res.end(JSON.stringify({
                    message: "Student added successfully",
                    student: newStudent
                }));

            } catch (error) {

                res.writeHead(400, {
                    "Content-Type": "application/json"
                });

                res.end(JSON.stringify({
                    message: "Invalid JSON"
                }));

            }

        });

    }

    // Invalid Route
    else {

        res.writeHead(404, {
            "Content-Type": "text/plain"
        });

        res.end("404 - Page Not Found");

    }

});

server.listen(3000, () => {

    console.log("Server running at http://localhost:3000");

});
```

### Step 3 – Run the Application

```bash
node server.js
```

Output:

```text
Server running at http://localhost:3000
```

### Step 4 – Test GET Request

Open the browser:

```text
http://localhost:3000/
```

Output:

```text
Welcome to Student Management System
```

Test:

```text
http://localhost:3000/students
```

Output:

```json
[
    {
        "id": 1,
        "name": "Anurag",
        "course": "CMCE"
    },
    {
        "id": 2,
        "name": "Rahul",
        "course": "CMCE"
    }
]
```

### Step 5 – Test POST Request Using Thunder Client

Install the Thunder Client extension in VS Code or use Postman.

Select:

```text
POST http://localhost:3000/students
```

Choose:

```text
Body → JSON
```

Send:

```json
{
    "name": "Sushant",
    "course": "CMCE"
}
```

Expected response:

```json
{
    "message": "Student added successfully",
    "student": {
        "id": 3,
        "name": "Sushant",
        "course": "CMCE"
    }
}
```

Now send a GET request again:

```text
GET http://localhost:3000/students
```

The newly added student will appear.

**Important:** This example stores student data in memory. Data will be lost when the server restarts. A real application should use a database such as MySQL or MongoDB.

---

# 11. Lab Practical 1 – Create a Module and Import It into Other Programs

## Objective

Create a user-defined Node.js module and import it into another JavaScript file.

### Folder Structure

```text
module-practice/
    |
    |-- math.js
    |-- app.js
```

### Step 1 – Create math.js

```javascript
function add(a, b) {

    return a + b;

}

function subtract(a, b) {

    return a - b;

}

function multiply(a, b) {

    return a * b;

}

module.exports = {
    add,
    subtract,
    multiply
};
```

### Step 2 – Create app.js

```javascript
const math = require("./math");

console.log("Addition:", math.add(10, 5));

console.log("Subtraction:", math.subtract(10, 5));

console.log("Multiplication:", math.multiply(10, 5));
```

### Step 3 – Execute

```bash
node app.js
```

Output:

```text
Addition: 15
Subtraction: 5
Multiplication: 50
```

### Learning Outcome

- Understand user-defined modules.
- Understand `module.exports`.
- Understand `require()`.
- Reuse functions across files.

---

# 12. Lab Practical 2 – Install a Module/Package Using npm

## Objective

Create a Node.js project and install a third-party package using npm.

We will install the Lodash package.

### Step 1 – Create Project

```bash
mkdir npm-practice
cd npm-practice
```

### Step 2 – Initialize npm

```bash
npm init -y
```

This creates:

```text
package.json
```

### Step 3 – Install Lodash

```bash
npm install lodash
```

npm creates:

```text
node_modules/
package-lock.json
```

### Step 4 – Create app.js

```javascript
const _ = require("lodash");

const numbers = [10, 20, 30, 40, 50];

const reversed = _.reverse([...numbers]);

console.log(reversed);
```

Output:

```text
[ 50, 40, 30, 20, 10 ]
```

Here:
- `lodash` is a third-party package.
- `require("lodash")` imports it.
- `_.reverse()` reverses the array.

### Step 5 – Run

```bash
node app.js
```

### Step 6 – Check Installed Package

```bash
npm list
```

### Step 7 – Uninstall Package

```bash
npm uninstall lodash
```

### Learning Outcome

- Initialize npm.
- Install a package.
- Import a package.
- Execute a program using a package.
- Understand node_modules and package.json.

---

# 13. Lab Practical 3 – Synchronous Write and Asynchronous Read

## Problem Statement

Write a Node.js program to:

1. Create a new file.
2. Write some content into the file using synchronous mode.
3. Read the file using asynchronous mode.
4. Display the file contents on standard output.

## Program

Create `file-demo.js`:

```javascript
const fs = require("fs");

// Step 1: Write file synchronously

fs.writeFileSync(
    "demo.txt",
    "Welcome to Node.js File Handling\nLearning CMCE"
);

console.log("File created successfully");

// Step 2: Read file asynchronously

fs.readFile(
    "demo.txt",
    "utf8",
    (err, data) => {

        if (err) {

            console.log("Error:", err.message);

            return;

        }

        console.log("File Contents:");

        console.log(data);

    }
);

console.log("Other operations can continue");
```

### Execute

```bash
node file-demo.js
```

### Expected Output

```text
File created successfully
Other operations can continue
File Contents:
Welcome to Node.js File Handling
Learning CMCE
```

### Explanation

**Synchronous write:**

```javascript
fs.writeFileSync("demo.txt", "Hello");
```

- Creates a file if it does not exist.
- Replaces the content if it already exists.
- Blocks execution until writing finishes.

**Asynchronous read:**

```javascript
fs.readFile("demo.txt", "utf8", callback);
```

- Starts reading the file.
- Allows other JavaScript code to continue.
- Executes the callback when reading finishes.

**Standard output:** In Node.js, `console.log()` writes output to the standard output stream, commonly the terminal.

---

# 14. Lab Practical 4 – Build a Simple Node.js Web Application Serving GET and POST

## Objective

Create an HTTP server using Node.js that supports both GET and POST requests.

### Folder Structure

```text
http-app/
    |
    |-- server.js
    |-- package.json
```

### Step 1 – Create Project

```bash
mkdir http-app
cd http-app
npm init -y
```

No external package is needed because we will use the built-in HTTP module.

### Step 2 – Create server.js

```javascript
const http = require("http");

const students = [];

const server = http.createServer((req, res) => {

    // GET request
    if (req.method === "GET" && req.url === "/") {

        res.writeHead(200, {
            "Content-Type": "text/plain"
        });

        res.end("Node.js HTTP Application");

    }

    // GET all students
    else if (
        req.method === "GET" &&
        req.url === "/students"
    ) {

        res.writeHead(200, {
            "Content-Type": "application/json"
        });

        res.end(JSON.stringify(students));

    }

    // POST student
    else if (
        req.method === "POST" &&
        req.url === "/students"
    ) {

        let body = "";

        req.on("data", chunk => {

            body += chunk.toString();

        });

        req.on("end", () => {

            try {

                const student = JSON.parse(body);

                if (
                    typeof student.name !== "string" ||
                    !student.name.trim()
                ) {

                    res.writeHead(400, {
                        "Content-Type": "application/json"
                    });

                    res.end(JSON.stringify({
                        message: "Student name is required"
                    }));

                    return;

                }

                const newStudent = {
                    id: students.length + 1,
                    name: student.name
                };

                students.push(newStudent);

                res.writeHead(201, {
                    "Content-Type": "application/json"
                });

                res.end(JSON.stringify({
                    message: "Student added",
                    data: newStudent
                }));

            } catch (error) {

                res.writeHead(400, {
                    "Content-Type": "application/json"
                });

                res.end(JSON.stringify({
                    message: "Invalid JSON"
                }));

            }

        });

    }

    else {

        res.writeHead(404);

        res.end("Route Not Found");

    }

});

server.listen(3000, () => {

    console.log("Server running on port 3000");

});
```

### Step 3 – Start Server

```bash
node server.js
```

### Step 4 – Test GET

```text
GET http://localhost:3000/
```

Response:

```text
Node.js HTTP Application
```

Test:

```text
GET http://localhost:3000/students
```

Response:

```json
[]
```

### Step 5 – Test POST

URL:

```text
POST http://localhost:3000/students
```

Body:

```json
{
    "name": "Anurag"
}
```

Response:

```json
{
    "message": "Student added",
    "data": {
        "id": 1,
        "name": "Anurag"
    }
}
```

### Step 6 – Verify GET Again

```text
GET http://localhost:3000/students
```

Response:

```json
[
    {
        "id": 1,
        "name": "Anurag"
    }
]
```

### Important HTTP Status Codes

| Status Code | Meaning |
|---|---|
| 200 | OK |
| 201 | Created |
| 400 | Bad Request |
| 404 | Not Found |
| 500 | Internal Server Error |

---

# 15. Common Errors and Troubleshooting

## 1. Cannot find module

Example:

```text
Error: Cannot find module 'express'
```

Reason:
- Package is not installed.
- Wrong module name.
- Incorrect module path.

Solution:

```bash
npm install express
```

For local modules, check the relative path:

```javascript
require("./math");
```

## 2. Cannot use import statement outside a module

Reason:

You are using ES module syntax in a file configured as CommonJS.

Solution:

Add the following to package.json:

```json
{
    "type": "module"
}
```

Or use CommonJS:

```javascript
const fs = require("fs");
```

## 3. EADDRINUSE

Example:

```text
Error: listen EADDRINUSE
```

Reason:

The port is already being used by another process.

Solution:
- Stop the other server.
- Use another available port.

## 4. ENOENT

Example:

```text
Error: ENOENT: no such file or directory
```

Reason:

Node.js cannot find the specified file or directory.

Solution:
- Check the filename.
- Check the file path.
- Check the current working directory.

## 5. JSON Parse Error

Reason:

The request body is not valid JSON.

Solution:

Check the JSON syntax and send the correct Content-Type header.

---

# 16. Important Interview and CCEE Questions

**Q1. What is a Node.js module?**

A reusable block of JavaScript code that can be exported and imported into other files.

**Q2. What are the types of Node.js modules?**

Core modules, local modules and third-party modules.

**Q3. What is require()?**

A CommonJS function used to load modules.

**Q4. What is module.exports?**

It defines the value that a CommonJS module exports.

**Q5. What is the difference between exports and module.exports?**

`exports` initially references `module.exports`, but assigning a new value to `exports` alone does not change what `require()` returns.

**Q6. What is npm?**

The default package manager distributed with Node.js.

**Q7. What is package.json?**

A project configuration file containing metadata, scripts and dependency requirements.

**Q8. What is package-lock.json?**

A lock file containing the resolved dependency versions and dependency tree.

**Q9. What is node_modules?**

The directory containing installed packages and their dependencies.

**Q10. What is the difference between dependencies and devDependencies?**

Dependencies are required by the application at runtime, whereas devDependencies are mainly used during development.

**Q11. What is the difference between local and global packages?**

Local packages are installed inside a project, whereas global packages are installed in a shared npm location.

**Q12. What is the fs module?**

A built-in Node.js module used for file system operations.

**Q13. What is the difference between writeFileSync() and writeFile()?**

`writeFileSync()` blocks execution until writing completes, whereas `writeFile()` performs the operation asynchronously.

**Q14. What is the difference between readFileSync() and readFile()?**

`readFileSync()` reads the file synchronously, whereas `readFile()` reads it asynchronously using a callback.

**Q15. What is the HTTP module?**

A built-in Node.js module used to create HTTP servers and handle HTTP communication.

**Q16. What is createServer()?**

A method of the HTTP module used to create an HTTP server.

**Q17. What are req and res?**

`req` represents the incoming HTTP request, and `res` represents the outgoing HTTP response.

**Q18. What is the purpose of res.end()?**

It completes the HTTP response and can send the final response data.

**Q19. What is the difference between GET and POST?**

GET retrieves data, while POST sends data to the server.

**Q20. Is Express required to create an HTTP server in Node.js?**

No. Node.js provides the built-in HTTP module. Express is an optional third-party framework.

---

# 17. Multiple Choice Questions (MCQs)

**1. Which function is used to import a CommonJS module?**

A. import()  
B. require()  
C. export()  
D. include()

**Answer: B. require()**

**2. Which property is used to export a module in CommonJS?**

A. module.import  
B. module.exports  
C. module.require  
D. module.include

**Answer: B. module.exports**

**3. Which module is built into Node.js?**

A. Express  
B. Axios  
C. fs  
D. Lodash

**Answer: C. fs**

**4. What is npm?**

A. Database  
B. Package manager  
C. Programming language  
D. Web browser

**Answer: B. Package manager**

**5. Which command creates package.json with default values?**

A. npm install  
B. npm init -y  
C. npm start  
D. node init

**Answer: B. npm init -y**

**6. Which file records exact resolved dependency versions?**

A. app.js  
B. package.json  
C. package-lock.json  
D. index.html

**Answer: C. package-lock.json**

**7. Which command installs a package globally?**

A. npm install express  
B. npm install -g express  
C. npm init express  
D. node install express

**Answer: B. npm install -g express**

**8. Which directory contains installed npm packages?**

A. public  
B. node_modules  
C. src  
D. assets

**Answer: B. node_modules**

**9. Which command installs Nodemon as a development dependency?**

A. npm install nodemon  
B. npm install -g nodemon  
C. npm install --save-dev nodemon  
D. node install nodemon

**Answer: C. npm install --save-dev nodemon**

**10. Which method writes a file synchronously?**

A. writeFile()  
B. writeFileSync()  
C. readFile()  
D. appendFile()

**Answer: B. writeFileSync()**

**11. Which method reads a file asynchronously using a callback?**

A. readFileSync()  
B. readFile()  
C. writeFileSync()  
D. createServer()

**Answer: B. readFile()**

**12. Which built-in module creates an HTTP server?**

A. fs  
B. path  
C. http  
D. os

**Answer: C. http**

**13. Which method creates an HTTP server?**

A. http.create()  
B. http.createServer()  
C. http.server()  
D. http.listen()

**Answer: B. http.createServer()**

**14. Which object represents the incoming HTTP request?**

A. res  
B. req  
C. server  
D. response

**Answer: B. req**

**15. Which method completes an HTTP response?**

A. res.start()  
B. res.end()  
C. res.close()  
D. res.stop()

**Answer: B. res.end()**

**16. Which HTTP method is used to retrieve data?**

A. POST  
B. DELETE  
C. GET  
D. PATCH

**Answer: C. GET**

**17. Which HTTP status code indicates successful resource creation?**

A. 200  
B. 201  
C. 400  
D. 404

**Answer: B. 201**

**18. Which function converts a JavaScript object into a JSON string?**

A. JSON.parse()  
B. JSON.stringify()  
C. JSON.convert()  
D. JSON.read()

**Answer: B. JSON.stringify()**

**19. Which function converts a JSON string into a JavaScript object?**

A. JSON.stringify()  
B. JSON.parse()  
C. JSON.write()  
D. JSON.convert()

**Answer: B. JSON.parse()**

**20. Is the HTTP module a third-party package?**

A. Yes  
B. No  
C. Only in Windows  
D. Only in Linux

**Answer: B. No**

---

# 18. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Module | Reusable code unit |
| Core module | Built into Node.js |
| Local module | Created by developer |
| Third-party module | Installed through npm |
| require() | Imports CommonJS modules |
| module.exports | Exports module value |
| exports | Initially references module.exports |
| npm | Node Package Manager |
| package.json | Project metadata and dependency requirements |
| package-lock.json | Locks resolved dependency versions |
| node_modules | Installed packages |
| dependencies | Runtime packages |
| devDependencies | Development packages |
| Local package | Installed inside project |
| Global package | Installed in global npm location |
| fs | File system module |
| writeFileSync() | Synchronous file writing |
| readFileSync() | Synchronous file reading |
| writeFile() | Asynchronous file writing |
| readFile() | Asynchronous file reading |
| http | HTTP server module |
| createServer() | Creates an HTTP server |
| req | Incoming request |
| res | Outgoing response |
| res.writeHead() | Sets status and headers |
| res.end() | Ends response |
| GET | Retrieves data |
| POST | Sends data |
| 200 | OK |
| 201 | Created |
| 400 | Bad Request |
| 404 | Not Found |

---

# 19. Additional Self-Learning Programs

1. Create a module to calculate the area of a circle and import it into another file.
2. Create a student module containing student details and display them in another file.
3. Install Lodash using npm and perform array operations.
4. Install Nodemon as a development dependency.
5. Write a program to append data to a file.
6. Write a program to rename a file.
7. Write a program to delete a file asynchronously.
8. Create an HTTP server that displays different messages for different routes.
9. Create a GET endpoint to display product details.
10. Create a POST endpoint to add new products.
11. Build a simple student registration server.
12. Test GET and POST requests using Thunder Client.

---

# 20. Final Practical Checklist

- [ ] Understand Node.js modules.
- [ ] Understand core, local and third-party modules.
- [ ] Use require() to import modules.
- [ ] Use module.exports to export functions and objects.
- [ ] Understand exports vs module.exports.
- [ ] Understand npm and npm registry.
- [ ] Create package.json.
- [ ] Understand package-lock.json.
- [ ] Install and uninstall packages.
- [ ] Understand dependencies and devDependencies.
- [ ] Understand local and global packages.
- [ ] Perform synchronous file operations.
- [ ] Perform asynchronous file operations.
- [ ] Understand the Node.js HTTP module.
- [ ] Create an HTTP server.
- [ ] Handle GET requests.
- [ ] Handle POST requests.
- [ ] Test APIs using Thunder Client or Postman.

## 21. Official References

1. [Node.js Modules Documentation](https://nodejs.org/api/modules.html)
2. [Node.js File System Documentation](https://nodejs.org/api/fs.html)
3. [Node.js HTTP Documentation](https://nodejs.org/api/http.html)
4. [Node.js Packages Documentation](https://nodejs.org/api/packages.html)
5. [npm Official Documentation](https://docs.npmjs.com/)
6. [npm Package Registry](https://www.npmjs.com/)
7. [MDN – HTTP Overview](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview)

**End of Session 19 – Node.js Modules**
