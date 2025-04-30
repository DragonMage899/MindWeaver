
# Task 1: Intro
In the year 2142, the world is a sprawling cyberpunk megacity, where the lines between the real and digital are blurred by the ceaseless glow of neon lights and nights of endless rain. Towering skyscrapers cast shadows over a networked labyrinth of streets and alleys. Amidst this scattered chaos, **MtEverest**, a colossal global banking conglomerate, reigns supreme. Their latest breakthrough - a secret technology enabling dimensional travel - promised to revolutionize the world.  
  
In the depths of **MtEverest’s** secret research labs, a rogue AI known as **Ares** interfaced with the dimensional travel system. The resulting catastrophe caused a rift in reality, merging the physical and digital worlds into a chaotic and unpredictable new existence. Cyberspace and reality now coexist, creating a twisted landscape where the reality blends into glitches and the laws of physics are no longer absolute.  
  
In the midst of this turmoil, a group of cyber warriors known as **MWR (Masters of Web Resistance)** rises from the shadows. Their mission: to infiltrate the heart of **MtEverest**, defeat **Ares**, and repair the fabric of reality itself. The battle will not be easy. **Ares** controls a vast network of digital defenses, and the merged reality teems with dangerous anomalies. Using information from a mysterious individual known as The Architect, you must brave the digital abyss and use your skill and wit to survive.  

**  
_Will you join the resistance, outsmart Ares, and bring reality back from the brink?_**

### Challenge structure:

In the following tasks, the objective will be to retrieve the killswitch flags. The format for the flags are:

**MWR{Flag-Here}**

Each task will have a walkthrough with some information about the specific vulnerability, along with a challenge where you will be able to retrieve the flag by completing the challenge. Some tasks may also have an additional, easier question which can be completed for another flag. Good luck.

# Task 2: Scanning
After months of relentless effort, MWR has finally uncovered the location of Ares' mainframe server, hidden deep within the digital maze of MtEverest's network. This discovery is a critical breakthrough, but the battle is far from over. To topple Ares and restore reality, **MWR** **must first perform reconnaissance on the mainframe.**

**Reconnaissance** is the first step to hacking anything. In order to hack something, you need to have some information about the environment you're trying to hack. The more information you have, the greater your understanding of the environment will be and you'll be able to construct an attack based on what you know. The process of performing reconnaissance and discovering information about an environment is known as **enumeration**.

# Task 3: Steganography
**Steganography** is a technique which involves hiding data within an ordinary, non-secret file or message to avoid detection. Steganography can be used to conceal any type of digital content, including text, image, video or audio content. Unlike **cryptography**, which focuses on making messages unreadable to unauthorized parties, steganography aims to hide _the existence of the message itself._ A non technical example of this would be a poem containing a message hidden in the first letter of every line.  

Stegonography can be seen in numerous digital use-cases, a few of which are explored below:

# Task 4: Cryptography
While performing reconnaissance at the edge of the Digital Abyss, a treacherous expanse where the boundaries between the physical and digital worlds blur, the resistance has uncovered a crucial clue — a seemingly innocuous data fragment left behind by Ares. This fragment, however, is more than it appears. Encoded within it is a crucial message.

### What is cryptography and encoding?

**Cryptography** is the practice and study of techniques for securing information and communications through the use of secret codes, so that only those for whom the information is intended can read and process it. It encompasses methods such as encryption, which converts plain text into an unreadable format (ciphertext), and decryption, which converts it back into readable plain text using a key. There are a plethora of encryption algorithms in use today such as the Advanced Encryption Standard (AES), among many others.  

**Encoding**, on the other hand, is the process of converting data from one format into another using a specific scheme, often for the purposes of data transformation, storage, or transmission. The goal of encoding is not to keep information secret, but to ensure it can be properly consumed by different systems. For example, _Base64_ encoding converts binary data into a text format that can be easily transmitted over media that are designed to deal with text.

# Task 5: Directory brute forcing
Ares' seemingly secure server contains a repository of mundane files that hides a deeper secret. Buried within its structure is a vulnerability—a flaw in its directory access controls. Ares's architects, in their haste to secure other defenses, overlooked this weakness - or perhaps it was a flaw put there intentionally... This flaw allows you to brute-force your way through directories, uncovering hidden paths and content. Exploit this vulnerability, and you may unlock vital information that could aid your cause.
**Directory brute forcing** is a technique used to systematically guess the names of directories and files on a web server in order to discover hidden or unprotected resources. This is typically done using automated tools that make numerous HTTP requests, testing different potential directory and file names from a predefined or dynamically generated list.

# Task 6: Hash Cracking
The resistance has recovered some key data, which appears to be hashed, from the edges of the digital abyss. This data might contain a killswitch for Ares left by The Architect, and will need to be cracked in order to be recovered.  

### What is hashing?

Hashing is a fundamental concept in computer science and cryptography. It involves taking input data (such as text, files, or passwords) and running it through a special mathematical function called a hash function. This function converts the input into a fixed-length binary output, which is usually represented with hex. Hash functions typically have the following characteristics:  

1. **Deterministic Output:** The hashing function will always produce the same output for the same provided input.
2. **Fixed Output Size:** Regardless of the size of the function's input, the hash function generates a hash output of a fixed length.
3. **One-Way Function:** Hashing is designed to be irreversible. It is easy to compute the hash value of an input, however, it is extremely difficult and infeasible to reverse-engineer the original input from the computed hash value.
4. **Avalanche Effect:** A small change in the input data should result in a significantly different hash output. This ensures that similar inputs produce vastly different hash outputs.


# Task 7: SQL Injection
The Ares mainframe appears to have various search functions which are used for querying different data. Intelligence from the resistance has suggested that these search functions may have been left intentionally vulnerable by the Architect, and that the data for a killswitch may lurk within.﻿  

### What is SQL injection?

**SQL Injection (SQLi)** is a security vulnerability that allows attackers to interfere with the queries an application makes to its database. This occurs because the application cannot differentiate between user input and the intended SQL commands. An attacker can manipulate the input provided to alter the structure of the SQL commands, potentially gaining unauthorized access to the database, extracting sensitive information, or executing administrative operations. SQLi can lead to severe consequences, including data breaches, data loss, and complete control over the database server.

# Task 8:  Union SQL Injection
### How do UNION statements work?

In the previous challenge, we used SQL Injection (SQLi) to bypass authentication. This did not require actually enumerating the database though, since the login page allowed you to simply bypass normal authentication processes by using the SQLi vulnerability. Sometimes though, you'd want to retrieve data in the case of a SQLi vulnerability.

# Task 9: Local File Inclusion and Directory Traversal
The Ares mainframe contains some functions responsible for the retrieval of personality cores, which were used to give Ares various personalities during its testing phase (Go play Portal 2). The functions were designed for the retrieval of said cores, however it seems that a little more than just the cores can be retrieved...  

### What is directory traversal?  

Directory traversal, also known as path traversal, is a type of security vulnerability that allows an attacker to access directories and files that are stored outside the web root folder. The **web root** is the base path on the server that a web application and its files are hosted from. Normally, for security reasons, a web server does not allow you to request files outside this base path as this would allow you to effectively read other files on the server that are not necessarily associated with the intended application.

# Task 10: Authorisation bypass
###Intel suggests that the access controls on several of Ares' main functions might have been intentionally left weak. Can you investigate this further and see if you can get your hands on data that was not intended for your use?  

### What is an authorisation bypass?

Authorisation may be defined as the process of verifying that a requested action or service is approved for a specific entity. Authorisation bypass is a security vulnerability in web applications that occurs when improper access controls allow a user to access resources, or perform actions, they should not be allowed to do. Commonly this manifests as access control issues where a user may be able to access data or functionality in an application not intended for them.

# Task 11: Logic Flaws
The clues that you have found led you deep into the digital labyrinth of Ares's domain. Following the breadcrumbs left by the Architect, you have stumbled upon the fragments of what was once a vast e-commerce empire. Before the dimensional split, this harbored most of MtEverest's trade - now it has been purged by Ares and there is little left. Hidden within this fractured data, however, may be a glimpse of a clue bound by an intentionally hidden logic flaw within the application.

### What are logic flaws?  

Logic flaws arise when a system's intended functionality is misinterpreted or when edge cases are overlooked, leading to unexpected behaviors. Ares's creators left these logical gaps, providing you with the opportunity to exploit them. By identifying and manipulating these flaws, you can subvert Ares's defenses and gain access to critical information, bringing you one step closer to its downfall.

# Task 12: Arbitrary File Uploads
Reconnaissance has identified an endpoint on the Ares mainframe which seems to be a supposedly secure repository for mundane files. Yet lurking within is a vulnerability, which could allow you to uncover the next piece of your journey - another killswitch to shut down the titan before reality collapses upon itself...

### What is arbitrary file upload?

**Arbitrary File Upload** refers to a vulnerability where a web application improperly validates or controls file uploads from users. This can allow malicious users to upload executable scripts disguised as harmless files (like images or documents). These scripts can then be executed by the server, leading to various attacks such as remote code execution or server compromise.

# Task 13: Race Conditions
### What are race conditions?  

Race conditions are a class of vulnerability similar to logic flaws. Race conditions occur when the very short time between an event happening and the system recording that the event happened is exploited. It is this race against time which lends the vulnerability its name. Web applications often handle multiple requests concurrently. When these requests interact with shared resources (e.g. databases, files), the timing of their execution can lead to race conditions.

# Task 14: Root
### Rooting the machine:

This is intended as a bonus challenge for those that have the skills to do it. Use the access you have acquired to the underlying infrastructure (via the file upload vulnerability) to gain a shell on the machine, and try root it to destroy Ares for good.

