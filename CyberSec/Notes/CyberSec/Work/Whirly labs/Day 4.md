Safety cli
Java packages
with past vulnerabilities
scraped sources but not accurate 

CVE website
Affects version x.a -> x.b
But often inaccurate 
Then other sources copy this 

Download historial jar files
Use joern to write a query
Detect vulnerability across versions 
Ask diff java packages if it has that particular code 

Difficult part
Go from CVE to query
Needs validation
test for known positives and false positives

Not looking for a joern query for a type of vuln
writing a joern function for a very specific case 
test actual function 


Iterate over a range and actual versions 


---
HW

## Deserialisation 
https://www.cve.org/CVERecord?id=CVE-2025-31129

cvss
https://www.first.org/cvss/calculator/3-0

cve can sometimes be a false fix
a simple exploit adjustment to the exploit may lead to the exploit working again 

It's hard to manage software at scale, just knowing what's in your network is a problem

cve vs cwe
cve - specific bug in a specific function
cwe - classes of vulnerability 

In java
.readObject();
Take a stream of bytes and try to construct an object. 
Always evaluate. 

![[Pasted image 20250612120659.png]]

Cast to java swing only happens after casting object 
This allows deserialisation of any class on a class path
conversion only happens after 

For further look at:
https://github.com/frohoff/ysoserial
If we have files on a class path we can chain to get arbitrary file upload 

Also
https://whirlylabs.com/pdf/bsides2023.pdf


vuln
https://github.com/jooby-project/jooby/commit/3e13562cf36d7407813eae464e0f4b598de15692
security: pac4j can cause deserialization of untrusted data

Prevent external 

We know they removed .readObject()); in strToObject
But does this properly fix the bug

let's inspect the new 
'Optional.of(serializer.deserializeFromString'
found in
![[Pasted image 20250612123104.png]]

different library
found at pc4j.core.util.serializer

![[Pasted image 20250612123441.png]]



![[Pasted image 20250612123441.png]]

just an interface 

back to file 
![[Pasted image 20250612123702.png]]

Trying to see where the context is set 
check relationship with serializer 
![[Pasted image 20250612123832.png]]

![[Pasted image 20250612123913.png]]

following this rabbit hole
we end up in 
https://www.pac4j.org/docs/web-context.html
![[Pasted image 20250612124248.png]]

We'll have to dig into serializer to make sure it's actually safe 


The devs might not know what that means 






---
Side
pom xml -> dependence 

pipe into file
![[Pasted image 20250612124034.png]]



