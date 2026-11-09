# Session 15 – Introduction to Node.js

**Course:** CMCE – August 2026 Batch  
**Subject:** Web Programming Technologies

# 1. Introduction to Node.js

## 1.1 What is Node.js?

Node.js is an open-source, cross-platform JavaScript runtime environment that allows developers to execute JavaScript code outside a web browser.

Traditionally, JavaScript was primarily used inside web browsers to make web pages interactive.

With Node.js, JavaScript can also run on the server side.

**Definition for exams:**

Node.js is an open-source, cross-platform JavaScript runtime environment built on Chrome's V8 JavaScript engine, used to execute JavaScript outside the browser.

### Why was Node.js introduced?

Earlier, JavaScript was mainly used for frontend development.

For backend development, developers commonly used languages such as:
- Java
- PHP
- Python
- C#
- Ruby

Node.js made it possible to use JavaScript for both frontend and backend development.

For example:

Before Node.js:

```text
Frontend: JavaScript
Backend:  Java / PHP / Python
Database: MySQL
```

Using Node.js:

```text
Frontend: JavaScript / React
Backend:  JavaScript / Node.js
Database: MySQL / MongoDB
```

This allows developers to use JavaScript throughout the application.

## 1.2 History of Node.js

Important historical points:

- Node.js was initially released in 2009.
- It was created by Ryan Dahl.
- It uses Google's V8 JavaScript engine.
- It introduced an event-driven, non-blocking I/O model.
- It became popular for building scalable network applications.

## 1.3 What is V8 JavaScript Engine?

V8 is an open-source JavaScript engine developed by Google.

It is written primarily in C++ and is used in Google Chrome and Node.js.

Its main responsibility is to execute JavaScript code.

### How does V8 work?

Consider:

```javascript
let a = 10;
let b = 20;

console.log(a + b);
```

V8 processes and executes the JavaScript code.

Simplified execution flow:

```text
JavaScript Code
      |
      v
V8 JavaScript Engine
      |
      v
Parsing and Compilation
      |
      v
Execution
      |
      v
Output
```

V8 uses techniques including interpretation and Just-In-Time (JIT) compilation to execute JavaScript efficiently.

**Remember:** Node.js is not a programming language. It is a runtime environment for JavaScript.

## 1.4 Features of Node.js

### 1. JavaScript Runtime

Node.js allows JavaScript to run outside browsers.

### 2. Asynchronous Programming

Node.js supports asynchronous programming, allowing operations to complete without unnecessarily blocking the main JavaScript execution thread.

### 3. Non-blocking I/O

Input/output operations can be handled asynchronously.

For example:
- Reading files
- Accessing databases
- Sending HTTP requests
- Communicating with servers

### 4. Event-driven Architecture

Node.js uses events and callbacks to manage asynchronous operations.

### 5. Single-threaded JavaScript Execution

JavaScript application code normally runs on a single main thread in a Node.js environment.

However, Node.js can use background facilities such as its worker pool and additional threads for certain operations.

### 6. Cross-platform

Node.js works on:
- Windows
- Linux
- macOS

### 7. NPM Support

Node.js comes with npm, the Node Package Manager.

It allows developers to install and manage external packages.

### 8. Scalable Applications

Its asynchronous, event-driven architecture is useful for applications that handle many concurrent connections.

## 1.5 Applications of Node.js

Node.js is commonly used for:

1. REST API development.
2. Backend development.
3. Real-time chat applications.
4. Streaming applications.
5. Microservices.
6. Command-line tools.
7. Web servers.
8. Real-time dashboards.

Examples of technologies using Node.js include Express.js, NestJS and Socket.IO.

---

# 2. Browser JavaScript vs Node.js

JavaScript can execute in different runtime environments.

The two important environments in this syllabus are:

1. Browser JavaScript
2. Node.js

Both execute JavaScript, but their available APIs and purposes are different.

## 2.1 Browser JavaScript

Browser JavaScript executes inside a web browser.

Examples:
- Google Chrome
- Mozilla Firefox
- Microsoft Edge
- Safari

Its main purpose is to make web pages interactive.

### Browser JavaScript example

```html
<!DOCTYPE html>
<html>
<head>
    <title>Browser JavaScript</title>
</head>
<body>

    <h1 id="heading">Hello</h1>

    <button onclick="changeText()">
        Click Me
    </button>

    <script>

        function changeText() {

            document.getElementById("heading").innerText =
                "Welcome to JavaScript";

        }

    </script>

</body>
</html>
```

Here:
- `document` represents the webpage.
- `getElementById()` selects an HTML element.
- `innerText` changes its text.

These are browser-provided APIs.

## 2.2 Node.js JavaScript

Node.js executes JavaScript outside the browser.

It is commonly used for backend development and command-line applications.

Example:

Create a file:

```text
app.js
```

Code:

```javascript
console.log("Hello from Node.js");
```

Run:

```bash
node app.js
```

Output:

```text
Hello from Node.js
```

Notice that we do not need an HTML file or browser.

## 2.3 Browser JavaScript vs Node.js

| Feature | Browser JavaScript | Node.js |
|---|---|---|
| Execution environment | Web browser | Node.js runtime |
| Main purpose | Frontend development | Backend and server-side development |
| JavaScript engine | Browser's JS engine | V8 in standard Node.js builds |
| DOM | Available | Not built in |
| `document` | Available in normal browser pages | Not available by default |
| `window` | Available in browsers | Not available by default |
| File system access | Restricted browser APIs | Node.js `fs` module |
| HTTP server | Not normally provided directly by browser JS | Can be created using built-in modules |
| Package management | No built-in npm workflow | npm is bundled with Node.js |
| Module systems | ES modules and browser module scripts | CommonJS and ES modules |
| Process information | Limited browser environment | `process` object |

### Important difference: DOM

DOM stands for Document Object Model.

The DOM represents the structure of an HTML document as a tree of objects.

Browser JavaScript can manipulate the DOM.

Example:

```javascript
document.getElementById("demo").innerHTML =
    "Hello World";
```

In Node.js, `document` is not available by default because Node.js does not provide a browser DOM.

### Important difference: File System

Node.js provides the built-in `fs` module to work with files.

Example:

```javascript
const fs = require("fs");

fs.writeFileSync(
    "hello.txt",
    "Hello from Node.js"
);

console.log("File created");
```

This creates a file named `hello.txt`.

### Can we use JavaScript in both environments?

Yes.

The JavaScript language syntax is largely the same, but available runtime APIs differ.

For example:

```javascript
console.log("Hello JavaScript");
```

This works in both browser JavaScript and Node.js.

However:

```javascript
document.write("Hello");
```

works in a normal browser page but not in standard Node.js without an additional DOM implementation.

**Important exam point:** JavaScript is the language. Browser and Node.js are different runtime environments.

---

# 3. Node.js REPL

## 3.1 What is REPL?

REPL stands for:

- R – Read
- E – Evaluate
- P – Print
- L – Loop

REPL is an interactive environment that allows developers to execute JavaScript statements directly from the terminal.

It reads the entered code, evaluates it, prints the result and waits for the next command.

### Definition for exams

REPL is an interactive command-line environment in Node.js that reads, evaluates and prints JavaScript expressions repeatedly.

## 3.2 How to start Node.js REPL?

Open Command Prompt or terminal.

Enter:

```bash
node
```

You will see a prompt similar to:

```text
Welcome to Node.js
>
```

Now you can execute JavaScript statements directly.

### Example 1 – Arithmetic

```javascript
> 10 + 20
30
```

### Example 2 – Variables

```javascript
> let a = 10
undefined

> let b = 20
undefined

> a + b
30
```

The `undefined` output after a declaration is normal because a variable declaration does not produce a useful expression value.

### Example 3 – String

```javascript
> "Hello " + "Node.js"
'Hello Node.js'
```

### Example 4 – Function

```javascript
> function add(a, b) {
... return a + b;
... }
undefined

> add(10, 20)
30
```

### Example 5 – Array

```javascript
> const numbers = [10, 20, 30]
undefined

> numbers.length
3
```

### Example 6 – Object

```javascript
> const student = {
... name: "Anurag",
... course: "CMCE"
... }
undefined

> student.name
'Anurag'
```

## 3.3 REPL Commands

Some useful REPL commands:

| Command | Purpose |
|---|---|
| `.help` | Displays available REPL commands |
| `.exit` | Exits REPL |
| `.clear` | Clears the current REPL context |
| `.save filename` | Saves the current REPL session |
| `.load filename` | Loads a JavaScript file into REPL |

You can also exit REPL by pressing:

```text
Ctrl + C twice
```

or:

```text
Ctrl + D
```

## 3.4 REPL vs JavaScript File Execution

| REPL | JavaScript File |
|---|---|
| Executes code interactively | Executes code from a file |
| Useful for testing small expressions | Useful for complete programs |
| No file creation required | Requires a `.js` file |
| Starts using `node` | Starts using `node filename.js` |

Example:

REPL:

```bash
node
```

JavaScript file:

```bash
node app.js
```

### When should you use REPL?

- Testing small JavaScript expressions.
- Checking function behaviour.
- Learning JavaScript syntax.
- Debugging small code snippets.
- Exploring Node.js features.

---

# 4. ECMAScript 2015 (ES6+)

## 4.1 What is ECMAScript?

ECMAScript is a standard specification for JavaScript.

It defines the syntax, features and behaviour of the JavaScript language.

JavaScript is an implementation of the ECMAScript standard.

### What is ES6?

ES6 stands for ECMAScript 2015.

It was a major JavaScript update released in 2015.

It introduced many important features that made JavaScript more powerful and easier to maintain.

Examples:
- `let` and `const`
- Arrow functions
- Template literals
- Destructuring
- Spread operator
- Rest parameters
- Classes
- Promises
- Modules
- Default parameters
- Enhanced object literals

These features are widely used in modern JavaScript and Node.js applications.

## 4.2 var, let and const

Before ES6, JavaScript commonly used `var` for variable declarations.

ES6 introduced `let` and `const`.

### var

`var` declares a function-scoped or globally scoped variable.

```javascript
var name = "Anurag";

console.log(name);
```

### let

`let` declares a block-scoped variable.

```javascript
let age = 22;

age = 23;

console.log(age);
```

### const

`const` declares a block-scoped binding that cannot be reassigned.

```javascript
const college = "PES Modern College";

console.log(college);
```

You cannot reassign a `const` variable.

### Difference between var, let and const

| Feature | var | let | const |
|---|---|---|---|
| Scope | Function | Block | Block |
| Reassignment | Allowed | Allowed | Not allowed |
| Redeclaration in same scope | Allowed | Not allowed | Not allowed |
| Hoisting | Yes, initialized as undefined | Yes, inaccessible before declaration | Yes, inaccessible before declaration |

**Important:** `let` and `const` are subject to the Temporal Dead Zone (TDZ), so accessing them before their declaration results in a ReferenceError.

## 4.3 Arrow Functions

Arrow functions provide a shorter syntax for writing functions.

### Traditional function

```javascript
function add(a, b) {
    return a + b;
}

console.log(add(10, 20));
```

### Arrow function

```javascript
const add = (a, b) => {
    return a + b;
};

console.log(add(10, 20));
```

### Shorter syntax

If the function contains only one return expression:

```javascript
const add = (a, b) => a + b;

console.log(add(10, 20));
```

Output:

```text
30
```

### Arrow function with one parameter

Parentheses can be omitted for a single parameter:

```javascript
const square = n => n * n;

console.log(square(5));
```

Output:

```text
25
```

### Important difference: this

Arrow functions do not have their own `this`. They capture `this` lexically from the surrounding scope.

Traditional functions have their own `this` depending on how they are called.

This distinction is important when working with objects, classes and event handlers.

## 4.4 Template Literals

Template literals allow strings to contain variables and expressions.

They use backticks instead of single or double quotes.

Example:

```javascript
const name = "Anurag";
const course = "CMCE";

console.log(`Hello ${name}, welcome to ${course}`);
```

Output:

```text
Hello Anurag, welcome to CMCE
```

### Advantages

- Easy string interpolation.
- Supports multiline strings.
- Makes dynamic strings more readable.

Example:

```javascript
const message = `
Welcome to CMCE.
Learn Node.js.
Practise JavaScript.
`;

console.log(message);
```

## 4.5 Destructuring

Destructuring allows values to be extracted from arrays and objects into separate variables.

### Array Destructuring

```javascript
const numbers = [10, 20, 30];

const [a, b, c] = numbers;

console.log(a);
console.log(b);
console.log(c);
```

Output:

```text
10
20
30
```

### Object Destructuring

```javascript
const student = {
    name: "Anurag",
    age: 22,
    course: "CMCE"
};

const { name, age, course } = student;

console.log(name);
console.log(age);
console.log(course);
```

Output:

```text
Anurag
22
CMCE
```

### Destructuring with renamed variables

```javascript
const { name: studentName } = student;

console.log(studentName);
```

## 4.6 Spread Operator

The spread operator (`...`) expands elements of an iterable or properties of an object.

### Array Example

```javascript
const a = [10, 20];
const b = [30, 40];

const result = [...a, ...b];

console.log(result);
```

Output:

```text
[10, 20, 30, 40]
```

### Object Example

```javascript
const student = {
    name: "Anurag",
    course: "CMCE"
};

const updatedStudent = {
    ...student,
    age: 22
};

console.log(updatedStudent);
```

Output:

```text
{
    name: 'Anurag',
    course: 'CMCE',
    age: 22
}
```

## 4.7 Rest Parameters

Rest parameters allow a function to accept any number of arguments as an array.

Example:

```javascript
function sum(...numbers) {

    let total = 0;

    for (const num of numbers) {
        total += num;
    }

    return total;
}

console.log(sum(10, 20, 30));
```

Output:

```text
60
```

### Spread vs Rest

| Spread | Rest |
|---|---|
| Expands values | Collects values |
| Used in function calls, arrays and objects | Used in function parameters and destructuring |
| Example: `[...arr]` | Example: `function sum(...nums)` |

## 4.8 Default Parameters

Default parameters provide a default value when an argument is missing or explicitly `undefined`.

Example:

```javascript
function greet(name = "Guest") {
    console.log(`Hello ${name}`);
}

greet("Anurag");
greet();
```

Output:

```text
Hello Anurag
Hello Guest
```

## 4.9 Classes

ES6 introduced class syntax for creating objects using class-based syntax.

Example:

```javascript
class Student {

    constructor(name, course) {
        this.name = name;
        this.course = course;
    }

    display() {
        console.log(this.name);
        console.log(this.course);
    }

}

const s1 = new Student("Anurag", "CMCE");

s1.display();
```

Output:

```text
Anurag
CMCE
```

### Important concepts

- `class` defines a class.
- `constructor()` initializes an object.
- `this` refers to the current object.
- `new` creates an object.
- Methods define object behaviour.

## 4.10 Promises

A Promise represents the eventual completion or failure of an asynchronous operation.

It has three states:

1. Pending
2. Fulfilled
3. Rejected

Example:

```javascript
const myPromise = new Promise((resolve, reject) => {

    const success = true;

    if (success) {
        resolve("Operation successful");
    } else {
        reject("Operation failed");
    }

});

myPromise
    .then(result => console.log(result))
    .catch(error => console.log(error));
```

Output:

```text
Operation successful
```

## 4.11 ES Modules

ES6 introduced modules to organize JavaScript code into reusable files.

Two important keywords are:

- `export`
- `import`

### Export

Create `math.js`:

```javascript
export function add(a, b) {
    return a + b;
}

export const PI = 3.14;
```

### Import

Create `app.js`:

```javascript
import { add, PI } from "./math.js";

console.log(add(10, 20));
console.log(PI);
```

To run ES modules in Node.js, use one of the supported module configurations, such as setting this in `package.json`:

```json
{
    "type": "module"
}
```

Then run:

```bash
node app.js
```

**Important:** Node.js supports both CommonJS and ECMAScript modules.

CommonJS example:

```javascript
const fs = require("fs");
```

ES module example:

```javascript
import fs from "node:fs";
```

---

# 5. Practical Lab 1 – Install Node.js 22 LTS and Verify

## Objective

Install Node.js version 22 LTS and verify the installation using terminal commands.

## Step 1 – Download Node.js

Official website:

https://nodejs.org/

Download the Node.js 22 LTS installer for Windows.

Choose the Windows x64 installer if you are using a standard 64-bit Windows system.

## Step 2 – Install Node.js

1. Open the downloaded installer.
2. Accept the licence agreement.
3. Select the installation location.
4. Keep the default installation options.
5. Ensure the option to add Node.js to PATH is enabled.
6. Complete the installation.

npm is included with the standard Node.js installer.

## Step 3 – Verify Node.js Installation

Open Command Prompt or VS Code terminal.

Run:

```bash
node -v
```

Expected version format:

```text
v22.x.x
```

The exact patch version may differ.

## Step 4 – Verify npm

Run:

```bash
npm -v
```

It should display the installed npm version.

## Step 5 – Execute Your First Node.js Program

Create a file:

```text
hello.js
```

Add:

```javascript
console.log("Hello, Node.js!");
console.log("Welcome to CMCE");
```

Execute:

```bash
node hello.js
```

Expected output:

```text
Hello, Node.js!
Welcome to CMCE
```

### Important commands

| Command | Purpose |
|---|---|
| `node -v` | Displays Node.js version |
| `npm -v` | Displays npm version |
| `node` | Opens Node.js REPL |
| `node app.js` | Executes JavaScript file |
| `npm init` | Creates a package configuration |
| `npm install package-name` | Installs a package |

---

# 6. Practical Lab 2 – Write a Recursive Function in Node.js

## 6.1 What is Recursion?

Recursion is a programming technique in which a function calls itself to solve a problem.

A recursive function generally contains two important parts:

1. Base condition
2. Recursive call

### Base Condition

The base condition stops the recursion.

Without a suitable base condition, a recursive function may continue calling itself until the call stack is exhausted.

### Recursive Call

A recursive call is the function calling itself with a smaller or simpler input.

## 6.2 Example – Factorial Using Recursion

Factorial of a number is the product of all positive integers from 1 to that number.

Mathematical representation:

```text
5! = 5 × 4 × 3 × 2 × 1

5! = 120
```

Formula:

```text
n! = n × (n - 1)!
0! = 1
```

### Node.js Program

Create:

```text
factorial.js
```

Code:

```javascript
function factorial(n) {

    // Base condition
    if (n === 0 || n === 1) {
        return 1;
    }

    // Recursive call
    return n * factorial(n - 1);

}

const result = factorial(5);

console.log("Factorial:", result);
```

Output:

```text
Factorial: 120
```

Run:

```bash
node factorial.js
```

## 6.3 How Does Recursion Work?

Consider:

```javascript
factorial(5);
```

Execution:

```text
factorial(5)
    |
    v
5 * factorial(4)
    |
    v
5 * 4 * factorial(3)
    |
    v
5 * 4 * 3 * factorial(2)
    |
    v
5 * 4 * 3 * 2 * factorial(1)
    |
    v
5 * 4 * 3 * 2 * 1
    |
    v
120
```

The function keeps calling itself until it reaches the base condition. Then the pending function calls return their results.

## 6.4 Another Example – Sum of Natural Numbers

```javascript
function sum(n) {

    if (n === 0) {
        return 0;
    }

    return n + sum(n - 1);

}

console.log(sum(5));
```

Output:

```text
15
```

Explanation:

```text
5 + 4 + 3 + 2 + 1 = 15
```

## 6.5 Important Points About Recursion

- A recursive function calls itself.
- Every recursive function needs a suitable base condition.
- Each recursive call uses stack space.
- Deep recursion may cause a stack overflow.
- Recursion is useful for problems that can be divided into smaller similar problems.

---

# 7. Practical Lab 3 – Print Numbers from 1 to 100 Using Foo, Bar and Foobar

## 7.1 Problem Statement

Write a Node.js program that prints all numbers between 1 and 100, each on a separate line.

Conditions:

1. If a number is divisible by 3, print `foo`.
2. If a number is divisible by 5, print `bar`.
3. If a number is divisible by both 3 and 5, print `foobar`.
4. Otherwise, print the number itself.

This problem is commonly known as **FizzBuzz**, with the words changed to foo, bar and foobar.

## 7.2 What is the Modulus Operator?

The modulus operator (`%`) returns the remainder after division.

Example:

```javascript
console.log(10 % 3);
```

Output:

```text
1
```

Another example:

```javascript
console.log(15 % 3);
console.log(15 % 5);
```

Output:

```text
0
0
```

When the remainder is zero, the number is divisible by that divisor.

Therefore:

```javascript
n % 3 === 0
```

means that `n` is divisible by 3.

Similarly:

```javascript
n % 5 === 0
```

means that `n` is divisible by 5.

## 7.3 Complete Node.js Program

Create:

```text
foobar.js
```

Code:

```javascript
for (let i = 1; i <= 100; i++) {

    if (i % 3 === 0 && i % 5 === 0) {

        console.log("foobar");

    } else if (i % 3 === 0) {

        console.log("foo");

    } else if (i % 5 === 0) {

        console.log("bar");

    } else {

        console.log(i);

    }

}
```

Run:

```bash
node foobar.js
```

## 7.4 Sample Output

```text
1
2
foo
4
bar
foo
7
8
foo
bar
11
foo
13
14
foobar
16
17
foo
19
bar
foo
22
23
foo
bar
26
foo
28
29
foobar
```

The program continues until 100.

## 7.5 Explanation of the Logic

```javascript
for (let i = 1; i <= 100; i++)
```

The loop starts at 1 and continues until 100.

```javascript
i % 3 === 0 && i % 5 === 0
```

Checks whether the number is divisible by both 3 and 5.

```javascript
i % 3 === 0
```

Checks whether the number is divisible by 3.

```javascript
i % 5 === 0
```

Checks whether the number is divisible by 5.

### Why must we check both conditions first?

Consider the number 15.

It is divisible by both 3 and 5.

If we check only:

```javascript
if (i % 3 === 0)
```

the program will print `foo` for 15 and will never reach the later conditions.

Therefore, the combined condition must be checked first.

## 7.6 Alternative Solution Using a Function

```javascript
function printFooBar() {

    for (let i = 1; i <= 100; i++) {

        let output = "";

        if (i % 3 === 0) {
            output += "foo";
        }

        if (i % 5 === 0) {
            output += "bar";
        }

        console.log(output || i);

    }

}

printFooBar();
```

This approach builds the output string.

For 15:
- Divisible by 3: append `foo`.
- Divisible by 5: append `bar`.
- Final result: `foobar`.

Both solutions are correct.

---

# 8. Important Node.js Concepts for Exams and Interviews

## Q1. What is Node.js?

Node.js is an open-source, cross-platform JavaScript runtime environment that executes JavaScript outside a web browser.

## Q2. Is Node.js a programming language?

No. Node.js is a runtime environment. JavaScript is the programming language.

## Q3. Who created Node.js?

Ryan Dahl initially created Node.js in 2009.

## Q4. Which JavaScript engine does Node.js use?

V8 JavaScript engine.

## Q5. What is V8?

V8 is Google's open-source JavaScript engine used to execute JavaScript code.

## Q6. What is npm?

npm is the default package manager distributed with Node.js. It is used to install, manage and share JavaScript packages.

## Q7. What is REPL?

REPL stands for Read, Evaluate, Print and Loop. It provides an interactive environment for executing JavaScript code.

## Q8. What is the difference between Browser JavaScript and Node.js?

Browser JavaScript executes inside a browser and provides browser APIs such as `window` and `document`. Node.js executes outside the browser and provides APIs such as file system and process management.

## Q9. Can Node.js manipulate the DOM?

Not by default. Node.js does not provide the browser DOM API.

## Q10. What is ES6?

ES6, also called ECMAScript 2015, is a major JavaScript standard update that introduced features such as let, const, arrow functions, classes, promises and modules.

## Q11. What is recursion?

Recursion is a programming technique in which a function calls itself until a base condition is satisfied.

## Q12. What is the purpose of a base condition?

It stops recursive calls and prevents infinite recursion.

## Q13. What is the difference between let and const?

Both are block-scoped. `let` allows reassignment, whereas `const` does not allow reassignment.

## Q14. What is an arrow function?

An arrow function is a shorter syntax for writing functions using the `=>` operator.

## Q15. What is the spread operator?

The spread operator expands elements of an iterable or properties of an object.

## Q16. What is the rest parameter?

The rest parameter collects multiple arguments into a single array.

## Q17. What is a Promise?

A Promise represents the eventual success or failure of an asynchronous operation.

## Q18. What is the difference between CommonJS and ES Modules?

CommonJS commonly uses `require()` and `module.exports`, whereas ES Modules use `import` and `export`.

---

# 9. Multiple Choice Questions (MCQs)

**1. Node.js is a:**

A. Programming language  
B. Database  
C. JavaScript runtime environment  
D. Web browser

**Answer: C. JavaScript runtime environment**

**2. Node.js uses which JavaScript engine?**

A. SpiderMonkey  
B. V8  
C. Chakra  
D. JavaScriptCore

**Answer: B. V8**

**3. Who created Node.js?**

A. Brendan Eich  
B. Ryan Dahl  
C. James Gosling  
D. Dennis Ritchie

**Answer: B. Ryan Dahl**

**4. What is the full form of REPL?**

A. Read Execute Print Loop  
B. Read Evaluate Print Loop  
C. Run Evaluate Program Loop  
D. Read Edit Print Language

**Answer: B. Read Evaluate Print Loop**

**5. Which command checks the installed Node.js version?**

A. `npm -v`  
B. `node -v`  
C. `node --install`  
D. `npm start`

**Answer: B. `node -v`**

**6. Which command checks the npm version?**

A. `node -v`  
B. `npm -v`  
C. `npm run`  
D. `node install`

**Answer: B. `npm -v`**

**7. Which object is available in a normal browser but not provided by default in Node.js?**

A. console  
B. Math  
C. document  
D. JSON

**Answer: C. document**

**8. Which keyword declares a block-scoped variable?**

A. var  
B. let  
C. function  
D. print

**Answer: B. let**

**9. Which operator is used in arrow functions?**

A. `->`  
B. `=>`  
C. `==>`  
D. `::`

**Answer: B. `=>`**

**10. Which operator is used for spreading array elements?**

A. `&&`  
B. `...`  
C. `??`  
D. `===`

**Answer: B. `...`**

**11. Which ES6 feature is used to extract values from arrays and objects?**

A. Destructuring  
B. Recursion  
C. Hoisting  
D. Iteration

**Answer: A. Destructuring**

**12. Which keyword is used to create a class?**

A. object  
B. function  
C. class  
D. constructor

**Answer: C. class**

**13. How many states does a Promise have?**

A. 2  
B. 3  
C. 4  
D. 5

**Answer: B. 3**

**14. Which condition stops a recursive function?**

A. Loop condition  
B. Base condition  
C. Import condition  
D. Default parameter

**Answer: B. Base condition**

**15. What is the output of `15 % 5`?**

A. 1  
B. 2  
C. 3  
D. 0

**Answer: D. 0**

**16. Which statement is correct about const?**

A. It is function-scoped.  
B. It allows reassignment.  
C. It is block-scoped and cannot be reassigned.  
D. It cannot store objects.

**Answer: C. It is block-scoped and cannot be reassigned.**

**17. Which method is commonly used to import a CommonJS module?**

A. import  
B. require  
C. export  
D. include

**Answer: B. require**

**18. Which file extension is commonly used for Node.js JavaScript programs?**

A. `.html`  
B. `.css`  
C. `.js`  
D. `.sql`

**Answer: C. `.js`**

**19. Which package manager is bundled with Node.js?**

A. pip  
B. npm  
C. Maven  
D. Gradle

**Answer: B. npm**

**20. Which output should be printed for 15 in the given Foo-Bar program?**

A. foo  
B. bar  
C. foobar  
D. 15

**Answer: C. foobar**

---

# 10. Additional Self-Practice Programs

After completing the syllabus practicals, try these programs.

1. Write a Node.js program to check whether a number is even or odd.
2. Write a recursive function to calculate the sum of digits.
3. Write a recursive function to calculate Fibonacci numbers.
4. Write a program to print numbers from 1 to 100 using a `while` loop.
5. Write a program to find the largest of three numbers.
6. Write a program to reverse a string.
7. Write a program to count vowels in a string.
8. Write a program to print the multiplication table of a number.
9. Write a program to find prime numbers between 1 and 100.
10. Write a program using ES6 arrow functions and template literals.

---

# 11. Quick Revision Notes

| Topic | Key Point |
|---|---|
| Node.js | JavaScript runtime environment |
| V8 | JavaScript engine |
| npm | Package manager |
| REPL | Read, Evaluate, Print, Loop |
| Browser JS | Executes inside browser |
| Node.js | Executes outside browser |
| DOM | Not built into Node.js |
| ES6 | ECMAScript 2015 |
| `let` | Block-scoped, reassignment allowed |
| `const` | Block-scoped, reassignment not allowed |
| Arrow function | Uses `=>` |
| Template literal | Uses backticks |
| Destructuring | Extracts values from arrays/objects |
| Spread | Expands values |
| Rest | Collects values |
| Promise | Represents an asynchronous result |
| Recursion | Function calls itself |
| Base condition | Stops recursion |

---

# 12. Final Practical Checklist

- [ ] Install Node.js 22 LTS.
- [ ] Verify using `node -v`.
- [ ] Verify using `npm -v`.
- [ ] Start Node.js REPL.
- [ ] Execute JavaScript statements in REPL.
- [ ] Create and execute a `.js` file.
- [ ] Write a recursive factorial function.
- [ ] Write a recursive sum function.
- [ ] Implement the Foo-Bar-Foobar program.
- [ ] Revise Browser JavaScript vs Node.js.
- [ ] Practise ES6+ features.

## References

1. [Node.js Official Documentation](https://nodejs.org/docs/latest/api/)
2. [Node.js Downloads](https://nodejs.org/en/download)
3. [Node.js Learn](https://nodejs.org/en/learn)
4. [MDN – JavaScript Guide](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide)
5. [MDN – JavaScript Reference](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference)
6. [ECMAScript Specifications](https://tc39.es/ecma262/)

**End of Session 15 – Introduction to Node.js**
