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