### **Detailed Notes and Summaries: Chapter 3 (Application Layer - Network-Oriented Protocols)**

---

## **1. DNS (Domain Name System)**

### **Purpose**

- Translates human-readable domain names (e.g., `example.com`) to IP addresses (e.g., `192.0.2.1`).
    
- Hierarchical, decentralized system for scalability.
    

### **Domain Name Structure**

- **TLDs (Top-Level Domains)**:
    
    - **gTLDs**: `.com`, `.net`, `.org` (generic).
        
    - **ccTLDs**: `.za` (South Africa), `.us` (USA).
        
    - **sTLDs**: `.google`, `.apple` (sponsored).
        
- **Second-Level Domains**: `example.com`, `co.za`.
    
- **Subdomains**: `mail.example.com`.
    

### **DNS Records**

| Record Type | Purpose                 | Example                                  |
| ----------- | ----------------------- | ---------------------------------------- |
| **A**       | IPv4 address            | `example.com A 192.0.2.1`                |
| **AAAA**    | IPv6 address            | `example.com AAAA 2001:db8::1`           |
| **NS**      | Name server             | `example.com NS ns1.example.com`         |
| **MX**      | Mail server             | `example.com MX 10 mail.example.com`     |
| **CNAME**   | Alias                   | `www.example.com CNAME example.com`      |
| **PTR**     | Reverse DNS (IP → name) | `1.2.0.192.in-addr.arpa PTR example.com` |

### **Manual Interaction with `nslookup`**

1. **Basic Query**:
    
    bash
    
    Copy
    
    nslookup example.com
    
    - Returns the IP address of `example.com`.
        
2. **Query Specific Record Type**:
    
    bash
    
    Copy
    
    nslookup -type=MX example.com
    
    - Lists mail servers for `example.com`.
        
3. **Iterative Query (Starting from Root)**:
    
    bash
    
    Copy
    
    nslookup
    > server a.root-servers.net  # Use root server
    > set type=NS
    > com.                       # Query .com TLD servers
    > server a.gtld-servers.net  # Switch to .com server
    > example.com.               # Query example.com NS
    

### **Port**

- **DNS Servers**: UDP/TCP **Port 53**.
    

---

## **2. DHCP (Dynamic Host Configuration Protocol)**

### **Purpose**

- Automatically assigns IP addresses, subnet masks, gateways, and DNS servers to devices on a network.
    
- Uses a **lease** system (temporary assignment).
    

### **DHCP Process (DORA)**

1. **Discover**: Client broadcasts "DHCP Discover" (Who’s the DHCP server?).
    
2. **Offer**: Server responds with "DHCP Offer" (Here’s an IP).
    
3. **Request**: Client requests the offered IP ("DHCP Request").
    
4. **Acknowledge**: Server confirms ("DHCP Ack").
    

### **Manual Interaction**

- **Linux**: `dhclient` (renew lease with `dhclient -r` then `dhclient`).
    
- **Windows**: `ipconfig /release` then `ipconfig /renew`.
    

### **Port**

- **DHCP Server**: UDP **Port 67**.
    
- **DHCP Client**: UDP **Port 68**.
    

---

## **3. SNMP (Simple Network Management Protocol)**

### **Purpose**

- Monitors and manages network devices (routers, switches, servers).
    
- Uses **agents** (on devices) and **managers** (control center).
    

### **SNMP Commands**

|Command|Purpose|
|---|---|
|**Get**|Fetch a value (e.g., CPU usage).|
|**GetNext**|Fetch the next variable in sequence.|
|**Set**|Change a configuration (e.g., reboot device).|
|**Trap**|Agent alerts manager of an event (e.g., high traffic).|

### **Manual Interaction**

- Use `snmpwalk` (Linux) to query SNMP devices:
    
    bash
    
    Copy
    
    snmpwalk -v 2c -c public 192.168.1.1
    
    - `-v 2c`: SNMP version.
        
    - `-c public`: Community string (password).
        

### **Port**

- **SNMP Manager**: UDP **Port 162** (traps).
    
- **SNMP Agent**: UDP **Port 161** (queries).
    

---

## **4. LDAP (Lightweight Directory Access Protocol)**

### **Purpose**

- Stores and retrieves hierarchical directory data (e.g., user accounts, org charts).
    
- Used in **Active Directory** (Microsoft) and **OpenLDAP**.
    

### **LDAP Structure**

- **Base DN**: Root of the directory (e.g., `dc=example,dc=com`).
    
- **Entries**: Objects (e.g., `cn=John Doe,ou=Users,dc=example,dc=com`).
    

### **Manual Interaction**

- Use `ldapsearch` (Linux):
    
    bash
    
    Copy
    
    ldapsearch -x -H ldap://example.com -b "dc=example,dc=com" "(cn=John Doe)"
    
    - `-x`: Simple authentication.
        
    - `-H`: LDAP server URI.
        
    - `-b`: Base DN for search.
        

### **Port**

- **LDAP**: TCP **Port 389** (unencrypted), **Port 636** (LDAPS, encrypted).
    

---

## **5. Routing Protocols**

### **RIP (Routing Information Protocol)**

- **Purpose**: Simple IGP (Interior Gateway Protocol) using **hop count**.
    
- **Algorithm**: Bellman-Ford (distance-vector).
    
- **Limitations**: Max 15 hops, slow convergence.
    

### **OSPF (Open Shortest Path First)**

- **Purpose**: Advanced IGP using **link-state** (Dijkstra’s algorithm).
    
- **Features**:
    
    - Faster convergence.
        
    - Supports **areas** for scalability.
        
    - Uses **cost** (bandwidth-based metric).
        

### **Manual Interaction**

- **Cisco Router (OSPF Example)**:
    
    bash
    
    Copy
    
    router ospf 1
    network 192.168.1.0 0.0.0.255 area 0
    
    - `area 0`: Backbone area.
        

### **Port**

- **RIP**: UDP **Port 520**.
    
- **OSPF**: IP Protocol **89** (no transport layer port).
    

---

## **Key Takeaways from Chapter 3**

1. **DNS**:
    
    - Hierarchical (`com → example.com → mail.example.com`).
        
    - Use `nslookup` for manual queries.
        
2. **DHCP**:
    
    - Automates IP assignment (DORA process).
        
3. **SNMP**:
    
    - Monitors devices (`snmpwalk` for queries).
        
4. **LDAP**:
    
    - Directory services (`ldapsearch` for queries).
        
5. **Routing Protocols**:
    
    - **RIP**: Simple, hop-based.
        
    - **OSPF**: Fast, cost-based.