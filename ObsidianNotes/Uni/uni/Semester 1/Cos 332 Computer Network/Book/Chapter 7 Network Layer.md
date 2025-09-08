- Routes packers from source node to destination node

IPV4
- Most used network layer protocol
- Unreliable best effort connection-less service 
- datagrams for packets

![[Pasted image 20250516200212.png]]

32 bit boundary

1 bytes per dot
32 bites total

Divided into a network portion and host portion
- Class determines this split 

network-host

Two special hosts:
**All zero's**
network.0.0.0
- The network itself

**All one's**
network.255.255.255
- Broadcast address

Thus a host field of n bits can address:
- 2^n - 2 addresses (since two are reserved)

![[Pasted image 20250516202413.png]]


