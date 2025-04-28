
# Challenges

Intro Section
Name
Description

## Task 2 Scanning
![[Pasted image 20250415192920.png]]

## Task 3 Steganography
Challenge category: steganography

Dropping into the challenge page we're greeted with a cool looking web page:
![[Pasted image 20250426142432.png]]
The challenge description points us to inspecting the source code:
Right at the top we see a comment left by a __ 
![[Pasted image 20250426142728.png]]

Following this puts us into a directory listing:
![[Pasted image 20250426143254.png]]
This tells us that the server allows for directory browsing which is normally a security concern and thus typically disabled, perhaps this was intentionally left on by the The Architect

In this directory we see 4 images, downloading these might lead to a clue so let's go 

Let's examine each file with exiftool
![[Pasted image 20250427232256.png]]
And hidden in metadata of mtEverest3.jpg we find a kill switch!
We're one step closer to stopping ares

## Task 4 Crypto
The first two encryption require a simple decode in cyber chef
![[Pasted image 20250427232720.png]]
![[Pasted image 20250427232744.png]]

First inspection of the the third cipher smells of base64, let's see where that puts us 
![[Pasted image 20250427232926.png]]
Well that's clearly a flag format but it seems to have been encrypted. 
![[Pasted image 20250427233005.png]]
Applying Both decryption reveals another flag with a hint that could be useful later on, it appears that ares has a kill switch somewhere. 
## Task 5 Dir brute force
Entering the challenge page we see the following:
![[Pasted image 20250427233646.png]]
It seems we need to dive into a rabbit hole to solve this challenge. Let's begin doing a directory scan of with gobuster on http://10.10.34.10/TASK5/Challenge/
And now for everyone's favourite moment... waiting for the scan to finish
![[Pasted image 20250427234018.png]]
Since the site quite unresponsive during the scan now would be the perfect time to grab some more coffee. 
![[Pasted image 20250427234047.png]]
Seems there's nothing more to see, let's scan the Challenge now


It seems we have our first hit after just one second!
![[Pasted image 20250427234646.png]]
Let's leave the scan to continue and see where admin takes us

![[Pasted image 20250427234858.png]]
It seems that the we don't have access to this page.
We've also gained some new information "apache 2.4.41"
Googling "apache 2.4.41 cve"
We see the following exploit:
![[Pasted image 20250427235148.png]]
We'll keep this in mind and keep exploring 
https://www.rapid7.com/blog/post/2021/10/06/apache-http-server-cve-2021-41773-exploited-in-the-wild/


Let's try to gain access to this page using burp suit.
![[Pasted image 20250427235531.png]]
Well that would've been too easy since there's no sort of authorisation header to play with let's continue to try common usernames and passwords until the scan finishes.

And no luck
![[Pasted image 20250427235856.png]]

Scanning has been working well thus far so let's continue with that.
While the directory scan of admin goes on let's go look at that Apache vulnerability.
Following this link from the article get's us to heart of the exploit:
https://attackerkb.com/topics/1RltOPCYqE/cve-2021-41773/rapid7-analysis?referrer=blog
It seems that using `/.%2e/` which translates to `../` (moving p one directory) allows us to access directories we're not meant to be able to access as 

`<Directory />`
    `Require all denied`
`</Directory>`
Is not set in the serves config file.

Looks like our scan got another hit!
along with a lot of errors...
![[Pasted image 20250428000437.png]]
Seems like the server does not appreciate our excessive poking.
Let's do another scan of /admin while we investigate /vault

![[Pasted image 20250428000935.png]]
Well we're still not allowed in, let's try that apache exploit:
![[Pasted image 20250428001038.png]]
![[Pasted image 20250428001055.png]]
Seems like there's nothing there, since we have a directory challenge later on let's drop this attack avenue for now and try more username and passwords while we wait for the scan to finish

![[Pasted image 20250428002053.png]]
Nothing new, but better safe than sorry. Let's scan the vault url. While that goes let's grab another cup of coffee 

![[Pasted image 20250428002858.png]]

Seems we've reached the ends of our directory search. 

It's time to start searching for files

We will now make the dangerous assumption that the flag is stored in a .txt file and hopefully not waste 3 hours 

Trying flag.txt, robots.txt, killswitch.txt, rabbit.txt, whiterabbit.txt, rabbithole.txt on /admin and /admin/vault doesn't lead anywhere

Let's start looking for files now using word lists from:
https://github.com/danielmiessler/SecLists/Discovery/Web-Content/

Let's start off with quick hits
![[Pasted image 20250428004311.png]]

We have some output but nothing particularly useful. Let's move on to common

I'll now start scanning use my custom version of big.txt where each word as .txt appended to it 

We have a hit!
and it's a code 200. It seems like someone left hidden file in the admin vault 
![[Pasted image 20250428004854.png]]

![[Pasted image 20250428005204.png]]
We have another killswitch flag!
## Task 6 Hash cracking
Navigating to challenge we greeted with a message from the architect
![[Pasted image 20250428005503.png]]
Along with the word Ares in mandarin.
Clicking the button downloads a zip file. 
If we try to unzip this file we're asked for a password.
Opening the zip with ark reveals a killswitch.txt
![[Pasted image 20250428005812.png]]


Let's see if we can see how this zip is being protected:
![[Pasted image 20250428010727.png]]

Doesn't reveal much, let's move onto john, we can use zip2john to extract the zip hash if it has one:

![[Pasted image 20250428010915.png]]

Let's save this to a text file and try to get the password using the rockyou.txt password list:
![[Pasted image 20250428011448.png]]
And we have a hit
'diablo'
![[Pasted image 20250428011544.png]]
Boom, another flag!
MWR{Hacking-And-Cracking-Your-Way}
## Task 7 SQL
Challenge, We have a log in form!
Let's hope the developers weren't too trusting of user input.
It. Following the walk through 

Username:
```sql
' OR 1=1 -- -
```
Password: a
![[Pasted image 20250428012630.png]]

Reveals the flag, sweet and easy!
MWR{No-Injections-Please}
## Task 8 Union SQL
Right looks like we have a union injection challenge!
![[Pasted image 20250428012936.png]]
We have a drop down menu
![[Pasted image 20250428013116.png]]
With a suspicious quoted value

![[Pasted image 20250428013237.png]]

Selecting a value fills the table, we also notice that we have a php file with a query string. Let's move over to burp suit and start playing around 

![[Pasted image 20250428104552.png]]
Seems like using + in the query string to represent a space, we know have enough to start manipulating the query

First step is figure out how many columns are being returned by the projection
![[Pasted image 20250428105633.png]]
![[Pasted image 20250428105820.png]]
We have an answer the projection is returning 5 columns

Not let's try a union Select
![[Pasted image 20250428110029.png]]
![[Pasted image 20250428110037.png]]
Perfect we can use the union select the populate the table!

Let's try to get the sql engine, the write up mentions sql lite so that would be a good starting point.

![[Pasted image 20250428110406.png]]
The first field doesn't seem to help us, let's try the next one

![[Pasted image 20250428110450.png]]
And there we go!

Not let's grab some information from the sqlite_master table
![[Pasted image 20250428110734.png]]
![[Pasted image 20250428110745.png]]

We have a fl4gged_events table, not only does it have the word it's also obscured, we're onto something!

Let's see what this table holds
![[Pasted image 20250428111113.png]]
We'll set id=1 and extract the timestamp and activity columns.
![[Pasted image 20250428111153.png]]
Nothing here, let's continue iterating until we run of rows

![[Pasted image 20250428111223.png]]
![[Pasted image 20250428111238.png]]
![[Pasted image 20250428111324.png]]
And there we have it. Ares will be going down soon


## Task 9 Dir Traversal
The architect has once again provided assistance, it seems he's left us a way to retrieve files we shouldn't have access to
![[Pasted image 20250428111450.png]]
First let's try to grab the index.html of the current page to make sure we understand how it works
![[Pasted image 20250428112926.png]]
![[Pasted image 20250428112952.png]]
Looks like we're grabbing from the cores folder in the current directory.
Let's try moving up one directory
"?page=../index.html"
![[Pasted image 20250428113054.png]]
Seems it has the ability to detect directory escapes.
Let's try the exploit we discovered in Task 5
`?page=.%2e/index.html`
![[Pasted image 20250428113301.png]]
Looks like that's been secured

Time to consult port swigger. 
Let's give this a try
https://portswigger.net/web-security/file-path-traversal
![[Pasted image 20250428112447.png]]

![[Pasted image 20250428113402.png]]
There we go!
To make sure we're on the right let's move up more directories until we find the inde.html for the home page
`?page=....//....//....//index.html`
![[Pasted image 20250428113607.png]]

Perfect! we can now start looking for the /opt/killswitch.txt
![[Pasted image 20250428113650.png]]
There we go!
`?page=....//....//....//....//....//....//opt/killswitch.txt`
MWR{Reading-The-Mountain}


## Task 10 Auth Bypass
![[Pasted image 20250428114141.png]]
Looks like we have a link to an admin portal which 

Trying to access admin.php we see
![[Pasted image 20250428114217.png]]

Let's inspect the request data and see what we can discover:
![[Pasted image 20250428114252.png]]
Interesting we're setting value for admin in the cookie field
"admin=ZmFsc2U%3D"
That smells of base64 encoding., off to cyber chef 

![[Pasted image 20250428114427.png]]
The cookie seems to be encoding a boolean value, let's replace it with the base64 value for true and see if that works
![[Pasted image 20250428114532.png]]
Replacing the admin cookie with `dHJ1ZQ==`
![[Pasted image 20250428114616.png]]
Turns us into an admin!
Another kill switch flag, we're one step close to shutting down ares



## Task 11 Logic flaws

## Task 12 File upload

## Task 13 Race conditions

## Root


# Vulnerability Report
