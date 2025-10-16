# Testing for log4j

In any of the functions,
auto reference variable.
We have some basic syntax:
![[Pasted image 20250610110636.png]]
![[Pasted image 20250610110654.png]]


If the attacker can specify the string, It allows the attacker to specify their own plugins.

Not a programming flaw, it exposes some functionality that allowed attackers to explore the available plugins. 
If the jndi plugin is present 
- Uses for fetching and loading java byte code from some remote location (with ldap support)
- Allow us to load whatever class we want 

![[Pasted image 20250610110928.png]]

Create a class that when loaded executes out code.

LDAP
Authentication across services.
Scan internet for ldap servers, cheap way to gain org info.


JNDI
- Uses ldap to get information on users 

![[Pasted image 20250610112237.png]]

Enable by default vs opt in 
- ideally you'd want to fully make sure the functionality is safe
- but people like having extra extra features 

# Source code

patch
https://github.com/apache/logging-log4j2/commit/c77b3cb39312b83b053d23a2158b99ac7de44dd3#diff-271353c1076e53f6893261e4420de27d34588bfd782806b5c66a3465c43b7f51


Add an allowed list

in JndiManager line 209 lookup.
Additional restrictions imposed in lookup function.

Can't reach out to just any ldap server 



## side 
Microsoft security advice

rmi

