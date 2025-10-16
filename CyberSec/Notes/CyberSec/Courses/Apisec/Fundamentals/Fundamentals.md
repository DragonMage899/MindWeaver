# API Security 
API's need to be part of your risk assessment 

API's provide direct access to sensitive data
Often over-permissioned
Vulnerable to logic flaws

API's are a central choke point between the flow of data between the interface and backend 

![[Pasted image 20250714143953.png]]

Challenges
- Security
- Privacy
- Accessibility 

![[Pasted image 20250714144130.png]]

# Real World breaches
![[Pasted image 20250714144649.png]]

#### Coinbase
BOLA owasp 1

Sell crypto did not own 
![[Pasted image 20250714145531.png]]
a

#### USPS
BOLA
Able to access the details of any other user
Authentication but no authorisation

#### Peleton
Bola and Broken Auth #2
No auth at all.
Could access details of any other user.

They secured authentication but forgot authorization 

#### Venmo
Broken Auth #2
Broken Obj Prop auth #3
Unrestricted resource consumption #4

Could call the api directly without auth 
Could pull non anonimized data (filtering happening at ui, not app lvl)
Could ping the server 115k times a day (with rate limiting)


#### Instagram
Bola and Broken Auth

Password reset, 6 digit code passed to API. 
Could be brute forced.
200 per ip.
Did not limit guesses per account.
Simply use proxies. 

#### Bumble
BOLA, Broken auth, Broken Function lvl auth #5

Access account info without auth.
Incremental id's, easy for scrapers 

Also returned distance to match.
Could use three accounts to triangulate exact location of other account

Api provided access to functions such as update, delete etc.
could update free to premium.

#### T-Mobile
Broken Auth
harvested 37 million accounts.

Required platforms to now file breach info with a body.


#### Optus
BOLA, Broken obj prop, Unrestricted res

Harvested data. 
Ransomed

#### Experian - credit broker
Bola, Broken obj prop, Improper inv management #9

API was meant for financial partners. 
Partner exposed api on site. 

With a name, address.
any credit score and records could be looked up. 


# 3 Pillars

Governance
- Defining, establishing and enforcing production and testing of api's

Testing
- Ensuring API's are free of risks and perform as expected

Monitoring
- Runtime monitoring to ensure they're behaving as expected.

#### Governance
Consistency in how the api's are developed and deployed.
Guidelines and Standard processes for developers.
Enforcing Security.

Knowing your api's
Full inventory, documentation, standardisation of deployment, development guidelines.

![[Pasted image 20250715123843.png]]
![[Pasted image 20250715124044.png]]

#### Testing 
Want to find vulnerabilities and logic flaws at development.

![[Pasted image 20250715124300.png]]

![[Pasted image 20250715124657.png]]

#### Monitoring 
![[Pasted image 20250715124759.png]]
![[Pasted image 20250715124929.png]]
![[Pasted image 20250715125021.png]]
![[Pasted image 20250715125110.png]]

### Tech Landscape
![[Pasted image 20250715125456.png]]

![[Pasted image 20250715125533.png]]



### Conclusion
![[Pasted image 20250715125950.png]]
