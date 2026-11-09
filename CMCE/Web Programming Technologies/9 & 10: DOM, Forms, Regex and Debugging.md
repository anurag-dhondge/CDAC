# Sessions 9 & 10: DOM, Forms, Regex and Debugging

## 1. Document Object Model (DOM)

### 1.1 What is DOM?

DOM stands for **Document Object Model**.

The DOM is a programming interface provided by the browser that represents an HTML document as a tree of objects.

JavaScript uses the DOM to:
- Access HTML elements.
- Change text and HTML content.
- Modify CSS styles.
- Add or remove HTML elements.
- Handle user events such as clicks and key presses.
- Read and validate form data.

**Example HTML:**

```html
<!DOCTYPE html>
<html>
<head>
    <title>DOM Example</title>
</head>
<body>
    <h1 id="heading">Hello World</h1>
    <button onclick="changeText()">Click Me</button>

    <script>
        function changeText() {
            document.getElementById("heading").textContent =
                "Welcome to JavaScript DOM!";
        }
    </script>
</body>
</html>
```

When the user clicks the button, JavaScript changes the heading.

**Important:** HTML provides the document structure, CSS provides presentation, and JavaScript uses the DOM to interact with the document.

### 1.2 Object hierarchy in JavaScript

The browser provides a hierarchy of objects that allows JavaScript to interact with the webpage and browser environment.

A simplified browser object hierarchy:

```text
Window
  |
  |-- document
  |     |
  |     |-- html
  |           |
  |           |-- head
  |           |     |-- title
  |           |
  |           |-- body
  |                 |-- h1
  |                 |-- p
  |                 |-- button
  |
  |-- location
  |-- history
  |-- navigator
  |-- console
  |-- localStorage
```

**Important objects:**

| Object | Purpose |
|---|---|
| `window` | Represents the browser window |
| `document` | Represents the current HTML document |
| `location` | Provides information about the current URL |
| `history` | Manages browser session history |
| `navigator` | Provides information about the browser |
| `console` | Provides debugging methods |

Example:

```javascript
console.log(window);
console.log(document);
console.log(location.href);
console.log(navigator.userAgent);
```

**Relationship between window and document:**

- `window` is the global browser object.
- `document` is a property of `window`.
- `document` represents the webpage.

```javascript
console.log(window.document);
console.log(document);
```

Both refer to the same document object.

### 1.3 DOM tree structure

Consider this HTML:

```html
<html>
<body>
    <h1>Welcome</h1>
    <p>Learning JavaScript</p>
</body>
</html>
```

Its simplified DOM tree:

```text
Document
   |
   HTML
    |
    BODY
    |------ H1
    |        |
    |      Text
    |
    |------ P
             |
           Text
```

Every HTML element becomes an object in the DOM.

**Types of DOM nodes:**

1. Document Node: Represents the entire document.
2. Element Node: Represents HTML elements such as `div`, `p`, and `h1`.
3. Text Node: Represents text inside elements.
4. Attribute Node: Represents HTML attributes in the DOM model.
5. Comment Node: Represents HTML comments.

Note: Attributes can be accessed through element properties and methods such as `getAttribute()` and `setAttribute()`.

### 1.4 Elements

An element is an HTML component represented as a DOM object.

Example:

```html
<h1 id="title">Hello</h1>
<p class="description">Welcome</p>
```

JavaScript can access these elements in different ways.

**A. getElementById()**

Selects an element using its ID.

```javascript
let heading = document.getElementById("title");

console.log(heading);
```

**B. getElementsByClassName()**

Selects elements using a class name.

```javascript
let elements =
    document.getElementsByClassName("description");

console.log(elements);
```

Returns an HTMLCollection.

**C. getElementsByTagName()**

Selects elements using their tag name.

```javascript
let paragraphs =
    document.getElementsByTagName("p");

console.log(paragraphs);
```

**D. querySelector()**

Returns the first element matching a CSS selector.

```javascript
let heading = document.querySelector("#title");

let paragraph = document.querySelector(".description");
```

**E. querySelectorAll()**

Returns all matching elements as a static NodeList.

```javascript
let paragraphs = document.querySelectorAll("p");

paragraphs.forEach(function (p) {
    console.log(p.textContent);
});
```

**Comparison:**

| Method | Returns | Selection |
|---|---|---|
| `getElementById()` | Element or null | ID |
| `getElementsByClassName()` | Live HTMLCollection | Class |
| `getElementsByTagName()` | Live HTMLCollection | Tag |
| `querySelector()` | Element or null | First CSS match |
| `querySelectorAll()` | Static NodeList | All CSS matches |

### 1.5 DOM properties

Common properties used to access or modify elements:

| Property | Purpose |
|---|---|
| `innerHTML` | Gets or sets HTML content |
| `textContent` | Gets or sets text content |
| `innerText` | Gets or sets rendered text |
| `value` | Gets or sets form control value |
| `id` | Gets or sets element ID |
| `className` | Gets or sets class attribute |
| `classList` | Manipulates CSS classes |
| `style` | Accesses inline CSS styles |

Example:

```html
<p id="message">Original Message</p>
<input type="text" id="username">
```

```javascript
let message = document.getElementById("message");

message.textContent = "Updated Message";

let username = document.getElementById("username");

username.value = "Anurag";

console.log(username.value);
```

**Difference between innerHTML and textContent:**

```javascript
let element = document.getElementById("message");

element.innerHTML = "<b>Hello</b>";
```

Displays bold HTML text.

```javascript
element.textContent = "<b>Hello</b>";
```

Displays the literal text `<b>Hello</b>`.

Security note: Avoid inserting untrusted user input through `innerHTML`, because it can introduce Cross-Site Scripting (XSS) vulnerabilities. Prefer `textContent` for plain text.

---

## 2. DOM Events

### 2.1 What are events?

An event is an action or occurrence detected by the browser.

Examples:
- User clicks a button.
- User types into an input.
- User submits a form.
- User moves the mouse.
- A webpage finishes loading.

JavaScript can execute a function when an event occurs.

### 2.2 Common JavaScript events

| Event | Description |
|---|---|
| `click` | User clicks an element |
| `dblclick` | User double-clicks |
| `mouseover` | Mouse moves over an element |
| `mouseout` | Mouse leaves an element |
| `keydown` | A keyboard key is pressed |
| `keyup` | A keyboard key is released |
| `input` | Input value changes |
| `change` | Value change is committed |
| `submit` | Form is submitted |
| `focus` | Element receives focus |
| `blur` | Element loses focus |
| `load` | Resource or document loads |
| `DOMContentLoaded` | HTML parsing is complete |

### 2.3 Ways to handle events

**Method 1: Inline event handler**

```html
<button onclick="showMessage()">Click</button>

<script>
function showMessage() {
    alert("Button clicked!");
}
</script>
```

**Method 2: DOM event property**

```html
<button id="btn">Click Me</button>

<script>
let button = document.getElementById("btn");

button.onclick = function () {
    alert("Button clicked!");
};
</script>
```

**Method 3: addEventListener()**

This is generally the preferred approach.

```html
<button id="btn">Click Me</button>

<script>
let button = document.getElementById("btn");

button.addEventListener("click", function () {
    alert("Button clicked!");
});
</script>
```

Advantages:
- Multiple event listeners can be attached.
- HTML and JavaScript remain separated.
- Event listeners can be removed.
- Better code organization.

### 2.4 Event object

When an event occurs, the browser passes an event object to the event handler.

It contains information about the event.

```javascript
document.getElementById("btn")
    .addEventListener("click", function (event) {
        console.log(event);
        console.log(event.target);
        console.log(event.type);
    });
```

Important event properties:

| Property | Description |
|---|---|
| `event.target` | Actual element that triggered the event |
| `event.currentTarget` | Element whose listener is currently executing |
| `event.type` | Event type |
| `event.key` | Keyboard key |
| `event.clientX` | Mouse X coordinate |
| `event.clientY` | Mouse Y coordinate |

### 2.5 Event propagation

Event propagation describes how an event travels through the DOM tree.

There are three phases:

1. Capturing phase: Event travels from the document towards the target.
2. Target phase: Event reaches the target element.
3. Bubbling phase: Event travels from the target back towards the document.

Example:

```html
<div id="parent">
    Parent
    <button id="child">Click Me</button>
</div>
```

```javascript
document.getElementById("parent")
    .addEventListener("click", function () {
        console.log("Parent clicked");
    });

document.getElementById("child")
    .addEventListener("click", function () {
        console.log("Child clicked");
    });
```

When the button is clicked, output:

```text
Child clicked
Parent clicked
```

This happens because click events normally bubble.

**stopPropagation():**

Stops an event from propagating further.

```javascript
document.getElementById("child")
    .addEventListener("click", function (event) {
        event.stopPropagation();
        console.log("Child clicked");
    });
```

**preventDefault():**

Prevents the browser's default action.

Example:

```javascript
document.querySelector("form")
    .addEventListener("submit", function (event) {
        event.preventDefault();
        console.log("Default form submission prevented");
    });
```

Important: `preventDefault()` and `stopPropagation()` perform different tasks.

### 2.6 Event delegation

Event delegation means attaching one event listener to a parent element instead of attaching separate listeners to every child.

```html
<ul id="fruits">
    <li>Apple</li>
    <li>Mango</li>
    <li>Banana</li>
</ul>
```

```javascript
document.getElementById("fruits")
    .addEventListener("click", function (event) {

        if (event.target.tagName === "LI") {
            console.log(event.target.textContent);
        }

    });
```

Benefits:
- Fewer event listeners.
- Better performance for large lists.
- Works with dynamically added child elements.

---

## 3. DOM Methods and Manipulation

DOM manipulation means dynamically changing the structure, content, attributes, and styles of a webpage using JavaScript.

### 3.1 Creating elements

`document.createElement()` creates a new HTML element.

```javascript
let paragraph = document.createElement("p");

paragraph.textContent = "This is a new paragraph";

document.body.appendChild(paragraph);
```

### 3.2 appendChild()

Adds a node as the last child of an element.

```javascript
let div = document.createElement("div");

div.textContent = "Hello";

document.body.appendChild(div);
```

### 3.3 append()

Adds one or more nodes or strings.

```javascript
let div = document.createElement("div");

div.append("Hello ", "JavaScript");

document.body.append(div);
```

### 3.4 prepend()

Adds content at the beginning of an element.

```javascript
let list = document.getElementById("list");

let item = document.createElement("li");

item.textContent = "First Item";

list.prepend(item);
```

### 3.5 remove()

Removes an element.

```javascript
let element = document.getElementById("message");

element.remove();
```

### 3.6 removeChild()

Removes a child from its parent.

```javascript
let parent = document.getElementById("parent");

let child = document.getElementById("child");

parent.removeChild(child);
```

### 3.7 setAttribute() and getAttribute()

Used to access and modify HTML attributes.

```javascript
let image = document.querySelector("img");

image.setAttribute("alt", "Profile Photo");

console.log(image.getAttribute("alt"));
```

### 3.8 classList methods

Used to manipulate CSS classes.

```javascript
let box = document.getElementById("box");

box.classList.add("active");

box.classList.remove("active");

box.classList.toggle("active");

console.log(box.classList.contains("active"));
```

### 3.9 Changing CSS using JavaScript

```javascript
let heading = document.getElementById("heading");

heading.style.color = "blue";
heading.style.backgroundColor = "yellow";
heading.style.fontSize = "30px";
```

Better approach: Define CSS classes and add or remove them through `classList`.

```css
.highlight {
    color: blue;
    background-color: yellow;
}
```

```javascript
heading.classList.add("highlight");
```

### 3.10 DOM traversal

DOM traversal means moving between related elements.

| Property | Purpose |
|---|---|
| `parentElement` | Gets parent element |
| `children` | Gets child elements |
| `firstElementChild` | Gets first child element |
| `lastElementChild` | Gets last child element |
| `nextElementSibling` | Gets next sibling element |
| `previousElementSibling` | Gets previous sibling element |

Example:

```javascript
let child = document.getElementById("child");

console.log(child.parentElement);
console.log(child.nextElementSibling);
console.log(child.previousElementSibling);
```

---

## 4. Forms, Forms API and Form Validation

### 4.1 What is an HTML form?

An HTML form collects information from users.

Examples:
- Registration forms.
- Login forms.
- Resume forms.
- Contact forms.
- Admission forms.

Example:

```html
<form id="myForm">
    <label>Name:</label>
    <input type="text" id="name">

    <label>Email:</label>
    <input type="email" id="email">

    <button type="submit">Submit</button>
</form>
```

### 4.2 Accessing form elements

JavaScript can access form controls using the DOM.

```javascript
let form = document.getElementById("myForm");

let name = document.getElementById("name");

console.log(name.value);
```

### 4.3 Forms API

The HTMLFormElement API provides properties and methods to interact with forms.

Important properties:

| Property | Description |
|---|---|
| `form.elements` | Collection of form controls |
| `form.length` | Number of controls |
| `form.action` | Form submission URL |
| `form.method` | HTTP method |
| `form.name` | Form name |
| `form.noValidate` | Controls browser validation behavior |

Important methods:

| Method | Purpose |
|---|---|
| `submit()` | Submits the form without firing the submit event or interactive constraint validation |
| `requestSubmit()` | Submits the form as if a submit button were activated |
| `reset()` | Resets form controls |
| `checkValidity()` | Checks validity of the form controls |
| `reportValidity()` | Checks validity and displays browser validation messages |

Example:

```javascript
let form = document.getElementById("myForm");

console.log(form.elements);
console.log(form.length);

form.reset();
```

### 4.4 Accessing form controls through elements

```html
<form id="studentForm">
    <input type="text" name="studentName">
    <input type="email" name="email">
    <button type="submit">Submit</button>
</form>
```

```javascript
let form = document.getElementById("studentForm");

console.log(form.elements["studentName"].value);
console.log(form.elements["email"].value);
```

### 4.5 Types of form validation

**1. Required validation**

Ensures that a field is not empty.

```javascript
if (name.value.trim() === "") {
    console.log("Name is required");
}
```

**2. Email validation**

```javascript
let email = "abc@gmail.com";

let emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

if (emailPattern.test(email)) {
    console.log("Valid email format");
} else {
    console.log("Invalid email format");
}
```

**3. Mobile number validation**

For a 10-digit Indian mobile number beginning with 6, 7, 8 or 9:

```javascript
let mobilePattern = /^[6-9]\d{9}$/;

console.log(mobilePattern.test("9876543210"));
```

**4. Minimum length validation**

```javascript
if (password.length < 8) {
    console.log("Password must contain at least 8 characters");
}
```

### 4.6 Constraint Validation API

HTML provides built-in validation features.

Example:

```html
<form id="form">
    <input type="text" id="name" required minlength="3">

    <input type="email" id="email" required>

    <button type="submit">Submit</button>
</form>
```

JavaScript:

```javascript
let name = document.getElementById("name");

console.log(name.validity.valid);
console.log(name.validity.valueMissing);
console.log(name.validity.tooShort);
console.log(name.validationMessage);
```

Important Constraint Validation API properties:

| Property | Meaning |
|---|---|
| `validity.valid` | Input satisfies constraints |
| `validity.valueMissing` | Required value is missing |
| `validity.typeMismatch` | Value does not match expected type |
| `validity.tooShort` | Value is shorter than minimum |
| `validity.tooLong` | Value exceeds maximum |
| `validity.patternMismatch` | Value does not match pattern |
| `validity.rangeUnderflow` | Value is below minimum |
| `validity.rangeOverflow` | Value exceeds maximum |

Methods:

```javascript
input.checkValidity();

input.reportValidity();

input.setCustomValidity("Please enter a valid value.");
```

To clear a custom error:

```javascript
input.setCustomValidity("");
```

**Important:** Client-side validation improves user experience, but server-side validation is also necessary because users can bypass browser-side checks.

---

## 5. Regular Expressions (Regex)

### 5.1 What is Regex?

Regex stands for **Regular Expression**.

A regular expression is a pattern used to search, match, validate, or replace text.

Common applications:
- Email format checking.
- Mobile number validation.
- Password validation.
- Finding words in a string.
- Replacing unwanted characters.
- Extracting information from text.

### 5.2 Creating a regular expression

Two common ways:

**Method 1: Regex literal**

```javascript
let pattern = /hello/;
```

**Method 2: RegExp constructor**

```javascript
let pattern = new RegExp("hello");
```

### 5.3 Regex methods

**1. test()**

Checks whether a pattern exists in a string.

Returns `true` or `false`.

```javascript
let pattern = /hello/;

console.log(pattern.test("hello world")); // true
console.log(pattern.test("good morning")); // false
```

**2. match()**

Returns matching results.

```javascript
let text = "JavaScript is powerful";

console.log(text.match(/JavaScript/));
```

**3. matchAll()**

Returns an iterator containing all matches and their details.

```javascript
let text = "cat bat rat";

let result = text.matchAll(/[a-z]at/g);

for (let item of result) {
    console.log(item[0]);
}
```

**4. replace()**

Replaces matched text.

```javascript
let text = "I like Java";

console.log(text.replace(/Java/, "JavaScript"));
```

**5. search()**

Returns the index of the first match or `-1`.

```javascript
let text = "Hello JavaScript";

console.log(text.search(/JavaScript/));
```

### 5.4 Common Regex symbols

| Symbol | Meaning | Example |
|---|---|---|
| `.` | Any character except line terminators by default | `/a.c/` |
| `^` | Beginning of string or line | `/^Hello/` |
| `$` | End of string or line | `/world$/` |
| `*` | Zero or more | `/ab*/` |
| `+` | One or more | `/ab+/` |
| `?` | Zero or one | `/colou?r/` |
| `{n}` | Exactly n repetitions | `/\d{4}/` |
| `{n,}` | At least n repetitions | `/\d{3,}/` |
| `{n,m}` | Between n and m repetitions | `/\d{2,5}/` |
| `[]` | Character set | `/[abc]/` |
| `[^]` | Negated character set | `/[^0-9]/` |
| `()` | Capturing group | `/(ab)+/` |
| `\|` | Alternation (OR) | `/cat\|dog/` |
| `\d` | Digit | `/\d/` |
| `\D` | Non-digit | `/\D/` |
| `\w` | Word character | `/\w/` |
| `\W` | Non-word character | `/\W/` |
| `\s` | Whitespace | `/\s/` |
| `\S` | Non-whitespace | `/\S/` |
| `\b` | Word boundary | `/\bcat\b/` |

### 5.5 Regex flags

Flags change how a regular expression behaves.

| Flag | Meaning |
|---|---|
| `g` | Global: find all matches |
| `i` | Case-insensitive |
| `m` | Multiline |
| `s` | Dot matches line terminators |
| `u` | Unicode-aware mode |
| `y` | Sticky matching |
| `d` | Provides match indices |

Example:

```javascript
let text = "JavaScript javascript JAVASCRIPT";

console.log(text.match(/javascript/gi));
```

Output:

```javascript
["JavaScript", "javascript", "JAVASCRIPT"]
```

### 5.6 Common practical regular expressions

**A. Name validation**

```javascript
let namePattern = /^[A-Za-z ]{2,50}$/;

console.log(namePattern.test("Anurag Dhondge"));
```

**B. Indian mobile number**

```javascript
let mobilePattern = /^[6-9]\d{9}$/;

console.log(mobilePattern.test("9876543210"));
```

**C. Email format**

```javascript
let emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

console.log(emailPattern.test("abc@gmail.com"));
```

**D. Password validation**

At least eight characters, with one uppercase letter, one lowercase letter, one digit, and one special character:

```javascript
let passwordPattern =
    /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[^A-Za-z0-9]).{8,}$/;

console.log(passwordPattern.test("Hello@123"));
```

**E. Extract numbers**

```javascript
let text = "My marks are 80 and 95";

console.log(text.match(/\d+/g));
```

Output:

```javascript
["80", "95"]
```

**F. Replace spaces**

```javascript
let text = "Hello JavaScript World";

console.log(text.replace(/\s/g, "-"));
```

Output:

```text
Hello-JavaScript-World
```

### 5.7 Difference between regex validity and input validation

These are two different tasks.

**Task 1: Check whether a string matches a regular expression.**

```javascript
function validateMobile(value) {
    let pattern = /^[6-9]\d{9}$/;

    return pattern.test(value);
}

console.log(validateMobile("9876543210")); // true
```

**Task 2: Check whether a string contains valid regex syntax.**

```javascript
function isValidRegex(patternString) {
    try {
        new RegExp(patternString);
        return true;
    } catch (error) {
        return false;
    }
}

console.log(isValidRegex("[a-z]+")); // true
console.log(isValidRegex("[a-z"));   // false
```

The second function checks whether the pattern itself can be compiled. It does not check whether a particular input matches it.

---

## 6. Errors and Debugging

### 6.1 What is an error?

An error is a problem in a program that prevents it from executing correctly or produces an unexpected result.

Example:

```javascript
console.log(x);
```

If `x` has not been declared, JavaScript throws a ReferenceError.

### 6.2 Types of JavaScript errors

**1. SyntaxError**

Occurs when JavaScript syntax is invalid.

```javascript
// Missing closing parenthesis
console.log("Hello";
```

**2. ReferenceError**

Occurs when accessing a variable that is not available.

```javascript
console.log(username);
```

**3. TypeError**

Occurs when an operation is performed on an incompatible value.

```javascript
let name = null;

console.log(name.toUpperCase());
```

**4. RangeError**

Occurs when a value is outside an allowed range.

```javascript
let number = 1;

number.toFixed(101);
```

**5. URIError**

Occurs when URI-related functions receive an invalid URI sequence.

```javascript
decodeURIComponent("%");
```

**6. AggregateError**

Represents multiple errors grouped together, such as when multiple promises fail in `Promise.any()`.

### 6.3 Error handling using try-catch-finally

`try-catch` handles runtime exceptions.

```javascript
try {
    let result = 10 / 0;

    console.log(result);

} catch (error) {

    console.log("An error occurred:", error.message);

} finally {

    console.log("Execution completed");
}
```

Note: Division by zero with JavaScript numbers returns `Infinity`; it does not throw an exception. The example demonstrates `finally`, not an actual caught error.

Better example:

```javascript
try {
    JSON.parse("{invalid json}");

} catch (error) {

    console.log("Invalid JSON:", error.message);

} finally {

    console.log("Finished");
}
```

**finally** executes whether an exception occurs or not, except in unusual cases where execution is interrupted.

### 6.4 throw keyword

The `throw` keyword is used to generate a custom error.

```javascript
function calculateAge(age) {

    if (age < 0) {
        throw new Error("Age cannot be negative");
    }

    return age;
}

try {
    console.log(calculateAge(-5));

} catch (error) {
    console.log(error.message);
}
```

### 6.5 Custom errors

You can create custom error classes.

```javascript
class ValidationError extends Error {

    constructor(message) {
        super(message);
        this.name = "ValidationError";
    }
}

try {
    throw new ValidationError("Invalid student data");

} catch (error) {

    console.log(error.name);
    console.log(error.message);
}
```

### 6.6 Debugging

Debugging is the process of identifying, analyzing, and fixing errors in a program.

Common debugging techniques:

1. `console.log()` – Displays values.
2. `console.error()` – Displays errors.
3. `console.warn()` – Displays warnings.
4. `debugger` – Pauses code execution when developer tools are open.
5. Browser breakpoints – Pause execution at selected lines.
6. Step-by-step execution – Execute code one line at a time.

Example:

```javascript
function calculateTotal(price, quantity) {

    debugger;

    let total = price * quantity;

    console.log(total);

    return total;
}

calculateTotal(100, 5);
```

When DevTools is open, execution pauses at `debugger`.

---

## 7. Introduction to Browser Developer Tools

Browser Developer Tools (DevTools) are built-in tools used to inspect, test, debug, and analyze web applications.

In Chrome:

- Press `F12`.
- Or press `Ctrl + Shift + I`.
- Or right-click a webpage and select Inspect.

### 7.1 Important DevTools tabs

**1. Elements**

Used to:
- Inspect HTML elements.
- View DOM structure.
- Modify HTML temporarily.
- Inspect CSS styles.
- Test CSS changes.

**2. Console**

Used to:
- Execute JavaScript commands.
- View logs.
- Identify JavaScript errors.
- Test expressions.

Example:

```javascript
console.log("Hello");
```

**3. Sources**

Used to:
- View JavaScript source files.
- Set breakpoints.
- Debug code.
- Step through execution.
- Inspect local variables and the call stack.

**4. Network**

Used to:
- Inspect API requests.
- Check HTTP status codes.
- View request and response headers.
- Inspect JSON responses.
- Identify failed network requests.
- Check loading time.

**5. Application**

Used to inspect:
- Local Storage.
- Session Storage.
- Cookies.
- IndexedDB.
- Cache Storage.

**6. Performance**

Used to analyze webpage performance, including runtime activity and loading behavior.

### 7.2 Debugging with breakpoints

Example:

```javascript
function add(a, b) {
    let result = a + b;

    console.log(result);

    return result;
}

add(10, 20);
```

Steps:

1. Open DevTools.
2. Go to Sources.
3. Open the JavaScript file.
4. Click the line number where you want execution to pause.
5. Reload or execute the code.
6. Inspect variables.
7. Use Step Over, Step Into, and Step Out.

Important debugging controls:

| Control | Purpose |
|---|---|
| Resume | Continue execution |
| Step Over | Execute the current line without entering called functions |
| Step Into | Enter a called function |
| Step Out | Finish the current function and return to its caller |
| Restart | Restart execution where supported |

---

## 8. Code Quality Using ESLint

### 8.1 What is ESLint?

ESLint is a JavaScript static analysis tool used to identify:
- Programming errors.
- Suspicious code.
- Unused variables.
- Undefined variables.
- Inconsistent coding styles.
- Potential code quality problems.

It analyzes code without needing to execute the application.

### 8.2 Why use ESLint?

Benefits:

1. Identifies common JavaScript mistakes.
2. Maintains consistent coding standards.
3. Improves code readability.
4. Detects unused variables.
5. Helps maintain large projects.
6. Can be integrated with editors and build workflows.

### 8.3 Installing ESLint

First, create a project:

```bash
mkdir eslint-demo
cd eslint-demo

npm init -y
```

Install ESLint:

```bash
npm install --save-dev eslint
```

Initialize configuration using the current ESLint CLI:

```bash
npx eslint --init
```

Follow the prompts to generate a suitable configuration.

### 8.4 Running ESLint

Suppose `app.js` contains:

```javascript
let username = "Anurag";

var age = 22;

console.log(username);
```

Run:

```bash
npx eslint app.js
```

ESLint reports issues according to your configured rules.

### 8.5 Example ESLint configuration

A simple flat configuration can be written in `eslint.config.js`:

```javascript
const js = require("@eslint/js");

module.exports = [
    {
        files: ["**/*.js"],
        languageOptions: {
            ecmaVersion: "latest",
            sourceType: "commonjs"
        },
        rules: {
            ...js.configs.recommended.rules,
            "no-unused-vars": "warn",
            "no-var": "error",
            "eqeqeq": "error",
            "semi": ["error", "always"]
        }
    }
];
```

Install the recommended rules package:

```bash
npm install --save-dev @eslint/js
```

This example uses CommonJS configuration. For an ESM project, use `import` and `export default` instead.

### 8.6 Common ESLint rules

| Rule | Purpose |
|---|---|
| `no-unused-vars` | Detects unused variables |
| `no-undef` | Detects undefined variables |
| `no-var` | Disallows `var` |
| `eqeqeq` | Enforces strict equality |
| `semi` | Controls semicolon usage |
| `no-console` | Controls console statements |
| `no-debugger` | Disallows debugger statements |

Remember: ESLint is a code quality and static analysis tool. It is not a replacement for testing or runtime debugging.

---

## 9. Fetch API and JSON

### 9.1 What is an API?

API stands for **Application Programming Interface**.

A web API allows different software applications to communicate with each other.

Example:

A frontend application can request student information from a backend server.

```text
Frontend (JavaScript)
        |
        | HTTP Request
        |
        v
Backend API
        |
        v
Database
        |
        v
Backend API
        |
        | JSON Response
        |
        v
Frontend
```

### 9.2 What is JSON?

JSON stands for **JavaScript Object Notation**.

It is a lightweight data-interchange format used to exchange information between applications.

Example:

```json
{
    "id": 1,
    "name": "Anurag",
    "course": "CMCE",
    "city": "Pune"
}
```

JSON data is represented using:
- Objects.
- Arrays.
- Strings.
- Numbers.
- Booleans.
- `null`.

JSON is a text format. It is not the same thing as a JavaScript object.

### 9.3 What is Fetch API?

Fetch API is a browser feature used to make HTTP requests and retrieve resources from a server.

It returns a Promise.

Basic syntax:

```javascript
fetch(url)
    .then(response => response.json())
    .then(data => console.log(data))
    .catch(error => console.log(error));
```

### 9.4 Fetch API using GET

Example endpoint:

`https://jsonplaceholder.typicode.com/users`

```javascript
fetch("https://jsonplaceholder.typicode.com/users")
    .then(response => response.json())
    .then(data => {
        console.log(data);
    })
    .catch(error => {
        console.log("Error:", error);
    });
```

### 9.5 Understanding the Fetch workflow

1. `fetch()` sends the HTTP request.
2. The server processes the request.
3. The server sends an HTTP response.
4. The response body is converted to JSON using `response.json()`.
5. The resulting JavaScript data is processed.

**Important:** Fetch does not reject its Promise just because the server returns an HTTP error status such as 404 or 500. You should check `response.ok`.

Correct error handling:

```javascript
fetch("https://jsonplaceholder.typicode.com/users")
    .then(response => {

        if (!response.ok) {
            throw new Error("HTTP Error: " + response.status);
        }

        return response.json();
    })
    .then(data => {
        console.log(data);
    })
    .catch(error => {
        console.error(error.message);
    });
```

### 9.6 Fetch API using async/await

The async/await syntax makes asynchronous code easier to read.

```javascript
async function getUsers() {

    try {

        let response =
            await fetch("https://jsonplaceholder.typicode.com/users");

        if (!response.ok) {
            throw new Error("HTTP Error: " + response.status);
        }

        let data = await response.json();

        console.log(data);

    } catch (error) {

        console.error("Error:", error.message);

    }
}

getUsers();
```

### 9.7 Fetch API using POST

POST is generally used to send data to a server.

```javascript
async function addUser() {

    try {

        let response = await fetch(
            "https://jsonplaceholder.typicode.com/users",
            {
                method: "POST",

                headers: {
                    "Content-Type": "application/json"
                },

                body: JSON.stringify({
                    name: "Anurag",
                    email: "anurag@example.com"
                })
            }
        );

        if (!response.ok) {
            throw new Error("Failed to add user");
        }

        let result = await response.json();

        console.log(result);

    } catch (error) {

        console.error(error.message);

    }
}

addUser();
```

`JSON.stringify()` converts a JavaScript object into JSON text.

`response.json()` reads a JSON response and converts it into a JavaScript value.

### 9.8 Common HTTP methods

| Method | Purpose |
|---|---|
| GET | Retrieve data |
| POST | Create or submit data |
| PUT | Replace a resource |
| PATCH | Partially update a resource |
| DELETE | Delete a resource |

---

# 10. Practical Labs

## Lab 1: Get First Name and Last Name from the Resume Form

### Objective

Write a JavaScript function to get the first and last name from the previously created Resume form.

Example HTML:

```html
<!DOCTYPE html>
<html>
<head>
    <title>Resume Form</title>
</head>
<body>

    <h2>Resume Form</h2>

    <form id="resumeForm">

        <label>First Name:</label>
        <input type="text" id="firstName" required>

        <br><br>

        <label>Last Name:</label>
        <input type="text" id="lastName" required>

        <br><br>

        <button type="button" id="getName">
            Get Full Name
        </button>

    </form>

    <h3 id="result"></h3>

    <script>

        function getFullName() {

            let firstName =
                document.getElementById("firstName").value.trim();

            let lastName =
                document.getElementById("lastName").value.trim();

            let fullName = firstName + " " + lastName;

            document.getElementById("result").textContent =
                "Full Name: " + fullName;
        }

        document.getElementById("getName")
            .addEventListener("click", getFullName);

    </script>

</body>
</html>
```

Expected output:

```text
Full Name: Anurag Dhondge
```

Concepts covered:
- `getElementById()`
- `.value`
- `.trim()`
- Functions
- `addEventListener()`
- `textContent`

## Lab 2: Validate the Entire Resume Form Using Client-Side JavaScript

### Objective

Validate all fields of the Resume form using JavaScript.

Fields:
- First Name
- Last Name
- Email
- Contact Number
- Gender
- Date of Birth
- Address
- Skills
- Resume upload

### Complete example

Save this as `resume.html`.

```html
<!DOCTYPE html>
<html>
<head>
    <title>Resume Form Validation</title>

    <style>
        body {
            font-family: Arial;
            margin: 30px;
        }

        input, textarea, select {
            margin: 8px;
            padding: 8px;
        }

        .error {
            color: red;
        }
    </style>

</head>
<body>

    <h2>Resume Registration Form</h2>

    <form id="resumeForm" novalidate>

        <label>First Name:</label>
        <input type="text" id="firstName">
        <br>

        <label>Last Name:</label>
        <input type="text" id="lastName">
        <br>

        <label>Email:</label>
        <input type="text" id="email">
        <br>

        <label>Mobile:</label>
        <input type="text" id="mobile">
        <br>

        <label>Gender:</label>

        <select id="gender">
            <option value="">Select Gender</option>
            <option value="Male">Male</option>
            <option value="Female">Female</option>
            <option value="Other">Other</option>
        </select>

        <br>

        <label>Date of Birth:</label>
        <input type="date" id="dob">
        <br>

        <label>Address:</label>
        <textarea id="address"></textarea>
        <br>

        <label>Skills:</label>
        <input type="checkbox" name="skills" value="Java">Java
        <input type="checkbox" name="skills" value="Python">Python
        <input type="checkbox" name="skills" value="React">React
        <br>

        <label>Resume:</label>
        <input type="file" id="resume">
        <br>

        <button type="submit">Submit</button>
        <button type="reset">Reset</button>

    </form>

    <p id="message"></p>

    <script>

        const form = document.getElementById("resumeForm");

        form.addEventListener("submit", function(event) {

            event.preventDefault();

            let firstName =
                document.getElementById("firstName").value.trim();

            let lastName =
                document.getElementById("lastName").value.trim();

            let email =
                document.getElementById("email").value.trim();

            let mobile =
                document.getElementById("mobile").value.trim();

            let gender =
                document.getElementById("gender").value;

            let dob =
                document.getElementById("dob").value;

            let address =
                document.getElementById("address").value.trim();

            let skills =
                document.querySelectorAll(
                    'input[name="skills"]:checked'
                );

            let resume =
                document.getElementById("resume").files[0];

            let errors = [];

            let namePattern = /^[A-Za-z ]{2,50}$/;

            let emailPattern =
                /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

            let mobilePattern = /^[6-9]\d{9}$/;

            if (!namePattern.test(firstName)) {
                errors.push("Invalid first name");
            }

            if (!namePattern.test(lastName)) {
                errors.push("Invalid last name");
            }

            if (!emailPattern.test(email)) {
                errors.push("Invalid email");
            }

            if (!mobilePattern.test(mobile)) {
                errors.push("Invalid mobile number");
            }

            if (gender === "") {
                errors.push("Please select gender");
            }

            if (dob === "") {
                errors.push("Please select date of birth");
            } else if (new Date(dob) > new Date()) {
                errors.push("Date of birth cannot be in the future");
            }

            if (address.length < 10) {
                errors.push("Address must contain at least 10 characters");
            }

            if (skills.length === 0) {
                errors.push("Select at least one skill");
            }

            if (!resume) {
                errors.push("Please upload your resume");
            } else {
                let allowedTypes = [
                    "application/pdf"
                ];

                if (!allowedTypes.includes(resume.type)) {
                    errors.push("Only PDF files are allowed");
                }

                if (resume.size > 2 * 1024 * 1024) {
                    errors.push("Resume must be smaller than 2 MB");
                }
            }

            let message = document.getElementById("message");

            if (errors.length > 0) {

                message.textContent = errors.join(" | ");
                message.style.color = "red";

            } else {

                message.textContent =
                    "Resume form submitted successfully!";

                message.style.color = "green";

                console.log({
                    firstName,
                    lastName,
                    email,
                    mobile,
                    gender,
                    dob,
                    address,
                    skills: Array.from(skills).map(skill => skill.value),
                    resumeName: resume.name
                });
            }

        });

    </script>

</body>
</html>
```

Important points:
- `event.preventDefault()` prevents normal form submission.
- `.trim()` removes unnecessary spaces.
- `querySelectorAll()` gets selected checkboxes.
- `.files[0]` accesses the uploaded file.
- `errors.push()` stores validation messages.
- `Array.from()` converts a NodeList into an array.

This lab checks the fields in the browser. It does not upload the resume file to a server. Actual upload requires a backend endpoint and `FormData`.

## Lab 3: Validate Whether a Given Value Is a Valid Regex

### Objective

Write a JavaScript function that checks whether a given string contains valid regular expression syntax.

```javascript
function validateRegex(pattern) {

    try {

        new RegExp(pattern);

        return true;

    } catch (error) {

        return false;

    }

}

console.log(validateRegex("[a-z]+"));  // true

console.log(validateRegex("[0-9]+"));  // true

console.log(validateRegex("[a-z"));    // false

console.log(validateRegex("*abc"));    // false
```

### Explanation

1. The function accepts a regex pattern as a string.
2. `new RegExp(pattern)` attempts to create a regular expression.
3. If the pattern is valid, it returns `true`.
4. If the pattern has invalid syntax, JavaScript throws a SyntaxError.
5. `catch` handles the error and returns `false`.

**Alternative: Check whether a value matches a given regex**

```javascript
function matchesRegex(value, pattern) {

    try {

        let regex = new RegExp(pattern);

        return regex.test(value);

    } catch (error) {

        return false;

    }

}

console.log(matchesRegex("9876543210", "^[6-9]\\d{9}$"));
```

Output:

```text
true
```

The first function validates the pattern syntax. The second validates the input against the pattern.

## Lab 4: Fetch Data from a JSON Endpoint and Display Results with Error Handling

### Objective

Fetch user data from a JSON API and display it on the webpage.

API:

`https://jsonplaceholder.typicode.com/users`

### Complete HTML and JavaScript code

```html
<!DOCTYPE html>
<html>
<head>
    <title>Fetch API Example</title>

    <style>
        body {
            font-family: Arial;
            margin: 30px;
        }

        .user {
            border: 1px solid gray;
            padding: 12px;
            margin: 10px;
        }
    </style>

</head>
<body>

    <h2>User Information</h2>

    <button id="loadUsers">Load Users</button>

    <p id="status"></p>

    <div id="users"></div>

    <script>

        const button = document.getElementById("loadUsers");

        const userContainer = document.getElementById("users");

        const status = document.getElementById("status");

        async function fetchUsers() {

            status.textContent = "Loading...";
            userContainer.replaceChildren();

            try {

                let response = await fetch(
                    "https://jsonplaceholder.typicode.com/users"
                );

                if (!response.ok) {

                    throw new Error(
                        "HTTP Error: " + response.status
                    );

                }

                let users = await response.json();

                if (!Array.isArray(users)) {
                    throw new Error("Unexpected API response");
                }

                users.forEach(user => {

                    let div = document.createElement("div");

                    div.className = "user";

                    let heading = document.createElement("h3");

                    heading.textContent = user.name;

                    let email = document.createElement("p");

                    email.textContent = "Email: " + user.email;

                    let city = document.createElement("p");

                    city.textContent =
                        "City: " + user.address.city;

                    div.append(heading, email, city);

                    userContainer.appendChild(div);

                });

                status.textContent = "Users loaded successfully";

            } catch (error) {

                status.textContent =
                    "Failed to load users: " + error.message;

                console.error(error);

            }

        }

        button.addEventListener("click", fetchUsers);

    </script>

</body>
</html>
```

### Expected result

When the user clicks Load Users, the application displays user details such as:

- Name
- Email
- City

### Concepts covered

- Fetch API
- HTTP GET
- Promise
- async/await
- try/catch
- response.ok
- response.json()
- createElement()
- appendChild()
- textContent
- addEventListener()

**Important:** This API is a testing API. It returns sample data and does not store actual user records.

---

# 11. Important CCEE and Interview Questions

## DOM

1. What is DOM?
2. What is the difference between HTML and DOM?
3. Explain the DOM tree.
4. What is the window object?
5. What is the document object?
6. Explain the JavaScript browser object hierarchy.
7. What is the difference between `getElementById()` and `querySelector()`?
8. What is the difference between `querySelector()` and `querySelectorAll()`?
9. What is the difference between HTMLCollection and NodeList?
10. What is the difference between `innerHTML` and `textContent`?
11. What is DOM manipulation?
12. Explain `createElement()` and `appendChild()`.
13. What is the difference between `append()` and `appendChild()`?
14. Explain DOM traversal.
15. What is `classList`?

## Events

16. What is an event in JavaScript?
17. Explain `addEventListener()`.
18. What is an event object?
19. What is event bubbling?
20. What is event capturing?
21. What is event delegation?
22. What is the difference between `preventDefault()` and `stopPropagation()`?
23. What is the difference between `target` and `currentTarget`?
24. What is the difference between `input` and `change` events?

## Forms and Regex

25. What is HTMLFormElement?
26. What is `form.elements`?
27. Explain `checkValidity()` and `reportValidity()`.
28. What is Constraint Validation API?
29. What is client-side validation?
30. Why is server-side validation required?
31. What is regular expression?
32. What is the difference between `test()` and `match()`?
33. Explain `replace()` and `search()`.
34. What are regex flags?
35. What is the meaning of `\d`, `\w`, and `\s`?
36. What is the difference between `*`, `+`, and `?`?
37. How do you validate an Indian mobile number using Regex?
38. How do you check whether a regex pattern itself is valid?

## Debugging, ESLint and Fetch

39. What is debugging?
40. Explain SyntaxError, ReferenceError and TypeError.
41. What is try-catch-finally?
42. What is the purpose of the throw keyword?
43. What is Browser Developer Tools?
44. Explain Elements, Console, Sources and Network tabs.
45. What is a breakpoint?
46. What is ESLint?
47. What is static code analysis?
48. What is Fetch API?
49. What is JSON?
50. What is a Promise?
51. What is the difference between `then()` and `async/await`?
52. What is the purpose of `response.json()`?
53. What is the purpose of `response.ok`?
54. Why does Fetch not automatically reject on HTTP 404?
55. What is the difference between `JSON.stringify()` and `response.json()`?

---

# 12. Important MCQs

**1. What is the full form of DOM?**

A. Data Object Model  
B. Document Object Model  
C. Digital Object Management  
D. Document Oriented Method  

**Answer: B**

**2. Which object represents an HTML document?**

A. Window  
B. Navigator  
C. Document  
D. Location  

**Answer: C**

**3. Which method selects an element using its ID?**

A. `querySelectorAll()`  
B. `getElementById()`  
C. `getElementsByTagName()`  
D. `createElement()`  

**Answer: B**

**4. Which method selects all elements matching a CSS selector?**

A. `querySelector()`  
B. `getElementById()`  
C. `querySelectorAll()`  
D. `appendChild()`  

**Answer: C**

**5. Which property is preferred for inserting plain text?**

A. `innerHTML`  
B. `textContent`  
C. `outerHTML`  
D. `style`  

**Answer: B**

**6. Which event occurs when a user clicks a button?**

A. change  
B. input  
C. click  
D. submit  

**Answer: C**

**7. Which method attaches an event listener?**

A. `attach()`  
B. `addEventListener()`  
C. `addEvent()`  
D. `eventListener()`  

**Answer: B**

**8. Which method prevents the default browser action?**

A. `stopPropagation()`  
B. `preventDefault()`  
C. `removeEventListener()`  
D. `stopDefault()`  

**Answer: B**

**9. Which event phase occurs after the target phase during normal bubbling?**

A. Capturing  
B. Bubbling  
C. Loading  
D. Parsing  

**Answer: B**

**10. Which method creates a new HTML element?**

A. `createElement()`  
B. `appendChild()`  
C. `getElementById()`  
D. `remove()`  

**Answer: A**

**11. Which method removes an element?**

A. `delete()`  
B. `remove()`  
C. `clear()`  
D. `destroy()`  

**Answer: B**

**12. Which property accesses the value of an input field?**

A. `textContent`  
B. `innerHTML`  
C. `value`  
D. `className`  

**Answer: C**

**13. Which method checks the validity of a form?**

A. `checkValidity()`  
B. `checkForm()`  
C. `validateForm()`  
D. `isValid()`  

**Answer: A**

**14. What does Regex stand for?**

A. Regular Expression  
B. Regular Execution  
C. Registered Expression  
D. Read Expression  

**Answer: A**

**15. Which Regex symbol represents a digit?**

A. `\w`  
B. `\d`  
C. `\s`  
D. `\D`  

**Answer: B**

**16. Which flag makes a regex case-insensitive?**

A. g  
B. m  
C. i  
D. s  

**Answer: C**

**17. Which Regex symbol means one or more repetitions?**

A. `*`  
B. `?`  
C. `+`  
D. `$`  

**Answer: C**

**18. Which method checks whether a string matches a regex pattern?**

A. `test()`  
B. `replace()`  
C. `searchAll()`  
D. `append()`  

**Answer: A**

**19. Which block handles exceptions?**

A. if-else  
B. try-catch  
C. switch  
D. for  

**Answer: B**

**20. Which keyword generates an error manually?**

A. error  
B. catch  
C. throw  
D. exception  

**Answer: C**

**21. Which tool is used to inspect HTML and CSS?**

A. Network  
B. Elements  
C. Performance  
D. Application  

**Answer: B**

**22. Which DevTools tab helps inspect API requests?**

A. Elements  
B. Console  
C. Network  
D. Sources  

**Answer: C**

**23. What is ESLint?**

A. Database  
B. JavaScript static analysis tool  
C. Browser  
D. JavaScript framework  

**Answer: B**

**24. Which API is used to make HTTP requests from JavaScript?**

A. DOM  
B. Fetch API  
C. CSS API  
D. Canvas API  

**Answer: B**

**25. What does Fetch return?**

A. Array  
B. String  
C. Promise  
D. Number  

**Answer: C**

**26. Which method converts a response body into JSON data?**

A. `JSON.stringify()`  
B. `response.json()`  
C. `JSON.parse()`  
D. `response.textContent()`  

**Answer: B**

**27. Which property indicates whether an HTTP response has a successful status?**

A. `response.statusText`  
B. `response.ok`  
C. `response.json`  
D. `response.success`  

**Answer: B**

**28. Which HTTP method is normally used to retrieve data?**

A. POST  
B. PUT  
C. GET  
D. DELETE  

**Answer: C**

**29. Which method converts a JavaScript object into JSON text?**

A. `JSON.parse()`  
B. `JSON.stringify()`  
C. `response.json()`  
D. `toString()`  

**Answer: B**

**30. Which keyword is used with await?**

A. static  
B. async  
C. yield  
D. promise  

**Answer: B**

---

# 13. Quick Revision Sheet

| Topic | Important concept |
|---|---|
| DOM | Document Object Model |
| Browser global object | `window` |
| HTML document | `document` |
| Select by ID | `getElementById()` |
| Select by CSS selector | `querySelector()` |
| Select all matching elements | `querySelectorAll()` |
| Read input value | `.value` |
| Read plain text | `.textContent` |
| Insert HTML | `.innerHTML` |
| Create element | `createElement()` |
| Add child | `appendChild()` |
| Remove element | `remove()` |
| Modify classes | `classList` |
| Attach event | `addEventListener()` |
| Stop default action | `preventDefault()` |
| Stop propagation | `stopPropagation()` |
| Form controls | `form.elements` |
| Validate form | `checkValidity()` |
| Display validation | `reportValidity()` |
| Regex matching | `test()` |
| Regex replacement | `replace()` |
| Regex search | `search()` |
| Error handling | `try-catch-finally` |
| Generate error | `throw` |
| Debugging | Breakpoints and `debugger` |
| Code quality | ESLint |
| HTTP requests | Fetch API |
| JSON response | `response.json()` |
| Object to JSON text | `JSON.stringify()` |
| HTTP error checking | `response.ok` |

---

# 14. Self-Learning and Practice Tasks

Try completing these tasks without copying the solutions.

### DOM practice
- [ ] Create a webpage with a heading and three buttons.
- [ ] Change heading text when a button is clicked.
- [ ] Change background color using `classList`.
- [ ] Create a list dynamically using `createElement()`.
- [ ] Delete a list item using an event listener.
- [ ] Implement event delegation.

### Forms and Regex practice
- [ ] Create a student registration form.
- [ ] Validate first name and last name.
- [ ] Validate email and mobile number.
- [ ] Validate password using Regex.
- [ ] Validate date of birth.
- [ ] Validate checkbox selection.
- [ ] Display all errors together.
- [ ] Validate uploaded PDF file type and size.

### Debugging and ESLint practice
- [ ] Create a program with a SyntaxError and fix it.
- [ ] Create a program with a ReferenceError and fix it.
- [ ] Use `debugger` to inspect variables.
- [ ] Set a breakpoint in Chrome DevTools.
- [ ] Inspect an API request using Network.
- [ ] Install ESLint and configure basic rules.

### Fetch API practice
- [ ] Fetch users from JSONPlaceholder.
- [ ] Display names and emails.
- [ ] Display a loading message.
- [ ] Handle HTTP errors.
- [ ] Handle network failures.
- [ ] Add a Reload button.
- [ ] Fetch posts and display titles.

---

# 15. Recommended References

Use these references to study the concepts in depth.

### Books

1. **JavaScript: The Definitive Guide, 7th Edition – David Flanagan (O'Reilly)**  
   Useful for JavaScript fundamentals, functions, objects, DOM and browser APIs.

2. **Web Development with Node and Express – Ethan Brown (O'Reilly)**  
   Useful for understanding web applications, HTTP communication and backend integration.

3. **React in Depth – Morten Barklund (O'Reilly, 2024)**  
   Useful for understanding how frontend applications evolve beyond direct DOM manipulation.

### Official documentation

- DOM: https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model
- Document API: https://developer.mozilla.org/en-US/docs/Web/API/Document
- Events: https://developer.mozilla.org/en-US/docs/Web/Events
- HTML Forms: https://developer.mozilla.org/en-US/docs/Web/HTML/Element/form
- Constraint Validation: https://developer.mozilla.org/en-US/docs/Web/HTML/Constraint_validation
- Regular Expressions: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_expressions
- Error Handling: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Control_flow_and_error_handling
- Fetch API: https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API
- ESLint: https://eslint.org/docs/latest/

---

# 16. Final Learning Checklist

By the end of Sessions 9 & 10, you should be able to:

- [ ] Explain DOM and its object hierarchy.
- [ ] Select HTML elements using JavaScript.
- [ ] Read and modify element content.
- [ ] Create, insert and remove DOM elements.
- [ ] Handle click, input, change and submit events.
- [ ] Explain event bubbling and capturing.
- [ ] Use event delegation.
- [ ] Access form fields using the Forms API.
- [ ] Validate forms using JavaScript.
- [ ] Write Regex patterns for common validations.
- [ ] Distinguish valid regex syntax from matching input.
- [ ] Handle errors using try-catch-finally.
- [ ] Debug JavaScript using browser DevTools.
- [ ] Understand and configure ESLint.
- [ ] Fetch JSON data using Fetch API.
- [ ] Handle HTTP errors and network failures.

**Your practical target:** Build one complete Resume Management webpage that includes DOM manipulation, form validation, Regex, file validation, and Fetch API integration. This will combine almost every concept from these two sessions into one project.
