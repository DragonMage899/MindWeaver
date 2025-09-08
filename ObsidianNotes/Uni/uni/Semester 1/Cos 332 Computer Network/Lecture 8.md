Name resolution
Resolving a name

Registrar registers domain.

bind
 - server
Zone file
- mapping for a particular organization
- www A 10.1.1.1 (or www IN A 10.1.1.1, IN stands for internet)
- arhur A 10.1.1.2 (Knights roundtable name)
- ftp CNAME arthur (synonym, results to the same address)
- @ MX, 10 mail.google.com
	- @ Any mail for this domain should be sent to google
	- MX- mail exchange, can accept email on our behalf
	- 10- Priorities, the lower  the better
- @ MX,20 mail2.google.com
	- backup
- @ MS 192.168.1.1
- @ MS 192.168.1.2
	- Can resolve domain names within my domain
- CS NS 192.168.3.4
- HOST
	- Allows external servers to provide services for this domain (works as auth as only domain name owner can edit this file)


nslookup
set type=mx

`nslookup`
> `set type=mx`
> `up.ac.za`
`Server:         10.255.255.254`
`Address:        10.255.255.254#53`

`up.ac.za        mail exchanger = 10 alt3.aspmx.l.google.com.`
`up.ac.za        mail exchanger = 5 alt2.aspmx.l.google.com.`
`up.ac.za        mail exchanger = 5 alt1.aspmx.l.google.com.`
`up.ac.za        mail exchanger = 1 aspmx.l.google.com.`
`up.ac.za        mail exchanger = 10 alt4.aspmx.l.google.com.`


> set type=ns
> up.ac.za
Server:         10.255.255.254
Address:        10.255.255.254#53

//MISING IP ADDRESES
up.ac.za        nameserver = ns2.up.ac.za.
up.ac.za        nameserver = ns1.up.ac.za.
up.ac.za        nameserver = ns5.up.ac.za.
up.ac.za        nameserver = ns3.up.ac.za.