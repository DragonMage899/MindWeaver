### Detailed Notes and Summaries: Chapter 2 (Application Layer - User-Oriented Protocols)

#### **1. Network Architectures**

- **Client-Server Architecture**: Dominant model where clients request services from servers. Servers may act as clients to backend services.
    
- **Relevance Across Layers**: Primarily applies to the application layer (Layer 7). Less relevant below Layer 4 (Transport Layer).
    

---

#### **2. Email Protocols**

##### **SMTP (Simple Mail Transfer Protocol)**

- **Purpose**: Transfers emails between servers/clients.
    
- **Ports**:
    
    - Port 25 (MTA-to-MTA communication).
        
    - Port 587 (Submission port, UA-to-MTA).
        
- **Key Commands** (Manual Interaction via Telnet):
    
    - `HELO/EHLO <domain>`: Greet the server.
        
    - `MAIL FROM: <sender>`: Specify sender.
        
    - `RCPT TO: <recipient>`: Specify recipient.
        
    - `DATA`: Start email body (end with `.` on a line).
        
    - `QUIT`: End session.
        
- **Example**:
    
    plaintext
    
    Copy
    
    EHLO example.com
    MAIL FROM: user@example.com
    RCPT TO: recipient@example.net
    DATA
    Hello, this is a test email.
    .
    QUIT
    

##### **POP3 (Post Office Protocol v3)**

- **Purpose**: Retrieve emails from a server to a local client.
    
- **Port**: 110 (unencrypted), 995 (encrypted).
    
- **Key Commands**:
    
    - `USER <username>`: Authenticate user.
        
    - `PASS <password>`: Provide password.
        
    - `RETR <n>`: Retrieve email number `n`.
        
    - `DELE <n>`: Mark email for deletion.
        
    - `QUIT`: End session (deletes marked emails).
        
- **Example**:
    
    plaintext
    
    Copy
    
    USER alice
    PASS password123
    RETR 1
    QUIT
    

##### **IMAP4 (Internet Message Access Protocol v4)**

- **Purpose**: Manage emails on the server (supports folders, flags).
    
- **Port**: 143 (unencrypted), 993 (encrypted).
    
- **Key Commands**:
    
    - `LOGIN <user> <password>`: Authenticate.
        
    - `SELECT <folder>`: Choose a mailbox.
        
    - `FETCH <n> <attributes>`: Retrieve parts of an email.
        
    - `STORE <n> FLAGS (\Flagged)`: Mark email.
        
- **Example**:
    
    plaintext
    
    Copy
    
    LOGIN alice password123
    SELECT INBOX
    FETCH 1 BODY[HEADER]
    

---

#### **3. Virtual Terminal Protocols**

##### **Telnet**

- **Purpose**: Remote terminal access (unencrypted).
    
- **Port**: 23.
    
- **Usage**:
    
    bash
    
    Copy
    
    telnet hostname 23
    
    - Login prompts are sent in cleartext (insecure).
        

##### **SSH (Secure Shell)**

- **Purpose**: Encrypted remote terminal access.
    
- **Port**: 22.
    
- **Usage**:
    
    bash
    
    Copy
    
    ssh user@hostname
    
    - Supports tunneling (e.g., `ssh -L 8080:localhost:80 user@host`).
        

---

#### **4. File Transfer Protocols**

##### **FTP (File Transfer Protocol)**

- **Purpose**: Transfer files between hosts.
    
- **Ports**:
    
    - 21 (control connection).
        
    - 20 (data connection in active mode).
        
- **Modes**:
    
    - **Active**: Server connects to client for data.
        
    - **Passive (PASV)**: Client connects to server for data.
        
- **Key Commands**:
    
    - `USER <name>`, `PASS <password>`: Authenticate.
        
    - `get <file>`, `put <file>`: Download/upload.
        
    - `ls`: List files.
        
- **Anonymous FTP**:
    
    plaintext
    
    Copy
    
    USER anonymous
    PASS email@example.com
    

---

#### **5. Web Protocols**

##### **HTTP (Hypertext Transfer Protocol)**

- **Purpose**: Fetch web resources.
    
- **Port**: 80.
    
- **Example Request**:
    
    http
    
    Copy
    
    GET / HTTP/1.1
    Host: example.com
    

##### **HTTPS (HTTP Secure)**

- **Purpose**: Encrypted HTTP.
    
- **Port**: 443.
    
- **Underlying Protocol**: TLS/SSL (Transport Layer Security).
    

---

#### **6. Other Protocols**

- **NTP (Network Time Protocol)**: Syncs time (Port 123).
    
- **VoIP/SIP**: Voice calls (Port 5060/5061 for SIP).
    
- **SMB/NFS**: File sharing (Ports 445/SMB, 2049/NFS).
    

---

#### **7. Sniffing Traffic**

- **Tool**: Wireshark.
    
- **Use Case**: Debugging protocols (e.g., observe SMTP/POP3 traffic).
    
- **Warning**: Avoid sniffing encrypted traffic (HTTPS/SSH) or unauthorized networks.
    

---

### Key Takeaways from Chapter 2:

1. **Protocol Ports**: Memorize key ports (e.g., SMTP:25, HTTP:80, SSH:22).
    
2. **Manual Interaction**: Use Telnet to manually test SMTP/POP3 (e.g., `telnet smtp.example.com 25`).
    
3. **Security**: Prefer encrypted protocols (SSH, HTTPS, IMAPS) over cleartext (Telnet, FTP).
    
4. **Email Flow**:
    
    - SMTP sends, POP3/IMAP retrieves.
        
    - IMAP manages server-side folders; POP3 downloads and deletes.