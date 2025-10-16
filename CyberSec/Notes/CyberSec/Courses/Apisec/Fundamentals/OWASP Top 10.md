![[Pasted image 20250714153639.png]]

# 1: Broken Object level Authorisation
After authenticating as user A, Can we retrieve and edit the record of user B.
Note: user can refer to anything connection to the api such as a server or a car.

Bleeding of data across entities.

![[Pasted image 20250715114919.png]]


# 2: Broken Authentication
Account take over risks, data theft, unauthorised transactions.
Caused by anything that could cause an attacker to easily impersonate another user.

![[Pasted image 20250715115020.png]]

# 3: Broken Object Property Level Authorization
Manipulation of data and objects through an endpoint.
Revealing unnecessary data. 

![[Pasted image 20250715120000.png]]

# 4: Unrestricted Resource Consumption
API's are designed for machine to machine transactions, typically high volume transactions. 
Lack of monitoring and management to resources.

![[Pasted image 20250715120330.png]]

# 5: Broken Function Level Authorization
Abuse of api to improperly modify objects (create, update, delete)
Endpoints that are made available for these purposes should not be accessible by regular users

![[Pasted image 20250715120621.png]]


# 6: Unrestricted Access to Sensitive Business Flows
Abuse of a legitimate business workflow.
Application logic flaw.

![[Pasted image 20250715120945.png]]


# 7: Server Side Request Forgery SSRF
Accepting urls as input.
If the attacker can control this, they can pass in malicious links.
Can also pass in a link to the api itself to get restricted data such as
localhost/api/private
where the local host is running an internal api as well

![[Pasted image 20250715121406.png]]


# 8: Security Misconfiguration
Normally Vulnerabilities that's bots or scanners are looking for, e.g. outdated services, missing patchers, unnecessary features enabled (telnet), Missing CORS policies


![[Pasted image 20250715121723.png]]

# 9: Improper Inventory Management
Maintaining old vulnerable api's, not documenting things properly, hidden endpoints.
Not being fully aware of the api you're running 

![[Pasted image 20250715121932.png]]

# 10: Unsafe Consumption
Risk when using third party api's

Example: Using a external api to validate addresses. 
An attacker could change their address on that third party so that it returns `drop database`



![[Pasted image 20250715122623.png]]
