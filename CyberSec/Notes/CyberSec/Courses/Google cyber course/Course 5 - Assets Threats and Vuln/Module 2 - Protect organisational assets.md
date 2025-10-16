![[Pasted image 20250113171537.png]]
![[Pasted image 20250113171552.png]]
![[Pasted image 20250113171624.png]]
![[Pasted image 20250113174531.png]]
![[Pasted image 20250113174538.png]]
![[Pasted image 20250113174547.png]]
# Principle of least privilege

Security controls are essential to keeping sensitive data private and safe. One of the most common controls is the principle of least privilege, also referred to as PoLP or least privilege. The **principle of least privilege** is a security concept in which a user is only granted the minimum level of access and authorization required to complete a task or function.

Least privilege is a fundamental security control that supports the confidentiality, integrity, and availability (CIA) triad of information. In this reading, you'll learn how the principle of least privilege reduces risk, how it's commonly implemented, and why it should be routinely audited.

## Limiting access reduces risk

Every business needs to plan for the risk of data theft, misuse, or abuse. Implementing the principle of least privilege can greatly reduce the risk of costly incidents like data breaches by:

- Limiting access to sensitive information
    
- Reducing the chances of accidental data modification, tampering, or loss
    
- Supporting system monitoring and administration
    

Least privilege greatly reduces the likelihood of a successful attack by connecting specific resources to specific users and placing limits on what they can do. It's an important security control that should be applied to any asset. Clearly defining who or what your users are is usually the first step of implementing least privilege effectively.

**Note:** Least privilege is closely related to another fundamental security principle, the _separation of duties—_a security concept that divides tasks and responsibilities among different users to prevent giving a single user complete control over critical business functions. You'll learn more about separation of duties in a different reading about identity and access management.

## Determining access and authorization

To implement least privilege, access and authorization must be determined first. There are two questions to ask to do so: 

- Who is the user? 
    
- How much access do they need to a specific resource? 
    

Determining who the user is usually straightforward. A user can refer to a person, like a customer, an employee, or a vendor. It can also refer to a device or software that's connected to your business network. In general, every user should have their own account. Accounts are typically stored and managed within an organization's directory service.

These are the most common types of user accounts:

- **Guest accounts** are provided to external users who need to access an internal network, like customers, clients, contractors, or business partners.
    
- **User accounts** are assigned to staff based on their job duties.
    
- **Service accounts** are granted to applications or software that needs to interact with other software on the network.
    
- **Privileged accounts** have elevated permissions or administrative access.
    

It's best practice to determine a baseline access level for each account type before implementing least privilege. However, the appropriate access level can change from one moment to the next. For example, a customer support representative should only have access to your information while they are helping you. Your data should then become inaccessible when the support agent starts working with another customer and they are no longer actively assisting you. Least privilege can only reduce risk if user accounts are routinely and consistently monitored.

**Pro tip:** Passwords play an important role when implementing the principle of least privilege. Even if user accounts are assigned appropriately, an insecure password can compromise your systems.

## Auditing account privileges

Setting up the right user accounts and assigning them the appropriate privileges is a helpful first step. Periodically auditing those accounts is a key part of keeping your company’s systems secure.

There are three common approaches to auditing user accounts:

- Usage audits
    
- Privilege audits
    
- Account change audits
    

As a security professional, you might be involved with any of these processes.

### **Usage audits**

When conducting a usage audit, the security team will review which resources each account is accessing and what the user is doing with the resource. Usage audits can help determine whether users are acting in accordance with an organization’s security policies. They can also help identify whether a user has permissions that can be revoked because they are no longer being used.

### **Privilege audits**

Users tend to accumulate more access privileges than they need over time, an issue known as _privilege creep_. This might occur if an employee receives a promotion or switches teams and their job duties change. Privilege audits assess whether a user's role is in alignment with the resources they have access to.

### **Account change audits**

Account directory services keep records and logs associated with each user. Changes to an account are usually saved and can be used to audit the directory for suspicious activity, like multiple attempts to change an account password. Performing account change audits helps to ensure that all account changes are made by authorized users.

**Note:** Most directory services can be configured to alert system administrators of suspicious activity.

## Key takeaways

The principle of least privilege is a security control that can reduce the risk of unauthorized access to sensitive information and resources. Setting up and configuring user accounts with the right levels of access and authorization is an important step toward implementing least privilege. Auditing user accounts and revoking unnecessary access rights is an important practice that helps to maintain the confidentiality, integrity, and availability of information.

# The data lifecycle

Organizations of all sizes handle a large amount of data that must be kept private. You learned that data can be vulnerable whether it is at rest, in use, or in transit. Regardless of the state it is in, information should be kept private by limiting access and authorization.

In security, data vulnerabilities are often mapped in a model known as the data lifecycle. Each stage of the data lifecycle plays an important role in the security controls that are put in place to maintain the CIA triad of information. In this reading, you will learn about the data lifecycle, the plans that determine how data is protected, and the specific types of data that require extra attention.

## The data lifecycle

The data lifecycle is an important model that security teams consider when protecting information. It influences how they set policies that align with business objectives. It also plays an important role in the technologies security teams use to make information accessible.

In general, the data lifecycle has five stages. Each describe how data flows through an organization from the moment it is created until it is no longer useful:

- Collect
    
- Store
    
- Use
    
- Archive
    
- Destroy
    

![Five stages of the data lifecycle: collection, storage, usage, archival, and destruction.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/Sx9FANHTQYK_Emc4x9cBsA_4dad354c13cc4354b9caef4a1b05d2f1_CS_R-091_ive-stages-of-the-data-lifecycle.png?expiry=1736899200000&hmac=564ipMhpxOf5CFJdBlQIYpdMXCfeif7tSv69IakzoKA)

Protecting information at each stage of this process describes the need to keep it accessible and recoverable should something go wrong.

## Data governance

Businesses handle massive amounts of data every day. New information is constantly being collected from internal and external sources. A structured approach to managing all of this data is the best way to keep it private and secure.

_Data governance_ is a set of processes that define how an organization manages information. Governance often includes policies that specify how to keep data private, accurate, available, and secure throughout its lifecycle.

Effective data governance is a collaborative activity that relies on people. Data governance policies commonly categorize individuals into a specific role:

- **Data owner:** the person that decides who can access, edit, use, or destroy their information.
    
- **Data custodian**: anyone or anything that's responsible for the safe handling, transport, and storage of information.
    
- **Data steward**: the person or group that maintains and implements data governance policies set by an organization.
    

Businesses store, move, and transform data using a wide range of IT systems. Data governance policies often assign accountability to data owners, custodians, and stewards.

**Note:** As a data custodian, you will primarily be  responsible for maintaining security and privacy rules for your organization.

## Protecting data at every stage

Most security plans include a specific policy that outlines how information will be managed across an organization. This is known as a data governance policy. These documents clearly define procedures that should be followed to participate in keeping data safe. They place limits on who or what can access data. Security professionals are important participants in data governance. As a data custodian, you will be responsible for ensuring that data isn’t damaged, stolen, or misused.

## Legally protected information

Data is more than just a bunch of 1s and 0s being processed by a computer. Data can represent someone's personal thoughts, actions, and choices. It can represent a purchase, a sensitive medical decision, and everything in between. For this reason, data owners should be the ones deciding whether or not to share their data. As a security professional, protecting a person's data privacy decisions must always be respected.

Securing data can be challenging. In large part, that's because data owners generate more data than they can manage. As a result, data custodians and stewards sometimes lack direct, explicit instructions on how they should handle specific types of data. Governments and other regulatory agencies have bridged this gap by creating rules that specify the types of information that organizations must protect by default:

- **PII** is any information used to infer an individual's identity. Personally identifiable information, or PII, refers to information that can be used to contact or locate someone.
    
- **PHI** stands for protected health information.  In the U.S., it is regulated by the Health Insurance Portability and Accountability Act (HIPAA), which defines PHI as “information that relates to the past, present, or future physical or mental health or condition of an individual.” In the EU, PHI has a similar definition but it is regulated by the General Data Protection Regulation (GDPR).
    
- **SPII** is a specific type of PII that falls under stricter handling guidelines. The _S_ stands for sensitive, meaning this is a type of personally identifiable information that should only be accessed on a need-to-know basis, such as a bank account number or login credentials.
    

Overall, it's important to protect all types of personal information from unauthorized use and disclosure.

## Key takeaways

Keeping information private has never been so important. Many organizations have data governance policies that outline how they plan to protect sensitive information. As a data custodian, you will play a key role in keeping information accessible and safe throughout its lifecycle. There are various types of information and controls that you’ll encounter in the field. As you continue through this course, you’ll learn more about major security controls that keep data private.

# Information privacy: Regulations and compliance

Security and privacy have a close relationship. As you may recall, people have the right to control how their personal data is collected and used. Organizations also have a responsibility to protect the information they are collecting from being compromised or misused. As a security professional, you will be highly involved in these efforts.

Previously, you learned how regulations and compliance reduce security risk. To review, refer to [the reading about how security controls, frameworks, and compliance regulations](https://www.coursera.org/learn/foundations-of-cybersecurity/supplement/xu4pr/controls-frameworks-and-compliance)

are used together to manage security and minimize risk. In this reading, you will learn how information privacy regulations affect data handling practices. You'll also learn about some of the most influential security regulations in the world. 

![A Venn diagram of privacy and security.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/fDaKJmUlQGuh59KQM1Y0Nw_0ca1ff72e15643bcb40f8aaabf7078f1_S35G006-1-.png?expiry=1736899200000&hmac=YP6ZE_eaz1J8vd6R3ELQ2UcRe_es_3BAIYAKt5DZmgY)

## Information security vs. information privacy

Security and privacy are two terms that often get used interchangeably outside of this field. Although the two concepts are connected, they represent specific functions:

- **Information privacy** refers to the protection of unauthorized access and distribution of data.
    
- **Information security** (InfoSec) refers to the practice of keeping data in all states away from unauthorized users.
    

The key difference: Privacy is about providing people with control over their personal information and how it's shared. Security is about protecting people’s choices and keeping their information safe from potential threats.

For example, a retail company might want to collect specific kinds of personal information about its customers for marketing purposes, like their age, gender, and location. How this private information will be used should be disclosed to customers before it's collected. In addition, customers should be given an option to opt-out if they decide not to share their data.

Once the company obtains consent to collect personal information, it might implement specific security controls in place to protect that private data from unauthorized access, use, or disclosure. The company should also have security controls in place to respect the privacy of all stakeholders and anyone who chose to opt-out.

**Note:** Privacy and security are both essential for maintaining customer trust and brand reputation.

## Why privacy matters in security

Data privacy and protection are topics that started gaining a lot of attention in the late 1990s. At that time, tech companies suddenly went from processing people’s data to storing and using it for business purposes. For example, if a user searched for a product online, companies began storing and sharing access to information about that user’s search history with other companies. Businesses were then able to deliver personalized shopping experiences to the user for free.

Eventually this practice led to a global conversation about whether these organizations had the right to collect and share someone’s private data. Additionally, the issue of data security became a greater concern; the more organizations collected data, the more vulnerable it was to being abused, misused, or stolen.

Many organizations became more concerned about the issues of data privacy. Businesses became more transparent about how they were collecting, storing, and using information. They also began implementing more security measures to protect people's data privacy. However, without clear rules in place, protections were inconsistently applied.

**Note:** The more data is collected, stored, and used, the more vulnerable it is to breaches and threats.

## Notable privacy regulations

Businesses are required to abide by certain laws to operate. As you might recall, **regulations** are rules set by a government or another authority to control the way something is done. Privacy regulations in particular exist to protect a user from having their information collected, used, or shared without their consent. Regulations may also describe the security measures that need to be in place to keep private information away from threats.

Three of the most influential industry regulations that every security professional should know about are:

- General Data Protection Regulation (GDPR)
    
- Payment Card Industry Data Security Standard (PCI DSS)
    
- Health Insurance Portability and Accountability Act (HIPAA)
    

### **GDPR**

GDPR is a set of rules and regulations developed by the European Union (EU) that puts data owners in total control of their personal information. Under GDPR, types of personal information include a person's name, address, phone number, financial information, and medical information.

The GDPR applies to any business that handles the data of EU citizens or residents, regardless of where that business operates. For example, a US based company that handles the data of EU visitors to their website is subject to the GDPRs provisions.

### **PCI DSS**

PCI DSS is a set of security standards formed by major organizations in the financial industry. This regulation aims to secure credit and debit card transactions against data theft and fraud.

### **HIPAA**

HIPAA is a U.S. law that requires the protection of sensitive patient health information. HIPAA prohibits the disclosure of a person's medical information without their knowledge and consent.

**Note:** These regulations influence data handling at many organizations around the world even though they were developed by specific nations.

Several other security and privacy compliance laws exist. Which ones your organization needs to follow will depend on the industry and the area of authority. Regardless of the circumstances, regulatory compliance is important to every business.

## Security assessments and audits

Businesses should comply with important regulations in their industry. Doing so validates that they have met a minimum level of security while also demonstrating their dedication to maintaining data privacy.

Meeting compliance standards is usually a continual, two-part process of security audits and assessments:

- A **security audit** is a review of an organization's security controls, policies, and procedures against a set of expectations.
    
- A **security assessment** is a check to determine how resilient current security implementations are against threats.
    

For example, if a regulation states that multi-factor authentication (MFA) must be enabled for all administrator accounts, an audit might be conducted to check those user accounts for compliance. After the audit, the internal team might perform a security assessment that determines many users are using weak passwords. Based on their assessment, the team could decide to enable MFA on all user accounts to improve their overall security posture.

**Note:** Compliance with legal regulations, such as GDPR, can be determined during audits.

As a security analyst, you are likely to be involved with security audits and assessments in the field. Businesses usually perform security audits less frequently, approximately once per year. Security audits may be performed both internally and externally by different third-party groups.

In contrast, security assessments are usually performed more frequently, about every three-to-six months. Security assessments are typically performed by internal employees, often as preparation for a security audit. Both evaluations are incredibly important ways to ensure that your systems are effectively protecting everyone's privacy.

## Key takeaways

A growing number of businesses are making it a priority to protect and govern the use of sensitive data to maintain customer trust. Security professionals should think about data and the need for privacy in these terms. Organizations commonly use security assessments and audits to evaluate gaps in their security plans. While it is possible to overlook or delay addressing the results of an assessment, doing so can have serious business consequences, such as fines or data breaches.

# Cryptography
![[Pasted image 20250113180817.png]]
![[Pasted image 20250113180951.png]]

![[Pasted image 20250113181031.png]]
![[Pasted image 20250113181043.png]]
![[Pasted image 20250113181111.png]]
![[Pasted image 20250113181211.png]]
![[Pasted image 20250113181217.png]]
![[Pasted image 20250113181250.png]]

# Symmetric and asymmetric encryption

Previously, you learned these terms: 

- **Encryption**: the process of converting data from a readable format to an encoded format
    
- **Public key infrastructure** (PKI):  an encryption framework that secures the exchange of online information
    
- **Cipher**: an algorithm that encrypts information
    

All digital information deserves to be kept private, safe, and secure. Encryption is one key to doing that! It is useful for transforming information into a form that unintended recipients cannot understand. In this reading, you’ll compare symmetric and asymmetric encryption and learn about some well-known algorithms for each.

## Types of encryption

There are two main types of encryption:

- **Symmetric encryption** is the use of a single secret key to exchange information. Because it uses one key for encryption and decryption, the sender and receiver must know the secret key to lock or unlock the cipher.
    
- **Asymmetric encryption** is the use of a public and private key pair for encryption and decryption of data. It uses two separate keys: a public key and a private key. The public key is used to encrypt data, and the private key decrypts it. The private key is only given to users with authorized access.
    

## The importance of key length

Ciphers are vulnerable to **brute force attacks**, which use a trial and error process to discover private information. This tactic is the digital equivalent of trying every number in a combination lock trying to find the right one. In modern encryption, longer key lengths are considered to be more secure. Longer key lengths mean more possibilities that an attacker needs to try to unlock a cipher.

One drawback to having long encryption keys is slower processing times. Although short key lengths are generally less secure, they’re much faster to compute. Providing fast data communication online while keeping information safe is a delicate balancing act. 

## Approved algorithms

Many web applications use a combination of symmetric and asymmetric encryption. This is how they balance user experience with safeguarding information. As an analyst, you should be aware of the most widely-used algorithms.

### **Symmetric algorithms**

- _Triple DES (3DES)_ is known as a block cipher because of the way it converts plaintext into ciphertext in “blocks.” Its origins trace back to the Data Encryption Standard (DES), which was developed in the early 1970s. DES was one of the earliest symmetric encryption algorithms that generated 64-bit keys. A **bit** is the smallest unit of data measurement on a computer. As you might imagine, Triple DES generates keys that are 192 bits, or three times as long. Despite the longer keys, many organizations are moving away from using Triple DES due to limitations on the amount of data that can be encrypted. However, Triple DES is likely to remain in use for backwards compatibility purposes.   
    
- _Advanced Encryption Standard (AES)_ is one of the most secure symmetric algorithms today. AES generates keys that are 128, 192, or 256 bits. Cryptographic keys of this size are considered to be safe from brute force attacks. It’s estimated that brute forcing an AES 128-bit key could take a modern computer billions of years!
    

### **Asymmetric algorithms**

- _Rivest Shamir Adleman (RSA)_ is named after its three creators who developed it while at the Massachusetts Institute of Technology (MIT). RSA is one of the first asymmetric encryption algorithms that produces a public and private key pair. Asymmetric algorithms like RSA produce even longer key lengths. In part, this is due to the fact that these functions are creating two keys. RSA key sizes are 1,024, 2,048, or 4,096 bits. RSA is mainly used to protect highly sensitive data.
    
- _Digital Signature Algorithm (DSA)_ is a standard asymmetric algorithm that was introduced by NIST in the early 1990s. DSA also generates key lengths of 2,048 bits. This algorithm is widely used today as a complement to RSA in public key infrastructure.
    

### **Generating keys**

These algorithms must be implemented when an organization chooses one to protect their data. One way this is done is using OpenSSL, which is an open-source command line tool that can be used to generate public and private keys. OpenSSL is commonly used by computers to verify digital certificates that are exchanged as part of public key infrastructure.

**Note:** OpenSSL is just one option. There are various others available that can generate keys with any of these common algorithms. 

In early 2014, OpenSSL disclosed a vulnerability, known as the [Heartbleed bug](https://en.wikipedia.org/wiki/Heartbleed)

, that exposed sensitive data in the memory of websites and applications. Although unpatched versions of OpenSSL are still available, the Heartbleed bug was patched later that year (2014). Many businesses today use the secure versions of OpenSSL to generate public and private keys, demonstrating the importance of using up-to-date software.

## Obscurity is not security

In the world of cryptography, a cipher must be proven to be unbreakable before claiming that it is secure. According to [Kerchoff’s principle](https://en.wikipedia.org/wiki/Kerckhoffs%27s_principle)

, cryptography should be designed in such a way that all the details of an algorithm—except for the private key—should be knowable without sacrificing its security. For example, you can access all the details about how AES encryption works online and yet it is still unbreakable.

Occasionally, organizations implement their own, custom encryption algorithms. There have been instances where those secret cryptographic systems have been quickly cracked after being made public.

**Pro tip:** A cryptographic system _should not_ be considered secure if it requires secrecy around how it works.

### Encryption is everywhere

Companies use both symmetric and asymmetric encryption. They often work as a team, balancing security with user experience.

For example, websites tend to use asymmetric encryption to secure small blocks of data that are important. Usernames and passwords are often secured with asymmetric encryption while processing login requests. Once a user gains access, the rest of their web session often switches to using symmetric encryption for its speed.

Using data encryption like this is increasingly required by law. Regulations like the Federal Information Processing Standards (FIPS 140-3) and the General Data Protection Regulation (GDPR) outline how data should be collected, used, and handled. Achieving compliance with either regulation is critical to demonstrating to business partners and governments that customer data is handled responsibly.

## Key takeaways

Knowing the basics of encryption is important for all security professionals. Symmetric encryption relies on a single secret key to protect data. On the other hand, asymmetric uses a public and private key pair. Their encryption algorithms create different key sizes. Both types of encryption are used to meet compliance regulations and protect data online.

![[Pasted image 20250113183640.png]]
![[Pasted image 20250113183734.png]]

# The evolution of hash functions

Hash functions are important controls that are part of every company's security strategy. Hashing is widely used for authentication and **non-repudiation**, the concept that the authenticity of information can’t be denied.

Previously, you learned that **hash functions** are algorithms that produce a code that can't be decrypted. Hash functions convert information into a unique value that can then be used to determine its integrity. In this reading, you’ll learn about the origins of hash functions and how they’ve changed over time.

![The hashing algorithm process. A plaintext document is converted by a hash function into hashed text.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/qISzBqG7RmukCvKmeU83mg_e0d4d256b3bb41be8504685b3338fcf1_CS_R-094_Hashing-algorithm.png?expiry=1736899200000&hmac=fNej88HkiNw4hK568AhdpFE6jlMvDMGEe75qw4U4r_4)

## Origins of hashing

Hash functions have been around since the early days of computing. They were originally created as a way to quickly search for data. Since the beginning, these algorithms have been designed to represent data of any size as small, fixed-size values, or digests. Using a hash table, which is a data structure that's used to store and reference hash values, these small values became a more secure and efficient way for computers to reference data.

One of the earliest hash functions is Message Digest 5, more commonly known as MD5. Professor Ronald Rivest of the Massachusetts Institute of Technology (MIT) developed MD5 in the early 1990s as a way to verify that a file sent over a network matched its source file.

Whether it’s used to convert a single email or the source code of an application, MD5 works by converting data into a 128-bit value. You might recall that a **bit** is the smallest unit of data measurement on a computer. Bits can either be a 0 or 1. In a computer, bits represent user input in a way that computers can interpret. In a hash table, this appears as a string of 32 characters. Altering anything in the source file generates an entirely new hash value.

Generally, the longer the hash value, the more secure it is. It wasn’t long after MD5's creation that security practitioners discovered 128-bit digests resulted in a major vulnerability.

Here is an example of how plaintext gets turned into hash values:

![Names being turned into hash values. The hash values are stored in random rows of a data table.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/4XExarUSRWuWRaIX64HrVw_2cb75b41a08b4817b5789ad39e861ff1_CS_R-094_Orgins-of-Hashing.png?expiry=1736899200000&hmac=v3VOXP-SKzF30FzVS8YmK4UhGqMT5CP_wR55chmJaz0)

### **Hash collisions**

One of the flaws in MD5 happens to be a characteristic of all hash functions. Hash algorithms map any input, regardless of its length, into a fixed-size value of letters and numbers. What’s the problem with that? Although there are an infinite amount of possible inputs, there’s only a finite set of available outputs!

MD5 values are limited to 32 characters in length. Due to the limited output size, the algorithm is considered to be vulnerable to **hash collision**, an instance when different inputs produce the same hash value. Because hashes are used for authentication, a hash collision is similar to copying someone’s identity. Attackers can carry out collision attacks to fraudulently impersonate authentic data.

## Next-generation hashing

To avoid the risk of hash collisions, functions that generated longer values were needed. MD5's shortcomings gave way to a new group of functions known as the Secure Hashing Algorithms, or SHAs.

The National Institute of Standards and Technology (NIST) approves each of these algorithms. Numbers besides each SHA function indicate the size of its hash value in bits. Except for SHA-1, which produces a 160-bit digest, these algorithms are considered to be collision-resistant. However, that doesn’t make them invulnerable to other exploits.

**Five functions make up the SHA family of algorithms:**

- SHA-1
    
- SHA-224
    
- SHA-256
    
- SHA-384
    
- SHA-512
    

## Secure password storage

Passwords are typically stored in a database where they are mapped to a username. The server receives a request for authentication that contains the credentials supplied by the user. It then looks up the username in the database and compares it with the password that was provided and verifies that it matches before granting them access.

This is a safe system unless an attacker gains access to the user database. If passwords are stored in plaintext, then an attacker can steal that information and use it to access company resources. Hashing adds an additional layer of security. Because hash values can't be reversed, an attacker would not be able to steal someone's login credentials if they managed to gain access to the database.

### **Rainbow tables**

A **rainbow table** is a file of pre-generated hash values and their associated plaintext. They’re like dictionaries of weak passwords. Attackers capable of obtaining an organization’s password database can use a rainbow table to compare them against all possible values.

## Adding some “salt”

Functions with larger digests are less vulnerable to collision and rainbow table attacks. But as you’re learning, no security control is perfect.

**Salting** is an additional safeguard that's used to strengthen hash functions. A _salt_ is a random string of characters that's added to data before it's hashed. The additional characters produce a more unique hash value, making salted data resilient to rainbow table attacks.

For example, a database containing passwords might have several hashed entries for the password "password." If those passwords were all salted, each entry would be completely different. That means an attacker using a rainbow table would be unable to find matching values for "password" in the database.

![User input entering a hash function. A random set of characters are added to the hashing process.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/VJFA9qhuRvan1_hRvGhSpg_70858cdbe6d94ad29538d1915f0e05f1_CS_R-094_Salting.png?expiry=1736899200000&hmac=KYlT9qSGm3fFeFGlrq3a2Ypq7tT-l0JPW0wVjVqJKsc)

For this reason, salting has become increasingly common when storing passwords and other types of sensitive data. The length and uniqueness of a salt is important. Similar to hash values, the longer and more complex a salt is, the harder it is to crack.

## Key takeaways

Security professionals often use hashing as a tool to validate the integrity of program files, documents, and other types of data. Another way it’s used is to reduce the chances of a data breach. As you’ve learned, not all hashing functions provide the same level of protection. Rainbow table attacks are more likely to work against algorithms that generate shorter keys, like MD5. Many small- and medium-sized businesses still rely on MD5 to secure sensitive data. Knowing about alternative algorithms and salting better prepares you to make impactful security recommendations.

# Authentication
![[Pasted image 20250113185102.png]]
![[Pasted image 20250113185210.png]]
![[Pasted image 20250113185246.png]]
![[Pasted image 20250113185323.png]]

# The rise of SSO and MFA

Most companies help keep their data safely locked up behind authentication systems. Usernames and passwords are the keys that unlock information for most organizations. But are those credentials enough? Information security often focuses on managing a user's access of, and authorization to, information.

Previously, you learned about the three factors of authentication: knowledge, ownership, and characteristic. Single sign-on (SSO) and multi-factor authentication (MFA) are two technologies that have become popular for implementing these authentication factors. In this reading, you’ll learn how these technologies work and why companies are adopting them.

## A better approach to authentication

**Single sign-on** (SSO) is a technology that combines several different logins into one. More companies are turning to SSO as a solution to their authentication needs for three reasons:

1. **SSO improves the user experience** by eliminating the number of usernames and passwords people have to remember.
    
2. **Companies can lower costs** by streamlining how they manage connected services.
    
3. **SSO improves overall security** by reducing the number of access points attackers can target.
    

This technology became available in the mid-1990s as a way to combat _password fatigue_, which refers to people’s tendency to reuse passwords across services. Remembering many different passwords can be a challenge, but using the same password repeatedly is a major security risk. SSO solves this dilemma by shifting the burden of authentication away from the user.

## How SSO works

SSO works by automating how trust is established between a user and a service provider. Rather than placing the responsibility on an employee or customer, SSO solutions use trusted third-parties to prove that a user is who they claim to be. This is done through the exchange of encrypted access tokens between the identity provider and the service provider.

Similar to other kinds of digital information, these access tokens are exchanged using specific protocols. SSO implementations commonly rely on two different authentication protocols: LDAP and SAML. LDAP, which stands for Lightweight Directory Access Protocol, is mostly used to transmit information on-premises; SAML, which stands for Security Assertion Markup Language, is mostly used to transmit information off-premises, like in the cloud.

**Note:** LDAP and SAML protocols are often used together.

Here's an example of how SSO can connect a user to multiple applications with one access token:

![One user connects to multiple applications with one access token.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/IaWbLEaURvGv7k6ZSOjbRg_c43ff4ecdca147cca2f5351aaaa917f1_image2.png?expiry=1736899200000&hmac=-kAwzUzjSNV1_eMG-2mjm4qegrgAFNSIUO8yQN4_CK4)

## Limitations of SSO

Usernames and passwords alone are not always the most secure way of protecting sensitive information. SSO provides useful benefits, but there’s still the risk associated with using one form of authentication. For example, a lost or stolen password could expose information across multiple services. Thankfully, there’s a solution to this problem.

## MFA to the rescue

**Multi-factor authentication** (MFA) requires a user to verify their identity in two or more ways to access a system or network. In a sense, MFA is similar to using an ATM to withdraw money from your bank account. First, you insert a debit card into the machine as one form of identification. Then, you enter your PIN number as a second form of identification. Combined, both steps, or factors, are used to verify your identity before authorizing you to access the account.

![An equation showing user login plus biometric or physical devices equal access.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/hNHsmtDZRI28CtisHKRAew_cedbe22c98dc4ef095d8b8884cf689f1_CS_R-095_mfa-equation.png?expiry=1736899200000&hmac=JJnF4GCJ8VOJNbSYHIuaxDx_hSgeELPeNjBVxCG_sxk)

## Strengthening authentication

MFA builds on the benefits of SSO. It works by having users prove that they are who they claim to be. The user must provide two factors (2FA) or three factors (3FA) to authenticate their identification. The MFA process asks users to provide these proofs, such as:

- **Something a user knows:** most commonly a username and password
    
- **Something a user has:** normally received from a service provider, like a one-time passcode (OTP) sent via SMS
    
- **Something a user is:** refers to physical characteristics of a user, like their fingerprints or facial scans
    

Requiring multiple forms of identification is an effective security measure, especially in cloud environments. It can be difficult for businesses in the cloud to ensure that the users remotely accessing their systems are not threat actors. MFA can reduce the risk of authenticating the wrong users by requiring forms of identification that are difficult to imitate or brute force.

## Key takeaways

Implementing both SSO and MFA security controls improves security without sacrificing the user experience. Relying on passwords alone is a serious vulnerability. Implementing SSO means fewer points of entry, but that’s not enough. Combining SSO and MFA can be an effective way to protect information, so that users have a streamlined experience while unauthorized people are kept away from important information.

![[Pasted image 20250113185626.png]]
![[Pasted image 20250113185945.png]]
![[Pasted image 20250113190007.png]]
![[Pasted image 20250113190021.png]]
![[Pasted image 20250113190142.png]]
![[Pasted image 20250113190154.png]]
![[Pasted image 20250113190204.png]]
![[Pasted image 20250113190226.png]]

# Identity and access management

Security is more than simply combining processes and technologies to protect assets. Instead, security is about ensuring that these processes and technologies are creating a secure environment that supports a defense strategy. A key to doing this is implementing two fundamental security principles that limit access to organizational resources:

- The **principle of least privilege** in which a user is only granted the minimum level of access and authorization required to complete a task or function.
    
- **Separation of duties**, which is the principle that users should not be given levels of authorization that would allow them to misuse a system.
    

Both principles typically support each other. For example, according to least privilege, a person who needs permission to approve purchases from the IT department shouldn't have the permission to approve purchases from every department. Likewise, according to separation of duties, the person who can approve purchases from the IT department should be different from the person who can input new purchases.

In other words, least privilege _limits_ _the access_ that an individual receives, while separation of duties _divides responsibilities_ among multiple people to prevent any one person from having too much control.

**Note:** Separation of duties is sometimes referred to as segregation of duties.

Previously, you learned about the authentication, authorization, and accounting (AAA) framework. Many businesses used this model to implement these two security principles and manage user access. In this reading, you’ll learn about the other major framework for managing user access, identity and access management (IAM). You will learn about the similarities between AAA and IAM and how they're commonly implemented.

## Identity and access management (IAM)

As organizations become more reliant on technology, regulatory agencies have put more pressure on them to demonstrate that they’re doing everything they can to prevent threats. **Identity and access management** (IAM) is a collection of processes and technologies that helps organizations manage digital identities in their environment. Both AAA and IAM systems are designed to authenticate users, determine their access privileges, and track their activities within a system.

Either model used by your organization is more than a single, clearly defined system. They each consist of a collection of security controls that ensure the _right user_ is granted access to the _right resources_ at the _right time_ and for the _right reasons_. Each of those four factors is determined by your organization's policies and processes.

**Note:** A user can either be a person, a device, or software.

## Authenticating users

To ensure the right user is attempting to access a resource requires some form of proof that the user is who they claim to be. In a [video on authentication controls](https://www.coursera.org/learn/assets-threats-and-vulnerabilities/item/r6XuB)

, you learned that there are a few factors that can be used to authenticate a user:

- **Knowledge**, or something the user knows
    
- **Ownership**, or something the user possesses
    
- **Characteristic**, or something the user is
    

Authentication is mainly verified with login credentials. **Single sign-on** (SSO), a technology that combines several different logins into one, and **multi-factor authentication** (MFA), a security measure that requires a user to verify their identity in two or more ways to access a system or network, are other tools that organizations use to authenticate individuals and systems.

**Pro tip:** Another way to remember this authentication model is: something you know, something you have, and something you are.

### **User provisioning**

Back-end systems need to be able to verify whether the information provided by a user is accurate. To accomplish this, users must be properly provisioned. **User provisioning** is the process of creating and maintaining a user's digital identity. For example, a college might create a new user account when a new instructor is hired. The new account will be configured to provide access to instructor-only resources while they are teaching. Security analysts are routinely involved with provisioning users and their access privileges.

**Pro tip:** Another role analysts have in IAM is to deprovision users. This is an important practice that removes a user's access rights when they should no longer have them.

### **Granting authorization**

If the right user has been authenticated, the network should ensure the right resources are made available. There are three common frameworks that organizations use to handle this step of IAM:

- Mandatory access control (MAC)
    
- Discretionary access control (DAC)
    
- Role-based access control (RBAC)
    

![A system administrator deciding to grant users and an operating system access to data.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/AxrWM2DLTSunrTWYAtwc4Q_49abc18d6b1c48748e222045153881f1_image3.png?expiry=1736899200000&hmac=C1Xzh92a9I7_DPsz3znbS_pqgv7rVU7jR74fPT7LOps)

### **Mandatory Access Control (MAC)**

MAC is the strictest of the three frameworks. Authorization in this model is based on a strict need-to-know basis. Access to information must be granted manually by a central authority or system administrator. For example, MAC is commonly applied in law enforcement, military, and other government agencies where users must request access through a chain of command. MAC is also known as non-discretionary control because access isn’t given at the discretion of the data owner.

![A data owner choosing to grant specific users access to their data.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/LHnKRh7ISfCc379NmCXMlw_5c65648b2a77437ab6998e6b978afcf1_image2.png?expiry=1736899200000&hmac=_7D1VL79Ggv7SGxxslzOkr_H0FaU9ac75OuCqbNqg60)

### **Discretionary Access Control (DAC)**

DAC is typically applied when a data owner decides appropriate levels of access. One example of DAC is when the owner of a Google Drive folder shares editor, viewer, or commentor access with someone else.

![A system administrator assigning users to specific roles that have predefined access levels.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/1EBo9jW3TGW_7Hulb3cUpA_16c10e1f1de94b3c95d88760722733f1_image1.png?expiry=1736899200000&hmac=YK9DDv50bXwdXWm53O9f_C0GHiOZ4EP5K0_UZPtLjvg)

### **Role-Based Access Control (RBAC)**

RBAC is used when authorization is determined by a user's role within an organization. For example, a user in the marketing department may have access to user analytics but not network administration.

## Access control technologies

Users often experience authentication and authorization as a single, seamless experience. In large part, that’s due to access control technologies that are configured to work together. These tools offer the speed and automation needed by administrators to monitor and modify access rights. They also decrease errors and potential risks.

An organization's IT department sometimes develops and maintains customized access control technologies on their own. A typical IAM or AAA system consists of a user directory, a set of tools for managing data in that directory, an authorization system, and an auditing system. Some organizations create custom systems to tailor them to their security needs. However, building an in-house solution comes at a steep cost of time and other resources.

Instead, many organizations opt to license third-party solutions that offer a suite of tools that enable them to quickly secure their information systems. Keep in mind, security is about more than combining a bunch of tools. It’s always important to configure these technologies so they can help to provide a secure environment.

## Key takeaways

Controlling access requires a collection of systems and tools. IAM and AAA are common frameworks for implementing least privilege and separation of duties. As a security analyst, you might be responsible for user provisioning and collaborating with other IAM or AAA teams. Having familiarity with these models is valuable for helping organizations achieve their security objectives. They each ensure that the right user is granted access to the right resources at the right time and for the right reasons.

## Resources for more information

The identity and access management industry is growing at a rapid pace. As with other domains in security, it’s important to stay informed.

- [IDPro](https://idpro.org/)
    

- © is a professional organization dedicated to sharing essential IAM industry knowledge.