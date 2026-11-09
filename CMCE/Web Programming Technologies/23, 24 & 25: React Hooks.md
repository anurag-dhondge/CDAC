# Sessions 23, 24 & 25: React Hooks

**Course:** CMCE – August 2026 Batch  
**Subject:** Web Programming Technologies  
**Duration:** 6 Theory + 6 Lab + 4 Self-Learning Hours

---

# 1. Introduction to React Hooks

## 1.1 What are React Hooks?

React Hooks are special functions that allow functional components to use React features such as:

- State management
- Component lifecycle and side effects
- Sharing data between components
- Performance optimization
- Accessing external state management systems

Before Hooks were introduced in React 16.8, state and lifecycle features were primarily associated with class components.

Hooks made it possible to use these features inside functional components.

### Without Hooks

A simple function component:

```jsx
function App() {
    return <h1>Hello React</h1>;
}
```

This component displays UI but does not manage changing data.

### With Hooks

```jsx
import { useState } from "react";

function App() {

    const [count, setCount] = useState(0);

    return (
        <div>
            <h1>Count: {count}</h1>

            <button onClick={() => setCount(count + 1)}>
                Increase
            </button>
        </div>
    );
}

export default App;
```

Now the component can store and update data.

## 1.2 Rules of React Hooks

Hooks must follow specific rules.

**Rule 1: Only call Hooks at the top level.**

Correct:

```jsx
function App() {

    const [count, setCount] = useState(0);

    return <h1>{count}</h1>;
}
```

Incorrect:

```jsx
function App() {

    if (true) {
        const [count, setCount] = useState(0);
    }

    return <h1>Hello</h1>;
}
```

Do not call Hooks inside:
- Conditions
- Loops
- Nested functions
- Event handlers

**Rule 2: Only call Hooks inside React function components or custom Hooks.**

Correct:

```jsx
function Student() {
    const [name, setName] = useState("Anurag");

    return <h1>{name}</h1>;
}
```

Incorrect:

```jsx
function calculate() {
    const [count, setCount] = useState(0);
}
```

**Rule 3: Use meaningful Hook names.**

Custom Hooks should start with `use`, for example:
- `useClock()`
- `useStudent()`
- `useFetch()`

---

# 2. useState Hook

## 2.1 What is useState?

`useState` is a React Hook used to add and manage state in functional components.

**State is data that a component remembers between renders.**

When state changes, React schedules a re-render so the UI can display the updated value.

### Syntax

```jsx
const [state, setState] = useState(initialValue);
```

Where:

- `state`: Current state value.
- `setState`: Function used to update state.
- `initialValue`: Initial value of state.

### Example: Counter Application

```jsx
import { useState } from "react";

function App() {

    const [count, setCount] = useState(0);

    return (
        <div>
            <h1>Count: {count}</h1>

            <button onClick={() => setCount(count + 1)}>
                Increase
            </button>

            <button onClick={() => setCount(count - 1)}>
                Decrease
            </button>
        </div>
    );
}

export default App;
```

### Explanation

Initially:

```javascript
count = 0;
```

When the Increase button is clicked:

```javascript
setCount(count + 1);
```

The state becomes:

```javascript
count = 1;
```

React renders the component again and displays the new value.

## 2.2 Updating State Using Previous State

When the next state depends on the previous state, use the functional updater form.

```jsx
setCount(previousCount => previousCount + 1);
```

Example:

```jsx
function App() {

    const [count, setCount] = useState(0);

    function increase() {
        setCount(previous => previous + 1);
    }

    return (
        <div>
            <h1>{count}</h1>
            <button onClick={increase}>Increase</button>
        </div>
    );
}
```

This is useful when multiple state updates depend on earlier values.

## 2.3 useState with Strings

```jsx
import { useState } from "react";

function App() {

    const [name, setName] = useState("Anurag");

    return (
        <div>
            <h1>Hello {name}</h1>

            <button onClick={() => setName("Rahul")}>
                Change Name
            </button>
        </div>
    );
}
```

## 2.4 useState with Objects

```jsx
import { useState } from "react";

function App() {

    const [student, setStudent] = useState({
        name: "Anurag",
        course: "CMCE",
        city: "Pune"
    });

    function updateCity() {

        setStudent(previous => ({
            ...previous,
            city: "Mumbai"
        }));

    }

    return (
        <div>
            <h2>{student.name}</h2>
            <p>{student.course}</p>
            <p>{student.city}</p>

            <button onClick={updateCity}>
                Change City
            </button>
        </div>
    );
}
```

**Important:** State objects should be updated immutably. Do not directly modify the existing object.

Incorrect:

```javascript
student.city = "Mumbai";
```

Correct:

```javascript
setStudent(previous => ({
    ...previous,
    city: "Mumbai"
}));
```

## 2.5 useState with Arrays

```jsx
import { useState } from "react";

function App() {

    const [students, setStudents] = useState([
        "Anurag",
        "Rahul"
    ]);

    function addStudent() {

        setStudents(previous => [
            ...previous,
            "Amit"
        ]);

    }

    return (
        <div>
            <h2>Students</h2>

            {students.map((student, index) => (
                <p key={index}>{student}</p>
            ))}

            <button onClick={addStudent}>
                Add Student
            </button>
        </div>
    );
}

export default App;
```

### Important points about useState

1. State belongs to a component instance.
2. Updating state schedules a re-render.
3. Never modify state directly.
4. Use the setter function to update state.
5. Use functional updates when the next value depends on the previous value.

---

# 3. useEffect Hook

## 3.1 What is useEffect?

`useEffect` is a React Hook used to synchronize a component with external systems.

Examples:
- Timers
- API calls
- Event listeners
- Browser APIs
- Subscriptions
- External connections

It is also commonly used to perform operations after a component has been committed to the screen.

### Syntax

```jsx
useEffect(() => {

    // Side effect code

    return () => {
        // Cleanup code
    };

}, [dependencies]);
```

The cleanup function is optional.

## 3.2 Understanding useEffect Dependency Array

The dependency array controls when the Effect runs.

### Case 1: Without dependency array

```jsx
useEffect(() => {
    console.log("Effect executed");
});
```

Runs after every committed render.

### Case 2: Empty dependency array

```jsx
useEffect(() => {
    console.log("Component mounted");
}, []);
```

Runs after the component is initially mounted.

It is similar to the old `componentDidMount` lifecycle concept for this basic example.

### Case 3: With dependency

```jsx
useEffect(() => {
    console.log("Count changed");
}, [count]);
```

Runs after the initial mount and again when `count` changes.

### Comparison

| Dependency array | When Effect runs |
|---|---|
| Not provided | After every committed render |
| `[]` | After initial mount |
| `[count]` | After initial mount and when count changes |

Note: React Strict Mode may run an additional setup-and-cleanup cycle for Effects in development to help identify problems.

## 3.3 Example: useEffect with useState

```jsx
import { useState, useEffect } from "react";

function App() {

    const [count, setCount] = useState(0);

    useEffect(() => {

        console.log("Count changed:", count);

    }, [count]);

    return (
        <div>
            <h1>{count}</h1>

            <button onClick={() => setCount(count + 1)}>
                Increase
            </button>
        </div>
    );
}

export default App;
```

Whenever the count changes, the Effect executes.

## 3.4 useEffect with setInterval

Consider a clock application.

We need to update the time every second.

```jsx
import { useState, useEffect } from "react";

function Clock() {

    const [time, setTime] = useState(new Date());

    useEffect(() => {

        const interval = setInterval(() => {
            setTime(new Date());
        }, 1000);

        return () => {
            clearInterval(interval);
        };

    }, []);

    return (
        <h1>{time.toLocaleTimeString()}</h1>
    );
}

export default Clock;
```

Explanation:

1. `useState` stores the current time.
2. `useEffect` creates the timer.
3. `setInterval()` executes every second.
4. `setTime()` updates the state.
5. React re-renders the Clock component.
6. `clearInterval()` stops the timer during cleanup.

## 3.5 useEffect Cleanup Function

A cleanup function is used to remove or stop resources created by an Effect.

Examples:
- Stop timers.
- Remove event listeners.
- Cancel or ignore outdated asynchronous work.
- Close subscriptions.

Example:

```jsx
useEffect(() => {

    const interval = setInterval(() => {
        console.log("Running");
    }, 1000);

    return () => {
        clearInterval(interval);
    };

}, []);
```

Without cleanup, timers or subscriptions may continue running unnecessarily.

## 3.6 useEffect with API Calls

We can use `useEffect` to fetch data when a component loads.

```jsx
import { useState, useEffect } from "react";

function App() {

    const [users, setUsers] = useState([]);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState("");

    useEffect(() => {

        async function fetchUsers() {

            try {

                const response = await fetch(
                    "https://jsonplaceholder.typicode.com/users"
                );

                if (!response.ok) {
                    throw new Error("Failed to fetch users");
                }

                const data = await response.json();

                setUsers(data);

            } catch (err) {

                setError(err.message);

            } finally {

                setLoading(false);

            }
        }

        fetchUsers();

    }, []);

    if (loading) return <h2>Loading...</h2>;

    if (error) return <h2>{error}</h2>;

    return (
        <div>
            <h1>Users</h1>

            {users.map(user => (
                <p key={user.id}>{user.name}</p>
            ))}
        </div>
    );
}

export default App;
```

---

# 4. useContext Hook

## 4.1 What is Context?

Context is a React feature used to share data between components without passing props manually through every intermediate component.

This solves a problem known as **prop drilling**.

## 4.2 What is Prop Drilling?

Prop drilling means passing data through multiple components even when intermediate components do not need that data.

Example:

```text
App
 |
 v
Header
 |
 v
Navbar
 |
 v
Profile
```

Suppose the user name is required only by Profile.

Without Context, the name may need to be passed through Header and Navbar.

This can make the code unnecessarily complicated.

## 4.3 What is useContext?

`useContext` is a React Hook used to read a value from a Context.

### Step 1: Create Context

```jsx
import { createContext } from "react";

export const UserContext = createContext();
```

### Step 2: Provide Context

```jsx
import { UserContext } from "./UserContext";
import Profile from "./Profile";

function App() {

    const user = "Anurag";

    return (
        <UserContext.Provider value={user}>
            <Profile />
        </UserContext.Provider>
    );
}

export default App;
```

### Step 3: Consume Context

```jsx
import { useContext } from "react";
import { UserContext } from "./UserContext";

function Profile() {

    const user = useContext(UserContext);

    return <h1>Welcome {user}</h1>;
}

export default Profile;
```

Output:

```text
Welcome Anurag
```

### Understanding the flow

```text
App Component
     |
     | Provides user = "Anurag"
     |
     v
UserContext.Provider
     |
     v
Profile Component
     |
     | useContext(UserContext)
     |
     v
Displays Welcome Anurag
```

## 4.4 Example: Theme Context

Suppose we want to share a theme across components.

```jsx
import { createContext, useContext, useState } from "react";

const ThemeContext = createContext(null);

function Header() {

    const { theme, toggleTheme } = useContext(ThemeContext);

    return (
        <header
            style={{
                background: theme === "dark" ? "#222" : "#eee",
                color: theme === "dark" ? "white" : "black",
                padding: "20px"
            }}
        >
            <h2>Theme: {theme}</h2>

            <button onClick={toggleTheme}>
                Change Theme
            </button>
        </header>
    );
}

function App() {

    const [theme, setTheme] = useState("light");

    function toggleTheme() {
        setTheme(previous =>
            previous === "light" ? "dark" : "light"
        );
    }

    return (
        <ThemeContext.Provider value={{ theme, toggleTheme }}>
            <Header />
        </ThemeContext.Provider>
    );
}

export default App;
```

### Benefits of useContext

- Avoids unnecessary prop drilling.
- Shares common data.
- Useful for authentication information.
- Useful for themes.
- Useful for language preferences.
- Useful for application-wide settings.

---

# 5. useMemo Hook

## 5.1 What is useMemo?

`useMemo` is a React Hook used to cache the result of a calculation between renders.

It helps avoid repeating expensive calculations when the dependencies have not changed.

### Syntax

```jsx
const memoizedValue = useMemo(() => {

    return expensiveCalculation();

}, [dependencies]);
```

## 5.2 Example without useMemo

```jsx
function App() {

    const [count, setCount] = useState(0);
    const [number, setNumber] = useState(10);

    function calculateSquare(num) {

        console.log("Calculation running");

        return num * num;

    }

    const result = calculateSquare(number);

    return (
        <div>
            <h2>Count: {count}</h2>
            <h2>Square: {result}</h2>

            <button onClick={() => setCount(count + 1)}>
                Increase Count
            </button>

        </div>
    );
}
```

Problem:

Even when only `count` changes, the square calculation runs again.

## 5.3 Example with useMemo

```jsx
import { useState, useMemo } from "react";

function App() {

    const [count, setCount] = useState(0);
    const [number, setNumber] = useState(10);

    const result = useMemo(() => {

        console.log("Calculating square");

        return number * number;

    }, [number]);

    return (
        <div>
            <h2>Count: {count}</h2>
            <h2>Number: {number}</h2>
            <h2>Square: {result}</h2>

            <button onClick={() => setCount(count + 1)}>
                Increase Count
            </button>

            <button onClick={() => setNumber(number + 1)}>
                Increase Number
            </button>
        </div>
    );
}

export default App;
```

Now the square calculation is reused when `count` changes. It recalculates when `number` changes.

### When should we use useMemo?

Use it when:
- Calculations are expensive.
- Filtering large arrays.
- Sorting large datasets.
- Deriving complex values.
- Avoiding unnecessary recalculation.

Do not use it everywhere. Memoization has its own cost and should be applied when useful.

---

# 6. useCallback Hook

## 6.1 What is useCallback?

`useCallback` is a React Hook used to cache a function definition between renders.

It is useful when passing functions to memoized child components or when function identity matters to another Hook.

### Syntax

```jsx
const memoizedFunction = useCallback(() => {

    // Function logic

}, [dependencies]);
```

## 6.2 Example without useCallback

```jsx
function Button({ handleClick }) {

    console.log("Button rendered");

    return (
        <button onClick={handleClick}>
            Click Me
        </button>
    );
}
```

```jsx
function App() {

    const [count, setCount] = useState(0);

    const handleClick = () => {
        console.log("Button clicked");
    };

    return (
        <div>
            <h1>{count}</h1>

            <button onClick={() => setCount(count + 1)}>
                Increase
            </button>

            <Button handleClick={handleClick} />
        </div>
    );
}
```

A new function is created during each App render.

## 6.3 Example with useCallback and memo

```jsx
import { useState, useCallback, memo } from "react";

const Button = memo(function Button({ handleClick }) {

    console.log("Button rendered");

    return (
        <button onClick={handleClick}>
            Click Me
        </button>
    );

});

function App() {

    const [count, setCount] = useState(0);

    const handleClick = useCallback(() => {
        console.log("Button clicked");
    }, []);

    return (
        <div>
            <h1>Count: {count}</h1>

            <button onClick={() => setCount(count + 1)}>
                Increase
            </button>

            <Button handleClick={handleClick} />
        </div>
    );
}

export default App;
```

Here:
- `useCallback` preserves the function reference while dependencies remain unchanged.
- `memo` can skip rendering the child when its props have not changed.

**Important:** `useCallback` caches a function definition; `useMemo` caches a calculated value.

## 6.4 useMemo vs useCallback

| useMemo | useCallback |
|---|---|
| Caches a calculated value | Caches a function definition |
| Returns a value | Returns a function |
| Used for expensive calculations | Used when function identity matters |
| `useMemo(() => value, [deps])` | `useCallback(() => {}, [deps])` |

---

# 7. useSelector Hook

## 7.1 What is useSelector?

`useSelector` is a Hook provided by the React Redux library.

It allows a React component to read data from the Redux store.

**Important distinction:**
- `useState`, `useEffect`, `useContext`, `useMemo` and `useCallback` belong to React.
- `useSelector` belongs to React Redux.

Redux is a state management library used to manage shared application state.

## 7.2 Why do we need useSelector?

Suppose an application contains:

- Login component
- Navbar component
- Profile component
- Dashboard component
- Cart component

Several components may need access to the same application data.

Redux provides a central store where shared state can be maintained.

`useSelector` reads a particular value from that store.

### Basic syntax

```jsx
const value = useSelector(state => state.someValue);
```

Here:
- `useSelector` accesses the Redux store.
- `state` represents the Redux state.
- The selector function returns the required value.

## 7.3 Installing Redux Toolkit and React Redux

```bash
npm install @reduxjs/toolkit react-redux
```

## 7.4 Example: Counter using Redux

### Step 1: Create counterSlice.js

```jsx
import { createSlice } from "@reduxjs/toolkit";

const counterSlice = createSlice({

    name: "counter",

    initialState: {
        value: 0
    },

    reducers: {

        increment: state => {
            state.value += 1;
        },

        decrement: state => {
            state.value -= 1;
        }

    }

});

export const { increment, decrement } = counterSlice.actions;

export default counterSlice.reducer;
```

### Step 2: Create store.js

```jsx
import { configureStore } from "@reduxjs/toolkit";
import counterReducer from "./counterSlice";

export const store = configureStore({

    reducer: {
        counter: counterReducer
    }

});
```

### Step 3: Configure Provider in main.jsx

```jsx
import React from "react";
import ReactDOM from "react-dom/client";
import { Provider } from "react-redux";

import App from "./App";
import { store } from "./store";

ReactDOM.createRoot(
    document.getElementById("root")
).render(

    <Provider store={store}>
        <App />
    </Provider>

);
```

### Step 4: Use useSelector in App.jsx

```jsx
import { useSelector, useDispatch } from "react-redux";

import { increment, decrement } from "./counterSlice";

function App() {

    const count = useSelector(state => state.counter.value);

    const dispatch = useDispatch();

    return (
        <div>

            <h1>Count: {count}</h1>

            <button onClick={() => dispatch(increment())}>
                Increase
            </button>

            <button onClick={() => dispatch(decrement())}>
                Decrease
            </button>

        </div>
    );
}

export default App;
```

### Understanding the flow

```text
React Component
      |
      | useSelector()
      v
Redux Store
      |
      | Returns state
      v
Component displays data

Button Click
      |
      | dispatch(increment())
      v
Redux Reducer
      |
      v
Store Updated
      |
      v
Component Receives Updated State
```

### useSelector vs useState

| useState | useSelector |
|---|---|
| React Hook | React Redux Hook |
| Manages local component state | Reads Redux store state |
| State belongs to a component instance | Reads shared application state |
| Uses a setter function | State changes through Redux actions and reducers |

---

# 8. Props vs State vs Context

These three concepts are important for managing and sharing data in React.

## 8.1 Props

Props are used to pass data from a parent component to a child component.

Example:

```jsx
function Student({ name }) {
    return <h2>{name}</h2>;
}

function App() {
    return <Student name="Anurag" />;
}
```

## 8.2 State

State is data managed by a component.

Example:

```jsx
const [count, setCount] = useState(0);
```

State changes can cause the component to re-render.

## 8.3 Context

Context allows data to be shared across a component tree without passing it through every intermediate component.

Example:

```jsx
const ThemeContext = createContext("light");
```

A Provider makes the value available to consuming components.

## 8.4 Comparison

| Feature | Props | State | Context |
|---|---|---|---|
| Purpose | Pass data to child | Store changing data | Share data across component tree |
| Managed by | Parent component | Component itself | Context Provider |
| Read-only for receiving child? | Yes | Updated through setter | Consumer reads provided value |
| Data flow | Parent to child | Component state | Provider to consumers |
| Common use | Student name, course | Counter, input values | Theme, language, user session |

### When should we use each?

- **Props:** When passing information to a child component.
- **State:** When a component needs to remember changing information.
- **Context:** When multiple components need access to shared information.

Remember: Context is not a replacement for all state management. Use the simplest solution that fits the application.

---

# 9. Handling Events in React

## 9.1 What are Events?

Events are actions performed by users or the browser.

Examples:
- Clicking a button.
- Typing into an input.
- Submitting a form.
- Moving the mouse.
- Changing a dropdown.

React provides event handlers to respond to these actions.

## 9.2 Common React Events

| Event | Purpose |
|---|---|
| `onClick` | Mouse click |
| `onChange` | Input value change |
| `onSubmit` | Form submission |
| `onMouseOver` | Mouse moves over an element |
| `onKeyDown` | Keyboard key pressed |
| `onFocus` | Input receives focus |
| `onBlur` | Input loses focus |

## 9.3 onClick Event

```jsx
function App() {

    function showMessage() {
        alert("Button clicked");
    }

    return (
        <button onClick={showMessage}>
            Click Me
        </button>
    );
}
```

Notice:

Correct:

```jsx
<button onClick={showMessage}>Click</button>
```

Incorrect:

```jsx
<button onClick={showMessage()}>Click</button>
```

The incorrect example calls the function during rendering rather than waiting for a click.

## 9.4 onChange Event

```jsx
import { useState } from "react";

function App() {

    const [name, setName] = useState("");

    return (
        <div>

            <input
                type="text"
                value={name}
                onChange={event => setName(event.target.value)}
            />

            <h2>Hello {name}</h2>

        </div>
    );
}
```

When the user types, the state is updated.

## 9.5 onSubmit Event

```jsx
function App() {

    function handleSubmit(event) {

        event.preventDefault();

        alert("Form submitted");

    }

    return (
        <form onSubmit={handleSubmit}>

            <input type="text" placeholder="Enter name" />

            <button type="submit">Submit</button>

        </form>
    );
}
```

`event.preventDefault()` prevents the browser's default form submission behavior.

## 9.6 Passing Arguments to Event Handlers

```jsx
function App() {

    function showName(name) {
        alert("Hello " + name);
    }

    return (
        <button onClick={() => showName("Anurag")}>
            Show Name
        </button>
    );
}
```

---

# 10. Conditional Rendering

## 10.1 What is Conditional Rendering?

Conditional rendering means displaying different UI depending on a condition.

For example:
- Display Login if the user is logged out.
- Display Dashboard if the user is logged in.
- Display Loading while fetching data.
- Display an error message if an API request fails.

## 10.2 Using if-else

```jsx
function App() {

    const isLoggedIn = true;

    if (isLoggedIn) {
        return <h1>Welcome User</h1>;
    }

    return <h1>Please Login</h1>;
}
```

## 10.3 Using Ternary Operator

Syntax:

```jsx
condition ? expression1 : expression2
```

Example:

```jsx
function App() {

    const isLoggedIn = false;

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

## 10.4 Using Logical AND (&&)

```jsx
function App() {

    const isAdmin = true;

    return (
        <div>
            {isAdmin && <h1>Admin Dashboard</h1>}
        </div>
    );
}
```

The element appears only when `isAdmin` is true.

**Caution:** Avoid expressions such as `{count && <p>...</p>}` when `count` can be zero, because React may display `0`. Use `{count > 0 && ...}` instead.

## 10.5 Conditional Rendering with State

```jsx
import { useState } from "react";

function App() {

    const [show, setShow] = useState(true);

    return (
        <div>

            <button onClick={() => setShow(!show)}>
                Toggle Message
            </button>

            {show && <h2>Hello React</h2>}

        </div>
    );
}
```

When the button is clicked, the message appears or disappears.

---

# 11. Lab 1 – Update Clock App Time Using useState and useEffect

## Objective

Create a React clock application that displays the current time and updates every second.

### Requirements

- Use `useState` to store time.
- Use `useEffect` to create a timer.
- Use `setInterval()` to update time.
- Use `clearInterval()` for cleanup.
- Display time in HH:MM:SS format.

### Step 1: Create a project

```bash
npm create vite@latest react-clock -- --template react

cd react-clock

npm install

npm run dev
```

### Step 2: Create Clock.jsx

```jsx
import { useState, useEffect } from "react";

function Clock() {

    const [time, setTime] = useState(new Date());

    useEffect(() => {

        const interval = setInterval(() => {

            setTime(new Date());

        }, 1000);

        return () => clearInterval(interval);

    }, []);

    return (
        <div>

            <h1>React Clock</h1>

            <h2>
                {time.toLocaleTimeString("en-GB")}
            </h2>

        </div>
    );
}

export default Clock;
```

### Step 3: Use Clock in App.jsx

```jsx
import Clock from "./Clock";

function App() {
    return <Clock />;
}

export default App;
```

### Output

```text
React Clock

23:15:01
23:15:02
23:15:03
```

The values above are illustrative. Your clock displays the actual local time.

---

# 12. Lab 2 – Improve React Clock App

## Requirements

Implement these features:

1. Update time in HH:MM:SS format using state and lifecycle-like Effect behavior.
2. Add a close function to every clock component.
3. Change the clock background according to AM or PM.

We will use three time zones:

- India – Asia/Kolkata
- United Kingdom – Europe/London
- Japan – Asia/Tokyo

## Step 1: Project structure

```text
react-clock/
│
├── src/
│   ├── components/
│   │   ├── Clock.jsx
│   │   └── Header.jsx
│   │
│   ├── App.jsx
│   ├── App.css
│   └── main.jsx
│
├── package.json
└── index.html
```

## Step 2: Create Clock.jsx

```jsx
import { useState, useEffect } from "react";

function Clock({ id, country, city, timeZone, onClose }) {

    const [time, setTime] = useState("");
    const [period, setPeriod] = useState("AM");

    useEffect(() => {

        function updateTime() {

            const now = new Date();

            const formatter = new Intl.DateTimeFormat(
                "en-US",
                {
                    timeZone: timeZone,
                    hour: "2-digit",
                    minute: "2-digit",
                    second: "2-digit",
                    hour12: true
                }
            );

            const parts = formatter.formatToParts(now);

            const hour = parts.find(
                part => part.type === "hour"
            )?.value;

            const minute = parts.find(
                part => part.type === "minute"
            )?.value;

            const second = parts.find(
                part => part.type === "second"
            )?.value;

            const dayPeriod = parts.find(
                part => part.type === "dayPeriod"
            )?.value;

            setTime(`${hour}:${minute}:${second}`);

            setPeriod(dayPeriod);

        }

        updateTime();

        const interval = setInterval(updateTime, 1000);

        return () => {
            clearInterval(interval);
        };

    }, [timeZone]);

    return (
        <div className={`clock-card ${period.toLowerCase()}`}>

            <button
                className="close-btn"
                onClick={() => onClose(id)}
                aria-label={`Close ${country} clock`}
            >
                ×
            </button>

            <h2>{country}</h2>

            <p>{city}</p>

            <h1>{time}</h1>

            <h3>{period}</h3>

        </div>
    );
}

export default Clock;
```

### Explanation

**1. State**

```jsx
const [time, setTime] = useState("");
const [period, setPeriod] = useState("AM");
```

The component stores:
- Current time.
- AM/PM period.

**2. Time zone formatting**

```javascript
new Intl.DateTimeFormat("en-US", {
    timeZone: timeZone,
    hour: "2-digit",
    minute: "2-digit",
    second: "2-digit",
    hour12: true
});
```

It generates time for the specified time zone.

**3. Extracting AM/PM**

```javascript
const dayPeriod = parts.find(
    part => part.type === "dayPeriod"
)?.value;
```

It returns `AM` or `PM`.

**4. Updating the background**

```jsx
<div className={`clock-card ${period.toLowerCase()}`}>
```

If the time is AM, the class becomes `clock-card am`.

If the time is PM, the class becomes `clock-card pm`.

**5. Close button**

```jsx
onClick={() => onClose(id)}
```

When clicked, it sends the clock ID to the parent component.

---

## Step 3: Create App.jsx

```jsx
import { useState } from "react";

import Clock from "./components/Clock";

function App() {

    const [clocks, setClocks] = useState([

        {
            id: 1,
            country: "India",
            city: "New Delhi",
            timeZone: "Asia/Kolkata"
        },

        {
            id: 2,
            country: "United Kingdom",
            city: "London",
            timeZone: "Europe/London"
        },

        {
            id: 3,
            country: "Japan",
            city: "Tokyo",
            timeZone: "Asia/Tokyo"
        }

    ]);

    function closeClock(id) {

        setClocks(previousClocks =>
            previousClocks.filter(clock => clock.id !== id)
        );

    }

    return (
        <div className="container">

            <h1>World Clock Application</h1>

            <div className="clock-container">

                {clocks.map(clock => (

                    <Clock
                        key={clock.id}
                        id={clock.id}
                        country={clock.country}
                        city={clock.city}
                        timeZone={clock.timeZone}
                        onClose={closeClock}
                    />

                ))}

            </div>

        </div>
    );
}

export default App;
```

### How the close function works

Suppose the application contains:

```javascript
[
    { id: 1, country: "India" },
    { id: 2, country: "United Kingdom" },
    { id: 3, country: "Japan" }
]
```

If the user closes clock ID 2:

```javascript
setClocks(previousClocks =>
    previousClocks.filter(clock => clock.id !== 2)
);
```

The resulting array is:

```javascript
[
    { id: 1, country: "India" },
    { id: 3, country: "Japan" }
]
```

React renders the remaining clocks.

The removed Clock component unmounts, and its Effect cleanup clears its interval.

---

## Step 4: Create App.css

```css
body {
    margin: 0;
    font-family: Arial, sans-serif;
    background: #f1f3f6;
}

.container {
    text-align: center;
    padding: 40px 20px;
}

.clock-container {
    display: flex;
    justify-content: center;
    flex-wrap: wrap;
    gap: 20px;
}

.clock-card {
    width: 250px;
    padding: 30px 20px;
    border-radius: 12px;
    position: relative;
    box-shadow: 0 4px 12px rgba(0, 0, 0, 0.15);
    transition: background-color 0.3s;
}

.clock-card.am {
    background-color: #d9efff;
    color: #123b60;
}

.clock-card.pm {
    background-color: #34345f;
    color: white;
}

.clock-card h1 {
    font-size: 30px;
}

.close-btn {
    position: absolute;
    right: 10px;
    top: 10px;
    border: none;
    border-radius: 50%;
    width: 28px;
    height: 28px;
    font-size: 20px;
    cursor: pointer;
    background: rgba(255, 255, 255, 0.8);
    color: #222;
}
```

## Step 5: Run the application

```bash
npm run dev
```

Open the Vite URL in your browser.

### Expected behaviour

**AM clock**

- Displays time in HH:MM:SS format.
- Has a light blue background.

**PM clock**

- Displays time in HH:MM:SS format.
- Has a dark background.

**Close button**

- Every clock has its own close button.
- Clicking it removes only that clock.
- Remaining clocks continue updating.

The AM/PM background is determined separately for each clock's time zone. Therefore, the clocks may have different backgrounds at the same instant.

### Important learning points

| Feature | React concept |
|---|---|
| Updating clock | `useState` |
| Creating timer | `useEffect` |
| Stopping timer | Effect cleanup |
| Removing clock | State update with `filter()` |
| Sending clock ID | Props |
| Close button | Event handling |
| AM/PM background | Conditional styling |
| Displaying three clocks | Component composition |

---

# 13. Lifecycle Methods vs useEffect

Before Hooks, React class components used lifecycle methods.

The important lifecycle methods include:

| Class lifecycle method | Purpose |
|---|---|
| `componentDidMount()` | Runs after initial mounting |
| `componentDidUpdate()` | Runs after updates |
| `componentWillUnmount()` | Runs before unmounting |

With functional components, `useEffect` can handle many of the same synchronization and cleanup tasks.

### Example: Class Component

```jsx
import React, { Component } from "react";

class Clock extends Component {

    state = {
        time: new Date()
    };

    componentDidMount() {

        this.interval = setInterval(() => {

            this.setState({
                time: new Date()
            });

        }, 1000);

    }

    componentWillUnmount() {
        clearInterval(this.interval);
    }

    render() {
        return (
            <h1>
                {this.state.time.toLocaleTimeString()}
            </h1>
        );
    }
}

export default Clock;
```

### Equivalent functional approach

```jsx
import { useState, useEffect } from "react";

function Clock() {

    const [time, setTime] = useState(new Date());

    useEffect(() => {

        const interval = setInterval(() => {
            setTime(new Date());
        }, 1000);

        return () => clearInterval(interval);

    }, []);

    return (
        <h1>{time.toLocaleTimeString()}</h1>
    );
}

export default Clock;
```

### Comparison

| Class Component | Functional Component |
|---|---|
| Uses `this.state` | Uses `useState` |
| Uses `this.setState()` | Uses state setter |
| Uses `componentDidMount()` | Often implemented with `useEffect` |
| Uses `componentWillUnmount()` | Uses Effect cleanup |
| Uses `componentDidUpdate()` | Uses an Effect with dependencies when appropriate |

**Important:** `useEffect` is not a direct one-to-one replacement for every lifecycle method. It is designed for synchronizing with external systems.

---

# 14. Important Differences for CCEE

## useState vs useEffect

| useState | useEffect |
|---|---|
| Manages component state | Synchronizes with external systems |
| Returns state and setter | Runs an Effect after commit |
| Updates can trigger rendering | Can set state and cause rendering |
| Example: counter | Example: timer or API request |

## useContext vs useSelector

| useContext | useSelector |
|---|---|
| React Hook | React Redux Hook |
| Reads React Context | Reads Redux store |
| Used for shared context values | Used for centralized Redux state |
| Uses Context Provider | Uses Redux Provider |

## useMemo vs useCallback

| useMemo | useCallback |
|---|---|
| Caches a value | Caches a function definition |
| Useful for expensive calculations | Useful when function identity matters |
| Returns calculated result | Returns function |

## Conditional Rendering vs Conditional Styling

| Conditional Rendering | Conditional Styling |
|---|---|
| Shows or hides an element | Changes appearance of an element |
| Example: show login page | Example: AM/PM background |
| Uses `if`, `&&`, `?:` | Uses conditional classes or styles |

---

# 15. CCEE / Interview Questions

### React Hooks

1. What are React Hooks?
2. Why were Hooks introduced?
3. What are the rules of Hooks?
4. Can Hooks be used inside class components?
5. What is a custom Hook?

### useState

6. What is useState?
7. What is the syntax of useState?
8. What happens when state changes?
9. Can we directly modify state?
10. What is a functional state update?
11. How do you manage arrays using useState?
12. How do you manage objects using useState?

### useEffect

13. What is useEffect?
14. What is a dependency array?
15. What happens if the dependency array is empty?
16. What happens if no dependency array is provided?
17. What is an Effect cleanup function?
18. Why do we use clearInterval?
19. How can we fetch API data using useEffect?
20. What is the difference between useState and useEffect?

### Context, Memoization and Redux

21. What is useContext?
22. What is prop drilling?
23. What is Context Provider?
24. What is useMemo?
25. What is useCallback?
26. Difference between useMemo and useCallback?
27. What is Redux?
28. What is useSelector?
29. Is useSelector a React core Hook?
30. What is the purpose of useDispatch?

### Events and Conditional Rendering

31. What are React events?
32. What is onClick?
33. What is onChange?
34. What is onSubmit?
35. What is event.preventDefault()?
36. What is conditional rendering?
37. Explain ternary operator in JSX.
38. What is the purpose of logical AND in JSX?
39. What is the difference between conditional rendering and conditional styling?
40. How can we remove a component from a rendered list?

---

# 16. MCQs – Practice for CCEE

**1. Which Hook is used to manage state?**

A. useEffect  
B. useState  
C. useContext  
D. useMemo  

**Answer: B. useState**

**2. Which Hook is used to synchronize a component with external systems?**

A. useState  
B. useMemo  
C. useEffect  
D. useSelector  

**Answer: C. useEffect**

**3. What does useState return?**

A. Only a value  
B. An array containing state and setter function  
C. An object containing props  
D. A Promise  

**Answer: B. An array containing state and setter function**

**4. Which function stops a setInterval timer?**

A. stopInterval()  
B. clearInterval()  
C. removeInterval()  
D. endInterval()  

**Answer: B. clearInterval()**

**5. What is the purpose of the useEffect cleanup function?**

A. Create JSX  
B. Clean up resources created by an Effect  
C. Update props  
D. Install packages  

**Answer: B. Clean up resources created by an Effect**

**6. Which Hook is used to consume Context?**

A. useMemo  
B. useContext  
C. useState  
D. useCallback  

**Answer: B. useContext**

**7. Prop drilling means:**

A. Passing data through intermediate components  
B. Deleting props  
C. Updating state directly  
D. Rendering HTML  

**Answer: A. Passing data through intermediate components**

**8. Which Hook caches a calculated value?**

A. useCallback  
B. useState  
C. useMemo  
D. useEffect  

**Answer: C. useMemo**

**9. Which Hook caches a function definition?**

A. useCallback  
B. useContext  
C. useEffect  
D. useSelector  

**Answer: A. useCallback**

**10. useSelector belongs to:**

A. React core  
B. React Redux  
C. Node.js  
D. Express  

**Answer: B. React Redux**

**11. Which Hook reads values from a Redux store?**

A. useState  
B. useContext  
C. useSelector  
D. useMemo  

**Answer: C. useSelector**

**12. Which event is used when a button is clicked?**

A. onChange  
B. onClick  
C. onSubmit  
D. onFocus  

**Answer: B. onClick**

**13. Which method prevents default browser form submission?**

A. event.stop()  
B. event.preventDefault()  
C. event.cancel()  
D. event.prevent()  

**Answer: B. event.preventDefault()**

**14. Which operator is commonly used for conditional rendering?**

A. Ternary operator  
B. Assignment operator only  
C. Bitwise operator  
D. Increment operator  

**Answer: A. Ternary operator**

**15. Which lifecycle method runs before a class component is removed?**

A. componentDidMount()  
B. componentDidUpdate()  
C. componentWillUnmount()  
D. componentRender()  

**Answer: C. componentWillUnmount()**

---

# 17. Quick Revision Notes

| Hook / Concept | Purpose |
|---|---|
| `useState` | Manages local state |
| `useEffect` | Synchronizes with external systems |
| `useContext` | Reads Context values |
| `useMemo` | Caches calculated values |
| `useCallback` | Caches function definitions |
| `useSelector` | Reads Redux store values |
| Props | Passes data from parent to child |
| State | Stores changing component data |
| Context | Shares data across component trees |
| `onClick` | Handles button clicks |
| `onChange` | Handles input changes |
| `onSubmit` | Handles form submissions |
| Conditional rendering | Displays UI based on conditions |
| `setInterval` | Repeats an operation after a time interval |
| `clearInterval` | Stops a timer |
| Effect cleanup | Releases resources used by an Effect |

---

# 18. Self-Learning Assignments

1. Create a counter using useState with Increase, Decrease and Reset buttons.
2. Create a digital clock using useState and useEffect.
3. Fetch users from an API using useEffect.
4. Create a theme switcher using useContext.
5. Create a student list using useState and useContext.
6. Use useMemo to calculate the sum of a large array.
7. Use useCallback to pass a function to a memoized child component.
8. Build a Redux counter using useSelector and useDispatch.
9. Create a login/logout application using conditional rendering.
10. Improve the World Clock by allowing users to add and remove countries.
11. Change clock background based on AM/PM.
12. Display a message when all clock components are closed.

---

# 19. Practical Checklist

- [ ] Understand React Hooks.
- [ ] Understand the Rules of Hooks.
- [ ] Implement useState.
- [ ] Implement useEffect.
- [ ] Understand dependency arrays.
- [ ] Implement Effect cleanup.
- [ ] Use useContext to share data.
- [ ] Understand prop drilling.
- [ ] Implement useMemo.
- [ ] Implement useCallback.
- [ ] Understand useSelector with Redux.
- [ ] Understand Props vs State vs Context.
- [ ] Handle click, change and submit events.
- [ ] Implement conditional rendering.
- [ ] Update Clock using useState and useEffect.
- [ ] Add a close button to each Clock.
- [ ] Implement AM/PM background colors.
- [ ] Test the Clock application in the browser.

---

# 20. Recommended References

### Books

1. **React in Depth** – Morten Barklund, O'Reilly, 2024.
2. **JavaScript: The Definitive Guide, 7th Edition** – David Flanagan, O'Reilly.

### Official Documentation

- React Hooks: https://react.dev/reference/react
- useState: https://react.dev/reference/react/useState
- useEffect: https://react.dev/reference/react/useEffect
- useContext: https://react.dev/reference/react/useContext
- useMemo: https://react.dev/reference/react/useMemo
- useCallback: https://react.dev/reference/react/useCallback
- React Redux Hooks: https://react-redux.js.org/api/hooks
- Conditional Rendering: https://react.dev/learn/conditional-rendering
- Responding to Events: https://react.dev/learn/responding-to-events

**Final study tip:** Practise `useState` and `useEffect` thoroughly before moving to the other Hooks. The World Clock assignment is particularly important because it combines state, Effects, cleanup, props, event handling, conditional styling and component rendering.
