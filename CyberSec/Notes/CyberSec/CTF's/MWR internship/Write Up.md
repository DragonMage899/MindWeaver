
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


![[Pasted image 20250428110029.png]]
![[Pasted image 20250428110037.png]]




![[Pasted image 20250428110406.png]]


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
![[Pasted image 20250428114749.png]]
We have a store front with a Coupon Code!

Let's add the OmniKey to our cart and see what we can do at the checkout page
DISCOUNT10

![[Pasted image 20250428114910.png]]
Seems like we're $80 short even after applying our coupon!
But hold on, looks like we can apply the coupon multiple times, how thoughtful of the developers to consider the state of you wallet.

![[Pasted image 20250428115157.png]]
We can now afford the OmniKey, but hold on I'd like an ice cream aswell
![[Pasted image 20250428115234.png]]
That's a lot better, but we can do a bit better
![[Pasted image 20250428115407.png]]
Unfortunately there doesn't appear to be any other coupon codes after trying a few versions of "DISCOUNT10" such as "DISCOUNT100" does nothing.

Time to checkout
![[Pasted image 20250428115529.png]]
 MWR{One-Key-To-Rule-Them-All}


## Task 12 File upload
We have an avatar upload page!
![[Pasted image 20250428115644.png]]

Let's see how this works:
![[Pasted image 20250428115845.png]]

![[Pasted image 20250428115911.png]]
Looks like the file get's uploaded to a path that we can easily access.

Let's try a different format:
![[Pasted image 20250428121930.png]]

![[Pasted image 20250428121414.png]]
Interesting, this makes it sounds like it's looking for jpg anywhere in the filename and not looking at the file type itself
Let's try renaming our text file to jpg.txt
![[Pasted image 20250428122103.png]]
Our blank text file got uploaded!
Let's try i one more time with text this time:
![[Pasted image 20250428122221.png]]
![[Pasted image 20250428122229.png]]

Right, now let's try to upload a reverse shell
![[Pasted image 20250428123145.png]]
We'll save this as jpg.png and upload it
![[Pasted image 20250428122459.png]]

Before we navigate to the shell let's start listening with netcat
![[Pasted image 20250428123448.png]]

and we've got access to the server
running the id command gives us another flag:
![[Pasted image 20250428123548.png]]
MWR{Ares-Compromised}

## Task 13 Race conditions
Logging in with the details provided drops into a transaction page
![[Pasted image 20250428123818.png]]
We'll make a transaction to account 1 
![[Pasted image 20250428123851.png]]
While we wait for this timer let's investigate the request 
![[Pasted image 20250428123928.png]]
We'll update the admin field for good measure and set up 
We'll now duplicate this to the maximum amount burp suit allows which is 100 we see a current balance of 9,999,750,000.00

Logging back into the transaction page. Seems we'd need to make 39999 transaction to empty the account yikes! We might need to write a python script for this.

First let's make sure the last-byte synchronization attack works with the 100 requests we've made. Let's add them all to a group and start the attack
![[Pasted image 20250428124513.png]]

Let's go back to the transaction and see how much damage we've done:
![[Pasted image 20250428124721.png]]

Thankfully we got the flag without having to completely empty the account

## Root
Our goal is to get root to the mainframe (I'm finally hacking a mainframe!)
First of let's go over what we know and have

Let's have another look at the open ports
![[Pasted image 20250415192920.png]]
There's nothing that stands out here. 
We there's a user called garcher from Task 9
We have a reverse through our reverse shell
We'll upload a few more reverse shells with different ports so that we can explore the scan while some scans run the background.

![[Pasted image 20250428133110.png]]
Let's try to gain access to the root folder


First off let's scan a system wide scan for SUID binaries owned by the root.
If we can try one of these we'll get immediate root access:
`find / -perm -4000 2>/dev/null`


While this is running let's start collecting information about the system
![[Pasted image 20250428131143.png]]
![[Pasted image 20250428131214.png]]
![[Pasted image 20250428131251.png]]
![[Pasted image 20250428131310.png]]
![[Pasted image 20250428131348.png]]
![[Pasted image 20250428131406.png]]
![[Pasted image 20250428131606.png]]
![[Pasted image 20250428131637.png]]

That's a bunch of information!
We'll save it all to a text file just in case we lose the terminal

Normally we'd start carefully examining this looking clues but we luckily for us we have super AI companion that can do a quick recon for us and point us in promising directions:

### System Information:

- **OS**: Ubuntu 20.04.6 LTS (Focal Fossa)
- **Kernel**: 5.15.0-117-generic
- **Architecture**: x86_64
- **User**: `www-data`
    - **UID**: 33
    - **Groups**: `www-data`, and **MWR{Ares-Compromised}** (a suspicious/CTF-like group name — may hint at a flag or special permissions)
        

---

### Current Access:
- **Shell**: Low-privilege reverse shell (`www-data` user, typical for web server).
- **Shell limitations**: No terminal job control (`cannot set terminal process group` warning).
- **Environment**: Default Apache environment variables present.
    

---

### Cron Jobs:
- `/etc/crontab` shows only standard system-wide crons (running system jobs via `run-parts`), **no obvious custom cron jobs** for escalation.
- Important to note: you may need to check inside `/etc/cron.{hourly,daily,weekly,monthly}` directories for hidden escalation vectors.
    

---

### Processes:
- Only **root** system processes observed.
- No strange, custom, or user processes yet (though your output got cut off — might need to scroll further).
- Apache (`www-data`) server must be running, but it wasn't listed yet in what you pasted — would be good to confirm the Apache process to know the parent PID.

---

### Potential Escalation Leads:

1. **Special Group: `MWR{Ares-Compromised}`**
    - Being in a **non-standard group** is **very suspicious**.
    - This group might have special file or sudo permissions.
    - Enumerate group-owned files (`find / -group MWR{Ares-Compromised} 2>/dev/null`) — may find writable files, scripts, or binaries.
        
2. **Writable Directories**
    - You landed in `/var/www/html/TASK12/uploads` — a typical web upload directory.
    - Check for **writable directories or files** system-wide or related to Apache that could be abused.
    
3. **SUID/SGID binaries**
    - Standard for privilege escalation to check if there are custom or vulnerable SUID binaries
    - Run:    find / -perm -4000 -type f 2>/dev/null

4. **Weak permissions or misconfigurations**

    Apache running as www-data may have access to configuration files, backups, or logs.
    Check /var/www, /var/backups, and /etc/apache2 for misconfigurations or sensitive credentials.

There doesn't appear to be any standouts.
Let's have a look at the result of our suid scan, we can once again use our trusty ai to examine the output and look for vulnerable binaries 
![[Pasted image 20250428132245.png]]
![[Pasted image 20250428132304.png]]
But hold on.
We have something very interesting over here!
Looks like we have a custom user binary with an ominous name 
![[Pasted image 20250428132319.png]]
Let's explore a bit further 
![[Pasted image 20250428132555.png]]
Looks like we need a password
![[Pasted image 20250428132645.png]]

I suppose that would've been a bit too easy

Let's run the binary through strings and see what we get
![[Pasted image 20250428132823.png]]
Looks like we have a c++ program, let's dig a bit more
![[Pasted image 20250428132852.png]]
This appears to spawn a shell with possible root access and luckily for us it looks like the password has not been obscured

And there we have it!
![[Pasted image 20250428133223.png]]

With the help of the architect ares has been defeated and MWR has saved the day!
