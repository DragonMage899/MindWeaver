# Intro
Chapter focuses on protocols useful for human usage (email, web etc)

# Network Architecture
**Client-Server**
- Client initiates communication
- Server then serves clients requsts

**P2P**
- Any participant can initiate communicaion

# Protocols
# Email

## X.400
- ITU-T standards (X.4xx)
- Define a message handling system
- Developed for ISO/OSI, later adapted to TCP
- Proposed delivery to some snail mail box
	- Actual postal service would then physically deliver the letter
- C ADMD PRMD O OU GIS
![[Pasted image 20250323185547.png]]
![[Pasted image 20250323185608.png]]

# SMTP
- Simple Mail Transfer protocol
- Agents
	- M/UA - Email System to user
		- User Agent
	- MTA - User to Usre
		- mail transfer agent
- UA At sender
	- Piece of code that accepts message, address of sender and recipient  
	- Forwards it to some MTA
- UA at recipient 
	- Accepts incoming mail for user and store it somewhere
	- User may then use POP3 / IMAP4 to view email
- MTA's find a route from sender to recipient
	- Organizations may publish a list of MTA's that accept email on their behalf
	- MTA's can also route mail within an internal organization structure
	- Organization can have an MTA for each department 
	- These can forward email to "outgoing" MTA's
- The usage of muliple MTA's are useful for security and spam reasons

when communicating with an SMTP servers:
start "HELO" or "EHLO"
...
end of mail: ". CRGTR linefeed"
can then proceed with other mail
client needs to tell server address of nearest appropriate MTA to contact
# POP3
- Having it be so that the user directly stores mail is inconvinient
- Instead stored at some email server and copied locally
- POP3 can be used to access your mail on a server
- User can download / delete messages stored on the mail server
- First Authenticates user (smtp does not do this)
![[Pasted image 20250326151922.png]]
- After logging in simple commands can be used
- RETR
- DELE
- QUIT
- STAT (amount of waiting messages)
- Port 110

# IMAP4
- Assumes user is managing on a server 
- Can organize server structure
- Can mark as read/unread
- Auth process
- Complex instructions

# Virtual Terminals

# TELNET
![[Pasted image 20250326153218.png]]
# SSH
- tunneling protocol, can be used by other protocols for secure comm
- can also do secure copy (scp)
- port 22

# FTP
- get
- put 
- ls (acutally compiles a file and transmits it via the data connection)
- RETR SP PATH CRLF
- STOR SP PATH CRLF
- Control Connection
- Data Connection (20)
- Passive mode, requests a port from os to transfer data
- PASV
# HTTP

# HTTPS

# Other
- NTP
	- Network time
- VOILP
	- Vpive over IP
- SMB
	- Server message block, mount remote files on local host
- NFS
	- classic version for mounting remote file systems
- RTSP
	- Real time streaming
	- Radio services and mutimedia
- X.11
	- Display graphical content on remote device 
