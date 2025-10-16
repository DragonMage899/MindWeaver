February 1996

Best Current Practises
Requests Discussion and Suggestions for improvements.

tldr: How to create internal networks without the need of assistance from IANA

Intro
Enterprise 
- Entity that autonomously operates a network using TCP/IP
- Determining the addressing plan and address assignment within that network

Describe address allocation for private Internets. 
Hosts inside and org are connected
Possibly hosts of different orgs aswell 

Cost of Use
- Effort to renumber hosts and network between public and private
- i.e.) If a device using a private address needs to go public, the process of renaming of locations that used that host name might be a time consuming endeavour. Update everything that referenced the address
	- Network config must be manually updated to make the ip accessible 
	- DNS records needs to be made
	- Other systems need to be reconfigured 
- Possible Sol
	- Private and Public at the same time 
		- Dual homes
		- Has it's own pitfalls
		- Security risk, bridge to internal network
		- Routing complexity increases
			- Device must decide which one to use for outgoing traffic
				- Possible asymmetric routing
		- Harder to configure
			- Firewall, Zone file management etc...
			- Need to manage both simultaneously 



**Motivation**
Can be used solely to on a local network

Routing overhead grows beyond ISP capabilities
- How is this looking in modern day?
- ipv6 was meant to be the solution but adoption is slow, why?

 ISP get's range from a registry.
 Then assigns each customer an address from that block
Thus routes to many customers are aggregated together
- What does this mean?

From another ISP is appears to be a single route
- RFC 1518 1519
- What's this about exactly?

"Such encouragement may become a requirement in the
future."
- Did this happens?


"To the contrary, it
is quite likely that when the organization would connect to the
Internet to achieve Internet-wide IP connectivity the organization
would need to change IP addresses (renumber) all of its public hosts
(hosts that require Internet-wide IP connectivity), regardless of
whether the addresses used by the organization initially were
globally unique or not."
- Was this ever true?
- Is it still a concern?

Need more justification to get a unique address

Within Enterprises 3 Categories
- 1
	- connection to outside not needed (at all)
- 2
	- Gateway access to outside needed (simple services ftp, smtp, rdp ...)
	- Unrestricted access probably not idea in most cases
	- Possibly ambiguous outside of enterprise
- 3
	- Globally unambiguous
	- Publicly accessible (web site)

1,2  -> Private
3 -> Public

IANA
10.0.0 -> 10.255.255.255 (10/8 prefix) 24 bit bloc
172.16.0.0 -> 172.31.255.255 (172.16/12 prefix) 20 bit block
192.168.0.0 -> 192.168.255.255 (192.168/16 prefix) 16 but block

CIDR notation
- need a quick refresh on this

Pre CIDR
- Class A
- 16 class B networks
- 256 class C networks

Need a refresh on Class A,B,C,D networks aswell

Ip addresses in this range can be used without any co ordination to IANA

Change from priv to public
- Change of ip address
- Change to config files
- Change to references 

Packets with private addressed are not forwarded between inter-enterprise links
- Whats an inter enterprise link?

Advantages 
- Conserve unique addresses 
- Flexibility in network design
- Prevents ambiguous routing 
	- Enterprise uses an address space privately then to connect to the internet

Disadvantages
- Reduced flexibility in internet access
- Renumbering if one wishes to change
- Merging private networks can be messy (overlaps)

Cost of renumbering can be manages with things like DHCP
- What exactly is DHCP?

**Operational Considerations**
Design private part first and use Private address space for internal links.
Then plan public subnets at locations needed and design external connectivity.
If a groups needs to go public/private can renumber the hosts later and change physical connectivity.
If changes can be forseen
- Elaborate on this?
advisable to configure separate physical mediumfor public and private

Groups with similar connectivity needs each on their own subnets
- Need a short refresher on subnetting and supernetting?

Suitable subnetting scheme supported by equipement
- 24 bit block (A) of private addresses with growth path

If subnetting is a problem
- 16 bit bock (C) or 20 bit block (B) of private addresses

Have both public and private on the same medium
- Pitfalls due to multiple ip subnets on a common data link sub network
- Elaborate?

Roouters that connect to external networks
- Packet and routing filters at both ends
- Packet routing information leakage
- Inbound filters (ambiguity if private packets point outside of enterprise)

Two sites can co ordinate their private networks for communication
Use some method of encapsulation at their public borders to keep private private

Randomness can help with the merge problem.

Outsiders should not have access to private dns info
Possible way to achieve this:
- Two name servers 
	- One for public reachable stuff
	- One for private reachable stuff






---
Would it be apt to say this this document highlights the idea that technology is built from loosely stuck together sticks and stones (or a similar metaphor) and not the idealised solid construction that people often tend to think?

AI answers:
Of course. Here are the answers to the questions from your notes.

---

### **Motivation**

#### **Routing overhead in modern day?**

The concern about routing overhead is still very real. The global internet routing table (the "map" every major router needs) has grown to over 1 million routes. This is managed through a system called the **Border Gateway Protocol (BGP)** and aggressive **route aggregation**. Without practices like private addressing (RFC 1918) and Network Address Translation (NAT), which hide millions of internal devices behind a single public IP, the internet's routing infrastructure would likely collapse under the strain.

---

#### **Why is IPv6 adoption slow?**

IPv6 was designed to solve the address exhaustion problem, but its adoption has been slow for several key reasons:

- **"Good Enough" Solutions:** Network Address Translation (NAT) worked surprisingly well as a stopgap for IPv4. It allows entire private networks to share a single public IPv4 address, drastically extending IPv4's lifespan1.
    
- **Cost and Complexity:** Migrating to IPv6 is a significant undertaking. It requires replacing or upgrading hardware (routers, switches), updating software, and retraining network engineers. For most organizations, there's no immediate financial incentive to switch while IPv4 is still working for them.
    
- **Lack of a "Flag Day":** There was never a coordinated, mandatory switchover date. Instead, networks are adopting a gradual, dual-stack approach (running both IPv4 and IPv6), which adds its own layer of complexity.
    

---

#### **What does "routes to many customers are aggregated together" mean?**

This is the core concept of **route aggregation** (or summarization). Instead of announcing every single customer's specific IP address to the entire internet, an Internet Service Provider (ISP) announces one large, summarized block that contains all of its customers.

Think of it like mail delivery. A country's postal service doesn't tell every other country in the world about every single street address it has. Instead, it just says, "Send all mail for South Africa to me." That's one "route." Once the mail arrives in the country, the local system handles getting it to the correct street. Similarly, an ISP tells the internet, "Send all traffic for the

`196.25.0.0/16` block to me," and then internally routes it to the correct customer2. This keeps the global routing tables small and efficient.

---

#### **What are RFCs 1518 and 1519 about?**

These two RFCs introduced

**Classless Inter-Domain Routing (CIDR)** in 19933. CIDR is the system that enables the route aggregation described above. It replaced the old, rigid "classful" system (Class A, B, C) with a flexible method where a network's size is defined by a prefix (e.g.,

`/24`), allowing for much more efficient allocation and summarization of IP address blocks.

---

#### **Did "renumbering encouragement become a requirement"?**

Yes, for the vast majority of cases, this has become a de facto requirement. When you sign up for an internet connection, the ISP assigns you an IP address from its own block. If you switch to a different ISP, you lose that IP address and are assigned a new one from the new provider's block. This forces you to **renumber**. While it's technically possible to get "Provider Independent" addresses that you can take with you, it's a much more difficult and expensive process reserved for large organizations.

---

#### **Was the statement about renumbering with globally unique addresses true, and is it still a concern?**

Yes, this was true and is still a concern. The issue arises from how route aggregation works. Even if your company was assigned a globally unique block of addresses years ago, it might be a small, "standalone" block. When you connect to an ISP, they might refuse to announce your small, specific route to the rest of the internet because it "de-aggregates" their larger, cleaner network announcement. They will require you to renumber your public hosts using addresses from their own block so they can maintain their efficient, aggregated routing4.

---

### **IANA & Address Classes**

#### **CIDR Notation Refresh**

CIDR (Classless Inter-Domain Routing) notation is a way to represent an IP address and its associated network mask. It looks like this: `192.168.1.0/24`.

- The `/24` is the **prefix length**.
    
- It tells you that the first **24 bits** of the address are the **network portion**.
    
- The remaining bits (32 - 24 = 8 bits) are the **host portion**, which can be assigned to individual devices.
    

---

#### **Class A, B, C, D Networks Refresh**

This is the old, largely obsolete "classful" system that CIDR replaced. Networks were divided into fixed-size classes based on the value of the first number (octet) in the IP address.

- **Class A:** First octet is `1-126`. (e.g., `10.x.x.x`). Designed for a few massive networks with millions of hosts.
    
- **Class B:** First octet is `128-191`. (e.g., `172.16.x.x`). For medium-to-large networks.
    
- **Class C:** First octet is `192-223`. (e.g., `192.168.1.x`). For many small networks.
    
- **Class D:** First octet is `224-239`. Reserved for **multicast** traffic (sending a packet to a group of destinations at once).
    

---

### **Private Addresses**

#### **What's an inter-enterprise link?**

An inter-enterprise link is any network connection that directly joins two different organizations. For example, a dedicated fiber optic line between a manufacturing company and its primary parts supplier. Packets with private source or destination addresses should not be forwarded across these links5.

---

### **Disadvantages**

#### **What exactly is DHCP?**

**DHCP** stands for **Dynamic Host Configuration Protocol**. It's a network management protocol that automates the process of configuring devices on a network. When a computer, phone, or other device connects to a network, a DHCP server automatically assigns it an IP address, subnet mask, default gateway, and DNS server information. This is crucial for renumbering because instead of changing the IP address on every single device manually, an administrator can just change the configuration on the DHCP server, and all devices will get new addresses automatically when they next connect6.

---

### **Operational Considerations**

#### **Elaborate on foreseeing changes (separate physical media)**

This is practical advice for network design. If you have a server room and you know that some servers currently used for internal purposes might need to become public-facing in the future, you should plan for it physically7. The recommendation is to install two separate sets of physical network infrastructure (cables, switches) in that room: one connected to the private internal network and one connected to the public-facing (internet) network8.

When the time comes to make a server public, the change is simple: you just unplug its network cable from the "private" port and plug it into the "public" port. This avoids complex software reconfiguration and is a clean, reliable way to manage the transition.

---

#### **Subnetting and Supernetting Refresher**

- **Subnetting:** This is the process of taking one large network and **dividing it into smaller logical pieces**, called subnets. This is done to improve organization and security. For example, you could take your company's main network and create separate subnets for the Engineering, Sales, and Guest Wi-Fi networks. This ensures that traffic from guests doesn't interfere with the Engineering department.
    
- **Supernetting:** This is the opposite of subnetting. It involves taking multiple smaller, contiguous network ranges and **combining them into a single, larger network summary**. This is another term for the route aggregation discussed earlier. It's used by routers to simplify routing tables.
    

---

#### **Elaborate on pitfalls of public/private on the same medium**

Putting public and private IP addresses on the same physical network segment (e.g., having devices plugged into the same switch) is possible but risky9. The "pitfalls" include:

- **Routing Confusion:** Devices on different IP subnets cannot talk to each other directly, even on the same switch; they need a router. This can create complex and inefficient traffic paths.
    
- **Security Weakness:** It blurs the critical security boundary between your trusted internal network and the untrusted public internet. A misconfiguration on a single machine could accidentally expose your entire private network to the internet. The RFC advises setting up packet and routing filters on routers connecting to external networks to prevent this information leakage10.



---
Advent of Cyber
- One of the larger sparks that pushed me towards Cyber Security
- Genuinely found it to be quite fun
- Exposed to a lot of topics that I've never encountered before, knowing that there'd be something new each day kept me coming back
- Favourite Challenges: 
	- Reverse engineering
		- Topic that always fascinates me
	- AD
		- First real encounter with AD
		- Been using windows for 10 years at that point thought I was decently familiar with it but I ended up going down a lot of rabbit holes that I didn't know existed which is always fun
