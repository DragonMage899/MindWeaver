50% test marks will be multiple choice

**root servers**
- 20 servers which we know the addresses of
- os comes built in with list

To resolve: cs.up.ac.za (root -> top level 0-> second level -> auth? -> serving computer)
- Go to root (point to top level)
- Ask for a Name Server (NS) where we can resolve za
	- za (extension to sub? domain)
	- za. (absolute / explicit)
	- za. -> ask the za server consortium (might be ZARC,probably) whois
		- Where can we find ac in the domain name server
		- We'll get some NS that can answer questions about up.ac.za
		- That will also respond with a NS that that can answer any question about the domain (actual host server)
			- Now ask it about "cs.", probably another computer

root server zone file
- entries:
- com. IN NS 10.1.1.1
	- expect to find an entry like this in the zone file
- com. IN NS 192.168.1.1
	- example form of what we expect
- net. IN NS 172.16.1.1
Note: can't actually resolve to the actual server (for root)
Will tell us where to go look for a second level domain
- Specialized structure typically followed
 
ISP can provide a default name server
- answers questions about any ip

**Recursive**: Do a name query, if something needs to be answered it will do the second part if needed, third part if needed etc...

root servers don't do recursive
default name servers can 


3 Well known public name servers (anyone can use)
- 8.8.8.8 (dns.google)
- 8.8.4.4 (googles 2nd machine, dns.google)
- 1.1.1.1 (one.one.one.one)

---

 nslookup
> server a.root-servers.net
Default server: a.root-servers.net
Address: 198.41.0.4#53
Default server: a.root-servers.net
Address: 2001:503:ba3e::2:30#53
> set type=ns
> com.
;; Truncated, retrying in TCP mode.
Server:         a.root-servers.net
Address:        198.41.0.4#53

Non-authoritative answer:
*** Can't find com.: No answer

Authoritative answers can be found from:
com     nameserver = l.gtld-servers.net.
com     nameserver = j.gtld-servers.net.
com     nameserver = h.gtld-servers.net.
com     nameserver = d.gtld-servers.net.
com     nameserver = b.gtld-servers.net.
com     nameserver = f.gtld-servers.net.
com     nameserver = k.gtld-servers.net.
com     nameserver = m.gtld-servers.net.
com     nameserver = i.gtld-servers.net.
com     nameserver = g.gtld-servers.net.
com     nameserver = a.gtld-servers.net.
com     nameserver = c.gtld-servers.net.
com     nameserver = e.gtld-servers.net.
l.gtld-servers.net      internet address = 192.41.162.30
l.gtld-servers.net      has AAAA address 2001:500:d937::30
j.gtld-servers.net      internet address = 192.48.79.30
j.gtld-servers.net      has AAAA address 2001:502:7094::30
h.gtld-servers.net      internet address = 192.54.112.30
h.gtld-servers.net      has AAAA address 2001:502:8cc::30
d.gtld-servers.net      internet address = 192.31.80.30
d.gtld-servers.net      has AAAA address 2001:500:856e::30
b.gtld-servers.net      internet address = 192.33.14.30
b.gtld-servers.net      has AAAA address 2001:503:231d::2:30
f.gtld-servers.net      internet address = 192.35.51.30
f.gtld-servers.net      has AAAA address 2001:503:d414::30
k.gtld-servers.net      internet address = 192.52.178.30
k.gtld-servers.net      has AAAA address 2001:503:d2d::30
m.gtld-servers.net      internet address = 192.55.83.30
m.gtld-servers.net      has AAAA address 2001:501:b1f9::30
i.gtld-servers.net      internet address = 192.43.172.30
i.gtld-servers.net      has AAAA address 2001:503:39c1::30
g.gtld-servers.net      internet address = 192.42.93.30
g.gtld-servers.net      has AAAA address 2001:503:eea3::30
a.gtld-servers.net      internet address = 192.5.6.30
a.gtld-servers.net      has AAAA address 2001:503:a83e::2:30
c.gtld-servers.net      internet address = 192.26.92.30
c.gtld-servers.net      has AAAA address 2001:503:83eb::30
e.gtld-servers.net      internet address = 192.12.94.30
e.gtld-servers.net      has AAAA address 2001:502:1ca1::30
> com
Server:         a.root-servers.net
Address:        198.41.0.4#53

Non-authoritative answer:
*** Can't find com: No answer

Authoritative answers can be found from:
za      nameserver = nsza.is.co.za.
za      nameserver = za1.dnsnode.net.
za      nameserver = za-ns.anycast.pch.net.
nsza.is.co.za   internet address = 196.4.160.27
za1.dnsnode.net internet address = 194.146.106.78
za1.dnsnode.net has AAAA address 2001:67c:1010:19::53
za-ns.anycast.pch.net   internet address = 204.61.216.55
za-ns.anycast.pch.net   has AAAA address 2001:500:14:6055:ad::1
> za
Server:         a.root-servers.net
Address:        198.41.0.4#53

Non-authoritative answer:
*** Can't find za: No answer

Authoritative answers can be found from:
za      nameserver = nsza.is.co.za.
za      nameserver = za1.dnsnode.net.
za      nameserver = za-ns.anycast.pch.net.
nsza.is.co.za   internet address = 196.4.160.27
za1.dnsnode.net internet address = 194.146.106.78
za1.dnsnode.net has AAAA address 2001:67c:1010:19::53
za-ns.anycast.pch.net   internet address = 204.61.216.55
za-ns.anycast.pch.net   has AAAA address 2001:500:14:6055:ad::1

---
nslookup
> server 8.8.8.8
Default server: 8.8.8.8
Address: 8.8.8.8#53
> set type=ns
> za
Server:         8.8.8.8
Address:        8.8.8.8#53

Non-authoritative answer:
*** Can't find za: No answer

Authoritative answers can be found from:
up.ac.za
        origin = ns2.up.ac.za
        mail addr = dnsadmin.up.ac.za
        serial = 4071973021
        refresh = 10800
        retry = 3600
        expire = 1728000
        minimum = 900
> za.
Server:         8.8.8.8
Address:        8.8.8.8#53

Non-authoritative answer:
za      nameserver = nsza.is.co.za.
za      nameserver = za-ns.anycast.pch.net.
za      nameserver = za1.dnsnode.net.

Authoritative answers can be found from:

---
> za.
Server:         8.8.8.8
Address:        8.8.8.8#53

Non-authoritative answer:
za      nameserver = nsza.is.co.za.
za      nameserver = za-ns.anycast.pch.net.
za      nameserver = za1.dnsnode.net.

Authoritative answers can be found from:
> set type=a
> nsza.is.co.za
Server:         8.8.8.8
Address:        8.8.8.8#53

Non-authoritative answer:
Name:   nsza.is.co.za
Address: 196.4.160.27

---
> set type=a
> nsza.is.co.za
Server:         8.8.8.8
Address:        8.8.8.8#53

Non-authoritative answer:
Name:   nsza.is.co.za
Address: 196.4.160.27
> server 196.4.160.27
Default server: 196.4.160.27
Address: 196.4.160.27#53
> set type=ns
> ac.za
Server:         196.4.160.27
Address:        196.4.160.27#53

Non-authoritative answer:
*** Can't find ac.za: No answer

Authoritative answers can be found from:
ac.za   nameserver = ns4.dns.business.
ac.za   nameserver = za-ns.anycast.pch.net.
ac.za   nameserver = ns3.dns.business.
ac.za   nameserver = disa.tenet.ac.za.
ac.za   nameserver = ns2us.dns.business.
disa.tenet.ac.za        internet address = 196.21.79.50
disa.tenet.ac.za        has AAAA address 2001:4200:ffff:a::1

---
disa.tenet.ac.za        has AAAA address 2001:4200:ffff:a::1
> set type=a
> disa.tenet.ac.za
Server:         196.4.160.27
Address:        196.4.160.27#53

Non-authoritative answer:
*** Can't find disa.tenet.ac.za: No answer
> server 196.4.160.27
Default server: 196.4.160.27
Address: 196.4.160.27#53
> set type=ns
> up.ac.za
Server:         196.4.160.27
Address:        196.4.160.27#53

Non-authoritative answer:
*** Can't find up.ac.za: No answer

Authoritative answers can be found from:
ac.za   nameserver = ns3.dns.business.
ac.za   nameserver = za-ns.anycast.pch.net.
ac.za   nameserver = disa.tenet.ac.za.
ac.za   nameserver = ns2us.dns.business.
ac.za   nameserver = ns4.dns.business.
disa.tenet.ac.za        internet address = 196.21.79.50

---
> server 137.215.98.24
Default server: 137.215.98.24
Address: 137.215.98.24#53
> set type=a
> cs.up.ac.za
;; communications error to 137.215.98.24#53: connection refused
;; communications error to 137.215.98.24#53: connection refused
;; communications error to 137.215.98.24#53: connection refused
;; no servers could be reached
> server 137.215.98.140
Default server: 137.215.98.140
Address: 137.215.98.140#53
> set type=a
> cs.up.ac.za
Server:         137.215.98.140
Address:        137.215.98.140#53

Name:   cs.up.ac.za
Address: 137.215.98.24

---
> set type=ns
> one.one.one.one
Server:         ns1.up.ac.za
Address:        137.215.98.140#53

Non-authoritative answer:
*** Can't find one.one.one.one: No answer

Authoritative answers can be found from:
one.one.one
        origin = dorthy.ns.cloudflare.com
        mail addr = dns.cloudflare.com
        serial = 2365643000
        refresh = 10000
        retry = 2400
        expire = 604800
        minimum = 1800
>
---

Above was iterative query, we had to work.
asking default server would immediately resolve to last line

default serves can cache commonly used sites to limit iteration

> server ns1.up.ac.za
Default server: ns1.up.ac.za
Address: 137.215.98.140#53
> 8.8.8.8
8.8.8.8.in-addr.arpa    name = dns.google.

Authoritative answers can be found from:
> 1.1.1.1
1.1.1.1.in-addr.arpa    name = one.one.one.one.

Authoritative answers can be found from: