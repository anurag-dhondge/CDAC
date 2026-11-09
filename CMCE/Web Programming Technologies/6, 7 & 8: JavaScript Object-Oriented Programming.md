# Sessions 6, 7 & 8: JavaScript Object-Oriented Programming

**Course:** Web Programming Technologies  
**Batch:** CMCE – August 2026  
**Duration:** 6 Theory + 6 Lab + 2 Self-Learning Sessions

---

# 1. JavaScript Objects

## 1.1 What is an Object?

An object is a collection of related data and functionality stored as key-value pairs.

- **Properties:** Store data.
- **Methods:** Functions associated with an object.

In JavaScript, objects are one of the fundamental data structures.

### Example

```javascript
const student = {
    name: "Anurag",
    age: 22,
    course: "AIML",

    displayDetails: function() {
        console.log("Student Name:", this.name);
        console.log("Age:", this.age);
        console.log("Course:", this.course);
    }
};

console.log(student.name);

student.displayDetails();
```

Output:

```text
Anurag
Student Name: Anurag
Age: 22
Course: AIML
```

Here:
- `student` is an object.
- `name`, `age` and `course` are properties.
- `displayDetails()` is a method.
- `this` refers to the object when this method is called as `student.displayDetails()`.

## 1.2 Creating Objects

There are multiple ways to create JavaScript objects.

### A. Object Literal

The simplest way to create an object.

```javascript
const employee = {
    id: 101,
    name: "Rahul",
    salary: 45000
};

console.log(employee);
```

### B. Using new Object()

```javascript
const student = new Object();

student.name = "Anurag";
student.age = 22;
student.course = "AIML";

console.log(student);
```

### C. Using a Constructor Function

```javascript
function Student(name, age, course) {
    this.name = name;
    this.age = age;
    this.course = course;
}

const s1 = new Student("Anurag", 22, "AIML");

const s2 = new Student("Rahul", 23, "MERN");

console.log(s1);
console.log(s2);
```

### D. Using Object.create()

Creates a new object with a specified prototype.

```javascript
const studentPrototype = {
    display() {
        console.log("Student Name:", this.name);
    }
};

const student = Object.create(studentPrototype);

student.name = "Anurag";

student.display();
```

Output:

```text
Student Name: Anurag
```

## 1.3 Object Properties

Properties represent information stored inside an object.

```javascript
const car = {
    brand: "Tata",
    model: "Nexon",
    price: 1200000
};
```

Accessing properties can be done in two ways.

### A. Dot Notation

```javascript
console.log(car.brand);
console.log(car.model);
```

### B. Bracket Notation

```javascript
console.log(car["brand"]);
console.log(car["model"]);
```

Bracket notation is useful when property names are dynamic or contain special characters.

```javascript
const propertyName = "brand";

console.log(car[propertyName]);
```

## 1.4 Adding and Updating Properties

```javascript
const student = {
    name: "Anurag",
    age: 22
};

// Add property
student.city = "Pune";

// Update property
student.age = 23;

console.log(student);
```

## 1.5 Deleting Properties

Use the `delete` operator to remove an object's own property.

```javascript
const student = {
    name: "Anurag",
    age: 22,
    city: "Pune"
};

delete student.city;

console.log(student);
```

Output:

```text
{
    name: "Anurag",
    age: 22
}
```

## 1.6 Object Methods

A method is a function stored as an object property.

```javascript
const calculator = {
    add: function(a, b) {
        return a + b;
    },

    subtract: function(a, b) {
        return a - b;
    },

    multiply(a, b) {
        return a * b;
    }
};

console.log(calculator.add(10, 20));

console.log(calculator.subtract(20, 10));

console.log(calculator.multiply(10, 5));
```

Output:

```text
30
10
50
```

The shorter method syntax is:

```javascript
const student = {
    name: "Anurag",

    display() {
        console.log(this.name);
    }
};

student.display();
```

## 1.7 The this Keyword

`this` refers to the current execution context. Its value depends on how a function is called.

Example:

```javascript
const student = {
    name: "Anurag",

    display() {
        console.log(this.name);
    }
};

student.display();
```

Output:

```text
Anurag
```

Here, `this` refers to `student`.

### Important: this in a Regular Function

```javascript
const student = {
    name: "Anurag",

    display: function() {
        console.log(this.name);
    }
};

student.display();
```

A regular function used as an object method receives the object as `this` when invoked through that object.

### this in Arrow Functions

Arrow functions do not have their own `this`. They capture `this` lexically from the surrounding scope.

```javascript
const student = {
    name: "Anurag",

    display: () => {
        console.log(this.name);
    }
};

student.display();
```

This does not behave like a normal object method. The arrow function does not receive `student` as its `this`.

**Remember:** Prefer regular method syntax when a method needs to access the object through `this`.

---

# 2. JavaScript Prototypes

## 2.1 What is a Prototype?

A prototype is an object from which another object can inherit properties and methods.

JavaScript uses prototype-based inheritance.

When a property is accessed on an object, JavaScript first checks the object itself. If the property is not found, it searches the object's prototype, then continues through the prototype chain.

This is called the **Prototype Chain**.

### Example

```javascript
const person = {
    greet() {
        console.log("Hello!");
    }
};

const student = {
    name: "Anurag"
};

Object.setPrototypeOf(student, person);

student.greet();
```

Output:

```text
Hello!
```

The `student` object does not directly contain `greet()`. JavaScript finds it through its prototype.

## 2.2 Prototype Chain

Consider:

```javascript
const parent = {
    country: "India"
};

const child = {
    name: "Anurag"
};

Object.setPrototypeOf(child, parent);

console.log(child.name);
console.log(child.country);
```

Output:

```text
Anurag
India
```

Explanation:

- JavaScript first searches `child`.
- `name` is found directly.
- `country` is not found in `child`.
- JavaScript searches the prototype `parent`.
- `country` is found.

The chain eventually reaches `Object.prototype` for ordinary objects, whose prototype is `null`.

## 2.3 Checking Prototypes

### Object.getPrototypeOf()

Returns the prototype of an object.

```javascript
const parent = {
    greet() {
        console.log("Hello");
    }
};

const child = {};

Object.setPrototypeOf(child, parent);

console.log(Object.getPrototypeOf(child) === parent);
```

Output:

```text
true
```

### isPrototypeOf()

Checks whether an object exists in another object's prototype chain.

```javascript
const parent = {};

const child = Object.create(parent);

console.log(parent.isPrototypeOf(child));
```

Output:

```text
true
```

### Object.hasOwn()

Checks whether an object has a property directly on itself, not inherited from its prototype.

```javascript
const parent = {
    city: "Pune"
};

const child = Object.create(parent);

child.name = "Anurag";

console.log(Object.hasOwn(child, "name"));

console.log(Object.hasOwn(child, "city"));
```

Output:

```text
true
false
```

## 2.4 Constructor Function and Prototype

Every ordinary JavaScript function has a `prototype` property that is used when the function is called as a constructor with `new`.

Example:

```javascript
function Student(name, age) {
    this.name = name;
    this.age = age;
}

Student.prototype.display = function() {
    console.log(this.name, this.age);
};

const s1 = new Student("Anurag", 22);

const s2 = new Student("Rahul", 23);

s1.display();

s2.display();
```

Both objects share the `display()` method through `Student.prototype`.

**Why use prototypes?**

If the method is defined inside the constructor, every instance gets its own function property. Defining it on the prototype allows instances to share the same method.

---

# 3. JavaScript Functions

## 3.1 What is a Function?

A function is a reusable block of code designed to perform a particular task.

Functions help to:
- Reuse code.
- Avoid repetition.
- Divide a large program into smaller parts.
- Improve readability.
- Simplify testing and maintenance.

## 3.2 Function Declaration

Syntax:

```javascript
function functionName(parameters) {
    // statements
}
```

Example:

```javascript
function greet() {
    console.log("Welcome to JavaScript");
}

greet();
```

Output:

```text
Welcome to JavaScript
```

## 3.3 Function with Parameters

Parameters are variables declared in the function definition.

Arguments are actual values supplied when the function is called.

```javascript
function add(a, b) {
    console.log(a + b);
}

add(10, 20);
```

Here:
- `a` and `b` are parameters.
- `10` and `20` are arguments.

## 3.4 Function with Return Value

The `return` statement sends a value back to the caller and ends the function execution.

```javascript
function multiply(a, b) {
    return a * b;
}

const result = multiply(10, 20);

console.log(result);
```

Output:

```text
200
```

## 3.5 Function Expression

A function can be assigned to a variable.

```javascript
const greet = function() {
    console.log("Hello");
};

greet();
```

The function in this example is anonymous because it has no function name.

## 3.6 Arrow Function

Arrow functions provide a shorter syntax for writing functions.

```javascript
const add = (a, b) => {
    return a + b;
};

console.log(add(10, 20));
```

Short form when there is a single expression:

```javascript
const add = (a, b) => a + b;

console.log(add(10, 20));
```

More examples:

```javascript
const square = n => n * n;

const greet = () => "Hello";

console.log(square(5));

console.log(greet());
```

## 3.7 Default Parameters

Default parameters provide values when arguments are missing or explicitly passed as `undefined`.

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

## 3.8 Function Invocation

Function invocation means executing a function.

Common invocation styles:

**1. Normal invocation**

```javascript
function greet() {
    console.log("Hello");
}

greet();
```

**2. Method invocation**

```javascript
const student = {
    name: "Anurag",

    display() {
        console.log(this.name);
    }
};

student.display();
```

**3. Constructor invocation**

```javascript
function Student(name) {
    this.name = name;
}

const s1 = new Student("Anurag");

console.log(s1.name);
```

**4. Using call()**

Calls a function with a specified `this` value and arguments.

```javascript
function display(city) {
    console.log(this.name, city);
}

const student = {
    name: "Anurag"
};

display.call(student, "Pune");
```

**5. Using apply()**

Similar to `call()`, but arguments are passed as an array.

```javascript
function add(a, b) {
    console.log(a + b);
}

add.apply(null, [10, 20]);
```

**6. Using bind()**

Returns a new function with a specified `this` value.

```javascript
function display() {
    console.log(this.name);
}

const student = {
    name: "Anurag"
};

const newFunction = display.bind(student);

newFunction();
```

## 3.9 Function Parameters and Arguments

| Parameters | Arguments |
|---|---|
| Declared in function definition | Supplied during invocation |
| Act as input variables | Actual input values |
| Example: `a, b` | Example: `10, 20` |

---

# 4. Closures

## 4.1 What is a Closure?

A closure is created when a function retains access to variables from its surrounding lexical scope, even after the outer function has finished executing.

In simple words, an inner function remembers the variables of the outer function.

### Example

```javascript
function outer() {

    let message = "Hello JavaScript";

    function inner() {
        console.log(message);
    }

    return inner;
}

const result = outer();

result();
```

Output:

```text
Hello JavaScript
```

Explanation:

1. `outer()` is called.
2. The inner function is returned.
3. `outer()` finishes execution.
4. `result()` still accesses `message`.
5. This happens because of closure.

## 4.2 Practical Example: Counter

Closures are useful when we want to maintain private state.

```javascript
function createCounter() {

    let count = 0;

    return function() {
        count++;
        console.log(count);
    };

}

const counter = createCounter();

counter();
counter();
counter();
```

Output:

```text
1
2
3
```

The variable `count` is not directly accessible outside the closure.

## 4.3 Practical Example: Bank Account

```javascript
function createBankAccount(initialBalance) {

    let balance = initialBalance;

    return {

        deposit(amount) {
            if (amount > 0) {
                balance += amount;
            }
        },

        withdraw(amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
            }
        },

        getBalance() {
            return balance;
        }

    };
}

const account = createBankAccount(1000);

account.deposit(500);

account.withdraw(200);

console.log(account.getBalance());
```

Output:

```text
1300
```

The balance is maintained inside the closure and accessed through controlled methods.

## 4.4 Uses of Closures

1. Data privacy.
2. Maintaining state.
3. Creating function factories.
4. Event handlers.
5. Callbacks.
6. Implementing module patterns.

---

# 5. Introduction to Object-Oriented Programming in JavaScript

## 5.1 What is OOP?

Object-Oriented Programming (OOP) is a programming approach that organizes code around objects containing data and methods.

OOP helps developers build reusable, modular and maintainable applications.

### Real-World Example

Consider a car.

A car has properties:
- Brand
- Model
- Colour
- Speed

A car has methods:
- start()
- stop()
- accelerate()
- brake()

In JavaScript:

```javascript
const car = {

    brand: "Tata",

    model: "Nexon",

    speed: 0,

    start() {
        console.log("Car started");
    },

    accelerate() {
        this.speed += 10;
        console.log("Current speed:", this.speed);
    },

    stop() {
        this.speed = 0;
        console.log("Car stopped");
    }
};

car.start();

car.accelerate();

car.stop();
```

## 5.2 Four Pillars of OOP

The four major principles of OOP are:

1. Encapsulation
2. Abstraction
3. Inheritance
4. Polymorphism

---

# 6. Methods

A method is a function associated with an object or class.

Example:

```javascript
class Student {

    display() {
        console.log("Student Details");
    }

}

const s1 = new Student();

s1.display();
```

## Types of Methods in Classes

### A. Instance Method

An instance method is called using an object created from a class.

```javascript
class Student {

    display() {
        console.log("Hello Student");
    }

}

const s1 = new Student();

s1.display();
```

### B. Static Method

A static method belongs to the class itself and is called using the class name.

```javascript
class Calculator {

    static add(a, b) {
        return a + b;
    }

}

console.log(Calculator.add(10, 20));
```

Output:

```text
30
```

A static method is not directly available as an instance method.

### C. Getter and Setter

Getters and setters allow controlled property access.

```javascript
class Student {

    constructor(name) {
        this._name = name;
    }

    get name() {
        return this._name;
    }

    set name(value) {

        if (value.length >= 3) {
            this._name = value;
        } else {
            console.log("Name is too short");
        }

    }

}

const s1 = new Student("Anurag");

console.log(s1.name);

s1.name = "Rahul";

console.log(s1.name);
```

---

# 7. Constructor

## 7.1 What is a Constructor?

A constructor is a special method used to initialize an object when an instance of a class is created.

In JavaScript classes, the constructor is written using the `constructor` keyword.

Example:

```javascript
class Student {

    constructor(name, age) {

        this.name = name;

        this.age = age;

    }

}

const s1 = new Student("Anurag", 22);

console.log(s1.name);

console.log(s1.age);
```

Output:

```text
Anurag
22
```

Important points:

- A class can have only one constructor method.
- The constructor is called automatically when `new` creates an instance.
- It initializes instance properties.
- If no constructor is written, JavaScript provides a default constructor.

## 7.2 Constructor Function vs Class Constructor

Constructor function:

```javascript
function Student(name, age) {

    this.name = name;

    this.age = age;

}

const s1 = new Student("Anurag", 22);
```

Class syntax:

```javascript
class Student {

    constructor(name, age) {

        this.name = name;

        this.age = age;

    }

}

const s1 = new Student("Anurag", 22);
```

Both approaches can create objects, but class syntax provides a clearer structure for OOP.

---

# 8. Inheritance

## 8.1 What is Inheritance?

Inheritance allows one class to acquire properties and methods from another class.

It promotes code reuse.

The existing class is called:
- Parent class
- Base class
- Superclass

The class that inherits is called:
- Child class
- Derived class
- Subclass

### Example

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

Here:
- `Animal` is the parent class.
- `Dog` is the child class.
- `extends` establishes inheritance.

## 8.2 super Keyword

The `super` keyword is used to access the parent class constructor and methods.

Example:

```javascript
class Animal {

    constructor(name) {
        this.name = name;
    }

    eat() {
        console.log(this.name, "is eating");
    }

}

class Dog extends Animal {

    constructor(name, breed) {

        super(name);

        this.breed = breed;

    }

    display() {

        console.log(this.name);

        console.log(this.breed);

    }

}

const dog = new Dog("Tommy", "Labrador");

dog.display();

dog.eat();
```

Output:

```text
Tommy
Labrador
Tommy is eating
```

Important:
- `super()` calls the parent constructor.
- In a derived class constructor, `super()` must be called before using `this`.
- `super.methodName()` calls a parent class method.

## 8.3 Types of Inheritance

Common OOP inheritance patterns include:

1. Single inheritance
2. Multilevel inheritance
3. Hierarchical inheritance
4. Multiple inheritance

JavaScript classes directly support single inheritance through `extends`.

### A. Single Inheritance

One child inherits from one parent.

```javascript
class Animal {
    eat() {
        console.log("Eating");
    }
}

class Dog extends Animal {
    bark() {
        console.log("Barking");
    }
}

const d = new Dog();

d.eat();
d.bark();
```

### B. Multilevel Inheritance

A class inherits from a class that itself inherits from another class.

```javascript
class Animal {

    eat() {
        console.log("Eating");
    }

}

class Mammal extends Animal {

    walk() {
        console.log("Walking");
    }

}

class Dog extends Mammal {

    bark() {
        console.log("Barking");
    }

}

const dog = new Dog();

dog.eat();

dog.walk();

dog.bark();
```

### C. Hierarchical Inheritance

Multiple child classes inherit from the same parent.

```javascript
class Animal {

    eat() {
        console.log("Eating");
    }

}

class Dog extends Animal {

    bark() {
        console.log("Barking");
    }

}

class Cat extends Animal {

    meow() {
        console.log("Meowing");
    }

}

const dog = new Dog();

const cat = new Cat();

dog.eat();

cat.eat();
```

### D. Multiple Inheritance

In classical multiple inheritance, a class inherits directly from more than one parent class.

JavaScript classes do not support this directly.

However, similar behaviour can be achieved through composition or mixins.

Example using mixins:

```javascript
const CanFly = {

    fly() {
        console.log("Flying");
    }

};

const CanSwim = {

    swim() {
        console.log("Swimming");
    }

};

class Duck {

    constructor(name) {
        this.name = name;
    }

}

Object.assign(Duck.prototype, CanFly, CanSwim);

const duck = new Duck("Donald");

duck.fly();

duck.swim();
```

---

# 9. Encapsulation

## 9.1 What is Encapsulation?

Encapsulation means combining data and methods into one unit and controlling access to internal data.

It helps protect data from unwanted modification.

### Example: Without Encapsulation

```javascript
const account = {

    balance: 1000

};

account.balance = -5000;

console.log(account.balance);
```

The balance can be directly modified.

### Example: Using Private Fields

JavaScript supports private class fields using the `#` prefix.

```javascript
class BankAccount {

    #balance;

    constructor(initialBalance) {

        this.#balance = initialBalance;

    }

    deposit(amount) {

        if (amount > 0) {

            this.#balance += amount;

        }

    }

    withdraw(amount) {

        if (amount > 0 && amount <= this.#balance) {

            this.#balance -= amount;

        } else {

            console.log("Invalid withdrawal");

        }

    }

    getBalance() {

        return this.#balance;

    }

}

const account = new BankAccount(1000);

account.deposit(500);

account.withdraw(200);

console.log(account.getBalance());
```

Output:

```text
1300
```

Trying to access the private property directly:

```javascript
// console.log(account.#balance);
```

This causes a syntax error because private fields are accessible only within the class body.

## 9.2 Benefits of Encapsulation

1. Data protection.
2. Controlled access.
3. Better code organization.
4. Easier maintenance.
5. Reduced accidental modification.

---

# 10. Abstraction

## 10.1 What is Abstraction?

Abstraction means hiding unnecessary implementation details and exposing only essential functionality.

### Real-World Example

When using an ATM:
- You enter your PIN.
- You select withdrawal.
- You receive money.

You do not need to understand the internal banking system or cash-dispensing mechanism.

This is abstraction.

### JavaScript Example

```javascript
class ATM {

    withdraw(amount) {

        if (this.#validate(amount)) {

            this.#processWithdrawal(amount);

        }

    }

    #validate(amount) {

        return amount > 0;

    }

    #processWithdrawal(amount) {

        console.log("Processing withdrawal:", amount);

    }

}

const atm = new ATM();

atm.withdraw(500);
```

Output:

```text
Processing withdrawal: 500
```

Here:
- `withdraw()` is the public operation.
- `#validate()` and `#processWithdrawal()` are private implementation details.

**Important:** JavaScript does not have a dedicated `abstract class` keyword like Java. Abstraction can be implemented using classes, private methods, controlled interfaces and other design techniques.

---

# 11. Polymorphism

## 11.1 What is Polymorphism?

Polymorphism means "many forms".

It allows the same method name or interface to behave differently depending on the object or context.

### Example: Method Overriding

```javascript
class Animal {

    sound() {
        console.log("Animal makes a sound");
    }

}

class Dog extends Animal {

    sound() {
        console.log("Dog barks");
    }

}

class Cat extends Animal {

    sound() {
        console.log("Cat meows");
    }

}

const dog = new Dog();

const cat = new Cat();

dog.sound();

cat.sound();
```

Output:

```text
Dog barks
Cat meows
```

The child classes override the parent method.

## 11.2 Runtime Polymorphism

The method implementation is selected based on the actual object.

```javascript
class Shape {

    area() {
        console.log("Area of shape");
    }

}

class Circle extends Shape {

    constructor(radius) {
        super();
        this.radius = radius;
    }

    area() {
        return Math.PI * this.radius * this.radius;
    }

}

class Rectangle extends Shape {

    constructor(length, breadth) {
        super();
        this.length = length;
        this.breadth = breadth;
    }

    area() {
        return this.length * this.breadth;
    }

}

const shapes = [
    new Circle(5),
    new Rectangle(10, 5)
];

for (const shape of shapes) {

    console.log(shape.area());

}
```

The same `area()` method produces different results depending on the object's class.

## 11.3 Method Overloading in JavaScript

JavaScript does not support traditional method overloading based on different parameter lists in the same way as Java or C++.

However, similar behaviour can be achieved using optional parameters, default parameters or rest parameters.

Example:

```javascript
class Calculator {

    add(...numbers) {

        return numbers.reduce((sum, num) => sum + num, 0);

    }

}

const calculator = new Calculator();

console.log(calculator.add(10, 20));

console.log(calculator.add(10, 20, 30));

console.log(calculator.add(10, 20, 30, 40));
```

---

# 12. ES6 Class Syntax

## 12.1 What is a Class?

A class is a template for creating objects.

It defines the properties and methods that instances can use.

JavaScript introduced class syntax in ES6 (ES2015).

**Important:** JavaScript classes are built on the prototype system. They provide cleaner syntax for creating objects and implementing inheritance.

## 12.2 Creating a Class

```javascript
class Student {

    constructor(name, age) {

        this.name = name;

        this.age = age;

    }

    display() {

        console.log("Name:", this.name);

        console.log("Age:", this.age);

    }

}

const s1 = new Student("Anurag", 22);

const s2 = new Student("Rahul", 23);

s1.display();

s2.display();
```

## 12.3 Class Expression

A class can also be assigned to a variable.

```javascript
const Student = class {

    constructor(name) {
        this.name = name;
    }

    display() {
        console.log(this.name);
    }

};

const s1 = new Student("Anurag");

s1.display();
```

## 12.4 Inheritance Using Classes

```javascript
class Person {

    constructor(name) {
        this.name = name;
    }

    display() {
        console.log("Name:", this.name);
    }

}

class Student extends Person {

    constructor(name, course) {

        super(name);

        this.course = course;

    }

    showCourse() {
        console.log("Course:", this.course);
    }

}

const student = new Student("Anurag", "AIML");

student.display();

student.showCourse();
```

## 12.5 Static Properties and Methods

Static members belong to the class rather than its instances.

```javascript
class College {

    static collegeName = "ACTS Pune";

    static display() {
        console.log(this.collegeName);
    }

}

College.display();

console.log(College.collegeName);
```

## 12.6 Private Fields and Methods

```javascript
class Employee {

    #salary;

    constructor(name, salary) {

        this.name = name;

        this.#salary = salary;

    }

    #calculateBonus() {
        return this.#salary * 0.10;
    }

    displayBonus() {
        console.log(this.#calculateBonus());
    }

}

const employee = new Employee("Anurag", 50000);

employee.displayBonus();
```

---

# 13. Symbol (ES6+)

## 13.1 What is Symbol?

`Symbol` is a primitive data type introduced in ES6.

Every Symbol value created using `Symbol()` is unique.

Symbols are often used as unique property keys.

### Example

```javascript
const id1 = Symbol("id");

const id2 = Symbol("id");

console.log(id1 === id2);
```

Output:

```text
false
```

Although both Symbols have the same description, they are different values.

## 13.2 Symbol as an Object Property

```javascript
const id = Symbol("studentId");

const student = {

    name: "Anurag",

    [id]: 101

};

console.log(student.name);

console.log(student[id]);
```

Output:

```text
Anurag
101
```

Notice that Symbol keys are not included in ordinary string-key enumeration methods such as `Object.keys()`.

```javascript
console.log(Object.keys(student));
```

Output:

```text
["name"]
```

To retrieve Symbol keys:

```javascript
console.log(Object.getOwnPropertySymbols(student));
```

## 13.3 Symbol.for()

`Symbol.for()` uses a global Symbol registry.

```javascript
const s1 = Symbol.for("college");

const s2 = Symbol.for("college");

console.log(s1 === s2);
```

Output:

```text
true
```

Unlike `Symbol()`, repeated calls to `Symbol.for()` with the same key return the same registered Symbol.

## 13.4 Uses of Symbols

1. Creating unique property keys.
2. Avoiding accidental property-name collisions.
3. Implementing custom iteration behaviour.
4. Using built-in well-known Symbols.

Important well-known Symbols include:
- `Symbol.iterator`
- `Symbol.toPrimitive`
- `Symbol.toStringTag`
- `Symbol.hasInstance`

---

# 14. Iterators

## 14.1 What is an Iterator?

An iterator is an object that provides a sequence of values one at a time.

An iterator must implement a `next()` method.

The `next()` method returns an object containing:

- `value`: The current value.
- `done`: Whether iteration has completed.

### Example

```javascript
const numbers = [10, 20, 30];

const iterator = numbers[Symbol.iterator]();

console.log(iterator.next());

console.log(iterator.next());

console.log(iterator.next());

console.log(iterator.next());
```

Output:

```text
{ value: 10, done: false }
{ value: 20, done: false }
{ value: 30, done: false }
{ value: undefined, done: true }
```

## 14.2 Creating a Custom Iterator

```javascript
const myIterator = {

    current: 1,

    last: 5,

    next() {

        if (this.current <= this.last) {

            return {
                value: this.current++,
                done: false
            };

        }

        return {
            value: undefined,
            done: true
        };

    }

};

console.log(myIterator.next());

console.log(myIterator.next());

console.log(myIterator.next());
```

## 14.3 Iterable vs Iterator

| Iterable | Iterator |
|---|---|
| An object that provides an iterator | An object that produces values |
| Has a `[Symbol.iterator]()` method | Has a `next()` method |
| Examples: arrays, strings, maps | Example: result of `array[Symbol.iterator]()` |

Example:

```javascript
const numbers = [10, 20, 30];

const iterator = numbers[Symbol.iterator]();
```

Here:
- `numbers` is iterable.
- `iterator` is an iterator.

---

# 15. Generators (ES6+)

## 15.1 What is a Generator?

A generator is a special function that can pause its execution and resume later.

Generators use the `function*` syntax and the `yield` keyword.

### Example

```javascript
function* generateNumbers() {

    yield 10;

    yield 20;

    yield 30;

}

const generator = generateNumbers();

console.log(generator.next());

console.log(generator.next());

console.log(generator.next());

console.log(generator.next());
```

Output:

```text
{ value: 10, done: false }
{ value: 20, done: false }
{ value: 30, done: false }
{ value: undefined, done: true }
```

## 15.2 How yield Works

`yield` pauses the generator and returns a value.

When `next()` is called again, execution continues from the point where it was paused.

Example:

```javascript
function* demo() {

    console.log("First");

    yield 1;

    console.log("Second");

    yield 2;

    console.log("Third");

}

const g = demo();

console.log(g.next());

console.log(g.next());

console.log(g.next());
```

Output:

```text
First
{ value: 1, done: false }

Second
{ value: 2, done: false }

Third
{ value: undefined, done: true }
```

## 15.3 Generator with for...of

```javascript
function* numbers() {

    yield 10;

    yield 20;

    yield 30;

}

for (const num of numbers()) {

    console.log(num);

}
```

Output:

```text
10
20
30
```

## 15.4 Practical Example: Generate Even Numbers

```javascript
function* evenNumbers(limit) {

    for (let i = 2; i <= limit; i += 2) {

        yield i;

    }

}

for (const num of evenNumbers(10)) {

    console.log(num);

}
```

Output:

```text
2
4
6
8
10
```

## 15.5 Iterator vs Generator

| Iterator | Generator |
|---|---|
| Usually created manually or by an iterable | Created using `function*` |
| Requires a `next()` method | Provides `next()` automatically |
| Can be more verbose to implement | Simpler way to create iterators |
| Returns `{value, done}` from `next()` | Also returns `{value, done}` |

---

# 16. Functional Programming Patterns

## 16.1 What is Functional Programming?

Functional Programming (FP) is a programming approach that treats computation as the evaluation of functions.

It encourages:
- Reusable functions.
- Predictable results.
- Avoiding unnecessary side effects.
- Immutable data handling.
- Transforming data through function composition.

JavaScript supports both object-oriented and functional programming styles.

## 16.2 Pure Functions

A pure function:
1. Returns the same output for the same input.
2. Does not cause side effects.

### Example of a Pure Function

```javascript
function add(a, b) {

    return a + b;

}

console.log(add(10, 20));

console.log(add(10, 20));
```

Output:

```text
30
30
```

The result depends only on the inputs.

### Example of an Impure Function

```javascript
let total = 0;

function add(value) {

    total += value;

    return total;

}

console.log(add(10));

console.log(add(10));
```

Output:

```text
10
20
```

The result depends on the external variable `total`, which changes between calls.

## 16.3 Side Effects

A side effect occurs when a function changes something outside its local computation.

Examples:
- Modifying a global variable.
- Changing an external object.
- Writing to a file.
- Making an API request.
- Updating the DOM.
- Printing to the console.

Pure functions are easier to test because they do not depend on external state.

---

# 17. map(), filter() and reduce()

These three array methods are very important in functional programming and modern JavaScript.

## 17.1 map()

`map()` creates a new array by applying a callback function to every element.

Syntax:

```javascript
array.map(callback);
```

Example:

```javascript
const numbers = [1, 2, 3, 4, 5];

const result = numbers.map(num => num * 2);

console.log(result);
```

Output:

```text
[2, 4, 6, 8, 10]
```

The original array remains unchanged.

### Practical Example

Convert student names to uppercase.

```javascript
const students = [
    "Anurag",
    "Rahul",
    "Sneha"
];

const result = students.map(name => name.toUpperCase());

console.log(result);
```

Output:

```text
["ANURAG", "RAHUL", "SNEHA"]
```

## 17.2 filter()

`filter()` creates a new array containing elements that satisfy a specified condition.

Syntax:

```javascript
array.filter(callback);
```

Example:

```javascript
const numbers = [10, 15, 20, 25, 30];

const result = numbers.filter(num => num > 20);

console.log(result);
```

Output:

```text
[25, 30]
```

### Practical Example

Find students who passed.

```javascript
const students = [
    { name: "Anurag", marks: 85 },
    { name: "Rahul", marks: 35 },
    { name: "Sneha", marks: 92 },
    { name: "Amit", marks: 28 }
];

const passed = students.filter(student => student.marks >= 40);

console.log(passed);
```

## 17.3 reduce()

`reduce()` executes a callback for each element and accumulates a single result.

Syntax:

```javascript
array.reduce((accumulator, currentValue) => {
    return updatedAccumulator;
}, initialValue);
```

Example:

```javascript
const numbers = [10, 20, 30, 40];

const total = numbers.reduce((sum, num) => {
    return sum + num;
}, 0);

console.log(total);
```

Output:

```text
100
```

Explanation:

| Iteration | Accumulator | Current value | New accumulator |
|---|---:|---:|---:|
| 1 | 0 | 10 | 10 |
| 2 | 10 | 20 | 30 |
| 3 | 30 | 30 | 60 |
| 4 | 60 | 40 | 100 |

## 17.4 Difference Between map(), filter() and reduce()

| Method | Purpose | Return |
|---|---|---|
| `map()` | Transform every element | New array |
| `filter()` | Select matching elements | New array |
| `reduce()` | Accumulate values | Single accumulated result |

### Combined Example

```javascript
const numbers = [10, 20, 30, 40, 50, 60];

// Select numbers greater than 20
const filtered = numbers.filter(num => num > 20);

// Multiply each selected number by 2
const mapped = filtered.map(num => num * 2);

// Calculate the total
const total = mapped.reduce((sum, num) => sum + num, 0);

console.log(filtered);

console.log(mapped);

console.log(total);
```

Output:

```text
[30, 40, 50, 60]

[60, 80, 100, 120]

360
```

---

# 18. Immutability

## 18.1 What is Immutability?

Immutability means avoiding modification of existing data after it has been created.

Instead of changing the original object or array, create a new copy with the required changes.

### Example: Mutable Approach

```javascript
const student = {
    name: "Anurag",
    age: 22
};

student.age = 23;

console.log(student);
```

The original object is modified.

### Example: Immutable Approach

```javascript
const student = {
    name: "Anurag",
    age: 22
};

const updatedStudent = {
    ...student,
    age: 23
};

console.log(student);

console.log(updatedStudent);
```

Output:

```text
{ name: "Anurag", age: 22 }

{ name: "Anurag", age: 23 }
```

The original object remains unchanged.

## 18.2 Immutable Array Operations

Instead of modifying an array using `push()`:

```javascript
const numbers = [10, 20, 30];

const updatedNumbers = [...numbers, 40];

console.log(numbers);

console.log(updatedNumbers);
```

Output:

```text
[10, 20, 30]

[10, 20, 30, 40]
```

## 18.3 Updating an Object in an Array

```javascript
const students = [
    { id: 1, name: "Anurag", marks: 80 },
    { id: 2, name: "Rahul", marks: 70 }
];

const updatedStudents = students.map(student => {

    if (student.id === 1) {

        return {
            ...student,
            marks: 90
        };

    }

    return student;

});

console.log(updatedStudents);
```

## 18.4 Benefits of Immutability

1. Predictable state changes.
2. Easier debugging.
3. Reduced accidental modification.
4. Better code organization.
5. Useful in React state management.

**Important:** Spread syntax creates only a shallow copy. Nested objects still require careful copying if you need to avoid sharing nested references.

---

# 19. Lab Programs

The following programs directly cover your ACTS syllabus lab requirements.

## Lab 1: Sort a List of Elements Using a Sorting Algorithm

### Aim

Write a JavaScript program to sort a list of numbers by implementing a sorting algorithm.

### Bubble Sort

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.

Example:

```javascript
function bubbleSort(arr) {

    let n = arr.length;

    for (let i = 0; i < n - 1; i++) {

        for (let j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                let temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;

            }

        }

    }

    return arr;

}

const numbers = [64, 34, 25, 12, 22, 11, 90];

console.log("Original Array:", numbers);

console.log("Sorted Array:", bubbleSort(numbers));
```

Output:

```text
Original Array:
[64, 34, 25, 12, 22, 11, 90]

Sorted Array:
[11, 12, 22, 25, 34, 64, 90]
```

### How Bubble Sort Works

Initial array:

```text
[5, 3, 8, 2]
```

Pass 1:

```text
Compare 5 and 3 → Swap
[3, 5, 8, 2]

Compare 5 and 8 → No swap
[3, 5, 8, 2]

Compare 8 and 2 → Swap
[3, 5, 2, 8]
```

Pass 2:

```text
Compare 3 and 5 → No swap
[3, 5, 2, 8]

Compare 5 and 2 → Swap
[3, 2, 5, 8]
```

Pass 3:

```text
Compare 3 and 2 → Swap
[2, 3, 5, 8]
```

Final sorted array:

```text
[2, 3, 5, 8]
```

### Bubble Sort Complexity

| Case | Time Complexity |
|---|---|
| Best case with optimized early stopping | O(n) |
| Average case | O(n²) |
| Worst case | O(n²) |
| Space complexity | O(1) |

### Optimized Bubble Sort

```javascript
function bubbleSort(arr) {

    let n = arr.length;

    for (let i = 0; i < n - 1; i++) {

        let swapped = false;

        for (let j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                [arr[j], arr[j + 1]] =
                    [arr[j + 1], arr[j]];

                swapped = true;

            }

        }

        if (!swapped) {
            break;
        }

    }

    return arr;

}

const numbers = [5, 3, 8, 2, 1];

console.log(bubbleSort(numbers));
```

### Additional Sorting Algorithms to Practise

1. Selection Sort.
2. Insertion Sort.
3. Merge Sort.
4. Quick Sort.

---

## Lab 2: List the Properties of a JavaScript Object

### Aim

Write a JavaScript program to display all properties of an object.

### Method 1: Using for...in

```javascript
const student = {

    name: "Anurag",

    age: 22,

    course: "AIML",

    city: "Pune"

};

for (let key in student) {

    console.log(key, ":", student[key]);

}
```

Output:

```text
name : Anurag
age : 22
course : AIML
city : Pune
```

### Method 2: Using Object.keys()

Returns an array of an object's own enumerable string-keyed property names.

```javascript
const student = {

    name: "Anurag",

    age: 22,

    course: "AIML"

};

const keys = Object.keys(student);

console.log(keys);
```

Output:

```text
["name", "age", "course"]
```

### Method 3: Using Object.values()

Returns the object's own enumerable string-keyed property values.

```javascript
const student = {

    name: "Anurag",

    age: 22,

    course: "AIML"

};

console.log(Object.values(student));
```

Output:

```text
["Anurag", 22, "AIML"]
```

### Method 4: Using Object.entries()

Returns an array of key-value pairs.

```javascript
const student = {

    name: "Anurag",

    age: 22,

    course: "AIML"

};

console.log(Object.entries(student));
```

Output:

```text
[
    ["name", "Anurag"],
    ["age", 22],
    ["course", "AIML"]
]
```

### Method 5: Using Reflect.ownKeys()

Returns all own property keys, including non-enumerable string keys and Symbol keys.

```javascript
const id = Symbol("studentId");

const student = {
    name: "Anurag",
    age: 22,
    [id]: 101
};

console.log(Reflect.ownKeys(student));
```

### Important Difference

| Method | Returns |
|---|---|
| `Object.keys()` | Own enumerable string keys |
| `Object.values()` | Own enumerable string-keyed values |
| `Object.entries()` | Own enumerable string-keyed key-value pairs |
| `Object.getOwnPropertyNames()` | All own string keys |
| `Object.getOwnPropertySymbols()` | Own Symbol keys |
| `Reflect.ownKeys()` | All own string and Symbol keys |
| `for...in` | Enumerable string keys, including inherited keys |

---

## Lab 3: Rewrite a Prototype-Based Object Using ES6 Class Syntax

### Aim

Create an object using prototype-based inheritance and rewrite it using ES6 class syntax.

### Step 1: Prototype-Based Implementation

```javascript
function Person(name, age) {

    this.name = name;

    this.age = age;

}

Person.prototype.display = function() {

    console.log("Name:", this.name);

    console.log("Age:", this.age);

};

function Student(name, age, course) {

    Person.call(this, name, age);

    this.course = course;

}

Student.prototype = Object.create(Person.prototype);

Student.prototype.constructor = Student;

Student.prototype.showCourse = function() {

    console.log("Course:", this.course);

};

const s1 = new Student("Anurag", 22, "AIML");

s1.display();

s1.showCourse();
```

Output:

```text
Name: Anurag
Age: 22
Course: AIML
```

### Step 2: Rewrite Using ES6 Classes

```javascript
class Person {

    constructor(name, age) {

        this.name = name;

        this.age = age;

    }

    display() {

        console.log("Name:", this.name);

        console.log("Age:", this.age);

    }

}

class Student extends Person {

    constructor(name, age, course) {

        super(name, age);

        this.course = course;

    }

    showCourse() {

        console.log("Course:", this.course);

    }

}

const s1 = new Student("Anurag", 22, "AIML");

s1.display();

s1.showCourse();
```

### Comparison

| Prototype-Based | ES6 Class |
|---|---|
| Constructor function | `class` |
| `prototype.method` | Method inside class |
| `Object.create()` | `extends` |
| `Parent.call(this, ...)` | `super(...)` |
| More manual setup | Cleaner syntax |

**Learning outcome:** Understand how ES6 class syntax provides a cleaner way to work with JavaScript's prototype-based inheritance.

---

## Lab 4: Functional Programming – Transform a Dataset Using map(), filter() and reduce()

### Aim

Create a dataset and transform it using functional programming methods.

### Dataset

```javascript
const employees = [

    {
        id: 1,
        name: "Anurag",
        department: "IT",
        salary: 45000
    },

    {
        id: 2,
        name: "Rahul",
        department: "HR",
        salary: 30000
    },

    {
        id: 3,
        name: "Sneha",
        department: "IT",
        salary: 60000
    },

    {
        id: 4,
        name: "Amit",
        department: "Finance",
        salary: 35000
    },

    {
        id: 5,
        name: "Priya",
        department: "IT",
        salary: 55000
    }

];
```

### Task 1: Display Employee Names Using map()

```javascript
const names = employees.map(emp => emp.name);

console.log(names);
```

Output:

```text
["Anurag", "Rahul", "Sneha", "Amit", "Priya"]
```

### Task 2: Filter IT Department Employees

```javascript
const itEmployees = employees.filter(
    emp => emp.department === "IT"
);

console.log(itEmployees);
```

### Task 3: Find Employees with Salary Greater Than 40000

```javascript
const highSalaryEmployees = employees.filter(
    emp => emp.salary > 40000
);

console.log(highSalaryEmployees);
```

### Task 4: Calculate Total Salary

```javascript
const totalSalary = employees.reduce(
    (total, emp) => total + emp.salary,
    0
);

console.log("Total Salary:", totalSalary);
```

Output:

```text
225000
```

### Task 5: Calculate Average Salary

```javascript
const total = employees.reduce(
    (sum, emp) => sum + emp.salary,
    0
);

const average = total / employees.length;

console.log("Average Salary:", average);
```

Output:

```text
45000
```

### Task 6: Give Every Employee a 10% Salary Increment

```javascript
const updatedEmployees = employees.map(emp => {

    return {

        ...emp,

        salary: emp.salary * 1.10

    };

});

console.log(updatedEmployees);
```

The original employee dataset remains unchanged.

### Task 7: Find Total Salary of IT Employees

```javascript
const totalITSalary = employees

    .filter(emp => emp.department === "IT")

    .reduce((sum, emp) => sum + emp.salary, 0);

console.log("Total IT Salary:", totalITSalary);
```

Output:

```text
160000
```

### Task 8: Get Names of Employees Earning More Than 40000

```javascript
const result = employees

    .filter(emp => emp.salary > 40000)

    .map(emp => emp.name);

console.log(result);
```

Output:

```text
["Anurag", "Sneha", "Priya"]
```

---

# 20. Additional Practical Programs

## Program 1: Create a Student Class

```javascript
class Student {

    constructor(name, rollNo, marks) {

        this.name = name;

        this.rollNo = rollNo;

        this.marks = marks;

    }

    display() {

        console.log("Name:", this.name);

        console.log("Roll No:", this.rollNo);

        console.log("Marks:", this.marks);

    }

    checkResult() {

        if (this.marks >= 40) {
            console.log("Pass");
        } else {
            console.log("Fail");
        }

    }

}

const s1 = new Student("Anurag", 101, 85);

s1.display();

s1.checkResult();
```

## Program 2: Create an Employee Inheritance Example

```javascript
class Employee {

    constructor(name, salary) {

        this.name = name;

        this.salary = salary;

    }

    display() {

        console.log("Name:", this.name);

        console.log("Salary:", this.salary);

    }

}

class Manager extends Employee {

    constructor(name, salary, department) {

        super(name, salary);

        this.department = department;

    }

    showDepartment() {

        console.log("Department:", this.department);

    }

}

const manager = new Manager(
    "Anurag",
    60000,
    "Development"
);

manager.display();

manager.showDepartment();
```

## Program 3: Demonstrate Closure

```javascript
function createMultiplier(multiplier) {

    return function(number) {

        return number * multiplier;

    };

}

const double = createMultiplier(2);

const triple = createMultiplier(3);

console.log(double(10));

console.log(triple(10));
```

Output:

```text
20
30
```

## Program 4: Generate Fibonacci Numbers Using Generator

```javascript
function* fibonacci(limit) {

    let a = 0;

    let b = 1;

    for (let i = 0; i < limit; i++) {

        yield a;

        [a, b] = [b, a + b];

    }

}

for (const num of fibonacci(8)) {

    console.log(num);

}
```

Output:

```text
0
1
1
2
3
5
8
13
```

## Program 5: Find Maximum Salary Using reduce()

```javascript
const salaries = [25000, 45000, 60000, 35000];

const maximum = salaries.reduce(
    (max, salary) => salary > max ? salary : max,
    salaries[0]
);

console.log(maximum);
```

Output:

```text
60000
```

---

# 21. CCEE and Interview Questions

## Objects and Prototypes

1. What is an object in JavaScript?
2. What are object properties?
3. What are object methods?
4. What is the difference between dot notation and bracket notation?
5. What is the purpose of the `this` keyword?
6. What is a prototype?
7. What is prototype-based inheritance?
8. What is the prototype chain?
9. What is the difference between `__proto__` and `prototype`?
10. What is the use of `Object.create()`?
11. What is the use of `Object.getPrototypeOf()`?
12. What is the difference between an own property and an inherited property?

## Functions and Closures

13. What is a function?
14. What is the difference between parameters and arguments?
15. What is function invocation?
16. What is a function declaration?
17. What is a function expression?
18. What is an arrow function?
19. What is the difference between regular and arrow functions?
20. What is the purpose of the return statement?
21. What are default parameters?
22. What are `call()`, `apply()` and `bind()`?
23. What is a closure?
24. What is lexical scope?
25. What are the practical uses of closures?

## OOP Concepts

26. What is Object-Oriented Programming?
27. What are the four pillars of OOP?
28. What is encapsulation?
29. What is abstraction?
30. What is inheritance?
31. What is polymorphism?
32. What is a constructor?
33. What is the purpose of `extends`?
34. What is the purpose of `super`?
35. What is method overriding?
36. Does JavaScript support traditional method overloading?
37. What is a static method?
38. What are private fields in JavaScript?
39. What is the difference between an instance method and a static method?
40. How are classes related to prototypes in JavaScript?

## Symbol, Iterators and Generators

41. What is Symbol?
42. Why are Symbols unique?
43. What is `Symbol.for()`?
44. What is an iterator?
45. What is an iterable?
46. What is `Symbol.iterator`?
47. What does `next()` return?
48. What is a generator?
49. What is the purpose of `yield`?
50. What is the difference between an iterator and a generator?

## Functional Programming

51. What is functional programming?
52. What is a pure function?
53. What is an impure function?
54. What is a side effect?
55. What is immutability?
56. What is the difference between map and filter?
57. What is the purpose of reduce?
58. What is the difference between forEach and map?
59. Why is immutability useful in React?
60. What is the difference between mutable and immutable operations?

---

# 22. MCQs – Practice Test

**Q1. JavaScript primarily uses which inheritance model?**

A. Class-based only  
B. Prototype-based  
C. Multiple inheritance only  
D. Procedural only  

**Answer: B**

**Q2. Which operator is used to create a new object with a specified prototype?**

A. `new`  
B. `Object.create()`  
C. `Object.assign()`  
D. `prototype()`  

**Answer: B**

**Q3. What is a method?**

A. A variable  
B. A function associated with an object  
C. An operator  
D. A loop  

**Answer: B**

**Q4. Which keyword refers to the current method's calling context?**

A. self  
B. this  
C. current  
D. super  

**Answer: B**

**Q5. Which function creates a constructor function instance?**

A. create  
B. new  
C. class  
D. prototype  

**Answer: B**

**Q6. What is a closure?**

A. A loop  
B. A function that retains access to its lexical scope  
C. An object property  
D. A constructor  

**Answer: B**

**Q7. Which keyword is used to define a class?**

A. object  
B. class  
C. prototype  
D. constructor  

**Answer: B**

**Q8. Which keyword is used for class inheritance?**

A. inherits  
B. extends  
C. implements  
D. parent  

**Answer: B**

**Q9. Which keyword calls the parent class constructor?**

A. this  
B. parent  
C. super  
D. base  

**Answer: C**

**Q10. Which symbol is used to declare a private class field?**

A. `@`  
B. `#`  
C. `$`  
D. `_`  

**Answer: B**

**Q11. Which of the following is an OOP principle?**

A. Encapsulation  
B. Compilation  
C. Interpretation  
D. Parsing  

**Answer: A**

**Q12. What is method overriding?**

A. Deleting a method  
B. A child class providing its own implementation of an inherited method  
C. Calling multiple methods  
D. Creating a variable  

**Answer: B**

**Q13. Which keyword creates a unique Symbol value?**

A. unique  
B. Symbol  
C. object  
D. iterator  

**Answer: B**

**Q14. What does `Symbol.for()` do?**

A. Creates a new object  
B. Uses the global Symbol registry  
C. Creates an array  
D. Creates a class  

**Answer: B**

**Q15. Which method is required by the iterator protocol?**

A. start()  
B. next()  
C. iterate()  
D. finish()  

**Answer: B**

**Q16. Which property makes an object iterable?**

A. `Symbol.iterator`  
B. `Symbol.next`  
C. `Symbol.value`  
D. `Symbol.loop`  

**Answer: A**

**Q17. Which syntax declares a generator function?**

A. `function()`  
B. `function*`  
C. `generator()`  
D. `yield function`  

**Answer: B**

**Q18. Which keyword pauses a generator?**

A. pause  
B. break  
C. yield  
D. return  

**Answer: C**

**Q19. Which array method creates a new transformed array?**

A. map()  
B. pop()  
C. push()  
D. shift()  

**Answer: A**

**Q20. Which array method selects elements based on a condition?**

A. reduce()  
B. filter()  
C. map()  
D. join()  

**Answer: B**

**Q21. Which method is used to calculate the sum of array values?**

A. map()  
B. filter()  
C. reduce()  
D. find()  

**Answer: C**

**Q22. What is a pure function?**

A. A function that modifies global data  
B. A function with predictable output and no side effects  
C. A function without parameters  
D. A function that returns an object only  

**Answer: B**

**Q23. Which syntax is commonly used to make a shallow copy of an object?**

A. `Object.delete()`  
B. `{ ...object }`  
C. `object.remove()`  
D. `new Object.copy()`  

**Answer: B**

**Q24. Which method returns an object's own enumerable string-keyed property names?**

A. Object.values()  
B. Object.keys()  
C. Object.entries()  
D. Object.create()  

**Answer: B**

**Q25. What does `Object.hasOwn(obj, "name")` check?**

A. Whether name exists anywhere in the prototype chain  
B. Whether name is an own property of obj  
C. Whether name is a method  
D. Whether obj is iterable  

**Answer: B**

**Q26. Which method can be used to call a function with a specified this value and individual arguments?**

A. bind()  
B. call()  
C. map()  
D. reduce()  

**Answer: B**

**Q27. Which of the following is a static method call?**

A. `obj.add()`  
B. `Calculator.add()`  
C. `new Calculator.add()`  
D. `this.add()`  

**Answer: B**

**Q28. What is the main purpose of encapsulation?**

A. Increase repetition  
B. Protect and control access to data  
C. Remove all methods  
D. Avoid objects  

**Answer: B**

**Q29. What is the main purpose of abstraction?**

A. Show all implementation details  
B. Hide unnecessary implementation details  
C. Duplicate data  
D. Remove inheritance  

**Answer: B**

**Q30. JavaScript classes are primarily built on:**

A. Prototype-based inheritance  
B. Multiple inheritance  
C. Database inheritance  
D. HTML inheritance  

**Answer: A**

---

# 23. Quick Revision Sheet

| Concept | Important Syntax / Meaning |
|---|---|
| Object | `{ name: "Anurag" }` |
| Property access | `obj.name` |
| Bracket access | `obj["name"]` |
| Method | `obj.display()` |
| Current context | `this` |
| Constructor function | `function Student() {}` |
| Create instance | `new Student()` |
| Prototype | `Student.prototype` |
| Object prototype | `Object.getPrototypeOf(obj)` |
| Object creation | `Object.create(proto)` |
| Function | `function add(a,b) {}` |
| Arrow function | `(a,b) => a+b` |
| Function expression | `const add = function() {}` |
| Closure | Function retaining lexical scope |
| Class | `class Student {}` |
| Constructor | `constructor()` |
| Inheritance | `class Dog extends Animal` |
| Parent constructor | `super()` |
| Parent method | `super.method()` |
| Private field | `#balance` |
| Static method | `static add()` |
| Getter | `get name()` |
| Setter | `set name(value)` |
| Symbol | `Symbol("id")` |
| Global Symbol | `Symbol.for("id")` |
| Iterator | Object with `next()` |
| Iterable | Object with `[Symbol.iterator]()` |
| Generator | `function* generate()` |
| Yield | `yield value` |
| Pure function | Same input, same output, no side effects |
| map() | Transform elements |
| filter() | Select elements |
| reduce() | Accumulate values |
| Immutability | Create new data instead of modifying existing data |
| Spread | `{ ...obj }` |
| Object keys | `Object.keys(obj)` |
| Object values | `Object.values(obj)` |
| Object entries | `Object.entries(obj)` |

---

# 24. Self-Learning Tasks (2 SL)

Complete these tasks independently.

## Task 1: Library Management System

Create a `Book` class with:

- Book ID
- Book Name
- Author
- Price

Requirements:

1. Create a constructor.
2. Create a method to display book details.
3. Create a method to update price.
4. Create an array of five books.
5. Display all books.
6. Find books costing more than ₹500 using `filter()`.
7. Calculate the total price using `reduce()`.

## Task 2: Vehicle Inheritance

Create the following classes:

```text
Vehicle
  |
  |-- Car
  |
  |-- Bike
```

Requirements:

1. Vehicle should have brand and speed.
2. Car should have number of doors.
3. Bike should have engine capacity.
4. Use `extends` and `super`.
5. Create display methods.
6. Demonstrate method overriding.

## Task 3: Bank Account Using Encapsulation

Create a BankAccount class.

Requirements:

1. Create a private balance field.
2. Add a deposit method.
3. Add a withdraw method.
4. Add a method to check the balance.
5. Prevent negative deposits.
6. Prevent withdrawals greater than the balance.

## Task 4: Closure-Based Counter

Create a counter using closures.

Requirements:

1. Initial value should be zero.
2. Create an increment function.
3. Create a decrement function.
4. Create a reset function.
5. Return the current count.
6. Do not expose the count variable directly.

## Task 5: Employee Dataset Processing

Create at least ten employee records.

Requirements:

1. Display employee names using `map()`.
2. Filter employees by department.
3. Find the highest salary.
4. Calculate the average salary.
5. Sort employees by salary.
6. Create a new dataset with a 10% salary increment.
7. Keep the original dataset unchanged.

## Task 6: Custom Iterator

Create a custom iterator that returns numbers from 1 to 10.

Requirements:

1. Implement `next()`.
2. Return `value`.
3. Return `done`.
4. Display all values.
5. Handle the completed state.

## Task 7: Generator Function

Create a generator that produces Fibonacci numbers.

Requirements:

1. Use `function*`.
2. Use `yield`.
3. Generate the first ten Fibonacci numbers.
4. Iterate using `for...of`.

---

# 25. Recommended References and Learning Resources

## Books

**1. JavaScript: The Definitive Guide, 7th Edition – David Flanagan**

Recommended topics:
- Objects and properties.
- Functions and closures.
- Prototypes and inheritance.
- Classes and methods.
- Iterators and generators.
- Arrays and functional programming.

**2. Web Development with Node and Express – Ethan Brown**

Recommended topics:
- JavaScript objects and functions.
- Application structure.
- Modules.
- Practical JavaScript usage in web development.

**3. React in Depth – Morten Barklund**

Recommended topics:
- Modern JavaScript.
- Objects and arrays.
- Functional programming.
- Immutable data transformations.
- JavaScript concepts used in React.

## Official Online Resources

- JavaScript Objects: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Working_with_objects
- JavaScript Functions: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Functions
- JavaScript Closures: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Closures
- JavaScript Classes: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes
- JavaScript Inheritance: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Inheritance_and_the_prototype_chain
- JavaScript Symbols: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol
- Iterators and Generators: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Iterators_and_generators
- Array Methods: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array

---

# 26. Final Learning Checklist

## Objects and Functions

- [ ] Create objects using object literals.
- [ ] Access, add, update and delete properties.
- [ ] Create object methods.
- [ ] Understand `this`.
- [ ] Understand prototypes and prototype chains.
- [ ] Create constructor functions.
- [ ] Understand function declarations and expressions.
- [ ] Practise arrow functions.
- [ ] Understand function invocation.
- [ ] Implement closures.

## OOP Concepts

- [ ] Understand OOP.
- [ ] Understand methods and constructors.
- [ ] Implement inheritance.
- [ ] Use `extends` and `super`.
- [ ] Understand encapsulation.
- [ ] Implement private fields.
- [ ] Understand abstraction.
- [ ] Understand polymorphism.
- [ ] Implement method overriding.
- [ ] Understand static methods.

## ES6+ Features

- [ ] Understand Symbol.
- [ ] Understand iterators.
- [ ] Create custom iterators.
- [ ] Create generator functions.
- [ ] Use `yield`.
- [ ] Understand pure functions.
- [ ] Practise map, filter and reduce.
- [ ] Understand immutability.

## Lab Completion

- [ ] Implement Bubble Sort.
- [ ] List object properties.
- [ ] Rewrite prototype-based code using ES6 classes.
- [ ] Transform a dataset using map/filter/reduce.
- [ ] Complete the additional practical programs.
- [ ] Solve CCEE MCQs.
- [ ] Complete self-learning tasks.

---

# 27. Final Learning Goal

After completing Sessions 6, 7 and 8, you should be able to:

1. Create and manipulate JavaScript objects.
2. Understand prototypes and prototype-based inheritance.
3. Write reusable functions and implement closures.
4. Apply all four major OOP principles.
5. Build applications using ES6 classes.
6. Understand Symbol, iterators and generators.
7. Transform datasets using functional programming.
8. Write maintainable and reusable JavaScript code.

**Important for upcoming frontend development:** Master objects, classes, destructuring, spread syntax, closures, `map()`, `filter()` and immutability. These concepts are especially useful when learning React components, props and state management.
