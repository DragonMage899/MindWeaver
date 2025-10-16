You will be given two days to complete the challenge and send us your report. All reports must be in our inbox by Friday 3 October 2025 at 14:00 +0200.

Please submit your report in PDF format with your name as the document name. For example: John_Doe.pdf

The report needs to contain a walkthrough to discuss your activities that you conducted with the relevant screenshots. Please include your thinking process on the activities performed.

Your challenge is to progress through the levels on it, while taking screenshots of your progress.

Then you will need to send us a detailed report. Please see Orange Cyberdefense as your customer, so the report needs to be of the highest quality. 

Happy hunting.

# 0 
![[Pasted image 20251001123737.png]]

![[Pasted image 20251001124236.png]]
![[Pasted image 20251001124334.png]]
![[Pasted image 20251001124436.png]]
![[Pasted image 20251001124449.png]]
![[Pasted image 20251001124503.png]]

Answer: ip = 127.0.0.0
# 1
![[Pasted image 20251001124617.png]]
![[Pasted image 20251001124629.png]]
![[Pasted image 20251001124642.png]]
password: The best preparation for tomorrow is doing your best today
# 2
Got kicked
![[Pasted image 20251001164213.png]]

let's start saving the urls in case this happens later on
![[Pasted image 20251001124814.png]]
luckily it's still here

https://challenge.orangecyberdefense.academy/level2_ea40fae0a964be0943b949e0b782ac6d.html

![[Pasted image 20251001125040.png]]

![[Pasted image 20251001125051.png]]

YmFzZV82NF9pc19ub3RfZW5jcnlwdGlvbg==
![[Pasted image 20251001125157.png]]
base_64_is_not_encryption

get it onto our clipboard and proceed:
![[Pasted image 20251001125250.png]]

Password: base_64_is_not_encryption
# 3
https://challenge.orangecyberdefense.academy/level3-base_64_is_not_encryption.html

![[Pasted image 20251001125355.png]]
![[Pasted image 20251001125433.png]]

![[Pasted image 20251001125608.png]]

![[Pasted image 20251001125747.png]]

"String.fromCharCode"
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/fromCharCode

tldr: converts utf-16 ints to their corresponding 
rabbit hole

Adjust the script a bit
![[Pasted image 20251001130544.png]]

![[Pasted image 20251001130828.png]]
The_Obstacle_istheway

![[Pasted image 20251001130840.png]]


Answer: The_Obstacle_istheway
# 4
![[Pasted image 20251001130853.png]]

![[Pasted image 20251001131146.png]]
![[Pasted image 20251001131112.png]]

![[Pasted image 20251001131302.png]]
![[Pasted image 20251001131520.png]]

Simplest solution would be to copy paste this
but that feels like cheating...

but wait, the button was taunting me


![[Pasted image 20251001131839.png]]

![[Pasted image 20251001132018.png]]
![[Pasted image 20251001132142.png]]
Now we can close
![[Pasted image 20251001132201.png]]
and just ignore the redirect

don't tell me I can't close you

![[Pasted image 20251001132258.png]]

and..
![[Pasted image 20251001132525.png]]

where's my challenge completion dialogue?

Right so, I dropped the redirect request, but the page still appears to have ran `location.href = "level4-The_Obstacle_istheway.html"`
It seems 

Let's try a different approach
![[Pasted image 20251001133323.png]]
Breakpoints!
Add a break point to line one 
![[Pasted image 20251001133442.png]]
Now let's inject some of out own code:

```
if (confirm("You can't close me :P")) {
    location.href = "level4-The_Obstacle_istheway.html";
} else {
    location.href = "level4-The_Obstacle_istheway.html";
}
```
examining the source we have a confirm popup
Regardless of what button we click we get redirected 

Thus interacting with the pop up is a cul de sac

Goal: Still to click the button, but make it close!

Let's write a script that does the following:
1. Capture the original confirm window
2. Let it open, but then redefine it's function behaviour 

Let's have a look at the confirm function:
https://developer.mozilla.org/en-US/docs/Web/API/Window/confirm
![[Pasted image 20251001135240.png]]

we'll need to hijack the `confirm(message)` version and reassign it.
To do this we can intercept the return value
![[Pasted image 20251001135443.png]]
and prevent it from returning

```javascript
const ogConfirm = window.confirm;

//hijack behaviour
window.confirm = function(message) {
const retVal = ogConfirm(message);
throw new Error("get rekt button");
};
```
This should in theory prevent the redirect from executing as it never receives a return value, thus the conditional never executes 


Let's give it a try:
![[Pasted image 20251001135730.png]]
Then let's hijack the return and execute our own code:
![[Pasted image 20251001150352.png]]

![[Pasted image 20251001135838.png]]

Now when we click this, it should close
![[Pasted image 20251001135911.png]]


We get redirected to lvl 5

# 5
https://challenge.orangecyberdefense.academy/level5-119df23b44e4b4022c32cef982a98e6e.html
![[Pasted image 20251001135934.png]]


Sudoku,
let's solve it!

![[Pasted image 20251001140301.png]]
After perhaps way too long
![[Pasted image 20251001152351.png]]

int:
5617
4

54617


Now back to the challenge page
examining the source we find this script
![[Pasted image 20251001152444.png]]

```javascript
 encryptedText ="U2FsdGVkX1/18AY487WSY8L3EFFnPS9aLfjaxwTXu+IOlXCHHhGY1aJpOUcv7xAZ"                   
 //console.log('Encrypted Text:', encryptedText);
  
  function decryptMe(mytext,mykey) { 
	  var decr = CryptoJS.AES.decrypt(mytext, mykey);
	  const now = new Date();
          const currentDateTime = now.toLocaleString(); 
	  decr = decr.toString(CryptoJS.enc.Utf8);
	  console.log('Decrypted Text:', decr.toString()); 
	  
		if (md5(decr) == "09193c6d7540cf234372c7458a700d8e") {
		    alert("Well done! Take a screenshot and let's go to the next level. Please remember to add your solution to the Sudoku puzzle in your report. "+currentDateTime + " "+ md5(currentDateTime));   
		    location.href = "level6-" + decr + ".html";
		}
		else {
		    alert("Nope...");
		}
  }
```

We need a key:
let's try 54617
![[Pasted image 20251001153825.png]]
![[Pasted image 20251001153846.png]]

How about 56147?
Nope... right, that would be too easy I guess

Let's throw this into node and try all permutations
After an intense coding session
![[Pasted image 20251001154230.png]]

I got this script:
```javascript
const CryptoJS = require("crypto-js");
const md5 = require("md5");

const encryptedText = "U2FsdGVkX1/18AY487WSY8L3EFFnPS9aLfjaxwTXu+IOlXCHHhGY1aJpOUcv7xAZ";

// Generate all permutations of the string "56147"

function permute(str) {
	if (str.length <= 1) return [str];
	
	const perms = [];
	for (let i = 0; i < str.length; i++) {
		const char = str[i];
		const rest = str.slice(0, i) + str.slice(i + 1);
		
		for (const sub of permute(rest)) {
			perms.push(char + sub);
		}
	}
return perms;
}

function decryptMe(mytext, mykey) {
	try {
		let decr = CryptoJS.AES.decrypt(mytext, mykey);
		decr = decr.toString(CryptoJS.enc.Utf8);
		if (!decr) return false; // invalid key, skip
		
		if (md5(decr) === "09193c6d7540cf234372c7458a700d8e") {
			const now = new Date();
			const currentDateTime = now.toLocaleString();
			console.log("✅ Correct Key:", mykey);
			console.log("Decrypted Text:", decr);
			console.log(
			"Well done! Take a screenshot and let's go to the next level. " +
			currentDateTime +" " +md5(currentDateTime));
			
			return true;
		}
	
	} catch (err) {
	// Ignore bad decrypt attempts
	}
	return false;
}

const allPerms = permute("56147");
console.log("Trying", allPerms.length, "permutations...");

for (const key of allPerms) {
	if (decryptMe(encryptedText, key)) {
		break; // stop once the correct key is found
	}
}
```

![[Pasted image 20251001154311.png]]

We got our key!
Seems need needed to read the key japan style, left to right
![[Pasted image 20251001154343.png]]

Answer:
U2FsdGVkX1/18AY487WSY8L3EFFnPS9aLfjaxwTXu+IOlXCHHhGY1aJpOUcv7xAZ
45716
# 6
https://challenge.orangecyberdefense.academy/level6-Onto_th3_n3xtl3v3l.html

![[Pasted image 20251001154555.png]]
Seems like we need to time a submit

Examining the script we find:
![[Pasted image 20251001154736.png]]

There seems to be a bit of obfuscated js code:
Let's head over to https://obf-io.deobfuscate.io/ before we run it again
![[Pasted image 20251001155303.png]]

Nothing there.

Let's look at the actual function now:

When the text field is first put into focus, we save the date and time and set typing to true
Then call update duration every second
a running total of time spent is then tracked until you click out of the box

Check button
char count == 202
![[Pasted image 20251001160017.png]]
checks out

Then generate a random number between 0 and 6

Looking at the conditional we appear to be missing a function
```c
if(totalTypingTime> calcValue(rndInt) && totalTypingTime < rndInt && mylen == '202'){
```

Seems like we has a sneaky function hidden at
![[Pasted image 20251001160420.png]]
view-source:https://challenge.orangecyberdefense.academy/myquery.js

```javascript
  function calcValue(mytext) { 
  	new_value=mytext-10
	return new_value;
  }
```

Right in order to pass the condition:
```javascript
totalTypingTime > calcValue(rndInt) 
```

```javascript
totalTypingTime < rndInt
```

```javascript
mylen == '202'
```

Right so total typing time needs to be (random number + 60) +- 10
range:
50-60
56-66

Guaranteed win range:
56-59 seconds

This aolve matches the ridd

let's refresh, wait 56 seconds and then press

![[Pasted image 20251001161200.png]]

![[Pasted image 20251001161214.png]]
![[Pasted image 20251001161223.png]]
:]

![[Pasted image 20251001161547.png]]

![[Pasted image 20251001161815.png]]
![[Pasted image 20251001161828.png]]
![[Pasted image 20251001161917.png]]

![[Pasted image 20251001161941.png]]

Answer: 56- 59 seconds

# 7 
![[Pasted image 20251001162033.png]]
![[Pasted image 20251001162043.png]]
![[Pasted image 20251001162054.png]]

admin123
# 8
![[Pasted image 20251001162107.png]]
Seems we have another encrypted thing

Inspecting the source we find
![[Pasted image 20251001162351.png]]

navigating to 
https://challenge.orangecyberdefense.academy/1506aeeb8c3a699b1e3c87db03156428.zip

Which downloads a zip file
extracting this we find a pcap file
![[Pasted image 20251001162526.png]]

Apply some filters to weed out noise;
`!arp && !icmp`
![[Pasted image 20251001162628.png]]
`GET /mynetworkcaptureMAKESITSOEASY.html `

![[Pasted image 20251001162710.png]]
![[Pasted image 20251001165306.png]]

Nothing in the src


Right before we continue let's get back onto tracl
Encrypted thing:
```
U2FsdGVkX1/iv6IzXDS92ZVHPh897oNDrRYFOObVD2Pz28wUAhwOlsruKTihNIkPGsFPGMFP4trmsKtqbzVERD2Zre8useTZO7OIjro8WqaZRhQwmmwWkYAwFWZIqWv+S4Kmjx6+T9Y3idEvvwgnJqwVjPQnBHi+HRa5gV/psdKy8uydUztAfLyUff8UYvl4u9tHTC4TZ+O952QpiWcENw==
```

not quite sure what this is yet, let's assume we can use the script from earlier to decrypt it and that we need to find the key to decrypt it
Then the key is probably hidden in the pcap file

Looking at our hint:
Note: You need to make use of everything you have learned and observed till this point.

Let's retrace our steps from the first challenge
chal 0: get the ip
chal 1: get the password (by inspecting element)
chal 2: decode the base 64 and enter before the timer ran out
chal 3: reverse the decryption process to find the password
chal 4: bypass the unclosable button
chal 5: Solve the sudoku to get a key to decrypt the password
chal 6: expect the source code to get / bypass the win condition
chal7 : crack the hash

right, I see no way to string these together, let's just continue as normal...

chal 8 so far:
inspect source to find secret file
analyse pcap
easter egg site 

Pcap observations:
Everything is local host

Let's see if anything is hidden in the zip itself:
![[Pasted image 20251001171934.png]]

doesn't seem like it

initially assumed the hash was of the file
![[Pasted image 20251001172047.png]]

but it's not
moving into crackstation
![[Pasted image 20251001172103.png]]
midnight

Don't see any timestamps related to midnight.
Let's follow the tcp and http packets:

HTTP:
Some client: `192.168.56.123`
Communicating with a server: `192.168.56.1:8080`

Client fetches `mynetworkcaptureMAKESITSOEASY.html` from server 

Right after, requests for the images are made
server tells client images don't exist

This repeats


TCP:
Handshale between client and server
Data transmission, 
html pages for HTTP/1.0 304 Not Modified and Error code: 404

maybe
https://challenge.orangecyberdefense.academy:8080
https://challenge.orangecyberdefense.academy:8080/mynetworkcaptureMAKESITSOEASY.html
takes us nowehere

Right, that went no where.
Let's redo all the challenges and look for clues
![[Pasted image 20251001204813.png]]

Challenge 2:
`monitor.js`
```javascript
function mydecrypt(){
    //access_key='S2V5VG9FbmNyeXB0';
}

and

    var a = String.fromCharCode(115) + String.fromCharCode(112) + String.fromCharCode(98) + String.fromCharCode(111) + String.fromCharCode(110) + String.fromCharCode(117) + String.fromCharCode(115);
```


![[Pasted image 20251001181802.png]]
KeyToEncrypt also nothig
![[Pasted image 20251001181813.png]]
yeah I don't think that's right

lvl6
```
For today, we have riddle, solve me. A train leaves the station at 15:00, traveling at 240 kph. Another train leaves the same station at 16:00, traveling at 360 kph. When will the second train catch up?
```
answer:
2 hours -> 18:00

lvl 7
```html
Today is your opportunity to build the tomorrow you want.

Just one small positive thought in the morning can change your whole day. 

There is a special thrill in pentesting: the quiet satisfaction of unraveling a tangled system, the detective work of tracing clues in logs and code, and the creativity of turning defensive puzzles into elegant exploit chains, all while staying firmly on the ethical side. It is equal parts curiosity, craftsmanship, and responsibility: you learn new technologies, sharpen your instincts, and then hand practical fixes to teams so their systems are safer. At its best, pentesting feels like solving a living puzzle that actually makes the internet a little kinder. 
```

Right, nothing stands out.
Now's the time for some more coffee and some fresh air...

Right I came back and realised that im retarted:
```js
const CryptoJS = require("crypto-js");

const md5 = require("md5");

  

encryptedText ="U2FsdGVkX1/iv6IzXDS92ZVHPh897oNDrRYFOObVD2Pz28wUAhwOlsruKTihNIkPGsFPGMFP4trmsKtqbzVERD2Zre8useTZO7OIjro8WqaZRhQwmmwWkYAwFWZIqWv+S4Kmjx6+T9Y3idEvvwgnJqwVjPQnBHi+HRa5gV/psdKy8uydUztAfLyUff8UYvl4u9tHTC4TZ+O952QpiWcENw=="

function decryptMe(mytext,mykey) {

try{

var decr = CryptoJS.AES.decrypt(mytext, mykey);

decr = decr.toString(CryptoJS.enc.Utf16);

console.log('Decrypted Text:', decr.toString(), "\nplain: ", decr);

}

catch{

console.log("Not right")

}

}

  

decryptMe(encryptedText, "S2V5VG9FbmNyeXB0");
```

I changed utf8 to utf16 and forgot...

so anyway...
![[Pasted image 20251001204744.png]]
`VEgxU19pc19SRWFsbHlfRlVO`

![[Pasted image 20251001204857.png]]
TH1S_is_REally_FUN

I dug around a bit farther but I think that's it...
![[Pasted image 20251001205252.png]]

But wait, that doesn't feel right...

What if I...
`https://challenge.orangecyberdefense.academy/level9-TH1S_is_REally_FUN.html`

Ah

Onto Challenge 9!

# 9
![[Pasted image 20251002115749.png]]
![[Pasted image 20251002115738.png]]
![[Pasted image 20251002115929.png]]

# 10
![[Pasted image 20251002115956.png]]

Let's see if this is hiding anything:
```bash
󰣇 Cyber/Ctf/Orange ❯ exiftool 1canhas.png                                                                                                 
ExifTool Version Number         : 13.30
File Name                       : 1canhas.png
Directory                       : .
File Size                       : 229 kB
File Modification Date/Time     : 2025:10:02 12:00:51+02:00
File Access Date/Time           : 2025:10:02 12:01:16+02:00
File Inode Change Date/Time     : 2025:10:02 12:00:51+02:00
File Permissions                : -rw-r--r--
File Type                       : PNG
File Type Extension             : png
MIME Type                       : image/png
Image Width                     : 610
Image Height                    : 618
Bit Depth                       : 8
Color Type                      : RGB
Compression                     : Deflate/Inflate
Filter                          : Adaptive
Interlace                       : Noninterlaced
Significant Bits                : 8 8 8
Software                        : Shutter
Image Size                      : 610x618
Megapixels                      : 0.377

󰣇 Cyber/Ctf/Orange ❯ pngcheck 1canhas.png                                                                                                 
OK: 1canhas.png (610x618, 24-bit RGB, non-interlaced, static, 79.7%).
󰣇 Cyber/Ctf/Orange ❯ pngcheck -v 1canhas.png                                                                                              
File: 1canhas.png (229323 bytes)
  chunk IHDR at offset 0x0000c, length 13
    610 x 618 image, 24-bit RGB, non-interlaced
  chunk sBIT at offset 0x00025, length 3
    red = 8 = 0x08, green = 8 = 0x08, blue = 8 = 0x08
  chunk tEXt at offset 0x00034, length 16, keyword: Software
  chunk IDAT at offset 0x00050, length 8192
    zlib: deflated, 32K window, maximum compression
  chunk IDAT at offset 0x0205c, length 8192
  chunk IDAT at offset 0x04068, length 8192
  chunk IDAT at offset 0x06074, length 8192
  chunk IDAT at offset 0x08080, length 8192
  chunk IDAT at offset 0x0a08c, length 8192
  chunk IDAT at offset 0x0c098, length 8192
  chunk IDAT at offset 0x0e0a4, length 8192
  chunk IDAT at offset 0x100b0, length 8192
  chunk IDAT at offset 0x120bc, length 8192
  chunk IDAT at offset 0x140c8, length 8192
  chunk IDAT at offset 0x160d4, length 8192
  chunk IDAT at offset 0x180e0, length 8192
  chunk IDAT at offset 0x1a0ec, length 8192
  chunk IDAT at offset 0x1c0f8, length 8192
  chunk IDAT at offset 0x1e104, length 8192
  chunk IDAT at offset 0x20110, length 8192
  chunk IDAT at offset 0x2211c, length 8192
  chunk IDAT at offset 0x24128, length 8192
  chunk IDAT at offset 0x26134, length 8192
  chunk IDAT at offset 0x28140, length 8192
  chunk IDAT at offset 0x2a14c, length 8192
  chunk IDAT at offset 0x2c158, length 8192
  chunk IDAT at offset 0x2e164, length 8192
  chunk IDAT at offset 0x30170, length 8192
  chunk IDAT at offset 0x3217c, length 8192
  chunk IDAT at offset 0x34188, length 8192
  chunk IDAT at offset 0x36194, length 7715
  chunk IEND at offset 0x37fc3, length 0
No errors detected in 1canhas.png (32 chunks, 79.7% compression).

```
Appears to be fine, let's go and inspect source code

```javascript
<script type="text/javascript">
function Try(password) { var html = "&#109;" + "&#111;" + "&#118;" + "&#105;" + "&#110;" + "&#103;" + "&#95;" + "&#102;" + "&#111;" + "&#114;" + "&#119;" + "&#97;" + "&#114;" + "&#100;"; var a = "/level11-" + decode(html); }</script> 
This is not the end!!!<br /><br /><br /> <img src="[1canhas.png](view-source:https://challenge.orangecyberdefense.academy/1canhas.png)"></img> <!-- end content --> </td> </tr> </table> 
<!-- 1506aeeb8c3a699b1e3c87db03156428.zip -->
```
We have a commented out function and the zip name from earlier. 

Examining we see some encoded text with the missing decode function.
According to our trusty AI companion this is the decimal representation of Uni code characters:
![[Pasted image 20251002121145.png]]

Adjusting the script a bit for node we get:
```javascript
const he = require("he");

function test() {

var html = "&#109;" + "&#111;" + "&#118;" + "&#105;" + "&#110;" + "&#103;" + "&#95;" + "&#102;" + "&#111;" + "&#114;" + "&#119;" + "&#97;" + "&#114;" + "&#100;";

var a = "/level11-" + he.decode(html)

console.log(a)

}

test();
```
![[Pasted image 20251002121402.png]]

# 11
https://challenge.orangecyberdefense.academy/level11-moving_forward.html
ab02a855dcf81de49648c834bd6056cf
meow

Find the following code snippet when we examine the source
![[Pasted image 20251002121710.png]]
We have a whack a mole button and a hash we need to crack:
"ab02a855dcf81de49648c834bd6056cf"

Since none of the online password sites get any hits let's load up hashcat and try a few of my own worldists. Unfortunately no hits after trying 30 million passwords.
It's time to start hunting for possible password candidates:

Try canhas related stuff maybe?
![[Pasted image 20251002125229.png]]
Right seems the the password is the file hash....

Time to look at how md5sum hashes files
www.man7.org/linux/man-pages/man1/md5sum.1.html

![[Pasted image 20251002131517.png]]

Seems like it's using the raw binary

![[Pasted image 20251002131315.png]]

We can either copy the raw bytes onto my clipboard through some linux black magic or we can find a clash.
Why not both?
 Let's start running a bruteforce while we investigate if it's possible to somehow submit the image to the site.

Previous challenges:
![[Pasted image 20251002150155.png]]
clear trend of lowecase upper case digits, _ and -
charset:
a-z
A-Z

```
hashcat -m 0 -a 3 -1 '?l?u?d_-' hash.txt '?1?1?1?1?1?1?1'
```
![[Pasted image 20251002150516.png]]
Right while that slowly heats up my room
![[Pasted image 20251002152831.png]]

let's dive into trying to get those bytes into the page.

Inspecting the form we see:
My intitial guess was to just add a file upload to the site through the console, but upon closer inspection:
```javascript
location.href = password+".html";
```

So we know that the the password has to resolve to some filename, a quick google search reveals that unix has a max file name length of 255 bytes, supposing all characters are ascii that's 255 characters to work with (250 with we account for .html)
Given that md5 uses raw bytes to generate the hash and that these bytes are well above that limit, this idea doesn't make too much sense...

But let's give it a go anyway
```js
document.getElementById('runaway').onmouseover = null;
function submitDecodedContent() {
  const passwordField = document.querySelector('input[name="password"]');
  const base64Content = passwordField.value;

  if (!base64Content) {
    alert("paste the base64 contents of the file into");
    return;
  }

  try {

    const rawFileContent = atob(base64Content);
    

    console.log("Submitting decoded content...");
    console.log('md5: ', md5(rawFileContent));
    Try(rawFileContent);
  } catch (error) {
    console.error("Base64 decoding failed:", error);
    alert("The pasted text is not a valid Base64 string.");
  }
}

submitDecodedContent();
```

![[Pasted image 20251002155850.png]]

![[Pasted image 20251002155803.png]]

Let's adjust the script to add an upload file button, then turn this file into a byte stream and send it to the Try()
```js
document.getElementById('fileInput')?.remove();

var fileInput = document.createElement('input');
fileInput.type = 'file';
fileInput.id = 'fileInput';

document.body.prepend(fileInput);

document.getElementById('fileInput').addEventListener('change', function(event) {
    var file = event.target.files[0];
    if (file) {
        var reader = new FileReader();
        
        reader.onload = function(e) {
            var fileContent = e.target.result;
            var generatedHash = md5(fileContent);
            console.log("File hash:", generatedHash);
            console.log("Target hash:", "ab02a855dcf81de49648c834bd6056cf");
            
            Try(fileContent);
        };
        
        reader.readAsArrayBuffer(file);
    }
}, false);

console.log("New file input created. Please select the '1canhas.png' file.");
```

Right that also doesn't work, maybe the md5 file has been messed with?

Next let's examine the md5 file that the site is using as passing raw bytes doesn't seem to be going anywhere

we call md5(password) in the main script

In the file `"object" == typeof module && module.exports ? module.exports = A : n.md5 = A`
A get's called
```js
function A(n, t, r) { return t ? r ? s(t, n) : C(t, n) : r ? m(n) : p(n) }
```

```js
function p(n) { return g(m(n)) }
```

```js
function m(n) {
    return h(v(n))
}
```

```js
function h(n) { return a(i(d(n), 8 * n.length)) }
```

```js
function d(n) { var t, r = []; for (r[(n.length >> 2) - 1] = void 0, t = 0; t < r.length; t += 1) r[t] = 0; var e = 8 * n.length; for (t = 0; t < e; t += 8) r[t >> 5] |= (255 & n.charCodeAt(t / 8)) << t % 32; return r }
```
Quite critically d uses `n.charCodeAt()` meaning we can't actually pass in raw bytes, this md5 function only accepts characters. 
It's probably a good idea to drop the raw byte upload for now as I don't see a way of bypassing this.

It seems more likely that we're looking for a hash collision, hashcat is still cracking away so let's do something else

Time for some investigative work (and more caffeine)
The image name (icanhas)
is seemingly related to https://icanhas.cheezburger.com/
Which is a blog spot for cat media which aligns quite well with the image itself
An image search also brings us to https://pixabay.com/vectors/ai-generated-cat-glasses-feline-8552962/
We also see another link to the zip with the easter egg pcap but I don't think that has anything to do with this.


Assumption:
The image was altered in some way to produce the hash of another work which we can find with OSINT.
Let's start digging:

Random guesses:
```
::[ OrangeCyberdefense Challenge ]::
OrangeCyberdefense Challenge
OrangeCyberdefense
Orange Cyberdefense
mynetworkcaptureMAKESITSOEASY.html
mynetworkcaptureMAKESITSOEASY
MAKESITSOEASY
1canhas.png
1canhas
canhas
Canhas
Meow
meow
LOLcat
lolcat
I Can Has Cheezburger?
I Can Has Cheezburger
icanhascheezburger
I can has Interview?
I can has Interview
I can has ¤ Interview?
Sir are you aware you are a cat?
Grumpy Cat
(it's a file name, stop adding spaces)
level12-icanhascheezburger?
level12-icanhascheezburger
level12-icanhas
level12-icanhasinterview?
level12-ICanHasInterview?
level12-ICanHasInterview?
level12-I_Can_Has_Interview?
level12-i_can_has_interview?
level12-I_Can_Has_Interview?
level12-I_Can_Has_Cheezburger
level12-I_Can_Has_Cheezburger?
level12-i_can_has_cheezburger
I_Can_Has_Cheezburger?
i_can_has_cheezburger?
I_Can_Has_Interview?
icanhas.cheezburger.com
icanhas.cheezburger
this_is_not_the_end

```
https://www.youtube.com/watch?v=BW8Aleq2Hn0
I then proceeded to take a 5 min break and watch cat videos for the next hour

Ideally at this point I would start scraping https://icanhas.cheezburger.com/ to create a wordlist that I can use with hashcat which I unfortunately had to stop due to my PC shutting down (thx defective cpu cooler) 
But alas I'm a noob so random guesses it is
Also my youtube feed is now filled with cats, thanks for that

Maybe there's a flaw in the challenge, let's try taking the above list and trying them directly in the url in the form:

```
https://challenge.orangecyberdefense.academy/term.html

https://challenge.orangecyberdefense.academy/level12-term.html
```

and boom
https://challenge.orangecyberdefense.academy/ab02a855dcf81de49648c834bd6056cf.html

# 12

![[Pasted image 20251002174658.png]]
AND WE'RE DONE!
or are we?
Looks like we have some Encoded text:
`BhDm9qsHe7rx6XulXISLjSg0ZGaBDouZ`

But that's just a random character sequence it would seem!
![[Pasted image 20251002180707.png]]

Congratulations!!! You've finished the challenge.
Completed: 2025/10/02, 17:40:04 d9bf04528fd6e2f8583fd415d9cbb60d
Mozilla/5.0 (X11; Linux x86_64; rv:141.0) Gecko/20100101 Firefox/141.0


