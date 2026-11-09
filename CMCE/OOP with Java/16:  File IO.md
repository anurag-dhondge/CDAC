# Session 16: File I/O in Java

**Course:** CMCE – August 2026 Batch  
**Subject:** Core Java  
**Topic:** File Input/Output, Streams, Readers, Writers, NIO, Serialization and Deserialization

---

## 1. Introduction to File I/O

**File I/O (Input/Output)** in Java refers to reading data from files and writing data into files.

Java provides several classes and interfaces to perform file operations.

File I/O is useful for:

- Storing application data permanently.
- Reading configuration files.
- Creating log files.
- Storing user information.
- Saving and restoring objects.
- Processing text and binary files.

### What is Input?

Input means receiving data from a source.

Example:
- Reading data from a text file.
- Reading an image.
- Reading data from the keyboard.

### What is Output?

Output means sending data to a destination.

Example:
- Writing text into a file.
- Saving an image.
- Writing application logs.

### File I/O Flow

```text
                 Java Application
                        |
              +---------+---------+
              |                   |
              v                   v
           Input                Output
              |                   |
              v                   v
       Read from File        Write to File
              |                   |
              v                   v
         InputStream          OutputStream
         Reader               Writer
```

---

## 2. Introduction to InputStream and OutputStream

Java provides two important abstract classes for byte-based input and output:

1. `InputStream`
2. `OutputStream`

These classes belong to the `java.io` package.

### 2.1 InputStream

`InputStream` is an abstract class used to read byte data from a source.

It is mainly used for binary data such as:

- Images
- Audio files
- Video files
- PDF files
- Other binary files

**Common methods:**

| Method | Description |
|---|---|
| `read()` | Reads one byte of data |
| `read(byte[] b)` | Reads bytes into an array |
| `available()` | Estimates bytes that can be read without blocking |
| `close()` | Closes the input stream |
| `skip(long n)` | Skips a specified number of bytes |

The `read()` method returns:
- A byte value as an integer from 0 to 255.
- `-1` when the end of the stream is reached.

### 2.2 OutputStream

`OutputStream` is an abstract class used to write byte data to a destination.

It is useful for writing binary data.

**Common methods:**

| Method | Description |
|---|---|
| `write(int b)` | Writes one byte |
| `write(byte[] b)` | Writes a byte array |
| `flush()` | Forces buffered output to be written |
| `close()` | Closes the output stream |

### InputStream vs OutputStream

| InputStream | OutputStream |
|---|---|
| Reads data | Writes data |
| Used for input operations | Used for output operations |
| Byte-based | Byte-based |
| Parent of byte-input classes | Parent of byte-output classes |
| Example: FileInputStream | Example: FileOutputStream |

### Example: FileInputStream

`FileInputStream` reads bytes from a file.

**File: InputStreamDemo.java**

```java
import java.io.FileInputStream;
import java.io.IOException;

public class InputStreamDemo {

    public static void main(String[] args) {

        try (FileInputStream fis =
                     new FileInputStream("input.txt")) {

            int data;

            while ((data = fis.read()) != -1) {
                System.out.print((char) data);
            }

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```

**Suppose input.txt contains:**

```text
Hello Java
Welcome to File I/O
```

**Output:**

```text
Hello Java
Welcome to File I/O
```

**Explanation:**

1. `FileInputStream` opens the file.
2. `read()` reads one byte at a time.
3. The byte is converted to a character.
4. The loop continues until `read()` returns `-1`.
5. Try-with-resources closes the stream automatically.

### Example: FileOutputStream

`FileOutputStream` writes bytes into a file.

**File: OutputStreamDemo.java**

```java
import java.io.FileOutputStream;
import java.io.IOException;

public class OutputStreamDemo {

    public static void main(String[] args) {

        String message = "Hello Java File Handling";

        try (FileOutputStream fos =
                     new FileOutputStream("output.txt")) {

            byte[] data = message.getBytes();

            fos.write(data);

            System.out.println("Data written successfully");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```

**Output:**

```text
Data written successfully
```

**Content of output.txt:**

```text
Hello Java File Handling
```

**Important:** `new FileOutputStream("output.txt")` overwrites an existing file by default.

To append instead:

```java
FileOutputStream fos =
        new FileOutputStream("output.txt", true);
```

---

## 3. Reader and Writer Interfaces

Java also provides character-based I/O for reading and writing text.

The two important abstract classes are:

1. `Reader`
2. `Writer`

They belong to the `java.io` package.

### 3.1 Reader

`Reader` is an abstract class used to read character data.

It is suitable for text files.

Examples:
- Reading names.
- Reading sentences.
- Reading source code.
- Reading configuration files.

**Common methods:**

| Method | Description |
|---|---|
| `read()` | Reads one character |
| `read(char[] c)` | Reads characters into an array |
| `close()` | Closes the reader |
| `skip(long n)` | Skips characters |

### 3.2 Writer

`Writer` is an abstract class used to write character data.

It is suitable for writing text files.

**Common methods:**

| Method | Description |
|---|---|
| `write(int c)` | Writes one character |
| `write(String s)` | Writes a string |
| `append(char c)` | Appends a character |
| `flush()` | Flushes buffered data |
| `close()` | Closes the writer |

### Reader vs Writer

| Reader | Writer |
|---|---|
| Reads characters | Writes characters |
| Character-based input | Character-based output |
| Used for text reading | Used for text writing |
| Example: FileReader | Example: FileWriter |

### Byte Streams vs Character Streams

| Byte Streams | Character Streams |
|---|---|
| Work with bytes | Work with characters |
| Suitable for binary data | Suitable for text data |
| InputStream | Reader |
| OutputStream | Writer |
| FileInputStream | FileReader |
| FileOutputStream | FileWriter |

**Remember:**

- Use byte streams for binary files.
- Use character streams for text files.
- Character streams handle character encoding and decoding.

---

## 4. FileWriter – Writing Text into a File

`FileWriter` is a character-based class used to write text into files.

**Example: FileWriterDemo.java**

```java
import java.io.FileWriter;
import java.io.IOException;

public class FileWriterDemo {

    public static void main(String[] args) {

        try (FileWriter writer =
                     new FileWriter("student.txt")) {

            writer.write("Student Name: Anurag\n");
            writer.write("Course: CMCE\n");
            writer.write("Subject: Core Java\n");

            System.out.println("File written successfully");

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

**Output:**

```text
File written successfully
```

**Content of student.txt:**

```text
Student Name: Anurag
Course: CMCE
Subject: Core Java
```

### Append Data Using FileWriter

```java
try (FileWriter writer =
             new FileWriter("student.txt", true)) {

    writer.write("Session: File I/O\n");

}
```

The second argument `true` enables append mode.

---

## 5. FileReader – Reading Text from a File

`FileReader` is used to read character data from a text file.

**Example: FileReaderDemo.java**

```java
import java.io.FileReader;
import java.io.IOException;

public class FileReaderDemo {

    public static void main(String[] args) {

        try (FileReader reader =
                     new FileReader("student.txt")) {

            int data;

            while ((data = reader.read()) != -1) {
                System.out.print((char) data);
            }

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

**Output:**

```text
Student Name: Anurag
Course: CMCE
Subject: Core Java
```

---

## 6. BufferedReader

`BufferedReader` is used to read text efficiently by buffering characters.

Instead of reading one character at a time, it can read a complete line using `readLine()`.

### Important Methods

| Method | Description |
|---|---|
| `read()` | Reads one character |
| `readLine()` | Reads one complete line |
| `ready()` | Checks whether the stream is ready to be read |
| `close()` | Closes the reader |

### Example: BufferedReaderDemo.java

```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class BufferedReaderDemo {

    public static void main(String[] args) {

        try (BufferedReader br =
                     new BufferedReader(
                             new FileReader("student.txt"))) {

            String line;

            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

**Output:**

```text
Student Name: Anurag
Course: CMCE
Subject: Core Java
```

### Why BufferedReader?

- Reads text efficiently using a buffer.
- Provides the convenient `readLine()` method.
- Reduces repeated low-level read operations.
- Commonly used with `FileReader`.

### FileReader vs BufferedReader

| FileReader | BufferedReader |
|---|---|
| Reads characters from a file | Reads buffered character data |
| Does not provide `readLine()` | Provides `readLine()` |
| Can read one character or character array | Can read one character, arrays, or complete lines |
| Often wrapped inside BufferedReader | Often wraps FileReader |

---

## 7. Overview of Java NIO Package

**NIO stands for New I/O.**

Java NIO was introduced in Java 1.4 to provide additional I/O capabilities.

The main package is:

```java
java.nio
```

Important related packages include:

```java
java.nio.file
java.nio.channels
java.nio.charset
java.nio.file.attribute
```

### Why NIO?

Traditional I/O generally uses stream-based operations.

NIO provides additional capabilities such as:

- Buffer-based data handling.
- Channels for reading and writing.
- File and directory operations using `Path` and `Files`.
- Non-blocking I/O through supported channels.
- Improved support for working with large files and network operations.

### Important NIO Components

#### 1. Path

`Path` represents the location of a file or directory.

```java
import java.nio.file.Path;

public class PathDemo {
    public static void main(String[] args) {

        Path path = Path.of("student.txt");

        System.out.println(path);
    }
}
```

**Output:**

```text
student.txt
```

#### 2. Files

`Files` is a utility class that provides methods for file operations.

Common methods:

| Method | Purpose |
|---|---|
| `createFile()` | Creates a file |
| `createDirectory()` | Creates a directory |
| `readString()` | Reads file content as a String |
| `writeString()` | Writes a String to a file |
| `copy()` | Copies a file |
| `move()` | Moves a file |
| `delete()` | Deletes a file |
| `exists()` | Checks whether a path exists |

#### 3. Channels

A Channel represents a connection to a file or another I/O source.

Examples:
- FileChannel
- SocketChannel
- ServerSocketChannel
- DatagramChannel

#### 4. Buffers

A Buffer is a container for data used with NIO channels.

Examples:
- ByteBuffer
- CharBuffer
- IntBuffer
- DoubleBuffer

### Example: Writing and Reading Using NIO

**File: NIODemo.java**

```java
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class NIODemo {

    public static void main(String[] args) {

        Path path = Path.of("nio.txt");

        try {

            Files.writeString(
                    path,
                    "Welcome to Java NIO"
            );

            System.out.println("Data written successfully");

            String data = Files.readString(path);

            System.out.println("File Content: " + data);

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

**Output:**

```text
Data written successfully
File Content: Welcome to Java NIO
```

### Traditional I/O vs NIO

| Traditional I/O | NIO |
|---|---|
| Stream-oriented | Buffer and channel-oriented capabilities |
| Uses InputStream and OutputStream | Uses Channels and Buffers |
| Uses Reader and Writer | Supports character and byte buffers |
| File handling with FileInputStream, FileReader, etc. | File handling with Path and Files |
| Primarily blocking stream operations | Supports blocking and non-blocking channel operations |

**Important:** NIO does not mean every NIO operation is non-blocking. For example, `Files.readString()` is a convenient file operation, not a non-blocking channel operation.

---

## 8. Serialization in Java

**Serialization** is the process of converting an object's state into a byte stream so that it can be stored in a file or transferred.

Serialization is commonly used for:

- Saving an object's state.
- Transferring objects over a network.
- Caching objects.
- Restoring application data later.

### What is Serializable?

`Serializable` is a marker interface in the `java.io` package.

It does not define any methods.

A class must implement `Serializable` to support standard Java object serialization.

### Serialization Flow

```text
             Java Object
                  |
                  v
        ObjectOutputStream
                  |
                  v
          Serialization
                  |
                  v
             Byte Stream
                  |
                  v
                File
```

### Example: Serializable Class

**File: Student.java**

```java
import java.io.Serializable;

public class Student implements Serializable {

    private int rollNo;
    private String name;
    private double marks;

    public Student(int rollNo, String name, double marks) {
        this.rollNo = rollNo;
        this.name = name;
        this.marks = marks;
    }

    public void display() {

        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Marks: " + marks);
    }
}
```

### Serialize an Object

`ObjectOutputStream` is used to write objects into a byte stream.

**File: SerializationDemo.java**

```java
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class SerializationDemo {

    public static void main(String[] args) {

        Student student =
                new Student(101, "Anurag", 85.5);

        try (ObjectOutputStream oos =
                     new ObjectOutputStream(
                             new FileOutputStream("student.ser"))) {

            oos.writeObject(student);

            System.out.println("Object serialized successfully");

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

**Output:**

```text
Object serialized successfully
```

The `student.ser` file contains serialized binary data, not ordinary readable text.

---

## 9. Deserialization in Java

**Deserialization** is the reverse process of serialization.

It converts a stored byte stream back into a Java object.

Java provides `ObjectInputStream` for deserialization.

### Deserialization Flow

```text
                File
                  |
                  v
             Byte Stream
                  |
                  v
         ObjectInputStream
                  |
                  v
          Deserialization
                  |
                  v
             Java Object
```

### Example: Deserialize an Object

**File: DeserializationDemo.java**

```java
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class DeserializationDemo {

    public static void main(String[] args) {

        try (ObjectInputStream ois =
                     new ObjectInputStream(
                             new FileInputStream("student.ser"))) {

            Student student = (Student) ois.readObject();

            System.out.println("Object restored successfully");

            student.display();

        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```

**Expected Output:**

```text
Object restored successfully
Roll No: 101
Name: Anurag
Marks: 85.5
```

**Important:** Run serialization first to create `student.ser`. Then run deserialization.

### Serialization vs Deserialization

| Serialization | Deserialization |
|---|---|
| Converts object into byte stream | Converts byte stream into object |
| Uses ObjectOutputStream | Uses ObjectInputStream |
| Uses `writeObject()` | Uses `readObject()` |
| Stores object state | Restores object state |

---

## 10. transient Keyword in Java

The `transient` keyword is used with instance fields to indicate that they should be skipped by Java's default serialization mechanism.

A transient field is not restored from the serialized stream.

For primitive transient fields, the restored value is the default value.

For reference transient fields, the restored value is `null`.

### Example

Suppose a Student object contains:

- Roll number
- Name
- Marks
- Password

We may want to serialize the student's details but skip the password.

### Serializable Class with transient Field

**File: Student.java**

```java
import java.io.Serializable;

public class Student implements Serializable {

    private int rollNo;
    private String name;
    private double marks;

    private transient String password;

    public Student(int rollNo, String name,
                   double marks, String password) {

        this.rollNo = rollNo;
        this.name = name;
        this.marks = marks;
        this.password = password;
    }

    public void display() {

        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Marks: " + marks);
        System.out.println("Password: " + password);
    }
}
```

### Serialize and Deserialize

**File: TransientDemo.java**

```java
import java.io.*;

public class TransientDemo {

    public static void main(String[] args) {

        Student student =
                new Student(101, "Anurag", 85.5, "abc123");

        // Serialization
        try (ObjectOutputStream oos =
                     new ObjectOutputStream(
                             new FileOutputStream("student.ser"))) {

            oos.writeObject(student);

            System.out.println("Serialization completed");

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }

        // Deserialization
        try (ObjectInputStream ois =
                     new ObjectInputStream(
                             new FileInputStream("student.ser"))) {

            Student restoredStudent =
                    (Student) ois.readObject();

            System.out.println("\nRestored Object Details:");

            restoredStudent.display();

        } catch (IOException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

### Expected Output

```text
Serialization completed

Restored Object Details:
Roll No: 101
Name: Anurag
Marks: 85.5
Password: null
```

### Explanation

| Field | Original Value | Restored Value |
|---|---|---|
| rollNo | 101 | 101 |
| name | Anurag | Anurag |
| marks | 85.5 | 85.5 |
| password | abc123 | null |

The password is skipped because it is declared as `transient`.

### Important Points About transient

- Used with instance variables.
- Transient fields are skipped by default serialization.
- Transient primitive fields get default values after deserialization.
- Transient reference fields become `null`.
- Static fields are not serialized as part of an object's default instance state.
- `transient` does not encrypt or securely erase data.

**Security note:** Do not rely on `transient` alone as a complete security mechanism. Avoid serializing passwords or other secrets in the first place.

---

## 11. serialVersionUID

`serialVersionUID` is a version identifier used during Java serialization and deserialization.

It helps determine whether the serialized object and the current class are compatible.

Example:

```java
private static final long serialVersionUID = 1L;
```

A complete example:

```java
import java.io.Serializable;

public class Employee implements Serializable {

    private static final long serialVersionUID = 1L;

    private int id;
    private String name;

    public Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }
}
```

If the serial version identifiers are incompatible, deserialization can fail with `InvalidClassException`.

**Remember:** Defining an explicit `serialVersionUID` is a good practice for serializable classes whose structure may change over time.

---

# 12. Complete Lab Programs

## Lab 1: Write Data Using FileOutputStream

```java
import java.io.FileOutputStream;
import java.io.IOException;

public class FileOutputStreamLab {

    public static void main(String[] args) {

        String data = "Learning Java File I/O";

        try (FileOutputStream fos =
                     new FileOutputStream("byteData.txt")) {

            fos.write(data.getBytes());

            System.out.println("FileOutputStream: Data written");

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

## Lab 2: Write Data Using FileWriter

```java
import java.io.FileWriter;
import java.io.IOException;

public class FileWriterLab {

    public static void main(String[] args) {

        try (FileWriter fw =
                     new FileWriter("characterData.txt")) {

            fw.write("Learning Java FileWriter");
            fw.write("\nWriting character data");

            System.out.println("FileWriter: Data written");

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

## Lab 3: Read Data Using FileInputStream

```java
import java.io.FileInputStream;
import java.io.IOException;

public class FileInputStreamLab {

    public static void main(String[] args) {

        try (FileInputStream fis =
                     new FileInputStream("byteData.txt")) {

            int data;

            while ((data = fis.read()) != -1) {
                System.out.print((char) data);
            }

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

## Lab 4: Read Data Using FileReader

```java
import java.io.FileReader;
import java.io.IOException;

public class FileReaderLab {

    public static void main(String[] args) {

        try (FileReader fr =
                     new FileReader("characterData.txt")) {

            int ch;

            while ((ch = fr.read()) != -1) {
                System.out.print((char) ch);
            }

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

## Lab 5: Read Data Using BufferedReader

```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class BufferedReaderLab {

    public static void main(String[] args) {

        try (BufferedReader br =
                     new BufferedReader(
                             new FileReader("characterData.txt"))) {

            String line;

            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
```

## Lab 6: Serialization and Deserialization with transient Fields

Use the `Student.java` and `TransientDemo.java` programs from Sections 10 and 11.

Observe that:

- Normal fields are restored with their serialized values.
- The transient password field is restored as `null`.
- The restored object can be used like an ordinary Java object.

---

# 13. Important Interview Questions

**Q1. What is File I/O in Java?**

File I/O is the process of reading data from and writing data to files.

**Q2. What is InputStream?**

InputStream is an abstract class used for byte-based input operations.

**Q3. What is OutputStream?**

OutputStream is an abstract class used for byte-based output operations.

**Q4. What is Reader?**

Reader is an abstract class used for character-based input operations.

**Q5. What is Writer?**

Writer is an abstract class used for character-based output operations.

**Q6. Difference between FileInputStream and FileReader?**

FileInputStream reads bytes, while FileReader reads characters.

**Q7. Difference between FileOutputStream and FileWriter?**

FileOutputStream writes bytes, while FileWriter writes characters.

**Q8. What is BufferedReader?**

BufferedReader reads character data efficiently using a buffer and provides `readLine()`.

**Q9. What is NIO?**

NIO stands for New I/O. It provides buffers, channels, and enhanced file operations.

**Q10. What is Path in Java?**

Path represents a file or directory location in NIO.

**Q11. What is Files in Java?**

Files is a utility class containing methods for creating, reading, writing, copying, moving, and deleting files.

**Q12. What is serialization?**

Serialization converts an object's state into a byte stream.

**Q13. What is deserialization?**

Deserialization restores an object from a byte stream.

**Q14. What is Serializable?**

Serializable is a marker interface used to indicate that a class supports standard Java object serialization.

**Q15. What is ObjectOutputStream?**

It is used to serialize objects using `writeObject()`.

**Q16. What is ObjectInputStream?**

It is used to deserialize objects using `readObject()`.

**Q17. What is transient?**

It marks an instance field to be skipped by default serialization.

**Q18. What happens to transient fields after deserialization?**

They have default values, such as `0`, `false`, or `null`.

**Q19. Are static variables serialized?**

Static variables are not serialized as part of an object's default instance state.

**Q20. What is serialVersionUID?**

It is a version identifier used to check compatibility during deserialization.

**Q21. What happens if a class does not implement Serializable?**

Standard Java serialization of that object normally fails with `NotSerializableException`.

**Q22. What is the difference between byte streams and character streams?**

Byte streams handle raw bytes, while character streams handle text characters.

**Q23. What is try-with-resources?**

It automatically closes resources that implement `AutoCloseable`.

**Q24. Does FileWriter support append mode?**

Yes. Use `new FileWriter("file.txt", true)`.

**Q25. Is Java serialization safe for untrusted data?**

No. Deserializing untrusted data can create serious security risks. Avoid it or apply strict filtering and validation.

---

# 14. MCQs

**1. Which package contains FileInputStream?**

A. java.util  
B. java.io  
C. java.sql  
D. java.lang  

**Answer: B. java.io**

**2. Which class reads byte data from a file?**

A. FileReader  
B. FileWriter  
C. FileInputStream  
D. BufferedReader  

**Answer: C. FileInputStream**

**3. Which class writes character data into a file?**

A. FileOutputStream  
B. FileWriter  
C. FileInputStream  
D. ObjectInputStream  

**Answer: B. FileWriter**

**4. Which method reads a complete line using BufferedReader?**

A. read()  
B. write()  
C. readLine()  
D. nextLine()  

**Answer: C. readLine()**

**5. What does NIO stand for?**

A. New Input Output  
B. Network Input Output  
C. New Integrated Output  
D. None of these  

**Answer: A. New Input Output**

**6. Which interface supports standard Java object serialization?**

A. Cloneable  
B. Runnable  
C. Serializable  
D. Comparable  

**Answer: C. Serializable**

**7. Which class is used to serialize objects?**

A. ObjectInputStream  
B. ObjectOutputStream  
C. FileReader  
D. BufferedReader  

**Answer: B. ObjectOutputStream**

**8. Which method is used to serialize an object?**

A. readObject()  
B. writeObject()  
C. write()  
D. serialize()  

**Answer: B. writeObject()**

**9. Which method restores an object?**

A. writeObject()  
B. readObject()  
C. restore()  
D. getObject()  

**Answer: B. readObject()**

**10. Which keyword skips a field during default serialization?**

A. static  
B. final  
C. transient  
D. volatile  

**Answer: C. transient**

**11. What is the restored value of a transient reference field if it is not otherwise initialized?**

A. 0  
B. false  
C. null  
D. Empty String  

**Answer: C. null**

**12. Which class provides file operations in NIO?**

A. FileReader  
B. Files  
C. Object  
D. Serializable  

**Answer: B. Files**

**13. Which NIO type represents a file path?**

A. FileInputStream  
B. Path  
C. Reader  
D. Writer  

**Answer: B. Path**

**14. Which class reads serialized objects?**

A. ObjectOutputStream  
B. ObjectInputStream  
C. FileWriter  
D. FileOutputStream  

**Answer: B. ObjectInputStream**

**15. Which method closes a stream?**

A. stop()  
B. end()  
C. close()  
D. terminate()  

**Answer: C. close()**

---

# 15. Quick Revision Notes

| Topic | Important Point |
|---|---|
| InputStream | Byte-based input |
| OutputStream | Byte-based output |
| Reader | Character-based input |
| Writer | Character-based output |
| FileInputStream | Reads bytes from a file |
| FileOutputStream | Writes bytes to a file |
| FileReader | Reads characters from a file |
| FileWriter | Writes characters to a file |
| BufferedReader | Buffered text reading |
| readLine() | Reads one complete line |
| NIO | New I/O |
| Path | Represents file location |
| Files | Utility methods for file operations |
| Channel | Connection for I/O operations |
| Buffer | Container for data |
| Serialization | Object to byte stream |
| Deserialization | Byte stream to object |
| Serializable | Marker interface |
| ObjectOutputStream | Writes objects |
| ObjectInputStream | Reads objects |
| transient | Skips field in default serialization |
| serialVersionUID | Serialization version identifier |

### Important Methods to Remember

```java
// Byte input
fis.read();

// Byte output
fos.write(data);

// Character input
fr.read();

// Character output
fw.write("Hello");

// Read a complete line
br.readLine();

// Serialize object
oos.writeObject(object);

// Deserialize object
ois.readObject();

// NIO
Files.readString(path);
Files.writeString(path, "Hello");
```

---

# 16. Practice Checklist

- [ ] Understand InputStream and OutputStream.
- [ ] Understand Reader and Writer.
- [ ] Differentiate byte streams and character streams.
- [ ] Write data using FileOutputStream.
- [ ] Write data using FileWriter.
- [ ] Read data using FileInputStream.
- [ ] Read data using FileReader.
- [ ] Read lines using BufferedReader.
- [ ] Understand the NIO package.
- [ ] Practice Path and Files.
- [ ] Understand serialization and deserialization.
- [ ] Implement Serializable.
- [ ] Use ObjectOutputStream and ObjectInputStream.
- [ ] Understand transient fields.
- [ ] Practice serialVersionUID.
- [ ] Complete all File I/O lab programs.

---

## References

- [Oracle Java I/O Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/io/package-summary.html)
- [Oracle Java NIO Documentation](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/nio/package-summary.html)
- [Java Serialization Documentation](https://docs.oracle.com/en/java/javase/17/docs/specs/serialization/index.html)

**Note:** This README is prepared for the CMCE August 2026 Batch and covers Session 16 – File I/O in Core Java.
