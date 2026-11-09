# 1. Introduction to JSON

## 1.1 What is JSON?

JSON stands for **JavaScript Object Notation**.

It is a lightweight, text-based data-interchange format used to store and exchange data between different applications.

JSON is easy for humans to read and easy for machines to parse and generate.

Example:

```json
{
    "name": "Anurag",
    "age": 22,
    "course": "CMCE",
    "city": "Pune"
}
```

This JSON data represents a student with four properties:
- name
- age
- course
- city

## 1.2 Why do we need JSON?

Consider a web application where a frontend needs student details from a backend server.

Without a standard data format, different applications may represent the same information differently.

JSON provides a common format for exchanging structured information.

### Example: Frontend and backend communication

```text
React / JavaScript Frontend
           |
           | HTTP Request
           v
      Backend Server
           |
           | Database Query
           v
         Database
           |
           | Student Data
           v
      Backend Server
           |
           | JSON Response
           v
React / JavaScript Frontend
```

Example JSON response:

```json
{
    "id": 101,
    "name": "Anurag",
    "course": "PGCP-AC",
    "city": "Pune"
}
```

The frontend receives the JSON data and displays it on the webpage.

### Advantages of JSON

1. **Lightweight:** JSON is generally compact and easy to transfer.
2. **Readable:** Humans can understand its structure.
3. **Language-independent:** Many programming languages support JSON.
4. **Easy parsing:** JavaScript provides built-in JSON methods.
5. **API communication:** Widely used in REST APIs.
6. **Data storage:** Can store structured information in `.json` files.
7. **Interoperability:** Different systems can exchange data using a common format.

## 1.3 JSON vs JavaScript Object

These two look similar but are not exactly the same.

**JavaScript object:**

```javascript
let student = {
    name: "Anurag",
    age: 22,
    course: "CMCE"
};
```

**JSON:**

```json
{
    "name": "Anurag",
    "age": 22,
    "course": "CMCE"
}
```

Important differences:

| JavaScript Object | JSON |
|---|---|
| Used directly in JavaScript programs | Used for data exchange and storage |
| Property names can be unquoted | Property names must use double quotes |
| Supports functions as property values | Does not support functions |
| Supports `undefined` values | Does not support `undefined` |
| Supports comments in some JavaScript contexts | Does not support comments |
| Can contain special JavaScript values | Supports a limited set of data types |

Example:

```javascript
// Valid JavaScript object
let employee = {
    name: "Rahul",
    greet: function() {
        return "Hello";
    }
};
```

The above object cannot be represented as valid JSON because JSON does not support functions.

# 2. JSON Syntax Rules

JSON follows strict syntax rules.

## Rule 1: Data is represented using key-value pairs

```json
{
    "name": "Anurag",
    "age": 22
}
```

Here:
- `"name"` is the key.
- `"Anurag"` is the value.
- `"age"` is another key.
- `22` is its value.

## Rule 2: Keys must be enclosed in double quotes

Correct:

```json
{
    "name": "Anurag"
}
```

Incorrect:

```javascript
{
    name: "Anurag"
}
```

The second example is a JavaScript object, not valid JSON.

## Rule 3: Strings must use double quotes

Correct:

```json
{
    "city": "Pune"
}
```

Incorrect:

```javascript
{
    "city": 'Pune'
}
```

## Rule 4: Separate key-value pairs using commas

Correct:

```json
{
    "name": "Anurag",
    "age": 22,
    "city": "Pune"
}
```

## Rule 5: JSON supports specific data types

JSON supports six types:

| Data type | Example |
|---|---|
| String | `"name": "Anurag"` |
| Number | `"age": 22` |
| Boolean | `"active": true` |
| Object | `"address": {"city": "Pune"}` |
| Array | `"skills": ["Java", "Python"]` |
| Null | `"middleName": null` |

## Rule 6: No trailing commas

Correct:

```json
{
    "name": "Anurag",
    "age": 22
}
```

Incorrect:

```javascript
{
    "name": "Anurag",
    "age": 22,
}
```

## Rule 7: JSON does not support comments

Incorrect:

```javascript
{
    // Student details
    "name": "Anurag"
}
```

JSON does not allow `//` or `/* ... */` comments.

## Rule 8: JSON does not support undefined, NaN or Infinity

Invalid JSON examples:

```javascript
{
    "name": undefined,
    "marks": NaN,
    "amount": Infinity
}
```

Use `null` or an appropriate valid value when representing missing information.

# 3. JSON Objects

## 3.1 What is a JSON object?

A JSON object is a collection of key-value pairs enclosed within curly braces `{}`.

Syntax:

```json
{
    "key1": "value1",
    "key2": "value2"
}
```

Example:

```json
{
    "studentId": 101,
    "name": "Anurag",
    "course": "CMCE",
    "isActive": true
}
```

## 3.2 Nested JSON objects

A JSON object can contain another JSON object as its value.

Example:

```json
{
    "studentId": 101,
    "name": "Anurag",
    "address": {
        "city": "Pune",
        "state": "Maharashtra",
        "country": "India"
    }
}
```

Accessing nested properties in JavaScript:

```javascript
let student = {
    studentId: 101,
    name: "Anurag",
    address: {
        city: "Pune",
        state: "Maharashtra"
    }
};

console.log(student.name);

console.log(student.address.city);

console.log(student.address.state);
```

Output:

```text
Anurag
Pune
Maharashtra
```

## 3.3 Array inside an object

An object can contain an array.

```json
{
    "name": "Anurag",
    "skills": [
        "Java",
        "Python",
        "JavaScript",
        "React"
    ]
}
```

Accessing array elements:

```javascript
let student = {
    name: "Anurag",
    skills: ["Java", "Python", "JavaScript", "React"]
};

console.log(student.skills[0]);

console.log(student.skills[2]);
```

Output:

```text
Java
JavaScript
```

## 3.4 Object inside an array

An array can contain multiple objects.

```json
[
    {
        "id": 1,
        "name": "Anurag"
    },
    {
        "id": 2,
        "name": "Rahul"
    },
    {
        "id": 3,
        "name": "Amit"
    }
]
```

Accessing data:

```javascript
let students = [
    { id: 1, name: "Anurag" },
    { id: 2, name: "Rahul" },
    { id: 3, name: "Amit" }
];

console.log(students[0].name);

console.log(students[1].name);
```

Output:

```text
Anurag
Rahul
```

# 4. JSON Arrays

## 4.1 What is a JSON array?

A JSON array is an ordered collection of values enclosed within square brackets `[]`.

Example:

```json
[
    "Java",
    "Python",
    "JavaScript",
    "React"
]
```

An array can contain:
- Strings
- Numbers
- Booleans
- Objects
- Other arrays
- Null values

## 4.2 Array of numbers

```json
{
    "marks": [80, 85, 90, 95]
}
```

## 4.3 Array of objects

```json
{
    "employees": [
        {
            "id": 101,
            "name": "Rahul",
            "salary": 30000
        },
        {
            "id": 102,
            "name": "Amit",
            "salary": 35000
        }
    ]
}
```

## 4.4 Iterating over JSON arrays in JavaScript

```javascript
let employees = [
    { id: 101, name: "Rahul", salary: 30000 },
    { id: 102, name: "Amit", salary: 35000 },
    { id: 103, name: "Anurag", salary: 40000 }
];

employees.forEach(function(employee) {
    console.log(employee.name);
});
```

Using `map()`:

```javascript
let names = employees.map(employee => employee.name);

console.log(names);
```

Using `filter()`:

```javascript
let highSalaryEmployees = employees.filter(
    employee => employee.salary > 30000
);

console.log(highSalaryEmployees);
```

These array methods connect directly with the functional programming concepts studied in Sessions 6–8.

# 5. JSON Files

## 5.1 What is a JSON file?

A JSON file is a text file that stores structured data in JSON format.

It commonly uses the `.json` extension.

Example filename:

```text
students.json
```

Contents of `students.json`:

```json
{
    "students": [
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
}
```

## 5.2 Why use JSON files?

JSON files are useful for:
- Storing configuration settings.
- Maintaining sample data.
- Storing application information.
- Providing mock API responses.
- Sharing structured data between systems.
- Maintaining test datasets.

Examples of common JSON files:

```text
package.json
tsconfig.json
settings.json
students.json
products.json
```

## 5.3 Reading a JSON file in JavaScript using Fetch API

Suppose you have a file named `students.json`.

Project structure:

```text
json-demo/
│
├── index.html
├── script.js
└── students.json
```

`students.json`:

```json
{
    "students": [
        {
            "id": 1,
            "name": "Anurag",
            "city": "Pune"
        },
        {
            "id": 2,
            "name": "Rahul",
            "city": "Mumbai"
        }
    ]
}
```

`index.html`:

```html
<!DOCTYPE html>
<html>
<head>
    <title>JSON File Example</title>
</head>
<body>

    <h2>Student Details</h2>

    <button onclick="loadStudents()">Load Students</button>

    <div id="result"></div>

    <script src="script.js"></script>

</body>
</html>
```

`script.js`:

```javascript
async function loadStudents() {

    try {

        let response = await fetch("students.json");

        if (!response.ok) {
            throw new Error("Unable to load JSON file");
        }

        let data = await response.json();

        let result = document.getElementById("result");

        data.students.forEach(student => {

            let p = document.createElement("p");

            p.textContent =
                student.id + " - " +
                student.name + " - " +
                student.city;

            result.appendChild(p);

        });

    } catch (error) {

        console.error(error.message);

    }

}
```

**Important:** Run this project using a local development server, such as VS Code Live Server. Browsers generally restrict Fetch requests from pages opened directly through the `file://` protocol.

# 6. JSON Parsing

## 6.1 What is JSON parsing?

JSON parsing is the process of converting JSON-formatted text into a JavaScript value, such as an object or array.

JavaScript provides a built-in method:

```javascript
JSON.parse()
```

Example:

```javascript
let jsonString = '{"name":"Anurag","age":22}';

let student = JSON.parse(jsonString);

console.log(student.name);

console.log(student.age);
```

Output:

```text
Anurag
22
```

The input is a JSON string. After parsing, it becomes a JavaScript object.

## 6.2 JSON.stringify()

`JSON.stringify()` converts a JavaScript value into a JSON-formatted string.

Example:

```javascript
let student = {
    name: "Anurag",
    age: 22,
    course: "CMCE"
};

let jsonString = JSON.stringify(student);

console.log(jsonString);

console.log(typeof jsonString);
```

Output:

```text
{"name":"Anurag","age":22,"course":"CMCE"}
string
```

## 6.3 Difference between JSON.parse() and JSON.stringify()

| JSON.parse() | JSON.stringify() |
|---|---|
| Converts JSON text into a JavaScript value | Converts a JavaScript value into JSON text |
| JSON string → JavaScript value | JavaScript value → JSON string |
| Used when receiving JSON data | Used when sending or storing JSON data |

Remember:

```javascript
let obj = { name: "Anurag" };

// Object to JSON string
let json = JSON.stringify(obj);

// JSON string to JavaScript object
let result = JSON.parse(json);
```

## 6.4 Handling invalid JSON

If a JSON string has invalid syntax, `JSON.parse()` throws a SyntaxError.

```javascript
let jsonString = '{"name":"Anurag"';

try {

    let student = JSON.parse(jsonString);

    console.log(student);

} catch (error) {

    console.log("Invalid JSON:", error.message);

}
```

This connects to the error-handling concepts from Sessions 9 & 10.

## 6.5 JSON.stringify() with indentation

The third-party-looking but built-in method `JSON.stringify()` accepts a spacing argument.

```javascript
let student = {
    name: "Anurag",
    age: 22,
    course: "CMCE"
};

let json = JSON.stringify(student, null, 4);

console.log(json);
```

Output:

```json
{
    "name": "Anurag",
    "age": 22,
    "course": "CMCE"
}
```

The third argument (`4`) specifies indentation spaces, making the JSON easier to read.

## 6.6 JSON limitations and conversion behavior

JSON supports a limited set of data types. For example:

```javascript
let data = {
    name: "Anurag",
    age: undefined,
    greet: function() {
        return "Hello";
    }
};

console.log(JSON.stringify(data));
```

Output:

```json
{"name":"Anurag"}
```

Object properties with `undefined` values and function values are omitted during serialization.

Other important behaviors:
- `NaN` and `Infinity` are serialized as `null`.
- `Date` objects are serialized as strings through their `toJSON()` method.
- Circular references cannot be serialized directly and cause a TypeError.

# 7. Important JSON Concepts at a Glance

| Concept | Meaning |
|---|---|
| JSON | JavaScript Object Notation |
| `{}` | JSON object |
| `[]` | JSON array |
| Key | Property name |
| Value | Data associated with a key |
| `.json` | Common JSON file extension |
| `JSON.parse()` | JSON string to JavaScript value |
| `JSON.stringify()` | JavaScript value to JSON string |
| `null` | Represents an explicitly empty value |
| Nested object | Object inside another object |
| Nested array | Array inside another array |

# 8. Lab: Cricket Match Scoreboard Using JSON

## Objective

Create a JSON object, array, and JSON file to store a cricket match scoreboard.

The scoreboard should contain:
- Match details.
- Team information.
- Players.
- Runs scored.
- Balls faced.
- Fours and sixes.
- Wickets.
- Overs.
- Extras.
- Total score.
- Match result.

## Part A: Create a JSON object

Example:

```json
{
    "matchId": 101,
    "match": "India vs Australia",
    "venue": "Mumbai",
    "format": "ODI",
    "date": "2026-11-09",
    "tossWinner": "India",
    "tossDecision": "Batting",
    "result": "India won by 25 runs"
}
```

This object stores the basic information about the match.

## Part B: Create a JSON array for players

```json
[
    {
        "playerId": 1,
        "name": "Player A",
        "runs": 85,
        "balls": 70,
        "fours": 8,
        "sixes": 3,
        "status": "Out"
    },
    {
        "playerId": 2,
        "name": "Player B",
        "runs": 45,
        "balls": 38,
        "fours": 5,
        "sixes": 1,
        "status": "Out"
    },
    {
        "playerId": 3,
        "name": "Player C",
        "runs": 60,
        "balls": 50,
        "fours": 6,
        "sixes": 2,
        "status": "Not Out"
    }
]
```

This array stores individual player performances.

## Part C: Complete scoreboard JSON object

Create a file named:

`cricket-scoreboard.json`

Contents:

```json
{
    "matchId": 101,
    "matchDetails": {
        "team1": "India",
        "team2": "Australia",
        "venue": "Mumbai",
        "format": "ODI",
        "date": "2026-11-09",
        "tossWinner": "India",
        "tossDecision": "Batting"
    },

    "teams": [
        {
            "teamName": "India",
            "innings": {
                "runs": 250,
                "wickets": 8,
                "overs": 50,
                "extras": 10,

                "players": [
                    {
                        "name": "Player A",
                        "runs": 85,
                        "balls": 70,
                        "fours": 8,
                        "sixes": 3,
                        "status": "Out"
                    },
                    {
                        "name": "Player B",
                        "runs": 45,
                        "balls": 38,
                        "fours": 5,
                        "sixes": 1,
                        "status": "Out"
                    },
                    {
                        "name": "Player C",
                        "runs": 60,
                        "balls": 50,
                        "fours": 6,
                        "sixes": 2,
                        "status": "Not Out"
                    }
                ]
            }
        },

        {
            "teamName": "Australia",
            "innings": {
                "runs": 225,
                "wickets": 10,
                "overs": 48,
                "extras": 12,

                "players": [
                    {
                        "name": "Player D",
                        "runs": 75,
                        "balls": 65,
                        "fours": 7,
                        "sixes": 2,
                        "status": "Out"
                    },
                    {
                        "name": "Player E",
                        "runs": 50,
                        "balls": 42,
                        "fours": 4,
                        "sixes": 2,
                        "status": "Out"
                    }
                ]
            }
        }
    ],

    "result": {
        "winner": "India",
        "margin": "25 runs"
    }
}
```

*Note: This is illustrative sample data, not a record of an actual match. The shortened player lists are for demonstrating JSON structure.*

## Part D: Read and display the scoreboard using JavaScript

Create these files:

```text
cricket-scoreboard/
│
├── index.html
├── script.js
└── cricket-scoreboard.json
```

### index.html

```html
<!DOCTYPE html>
<html>
<head>
    <title>Cricket Scoreboard</title>
</head>
<body>

    <h1>Cricket Match Scoreboard</h1>

    <button id="loadScore">Load Scoreboard</button>

    <div id="scoreboard"></div>

    <script src="script.js"></script>

</body>
</html>
```

### script.js

```javascript
async function loadScoreboard() {

    try {

        let response = await fetch("cricket-scoreboard.json");

        if (!response.ok) {
            throw new Error("Unable to load scoreboard");
        }

        let data = await response.json();

        let container = document.getElementById("scoreboard");

        container.replaceChildren();

        let heading = document.createElement("h2");

        heading.textContent =
            data.matchDetails.team1 + " vs " +
            data.matchDetails.team2;

        container.appendChild(heading);

        data.teams.forEach(team => {

            let teamHeading = document.createElement("h3");

            teamHeading.textContent = team.teamName;

            container.appendChild(teamHeading);

            let innings = team.innings;

            let score = document.createElement("p");

            score.textContent =
                "Score: " + innings.runs + "/" +
                innings.wickets + " (" +
                innings.overs + " overs)";

            container.appendChild(score);

            let table = document.createElement("table");

            table.border = "1";

            table.innerHTML = `
                <tr>
                    <th>Player</th>
                    <th>Runs</th>
                    <th>Balls</th>
                    <th>4s</th>
                    <th>6s</th>
                    <th>Status</th>
                </tr>
            `;

            innings.players.forEach(player => {

                let row = table.insertRow();

                row.insertCell().textContent = player.name;
                row.insertCell().textContent = player.runs;
                row.insertCell().textContent = player.balls;
                row.insertCell().textContent = player.fours;
                row.insertCell().textContent = player.sixes;
                row.insertCell().textContent = player.status;

            });

            container.appendChild(table);

        });

        let result = document.createElement("h3");

        result.textContent =
            "Result: " + data.result.winner +
            " won by " + data.result.margin;

        container.appendChild(result);

    } catch (error) {

        console.error(error);

        document.getElementById("scoreboard").textContent =
            "Error: " + error.message;

    }

}

document.getElementById("loadScore")
    .addEventListener("click", loadScoreboard);
```

This practical combines:
- JSON objects.
- JSON arrays.
- Nested objects and arrays.
- JSON files.
- Fetch API.
- JSON parsing.
- DOM manipulation.
- Error handling.

## Part E: Create a JSON object directly in JavaScript

You can also create the scoreboard without a separate file.

```javascript
let match = {

    match: "India vs Australia",

    venue: "Mumbai",

    teams: [

        {
            name: "India",
            runs: 250,
            wickets: 8
        },

        {
            name: "Australia",
            runs: 225,
            wickets: 10
        }

    ]

};

console.log(match.match);

console.log(match.teams[0].name);

console.log(match.teams[0].runs);
```

## Part F: Convert the scoreboard object into a JSON string

```javascript
let jsonData = JSON.stringify(match, null, 4);

console.log(jsonData);
```

Convert it back:

```javascript
let newMatch = JSON.parse(jsonData);

console.log(newMatch.teams[1].name);
```

# 9. CCEE and Interview Questions

1. What is JSON?
2. What is the full form of JSON?
3. Why do we need JSON?
4. What are the advantages of JSON?
5. What are the syntax rules of JSON?
6. What is a JSON object?
7. What is a JSON array?
8. What is the difference between JSON object and JSON array?
9. Can JSON contain nested objects?
10. Can a JSON object contain an array?
11. Can a JSON array contain objects?
12. Which data types are supported by JSON?
13. Does JSON support functions?
14. Does JSON support comments?
15. Does JSON support single-quoted strings?
16. What is a JSON file?
17. What is the extension of a JSON file?
18. What is JSON parsing?
19. What is `JSON.parse()`?
20. What is `JSON.stringify()`?
21. What is the difference between `parse()` and `stringify()`?
22. What happens if JSON syntax is invalid?
23. How do you handle JSON parsing errors?
24. How is JSON used in REST APIs?
25. How do you fetch and display a JSON file in JavaScript?

# 10. MCQs

**1. What is the full form of JSON?**

A. Java Standard Object Notation  
B. JavaScript Object Notation  
C. Java Source Object Network  
D. JavaScript Online Network  

**Answer: B**

**2. Which brackets represent a JSON object?**

A. `[]`  
B. `{}`  
C. `()`  
D. `<>`  

**Answer: B**

**3. Which brackets represent a JSON array?**

A. `{}`  
B. `()`  
C. `[]`  
D. `<>`  

**Answer: C**

**4. Which method converts JSON text into a JavaScript value?**

A. `JSON.stringify()`  
B. `JSON.parse()`  
C. `JSON.convert()`  
D. `JSON.object()`  

**Answer: B**

**5. Which method converts a JavaScript object into JSON text?**

A. `JSON.parse()`  
B. `JSON.stringify()`  
C. `JSON.convert()`  
D. `JSON.read()`  

**Answer: B**

**6. Which data type is not supported by JSON?**

A. String  
B. Number  
C. Boolean  
D. Function  

**Answer: D**

**7. Which quotation marks are required for JSON strings?**

A. Single quotes  
B. Double quotes  
C. Backticks  
D. No quotes  

**Answer: B**

**8. Which value represents an empty value in JSON?**

A. undefined  
B. empty  
C. null  
D. void  

**Answer: C**

**9. What is the extension of a JSON file?**

A. `.js`  
B. `.html`  
C. `.json`  
D. `.xml`  

**Answer: C**

**10. What happens when JSON.parse() receives invalid JSON?**

A. Returns null automatically  
B. Throws a SyntaxError  
C. Returns undefined  
D. Converts it to a string  

**Answer: B**

**11. JSON is primarily used for:**

A. Styling webpages  
B. Data exchange  
C. Compiling programs  
D. Creating animations  

**Answer: B**

**12. Which of the following is valid JSON?**

A. `{name: 'Anurag'}`  
B. `{'name': 'Anurag'}`  
C. `{"name": "Anurag"}`  
D. `{name = "Anurag"}`  

**Answer: C**

**13. Can JSON arrays contain objects?**

A. Yes  
B. No  
C. Only strings  
D. Only numbers  

**Answer: A**

**14. Which JavaScript API is commonly used to fetch JSON files?**

A. DOM  
B. Fetch API  
C. Canvas API  
D. Storage API  

**Answer: B**

**15. Which method makes JSON output more readable with indentation?**

A. `JSON.parse(obj, 4)`  
B. `JSON.stringify(obj, null, 4)`  
C. `JSON.read(obj, 4)`  
D. `JSON.format(obj)`  

**Answer: B**

# 11. Quick Revision

| Topic | Remember |
|---|---|
| JSON | JavaScript Object Notation |
| Object | Curly braces `{}` |
| Array | Square brackets `[]` |
| Key | Must be double quoted |
| String | Must use double quotes |
| Number | Integer or decimal |
| Boolean | `true` or `false` |
| Empty value | `null` |
| JSON file | `.json` |
| Parsing | JSON text → JavaScript value |
| `JSON.parse()` | Converts JSON to JS value |
| `JSON.stringify()` | Converts JS value to JSON text |
| Invalid JSON | Throws SyntaxError when parsed |
| Fetch | Retrieves JSON from a URL or server |

# 12. Self-Learning Tasks

- [ ] Create a student JSON object.
- [ ] Create an array of five student objects.
- [ ] Create a nested JSON object containing address and contact details.
- [ ] Create an employee JSON file.
- [ ] Read a JSON file using Fetch API.
- [ ] Convert an object into a JSON string.
- [ ] Parse a JSON string into an object.
- [ ] Handle invalid JSON using try-catch.
- [ ] Build a cricket scoreboard using nested JSON objects and arrays.
- [ ] Display the scoreboard dynamically using DOM methods.

# 13. References

1. JavaScript: The Definitive Guide, 7th Edition – David Flanagan.
2. MDN – JSON: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON
3. MDN – JSON.parse(): https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON/parse
4. MDN – JSON.stringify(): https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON/stringify
5. JSON Official Website: https://www.json.org/json-en.html
6. JSON Standard (RFC 8259): https://www.rfc-editor.org/rfc/rfc8259

---

**Final learning goal:** You should be able to create structured JSON data, store it in a `.json` file, parse it into JavaScript objects, and display that data dynamically on a webpage.
