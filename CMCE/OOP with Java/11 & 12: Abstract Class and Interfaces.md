

# Sessions 11 & 12: Abstract Class and Interfaces in Java

**Course:** CDAC CMCE – August 2026 Batch  
**Technology:** Java 17  
**Topics:** Abstract Classes, Abstract Methods, Interfaces, Multiple Interface Implementation, Java 8 & 11 Interface Features

---

# 1. Abstract Class in Java

## 1.1 What is an Abstract Class?

An abstract class is a class declared using the `abstract` keyword.

It is used as a blueprint for other classes.

An abstract class can contain:
- Abstract methods (methods without a body).
- Concrete methods (methods with a body).
- Instance variables.
- Static variables and methods.
- Constructors.
- Final methods.
- Other class members.

An abstract class cannot be instantiated directly.

**Real-world example:**

Consider a vehicle.

Every vehicle has common properties:
- Brand
- Model
- Speed

But different vehicles have different ways of starting:
- Car starts using an ignition system.
- Bike starts using a self-start or kick-start mechanism.
- Electric vehicle starts using an electric power system.

We can define common properties and behavior in an abstract `Vehicle` class and let subclasses implement their own starting behavior.

## 1.2 Syntax of Abstract Class

```java
abstract class ClassName {

    // Instance variable
    int value;

    // Abstract method
    abstract void display();

    // Concrete method
    void show() {
        System.out.println("Concrete method");
    }
}
```

**Important:** An abstract method does not have a method body and ends with a semicolon.

## 1.3 Basic Abstract Class Example

```java
abstract class Animal {

    abstract void sound();

    void eat() {
        System.out.println("Animal is eating");
    }
}

class Dog extends Animal {

    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

public class AbstractDemo {

    public static void main(String[] args) {

        // Animal a = new Animal();
        // Compilation error: Cannot instantiate abstract class

        Dog d = new Dog();

        d.sound();
        d.eat();
    }
}
```

**Output:**

```text
Dog barks
Animal is eating
```

**Explanation:**

1. `Animal` is an abstract class.
2. It contains one abstract method, `sound()`.
3. It also contains one concrete method, `eat()`.
4. `Dog` extends `Animal`.
5. `Dog` provides the implementation of `sound()`.
6. The inherited `eat()` method can be called directly.

## 1.4 Abstract Methods

An abstract method is a method declared without an implementation.

Example:

```java
abstract class Shape {

    abstract double calculateArea();
}
```

The subclasses must provide an implementation unless they are also abstract.

```java
class Circle extends Shape {

    double radius = 5;

    @Override
    double calculateArea() {

        return 3.14 * radius * radius;
    }
}

public class ShapeDemo {

    public static void main(String[] args) {

        Circle c = new Circle();

        System.out.println(c.calculateArea());
    }
}
```

**Output:**

```text
78.5
```

## 1.5 Abstract Class with Constructor

An abstract class can have a constructor.

The constructor is executed when a subclass object is created.

```java
abstract class Person {

    String name;

    Person(String name) {

        this.name = name;

        System.out.println("Person constructor called");
    }

    abstract void display();
}

class Student extends Person {

    Student(String name) {

        super(name);

        System.out.println("Student constructor called");
    }

    @Override
    void display() {

        System.out.println("Student Name: " + name);
    }
}

public class AbstractConstructorDemo {

    public static void main(String[] args) {

        Student s = new Student("Anurag");

        s.display();
    }
}
```

**Output:**

```text
Person constructor called
Student constructor called
Student Name: Anurag
```

**Important:** Abstract classes cannot be instantiated directly, but their constructors are called during subclass object creation.

## 1.6 Abstract Class with Reference Variable

We cannot create an abstract class object directly, but we can create a reference variable of an abstract class.

```java
abstract class Animal {

    abstract void sound();
}

class Cat extends Animal {

    @Override
    void sound() {

        System.out.println("Cat meows");
    }
}

public class AbstractReferenceDemo {

    public static void main(String[] args) {

        Animal a = new Cat();

        a.sound();
    }
}
```

**Output:**

```text
Cat meows
```

This is an example of runtime polymorphism.

The reference type is `Animal`, but the actual object is `Cat`.

## 1.7 Rules of Abstract Classes

1. An abstract class is declared using `abstract`.
2. We cannot instantiate an abstract class directly.
3. An abstract class can contain abstract and concrete methods.
4. An abstract class can contain constructors.
5. An abstract class can contain instance and static variables.
6. An abstract class can extend another class.
7. An abstract class can implement interfaces.
8. A subclass must implement inherited abstract methods or remain abstract.
9. An abstract method cannot be `private`, `static` or `final`.
10. An abstract class can exist without any abstract methods.

---

# 2. Interface in Java

## 2.1 What is an Interface?

An interface is a reference type in Java that defines a contract for classes.

It specifies what operations a class should provide.

A class implements an interface using the `implements` keyword.

**Real-world example:**

Consider a mobile phone.

It may support:
- Calling
- Internet connectivity
- Charging
- Software updates

These are different capabilities.

We can represent these capabilities using separate interfaces:

- `Connectable`
- `Rechargeable`
- `Upgradeable`

A mobile phone can implement all three interfaces.

## 2.2 Syntax of Interface

```java
interface InterfaceName {

    void method1();

    void method2();
}
```

A class implements the interface:

```java
class MyClass implements InterfaceName {

    @Override
    public void method1() {
        // Implementation
    }

    @Override
    public void method2() {
        // Implementation
    }
}
```

## 2.3 Basic Interface Example

```java
interface Animal {

    void sound();
}

class Dog implements Animal {

    @Override
    public void sound() {

        System.out.println("Dog barks");
    }
}

public class InterfaceDemo {

    public static void main(String[] args) {

        Dog d = new Dog();

        d.sound();
    }
}
```

**Output:**

```text
Dog barks
```

**Explanation:**

1. `Animal` is an interface.
2. It declares the `sound()` method.
3. `Dog` implements the interface.
4. `Dog` provides the implementation of `sound()`.

## 2.4 Important Interface Rules

1. An interface is declared using the `interface` keyword.
2. We cannot instantiate an interface directly.
3. A class uses `implements` to implement an interface.
4. A class can implement multiple interfaces.
5. Interface abstract methods are implicitly `public abstract`.
6. Interface fields are implicitly `public static final`.
7. An interface can extend one or more interfaces.
8. A class implementing an interface must implement its abstract methods unless the class is abstract.
9. Interfaces do not have constructors.
10. Interfaces can contain default, static and private methods, depending on Java version.

## 2.5 Interface Variables

Variables declared in an interface are automatically:

- `public`
- `static`
- `final`

Example:

```java
interface College {

    String COLLEGE_NAME = "PES Modern College";
}

public class InterfaceVariableDemo {

    public static void main(String[] args) {

        System.out.println(College.COLLEGE_NAME);
    }
}
```

**Output:**

```text
PES Modern College
```

The following declaration:

```java
String COLLEGE_NAME = "PES Modern College";
```

is equivalent to:

```java
public static final String COLLEGE_NAME = "PES Modern College";
```

---

# 3. Implementing Multiple Interfaces

## 3.1 What is Multiple Interface Implementation?

Java does not support multiple inheritance of classes.

However, Java allows a class to implement multiple interfaces.

This is called multiple interface implementation.

**Example:**

A SmartPhone can be:
- Connectable
- Rechargeable
- Upgradeable

It can implement all three interfaces.

### Syntax

```java
class ClassName implements Interface1, Interface2, Interface3 {

    // Implement interface methods
}
```

## 3.2 Example of Multiple Interface Implementation

```java
interface Connectable {

    void connectToWifi();
}

interface Rechargeable {

    void chargeBattery();
}

interface Upgradeable {

    void updateSoftware();
}

class SmartPhone implements Connectable,
                            Rechargeable,
                            Upgradeable {

    @Override
    public void connectToWifi() {

        System.out.println("Connected to WiFi");
    }

    @Override
    public void chargeBattery() {

        System.out.println("Charging battery");
    }

    @Override
    public void updateSoftware() {

        System.out.println("Software updated");
    }
}

public class MultipleInterfaceDemo {

    public static void main(String[] args) {

        SmartPhone phone = new SmartPhone();

        phone.connectToWifi();

        phone.chargeBattery();

        phone.updateSoftware();
    }
}
```

**Output:**

```text
Connected to WiFi
Charging battery
Software updated
```

## 3.3 Why Does Java Support Multiple Interfaces?

Suppose Java allowed a class to extend multiple classes:

```java
class C extends A, B {
}
```

If both parent classes had the same method, Java would face ambiguity about which implementation to inherit.

This is commonly called the diamond problem.

Java avoids multiple inheritance of classes but allows multiple interfaces because interfaces define contracts and Java has explicit rules for resolving conflicting default methods.

---

# 4. New Interface Features in Java 8

Java 8 introduced important interface features.

The major features are:

1. Default methods
2. Static methods
3. Functional interfaces and lambda expressions

## 4.1 Default Methods

Before Java 8, interfaces mainly contained abstract methods and constants.

Suppose an interface is already implemented by many classes. Adding a new abstract method could break existing implementations because every implementing class would need to provide the new method.

Java 8 introduced default methods to allow interfaces to provide a method implementation.

### Syntax

```java
interface InterfaceName {

    default void methodName() {

        System.out.println("Default method");
    }
}
```

### Example

```java
interface Vehicle {

    void start();

    default void stop() {

        System.out.println("Vehicle stopped");
    }
}

class Car implements Vehicle {

    @Override
    public void start() {

        System.out.println("Car started");
    }
}

public class DefaultMethodDemo {

    public static void main(String[] args) {

        Car car = new Car();

        car.start();

        car.stop();
    }
}
```

**Output:**

```text
Car started
Vehicle stopped
```

**Explanation:**

- `start()` is an abstract method and must be implemented by `Car`.
- `stop()` is a default method with an implementation.
- `Car` can use the default method without overriding it.

### Overriding a Default Method

A class can override a default method.

```java
interface Vehicle {

    default void stop() {

        System.out.println("Vehicle stopped");
    }
}

class Bike implements Vehicle {

    @Override
    public void stop() {

        System.out.println("Bike stopped");
    }
}

public class DefaultOverrideDemo {

    public static void main(String[] args) {

        Bike bike = new Bike();

        bike.stop();
    }
}
```

**Output:**

```text
Bike stopped
```

## 4.2 Static Methods in Interfaces

Java 8 allows interfaces to contain static methods.

A static interface method belongs to the interface itself.

It is called using the interface name.

### Example

```java
interface Calculator {

    static int add(int a, int b) {

        return a + b;
    }
}

public class InterfaceStaticDemo {

    public static void main(String[] args) {

        int result = Calculator.add(10, 20);

        System.out.println(result);
    }
}
```

**Output:**

```text
30
```

**Important points:**

- Static methods belong to the interface.
- They are called using the interface name.
- They are not inherited as instance methods by implementing classes.
- They cannot be overridden as interface instance methods.

## 4.3 Functional Interfaces

A functional interface is an interface that contains exactly one abstract method.

It can contain:
- One abstract method
- Multiple default methods
- Multiple static methods
- Methods inherited from `Object` without counting them as additional abstract methods

Functional interfaces are commonly used with lambda expressions.

### Example

```java
@FunctionalInterface
interface Greeting {

    void sayHello();
}

public class FunctionalInterfaceDemo {

    public static void main(String[] args) {

        Greeting g = () -> {

            System.out.println("Hello Java 17");
        };

        g.sayHello();
    }
}
```

**Output:**

```text
Hello Java 17
```

### What is @FunctionalInterface?

`@FunctionalInterface` is an annotation that tells the compiler that the interface is intended to be functional.

If we add another unrelated abstract method, the compiler reports an error.

### Example with Parameters

```java
@FunctionalInterface
interface Addition {

    int add(int a, int b);
}

public class LambdaDemo {

    public static void main(String[] args) {

        Addition obj = (a, b) -> a + b;

        System.out.println(obj.add(10, 20));
    }
}
```

**Output:**

```text
30
```

---

# 5. Interface Features in Java 9 and Java 11

## 5.1 Private Methods in Interfaces – Java 9

Java 9 introduced private methods inside interfaces.

They help reuse common code between default and static methods.

A private interface method:
- Cannot be accessed outside the interface.
- Cannot be implemented or overridden by implementing classes.
- Can be called from other methods inside the interface.

### Example

```java
interface Device {

    default void connect() {

        checkConnection();

        System.out.println("Device connected");
    }

    default void disconnect() {

        checkConnection();

        System.out.println("Device disconnected");
    }

    private void checkConnection() {

        System.out.println("Checking connection...");
    }
}

class SmartDevice implements Device {
}

public class PrivateInterfaceMethodDemo {

    public static void main(String[] args) {

        SmartDevice device = new SmartDevice();

        device.connect();

        device.disconnect();
    }
}
```

**Output:**

```text
Checking connection...
Device connected
Checking connection...
Device disconnected
```

The private method avoids duplicating the same logic in multiple default methods.

## 5.2 Private Static Methods in Interfaces – Java 9

An interface can also declare private static methods.

```java
interface Utility {

    static void display() {

        System.out.println("Display method");

        helper();
    }

    private static void helper() {

        System.out.println("Private static helper");
    }
}

public class PrivateStaticInterfaceDemo {

    public static void main(String[] args) {

        Utility.display();
    }
}
```

**Output:**

```text
Display method
Private static helper
```

## 5.3 Java 11 Interface Features

Java 11 did not introduce a new major category of interface methods.

The important interface features used in Java 11 are:

| Feature | Introduced |
|---|---|
| Abstract methods | Java 1.0 |
| Interface constants | Java 1.0 |
| Default methods | Java 8 |
| Static methods | Java 8 |
| Functional interfaces and lambda support | Java 8 |
| Private instance methods | Java 9 |
| Private static methods | Java 9 |

All these features are available when developing with Java 11 and Java 17.

**Important for CMCE:** If the syllabus mentions Java 8 and Java 11 interface features, understand default and static methods from Java 8 and private interface methods from Java 9. These features are supported by Java 11 and Java 17.

---

# 6. Default Method Conflict in Multiple Interfaces

What happens when two interfaces contain a default method with the same signature?

The implementing class must resolve the conflict by overriding that method.

### Example

```java
interface Camera {

    default void start() {

        System.out.println("Camera started");
    }
}

interface MusicPlayer {

    default void start() {

        System.out.println("Music Player started");
    }
}

class SmartPhone implements Camera, MusicPlayer {

    @Override
    public void start() {

        Camera.super.start();

        MusicPlayer.super.start();

        System.out.println("SmartPhone started");
    }
}

public class DefaultConflictDemo {

    public static void main(String[] args) {

        SmartPhone phone = new SmartPhone();

        phone.start();
    }
}
```

**Output:**

```text
Camera started
Music Player started
SmartPhone started
```

**Explanation:**

- Both interfaces provide a default `start()` method.
- The class must override the conflicting method.
- `Camera.super.start()` calls the Camera interface's default implementation.
- `MusicPlayer.super.start()` calls the MusicPlayer interface's default implementation.

### Important Default Method Resolution Rules

1. A class method takes precedence over an interface default method.
2. A more specific interface's default method takes precedence over a less specific parent interface's default method.
3. If two unrelated interfaces provide conflicting default methods, the implementing class must resolve the conflict.

---

# 7. Abstract Class vs Interface

Both abstract classes and interfaces support abstraction, but they serve different purposes.

## 7.1 Comparison Table

| Feature | Abstract Class | Interface |
|---|---|---|
| Declaration | `abstract class` | `interface` |
| Object creation | Cannot instantiate directly | Cannot instantiate directly |
| Constructors | Yes | No |
| Instance variables | Yes | No ordinary instance fields |
| Constants | Can have constants | Fields are implicitly `public static final` |
| Abstract methods | Yes | Yes |
| Concrete methods | Yes | Yes |
| Default methods | Not applicable as an interface feature | Yes |
| Static methods | Yes | Yes |
| Private methods | Yes | Yes, since Java 9 |
| Inheritance | A class can extend one class | A class can implement multiple interfaces |
| State | Can maintain instance state | Does not maintain per-object instance state |
| Main purpose | Shared state and common base behavior | Common contract or capability |

## 7.2 When Should We Prefer an Abstract Class?

Prefer an abstract class when:

1. Related classes share common properties.
2. You need instance variables to store shared state.
3. You need constructors to initialize common fields.
4. You want to provide common method implementations.
5. You want to define a common base class for a family of related objects.

**Example:**

```java
abstract class Employee {

    int employeeId;

    String name;

    Employee(int employeeId, String name) {

        this.employeeId = employeeId;
        this.name = name;
    }

    abstract double calculateSalary();

    void displayDetails() {

        System.out.println(employeeId + " " + name);
    }
}
```

Different employee types can inherit common fields and behavior.

## 7.3 When Should We Prefer an Interface?

Prefer an interface when:

1. Different unrelated classes need to support the same capability.
2. A class needs to implement multiple contracts.
3. You want loose coupling between components.
4. You want to define a capability without forcing a common class hierarchy.
5. You need default behavior that multiple classes can share.

**Example:**

```java
interface Rechargeable {

    void chargeBattery();
}

class SmartPhone implements Rechargeable {

    @Override
    public void chargeBattery() {

        System.out.println("Phone charging");
    }
}

class SmartWatch implements Rechargeable {

    @Override
    public void chargeBattery() {

        System.out.println("Watch charging");
    }
}
```

A phone and a watch are different types of devices, but both support charging.

## 7.4 Real-World Design: Abstract Class + Interfaces

For a Smart Device Management System:

- `Device` should be an abstract class because all devices share common properties such as device ID, brand and model.
- `Connectable` should be an interface because only some devices support network connectivity.
- `Rechargeable` should be an interface because only some devices have rechargeable batteries.
- `Upgradeable` should be an interface because some devices support software upgrades.

This combination provides reusable common state and flexible capabilities.

---

# 8. Smart Device Management System – Complete Lab

## 8.1 Problem Statement

Design a Smart Device Management System where:

1. `Device` is an abstract class.
2. Interfaces such as `Connectable`, `Rechargeable` and `Upgradeable` define device capabilities.
3. Different devices implement one or more interfaces.
4. Default methods provide common functionality.
5. The system demonstrates abstract methods, multiple interfaces, polymorphism and Java 8/9 interface features.

## 8.2 System Design

### Abstract Class

`Device`

Common properties:
- Device ID
- Device name
- Brand

Common behavior:
- Display device details
- Abstract `powerOn()` method

### Interfaces

`Connectable`
- `connectToWifi()`
- Default `disconnect()`

`Rechargeable`
- `chargeBattery()`
- Default `showBatteryStatus()`

`Upgradeable`
- `upgradeSoftware()`
- Default `checkUpdate()`

### Device Types

| Device | Connectable | Rechargeable | Upgradeable |
|---|---|---|---|
| SmartPhone | Yes | Yes | Yes |
| SmartWatch | Yes | Yes | Yes |
| SmartTV | Yes | No | Yes |
| BluetoothSpeaker | Yes | Yes | No |

## 8.3 Class Diagram

```text
                  Device
              (Abstract Class)
                     |
          -----------------------
          |          |          |
     SmartPhone   SmartTV   SmartWatch
          |          |          |
          |          |          |
      Connectable Connectable Connectable
      Rechargeable           Rechargeable
      Upgradeable Upgradeable Upgradeable

             BluetoothSpeaker
                    |
               Connectable
               Rechargeable
```

## 8.4 Complete Java Program

Save this code as:

`SmartDeviceManagementSystem.java`

```java
import java.util.ArrayList;
import java.util.List;

// ========================================
// 1. Abstract Class
// ========================================

abstract class Device {

    protected int deviceId;

    protected String deviceName;

    protected String brand;

    Device(int deviceId, String deviceName, String brand) {

        this.deviceId = deviceId;

        this.deviceName = deviceName;

        this.brand = brand;
    }

    // Abstract method
    public abstract void powerOn();

    // Concrete method
    public void displayDetails() {

        System.out.println("\nDevice ID: " + deviceId);

        System.out.println("Device Name: " + deviceName);

        System.out.println("Brand: " + brand);
    }
}

// ========================================
// 2. Connectable Interface
// ========================================

interface Connectable {

    void connectToWifi();

    default void disconnect() {

        System.out.println("Device disconnected from WiFi");
    }

    default void showConnectionStatus() {

        System.out.println("Connection status: Active");
    }

    // Private helper method (Java 9+)
    private void validateConnection() {

        System.out.println("Validating network connection...");
    }

    default void reconnect() {

        validateConnection();

        System.out.println("Reconnecting device...");
    }
}

// ========================================
// 3. Rechargeable Interface
// ========================================

interface Rechargeable {

    void chargeBattery();

    default void showBatteryStatus() {

        System.out.println("Battery status: Charging");
    }
}

// ========================================
// 4. Upgradeable Interface
// ========================================

interface Upgradeable {

    void upgradeSoftware();

    default void checkUpdate() {

        System.out.println("Checking for software updates...");
    }

    static void showUpdatePolicy() {

        System.out.println(
            "Software updates should be installed regularly."
        );
    }
}

// ========================================
// 5. SmartPhone Class
// ========================================

class SmartPhone extends Device
        implements Connectable, Rechargeable, Upgradeable {

    SmartPhone(int id, String name, String brand) {

        super(id, name, brand);
    }

    @Override
    public void powerOn() {

        System.out.println("SmartPhone powered ON");
    }

    @Override
    public void connectToWifi() {

        System.out.println("SmartPhone connected to WiFi");
    }

    @Override
    public void chargeBattery() {

        System.out.println("SmartPhone battery charging");
    }

    @Override
    public void upgradeSoftware() {

        System.out.println("SmartPhone software upgraded");
    }
}

// ========================================
// 6. SmartWatch Class
// ========================================

class SmartWatch extends Device
        implements Connectable, Rechargeable, Upgradeable {

    SmartWatch(int id, String name, String brand) {

        super(id, name, brand);
    }

    @Override
    public void powerOn() {

        System.out.println("SmartWatch powered ON");
    }

    @Override
    public void connectToWifi() {

        System.out.println("SmartWatch connected to WiFi");
    }

    @Override
    public void chargeBattery() {

        System.out.println("SmartWatch battery charging");
    }

    @Override
    public void upgradeSoftware() {

        System.out.println("SmartWatch software upgraded");
    }
}

// ========================================
// 7. SmartTV Class
// ========================================

class SmartTV extends Device
        implements Connectable, Upgradeable {

    SmartTV(int id, String name, String brand) {

        super(id, name, brand);
    }

    @Override
    public void powerOn() {

        System.out.println("SmartTV powered ON");
    }

    @Override
    public void connectToWifi() {

        System.out.println("SmartTV connected to WiFi");
    }

    @Override
    public void upgradeSoftware() {

        System.out.println("SmartTV software upgraded");
    }
}

// ========================================
// 8. BluetoothSpeaker Class
// ========================================

class BluetoothSpeaker extends Device
        implements Connectable, Rechargeable {

    BluetoothSpeaker(int id, String name, String brand) {

        super(id, name, brand);
    }

    @Override
    public void powerOn() {

        System.out.println("Bluetooth Speaker powered ON");
    }

    @Override
    public void connectToWifi() {

        System.out.println("Speaker connected");
    }

    @Override
    public void chargeBattery() {

        System.out.println("Speaker battery charging");
    }
}

// ========================================
// 9. Main Management System
// ========================================

public class SmartDeviceManagementSystem {

    public static void main(String[] args) {

        List<Device> devices = new ArrayList<>();

        // Creating device objects
        Device d1 = new SmartPhone(
            101, "Galaxy S24", "Samsung"
        );

        Device d2 = new SmartWatch(
            102, "Galaxy Watch", "Samsung"
        );

        Device d3 = new SmartTV(
            103, "Bravia TV", "Sony"
        );

        Device d4 = new BluetoothSpeaker(
            104, "Sound Speaker", "JBL"
        );

        devices.add(d1);
        devices.add(d2);
        devices.add(d3);
        devices.add(d4);

        // Processing all devices
        for (Device device : devices) {

            device.displayDetails();

            device.powerOn();

            // Connectable capability
            if (device instanceof Connectable c) {

                c.connectToWifi();

                c.showConnectionStatus();
            }

            // Rechargeable capability
            if (device instanceof Rechargeable r) {

                r.chargeBattery();

                r.showBatteryStatus();
            }

            // Upgradeable capability
            if (device instanceof Upgradeable u) {

                u.checkUpdate();

                u.upgradeSoftware();
            }

            System.out.println("--------------------------");
        }

        // Static interface method
        Upgradeable.showUpdatePolicy();

        // Interface default method
        Connectable connection = (Connectable) d1;

        connection.reconnect();
    }
}
```

## 8.5 Expected Output

```text
Device ID: 101
Device Name: Galaxy S24
Brand: Samsung
SmartPhone powered ON
SmartPhone connected to WiFi
Connection status: Active
SmartPhone battery charging
Battery status: Charging
Checking for software updates...
SmartPhone software upgraded
--------------------------

Device ID: 102
Device Name: Galaxy Watch
Brand: Samsung
SmartWatch powered ON
SmartWatch connected to WiFi
Connection status: Active
SmartWatch battery charging
Battery status: Charging
Checking for software updates...
SmartWatch software upgraded
--------------------------

Device ID: 103
Device Name: Bravia TV
Brand: Sony
SmartTV powered ON
SmartTV connected to WiFi
Connection status: Active
Checking for software updates...
SmartTV software upgraded
--------------------------

Device ID: 104
Device Name: Sound Speaker
Brand: JBL
Bluetooth Speaker powered ON
Speaker connected
Connection status: Active
Speaker battery charging
Battery status: Charging
--------------------------
Software updates should be installed regularly.
Validating network connection...
Reconnecting device...
```

## 8.6 Explanation of the Lab

### A. Abstract Device Class

```java
abstract class Device {

    protected int deviceId;

    protected String deviceName;

    protected String brand;

    public abstract void powerOn();
}
```

All devices share common properties.

Instead of writing these properties separately in every device class, we define them once in the abstract class.

Each device provides its own `powerOn()` implementation.

### B. Connectable Interface

```java
interface Connectable {

    void connectToWifi();

    default void disconnect() {
        System.out.println("Device disconnected");
    }
}
```

Any device implementing `Connectable` must provide `connectToWifi()`.

It automatically gets the default `disconnect()` method unless it overrides it.

### C. Rechargeable Interface

```java
interface Rechargeable {

    void chargeBattery();
}
```

Only devices that support charging implement this interface.

For example:
- SmartPhone
- SmartWatch
- BluetoothSpeaker

SmartTV does not implement this interface.

### D. Upgradeable Interface

```java
interface Upgradeable {

    void upgradeSoftware();
}
```

Devices implementing this interface must provide their own software upgrade functionality.

### E. Multiple Interface Implementation

```java
class SmartPhone extends Device
        implements Connectable, Rechargeable, Upgradeable
```

SmartPhone:
- Extends one abstract class.
- Implements three interfaces.

This demonstrates multiple interface implementation.

### F. Pattern Matching

```java
if (device instanceof Rechargeable r) {
    r.chargeBattery();
}
```

The system checks whether the device supports the `Rechargeable` capability.

If it does, the system calls the charging methods.

This avoids manually checking every device type.

### G. Default Methods

```java
default void showBatteryStatus() {
    System.out.println("Battery status: Charging");
}
```

The interface provides common behavior.

Implementing classes can reuse or override it.

### H. Static Interface Method

```java
Upgradeable.showUpdatePolicy();
```

A static method is called using the interface name.

### I. Private Interface Method

```java
private void validateConnection() {
    System.out.println("Validating network connection...");
}
```

This method is used internally by default methods in the interface.

It cannot be called directly by implementing classes.

---

# 9. Abstract Class vs Interface – Practical Example

Consider these two designs.

### Design A: Abstract Class

```java
abstract class Device {

    String brand;

    Device(String brand) {
        this.brand = brand;
    }

    abstract void powerOn();

    void displayBrand() {
        System.out.println(brand);
    }
}
```

This is useful because all devices have common state and initialization logic.

### Design B: Interface

```java
interface Connectable {

    void connectToWifi();
}

interface Rechargeable {

    void chargeBattery();
}
```

These are useful because devices may have different combinations of capabilities.

### Recommended Design

```java
class SmartPhone extends Device
        implements Connectable, Rechargeable {
}
```

Use the abstract class for shared identity and state.

Use interfaces for independent capabilities.

**Remember:**

- Abstract class = What an object fundamentally is.
- Interface = What an object can do.

This is a useful design guideline, not an absolute rule.

---

# 10. Important Interview Questions and Answers

### Q1. What is an abstract class?

An abstract class is a class declared using the `abstract` keyword that cannot be instantiated directly.

### Q2. What is an abstract method?

An abstract method is a method declared without an implementation.

### Q3. Can an abstract class contain concrete methods?

Yes. An abstract class can contain both abstract and concrete methods.

### Q4. Can an abstract class have a constructor?

Yes. Its constructor executes when a subclass object is created.

### Q5. Can we create a reference variable of an abstract class?

Yes. An abstract class reference can refer to an object of a concrete subclass.

### Q6. What is an interface?

An interface defines a contract that implementing classes must follow.

### Q7. Can an interface be instantiated?

No. We cannot directly create an object of an interface.

### Q8. Can a class implement multiple interfaces?

Yes. Java supports multiple interface implementation.

### Q9. Can an interface extend multiple interfaces?

Yes.

Example:

```java
interface A {
}

interface B {
}

interface C extends A, B {
}
```

### Q10. What are interface variables by default?

They are `public static final`.

### Q11. What are interface abstract methods by default?

They are `public abstract`.

### Q12. What is a default method?

A default method is an interface method with an implementation, introduced in Java 8.

### Q13. Why were default methods introduced?

They allow interfaces to evolve by adding behavior without forcing every existing implementing class to implement the new method.

### Q14. Can we override a default method?

Yes.

### Q15. What is a static method in an interface?

A method belonging to the interface itself, called using the interface name.

### Q16. What is a functional interface?

An interface with exactly one abstract method.

### Q17. What is the purpose of `@FunctionalInterface`?

It allows the compiler to verify that the interface has a valid functional-interface structure.

### Q18. Which Java version introduced private methods in interfaces?

Java 9.

### Q19. Why are private methods used in interfaces?

They allow code reuse inside default and static methods.

### Q20. Can an interface have a constructor?

No. Interfaces cannot have constructors.

### Q21. Can an abstract class implement an interface?

Yes. An abstract class can implement an interface and leave some methods unimplemented.

### Q22. Can a class extend an abstract class and implement multiple interfaces?

Yes.

Example:

```java
class SmartPhone extends Device
        implements Connectable, Rechargeable {
}
```

### Q23. What happens if two interfaces have the same default method?

The implementing class must resolve the conflict by overriding the method.

### Q24. Can an abstract method be final?

No. Abstract methods require implementation, whereas final methods cannot be overridden.

### Q25. When should we use an abstract class instead of an interface?

Use an abstract class when related classes need shared instance state, constructors and common implementation.

### Q26. When should we use an interface instead of an abstract class?

Use an interface when different classes need to support a common capability or contract, particularly when multiple capabilities are required.

### Q27. Can an interface have private static methods?

Yes. Java 9 introduced private static methods in interfaces.

### Q28. What is the difference between abstract class and interface?

An abstract class can maintain instance state and have constructors, while an interface primarily defines contracts and supports multiple implementation.

---

# 11. Important MCQs for CMCE

**1. Which keyword is used to declare an abstract class?**

A. `interface`  
B. `abstract`  
C. `final`  
D. `static`

**Answer: B. abstract**

**2. Can we create an object of an abstract class directly?**

A. Yes  
B. No  
C. Only with a constructor  
D. Only using static methods

**Answer: B. No**

**3. Which keyword is used to implement an interface?**

A. `extends`  
B. `implements`  
C. `interface`  
D. `abstract`

**Answer: B. implements**

**4. Can a Java class implement multiple interfaces?**

A. Yes  
B. No  
C. Only two  
D. Only three

**Answer: A. Yes**

**5. Which Java version introduced default methods in interfaces?**

A. Java 5  
B. Java 7  
C. Java 8  
D. Java 11

**Answer: C. Java 8**

**6. Which Java version introduced private methods in interfaces?**

A. Java 8  
B. Java 9  
C. Java 10  
D. Java 11

**Answer: B. Java 9**

**7. Interface variables are implicitly:**

A. private  
B. protected  
C. public static final  
D. public volatile

**Answer: C. public static final**

**8. Which annotation identifies a functional interface?**

A. `@Override`  
B. `@FunctionalInterface`  
C. `@Interface`  
D. `@Lambda`

**Answer: B. @FunctionalInterface**

**9. A functional interface contains how many abstract methods?**

A. Zero  
B. Exactly one  
C. Two  
D. Unlimited

**Answer: B. Exactly one**

**10. Can an interface contain a constructor?**

A. Yes  
B. No  
C. Only private constructors  
D. Only static constructors

**Answer: B. No**

**11. Which keyword is used for a method with an implementation inside an interface?**

A. `abstract`  
B. `default`  
C. `final`  
D. `implements`

**Answer: B. default**

**12. How do we call a static interface method?**

A. Using an object only  
B. Using the interface name  
C. Using `super`  
D. Using `this`

**Answer: B. Using the interface name**

**13. What happens if two unrelated interfaces contain the same default method?**

A. Compiler automatically selects the first  
B. Compiler automatically selects the second  
C. Implementing class must resolve the conflict  
D. Runtime exception occurs

**Answer: C. Implementing class must resolve the conflict**

**14. Which of the following can contain instance variables?**

A. Interface  
B. Abstract class  
C. Both as ordinary instance fields  
D. Neither

**Answer: B. Abstract class**

**15. Which is the best choice for defining a capability shared by unrelated classes?**

A. Constructor  
B. Interface  
C. Final variable  
D. Static block

**Answer: B. Interface**

---

# 12. Output-Based Questions

## Question 1: Abstract Class

```java
abstract class A {

    void display() {
        System.out.println("Abstract class");
    }
}

class B extends A {
}

public class Test1 {

    public static void main(String[] args) {

        B obj = new B();

        obj.display();
    }
}
```

**Answer:**

```text
Abstract class
```

Reason: An abstract class can contain concrete methods inherited by subclasses.

## Question 2: Interface Default Method

```java
interface A {

    default void show() {
        System.out.println("Default method");
    }
}

class B implements A {
}

public class Test2 {

    public static void main(String[] args) {

        B obj = new B();

        obj.show();
    }
}
```

**Answer:**

```text
Default method
```

## Question 3: Static Interface Method

```java
interface A {

    static void display() {
        System.out.println("Static interface method");
    }
}

public class Test3 {

    public static void main(String[] args) {

        A.display();
    }
}
```

**Answer:**

```text
Static interface method
```

## Question 4: Multiple Interfaces

```java
interface A {

    void show();
}

interface B {

    void display();
}

class C implements A, B {

    public void show() {
        System.out.println("A");
    }

    public void display() {
        System.out.println("B");
    }
}

public class Test4 {

    public static void main(String[] args) {

        C obj = new C();

        obj.show();

        obj.display();
    }
}
```

**Answer:**

```text
A
B
```

## Question 5: Abstract Reference and Polymorphism

```java
abstract class Animal {

    abstract void sound();
}

class Dog extends Animal {

    void sound() {
        System.out.println("Dog barks");
    }
}

public class Test5 {

    public static void main(String[] args) {

        Animal a = new Dog();

        a.sound();
    }
}
```

**Answer:**

```text
Dog barks
```

Reason: Runtime polymorphism calls the overridden method of the actual object.

---

# 13. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Abstract Class | Cannot be instantiated directly |
| Abstract Method | Method without body |
| Concrete Method | Method with implementation |
| Constructor in Abstract Class | Allowed |
| Abstract Reference | Can refer to subclass object |
| Interface | Defines a contract |
| `implements` | Used by a class to implement interface |
| Multiple Interfaces | A class can implement multiple interfaces |
| Interface Variables | `public static final` |
| Interface Abstract Methods | `public abstract` |
| Default Method | Introduced in Java 8 |
| Static Interface Method | Introduced in Java 8 |
| Functional Interface | Exactly one abstract method |
| `@FunctionalInterface` | Compiler-checking annotation |
| Private Interface Method | Introduced in Java 9 |
| Private Static Interface Method | Introduced in Java 9 |
| Default Method Conflict | Must be resolved by implementing class |
| Abstract Class | Useful for shared state and behavior |
| Interface | Useful for common capabilities and contracts |

---

# 14. Practice Checklist

- [ ] Understand abstract classes.
- [ ] Understand abstract methods.
- [ ] Create an abstract class with concrete methods.
- [ ] Create an abstract class with a constructor.
- [ ] Create an abstract class reference.
- [ ] Understand interface declaration.
- [ ] Implement a single interface.
- [ ] Implement multiple interfaces.
- [ ] Understand interface variables and methods.
- [ ] Practice default methods.
- [ ] Practice static methods in interfaces.
- [ ] Understand functional interfaces.
- [ ] Practice lambda expressions.
- [ ] Understand private interface methods.
- [ ] Practice private static interface methods.
- [ ] Understand default method conflicts.
- [ ] Understand when to choose abstract class versus interface.
- [ ] Complete the Smart Device Management System.

---

# 15. Additional Practice Assignments

1. Create an abstract class `BankAccount` with an abstract method `calculateInterest()`.
2. Implement `SavingsAccount` and `CurrentAccount`.
3. Create interfaces `Printable` and `Scannable`.
4. Create a `MultiFunctionPrinter` implementing both interfaces.
5. Create a functional interface `Calculator` and implement it using lambda expressions.
6. Create an interface with two default methods and one static method.
7. Create an interface with a private helper method.
8. Create two interfaces with the same default method and resolve the conflict.
9. Create an abstract class `Employee` and interfaces `Payable` and `Promotable`.
10. Extend the Smart Device Management System by adding a `VoiceAssistant` interface.
11. Add a `SmartHomeHub` device that implements multiple interfaces.
12. Create a device report that displays all supported capabilities.

---

# 16. Suggested GitHub Folder Structure

```text
Java/
├── Session-09-Wrapper-Classes-and-String/
│   └── README.md
│
└── Session-11-12-Abstract-Class-and-Interfaces/
    ├── README.md
    └── programs/
        ├── AbstractDemo.java
        ├── AbstractConstructorDemo.java
        ├── AbstractReferenceDemo.java
        ├── InterfaceDemo.java
        ├── MultipleInterfaceDemo.java
        ├── DefaultMethodDemo.java
        ├── InterfaceStaticDemo.java
        ├── FunctionalInterfaceDemo.java
        ├── PrivateInterfaceMethodDemo.java
        ├── DefaultConflictDemo.java
        └── SmartDeviceManagementSystem.java
```

---

# 17. Official Java References

- [Java 17 Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/)
- [Java 17 Language Specification – Abstract Classes](https://docs.oracle.com/javase/specs/jls/se17/html/jls-8.html#jls-8.4.3.1)
- [Java 17 Language Specification – Interfaces](https://docs.oracle.com/javase/specs/jls/se17/html/jls-9.html)
- [Java 17 Language Specification – Default Methods](https://docs.oracle.com/javase/specs/jls/se17/html/jls-9.html#jls-9.4.3)
- [Java 17 Language Specification – Functional Interfaces](https://docs.oracle.com/javase/specs/jls/se17/html/jls-9.html#jls-9.8)

---

**End of Sessions 11 & 12 – Abstract Class and Interfaces**

*Practice the Smart Device Management System independently. Focus especially on multiple interface implementation, default methods, private interface methods and the difference between abstract classes and interfaces.*

