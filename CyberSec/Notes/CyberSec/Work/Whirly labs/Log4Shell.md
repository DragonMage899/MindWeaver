Vuln in Log4j

Log4j
- Allows us to write logs within Java
- Logs are written to a log file
	- Can configure where the logs are going, such as a logging server 

Allowed us to put messages into the log that get's read from the environment
-> Can put messages that would be interpreted

2013 -> 2021
8 years

Simple to carry out in an attack
Very stable 

![[Pasted image 20250609134052.png]]
java:version get's interpreted and included in the string 

Allowed attackers to contact a server, download a class and execute it 

![[Pasted image 20250609134213.png]]

![[Pasted image 20250609134318.png]]

nvd is not reliable but can work as a good starting point
can also get resources on where to 

build a query to discover the vuln in jorne
hopefully use this aswell to discover vulnerabilities 