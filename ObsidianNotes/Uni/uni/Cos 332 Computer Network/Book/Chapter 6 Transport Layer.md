Layer 4
- Pipe between processes for communication 
- Goal is to hide details of the network itself from the application

 Choices
 - How to identify other processes
 - How reliable should the pipe be
	 - Ideally communications don't fail
	 - When they do should the communicating parties be informed
	 - What does the communicating parties then do


Identification is done though ports

The choice of reliability leads to an entire realm of design choices

## Reliability 

Reliable Connection Oriented
- TCP, QUIC

Connection less
- UDP

Reliable Message Exchange
- Buffers are used at the sender and the receiver to keep track of order 
- Flow Control
	- Stop and Wait: Send a message, wait for ack, send another
	- Sliding Window: Send multiple messages before ack
		- Once Acknowledged from receiver, remove from sender buffer 
			- Numbering Allows us to detect duplicates, missing and out of order
		- Go Back N ARQ
			- If N is lost or naked resend n and all following messges
		- Selective Repeat ARQ
			- If N is lost or naked resend N only

AQR
- Automatic Repeat reQuest
- Protocols that use timers and ACKs for re transmission 
- Has packer timers and ack timers


## Design Choices
![[Pasted image 20250516183301.png]]


## Ports
16 bit number
![[Pasted image 20250516183536.png]]


## TCP
messages are called segments
![[Pasted image 20250516183552.png]]

Timers
- RTO timer
	- Start when a segment is sent
	- If expires before ack assumes data is lost
	- re transmit if lost 
- Persistence Timer
	- Prevents deadlock 
		- Sometimes a update to the window flag may be lost
		- If this expires the sender sends a probe segment (1 byte)
		- The receiver should send the current window size 
			- Window: Amount of bytes sender if this segment is willing to accept, can start at 0 then update later on
- Keep alive timer 
	- Detect broken connections
	- Sends probes after a long period of inactivity
	- Disconnect if no response
- Quiet Timer (Time-Wait state timer)
	- After a connection closes wait for 2 x Max Segment Lifetime before reusing the port
	- Ensures previous connection dies off 


TCP States
![[Pasted image 20250516185630.png]]

### TCP Length
IP has a total length field
- Gives us length of while IP packet

TCP Packet = IP Total Length - IP Header Length (normally 20 bytes, increases if options are present)

Data Size in TCP = TCP Packet - 4 * Data offset

Byte offset for Data in TCP:
(IP Total Length + Data offset) * 4

## UDP
![[Pasted image 20250516185655.png]]

# QUIC
sends packets 

Long Header
- Connection establishment and version negotiation
![[Pasted image 20250516194117.png]]

Short Header
- 1 - RTT (data)
- After connection established
![[Pasted image 20250516194544.png]]

Establishing Connection
Client -> Server 
- Set 0-rtt is re establishing 
- CRYTPO frame with TLS hello client and eph keys

Server -> Client
- Initial ACK packet
- Handshake packet contain crypto frame with tls server hello
- server certificate and signed data
- tls "finished"
- derive session keys and send 1-RTT

Client -> Server
- ACK server's ack
- Handshake has tls finished
- Client can now derive session keys and decrypt any 1-RTT data from server or send 1-RTT data

![[Pasted image 20250516195602.png]]

![[Pasted image 20250516195609.png]]


