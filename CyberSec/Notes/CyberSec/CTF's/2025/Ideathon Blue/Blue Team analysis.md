
# Challenge goals:
![[Pasted image 20250413164437.png]]
![[Pasted image 20250413164518.png]]
https://www.virustotal.com/gui/file/453257c3494addafb39cb6815862403e827947a1e7737eb8168cd10522465deb

![[Pasted image 20250413164929.png]]

# pcap
Sorting by protocol we see: 
ARP
BROWSER 
DHCPv6 
DNS 
HTTP 
ICMP 
ICMPv6 
LLDP 
LLMNR 
MDNS 
NBNS
OCSP
STP 
TCP 
TLSv1.2 
UDP/XML

Standard outs: Browser, UDP/XML, llmnr, nbns (old windows version), TLSv1.2(encrypt tcp data comms)

noise clearing: Ignore protocols we can't use for tunnelling, spoofing or data transfers
`!arp && !icmpv6 && !dhcpv6 &&!lldp && !ocsp && !stp`

Suspected:
Windows device booting up
Performs Service Discovery




## **BROWSER**
![[Pasted image 20250413164740.png]]
https://wiki.wireshark.org/BrowserProtocol
![[Pasted image 20250414102458.png]]
We have SMB, let's dig deeper here
- Transport Protocol for SMB (set's of my alarm)
- Full name: Microsoft Windows Browser Protocol
- Before we go into SMB let's get a closer look at what this protocol does
https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-brws/d2d83b29-4b62-479e-b427-9b750303387b
- Basic idea seems to be providing and finding details about services on the networks

**Key terms related to protocol**
nonbrowser server: A server that wants to be enumerated to clients of the CIFS Browser
Protocol that does not otherwise implement elements of the CIFS Browser Protocol.

Master Browser: Device that delegate service allocation and discovery to other devices on the network


### **Traffic analysis**
same source, same destination
source: 192.168.100.255
destination: 192.168.100.8
both on the local network

### **Packet inspection**
We can see the following in the Command field for the protocol header:
![[Pasted image 20250414123353.png]]
From "2.2 Message Syntax" of the spec
MailSlot is used as the transport layer protocol 
- https://wiki.wireshark.org/Mailslot
Which appears to related to SMB1, a possible attack vector (wannacry, not_petya etc.)
- https://techcommunity.microsoft.com/blog/filecab/the-beginning-of-the-end-of-remote-mailslots-as-part-of-windows-insider/3762048

Messages grouped by roles

#### **Request Announcement** (2.2.2 AnnouncementRequest Browser Frame)
- Send by nonbrowser services
- From Computer to group
- machinegroup[0x00]
	- Forces all machines on the group to announce
- machinegroup[0x1D]
	- Force current master browser to announce itself 
	- Expects response as a set of HostAnnouncement frames
- The frame MUST be sent to mailslot \MAILSLOT\BROWSE.

![[Pasted image 20250414142540.png]]

#### **Host Announcement** (2.2.1 HostAnnouncement Browser Frame)
Host announces it:
**Windows 10 Version 1507** (Initial version)
![[Pasted image 20250414145741.png]]
Browser Protocol version 15.1
- Release Date: 3/12/2010 
- Suspected Eternal Blue 
- https://support.microsoft.com/en-us/topic/ms10-012-vulnerabilities-in-smb-server-could-allow-remote-code-execution-95e12916-461b-4411-ca40-12d84f3e648f

#### Browser Election Request 
3.3.5.8 Receiving a RequestElection Frame
- Local master browser indicates that another machine on the group also believes it's a local master
- Or
- Client unable to get info from local master 

Seems like 192.168.100.8 wants to be the master browser, it makes this request 4 times.
Seems like there's no other Master browser, thus the source get's elected

#### Domain Announcement 
![[Pasted image 20250414152129.png]]
The spec is a bit but it appears that the source is announcing to other browsers that it's a Domain with the name "WORKGROUP" where they can find network resources. 

We also have windows version set to 3.10?
Different from earlier, which was possibly spoofed


Seems like we have a mysterious field.
`Mysterious Field: 0x000001c8`
IN binary:
111001000

Potential server type field?
https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-rap/2258bd8d-f17b-45a9-a75e-3e770bc3ad07
Chucking this into chatgpt we have:
![[Pasted image 20250414165129.png]]

#### Local Master Announcement
Announces a machine as a master to all other browser services
Version back to 10
192.168.100.8 is now the master browser.
A lot of server type fields set


#### Recap 
All browser requests come from the same source 
- 192.168.100.8
After coming online it starts sending elections requests in an attempts to become the master browser which will allow it to serve service information to other devices on the network 
- Elections are dependent on os version
- Possibly spoofed top from 3.1 to 10.0

# Timeline
192.168.100.8 registers on the network
- mac address **`c4:14:00:55:fb:68`**
Determines 



# Inspecting  192.168.100.8
c4:14:00:55:fb:68

!arp && !icmpv6 && !dhcpv6 &&!lldp && !ocsp && (ip.src == 192.168.100.8 || ip.dst == 192.168.100.8)

(ip.src == 192.168.100.8 || ip.dst == 192.168.100.8)

Inspection

**BEFORE BECOMING MASTER BROWSER**

Registers itself with NBNS
Normal network discovery

makes a request announcement 
A tlsv1.2 connection appears, we don't appear to have information on the handshake so let's continue -
**52.213.60.184**

Standard DNS request to `settings-win.data.microsoft.com: type A, class IN`
- An address over the internet 
- This appears normal
DNS response, We see the following in the answer field:
![[Pasted image 20250414174416.png]]
Which isn't too odd but
**51.124.78.146**
Appears again alot
We make a TLSv1.2 connection to this ip 
Looking at virus total we come across an interesting comment:
https://www.virustotal.com/gui/ip-address/51.124.78.146/community
https://github.com/TheRavenFile/Daily-Hunt/blob/main/Crowdstrike%20Cryptomining%20Campaign
Seems to be an IOC for a crypto miner

**51.124.78.146 TCP stream**
23 packets 
192.168.100.8 makes a tsl handshake with 51.124.78.146
certificate seems valid
check it with crl.microsoft.com (dns request ) 23.216.77.6
Get the ip where the CRL is stored
Make a request for the clr cert to that
Next few frames appear data transmission occurs Till Frame 91
Frame 126:
- LLDP advertises itself on LLDP
Till Frame 151
Connection is maintaned with TCP ACKS
TLS comms continue 
TCP stream appears to be over

Frame 165: 52.213.60.184
- Amazon server. Retransmissoin to compromised machine 

Frame 166 - 168
Compromised machine tries to determine mac address of 3 devices

Frame 172
199.232.210.172 closes connection to comp dev

Continue with similar discovery behaviour untill Frame 195
Make a new TCP connection to 172.211.123.258

Frame 220: com dev looks for DHCPv6 servers

Frame 225
192.168.100.8 dns request to login.live.com
- Allows user to logs into all Microsoft services at once 
**20.190.259.68**

2.17.190.73 : Cert site
Frame 240
Cert appears to be fine 
![[Pasted image 20250415143611.png]]

Communicate with 20.190.259.68 Til Frame 316

Frame 313
Make another TCP connection to settings-win.data.microsoft.com
4.231.128.59
Appears to be related to mc diagnostics but has been flagged by one vendor
https://www.virustotal.com/gui/ip-address/4.231.128.59/detection

Frame 360 - 442
Network discovery

Frame 422
Comp starts Browser Election Spam

Frame 447
comp pings the dns server 

**192.168.0.1 Starts performing an arp scan for discovery**
General process:
- Ask for Mac Address for an ip
- If there's a response ping the ip

Discovers:
192.168.0.1
192.168.0.2 pb
192.168.0.6
192.168.0.10

During the scan we also observe the following happening multiple times: 
![[Pasted image 20250415163955.png]]
The device is registering WORKGROUP which was used in the Domain Announcement section of the Browser sequence 
It then does another NBNS registratoin for `__MSBROWSE__` which is the Master Browser
https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-brws/0c773bdd-78e2-4d8b-8b3d-b7506849847b
the device want to be the master browser and delegate service allocation and discovery to other devices on the network


Frame 1222
We see another transmission from the amazon server at 52.213.60.184

Frame 1223 Connect to ms update server 
4.242.163.56

Frame 1237 Connect to microsoft.com 
88.221.169.152

Frame 1248 Make connection to 4.245.163.56
Appears regular appears dns and mc traffic
Frame 1289 Connection to 13.95.31.18, Azure server 

Frame 1341 we see an arp scan from the dns server?
d4:da:6d:c0:cc:32

setting eth.addr == d4:da:6d:c0:cc:32
I see events for 192.168.100.8
![[Pasted image 20250415172405.png]]
This is likely an indicator that the dns server and comp dev are the same. 
Thus all dns traffic is now suspect
Let's come back to that 

Frame 1340 192.168.100.8 Domain Announcement

Frame 1393 Master Announcement
192.168.100.8

---

Another TLS connection from a outside computer:
13.95.31.18
Nothing much to really see
Moving on


We see another TLS connection without a hello
172.211.123.249
Nothing much to see
possible signs of tsl flooding thus far


---

# Inspecting 51.124.78.146
There's a lot of traffic which is odd for a telemetry server 
Certificate seems fine but it could be spoofed
![[Pasted image 20250414195054.png]]

Alot of tcp and tls
In the span of a few mili seconds we have 5 server hello's and 5 key exchanges
Possible C2 comms
Nothing conclusive, return to 192.168.100.8

# Inspecting 13.95.31.18
Server starts with a hello and certificate which is odd
![[Pasted image 20250414195744.png]]
Nothing else really 






# **SMB**
https://wiki.wireshark.org/SMB
https://en.wikipedia.org/wiki/Server_Message_Block
https://www.ibm.com/docs/sv/aix/7.1?topic=management-smb-protocol
- Remote file access protocol


# **Web Digging**
https://msrc.microsoft.com/blog/2011/02/notes-on-exploitability-of-the-recent-windows-browser-protocol-issue/

# Extra
## Protocol Breakdown

### 📡 **BROWSER**

- **Purpose**: Windows Browser Protocol (part of NetBIOS); used by legacy Windows systems to list available network shares and resources.
    
- **Common in**: Old LAN environments; replaced by modern protocols like WS-Discovery.
    
- **Tunneling/Evasion**: ❌ Rarely used for evasion due to its legacy status and verbosity.
    

---

### 🧧 **DHCPv6**

- **Purpose**: Assigns IPv6 addresses to clients and delivers network config info like DNS servers.
    
- **Common in**: IPv6-enabled networks.
    
- **Tunneling/Evasion**: ❌ Not designed for payload transport; not practical for tunneling.
    

---

### 🌐 **DNS**

- **Purpose**: Resolves domain names to IP addresses.
    
- **Common in**: Every networked environment.
    
- **Tunneling/Evasion**: ✅ **Yes**—**DNS tunneling** (e.g., `iodine`, `dnscat2`) is popular for exfiltration and C2 communication.
    

---

### 📄 **HTTP**

- **Purpose**: Web communication (requests/responses of websites, APIs).
    
- **Common in**: Browsers, APIs, IoT devices.
    
- **Tunneling/Evasion**: ✅ **Yes**—used in web-based tunneling (e.g., web shells, C2 frameworks like `Cobalt Strike`).
    

---

### 📶 **ICMP**

- **Purpose**: Diagnostic/control messages (e.g., `ping`, `destination unreachable`).
    
- **Common in**: Network testing and error reporting.
    
- **Tunneling/Evasion**: ✅ **Yes**—**ICMP tunneling** is real (e.g., `icmptunnel`, `ptunnel`, `ping tunnel`).
    

---

### 📶 **ICMPv6**

- **Purpose**: IPv6 version of ICMP; handles neighbor discovery, router solicitation, etc.
    
- **Common in**: IPv6 networks.
    
- **Tunneling/Evasion**: ⚠️ Rare, but possible in theory (ICMP-based tunneling tools may need IPv6 adaptation).
    

---

### 📦 **LLDP (Link Layer Discovery Protocol)**

- **Purpose**: Lets network devices advertise their identity/capabilities (used by switches, routers).
    
- **Common in**: Managed network hardware.
    
- **Tunneling/Evasion**: ❌ Not payload-capable; too constrained.
    

---

### 🌍 **LLMNR (Link-Local Multicast Name Resolution)**

- **Purpose**: Resolves local names without a DNS server (used by Windows).
    
- **Common in**: Local Windows LANs.
    
- **Tunneling/Evasion**: ⚠️ Exploitable via spoofing (e.g., `Responder`), but not great for tunneling.
    

---

### 🌐 **mDNS (Multicast DNS)**

- **Purpose**: Like DNS, but for local networks without a DNS server (e.g., `*.local` addresses).
    
- **Common in**: IoT, Apple devices (AirPlay, Bonjour).
    
- **Tunneling/Evasion**: ⚠️ Uncommon, but **could** be adapted for tunneling.
    

---

### 📣 **NBNS (NetBIOS Name Service)**

- **Purpose**: Resolves NetBIOS names to IPs (similar to DNS, but legacy).
    
- **Common in**: Older Windows networks.
    
- **Tunneling/Evasion**: ⚠️ Mostly abused via spoofing (again, `Responder`).
    

---

### 🛂 **OCSP (Online Certificate Status Protocol)**

- **Purpose**: Checks if a TLS certificate has been revoked.
    
- **Common in**: Browsers, TLS clients.
    
- **Tunneling/Evasion**: ❌ Not used for tunneling.
    

---

### 🕸️ **STP (Spanning Tree Protocol)**

- **Purpose**: Prevents Ethernet loops in network topologies.
    
- **Common in**: Switches and bridges.
    
- **Tunneling/Evasion**: ❌ No data carriage; no tunneling use.
    

---

### 🔁 **TCP**

- **Purpose**: Connection-oriented data transfer protocol (reliable).
    
- **Common in**: Most internet traffic—HTTP, HTTPS, FTP, SSH, etc.
    
- **Tunneling/Evasion**: ✅ Yes—used in tools like `ssh`, `ngrok`, and **covert channels**.
    

---

### 🔐 **TLSv1.2**

- **Purpose**: Encrypts TCP communication (e.g., HTTPS).
    
- **Common in**: Secure websites, email, APIs.
    
- **Tunneling/Evasion**: ✅ Yes—**encrypted tunnels** like VPNs, HTTPS C2 traffic.
    

---

### 🔀 **UDP**

- **Purpose**: Connectionless, fast transmission.
    
- **Common in**: VoIP, DNS, games, video streaming.
    
- **Tunneling/Evasion**: ✅ Yes—used in tools like `openvpn`, `iodine`, `udp tunnel`.
    

---

### 🧾 **UDP/XML**

- **Purpose**: Indicates XML-formatted data sent via UDP (e.g., custom protocols, SOAP-over-UDP).
    
- **Common in**: Embedded systems, legacy services, SSDP.
    
- **Tunneling/Evasion**: ⚠️ Uncommon, but if XML carries commands, could be misused.
    

---

## 🕵️‍♂️ Protocols Commonly Used for Tunneling or Evasion

|Protocol|Tunneling Potential|Notes|
|---|---|---|
|**DNS**|✅|DNS tunneling is a classic.|
|**HTTP**|✅|Web-based C2 and exfiltration.|
|**ICMP**|✅|ICMP tunnels bypass firewalls.|
|**TCP**|✅|Basis of most encrypted tunnels.|
|**TLS**|✅|Encrypted tunnels, hard to inspect.|
|**UDP**|✅|Used in VPNs and covert channels.|
|**LLMNR / NBNS**|⚠️|Can be spoofed for credential capture, not for tunneling.|
|**mDNS / XML-over-UDP**|⚠️|Rarely used for tunnels, but possible if protocol allows arbitrary data.|