# Session 5: JavaScript Fundamentals

**Course:** Web Programming Technologies  
**Batch:** CMCE – August 2026  
**Duration:** 2 Theory + 2 Lab + 2 Self-Learning Sessions

---

# 1. Introduction to JavaScript

## 1.1 What is JavaScript?

JavaScript (JS) is a high-level, dynamic programming language primarily used to make webpages interactive and dynamic.

It is one of the core technologies of web development:

| Technology | Purpose |
|---|---|
| HTML | Defines webpage structure |
| CSS | Defines webpage appearance |
| JavaScript | Defines webpage behaviour and functionality |

### Example

HTML:

```html
<h1 id="heading">Hello World</h1>

<button onclick="changeText()">
    Click Me
</button>
```

JavaScript:

```javascript
function changeText() {
    document.getElementById("heading").innerHTML =
        "Welcome to JavaScript!";
}
```

When the user clicks the button, JavaScript changes the heading.

## 1.2 Why is JavaScript Used?

JavaScript is used for:

1. Form validation.
2. Handling button clicks.
3. Dynamic webpage updates.
4. Creating interactive menus.
5. Calculations and data processing.
6. Animations and user interactions.
7. Communicating with backend APIs.
8. Building frontend applications using React, Angular and Vue.
9. Backend development using Node.js.
10. Developing full-stack applications.

## 1.3 Features of JavaScript

- Lightweight and flexible.
- Dynamically typed.
- Supports object-oriented programming.
- Supports functional programming.
- Event-driven.
- Supports asynchronous programming.
- Runs in web browsers.
- Can also run outside browsers using environments such as Node.js.

## 1.4 Where Does JavaScript Run?

JavaScript can run in different environments.

**1. Browser environment**

Examples:
- Google Chrome
- Mozilla Firefox
- Microsoft Edge
- Safari

The browser provides APIs such as:
- DOM API
- Fetch API
- Local Storage
- Geolocation API

**2. Server environment**

Node.js allows JavaScript to execute outside the browser.

Example:

```javascript
console.log("Hello from Node.js");
```

Run using:

```bash
node app.js
```

## 1.5 How to Add JavaScript to HTML

There are three common approaches.

### A. Inline JavaScript

JavaScript is written directly inside an HTML event attribute.

```html
<button onclick="alert('Hello JavaScript')">
    Click Me
</button>
```

Useful for small demonstrations, but generally avoided in larger applications.

### B. Internal JavaScript

JavaScript is written inside the `<script>` element.

```html
<!DOCTYPE html>
<html>
<head>
    <title>Internal JavaScript</title>
</head>
<body>

    <h1>Hello World</h1>

    <script>
        console.log("JavaScript is working");
    </script>

</body>
</html>
```

### C. External JavaScript

JavaScript is written in a separate `.js` file.

Project structure:

```text
javascript-project/
│
├── index.html
└── script.js
```

**index.html**

```html
<!DOCTYPE html>
<html>
<head>
    <title>External JavaScript</title>
</head>
<body>

    <h1>Welcome</h1>

    <script src="script.js"></script>

</body>
</html>
```

**script.js**

```javascript
console.log("External JavaScript is working!");
```

External JavaScript is generally preferred because it separates HTML structure from programming logic.

### D. Using defer

The `defer` attribute allows an external script to execute after the HTML document has been parsed.

```html
<script src="script.js" defer></script>
```

This is useful when JavaScript needs to access HTML elements.

---

# 2. Variables – var, let and const

## 2.1 What is a Variable?

A variable is a named storage location used to hold data.

Example:

```javascript
let name = "Anurag";
let age = 22;

console.log(name);
console.log(age);
```

Output:

```text
Anurag
22
```

## 2.2 Declaring Variables

JavaScript provides three main variable declaration keywords:

1. `var`
2. `let`
3. `const`

### A. var

`var` is the older way of declaring variables.

Example:

```javascript
var name = "Anurag";

console.log(name);
```

A `var` variable:
- Can be redeclared.
- Can be reassigned.
- Is function-scoped.
- Is hoisted and initialized with `undefined`.

Example:

```javascript
var age = 22;

var age = 23;

console.log(age);
```

Output:

```text
23
```

### B. let

`let` was introduced in ES6 (ES2015).

It is used when the variable's value needs to change.

Example:

```javascript
let marks = 80;

marks = 90;

console.log(marks);
```

Output:

```text
90
```

Important points:
- Can be reassigned.
- Cannot be redeclared in the same scope.
- Is block-scoped.
- Cannot be accessed before its declaration is initialized.

Example:

```javascript
let x = 10;

x = 20;

// let x = 30; // SyntaxError in the same scope

console.log(x);
```

### C. const

`const` is used to declare a variable whose binding cannot be reassigned.

Example:

```javascript
const PI = 3.14159;

console.log(PI);
```

Important points:
- Cannot be reassigned.
- Cannot be redeclared in the same scope.
- Is block-scoped.
- Must be initialized when declared.

Example:

```javascript
const country = "India";

// country = "USA"; // TypeError

console.log(country);
```

### Important: const with Objects and Arrays

`const` prevents reassignment of the variable binding. It does not make the object or array immutable.

Example:

```javascript
const student = {
    name: "Anurag",
    age: 22
};

student.age = 23;

console.log(student.age);
```

Output:

```text
23
```

But this is not allowed:

```javascript
// student = { name: "Rahul" };
```

The variable cannot be assigned a completely new object.

## 2.3 Difference Between var, let and const

| Feature | var | let | const |
|---|---|---|---|
| Scope | Function | Block | Block |
| Redeclaration | Yes | No, same scope | No, same scope |
| Reassignment | Yes | Yes | No |
| Hoisting | Yes | Yes | Yes |
| Initial value before declaration | undefined | Cannot access | Cannot access |
| Must initialize during declaration | No | No | Yes |

## 2.4 What is Scope?

Scope determines where a variable can be accessed.

### A. Global Scope

A variable declared outside functions and blocks may be accessible throughout its relevant script or module scope.

```javascript
let college = "ACTS Pune";

function display() {
    console.log(college);
}

display();
```

### B. Function Scope

Variables declared using `var` inside a function are accessible within that function.

```javascript
function test() {
    var x = 10;

    console.log(x);
}

test();

// console.log(x); // ReferenceError
```

### C. Block Scope

Variables declared using `let` and `const` inside `{}` are limited to that block.

```javascript
if (true) {
    let x = 10;
    const y = 20;

    console.log(x);
    console.log(y);
}

// console.log(x); // ReferenceError
```

## 2.5 What is Hoisting?

Hoisting is JavaScript's behaviour of processing declarations before executing code.

Example with `var`:

```javascript
console.log(a);

var a = 10;
```

Output:

```text
undefined
```

Conceptually, the declaration is processed before execution, while the assignment remains at its original position.

Example with `let`:

```javascript
// console.log(b); // ReferenceError

let b = 20;
```

`let` and `const` are also hoisted, but cannot be accessed before initialization because of the Temporal Dead Zone (TDZ).

---

# 3. Statements, Operators and Expressions

## 3.1 What is a Statement?

A statement is an instruction executed by JavaScript.

Example:

```javascript
let age = 22;

console.log(age);
```

Here:
- `let age = 22;` is a declaration statement.
- `console.log(age);` is an expression statement.

## 3.2 What is an Expression?

An expression is a piece of code that evaluates to a value.

Example:

```javascript
10 + 20
```

Result:

```text
30
```

Other examples:

```javascript
let x = 10;

x + 5;

x > 5;

"Hello" + " World";
```

## 3.3 What is an Operator?

An operator performs an operation on one or more operands.

Example:

```javascript
let result = 10 + 20;
```

Here:
- `10` and `20` are operands.
- `+` is the operator.

## 3.4 Types of Operators

### A. Arithmetic Operators

Used for mathematical operations.

| Operator | Meaning | Example | Result |
|---|---|---|---|
| `+` | Addition | `10 + 5` | 15 |
| `-` | Subtraction | `10 - 5` | 5 |
| `*` | Multiplication | `10 * 5` | 50 |
| `/` | Division | `10 / 5` | 2 |
| `%` | Modulus | `10 % 3` | 1 |
| `**` | Exponentiation | `2 ** 3` | 8 |
| `++` | Increment | `x++` | Adds 1 |
| `--` | Decrement | `x--` | Subtracts 1 |

Example:

```javascript
let a = 10;
let b = 3;

console.log(a + b);
console.log(a - b);
console.log(a * b);
console.log(a / b);
console.log(a % b);
console.log(a ** b);
```

### B. Assignment Operators

Used to assign values to variables.

| Operator | Example | Equivalent |
|---|---|---|
| `=` | `x = 10` | Assign 10 |
| `+=` | `x += 5` | `x = x + 5` |
| `-=` | `x -= 5` | `x = x - 5` |
| `*=` | `x *= 5` | `x = x * 5` |
| `/=` | `x /= 5` | `x = x / 5` |
| `%=` | `x %= 5` | `x = x % 5` |
| `**=` | `x **= 2` | `x = x ** 2` |

Example:

```javascript
let x = 10;

x += 5;

console.log(x);
```

Output:

```text
15
```

### C. Comparison Operators

Used to compare two values.

| Operator | Meaning |
|---|---|
| `==` | Equal value after type conversion |
| `===` | Strict equality: value and type |
| `!=` | Not equal after type conversion |
| `!==` | Strict inequality |
| `>` | Greater than |
| `<` | Less than |
| `>=` | Greater than or equal |
| `<=` | Less than or equal |

Example:

```javascript
console.log(10 == "10");
console.log(10 === "10");
console.log(10 > 5);
```

Output:

```text
true
false
true
```

**Important:** Prefer `===` and `!==` to avoid unexpected type conversion.

### D. Logical Operators

Used to combine or reverse Boolean conditions.

| Operator | Meaning |
|---|---|
| `&&` | Logical AND |
| `||` | Logical OR |
| `!` | Logical NOT |

Example:

```javascript
let age = 22;
let hasID = true;

console.log(age >= 18 && hasID);
console.log(age >= 18 || hasID);
console.log(!hasID);
```

Output:

```text
true
true
false
```

### E. Ternary Operator

The ternary operator is a shorthand for a simple conditional expression.

Syntax:

```javascript
condition ? expression1 : expression2;
```

Example:

```javascript
let age = 20;

let result = age >= 18 ? "Adult" : "Minor";

console.log(result);
```

Output:

```text
Adult
```

### F. Typeof Operator

Used to identify the type of a value.

```javascript
console.log(typeof 100);
console.log(typeof "Hello");
console.log(typeof true);
console.log(typeof undefined);
```

Output:

```text
number
string
boolean
undefined
```

One important exception:

```javascript
console.log(typeof null);
```

Output:

```text
object
```

This is a historical JavaScript behaviour. `null` is a primitive value, despite the result of `typeof null`.

---

# 4. Control Structures

Control structures determine the order in which statements execute.

The main types are:

1. Conditional statements.
2. Looping statements.
3. Jump statements.

## 4.1 if Statement

Executes code when a condition is true.

Syntax:

```javascript
if (condition) {
    // statements
}
```

Example:

```javascript
let age = 22;

if (age >= 18) {
    console.log("Eligible to vote");
}
```

## 4.2 if-else Statement

Executes one block when the condition is true and another when it is false.

```javascript
let marks = 75;

if (marks >= 40) {
    console.log("Pass");
} else {
    console.log("Fail");
}
```

## 4.3 else-if Ladder

Used to check multiple conditions.

```javascript
let marks = 85;

if (marks >= 90) {
    console.log("Grade A+");
} else if (marks >= 80) {
    console.log("Grade A");
} else if (marks >= 70) {
    console.log("Grade B");
} else if (marks >= 40) {
    console.log("Grade C");
} else {
    console.log("Fail");
}
```

Output:

```text
Grade A
```

## 4.4 Nested if

An if statement inside another if statement.

```javascript
let age = 22;
let hasID = true;

if (age >= 18) {

    if (hasID) {
        console.log("Entry allowed");
    } else {
        console.log("ID required");
    }

} else {
    console.log("Entry not allowed");
}
```

## 4.5 switch Statement

Used when one expression is compared against multiple possible values.

Syntax:

```javascript
switch (expression) {

    case value1:
        // statements
        break;

    case value2:
        // statements
        break;

    default:
        // default statements
}
```

Example:

```javascript
let day = 3;

switch (day) {

    case 1:
        console.log("Monday");
        break;

    case 2:
        console.log("Tuesday");
        break;

    case 3:
        console.log("Wednesday");
        break;

    default:
        console.log("Invalid day");
}
```

Output:

```text
Wednesday
```

**Why use break?**

`break` stops execution from continuing into the next case. Without it, execution can fall through to subsequent cases.

## 4.6 Loops

Loops execute a block of code repeatedly.

### A. for Loop

Used when the number of iterations is generally known.

Syntax:

```javascript
for (initialization; condition; update) {
    // statements
}
```

Example:

```javascript
for (let i = 1; i <= 5; i++) {
    console.log(i);
}
```

Output:

```text
1
2
3
4
5
```

### B. while Loop

Executes while a condition is true.

```javascript
let i = 1;

while (i <= 5) {
    console.log(i);
    i++;
}
```

### C. do-while Loop

Executes the block at least once, then checks the condition.

```javascript
let i = 1;

do {
    console.log(i);
    i++;
} while (i <= 5);
```

### D. for...of Loop

Used to iterate over iterable values such as arrays and strings.

```javascript
let fruits = ["Apple", "Mango", "Banana"];

for (let fruit of fruits) {
    console.log(fruit);
}
```

### E. for...in Loop

Used to iterate over enumerable property keys of an object.

```javascript
let student = {
    name: "Anurag",
    age: 22,
    course: "AIML"
};

for (let key in student) {
    console.log(key, student[key]);
}
```

Remember:
- `for...of` gives values from an iterable.
- `for...in` gives enumerable property keys.

### 4.7 Jump Statements

**break:** Terminates a loop or switch.

```javascript
for (let i = 1; i <= 10; i++) {

    if (i === 5) {
        break;
    }

    console.log(i);
}
```

Output:

```text
1
2
3
4
```

**continue:** Skips the current iteration.

```javascript
for (let i = 1; i <= 5; i++) {

    if (i === 3) {
        continue;
    }

    console.log(i);
}
```

Output:

```text
1
2
4
5
```

**return:** Exits a function and optionally returns a value.

```javascript
function add(a, b) {
    return a + b;
}

console.log(add(10, 20));
```

---

# 5. Strings and String Methods

## 5.1 What is a String?

A string is a sequence of characters used to represent text.

Example:

```javascript
let name = "Anurag";

let city = 'Pune';

let message = `Welcome to JavaScript`;
```

JavaScript supports:
- Single quotes `' '`
- Double quotes `" "`
- Backticks `` ` ` ``

## 5.2 String Length

The `length` property returns the number of UTF-16 code units in a string.

```javascript
let name = "Anurag";

console.log(name.length);
```

Output:

```text
6
```

## 5.3 Important String Methods

### A. toUpperCase()

Converts text to uppercase.

```javascript
let text = "javascript";

console.log(text.toUpperCase());
```

Output:

```text
JAVASCRIPT
```

### B. toLowerCase()

Converts text to lowercase.

```javascript
let text = "HELLO WORLD";

console.log(text.toLowerCase());
```

Output:

```text
hello world
```

### C. trim()

Removes whitespace from the beginning and end.

```javascript
let text = "   Hello World   ";

console.log(text.trim());
```

Output:

```text
Hello World
```

### D. charAt()

Returns the character at a specified index.

```javascript
let text = "JavaScript";

console.log(text.charAt(0));
```

Output:

```text
J
```

### E. includes()

Checks whether a string contains a specified value.

```javascript
let text = "Welcome to JavaScript";

console.log(text.includes("Java"));
```

Output:

```text
true
```

### F. indexOf()

Returns the first index of the specified value, or `-1` if it is not found.

```javascript
let text = "JavaScript";

console.log(text.indexOf("Script"));
```

Output:

```text
4
```

### G. slice()

Extracts part of a string.

Syntax:

```javascript
string.slice(start, end);
```

The ending index is excluded.

```javascript
let text = "JavaScript";

console.log(text.slice(0, 4));
```

Output:

```text
Java
```

### H. substring()

Returns part of a string.

```javascript
let text = "JavaScript";

console.log(text.substring(4, 10));
```

Output:

```text
Script
```

### I. replace()

Replaces the first matching occurrence.

```javascript
let text = "Hello World";

console.log(text.replace("World", "JavaScript"));
```

Output:

```text
Hello JavaScript
```

### J. replaceAll()

Replaces all matching occurrences.

```javascript
let text = "Java Java Java";

console.log(text.replaceAll("Java", "Python"));
```

Output:

```text
Python Python Python
```

### K. split()

Splits a string into an array.

```javascript
let text = "Java,Python,JavaScript";

let result = text.split(",");

console.log(result);
```

Output:

```text
["Java", "Python", "JavaScript"]
```

### L. startsWith() and endsWith()

```javascript
let text = "JavaScript";

console.log(text.startsWith("Java"));
console.log(text.endsWith("Script"));
```

Output:

```text
true
true
```

### M. concat()

Joins strings.

```javascript
let first = "Hello";
let second = "World";

console.log(first.concat(" ", second));
```

Output:

```text
Hello World
```

### String Method Revision Table

| Method | Purpose |
|---|---|
| `toUpperCase()` | Converts to uppercase |
| `toLowerCase()` | Converts to lowercase |
| `trim()` | Removes surrounding whitespace |
| `charAt()` | Returns character at index |
| `includes()` | Checks whether text exists |
| `indexOf()` | Returns first matching index |
| `slice()` | Extracts a substring |
| `substring()` | Extracts a substring |
| `replace()` | Replaces first matching occurrence |
| `replaceAll()` | Replaces all matching occurrences |
| `split()` | Converts string into array |
| `startsWith()` | Checks beginning |
| `endsWith()` | Checks ending |
| `concat()` | Joins strings |

**Important:** Strings are immutable in JavaScript. String methods return new strings instead of modifying the original string.

---

# 6. Numbers and Number Methods

## 6.1 What is a Number?

JavaScript uses the `number` primitive type for ordinary numeric values, including integers and floating-point numbers.

Example:

```javascript
let age = 22;

let price = 99.50;

let temperature = -5;

console.log(age);
console.log(price);
console.log(temperature);
```

Unlike some programming languages, JavaScript does not have separate ordinary primitive types for integers and floating-point numbers.

## 6.2 Number.isInteger()

Checks whether a value is an integer.

```javascript
console.log(Number.isInteger(100));
console.log(Number.isInteger(10.5));
```

Output:

```text
true
false
```

## 6.3 Number.isNaN()

Checks whether a value is the special `NaN` value.

```javascript
console.log(Number.isNaN(NaN));
console.log(Number.isNaN("Hello"));
```

Output:

```text
true
false
```

## 6.4 Number.isFinite()

Checks whether a value is a finite number.

```javascript
console.log(Number.isFinite(100));
console.log(Number.isFinite(Infinity));
```

Output:

```text
true
false
```

## 6.5 toFixed()

Formats a number using a specified number of digits after the decimal point and returns a string.

```javascript
let price = 123.4567;

console.log(price.toFixed(2));
```

Output:

```text
123.46
```

## 6.6 toString()

Converts a number into a string.

```javascript
let num = 100;

console.log(num.toString());

console.log(typeof num.toString());
```

Output:

```text
100
string
```

## 6.7 parseInt()

Converts a string to an integer by parsing its beginning.

```javascript
let value = "100";

console.log(parseInt(value));
```

Output:

```text
100
```

Example:

```javascript
console.log(parseInt("100.75"));
```

Output:

```text
100
```

## 6.8 parseFloat()

Parses a floating-point number from a string.

```javascript
let value = "100.75";

console.log(parseFloat(value));
```

Output:

```text
100.75
```

## 6.9 Number() vs parseInt() vs parseFloat()

| Function | Purpose | Example | Result |
|---|---|---|---|
| `Number()` | Converts entire value to a number | `Number("25.5")` | 25.5 |
| `parseInt()` | Parses integer from beginning | `parseInt("25.5")` | 25 |
| `parseFloat()` | Parses decimal from beginning | `parseFloat("25.5")` | 25.5 |

Example:

```javascript
console.log(Number("100"));
console.log(parseInt("100.75"));
console.log(parseFloat("100.75"));
```

Output:

```text
100
100
100.75
```

Important:

```javascript
console.log(Number("100abc"));      // NaN
console.log(parseInt("100abc"));    // 100
console.log(parseFloat("10.5abc")); // 10.5
```

Use `Number()` when you want the entire string to represent a valid numeric value.

## 6.10 Math Object

JavaScript provides the built-in `Math` object for mathematical operations.

```javascript
console.log(Math.round(10.6)); // 11

console.log(Math.floor(10.9)); // 10

console.log(Math.ceil(10.1)); // 11

console.log(Math.max(10, 20, 30)); // 30

console.log(Math.min(10, 20, 30)); // 10

console.log(Math.sqrt(25)); // 5

console.log(Math.pow(2, 3)); // 8

console.log(Math.abs(-10)); // 10
```

### Random Number

```javascript
console.log(Math.random());
```

Returns a random floating-point value greater than or equal to 0 and less than 1.

Generate a random integer between 1 and 10:

```javascript
let randomNumber = Math.floor(Math.random() * 10) + 1;

console.log(randomNumber);
```

---

# 7. Boolean Values

## 7.1 What is Boolean?

Boolean is a primitive data type that represents one of two values:

- `true`
- `false`

Example:

```javascript
let isStudent = true;

let isPassed = false;

console.log(isStudent);
console.log(isPassed);
```

## 7.2 Boolean Expressions

Comparison expressions usually produce Boolean values.

```javascript
let age = 22;

console.log(age >= 18);
console.log(age < 18);
```

Output:

```text
true
false
```

## 7.3 Boolean() Function

Converts a value to its Boolean equivalent.

```javascript
console.log(Boolean(1));
console.log(Boolean(0));
console.log(Boolean("Hello"));
console.log(Boolean(""));
```

Output:

```text
true
false
true
false
```

## 7.4 Truthy and Falsy Values

JavaScript evaluates values as either truthy or falsy in Boolean contexts.

Common falsy values:

| Value | Boolean result |
|---|---|
| `false` | false |
| `0` | false |
| `-0` | false |
| `0n` | false |
| `""` | false |
| `null` | false |
| `undefined` | false |
| `NaN` | false |

Most other values are truthy, including:

```javascript
Boolean("Hello"); // true

Boolean("0"); // true

Boolean([]); // true

Boolean({}); // true
```

**Important:** An empty array and empty object are truthy in JavaScript.

---

# 8. Dates, Date Formats and Date Methods

## 8.1 What is the Date Object?

The JavaScript `Date` object is used to work with dates and times.

It can be used to:
- Get the current date.
- Get the current time.
- Extract the day, month and year.
- Compare dates.
- Calculate time differences.
- Format dates.

## 8.2 Creating Date Objects

### A. Current Date and Time

```javascript
let today = new Date();

console.log(today);
```

### B. Date Using a String

```javascript
let date = new Date("2026-11-09");

console.log(date);
```

### C. Date Using Numeric Values

```javascript
let date = new Date(2026, 10, 9);

console.log(date);
```

Important: Month indexing starts at 0.

| Month | Index |
|---|---:|
| January | 0 |
| February | 1 |
| March | 2 |
| April | 3 |
| May | 4 |
| June | 5 |
| July | 6 |
| August | 7 |
| September | 8 |
| October | 9 |
| November | 10 |
| December | 11 |

Therefore:

```javascript
new Date(2026, 10, 9);
```

represents 9 November 2026 in the local timezone.

## 8.3 Important Date Methods

### A. getDate()

Returns the day of the month.

```javascript
let date = new Date();

console.log(date.getDate());
```

### B. getMonth()

Returns the month index from 0 to 11.

```javascript
let date = new Date();

console.log(date.getMonth());
```

### C. getFullYear()

Returns the full year.

```javascript
let date = new Date();

console.log(date.getFullYear());
```

### D. getDay()

Returns the day of the week from 0 to 6.

| Value | Day |
|---|---|
| 0 | Sunday |
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |

Example:

```javascript
let date = new Date();

console.log(date.getDay());
```

### E. getHours()

Returns the hour in local time.

```javascript
let date = new Date();

console.log(date.getHours());
```

### F. getMinutes()

```javascript
let date = new Date();

console.log(date.getMinutes());
```

### G. getSeconds()

```javascript
let date = new Date();

console.log(date.getSeconds());
```

### H. getTime()

Returns the number of milliseconds since 1 January 1970 UTC.

```javascript
let date = new Date();

console.log(date.getTime());
```

This is called the Unix epoch time in milliseconds.

### I. toISOString()

Returns a date-time string in ISO 8601 format in UTC.

```javascript
let date = new Date();

console.log(date.toISOString());
```

Example format:

```text
2026-11-09T10:30:00.000Z
```

The actual time depends on the execution environment and current date.

### J. toLocaleDateString()

Formats a date according to a locale.

```javascript
let date = new Date();

console.log(date.toLocaleDateString("en-IN"));
```

Example format:

```text
09/11/2026
```

### K. toLocaleString()

Returns a locale-sensitive date and time string.

```javascript
let date = new Date();

console.log(date.toLocaleString("en-IN"));
```

## 8.4 Setting Date Values

JavaScript also provides setter methods.

```javascript
let date = new Date();

date.setFullYear(2027);

date.setMonth(5);

date.setDate(15);

console.log(date);
```

## 8.5 Important Difference Between Date Formats

| Format | Example | Purpose |
|---|---|---|
| ISO date | `2026-11-09` | Standard date representation |
| ISO date-time | `2026-11-09T10:30:00Z` | UTC date and time |
| Local date string | `09/11/2026` | Locale-dependent display |
| Timestamp | `1794220000000` | Milliseconds since epoch |

**Important:** Date strings such as `09/11/2026` can be ambiguous across regions. Prefer standard ISO date strings for predictable parsing.

---

# 9. Arrays and Array Methods

## 9.1 What is an Array?

An array is a data structure used to store multiple values in a single variable.

Example:

```javascript
let fruits = ["Apple", "Mango", "Banana"];

console.log(fruits);
```

Output:

```text
["Apple", "Mango", "Banana"]
```

## 9.2 Array Indexing

Array indexes start from 0.

```javascript
let fruits = ["Apple", "Mango", "Banana"];

console.log(fruits[0]);
console.log(fruits[1]);
console.log(fruits[2]);
```

Output:

```text
Apple
Mango
Banana
```

## 9.3 Array Length

```javascript
let numbers = [10, 20, 30, 40];

console.log(numbers.length);
```

Output:

```text
4
```

## 9.4 Modifying Array Elements

```javascript
let fruits = ["Apple", "Mango", "Banana"];

fruits[1] = "Orange";

console.log(fruits);
```

Output:

```text
["Apple", "Orange", "Banana"]
```

## 9.5 Important Array Methods

### A. push()

Adds an element at the end.

```javascript
let numbers = [10, 20, 30];

numbers.push(40);

console.log(numbers);
```

Output:

```text
[10, 20, 30, 40]
```

### B. pop()

Removes the last element and returns it.

```javascript
let numbers = [10, 20, 30];

let removed = numbers.pop();

console.log(numbers);
console.log(removed);
```

Output:

```text
[10, 20]
30
```

### C. unshift()

Adds an element at the beginning.

```javascript
let numbers = [20, 30];

numbers.unshift(10);

console.log(numbers);
```

Output:

```text
[10, 20, 30]
```

### D. shift()

Removes the first element.

```javascript
let numbers = [10, 20, 30];

numbers.shift();

console.log(numbers);
```

Output:

```text
[20, 30]
```

### E. includes()

Checks whether an element exists.

```javascript
let fruits = ["Apple", "Mango", "Banana"];

console.log(fruits.includes("Mango"));
```

Output:

```text
true
```

### F. indexOf()

Returns the first index of an element, or -1.

```javascript
let fruits = ["Apple", "Mango", "Banana"];

console.log(fruits.indexOf("Banana"));
```

Output:

```text
2
```

### G. slice()

Returns a shallow copy of a selected portion without modifying the original array.

```javascript
let numbers = [10, 20, 30, 40, 50];

let result = numbers.slice(1, 4);

console.log(result);
```

Output:

```text
[20, 30, 40]
```

### H. splice()

Adds, removes or replaces elements in the original array.

Syntax:

```javascript
array.splice(start, deleteCount, item1, item2);
```

Example – Remove elements:

```javascript
let numbers = [10, 20, 30, 40];

numbers.splice(1, 2);

console.log(numbers);
```

Output:

```text
[10, 40]
```

Example – Insert elements:

```javascript
let numbers = [10, 40];

numbers.splice(1, 0, 20, 30);

console.log(numbers);
```

Output:

```text
[10, 20, 30, 40]
```

### I. concat()

Combines arrays.

```javascript
let a = [1, 2];

let b = [3, 4];

let result = a.concat(b);

console.log(result);
```

Output:

```text
[1, 2, 3, 4]
```

### J. join()

Converts an array into a string.

```javascript
let fruits = ["Apple", "Mango", "Banana"];

console.log(fruits.join(", "));
```

Output:

```text
Apple, Mango, Banana
```

### K. reverse()

Reverses the original array.

```javascript
let numbers = [1, 2, 3, 4];

numbers.reverse();

console.log(numbers);
```

Output:

```text
[4, 3, 2, 1]
```

### L. sort()

Sorts the original array.

```javascript
let fruits = ["Banana", "Apple", "Mango"];

fruits.sort();

console.log(fruits);
```

Output:

```text
["Apple", "Banana", "Mango"]
```

For numbers, use a comparison function.

```javascript
let numbers = [40, 5, 100, 20];

numbers.sort((a, b) => a - b);

console.log(numbers);
```

Output:

```text
[5, 20, 40, 100]
```

Descending order:

```javascript
numbers.sort((a, b) => b - a);
```

### M. forEach()

Executes a callback function for every array element.

```javascript
let numbers = [10, 20, 30];

numbers.forEach(function(num) {
    console.log(num);
});
```

Using an arrow function:

```javascript
numbers.forEach(num => console.log(num));
```

### N. map()

Creates a new array by transforming each element.

```javascript
let numbers = [1, 2, 3, 4];

let result = numbers.map(num => num * 2);

console.log(result);
```

Output:

```text
[2, 4, 6, 8]
```

### O. filter()

Creates a new array containing elements that satisfy a condition.

```javascript
let numbers = [10, 15, 20, 25, 30];

let result = numbers.filter(num => num > 20);

console.log(result);
```

Output:

```text
[25, 30]
```

### P. find()

Returns the first element satisfying a condition.

```javascript
let numbers = [10, 20, 30, 40];

let result = numbers.find(num => num > 20);

console.log(result);
```

Output:

```text
30
```

### Q. findIndex()

Returns the index of the first matching element, or -1.

```javascript
let numbers = [10, 20, 30, 40];

console.log(numbers.findIndex(num => num > 20));
```

Output:

```text
2
```

### R. reduce()

Reduces an array to a single accumulated result.

```javascript
let numbers = [10, 20, 30, 40];

let total = numbers.reduce((sum, num) => sum + num, 0);

console.log(total);
```

Output:

```text
100
```

### Array Methods Comparison

| Method | Purpose | Modifies Original Array? |
|---|---|---|
| `push()` | Add at end | Yes |
| `pop()` | Remove from end | Yes |
| `unshift()` | Add at beginning | Yes |
| `shift()` | Remove from beginning | Yes |
| `slice()` | Extract elements | No |
| `splice()` | Insert/remove elements | Yes |
| `concat()` | Combine arrays | No |
| `join()` | Convert to string | No |
| `map()` | Transform elements | No |
| `filter()` | Filter elements | No |
| `find()` | Find first matching value | No |
| `forEach()` | Execute callback | Does not itself modify |
| `reduce()` | Produce accumulated value | Does not itself modify |
| `sort()` | Sort array | Yes |
| `reverse()` | Reverse array | Yes |

**Important:** `map()`, `filter()`, and `reduce()` are particularly important for modern JavaScript and React development.

---

# 10. ES6+ Modern Syntax

## 10.1 What is ES6?

ES6 stands for ECMAScript 2015.

It introduced important improvements to JavaScript.

ECMAScript is the standard specification on which JavaScript is based.

ES6 introduced features such as:
- `let` and `const`
- Arrow functions
- Template literals
- Destructuring
- Spread operator
- Rest parameters
- Classes
- Modules
- Promises
- Default parameters

Later ECMAScript versions introduced additional features such as:
- Optional chaining
- Nullish coalescing
- Logical assignment operators

---

# 11. Template Literals

## 11.1 What are Template Literals?

Template literals are a modern way of creating strings using backticks.

They allow:
1. Variable interpolation.
2. Expressions inside strings.
3. Multiline strings.

## 11.2 Traditional String Concatenation

```javascript
let name = "Anurag";

let age = 22;

let message = "My name is " + name + " and my age is " + age;

console.log(message);
```

## 11.3 Using Template Literals

```javascript
let name = "Anurag";

let age = 22;

let message = `My name is ${name} and my age is ${age}`;

console.log(message);
```

Output:

```text
My name is Anurag and my age is 22
```

## 11.4 Expression Interpolation

You can write expressions inside `${}`.

```javascript
let a = 10;

let b = 20;

console.log(`Addition = ${a + b}`);
```

Output:

```text
Addition = 30
```

## 11.5 Multiline Strings

```javascript
let message = `
Welcome to JavaScript.
Learn modern ES6 features.
Practise daily.
`;

console.log(message);
```

---

# 12. Destructuring

## 12.1 What is Destructuring?

Destructuring is a JavaScript feature that allows us to extract values from arrays or properties from objects into separate variables.

There are two major types:

1. Array destructuring.
2. Object destructuring.

## 12.2 Array Destructuring

Traditional approach:

```javascript
let numbers = [10, 20, 30];

let a = numbers[0];

let b = numbers[1];

let c = numbers[2];

console.log(a, b, c);
```

Using destructuring:

```javascript
let numbers = [10, 20, 30];

let [a, b, c] = numbers;

console.log(a, b, c);
```

Output:

```text
10 20 30
```

### Skipping Elements

```javascript
let numbers = [10, 20, 30];

let [a, , c] = numbers;

console.log(a, c);
```

Output:

```text
10 30
```

### Default Values

```javascript
let numbers = [10];

let [a, b = 20] = numbers;

console.log(a, b);
```

Output:

```text
10 20
```

### Swapping Variables

```javascript
let a = 10;

let b = 20;

[a, b] = [b, a];

console.log(a, b);
```

Output:

```text
20 10
```

## 12.3 Object Destructuring

Traditional approach:

```javascript
let student = {
    name: "Anurag",
    age: 22,
    course: "AIML"
};

let name = student.name;

let age = student.age;

console.log(name, age);
```

Using destructuring:

```javascript
let student = {
    name: "Anurag",
    age: 22,
    course: "AIML"
};

let { name, age, course } = student;

console.log(name, age, course);
```

Output:

```text
Anurag 22 AIML
```

### Renaming Variables

```javascript
let student = {
    name: "Anurag",
    age: 22
};

let { name: studentName, age: studentAge } = student;

console.log(studentName, studentAge);
```

Output:

```text
Anurag 22
```

### Default Values

```javascript
let student = {
    name: "Anurag"
};

let { name, course = "AIML" } = student;

console.log(name, course);
```

Output:

```text
Anurag AIML
```

### Nested Destructuring

```javascript
let student = {
    name: "Anurag",
    address: {
        city: "Pune",
        state: "Maharashtra"
    }
};

let {
    address: { city, state }
} = student;

console.log(city, state);
```

Output:

```text
Pune Maharashtra
```

---

# 13. Spread and Rest Operators

Both use three dots (`...`), but their purposes are different.

## 13.1 Spread Operator

The spread operator expands iterable elements or enumerable object properties into individual values.

### A. Spread with Arrays

```javascript
let a = [10, 20, 30];

let b = [...a];

console.log(b);
```

Output:

```text
[10, 20, 30]
```

### B. Combining Arrays

```javascript
let a = [1, 2];

let b = [3, 4];

let result = [...a, ...b];

console.log(result);
```

Output:

```text
[1, 2, 3, 4]
```

### C. Adding New Elements

```javascript
let numbers = [10, 20, 30];

let result = [5, ...numbers, 40];

console.log(result);
```

Output:

```text
[5, 10, 20, 30, 40]
```

### D. Spread with Objects

```javascript
let student = {
    name: "Anurag",
    age: 22
};

let updatedStudent = {
    ...student,
    course: "AIML"
};

console.log(updatedStudent);
```

Output:

```text
{
    name: "Anurag",
    age: 22,
    course: "AIML"
}
```

### E. Overriding Object Properties

```javascript
let student = {
    name: "Anurag",
    age: 22
};

let updatedStudent = {
    ...student,
    age: 23
};

console.log(updatedStudent);
```

Output:

```text
{
    name: "Anurag",
    age: 23
}
```

**Important:** Spread creates a shallow copy, not a deep copy. Nested objects may still be shared.

## 13.2 Rest Operator

The rest syntax collects multiple remaining values into a single array or object.

### A. Rest with Function Parameters

```javascript
function add(...numbers) {

    let total = 0;

    for (let num of numbers) {
        total += num;
    }

    return total;
}

console.log(add(10, 20, 30));
```

Output:

```text
60
```

### B. Rest with Array Destructuring

```javascript
let numbers = [10, 20, 30, 40, 50];

let [a, b, ...remaining] = numbers;

console.log(a);
console.log(b);
console.log(remaining);
```

Output:

```text
10
20
[30, 40, 50]
```

### C. Rest with Object Destructuring

```javascript
let student = {
    name: "Anurag",
    age: 22,
    city: "Pune",
    course: "AIML"
};

let { name, ...otherDetails } = student;

console.log(name);

console.log(otherDetails);
```

Output:

```text
Anurag

{
    age: 22,
    city: "Pune",
    course: "AIML"
}
```

## 13.3 Spread vs Rest

| Spread | Rest |
|---|---|
| Expands values | Collects remaining values |
| Used in arrays and objects | Used in function parameters and destructuring |
| Distributes elements | Groups elements |
| Example: `[...arr]` | Example: `function add(...nums)` |

---

# 14. Optional Chaining (?.)

## 14.1 What is Optional Chaining?

Optional chaining allows us to safely access object properties or call functions when an intermediate value may be `null` or `undefined`.

It avoids errors caused by accessing properties of null or undefined values.

### Without Optional Chaining

```javascript
let student = {
    name: "Anurag"
};

console.log(student.address.city);
```

This produces a TypeError because `address` does not exist.

### With Optional Chaining

```javascript
let student = {
    name: "Anurag"
};

console.log(student.address?.city);
```

Output:

```text
undefined
```

## 14.2 Optional Chaining with Nested Objects

```javascript
let student = {
    name: "Anurag",
    address: {
        city: "Pune"
    }
};

console.log(student.address?.city);
```

Output:

```text
Pune
```

## 14.3 Optional Chaining with Arrays

```javascript
let students = [
    {
        name: "Anurag"
    }
];

console.log(students[0]?.name);

console.log(students[1]?.name);
```

Output:

```text
Anurag
undefined
```

## 14.4 Optional Chaining with Functions

```javascript
let user = {
    name: "Anurag"
};

user.display?.();
```

If `display` is missing or nullish, the optional call returns `undefined` instead of throwing an error.

**Important:** Optional chaining does not make every access safe. For example, `student.address.city` still fails if `address` is undefined. Use `student.address?.city`.

---

# 15. Nullish Coalescing (??)

## 15.1 What is Nullish Coalescing?

The nullish coalescing operator (`??`) provides a default value when the left-hand operand is either:

- `null`
- `undefined`

Syntax:

```javascript
value ?? defaultValue;
```

Example:

```javascript
let username = null;

let result = username ?? "Guest";

console.log(result);
```

Output:

```text
Guest
```

## 15.2 Difference Between || and ??

Logical OR (`||`) uses any falsy value to select the right-hand operand.

Nullish coalescing (`??`) uses only `null` and `undefined`.

Example:

```javascript
let a = 0;

console.log(a || 100);

console.log(a ?? 100);
```

Output:

```text
100
0
```

Comparison:

| Value | `value || 100` | `value ?? 100` |
|---|---|---|
| `null` | 100 | 100 |
| `undefined` | 100 | 100 |
| `0` | 100 | 0 |
| `false` | 100 | false |
| `""` | 100 | "" |
| `25` | 25 | 25 |

## 15.3 Practical Example

```javascript
let student = {
    name: "Anurag",
    marks: 0
};

let marks = student.marks ?? "Not available";

console.log(marks);
```

Output:

```text
0
```

This is useful because zero is a valid value and should not be replaced by a default.

**Important:** JavaScript does not allow mixing `??` directly with `&&` or `||` without parentheses.

---

# 16. Logical Assignment Operators

## 16.1 What are Logical Assignment Operators?

Logical assignment operators combine logical operations with assignment.

They were introduced in ECMAScript 2021.

There are three important logical assignment operators:

1. `||=`
2. `&&=`
3. `??=`

## 16.2 OR Assignment (||=)

Assigns the right-hand value only when the left-hand value is falsy.

```javascript
let username = "";

username ||= "Guest";

console.log(username);
```

Output:

```text
Guest
```

Equivalent concept:

```javascript
username = username || "Guest";
```

## 16.3 AND Assignment (&&=)

Assigns the right-hand value only when the left-hand value is truthy.

```javascript
let isLoggedIn = true;

isLoggedIn &&= "Welcome User";

console.log(isLoggedIn);
```

Output:

```text
Welcome User
```

If the left-hand value is falsy, it remains unchanged.

## 16.4 Nullish Assignment (??=)

Assigns the right-hand value only when the left-hand value is `null` or `undefined`.

```javascript
let username = null;

username ??= "Guest";

console.log(username);
```

Output:

```text
Guest
```

## 16.5 Comparison

| Operator | Assignment happens when |
|---|---|
| `||=` | Left side is falsy |
| `&&=` | Left side is truthy |
| `??=` | Left side is null or undefined |

### Combined Example

```javascript
let a = 0;

let b = true;

let c = null;

a ||= 10;

b &&= false;

c ??= "Default";

console.log(a, b, c);
```

Output:

```text
10 false Default
```

---

# 17. ES Modules – Import and Export

## 17.1 What are ES Modules?

ES Modules are a standard JavaScript module system used to divide code into separate files.

Modules allow us to:
- Organize code.
- Reuse functions.
- Share variables and classes.
- Improve maintainability.
- Avoid unnecessary global variables.

There are two important keywords:

- `export`
- `import`

## 17.2 Types of Exports

1. Named export.
2. Default export.

## 17.3 Named Export

A named export allows us to export multiple values from one module.

**math.js**

```javascript
export function add(a, b) {
    return a + b;
}

export function subtract(a, b) {
    return a - b;
}

export const PI = 3.14159;
```

**app.js**

```javascript
import { add, subtract, PI } from "./math.js";

console.log(add(10, 20));

console.log(subtract(20, 10));

console.log(PI);
```

Output:

```text
30
10
3.14159
```

Important:
- Named imports use curly braces.
- Imported names must match exported names unless renamed.

## 17.4 Default Export

A module can have one default export.

**greeting.js**

```javascript
export default function greeting() {
    return "Welcome to JavaScript";
}
```

**app.js**

```javascript
import greeting from "./greeting.js";

console.log(greeting());
```

Output:

```text
Welcome to JavaScript
```

The default import can use a different local name.

## 17.5 Named and Default Export Together

**student.js**

```javascript
export const college = "ACTS Pune";

export function displayStudent() {
    console.log("Student details");
}

export default class Student {
    constructor(name) {
        this.name = name;
    }
}
```

**app.js**

```javascript
import Student, {
    college,
    displayStudent
} from "./student.js";

let s1 = new Student("Anurag");

console.log(s1.name);

console.log(college);

displayStudent();
```

## 17.6 Renaming Imports

```javascript
import { add as addition } from "./math.js";

console.log(addition(10, 20));
```

## 17.7 Importing Everything

```javascript
import * as math from "./math.js";

console.log(math.add(10, 20));

console.log(math.PI);
```

## 17.8 Using ES Modules in HTML

```html
<!DOCTYPE html>
<html>
<head>
    <title>ES Modules</title>
</head>
<body>

    <h1>JavaScript Modules</h1>

    <script type="module" src="./app.js"></script>

</body>
</html>
```

The `type="module"` attribute tells the browser to load the script as an ES module.

**Important:**
- Use a local development server such as Vite.
- Browser modules use `import` and `export`.
- Modules are automatically deferred.
- Module scripts use strict mode.
- Node.js also supports ES modules, with appropriate package or file configuration.

---

# 18. Practical Programs – JavaScript Fundamentals

Complete these programs independently before moving to the ES6+ exercises.

## Program 1: Print Your Details

```javascript
let name = "Anurag";

let age = 22;

let city = "Pune";

let course = "AIML";

console.log("Name:", name);

console.log("Age:", age);

console.log("City:", city);

console.log("Course:", course);
```

## Program 2: Addition of Two Numbers

```javascript
let a = 10;

let b = 20;

let sum = a + b;

console.log("Addition:", sum);
```

## Program 3: Check Even or Odd

```javascript
let number = 15;

if (number % 2 === 0) {
    console.log("Even Number");
} else {
    console.log("Odd Number");
}
```

## Program 4: Find the Largest of Three Numbers

```javascript
let a = 10;

let b = 25;

let c = 15;

if (a >= b && a >= c) {
    console.log("A is largest");
} else if (b >= a && b >= c) {
    console.log("B is largest");
} else {
    console.log("C is largest");
}
```

## Program 5: Calculate Grade

```javascript
let marks = 85;

if (marks >= 90) {
    console.log("Grade A+");
} else if (marks >= 80) {
    console.log("Grade A");
} else if (marks >= 70) {
    console.log("Grade B");
} else if (marks >= 40) {
    console.log("Grade C");
} else {
    console.log("Fail");
}
```

## Program 6: Multiplication Table

```javascript
let number = 5;

for (let i = 1; i <= 10; i++) {

    console.log(`${number} x ${i} = ${number * i}`);

}
```

## Program 7: Factorial of a Number

```javascript
let number = 5;

let factorial = 1;

for (let i = 1; i <= number; i++) {
    factorial *= i;
}

console.log("Factorial:", factorial);
```

Output:

```text
Factorial: 120
```

## Program 8: Reverse a String

```javascript
let text = "JavaScript";

let reversed = text.split("").reverse().join("");

console.log(reversed);
```

Output:

```text
tpircSavaJ
```

## Program 9: Count Vowels in a String

```javascript
let text = "JavaScript";

let count = 0;

for (let char of text.toLowerCase()) {

    if ("aeiou".includes(char)) {
        count++;
    }

}

console.log("Vowels:", count);
```

Output:

```text
Vowels: 3
```

## Program 10: Sum of Array Elements

```javascript
let numbers = [10, 20, 30, 40, 50];

let sum = 0;

for (let num of numbers) {
    sum += num;
}

console.log("Sum:", sum);
```

Output:

```text
Sum: 150
```

## Program 11: Find Maximum Array Element

```javascript
let numbers = [10, 50, 20, 90, 30];

let max = numbers[0];

for (let num of numbers) {

    if (num > max) {
        max = num;
    }

}

console.log("Maximum:", max);
```

Output:

```text
Maximum: 90
```

## Program 12: Reverse an Array

```javascript
let numbers = [10, 20, 30, 40, 50];

let result = numbers.reverse();

console.log(result);
```

Output:

```text
[50, 40, 30, 20, 10]
```

Note: `reverse()` modifies the original array.

## Program 13: Check Palindrome

```javascript
let text = "madam";

let reversed = text.split("").reverse().join("");

if (text === reversed) {
    console.log("Palindrome");
} else {
    console.log("Not Palindrome");
}
```

## Program 14: Generate Random Number

```javascript
let number = Math.floor(Math.random() * 100) + 1;

console.log("Random Number:", number);
```

## Program 15: Display Current Date

```javascript
let today = new Date();

console.log("Date:", today.getDate());

console.log("Month:", today.getMonth() + 1);

console.log("Year:", today.getFullYear());

console.log("Full Date:", today.toLocaleDateString("en-IN"));
```

---

# 19. ES6+ Practical Exercises

These exercises focus on modern JavaScript syntax.

## Exercise 1: Template Literals

Create variables for name, course and college. Display all details using template literals.

Expected format:

```text
My name is Anurag.
I am studying AIML.
My college is ACTS Pune.
```

Solution:

```javascript
const name = "Anurag";

const course = "AIML";

const college = "ACTS Pune";

console.log(`
My name is ${name}.
I am studying ${course}.
My college is ${college}.
`);
```

## Exercise 2: Array Destructuring

Extract the first, second and third values.

```javascript
const subjects = [
    "Java",
    "DBT",
    "Web Programming"
];

const [first, second, third] = subjects;

console.log(first);

console.log(second);

console.log(third);
```

## Exercise 3: Object Destructuring

Extract student information.

```javascript
const student = {
    name: "Anurag",
    age: 22,
    city: "Pune"
};

const { name, age, city } = student;

console.log(name, age, city);
```

## Exercise 4: Spread Operator

Combine two arrays.

```javascript
const a = [10, 20, 30];

const b = [40, 50, 60];

const result = [...a, ...b];

console.log(result);
```

## Exercise 5: Rest Operator

Create a function that accepts any number of arguments and returns their sum.

```javascript
function sum(...numbers) {

    return numbers.reduce((total, num) => total + num, 0);

}

console.log(sum(10, 20, 30, 40));
```

## Exercise 6: Optional Chaining

Safely access the city property.

```javascript
const student = {
    name: "Anurag",
    address: {
        city: "Pune"
    }
};

console.log(student.address?.city);

console.log(student.contact?.mobile);
```

## Exercise 7: Nullish Coalescing

Assign a default value when the value is null or undefined.

```javascript
let username = null;

let result = username ?? "Guest";

console.log(result);
```

## Exercise 8: Logical Assignment

```javascript
let name = "";

let age = 22;

let city = null;

name ||= "Guest";

age &&= 23;

city ??= "Pune";

console.log(name);

console.log(age);

console.log(city);
```

## Exercise 9: Array map()

Multiply each number by 5.

```javascript
const numbers = [1, 2, 3, 4, 5];

const result = numbers.map(num => num * 5);

console.log(result);
```

## Exercise 10: Array filter()

Find numbers greater than 50.

```javascript
const numbers = [10, 60, 30, 80, 100];

const result = numbers.filter(num => num > 50);

console.log(result);
```

## Exercise 11: Array reduce()

Calculate total marks.

```javascript
const marks = [80, 75, 90, 85, 70];

const total = marks.reduce((sum, mark) => sum + mark, 0);

console.log("Total Marks:", total);
```

## Exercise 12: ES Modules

Create two files.

**calculator.js**

```javascript
export const add = (a, b) => a + b;

export const multiply = (a, b) => a * b;
```

**app.js**

```javascript
import { add, multiply } from "./calculator.js";

console.log(add(10, 20));

console.log(multiply(10, 20));
```

---

# 20. CCEE and Interview Questions

## Basic Questions

1. What is JavaScript?
2. What is the difference between Java and JavaScript?
3. What are the main uses of JavaScript?
4. How can JavaScript be included in HTML?
5. What is the difference between internal and external JavaScript?
6. What is a variable?
7. What are `var`, `let` and `const`?
8. What is the difference between `let` and `const`?
9. What is dynamic typing?
10. What are JavaScript primitive data types?

## Operators and Control Structures

11. What is an operator?
12. What is the difference between `==` and `===`?
13. What is the difference between `=` and `==`?
14. What are arithmetic operators?
15. What are logical operators?
16. What is the ternary operator?
17. What is the purpose of `typeof`?
18. What is the difference between if-else and switch?
19. What is the difference between while and do-while?
20. What is the difference between break and continue?

## Strings, Numbers, Boolean and Dates

21. What is a string?
22. Are strings mutable or immutable?
23. What is the difference between `slice()` and `substring()`?
24. What is the difference between `indexOf()` and `includes()`?
25. What is the difference between `parseInt()` and `parseFloat()`?
26. What is the purpose of `toFixed()`?
27. What is NaN?
28. What are truthy and falsy values?
29. What is the difference between `null` and `undefined`?
30. What is the JavaScript Date object?

## Arrays

31. What is an array?
32. What is the difference between push and pop?
33. What is the difference between shift and unshift?
34. What is the difference between slice and splice?
35. What is the difference between map and forEach?
36. What is the difference between map and filter?
37. What is the purpose of reduce?
38. How do you sort an array of numbers?
39. What is the difference between find and filter?
40. What is the difference between an array and an object?

## ES6+ and Modules

41. What is ES6?
42. What are template literals?
43. What is destructuring?
44. What is the difference between array and object destructuring?
45. What is the spread operator?
46. What is the rest operator?
47. What is the difference between spread and rest?
48. What is optional chaining?
49. What is nullish coalescing?
50. What is the difference between `||` and `??`?
51. What are logical assignment operators?
52. What are ES modules?
53. What is the difference between named and default exports?
54. What is the purpose of `type="module"`?
55. What is the difference between `for...of` and `for...in`?

---

# 21. MCQs – Practice Test

**Q1. JavaScript is primarily used to make webpages:**

A. Static  
B. Interactive  
C. Printed  
D. Database-driven only  

**Answer: B**

**Q2. Which keyword is used to declare a block-scoped variable?**

A. var  
B. let  
C. function  
D. define  

**Answer: B**

**Q3. Which variable declaration cannot be reassigned?**

A. var  
B. let  
C. const  
D. All  

**Answer: C**

**Q4. What is the output?**

```javascript
console.log(10 == "10");
```

A. true  
B. false  
C. undefined  
D. Error  

**Answer: A**

**Q5. What is the output?**

```javascript
console.log(10 === "10");
```

A. true  
B. false  
C. null  
D. Error  

**Answer: B**

**Q6. Which operator is used for exponentiation?**

A. `*`  
B. `**`  
C. `//`  
D. `^`  

**Answer: B**

**Q7. Which loop executes at least once?**

A. for  
B. while  
C. do-while  
D. for...of  

**Answer: C**

**Q8. Which statement terminates a loop?**

A. continue  
B. break  
C. return only  
D. skip  

**Answer: B**

**Q9. Which method converts a string into uppercase?**

A. `upper()`  
B. `toUpperCase()`  
C. `uppercase()`  
D. `toUpper()`  

**Answer: B**

**Q10. What does `trim()` do?**

A. Removes all characters  
B. Removes surrounding whitespace  
C. Converts to uppercase  
D. Splits a string  

**Answer: B**

**Q11. What is the output?**

```javascript
console.log(parseInt("25.75"));
```

A. 25.75  
B. 26  
C. 25  
D. NaN  

**Answer: C**

**Q12. Which function checks whether a value is an integer?**

A. `Number.isInteger()`  
B. `Number.parseFloat()`  
C. `Math.floor()`  
D. `isString()`  

**Answer: A**

**Q13. Which of the following is a falsy value?**

A. `"0"`  
B. `[]`  
C. `{}`  
D. `0`  

**Answer: D**

**Q14. What does `getMonth()` return?**

A. Month from 1 to 12  
B. Month from 0 to 11  
C. Day from 0 to 31  
D. Year  

**Answer: B**

**Q15. Array indexes start from:**

A. 1  
B. 0  
C. -1  
D. 2  

**Answer: B**

**Q16. Which method adds an element to the end of an array?**

A. shift  
B. pop  
C. push  
D. unshift  

**Answer: C**

**Q17. Which method creates a new array by transforming elements?**

A. map  
B. push  
C. pop  
D. reverse  

**Answer: A**

**Q18. Which method returns elements matching a condition?**

A. map  
B. filter  
C. reduce  
D. join  

**Answer: B**

**Q19. Which method reduces an array to a single value?**

A. map  
B. filter  
C. reduce  
D. slice  

**Answer: C**

**Q20. Template literals use:**

A. Single quotes  
B. Double quotes  
C. Backticks  
D. Brackets  

**Answer: C**

**Q21. Which syntax is used for array destructuring?**

A. `{a, b}`  
B. `[a, b]`  
C. `(a, b)`  
D. `<a, b>`  

**Answer: B**

**Q22. Which operator is used for spread and rest syntax?**

A. `..`  
B. `...`  
C. `***`  
D. `&&`  

**Answer: B**

**Q23. What is the output?**

```javascript
let a = null;

console.log(a ?? 10);
```

A. null  
B. undefined  
C. 10  
D. Error  

**Answer: C**

**Q24. What does optional chaining use?**

A. `??`  
B. `?.`  
C. `&&`  
D. `||`  

**Answer: B**

**Q25. Which operator assigns a default value only when the variable is null or undefined?**

A. `||=`  
B. `&&=`  
C. `??=`  
D. `+=`  

**Answer: C**

**Q26. Which keyword exports a default value from a module?**

A. import  
B. export default  
C. require  
D. include  

**Answer: B**

**Q27. Which keyword imports named exports?**

A. `import { }`  
B. `export { }`  
C. `include { }`  
D. `require { }`  

**Answer: A**

**Q28. Which attribute enables ES modules in a browser script?**

A. `async="module"`  
B. `type="module"`  
C. `module="true"`  
D. `script="module"`  

**Answer: B**

**Q29. What is the output?**

```javascript
console.log(typeof null);
```

A. null  
B. undefined  
C. object  
D. boolean  

**Answer: C**

**Q30. Which loop iterates over values of an array?**

A. for...in  
B. for...of  
C. while...in  
D. switch  

**Answer: B**

---

# 22. Quick Revision Sheet

| Topic | Important Syntax |
|---|---|
| Variable | `let x = 10;` |
| Constant | `const PI = 3.14;` |
| Old variable declaration | `var x = 10;` |
| Strict equality | `a === b` |
| Logical AND | `a && b` |
| Logical OR | `a || b` |
| Ternary | `condition ? a : b` |
| If | `if (condition) {}` |
| Switch | `switch(value) {}` |
| For loop | `for(let i=0; i<5; i++) {}` |
| While loop | `while(condition) {}` |
| String length | `str.length` |
| Uppercase | `str.toUpperCase()` |
| Lowercase | `str.toLowerCase()` |
| Trim | `str.trim()` |
| String split | `str.split(",")` |
| Parse integer | `parseInt(value)` |
| Parse decimal | `parseFloat(value)` |
| Integer check | `Number.isInteger(value)` |
| Current date | `new Date()` |
| Get year | `date.getFullYear()` |
| Array push | `arr.push(value)` |
| Array pop | `arr.pop()` |
| Array map | `arr.map()` |
| Array filter | `arr.filter()` |
| Array reduce | `arr.reduce()` |
| Template literal | `` `Hello ${name}` `` |
| Array destructuring | `const [a,b] = arr` |
| Object destructuring | `const {name} = obj` |
| Spread | `[...arr]` |
| Rest | `function add(...args) {}` |
| Optional chaining | `obj?.property` |
| Nullish coalescing | `value ?? defaultValue` |
| OR assignment | `x ||= value` |
| AND assignment | `x &&= value` |
| Nullish assignment | `x ??= value` |
| Named export | `export { add }` |
| Named import | `import { add } from "./math.js"` |
| Default export | `export default function()` |
| Default import | `import myFunction from "./file.js"` |

---

# 23. Self-Learning Tasks (2 SL)

Complete these additional exercises to strengthen your JavaScript fundamentals.

## Task 1: Student Marks Management

Create an array of student objects.

```javascript
const students = [
    {
        name: "Anurag",
        marks: 85
    },
    {
        name: "Rahul",
        marks: 72
    },
    {
        name: "Sneha",
        marks: 92
    },
    {
        name: "Amit",
        marks: 65
    }
];
```

Tasks:

1. Display all students using `forEach()`.
2. Find students scoring more than 75 using `filter()`.
3. Find the student scoring more than 90 using `find()`.
4. Create a new array containing only student names using `map()`.
5. Calculate total marks using `reduce()`.
6. Calculate average marks.

## Task 2: Employee Management

Create an employee object:

```javascript
const employee = {
    id: 101,
    name: "Anurag",
    department: "Development",
    salary: 45000,
    address: {
        city: "Pune",
        state: "Maharashtra"
    }
};
```

Tasks:

1. Extract employee details using object destructuring.
2. Rename the extracted name variable.
3. Use optional chaining to access the city.
4. Use nullish coalescing for a missing phone number.
5. Use spread syntax to create an updated employee object.
6. Use template literals to display employee details.

## Task 3: Shopping Cart

Create an array:

```javascript
const cart = [
    {
        product: "Laptop",
        price: 50000,
        quantity: 1
    },
    {
        product: "Mouse",
        price: 500,
        quantity: 2
    },
    {
        product: "Keyboard",
        price: 1000,
        quantity: 1
    }
];
```

Tasks:

1. Display all products.
2. Calculate the total quantity.
3. Calculate the total bill using `reduce()`.
4. Filter products with a price above ₹1000.
5. Create a new array containing product names.
6. Add another product using `push()`.

## Task 4: ES6+ Calculator

Create a calculator using:
- Arrow functions
- Template literals
- Rest parameters
- Destructuring
- Default parameters

Required operations:
- Addition
- Subtraction
- Multiplication
- Division

## Task 5: Module-Based Application

Create a project with the following structure:

```text
calculator-project/
│
├── index.html
│
└── src/
    ├── app.js
    └── calculator.js
```

Requirements:

1. Create arithmetic functions in `calculator.js`.
2. Export the functions.
3. Import them in `app.js`.
4. Display the results.
5. Run the project using a local development server.

---

# 24. Recommended References and Learning Resources

## Books

1. **JavaScript: The Definitive Guide, 7th Edition – David Flanagan**
   - JavaScript fundamentals.
   - Variables and operators.
   - Functions, objects and arrays.
   - Modern JavaScript features.

2. **Web Development with Node and Express – Ethan Brown**
   - JavaScript in web applications.
   - Browser and server-side JavaScript.
   - Modules and application architecture.

3. **React in Depth – Morten Barklund**
   - Modern JavaScript syntax.
   - Array methods.
   - Destructuring and spread syntax.
   - JavaScript used in React applications.

## Official Online Resources

- MDN JavaScript Guide: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide
- JavaScript Reference: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference
- JavaScript Array Methods: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array
- JavaScript String Methods: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String
- JavaScript Date: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date
- JavaScript Modules: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules
- ECMAScript Specification: https://tc39.es/ecma262/

---

# 25. Session 5 Learning Checklist

## JavaScript Fundamentals

- [ ] Understand JavaScript and its applications.
- [ ] Include JavaScript in HTML.
- [ ] Understand variables: var, let and const.
- [ ] Understand variable scope.
- [ ] Understand hoisting.
- [ ] Understand statements, operators and expressions.
- [ ] Practise arithmetic, comparison and logical operators.
- [ ] Use if, if-else and switch.
- [ ] Practise for, while and do-while loops.

## JavaScript Data Handling

- [ ] Understand strings and string methods.
- [ ] Understand numbers and number methods.
- [ ] Understand Boolean values.
- [ ] Understand truthy and falsy values.
- [ ] Create and manipulate Date objects.
- [ ] Create and manipulate arrays.
- [ ] Practise map, filter, find and reduce.

## ES6+ Features

- [ ] Use template literals.
- [ ] Perform array destructuring.
- [ ] Perform object destructuring.
- [ ] Use spread syntax.
- [ ] Use rest parameters.
- [ ] Use optional chaining.
- [ ] Use nullish coalescing.
- [ ] Use logical assignment operators.
- [ ] Create modules using export and import.

## Practical Work

- [ ] Complete basic JavaScript programs.
- [ ] Complete string and array programs.
- [ ] Complete ES6+ exercises.
- [ ] Create a calculator using JavaScript.
- [ ] Create a module-based application.
- [ ] Solve CCEE MCQs.

---

# 26. Final Learning Goal

After completing Session 5, you should be able to:

1. Write JavaScript programs independently.
2. Understand variables, operators and control structures.
3. Work with strings, numbers, dates and arrays.
4. Manipulate data using modern array methods.
5. Use ES6+ syntax confidently.
6. Organize JavaScript code using modules.
7. Write clean, reusable and maintainable JavaScript code.

**Recommended next step:** After mastering these fundamentals, move towards functions, objects, DOM manipulation, events and form validation in the upcoming JavaScript sessions.
