# Intro

**Offensive Security**
- Gaining unauthorised access thru exploits, bugs etc

**Defensive Security**
- Protect pc and secure threats

![[Pasted image 20240903213353.png]]
File things

**Careers in Cyber Sec**
- Pen Tester: Testing and exploiting products
- Red Teamer: Attack org and give feedback
- Security engineer: Design networks and systems for preventing attacks

# Defensive Security 

Offensive security focuses on breaking into systems (exploit bugs, abuse insecure steps, take advantage of bad access control - Red teams)
Defensive security is the opposite
- Prevents intrusion
- Detect intrusion and respond'

Tasks:
- User cyber security awareness : Training users to protect against attacks
- Documenting and managing assets : Know types of systems and devices that we need to protect
- Updating and Patching Systems : Ensure that systems are patched against security
- Logging and Monitoring : Detect malicious activities

## Areas of Defensive Security 
- Security Operations Centre (SOC) - Threat intelligence 
- Digital Forensics and Incident response (DFIR) - Malware analysis

SOC's
- Monitor Networks and systems and detects malicious/ suspicious activities.
	- Discovers vulnerability and prevent exploitation 
	- Ensure users are adhering to security policies 
	- Monitor for unauthorised access (password stolen)
	- Monitor for network intrusions (link)

**Threat Intelligence**
- Intelligence -> info about actual and potential enemies
- Threat -> Action than can disrupt a system
- Collection information to build a threat informed defence.
- Build intelligence by collecting, processing and analysing data

**SOC**: Sec op Centre (Threat intelligence)
**DFIR**: Digital Forensics and Incident Response (Malware analysis)

## SOC: Monitor Networks and Systems
- Search for Vuln (doesn't always apply patchh)
- Policy violations creation and monitoring
- Detect unauthorised access 
- Detect Network intrusion

**Threat Intelligence**
- Collecting information to help a company prepare against adversaries
- Goal: Threat informed defence 
- Intelligence needs data
- Data needs to be collected an analysed
- Data processing arranges it into a form we can analyse
- Predict thread actors and their activities 

## DFIR
**Digital Forensics**
Forensics: Use of science to investigate crimes and establish facts

Digital: Analyse evidence of an attack and its perpetrators as well as other digital crime 
related areas

Focus:
- File System: Installed programs, files, partially overwritten files, deleted files etc
- System Memory: Examining malware running in memory
- System logs: Event information
- Network logs: Log of network packets

**Incident Response**
Incident: Cyber Attack / Breach / Misconfiguration / Policy violation... etc

Incident Response: Methodology to be followed when an incident occurs
Goal: Reduce Damage and Recover ASAP

Phases:
- Preparation: Train team in advance
- Detection and Analysis: Team uses resources to detect and analyse
- Containment, Eradication and Recovery: Prevent further infection
- Post incident: Produce a report and guard for future incidents 

**Malware Analysis**
- Virus spreads from one computer to another
- Trojan hides malicious function under desirable function
- Ransomware encrypts user's files

Static Analysis: Inspect malicious program without running it (Disassemble)
Dynamic Analysis: Run malware in controlled environment


---
_Security Information and Event Management_ (SIEM)
143 110 250 149


# Careers

## Security Analyst
![[Pasted image 20241210221325.png]]

## Security Engineer
![[Pasted image 20241210221428.png]]

## Incident Responder
![[Pasted image 20241210221516.png]]

## Digital Forensics
![[Pasted image 20241210221655.png]]

## Malware Analyst 
![[Pasted image 20241210221734.png]]

## Pen Tester
![[Pasted image 20241210221820.png]]

## Red Teamer
![[Pasted image 20241210221911.png]]

# Networking
The first iteration of the Internet was within the ARPANET project in the late 1960s. This project was funded by the United States Defence Department and was the first documented network in action. However, it wasn't until 1989 when the Internet as we know it was invented by Tim Berners-Lee by the creation of the **W**orld **W**ide **W**eb (**WWW**). It wasn't until this point that the Internet started to be used as a repository for storing and sharing information, just like it is today.

Devices have the same thing: two means of identification, with one being permeable. These are:

- An IP Address
- A Media Access Control (MAC) Address -- think of this as being similar to a serial number.

### 

### **IP Addresses**

Briefly, an IP address (or **I**nternet **P**rotocol) address can be used as a way of identifying a host on a network for a period of time, where that IP address can then be associated with another device without the IP address changing. First, let's split up precisely what an IP address is in the diagram below:

![](https://tryhackme-images.s3.amazonaws.com/user-uploads/5de96d9ca744773ea7ef8c00/room-content/a0de0d68641982ddf1a8c5a9f1984c4c.png)  

An **IP** address is a set of numbers that are divided into four octets. The value of each octet will summarise to be the IP address of the device on the network. This number is calculated through a technique known as IP addressing & subnetting, but that is for another day. What's important to understand here is that IP addresses can change from device to device but cannot be active simultaneously more than once within the same network.

IP Addresses follow a set of standards known as protocols. These protocols are the backbone of networking and force many devices to communicate in the same language, which is something that we'll come onto another time. However, we should recall that devices can be on both a private and public network. Depending on where they are will determine what type of IP address they have: a public or private IP address.

A public address is used to identify the device on the Internet, whereas a private address is used to identify a device amongst other devices. Take the table & screenshot below as an example. Here we have two devices on a private network:

  

|   |   |   |
|---|---|---|
|**Device Name**|**IP Address**|**IP Address Type**|
|DESKTOP-KJE57FD|192.168.1.77|Private|
|DESKTOP-KJE57FD|86.157.52.21|Public|
|CMNatic-PC|192.168.1.74|Private|
|CMNatic-PC|86.157.52.21|Public|

  
![https://assets.tryhackme.com/additional/cmn-aoc2020/day-8/1.png](https://assets.tryhackme.com/additional/cmn-aoc2020/day-8/1.png)

These two devices will be able to use their private IP addresses to communicate with each other. However, any data sent to the Internet from either of these devices will be identified by the same public IP address. Public IP addresses are given by your **I**nternet **S**ervice **P**rovider (or **ISP**) at a monthly fee (your bill!)

![https://assets.tryhackme.com/additional/cmn-aoc2020/day-8/2.png](https://assets.tryhackme.com/additional/cmn-aoc2020/day-8/2.png)

As more and more devices become connected, it is becoming increasingly harder to get a public address that isn't already in use. For example, Cisco, an industry giant in the world of networking, estimated that there would be approximately 50 billion devices connected on the Internet by the end of 2021. [(Cisco., 2021)](https://www.cisco.com/c/dam/en_us/about/ac79/docs/innov/IoT_IBSG_0411FINAL.pdf). Enter IP address versions. So far, we have only discussed one version of the Internet Protocol addressing scheme known as IPv4, which uses a numbering system of 2^32 IP addresses (4.29 billion) -- so you can see why there is such a shortage!

IPv6 is a new iteration of the Internet Protocol addressing scheme to help tackle this issue. Although it is seemingly more daunting, it boasts a few benefits:

- Supports up to 2^128 of IP addresses (340 trillion-plus), resolving the issues faced with IPv4
- More efficient due to new methodologies

The screenshot below compares both an IPv6 and IPv4 address.

![](https://assets.tryhackme.com/additional/networking-fundamentals/intro-to-networking/ipv6.png)  

**MAC Addresses  
**

Devices on a network will all have a physical network interface, which is a microchip board found on the device's motherboard. This network interface is assigned a unique address at the factory it was built at, called a **MAC** (**M**edia **A**ccess **C**ontrol ) address. The MAC address is a **twelve-character** hexadecimal number (_a base sixteen numbering system used in computing to represent numbers_) split into two's and separated by a colon. These colons are considered separators. For example, _a4:c3:f0:85:ac:2d_. The first six characters represent the company that made the network interface, and the last six is a unique number.

![](https://tryhackme-images.s3.amazonaws.com/user-uploads/5de96d9ca744773ea7ef8c00/room-content/394caee97fb1b9f7b5a5f7a7ea0a9f71.png)  

  

However, an interesting thing with MAC addresses is that they can be faked or "spoofed" in a process known as spoofing. This spoofing occurs when a networked device pretends to identify as another using its MAC address. When this occurs, it can often break poorly implemented security designs that assume that devices talking on a network are trustworthy. Take the following scenario: A firewall is configured to allow any communication going to and from the MAC address of the administrator. If a device were to pretend or "spoof" this MAC address, the firewall would now think that it is receiving communication from the administrator when it isn't.

Places such as cafes, coffee shops, and hotels alike often use MAC address control when using their "Guest "or "Public" Wi-Fi. This configuration could offer better services, i.e. a faster connection for a price if you are willing to pay the fee per device.  The **interactive lab attached to this task** has been made to replicate this scenario!


# Security Principles
Security has become a buzzword; every company wants to claim its product or service is secure. But is it?

Before we start discussing the different security principles, it is vital to know the adversary against whom we are protecting our assets. Are you trying to stop a toddler from accessing your laptop? Or are you trying to protect a laptop that contains technical designs worth millions of dollars? Using the exact protection mechanisms against toddlers and industrial espionage actors would be ludicrous. Consequently, knowing our adversary is a must so we can learn about their attacks and start implementing appropriate security controls.

## CIA
security triad: confidentiality, integrity, and availability (CIA).

- **Confidentiality** ensures that only the intended persons or recipients can access the data.
- **Integrity** aims to ensure that the data cannot be altered; moreover, we can detect any alteration if it occurs.
- **Availability** aims to ensure that the system or service is available when needed.

![A seller with a receipt, adding a zero to the price of an item after a shopper chooses it, thus multiplying the price by ten.](https://tryhackme-images.s3.amazonaws.com/user-uploads/5f04259cf9bf5b57aed2c476/room-content/6b93d35050cea9dc51b700855677edf4.png)

Let’s consider the CIA security triad in the case of placing an order for online shopping:

- **Confidentiality**: During online shopping, you expect your credit card number to be disclosed only to the entity that processes the payment. If you doubt that your credit card information will be disclosed to an untrusted party, you will most likely refrain from continuing with the transaction. Moreover, if a data breach results in the disclosure of personally identifiable information, including credit cards, the company will incur huge losses on multiple levels.
- **Integrity**: After filling out your order, if an intruder can alter the shipping address you have submitted, the package will be sent to someone else. Without data integrity, you might be very reluctant to place your order with this seller.
- **Availability**: To place your online order, you will either browse the store’s website or use its official app. If the service is unavailable, you won’t be able to browse the products or place an order. If you continue to face such technical issues, you might eventually give up and start looking for a different online store.

Let’s consider the CIA as it relates to patient records and related systems:

- **Confidentiality**: According to various laws in modern countries, healthcare providers must ensure and maintain the confidentiality of medical records. Consequently, healthcare providers can be held legally accountable if they illegally disclose their patients’ medical records.
- **Integrity**: If a patient record is accidentally or maliciously altered, it can lead to the wrong treatment being administered, which, in turn, can lead to a life-threatening situation. Hence, the system would be useless and potentially harmful without ensuring the integrity of medical records.
- **Availability**: When a patient visits a clinic to follow up on their medical condition, the system must be available. An unavailable system would mean that the medical practitioner cannot access the patient’s records and consequently won’t know if any current symptoms are related to the patient’s medical history. This situation can make the medical diagnosis more challenging and error-prone.

The emphasis does not need to be the same on all three security functions. One example would be a university announcement; although it is usually not confidential, the document’s integrity is critical.

### Beyond CIA

![A delivery man with an absurdly large number of pizza boxes and a man at the door saying, I didn’t order that.](https://tryhackme-images.s3.amazonaws.com/user-uploads/5f04259cf9bf5b57aed2c476/room-content/aaeda28067dbaa5573f640e467be7834.png)

Going one more step beyond the CIA security triad, we can think of:

- **Authenticity**: Authentic means not fraudulent or counterfeit. Authenticity is about ensuring that the document/file/data is from the claimed source.
- **Nonrepudiation**: Repudiate means refusing to recognize the validity of something. Nonrepudiation ensures that the original source cannot deny that they are the source of a particular document/file/data. This characteristic is indispensable for various domains, such as shopping, patient diagnosis, and banking.

These two requirements are closely related. The need to tell authentic files or orders from fake ones is indispensable. Moreover, ensuring that the other party cannot deny being the source is vital for many systems to be usable.

In online shopping, depending on your business, you might tolerate attempting to deliver a t-shirt with cash-on-delivery and learn later that the recipient never placed such an order. However, no company can tolerate shipping 1000 cars to discover that the order is fake. In the example of a shopping order, you want to confirm that the said customer indeed placed this order; that’s authenticity. Moreover, you want to ensure they cannot deny placing this order; that’s nonrepudiation.

As a company, if you receive a shipment order of 1000 cars, you need to ensure the authenticity of this order; moreover, the source should not be able to deny placing such an order. Without authenticity and nonrepudiation, the business cannot be conducted.

### Parkerian Hexad

In 1998, Donn Parker proposed the Parkerian Hexad, a set of six security elements. They are:

1. Availability
2. Utility
3. Integrity
4. Authenticity
5. Confidentiality
6. Possession

We have already covered four of the above six elements. Let's discuss the remaining two elements:

- **Utility**: Utility focuses on the usefulness of the information. For instance, a user might have lost the decryption key to access a laptop with encrypted storage. Although the user still has the laptop with its disk(s) intact, they cannot access them. In other words, although still available, the information is in a form that is not useful, i.e., of no utility.
- **Possession**: This security element requires that we protect the information from unauthorized taking, copying, or controlling. For instance, an adversary might take a backup drive, meaning we lose possession of the information as long as they have the drive. Alternatively, the adversary might succeed in encrypting our data using ransomware; this also leads to the loss of possession of the data.
## DA
![[Pasted image 20250125154911.png]]

The security of a system is attacked through one of several means. It can be via the disclosure of secret data, alteration of data, or destruction of data.

- **Disclosure** is the opposite of confidentiality. In other words, disclosure of confidential data would be an attack on confidentiality.
- **Alteration** is the opposite of Integrity. For example, the integrity of a cheque is indispensable.
- **Destruction/Denial** is the opposite of Availability.

The opposite of the CIA Triad would be the DAD Triad: Disclosure, Alteration, and Destruction.

Consider the previous example of patient records and related systems:

- Disclosure: As in most modern countries, healthcare providers must maintain medical records’ confidentiality. As a result, if an attacker succeeds in stealing some of these medical records and dumping them online to be viewed publicly, the health care provider will incur a loss due to this data disclosure attack.
- Alteration: Consider the gravity of the situation if the attacker manages to modify patient medical records. This alteration attack might lead to the wrong treatment being administered, and consequently, this alteration attack could be life-threatening.
- Destruction/Denial: Consider the case where a medical facility has gone completely paperless. If an attacker manages to make the database systems unavailable, the facility will not be able to function properly. They can go back to paper temporarily; however, the patient records won’t be available. This denial attack would stall the whole facility.

Protecting against disclosure, alteration, and destruction/denial is of utter significance. This protection is equivalent to working to maintain confidentiality, integrity and availability.  
  
Protecting confidentiality and integrity to an extreme can restrict availability, and increasing availability to an extreme can result in losing confidentiality and integrity. Good security principles implementation requires a balance between the three.


# Security Models concepts
We have learned that the security triad is represented by Confidentiality, Integrity, and Availability (CIA). One might ask, how can we create a system that ensures one or more security functions? The answer would be in using security models. In this task, we will introduce three foundational security models:

- Bell-LaPadula Model
- The Biba Integrity Model
- The Clark-Wilson Model

### Bell-LaPadula Model

The Bell-LaPadula Model aims to achieve **confidentiality** by specifying three rules:

- **Simple Security Property**: This property is referred to as “no read up”; it states that a subject at a lower security level cannot read an object at a higher security level. This rule prevents access to sensitive information above the authorized level.
- **Star Security Property**: This property is referred to as “no write down”; it states that a subject at a higher security level cannot write to an object at a lower security level. This rule prevents the disclosure of sensitive information to a subject of lower security level.
- **Discretionary-Security Property**: This property uses an access matrix to allow read and write operations. An example access matrix is shown in the table below and used in conjunction with the first two properties.

|Subjects|Object A|Object B|
|---|---|---|
|Subject 1|Write|No access|
|Subject 2|Read/Write|Read|

The first two properties can be summarized as “write up, read down.” You can share confidential information with people of higher security clearance (write up), and you can receive confidential information from people with lower security clearance (read down).

There are certain limitations to the Bell-LaPadula model. For example, it was not designed to handle file-sharing.  

### Biba Model

The Biba Model aims to achieve **integrity** by specifying two main rules:

- **Simple Integrity Property**: This property is referred to as “no read down”; a higher integrity subject should not read from a lower integrity object.
- **Star Integrity Property**: This property is referred to as “no write up”; a lower integrity subject should not write to a higher integrity object.

These two properties can be summarized as “read up, write down.” This rule is in contrast with the Bell-LaPadula Model, and this should not be surprising as one is concerned with confidentiality while the other is with integrity.

Biba Model suffers from various limitations. One example is that it does not handle internal threats (insider threat).  

### Clark-Wilson Model

The Clark-Wilson Model also aims to achieve integrity by using the following concepts:

- **Constrained Data Item (CDI)**: This refers to the data type whose integrity we want to preserve.
- **Unconstrained Data Item (UDI)**: This refers to all data types beyond CDI, such as user and system input.
- **Transformation Procedures (TPs)**: These procedures are programmed operations, such as read and write, and should maintain the integrity of CDIs.
- **Integrity Verification Procedures (IVPs)**: These procedures check and ensure the validity of CDIs.

We covered only three security models. The reader can explore many additional security models. Examples include:

- Brewer and Nash model
- Goguen-Meseguer model
- Sutherland model
- Graham-Denning model
- Harrison-Ruzzo-Ullman model

**Defence-in-Depth** refers to creating a security system of multiple levels; hence it is also called Multi-Level Security.

Consider the following analogy: you have a locked drawer where you keep your important documents and pricey stuff. The drawer is locked; however, do you want this drawer lock to be the only thing standing between a thief and your expensive items? If we think of multi-level security, we would prefer that the drawer be locked, the relevant room be locked, the main door of the apartment be locked, the building gate be locked, and you might even want to throw in a few security cameras along the way. Although these multiple levels of security cannot stop every thief, they would block most of them and slow down the others.


## ISO/IEC 19249
The International Organization for Standardization (ISO) and the International Electrotechnical Commission (IEC) have created the ISO/IEC 19249. In this task, we will brush briefly upon ISO/IEC 19249:2017 _Information technology - Security techniques - Catalogue of architectural and design principles for secure products, systems and applications_. The purpose is to have a better idea of what international organizations would teach regarding security principles.

ISO/IEC 19249 lists five _architectural_ principles:

1. **Domain Separation**: Every set of related components is grouped as a single entity; components can be applications, data, or other resources. Each entity will have its own domain and be assigned a common set of security attributes. For example, consider the x86 processor privilege levels: the operating system kernel can run in ring 0 (the most privileged level). In contrast, user-mode applications can run in ring 3 (the least privileged level). Domain separation is included in the Goguen-Meseguer Model.
2. **Layering**: When a system is structured into many abstract levels or layers, it becomes possible to impose security policies at different levels; moreover, it would be feasible to validate the operation. Let’s consider the OSI (Open Systems Interconnection) model with its seven layers in networking. Each layer in the OSI model provides specific services to the layer above it. This layering makes it possible to impose security policies and easily validate that the system is working as intended. Another example from the programming world is disk operations; a programmer usually uses the disk read and write functions provided by the chosen high-level programming language. The programming language hides the low-level system calls and presents them as more user-friendly methods. Layering relates to Defence in Depth.
3. **Encapsulation**: In object-oriented programming (OOP), we hide low-level implementations and prevent direct manipulation of the data in an object by providing specific methods for that purpose. For example, if you have a clock object, you would provide a method `increment()` instead of giving the user direct access to the `seconds` variable. The aim is to prevent invalid values for your variables. Similarly, in larger systems, you would use (or even design) a proper Application Programming Interface (API) that your application would use to access the database.
4. **Redundancy**: This principle ensures availability and integrity. There are many examples related to redundancy. Consider the case of a hardware server with two built-in power supplies: if one power supply fails, the system continues to function. Consider a RAID 5 configuration with three drives: if one drive fails, data remains available using the remaining two drives. Moreover, if data is improperly changed on one of the disks, it would be detected via the parity, ensuring the data’s integrity.
5. **Virtualization**: With the advent of cloud services, virtualization has become more common and popular. The concept of virtualization is sharing a single set of hardware among multiple operating systems. Virtualization provides sandboxing capabilities that improve security boundaries, secure detonation, and observance of malicious programs.

ISO/IEC 19249 teaches five _design_ principles:

1. **Least Privilege**: You can also phrase it informally as “need-to basis” or “need-to-know basis” as you answer the question, “who can access what?” The principle of least privilege teaches that you should provide the least amount of permissions for someone to carry out their task and nothing more. For example, if a user needs to be able to view a document, you should give them read rights without write rights.
2. **Attack Surface Minimisation**: Every system has vulnerabilities that an attacker might use to compromise a system. Some vulnerabilities are known, while others are yet to be discovered. These vulnerabilities represent risks that we should aim to minimize. For example, in one of the steps to harden a Linux system, we would disable any service we don’t need.
3. **Centralized Parameter Validation**: Many threats are due to the system receiving input, especially from users. Invalid inputs can be used to exploit vulnerabilities in the system, such as denial of service and remote code execution. Therefore, parameter validation is a necessary step to ensure the correct system state. Considering the number of parameters a system handles, the validation of the parameters should be centralized within one library or system.
4. **Centralized General Security Services**: As a security principle, we should aim to centralize all security services. For example, we would create a centralized server for authentication. Of course, you might take proper measures to ensure availability and prevent creating a single point of failure.
5. **Preparing for Error and Exception Handling**: Whenever we build a system, we should take into account that errors and exceptions do and will occur. For instance, in a shopping application, a customer might try to place an order for an out-of-stock item. A database might get overloaded and stop responding to a web application. This principle teaches that the systems should be designed to fail safe; for example, if a firewall crashes, it should block all traffic instead of allowing all traffic. Moreover, we should be careful that error messages don’t leak information that we consider confidential, such as dumping memory content that contains information related to other customers.

In the following questions, refer to the ISO/IEC 19249 five design principles above. Answer with a number between 1 and 5, depending on the number of the design principle.


## Zero Trust
Trust is a very complex topic; in reality, we cannot function without trust. If one were to think that the laptop vendor has installed spyware on the laptop, they would most likely end up rebuilding the system. If one were to mistrust the hardware vendor, they would stop using it completely. If we think of trust on a business level, things only become more sophisticated; however, we need some guiding security principles. Two security principles that are of interest to us regarding trust:

- Trust but Verify
- Zero Trust

**Trust but Verify**: This principle teaches that we should always verify even when we trust an entity and its behaviour. An entity might be a user or a system. Verifying usually requires setting up proper logging mechanisms; verifying indicates going through the logs to ensure everything is normal. In reality, it is not feasible to verify everything; just think of the work it takes to review all the actions taken by a single entity, such as Internet pages browsed by a single user. This requires automated security mechanisms, such as proxy, intrusion detection, and intrusion prevention systems.

**Zero Trust**: This principle treats trust as a vulnerability, and consequently, it caters to insider-related threats. After considering trust as a vulnerability, zero trust tries to eliminate it. It is teaching indirectly, “never trust, always verify.” In other words, every entity is considered adversarial until proven otherwise. Zero trust does not grant trust to a device based on its location or ownership. This approach contrasts with older models that would trust internal networks or enterprise-owned devices. Authentication and authorization are required before accessing any resource. As a result, if any breach occurs, the damage would be more contained if a zero trust architecture had been implemented.

Microsegmentation is one of the implementations used for Zero Trust. It refers to the design where a network segment can be as small as a single host. Moreover, communication between segments requires authentication, access control list checks, and other security requirements.  

There is a limit to how much we can apply zero trust without negatively impacting a business; however, this does not mean that we should not apply it as long as it is feasible.

## Threats and risks
There are three terms that we need to take note of to avoid any confusion.

- **Vulnerability**: Vulnerable means susceptible to attack or damage. In information security, a vulnerability is a weakness.
- **Threat**: A threat is a potential danger associated with this weakness or vulnerability.
- **Risk**: The risk is concerned with the likelihood of a threat actor exploiting a vulnerability and the consequent impact on the business.

Away from information systems, a showroom with doors and windows made of standard glass suffers a weakness, or _vulnerability_, due to the nature of glass. Consequently, there is a _threat_ that the glass doors and windows can be broken. The showroom owners should contemplate the _risk_, i.e. the likelihood that a glass door or window gets broken and the resulting impact on the business.

Consider another example directly related to information systems. You work for a hospital that uses a particular database system to store all the medical records. One day, you are following the latest security news, and you learn that the used database system is not only vulnerable but also a proof-of-concept working exploit code has been released; the released exploit code indicates that the threat is real. With this knowledge, you must consider the resulting risk and decide the next steps.

We will cover threats and risks in detail in a separate room.



# Governance & Regulation
Cyber security is a rapidly evolving landscape wherein malicious actors relentlessly endeavour to exploit vulnerabilities in highly-sensitive systems, often with the intent of causing severe damage, disruption, and stealing of sensitive corporate data. To combat this evolving threat, a comprehensive approach to **information security governance & regulation** is necessary. Such an approach requires establishing robust policies and guidelines and implementing rigorous monitoring and enforcement mechanisms to ensure compliance. By adopting a proactive and strategic stance towards cyber security, organisations can mitigate the risks posed by malicious actors and safeguard their sensitive systems against potentially catastrophic breaches.

Important Terminologies

- **Governance**: Managing and directing an organisation or system to achieve its objectives and ensure compliance with laws, regulations, and standards.
- **Regulation**: A rule or law enforced by a governing body to ensure compliance and protect against harm.
- **Compliance**: The state of adhering to laws, regulations, and standards that apply to an organisation or system.

Information Security Governance

**Information security governance represents an organisation's established structure, policies, methods, and guidelines designed to guarantee the privacy, reliability, and accessibility of its information assets.** Given the escalating complexity of cyber threats, the significance of information security governance is continually growing. It is essential for risk management, safeguarding confidential data from unauthorised intrusion, and adhering to pertinent regulations. Information security governance falls under the purview of top-tier management and includes the following processes:  
![What are the processes of information security governance](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/48120d5b5fc7d9cb7e283b8956e6a666.png)

- **Strategy**: Developing and implementing a comprehensive information security strategy that aligns with the organisation's overall business objectives.
- **Policies and procedures**: Preparing policies and procedures that govern the use and protection of information assets.
- **Risk management**: Conduct risk assessments to identify potential threats to the organisation's information assets and implement risk mitigation measures.
- **Performance measurement**: Establishing metrics and key performance indicators (KPIs) to measure the effectiveness of the information security governance program.
- **Compliance**: Ensuring compliance with relevant regulations and industry best practices.

Information Security Regulation

Governance and regulation are closely linked in the information security paradigm but have distinct meanings. Information security regulation refers to legal and regulatory frameworks that govern the use and protection of information assets. Regulations are designed to protect sensitive data from unauthorized access, theft, and misuse. Compliance with regulations is typically mandatory and enforced by government agencies or other regulatory bodies. Examples of information security regulations/standards include the General Data Protection Regulation (GDPR), Payment Card Industry Data Security Standard (PCI DSS), Personal Information Protection and Electronic Documents Act (PIPEDA), and many more.

Key Benefits

The following are the benefits of implementing governance and regulation:

- **More Robust Security Posture**: Implementing a comprehensive security governance program and complying with relevant regulations can help an organisation reduce the risk of security breaches and protect sensitive information from unauthorised access, theft, and misuse.![benefits of security governance and regulations](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/a148517c47f4063df1a246f3ad278fd6.png)
- **Increased Stakeholder Confidence**: Effective security governance and regulation can enhance stakeholder trust by demonstrating that an organisation takes cyber security seriously and has implemented measures to protect sensitive data.
- **Regulatory Compliance**: Compliance with relevant regulations, such as GDPR, HIPAA, and PCI DSS, can help organisations avoid legal and financial penalties and reputational damage resulting from non-compliance.
- **Better alignment with business objectives**: Security governance frameworks can help organisations align their information security strategies with their overall business objectives and ensure that security measures are cost-effective and contribute to the organisation's success.
- **Informed decision-making**: Security governance programs can provide decision-makers with the knowledge they need to make sophisticated decisions about information security risks and ensure that security measures are implemented where they are most needed.
- **Competitive advantage**: Effective security governance and compliance with relevant regulations can provide a competitive advantage by demonstrating an organisation's commitment to protecting sensitive data and enhancing stakeholder trust.

Relevant Laws and Regulations

Specific laws and regulations operate the security governance and regulatory ecosystem. They provide a structured framework for establishing minimum compliance standards, promoting accountability and trust, and fostering innovative approaches to safeguarding critical systems and data. By offering clear and concise rules, they reduce ambiguity and provide a common language for organisations to measure their security posture and ensure regulatory compliance. Following is an overview of some relevant laws and regulations:

|                                                             |                           |                                                                                                                                                                                                                                |
| ----------------------------------------------------------- | ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Law/Regulation**                                          | **Domain**                | **Description**                                                                                                                                                                                                                |
| General Data Protection Regulation (GDPR)                   | Data Privacy & Protection | GDPR is a regulation propagated by the European Union that sets strict requirements for how organisations handle and protect and  secure the personal data of EU citizens and residents.                                       |
| Health Insurance Portability and Accountability Act (HIPAA) | Healthcare                | A US-based official law to maintain the sensitivity of health-related information of citizens.                                                                                                                                 |
| Payment Card Industry Data Security Standard (PCI-DSS)      | Financial                 | Set technical and operational requirements to ensure the secure handling, storage, processing, and transmission of cardholder data by merchants, service providers, and other entities that handle payment cards.              |
| Gramm-Leach-Bliley Act (GLBA)                               | Financial                 | Financial companies must be sensitive to their customers' nonpublic personal information (NPI), including implementing information security programs, providing privacy notices, and disclosing information-sharing practices. |
﻿﻿## Information Security Frameworks

The information security framework provides a comprehensive set of documents that outline the organisation's approach to information security and governs how security is implemented, managed, and enforced within the organisation. This mainly includes:

- Policies: A formal statement that outlines an organisation's goals, principles, and guidelines for achieving specific objectives.
- Standards: A document establishing specific requirements or specifications for a particular process, product, or service.
- Guidelines: A document that provides recommendations and best practices (non-mandatory) for achieving specific goals or objectives.
- Procedures: Set of specific steps for undertaking a particular task or process.
- Baselines: A set of minimum security standards or requirements that an organisation or system must meet.

Developing Governance Documents

Here are some generalised steps used to develop policies, standards, guidelines, etc.![how to develop governance documents](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/957df3acd08e9884b95a28e72bd7219a.png)

- **Identify the scope and purpose**:  Determine what the document will cover and why it is needed. For example, a password policy might be required to ensure robust and secure user passwords. In contrast, a baseline might be required to establish a minimum level of security for all systems.
- **Research and review**: Research relevant laws, regulations, industry standards, and best practices to ensure your document is comprehensive and up-to-date. Review existing policies, procedures, and other documents to avoid duplicating efforts or contradicting existing guidance.
- **Draft the document**: Develop an outline and start drafting the document, following best practices for writing clear and concise policies, procedures, standards, guidelines, and baselines. Ensure the document is specific, actionable, and aligned with the organisation's goals and values.
- **Review and approval**: Have the document reviewed by stakeholders, such as subject matter experts, legal and compliance teams, and senior management. Incorporate their feedback and ensure the document aligns with organisational goals and values. Obtain final approval from appropriate stakeholders.
- **Implementation and communication**: Communicate the document to all relevant employees and stakeholders, and ensure they understand their roles and responsibilities in implementing it. Develop training and awareness programs to ensure the document is understood and followed.
- **Review and update**: Periodically review and update the document to ensure it remains relevant and practical. Monitor compliance and adjust the document based on feedback and changes in the threat landscape or regulatory environment.

Explanation through Real-world Scenarios

We will go through some real-world scenarios to fully understand the steps to develop these documents.

Preparing a Password Policy

- **Define password requirements**: Minimum length, complexity, and expiration.
- **Define password usage guidelines**: Specify how passwords should be used, such as requiring unique passwords for each account, prohibiting the sharing of passwords, and prohibiting default passwords.
- **Define password storage and transmission guidelines**: Using encryption for password storage and requiring secure connections for password transmission.
- **Define password change and reset guidelines**: How often passwords should be changed etc. 
- **Communicate the policy**: Communicate the password policy to all relevant employees and stakeholders, and ensure that they understand the requirements and guidelines. Develop training and awareness programs to ensure that employees follow the policy.
- **Monitor compliance**: Monitor compliance with the password policy and adjust the policy as needed based on feedback and changes in the threat landscape or regulatory environment.

Making an Incident Response Procedure

- **Define incident types**: Unauthorised access, malware infections, or data breaches.
- **Define incident response roles and responsibilities**: Identify the stakeholders,  such as incident response team members, IT personnel, legal and compliance teams, and senior management.
- **Detailed Steps**: Develop step-by-step procedures for responding to each type of incident,  including initial response steps, such as containing the incident and preserving evidence; analysis and investigation steps, such as identifying the root cause and assessing the impact; response and recovery steps, such as mitigating the incident, reporting and restoring normal operations.
- **Report** the incident to management and document the incident response process for future reference.  
    
- **Communicate** the incident response procedures.
- **Review** and update the incident response procedures.

Organisations only sometimes need to make a standard, frameworks, or baselines; instead, they follow and use already made documents related to their field or discipline, as the financial sector may follow PCI-DSS and GLBA; healthcare may follow HIPPA, etc. There are numerous factors upon which we decide which standard framework of baseline checklist should be used; these include regulatory requirements primarily related to the particular geographical areas, scope, objectives, available resources, and many more.

## GRC
As we have studied, information security governance and compliance are necessary to maintain any organisation's overall security posture. But how to achieve it? Here comes the role of the Governance and Risk Compliance (GRC) framework. It focuses on steering the organisation's overall governance, enterprise risk management, and compliance in an integrated manner. It is a holistic approach to information security that aligns with the organisation's goals and objectives and helps to ensure that the organisation operates within the boundaries of relevant regulations and industry standards. GRC framework has the following three components:  

![Components of GRC](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/99f1191333d407baaa8e786ebd0ce9c0.png)

- **Governance Component**: Involves guiding an organisation by setting its direction through information security strategy,  which includes policies, standards, baselines, frameworks, etc., along with establishing appropriate monitoring methods to measure its performance and assess the outcomes.
- **Risk Management Component**: Involves identifying, assessing, and prioritising risks to the organisation and implementing controls and mitigation strategies to manage those risks effectively. This includes monitoring and reporting on risks and continuously evaluating and refining the risk management program to ensure its ongoing effectiveness.
- **Compliance Component**: Ensuring that the organisation meets its legal, regulatory, and industry obligations and that its activities align with its policies and procedures. This includes developing and implementing compliance programs, conducting regular audits and assessments, and reporting on compliance issues to stakeholders.

How to Develop GRC Program - Generic Guidelines 

A well-developed and implemented GRC program for cyber security provides an integrated framework for managing risks, complying with regulations and standards, and improving the overall security perspective of an organisation. It enables effective governance, risk management, and compliance activities, mitigating cyber incidents' impact and ensuring business resilience. In this section, we will explore how to develop and implement a GRC framework. Developing and implementing a GRC framework involves various steps; we will explain each step with an appropriate example so that we can easily understand:

- **Define the scope and objectives**: This step involves determining the scope of the GRC program and defining its goals. For example, a company can implement a GRC program for its customer data management system. The objective might be to reduce cyber risks to 50% in the next 12 months while maintaining the trust of its customers. 
- **Conduct a risk assessment**: In this step, the organisation identifies and assesses its cyber risks. For example, a risk assessment might reveal that the customer data management system is vulnerable to external attacks due to weak access controls or outdated software. The organisation can then prioritize these risks and develop a risk management strategy.
- **Develop policies and procedures**: Policies and procedures are developed to guide cyber security practices within the organisation. For example, the company might establish a password policy to ensure the usage of strong passwords. They might also implement logging and monitoring system access procedures to detect suspicious activity.
- **Establish governance processes**: Governance processes ensure the GRC program is effectively managed and controlled. For example, the organisation might establish a security steering committee that meets regularly to review security risks and make decisions about security investments and priorities. Roles and responsibilities are defined to ensure everyone understands their role in the program.
- **Implement controls**: Technical and non-technical controls are implemented to mitigate risks identified in risk assessment. For example, the company might implement firewalls, [Intrusion Prevention System (IPS)](https://tryhackme.com/room/idsevasion), [Intrusion Detection System (IDS)](https://tryhackme.com/room/redteamnetsec), and [Security Information and Event Management (SIEM)](https://tryhackme.com/room/introtosiem) to prevent external attacks and impart employee training to improve security awareness and reduce the risk of human error.
- **Monitor and measure performance**: Processes are established to monitor and measure the effectiveness of the GRC program. For example, the organisation can track metrics and compliance with security policies. This information is used to identify areas for improvement and adjust the program as needed.
- **Continuously improve**: The GRC program is constantly reviewed and improved based on performance metrics, changing risk profiles, and stakeholder feedback. For example, suppose the organisation experiences a security incident. In that case, it might conduct a post-incident analysis to identify the root cause and make changes to prevent a similar incident from happening again.

An Example - GRC Framework in Financial Sector

To fully understand each component of GRC, it is necessary to understand it with real-world examples and scenarios. In the ensuing section, we will see how the financial industry implements each component of the GRC framework:

- **Governance-Related Activities:** Nominate the governance level executives, and make financial-related policies such as bank secrecy act, anti-money laundering policy, financial audit policies, financial reporting, crisis management, and many more.
- **Risk Management Activities:** Identify potential risks, their possible outcomes, and countermeasures such as financial fraud risks, fraudulent transactions through cyber-attack, stolen credentials through phishing, fake ATM cards, etc.
- **Compliance Activities:** Take measures to meet legal requirements and industry standards such as PCI DSS, GLBA, etc. Moreover, this also includes implementing correct methods like SSL/ TLS to avoid Man in the Middle (MITM) attacks, ensuring automatic patch management against unpatched software, creating awareness campaigns for users to protect them from phishing attacks, and many more.

## Privacy and Data Protection
In every sector, such as financial, healthcare, government, and industry, privacy and data protection regulations are critical as they deal with citizens' Personally Identifiable Information (PII). Privacy regulations help ensure individuals' personal information is handled and stored responsibly and ethically. They also help to establish trust, protect personal information, and maintain regulatory compliance. Moving forward, we will go through essential cardinals of the most important privacy and data protection regulations and their purpose, which will help us to understand why data protection regulations are crucial.   

General Data Protection Regulation (GDPR)

The [GDPR](https://gdpr-info.eu/) is a data protection law implemented by the EU in May 2018 to protect personal data. Personal data is "_Any data associated with an individual that can be utilised to identify them either directly or indirectly_". Key points of the law include the following:  

-  **Prior approval** must be obtained before collecting any personal data.
-  Personal data should be kept to a **minimum** and only collected when necessary.
-  **Adequate measures** are to be adopted to protect stored personal data.

![What are the benefits of GDPR](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/772ddef796e37d2c2f82c1bb9b240a36.png)  

The law applies to all business entities that conduct business in the European Union (EU) and collect/store/process the personal data of EU residents and are required to comply. It is one of the most stringent data privacy regulations worldwide and safeguards personal data during collection. Companies can only collect personal data for a legitimate reason and must inform the owner about its processing. Moreover, this also includes penalties and fines based on non-compliance in the following two tiers:  

- Tier 1: More severe violations, including unintended data collection, sharing data with third parties without consent, etc. Maximum penalty amounting to 4% of the organisation's revenue or 20 million euros (whichever is higher).
- **Tier 2**: Less severe violations, including data breach notifications, cyber policies, etc. The maximum fine for Tier 2 is 2% of the organisation's revenue or 10 million euros (whichever is higher).

Payment Card Industry Data Security Standard (PCI DSS)

[PCI DSS](https://www.pcisecuritystandards.org/) is focused on maintaining secure card transactions and protecting against data theft and fraud. It is widely used by businesses, primarily online, for card-based transactions. It was established by major credit card brands (Visa, MasterCard & American Express). It requires strict control access to cardholder information and monitoring unauthorised access, using recommended measures such as web application firewalls and encryption. You can learn more about the standard [here](https://docs-prv.pcisecuritystandards.org/PCI%20DSS/Supporting%20Document/PCI_DSS-QRG-v4_0.pdf).


## NIST
NIST 800-53  

[NIST 800-53](https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-53r5.pdf) is a publication titled "**Security and Privacy Controls for Information Systems and Organisations**",  developed by the National Institute of Standards and Technology (NIST), US, that provides a catalogue of security controls to protect the CIA triad of information systems. The publication serves as a framework for organisations to assess and enhance the security and privacy of their information systems and comply with various laws, regulations, and policies. It incorporates best practices from multiple sources, including industry standards, guidelines, and international frameworks.

  

Key Points

NIST 800-53 offers a comprehensive set of security and privacy controls that organisations can use to safeguard their operations, assets, personnel, and other organisations from various threats and risks. These include intentional attacks, unintentional errors, natural disasters, infrastructure failures, foreign intelligence activity, and privacy concerns. NIST 800-53 Revision 5 organises security controls into twenty families, each addressing a specific security concern category. You can learn more about the controls [here](https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-53r5.pdf) (Section 2.2).

![What are the different controls of NIST 800-53](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/2d3a7efe843b31609b11e53cbc1e2719.png)  

  

Developing and Implementing NIST 800-53 based Information Security Program

Among all the families, "**Program Management**" is one of the crucial control of the NIST 800-53 framework. Program Management control mandates establishing, implementing, and monitoring organisation-wide programs for information security and privacy while safeguarding the processed, stored, or transmitted through systems. To ensure program management, the following subcontrols are necessary to be implemented:

![What are different program management controls](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/43092cc2b85ee7ce4395ce6d7afd842f.png)  

Compliance Best Practices  
First and foremost, businesses must conduct a thorough **discovery process** to recognise and catalogue their data assets, information systems, and associated threats. This includes understanding **data flows, system dependencies, and potential vulnerabilities**. ![What are some of best NIST 800-53 compliance practices](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/8b7e0ab2ab4f7b72b59e6489cb893063.png)The NIST 800-53 control families must be mapped to the **identified assets and hazards**, making creating a structured approach for matching the controls to the organisation's demands easier. Thirdly, **creating a governance structure**, allocating duties, and outlining precise controls implementation and maintenance procedures are all necessary to effectively **manage** the implementation process. All measures must be **regularly monitored** and evaluated to ensure compliance. Finally, organisations should establish effective monitoring systems to identify and address security issues, conduct routine evaluations and audits, and improve control implementation. By adhering to these best practices, organisations can successfully implement NIST 800-53 and enhance their security outlook while mitigating risks effectively.

NIST 800-63B  
NIST Special Publication 800-63B is a set of guidelines created by the NIST to help organisations establish effective **digital identity practices**. Its primary focus is on authenticating and verifying the identities of individuals who access digital services, systems, and networks. The guidelines provide recommendations for different levels of identity assurance, ranging from basic to high assurance. They also offer advice on using authentication factors, including passwords, biometrics, and tokens, and securely managing and storing user credentials.


## IS management and compliance
﻿The strategic planning, execution, and continuous administration of security measures are all part of Information Security (IS) management, which **protects information assets from unauthorised access, use, disclosure, interruption, alteration, and destruction**. It involves risk assessment and identification, security controls and procedures development, incident response planning, and security awareness training. Contrarily, compliance refers to **observing information security-related legal, regulatory, contractual, and industry-specific standards**. In IS management and compliance, we will go through two key standards.  

ISO/IEC 27001

**ISO 27001** is an internationally recognised standard for requirements to **plan, develop, run, and update** an organisation's Information Security Management System (ISMS). The official ISO/IEC 27001 documents are paid for and can be purchased from this [link](https://www.iso.org/standard/27001). It was developed by International Organization for Standardization (ISO) and the International Electrotechnical Commission (IEC) and has the following core components:

- **Scope**: This specifies the ISMS's boundaries, including the covered assets and processes.
- **Information security policy**: A high-level document defining an organisation's information security approach.
- **Risk assessment**: Involves identifying and evaluating the risks to the confidentiality, integrity, and availability of the organisation's information.
- **Risk treatment**: Involves selecting and implementing controls to reduce the identified risks to an acceptable level.
- **Statement of Applicability (SoA)**: This document specifies which controls from the standard are applicable and which are not.
- **Internal audit**: This involves conducting periodic audits of the ISMS to ensure that it is operating effectively.
- **Management review**: Review the performance of ISMS at regular intervals.

![What are the benefits of ISO 27001](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/2e0517ce65aa9336144e9832fb65cce1.png)  

An ISMS built on the ISO 27001 standard requires careful design and execution. It entails exhaustively evaluating the **organisation's security procedures, detecting gaps, and conducting a thorough risk assessment**. Access control, incident response, etc., are just a few examples of the areas where clear rules and processes must be created and aligned with ISO 27001 requirements. **Leadership support and resource allocation** are also essential for the ISMS to be implemented successfully. **Regular monitoring, measurement, and continual development** are crucial to guarantee the efficacy and continued alignment of the ISMS with the organization's objectives.  

Service Organisation Control 2 (SOC 2)

**SOC 2** was developed by the American Institute of Certified Public Accountants (AICPA) as a **compliance/auditing framework**. It focuses on assessing the efficacy of a company's data security based on the CIA triad. SOC 2 can reassure customers, stakeholders, and business partners that the company has put **sufficient controls in place to safeguard its systems, data, and sensitive information**.  

  

The SOC 2 framework is essential for service providers interacting with client data or offering solutions that **process, store, or transmit sensitive data**. It assists businesses in demonstrating their dedication to upholding strict privacy and security standards. Customers frequently ask for SOC 2 reports or use them as a competitive advantage to guarantee clients that their information will be handled securely. You can learn more about it [here](https://soc2.co.uk/).

  

Important Cardinals 

- SOC 2 is an auditing standard that evaluates the usefulness of a service organisation's controls related to confidentiality, availability, integrity, and privacy.
- Independent auditors conduct SOC 2 audits to determine that security controls meet the relevant criteria.
- SOC 2 reports provide valuable information to customers, stakeholders, and regulators on a service organisation's security and privacy practices. They can be used to demonstrate that the service organisation has adequate controls to protect the data and systems it uses to process customers' information. For example, a cloud computing company that provides infrastructure services to other businesses may undergo a SOC 2 audit to demonstrate its adequate controls to protect customer data stored on its servers. The audit may cover physical security, network security, data encryption, backup and recovery, and employee training and awareness.
- The SOC 2 audit report will assess the controls in place at the cloud computing company and include any findings or recommendations for improvement. The information can be shared with customers and other stakeholders to ensure the company takes appropriate measures to protect its data and systems.

What Information Security Protection SOC 2 provides?

The primary purpose of the SOC 2 audit is to ensure that third-party service providers store and process sensitive information securely.   
  

**Planning and Undergoing a SOC 2 Audit**

The following steps can be taken by an organisation’s management team before and during an audit:

- **Determine the scope**: This may include specific systems, processes, or locations that are relevant to the security and privacy of customer data.
- **Choose a suitable auditor**: Select a qualified auditor with experience conducting SOC 2 audits for financial companies. Consider factors such as the auditor's reputation, experience, and availability.
- **Plan the audit:** Work with the auditor to plan the audit, including the audit timeline, the scope of the audit, and the audit criteria.
- **Prepare for the audit**: Prepare for the audit by reviewing your security and privacy controls, policies, and procedures. Identify any gaps or deficiencies and develop a plan to address them.
- **Conduct the audit**: The auditor will review your controls and conduct testing to assess their effectiveness. The audit may include interviews with key personnel, documentation reviews, and controls tests.
- **Receive the audit report**: Once the audit is complete, the auditor will provide a report detailing the audit results. The report may include a description of your controls, any deficiencies or gaps identified, and recommendations for improvement.

![What are the generic controls that will be checked during SOC 2 audit](https://tryhackme-images.s3.amazonaws.com/user-uploads/62a7685ca6e7ce005d3f3afe/room-content/b3ce9d297ce5934620c3686b114529d0.png)  

The above diagram shows the generic controls that will be checked during a SOC 2 audit for a financial company depending on the scope of the audit. Other than that, there are technical and specific controls, like ensuring data encryption in transit, network security, incident management, etc.


# Cyber Kill Chain

The term **kill chain** is a military concept related to the structure of an attack. It consists of target identification, decision and order to attack the target, and finally the target destruction.

Thanks to Lockheed Martin, a global security and aerospace company, that established the Cyber Kill Chain® framework for the cybersecurity industry in 2011 based on the military concept. The framework defines the steps used by adversaries or malicious actors in cyberspace. To succeed, an adversary needs to go through all phases of the Kill Chain. We will go through the attack phases and help you better understand adversaries and their techniques used in the attack to defend yourself.

So, why is it important to understand how Cyber Kill Chain works? 

The Cyber Kill Chain will help you understand and protect against ransomware attacks, security breaches as well as Advanced Persistent Threats (APTs). You can use the Cyber Kill Chain to assess your network and system security by identifying missing security controls and closing certain security gaps based on your company's infrastructure.

By understanding the Kill Chain as a SOC Analyst, Security Researcher, Threat Hunter, or Incident Responder, you will be able to recognize the intrusion attempts and understand the intruder's goals and objectives.

## Recon
To learn what reconnaissance is from the attacker's perspective, first, let's define the term **reconnaissance.** 

**Reconnaissance** is discovering and collecting information on the system and the victim. The reconnaissance phase is the planning phase for the adversaries.

**OSINT** (Open-Source Intelligence) also falls under reconnaissance. OSINT is the first step an attacker needs to complete to carry out the further phases of an attack. The attacker needs to study the victim by collecting every available piece of information on the company and its employees, such as the company's size, email addresses, phone numbers from publicly available resources to determine the best target for the attack. 

You can also find out more about OSINT from this Varonis article, ["What is OSINT?"](https://www.varonis.com/blog/what-is-osint/)

Let's look at it from the attacker's perspective, who initially doesn't know what company he wants to attack. 

Here is the scenario: A malicious attacker who names himself "Megatron" decides to conduct a very sophisticated attack that he has been planning out for years; he has been studying and researching different tools and techniques that could help him get to the last phase of the Cyber Kill Chain. But first, he needs to start from the Reconnaissance phase.

In order to operate in this phase, the attacker would need to conduct OSINT.  Let's have a look at Email harvesting.

**Email harvesting** is the process of obtaining email addresses from public, paid, or free services. An attacker can use email-address harvesting for a phishing attack (a type of social-engineering attack used to steal sensitive data, including login credentials and credit card numbers). The attacker will have a big arsenal of tools available for reconnaissance purposes. Here are some of them:

- [theHarvester](https://github.com/laramies/theHarvester) - other than gathering emails, this tool is also capable of gathering names, subdomains, IPs, and URLs using multiple public data sources 
- [Hunter.io](https://hunter.io/) - this is  an email hunting tool that will let you obtain contact information associated with the domain
- [OSINT Framework](https://osintframework.com/) - OSINT Framework provides the collection of OSINT tools based on various categories  
    

An attacker would also use social media websites such as LinkedIn, Facebook, Twitter, and Instagram to collect information on a specific victim he would want to attack or the company. The information found on social media can be beneficial for an attacker to conduct a phishing attack.

## Weaponization
After a successful reconnaissance stage, "Megatron" would work on crafting a "weapon of destruction". He would prefer not to interact with the victim directly and, instead, he will create a "weaponizer" that, according to Lockheed Martin, combines **malware** and **exploit** into a deliverable **payload**. Most attackers usually use automated tools to generate the malware or refer to the [DarkWeb](https://www.kaspersky.com/resource-center/threats/deep-web) to purchase the malware. More sophisticated actors or nation-sponsored APT (Advanced Persistent Threat Groups) would write their custom malware to make the malware sample unique and evade detection on the target.

Let's first define some terminology before we analyze the Weaponization phase.  

**Malware** is a program or software that is designed to damage, disrupt, or gain unauthorized access to a computer.

An **exploit** is a program or a code that takes advantage of the vulnerability or flaw in the application or system.

A **payload** is a malicious code that the attacker runs on the system.

Continuing with our adversary, "Megatron" chooses...  

"Megatron" chooses to buy an already written payload from someone else in the DarkWeb, so that he can spend more time on the other phases. 

In the Weaponization phase, the attacker would:

- Create an infected Microsoft Office document containing a malicious macro or VBA (Visual Basic for Applications) scripts. If you want to learn about macro and VBA, please refer to the article ["Intro to Macros and VBA For Script Kiddies" by TrustedSec](https://www.trustedsec.com/blog/intro-to-macros-and-vba-for-script-kiddies/).
- An attacker can create a malicious payload or a very sophisticated worm, implant it on the USB drives, and then distribute them in public. An example of the virus. 
- An attacker would choose Command and Control (C2) techniques for executing the commands on the victim's machine or deliver more payloads. You can read more about the C2 techniques on [MITRE ATT&CK](https://attack.mitre.org/tactics/TA0011/).
- An attacker would select a **backdoor** implant (the way to access the computer system, which includes bypassing the security mechanisms).
## Delivery
The Delivery phase is when "Megatron" decides to choose the method for transmitting the payload or the malware. He has plenty of options to choose from: 

- Phishing email: after conducting the reconnaissance and determining the targets for the attack, the malicious actor would craft a malicious email that would target either a specific person (spearphishing attack) or multiple people in the company. The email would contain a payload or malware. For example, "Megatron" would learn that Nancy from the Sales department at company A would constantly like the posts on LinkedIn from Scott, a Service Delivery Manager at company B. He would give it a second guess that they both communicate with each other over work emails. "Megatron" would craft an email using Scott's First Name and Last Name, making the domain look similar to the company Scott is working at. An attacker would then send a fake "Invoice" email to Nancy, which contains the payload.

- Distributing infected USB drives in public places like coffee shops, parking lots, or on the street. An attacker might decide to conduct a sophisticated USB Drop Attack by printing the company's logo on the USB drives and mailing them to the company while pretending to be a customer sending the USB devices as a gift. You can read about one of these similar attacks at [CSO Online "Cybercriminal group mails malicious USB dongles to targeted companies."](https://www.csoonline.com/article/3534693/cybercriminal-group-mails-malicious-usb-dongles-to-targeted-companies.html)

- Watering hole attack. A watering hole attack is a targeted attack designed to aim at a specific group of people by compromising the website they are usually visiting and then redirecting them to the malicious website of an attacker's choice. The attacker would look for a known vulnerability for the website and try to exploit it. The attacker would encourage the victims to visit the website by sending "harmless" emails pointing out the malicious URL to make the attack work more efficiently. After visiting the website, the victim would unintentionally download malware or a malicious application to their computer. This type of attack is called a drive-by download. An example can be a malicious pop-up asking to download a fake Browser extension.
## Exploitation
To gain access to the system, an attacker needs to exploit the vulnerability. In this phase, "Megatron" got a little bit creative - he created two phishing emails, one that contains a phishing link to a fake Office 365 login page and another one containing a macro attachment that would execute ransomware when the victim opens it. "Megatron" successfully delivered his exploits and got two victims to click on the malicious link and open the malicious file.  

After gaining access to the system, the malicious actor could exploit software, system, or server-based vulnerabilities to escalate the privileges or move laterally through the network. According to [CrowdStrike](https://www.crowdstrike.com/cybersecurity-101/lateral-movement/), **lateral movement** refers to the techniques that a malicious actor uses after gaining initial access to the victim's machine to move deeper into a network to obtain sensitive data. 

If you want to learn more about server-based or web-based vulnerabilities, please refer to the TryHackMe room [OWASP Top 10](https://tryhackme.com/room/owasptop10).

The attacker might also apply a "Zero-day Exploit" in this stage. According to [FireEye](https://www.fireeye.com/current-threats/what-is-a-zero-day-exploit.html), _"the zero-day exploit or a zero-day vulnerability is an unknown exploit in the wild that exposes a vulnerability in software or hardware and can create complicated problems well before anyone realizes something is wrong. A zero-day exploit leaves NO opportunity for detection at the beginning."_

These are examples of how an attacker carries out exploitation:

- The victim triggers the exploit by opening the email attachment or clicking on a malicious link.
- Using a zero-day exploit.
- Exploit software, hardware, or even human vulnerabilities. 
- An attacker triggers the exploit for server-based vulnerabilities.

## Installation
As you have learned from the Weaponization phase, the backdoor lets an attacker bypass security measures and hide the access. A backdoor is also known as an access point. 

Once the attacker gets access to the system, he would want to reaccess the system if he loses the connection to it or if he got detected and got the initial access removed, or if the system is later patched. He will no longer have access to it. That is when the attacker needs to install a **[persistent backdoor](https://www.offensive-security.com/metasploit-unleashed/persistent-backdoors/).** A persistent backdoor will let the attacker access the system he compromised in the past. You can check out the [Windows Persistence Room](https://tryhackme.com/room/windowslocalpersistence) on TryHackMe to learn how an attacker can achieve persistence on Windows. 

The persistence can be achieved through:

- Installing a **web shell** on the webserver. A web shell is a malicious script written in web development programming languages such as ASP, PHP, or JSP used by an attacker to maintain access to the compromised system. Because of the web shell simplicity and file formatting (.php, .asp, .aspx, .jsp, etc.) can be difficult to detect and might be classified as benign. You may check out this great article released by [Microsoft](https://www.microsoft.com/security/blog/2021/02/11/web-shell-attacks-continue-to-rise/) on various web shell attacks.
- Installing a backdoor on the victim's machine. For example, the attacker can use [Meterpreter](https://www.offensive-security.com/metasploit-unleashed/meterpreter-backdoor/) to install a backdoor on the victim's machine. Meterpreter is a Metasploit Framework payload that gives an interactive shell from which an attacker can interact with the victim's machine remotely and execute the malicious code.
- Creating or modifying Windows services. This technique is known as [T1543.003](https://attack.mitre.org/techniques/T1543/003/) on MITRE ATT&CK (MITRE ATT&CK® is a knowledge base of adversary tactics and techniques based on real-world scenarios). An attacker can create or modify the Windows services to execute the malicious scripts or payloads regularly as a part of the persistence. An attacker can use the tools like **sc.exe** (sc.exe lets you Create, Start, Stop, Query, or Delete any Windows Service) and [Reg](https://attack.mitre.org/software/S0075/) to modify service configurations. The attacker can also **[masquerade](https://attack.mitre.org/techniques/T1036/)** the malicious payload by using a service name that is known to be related to the Operating System or legitimate software. 
- Adding the entry to the "run keys" for the malicious payload in the Registry or the Startup Folder. By doing that, the payload will execute each time the user logs in on the computer. According to MITRE ATT&CK, there is a startup folder location for individual user accounts and a system-wide startup folder that will be checked no matter what user account logs in.

You can read more about the Registry Run Keys / Startup Folder persistence on one of the [MITRE ATT&CK techniques](https://attack.mitre.org/techniques/T1547/001/).

In this phase, the attacker can also use the **[Timestomping](https://attack.mitre.org/techniques/T1070/006/)** technique to avoid detection by the forensic investigator and also to make the malware appear as a part of a legitimate program. The Timestomping technique lets an attacker modify the file's timestamps, including the modify, access, create and change times.

## Command and Control
After getting persistence and executing the malware on the victim's machine, "Megatron" opens up the C2 (Command and Control) channel through the malware to remotely control and manipulate the victim. This term is also known as **C&C or C2 Beaconing** as a type of malicious communication between a C&C server and malware on the infected host. The infected host will consistently communicate with the C2 server; that is also where the beaconing term came from. 

The compromised endpoint would communicate with an external server set up by an attacker to establish a command & control channel. After establishing the connection,  the attacker has full control of the victim's machine. Until recently, IRC (Internet Relay Chat) was the traditional C2 channel used by attackers. This is no longer the case, as modern security solutions can easily detect malicious IRC traffic. 

The most common C2 channels used by adversaries nowadays:

- The protocols HTTP on port 80 and HTTPS on port 443 - this type of beaconing blends the malicious traffic with the legitimate traffic and can help the attacker evade firewalls.    
    
- DNS (Domain Name Server). The infected machine makes constant DNS requests to the DNS server that belongs to an attacker, this type of C2 communication is also known as DNS Tunneling.

Important to note that an adversary or another compromised host can be the owner of the C2 infrastructure.


## Exfiltration
After going through six phases of the attack, "Megatron" can finally achieve his goals, which means taking action on the original objectives. With hands-on keyboard access, the attacker can achieve the following: 

- Collect the credentials from users.
- Perform privilege escalation (gaining elevated access like domain administrator access from a workstation by exploiting the misconfiguration).
- Internal reconnaissance (for example, an attacker gets to interact with internal software to find its vulnerabilities).
- Lateral movement through the company's environment.
- Collect and exfiltrate sensitive data.
- Deleting the backups and shadow copies. Shadow Copy is a Microsoft technology that can create backup copies, snapshots of computer files, or volumes. 
- Overwrite or corrupt data.

![[Pasted image 20250128120755.png]]

## Conclusion
Cyber Kill Chain can be a great tool to improve network defence. Is it perfect and can it be the only tool to rely on? No. 

The traditional Cyber Kill Chain or Lockheed Martin Cyber Kill Chain was last modified in 2011, which, if you remember, is the date of its establishment. The absence of updates and modifications creates security gaps. 

The traditional Cyber Kill Chain was designed to secure the network perimeter and protect against malware threats. But the cybersecurity threats have developed drastically nowadays, and adversaries are combining multiple TTP (tactics, techniques, and procedures) to achieve their goal. Adversaries are capable of defeating threat intelligence by modifying the file hashes and IP addresses. Security solutions companies are developing technologies like AI (Artificial Intelligence) and different algorithms to detect even slight and suspicious changes. 

Since the main focus of the framework is on malware delivery and network security, the traditional Cyber Kill Chain will not be able to identify **Insider Threats**. According to [CISA](https://www.cisa.gov/defining-insider-threats), _"The Insider Threat is the potential for an insider to use their authorized access or understanding of an organization to harm that organization."_

We recommend not only relying on the traditional Cyber Kill Chain model but also referring to [MITRE ATT&CK](https://attack.mitre.org/) as well as [Unified Kill Chain](https://unifiedkillchain.com/) to apply a more comprehensive approach to your defence methodologies.