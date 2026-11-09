# 🌐 CMCE – Web Programming Technologies
# Session 1: Architecture of Web

**Program:** PGCP-AC (CMCE)  
**Batch:** August 2026  
**Institute:** ACTS, Pune  
**Session:** 1  
**Duration:** 2 Theory Hours

---

# 1. Introduction to the Internet

## 1.1 What is the Internet?

The **Internet** is a worldwide network of interconnected computer networks that communicate with each other using standard communication protocols such as TCP/IP.

In simple words, the Internet connects millions of computers, smartphones, servers and other devices so that they can exchange information.

### Examples of Internet Applications

1. Web browsing – Google, YouTube, Amazon.
2. Email – Gmail, Outlook.
3. Social Networking – Instagram, Facebook.
4. Online Banking – Internet banking applications.
5. Video Conferencing – Google Meet, Zoom.
6. File Transfer – Uploading and downloading files.
7. Cloud Computing – Google Drive, Microsoft OneDrive.

## 1.2 History and Evolution of the Internet

The Internet developed over several decades.

| Year | Development |
|---|---|
| 1960s | Research into packet-switching networks |
| 1969 | ARPANET connected its first nodes |
| 1970s | TCP/IP protocols were developed |
| 1983 | ARPANET adopted TCP/IP |
| 1984 | DNS was introduced |
| 1989 | Tim Berners-Lee proposed the World Wide Web |
| 1991 | The World Wide Web became publicly available |
| 1993 | Mosaic graphical web browser was released |
| 1995 | Commercial Internet expansion accelerated |
| 2000s | Web 2.0, social networking and interactive websites |
| 2010s | Cloud computing, mobile applications and modern web technologies |
| 2020s | AI-powered applications, edge computing and advanced web platforms |

**Important people:**

- Vint Cerf and Bob Kahn: Major contributors to TCP/IP development.
- Tim Berners-Lee: Invented the World Wide Web.
- Paul Mockapetris: Designed the Domain Name System (DNS).

## 1.3 What is ARPANET?

ARPANET stands for **Advanced Research Projects Agency Network**.

It was an early packet-switching network developed by the US Department of Defense's research agency.

Important points:

- Started in 1969.
- Connected research institutions and universities.
- Used packet-switching technology.
- Became an important foundation for the development of the Internet.

## 1.4 What is Packet Switching?

Packet switching is a communication technique in which large data is divided into smaller units called packets.

Each packet contains information required to reach its destination.

### Example

Suppose you send a 10 MB image to your friend.

Instead of transferring it as one huge unit, the data is divided into smaller packets.

```text
Original File: 10 MB
       |
       v
  Packet Switching
       |
  ---------------------
  |    |    |    |    |
  v    v    v    v    v
 P1   P2   P3   P4   P5
  |    |    |    |    |
  ---------------------
       |
       v
 Destination Device
       |
       v
 Packets Reassembled
       |
       v
 Original Image
```

Advantages:

- Efficient use of network resources.
- Multiple devices can share network links.
- Packets can travel through different routes.
- Network failures can sometimes be handled through alternative routes.

**Note:** TCP provides reliable, ordered delivery of a byte stream. IP handles addressing and forwarding of packets.

---

# 2. Internet vs World Wide Web

These two terms are often used interchangeably, but they are different.

## 2.1 What is the World Wide Web (WWW)?

The World Wide Web is a system of interconnected documents and resources that can be accessed over the Internet using web browsers.

It uses technologies such as:

- HTML
- HTTP/HTTPS
- URLs
- Web browsers
- Web servers

Examples:

- Google Search
- Wikipedia
- Amazon
- YouTube

## 2.2 Difference Between Internet and WWW

| Internet | World Wide Web |
|---|---|
| Global network of interconnected networks | Collection of interconnected web resources |
| Provides network connectivity | Provides access to web pages and applications |
| Uses TCP/IP and other networking protocols | Primarily uses HTTP/HTTPS |
| Includes email, FTP, VoIP and WWW | One of the services running on the Internet |
| Infrastructure for communication | Information-sharing system |

**Remember:** The Internet is the infrastructure, while the WWW is a service that runs on it.

---

# 3. How Does the Internet Work?

The Internet works through interconnected networks, routers, switches, servers and communication protocols.

When you access a website, multiple operations happen in the background.

### Step-by-step working

Suppose you enter:

`https://www.google.com`

1. You enter the website address in your browser.
2. The browser identifies the domain name.
3. DNS resolves the domain name into an IP address.
4. The browser establishes the required network connection.
5. For HTTPS, a secure TLS connection is established.
6. The browser sends an HTTP request.
7. The server processes the request.
8. The server sends an HTTP response.
9. The browser receives HTML, CSS, JavaScript and other resources.
10. The browser renders the webpage.

### Diagram

```text
          USER
            |
            v
       WEB BROWSER
            |
            v
       DNS LOOKUP
            |
            v
       IP ADDRESS
            |
            v
    SERVER CONNECTION
            |
            v
     HTTP REQUEST
            |
            v
       WEB SERVER
            |
            v
     HTTP RESPONSE
            |
            v
      WEB BROWSER
            |
            v
       WEB PAGE
```

---

# 4. Client and Server Architecture

## 4.1 What is a Client?

A client is a computer or software application that requests services or resources from a server.

Examples:

- Google Chrome
- Mozilla Firefox
- Mobile applications
- Postman
- React frontend applications

## 4.2 What is a Server?

A server is a computer or software application that receives requests from clients and provides the required services or resources.

Examples:

- Apache HTTP Server
- Microsoft IIS
- Nginx
- Node.js applications
- Database servers

## 4.3 Client-Server Communication

Communication generally follows the request-response model.

```text
       CLIENT
    (Web Browser)
          |
          | Request
          v
       SERVER
          |
          | Processing
          |
          v
       RESPONSE
          |
          v
       CLIENT
```

### Real-world example

When you log in to a website:

1. You enter your username and password.
2. The browser sends the login request to the server.
3. The server validates the credentials.
4. The server checks the database if required.
5. The server returns a success or failure response.
6. The browser displays the result.

## 4.4 Types of Clients

- Thick Client: Performs a significant amount of processing locally.
- Thin Client: Depends heavily on a server for processing and services.
- Web Client: Uses a browser to access web applications.

---

# 5. Internet Protocols

## 5.1 What is a Protocol?

A protocol is a set of rules and standards that define how devices communicate and exchange information over a network.

In simple words, protocols define how data should be formatted, transmitted, received and interpreted.

### Why are protocols required?

Without communication protocols, different devices and operating systems would not have a common method of exchanging information.

Protocols define:

1. Data format.
2. Communication rules.
3. Error handling.
4. Addressing.
5. Data transmission.
6. Connection management.

## 5.2 Important Internet Protocols

| Protocol | Full Form | Purpose |
|---|---|---|
| IP | Internet Protocol | Addressing and routing packets |
| TCP | Transmission Control Protocol | Reliable data transmission |
| UDP | User Datagram Protocol | Fast, connectionless data transmission |
| HTTP | Hypertext Transfer Protocol | Web communication |
| HTTPS | Hypertext Transfer Protocol Secure | Secure web communication |
| FTP | File Transfer Protocol | File transfer |
| SMTP | Simple Mail Transfer Protocol | Sending emails |
| POP3 | Post Office Protocol Version 3 | Retrieving emails |
| IMAP | Internet Message Access Protocol | Accessing and synchronizing emails |
| DNS | Domain Name System | Resolving domain names |

## 5.3 Internet Protocol (IP)

IP stands for Internet Protocol.

It is responsible for addressing and routing packets from a source device to a destination device.

Every device communicating over an IP network uses an IP address.

### Types of IP Addresses

**1. IPv4**

- Uses 32-bit addressing.
- Written in dotted-decimal notation.
- Contains four octets.
- Each octet ranges from 0 to 255.

Example:

```text
192.168.1.10
```

IPv4 supports approximately 4.3 billion addresses.

**2. IPv6**

- Uses 128-bit addressing.
- Written in hexadecimal notation.
- Uses colons to separate groups.

Example:

```text
2001:db8:85a3::8a2e:370:7334
```

IPv6 provides a significantly larger address space than IPv4.

### IPv4 vs IPv6

| Feature | IPv4 | IPv6 |
|---|---|---|
| Address Size | 32 bits | 128 bits |
| Format | Decimal | Hexadecimal |
| Separator | Dot (.) | Colon (:) |
| Example | 192.168.1.1 | 2001:db8::1 |
| Address Space | Approximately 4.3 billion | 2¹²⁸ addresses |

## 5.4 TCP – Transmission Control Protocol

TCP is a connection-oriented transport-layer protocol that provides reliable and ordered data transmission.

### Features

1. Connection-oriented.
2. Reliable data delivery.
3. Error detection.
4. Data sequencing.
5. Retransmission of lost data.
6. Flow control.
7. Congestion control.

### How TCP Works

TCP uses a three-way handshake to establish a connection.

**Three-way handshake:**

```text
       CLIENT                 SERVER
          |                      |
          |------ SYN ---------->|
          |                      |
          |<----- SYN-ACK -------|
          |                      |
          |------ ACK ---------->|
          |                      |
          |   CONNECTION READY   |
```

Steps:

1. SYN: Client requests a connection.
2. SYN-ACK: Server acknowledges and responds.
3. ACK: Client acknowledges the server.

After this process, data transmission can begin.

## 5.5 UDP – User Datagram Protocol

UDP is a connectionless transport-layer protocol that sends data without establishing a connection first.

### Features

- No connection establishment.
- Low communication overhead.
- No guarantee of delivery.
- No guarantee of packet ordering.
- No retransmission mechanism built into UDP.
- Useful for time-sensitive communication.

### Applications

- Live video streaming.
- Online gaming.
- Voice over IP.
- DNS queries.
- Real-time communication.

## 5.6 TCP vs UDP

| TCP | UDP |
|---|---|
| Connection-oriented | Connectionless |
| Reliable delivery | No delivery guarantee |
| Maintains packet order | No ordering guarantee |
| Uses acknowledgements | No acknowledgement mechanism built in |
| Retransmits lost data | No retransmission mechanism built in |
| Higher overhead | Lower overhead |
| Used by traditional HTTP/1.1 and HTTP/2 over TCP | Used by DNS and real-time applications |
| Connection establishment required | No connection establishment required |

**Important:** HTTP/3 uses QUIC, which runs over UDP. Therefore, not all HTTP versions use TCP.

## 5.7 FTP – File Transfer Protocol

FTP is a protocol used to transfer files between a client and a server.

Operations:

- Upload files.
- Download files.
- Rename files.
- Delete files.
- List directory contents.

Example:

A developer can use FTP to upload website files to a hosting server.

Traditional FTP does not encrypt credentials or data. Secure alternatives include SFTP and FTPS.

## 5.8 Email Protocols

**SMTP – Simple Mail Transfer Protocol**

Used to send and relay emails.

**POP3 – Post Office Protocol Version 3**

Used to retrieve emails from a mail server, traditionally downloading messages to a client.

**IMAP – Internet Message Access Protocol**

Used to access and synchronize emails stored on a mail server across multiple devices.

### SMTP vs POP3 vs IMAP

| SMTP | POP3 | IMAP |
|---|---|---|
| Sends emails | Retrieves emails | Accesses and synchronizes emails |
| Outgoing mail | Incoming mail | Incoming mail |
| Mail transfer | Mail retrieval | Mail synchronization |

---

# 6. Domain Names and DNS

## 6.1 What is an IP Address?

An IP address is a numerical address assigned to a device or network interface for communication over an IP network.

Example:

```text
142.250.183.14
```

Remembering numerical IP addresses for every website is difficult.

This is why domain names are used.

## 6.2 What is a Domain Name?

A domain name is a human-readable name used to identify a website or Internet service.

Examples:

- google.com
- amazon.in
- wikipedia.org
- github.com

A domain name maps to network information, commonly an IP address, through DNS.

## 6.3 Domain Name vs IP Address

| Domain Name | IP Address |
|---|---|
| Human-readable name | Numerical network address |
| Easier to remember | Difficult to remember |
| Used to identify Internet services | Used for network addressing |
| Example: google.com | Example: 142.250.183.14 |

## 6.4 Structure of a Domain Name

Consider:

```text
www.google.com
```

It contains:

- www – Host name or subdomain.
- google – Second-level domain.
- com – Top-Level Domain (TLD).

### Types of Domain Extensions

| Extension | Common Association |
|---|---|
| .com | Commercial |
| .org | Organizations |
| .edu | Educational institutions, primarily in the US |
| .gov | Government, primarily in the US |
| .net | Originally network-related |
| .in | India country-code domain |
| .uk | United Kingdom |
| .io | Country-code domain widely used in technology |

## 6.5 What is DNS?

DNS stands for **Domain Name System**.

DNS is a distributed naming system that translates domain names into information required to locate Internet services, commonly IP addresses.

In simple words:

DNS works like the phonebook of the Internet.

### Example

You enter:

```text
www.google.com
```

Your computer needs the corresponding IP address to communicate with the destination.

DNS helps find that address.

## 6.6 Why is DNS Required?

- Humans remember names more easily than IP addresses.
- Websites can change IP addresses without requiring users to remember new addresses.
- DNS provides a distributed naming infrastructure.
- It supports different types of Internet services.

## 6.7 DNS Architecture

Important DNS components:

**1. DNS Resolver**

Receives DNS queries from client devices and performs the resolution process.

**2. Root Name Server**

Provides information about the appropriate Top-Level Domain name servers.

**3. TLD Name Server**

Provides information about authoritative name servers for domains under a particular TLD.

**4. Authoritative Name Server**

Provides the DNS records for the domain it manages.

## 6.8 DNS Resolution Process

Suppose you visit:

```text
www.example.com
```

The simplified resolution process is:

```text
       USER
         |
         v
    WEB BROWSER
         |
         v
    DNS RESOLVER
         |
         v
    ROOT SERVER
         |
         v
    TLD SERVER (.com)
         |
         v
 AUTHORITATIVE SERVER
         |
         v
      IP ADDRESS
         |
         v
    WEB BROWSER
         |
         v
    WEB SERVER
```

Steps:

1. User enters the domain name.
2. The browser or operating system checks available DNS caches.
3. If the answer is not cached, the DNS resolver performs a lookup.
4. The resolver queries a root name server.
5. The root server directs it to the appropriate TLD server.
6. The TLD server directs it to the authoritative name server.
7. The authoritative server provides the requested DNS record.
8. The resolver returns the result to the client.
9. The browser can now connect to the destination server.

**Important:** This is a simplified iterative lookup explanation. A DNS resolver normally performs the queries on behalf of the client and may use cached answers.

## 6.9 DNS Records

DNS stores different types of records.

| Record | Purpose |
|---|---|
| A | Maps a domain to an IPv4 address |
| AAAA | Maps a domain to an IPv6 address |
| CNAME | Creates an alias for another domain name |
| MX | Specifies mail servers for a domain |
| NS | Identifies authoritative name servers |
| TXT | Stores text information, often used for verification and email security |

### Examples

**A Record**

```text
example.com → 93.184.216.34
```

**AAAA Record**

```text
example.com → IPv6 address
```

**CNAME Record**

```text
www.example.com → example.com
```

**MX Record**

Specifies which mail servers receive emails for a domain.

## 6.10 Practical DNS Commands

Open Command Prompt.

Find the IP address of a domain:

```bash
nslookup google.com
```

Check DNS information:

```bash
nslookup github.com
```

Check network configuration:

```bash
ipconfig /all
```

Clear the Windows DNS cache:

```bash
ipconfig /flushdns
```

---

# 7. HTTP – Hypertext Transfer Protocol

## 7.1 What is HTTP?

HTTP stands for **Hypertext Transfer Protocol**.

HTTP is an application-layer protocol used for communication between clients and servers on the Web.

It defines how clients request resources and how servers respond.

Examples:

- Loading a webpage.
- Submitting a registration form.
- Retrieving product information.
- Sending data to an API.
- Downloading an image.

## 7.2 Why is HTTP Required?

HTTP provides standard rules for web communication.

It defines:

1. Request methods.
2. Request and response structure.
3. Headers.
4. Status codes.
5. Resource identification.
6. Communication semantics.

## 7.3 HTTP Request and HTTP Response

HTTP communication follows a request-response model.

**HTTP Request:** A message sent by a client to a server requesting an operation.

**HTTP Response:** A message returned by the server containing the result of the requested operation.

### HTTP Communication

```text
      CLIENT
         |
         | HTTP REQUEST
         v
      SERVER
         |
         | PROCESS REQUEST
         |
         v
      DATABASE
         |
         v
      SERVER
         |
         | HTTP RESPONSE
         v
      CLIENT
```

## 7.4 Structure of an HTTP Request

An HTTP request generally contains:

1. Request line.
2. Request headers.
3. Blank line.
4. Optional request body.

Example:

```http
GET /products HTTP/1.1
Host: example.com
Accept: application/json
User-Agent: Chrome
```

Explanation:

- GET: HTTP method.
- /products: Requested resource path.
- HTTP/1.1: HTTP version.
- Host: Identifies the target host.
- Accept: Indicates acceptable response formats.
- User-Agent: Identifies the client software.

### HTTP Request Body

Some methods, such as POST and PUT, commonly include a request body.

Example:

```http
POST /users HTTP/1.1
Host: example.com
Content-Type: application/json

{
  "name": "Anurag",
  "email": "anurag@example.com"
}
```

## 7.5 Structure of an HTTP Response

An HTTP response generally contains:

1. Status line.
2. Response headers.
3. Blank line.
4. Optional response body.

Example:

```http
HTTP/1.1 201 Created
Content-Type: application/json

{
  "message": "User created successfully"
}
```

Explanation:

- HTTP/1.1: Protocol version.
- 201: Status code.
- Created: Reason phrase.
- Content-Type: Response content format.
- Body: Actual response data.

## 7.6 HTTP Request Methods

HTTP methods define what operation the client wants to perform on a resource.

### 1. GET

Used to retrieve information from a server.

Example:

```http
GET /students
```

Real-world example: Displaying a list of students.

### 2. POST

Used to submit data to a server, commonly to create a new resource or perform an operation.

Example:

```http
POST /students
```

Real-world example: Registering a new student.

### 3. HEAD

Similar to GET, but the server returns response headers without the response body.

Example:

```http
HEAD /students
```

Use: Checking resource metadata without downloading its content.

### 4. PUT

Used to create or completely replace the state of a resource at a specified URI.

Example:

```http
PUT /students/101
```

Real-world example: Replacing the details of student 101.

### 5. PATCH

Used to partially update an existing resource.

Example:

```http
PATCH /students/101
```

Real-world example: Updating only the student's phone number.

### 6. DELETE

Used to delete a specified resource.

Example:

```http
DELETE /students/101
```

Real-world example: Deleting student 101.

### 7. OPTIONS

Used to identify the communication options supported by a server or resource.

Example:

```http
OPTIONS /students
```

### 8. TRACE

Used for diagnostic message loop-back testing.

It is generally disabled on production servers due to security considerations.

## 7.7 GET vs POST

| GET | POST |
|---|---|
| Retrieves information | Submits information |
| Parameters commonly appear in URL query strings | Data commonly appears in request body |
| Intended to be safe | Not inherently safe |
| Generally cacheable | Not cacheable by default |
| Can be bookmarked with URL parameters | Request body is not stored in the URL |
| Example: Search products | Example: Register user |

**Important:** POST data is not automatically secure. HTTPS is required to protect data in transit.

## 7.8 PUT vs PATCH

| PUT | PATCH |
|---|---|
| Creates or replaces a resource | Partially modifies a resource |
| Usually sends a complete representation | Sends only the required changes |
| Idempotent | Not necessarily idempotent |
| Example: Replace complete student record | Example: Update student phone number |

## 7.9 HTTP Status Codes

HTTP status codes are three-digit numbers returned by a server to indicate the outcome of a request.

There are five major categories.

### 1xx – Informational

The request has been received and the process is continuing.

Examples:

- 100 Continue
- 101 Switching Protocols

### 2xx – Success

The request was successfully received, understood and processed.

| Code | Meaning |
|---|---|
| 200 | OK |
| 201 | Created |
| 202 | Accepted |
| 204 | No Content |

### 3xx – Redirection

The client needs to take additional action to complete the request, commonly by following a redirect.

| Code | Meaning |
|---|---|
| 301 | Moved Permanently |
| 302 | Found |
| 303 | See Other |
| 304 | Not Modified |
| 307 | Temporary Redirect |
| 308 | Permanent Redirect |

### 4xx – Client Error

The request contains an error or cannot be fulfilled due to a client-side issue.

| Code | Meaning |
|---|---|
| 400 | Bad Request |
| 401 | Unauthorized |
| 403 | Forbidden |
| 404 | Not Found |
| 405 | Method Not Allowed |
| 408 | Request Timeout |
| 409 | Conflict |
| 429 | Too Many Requests |

### 5xx – Server Error

The server failed to fulfil a valid request.

| Code | Meaning |
|---|---|
| 500 | Internal Server Error |
| 501 | Not Implemented |
| 502 | Bad Gateway |
| 503 | Service Unavailable |
| 504 | Gateway Timeout |

### Important Difference: 401 vs 403

- 401 Unauthorized: Authentication is required or the supplied authentication credentials are invalid.
- 403 Forbidden: The server understands the request but refuses access.

### Important Difference: 404 vs 500

- 404: Requested resource could not be found.
- 500: An unexpected error occurred on the server.

---

# 8. Stateless Nature of HTTP

## 8.1 What is a Stateless Protocol?

A stateless protocol does not automatically retain application-level information from one request to the next.

HTTP is a stateless protocol.

This means each HTTP request is treated independently by the protocol.

### Example

Suppose you log in to an online shopping website.

1. You send a login request.
2. The server validates your credentials.
3. You open the product page.
4. You open the shopping cart.

HTTP does not automatically remember your login information between these requests.

The application must implement a mechanism to maintain the user's state.

## 8.2 Why is HTTP Stateless?

- Each request is independent.
- HTTP does not automatically maintain user-specific session state.
- Requests can be handled by different server instances.
- Stateless communication simplifies the basic protocol design.

## 8.3 Problems with Stateless HTTP

Without state management, applications would struggle to maintain:

- Login information.
- Shopping cart details.
- User preferences.
- Authentication status.
- Multi-step form progress.

To solve this, web applications use cookies, sessions and tokens.

---

# 9. HTTP Sessions

## 9.1 What is a Session?

A session is a mechanism used by a web application to maintain user-specific state across multiple HTTP requests.

In simple words, a session helps a website remember a user's activity between requests.

### Example: Online Shopping

1. User logs in.
2. Server creates a session.
3. Server generates a session ID.
4. Session ID is sent to the browser, commonly through a cookie.
5. Browser sends the cookie with subsequent requests.
6. Server uses the session ID to identify the user's session.

### Session Working Diagram

```text
        CLIENT
           |
           | Login Request
           v
        SERVER
           |
           | Validate User
           |
           v
     Create Session
           |
           v
     Generate Session ID
           |
           v
      Send Cookie
           |
           v
        CLIENT
           |
           | Next Request
           | Cookie + Session ID
           v
        SERVER
           |
           v
     Identify Session
           |
           v
     Continue User Activity
```

## 9.2 What is a Cookie?

A cookie is a small piece of data stored by a browser for a website.

Cookies are commonly used for:

- Session identification.
- User preferences.
- Authentication-related information.
- Tracking and personalization.

Example:

```http
Set-Cookie: sessionId=abc123; HttpOnly; Secure
```

The browser can send the cookie in subsequent requests:

```http
Cookie: sessionId=abc123
```

## 9.3 What is a Session ID?

A Session ID is a unique identifier associated with a user's session.

It allows the server to retrieve the correct session information.

Example:

```text
sessionId = abc123xyz
```

A session ID should be unpredictable and protected from unauthorized access.

## 9.4 Cookies vs Sessions

| Cookies | Sessions |
|---|---|
| Stored on the client browser | Commonly stored on the server |
| Can store small amounts of data | Can maintain application session data |
| Sent with matching requests | Identified through a session ID or other mechanism |
| Can have expiration dates | Usually have server-controlled expiration |
| Can be modified by the client unless protected | Server-side session data is not directly stored in the browser |

**Important:** A session is an application-level concept. It is commonly implemented using a server-side store and a browser cookie, but other approaches are possible.

---

# 10. HTTPS – Hypertext Transfer Protocol Secure

## 10.1 What is HTTPS?

HTTPS stands for **Hypertext Transfer Protocol Secure**.

HTTPS is HTTP communication protected using TLS (Transport Layer Security).

It provides secure communication between a client and a server.

Example:

```text
https://www.google.com
```

## 10.2 Why is HTTPS Required?

Normal HTTP does not provide encryption by itself.

If sensitive information is sent through an unencrypted connection, attackers may be able to intercept or modify the data.

HTTPS helps protect:

1. Login credentials.
2. Banking information.
3. Personal information.
4. Payment information.
5. Communication between browser and server.

## 10.3 Features of HTTPS

**1. Encryption**

Protects information from being read by unauthorized parties during transmission.

**2. Authentication**

Helps the browser verify the identity of the server using digital certificates.

**3. Data Integrity**

Helps detect unauthorized modification of transmitted data.

## 10.4 What is SSL?

SSL stands for **Secure Sockets Layer**.

It was an earlier protocol designed to secure communication over networks.

SSL is obsolete and should not be used in modern systems.

## 10.5 What is TLS?

TLS stands for **Transport Layer Security**.

TLS is the modern cryptographic protocol used to secure communication.

HTTPS uses TLS to protect HTTP communication.

## 10.6 What is a Digital Certificate?

A digital certificate is an electronic document used to associate a public key with an identity, such as a website's domain name.

It is issued by a trusted Certificate Authority (CA).

A browser verifies the certificate as part of establishing a secure connection.

## 10.7 Basic HTTPS Handshake

```text
        CLIENT
           |
           | ClientHello
           v
        SERVER
           |
           | ServerHello
           | Certificate
           v
        CLIENT
           |
           | Certificate Validation
           | Key Establishment
           v
     SECURE CONNECTION
           |
           v
     ENCRYPTED HTTP DATA
```

This is a simplified view of a TLS handshake. Modern TLS uses more detailed key-exchange and authentication procedures.

## 10.8 HTTP vs HTTPS

| HTTP | HTTPS |
|---|---|
| Hypertext Transfer Protocol | Hypertext Transfer Protocol Secure |
| No built-in transport encryption | Uses TLS encryption |
| No server authentication through TLS | Supports server authentication through certificates |
| No TLS integrity protection | Provides integrity protection |
| Common default port 80 | Common default port 443 |
| URL starts with http:// | URL starts with https:// |

**Remember:** HTTPS is not a separate replacement for HTTP methods. It is HTTP communication protected by TLS.

---

# 11. Architecture of the Web

## 11.1 What is Web Architecture?

Web Architecture describes the structure and interaction of the components involved in developing and running web applications.

It defines how clients, web servers, application servers and databases communicate.

### Main Components

1. Client / Web Browser.
2. Web Server.
3. Application Server.
4. Database Server.
5. Network and Communication Protocols.

## 11.2 Client-Side

The client-side is the part of a web application that runs in the user's browser.

Technologies:

- HTML – Defines webpage structure.
- CSS – Controls webpage presentation.
- JavaScript – Adds interactivity.
- React – Builds component-based user interfaces.

Examples:

- Login form.
- Navigation bar.
- Product list.
- Dashboard.
- Registration page.

## 11.3 Server-Side

The server-side is responsible for processing requests, applying business logic and communicating with databases or other services.

Technologies:

- Node.js
- Express.js
- Java Spring Boot
- Python Flask
- Python Django

Responsibilities:

- User authentication.
- Business logic.
- Data validation.
- Database operations.
- API development.
- Response generation.

## 11.4 Database Server

A database server stores and manages application data.

Examples:

- MySQL
- PostgreSQL
- MongoDB
- Oracle Database
- SQL Server

Responsibilities:

- Store data.
- Retrieve data.
- Update data.
- Delete data.
- Manage transactions.
- Maintain data consistency.

## 11.5 Three-Tier Architecture

Three-tier architecture divides an application into three logical layers.

**1. Presentation Layer**

Responsible for displaying information and accepting user input.

Example: React frontend.

**2. Application / Business Logic Layer**

Processes requests and implements application logic.

Example: Node.js with Express.

**3. Data Layer**

Stores and manages application information.

Example: MySQL database.

### Diagram

```text
       USER
         |
         v
  PRESENTATION LAYER
     React / HTML
         |
         v
  APPLICATION LAYER
    Node / Express
         |
         v
      DATA LAYER
       MySQL
```

### Advantages

- Separation of responsibilities.
- Easier maintenance.
- Better scalability.
- Improved organization.
- Easier testing.
- Independent development of layers.

---

# 12. Web Servers

## 12.1 What is a Web Server?

A web server is software, and the computer running it, that accepts HTTP requests and provides HTTP responses.

It delivers website resources such as:

- HTML files.
- CSS files.
- JavaScript files.
- Images.
- Videos.
- Other static resources.

It can also forward requests to application servers for dynamic processing.

## 12.2 Functions of a Web Server

1. Accept HTTP/HTTPS requests.
2. Serve static files.
3. Handle client connections.
4. Return HTTP responses.
5. Manage request routing.
6. Support TLS configuration.
7. Generate access and error logs.
8. Support authentication and access control.
9. Perform reverse proxying.
10. Support caching and other performance features.

## 12.3 Types of Web Content

**Static Content**

Content delivered largely as stored, without generating a new page for each request.

Examples:

- HTML files.
- CSS files.
- Images.
- JavaScript files.

**Dynamic Content**

Content generated or customized when a request is processed.

Examples:

- User dashboard.
- Shopping cart.
- Personalized profile.
- Banking transaction history.

## 12.4 Web Server vs Application Server

| Web Server | Application Server |
|---|---|
| Handles HTTP requests and responses | Executes application/business logic |
| Commonly serves static files | Commonly generates dynamic responses |
| Can forward requests | Processes application operations |
| Example: Apache HTTP Server | Example: Node.js application |
| Focuses on web delivery | Focuses on application processing |

**Important:** Modern web servers can also perform reverse proxying and other functions. The distinction is logical, not always a strict separation of software products.

---

# 13. IIS – Internet Information Services

## 13.1 What is IIS?

IIS stands for **Internet Information Services**.

IIS is a web server software developed by Microsoft for Windows environments.

It is used to host websites, web applications and web services.

## 13.2 Features of IIS

1. Developed by Microsoft.
2. Runs on Windows Server and supported Windows editions.
3. Supports HTTP and HTTPS.
4. Supports ASP.NET applications.
5. Provides website and application management.
6. Supports authentication and authorization.
7. Provides logging and monitoring.
8. Supports application pools.
9. Provides security and configuration features.

## 13.3 What is an IIS Application Pool?

An application pool is a mechanism in IIS used to isolate web applications or groups of applications into separate worker-process environments.

Advantages:

- Application isolation.
- Better reliability.
- Independent application configuration.
- Control over worker processes.

## 13.4 Uses of IIS

- Hosting ASP.NET applications.
- Hosting enterprise websites.
- Hosting web APIs.
- Deploying Windows-based web applications.

---

# 14. Apache HTTP Server

## 14.1 What is Apache?

Apache HTTP Server is an open-source, cross-platform web server developed and maintained by the Apache Software Foundation.

It is commonly known as Apache or httpd.

It is used to host websites and serve web content over HTTP and HTTPS.

## 14.2 Features of Apache

1. Open-source.
2. Cross-platform.
3. Supports HTTP and HTTPS.
4. Modular architecture.
5. Supports virtual hosting.
6. Provides access logging.
7. Supports URL rewriting.
8. Supports reverse proxy functionality.
9. Provides configurable access control.

## 14.3 What is Virtual Hosting?

Virtual hosting allows a single Apache server to host multiple websites.

Example:

```text
One Apache Server
       |
  -------------
  |     |     |
  v     v     v
Site A Site B Site C
```

Each website can have its own domain name and configuration.

## 14.4 Common Apache Modules

| Module | Purpose |
|---|---|
| mod_rewrite | URL rewriting |
| mod_ssl | TLS/SSL support |
| mod_proxy | Proxy functionality |
| mod_headers | Managing HTTP headers |
| mod_deflate | Compression |
| mod_auth_basic | Basic authentication |

## 14.5 Uses of Apache

- Hosting websites.
- Hosting PHP applications.
- Serving static content.
- Acting as a reverse proxy.
- Hosting multiple domains.

---

# 15. IIS vs Apache

| Feature | IIS | Apache |
|---|---|---|
| Developer | Microsoft | Apache Software Foundation |
| Source Model | Proprietary | Open-source |
| Main Environment | Windows | Cross-platform |
| Configuration | IIS Manager and configuration files | Configuration files |
| ASP.NET Integration | Strong native integration | Possible through suitable hosting setups |
| Virtual Hosting | Supported | Supported |
| TLS/HTTPS | Supported | Supported |
| Logging | Supported | Supported |

---

# 16. Important Ports in Web Communication

A port identifies a communication endpoint on a device.

Common ports:

| Port | Protocol / Service |
|---|---|
| 20 | FTP data, traditional active mode |
| 21 | FTP control |
| 22 | SSH / SFTP |
| 25 | SMTP |
| 53 | DNS |
| 80 | HTTP |
| 110 | POP3 |
| 143 | IMAP |
| 443 | HTTPS |
| 3306 | MySQL |
| 5432 | PostgreSQL |

**Important:** A port number is associated with a transport-layer endpoint. These are conventional default ports; services can be configured to use other ports.

---

# 17. Complete Working Example: Opening a Website

Consider opening:

`https://www.amazon.in`

### Step 1: URL Entry

The user enters the URL in the browser.

### Step 2: DNS Resolution

The browser obtains the destination IP address through DNS resolution.

### Step 3: Network Connection

The browser establishes the necessary connection to the destination.

### Step 4: TLS Handshake

Because the URL uses HTTPS, the browser and server establish a secure TLS connection.

### Step 5: HTTP Request

The browser sends a request such as:

```http
GET / HTTP/1.1
Host: www.amazon.in
```

### Step 6: Server Processing

The web server receives the request and serves the resource or forwards it to the application.

### Step 7: Database Communication

For dynamic content, application logic may retrieve product and user information from a database.

### Step 8: HTTP Response

The server sends a response containing HTML or other requested data.

### Step 9: Browser Rendering

The browser processes HTML, CSS and JavaScript and displays the webpage.

---

# 18. Practical Lab and Self-Learning Activities

These exercises will help you understand Session 1 practically.

## Practical 1: Find Your IP Configuration

Command:

```bash
ipconfig
```

Learn:

- IPv4 Address.
- Subnet Mask.
- Default Gateway.
- DNS Server.

## Practical 2: Find a Website IP Address

Command:

```bash
nslookup google.com
```

Learn:

- DNS lookup.
- DNS server response.
- Domain-to-IP resolution.

## Practical 3: Check Network Connectivity

Command:

```bash
ping google.com
```

Learn:

- Network connectivity.
- Round-trip time.
- Packet loss.

Note: Some servers block ICMP echo requests, so a failed ping does not always mean the website is unavailable.

## Practical 4: Inspect HTTP Headers

Command:

```bash
curl -I https://www.google.com
```

Learn:

- HTTP response status.
- Response headers.
- Server response metadata.

## Practical 5: Inspect HTTP Requests in Chrome

1. Open Google Chrome.
2. Press F12.
3. Select the Network tab.
4. Open a website.
5. Select any request.
6. Inspect the following:

   - Request URL.
   - Request Method.
   - Status Code.
   - Request Headers.
   - Response Headers.
   - Response Payload.
   - Timing.

## Practical 6: Explore HTTPS Certificates

1. Open a website using HTTPS.
2. Click the site information icon near the address bar.
3. Open connection security information.
4. Inspect the certificate details.

## Practical 7: Test HTTP Methods Using Postman

Try these methods using a test API such as:

`https://jsonplaceholder.typicode.com`

| Method | Example Endpoint |
|---|---|
| GET | /posts |
| GET | /posts/1 |
| POST | /posts |
| PUT | /posts/1 |
| PATCH | /posts/1 |
| DELETE | /posts/1 |

Note: JSONPlaceholder is a testing API. Its write operations are simulated and do not permanently modify a real database.

---

# 19. Important CCEE and Interview Questions

## Basic Questions

**Q1. What is the Internet?**

The Internet is a worldwide network of interconnected computer networks that communicate using standard protocols.

**Q2. What is WWW?**

WWW is a collection of interconnected web resources accessed through the Internet.

**Q3. Who invented the World Wide Web?**

Tim Berners-Lee.

**Q4. What is ARPANET?**

ARPANET was an early packet-switching network and an important predecessor of the Internet.

**Q5. What is a protocol?**

A protocol is a set of rules governing communication between devices.

**Q6. What is TCP?**

TCP is a connection-oriented transport protocol that provides reliable and ordered data transmission.

**Q7. What is UDP?**

UDP is a connectionless transport protocol that provides low-overhead data transmission without delivery guarantees.

**Q8. What is an IP address?**

An IP address identifies a network interface for communication over an IP network.

**Q9. What is DNS?**

DNS is a distributed naming system that resolves domain names into information such as IP addresses.

**Q10. What is HTTP?**

HTTP is an application-layer protocol used for communication between web clients and servers.

## Intermediate Questions

**Q11. What is the difference between HTTP and HTTPS?**

HTTPS protects HTTP communication using TLS.

**Q12. Why is HTTP called stateless?**

Because HTTP does not automatically retain application session information between requests.

**Q13. What is a session?**

A session maintains user-specific application state across multiple requests.

**Q14. What is a cookie?**

A cookie is a small piece of data stored by a browser and sent with matching requests.

**Q15. What is a web server?**

A web server accepts HTTP requests and returns HTTP responses.

**Q16. What is the difference between GET and POST?**

GET is used to retrieve information, while POST submits information to a server.

**Q17. What is the difference between PUT and PATCH?**

PUT creates or replaces a resource, while PATCH partially modifies it.

**Q18. What is the difference between 401 and 403?**

401 indicates an authentication problem; 403 indicates that access is forbidden.

**Q19. What is the difference between 404 and 500?**

404 indicates a missing resource; 500 indicates an internal server error.

**Q20. What is TLS?**

TLS is a cryptographic protocol that secures communication over a network.

## Advanced Questions

**Q21. Explain the TCP three-way handshake.**

SYN, SYN-ACK and ACK are exchanged to establish a TCP connection.

**Q22. Explain DNS resolution.**

A DNS resolver obtains DNS information through caches and, when necessary, queries root, TLD and authoritative name servers.

**Q23. Explain the HTTP request-response cycle.**

A client sends an HTTP request, the server processes it and returns an HTTP response.

**Q24. Explain three-tier architecture.**

It divides an application into presentation, business logic and data layers.

**Q25. What is the difference between a web server and an application server?**

A web server handles web communication and resource delivery, whereas an application server executes business logic.

**Q26. What is an application pool in IIS?**

It provides an isolated worker-process environment for hosting applications.

**Q27. What is virtual hosting in Apache?**

It allows multiple websites to be hosted on a single Apache server.

**Q28. Why is DNS caching used?**

To reduce repeated DNS queries and improve name-resolution performance.

**Q29. What is the difference between IPv4 and IPv6?**

IPv4 uses 32-bit addresses, while IPv6 uses 128-bit addresses.

**Q30. Does HTTPS use a different set of HTTP methods?**

No. HTTPS uses the same HTTP methods, but communication is protected by TLS.

---

# 20. CCEE Practice MCQs

### Q1. Who invented the World Wide Web?

A. Vint Cerf  
B. Tim Berners-Lee  
C. Bill Gates  
D. Dennis Ritchie

**Answer: B – Tim Berners-Lee**

### Q2. Which protocol provides reliable data transmission?

A. UDP  
B. IP  
C. TCP  
D. DNS

**Answer: C – TCP**

### Q3. How many bits are used by IPv4?

A. 16  
B. 32  
C. 64  
D. 128

**Answer: B – 32 bits**

### Q4. What is the full form of DNS?

A. Domain Network System  
B. Data Name Service  
C. Domain Name System  
D. Digital Network Service

**Answer: C – Domain Name System**

### Q5. Which protocol is used to send emails?

A. POP3  
B. SMTP  
C. IMAP  
D. FTP

**Answer: B – SMTP**

### Q6. Which HTTP method retrieves data?

A. POST  
B. DELETE  
C. GET  
D. PATCH

**Answer: C – GET**

### Q7. Which status code represents successful creation?

A. 200  
B. 201  
C. 301  
D. 404

**Answer: B – 201**

### Q8. Which status code represents Not Found?

A. 400  
B. 401  
C. 403  
D. 404

**Answer: D – 404**

### Q9. HTTP is a ______ protocol.

A. Stateful  
B. Stateless  
C. Connectionless transport  
D. Routing

**Answer: B – Stateless**

### Q10. Which protocol secures HTTPS communication?

A. FTP  
B. UDP  
C. TLS  
D. POP3

**Answer: C – TLS**

### Q11. What is the default port for HTTP?

A. 21  
B. 25  
C. 80  
D. 443

**Answer: C – 80**

### Q12. What is the default port for HTTPS?

A. 53  
B. 80  
C. 110  
D. 443

**Answer: D – 443**

### Q13. Which DNS record maps a name to an IPv4 address?

A. MX  
B. AAAA  
C. A  
D. CNAME

**Answer: C – A**

### Q14. Which server is developed by Microsoft?

A. Apache  
B. IIS  
C. Nginx  
D. Tomcat

**Answer: B – IIS**

### Q15. Which of the following is an open-source web server?

A. IIS  
B. Apache HTTP Server  
C. Microsoft SQL Server  
D. Windows Server

**Answer: B – Apache HTTP Server**

### Q16. Which HTTP method partially updates a resource?

A. GET  
B. POST  
C. PUT  
D. PATCH

**Answer: D – PATCH**

### Q17. Which HTTP status code indicates an internal server error?

A. 301  
B. 400  
C. 404  
D. 500

**Answer: D – 500**

### Q18. Which protocol is commonly used for domain name resolution?

A. FTP  
B. DNS  
C. SMTP  
D. HTTP

**Answer: B – DNS**

### Q19. Which component stores application data?

A. Browser  
B. Database Server  
C. DNS Resolver  
D. Client

**Answer: B – Database Server**

### Q20. Which architecture contains Presentation, Business Logic and Data layers?

A. Two-tier  
B. Three-tier  
C. Peer-to-peer  
D. Single-tier

**Answer: B – Three-tier**

---

# 21. Quick Revision Sheet

| Concept | Remember |
|---|---|
| Internet | Network of networks |
| WWW | Interconnected web resources |
| ARPANET | Early packet-switching network |
| Protocol | Communication rules |
| TCP | Reliable, connection-oriented |
| UDP | Connectionless, low overhead |
| IPv4 | 32 bits |
| IPv6 | 128 bits |
| DNS | Domain name resolution |
| HTTP | Web communication protocol |
| HTTPS | HTTP secured using TLS |
| GET | Retrieve data |
| POST | Submit data |
| PUT | Create or replace resource |
| PATCH | Partially update resource |
| DELETE | Delete resource |
| 200 | OK |
| 201 | Created |
| 301 | Moved Permanently |
| 400 | Bad Request |
| 401 | Unauthorized |
| 403 | Forbidden |
| 404 | Not Found |
| 500 | Internal Server Error |
| HTTP | Stateless |
| Cookie | Browser-side data |
| Session | Application state across requests |
| IIS | Microsoft Web Server |
| Apache | Open-source Web Server |
| HTTP Port | 80 |
| HTTPS Port | 443 |
| DNS Port | 53 |

---

# 22. Reference Books and Learning Resources

## Official ACTS Reference Books

**1. Web Development with Node and Express**

Author: Ethan Brown  
Publisher: O'Reilly Media  
Edition: 2014

Relevant for:
- Web architecture.
- HTTP fundamentals.
- Web servers.
- Client-server communication.
- Node.js and Express concepts.

**2. JavaScript: The Definitive Guide**

Author: David Flanagan  
Publisher: O'Reilly Media  
Edition: 7th Edition

Relevant for:
- Web programming fundamentals.
- Browser environment.
- JavaScript-based web applications.
- Client-side programming.

**3. React in Depth**

Author: Morten Barklund  
Publisher: O'Reilly Media  
Edition: 2024

Relevant for:
- Modern frontend architecture.
- React application structure.
- Component-based development.

## Additional Official Learning Resources

- MDN – [How the Web Works](https://developer.mozilla.org/en-US/docs/Learn_web_development/Getting_started/Web_standards/How_the_web_works)
- MDN – [HTTP Overview](https://developer.mozilla.org/en-US/docs/Web/HTTP/Guides/Overview)
- MDN – [HTTP Methods](https://developer.mozilla.org/en-US/docs/Web/HTTP/Reference/Methods)
- MDN – [HTTP Status Codes](https://developer.mozilla.org/en-US/docs/Web/HTTP/Reference/Status)
- Cloudflare – [DNS Explained](https://www.cloudflare.com/learning/dns/what-is-dns/)
- Apache – [Official Documentation](https://httpd.apache.org/docs/)
- Microsoft – [IIS Documentation](https://learn.microsoft.com/en-us/iis/)

---

# 23. Final Learning Checklist

Before moving to Session 2 (HTML), make sure you can:

- [ ] Explain the history and evolution of the Internet.
- [ ] Differentiate between Internet and WWW.
- [ ] Explain packet switching.
- [ ] Explain client-server architecture.
- [ ] Understand TCP, UDP and IP.
- [ ] Differentiate IPv4 and IPv6.
- [ ] Explain domain names and DNS.
- [ ] Draw and explain DNS resolution.
- [ ] Understand HTTP request and response.
- [ ] Explain all important HTTP methods.
- [ ] Remember important HTTP status codes.
- [ ] Explain why HTTP is stateless.
- [ ] Differentiate cookies and sessions.
- [ ] Explain HTTPS, SSL and TLS.
- [ ] Understand web architecture and three-tier architecture.
- [ ] Differentiate web server and application server.
- [ ] Explain IIS and Apache.
- [ ] Perform basic networking commands.
- [ ] Inspect HTTP requests using Chrome Developer Tools.

---

## 🎯 Session 1 Completion Goal

By completing this session, you should understand what happens behind the scenes when you open a website, how the browser communicates with a server, how DNS locates a website, how HTTP transfers information and how web servers deliver web applications.

**Learn → Understand → Practice → Revise → Implement**

⭐ If these notes are useful, consider starring the repository and sharing improvements.

**Happy Learning! 🚀**
