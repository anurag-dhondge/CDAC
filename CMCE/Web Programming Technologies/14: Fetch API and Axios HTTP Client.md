# Session 14 – Fetch API and Axios HTTP Client

**Course:** CMCE – August 2026 Batch  
**Subject:** Web Programming Technologies

## 1. Introduction to HTTP Requests

Modern web applications communicate with servers to exchange information.

For example:
- A weather application fetches weather information from a server.
- A shopping application fetches product details.
- A login page sends username and password to a backend.
- A news application fetches the latest headlines from a news API.

This communication generally happens through **HTTP (Hypertext Transfer Protocol)**.

### How API communication works

1. The client sends an HTTP request to a server.
2. The server processes the request.
3. The server sends an HTTP response.
4. The client receives and displays the response.

**Example:**

A user opens a news application.

```text
Frontend Application
        |
        | HTTP GET Request
        v
News API Server
        |
        | JSON Response
        v
Frontend Application
        |
        v
Display News Headlines
```

### What is an API?

API stands for Application Programming Interface.

An API allows two software applications to communicate with each other.

For example:

```text
Frontend (React)
       |
       | API Request
       v
Backend (Node.js)
       |
       v
Database (MySQL)
```

The frontend does not directly need to know how the backend stores or processes the information. It communicates through API endpoints.

Example API endpoint:

```text
https://jsonplaceholder.typicode.com/users
```

---

# Part A – Fetch API

## 2. What is the Fetch API?

The Fetch API is a built-in JavaScript API used to make HTTP requests and retrieve resources from servers.

It allows developers to:
- Retrieve data from APIs.
- Send data to servers.
- Upload information.
- Handle HTTP responses.
- Work with JSON data.
- Cancel HTTP requests.

Fetch returns a **Promise**.

### Syntax

```javascript
fetch(url, options)
    .then(response => {
        // Handle response
    })
    .catch(error => {
        // Handle network errors
    });
```

Parameters:

| Parameter | Description |
|---|---|
| `url` | API endpoint or resource URL |
| `options` | Optional request configuration |

Example:

```javascript
fetch("https://jsonplaceholder.typicode.com/users")
    .then(response => response.json())
    .then(data => console.log(data))
    .catch(error => console.log(error));
```

### Important point

Fetch is already available in modern browsers. You do not need to install an external package to use it.

---

## 3. Request and Response

HTTP communication involves two important objects:

1. Request
2. Response

### 3.1 Request

A Request represents an HTTP request that is sent to a server.

It contains information such as:
- URL
- HTTP method
- Headers
- Request body
- Cache settings
- Credentials settings

Example:

```javascript
const request = new Request(
    "https://jsonplaceholder.typicode.com/users",
    {
        method: "GET"
    }
);

fetch(request)
    .then(response => response.json())
    .then(data => console.log(data));
```

### 3.2 Response

A Response represents the response received from the server.

Important Response properties:

| Property | Description |
|---|---|
| `status` | HTTP status code |
| `statusText` | Status description |
| `ok` | True when status is in the 200–299 range |
| `headers` | Response headers |
| `url` | Response URL |
| `body` | Response body stream |
| `redirected` | Indicates whether a redirect occurred |

Example:

```javascript
fetch("https://jsonplaceholder.typicode.com/users")
    .then(response => {
        console.log(response.status);
        console.log(response.statusText);
        console.log(response.ok);

        return response.json();
    })
    .then(data => console.log(data));
```

Possible output:

```text
200
OK
true
```

### Request vs Response

| Request | Response |
|---|---|
| Sent by client | Received from server |
| Contains request details | Contains response details |
| Includes method and request headers | Includes status and response headers |
| May contain a request body | Contains a response body |

---

## 4. HTTP Headers

Headers provide additional information about an HTTP request or response.

They describe how information should be sent, received, or interpreted.

### Common HTTP Headers

| Header | Purpose |
|---|---|
| `Content-Type` | Specifies the format of the request or response body |
| `Accept` | Specifies the response format the client accepts |
| `Authorization` | Sends authentication credentials or tokens |
| `Cache-Control` | Controls caching |
| `User-Agent` | Identifies the client software |

### Example: Sending Headers

```javascript
fetch("https://api.example.com/users", {
    method: "GET",
    headers: {
        "Accept": "application/json",
        "Authorization": "Bearer YOUR_TOKEN"
    }
})
.then(response => response.json())
.then(data => console.log(data))
.catch(error => console.error(error));
```

### Using the Headers object

```javascript
const headers = new Headers();

headers.append("Content-Type", "application/json");
headers.append("Accept", "application/json");

console.log(headers.get("Content-Type"));
```

Output:

```text
application/json
```

### Why are headers important?

1. They specify the content format.
2. They support authentication.
3. They help control caching.
4. They communicate client and server preferences.

---

## 5. GET and POST Methods

HTTP methods define what action the client wants the server to perform.

Two commonly used methods are GET and POST.

### 5.1 GET Method

GET is used to retrieve data from a server.

Example:

```javascript
fetch("https://jsonplaceholder.typicode.com/users")
    .then(response => response.json())
    .then(data => console.log(data))
    .catch(error => console.error(error));
```

GET characteristics:
- Retrieves information.
- Usually does not contain a request body.
- Can be cached.
- Should not modify server data.

### 5.2 POST Method

POST is used to send data to a server.

Example:

```javascript
const user = {
    name: "Anurag",
    email: "anurag@example.com"
};

fetch("https://jsonplaceholder.typicode.com/users", {
    method: "POST",

    headers: {
        "Content-Type": "application/json"
    },

    body: JSON.stringify(user)
})
.then(response => response.json())
.then(data => console.log(data))
.catch(error => console.error(error));
```

Explanation:

- `method`: Specifies the HTTP method.
- `headers`: Specifies the content format.
- `JSON.stringify()`: Converts a JavaScript object into a JSON string.
- `body`: Contains the data sent to the server.

### GET vs POST

| GET | POST |
|---|---|
| Retrieves data | Sends data |
| Normally has no request body | Usually contains a request body |
| Parameters may appear in URL | Data is commonly sent in the body |
| Generally safe and idempotent | Not necessarily safe or idempotent |
| Can be cached | Not normally cached by default |

Other HTTP methods:

| Method | Purpose |
|---|---|
| GET | Retrieve data |
| POST | Create or submit data |
| PUT | Replace a resource |
| PATCH | Partially update a resource |
| DELETE | Delete a resource |

---

## 6. JSON with Fetch API

JSON stands for JavaScript Object Notation.

It is a lightweight data-interchange format used to exchange information between applications.

Example JSON:

```json
{
    "id": 1,
    "name": "Anurag",
    "course": "CMCE",
    "technology": "JavaScript"
}
```

### Reading JSON using Fetch

```javascript
fetch("https://jsonplaceholder.typicode.com/users/1")
    .then(response => response.json())
    .then(user => {
        console.log(user.name);
        console.log(user.email);
    });
```

### Important JSON methods

| Method | Purpose |
|---|---|
| `JSON.parse()` | Converts JSON string into a JavaScript value |
| `JSON.stringify()` | Converts a JavaScript value into a JSON string |
| `response.json()` | Reads the response body and parses JSON |

Example:

```javascript
const user = {
    name: "Anurag",
    course: "CMCE"
};

const jsonString = JSON.stringify(user);

console.log(jsonString);

const object = JSON.parse(jsonString);

console.log(object.name);
```

Output:

```text
{"name":"Anurag","course":"CMCE"}
Anurag
```

**Important:** `response.json()` is asynchronous and returns a Promise.

---

## 7. AbortController

AbortController is a JavaScript feature used to cancel ongoing asynchronous operations, including Fetch requests.

### Why do we need AbortController?

Imagine a user searches for news headlines.

1. The user searches for "Technology".
2. A request is sent to the server.
3. Before the request completes, the user searches for "Sports".
4. The previous request may no longer be useful.

AbortController allows us to cancel the earlier request.

### Syntax

```javascript
const controller = new AbortController();

fetch(url, {
    signal: controller.signal
});

controller.abort();
```

### Example

```javascript
const controller = new AbortController();

fetch("https://jsonplaceholder.typicode.com/users", {
    signal: controller.signal
})
.then(response => response.json())
.then(data => console.log(data))
.catch(error => {
    if (error.name === "AbortError") {
        console.log("Request was cancelled");
    } else {
        console.log("Error:", error);
    }
});

// Cancel the request
controller.abort();
```

### Important methods and properties

| Name | Description |
|---|---|
| `AbortController()` | Creates an abort controller |
| `controller.signal` | Provides the signal to the request |
| `controller.abort()` | Cancels the operation |
| `AbortSignal` | Represents the cancellation signal |

### Timeout using AbortController

```javascript
const controller = new AbortController();

const timeoutId = setTimeout(() => {
    controller.abort();
}, 5000);

fetch("https://jsonplaceholder.typicode.com/users", {
    signal: controller.signal
})
.then(response => response.json())
.then(data => console.log(data))
.catch(error => {
    if (error.name === "AbortError") {
        console.log("Request timed out or was cancelled");
    }
})
.finally(() => {
    clearTimeout(timeoutId);
});
```

This example cancels the request after five seconds if it has not completed.

---

## 8. Error Handling in Fetch API

Error handling is important because API requests may fail for several reasons.

Possible reasons:
- No internet connection.
- Server is unavailable.
- Invalid API endpoint.
- Authentication failure.
- Server returns an HTTP error.
- Request is cancelled.

### Important concept: Fetch does not reject for HTTP error status codes

For example, Fetch normally resolves its Promise even if the server returns:

- 400 – Bad Request
- 401 – Unauthorized
- 404 – Not Found
- 500 – Internal Server Error

Therefore, we must manually check `response.ok`.

### Correct error handling example

```javascript
fetch("https://jsonplaceholder.typicode.com/users")
    .then(response => {

        if (!response.ok) {
            throw new Error(
                `HTTP Error: ${response.status}`
            );
        }

        return response.json();
    })
    .then(data => {
        console.log("Users:", data);
    })
    .catch(error => {
        console.error("Error:", error.message);
    });
```

### Using async/await

```javascript
async function getUsers() {

    try {

        const response = await fetch(
            "https://jsonplaceholder.typicode.com/users"
        );

        if (!response.ok) {
            throw new Error(
                `HTTP Error: ${response.status}`
            );
        }

        const data = await response.json();

        console.log(data);

    } catch (error) {

        console.error("Failed to fetch users:", error);

    }
}

getUsers();
```

### Important error-handling concepts

| Concept | Purpose |
|---|---|
| `try` | Contains code that may fail |
| `catch` | Handles errors |
| `throw` | Creates and throws an error |
| `finally` | Executes whether the operation succeeds or fails |
| `response.ok` | Checks whether the HTTP response is successful |

---

# Part B – Axios HTTP Client

## 9. What is Axios?

Axios is a promise-based HTTP client used to make HTTP requests from browsers and Node.js.

It simplifies communication between frontend and backend applications.

Axios provides:
- GET, POST, PUT, PATCH and DELETE requests.
- Automatic JSON response transformation.
- Request and response interceptors.
- Request timeout configuration.
- Error handling.
- Request cancellation.
- Custom Axios instances.

### Installing Axios

For a Node.js or React project:

```bash
npm install axios
```

For TypeScript:

```bash
npm install axios
```

Axios already includes TypeScript type definitions, so a separate `@types/axios` installation is not required.

### Importing Axios

```javascript
import axios from "axios";
```

### Basic GET request

```javascript
import axios from "axios";

axios.get("https://jsonplaceholder.typicode.com/users")
    .then(response => {
        console.log(response.data);
    })
    .catch(error => {
        console.log(error);
    });
```

**Important:** Axios provides the response data directly through `response.data`.

---

## 10. Axios Instance and Its Configuration

An Axios instance is a customized Axios object created using `axios.create()`.

It allows us to define common configurations for multiple API requests.

### Why do we need Axios instances?

Suppose an application communicates with the same backend repeatedly.

Without an instance, we may need to write the base URL and common headers in every request.

With an Axios instance, we can define them once.

### Syntax

```javascript
const api = axios.create({
    baseURL: "https://api.example.com",
    timeout: 5000,
    headers: {
        "Content-Type": "application/json"
    }
});
```

### Important configuration properties

| Configuration | Description |
|---|---|
| `baseURL` | Common base URL for requests |
| `timeout` | Maximum request duration in milliseconds |
| `headers` | Default HTTP headers |
| `params` | URL query parameters |
| `data` | Request body |
| `withCredentials` | Controls whether cross-origin credentials are included |
| `responseType` | Expected response type |

### Example

```javascript
import axios from "axios";

const api = axios.create({

    baseURL: "https://jsonplaceholder.typicode.com",

    timeout: 5000,

    headers: {
        "Content-Type": "application/json"
    }

});

// GET request
api.get("/users")
    .then(response => console.log(response.data));
```

Here, Axios automatically combines:

```text
Base URL:
https://jsonplaceholder.typicode.com

Endpoint:
/users

Final URL:
https://jsonplaceholder.typicode.com/users
```

### Request-specific configuration

You can also override configuration for an individual request.

```javascript
api.get("/users", {
    timeout: 10000,
    params: {
        id: 1
    }
});
```

---

## 11. Handling Requests and Responses in Axios

Axios supports different HTTP methods.

### 11.1 GET Request

Used to retrieve information.

```javascript
axios.get("https://jsonplaceholder.typicode.com/users")
    .then(response => {
        console.log(response.data);
    });
```

### 11.2 POST Request

Used to send information to the server.

```javascript
const user = {
    name: "Anurag",
    email: "anurag@example.com"
};

axios.post(
    "https://jsonplaceholder.typicode.com/users",
    user
)
.then(response => {
    console.log(response.data);
});
```

Unlike Fetch, Axios automatically serializes ordinary JavaScript objects into JSON request bodies when appropriate.

### 11.3 PUT Request

Used to replace an existing resource.

```javascript
axios.put(
    "https://jsonplaceholder.typicode.com/users/1",
    {
        name: "Anurag Updated",
        email: "updated@example.com"
    }
)
.then(response => console.log(response.data));
```

### 11.4 PATCH Request

Used to partially update an existing resource.

```javascript
axios.patch(
    "https://jsonplaceholder.typicode.com/users/1",
    {
        name: "Updated Name"
    }
)
.then(response => console.log(response.data));
```

### 11.5 DELETE Request

Used to delete a resource.

```javascript
axios.delete(
    "https://jsonplaceholder.typicode.com/users/1"
)
.then(response => console.log(response.data));
```

### Axios Response Object

Axios returns a response object containing several properties.

| Property | Description |
|---|---|
| `data` | Response data |
| `status` | HTTP status code |
| `statusText` | HTTP status description |
| `headers` | Response headers |
| `config` | Request configuration |
| `request` | Underlying request object |

Example:

```javascript
axios.get("https://jsonplaceholder.typicode.com/users/1")
    .then(response => {

        console.log(response.data);
        console.log(response.status);
        console.log(response.headers);

    });
```

**Remember:** The actual API data is usually available in `response.data`.

---

## 12. Axios Error Handling

Axios automatically rejects its Promise for unsuccessful HTTP status codes by default.

For example:
- 400 – Bad Request
- 401 – Unauthorized
- 404 – Not Found
- 500 – Internal Server Error

### Basic error handling

```javascript
axios.get("https://jsonplaceholder.typicode.com/invalid")
    .then(response => {
        console.log(response.data);
    })
    .catch(error => {
        console.log("Something went wrong");
    });
```

### Detailed error handling

Axios errors can be categorized into three situations.

**1. Server responded with an error status**

```javascript
if (error.response) {
    console.log(error.response.status);
    console.log(error.response.data);
}
```

**2. Request was sent but no response was received**

```javascript
else if (error.request) {
    console.log("No response received from server");
}
```

**3. Error occurred while setting up the request**

```javascript
else {
    console.log("Error:", error.message);
}
```

### Complete example

```javascript
import axios from "axios";

async function getUsers() {

    try {

        const response = await axios.get(
            "https://jsonplaceholder.typicode.com/users"
        );

        console.log(response.data);

    } catch (error) {

        if (axios.isAxiosError(error)) {

            if (error.response) {

                console.log(
                    "Server Error:",
                    error.response.status
                );

            } else if (error.request) {

                console.log(
                    "No response received"
                );

            } else {

                console.log(error.message);

            }

        } else {

            console.log("Unexpected error");

        }
    }
}

getUsers();
```

### Fetch vs Axios Error Handling

| Fetch | Axios |
|---|---|
| Does not reject for HTTP 404 or 500 by default | Rejects for unsuccessful status codes by default |
| Requires manual `response.ok` checking | Uses catch for unsuccessful HTTP status codes |
| Network errors reject the Promise | Network errors reject the Promise |
| Cancellation uses AbortController | Supports AbortController through its `signal` configuration |

---

## 13. Axios Interceptors

Interceptors allow us to execute common logic before requests are sent or after responses are received.

There are two main types:

1. Request interceptor
2. Response interceptor

### Request Interceptor

Runs before an HTTP request is sent.

Common uses:
- Adding authentication tokens.
- Adding common headers.
- Logging outgoing requests.

Example:

```javascript
import axios from "axios";

const api = axios.create({
    baseURL: "https://api.example.com"
});

api.interceptors.request.use(
    config => {

        config.headers.Authorization =
            "Bearer YOUR_TOKEN";

        return config;

    },
    error => {
        return Promise.reject(error);
    }
);
```

### Response Interceptor

Runs when a response is received.

Common uses:
- Logging responses.
- Handling common errors.
- Managing authentication failures.

Example:

```javascript
api.interceptors.response.use(

    response => {
        return response;
    },

    error => {

        if (error.response?.status === 401) {
            console.log("Unauthorized access");
        }

        return Promise.reject(error);
    }

);
```

### Advantages of Interceptors

- Avoid repeated code.
- Centralize authentication.
- Handle common API errors.
- Improve code organization.

---

## 14. Request Cancellation in Axios

Axios supports request cancellation using AbortController.

Example:

```javascript
import axios from "axios";

const controller = new AbortController();

axios.get(
    "https://jsonplaceholder.typicode.com/users",
    {
        signal: controller.signal
    }
)
.then(response => {
    console.log(response.data);
})
.catch(error => {

    if (axios.isCancel(error)) {
        console.log("Request cancelled");
    } else {
        console.log(error.message);
    }

});

// Cancel request
controller.abort();
```

Axios also supports `AbortSignal` and integrates with modern JavaScript cancellation patterns.

---

# Part C – Fetch API vs Axios

## 15. Important Differences

| Feature | Fetch API | Axios |
|---|---|---|
| Type | Built-in browser API | Third-party library |
| Installation | Not required in browsers | Requires installation |
| Promise-based | Yes | Yes |
| JSON handling | Use `response.json()` | Automatically transforms JSON responses |
| HTTP error handling | Check `response.ok` manually | Rejects unsuccessful status codes by default |
| Request configuration | Options object | Axios configuration object |
| Interceptors | Not built in | Supported |
| Timeout | Usually implemented using AbortController | Built-in `timeout` configuration |
| Cancellation | AbortController | AbortController supported |
| Request and response transformation | Manual or custom | Built-in transformation support |

### When should you use Fetch?

- Small applications.
- Simple API requests.
- When you do not want external dependencies.
- When native browser APIs are sufficient.

### When should you use Axios?

- Larger applications.
- Applications with multiple API endpoints.
- Applications requiring common headers and interceptors.
- Applications requiring centralized API configuration.
- Projects that benefit from Axios's request and response handling.

---

# Part D – Practical Lab

# 16. Live News Headlines Using Axios with Typed TypeScript API Response

## Objective

Develop a web application that fetches live news headlines from a news API using Axios and TypeScript.

### Requirements

The application should:
1. Connect to a news API.
2. Retrieve the latest news headlines.
3. Use Axios for HTTP communication.
4. Define TypeScript interfaces for API responses.
5. Display news titles.
6. Display descriptions and images.
7. Display news source and publication date.
8. Handle loading and error states.

## 16.1 Application Architecture

```text
          React Frontend
                |
                | Axios Request
                v
        Node.js / Express
                |
                | API Request
                v
             News API
                |
                | JSON Response
                v
        Node.js / Express
                |
                | JSON Response
                v
          React Frontend
                |
                v
        Display News Headlines
```

**Why use a backend proxy?**

The News API key should not be exposed in frontend code. The backend stores the API key and communicates with the external news service.

## 16.2 Technologies Required

| Technology | Purpose |
|---|---|
| React | Frontend development |
| TypeScript | Static type checking |
| Axios | HTTP communication |
| Node.js | JavaScript runtime |
| Express.js | Backend API |
| News API | News data provider |
| HTML/CSS | Structure and styling |

## 16.3 Step 1 – Create React + TypeScript Project

Create a project using Vite.

```bash
npm create vite@latest live-news -- --template react-ts
```

Move into the project:

```bash
cd live-news
```

Install dependencies:

```bash
npm install
```

Install Axios:

```bash
npm install axios
```

Start the frontend:

```bash
npm run dev
```

## 16.4 Step 2 – Create Backend

Create a separate backend folder.

```bash
mkdir backend
cd backend
npm init -y
```

Install packages:

```bash
npm install express axios cors dotenv
```

Install TypeScript development dependencies if you want a TypeScript backend:

```bash
npm install -D typescript tsx @types/node @types/express @types/cors
```

For the example below, the backend uses JavaScript for simplicity.

Create `.env`:

```env
NEWS_API_KEY=YOUR_NEWS_API_KEY
PORT=5000
```

Create `server.js`:

```javascript
const express = require("express");
const axios = require("axios");
const cors = require("cors");
require("dotenv").config();

const app = express();

app.use(cors());
app.use(express.json());

app.get("/api/news", async (req, res) => {

    try {

        const response = await axios.get(
            "https://newsapi.org/v2/top-headlines",
            {
                params: {
                    country: "in",
                    apiKey: process.env.NEWS_API_KEY
                }
            }
        );

        res.json(response.data);

    } catch (error) {

        console.error(
            "News API Error:",
            error.response?.data || error.message
        );

        res.status(500).json({
            message: "Unable to fetch news"
        });

    }

});

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
```

Run backend:

```bash
node server.js
```

Backend endpoint:

```text
http://localhost:5000/api/news
```

**Note:** Obtain an API key from the News API provider and check its current plan, availability, and usage restrictions. The example uses the top-headlines endpoint. The API may restrict development or localhost usage depending on the plan.

Also add `.env` to `.gitignore`:

```text
node_modules/
.env
```

Never upload your real API key to GitHub.

## 16.5 Step 3 – Define TypeScript Interfaces

Create:

```text
src/types/news.ts
```

An interface defines the structure of an object in TypeScript.

```typescript
export interface NewsSource {
    id: string | null;
    name: string;
}

export interface NewsArticle {
    source: NewsSource;
    author: string | null;
    title: string;
    description: string | null;
    url: string;
    urlToImage: string | null;
    publishedAt: string;
    content: string | null;
}

export interface NewsApiResponse {
    status: string;
    totalResults: number;
    articles: NewsArticle[];
}
```

### Understanding the interfaces

**NewsSource**

Contains information about the news publisher.

**NewsArticle**

Contains information about an individual news article.

**NewsApiResponse**

Represents the complete response returned by the news API.

Why do we use TypeScript interfaces?

- They define expected data structures.
- They improve code readability.
- They provide compile-time type checking.
- They improve editor autocomplete.
- They help detect type-related mistakes.

## 16.6 Step 4 – Create Axios Instance

Create:

```text
src/services/api.ts
```

```typescript
import axios from "axios";

const api = axios.create({

    baseURL: "http://localhost:5000/api",

    timeout: 10000,

    headers: {
        "Content-Type": "application/json"
    }

});

export default api;
```

This instance contains the common configuration for API requests.

## 16.7 Step 5 – Fetch News Using Axios

Create:

```text
src/services/newsService.ts
```

```typescript
import axios from "axios";

import api from "./api";

import type { NewsApiResponse } from "../types/news";

export const getNews = async (): Promise<NewsApiResponse> => {

    try {

        const response = await api.get<NewsApiResponse>(
            "/news"
        );

        return response.data;

    } catch (error) {

        if (axios.isAxiosError(error)) {
            throw new Error(
                error.response?.data?.message ||
                error.message
            );
        }

        throw new Error("Something went wrong");

    }

};
```

### Important TypeScript concept

```typescript
api.get<NewsApiResponse>("/news");
```

Here, `NewsApiResponse` tells TypeScript what type of response data we expect.

```typescript
Promise<NewsApiResponse>
```

This specifies that the asynchronous function returns a Promise resolving to a `NewsApiResponse`.

**Important:** TypeScript types provide compile-time checking. They do not automatically validate the actual JSON received from an external server at runtime.

## 16.8 Step 6 – Create News Component

Open:

```text
src/App.tsx
```

Add the following code:

```tsx
import { useEffect, useState } from "react";

import { getNews } from "./services/newsService";

import type { NewsArticle } from "./types/news";

function App() {

    const [articles, setArticles] =
        useState<NewsArticle[]>([]);

    const [loading, setLoading] =
        useState<boolean>(true);

    const [error, setError] =
        useState<string>("");

    useEffect(() => {

        const fetchNews = async () => {

            try {

                setLoading(true);
                setError("");

                const data = await getNews();

                setArticles(data.articles);

            } catch (err) {

                setError(
                    err instanceof Error
                        ? err.message
                        : "Unable to fetch news"
                );

            } finally {

                setLoading(false);

            }

        };

        fetchNews();

    }, []);

    if (loading) {
        return <h2>Loading news...</h2>;
    }

    if (error) {
        return <h2>Error: {error}</h2>;
    }

    return (

        <div className="container">

            <h1>Live News Headlines</h1>

            <div className="news-container">

                {articles.map((article, index) => (

                    <div className="news-card" key={article.url || index}>

                        {article.urlToImage && (

                            <img
                                src={article.urlToImage}
                                alt={article.title}
                            />

                        )}

                        <h3>{article.title}</h3>

                        <p>
                            {article.description}
                        </p>

                        <small>
                            Source: {article.source.name}
                        </small>

                        <p>
                            Published: {
                                new Date(
                                    article.publishedAt
                                ).toLocaleString()
                            }
                        </p>

                        <a
                            href={article.url}
                            target="_blank"
                            rel="noreferrer"
                        >
                            Read More
                        </a>

                    </div>

                ))}

            </div>

        </div>

    );

}

export default App;
```

## 16.9 Step 7 – Add CSS

Open:

```text
src/index.css
```

```css
body {
    margin: 0;
    font-family: Arial, sans-serif;
    background: #f4f4f4;
}

.container {
    width: 90%;
    margin: auto;
    padding: 20px;
}

h1 {
    text-align: center;
}

.news-container {
    display: grid;
    grid-template-columns: repeat(
        auto-fit,
        minmax(280px, 1fr)
    );
    gap: 20px;
}

.news-card {
    background: white;
    padding: 15px;
    border-radius: 10px;
    box-shadow: 0 2px 8px rgba(0, 0, 0, 0.1);
}

.news-card img {
    width: 100%;
    height: 180px;
    object-fit: cover;
    border-radius: 8px;
}

.news-card a {
    display: inline-block;
    margin-top: 10px;
    color: blue;
    text-decoration: none;
}
```

## 16.10 Step 8 – Run the Application

Start the backend:

```bash
cd backend
node server.js
```

Start the frontend in another terminal:

```bash
cd live-news
npm run dev
```

Open the Vite URL in your browser.

Expected application flow:

1. The user opens the application.
2. React calls `getNews()`.
3. Axios sends a request to the Express backend.
4. Express calls the News API.
5. The News API returns JSON data.
6. Express forwards the response.
7. Axios receives the response.
8. TypeScript types describe the expected response.
9. React displays the headlines.

## 16.11 Expected Output

The application should display:

- News headline
- News image, if available
- News description
- Publisher name
- Publication date
- Read More link

It should also display loading and error messages when appropriate.

## 16.12 Lab Learning Outcomes

After completing this practical, you should be able to:

1. Create a React + TypeScript application.
2. Install and configure Axios.
3. Create an Axios instance.
4. Define TypeScript interfaces for API responses.
5. Make asynchronous API requests.
6. Handle API errors.
7. Display JSON data in React.
8. Connect a frontend application with a backend API.
9. Protect API keys using environment variables and a backend proxy.

---

# Part E – Important CCEE and Interview Questions

## 17. Frequently Asked Theory Questions

**Q1. What is Fetch API?**

Fetch API is a built-in JavaScript API used to make HTTP requests and communicate with servers.

**Q2. What is Axios?**

Axios is a promise-based HTTP client used to make HTTP requests from browsers and Node.js.

**Q3. What is a Promise?**

A Promise represents the eventual completion or failure of an asynchronous operation.

**Q4. What is the difference between Request and Response?**

Request represents the information sent by the client, whereas Response represents the information returned by the server.

**Q5. What are HTTP headers?**

HTTP headers provide additional information about an HTTP request or response.

**Q6. What is the purpose of GET?**

GET is used to retrieve information from a server.

**Q7. What is the purpose of POST?**

POST is used to send information to a server.

**Q8. What is JSON?**

JSON is a lightweight data-interchange format used to exchange information between applications.

**Q9. What is AbortController?**

AbortController is used to cancel ongoing asynchronous operations such as Fetch requests.

**Q10. Does Fetch automatically throw an error for HTTP 404?**

No. Fetch normally resolves for HTTP error responses. We must check `response.ok`.

**Q11. Why do we use Axios instances?**

Axios instances allow us to configure common settings such as baseURL, timeout and headers once.

**Q12. What is an Axios interceptor?**

An interceptor is a function that executes before a request is sent or after a response is received.

**Q13. What is the difference between `response.json()` and `response.data`?**

`response.json()` parses a Fetch response body into a JavaScript value. `response.data` contains the response data provided by Axios.

**Q14. Why do we use TypeScript interfaces in API communication?**

Interfaces define the expected structure of API data and provide compile-time type checking.

**Q15. Why should API keys not be exposed in frontend code?**

Frontend code is visible to users, so API keys stored there can be extracted and misused. Sensitive keys should be kept on the backend.

---

## 18. Multiple Choice Questions (MCQs)

**1. Which API is built into modern browsers for HTTP requests?**

A. Axios  
B. Fetch API  
C. Express  
D. MongoDB

**Answer: B. Fetch API**

**2. What does Fetch return?**

A. String  
B. Number  
C. Promise  
D. Boolean

**Answer: C. Promise**

**3. Which method is used to parse a Fetch response as JSON?**

A. JSON.parse()  
B. response.json()  
C. JSON.stringify()  
D. response.parse()

**Answer: B. response.json()**

**4. Which HTTP method is generally used to retrieve data?**

A. POST  
B. DELETE  
C. GET  
D. PATCH

**Answer: C. GET**

**5. Which HTTP method is generally used to submit data?**

A. GET  
B. POST  
C. HEAD  
D. OPTIONS

**Answer: B. POST**

**6. Which method converts a JavaScript object into a JSON string?**

A. JSON.parse()  
B. JSON.stringify()  
C. response.json()  
D. JSON.convert()

**Answer: B. JSON.stringify()**

**7. Which object is used to cancel Fetch requests?**

A. Promise  
B. Request  
C. AbortController  
D. Headers

**Answer: C. AbortController**

**8. Does Fetch reject its Promise for HTTP 404 by default?**

A. Yes  
B. No  
C. Only in React  
D. Only in TypeScript

**Answer: B. No**

**9. Which Axios method creates a custom Axios instance?**

A. axios.new()  
B. axios.create()  
C. axios.instance()  
D. axios.config()

**Answer: B. axios.create()**

**10. Where is the response body generally available in Axios?**

A. response.json()  
B. response.body  
C. response.data  
D. response.content

**Answer: C. response.data**

**11. Which Axios feature executes before a request is sent?**

A. Response interceptor  
B. Request interceptor  
C. Promise callback  
D. JSON parser

**Answer: B. Request interceptor**

**12. What is the purpose of the Axios `timeout` configuration?**

A. To delay the request  
B. To limit request duration  
C. To delete the response  
D. To modify the URL

**Answer: B. To limit request duration**

**13. Which TypeScript feature describes the structure of an API response?**

A. Loop  
B. Interface  
C. Alert  
D. Console

**Answer: B. Interface**

**14. Which operator is used to access optional nested properties safely?**

A. `&&`  
B. `||`  
C. `?.`  
D. `??`

**Answer: C. `?.`**

**15. Which package is used for HTTP requests in the practical?**

A. Express  
B. Axios  
C. MySQL  
D. Vite

**Answer: B. Axios**

---

# Part F – Quick Revision

## 19. Important Syntax to Remember

### Fetch GET

```javascript
const response = await fetch(url);

if (!response.ok) {
    throw new Error("HTTP Error");
}

const data = await response.json();
```

### Fetch POST

```javascript
await fetch(url, {
    method: "POST",
    headers: {
        "Content-Type": "application/json"
    },
    body: JSON.stringify(data)
});
```

### AbortController

```javascript
const controller = new AbortController();

fetch(url, {
    signal: controller.signal
});

controller.abort();
```

### Axios GET

```javascript
const response = await axios.get(url);

console.log(response.data);
```

### Axios POST

```javascript
await axios.post(url, data);
```

### Axios Instance

```javascript
const api = axios.create({
    baseURL: "https://api.example.com",
    timeout: 5000
});
```

### Axios Error Handling

```javascript
try {
    const response = await axios.get(url);
    console.log(response.data);
}
catch (error) {
    console.log(error);
}
```

### TypeScript API Response

```typescript
interface User {
    id: number;
    name: string;
    email: string;
}
```

---

# Part G – Self-Learning and Practice

## 20. Practice Assignments

1. Fetch users from JSONPlaceholder and display them in a table.
2. Create a POST request to submit a new user.
3. Create a Fetch request with error handling.
4. Cancel an API request using AbortController.
5. Create an Axios instance with a base URL and timeout.
6. Create GET, POST, PUT and DELETE requests using Axios.
7. Implement request and response interceptors.
8. Define TypeScript interfaces for a product API.
9. Fetch products using Axios and display them in React.
10. Complete the Live News Headlines application.

## 21. Important References

### Official Documentation

- [MDN – Fetch API](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API)
- [MDN – Request](https://developer.mozilla.org/en-US/docs/Web/API/Request)
- [MDN – Response](https://developer.mozilla.org/en-US/docs/Web/API/Response)
- [MDN – AbortController](https://developer.mozilla.org/en-US/docs/Web/API/AbortController)
- [Axios Documentation](https://axios-http.com/docs/intro)
- [Axios API Reference](https://axios-http.com/docs/api_intro)
- [TypeScript Documentation](https://www.typescriptlang.org/docs/)
- [React Documentation](https://react.dev/)

### Practice API

- [JSONPlaceholder](https://jsonplaceholder.typicode.com/)
- [News API](https://newsapi.org/)

---

## 22. Final Session Checklist

- [ ] Understand HTTP request and response.
- [ ] Understand Fetch API.
- [ ] Understand Request and Response objects.
- [ ] Understand HTTP headers.
- [ ] Perform GET and POST requests.
- [ ] Parse JSON responses.
- [ ] Use AbortController.
- [ ] Implement Fetch error handling.
- [ ] Install and configure Axios.
- [ ] Create Axios instances.
- [ ] Handle Axios requests and responses.
- [ ] Implement Axios error handling.
- [ ] Understand interceptors.
- [ ] Use TypeScript interfaces for API responses.
- [ ] Complete the Live News Headlines practical.

**Most important for CCEE:** Focus on Fetch vs Axios, Request vs Response, GET vs POST, JSON parsing, AbortController, error handling, Axios instances, interceptors, and TypeScript API response interfaces.
