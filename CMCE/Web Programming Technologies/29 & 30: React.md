# Sessions 29 & 30: React – Error Boundaries, Composition and React Router

**Course:** CMCE – August 2026 Batch  
**Subject:** Web Programming Technologies  
**Duration:** 4 Theory + 4 Lab + 2 Self-Learning Hours

---

# 1. Error Boundaries

## 1.1 What are Error Boundaries?

Error Boundaries are React components that catch JavaScript errors occurring during rendering, in lifecycle methods, and in constructors of their descendant components.

They display a fallback UI instead of allowing the entire component tree to crash.

### Real-world example

Consider a World Clock application containing:

- Header
- Navigation
- India Clock
- UK Clock
- Japan Clock

Suppose the Japan Clock component encounters a rendering error.

Without error handling, the error may affect the application UI.

With an Error Boundary, we can isolate the problem and display:

```text
World Clock Application

India Clock       10:30:00
UK Clock          05:00:00

Japan Clock

Something went wrong while displaying this clock.

[Try Again]
```

The other clocks can continue displaying normally if each clock has its own Error Boundary.

## 1.2 Why do we need Error Boundaries?

Error Boundaries help us:

1. Prevent rendering errors from crashing large parts of the UI.
2. Display user-friendly fallback messages.
3. Isolate errors in specific components.
4. Improve application reliability.
5. Provide a recovery mechanism.

## 1.3 How do Error Boundaries work?

An Error Boundary catches errors in its descendant component tree.

It uses two important lifecycle methods:

| Method | Purpose |
|---|---|
| `static getDerivedStateFromError()` | Updates state to display fallback UI |
| `componentDidCatch()` | Receives error details for logging or reporting |

**Important:** React currently provides Error Boundaries through class components. There is no built-in function-component Hook equivalent.

## 1.4 Creating an Error Boundary

Create a file named `ErrorBoundary.jsx`.

```jsx
import React from "react";

class ErrorBoundary extends React.Component {

    constructor(props) {

        super(props);

        this.state = {
            hasError: false
        };

    }

    static getDerivedStateFromError(error) {

        return {
            hasError: true
        };

    }

    componentDidCatch(error, errorInfo) {

        console.error("Error caught:", error);

        console.error("Error details:", errorInfo);

    }

    render() {

        if (this.state.hasError) {

            return (
                <div>
                    <h2>Something went wrong!</h2>

                    <p>Unable to display this component.</p>

                    <button
                        onClick={() =>
                            this.setState({ hasError: false })
                        }
                    >
                        Try Again
                    </button>
                </div>
            );

        }

        return this.props.children;

    }

}

export default ErrorBoundary;
```

### Explanation

**1. Constructor**

```jsx
constructor(props) {
    super(props);

    this.state = {
        hasError: false
    };
}
```

Initially, there is no error.

**2. getDerivedStateFromError()**

```jsx
static getDerivedStateFromError(error) {
    return {
        hasError: true
    };
}
```

When a descendant rendering error occurs, React uses this method to update the Error Boundary state.

**3. componentDidCatch()**

```jsx
componentDidCatch(error, errorInfo) {
    console.error(error);
}
```

This method is useful for logging errors.

**4. render()**

```jsx
if (this.state.hasError) {
    return <h2>Something went wrong!</h2>;
}
```

Displays fallback UI when an error is caught.

Otherwise:

```jsx
return this.props.children;
```

Displays the normal child components.

## 1.5 Using Error Boundary in App.jsx

```jsx
import ErrorBoundary from "./ErrorBoundary";
import Clock from "./Clock";

function App() {

    return (
        <div>

            <h1>World Clock</h1>

            <ErrorBoundary>
                <Clock
                    country="India"
                    timeZone="Asia/Kolkata"
                />
            </ErrorBoundary>

            <ErrorBoundary>
                <Clock
                    country="UK"
                    timeZone="Europe/London"
                />
            </ErrorBoundary>

            <ErrorBoundary>
                <Clock
                    country="Japan"
                    timeZone="Asia/Tokyo"
                />
            </ErrorBoundary>

        </div>
    );
}

export default App;
```

Here, each Clock has its own Error Boundary.

If one clock encounters a rendering error, its fallback UI is displayed without necessarily affecting the other clocks.

## 1.6 Error Boundary Limitations

Error Boundaries do not catch every type of error.

They generally do not catch errors occurring in:

1. Event handlers.
2. Asynchronous callbacks such as `setTimeout`.
3. Promise callbacks.
4. Server-side rendering.
5. Errors thrown by the Error Boundary itself.

Example:

```jsx
function App() {

    function handleClick() {

        throw new Error("Button error");

    }

    return (
        <button onClick={handleClick}>
            Click Me
        </button>
    );
}
```

This event-handler error is not caught by a normal Error Boundary.

For event handlers and asynchronous operations, use normal JavaScript error handling such as `try...catch`.

### Important distinction

| Error type | Error Boundary catches it? |
|---|---|
| Rendering error in child | Yes |
| Constructor error in child | Yes |
| Lifecycle error in child | Yes |
| Event handler error | No |
| setTimeout callback error | No |
| Promise rejection | No |
| Error inside the boundary itself | No |

---

# 2. Composition vs. Inheritance

## 2.1 What is Composition?

Composition means building complex components by combining smaller reusable components.

Instead of writing one large component, we create multiple independent components and combine them.

Example:

```text
App
 |
 |--- Header
 |
 |--- Navigation
 |
 |--- ClockContainer
 |       |
 |       |--- Clock
 |       |--- Clock
 |       |--- Clock
 |
 |--- Footer
```

Each component performs a specific task.

### Example

```jsx
function Header() {
    return <h1>World Clock</h1>;
}

function Footer() {
    return <p>React Clock Application</p>;
}

function App() {

    return (
        <div>

            <Header />

            <h2>Welcome to World Clock</h2>

            <Footer />

        </div>
    );

}

export default App;
```

Here, App is composed of Header and Footer components.

## 2.2 What is Inheritance?

Inheritance is an object-oriented programming concept where one class derives properties and methods from another class.

Example in JavaScript:

```javascript
class Animal {

    eat() {
        console.log("Animal is eating");
    }

}

class Dog extends Animal {

    bark() {
        console.log("Dog is barking");
    }

}

const dog = new Dog();

dog.eat();
dog.bark();
```

Output:

```text
Animal is eating
Dog is barking
```

The Dog class inherits the `eat()` method from Animal.

### In React

React does not recommend using component inheritance as the primary method of sharing component logic.

Instead, React encourages composition.

## 2.3 Composition vs. Inheritance

| Composition | Inheritance |
|---|---|
| Combines smaller components | Derives from a parent class |
| Uses props and children | Uses `extends` |
| Encourages reusable components | Creates class relationships |
| Preferred React design approach | Rarely needed for React component reuse |
| Flexible component structure | Can create tighter dependencies |

---

# 3. Composition – Containment

## 3.1 What is Containment?

Containment means allowing a component to receive other components or elements through the `children` prop.

It is useful when a component acts as a container for other components.

For example:

- Card
- Modal
- Dashboard layout
- Panel
- Page layout

### Example

```jsx
function Card({ children }) {

    return (
        <div className="card">

            {children}

        </div>
    );

}
```

Now we can reuse Card with different content.

```jsx
function App() {

    return (
        <div>

            <Card>
                <h2>India Clock</h2>
                <p>10:30:00</p>
            </Card>

            <Card>
                <h2>Japan Clock</h2>
                <p>14:00:00</p>
            </Card>

        </div>
    );

}
```

The Card component does not need to know what content it contains.

It simply renders whatever is passed through `children`.

### Understanding children

```jsx
<Card>
    <h1>Hello</h1>
    <p>Welcome to React</p>
</Card>
```

Inside Card:

```jsx
function Card({ children }) {
    return <div>{children}</div>;
}
```

The nested JSX becomes the value of `children`.

## 3.2 Benefits of Containment

1. Reusable container components.
2. Flexible layouts.
3. Less code duplication.
4. Separation of content and layout.
5. Easy customization.

---

# 4. Composition – Specialization

## 4.1 What is Specialization?

Specialization means creating a more specific component from a general component by passing different props or configuration.

Example:

Suppose we have a general Button component.

We can create specialized buttons such as:

- Primary Button
- Danger Button
- Success Button

### Example

```jsx
function Button({ children, color }) {

    return (
        <button style={{ backgroundColor: color }}>
            {children}
        </button>
    );

}
```

Now specialize it:

```jsx
function PrimaryButton({ children }) {

    return (
        <Button color="blue">
            {children}
        </Button>
    );

}

function DangerButton({ children }) {

    return (
        <Button color="red">
            {children}
        </Button>
    );

}
```

Use in App:

```jsx
function App() {

    return (
        <div>

            <PrimaryButton>
                Save
            </PrimaryButton>

            <DangerButton>
                Delete
            </DangerButton>

        </div>
    );

}
```

Here, PrimaryButton and DangerButton are specialized versions of the general Button component.

## 4.2 Containment vs. Specialization

| Containment | Specialization |
|---|---|
| Passes nested content using children | Creates specific versions of a general component |
| Focuses on containing components | Focuses on configuring components |
| Example: Card, Modal | Example: PrimaryButton, DangerButton |
| Flexible content | Specific behavior or appearance |

---

# 5. React Router

## 5.1 What is React Router?

React Router is a routing library used to navigate between different views or pages in a React application.

For example:

```text
Home
  |
  |--- About
  |
  |--- World Clock
  |
  |--- Contact
```

React Router allows us to display different components based on the URL.

### Why do we need React Router?

Suppose we are developing a World Clock application.

We may need these pages:

- Home Page
- World Clock Page
- About Page
- Clock Details Page

React Router helps manage navigation between them.

## 5.2 What is Routing?

Routing means mapping a URL path to a particular component or page.

Example:

| URL | Component |
|---|---|
| `/` | Home |
| `/clock` | Clock |
| `/about` | About |
| `/clock/India` | Clock Details |

When the URL changes, React Router renders the matching route.

---

# 6. Client-Side Routing

## 6.1 What is Client-Side Routing?

Client-side routing means navigation is handled by JavaScript in the browser without requesting a completely new HTML document for every route.

In a React SPA, React Router can change the displayed component while keeping the application loaded.

Example:

```text
User clicks About
        |
        v
React Router handles navigation
        |
        v
URL changes to /about
        |
        v
About component renders
```

## 6.2 What is SPA?

SPA stands for Single Page Application.

An SPA is a web application that loads an initial HTML document and updates its content dynamically as the user interacts with it.

Examples:
- Gmail
- Google Maps
- React applications
- Social media dashboards

### Traditional Website vs SPA

| Traditional Website | SPA |
|---|---|
| Often loads a new HTML document during navigation | Updates views in the browser |
| Navigation may trigger a full page reload | Client-side navigation can avoid full reloads |
| Server commonly returns a page for each navigation | React renders the matching component |
| Can involve more document reloads | Often provides smoother transitions |

**Important:** An SPA still communicates with servers for APIs and other resources. Client-side routing does not mean the application never makes network requests.

---

# 7. Installing React Router

For the standard React Router DOM setup used in many React projects:

```bash
npm install react-router-dom
```

Check package installation:

```bash
npm list react-router-dom
```

We will use these important components and Hooks:

| Component / Hook | Purpose |
|---|---|
| `BrowserRouter` | Enables browser-based routing |
| `Routes` | Contains route definitions |
| `Route` | Defines a URL path and its element |
| `Link` | Navigates without a full page reload |
| `NavLink` | Navigation link with active-state information |
| `useNavigate` | Navigates programmatically |
| `useParams` | Reads dynamic URL parameters |
| `Outlet` | Renders matched child routes |

---

# 8. BrowserRouter, Routes and Route

## 8.1 BrowserRouter

`BrowserRouter` is the router component that enables client-side routing using the browser History API.

Example:

```jsx
import { BrowserRouter } from "react-router-dom";

function App() {

    return (
        <BrowserRouter>
            <h1>My React Application</h1>
        </BrowserRouter>
    );

}
```

Usually, we place BrowserRouter near the root of the application.

## 8.2 Routes

`Routes` groups route definitions.

## 8.3 Route

`Route` connects a URL path with a React element.

### Example

```jsx
import {
    BrowserRouter,
    Routes,
    Route
} from "react-router-dom";

function Home() {
    return <h1>Home Page</h1>;
}

function About() {
    return <h1>About Page</h1>;
}

function Contact() {
    return <h1>Contact Page</h1>;
}

function App() {

    return (
        <BrowserRouter>

            <Routes>

                <Route path="/" element={<Home />} />

                <Route path="/about" element={<About />} />

                <Route path="/contact" element={<Contact />} />

            </Routes>

        </BrowserRouter>
    );

}

export default App;
```

### Explanation

```jsx
<Route path="/" element={<Home />} />
```

When the URL is:

```text
http://localhost:5173/
```

React Router renders the Home component.

Similarly:

```text
http://localhost:5173/about
```

Displays About.

---

# 9. Link Component

## 9.1 What is Link?

`Link` is used to navigate between routes without performing a full page reload.

Syntax:

```jsx
<Link to="/path">Link Text</Link>
```

Example:

```jsx
import { Link } from "react-router-dom";

function Home() {

    return (
        <div>

            <h1>Home Page</h1>

            <Link to="/about">
                Go to About
            </Link>

        </div>
    );

}
```

When clicked, the URL changes and React Router displays the matching component.

### Link vs HTML Anchor

| Link | HTML Anchor |
|---|---|
| Provided by React Router | Built into HTML |
| Supports client-side routing | Normally navigates through browser document loading |
| Uses `to` prop | Uses `href` attribute |
| Suitable for internal SPA navigation | Suitable for external URLs and ordinary document navigation |

Example:

```jsx
<Link to="/about">About</Link>
```

Instead of:

```html
<a href="/about">About</a>
```

---

# 10. NavLink Component

## 10.1 What is NavLink?

`NavLink` is similar to Link but provides information about whether the link is currently active.

It is useful for navigation menus.

Example:

```jsx
import { NavLink } from "react-router-dom";

function Navbar() {

    return (
        <nav>

            <NavLink to="/">
                Home
            </NavLink>

            <NavLink to="/clock">
                Clock
            </NavLink>

            <NavLink to="/about">
                About
            </NavLink>

        </nav>
    );

}

export default Navbar;
```

## 10.2 Active Link Styling

```jsx
import { NavLink } from "react-router-dom";

function Navbar() {

    return (
        <nav>

            <NavLink
                to="/"
                className={({ isActive }) =>
                    isActive ? "active" : ""
                }
            >
                Home
            </NavLink>

            <NavLink
                to="/clock"
                className={({ isActive }) =>
                    isActive ? "active" : ""
                }
            >
                Clock
            </NavLink>

        </nav>
    );

}

export default Navbar;
```

CSS:

```css
nav {
    display: flex;
    gap: 20px;
}

nav a {
    text-decoration: none;
    color: black;
}

nav a.active {
    color: blue;
    font-weight: bold;
}
```

### Link vs NavLink

| Link | NavLink |
|---|---|
| Used for navigation | Used for navigation |
| Does not provide active-state styling automatically | Provides active-state information |
| Useful for ordinary links | Useful for navigation menus |

---

# 11. useNavigate Hook

## 11.1 What is useNavigate?

`useNavigate` is a React Router Hook used for programmatic navigation.

Programmatic navigation means changing the route using JavaScript rather than clicking a Link.

Common situations:
- Redirect after login.
- Navigate after form submission.
- Navigate after adding a record.
- Return to the previous page.
- Redirect after completing an operation.

### Syntax

```jsx
const navigate = useNavigate();

navigate("/path");
```

## 11.2 Example: Navigate After Button Click

```jsx
import { useNavigate } from "react-router-dom";

function Home() {

    const navigate = useNavigate();

    function goToClock() {

        navigate("/clock");

    }

    return (
        <div>

            <h1>Home Page</h1>

            <button onClick={goToClock}>
                Open World Clock
            </button>

        </div>
    );

}

export default Home;
```

When the button is clicked, the user navigates to `/clock`.

## 11.3 Example: Navigate After Form Submission

```jsx
import { useState } from "react";
import { useNavigate } from "react-router-dom";

function Login() {

    const [username, setUsername] = useState("");

    const navigate = useNavigate();

    function handleSubmit(event) {

        event.preventDefault();

        if (username.trim() !== "") {

            navigate("/clock");

        }

    }

    return (
        <form onSubmit={handleSubmit}>

            <input
                value={username}
                onChange={event => setUsername(event.target.value)}
                placeholder="Enter username"
            />

            <button type="submit">
                Login
            </button>

        </form>
    );

}

export default Login;
```

This is only a navigation demonstration. Real authentication must validate credentials securely.

## 11.4 Navigating Back

```jsx
const navigate = useNavigate();

navigate(-1);
```

This navigates to the previous history entry when available.

---

# 12. Dynamic Routes and useParams

## 12.1 What are Dynamic Routes?

Dynamic routes are routes where part of the URL changes based on the data.

Example:

```text
/clock/India
/clock/Japan
/clock/UK
```

Instead of creating three separate route definitions, we can create one dynamic route.

```jsx
<Route path="/clock/:country" element={<ClockDetails />} />
```

Here, `:country` is a dynamic URL parameter.

## 12.2 What is useParams?

`useParams` is a React Router Hook used to access dynamic values from the current URL.

Syntax:

```jsx
const params = useParams();
```

Example:

```jsx
import { useParams } from "react-router-dom";

function ClockDetails() {

    const { country } = useParams();

    return (
        <h1>Clock Details: {country}</h1>
    );

}

export default ClockDetails;
```

Route:

```jsx
<Route
    path="/clock/:country"
    element={<ClockDetails />}
/>
```

If the user opens:

```text
/clock/India
```

Output:

```text
Clock Details: India
```

If the user opens:

```text
/clock/Japan
```

Output:

```text
Clock Details: Japan
```

## 12.3 Dynamic Route with Multiple Parameters

Example:

```jsx
<Route
    path="/clock/:country/:city"
    element={<ClockDetails />}
/>
```

Component:

```jsx
import { useParams } from "react-router-dom";

function ClockDetails() {

    const { country, city } = useParams();

    return (
        <div>

            <h1>{country}</h1>

            <h2>{city}</h2>

        </div>
    );

}

export default ClockDetails;
```

URL:

```text
/clock/India/Mumbai
```

Output:

```text
India
Mumbai
```

---

# 13. Nested Routes

## 13.1 What are Nested Routes?

Nested routes are routes defined inside another route.

They are useful when multiple pages share a common layout.

Example:

```text
Dashboard
    |
    |--- Overview
    |
    |--- Profile
    |
    |--- Settings
```

All these pages share the same Dashboard layout.

Instead of repeating the dashboard header and sidebar in every component, we can create a parent layout route.

## 13.2 Understanding Outlet

`Outlet` is a React Router component used to render the matching child route inside a parent layout.

### Example

Create DashboardLayout.jsx:

```jsx
import { Outlet, Link } from "react-router-dom";

function DashboardLayout() {

    return (
        <div>

            <h1>Dashboard</h1>

            <nav>

                <Link to="overview">Overview</Link>

                <Link to="profile">Profile</Link>

                <Link to="settings">Settings</Link>

            </nav>

            <hr />

            <Outlet />

        </div>
    );

}

export default DashboardLayout;
```

Create child components:

```jsx
function Overview() {
    return <h2>Dashboard Overview</h2>;
}

export default Overview;
```

```jsx
function Profile() {
    return <h2>User Profile</h2>;
}

export default Profile;
```

```jsx
function Settings() {
    return <h2>Dashboard Settings</h2>;
}

export default Settings;
```

Route configuration:

```jsx
import {
    BrowserRouter,
    Routes,
    Route
} from "react-router-dom";

import DashboardLayout from "./DashboardLayout";
import Overview from "./Overview";
import Profile from "./Profile";
import Settings from "./Settings";

function App() {

    return (
        <BrowserRouter>

            <Routes>

                <Route
                    path="/dashboard"
                    element={<DashboardLayout />}
                >

                    <Route
                        index
                        element={<Overview />}
                    />

                    <Route
                        path="profile"
                        element={<Profile />}
                    />

                    <Route
                        path="settings"
                        element={<Settings />}
                    />

                </Route>

            </Routes>

        </BrowserRouter>
    );

}

export default App;
```

### Understanding the URLs

| URL | Displayed component |
|---|---|
| `/dashboard` | Dashboard + Overview |
| `/dashboard/profile` | Dashboard + Profile |
| `/dashboard/settings` | Dashboard + Settings |

The parent layout remains visible while the child component changes inside Outlet.

---

# 14. Layout Routes

## 14.1 What is a Layout Route?

A layout route is a parent route that provides a common UI structure for its child routes.

Examples:
- Common Navbar
- Footer
- Sidebar
- Dashboard menu
- Header

### Example

```jsx
import { Outlet } from "react-router-dom";

function MainLayout() {

    return (
        <div>

            <header>
                <h1>My Application</h1>
            </header>

            <nav>
                Navigation Menu
            </nav>

            <main>
                <Outlet />
            </main>

            <footer>
                Footer
            </footer>

        </div>
    );

}

export default MainLayout;
```

Routes:

```jsx
<Routes>

    <Route element={<MainLayout />}>

        <Route path="/" element={<Home />} />

        <Route path="/clock" element={<Clock />} />

        <Route path="/about" element={<About />} />

    </Route>

</Routes>
```

All child routes share the same layout.

### Nested Route vs Layout Route

A layout route is a parent route used to share a UI structure. Nested routes describe the parent-child route relationship. A layout route commonly uses nested routes and `Outlet` to render the child route.

---

# 15. Thinking in React

## 15.1 What is Thinking in React?

Thinking in React is an approach to designing applications by breaking the UI into components and identifying how data flows between them.

Instead of immediately writing code, we first understand the UI and divide it into smaller reusable components.

React recommends a component-oriented way of thinking.

## 15.2 Steps for Thinking in React

### Step 1: Break the UI into Components

Consider a World Clock application.

We can divide it into:

```text
App
 |
 |--- Header
 |
 |--- Navbar
 |
 |--- ClockForm
 |
 |--- ClockContainer
 |       |
 |       |--- Clock
 |       |--- Clock
 |       |--- Clock
 |
 |--- Footer
```

Each component has a separate responsibility.

### Step 2: Build a Static Version

First create the UI without implementing dynamic behavior.

Example:

```jsx
function Clock({ country, time }) {

    return (
        <div>
            <h2>{country}</h2>
            <h1>{time}</h1>
        </div>
    );

}
```

At this stage, focus on the component structure and visual layout.

### Step 3: Identify the Minimum State

Ask:

- Which values change?
- Which values are received from props?
- Which values can be calculated?
- Which values need to be shared?

For a World Clock:

| Data | Where it belongs |
|---|---|
| Selected time zone | App state |
| List of added clocks | App state |
| Current time | Clock or custom Hook state |
| Country name | Clock props |
| Time zone | Clock props |
| AM/PM | Calculated from time-zone formatting |

### Step 4: Identify Where State Should Live

If multiple components need the same data, keep it in their nearest common parent.

For example:

```text
App
 |
 |--- ClockForm
 |
 |--- ClockContainer
         |
         |--- Clock
```

App manages the list of clocks and selected time zone.

ClockForm receives the selected value and callback functions through props.

ClockContainer receives the clock list.

### Step 5: Add Data Flow and Interactivity

Implement:

- Add Clock
- Remove Clock
- Change selected country
- Update time every second
- Navigate to clock details
- Handle errors

### Step 6: Add Routing and Error Handling

Finally:
- Add React Router.
- Create route components.
- Add Error Boundaries.
- Test navigation and invalid routes.

## 15.3 Benefits of Thinking in React

1. Better component organization.
2. Clear data flow.
3. Reusable components.
4. Less duplicated code.
5. Easier debugging.
6. Easier application maintenance.

---

# 16. Lab 1 – Implement Error Boundaries in React Clock

## Objective

Implement Error Boundaries at appropriate places in the World Clock application.

### Project structure

```text
src/
│
├── components/
│   ├── Clock.jsx
│   ├── ClockForm.jsx
│   └── ErrorBoundary.jsx
│
├── App.jsx
├── App.css
└── main.jsx
```

### Step 1: Create ErrorBoundary.jsx

```jsx
import React from "react";

class ErrorBoundary extends React.Component {

    constructor(props) {

        super(props);

        this.state = {
            hasError: false
        };

    }

    static getDerivedStateFromError() {

        return {
            hasError: true
        };

    }

    componentDidCatch(error, errorInfo) {

        console.error("Clock Error:", error);

        console.error(errorInfo);

    }

    render() {

        if (this.state.hasError) {

            return (
                <div className="error-card">

                    <h2>Clock Error</h2>

                    <p>Unable to display this clock.</p>

                    <button
                        onClick={() =>
                            this.setState({ hasError: false })
                        }
                    >
                        Try Again
                    </button>

                </div>
            );

        }

        return this.props.children;

    }

}

export default ErrorBoundary;
```

### Step 2: Use ErrorBoundary in App.jsx

```jsx
import ErrorBoundary from "./components/ErrorBoundary";
import Clock from "./components/Clock";

function App() {

    const clocks = [

        {
            id: 1,
            country: "India",
            timeZone: "Asia/Kolkata"
        },

        {
            id: 2,
            country: "UK",
            timeZone: "Europe/London"
        },

        {
            id: 3,
            country: "Japan",
            timeZone: "Asia/Tokyo"
        }

    ];

    return (
        <div>

            <h1>World Clock</h1>

            {clocks.map(clock => (

                <ErrorBoundary key={clock.id}>

                    <Clock
                        country={clock.country}
                        timeZone={clock.timeZone}
                    />

                </ErrorBoundary>

            ))}

        </div>
    );

}

export default App;
```

### Step 3: Test Error Boundary

For testing only, temporarily add this inside the Clock component:

```jsx
if (country === "Japan") {
    throw new Error("Test clock rendering error");
}
```

Expected result:

- India Clock displays normally.
- UK Clock displays normally.
- Japan Clock displays the fallback UI.

Remove the test code after verifying the Error Boundary.

**Note:** Do not use this test condition in the actual application.

---

# 17. Lab 2 – Add React Router to World Clock

## Objective

Add routing to the existing React Clock application.

Required pages:

1. Home
2. World Clock
3. About

## Step 1: Install React Router

```bash
npm install react-router-dom
```

## Step 2: Project structure

```text
src/
│
├── components/
│   ├── Navbar.jsx
│   ├── Clock.jsx
│   └── ErrorBoundary.jsx
│
├── pages/
│   ├── Home.jsx
│   ├── WorldClock.jsx
│   ├── About.jsx
│   └── NotFound.jsx
│
├── layouts/
│   └── MainLayout.jsx
│
├── App.jsx
├── App.css
└── main.jsx
```

## Step 3: Create Navbar.jsx

```jsx
import { NavLink } from "react-router-dom";

function Navbar() {

    return (
        <nav className="navbar">

            <NavLink to="/" end>
                Home
            </NavLink>

            <NavLink to="/clock">
                World Clock
            </NavLink>

            <NavLink to="/about">
                About
            </NavLink>

        </nav>
    );

}

export default Navbar;
```

## Step 4: Create MainLayout.jsx

```jsx
import { Outlet } from "react-router-dom";

import Navbar from "../components/Navbar";

function MainLayout() {

    return (
        <div>

            <header>
                <h1>World Clock Application</h1>
            </header>

            <Navbar />

            <main>
                <Outlet />
            </main>

            <footer>
                <p>React CMCE Practice Project</p>
            </footer>

        </div>
    );

}

export default MainLayout;
```

## Step 5: Create Home.jsx

```jsx
import { useNavigate } from "react-router-dom";

function Home() {

    const navigate = useNavigate();

    return (
        <div>

            <h2>Welcome to World Clock</h2>

            <p>Check time in different countries.</p>

            <button
                onClick={() => navigate("/clock")}
            >
                Open Clock
            </button>

        </div>
    );

}

export default Home;
```

## Step 6: Create WorldClock.jsx

```jsx
import Clock from "../components/Clock";
import ErrorBoundary from "../components/ErrorBoundary";

function WorldClock() {

    const clocks = [

        {
            id: 1,
            country: "India",
            timeZone: "Asia/Kolkata"
        },

        {
            id: 2,
            country: "United Kingdom",
            timeZone: "Europe/London"
        },

        {
            id: 3,
            country: "Japan",
            timeZone: "Asia/Tokyo"
        }

    ];

    return (
        <div>

            <h2>World Clock</h2>

            <div className="clock-container">

                {clocks.map(clock => (

                    <ErrorBoundary key={clock.id}>

                        <Clock
                            country={clock.country}
                            timeZone={clock.timeZone}
                        />

                    </ErrorBoundary>

                ))}

            </div>

        </div>
    );

}

export default WorldClock;
```

## Step 7: Create About.jsx

```jsx
function About() {

    return (
        <div>

            <h2>About Application</h2>

            <p>
                This application displays the current time
                in different countries.
            </p>

        </div>
    );

}

export default About;
```

## Step 8: Create NotFound.jsx

```jsx
import { Link } from "react-router-dom";

function NotFound() {

    return (
        <div>

            <h2>404 - Page Not Found</h2>

            <p>The requested page does not exist.</p>

            <Link to="/">
                Go Home
            </Link>

        </div>
    );

}

export default NotFound;
```

## Step 9: Configure Routes in App.jsx

```jsx
import {
    BrowserRouter,
    Routes,
    Route
} from "react-router-dom";

import MainLayout from "./layouts/MainLayout";

import Home from "./pages/Home";
import WorldClock from "./pages/WorldClock";
import About from "./pages/About";
import NotFound from "./pages/NotFound";

function App() {

    return (
        <BrowserRouter>

            <Routes>

                <Route element={<MainLayout />}>

                    <Route
                        path="/"
                        element={<Home />}
                    />

                    <Route
                        path="/clock"
                        element={<WorldClock />}
                    />

                    <Route
                        path="/about"
                        element={<About />}
                    />

                    <Route
                        path="*"
                        element={<NotFound />}
                    />

                </Route>

            </Routes>

        </BrowserRouter>
    );

}

export default App;
```

## Step 10: Run Application

```bash
npm run dev
```

Test these URLs:

| URL | Result |
|---|---|
| `/` | Home |
| `/clock` | World Clock |
| `/about` | About |
| `/invalid` | 404 Page |

### What did we implement?

- BrowserRouter
- Routes
- Route
- NavLink
- Link
- useNavigate
- Outlet
- Layout route
- ErrorBoundary

---

# 18. Lab 3 – useNavigate for Programmatic Navigation

## Objective

Navigate from Home to World Clock using a button.

```jsx
import { useNavigate } from "react-router-dom";

function Home() {

    const navigate = useNavigate();

    function openClock() {

        navigate("/clock");

    }

    return (
        <div>

            <h1>Home Page</h1>

            <button onClick={openClock}>
                Go to World Clock
            </button>

        </div>
    );

}

export default Home;
```

### Additional examples

Navigate to About:

```javascript
navigate("/about");
```

Go back:

```javascript
navigate(-1);
```

Go forward:

```javascript
navigate(1);
```

Replace current history entry:

```javascript
navigate("/clock", {
    replace: true
});
```

### Practical use cases

- Redirect after login.
- Navigate after adding a clock.
- Redirect after submitting a form.
- Navigate back after closing details.

---

# 19. Lab 4 – useParams for Dynamic Routes

## Objective

Create a dynamic route that displays clock details based on the country selected.

### Step 1: Create ClockDetails.jsx

```jsx
import { useParams, Link } from "react-router-dom";

const timeZones = {

    India: {
        city: "New Delhi",
        timeZone: "Asia/Kolkata"
    },

    Japan: {
        city: "Tokyo",
        timeZone: "Asia/Tokyo"
    },

    UK: {
        city: "London",
        timeZone: "Europe/London"
    }

};

function ClockDetails() {

    const { country } = useParams();

    const details = timeZones[country];

    if (!details) {

        return (
            <div>

                <h2>Country not found</h2>

                <Link to="/clock">
                    Back to World Clock
                </Link>

            </div>
        );

    }

    return (
        <div>

            <h1>{country} Clock Details</h1>

            <h2>City: {details.city}</h2>

            <h2>Time Zone: {details.timeZone}</h2>

            <Link to="/clock">
                Back to World Clock
            </Link>

        </div>
    );

}

export default ClockDetails;
```

### Step 2: Add Dynamic Route

Inside App.jsx:

```jsx
<Route
    path="/clock/:country"
    element={<ClockDetails />}
/>
```

### Step 3: Add Navigation Link from WorldClock.jsx

```jsx
import { Link } from "react-router-dom";

function ClockLinks() {

    return (
        <div>

            <Link to="/clock/India">
                India Details
            </Link>

            <Link to="/clock/Japan">
                Japan Details
            </Link>

            <Link to="/clock/UK">
                UK Details
            </Link>

        </div>
    );

}

export default ClockLinks;
```

### Test URLs

```text
/clock/India
/clock/Japan
/clock/UK
```

Expected results:

```text
India Clock Details
City: New Delhi
Time Zone: Asia/Kolkata
```

```text
Japan Clock Details
City: Tokyo
Time Zone: Asia/Tokyo
```

```text
UK Clock Details
City: London
Time Zone: Europe/London
```

---

# 20. Important React Router Comparisons

## Link vs NavLink

| Link | NavLink |
|---|---|
| Navigates between routes | Navigates between routes |
| No automatic active-state styling | Provides active-state information |
| Useful for ordinary navigation | Useful for menus |

## useNavigate vs Link

| useNavigate | Link |
|---|---|
| Programmatic navigation | Declarative navigation |
| Called inside event handlers or other logic | Rendered as an element |
| Useful after form submission | Useful for navigation menus |

## useParams vs useNavigate

| useParams | useNavigate |
|---|---|
| Reads dynamic URL parameters | Changes current route |
| Returns route parameter values | Returns navigation function |
| Example: `/clock/India` | Example: `navigate("/clock")` |

## Routes vs Route

| Routes | Route |
|---|---|
| Groups and selects matching routes | Defines an individual route |
| Contains Route elements | Specifies path and element |

## BrowserRouter vs Outlet

| BrowserRouter | Outlet |
|---|---|
| Enables browser-based routing | Renders matched child route |
| Usually wraps the application | Placed inside parent layout |

---

# 21. CCEE / Interview Questions

## Error Boundaries

1. What are Error Boundaries?
2. Why do we need Error Boundaries?
3. Which lifecycle methods are used in Error Boundaries?
4. What is getDerivedStateFromError()?
5. What is componentDidCatch()?
6. Can Error Boundaries catch event handler errors?
7. Can Error Boundaries catch Promise rejections?
8. Can we implement a built-in Error Boundary using a function component?
9. What is fallback UI?
10. Where should Error Boundaries be placed?

## Composition and Inheritance

11. What is component composition?
12. What is inheritance?
13. Why does React prefer composition?
14. What is containment?
15. What is specialization?
16. What is the children prop?
17. Give examples of reusable container components.
18. What is the difference between composition and inheritance?

## React Router

19. What is React Router?
20. What is routing?
21. What is client-side routing?
22. What is an SPA?
23. What is BrowserRouter?
24. What is Routes?
25. What is Route?
26. What is the difference between Link and NavLink?
27. What is useNavigate?
28. What is useParams?
29. What are dynamic routes?
30. What are nested routes?
31. What is Outlet?
32. What are layout routes?
33. How do you implement a 404 page?
34. What is the difference between useNavigate and Link?
35. What is the purpose of the `index` route?

## Thinking in React

36. What is Thinking in React?
37. How do you break a UI into components?
38. How do you identify state?
39. Where should shared state be stored?
40. Why is component reusability important?

---

# 22. MCQs – CCEE Practice

**1. Which lifecycle method updates Error Boundary state after a descendant error?**

A. componentDidMount()  
B. getDerivedStateFromError()  
C. componentWillUnmount()  
D. renderError()  

**Answer: B. getDerivedStateFromError()**

**2. Which method is useful for logging Error Boundary details?**

A. componentDidCatch()  
B. componentDidMount()  
C. getSnapshotBeforeUpdate()  
D. shouldComponentUpdate()  

**Answer: A. componentDidCatch()**

**3. Can an Error Boundary catch an event handler error?**

A. Yes  
B. No  
C. Only in production  
D. Only with useEffect  

**Answer: B. No**

**4. Which approach is preferred for component reuse in React?**

A. Inheritance  
B. Composition  
C. Global variables  
D. Direct DOM manipulation  

**Answer: B. Composition**

**5. Which prop is used to pass nested JSX into a component?**

A. value  
B. children  
C. key  
D. ref  

**Answer: B. children**

**6. Which library is commonly used for React client-side routing?**

A. Express  
B. React Router  
C. Axios  
D. Redux  

**Answer: B. React Router**

**7. Which component enables browser-based routing?**

A. Routes  
B. Route  
C. BrowserRouter  
D. Outlet  

**Answer: C. BrowserRouter**

**8. Which component defines an individual route?**

A. Route  
B. Link  
C. NavLink  
D. Outlet  

**Answer: A. Route**

**9. Which component is used for normal client-side navigation?**

A. Anchor  
B. Link  
C. Button  
D. Form  

**Answer: B. Link**

**10. Which component provides active-state information?**

A. Link  
B. NavLink  
C. Route  
D. Outlet  

**Answer: B. NavLink**

**11. Which Hook performs programmatic navigation?**

A. useParams  
B. useNavigate  
C. useState  
D. useRef  

**Answer: B. useNavigate**

**12. Which Hook reads dynamic route parameters?**

A. useNavigate  
B. useParams  
C. useEffect  
D. useMemo  

**Answer: B. useParams**

**13. Which component renders matched child routes?**

A. BrowserRouter  
B. Outlet  
C. Link  
D. NavLink  

**Answer: B. Outlet**

**14. What is an SPA?**

A. Single Page Application  
B. Server Program Application  
C. Simple Programming Architecture  
D. Single Process Application  

**Answer: A. Single Page Application**

**15. Which route is commonly used for a 404 page?**

A. `/`  
B. `*`  
C. `/home`  
D. `:id`  

**Answer: B. `*`**

---

# 23. Quick Revision Notes

| Topic | Key point |
|---|---|
| Error Boundary | Catches descendant rendering errors |
| getDerivedStateFromError | Updates fallback state |
| componentDidCatch | Logs error information |
| Composition | Combines reusable components |
| Inheritance | Derives from a parent class |
| Containment | Uses children to pass nested content |
| Specialization | Creates specific versions of general components |
| React Router | Manages navigation |
| SPA | Single Page Application |
| BrowserRouter | Enables browser routing |
| Routes | Groups route definitions |
| Route | Defines a route |
| Link | Client-side navigation |
| NavLink | Navigation with active-state information |
| useNavigate | Programmatic navigation |
| useParams | Reads URL parameters |
| Outlet | Renders nested child routes |
| Layout Route | Shares common UI structure |
| Thinking in React | Component-oriented UI design |

---

# 24. Self-Learning Assignments

1. Create an Error Boundary for a Student component.
2. Create a fallback UI with a Retry button.
3. Build a reusable Card component using containment.
4. Create PrimaryButton and DangerButton using specialization.
5. Create a React application with Home, About and Contact pages.
6. Add React Router to your existing World Clock application.
7. Create a navigation bar using NavLink.
8. Navigate programmatically after form submission using useNavigate.
9. Create dynamic routes using country names.
10. Use useParams to display country and city details.
11. Create a Dashboard with nested routes.
12. Implement a shared layout using Outlet.
13. Create a 404 Not Found page.
14. Draw the component hierarchy of your World Clock application.

---

# 25. Practical Checklist

- [ ] Understand Error Boundaries.
- [ ] Implement getDerivedStateFromError().
- [ ] Implement componentDidCatch().
- [ ] Create fallback UI.
- [ ] Understand Error Boundary limitations.
- [ ] Understand composition and inheritance.
- [ ] Implement containment using children.
- [ ] Implement specialization using props.
- [ ] Install React Router.
- [ ] Configure BrowserRouter.
- [ ] Implement Routes and Route.
- [ ] Navigate using Link.
- [ ] Highlight active links using NavLink.
- [ ] Implement useNavigate.
- [ ] Implement dynamic routes.
- [ ] Read parameters using useParams.
- [ ] Implement nested routes.
- [ ] Implement Outlet and layout routes.
- [ ] Create a 404 page.
- [ ] Apply Thinking in React to the Clock application.

---

# 26. Recommended References

### Books

1. **React in Depth** – Morten Barklund, O'Reilly, 2024.
2. **JavaScript: The Definitive Guide, 7th Edition** – David Flanagan, O'Reilly.

### Official Documentation

**React:**

- Error Boundaries: https://react.dev/reference/react/Component
- Composition and Children: https://react.dev/learn/passing-props-to-a-component
- Thinking in React: https://react.dev/learn/thinking-in-react

**React Router:**

- Main Documentation: https://reactrouter.com/
- BrowserRouter: https://reactrouter.com/api/declarative-routers/BrowserRouter
- Routes: https://reactrouter.com/api/components/Routes
- Route: https://reactrouter.com/api/components/Route
- Link: https://reactrouter.com/api/components/Link
- NavLink: https://reactrouter.com/api/components/NavLink
- useNavigate: https://reactrouter.com/api/hooks/useNavigate
- useParams: https://reactrouter.com/api/hooks/useParams
- Outlet: https://reactrouter.com/api/components/Outlet

**Final study tip:** Understand the difference between Link and useNavigate, and between Link and NavLink. Practise useParams with dynamic country URLs and Outlet with nested routes. These are particularly important concepts for practical assignments and CCEE questions.
