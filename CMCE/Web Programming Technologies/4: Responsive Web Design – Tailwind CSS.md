# Session 4: Responsive Web Design – Tailwind CSS

**Course:** Web Programming Technologies  
**Batch:** CMCE – August 2026  
**Duration:** 2 Theory + 2 Lab + 2 Self-Learning Sessions

---

# 1. Introduction to Responsive Web Design

## 1.1 What is Responsive Web Design?

Responsive Web Design (RWD) is an approach to web development in which a website automatically adjusts its layout and appearance according to the screen size and device.

A responsive website should work properly on:

- Desktop computers
- Laptops
- Tablets
- Mobile phones

For example, a desktop webpage may display three cards in one row, while the same webpage may display one card per row on a mobile phone.

## 1.2 Why is Responsive Web Design Required?

Different users access websites using different devices and screen sizes.

Responsive design helps to:

1. Improve the user experience.
2. Avoid horizontal scrolling on mobile devices.
3. Make text and images readable.
4. Improve navigation on smaller screens.
5. Reuse the same webpage across different devices.
6. Reduce the need to create separate mobile and desktop websites.

## 1.3 Common Responsive Design Techniques

| Technique | Purpose |
|---|---|
| Flexible layouts | Adjust element sizes according to available space |
| CSS Flexbox | Arrange elements in rows or columns |
| CSS Grid | Create responsive row-and-column layouts |
| Media queries | Apply CSS based on viewport conditions |
| Relative units | Use flexible measurements such as `%`, `rem`, and `fr` |
| Responsive images | Display suitable image sizes |
| Viewport meta tag | Make the layout use the device's viewport width |

Important HTML viewport configuration:

```html
<meta name="viewport" content="width=device-width, initial-scale=1.0">
```

Without this configuration, mobile browsers may use a wider virtual layout viewport, making responsive layouts behave unexpectedly.

---

# 2. Introduction to Utility-First CSS

## 2.1 What is Tailwind CSS?

Tailwind CSS is a utility-first CSS framework used to style webpages using predefined utility classes directly in HTML.

Instead of writing separate CSS rules for every element, developers combine small utility classes to create the required design.

For example, normal CSS:

```html
<h1 class="heading">Hello World</h1>
```

```css
.heading {
    color: blue;
    font-size: 30px;
    font-weight: bold;
    text-align: center;
}
```

Using Tailwind CSS:

```html
<h1 class="text-3xl font-bold text-blue-600 text-center">
    Hello World
</h1>
```

The Tailwind classes perform the styling directly.

## 2.2 What is Utility-First CSS?

Utility-first CSS means using small, single-purpose classes to style HTML elements.

Examples:

| Tailwind Class | Purpose |
|---|---|
| `text-center` | Centers text |
| `text-red-500` | Sets text color |
| `bg-blue-500` | Sets background color |
| `p-4` | Adds padding |
| `m-4` | Adds margin |
| `font-bold` | Makes text bold |
| `rounded-lg` | Adds rounded corners |
| `shadow-md` | Adds a medium shadow |
| `flex` | Enables Flexbox |
| `grid` | Enables CSS Grid |

## 2.3 Why Use Tailwind CSS?

1. Faster UI development.
2. Less need to write custom CSS.
3. Consistent spacing and colors.
4. Responsive design using prefixes.
5. Easy customization.
6. Reusable styling patterns.
7. Works with HTML, React, Vue, and other frontend technologies.

## 2.4 Tailwind CSS vs Traditional CSS

| Traditional CSS | Tailwind CSS |
|---|---|
| Write CSS rules separately | Use utility classes |
| Create custom class names | Combine predefined classes |
| Maintain separate CSS selectors | Many styles are written in HTML |
| Responsive design using media queries | Responsive prefixes such as `sm:` and `md:` |
| Custom styles are written manually | Existing utilities can be combined |

**Important:** Tailwind CSS does not replace CSS. It generates CSS from utility classes. Understanding normal CSS is essential for using Tailwind effectively.

---

# 3. Tailwind Setup and Configuration

Tailwind CSS can be used through a build tool such as Vite or through a CDN for quick experiments.

For practical development, use npm and Vite.

## 3.1 Check Node.js and npm

Open the terminal and execute:

```bash
node -v
npm -v
```

Both commands should display installed versions.

## 3.2 Create a Vite Project

For a basic HTML and CSS practical:

```bash
npm create vite@latest tailwind-resume -- --template vanilla
```

Navigate to the project:

```bash
cd tailwind-resume
```

Install the project dependencies:

```bash
npm install
```

## 3.3 Install Tailwind CSS

The following setup uses Tailwind CSS v4 with the official Vite plugin.

```bash
npm install tailwindcss @tailwindcss/vite
```

## 3.4 Configure vite.config.js

Open `vite.config.js` and add the Tailwind plugin.

```javascript
import { defineConfig } from 'vite'
import tailwindcss from '@tailwindcss/vite'

export default defineConfig({
    plugins: [
        tailwindcss(),
    ],
})
```

## 3.5 Import Tailwind CSS

Open `src/style.css` and add:

```css
@import "tailwindcss";
```

This imports Tailwind CSS into the project.

## 3.6 Link CSS to HTML

In `index.html`, ensure the stylesheet is imported:

```html
<link rel="stylesheet" href="/src/style.css">
```

## 3.7 Test Tailwind CSS

Open `index.html` and replace the body content with:

```html
<body class="bg-gray-100">

    <h1 class="text-3xl font-bold text-blue-600 text-center mt-10">
        Welcome to Tailwind CSS
    </h1>

</body>
```

## 3.8 Run the Project

```bash
npm run dev
```

Open the local URL shown in the terminal.

You should see a blue, bold, centered heading.

## 3.9 Project Structure

```text
tailwind-resume/
│
├── index.html
├── package.json
├── vite.config.js
│
└── src/
    └── style.css
```

## 3.10 What Happens Internally?

1. You write Tailwind utility classes in HTML.
2. Tailwind scans your source files for class names.
3. It generates the CSS needed for the detected classes.
4. Vite serves the generated styles during development.
5. The browser displays the styled webpage.

Tailwind generates CSS at build time; it does not need a JavaScript styling engine running in the browser.

**Version note:** This chapter uses Tailwind CSS v4 for installation and theme examples. Older tutorials may use Tailwind v3, which has a different setup process.

---

# 4. Core Utilities: Spacing

Tailwind provides utility classes for controlling margin, padding, width, height, and gaps.

## 4.1 Padding

Padding is the space inside an element, between its content and border.

Normal CSS:

```css
.box {
    padding: 16px;
}
```

Tailwind:

```html
<div class="p-4">
    This is a padded box.
</div>
```

Common padding utilities:

| Class | Meaning |
|---|---|
| `p-2` | Padding on all sides |
| `p-4` | Padding on all sides |
| `px-4` | Horizontal padding |
| `py-4` | Vertical padding |
| `pt-4` | Top padding |
| `pb-4` | Bottom padding |
| `ps-4` | Padding at inline start |
| `pe-4` | Padding at inline end |

## 4.2 Margin

Margin is the space outside an element.

Normal CSS:

```css
.box {
    margin: 16px;
}
```

Tailwind:

```html
<div class="m-4">
    This box has margin.
</div>
```

Common margin utilities:

| Class | Meaning |
|---|---|
| `m-4` | Margin on all sides |
| `mx-4` | Horizontal margin |
| `my-4` | Vertical margin |
| `mt-4` | Top margin |
| `mb-4` | Bottom margin |
| `ml-4` | Left margin in left-to-right layouts |
| `mr-4` | Right margin in left-to-right layouts |
| `mx-auto` | Automatic horizontal margins |

Example:

```html
<div class="mx-auto mt-8 max-w-xl">
    Centered container
</div>
```

## 4.3 Width and Height

| Class | Purpose |
|---|---|
| `w-full` | Width 100% |
| `w-1/2` | Width 50% |
| `w-1/3` | Width one-third |
| `w-screen` | Width of viewport |
| `h-full` | Height 100% |
| `h-screen` | Height of viewport |
| `min-h-screen` | Minimum height of viewport |
| `max-w-xl` | Maximum width using the XL size |

Example:

```html
<div class="w-full max-w-lg mx-auto">
    Responsive container
</div>
```

## 4.4 Gap

Gap controls the spacing between child elements in Flexbox and Grid layouts.

```html
<div class="flex gap-4">
    <div>One</div>
    <div>Two</div>
    <div>Three</div>
</div>
```

Other examples:

```html
<div class="grid grid-cols-2 gap-6">
    ...
</div>
```

---

# 5. Core Utilities: Typography

Typography controls the appearance of text.

## 5.1 Font Size

| Class | Purpose |
|---|---|
| `text-xs` | Extra small text |
| `text-sm` | Small text |
| `text-base` | Normal text |
| `text-lg` | Large text |
| `text-xl` | Extra large text |
| `text-2xl` | 2XL text |
| `text-3xl` | 3XL text |
| `text-4xl` | 4XL text |

Example:

```html
<h1 class="text-4xl">
    Welcome
</h1>

<p class="text-base">
    Learn Tailwind CSS.
</p>
```

## 5.2 Font Weight

| Class | Purpose |
|---|---|
| `font-thin` | Thin text |
| `font-light` | Light text |
| `font-normal` | Normal text |
| `font-medium` | Medium text |
| `font-semibold` | Semi-bold text |
| `font-bold` | Bold text |
| `font-extrabold` | Extra bold text |

Example:

```html
<h1 class="font-bold">
    My Resume
</h1>
```

## 5.3 Text Alignment

| Class | Purpose |
|---|---|
| `text-left` | Align left |
| `text-center` | Align center |
| `text-right` | Align right |
| `text-justify` | Justify text |

Example:

```html
<p class="text-center">
    Center aligned paragraph
</p>
```

## 5.4 Text Decoration

```html
<p class="underline">
    Underlined text
</p>

<p class="line-through">
    Strikethrough text
</p>

<p class="no-underline">
    No underline
</p>
```

## 5.5 Text Transform

```html
<p class="uppercase">hello world</p>

<p class="lowercase">HELLO WORLD</p>

<p class="capitalize">hello world</p>
```

## 5.6 Line Height

Controls the vertical distance between lines.

```html
<p class="leading-relaxed">
    This is a paragraph with relaxed line spacing.
</p>
```

Other classes include:

- `leading-tight`
- `leading-normal`
- `leading-loose`

---

# 6. Core Utilities: Colours

Tailwind provides predefined color palettes.

## 6.1 Text Colors

```html
<p class="text-red-500">Red text</p>

<p class="text-blue-600">Blue text</p>

<p class="text-green-500">Green text</p>

<p class="text-gray-700">Gray text</p>
```

## 6.2 Background Colors

```html
<div class="bg-blue-500">
    Blue background
</div>

<div class="bg-yellow-200">
    Yellow background
</div>
```

## 6.3 Color Shades

Tailwind provides different shades of a color.

For example:

```html
<div class="bg-blue-100">Blue 100</div>
<div class="bg-blue-300">Blue 300</div>
<div class="bg-blue-500">Blue 500</div>
<div class="bg-blue-700">Blue 700</div>
<div class="bg-blue-900">Blue 900</div>
```

Generally, smaller shade numbers are lighter and larger numbers are darker.

## 6.4 Opacity

You can control color opacity using slash notation.

```html
<div class="bg-blue-500/50">
    50% background opacity
</div>
```

---

# 7. Core Utilities: Borders

Tailwind provides utilities for border width, color, radius, and style.

## 7.1 Border Width

```html
<div class="border">
    Normal border
</div>

<div class="border-2">
    2px border
</div>

<div class="border-4">
    4px border
</div>
```

## 7.2 Border Color

```html
<div class="border border-blue-500">
    Blue border
</div>
```

## 7.3 Border Radius

| Class | Purpose |
|---|---|
| `rounded-none` | No rounded corners |
| `rounded-sm` | Small radius |
| `rounded` | Default radius |
| `rounded-md` | Medium radius |
| `rounded-lg` | Large radius |
| `rounded-xl` | Extra large radius |
| `rounded-full` | Fully rounded |

Example:

```html
<div class="border border-gray-300 rounded-lg p-4">
    Rounded card
</div>
```

## 7.4 Border Style

```html
<div class="border-2 border-solid">
    Solid border
</div>

<div class="border-2 border-dashed">
    Dashed border
</div>

<div class="border-2 border-dotted">
    Dotted border
</div>
```

## 7.5 Shadow Utilities

```html
<div class="shadow-sm">Small shadow</div>

<div class="shadow-md">Medium shadow</div>

<div class="shadow-lg">Large shadow</div>

<div class="shadow-xl">Extra large shadow</div>
```

---

# 8. Responsive Prefixes

## 8.1 What are Responsive Prefixes?

Responsive prefixes are modifiers added before Tailwind utility classes to apply styles at specific viewport widths.

They allow us to change the layout according to screen size.

For example:

```html
<div class="text-sm md:text-xl lg:text-3xl">
    Responsive Text
</div>
```

Meaning:

- Default: Small text.
- At medium screens and above: Extra large text.
- At large screens and above: 3XL text.

## 8.2 Default Breakpoints

Tailwind CSS v4 uses these default breakpoints:

| Prefix | Minimum viewport width | Meaning |
|---|---:|---|
| No prefix | All sizes | Default styles |
| `sm:` | 40rem (640px) | Small screens and above |
| `md:` | 48rem (768px) | Medium screens and above |
| `lg:` | 64rem (1024px) | Large screens and above |
| `xl:` | 80rem (1280px) | Extra large screens and above |
| `2xl:` | 96rem (1536px) | 2XL screens and above |

These are mobile-first, minimum-width breakpoints.

## 8.3 Mobile-First Approach

Tailwind uses a mobile-first approach.

This means:
- Write default utility classes for smaller screens.
- Add responsive prefixes to modify the design for larger screens.

Example:

```html
<div class="text-sm md:text-lg lg:text-2xl">
    Responsive heading
</div>
```

The default style applies everywhere. The `md:` and `lg:` styles override it when their minimum widths are reached.

## 8.4 Responsive Width

```html
<div class="w-full md:w-1/2 lg:w-1/3">
    Responsive Box
</div>
```

Meaning:

- Mobile: 100% width.
- Medium and above: 50% width.
- Large and above: One-third width.

## 8.5 Responsive Grid

```html
<div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-4">

    <div class="bg-blue-200 p-4">Card 1</div>
    <div class="bg-blue-200 p-4">Card 2</div>
    <div class="bg-blue-200 p-4">Card 3</div>

</div>
```

Layout:

- Mobile: One column.
- Tablet: Two columns.
- Desktop: Three columns.

## 8.6 Responsive Flexbox

```html
<div class="flex flex-col md:flex-row gap-4">

    <div class="bg-blue-200 p-4">Left</div>

    <div class="bg-green-200 p-4">Right</div>

</div>
```

On mobile, the items are stacked vertically.

On medium and larger screens, they are displayed horizontally.

## 8.7 Responsive Visibility

```html
<div class="block md:hidden">
    Visible only below medium breakpoint
</div>

<div class="hidden md:block">
    Visible from medium breakpoint onwards
</div>
```

## 8.8 Responsive Padding

```html
<div class="p-3 md:p-6 lg:p-10">
    Responsive padding
</div>
```

## 8.9 Responsive Text Alignment

```html
<h1 class="text-center md:text-left">
    Responsive Heading
</h1>
```

## 8.10 Important Concept: Prefixes Apply Upwards

For example:

```html
<div class="bg-red-500 md:bg-blue-500 lg:bg-green-500">
    Responsive Background
</div>
```

- Below 768px: Red.
- 768px and above: Blue.
- 1024px and above: Green.

Remember: `md:` does not mean only tablet. It applies at the medium breakpoint and all larger widths unless another rule overrides it.

---

# 9. Dark Mode with Tailwind CSS

## 9.1 What is Dark Mode?

Dark mode is a user-interface theme that uses darker backgrounds and lighter text.

Example:

Light mode:
- White background.
- Dark text.

Dark mode:
- Dark background.
- Light text.

Advantages:
1. Provides an alternative appearance.
2. Can be more comfortable in low-light environments.
3. Allows users to select their preferred theme.

## 9.2 Using the dark: Prefix

Tailwind provides the `dark:` variant.

Example:

```html
<div class="bg-white text-black dark:bg-gray-900 dark:text-white p-6">

    <h1 class="text-2xl font-bold">
        Welcome
    </h1>

    <p>
        This content supports dark mode.
    </p>

</div>
```

The dark styles apply when the dark-mode condition is active.

## 9.3 System-Based Dark Mode

By default, Tailwind's dark variant follows the operating system's color-scheme preference.

The browser checks whether the user prefers a dark color scheme.

Example:

```html
<body class="bg-white text-gray-900 dark:bg-gray-950 dark:text-white">

    <h1 class="text-3xl font-bold">
        My Website
    </h1>

</body>
```

## 9.4 Manual Dark Mode

Sometimes we want users to switch between light and dark modes using a button.

For Tailwind CSS v4, add this to your CSS file:

```css
@import "tailwindcss";

@custom-variant dark (&:where(.dark, .dark *));
```

Now dark mode can be controlled by adding the `dark` class to the HTML element.

Example:

```html
<html class="dark">
<body>

    <div class="bg-white text-black dark:bg-gray-900 dark:text-white">
        Dark Mode Example
    </div>

</body>
</html>
```

## 9.5 Simple Dark Mode Toggle Using JavaScript

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Dark Mode</title>
    <link rel="stylesheet" href="/src/style.css">
</head>

<body class="bg-white text-gray-900 dark:bg-gray-900 dark:text-white">

    <div class="p-8 text-center">

        <h1 class="text-3xl font-bold mb-4">
            Dark Mode Example
        </h1>

        <button
            id="themeButton"
            class="rounded-lg bg-blue-600 px-5 py-2 text-white hover:bg-blue-700"
        >
            Toggle Theme
        </button>

    </div>

    <script>
        const button = document.getElementById("themeButton");

        button.addEventListener("click", () => {
            document.documentElement.classList.toggle("dark");
        });
    </script>

</body>
</html>
```

The button adds or removes the `dark` class from the root HTML element.

This example is a basic toggle and does not save the user's preference after reloading the page.

---

# 10. Custom Themes with Tailwind CSS

## 10.1 What is a Theme?

A theme defines the design system of an application.

It may contain:
- Colors
- Fonts
- Font sizes
- Spacing
- Breakpoints
- Border radius
- Shadows

Tailwind allows us to customize these design values.

## 10.2 Custom Theme in Tailwind CSS v4

Tailwind v4 uses the `@theme` directive to define custom theme variables.

Example:

```css
@import "tailwindcss";

@theme {
    --color-primary: #17365d;
    --color-secondary: #e8f0fe;
    --color-accent: #f59e0b;

    --font-display: Arial, sans-serif;

    --breakpoint-3xl: 120rem;
}
```

Now these utilities can be used:

```html
<h1 class="text-primary font-display text-3xl">
    Custom Theme Heading
</h1>

<div class="bg-secondary p-6">
    Custom Theme Container
</div>

<button class="bg-accent text-white p-3 rounded-lg">
    Submit
</button>
```

## 10.3 Why Use Custom Themes?

1. Maintain a consistent design.
2. Reuse brand colors.
3. Define custom fonts.
4. Customize responsive breakpoints.
5. Make future design changes easier.

## 10.4 Custom Breakpoints

Example:

```css
@import "tailwindcss";

@theme {
    --breakpoint-xs: 30rem;
    --breakpoint-3xl: 120rem;
}
```

You can now use:

```html
<div class="text-sm xs:text-base 3xl:text-3xl">
    Custom Breakpoint Example
</div>
```

---

# 11. @apply for Component Extraction

## 11.1 What is @apply?

`@apply` is a Tailwind CSS directive used to combine existing utility classes into a custom CSS class.

It is useful when the same collection of utility classes is repeated many times.

Without `@apply`:

```html
<button class="bg-blue-600 text-white px-5 py-2 rounded-lg font-semibold">
    Save
</button>

<button class="bg-blue-600 text-white px-5 py-2 rounded-lg font-semibold">
    Submit
</button>
```

With `@apply`:

CSS:

```css
@import "tailwindcss";

.btn-primary {
    @apply bg-blue-600 text-white px-5 py-2 rounded-lg font-semibold;
}
```

HTML:

```html
<button class="btn-primary">
    Save
</button>

<button class="btn-primary">
    Submit
</button>
```

## 11.2 Another Example: Form Input

CSS:

```css
.form-input {
    @apply w-full rounded-lg border border-gray-300 px-4 py-2 outline-none;
}
```

HTML:

```html
<input type="text" class="form-input">

<input type="email" class="form-input">
```

## 11.3 Advantages of @apply

- Reduces repeated utility class combinations.
- Helps create reusable styling patterns.
- Useful when styling third-party HTML elements.
- Keeps repeated component styles consistent.

## 11.4 When Should You Use @apply?

Use it when:
- The same utility combination appears repeatedly.
- You need to style a third-party component.
- You want a reusable custom CSS class.

Avoid using it for every element. Tailwind's normal approach is to use utility classes directly in HTML.

**Important:** `@apply` is processed by Tailwind. It will not work in an ordinary CSS file unless that file is processed by the Tailwind build system.

---

# 12. Responsive Design with Tailwind CSS

Responsive design combines Tailwind utilities with responsive prefixes.

## 12.1 Responsive Container

```html
<div class="mx-auto w-full max-w-6xl px-4">

    <h1 class="text-3xl font-bold text-center">
        Responsive Website
    </h1>

</div>
```

## 12.2 Responsive Card Layout

```html
<div class="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6 p-4">

    <div class="rounded-lg bg-white p-6 shadow-md">
        Card 1
    </div>

    <div class="rounded-lg bg-white p-6 shadow-md">
        Card 2
    </div>

    <div class="rounded-lg bg-white p-6 shadow-md">
        Card 3
    </div>

</div>
```

## 12.3 Responsive Navigation Bar

```html
<nav class="flex flex-col gap-4 bg-blue-900 p-4 text-white md:flex-row md:items-center md:justify-between">

    <h1 class="text-2xl font-bold">
        My Website
    </h1>

    <div class="flex flex-col gap-3 md:flex-row md:gap-6">

        <a href="#" class="hover:text-yellow-300">Home</a>

        <a href="#" class="hover:text-yellow-300">About</a>

        <a href="#" class="hover:text-yellow-300">Contact</a>

    </div>

</nav>
```

## 12.4 Responsive Image

```html
<img
    src="profile.jpg"
    alt="Profile"
    class="h-48 w-48 rounded-full object-cover"
/>
```

## 12.5 Responsive Two-Column Layout

```html
<div class="grid grid-cols-1 gap-6 md:grid-cols-2">

    <div class="bg-blue-100 p-6">
        Left Section
    </div>

    <div class="bg-green-100 p-6">
        Right Section
    </div>

</div>
```

## 12.6 Responsive Form Layout

```html
<form class="mx-auto grid max-w-4xl grid-cols-1 gap-5 rounded-xl bg-white p-6 shadow-lg md:grid-cols-2">

    <div>
        <label class="mb-2 block font-medium">First Name</label>
        <input type="text" class="w-full rounded-lg border p-3">
    </div>

    <div>
        <label class="mb-2 block font-medium">Last Name</label>
        <input type="text" class="w-full rounded-lg border p-3">
    </div>

    <div class="md:col-span-2">
        <label class="mb-2 block font-medium">Address</label>
        <textarea class="w-full rounded-lg border p-3"></textarea>
    </div>

    <button class="rounded-lg bg-blue-600 p-3 text-white md:col-span-2">
        Submit
    </button>

</form>
```

On small screens, fields are arranged in one column.

On medium and larger screens, the first two fields appear side by side.

---

# 13. LAB PRACTICAL 1: Rebuild Resume Form Using Tailwind CSS Utility Classes

## Objective

Create a resume form using Tailwind CSS utility classes instead of writing a large external CSS stylesheet.

## Project Structure

```text
tailwind-resume/
│
├── index.html
├── package.json
├── vite.config.js
│
└── src/
    └── style.css
```

Use the Vite and Tailwind installation steps from Section 3.

## Complete index.html

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">

    <meta name="viewport"
          content="width=device-width, initial-scale=1.0">

    <title>Resume Form - Tailwind CSS</title>

    <link rel="stylesheet" href="/src/style.css">
</head>

<body class="min-h-screen bg-gray-100 px-4 py-8">

    <div class="mx-auto max-w-4xl rounded-xl bg-white p-6 shadow-lg md:p-10">

        <!-- Header -->

        <header class="mb-8 text-center">

            <h1 class="text-3xl font-bold text-blue-900 md:text-4xl">
                Resume Builder
            </h1>

            <p class="mt-2 text-gray-600">
                Enter your details to create your resume.
            </p>

        </header>

        <!-- Form -->

        <form class="space-y-8">

            <!-- Personal Information -->

            <section>

                <h2 class="mb-5 border-b-2 border-blue-600 pb-2 text-xl font-bold text-blue-900">
                    Personal Information
                </h2>

                <div class="grid grid-cols-1 gap-5 md:grid-cols-2">

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            Full Name
                        </label>

                        <input
                            type="text"
                            placeholder="Enter your full name"
                            required
                            class="w-full rounded-lg border border-gray-300 px-4 py-3 outline-none focus:border-blue-500 focus:ring-2 focus:ring-blue-200"
                        >
                    </div>

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            Email
                        </label>

                        <input
                            type="email"
                            placeholder="Enter your email"
                            required
                            class="w-full rounded-lg border border-gray-300 px-4 py-3 outline-none focus:border-blue-500 focus:ring-2 focus:ring-blue-200"
                        >
                    </div>

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            Mobile Number
                        </label>

                        <input
                            type="tel"
                            placeholder="Enter mobile number"
                            required
                            class="w-full rounded-lg border border-gray-300 px-4 py-3 outline-none focus:border-blue-500 focus:ring-2 focus:ring-blue-200"
                        >
                    </div>

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            Date of Birth
                        </label>

                        <input
                            type="date"
                            class="w-full rounded-lg border border-gray-300 px-4 py-3"
                        >
                    </div>

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            Gender
                        </label>

                        <select
                            class="w-full rounded-lg border border-gray-300 bg-white px-4 py-3"
                        >
                            <option value="">Select Gender</option>
                            <option>Male</option>
                            <option>Female</option>
                            <option>Other</option>
                        </select>
                    </div>

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            City
                        </label>

                        <input
                            type="text"
                            placeholder="Enter city"
                            class="w-full rounded-lg border border-gray-300 px-4 py-3"
                        >
                    </div>

                    <div class="md:col-span-2">
                        <label class="mb-2 block font-medium text-gray-700">
                            Address
                        </label>

                        <textarea
                            rows="3"
                            placeholder="Enter your complete address"
                            class="w-full rounded-lg border border-gray-300 px-4 py-3"
                        ></textarea>
                    </div>

                </div>

            </section>

            <!-- Career Objective -->

            <section>

                <h2 class="mb-5 border-b-2 border-blue-600 pb-2 text-xl font-bold text-blue-900">
                    Career Objective
                </h2>

                <textarea
                    rows="4"
                    placeholder="Write your career objective"
                    class="w-full rounded-lg border border-gray-300 px-4 py-3"
                ></textarea>

            </section>

            <!-- Education -->

            <section>

                <h2 class="mb-5 border-b-2 border-blue-600 pb-2 text-xl font-bold text-blue-900">
                    Education
                </h2>

                <div class="grid grid-cols-1 gap-5 md:grid-cols-2">

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            Qualification
                        </label>

                        <input
                            type="text"
                            placeholder="BE / BTech / Diploma"
                            class="w-full rounded-lg border border-gray-300 px-4 py-3"
                        >
                    </div>

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            Institute Name
                        </label>

                        <input
                            type="text"
                            placeholder="Enter institute name"
                            class="w-full rounded-lg border border-gray-300 px-4 py-3"
                        >
                    </div>

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            Passing Year
                        </label>

                        <input
                            type="number"
                            placeholder="2026"
                            class="w-full rounded-lg border border-gray-300 px-4 py-3"
                        >
                    </div>

                    <div>
                        <label class="mb-2 block font-medium text-gray-700">
                            Percentage / CGPA
                        </label>

                        <input
                            type="text"
                            placeholder="Enter percentage or CGPA"
                            class="w-full rounded-lg border border-gray-300 px-4 py-3"
                        >
                    </div>

                </div>

            </section>

            <!-- Technical Skills -->

            <section>

                <h2 class="mb-5 border-b-2 border-blue-600 pb-2 text-xl font-bold text-blue-900">
                    Technical Skills
                </h2>

                <div class="grid grid-cols-2 gap-4 sm:grid-cols-3">

                    <label class="flex items-center gap-2">
                        <input type="checkbox" class="h-4 w-4">
                        Java
                    </label>

                    <label class="flex items-center gap-2">
                        <input type="checkbox" class="h-4 w-4">
                        Python
                    </label>

                    <label class="flex items-center gap-2">
                        <input type="checkbox" class="h-4 w-4">
                        React
                    </label>

                    <label class="flex items-center gap-2">
                        <input type="checkbox" class="h-4 w-4">
                        MySQL
                    </label>

                    <label class="flex items-center gap-2">
                        <input type="checkbox" class="h-4 w-4">
                        HTML
                    </label>

                    <label class="flex items-center gap-2">
                        <input type="checkbox" class="h-4 w-4">
                        CSS
                    </label>

                </div>

            </section>

            <!-- Projects -->

            <section>

                <h2 class="mb-5 border-b-2 border-blue-600 pb-2 text-xl font-bold text-blue-900">
                    Projects
                </h2>

                <textarea
                    rows="4"
                    placeholder="Describe your projects"
                    class="w-full rounded-lg border border-gray-300 px-4 py-3"
                ></textarea>

            </section>

            <!-- Certifications -->

            <section>

                <h2 class="mb-5 border-b-2 border-blue-600 pb-2 text-xl font-bold text-blue-900">
                    Certifications
                </h2>

                <textarea
                    rows="3"
                    placeholder="Enter your certifications"
                    class="w-full rounded-lg border border-gray-300 px-4 py-3"
                ></textarea>

            </section>

            <!-- Declaration -->

            <section>

                <h2 class="mb-4 border-b-2 border-blue-600 pb-2 text-xl font-bold text-blue-900">
                    Declaration
                </h2>

                <label class="flex items-start gap-3 text-sm text-gray-700">

                    <input
                        type="checkbox"
                        required
                        class="mt-1 h-4 w-4"
                    >

                    <span>
                        I hereby declare that the information provided
                        above is true to the best of my knowledge.
                    </span>

                </label>

            </section>

            <!-- Buttons -->

            <div class="flex flex-col gap-4 sm:flex-row">

                <button
                    type="submit"
                    class="flex-1 rounded-lg bg-blue-700 px-6 py-3 font-semibold text-white hover:bg-blue-800"
                >
                    Submit Resume
                </button>

                <button
                    type="reset"
                    class="flex-1 rounded-lg border border-gray-400 px-6 py-3 font-semibold text-gray-700 hover:bg-gray-100"
                >
                    Reset Form
                </button>

            </div>

        </form>

    </div>

</body>
</html>
```

## src/style.css

```css
@import "tailwindcss";
```

## Practical Explanation

Some important classes used in the resume:

| Class | Purpose |
|---|---|
| `min-h-screen` | Minimum height of the viewport |
| `bg-gray-100` | Light gray background |
| `mx-auto` | Centers the container horizontally |
| `max-w-4xl` | Restricts maximum container width |
| `rounded-xl` | Rounded corners |
| `shadow-lg` | Large shadow |
| `p-6` | Padding on all sides |
| `md:p-10` | Larger padding at medium breakpoint |
| `grid` | Enables CSS Grid |
| `grid-cols-1` | One column |
| `md:grid-cols-2` | Two columns at medium breakpoint |
| `gap-5` | Space between grid items |
| `md:col-span-2` | Makes an item span two columns |
| `focus:ring-2` | Displays a focus ring |
| `hover:bg-blue-800` | Changes background on hover |

**Expected result:** A clean resume form with a single-column layout on mobile and a two-column layout for appropriate fields on larger screens.

---

# 14. LAB PRACTICAL 2: Make the Layout Fully Responsive Using Tailwind Breakpoints

## Objective

Modify the resume form so it works on:
- Mobile phones
- Tablets
- Laptops
- Desktop monitors

## Step 1: Responsive Container

Use:

```html
<div class="mx-auto w-full max-w-5xl px-3 sm:px-5 md:px-8">
```

Explanation:

- Default: Small horizontal padding.
- `sm:` Larger padding.
- `md:` More padding.
- `max-w-5xl`: Limits the container width.

## Step 2: Responsive Header

```html
<header class="flex flex-col items-center gap-3 text-center md:flex-row md:justify-between md:text-left">

    <div>
        <h1 class="text-2xl font-bold sm:text-3xl md:text-4xl">
            Resume Builder
        </h1>

        <p class="text-sm text-gray-500 sm:text-base">
            Create your professional resume
        </p>
    </div>

    <button class="rounded-lg bg-blue-600 px-5 py-2 text-white">
        Help
    </button>

</header>
```

## Step 3: Responsive Form Fields

```html
<div class="grid grid-cols-1 gap-4 sm:grid-cols-2 lg:grid-cols-3">

    <input type="text" placeholder="First Name"
           class="rounded-lg border p-3">

    <input type="text" placeholder="Last Name"
           class="rounded-lg border p-3">

    <input type="email" placeholder="Email"
           class="rounded-lg border p-3">

</div>
```

Layout:

- Mobile: One column.
- Small screens and above: Two columns.
- Large screens and above: Three columns.

## Step 4: Responsive Education Section

```html
<div class="grid grid-cols-1 gap-5 md:grid-cols-2">

    <input type="text" placeholder="Qualification"
           class="rounded-lg border p-3">

    <input type="text" placeholder="Institute"
           class="rounded-lg border p-3">

    <input type="number" placeholder="Passing Year"
           class="rounded-lg border p-3">

    <input type="text" placeholder="Percentage"
           class="rounded-lg border p-3">

</div>
```

## Step 5: Responsive Buttons

```html
<div class="flex flex-col gap-3 sm:flex-row">

    <button class="w-full rounded-lg bg-blue-600 p-3 text-white sm:w-1/2">
        Submit
    </button>

    <button class="w-full rounded-lg border p-3 sm:w-1/2">
        Reset
    </button>

</div>
```

On mobile, the buttons appear vertically.

On small and larger screens, they appear horizontally.

## Step 6: Test Responsiveness

Open the webpage in Chrome.

1. Right-click the webpage.
2. Select Inspect.
3. Open the device toolbar.
4. Select a mobile device or enter a custom width.
5. Check the form at different screen sizes.
6. Verify that there is no unwanted horizontal scrolling.
7. Verify that buttons and fields remain readable and usable.

## Responsive Testing Table

| Device type | Example viewport | Expected layout |
|---|---:|---|
| Mobile | 375px | One-column form |
| Large mobile | 430px | One-column form |
| Tablet | 768px | Two-column form |
| Laptop | 1366px | Two-column or three-column sections |
| Desktop | 1920px | Centered form with maximum width |

These are test viewport examples, not Tailwind breakpoint definitions.

---

# 15. Additional Practical: Responsive Layout Using Tailwind Grid and Flexbox

## Grid Example

```html
<div class="grid grid-cols-1 gap-5 sm:grid-cols-2 lg:grid-cols-3">

    <div class="rounded-lg bg-blue-100 p-6">Card 1</div>

    <div class="rounded-lg bg-green-100 p-6">Card 2</div>

    <div class="rounded-lg bg-yellow-100 p-6">Card 3</div>

</div>
```

## Flexbox Example

```html
<div class="flex flex-col items-center justify-between gap-5 md:flex-row">

    <div class="rounded-lg bg-blue-100 p-6">
        Profile
    </div>

    <div class="rounded-lg bg-green-100 p-6">
        Skills
    </div>

    <div class="rounded-lg bg-yellow-100 p-6">
        Projects
    </div>

</div>
```

**Remember:** Tailwind's `flex`, `grid`, `flex-col`, `grid-cols-2`, and related classes are utility classes for the same CSS layout systems studied in Session 3.

---

# 16. Important Differences: Tailwind CSS v3 vs v4

Many online tutorials still teach Tailwind v3. It is important to identify which version is being used.

| Feature | Tailwind v3 | Tailwind v4 |
|---|---|---|
| Main CSS setup | `@tailwind` directives | `@import "tailwindcss"` |
| Vite integration | Commonly PostCSS | Official Vite plugin available |
| Theme customization | `tailwind.config.js` | CSS-first `@theme` |
| Content configuration | `content` array | Automatic source detection by default |
| Dark mode | Configuration or variants | `dark:` variant and custom variants |
| Custom variants | Configuration/API | `@custom-variant` |
| Custom utility styles | Often `@layer utilities` | `@utility` API |

### Tailwind v3 setup – for understanding older tutorials

Install:

```bash
npm install -D tailwindcss@3 postcss autoprefixer
```

Generate configuration:

```bash
npx tailwindcss init -p
```

In `tailwind.config.js`:

```javascript
/** @type {import('tailwindcss').Config} */

export default {
    content: [
        "./index.html",
        "./src/**/*.{js,ts,jsx,tsx}",
    ],

    theme: {
        extend: {},
    },

    plugins: [],
}
```

In the CSS file:

```css
@tailwind base;
@tailwind components;
@tailwind utilities;
```

**For this chapter, follow the v4 setup in Section 3 unless your instructor specifically requires v3. Do not mix v3 configuration instructions with v4 installation steps.**

---

# 17. CCEE and Interview Questions

## Basic Questions

1. What is Tailwind CSS?
2. What is utility-first CSS?
3. Why do we use Tailwind CSS?
4. What is the difference between traditional CSS and Tailwind CSS?
5. What is a utility class?
6. How do you install Tailwind CSS?
7. What is Vite?
8. What is the purpose of `@import "tailwindcss"`?
9. What is the purpose of `bg-blue-500`?
10. What is the purpose of `text-center`?

## Intermediate Questions

11. What are Tailwind spacing utilities?
12. What is the difference between margin and padding?
13. Explain typography utilities.
14. How do you apply background and text colors?
15. What is the purpose of `rounded-lg`?
16. What is a responsive prefix?
17. Explain the mobile-first approach.
18. What are the default Tailwind breakpoints?
19. What is the purpose of `md:grid-cols-2`?
20. What is the difference between `hidden` and `block`?
21. What is dark mode?
22. How does the `dark:` prefix work?
23. What is a custom theme?
24. What is the `@theme` directive in Tailwind v4?
25. What is the purpose of `@apply`?

## Advanced Questions

26. Explain how Tailwind generates CSS.
27. What is the difference between Tailwind v3 and v4?
28. How do you create custom breakpoints?
29. How do you create a manual dark-mode toggle?
30. How do you create reusable styles using `@apply`?
31. How can you create a responsive form using Grid?
32. Why is the viewport meta tag important?
33. What is the difference between `sm:` and `md:`?
34. How do Flexbox and Grid work with Tailwind?
35. Why should a developer test a webpage at different viewport widths?

---

# 18. MCQs – Practice Test

**Q1. What is Tailwind CSS?**

A. JavaScript framework  
B. Utility-first CSS framework  
C. Database  
D. Backend framework  

**Answer: B**

**Q2. Which class applies a blue background?**

A. `text-blue-500`  
B. `bg-blue-500`  
C. `blue-background`  
D. `background-blue`  

**Answer: B**

**Q3. Which class makes text bold?**

A. `text-bold`  
B. `font-bold`  
C. `bold-text`  
D. `weight-bold`  

**Answer: B**

**Q4. Which class applies padding on all sides?**

A. `m-4`  
B. `p-4`  
C. `gap-4`  
D. `w-4`  

**Answer: B**

**Q5. Which class applies horizontal margin?**

A. `mx-4`  
B. `my-4`  
C. `px-4`  
D. `py-4`  

**Answer: A**

**Q6. Which class creates rounded corners?**

A. `border-lg`  
B. `rounded-lg`  
C. `corner-lg`  
D. `radius-lg`  

**Answer: B**

**Q7. Which class activates Flexbox?**

A. `grid`  
B. `flex`  
C. `block`  
D. `inline`  

**Answer: B**

**Q8. Which class activates CSS Grid?**

A. `flex`  
B. `grid`  
C. `table`  
D. `row`  

**Answer: B**

**Q9. What is the default minimum width of the `sm:` breakpoint in Tailwind v4?**

A. 320px  
B. 480px  
C. 640px  
D. 768px  

**Answer: C**

**Q10. What is the default minimum width of the `md:` breakpoint?**

A. 640px  
B. 768px  
C. 1024px  
D. 1280px  

**Answer: B**

**Q11. Which prefix applies styles from the large breakpoint onwards?**

A. `sm:`  
B. `md:`  
C. `lg:`  
D. `xl:`  

**Answer: C**

**Q12. Which approach does Tailwind use for responsive design?**

A. Desktop-first  
B. Mobile-first  
C. Server-first  
D. Database-first  

**Answer: B**

**Q13. Which prefix is used for dark mode?**

A. `night:`  
B. `black:`  
C. `dark:`  
D. `theme:`  

**Answer: C**

**Q14. Which Tailwind v4 directive defines custom theme variables?**

A. `@apply`  
B. `@theme`  
C. `@media`  
D. `@font`  

**Answer: B**

**Q15. What is the purpose of `@apply`?**

A. To execute JavaScript  
B. To combine utility classes into custom CSS rules  
C. To create HTML elements  
D. To install Tailwind  

**Answer: B**

**Q16. Which class creates two equal grid columns?**

A. `grid-cols-2`  
B. `grid-rows-2`  
C. `flex-cols-2`  
D. `cols-2`  

**Answer: A**

**Q17. Which class hides an element?**

A. `invisible-text`  
B. `hidden`  
C. `none`  
D. `remove`  

**Answer: B**

**Q18. Which utility adds space between flex or grid items?**

A. `padding`  
B. `margin`  
C. `gap-4`  
D. `border-4`  

**Answer: C**

**Q19. Which package provides the official Tailwind Vite plugin?**

A. `tailwind-vite`  
B. `@tailwindcss/vite`  
C. `vite-tailwind`  
D. `@vite/tailwind`  

**Answer: B**

**Q20. Which command starts a typical Vite development server?**

A. `npm start-tailwind`  
B. `npm run dev`  
C. `npm install dev`  
D. `tailwind start`  

**Answer: B**

---

# 19. Quick Revision Sheet

| Topic | Important Syntax |
|---|---|
| Tailwind background | `bg-blue-500` |
| Text color | `text-red-500` |
| Font size | `text-2xl` |
| Font weight | `font-bold` |
| Text alignment | `text-center` |
| Padding | `p-4` |
| Horizontal padding | `px-4` |
| Margin | `m-4` |
| Horizontal margin | `mx-4` |
| Width | `w-full` |
| Maximum width | `max-w-4xl` |
| Border | `border` |
| Border color | `border-blue-500` |
| Rounded corners | `rounded-lg` |
| Shadow | `shadow-md` |
| Flexbox | `flex` |
| Grid | `grid` |
| Grid columns | `grid-cols-2` |
| Gap | `gap-4` |
| Small breakpoint | `sm:` |
| Medium breakpoint | `md:` |
| Large breakpoint | `lg:` |
| Extra large breakpoint | `xl:` |
| Dark mode | `dark:` |
| Custom theme | `@theme` |
| Custom CSS extraction | `@apply` |
| Tailwind v4 import | `@import "tailwindcss";` |

---

# 20. Self-Learning Tasks (2 SL)

Complete these tasks after the theory and lab sessions.

## Task 1: Build a Responsive Portfolio

Create a portfolio webpage containing:

- Navigation bar
- Profile section
- About Me
- Technical Skills
- Projects
- Education
- Contact section
- Footer

Requirements:

- Use Tailwind utility classes.
- Use responsive prefixes.
- Use Flexbox and Grid.
- Test on mobile, tablet, and desktop.
- Use consistent colors and typography.

## Task 2: Add Dark Mode

Add a theme toggle button to your portfolio.

Requirements:

- Light theme
- Dark theme
- JavaScript-based toggle
- Different background and text colors
- Readable text in both themes

## Task 3: Custom Theme

Define a custom color palette using `@theme`.

Use your custom colors for:
- Header
- Buttons
- Cards
- Links
- Section headings

## Task 4: Component Extraction

Create reusable styles using `@apply`.

Create at least these reusable classes:

- `.btn-primary`
- `.btn-secondary`
- `.form-input`
- `.card`

## Task 5: Responsive Testing

Test your portfolio at:

- 375px
- 640px
- 768px
- 1024px
- 1366px

Check for:
- Horizontal scrolling
- Overlapping elements
- Text overflow
- Unusable buttons
- Incorrect spacing

---

# 21. Recommended References and Learning Resources

### Official Documentation

1. Tailwind CSS documentation: https://tailwindcss.com/docs
2. Installation with Vite: https://tailwindcss.com/docs/installation/using-vite
3. Responsive design: https://tailwindcss.com/docs/responsive-design
4. Dark mode: https://tailwindcss.com/docs/dark-mode
5. Theme variables: https://tailwindcss.com/docs/theme
6. Adding custom styles and `@apply`: https://tailwindcss.com/docs/adding-custom-styles
7. MDN Responsive Design: https://developer.mozilla.org/en-US/docs/Learn_web_development/Core/CSS_layout/Responsive_Design

### Books from the Web Programming reference list

1. **Web Development with Node and Express – Ethan Brown:** Useful for understanding how frontend webpages fit into complete web applications.
2. **JavaScript: The Definitive Guide – David Flanagan:** Useful for understanding JavaScript interactions, such as a dark-mode toggle.
3. **React in Depth – Morten Barklund:** Useful when applying Tailwind CSS to component-based frontend applications.

---

# 22. Session 4 Learning Checklist

- [ ] Understand Responsive Web Design.
- [ ] Understand utility-first CSS.
- [ ] Explain Tailwind CSS.
- [ ] Install Tailwind CSS using Vite.
- [ ] Understand the Tailwind v4 setup.
- [ ] Use spacing utilities.
- [ ] Use typography utilities.
- [ ] Apply text and background colors.
- [ ] Apply borders, radius, and shadows.
- [ ] Understand responsive prefixes.
- [ ] Understand the mobile-first approach.
- [ ] Use `sm:`, `md:`, `lg:`, `xl:`, and `2xl:`.
- [ ] Implement dark mode.
- [ ] Create a custom theme using `@theme`.
- [ ] Use `@apply` for reusable component styles.
- [ ] Rebuild the resume form using Tailwind.
- [ ] Make the resume responsive.
- [ ] Test the layout on different screen sizes.

## Final Session Goal

After completing Session 4, you should be able to build a professional, responsive webpage using Tailwind CSS utility classes, customize its theme, implement dark mode, and adapt the layout for mobile, tablet, and desktop screens.

**Important learning sequence:**

1. Understand normal CSS from Session 3.
2. Learn Tailwind utility classes.
3. Practise spacing, colors, typography, and borders.
4. Learn responsive prefixes.
5. Implement dark mode and custom themes.
6. Rebuild your Session 2 résumé form using Tailwind CSS.
7. Test the final result on different screen sizes.
