# **Subnetting**
![[Pasted image 20250602132003.png]]
![[Pasted image 20250602132107.png]]

3 networks
![[Pasted image 20250602132153.png]]
take 4 but only use 3 of them

4 subnets
each subnet will have 64 host ids (with 2 special host ids, 0 and 255)

![[Pasted image 20250602132438.png]]

# NAT
**Initially** 
- Get a block of unique ip addresses
- Each computer then get's an address 
- Default gateway also get's an ip
- IP address of ISP get's assigned to wan side of gateway 
- Each computer is then told the gateways address 
- All ip addresses are public addresses in this scenario

This is not secure, we can enumerate and discover computers on the private network.
IP address exhaustion.

NAT was created to slove this.
Use Private IP add

Router then translates internal private IP address to public IP and vice versa.
NAT
- Improves security (internal private network is hidden)
- 

