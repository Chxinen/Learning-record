# 2Application Layer

## 2.1Principles of Network Application Architectures

### 2.1.1Network Application Architectures

#### client-server architecture

##### server: 

always-on host responds by sending the requested object to client host

##### clients: 

sent request for an object

do not directly communicate

##### IP address

server has it

fix,well-known

Because the server is always on, a client can always contact the server by **sending a packet** to IP address.

##### data centre

to  keep up with all request from clients

host a large number of hosts

often used to create a powerful virtual server

#### peer-to-peer architecture

direct communication between pairs of intermittently connected hosts => peers

self-scalability:  although each peer generates workload by requesting files, each peer also adds service capacity to the system by distributing files to other peers.

cost effective: do not require server infrastructure and server bandwidth

face challenges of security, performance and reliability

### 2.1.2Processes Communicating

how processes running on different hosts (with potentially different operating systems) communicate? =>  exchange messages across the computer network

#### Client and Server Processes

##### client process

the process that initiates the communication

browser

peer that is downloading

##### server process

the process that waits to be contacted 

Web server

peer that is uploading

#### The Interface Between the Process and the Computer Network

socket: a software interface 

​			is also referred  to as the Application Programming Interface (API)

analogous: 

process=>house

socket=>door

#### Addressing Processes

the address of the host

an identifier that specifies the receiving process in the destination host

IP address: 32-bit

##### port number: 

identification of the receiving process (more specifically, the receiving socket) running in the host.

### 2.1.3Transport Services Available to Applications

###### Reliable Data Transfer

correct

complete

###### Throughput

###### Timing

###### Security

### 2.1.4Transport Services Provided by the Internet

##### TCP Services

Connection-oriented service :full-duplex

Reliable data transfer service: without error, proper order

includes a congestion-control mechanism

TLS :an enhancement of TCP, with the enhancements being implemented in the application layer to encrypts and decrypts data

##### UDP Services

connectionless

no handshaking before the two processes start

unreliable data transfer service

does not include a congestion-control mechanism

##### Services Not Provided by Internet Transport Protocols

### 2.1.5Application-Layer Protocols

types

syntax

semantics

rules

### 2.1.6Network Applications Covered in This Book

Web

E-mail

DNS

P2P

## 2.2The Web and HTTP

![1682599430659](Computer%20Networks.assets\1682599430659.png)

### 2.2.1Overview of HTTP

HyperText Transfer Protocol

##### Web page

an HTML file, a JPEG image, a Javascrpt file, a CCS style sheet file, or a video clip—that is addressable by a single URL.

###### ?? 在浏览一个网页时，用户发送请求=>client/browser，网站接受请求=>server，网页返回数据时仍为server

##### stateless protocol

don't save the clients' information

### 2.2.2Non-Persistent and Persistent Connections

#### HTTP with Non-Persistent Connections

drawback:

1.a significant burden(TCP buffers must be allocated and TCP variables must be kept in both
the client and server)

2.two RTTs



client initiates a TCP connection,there will be a socket

client send request message via its socket

sever receives, retrieves , encapsulates the object in HTTP response message and sends response message to client

sever tells TCP to close connection

client receives message. connection terminates

##### round-trip time(RTT)

includes

packet-propagation delays, 

packet-queuing delays in intermediate routers and switches,

packet-processing delays.

##### three-way handshake

when: the browser initiate a TCP connection

how:

1.the client sends a small TCP segment to the server, 

2.the server acknowledges and responds with a small TCP segment,

3.the client acknowledges back to the server.

the client sends a small TCP segment to the server, 

the server acknowledges and responds with a small TCP segment, 

the client acknowledges back to the server.

![1682069130768](Computer%20Networks.assets/1682069130768-1682689042375.png)

###### if there are more handshake, it will cost more RTT?

#### HTTP with Persistent Connections

the TCP connection open after sending a response

Subsequent requests and responses between the same client and server can be sent over the same connection.

### 2.2.3HTTP Message Format

#### HTTP Request Message

![1682074864507](Computer%20Networks.assets/1682074864507-1682689040382.png)

**request line**: 

The first line of an HTTP request message

three fields: 

###### the method field:

can take on several different values, including GET, POST, HEAD, PUT, and DELETE

the URL field

the HTTP version field

**header lines**:

 the subsequent lines



![1682075761470](Computer%20Networks.assets/1682075761470-1682689037040.png)

##### entity body:

GET: empty

POST: the entity body contains what the user entered into the form fields

An HTTP client often uses the POST method when the user fills out a form

a request generated with a form does not necessarily have to use the POST method. Instead, HTML forms often use the GET method and include the inputted data (in the form fields) in the requested URL.

![1682076684404](Computer%20Networks.assets\1682076684404.png)

#### HTTP Response Message

![1682076902554](Computer%20Networks.assets\1682076902554.png)

![1682335785611](Computer%20Networks.assets/1682335785611-1682689034495.png)

### 2.2.4User-Server Interaction: Cookies

![1682336315706](Computer%20Networks.assets/1682336315706-1682689032562.png)

### 2.2.5 Web Caching

A Web cache—also called a proxy server—is a network entity that satisfies HTTP requests on the behalf of an origin Web server.

#### The Conditional GET

allows a cache to verify that its objects are up to date

### 2.2.6 HTTP/2

HTTP/2 changes how the data is formatted and transported between the client and server.

###### what is the difference between http/1.1 and http/2?

 binary framing layer ( a part of the application layer in the internet protocol stack ):

 HTTP/1.1:

keeps all requests and responses in plain text format

head-of-line (HOL) blocking 

limits to the number of concurrent TCP connections possible between a client and server, 

HTTP/2:

 uses the binary framing layer to encapsulate all messages in binary format, while still maintaining HTTP semantics, such as verbs, methods, and headers.  

  the binary framing layer encodes requests/responses and cuts them up into smaller packets of information, greatly increasing the flexibility of data transfer. 

#### HTTP/2 Framing

sub-layer=>break down, interleave, reassemble HTTP message

#### Response Message Prioritization and Server Pushing

##### prioritize:

assign a weight to each message

##### server pushing: eliminate the latency

HTML base page indicates the objects that will be needed to fully render the web page

send them to the client before receiving explicit requests for these objects.

#### HTTP/3

HTTP/3 is yet a new HTTP protocol that is designed to operate over QUIC

## 2.3 Electronic Mail in the Internet

![1682600495983](Computer%20Networks.assets\1682600495983.png)

### 2.3.1 SMTP

a push protocol

SMTP( Simple Mail Transfer Protocol ) transfers messages from senders’ mail servers to the recipients’ mail servers.

it restricts the body (not just the headers) of all mail messages to simple **7-bit ASCII.**

it requires binary multimedia data to be encoded to ASCII before being sent over SMTP; 

it requires the corresponding ASCII message to be decoded back to binary after SMTP transport.

the message does not get placed in some intermediate mail server.(just like face-to-face human interaction)

![1682602214782](Computer%20Networks.assets\1682602214782.png)

![1682602181298](Computer%20Networks.assets\1682602181298.png)

###### task:

![1682602412232](Computer%20Networks.assets\1682602412232.png)

### 2.3.2 Mail Message Formats

must have a From: header line and a To: header line;

may include a Subject: header line as well as other optional header lines.

these header lines are different from the SMTP commands, they just the part of the mail message itself.

###### task:

![1682648628976](Computer%20Networks.assets\1682648628976.png)

example:

![1682648642381](Computer%20Networks.assets\1682648642381.png)

### 2.3.3 Mail Access Protocols

![1682650497602](Computer%20Networks.assets\1682650497602.png)

If Bob is using **Web-based e-mail** or a smartphone app (such as Gmail), then the user agent will **use HTTP** to retrieve Bob’s e-mail. This case requires Bob’s mail server to have an HTTP interface as well as an SMTP interface (to communicate with
Alice’s mail server). 

The **alternative method**, typically used with mail clients such as Microsoft Outlook, is to use the **Internet Mail Access Protocol (IMAP)**

###### 也就是说要想随时能收到邮件（无需一直开着local host）第二个server需要一直向agent发送，直至接收？

## 2.4 DNS—The Internet’s Directory Service

DNS(domain name system) task: 

a directory service that translates hostnames to IP addresses

### 2.4.1 Services Provided by DNS

The DNS is

 (1) a distributed database implemented in a hierarchy of DNS servers,
\(2) an application-layer protocol that allows hosts to query the distributed database.

The DNS protocol runs over **UDP** and uses **port 53**.

![1682652093552](Computer%20Networks.assets\1682652093552.png)

###### and the user's host will first search the local host file to see if there have the IP address of the hostname

### 

the desired IP address is often cached in a “nearby” DNS server, which helps to reduce DNS network traffic as well as the average DNS delay.

#### a few other important services

##### Host aliasing

DNS can be invoked by an application to obtain the canonical hostname for a supplied alias hostname as well as the IP address of the host.

##### Mail server aliasing

DNS can be invoked by a mail application to obtain the canonical hostname for a supplied alias hostname as well as the IP address of the host. In fact, the MX record (see below) permits a company’s mail server and Web server to have identical (aliased) hostnames; for example, a company’s Web server and mail server can both be called enterprise.com.

##### Load distribution

DNS is also used to perform load distribution among replicated servers, such as replicated Web servers.

When clients make a DNS query for a name mapped to a
set of addresses, the server responds with the entire set of IP addresses, but **rotates the ordering** of the addresses within each reply. Because a **client typically sends its HTTP request message to the IP address that is listed first in the set**, DNS rotation distributes the traffic among the replicated servers.

is different to CDN

###### reference

The interested reader is referred to these RFCs and the book by Albitz and Liu [Albitz 1993]; see also the retrospective paper [Mockapetris 1988], which provides a nice description of the what and why of DNS, and [Mockapetris 2005].

### 2.4.2 Overview of How DNS Works

