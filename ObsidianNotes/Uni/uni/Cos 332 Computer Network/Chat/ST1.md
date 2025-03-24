Based on the past papers and class tests, here are the **key areas** you should focus on when studying for COS332:

---

### **1. Protocol Port Numbers (Must Memorize!)**

- **SMTP**: 25 (MTA-to-MTA), 587 (Submission)

- **DNS**: 53 (UDP/TCP)
    
- **HTTP**: 80
    
- **HTTPS**: 443
    
- **SSH**: 22
    
- **Telnet**: 23
    
- **FTP**: 21 (control), 20 (data in active mode)
    
- **POP3**: 110 (unencrypted), 995 (encrypted)
    
- **IMAP**: 143 (unencrypted), 993 (encrypted)
    
- **DHCP**: 67 (server), 68 (client)
    
- **SNMP**: 161 (agent), 162 (manager)
    

**Exam Focus**: Direct questions (e.g., "Which port is used for HTTP?").

---

### **2. DNS (Domain Name System)**

- **Hierarchy**: TLDs (e.g., `.com`, `.za`), second-level domains (e.g., `co.za`).
    
- **Record Types**:
    
    - **A**: IPv4 address.
        
    - **AAAA**: IPv6 address.
        
    - **MX**: Mail server.
        
    - **CNAME**: Alias.
        
    - **NS**: Name server.
        
    - **PTR**: Reverse DNS (IP → name).
        
- **Name Resolution**:
    
    - **Iterative**: Server refers client to another server.
        
    - **Recursive**: Server resolves the query fully.
        
- **Tools**: `nslookup`, `dig`.
    
    - Example:
        
        bash
        
        Copy
        
        nslookup -type=MX example.com
        
- **Zone Files**: SOA records, serial numbers (YYYYMMDDnn format).
    

**Exam Focus**:

- DNS queries (e.g., "What is the address of `ftp.xx.co.za`?").
    
- Zone file interpretation.
    
- Iterative vs. recursive resolution.
    

---

### **3. Email Protocols (SMTP, POP3, IMAP)**

- **SMTP**:
    
    - Commands: `HELO`, `MAIL FROM:`, `RCPT TO:`, `DATA`, `QUIT`.
        
    - Transparency issue: A lone `.` ends the email body.
        
- **POP3**:
    
    - Commands: `USER`, `PASS`, `RETR`, `DELE`, `QUIT`.
        
    - Downloads and deletes emails by default.
        
- **IMAP**:
    
    - Manages emails on the server (supports folders/flags).
        
    - Commands: `LOGIN`, `SELECT`, `FETCH`.
        

**Exam Focus**:

- Manual SMTP/POP3 interaction (e.g., "What command retrieves email in POP3?").
    
- Differences between POP3 and IMAP.
    

---

### **4. HTTP/HTTPS**

- **HTTP Headers**:
    
    - `Host:` (for virtual hosting).
        
    - `GET / HTTP/1.1` (request format).
        
- **HTTPS**: Uses TLS/SSL (Port 443).
    

**Exam Focus**:

- HTTP request/response structure.
    
- Purpose of `Host:` header.
    

---

### **5. Network Management & Bootstrapping**

- **SNMP**:
    
    - Commands: `Get`, `Set`, `Trap`.
        
    - Used for monitoring devices.
        
- **DHCP**:
    
    - DORA process (Discover, Offer, Request, Acknowledge).
        
    - Assigns IP, subnet, gateway, DNS.
        

**Exam Focus**:

- SNMP operations (e.g., "Which command fetches a value?").
    
- DHCP lease process.
    

---

### **6. ISO/OSI Model Layers**

- **Layer 7 (Application)**: HTTP, SMTP, DNS.
    
- **Layer 6 (Presentation)**: Data formatting (e.g., MIME types).
    
- **Layer 5 (Session)**: Manages connections (e.g., SSH).
    
- **Layer 4 (Transport)**: TCP/UDP.
    
- **Layer 3 (Network)**: IP, routing.
    
- **Layer 2 (Data Link)**: MAC addresses.
    
- **Layer 1 (Physical)**: Cables, signals.
    

**Exam Focus**:

- Layer responsibilities (e.g., "Which layer handles routing?").
    
- Protocols per layer.
    

---

### **7. Routing Protocols**

- **RIP**: Uses hop count (max 15), Bellman-Ford algorithm.
    
- **OSPF**: Link-state, Dijkstra’s algorithm.
    
- **BGP**: Policy-based (used between ASes).
    

**Exam Focus**:

- RIP vs. OSPF differences.
    
- Routing table updates.
    

---

### **8. Practical Tools & Commands**

- **Telnet**:
    
    bash
    
    Copy
    
    telnet example.com 25  # Test SMTP
    
- **SSH**:
    
    bash
    
    Copy
    
    ssh user@host
    
- **Wireshark**: For sniffing traffic (avoid encrypted protocols).
    

**Exam Focus**:

- Using Telnet to test protocols.
    
- Interpreting `nslookup` outputs.
    

---

### **9. Security & Miscellaneous**

- **SSH vs. Telnet**: SSH encrypts; Telnet is plaintext.
    
- **FTP Modes**: Active (port 20) vs. Passive (`PASV`).
    
- **X.509 Certificates**: Used in HTTPS (PKI).
    

**Exam Focus**:

- Why SSH is preferred over Telnet.
    
- FTP data transfer modes.
    

---

### **Exam Strategy**

1. **Memorize ports and protocols**.
    
2. Practice **manual protocol interactions** (e.g., SMTP via Telnet).
    
3. Understand **DNS resolution** (iterative vs. recursive).
    
4. Review **ISO/OSI layer** responsibilities.
    
5. Solve past papers for question patterns.
    

---

### **Final Tip**

Focus on **2016 Big Class Test** (ports, DNS) and **2018 Semester Test** (HTTP, SMTP, OSI layers). The **2024 test** emphasizes practical commands (e.g., `nslookup`) and protocol headers.

Let me know if you'd like deeper explanations on any topic!