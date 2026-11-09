# 🌐 CMCE – Web Programming Technologies
# Session 2: HTML5

![Course](https://img.shields.io/badge/Course-Web%20Programming%20Technologies-blue)
![Batch](https://img.shields.io/badge/Batch-August%202026-green)
![Session](https://img.shields.io/badge/Session-02-orange)
![Duration](https://img.shields.io/badge/Duration-2T%20%2B%202L-purple)

---

# 1. Introduction to HTML

## 1.1 What is HTML?

HTML stands for **HyperText Markup Language**.

HTML is the standard markup language used to create and structure web pages.

It tells the browser what content should appear on a webpage, such as:

- Headings
- Paragraphs
- Images
- Links
- Lists
- Tables
- Forms
- Audio and video

**Important:** HTML is a markup language, not a programming language. It describes the structure and meaning of content rather than implementing general-purpose programming logic.

### Example

```html
<!DOCTYPE html>
<html>
<head>
    <title>My First Webpage</title>
</head>
<body>
    <h1>Hello World!</h1>
    <p>Welcome to HTML.</p>
</body>
</html>
```

Output:

Hello World!

Welcome to HTML.

## 1.2 What is HyperText?

HyperText refers to text that contains links to other documents or resources.

Example:

When you click on a link in a webpage and navigate to another webpage, you are using HyperText.

## 1.3 What is Markup Language?

A markup language uses tags to define the structure and presentation or meaning of content.

Examples:

- HTML – Structures web pages.
- XML – Stores and describes structured data.
- SVG – Describes scalable vector graphics.

## 1.4 History of HTML

| Year | Development |
|---|---|
| 1991 | First version of HTML |
| 1995 | HTML 2.0 |
| 1997 | HTML 3.2 |
| 1997 | HTML 4.0 |
| 1999 | HTML 4.01 |
| 2008 | First public HTML5 draft |
| 2014 | HTML5 W3C Recommendation |
| 2019 | WHATWG and W3C agreed on a single continuously maintained HTML standard |
| Present | HTML Living Standard |

**Inventor:** Tim Berners-Lee.

## 1.5 What is HTML5?

HTML5 is the fifth major version of HTML and introduced important capabilities for modern web applications.

Major features:

1. Semantic elements.
2. Audio and video support.
3. Canvas graphics.
4. Improved form controls.
5. New input types.
6. Geolocation API.
7. Better accessibility support.
8. Support for modern web application features.

---

# 2. Basic Structure of an HTML5 Document

Every HTML document follows a standard structure.

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>My First Page</title>
</head>

<body>

    <h1>Welcome to HTML5</h1>
    <p>This is my first webpage.</p>

</body>
</html>
```

## 2.1 Explanation of Each Element

| Element | Purpose |
|---|---|
| `<!DOCTYPE html>` | Declares an HTML5 document |
| `<html>` | Root element of the document |
| `<head>` | Contains document metadata and resource references |
| `<meta>` | Provides metadata |
| `<title>` | Defines the browser tab title |
| `<body>` | Contains visible webpage content |
| `<h1>` | Defines the main heading |
| `<p>` | Defines a paragraph |

### Important Concepts

**DOCTYPE**

```html
<!DOCTYPE html>
```

It tells the browser to interpret the document using modern HTML standards.

**Meta Charset**

```html
<meta charset="UTF-8">
```

Specifies the character encoding of the document.

UTF-8 supports a wide range of characters and symbols.

**Viewport**

```html
<meta name="viewport" content="width=device-width, initial-scale=1.0">
```

Helps the webpage adapt to different screen sizes.

---

# 3. HTML Tags, Elements and Attributes

## 3.1 What is an HTML Tag?

An HTML tag is a markup instruction enclosed within angle brackets.

Example:

```html
<p>
```

Here, `p` is the paragraph tag.

## 3.2 What is an HTML Element?

An HTML element generally consists of:

- Opening tag.
- Content.
- Closing tag.

Example:

```html
<p>Hello Anurag</p>
```

Here:

- `<p>` – Opening tag.
- `Hello Anurag` – Content.
- `</p>` – Closing tag.

## 3.3 What are Attributes?

Attributes provide additional information or configuration to HTML elements.

Example:

```html
<a href="https://www.google.com" target="_blank">
    Visit Google
</a>
```

Here:

- `href` specifies the destination.
- `target="_blank"` requests opening the destination in a new browsing context, usually a new tab.

### Common HTML Attributes

| Attribute | Purpose |
|---|---|
| `id` | Unique identifier for an element |
| `class` | Groups elements for styling or scripting |
| `style` | Adds inline CSS |
| `title` | Provides additional advisory information |
| `src` | Specifies a resource URL |
| `href` | Specifies a hyperlink destination |
| `alt` | Provides alternative text for images |
| `width` | Specifies width |
| `height` | Specifies height |
| `name` | Identifies a form control or other named element |
| `value` | Specifies a control's value |
| `type` | Specifies an element or input type |
| `disabled` | Disables a form control |
| `required` | Makes a form control mandatory |
| `placeholder` | Displays a hint inside an input |

## 3.4 Types of HTML Elements

### 1. Paired Elements

Contain opening and closing tags.

```html
<h1>Welcome</h1>
<p>Hello World</p>
```

### 2. Void Elements

Do not have closing tags.

Examples:

```html
<br>
<hr>
<img src="photo.jpg" alt="My Photo">
<input type="text">
```

## 3.5 Block-Level and Inline Elements

**Block-Level Elements**

Generally start on a new line and occupy the available width of their containing block by default.

Examples:

- `<div>`
- `<p>`
- `<h1>`
- `<section>`
- `<ul>`

**Inline Elements**

Generally flow within surrounding text.

Examples:

- `<span>`
- `<a>`
- `<strong>`
- `<em>`
- `<img>`

Note: CSS can change how elements are displayed.

---

# 4. Basic HTML Tags

## 4.1 Headings

HTML provides six heading levels.

```html
<h1>Main Heading</h1>
<h2>Sub Heading</h2>
<h3>Heading Level 3</h3>
<h4>Heading Level 4</h4>
<h5>Heading Level 5</h5>
<h6>Heading Level 6</h6>
```

### Heading Hierarchy

| Tag | Meaning |
|---|---|
| `<h1>` | Highest-level heading |
| `<h2>` | Second-level heading |
| `<h3>` | Third-level heading |
| `<h4>` | Fourth-level heading |
| `<h5>` | Fifth-level heading |
| `<h6>` | Sixth-level heading |

Important points:

- Use headings according to document structure.
- Do not select heading levels merely for their default font sizes.
- A webpage generally has one main page heading, though HTML permits multiple h1 elements.

## 4.2 Paragraph

The `<p>` tag defines a paragraph.

```html
<p>
    HTML is used to create web pages.
</p>
```

Multiple paragraphs:

```html
<p>First paragraph.</p>
<p>Second paragraph.</p>
```

## 4.3 Line Break

The `<br>` tag inserts a line break.

```html
<p>
    My name is Anurag.<br>
    I am learning HTML.<br>
    I am studying CMCE.
</p>
```

## 4.4 Horizontal Rule

The `<hr>` tag represents a thematic break, generally displayed as a horizontal line.

```html
<h2>About Me</h2>
<p>Information about me.</p>

<hr>

<h2>Education</h2>
<p>My educational details.</p>
```

## 4.5 Text Formatting Tags

| Tag | Purpose |
|---|---|
| `<b>` | Draws attention with bold styling |
| `<strong>` | Indicates strong importance |
| `<i>` | Marks text in an alternate voice or mood |
| `<em>` | Emphasizes text |
| `<u>` | Marks text with an underline |
| `<mark>` | Highlights text |
| `<small>` | Represents side comments or smaller print |
| `<del>` | Represents deleted text |
| `<ins>` | Represents inserted text |
| `<sub>` | Subscript text |
| `<sup>` | Superscript text |

Example:

```html
<p><strong>Important:</strong> Complete the assignment.</p>

<p><em>HTML is easy to learn.</em></p>

<p>Water formula: H<sub>2</sub>O</p>

<p>Mathematical expression: X<sup>2</sup></p>

<p><mark>Highlighted Text</mark></p>
```

## 4.6 Alignment

Alignment controls the horizontal positioning of content.

Modern HTML uses CSS for alignment rather than old presentational attributes.

Example:

```html
<p style="text-align: left;">Left Aligned</p>

<p style="text-align: center;">Center Aligned</p>

<p style="text-align: right;">Right Aligned</p>

<p style="text-align: justify;">
    This paragraph is justified using CSS.
</p>
```

Common values:

- `left`
- `center`
- `right`
- `justify`

**Important:** The `align` attribute is obsolete for most HTML elements. Use CSS instead.

---

# 5. Anchor Tag – Hyperlinks

## 5.1 What is an Anchor Tag?

The `<a>` tag creates hyperlinks that connect one resource to another.

Syntax:

```html
<a href="URL">Link Text</a>
```

Example:

```html
<a href="https://www.google.com">
    Visit Google
</a>
```

## 5.2 Important Anchor Attributes

| Attribute | Purpose |
|---|---|
| `href` | Destination URL |
| `target` | Specifies where to open the link |
| `title` | Additional advisory information |
| `rel` | Describes the relationship with the destination |
| `download` | Suggests downloading the linked resource |

### Opening a Link in a New Tab

```html
<a href="https://www.google.com" target="_blank">
    Google
</a>
```

For external links, consider:

```html
<a href="https://example.com"
   target="_blank"
   rel="noopener noreferrer">
    Open Website
</a>
```

## 5.3 Types of Hyperlinks

**1. External Link**

```html
<a href="https://www.github.com">
    GitHub
</a>
```

**2. Internal Link**

```html
<a href="about.html">
    About Us
</a>
```

**3. Email Link**

```html
<a href="mailto:anurag@example.com">
    Send Email
</a>
```

**4. Telephone Link**

```html
<a href="tel:+919876543210">
    Call Us
</a>
```

**5. Page Section Link**

```html
<a href="#contact">Go to Contact</a>

<h2 id="contact">Contact Information</h2>
```

---

# 6. Images in HTML

## 6.1 Image Tag

The `<img>` tag displays an image on a webpage.

Syntax:

```html
<img src="image.jpg" alt="Description">
```

Example:

```html
<img src="profile.jpg"
     alt="Anurag Profile Photo"
     width="200"
     height="200">
```

### Important Attributes

| Attribute | Purpose |
|---|---|
| `src` | Image location |
| `alt` | Alternative text |
| `width` | Image width |
| `height` | Image height |
| `loading` | Controls loading behavior |
| `title` | Additional advisory information |

## 6.2 Types of Image Paths

**Absolute Path**

```html
<img src="https://example.com/images/photo.jpg" alt="Photo">
```

**Relative Path**

```html
<img src="images/photo.jpg" alt="Photo">
```

## 6.3 Why is the alt Attribute Important?

The `alt` attribute provides alternative text when an image cannot be displayed.

It also helps screen-reader users understand meaningful images.

Example:

```html
<img src="college.jpg" alt="PES Modern College of Engineering">
```

For purely decorative images, an empty alt attribute is appropriate:

```html
<img src="decoration.png" alt="">
```

---

# 7. HTML Lists

HTML provides three common types of lists.

## 7.1 Ordered List

An ordered list displays items in a sequence.

Tag: `<ol>`

Example:

```html
<h2>Programming Languages</h2>

<ol>
    <li>C</li>
    <li>C++</li>
    <li>Java</li>
    <li>Python</li>
</ol>
```

Output:

1. C
2. C++
3. Java
4. Python

### Important Attributes

```html
<ol type="A">
    <li>HTML</li>
    <li>CSS</li>
</ol>
```

Common `type` values:

- `1` – Numbers.
- `A` – Uppercase letters.
- `a` – Lowercase letters.
- `I` – Uppercase Roman numerals.
- `i` – Lowercase Roman numerals.

## 7.2 Unordered List

An unordered list displays items with bullets.

Tag: `<ul>`

Example:

```html
<h2>Skills</h2>

<ul>
    <li>Java</li>
    <li>Python</li>
    <li>React</li>
    <li>MySQL</li>
</ul>
```

## 7.3 Description List

Used to display terms and their descriptions.

Tags:

- `<dl>` – Description list.
- `<dt>` – Description term.
- `<dd>` – Description details.

Example:

```html
<dl>
    <dt>HTML</dt>
    <dd>Used to structure webpages.</dd>

    <dt>CSS</dt>
    <dd>Used to style webpages.</dd>
</dl>
```

## 7.4 Nested Lists

A list inside another list is called a nested list.

```html
<ul>
    <li>Frontend
        <ul>
            <li>HTML</li>
            <li>CSS</li>
            <li>JavaScript</li>
        </ul>
    </li>

    <li>Backend
        <ul>
            <li>Java</li>
            <li>Python</li>
        </ul>
    </li>
</ul>
```

---

# 8. HTML Tables

## 8.1 What is an HTML Table?

An HTML table organizes data into rows and columns.

Important tags:

| Tag | Purpose |
|---|---|
| `<table>` | Defines a table |
| `<tr>` | Defines a row |
| `<th>` | Defines a header cell |
| `<td>` | Defines a data cell |
| `<caption>` | Defines a table caption |
| `<thead>` | Groups header rows |
| `<tbody>` | Groups body rows |
| `<tfoot>` | Groups footer rows |

## 8.2 Basic Table Example

```html
<table border="1">

    <tr>
        <th>Roll No</th>
        <th>Name</th>
        <th>Course</th>
    </tr>

    <tr>
        <td>101</td>
        <td>Anurag</td>
        <td>PGCP-AC</td>
    </tr>

    <tr>
        <td>102</td>
        <td>Rahul</td>
        <td>PGCP-AC</td>
    </tr>

</table>
```

## 8.3 Table with Semantic Sections

```html
<table border="1">

    <caption>Student Information</caption>

    <thead>
        <tr>
            <th>Roll No</th>
            <th>Name</th>
            <th>Marks</th>
        </tr>
    </thead>

    <tbody>
        <tr>
            <td>101</td>
            <td>Anurag</td>
            <td>90</td>
        </tr>

        <tr>
            <td>102</td>
            <td>Rahul</td>
            <td>85</td>
        </tr>
    </tbody>

    <tfoot>
        <tr>
            <td colspan="2">Total Students</td>
            <td>2</td>
        </tr>
    </tfoot>

</table>
```

## 8.4 Colspan

`colspan` merges multiple columns.

```html
<table border="1">

    <tr>
        <th colspan="2">Student Details</th>
    </tr>

    <tr>
        <td>Name</td>
        <td>Anurag</td>
    </tr>

</table>
```

## 8.5 Rowspan

`rowspan` merges multiple rows.

```html
<table border="1">

    <tr>
        <th>Name</th>
        <th>Subject</th>
    </tr>

    <tr>
        <td rowspan="2">Anurag</td>
        <td>Java</td>
    </tr>

    <tr>
        <td>Python</td>
    </tr>

</table>
```

Note: The `border` attribute is useful in simple demonstrations, but modern styling should be done using CSS.

---

# 9. iFrames

## 9.1 What is an iFrame?

An iframe (Inline Frame) is used to embed another HTML document or an embeddable external resource inside the current webpage.

Tag: `<iframe>`

Example:

```html
<iframe
    src="about.html"
    width="600"
    height="300"
    title="About Page">
</iframe>
```

## 9.2 Important Attributes

| Attribute | Purpose |
|---|---|
| `src` | Specifies embedded resource URL |
| `width` | Specifies width |
| `height` | Specifies height |
| `title` | Provides an accessible description |
| `allow` | Controls permitted features |
| `loading` | Controls loading behavior |
| `sandbox` | Applies security restrictions |

## 9.3 Embedding a YouTube Video

```html
<iframe
    width="560"
    height="315"
    src="https://www.youtube.com/embed/VIDEO_ID"
    title="YouTube Video"
    allowfullscreen>
</iframe>
```

Replace `VIDEO_ID` with an actual embeddable video ID.

## 9.4 Uses of iFrames

- Embedding maps.
- Embedding videos.
- Displaying external webpages where permitted.
- Embedding third-party applications.

## 9.5 Security Considerations

- Use trusted sources.
- Use `sandbox` when appropriate.
- Provide a descriptive `title`.
- External websites may block embedding.
- Avoid embedding untrusted content without restrictions.

---

# 10. HTML5 New Semantic Elements

## 10.1 What are Semantic Elements?

Semantic elements clearly describe the meaning and purpose of the content they contain.

Before HTML5, developers commonly used `<div>` elements for almost everything.

HTML5 introduced semantic elements to make document structure clearer.

### Important Semantic Elements

| Element | Purpose |
|---|---|
| `<header>` | Introductory content or section header |
| `<nav>` | Navigation links |
| `<main>` | Main content of a document |
| `<section>` | Thematic grouping of content |
| `<article>` | Self-contained content |
| `<aside>` | Complementary content |
| `<footer>` | Footer information |
| `<figure>` | Self-contained illustrative content |
| `<figcaption>` | Caption for a figure |
| `<details>` | Expandable disclosure widget |
| `<summary>` | Visible heading for details |
| `<time>` | Represents date or time |
| `<mark>` | Highlights relevant content |

## 10.2 Example of Semantic HTML

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <title>Semantic HTML</title>
</head>

<body>

    <header>
        <h1>My Website</h1>
    </header>

    <nav>
        <a href="home.html">Home</a>
        <a href="about.html">About</a>
        <a href="contact.html">Contact</a>
    </nav>

    <main>

        <section>
            <h2>About HTML</h2>
            <p>HTML structures web pages.</p>
        </section>

        <article>
            <h2>HTML5 Features</h2>
            <p>HTML5 provides semantic elements.</p>
        </article>

        <aside>
            <p>Related information.</p>
        </aside>

    </main>

    <footer>
        <p>Copyright 2026</p>
    </footer>

</body>
</html>
```

## 10.3 Semantic vs Non-Semantic Elements

| Semantic | Non-Semantic |
|---|---|
| `<header>` | `<div>` |
| `<footer>` | `<span>` |
| `<article>` | `<div>` |
| `<nav>` | `<div>` |
| `<section>` | `<div>` |

Advantages of semantic HTML:

- Better document structure.
- Improved accessibility.
- Easier code maintenance.
- Better understanding for developers.
- Helps search engines understand content.

---

# 11. HTML5 Attributes

HTML5 supports many global and element-specific attributes.

## 11.1 Global Attributes

These can be used on most HTML elements.

| Attribute | Purpose |
|---|---|
| `id` | Unique element identifier |
| `class` | CSS/JavaScript grouping |
| `style` | Inline styling |
| `title` | Additional information |
| `hidden` | Hides an element |
| `tabindex` | Controls keyboard focus order |
| `contenteditable` | Allows editing element content |
| `draggable` | Indicates whether an element can be dragged |
| `data-*` | Stores custom data |
| `lang` | Specifies language |
| `dir` | Specifies text direction |

## 11.2 Contenteditable

Makes an element editable by the user.

```html
<p contenteditable="true">
    You can edit this paragraph.
</p>
```

## 11.3 Data Attributes

Used to store custom data on HTML elements.

```html
<div id="student"
     data-roll="101"
     data-course="PGCP-AC">

    Anurag

</div>
```

JavaScript can access these values through the element's `dataset` property.

## 11.4 Hidden Attribute

```html
<p hidden>
    This content is hidden.
</p>
```

## 11.5 Required Attribute

```html
<input type="text" required>
```

Makes the input mandatory for successful form submission.

---

# 12. ARIA Accessibility

## 12.1 What is Accessibility?

Accessibility means designing websites so that people with different abilities can use them effectively.

Examples of users who benefit from accessible websites:

- People with visual impairments.
- People with hearing impairments.
- People with motor disabilities.
- People using screen readers.
- People navigating through keyboards.

## 12.2 What is ARIA?

ARIA stands for **Accessible Rich Internet Applications**.

It is a set of attributes used to provide additional accessibility information to assistive technologies.

ARIA helps communicate the role, name, state and properties of interactive elements.

## 12.3 Important ARIA Attributes

| Attribute | Purpose |
|---|---|
| `role` | Specifies an accessibility role |
| `aria-label` | Provides an accessible name |
| `aria-labelledby` | References an element that labels another |
| `aria-describedby` | References additional descriptive content |
| `aria-hidden` | Controls exposure to accessibility APIs |
| `aria-expanded` | Communicates expanded or collapsed state |
| `aria-checked` | Communicates checked state |
| `aria-required` | Communicates required state |
| `aria-live` | Announces dynamic content updates |

## 12.4 Example: ARIA Label

```html
<button aria-label="Close menu">
    X
</button>
```

A screen reader can announce the button's accessible name as "Close menu".

## 12.5 Example: aria-expanded

```html
<button aria-expanded="false"
        aria-controls="menu">
    Menu
</button>

<nav id="menu" hidden>
    <a href="home.html">Home</a>
    <a href="about.html">About</a>
</nav>
```

JavaScript would need to update both the `hidden` state and `aria-expanded` state when the menu opens or closes.

## 12.6 Important ARIA Rule

**Use native HTML elements whenever possible.**

For example:

Prefer:

```html
<button>Submit</button>
```

Instead of:

```html
<div role="button" tabindex="0">
    Submit
</div>
```

A native button already provides keyboard and accessibility behavior.

---

# 13. HTML5 Canvas

## 13.1 What is Canvas?

The `<canvas>` element provides a drawable area for graphics using JavaScript.

It can be used to create:

- Shapes.
- Lines.
- Charts.
- Animations.
- Games.
- Interactive graphics.

## 13.2 Canvas Syntax

```html
<canvas id="myCanvas"
        width="400"
        height="300">

    Your browser does not support canvas.

</canvas>
```

## 13.3 Drawing a Rectangle

```html
<!DOCTYPE html>
<html>

<body>

    <canvas id="myCanvas"
            width="400"
            height="300"
            style="border:1px solid black;">
    </canvas>

    <script>

        const canvas =
            document.getElementById("myCanvas");

        const ctx = canvas.getContext("2d");

        ctx.fillStyle = "blue";

        ctx.fillRect(50, 50, 200, 100);

    </script>

</body>
</html>
```

### Explanation

- `getElementById()` selects the canvas.
- `getContext("2d")` creates a 2D drawing context.
- `fillStyle` sets the fill color.
- `fillRect(x, y, width, height)` draws a filled rectangle.

## 13.4 Drawing a Circle

```javascript
ctx.beginPath();

ctx.arc(150, 150, 50, 0, 2 * Math.PI);

ctx.fillStyle = "red";

ctx.fill();
```

## 13.5 Canvas vs SVG

| Canvas | SVG |
|---|---|
| Pixel-based drawing surface | Vector-based graphics |
| Drawing through JavaScript | Uses XML-based markup |
| Individual shapes are not DOM elements | Individual shapes are DOM elements |
| Suitable for games and complex drawing | Suitable for icons and scalable diagrams |
| Can become pixelated when enlarged | Scales without losing vector quality |

---

# 14. HTML5 Form Validation

## 14.1 What is Form Validation?

Form validation checks whether user-entered information satisfies specified requirements before submission.

Example:

A registration form may require:

- Name must not be empty.
- Email must have a valid format.
- Password must satisfy length requirements.
- Age must fall within an allowed range.

## 14.2 HTML5 Built-in Validation Attributes

| Attribute | Purpose |
|---|---|
| `required` | Makes a field mandatory |
| `min` | Minimum numeric/date value |
| `max` | Maximum numeric/date value |
| `minlength` | Minimum text length |
| `maxlength` | Maximum text length |
| `pattern` | Regular-expression constraint |
| `step` | Permitted numeric increments |
| `type="email"` | Checks email format |
| `type="url"` | Checks URL format |

## 14.3 Example: Registration Form

```html
<form>

    <label for="name">Name:</label>

    <input
        type="text"
        id="name"
        name="name"
        required
        minlength="3"
        maxlength="30">

    <br><br>

    <label for="email">Email:</label>

    <input
        type="email"
        id="email"
        name="email"
        required>

    <br><br>

    <label for="age">Age:</label>

    <input
        type="number"
        id="age"
        name="age"
        min="18"
        max="60"
        required>

    <br><br>

    <button type="submit">Register</button>

</form>
```

## 14.4 Pattern Validation

The `pattern` attribute accepts a regular expression.

Example:

```html
<input
    type="text"
    name="username"
    pattern="[A-Za-z]{3,15}"
    title="Enter 3 to 15 letters"
    required>
```

This accepts usernames containing 3 to 15 English letters.

## 14.5 HTML Validation vs JavaScript Validation

| HTML Validation | JavaScript Validation |
|---|---|
| Built into the browser | Implemented using JavaScript |
| Simple constraints | Complex custom rules |
| Uses required, pattern, min, max | Uses conditions and functions |
| Easy to implement | More flexible |
| Limited customization | Supports custom error messages |

**Important:** Browser validation improves usability but does not replace server-side validation. The server must validate submitted data independently.

---

# 15. Audio Support in HTML5

## 15.1 What is the Audio Element?

The `<audio>` element allows audio playback directly in a webpage without requiring external plugins.

Example:

```html
<audio controls>

    <source src="music.mp3"
            type="audio/mpeg">

    <source src="music.ogg"
            type="audio/ogg">

    Your browser does not support audio.

</audio>
```

## 15.2 Important Audio Attributes

| Attribute | Purpose |
|---|---|
| `controls` | Displays playback controls |
| `autoplay` | Requests automatic playback |
| `loop` | Repeats audio |
| `muted` | Starts muted |
| `preload` | Provides a loading hint |

Example:

```html
<audio controls loop>
    <source src="song.mp3" type="audio/mpeg">
</audio>
```

Note: Browsers often block autoplay when audio is not muted or when there has been no user interaction.

---

# 16. Video Support in HTML5

## 16.1 What is the Video Element?

The `<video>` element is used to embed video content in webpages.

Example:

```html
<video width="500"
       height="300"
       controls>

    <source src="movie.mp4"
            type="video/mp4">

    Your browser does not support video.

</video>
```

## 16.2 Important Video Attributes

| Attribute | Purpose |
|---|---|
| `controls` | Displays video controls |
| `autoplay` | Requests automatic playback |
| `loop` | Repeats video |
| `muted` | Starts video muted |
| `poster` | Displays a preview image |
| `width` | Specifies width |
| `height` | Specifies height |
| `preload` | Provides a loading hint |

## 16.3 Audio vs Video

| Audio | Video |
|---|---|
| `<audio>` | `<video>` |
| Plays sound | Plays visual and audio content |
| Does not have a poster attribute | Supports poster |
| Uses audio controls | Uses video controls |

---

# 17. HTML5 Geolocation Support

## 17.1 What is Geolocation?

Geolocation is a browser feature that allows a website to request the user's geographical location.

It is provided through the JavaScript Geolocation API.

Possible applications:

- Maps.
- Navigation.
- Nearby services.
- Location-based applications.
- Weather applications.

## 17.2 How Does Geolocation Work?

1. Website requests location permission.
2. Browser asks the user for permission.
3. User allows or denies access.
4. Browser obtains location information using available device sources.
5. Website receives coordinates if access is granted.

## 17.3 Geolocation Example

```html
<!DOCTYPE html>
<html>

<body>

    <h2>Find My Location</h2>

    <button onclick="getLocation()">
        Get Location
    </button>

    <p id="result"></p>

    <script>

        function getLocation() {

            const result =
                document.getElementById("result");

            if (navigator.geolocation) {

                navigator.geolocation.getCurrentPosition(

                    function(position) {

                        result.innerHTML =
                            "Latitude: " +
                            position.coords.latitude +
                            "<br>Longitude: " +
                            position.coords.longitude;

                    },

                    function(error) {

                        result.innerHTML =
                            "Unable to retrieve location.";

                    }

                );

            } else {

                result.innerHTML =
                    "Geolocation is not supported.";

            }

        }

    </script>

</body>
</html>
```

## 17.4 Important Geolocation Methods

| Method | Purpose |
|---|---|
| `getCurrentPosition()` | Gets the current location once |
| `watchPosition()` | Monitors location changes |
| `clearWatch()` | Stops location monitoring |

Important:

- Geolocation generally requires HTTPS or another secure context such as localhost.
- User permission is required.
- Location accuracy depends on the device and available sources.
- Always handle permission denial and errors.

---

# 18. HTML Forms and Controls

## 18.1 What is an HTML Form?

An HTML form collects information from users and submits it for processing.

Examples:

- Login forms.
- Registration forms.
- Contact forms.
- Resume forms.
- Feedback forms.
- Online application forms.

Tag:

```html
<form>
    Form Controls
</form>
```

## 18.2 Form Attributes

| Attribute | Purpose |
|---|---|
| `action` | Specifies where form data is submitted |
| `method` | Specifies HTTP submission method |
| `enctype` | Specifies request-body encoding |
| `target` | Specifies where the response is displayed |
| `autocomplete` | Controls browser autocomplete |
| `novalidate` | Disables built-in form validation |

Example:

```html
<form action="/register"
      method="post">

    <!-- Form controls -->

</form>
```

## 18.3 GET vs POST in Forms

**GET Method**

```html
<form action="/search" method="get">

    <input type="text" name="query">

    <button type="submit">Search</button>

</form>
```

Form data is commonly appended to the URL as query parameters.

Example:

```text
/search?query=HTML
```

**POST Method**

```html
<form action="/register" method="post">

    <input type="text" name="username">

    <button type="submit">Register</button>

</form>
```

Form data is transmitted in the request body.

For sensitive information, use HTTPS. POST alone does not encrypt data.

## 18.4 Input Element

The `<input>` element creates different types of form controls.

### Text Input

```html
<input type="text"
       name="username"
       placeholder="Enter your name">
```

### Password Input

```html
<input type="password"
       name="password">
```

### Email Input

```html
<input type="email"
       name="email">
```

### Number Input

```html
<input type="number"
       name="age"
       min="18"
       max="60">
```

### Date Input

```html
<input type="date"
       name="dob">
```

### Telephone Input

```html
<input type="tel"
       name="mobile">
```

### URL Input

```html
<input type="url"
       name="website">
```

### File Input

```html
<input type="file"
       name="resume">
```

### Color Input

```html
<input type="color"
       name="color">
```

### Range Input

```html
<input type="range"
       min="0"
       max="100">
```

### Hidden Input

```html
<input type="hidden"
       name="userId"
       value="101">
```

## 18.5 Textarea

The `<textarea>` element accepts multi-line text.

Example:

```html
<label for="address">Address:</label>

<textarea
    id="address"
    name="address"
    rows="4"
    cols="40">
</textarea>
```

Uses:

- Address.
- Feedback.
- Description.
- Comments.
- About Me section.

## 18.6 Radio Button

Radio buttons allow users to select one option from a group of options sharing the same name.

Example:

```html
<p>Select Gender:</p>

<input type="radio"
       id="male"
       name="gender"
       value="Male">

<label for="male">Male</label>

<input type="radio"
       id="female"
       name="gender"
       value="Female">

<label for="female">Female</label>
```

Important: Radio buttons in the same group should use the same `name`.

## 18.7 Checkbox

Checkboxes allow users to select zero or more options.

Example:

```html
<p>Select Skills:</p>

<input type="checkbox"
       name="skills"
       value="Java">

<label>Java</label>

<input type="checkbox"
       name="skills"
       value="Python">

<label>Python</label>

<input type="checkbox"
       name="skills"
       value="React">

<label>React</label>
```

## 18.8 Dropdown List

The `<select>` element creates a dropdown menu.

The `<option>` element defines individual options.

Example:

```html
<label for="course">Select Course:</label>

<select id="course" name="course">

    <option value="">Select Course</option>

    <option value="Java">Java</option>

    <option value="Python">Python</option>

    <option value="MERN">MERN</option>

</select>
```

### Multiple Selection

```html
<select name="skills" multiple>

    <option value="Java">Java</option>

    <option value="Python">Python</option>

    <option value="SQL">SQL</option>

</select>
```

## 18.9 Submit Button

Submits the form.

```html
<button type="submit">Submit</button>
```

## 18.10 Reset Button

Resets form controls to their initial values.

```html
<button type="reset">Reset</button>
```

## 18.11 Normal Button

A normal button does not automatically submit or reset the form.

```html
<button type="button">
    Click Me
</button>
```

### Difference Between Submit, Reset and Button

| Button Type | Purpose |
|---|---|
| Submit | Submits form |
| Reset | Resets form controls |
| Button | Performs custom actions using JavaScript |

## 18.12 Complete HTML Form Example

```html
<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="UTF-8">

    <title>Registration Form</title>

</head>

<body>

    <h1>Student Registration</h1>

    <form action="/register" method="post">

        <label for="name">Name:</label>

        <input type="text"
               id="name"
               name="name"
               required>

        <br><br>

        <label for="email">Email:</label>

        <input type="email"
               id="email"
               name="email"
               required>

        <br><br>

        <label for="password">Password:</label>

        <input type="password"
               id="password"
               name="password"
               required>

        <br><br>

        <label for="dob">Date of Birth:</label>

        <input type="date"
               id="dob"
               name="dob">

        <br><br>

        <p>Gender:</p>

        <input type="radio"
               name="gender"
               value="Male">

        <label>Male</label>

        <input type="radio"
               name="gender"
               value="Female">

        <label>Female</label>

        <br><br>

        <p>Skills:</p>

        <input type="checkbox"
               name="skills"
               value="Java">

        <label>Java</label>

        <input type="checkbox"
               name="skills"
               value="Python">

        <label>Python</label>

        <br><br>

        <label for="course">Course:</label>

        <select id="course"
                name="course">

            <option value="">Select Course</option>

            <option value="PGCP-AC">PGCP-AC</option>

            <option value="PGCP-BDA">PGCP-BDA</option>

        </select>

        <br><br>

        <label for="address">Address:</label>

        <textarea id="address"
                  name="address"
                  rows="4">
        </textarea>

        <br><br>

        <button type="submit">Submit</button>

        <button type="reset">Reset</button>

    </form>

</body>
</html>
```

---

# 19. Introduction to DOM

## 19.1 What is DOM?

DOM stands for **Document Object Model**.

The DOM is a programming interface that represents an HTML document as a structured tree of objects.

JavaScript can use the DOM to access and manipulate webpage elements.

In simple words:

DOM allows JavaScript to interact with HTML.

## 19.2 Why is DOM Required?

Without DOM manipulation, webpages would be largely static.

Using the DOM, JavaScript can:

- Change text.
- Change HTML content.
- Modify CSS styles.
- Add elements.
- Remove elements.
- Respond to user events.
- Validate forms.
- Update webpage content dynamically.

## 19.3 DOM Tree Structure

Consider:

```html
<html>

    <body>

        <h1>Hello</h1>

        <p>Welcome to HTML</p>

    </body>

</html>
```

DOM representation:

```text
           Document
               |
             html
               |
             body
            /    \
          h1      p
          |       |
        Hello   Welcome
                to HTML
```

## 19.4 DOM Node Types

Common DOM node types:

| Node | Meaning |
|---|---|
| Document | Entire document |
| Element | HTML element |
| Text | Text inside elements |
| Attribute | Element attribute |
| Comment | HTML comment |

## 19.5 Selecting Elements Using JavaScript

**getElementById()**

```javascript
document.getElementById("heading");
```

Selects an element using its ID.

**getElementsByClassName()**

```javascript
document.getElementsByClassName("box");
```

Selects elements using a class name.

**getElementsByTagName()**

```javascript
document.getElementsByTagName("p");
```

Selects elements using a tag name.

**querySelector()**

```javascript
document.querySelector(".box");
```

Returns the first element matching a CSS selector.

**querySelectorAll()**

```javascript
document.querySelectorAll("p");
```

Returns all matching elements as a NodeList.

## 19.6 Changing HTML Content

```html
<h1 id="heading">Old Heading</h1>

<script>

    document.getElementById("heading")
        .innerHTML = "New Heading";

</script>
```

## 19.7 Changing Text Content

```javascript
document.getElementById("heading")
    .textContent = "Hello Anurag";
```

Difference:

- `innerHTML` reads or sets HTML markup.
- `textContent` reads or sets text content.

Use `textContent` when inserting ordinary user-provided text to avoid unintentionally interpreting it as HTML.

## 19.8 Changing CSS Using DOM

```html
<p id="demo">Hello World</p>

<script>

    document.getElementById("demo")
        .style.color = "blue";

    document.getElementById("demo")
        .style.fontSize = "25px";

</script>
```

## 19.9 Creating HTML Elements

```javascript
const newElement =
    document.createElement("p");

newElement.textContent =
    "This is a new paragraph.";

document.body.appendChild(newElement);
```

## 19.10 Removing HTML Elements

```javascript
const element =
    document.getElementById("demo");

element.remove();
```

## 19.11 DOM Events

Events represent actions or occurrences that JavaScript can respond to.

Common events:

| Event | Purpose |
|---|---|
| `click` | User clicks an element |
| `dblclick` | User double-clicks |
| `mouseover` | Pointer enters an element |
| `mouseout` | Pointer leaves an element |
| `keydown` | Keyboard key is pressed |
| `keyup` | Keyboard key is released |
| `change` | Control value changes and is committed |
| `input` | Value changes during input |
| `submit` | Form is submitted |
| `focus` | Element receives focus |
| `blur` | Element loses focus |

Example:

```html
<button id="btn">Click Me</button>

<p id="result"></p>

<script>

    document.getElementById("btn")
        .addEventListener("click", function() {

            document.getElementById("result")
                .textContent = "Button Clicked!";

        });

</script>
```

---

# 20. DOM vs HTML

| HTML | DOM |
|---|---|
| Markup language | Programming interface |
| Defines document structure | Represents document structure as objects |
| Written using HTML tags | Accessed using JavaScript and other APIs |
| Describes webpage content | Allows dynamic access and manipulation |

**Important:** The browser parses HTML and constructs a DOM tree. JavaScript can then modify the DOM without necessarily changing the original HTML source file.

---

# 21. Lab Assignment – Build Your Resume Using HTML

## Objective

Create a resume webpage using HTML5 elements and form controls.

The practical should demonstrate the use of:

- HTML document structure.
- Headings.
- Paragraphs.
- Images.
- Lists.
- Tables.
- Anchor tags.
- Form controls.
- HTML5 validation.
- Semantic HTML.

## Requirements

Create a resume form containing the following sections:

### 1. Personal Information

- Full Name.
- Profile Photo.
- Email Address.
- Contact Number.
- Date of Birth.
- Gender.
- Address.

### 2. Career Objective

Use a textarea to collect the career objective.

### 3. Educational Qualification

Create a table containing:

- Qualification.
- Institute.
- University/Board.
- Passing Year.
- Percentage/CGPA.

### 4. Technical Skills

Use checkboxes to select skills.

Examples:

- C.
- C++.
- Java.
- Python.
- HTML.
- CSS.
- JavaScript.
- React.
- MySQL.

### 5. Projects

Use a textarea to describe projects.

### 6. Experience

Include internship or work experience information.

### 7. Certifications

Allow the user to enter certifications.

### 8. Social Profiles

Include hyperlinks to:

- GitHub.
- LinkedIn.
- Portfolio.

### 9. Declaration

Include a declaration checkbox.

### 10. Form Buttons

- Submit.
- Reset.

## Expected Form Structure

```text
           BUILD YOUR RESUME
    --------------------------------

           Personal Details

    Full Name:       [____________]

    Email:           [____________]

    Mobile:          [____________]

    Date of Birth:   [____________]

    Gender:          ( ) Male
                     ( ) Female

    Address:         [____________]

    --------------------------------

           Career Objective

    [                            ]
    [                            ]

    --------------------------------

          Educational Details

    Qualification | Institute | Year | Marks

    --------------------------------

             Technical Skills

    [ ] C
    [ ] C++
    [ ] Java
    [ ] Python
    [ ] HTML
    [ ] CSS
    [ ] JavaScript
    [ ] React

    --------------------------------

               Projects

    [                            ]

    --------------------------------

             Certifications

    [                            ]

    --------------------------------

             Social Profiles

    GitHub:          [____________]

    LinkedIn:        [____________]

    --------------------------------

    [ ] I declare that the information
        provided is correct.

       [ Submit ]  [ Reset ]
```

## Suggested Folder Structure

```text
Resume-Builder/
|
|---- index.html
|
|---- images/
|      |
|      |---- profile.jpg
|
|---- README.md
```

## Expected Learning Outcome

After completing this practical, students should be able to:

1. Create a complete HTML5 document.
2. Use different HTML tags.
3. Organize information using lists and tables.
4. Collect information using forms.
5. Apply basic HTML5 validation.
6. Create hyperlinks and display images.
7. Understand the foundation of DOM manipulation.

**Extension:** In a later JavaScript practical, use the submitted form values to dynamically generate a resume preview.

---

# 22. Important CCEE and Interview Questions

## Basic Questions

**Q1. What is HTML?**

HTML is a standard markup language used to structure webpages.

**Q2. What is the full form of HTML?**

HyperText Markup Language.

**Q3. Who invented HTML?**

Tim Berners-Lee.

**Q4. Is HTML a programming language?**

No. HTML is a markup language.

**Q5. What is HTML5?**

HTML5 is the fifth major version of HTML and introduced semantic elements and several modern web capabilities.

**Q6. What is the purpose of DOCTYPE?**

It tells the browser to use standards mode for rendering the document.

**Q7. What is an HTML attribute?**

An attribute provides additional information or configuration for an element.

**Q8. What is the difference between tag and element?**

A tag is markup such as `<p>`, while an element includes the opening tag, content and closing tag.

**Q9. What is the purpose of the title tag?**

It defines the document title displayed in the browser tab.

**Q10. What is the purpose of the alt attribute?**

It provides alternative text for an image.

## Intermediate Questions

**Q11. What is the difference between block and inline elements?**

Block elements generally start on a new line, while inline elements flow within surrounding text.

**Q12. What is the difference between ordered and unordered lists?**

Ordered lists display sequential numbering or lettering; unordered lists display bullets.

**Q13. What is the purpose of colspan?**

It allows a table cell to span multiple columns.

**Q14. What is the purpose of rowspan?**

It allows a table cell to span multiple rows.

**Q15. What is an iframe?**

An iframe embeds another document or resource within the current webpage.

**Q16. What are semantic elements?**

Elements that describe the meaning and structure of content.

**Q17. What is ARIA?**

ARIA provides additional accessibility information for assistive technologies.

**Q18. What is canvas?**

Canvas is an HTML element used with JavaScript to draw graphics.

**Q19. What is HTML5 form validation?**

It checks whether form input satisfies specified constraints before submission.

**Q20. What is the difference between radio buttons and checkboxes?**

Radio buttons typically allow one selection per group; checkboxes allow multiple independent selections.

## Advanced Questions

**Q21. What is the DOM?**

DOM is a programming interface representing an HTML document as a tree of objects.

**Q22. What is the difference between innerHTML and textContent?**

innerHTML works with HTML markup; textContent works with text content.

**Q23. What is the difference between GET and POST in HTML forms?**

GET places submitted data in the URL query string, while POST generally places it in the request body.

**Q24. What is the difference between id and class?**

ID identifies an element uniquely within a document; class groups elements.

**Q25. What is the difference between HTML validation and JavaScript validation?**

HTML provides built-in constraints, while JavaScript supports custom validation logic.

**Q26. What is the Geolocation API?**

It allows websites to request the user's geographical location with permission.

**Q27. What is the difference between Canvas and SVG?**

Canvas is a pixel-based drawing surface; SVG uses scalable vector graphics.

**Q28. Why should semantic HTML be used?**

It improves document structure, accessibility and maintainability.

**Q29. What is the difference between a button and a submit button?**

A button with `type="button"` does not submit a form automatically; `type="submit"` submits the form.

**Q30. Why is server-side validation required?**

Client-side validation can be bypassed, so the server must independently validate submitted data.

---

# 23. CCEE Practice MCQs

### Q1. HTML stands for:

A. Hyper Text Machine Language  
B. HyperText Markup Language  
C. High Text Markup Language  
D. Hyper Transfer Markup Language

**Answer: B**

### Q2. Who invented HTML?

A. James Gosling  
B. Dennis Ritchie  
C. Tim Berners-Lee  
D. Brendan Eich

**Answer: C**

### Q3. Which tag defines the largest heading level?

A. h6  
B. h1  
C. head  
D. heading

**Answer: B**

### Q4. Which tag creates a hyperlink?

A. img  
B. link  
C. a  
D. href

**Answer: C**

### Q5. Which attribute specifies an image location?

A. href  
B. src  
C. alt  
D. target

**Answer: B**

### Q6. Which tag creates an ordered list?

A. ul  
B. dl  
C. ol  
D. li

**Answer: C**

### Q7. Which tag creates a table row?

A. td  
B. th  
C. tr  
D. table-row

**Answer: C**

### Q8. Which attribute merges table columns?

A. rowspan  
B. colspan  
C. merge  
D. column

**Answer: B**

### Q9. Which tag embeds another webpage?

A. video  
B. iframe  
C. canvas  
D. framebody

**Answer: B**

### Q10. Which element represents the main content of a document?

A. nav  
B. header  
C. main  
D. footer

**Answer: C**

### Q11. ARIA stands for:

A. Accessible Rich Internet Applications  
B. Advanced Rich Internet Access  
C. Application Rich Internet Architecture  
D. Accessible Remote Internet Applications

**Answer: A**

### Q12. Which element is used for JavaScript-based graphics?

A. svg  
B. canvas  
C. img  
D. picture

**Answer: B**

### Q13. Which attribute makes an input mandatory?

A. validate  
B. mandatory  
C. required  
D. compulsory

**Answer: C**

### Q14. Which input type validates an email format?

A. text  
B. email  
C. mail  
D. string

**Answer: B**

### Q15. Which element accepts multi-line text?

A. input  
B. select  
C. textarea  
D. option

**Answer: C**

### Q16. Which input allows multiple independent selections?

A. Radio  
B. Checkbox  
C. Password  
D. Submit

**Answer: B**

### Q17. Which input type is used for date selection?

A. datetime  
B. date  
C. calendar  
D. timeonly

**Answer: B**

### Q18. Which element is used for audio playback?

A. sound  
B. music  
C. audio  
D. media

**Answer: C**

### Q19. Which API is used to access geographical location?

A. Canvas API  
B. Geolocation API  
C. DOM API  
D. Audio API

**Answer: B**

### Q20. DOM stands for:

A. Data Object Model  
B. Document Object Model  
C. Digital Object Method  
D. Document Orientation Model

**Answer: B**

### Q21. Which JavaScript method selects an element by ID?

A. getClass()  
B. getElementById()  
C. queryById()  
D. selectId()

**Answer: B**

### Q22. Which event occurs when a form is submitted?

A. click  
B. change  
C. submit  
D. focus

**Answer: C**

### Q23. Which attribute specifies a unique element identifier?

A. class  
B. id  
C. name  
D. style

**Answer: B**

### Q24. Which tag defines the document title?

A. heading  
B. meta  
C. title  
D. headtitle

**Answer: C**

### Q25. Which element represents complementary content?

A. aside  
B. main  
C. nav  
D. article

**Answer: A**

---

# 24. Quick Revision Sheet

| Topic | Important Point |
|---|---|
| HTML | HyperText Markup Language |
| HTML5 | Modern HTML standard |
| DOCTYPE | Declares document type |
| html | Root element |
| head | Metadata |
| body | Visible webpage content |
| h1–h6 | Headings |
| p | Paragraph |
| br | Line break |
| hr | Thematic break |
| a | Hyperlink |
| img | Image |
| ol | Ordered list |
| ul | Unordered list |
| li | List item |
| table | Table |
| tr | Table row |
| th | Header cell |
| td | Data cell |
| colspan | Merge columns |
| rowspan | Merge rows |
| iframe | Embed another document |
| header | Introductory content |
| nav | Navigation |
| main | Main content |
| section | Thematic content |
| article | Self-contained content |
| footer | Footer |
| ARIA | Accessibility attributes |
| canvas | JavaScript graphics |
| required | Mandatory form field |
| pattern | Regular expression validation |
| audio | Audio playback |
| video | Video playback |
| Geolocation | Location access API |
| input | Form control |
| textarea | Multi-line input |
| select | Dropdown |
| radio | Single selection per group |
| checkbox | Multiple independent selections |
| DOM | Document Object Model |
| querySelector | CSS-selector-based element selection |
| addEventListener | Registers an event listener |

---

# 25. Reference Books and Learning Resources

## Official ACTS Reference Books

**1. Web Development with Node and Express**

Author: Ethan Brown  
Publisher: O'Reilly Media

Relevant concepts:
- Web document structure.
- HTML forms.
- Browser-server interaction.
- Web application development.

**2. JavaScript: The Definitive Guide – 7th Edition**

Author: David Flanagan  
Publisher: O'Reilly Media

Relevant concepts:
- HTML and browser environment.
- DOM.
- JavaScript interaction with HTML.
- Form handling.
- Browser APIs.

**3. React in Depth**

Author: Morten Barklund  
Publisher: O'Reilly Media

Relevant concepts:
- HTML fundamentals for React.
- Semantic markup.
- Component-based UI development.
- Accessibility.

## Additional Official Resources

- [MDN – HTML](https://developer.mozilla.org/en-US/docs/Web/HTML)
- [MDN – HTML Elements Reference](https://developer.mozilla.org/en-US/docs/Web/HTML/Reference/Elements)
- [MDN – HTML Forms](https://developer.mozilla.org/en-US/docs/Learn_web_development/Extensions/Forms)
- [MDN – DOM Introduction](https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model/Introduction)
- [MDN – Canvas API](https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API)
- [MDN – Geolocation API](https://developer.mozilla.org/en-US/docs/Web/API/Geolocation_API)
- [W3C – WAI Accessibility](https://www.w3.org/WAI/)
- [WHATWG – HTML Living Standard](https://html.spec.whatwg.org/)

---

# 26. Final Learning Checklist

Before moving to Session 3, make sure you can:

- [ ] Explain HTML and HTML5.
- [ ] Write the complete HTML5 document structure.
- [ ] Differentiate HTML tags, elements and attributes.
- [ ] Use headings, paragraphs and alignment.
- [ ] Create hyperlinks and display images.
- [ ] Create ordered, unordered and description lists.
- [ ] Create tables using rowspan and colspan.
- [ ] Embed resources using iframes.
- [ ] Explain semantic HTML5 elements.
- [ ] Understand global HTML attributes.
- [ ] Explain ARIA accessibility.
- [ ] Draw graphics using Canvas.
- [ ] Apply HTML5 form validation.
- [ ] Embed audio and video.
- [ ] Explain Geolocation API.
- [ ] Create forms using different controls.
- [ ] Understand DOM and DOM tree structure.
- [ ] Select and manipulate HTML elements using JavaScript.
- [ ] Complete the resume-building lab assignment.

---

# 🎯 Session 2 Completion Goal

After completing this session, you should be able to independently create a structured HTML5 webpage, build forms, display multimedia, use semantic elements and understand how JavaScript interacts with HTML through the DOM.

**Learn → Understand → Code → Practice → Revise**

⭐ If these notes are useful, consider starring the repository and sharing improvements.

**Happy Learning! 🚀**
