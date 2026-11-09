# Session 22: Introduction to React

**Course:** CMCE – August 2026 Batch  
**Subject:** Web Programming Technologies  
**Duration:** 2 Theory + 2 Lab + 2 Self-Learning Hours

---

# 1. Introduction to React

## 1.1 What is React?

**React is a JavaScript library used to build user interfaces, especially interactive and dynamic web applications.**

React was developed by Facebook (now Meta).

It allows developers to divide a user interface into small, reusable pieces called components.

### Example

Consider a college website containing:

- Header
- Navigation bar
- Student profile
- Course list
- Footer

In traditional HTML, we may write all these elements in a single HTML file.

In React, we can create separate components:

```text
App
 |
 |--- Header
 |
 |--- Navbar
 |
 |--- StudentProfile
 |
 |--- CourseList
 |
 |--- Footer
```

Each component is responsible for a specific part of the user interface.

## 1.2 Why React?

Suppose you are developing a student management application.

It contains:
- Student registration
- Student login
- Student profile
- Student list
- Course information

If everything is written in one large file, maintaining the application becomes difficult.

React solves this problem through component-based architecture.

### Advantages of React

| Feature | Explanation |
|---|---|
| Component-based | Divides UI into reusable components |
| Reusability | Components can be reused multiple times |
| Declarative | Describe what UI should look like for the current data |
| Virtual DOM | React uses an in-memory representation to help update the UI efficiently |
| One-way data flow | Data generally flows from parent to child through props |
| JSX | Allows HTML-like syntax inside JavaScript |
| Large ecosystem | Supports libraries for routing, state management and more |

## 1.3 React vs JavaScript vs HTML

| HTML | JavaScript | React |
|---|---|---|
| Defines webpage structure | Adds logic and interactivity | Builds component-based interfaces |
| Markup language | Programming language | JavaScript library |
| Uses tags | Uses functions and statements | Uses components and JSX |
| Defines elements | Manipulates data and DOM | Describes and updates UI |

## 1.4 What is SPA?

SPA stands for **Single Page Application**.

A Single Page Application loads a main HTML page and updates its content dynamically without requiring a complete page reload for every navigation or interaction.

Examples of applications commonly built using React include:
- Dashboards
- Social media applications
- E-commerce websites
- Student management systems

React can be used to build SPAs, but React itself does not automatically provide a complete routing solution. Libraries such as React Router are commonly used for routing.

## 1.5 Virtual DOM

DOM stands for Document Object Model.

The browser represents an HTML document as a tree of objects.

Example HTML:

```html
<div>
    <h1>Hello</h1>
    <p>Welcome to React</p>
</div>
```

Simplified DOM tree:

```text
        div
         |
    -----------
    |         |
   h1         p
    |         |
  Hello    Welcome
           to React
```

React uses an in-memory representation of the UI, commonly called the Virtual DOM.

When application data changes:
1. React calculates the next UI representation.
2. It compares it with the previous representation.
3. React determines what needs to change.
4. It updates the necessary parts of the actual DOM.

**Important:** The Virtual DOM is a useful conceptual model for understanding React updates. Modern React's rendering process is more sophisticated than simply comparing two complete DOM trees.

## 1.6 Setting up a React Project using Vite

Vite is a frontend development tool used to create and run modern React projects.

### Prerequisites

Install:
- Node.js
- npm
- VS Code

Check installation:

```bash
node -v
npm -v
```

### Step 1: Create a React project

```bash
npm create vite@latest my-react-app -- --template react
```

### Step 2: Enter the project folder

```bash
cd my-react-app
```

### Step 3: Install dependencies

```bash
npm install
```

### Step 4: Start the development server

```bash
npm run dev
```

Vite will display a local URL, usually:

```text
http://localhost:5173
```

Open this URL in your browser.

### React project structure

```text
my-react-app/
│
├── node_modules/
│
├── public/
│
├── src/
│   ├── assets/
│   ├── App.jsx
│   ├── App.css
│   ├── index.css
│   └── main.jsx
│
├── index.html
├── package.json
└── vite.config.js
```

### Important files

| File | Purpose |
|---|---|
| `index.html` | Main HTML document |
| `main.jsx` | Entry point of React application |
| `App.jsx` | Main application component |
| `App.css` | Styling for application |
| `index.css` | Global CSS |
| `package.json` | Project configuration and dependencies |
| `node_modules` | Installed packages |

### Understanding main.jsx

```jsx
import React from "react";
import ReactDOM from "react-dom/client";
import App from "./App.jsx";

ReactDOM.createRoot(
    document.getElementById("root")
).render(
    <React.StrictMode>
        <App />
    </React.StrictMode>
);
```

Explanation:

- `ReactDOM` connects React with the browser DOM.
- `createRoot()` creates a React root.
- `document.getElementById("root")` selects the root HTML element.
- `render()` displays the React application.
- `<App />` represents the main application component.
- `React.StrictMode` enables additional development checks.

The `index.html` file contains:

```html
<div id="root"></div>
```

React renders the application inside this element.

---

# 2. React Elements and Components

## 2.1 What is a React Element?

A React element is a JavaScript object that describes what should appear on the screen.

It is the smallest building block of a React user interface.

Example:

```jsx
const element = <h1>Hello React</h1>;
```

Here, `element` describes an HTML heading.

To display it:

```jsx
function App() {
    const element = <h1>Hello React</h1>;

    return element;
}

export default App;
```

Output:

```text
Hello React
```

### React element using React.createElement()

JSX is transformed into React element creation instructions.

A similar element can be created without JSX:

```jsx
const element = React.createElement(
    "h1",
    null,
    "Hello React"
);
```

Parameters:

1. Element type: `"h1"`
2. Props: `null`
3. Children: `"Hello React"`

In normal development, JSX is generally preferred because it is easier to read.

## 2.2 What is a React Component?

A React component is a reusable piece of UI.

A component can contain:
- JSX
- JavaScript logic
- Data
- Other components

Example:

```jsx
function Welcome() {
    return <h1>Welcome to React</h1>;
}

export default Welcome;
```

Using the component:

```jsx
function App() {
    return (
        <div>
            <Welcome />
        </div>
    );
}

export default App;
```

Output:

```text
Welcome to React
```

### Important difference: Element vs Component

| React Element | React Component |
|---|---|
| Describes what should appear in the UI | Defines a reusable part of the UI |
| Usually created using JSX | Usually created using a function |
| Can represent an HTML tag or component | Can return React elements |
| Example: `<h1>Hello</h1>` | Example: `function Welcome() { ... }` |

Remember:

```jsx
const element = <h1>Hello</h1>;
```

This is an element.

```jsx
function Welcome() {
    return <h1>Hello</h1>;
}
```

This is a component.

```jsx
<Welcome />
```

This is an element representing the `Welcome` component.

## 2.3 JSX – JavaScript XML

JSX stands for JavaScript XML.

It is a syntax extension that allows us to write HTML-like markup inside JavaScript.

Example:

```jsx
function App() {
    return (
        <div>
            <h1>Hello React</h1>
            <p>Learning JSX</p>
        </div>
    );
}
```

### JSX Rules

**Rule 1: Return a single parent element**

Incorrect:

```jsx
function App() {
    return (
        <h1>Hello</h1>
        <p>Welcome</p>
    );
}
```

Correct:

```jsx
function App() {
    return (
        <div>
            <h1>Hello</h1>
            <p>Welcome</p>
        </div>
    );
}
```

You can also use a React Fragment:

```jsx
function App() {
    return (
        <>
            <h1>Hello</h1>
            <p>Welcome</p>
        </>
    );
}
```

**Rule 2: Close all tags**

Correct:

```jsx
<img src="photo.png" alt="Profile" />
```

**Rule 3: Use className instead of class**

HTML:

```html
<h1 class="title">Hello</h1>
```

JSX:

```jsx
<h1 className="title">Hello</h1>
```

**Rule 4: Use camelCase for many JSX attributes**

HTML:

```html
<button onclick="showMessage()">Click</button>
```

JSX:

```jsx
<button onClick={showMessage}>Click</button>
```

**Rule 5: Use curly braces for JavaScript expressions**

```jsx
function App() {

    const name = "Anurag";

    return (
        <h1>Hello {name}</h1>
    );
}
```

Output:

```text
Hello Anurag
```

You can also perform calculations:

```jsx
function App() {

    const a = 10;
    const b = 20;

    return <h1>Sum: {a + b}</h1>;
}
```

Output:

```text
Sum: 30
```

---

# 3. Function Components

## 3.1 What is a Function Component?

A function component is a JavaScript function that returns React elements, usually written using JSX.

Example:

```jsx
function Welcome() {
    return <h1>Welcome to React</h1>;
}
```

It can be used like an HTML element:

```jsx
<Welcome />
```

### Important rules

1. Component names must start with a capital letter.
2. A component should return React-compatible UI.
3. A component should be used as JSX, such as `<Welcome />`.
4. Components should be written as reusable, focused functions.
5. React Hooks, when used, must follow the Rules of Hooks.

## 3.2 Creating Multiple Components

Example:

```jsx
function Header() {
    return <h1>Student Management System</h1>;
}

function Footer() {
    return <p>Copyright 2026</p>;
}

function App() {
    return (
        <div>
            <Header />
            <h2>Welcome Students</h2>
            <Footer />
        </div>
    );
}

export default App;
```

Output:

```text
Student Management System

Welcome Students

Copyright 2026
```

## 3.3 Arrow Function Components

Components can also be created using arrow functions.

```jsx
const Welcome = () => {
    return <h1>Welcome to React</h1>;
};

export default Welcome;
```

Shorter version:

```jsx
const Welcome = () => <h1>Welcome to React</h1>;
```

Both are valid function components.

## 3.4 Separating Components into Different Files

For better code organization, create separate files for components.

Project structure:

```text
src/
│
├── components/
│   ├── Header.jsx
│   ├── Footer.jsx
│   └── Welcome.jsx
│
├── App.jsx
└── main.jsx
```

**Header.jsx**

```jsx
function Header() {
    return <h1>My React Application</h1>;
}

export default Header;
```

**Footer.jsx**

```jsx
function Footer() {
    return <p>Thank you for visiting!</p>;
}

export default Footer;
```

**Welcome.jsx**

```jsx
function Welcome() {
    return <h2>Welcome to React</h2>;
}

export default Welcome;
```

**App.jsx**

```jsx
import Header from "./components/Header";
import Footer from "./components/Footer";
import Welcome from "./components/Welcome";

function App() {
    return (
        <>
            <Header />
            <Welcome />
            <Footer />
        </>
    );
}

export default App;
```

This approach makes the application easier to understand and maintain.

---

# 4. Working with Props

## 4.1 What are Props?

Props stands for properties.

Props are used to pass data from a parent component to a child component.

In simple words:

**Props allow one component to send information to another component.**

Example:

```jsx
function Student(props) {
    return <h2>Name: {props.name}</h2>;
}

function App() {
    return (
        <Student name="Anurag" />
    );
}

export default App;
```

Output:

```text
Name: Anurag
```

Here:
- `App` is the parent component.
- `Student` is the child component.
- `name="Anurag"` is a prop.
- `props.name` accesses the prop.

## 4.2 Passing Multiple Props

```jsx
function Student(props) {
    return (
        <div>
            <h2>Name: {props.name}</h2>
            <p>Age: {props.age}</p>
            <p>Course: {props.course}</p>
        </div>
    );
}

function App() {
    return (
        <Student
            name="Anurag"
            age={22}
            course="CMCE"
        />
    );
}

export default App;
```

Output:

```text
Name: Anurag
Age: 22
Course: CMCE
```

Notice:
- String values can be passed using quotes.
- JavaScript values such as numbers are passed using curly braces.

## 4.3 Destructuring Props

Instead of writing `props.name`, `props.age`, etc., we can use destructuring.

```jsx
function Student({ name, age, course }) {
    return (
        <div>
            <h2>{name}</h2>
            <p>{age}</p>
            <p>{course}</p>
        </div>
    );
}
```

This is a cleaner approach.

## 4.4 Passing Arrays as Props

```jsx
function StudentList({ students }) {
    return (
        <ul>
            {students.map((student) => (
                <li key={student.id}>
                    {student.name}
                </li>
            ))}
        </ul>
    );
}

function App() {

    const students = [
        { id: 1, name: "Anurag" },
        { id: 2, name: "Rahul" },
        { id: 3, name: "Amit" }
    ];

    return <StudentList students={students} />;
}

export default App;
```

Output:

- Anurag
- Rahul
- Amit

**Important:** React uses `key` to identify items in lists. Use a stable and unique key, such as a database ID.

## 4.5 Passing Functions as Props

Props can also contain functions.

```jsx
function Child({ showMessage }) {
    return (
        <button onClick={showMessage}>
            Click Me
        </button>
    );
}

function App() {

    const message = () => {
        alert("Hello from Parent Component");
    };

    return <Child showMessage={message} />;
}

export default App;
```

Here:
- The parent defines the function.
- The function is passed to the child.
- The child executes it when the button is clicked.

**Remember:** Props are read-only. A child component should not directly modify the props received from its parent.

---

# 5. Compose Components

## 5.1 What is Component Composition?

Component composition means combining smaller components to create a larger user interface.

Instead of creating one big component, we create multiple small components and combine them.

Example:

```text
App
 |
 |--- Header
 |
 |--- StudentProfile
 |        |
 |        |--- ProfileImage
 |        |
 |        |--- StudentDetails
 |
 |--- Footer
```

### Example

**Header.jsx**

```jsx
function Header() {
    return <h1>Student Portal</h1>;
}

export default Header;
```

**ProfileImage.jsx**

```jsx
function ProfileImage() {
    return (
        <img
            src="https://via.placeholder.com/100"
            alt="Student"
        />
    );
}

export default ProfileImage;
```

**StudentDetails.jsx**

```jsx
function StudentDetails() {
    return (
        <div>
            <h2>Anurag Dhondge</h2>
            <p>Course: CMCE</p>
            <p>College: ACTS Pune</p>
        </div>
    );
}

export default StudentDetails;
```

**StudentProfile.jsx**

```jsx
import ProfileImage from "./ProfileImage";
import StudentDetails from "./StudentDetails";

function StudentProfile() {
    return (
        <div>
            <ProfileImage />
            <StudentDetails />
        </div>
    );
}

export default StudentProfile;
```

**App.jsx**

```jsx
import Header from "./Header";
import StudentProfile from "./StudentProfile";

function App() {
    return (
        <>
            <Header />
            <StudentProfile />
        </>
    );
}

export default App;
```

### Benefits of component composition

- Reusability
- Easy maintenance
- Better readability
- Separation of responsibilities
- Easier testing
- Smaller and manageable code

---

# 6. Render Components

## 6.1 What is Rendering?

Rendering means displaying React elements and components in the browser.

React takes the component structure and displays the resulting UI inside a DOM root.

### Example

```jsx
function App() {
    return <h1>Hello React</h1>;
}
```

In `main.jsx`:

```jsx
import ReactDOM from "react-dom/client";
import App from "./App";

ReactDOM.createRoot(
    document.getElementById("root")
).render(
    <App />
);
```

### Rendering multiple components

```jsx
function Header() {
    return <h1>Header</h1>;
}

function Content() {
    return <p>Main Content</p>;
}

function Footer() {
    return <h3>Footer</h3>;
}

function App() {
    return (
        <>
            <Header />
            <Content />
            <Footer />
        </>
    );
}
```

## 6.2 Conditional Rendering

Conditional rendering means displaying different UI based on a condition.

Example:

```jsx
function App() {

    const isLoggedIn = true;

    return (
        <div>
            {isLoggedIn
                ? <h1>Welcome User</h1>
                : <h1>Please Login</h1>
            }
        </div>
    );
}
```

Output:

```text
Welcome User
```

Using logical AND:

```jsx
function App() {

    const isAdmin = true;

    return (
        <div>
            {isAdmin && <h2>Admin Dashboard</h2>}
        </div>
    );
}
```

## 6.3 Rendering Lists

We can use JavaScript's `map()` method to render lists.

```jsx
function App() {

    const courses = [
        "Java",
        "Python",
        "MERN",
        "DBT",
        "CMCE"
    ];

    return (
        <ul>
            {courses.map((course, index) => (
                <li key={index}>{course}</li>
            ))}
        </ul>
    );
}
```

For lists that may be reordered or changed, prefer stable unique IDs over array indexes.

---

# 7. Declutter Components

## 7.1 What does Decluttering mean?

Decluttering means making components clean, simple, readable and manageable by separating responsibilities.

A component should ideally perform one clear task.

Avoid writing the entire application inside one large component.

### Example: Without Decluttering

```jsx
function App() {
    return (
        <div>
            <h1>Student Management</h1>

            <h2>Anurag</h2>
            <p>Course: CMCE</p>

            <h2>Rahul</h2>
            <p>Course: Java</p>

            <h2>Amit</h2>
            <p>Course: Python</p>

            <p>Copyright 2026</p>
        </div>
    );
}
```

This code works, but it becomes difficult to maintain when more features are added.

### Example: After Decluttering

```jsx
function Header() {
    return <h1>Student Management</h1>;
}

function Student({ name, course }) {
    return (
        <div>
            <h2>{name}</h2>
            <p>Course: {course}</p>
        </div>
    );
}

function Footer() {
    return <p>Copyright 2026</p>;
}

function App() {
    return (
        <div>
            <Header />

            <Student name="Anurag" course="CMCE" />
            <Student name="Rahul" course="Java" />
            <Student name="Amit" course="Python" />

            <Footer />
        </div>
    );
}

export default App;
```

### Best practices for clean React components

1. Create separate components for different UI sections.
2. Use meaningful component names.
3. Pass dynamic data through props.
4. Avoid unnecessary duplication.
5. Keep JSX readable.
6. Extract repeated UI into reusable components.
7. Keep styling in separate CSS files when appropriate.
8. Avoid making a single component responsible for too many tasks.

---

# 8. Lab 1 – Rebuild a Previous Plain HTML Assignment Using React Functional Components

## Objective

Rebuild the previous HTML Resume Registration Form using React functional components.

### Requirements

Create a form containing:
- Full Name
- Email
- Mobile Number
- Qualification
- Skills
- Submit button

Use separate React components for:
- Header
- Resume Form
- Form Fields
- Footer

## Step 1: Create the React project

```bash
npm create vite@latest resume-react -- --template react

cd resume-react

npm install

npm run dev
```

## Step 2: Create the folder structure

```text
src/
│
├── components/
│   ├── Header.jsx
│   ├── FormField.jsx
│   ├── ResumeForm.jsx
│   └── Footer.jsx
│
├── App.jsx
├── App.css
└── main.jsx
```

## Step 3: Header.jsx

```jsx
function Header() {
    return (
        <header>
            <h1>Resume Registration Form</h1>
            <p>Enter your personal and professional details</p>
        </header>
    );
}

export default Header;
```

## Step 4: FormField.jsx

```jsx
function FormField({ label, type, name, placeholder }) {
    return (
        <div className="form-group">

            <label>{label}</label>

            <input
                type={type}
                name={name}
                placeholder={placeholder}
            />

        </div>
    );
}

export default FormField;
```

This component is reusable. We can use it for different input fields by changing its props.

## Step 5: ResumeForm.jsx

```jsx
import FormField from "./FormField";

function ResumeForm() {

    function handleSubmit(event) {

        event.preventDefault();

        alert("Resume submitted successfully!");

    }

    return (
        <form onSubmit={handleSubmit}>

            <FormField
                label="Full Name"
                type="text"
                name="fullname"
                placeholder="Enter your name"
            />

            <FormField
                label="Email"
                type="email"
                name="email"
                placeholder="Enter your email"
            />

            <FormField
                label="Mobile Number"
                type="tel"
                name="mobile"
                placeholder="Enter mobile number"
            />

            <div className="form-group">

                <label>Qualification</label>

                <select name="qualification" defaultValue="">
                    <option value="" disabled>Select Qualification</option>
                    <option value="BE">BE</option>
                    <option value="BTech">BTech</option>
                    <option value="MCA">MCA</option>
                </select>

            </div>

            <div className="form-group">

                <label>Skills</label>

                <div>
                    <input type="checkbox" name="skills" value="Java" />
                    Java
                </div>

                <div>
                    <input type="checkbox" name="skills" value="Python" />
                    Python
                </div>

                <div>
                    <input type="checkbox" name="skills" value="React" />
                    React
                </div>

            </div>

            <button type="submit">Submit</button>

        </form>
    );
}

export default ResumeForm;
```

## Step 6: Footer.jsx

```jsx
function Footer() {
    return (
        <footer>
            <p>Resume Registration System - 2026</p>
        </footer>
    );
}

export default Footer;
```

## Step 7: App.jsx

```jsx
import Header from "./components/Header";
import ResumeForm from "./components/ResumeForm";
import Footer from "./components/Footer";

function App() {
    return (
        <div className="container">

            <Header />

            <ResumeForm />

            <Footer />

        </div>
    );
}

export default App;
```

## Step 8: App.css

```css
body {
    font-family: Arial, sans-serif;
    background-color: #f2f2f2;
}

.container {
    max-width: 550px;
    margin: 40px auto;
    padding: 25px;
    background-color: white;
    border-radius: 8px;
}

header {
    text-align: center;
}

.form-group {
    margin: 15px 0;
}

label {
    display: block;
    margin-bottom: 6px;
}

input, select {
    padding: 9px;
    width: 100%;
    box-sizing: border-box;
}

button {
    padding: 10px 20px;
    cursor: pointer;
}

footer {
    margin-top: 20px;
    text-align: center;
}
```

## Step 9: Test the application

```bash
npm run dev
```

Open the URL displayed by Vite.

### What did we learn?

- Created functional components.
- Imported and exported components.
- Reused FormField using props.
- Composed multiple components.
- Rendered components inside App.
- Used an event handler for form submission.
- Used JSX to create the form UI.

**Note:** This introductory lab demonstrates component composition. It does not yet store form input in React state or submit it to a backend. Those concepts can be added in later React sessions.

---

# 9. Lab 2 – React Clock App Showing Time of Three Countries

## Objective

Build a React application that displays the live time in three different countries using the 24-hour format:

**HH:MM:SS**

Countries:
1. India – New Delhi
2. United Kingdom – London
3. Japan – Tokyo

## Concepts required

- Functional components
- JSX
- Component composition
- Props
- `useState`
- `useEffect`
- JavaScript Date object
- `Intl.DateTimeFormat`
- `setInterval`
- `clearInterval`

**Note:** `useState` and `useEffect` are React Hooks. They are introduced here because a clock needs to update its displayed time continuously.

## Step 1: Create a React project

```bash
npm create vite@latest world-clock -- --template react

cd world-clock

npm install

npm run dev
```

## Step 2: Folder structure

```text
src/
│
├── components/
│   ├── Clock.jsx
│   └── Header.jsx
│
├── App.jsx
├── App.css
└── main.jsx
```

## Step 3: Header.jsx

```jsx
function Header() {
    return (
        <header>
            <h1>World Clock</h1>
            <p>Live time across different countries</p>
        </header>
    );
}

export default Header;
```

## Step 4: Clock.jsx

```jsx
import { useState, useEffect } from "react";

function Clock({ country, city, timeZone }) {

    const [time, setTime] = useState("");

    useEffect(() => {

        function updateTime() {

            const currentTime = new Intl.DateTimeFormat(
                "en-GB",
                {
                    timeZone: timeZone,
                    hour: "2-digit",
                    minute: "2-digit",
                    second: "2-digit",
                    hour12: false
                }
            ).format(new Date());

            setTime(currentTime);

        }

        updateTime();

        const interval = setInterval(updateTime, 1000);

        return () => clearInterval(interval);

    }, [timeZone]);

    return (
        <div className="clock-card">

            <h2>{country}</h2>

            <p>{city}</p>

            <h1>{time}</h1>

        </div>
    );
}

export default Clock;
```

### Explanation

**1. useState()**

```jsx
const [time, setTime] = useState("");
```

- `time` stores the current displayed time.
- `setTime` updates the time.
- `useState("")` initializes it with an empty string.

When state changes, React updates the component's UI.

**2. useEffect()**

```jsx
useEffect(() => {
    // Clock logic
}, [timeZone]);
```

`useEffect` is used to synchronize a component with an external system, such as a timer.

Here it manages the clock interval.

**3. Intl.DateTimeFormat()**

```javascript
new Intl.DateTimeFormat("en-GB", {
    timeZone: "Asia/Kolkata",
    hour: "2-digit",
    minute: "2-digit",
    second: "2-digit",
    hour12: false
});
```

It formats the time according to the specified time zone.

**4. setInterval()**

```javascript
setInterval(updateTime, 1000);
```

Calls `updateTime()` approximately every 1000 milliseconds (one second).

**5. clearInterval()**

```javascript
return () => clearInterval(interval);
```

Cleans up the interval when the component is removed or its time zone changes.

This prevents unnecessary timers from continuing to run.

## Step 5: App.jsx

```jsx
import Header from "./components/Header";
import Clock from "./components/Clock";

function App() {

    return (
        <div className="container">

            <Header />

            <div className="clock-container">

                <Clock
                    country="India"
                    city="New Delhi"
                    timeZone="Asia/Kolkata"
                />

                <Clock
                    country="United Kingdom"
                    city="London"
                    timeZone="Europe/London"
                />

                <Clock
                    country="Japan"
                    city="Tokyo"
                    timeZone="Asia/Tokyo"
                />

            </div>

        </div>
    );
}

export default App;
```

Notice that we reuse the same Clock component three times with different props.

This is an example of component reusability and composition.

## Step 6: App.css

```css
body {
    margin: 0;
    font-family: Arial, sans-serif;
    background: #eef2f7;
}

.container {
    text-align: center;
    padding: 40px 20px;
}

header {
    margin-bottom: 35px;
}

.clock-container {
    display: flex;
    justify-content: center;
    flex-wrap: wrap;
    gap: 20px;
}

.clock-card {
    width: 250px;
    padding: 25px;
    border-radius: 12px;
    background: white;
    box-shadow: 0 3px 12px rgba(0, 0, 0, 0.12);
}

.clock-card h2 {
    color: #222;
}

.clock-card p {
    color: #666;
}

.clock-card h1 {
    font-size: 32px;
    color: #1769aa;
}
```

## Step 7: Run the application

```bash
npm run dev
```

Open:

```text
http://localhost:5173
```

### Expected output

Your application will display three clock cards:

| Country | City | Time Zone |
|---|---|---|
| India | New Delhi | `Asia/Kolkata` |
| United Kingdom | London | `Europe/London` |
| Japan | Tokyo | `Asia/Tokyo` |

Each card displays a live clock in the format:

```text
HH:MM:SS
```

The actual times will depend on when you run the application.

### Why use time zones?

Different countries have different time zones.

For example:
- India uses UTC+05:30.
- United Kingdom uses UTC+00:00 during standard time and UTC+01:00 during British Summer Time.
- Japan uses UTC+09:00.

Using the IANA time zone identifiers with `Intl.DateTimeFormat` automatically handles daylight-saving rules where applicable.

---

# 10. Important React Interview and CCEE Questions

1. What is React?
2. Who developed React?
3. Is React a library or framework?
4. What is a component?
5. What is a React element?
6. What is JSX?
7. What is the difference between JSX and HTML?
8. What is the Virtual DOM?
9. What is a functional component?
10. What is the difference between an element and a component?
11. What are props?
12. How do you pass data from a parent component to a child component?
13. Can a child component directly modify props?
14. What is component composition?
15. What is component reusability?
16. What is component rendering?
17. What is conditional rendering?
18. How do you render an array in React?
19. Why is the `key` prop important when rendering lists?
20. What is the difference between `class` and `className`?
21. Why should component names start with capital letters?
22. What is the purpose of `main.jsx`?
23. What is the purpose of `createRoot()`?
24. What is Vite?
25. What is the purpose of `useState`?
26. What is the purpose of `useEffect`?
27. What is the difference between props and state?
28. What is the purpose of `useEffect` cleanup?
29. What is a Single Page Application?
30. What is the benefit of component-based architecture?

---

# 11. MCQs – Practice for CCEE

**1. React is primarily used for:**

A. Database management  
B. Building user interfaces  
C. Operating systems  
D. Networking  

**Answer: B. Building user interfaces**

**2. React was developed by:**

A. Google  
B. Microsoft  
C. Facebook (Meta)  
D. Oracle  

**Answer: C. Facebook (Meta)**

**3. React is a:**

A. Programming language  
B. JavaScript library  
C. Database  
D. Operating system  

**Answer: B. JavaScript library**

**4. What does JSX stand for?**

A. JavaScript XML  
B. Java Syntax Extension  
C. JSON XML  
D. JavaScript Extra  

**Answer: A. JavaScript XML**

**5. Which function creates a functional component?**

A. A JavaScript function returning JSX  
B. A CSS function  
C. A database query  
D. An HTML file  

**Answer: A. A JavaScript function returning JSX**

**6. React component names should begin with:**

A. Lowercase letters  
B. Capital letters  
C. Numbers  
D. Special characters  

**Answer: B. Capital letters**

**7. Which is the correct way to use a React component?**

A. `<welcome>`  
B. `<Welcome />`  
C. `welcome()` inside HTML  
D. `<function Welcome>`  

**Answer: B. `<Welcome />`**

**8. Props are used to:**

A. Style components  
B. Pass data between components  
C. Install React  
D. Create databases  

**Answer: B. Pass data between components**

**9. Props are generally:**

A. Read-only  
B. Always editable by children  
C. Global variables  
D. CSS properties  

**Answer: A. Read-only**

**10. Which method is commonly used to render arrays in JSX?**

A. filter()  
B. map()  
C. push()  
D. pop()  

**Answer: B. map()**

**11. Which attribute is used instead of HTML class in JSX?**

A. class  
B. classname  
C. className  
D. cssClass  

**Answer: C. className**

**12. Which method creates a React root?**

A. ReactDOM.createRoot()  
B. React.createPage()  
C. ReactDOM.createHTML()  
D. React.start()  

**Answer: A. ReactDOM.createRoot()**

**13. Which Hook is used to manage state in a functional component?**

A. useEffect  
B. useState  
C. useRoute  
D. useHTML  

**Answer: B. useState**

**14. Which Hook is used to manage effects such as timers?**

A. useState  
B. useEffect  
C. useProps  
D. useRender  

**Answer: B. useEffect**

**15. Which tool is used in this session to create a React project?**

A. Vite  
B. MySQL  
C. MongoDB  
D. Apache  

**Answer: A. Vite**

---

# 12. Quick Revision Notes

| Concept | Meaning |
|---|---|
| React | JavaScript library for building UI |
| JSX | JavaScript XML syntax extension |
| Element | Describes what should appear in UI |
| Component | Reusable UI building block |
| Function Component | JavaScript function returning UI |
| Props | Data passed from parent to child |
| Component Composition | Combining smaller components |
| Rendering | Displaying React UI |
| Virtual DOM | In-memory representation of UI |
| SPA | Single Page Application |
| Vite | Frontend development tool |
| `main.jsx` | React application entry point |
| `App.jsx` | Main application component |
| `createRoot()` | Creates React root |
| `className` | JSX equivalent of HTML class |
| `map()` | Used to render arrays |
| `key` | Identifies list elements |
| `useState()` | Manages component state |
| `useEffect()` | Synchronizes component with external systems |

---

# 13. Self-Learning Assignments

1. Create a React application displaying your personal profile.
2. Create separate Header, Navbar, Content and Footer components.
3. Create a Student component that accepts name, roll number and course using props.
4. Create a Product component and display five products using an array.
5. Create a conditional rendering example for login and logout messages.
6. Create a reusable Button component and pass its text using props.
7. Rebuild a college admission form using React functional components.
8. Modify the World Clock application to display five countries.
9. Add date and day information to the World Clock.
10. Organize all components in a separate `components` folder.

---

# 14. Practical Checklist

- [ ] Understand React and its purpose.
- [ ] Understand React elements and components.
- [ ] Install Node.js and create a React project using Vite.
- [ ] Understand `main.jsx` and `App.jsx`.
- [ ] Understand JSX syntax and rules.
- [ ] Create functional components.
- [ ] Export and import components.
- [ ] Pass data using props.
- [ ] Understand component composition.
- [ ] Render components.
- [ ] Render arrays using `map()`.
- [ ] Understand conditional rendering.
- [ ] Declutter a large component.
- [ ] Complete the Resume Form React assignment.
- [ ] Complete the Three-Country Clock application.

---

# 15. Recommended References

### Books from the Web Programming reference list

1. **JavaScript: The Definitive Guide, 7th Edition** – David Flanagan, O'Reilly.
2. **React in Depth** – Morten Barklund, O'Reilly, 2024.
3. **Web Development with Node and Express** – Ethan Brown, O'Reilly.

### Official Documentation

- React Documentation: https://react.dev/
- Your First Component: https://react.dev/learn/your-first-component
- JSX: https://react.dev/learn/writing-markup-with-jsx
- Passing Props: https://react.dev/learn/passing-props-to-a-component
- Rendering Lists: https://react.dev/learn/rendering-lists
- Vite Documentation: https://vite.dev/guide/

**Study tip:** Focus on understanding the relationship between components, JSX and props. Practise creating reusable components rather than writing everything inside `App.jsx`. These are the foundations for the next React topics, including state, events, Hooks, forms and API integration.
