# **Comprehensive Notes for COS332 (Chapters 2 & 3) – Simplified for Essay-Type Questions**

---

## **1. Email Protocols (SMTP, POP3, IMAP)**

### **SMTP (Simple Mail Transfer Protocol)**

- **Purpose**: Transfers emails between servers/clients.
    
- **Ports**:
    
    - **25** (MTA-to-MTA, legacy).
        
    - **587** (Submission port, modern, requires authentication).
        
- **Key Commands**:
    
    - `HELO/EHLO` (greet server).
        
    - `MAIL FROM:` (sender).
        
    - `RCPT TO:` (recipient).
        
    - `DATA` (message body, ends with `.` on a line).
        
- **Transparency Issue**: A lone `.` terminates the email body.
    
- **Security Issues**: No encryption by default (use **SMTPS** on port **465** or **STARTTLS**).
    

### **POP3 (Post Office Protocol v3)**

- **Purpose**: Downloads emails from server → local client (deletes from server by default).
    
- **Ports**: **110** (unencrypted), **995** (SSL/TLS).
    
- **Key Commands**:
    
    - `USER`, `PASS` (login).
        
    - `RETR` (retrieve email).
        
    - `DELE` (mark for deletion).
        
    - `QUIT` (ends session, deletes marked emails).
        
- **Limitations**: No server-side folder management.
    

### **IMAP4 (Internet Message Access Protocol v4)**

- **Purpose**: Manages emails **on the server** (supports folders, flags, and synchronization across devices).
    
- **Ports**: **143** (unencrypted), **993** (SSL/TLS).
    
- **Key Commands**:
    
    - `LOGIN`, `SELECT` (choose mailbox).
        
    - `FETCH` (retrieve parts of an email).
        
    - `STORE` (mark emails, e.g., `\Seen`).
        
- **Advantages**: Better for multiple devices, retains emails on server.
    

---

## **2. DNS (Domain Name System)**

### **Hierarchy & Structure**

- **TLDs**: `.com`, `.za`, `.io` (ccTLD for British Indian Ocean Territory, but used as gTLD).
    
- **Second-Level Domains**: `example.co.za`.
    
- **Subdomains**: `mail.example.com`.
    

### **DNS Record Types**

|Record|Purpose|Example|
|---|---|---|
|**A**|IPv4 address|`example.com A 192.0.2.1`|
|**AAAA**|IPv6 address|`example.com AAAA 2001:db8::1`|
|**MX**|Mail server|`example.com MX 10 mail.example.com`|
|**CNAME**|Alias|`www.example.com CNAME example.com`|
|**NS**|Name server|`example.com NS ns1.example.com`|
|**PTR**|Reverse DNS|`1.2.0.192.in-addr.arpa PTR example.com`|

### **Name Resolution**

- **Iterative**: Server refers client to another server (used by root/TLD servers).
    
- **Recursive**: Server resolves fully (used by ISP DNS servers).
    

### **Tools**

- `nslookup`:
    
    bash
    
    Copy
    
    nslookup -type=MX example.com
    
- `dig`: More detailed DNS queries.
    

---

## **3. Virtual Terminal Protocols (Telnet, SSH)**

### **Telnet**

- **Purpose**: Remote terminal access (**unencrypted**).
    
- **Port**: **23**.
    
- **Security Issues**: Passwords sent in plaintext (insecure).
    
- **Modern Use**: Debugging protocols (e.g., `telnet smtp.example.com 25`).
    

### **SSH (Secure Shell)**

- **Purpose**: Encrypted remote terminal access.
    
- **Port**: **22**.
    
- **Features**:
    
    - **Tunneling** (e.g., `ssh -L 8080:localhost:80 user@host`).
        
    - **SCP** (secure file transfer).
        
- **Authentication**: Password, public-key (more secure).
    

---

## **4. File Transfer Protocols (FTP, SCP)**

### **FTP (File Transfer Protocol)**

- **Ports**:
    
    - **21** (control).
        
    - **20** (data, active mode).
        
- **Modes**:
    
    - **Active**: Server connects to client (issues with firewalls).
        
    - **Passive (`PASV`)**: Client connects to server (better for NAT).
        
- **Anonymous FTP**:
    
    bash
    
    Copy
    
    USER anonymous  
    PASS email@example.com  
    

### **SCP (Secure Copy)**

- **Purpose**: Encrypted file transfer over SSH.
    
- **Command**:
    
    bash
    
    Copy
    
    scp file.txt user@host:/path/
    

---

## **5. Web Protocols (HTTP, HTTPS)**

### **HTTP (Hypertext Transfer Protocol)**

- **Port**: **80**.
    
- **Request Structure**:
    
    http
    
    Copy
    
    GET / HTTP/1.1  
    Host: example.com  
    
- **Headers**:
    
    - `Host:` (required for virtual hosting).
        
    - `User-Agent:` (identifies browser).
        

### **HTTPS (HTTP Secure)**

- **Port**: **443**.
    
- **Underlying Protocol**: **TLS/SSL** (encrypts traffic).
    
- **Certificates**: X.509 PKI (see below).
    

---

## **6. Directory Services (X.500, LDAP, X.509)**

### **X.500**

- **Purpose**: Hierarchical directory service (predecessor to LDAP).
    
- **Components**:
    
    - **DSA (Directory System Agent)**: Server.
        
    - **DUA (Directory User Agent)**: Client.
        
- **Structure**:
    
    - **DN (Distinguished Name)**: `C=ZA, O=Example, CN=John Doe`.
        

### **LDAP (Lightweight Directory Access Protocol)**

- **Purpose**: Simplified X.500 for TCP/IP.
    
- **Ports**: **389** (unencrypted), **636** (LDAPS).
    
- **Used in**: Active Directory, OpenLDAP.
    
- **Query Example**:
    
    bash
    
    Copy
    
    ldapsearch -x -H ldap://example.com -b "dc=example,dc=com" "(cn=John Doe)"
    

### **X.509 (Public Key Infrastructure)**

- **Purpose**: Digital certificates for authentication/encryption.
    
- **Components**:
    
    - **CA (Certificate Authority)**: Issues certificates (e.g., Verisign).
        
    - **Certificate Fields**:
        
        - **Subject**: Entity (e.g., `CN=example.com`).
            
        - **Issuer**: CA (e.g., `O=Let's Encrypt`).
            
        - **Validity Period**.
            
        - **Public Key**.
            
        - **Signature** (CA’s private key).
            
- **Uses**: HTTPS (SSL/TLS), S/MIME (email encryption).
    

---

## **7. Network Management (SNMP, DHCP)**

### **SNMP (Simple Network Management Protocol)**

- **Purpose**: Monitor/manage network devices.
    
- **Agents vs. Managers**:
    
    - **Agent**: Runs on devices (e.g., routers).
        
    - **Manager**: Central control (e.g., PRTG).
        
- **Commands**:
    
    - `Get` (fetch data).
        
    - `Set` (change config).
        
    - `Trap` (alert manager).
        
- **Ports**: **161** (agent), **162** (manager).
    

### **DHCP (Dynamic Host Configuration Protocol)**

- **Purpose**: Auto-assign IP, subnet, gateway, DNS.
    
- **Process (DORA)**:
    
    1. **Discover** (client broadcasts).
        
    2. **Offer** (server proposes IP).
        
    3. **Request** (client accepts).
        
    4. **Acknowledge** (server confirms).
        
- **Ports**: **67** (server), **68** (client).
    

---

## **8. Routing Protocols (RIP, OSPF, BGP)**

### **RIP (Routing Information Protocol)**

- **Type**: Distance-vector (Bellman-Ford).
    
- **Metric**: Hop count (max **15**).
    
- **Port**: **520** (UDP).
    

### **OSPF (Open Shortest Path First)**

- **Type**: Link-state (Dijkstra’s algorithm).
    
- **Metric**: Cost (based on bandwidth).
    
- **Features**:
    
    - **Areas** (scalability).
        
    - **Fast convergence**.
        

### **BGP (Border Gateway Protocol)**

- **Type**: Path-vector (policy-based).
    
- **Used for**: Inter-AS routing (Internet backbone).