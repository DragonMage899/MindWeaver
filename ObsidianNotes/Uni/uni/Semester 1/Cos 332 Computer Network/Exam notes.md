# Layer 7
## x400
![[Pasted image 20250609173124.png]]

## smtp
![[Pasted image 20250609173306.png]]
![[Pasted image 20250609173321.png]]
![[Pasted image 20250609173335.png]]


## pop3
![[Pasted image 20250609173400.png]]
![[Pasted image 20250609173422.png]]
![[Pasted image 20250609173443.png]]
![[Pasted image 20250609174608.png]]

## imap4
![[Pasted image 20250609173512.png]]

## telnet
![[Pasted image 20250609173541.png]]

## ssh
![[Pasted image 20250609174309.png]]
![[Pasted image 20250609174344.png]]

## HTTP
![[Pasted image 20250609174414.png]]

![[Pasted image 20250609174458.png]]
![[Pasted image 20250609174505.png]]

Network oriented protocols
![[Pasted image 20250609174718.png]]


## DNS
![[Pasted image 20250609174741.png]]
![[Pasted image 20250609175249.png]]
![[Pasted image 20250609175355.png]]
![[Pasted image 20250609175414.png]]

![[Pasted image 20250609175425.png]]
![[Pasted image 20250609175435.png]]
![[Pasted image 20250609175513.png]]
![[Pasted image 20250609175531.png]]
![[Pasted image 20250609175601.png]]
![[Pasted image 20250609175613.png]]

![[Pasted image 20250609175637.png]]

![[Pasted image 20250609175656.png]]

![[Pasted image 20250609175722.png]]

![[Pasted image 20250609175851.png]]
![[Pasted image 20250609175901.png]]

![[Pasted image 20250609175942.png]]
![[Pasted image 20250609175949.png]]

![[Pasted image 20250609180038.png]]
![[Pasted image 20250609180047.png]]

![[Pasted image 20250609180117.png]]

![[Pasted image 20250609180214.png]]
![[Pasted image 20250609180223.png]]
![[Pasted image 20250609180233.png]]

![[Pasted image 20250609180242.png]]

![[Pasted image 20250609180306.png]]

![[Pasted image 20250609180354.png]]

### Bellman ford
https://www.youtube.com/watch?v=obWXjtg0L64

Iterate from left to right
![[Pasted image 20250609181750.png]]


![[Pasted image 20250609181837.png]]

### Djikstra
https://www.youtube.com/watch?v=_lHSawdgXpI

Choose smallest for next
![[Pasted image 20250609182230.png]]


# Presentation layer
![[Pasted image 20250609182612.png]]
![[Pasted image 20250609182630.png]]
![[Pasted image 20250609182712.png]]
![[Pasted image 20250609182742.png]]


![[Pasted image 20250609182834.png]]
![[Pasted image 20250609182912.png]]
![[Pasted image 20250609182944.png]]
![[Pasted image 20250609183046.png]]

![[Pasted image 20250609183219.png]]


### UTF TO UNICODE
![[Pasted image 20250609183528.png]]

### UNICODE TO UTF8
![[Pasted image 20250609183642.png]]


# Transport Layer
![[Pasted image 20250609193443.png]]

buffer only not good
may fill up
![[Pasted image 20250609193607.png]]

## TCP
![[Pasted image 20250609194109.png]]

![[Pasted image 20250609194726.png]]
![[Pasted image 20250609194809.png]]

![[Pasted image 20250609200057.png]]
![[Pasted image 20250609200107.png]]
![[Pasted image 20250609200114.png]]
![[Pasted image 20250609200121.png]]
![[Pasted image 20250609200129.png]]
![[Pasted image 20250609200137.png]]
![[Pasted image 20250609200208.png]]
![[Pasted image 20250609200146.png]]


![[Pasted image 20250609194834.png]]
![[Pasted image 20250609194843.png]]
![[Pasted image 20250609194926.png]]


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

# Network layer (routing 3)

![[Pasted image 20250609200642.png]]
![[Pasted image 20250609200723.png]]
![[Pasted image 20250609200807.png]]

NETWORK - HOST
![[Pasted image 20250609200927.png]]
 📡 **Network Portion**
- Identifies the **specific network** the IP address belongs to.
- All devices on the same network share this portion.
- Used by routers to forward data to the correct destination network.
💻 **Host Portion**
- Identifies the **specific device** (host) on that network.
- Must be unique within that network.
- Used within the network to deliver data to the correct device.
![[Pasted image 20250609201416.png]]

Yes. The class (or subnet size) depends on:
- **How many devices (hosts)** you need per network.    
- **How many separate networks** you require.

- **Small business?** Use Class C or /24 ranges (private: `192.168.x.x`).
- **Large enterprise?** Might need Class B or custom CIDR (like `/20`).
- **Huge ISP or data center?** Historically needed Class A (now done with CIDR).
➡️ Today, classless addressing (CIDR) gives more flexibility than classful addressing.

![[Pasted image 20250609202035.png]]

![[Pasted image 20250609203007.png]]
TAKE 11 BITS FROM HOST SECTION


![[Pasted image 20250609203107.png]]

![[Pasted image 20250609203407.png]]
![[Pasted image 20250609203420.png]]

![[Pasted image 20250609203547.png]]


![[Pasted image 20250609204129.png]]
![[Pasted image 20250609204550.png]]
![[Pasted image 20250609204607.png]]


![[Pasted image 20250609204641.png]]

![[Pasted image 20250609204748.png]]

![[Pasted image 20250609204803.png]]

![[Pasted image 20250609204818.png]]

![[Pasted image 20250609204835.png]]


![[Pasted image 20250609204904.png]]
![[Pasted image 20250609204918.png]]
![[Pasted image 20250609204929.png]]
![[Pasted image 20250609204940.png]]
![[Pasted image 20250609205002.png]]

# Data Link layer
![[Pasted image 20250609205042.png]]
![[Pasted image 20250609205101.png]]
![[Pasted image 20250609205150.png]]
![[Pasted image 20250609205225.png]]
![[Pasted image 20250609205258.png]]
![[Pasted image 20250609205324.png]]
![[Pasted image 20250609205357.png]]


# Physical layer
![[Pasted image 20250609205429.png]]


