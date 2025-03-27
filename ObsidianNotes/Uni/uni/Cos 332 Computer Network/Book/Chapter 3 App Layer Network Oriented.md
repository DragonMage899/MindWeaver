

# DNS
- South Aftica ccTLD controlled by ZADNA
- Second level administrators assigned by zadna
	- determines who has .co.za endings
- sTLD managed by party who registered

ZADNA: National registry
UniForum/ZARC: co.za Registry


DNS Authority:
- IANA (int assigned number auth)
- operated by ICANN (int cord for assigned names and numbers)

whois www.example.com

Manual look up
- Start at IANA
- Look for manager of tld (given as a url)
- Then traverse and hop until found

## Name servers
- DNS can be explained through how one would go about putting information in the dns and how one would retrieve the information


**Putting info in**
DNS is a tree that uses pointers to link parent nodes to child nodes.
A zone file is used to structure data at each point.

**Zone File**
- Set of triples
	- Name of a host/subdomain
	- Record Type indicator (A, NS)
		- A -> Name of a computer
		- NS -> Name server
	- Address that corresponds to name (of computer / name server)
Zone file fo xx.co.za
![[Pasted image 20250326194058.png]]

Names get resolved to addresses (name resolution)

suppose:
merlin.table.xx.co.za

Ask name server for xx.co.za where to find name server for tabel.co.za
ow would query 10.1.1.4 for the location of merlin

Web based applications typically send DNS requests to resolve names.

### nslookup
nslookup can also be used for cli querying
![[Pasted image 20250326194649.png]]
This is a recursive resolution
We ask the name server to resolve the address from root right till the pc

Iterative resolution 
Name server will refer us to another name server

ISP server becomes a client to various other name server to answer recursive queries

For iterative a starting point is needed
13 root name servers
- Contain information for name servers of TLD's only
- a.root-servers.net
- ...
- m.root-servers.net

Resolving www.example.com iteritively

nslookup
server 192.5.5.241 (change default name server)
set type=ns (want a pointer to a ns to be returned, not an address associated with domain)
com. (query for FQDN com would be a relative lookup, does not apply here)
{Returns a list of name servers followed by addresses}
![[Pasted image 20250326200054.png]]
...
set server 192.5.6.30
set type=ns (still interested in pointers)
example.com
![[Pasted image 20250326200338.png]]
(Should now have the name server for example.com)
server 192.0.34.43
set type=a
www.example.com
![[Pasted image 20250326200506.png]]
Now have the address of the actual computer!

### More on zone files
txt file
Example:
![[Pasted image 20250326200632.png]]
- The zone file should be in a server that will server information to those that request it
- Other Servers need to point to it

Can have it set up at some intermediary server.
i.e.) zone file saved at: dns.example.com

Challenge this getting it into co.za:
xx IN NS dns.example.com

![[Pasted image 20250326201151.png]]

![[Pasted image 20250326201236.png]]
SOA: start if Authority
![[Pasted image 20250326201335.png]]

primary -> secondary copy is called zone transfer

![[Pasted image 20250326201824.png]]
![[Pasted image 20250326201913.png]]
![[Pasted image 20250326201942.png]]

![[Pasted image 20250326202045.png]]
![[Pasted image 20250326202135.png]]
![[Pasted image 20250326202200.png]]
![[Pasted image 20250326202425.png]]

![[Pasted image 20250326202555.png]]
![[Pasted image 20250326202621.png]]
![[Pasted image 20250326202653.png]]
# Bootstrapping Protocols
![[Pasted image 20250326202814.png]]

# Network Management
redundant network access

**Managing Networks**
- Some that collects data and executes actions at each node
- Central management node
- event driven arch

## SNMP
![[Pasted image 20250326203616.png]]

## CMIP
![[Pasted image 20250326203707.png]]


# Directory access protocols

## X.500
![[Pasted image 20250326204001.png]]

## X.509
![[Pasted image 20250326204133.png]]
![[Pasted image 20250326204302.png]]


## LDAP
![[Pasted image 20250326204328.png]]


# Gateway protocols
![[Pasted image 20250326204736.png]]
![[Pasted image 20250326204842.png]]
![[Pasted image 20250326204919.png]]
![[Pasted image 20250326204935.png]]

![[Pasted image 20250326205049.png]]

## RIP
![[Pasted image 20250326205111.png]]
![[Pasted image 20250326205233.png]]
![[Pasted image 20250326205251.png]]

## OSPF
![[Pasted image 20250326205410.png]]
![[Pasted image 20250326205505.png]]
