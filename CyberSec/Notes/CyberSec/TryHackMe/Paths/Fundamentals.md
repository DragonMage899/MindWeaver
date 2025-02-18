# Linux fundamentals
## Where is Linux Used?

It's fair to say that Linux is a lot more intimidating to approach than Operating System's (OSs) such as Windows. Both variants have their own advantages and disadvantages. For example, Linux is considerably much more lightweight and you'd be surprised to know that there's a good chance you've used Linux in some form or another every day! Linux powers things such as:

- Websites that you visit
- Car entertainment/control panels
- Point of Sale (PoS) systems such as checkout tills and registers in shops
- Critical infrastructures such as traffic light controllers or industrial sensors

##   

## Flavours of Linux

The name "Linux" is actually an umbrella term for multiple OS's that are based on UNIX (another operating system). Thanks to Linux being open-source, variants of Linux come in all shapes and sizes - suited best for what the system is being used for.

For example, Ubuntu & Debian are some of the more commonplace distributions of Linux because it is so extensible. I.e. you can run Ubuntu as a server (such as websites & web applications) or as a fully-fledged desktop. For this series, we're going to be using Ubuntu.

_Note: Ubuntu Server can run on systems with only 512MB of RAM!_

Similar to how you have different versions Windows (7, 8 and 10), there are many different versions/distributions of Linux.

## Operators![[Pasted image 20250129161149.png]]

# Introductory Networking
## OSI
The OSI (**O**pen **S**ystems **I**nterconnection) Model is a standardised model which we use to demonstrate the theory behind computer networking. In practice, it's actually the more compact TCP/IP model that real-world networking is based off; however the OSI model, in many ways, is easier to get an initial understanding from.

The OSI model consists of seven layers:

![Table showing the OSI layers: Application, Presentation, Session, Transport, Network, Data Link, Physical](https://muirlandoracle.co.uk/wp-content/uploads/2020/02/OSI-Table.png)

There are many mnemonics floating around to help you learn the layers of the OSI model -- search around until you find one that you like.

I personally favour: **A**nxious **P**ale **S**hakespeare **T**reated **N**ervous **D**runks **P**atiently

Let's briefly take a look at each of these in turn:

Layer 7 -- Application:

The application layer of the OSI model essentially provides networking options to programs running on a computer. It works almost exclusively with applications, providing an interface for them to use in order to transmit data. When data is given to the application layer, it is passed down into the presentation layer.  

Layer 6 -- Presentation:

The presentation layer receives data from the application layer. This data tends to be in a format that the application understands, but it's not necessarily in a standardised format that could be understood by the application layer in the _receiving_ computer. The presentation layer translates the data into a standardised format, as well as handling any encryption, compression or other transformations to the data. With this complete, the data is passed down to the session layer.

Layer 5 -- Session:

When the session layer receives the correctly formatted data from the presentation layer, it looks to see if it can set up a connection with the other computer across the network. If it can't then it sends back an error and the process goes no further. If a session _can_ be established then it's the job of the session layer to maintain it, as well as co-operate with the session layer of the remote computer in order to synchronise communications. The session layer is particularly important as the session that it creates is unique to the communication in question. This is what allows you to make multiple requests to different endpoints simultaneously without all the data getting mixed up (think about opening two tabs in a web browser at the same time)! When the session layer has successfully logged a connection between the host and remote computer the data is passed down to Layer 4: the transport Layer.

Layer 4 -- Transport:

The transport layer is a very interesting layer that serves numerous important functions. Its first purpose is to choose the protocol over which the data is to be transmitted. The two most common protocols in the transport layer are TCP (**T**ransmission **C**ontrol **P**rotocol) and UDP (**U**ser **D**atagram **P**rotocol); with TCP the transmission is _connection-based_ which means that a connection between the computers is established and maintained for the duration of the request. This allows for a reliable transmission, as the connection can be used to ensure that the packets _all_ get to the right place. A TCP connection allows the two computers to remain in constant communication to ensure that the data is sent at an acceptable speed, and that any lost data is re-sent. With UDP, the opposite is true; packets of data are essentially thrown at the receiving computer -- if it can't keep up then that's _its_ problem (this is why a video transmission over something like Skype can be pixelated if the connection is bad). What this means is that TCP would usually be chosen for situations where accuracy is favoured over speed (e.g. file transfer, or loading a webpage), and UDP would be used in situations where speed is more important (e.g. video streaming).

With a protocol selected, the transport layer then divides the transmission up into bite-sized pieces (over TCP these are called _segments_, over UDP they're called _datagrams_), which makes it easier to transmit the message successfully. 

Layer 3 -- Network:

The network layer is responsible for locating the destination of your request. For example, the Internet is a huge network; when you want to request information from a webpage, it's the network layer that takes the IP address for the page and figures out the best route to take. At this stage we're working with what is referred to as _Logical_ addressing (i.e. IP addresses) which are still software controlled. Logical addresses are used to provide order to networks, categorising them and allowing us to properly sort them. Currently the most common form of logical addressing is the IPV4 format, which you'll likely already be familiar with (i.e 192.168.1.1 is a common address for a home router).

Layer 2 -- Data Link:

The data link layer focuses on the _physical_ addressing of the transmission. It receives a packet from the network layer (that includes the IP address for the remote computer) and adds in the physical (MAC) address of the receiving endpoint. Inside every network enabled computer is a Network Interface Card (NIC) which comes with a unique MAC (Media Access Control) address to identify it.

MAC addresses are set by the manufacturer and literally burnt into the card; they can't be changed -- although they _can_ be spoofed. When information is sent across a network, it's actually the physical address that is used to identify where exactly to send the information.

Additionally, it's also the job of the data link layer to present the data in a format suitable for transmission.

The data link layer also serves an important function when it receives data, as it checks the received information to make sure that it hasn't been corrupted during transmission, which could well happen when the data is transmitted by layer 1: the physical layer.

Layer 1 -- Physical:

The physical layer is right down to the hardware of the computer. This is where the electrical pulses that make up data transfer over a network are sent and received. It's the job of the physical layer to convert the binary data of the transmission into signals and transmit them across the network, as well as receiving incoming signals and converting them back into binary data.

## Encapsulation
As the data is passed down each layer of the model, more information containing details specific to the layer in question is added on to the start of the transmission. As an example, the header added by the Network Layer would include things like the source and destination IP addresses, and the header added by the Transport Layer would include (amongst other things) information specific to the protocol being used. The data link layer also adds a piece on at the _end_ of the transmission, which is used to verify that the data has not been corrupted on transmission; this also has the added bonus of increased security, as the data can't be intercepted and tampered with without breaking the trailer. This whole process is referred to as _encapsulation;_ the process by which data can be sent from one computer to another.

![Encapsulation process](https://muirlandoracle.co.uk/wp-content/uploads/2020/02/image.jpeg)

Notice that the encapsulated data is given a different name at different steps of the process. In layers 7,6 and 5, the data is simply referred to as data. In the transport layer the encapsulated data is referred to as a segment or a datagram (depending on whether TCP or UDP has been selected as a transmission protocol). At the Network Layer, the data is referred to as a packet. When the packet gets passed down to the Data Link layer it becomes a frame, and by the time it's transmitted across a network the frame has been broken down into bits.

When the message is received by the second computer, it reverses the process -- starting at the physical layer and working up until it reaches the application layer, stripping off the added information as it goes. This is referred to as _de-encapsulation._ As such you can think of the layers of the OSI model as existing inside every computer with network capabilities. Whilst it's not actually as clear cut in practice, computers all follow the same process of encapsulation to send data and de-encapsulation upon receiving it.

The processes of encapsulation and de-encapsulation are very important -- not least because of their practical use, but also because they give us a standardised method for sending data. This means that all transmissions will consistently follow the same methodology, allowing any network enabled device to send a request to any other reachable device and be sure that it will be understood -- regardless of whether they are from the same manufacturer; use the same operating system; or any other factors.

## TCP/IP
The TCP/IP model is, in many ways, very similar to the OSI model. It's a few years older, and serves as the basis for real-world networking. The TCP/IP model consists of four layers: Application, Transport, Internet and Network Interface. Between them, these cover the same range of functions as the seven layers of the OSI Model.

![The layesrs of the TCP/IP model: Application, Transport,Internet, Network Interface](https://muirlandoracle.co.uk/wp-content/uploads/2020/02/image-4.png)

_**Note:** Some recent sources split the TCP/IP model into five layers -- breaking the Network Interface layer into Data Link and Physical layers (as with the OSI model). This is accepted and well-known; however, it is not officially defined (unlike the original four layers which are defined in RFC1122). It's up to you which version you use -- both are generally considered valid._  

You would be justified in asking why we bother with the OSI model if it's not actually used for anything in the real-world. The answer to that question is quite simply that the OSI model (due to being less condensed and more rigid than the TCP/IP model) tends to be easier for learning the initial theory of networking.  

The two models match up something like this:

![Comparison between the TCP/IP and OSI models.](https://muirlandoracle.co.uk/wp-content/uploads/2020/02/image-3.png)

The processes of encapsulation and de-encapsulation work in exactly the same way with the TCP/IP model as they do with the OSI model. At each layer of the TCP/IP model a header is added during encapsulation, and removed during de-encapsulation.

---

Now let's get down to the practical side of things.

A layered model is great as a visual aid -- it shows us the general process of how data can be encapsulated and sent across a network, but how does it actually happen?

When we talk about TCP/IP, it's all well and good to think about a table with four layers in it, but we're actually talking about a suite of protocols -- sets of rules that define how an action is to be carried out. TCP/IP takes its name from the two most important of these: the **T**ransmission **C**ontrol **P**rotocol (which we touched upon earlier in the OSI model) that controls the flow of data between two endpoints, and the **I**nternet **P**rotocol, which controls how packets are addressed and sent. There are many more protocols that make up the TCP/IP suite; we will cover some of these in later tasks. For now though, let's talk about TCP.

As mentioned earlier, TCP is a _connection-based_ protocol. In other words, before you send any data via TCP, you must first form a stable connection between the two computers. The process of forming this connection is called the _three-way handshake_.

When you attempt to make a connection, your computer first sends a special request to the remote server indicating that it wants to initialise a connection. This request contains something called a _SYN_ (short for _synchronise_) bit, which essentially makes first contact in starting the connection process. The server will then respond with a packet containing the SYN bit, as well as another "acknowledgement" bit, called _ACK_. Finally, your computer will send a packet that contains the ACK bit by itself, confirming that the connection has been setup successfully. With the three-way handshake successfully completed, data can be reliably transmitted between the two computers. Any data that is lost or corrupted on transmission is re-sent, thus leading to a connection which appears to be lossless.

![The three way handshake](https://muirlandoracle.co.uk/wp-content/uploads/2020/03/image-2.png)

  

![Frank Syn-acktra -- humour value only](https://muirlandoracle.co.uk/wp-content/uploads/2020/02/syn-acktra.jpeg)

_(Credit Kieran Smith, Abertay University)_

We're not going to go into exactly _how_ this works on a step-to-step level -- not in this room at any rate. It is sufficient to know that the three-way handshake must be carried out before a connection can be established using TCP.

---

**History:**

It's important to understand exactly _why_ the TCP/IP and OSI models were originally created. To begin with there was no standardisation -- different manufacturers followed their own methodologies, and consequently systems made by different manufacturers were completely incompatible when it came to networking. The TCP/IP model was introduced by the American DoD in 1982 to provide a standard -- something for all of the different manufacturers to follow. This sorted out the inconsistency problems. Later the OSI model was also introduced by the International Organisation for Standardisation ([ISO](https://www.iso.org/home.html)); however, it's mainly used as a more comprehensive guide for learning, as the TCP/IP model is still the standard upon which modern networking is based.

## Ping
The ping command is used when we want to test whether a connection to a remote resource is possible. Usually this will be a website on the internet, but it could also be for a computer on your home network if you want to check if it's configured correctly. Ping works using the ICMP protocol, which is one of the slightly less well-known TCP/IP protocols that were mentioned earlier. The ICMP protocol works on the Network layer of the OSI Model, and thus the Internet layer of the TCP/IP model. The basic syntax for ping is `ping <target>`. In this example we are using ping to test whether a network connection to Google is possible:

![Pinging Google -- it is possible](https://muirlandoracle.co.uk/wp-content/uploads/2020/03/image-14.png)

Notice that the ping command actually returned the IP address for the Google server that it connected to, rather than the URL that was requested. This is a handy secondary application for ping, as it can be used to determine the IP address of the server hosting a website. One of the big advantages of ping is that it's pretty much ubiquitous to any network enabled device. All operating systems support it out of the box, and even most embedded devices can use ping!  

Have a go at the following questions. Any questions about syntax can be answered using the man page for ping (`man ping` on Linux).

## Traceroute
The logical follow-up to the ping command is 'traceroute'. Traceroute can be used to map the path your request takes as it heads to the target machine.  
  
The internet is made up of many, many different servers and end-points, all networked up to each other. This means that, in order to get to the content you actually want, you first need to go through a bunch of other servers. Traceroute allows you to see each of these connections -- it allows you to see every intermediate step between your computer and the resource that you requested. The basic syntax for traceroute on Linux is this: `traceroute <destination>`

By default, the Windows traceroute utility (`tracert`) operates using the same ICMP protocol that ping utilises, and the Unix equivalent operates over UDP. This can be altered with switches in both instances.

![Performing a traceroute to Google.com](https://muirlandoracle.co.uk/wp-content/uploads/2020/03/image-15.png)

You can see that it took 13 hops to get from my router (`_gateway`) to the Google server at 216.58.205.46

Now it's your turn. As with before, all questions about switches can be answered with the man page for traceroute  
(`man traceroute`).

## Whois
Domain Names -- the unsung saviours of the internet.

Can you imagine how it would feel to remember the IP address of every website you want to visit? Horrible thought.

Fortunately, we've got domains.

We'll talk a little bit more about how this works in the next task, but for now suffice to know that a domain translates into an IP address so that we don't need to remember it (e.g. you can type tryhackme.com, rather than the TryHackMe IP address). Domains are leased out by companies called Domain Registrars. If you want a domain, you go and register with a registrar, then lease the domain for a certain length of time. 

Enter Whois.

Whois essentially allows you to query who a domain name is registered to. In Europe personal details are redacted; however, elsewhere you can potentially get a great deal of information from a whois search.

For Free Users using the AttackBox, there is a [web version](https://www.whois.com/whois/) of the whois tool.

_(Note: You may need to install whois before using it. On Debian based systems this can be done with_ `sudo apt update && sudo apt-get install whois`_)_

Whois lookups are very easy to perform. Just use `whois <domain>` to get a list of available information about the domain registration:

![Performing a whois lookup on bbc.co.uk](https://muirlandoracle.co.uk/wp-content/uploads/2020/03/image-16.png)

This is comparatively a very small amount of information as can often be found. Notice that we've got the domain name, the company that registered the domain, the last renewal, and when it's next due, and a bunch of information about nameservers

## DIG
We talked about domains in the previous task -- now lets talk about how they work.

Ever wondered how a URL gets converted into an IP address that your computer can understand? The answer is a TCP/IP protocol called DNS (**D**omain **N**ame **S**ystem).

At the most basic level, DNS allows us to ask a special server to give us the IP address of the website we're trying to access. For example, if we made a request to www.google.com, our computer would first send a request to a special DNS server (which your computer already knows how to find). The server would then go looking for the IP address for Google and send it back to us. Our computer could then send the request to the IP of the Google server.

---

Let's break this down a bit.

You make a request to a website. The first thing that your computer does is check its local "**_[Hosts](https://www.ionos.co.uk/digitalguide/server/configuration/hosts-file/) File_**" to see if an explicit IP->Domain mapping has been created. This is an older system than DNS and much less commonly used in modern environments; however, it still takes precedence in the search order of most operating systems. If no mapping has been manually created, the computer then checks its local DNS cache to see if it already has an IP address stored for the website; if it does, great. If not, it goes to the next stage of the process.

Assuming the address hasn't already been found, your computer will then send a request to what is known as a _recursive_ DNS server. These will automatically be known to the router on your network. Many Internet Service Providers (ISPs) maintain their own recursive servers, but companies such as Google and OpenDNS also control recursive servers. This is how your computer automatically knows where to send the request for information: details for a recursive DNS server are stored in your router or computer. This server will also maintain a cache of results for popular domains; however, if the website you've requested isn't stored in the cache, the recursive server will pass the request on to a _root name_ server.

Before 2004 there were precisely 13 root name DNS servers in the world. These days there are many more; however, they are still accessible using the same 13 IP addresses assigned to the original servers (balanced so that you get the closest server when you make a request). The root name servers essentially keep track of the DNS servers in the next level down, choosing an appropriate one to redirect your request to. These lower level servers are called _Top-Level_ _Domain_ servers.

Top-Level Domain (TLD) servers are split up into extensions. So, for example, if you were searching for tryhackme**.com** your request would be redirected to a TLD server that handled `.com` domains. If you were searching for bbc**.co.uk** your request would be redirected to a TLD server that handles `.co.uk` domains. As with root name servers, TLD servers keep track of the next level down: _Authoritative name servers_. When a TLD server receives your request for information, the server passes it down to an appropriate Authoritative name server.

Authoritative name servers are used to store DNS records for domains directly. In other words, every domain in the world will have its DNS records stored on an Authoritative name server somewhere or another; they are the source of the information. When your request reaches the authoritative name server for the domain you're querying, it will send the relevant information back to you, allowing your computer to connect to the IP address behind the domain you requested.

---

When you visit a website in your web browser this all happens automatically, but we can also do it manually with a tool called `dig` . Like ping and traceroute, dig should be installed automatically on Linux systems.

Dig allows us to manually query recursive DNS servers of our choice for information about domains:  
`dig <domain> @<dns-server-ip>`

It is a very useful tool for network troubleshooting.

![Performing a DIG DNS lookup on google.com](https://muirlandoracle.co.uk/wp-content/uploads/2020/03/dig-demo.png)

This is a _lot_ of information. We're currently most interested in the `ANSWER` section for this room; however, taking the time to learn what the rest of this means is a very good idea. In summary, that information is telling us that we sent it one query and successfully (i.e. No Errors) received one full answer -- which, as expected, contains the IP address for the domain name that we queried.

Another interesting piece of information that dig gives us is the TTL (**T**ime **T**o **L**ive) of the queried DNS record. As mentioned previously, when your computer queries a domain name, it stores the results in its local cache. The TTL of the record tells your computer when to stop considering the record as being valid -- i.e. when it should request the data again, rather than relying on the cached copy.

The TTL can be found in the second column of the answer section:

![Results demonstrating that the TTL of the DNS record is 157](https://muirlandoracle.co.uk/wp-content/uploads/2020/03/TTL.png)

It's important to remember that TTL (in the context of DNS caching) is measured in _seconds,_ so the record in the example will expire in two minutes and thirty-seven seconds.



# Network services

## SMB
**What is SMB?**

SMB - Server Message Block Protocol - is a client-server communication protocol used for sharing access to files, printers, serial ports and other resources on a network. [[source](https://searchnetworking.techtarget.com/definition/Server-Message-Block-Protocol)]  

Servers make file systems and other resources (printers, named pipes, APIs) available to clients on the network. Client computers may have their own hard disks, but they also want access to the shared file systems and printers on the servers.

The SMB protocol is known as a response-request protocol, meaning that it transmits multiple messages between the client and server to establish a connection. Clients connect to servers using TCP/IP (actually NetBIOS over TCP/IP as specified in RFC1001 and RFC1002), NetBEUI or IPX/SPX.

**How does SMB work?**  

![](https://i.imgur.com/XMnru12.png)

Once they have established a connection, clients can then send commands (SMBs) to the server that allow them to access shares, open files, read and write files, and generally do all the sort of things that you want to do with a file system. However, in the case of SMB, these things are done over the network.

**What runs SMB?**

Microsoft Windows operating systems since Windows 95 have included client and server SMB protocol support. Samba, an open source server that supports the SMB protocol, was released for Unix systems.

## Enumerating SMB

**Enumeration**

Enumeration is the process of gathering information on a target in order to find potential attack vectors and aid in exploitation.

This process is essential for an attack to be successful, as wasting time with exploits that either don't work or can crash the system can be a waste of energy. Enumeration can be used to gather usernames, passwords, network information, hostnames, application data, services, or any other information that may be valuable to an attacker.

**SMB**  

Typically, there are SMB share drives on a server that can be connected to and used to view or transfer files. SMB can often be a great starting point for an attacker looking to discover sensitive information — you'd be surprised what is sometimes included on these shares.  

**Port Scanning**

The first step of enumeration is to conduct a port scan, to find out as much information as you can about the services, applications, structure and operating system of the target machine.  

If you haven't already looked at port scanning, I **recommend** checking out the Nmap room [here](https://tryhackme.com/room/furthernmap).

**Enum4Linux**

Enum4linux is a tool used to enumerate SMB shares on both Windows and Linux systems. It is basically a wrapper around the tools in the Samba package and makes it easy to quickly extract information from the target pertaining to SMB. It's already installed on the AttackBox, however if you need to install it on your own attacking machine, you can do so from the official [github](https://github.com/portcullislabs/enum4linux).

The syntax of Enum4Linux is nice and simple: **"enum4linux [options] ip"**  

**TAG**            **FUNCTION**  

-U             get userlist  
-M             get machine list  
-N             get namelist dump (different from -U and-M)  
-S             get sharelist  
-P             get password policy information  
-G             get group and member list

-a             all of the above (full basic enumeration)

---
SMB (Server Message Block) runs on both **port 445** and **port 139** due to differences in how it operates over network protocols:

### 1. **Port 139 (NetBIOS over TCP/IP)**

- Used in older versions of SMB (SMBv1).
- Requires **NetBIOS** to work.
- Operates over **NetBIOS Session Service**.
- Used when SMB communication happens on a network where direct TCP/IP communication isn’t possible.
- Common in legacy Windows networks (pre-Windows 2000).

### 2. **Port 445 (SMB over TCP/IP)**

- Introduced with **SMBv2 and later**.
- Does **not** require NetBIOS.
- Runs directly over TCP/IP, making it more efficient.
- Used in modern Windows environments.

### **Why Two Ports?**

- **Backward Compatibility:** Older systems and networks relied on NetBIOS (port 139), while modern systems use direct TCP/IP (port 445).
- **Different Transport Mechanisms:** Port 139 encapsulates SMB within NetBIOS, while port 445 allows direct communication.

### **Which Port is Used?**

- If NetBIOS over TCP/IP is enabled, SMB will attempt to use port **139**.
- If NetBIOS is disabled, SMB will use port **445** directly.
- Modern Windows systems primarily use **port 445**.
---


## Telnet

W**hat is Telnet?**

Telnet is an application protocol which allows you, with the use of a telnet client, to connect to and execute commands on a remote machine that's hosting a telnet server.  

The telnet client will establish a connection with the server. The client will then become a virtual terminal- allowing you to interact with the remote host.  

**Replacement**  

Telnet sends all messages in clear text and has no specific security mechanisms. Thus, in many applications and services, Telnet has been replaced by SSH in most implementations.  
   
****How does Telnet work?****

The user connects to the server by using the Telnet protocol, which means entering **"telnet"** into a command prompt. The user then executes commands on the server by using specific Telnet commands in the Telnet prompt. You can connect to a telnet server with the following syntax: **"telnet [ip] [port]"****

### Exploiting telnet 
**Types of Telnet Exploit  
**

Telnet, being a protocol, is in and of itself insecure for the reasons we talked about earlier. It lacks encryption, so sends all communication over plaintext, and for the most part has poor access control. There are CVE's for Telnet client and server systems, however, so when exploiting you can check for those on:

- [https://www.cvedetails.com/](https://www.cvedetails.com/)
- [https://cve.mitre.org/](https://cve.mitre.org/)[](https://cve.mitre.org/)

A CVE, short for Common Vulnerabilities and Exposures, is a list of publicly disclosed computer security flaws. When someone refers to a CVE, they usually mean the CVE ID number assigned to a security flaw.

However, you're far more likely to find a misconfiguration in how telnet has been configured or is operating that will allow you to exploit it.

**Method Breakdown**

So, from our enumeration stage, we know:

    - There is a poorly hidden telnet service running on this machine

    - The service itself is marked "backdoor"

    - We have possible username of "Skidy" implicated

Using this information, let's try accessing this telnet port, and using that as a foothold to get a full reverse shell on the machine!

**Connecting to Telnet**

You can connect to a telnet server with the following syntax:

    **"telnet [ip] [port]"**

We're going to need to keep this in mind as we try and exploit this machine.  
  

**What is a Reverse Shell?**

**![](https://i.imgur.com/EUC7VS6.png)**

A **"shell"** can simply be described as a piece of code or program which can be used to gain code or command execution on a device.

A reverse shell is a type of shell in which the target machine communicates back to the attacking machine.

The attacking machine has a listening port, on which it receives the connection, resulting in code or command execution being achieved.

## FTP
**What is FTP?**

File Transfer Protocol (FTP) is, as the name suggests , a protocol used to allow remote transfer of files over a network. It uses a client-server model to do this, and- as we'll come on to later- relays commands and data in a very efficient way.  

****How does FTP work?****

A typical FTP session operates using two channels:

- a command (sometimes called the control) channel
- a data channel.

As their names imply, the command channel is used for transmitting commands as well as replies to those commands, while the data channel is used for transferring data.

FTP operates using a client-server protocol. The client initiates a connection with the server, the server validates whatever login credentials are provided and then opens the session.

While the session is open, the client may execute FTP commands on the server.  

**Active vs Passive**

The FTP server may support either Active or Passive connections, or both. 

- In an Active FTP connection, the client opens a port and listens. The server is required to actively connect to it. 
- In a Passive FTP connection, the server opens a port and listens (passively) and the client connects to it. 

This separation of command information and data into separate channels is a way of being able to send commands to the server without having to wait for the current data transfer to finish. If both channels were interlinked, you could only enter commands in between data transfers, which wouldn't be efficient for either large file transfers, or slow internet connections.

**More Details:**

You can find more details on the technical function, and implementation of, FTP on the Internet Engineering Task Force website: [https://www.ietf.org/rfc/rfc959.txt](https://www.ietf.org/rfc/rfc959.txt). The IETF is one of a number of standards agencies, who define and regulate internet standards.

### Enumerating ftp
**Lets Get Started**

Before we begin, make sure to deploy the room and give it some time to boot. Please be aware, this can take up to five minutes so be patient!

**![](https://cdn4.iconfinder.com/data/icons/database-and-server-pixel-prefect-set-3/80/network__computer__connection__sharing_-512.png)Enumeration**

By now, I don't think I need to explain any further how enumeration is key when attacking network services and protocols. You should, by now, have enough experience with **nmap** to be able to port scan effectively. If you get stuck using any tool- you can always use **"tool [-h / -help / --help]"** to find out more about it's function and syntax. Equally, man pages are extremely useful for this purpose. They can be reached using **"man [tool]"**.

**Method**

We're going to be exploiting an anonymous FTP login, to see what files we can access- and if they contain any information that might allow us to pop a shell on the system. This is a common pathway in CTF challenges, and mimics a real-life careless implementation of FTP servers.

**Resources**

As we're going to be logging in to an FTP server, we will need to make sure an FTP client is installed on the system. There should be one installed by default on most Linux operating systems, such as Kali or Parrot OS. You can test if there is one by typing "ftp" into the console. If you're brought to a prompt that says: "ftp>", then you have a working FTP client on your system. If not, it's a simple matter of using "sudo apt install ftp" to install one.  

**Alternative Enumeration Methods**

It's worth noting  that some vulnerable versions of in.ftpd and some other FTP server variants return different responses to the "cwd" command for home directories which exist and those that don’t. This can be exploited because you can issue cwd commands before authentication, and if there's a home directory- there is more than likely a user account to go with it. While this bug is found mainly within legacy systems, it's worth knowing about, as a way to exploit FTP.  

This vulnerability is documented at: [https://www.exploit-db.com/exploits/20745](https://www.exploit-db.com/exploits/20745)

### Exploiting ftp
**Types of FTP Exploit**

![](https://webstockreview.net/images/lock-clipart-broken-lock-5.png)Similarly to Telnet, when using FTP both the command and data channels are unencrypted. Any data sent over these channels can be intercepted and read.

With data from FTP being sent in plaintext, if a man-in-the-middle attack took place an attacker could reveal anything sent through this protocol (such as passwords). An article written by [JSCape](https://www.jscape.com/blog/bid/91906/Countering-Packet-Sniffers-Using-Encrypted-FTP) demonstrates and explains this process using ARP-Poisoning to trick a victim into sending sensitive information to an attacker, rather than a legitimate source.

When looking at an FTP server from the position we find ourselves in for this machine, an avenue we can exploit is weak or default password configurations.  

**Method Breakdown**

So, from our enumeration stage, we know:

    - There is an FTP server running on this machine  

    - We have a possible username  

Using this information, let's try and **bruteforce** the password of the FTP Server.

**Hydra**

Hydra is a very fast online password cracking tool, which can perform rapid dictionary attacks against more than 50 Protocols, including Telnet, RDP, SSH, FTP, HTTP, HTTPS, SMB, several databases and much more. Hydra is already installed on the AttackBox, however, if you need it on your own attacking machine, you can find the GitHub repository [here](https://github.com/vanhauser-thc/thc-hydra).  

The syntax for the command we're going to use to find the passwords is this:

**"hydra -t 4 -l dale -P /usr/share/wordlists/rockyou.txt -vV 10.10.10.6 ftp"**

Let's break it down:

SECTION             FUNCTION  
  
hydra                   Runs the hydra tool  
  
-t 4                    Number of parallel connections per target  
  
-l [user]               Points to the user who's account you're trying to compromise  
  
-P [path to dictionary] Points to the file containing the list of possible passwords  
  
-vV                     Sets verbose mode to very verbose, shows the login+pass combination for each attempt  
  
[machine IP]            The IP address of the target machine  
  
ftp / protocol          Sets the protocol

Let's crack some passwords!

## **Further Learning**

There is no checklist of things to learn until you've officially learnt everything you can. There will always be things that surprise us all, especially in the sometimes abstract logical problems of capture the flag challenges. But, as with anything, practice makes perfect. We can all look back on the things we've learnt after completing something challenging and I hope you feel the same about this room.

**Reading**

Here's some things that might be useful to read after completing this room, if it interests you:

- [https://medium.com/@gregIT/exploiting-simple-network-services-in-ctfs-ec8735be5eef](https://medium.com/@gregIT/exploiting-simple-network-services-in-ctfs-ec8735be5eef)
- [https://attack.mitre.org/techniques/T1210/](https://attack.mitre.org/techniques/T1210/)
- [https://www.nextgov.com/cybersecurity/2019/10/nsa-warns-vulnerabilities-multiple-vpn-services/160456/](https://www.nextgov.com/cybersecurity/2019/10/nsa-warns-vulnerabilities-multiple-vpn-services/160456/)

# Network services 2
## NFS
- Network file system

**What is NFS?**

NFS stands for "Network File System" and allows a system to share directories and files with others over a network. By using NFS, users and programs can access files on remote systems almost as if they were local files. It does this by mounting all, or a portion of a file system on a server. The portion of the file system that is mounted can be accessed by clients with whatever privileges are assigned to each file.

**How does NFS work?**

**![Shared File](https://tryhackme-images.s3.amazonaws.com/user-uploads/5ed5961c6276df568891c3ea/room-content/e719d6f95ebdbed97c9c2557f8f5e2c6.png)**

We don't need to understand the technical exchange in too much detail to be able to exploit NFS effectively- however if this is something that interests you, I would recommend this resource: [https://docs.oracle.com/cd/E19683-01/816-4882/6mb2ipq7l/index.html](https://docs.oracle.com/cd/E19683-01/816-4882/6mb2ipq7l/index.html)

First, the client will request to mount a directory from a remote host on a local directory just the same way it can mount a physical device. The mount service will then act to connect to the relevant mount daemon using RPC.

The server checks if the user has permission to mount whatever directory has been requested. It will then return a file handle which uniquely identifies each file and directory that is on the server.

If someone wants to access a file using NFS, an RPC call is placed to NFSD (the NFS daemon) on the server. This call takes parameters such as:

-  The file handle
-  The name of the file to be accessed
-  The user's, user ID
-  The user's group ID  
    

These are used in determining access rights to the specified file. This is what controls user permissions, I.E read and write of files.  

**What runs NFS?**

Using the NFS protocol, you can transfer files between computers running Windows and other non-Windows operating systems, such as Linux, MacOS or UNIX.

A computer running Windows Server can act as an NFS file server for other non-Windows client computers. Likewise, NFS allows a Windows-based computer running Windows Server to access files stored on a non-Windows NFS server.

**More Information:**

Here are some resources that explain the technical implementation, and working of, NFS in more detail than I have covered here.

[https://www.datto.com/blog/what-is-nfs-file-share/](https://www.datto.com/blog/what-is-nfs-file-share/)  

[http://nfs.sourceforge.net/](http://nfs.sourceforge.net/)

[https://wiki.archlinux.org/index.php/NFS](https://wiki.archlinux.org/index.php/NFS)

## Enumerating nfs
**What is Enumeration?**

Enumeration is defined as "a process which establishes an active connection to the target hosts to discover potential attack vectors in the system, and the same can be used for further exploitation of the system." - [Infosec Institute](https://resources.infosecinstitute.com/what-is-enumeration/). It is a critical phase when considering how to enumerate and exploit a remote machine - as the information you will use to inform your attacks will come from this stage

**Requirements**

In order to do a more advanced enumeration of the NFS server, and shares- we're going to need a few tools. The first of which is key to interacting with any NFS share from your local machine: **nfs-common**.

**NFS-Common**

It is important to have this package installed on any machine that uses NFS, either as client or server. It includes programs such as: **l****ockd, statd**, **showmount**, **nfsstat,** **gssd**, **idmapd** and **mount.nfs**. Primarily, we are concerned with "showmount" and "mount.nfs" as these are going to be most useful to us when it comes to extracting information from the NFS share. If you'd like more information about this package, feel free to read: [https://packages.ubuntu.com/jammy/nfs-common](https://packages.ubuntu.com/jammy/nfs-common).

You can install **nfs-common** using "_sudo apt install nfs-common_", it is part of the default repositories for most Linux distributions such as the Kali Remote Machine or AttackBox that is provided to TryHackMe.

**Port Scanning**

Port scanning has been covered many times before, so I'll only cover the basics that you need for this room here. If you'd like to learn more about **nmap** in more detail please have a look at the [nmap](https://tryhackme.com/room/furthernmap) room.

The first step of enumeration is to conduct a port scan, to find out as much information as you can about the services, open ports and operating system of the target machine. You can go as in-depth as you like on this, however, I suggest using **nmap** with the **-A** and **-p-** tags.

**Mounting NFS shares**

Your client’s system needs a directory where all the content shared by the host server in the export folder can be accessed. You can create  
this folder anywhere on your system. Once you've created this mount point, you can use the "mount" command to connect the NFS share to the mount point on your machine like so:

**sudo mount -t nfs IP:share /tmp/mount/ -nolock**

Let's break this down

|||
|---|---|
|**Tag**|**Function**|
|sudo|Run as root|
|mount|Execute the mount command|
|-t nfs|Type of device to mount, then specifying that it's NFS|
|IP:share|The IP Address of the NFS server, and the name of the share we wish to mount|
|-nolock|Specifies not to use NLM locking|

  
  
Now we understand our tools, let's get started!
## Exploiting NFS
**We're done, right?**  

Not quite, if you have a low privilege shell on any machine and you found that a machine has an NFS share you might be able to use that to escalate privileges, depending on how it is configured.

**What is root_squash?**

By default, on NFS shares- Root Squashing is enabled, and prevents anyone connecting to the NFS share from having root access to the NFS volume. Remote root users are assigned a user “nfsnobody” when connected, which has the least local privileges. Not what we want. However, if this is turned off, it can allow the creation of SUID bit files, allowing a remote user root access to the connected system.

**SUID**

So, what are files with the SUID bit set? Essentially, this means that the file or files can be run with the permissions of the file(s) owner/group. In this case, as the super-user. We can leverage this to get a shell with these privileges!

**Method**

This sounds complicated, but really- provided you're familiar with how SUID files work, it's fairly easy to understand. We're able to upload files to the NFS share, and control the permissions of these files. We can set the permissions of whatever we upload, in this case a bash shell executable. We can then log in through SSH, as we did in the previous task- and execute this executable to gain a root shell!

**The Executable**

Due to compatibility reasons,  we will obtain the bash executable directly from the target machine.  
With the key obtained in the previous task, we can use SCP with the command `scp -i key_name username@10.10.138.223:/bin/bash ~/Downloads/bash` to download it onto our attacking machine.

Another method to overcome compatibility issues is to obtain a standard Ubuntu Server 18.04 bash executable, the same as the server's- as we know from our nmap scan. You can download it [here](https://github.com/TheRealPoloMints/Blog/blob/master/Security%20Challenge%20Walkthroughs/Networks%202/bash). If you want to download it via the command line, be careful not to download the github page instead of the raw script. You can use `wget https://github.com/polo-sec/writing/raw/master/Security%20Challenge%20Walkthroughs/Networks%202/bash`. Note that this method requires an internet connection, so you won't be able to download it when using a free AttackBox.

**Mapped Out Pathway:**

If this is still hard to follow, here's a step by step of the actions we're taking, and how they all tie together to allow us to gain a root shell:  
  

    NFS Access ->

        Gain Low Privilege Shell ->

            Upload Bash Executable to the NFS share ->

                Set SUID Permissions Through NFS Due To Misconfigured Root Squash ->

                    Login through SSH ->

                        Execute SUID Bit Bash Executable ->

                            ROOT ACCESS

Lets do this!


## SMTP
**What is SMTP?**

SMTP stands for "Simple Mail Transfer Protocol". It is utilised to handle the sending of emails. In order to support email services, a protocol pair is required, comprising of SMTP and POP/IMAP. Together they allow the user to send outgoing mail and retrieve incoming mail, respectively.

The SMTP server performs three basic functions:

-  It verifies who is sending emails through the SMTP server.
-  It sends the outgoing mail
-  If the outgoing mail can't be delivered it sends the message back to the sender

Most people will have encountered SMTP when configuring a new email address on some third-party email clients, such as Thunderbird; as when you configure a new email client, you will need to configure the SMTP server configuration in order to send outgoing emails.

**POP and IMAP**

POP, or "Post Office Protocol" and IMAP, "Internet Message Access Protocol" are both email protocols who are responsible for the transfer of email between a client and a mail server. The main differences is in POP's more simplistic approach of downloading the inbox from the mail server, to the client. Where IMAP will synchronise the current inbox, with new mail on the server, downloading anything new. This means that changes to the inbox made on one computer, over IMAP, will persist if you then synchronise the inbox from another computer. The POP/IMAP server is responsible for fulfiling this process.  

****How does SMTP work?****

Email delivery functions much the same as the physical mail delivery system. The user will supply the email (a letter) and a service (the postal delivery service), and through a series of steps- will deliver it to the recipients inbox (postbox). The role of the SMTP server in this service, is to act as the sorting office, the email (letter) is picked up and sent to this server, which then directs it to the recipient.

We can map the journey of an email from your computer to the recipient’s like this:

![](https://github.com/TheRealPoloMints/Blog/blob/master/Security%20Challenge%20Walkthroughs/Networks%202/untitled.png?raw=true)

1. The mail user agent, which is either your email client or an external program. connects to the SMTP server of your domain, e.g. smtp.google.com. This initiates the SMTP handshake. This connection works over the SMTP port- which is usually 25. Once these connections have been made and validated, the SMTP session starts.  

2. The process of sending mail can now begin. The client first submits the sender, and recipient's email address- the body of the email and any attachments, to the server.  

3. The SMTP server then checks whether the domain name of the recipient and the sender is the same.

4. The SMTP server of the sender will make a connection to the recipient's SMTP server before relaying the email. If the recipient's server can't be accessed, or is not available- the Email gets put into an SMTP queue.  

5. Then, the recipient's SMTP server will verify the incoming email. It does this by checking if the domain and user name have been recognised. The server will then forward the email to the POP or IMAP server, as shown in the diagram above.  

6. The E-Mail will then show up in the recipient's inbox.

This is a very simplified version of the process, and there are a lot of sub-protocols, communications and details that haven't been included. If you're looking to learn more about this topic, this is a really friendly to read breakdown of the finer technical details- I actually used it to write this breakdown:

[https://computer.howstuffworks.com/e-mail-messaging/email3.htm](https://computer.howstuffworks.com/e-mail-messaging/email3.htm)

******What runs SMTP?******

SMTP Server software is readily available on Windows server platforms, with many other variants of SMTP being available to run on Linux.  

**More Information:**

Here is a resource that explain the technical implementation, and working of, SMTP in more detail than I have covered here.

[https://www.afternerd.com/blog/smtp/](https://www.afternerd.com/blog/smtp/)