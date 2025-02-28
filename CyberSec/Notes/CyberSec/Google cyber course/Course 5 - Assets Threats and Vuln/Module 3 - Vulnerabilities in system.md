![[Pasted image 20250113193727.png]]
![[Pasted image 20250113193756.png]]
![[Pasted image 20250113193811.png]]
![[Pasted image 20250113193832.png]]
![[Pasted image 20250113193933.png]]
![[Pasted image 20250113203045.png]]
![[Pasted image 20250113203143.png]]
![[Pasted image 20250113203157.png]]
![[Pasted image 20250113203207.png]]
![[Pasted image 20250113203229.png]]
![[Pasted image 20250113203253.png]]
![[Pasted image 20250113203330.png]]

# The OWASP Top 10

To prepare for future risks, security professionals need to stay informed. Previously, you learned about the **CVE® list**, an openly accessible dictionary of known vulnerabilities and exposures. The CVE® list is an important source of information that the global security community uses to share information with each other.

In this reading, you’ll learn about another important resource that security professionals reference, the Open Web Application Security Project, recently renamed Open Worldwide Application Security Project® (OWASP). You’ll learn about OWASP’s role in the global security community and how companies use this resource to focus their efforts.

## What is OWASP?

OWASP is a nonprofit foundation that works to improve the security of software. OWASP is an open platform that security professionals from around the world use to share information, tools, and events that are focused on securing the web.

## The OWASP Top 10

One of OWASP’s most valuable resources is the OWASP Top 10. The organization has published this list since 2003 as a way to spread awareness of the web’s most targeted vulnerabilities. The Top 10 mainly applies to new or custom made software. Many of the world's largest organizations reference the OWASP Top 10 during application development to help ensure their programs address common security mistakes.

**Pro tip:** OWASP’s Top 10 is updated every few years as technologies evolve. Rankings are based on how often the vulnerabilities are discovered and the level of risk they present.

**Note:** Auditors also use the OWASP Top 10 as one point of reference when checking for regulatory compliance.

## Common vulnerabilities

Businesses often make critical security decisions based on the vulnerabilities listed in the OWASP Top 10. This resource influences how businesses design new software that will be on their network, unlike the CVE® list, which helps them identify improvements to existing programs. These are the most regularly listed vulnerabilities that appear in their rankings to know about:

### **Broken access control**

Access controls limit what users can do in a web application. For example, a blog might allow visitors to post comments on a recent article but restricts them from deleting the article entirely. Failures in these mechanisms can lead to unauthorized information disclosure, modification, or destruction. They can also give someone unauthorized access to other business applications.

### **Cryptographic failures**

Information is one of the most important assets businesses need to protect. Privacy laws such as General Data Protection Regulation (GDPR) require sensitive data to be protected by effective encryption methods. Vulnerabilities can occur when businesses fail to encrypt things like personally identifiable information (PII). For example, if a web application uses a weak hashing algorithm, like MD5, it’s more at risk of suffering a data breach.

### **Injection**

Injection occurs when malicious code is inserted into a vulnerable application. Although the app appears to work normally, it does things that it wasn’t intended to do. Injection attacks can give threat actors a backdoor into an organization’s information system. A common target is a website’s login form. When these forms are vulnerable to injection, attackers can insert malicious code that gives them access to modify or steal user credentials.

### **Insecure design**

Applications should be designed in such a way that makes them resilient to attack. When they aren’t, they’re much more vulnerable to threats like injection attacks or malware infections. Insecure design refers to a wide range of missing or poorly implemented security controls that should have been programmed into an application when it was being developed.

### **Security misconfiguration**

Misconfigurations occur when security settings aren’t properly set or maintained. Companies use a variety of different interconnected systems. Mistakes often happen when those systems aren’t properly set up or audited. A common example is when businesses deploy equipment, like a network server, using default settings. This can lead businesses to use settings that fail to address the organization's security objectives.

### **Vulnerable and outdated components**

Vulnerable and outdated components is a category that mainly relates to application development. Instead of coding everything from scratch, most developers use open-source libraries to complete their projects faster and easier. This publicly available software is maintained by communities of programmers on a volunteer basis. Applications that use vulnerable components that have not been maintained are at greater risk of being exploited by threat actors.

### **Identification and authentication failures**

Identification is the keyword in this vulnerability category. When applications fail to recognize who should have access and what they’re authorized to do, it can lead to serious problems. For example, a home Wi-Fi router normally uses a simple login form to keep unwanted guests off the network. If this defense fails, an attacker can invade the homeowner’s privacy.

### **Software and data integrity failures**

Software and data integrity failures are instances when updates or patches are inadequately reviewed before implementation. Attackers might exploit these weaknesses to deliver malicious software. When that occurs, there can be serious downstream effects. Third parties are likely to become infected if a single system is compromised, an event known as a supply chain attack.

A famous example of a supply chain attack is the [SolarWinds cyber attack (2020)](https://www.gao.gov/blog/solarwinds-cyberattack-demands-significant-federal-and-private-sector-response-infographic)

where hackers injected malicious code into software updates that the company unknowingly released to their customers.

### **Security logging and monitoring failures**

In security, it’s important to be able to log and trace back events. Having a record of events like user login attempts is critical to finding and fixing problems. Sufficient monitoring and incident response is equally important.

### **Server-side request forgery**

Companies have public and private information stored on web servers. When you use a hyperlink or click a button on a website, a request is sent to a server that should validate who you are, fetch the appropriate data, and then return it to you.

![A hacker using their victim's computer to steal data from a web server.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/DT6Hkom1RcugsbS_BFgoLw_7e1de97a7fdc4e00b7c9b14a0ad5fcf1_Pfjezx6XbwJ_TAJbWmCtLMpwLX4YD2xP4Se2IJeQF4uTD6BtqNXlcpObbGHeJuzWlxr5A3WqWQzZ2K6E6kFLsX3JiI0bxbFtWFjNUCxZTgs7ftpEgVEcI87zvBxN2flvGXs37nW_RJF0QVLY7798FCXB9pAH_uUI3zYLbXOiOpGcdhti00aMTwl7xbMFpg?expiry=1736899200000&hmac=nwdX4fOjEpvMhG2HMf3rYjoWsJB_NcivNxe4LNQnBE4)

Server-side request forgeries (SSRFs) are when attackers manipulate the normal operations of a server to read or update other resources on that server. These are possible when an application on the server is vulnerable. Malicious code can be carried by the vulnerable app to the host server that will fetch unauthorized data.

## Key takeaways

Staying informed and maintaining awareness about the latest cybersecurity trends can be a useful way to help defend against attacks and prepare for future risks in your security career. [OWASP’s Top 10](https://owasp.org/www-project-top-ten/)

is a useful resource where you can learn more about these vulnerabilities.


# Open source intelligence

Cyber attacks can sometimes be prevented with the right information, which starts with knowing where your systems are vulnerable. Previously, you learned that the CVE® list and scanning tools are two useful ways of finding weaknesses. But, there are other ways to identify vulnerabilities and threats.

In this reading, you’ll learn about open-source intelligence, commonly known as OSINT. OSINT is the collection and analysis of information from publicly available sources to generate usable intelligence. It's commonly used to support cybersecurity activities, like identifying potential threats and vulnerabilities. You'll learn why open-source intelligence is gathered and how it can improve cybersecurity. You’ll also learn about commonly used resources and tools for gathering information and intelligence.

## Information vs intelligence

The terms intelligence and information are often used interchangeably, making it easy to mix them up. Both are important aspects of cybersecurity that differ in their focus and objectives.

_Information_ refers to the collection of raw data or facts about a specific subject. _Intelligence_, on the other hand, refers to the analysis of information to produce knowledge or insights that can be used to support decision-making.

For example, new information might be released about an update to the operating system (OS) that's installed on your organization's workstations. Later, you might find that new cyber threats have been linked to this new update by researching multiple cybersecurity news resources. The analysis of this information can be used as intelligence to guide your organization's decision about installing the OS updates on employee workstations.

In other words, intelligence is derived from information through the process of analysis, interpretation, and integration. Gathering information and intelligence are both important aspects of cybersecurity.

## Intelligence improves decision-making 

Businesses often use information to gain insights into the behavior of their customers. Insights, or intelligence, can then be used to improve their decision making. In security, open-source information is used in a similar way to gain insights into threats and vulnerabilities that can pose risks to an organization.

OSINT plays a significant role in **information security (InfoSec)**, which is the practice of keeping data in all states away from unauthorized users.

For example, a company's InfoSec team is responsible for protecting their network from potential threats. They might utilize OSINT to monitor online forums and hacker communities for discussions about emerging vulnerabilities. If they come across a forum post discussing a newly discovered weakness in a popular software that the company uses, the team can quickly assess the risk, prioritize patching efforts, and implement necessary safeguards to prevent an attack.

Here are some of the ways OSINT can be used to generate intelligence:

- To provide insights into cyber attacks
    
- To detect potential data exposures
    
- To evaluate existing defenses
    
- To identify unknown vulnerabilities
    

Collecting intelligence is sometimes part of the vulnerability management process. Security teams might use OSINT to develop profiles of potential targets and make data driven decisions on improving their defenses.

## OSINT tools

There's an enormous amount of open-source information online. Finding relevant information that can be used to gather intelligence is a challenge. Information can be gathered from a variety of sources, such as search engines, social media, discussion boards, blogs, and more. Several tools also exist that can be used in your intelligence gathering process. Here are just a few examples of tools that you can explore:

- [VirusTotal](https://www.virustotal.com/gui/home/upload)
    

- is a service that allows anyone to analyze suspicious files, domains, URLs, and IP addresses for malicious content.
    
- [MITRE ATT&CK®](https://attack.mitre.org/)
    
- is a knowledge base of adversary tactics and techniques based on real-world observations.
    
- [OSINT Framework](https://osintframework.com/)
    
- is a web-based interface where you can find OSINT tools for almost any kind of source or platform.
    
- [Have I been Pwned](https://haveibeenpwned.com/)
    

- is a tool that can be used to search for breached email accounts.
    

There are numerous other OSINT tools that can be used to find specific types of information. Remember, information can be gathered from a variety of sources. Ultimately, it's your responsibility to thoroughly research any available information that's relevant to the problem you’re trying to solve.

## Key takeaways

Gathering information and intelligence are important aspects of cybersecurity. OSINT is used to make evidence-based decisions that can be used to prevent attacks. There’s so much information available, which is why it's important for security professionals to be skilled with searching for information. Having familiarity with popular OSINT tools and resources will make your research easier when gathering information and collecting intelligence.


# Vulnerability assessment
![[Pasted image 20250113203738.png]]
![[Pasted image 20250113203830.png]]

# Approaches to vulnerability scanning

Previously, you learned about a **vulnerability assessment**, which is the internal review process of an organization's security systems. An organization performs vulnerability assessments to identify weaknesses and prevent attacks. Vulnerability scanning tools are commonly used to simulate threats by finding vulnerabilities in an attack surface. They also help security teams take proactive steps towards implementing their remediation strategy.

Vulnerability scanners are important tools that you'll likely use in the field. In this reading, you’ll explore how vulnerability scanners work and the types of scans they can perform.

## What is a vulnerability scanner?

A **vulnerability scanner** is software that automatically compares known vulnerabilities and exposures against the technologies on the network. In general, these tools scan systems to find misconfigurations or programming flaws.

Scanning tools are used to analyze each of the five attack surfaces that you learned about in [the video about the defense in depth strategy](https://www.coursera.org/learn/assets-threats-and-vulnerabilities/lecture/IdvXj/defense-in-depth-strategy)

:

1. **Perimeter layer**, like authentication systems that validate user access
    
2. **Network layer**, which is made up of technologies like network firewalls and others
    
3. **Endpoint layer**, which describes devices on a network, like laptops, desktops, or servers
    
4. **Application layer**, which involves the software that users interact with
    
5. **Data layer**, which includes any information that’s stored, in transit, or in use
    

When a scan of any layer begins, the scanning tool compares the findings against databases of security threats. At the end of the scan, the tool flags any vulnerabilities that it finds and adds them to its reference database. Each scan adds more information to the database, helping the tool be more accurate in its analysis.

**Note:** Vulnerability databases are also routinely updated by the company that designed the scanning software.

## Performing scans

Vulnerability scanners are meant to be non-intrusive. Meaning, they don’t break or take advantage of a system like an attacker would. Instead, they simply scan a surface and alert you to any potentially unlocked doors in your systems.

**Note:** While vulnerability scanners are non-intrusive, there are instances when a scan can inadvertently cause issues, like crash a system.

There are a few different ways that these tools are used to scan a surface. Each approach corresponds to the pathway a threat actor might take. Next, you can explore each type of scan to get a clearer picture of this. 

**External vs. internal**

External and internal scans simulate an attacker's approach.

_External scans_ test the perimeter layer outside of the internal network. They analyze outward facing systems, like websites and firewalls. These kinds of scans can uncover vulnerable things like vulnerable network ports or servers.

_Internal scans_ start from the opposite end by examining an organization's internal systems. For example, this type of scan might analyze application software for weaknesses in how it handles user input.

### **Authenticated vs. unauthenticated**

Authenticated and unauthenticated scans simulate whether or not a user has access to a system.

_Authenticated scans_ might test a system by logging in with a real user account or even with an admin account. These service accounts are used to check for vulnerabilities, like broken access controls.

_Unauthenticated scans_ simulate external threat actors that do not have access to your business resources. For example, a scan might analyze file shares within the organization that are used to house internal-only documents. Unauthenticated users should receive "access denied" results if they tried opening these files. However, a vulnerability would be identified if you were able to access a file.

### **Limited vs. comprehensive**

Limited and comprehensive scans focus on particular devices that are accessed by internal and external users.

_Limited scans_ analyze particular devices on a network, like searching for misconfigurations on a firewall.

_Comprehensive scans_ analyze all devices connected to a network. This includes operating systems, user databases, and more.

**Pro tip:** Discovery scanning should be done prior to limited or comprehensive scans. Discovery scanning is used to get an idea of the computers, devices, and open ports that are on a network.

## Key takeaways

Finding vulnerabilities requires thinking of all possibilities. Vulnerability scans vary depending on the surfaces that an organization is evaluating. Usually, seasoned security professionals lead the effort of configuring and performing these types of scans to create a profile of a company’s security posture. However, analysts also play an important role in the process. The results of a vulnerability scan often lead to renewed compliance efforts, procedural changes, and system patching. Understanding the objectives of common types of vulnerability scans will help you participate in these proactive security exercises whenever possible.

**Tip:** To explore vulnerability scanner software commonly used in the cybersecurity industry, in your preferred browser enter search terms similar to “popular vulnerability scanner software” and/or “open source vulnerability scanner software used in cybersecurity”.


# The importance of updates

At some point in time, you may have wondered, “Why do my devices constantly need updating?” For consumers, updates provide improvements to performance, stability, and even new features! But from a security standpoint, they serve a specific purpose. Updates allow organizations to address security vulnerabilities that can place their users, devices, and networks at risk.

In a video, you learned that updates fit into every security team’s remediation strategy. They usually take place after a **vulnerability assessment**, which is the internal review process of an organization's security systems. In this reading, you’ll learn what updates do, how they’re delivered, and why they’re important to cybersecurity.

## Patching gaps in security

An outdated computer is a lot like a house with unlocked doors. Malicious actors use these gaps in security the same way, to gain unauthorized access. Software updates are similar to locking the doors to keep them out.

A **patch update** is a software and operating system update that addresses security vulnerabilities within a program or product. Patches usually contain bug fixes that address common security vulnerabilities and exposures.

**Note:** Ideally, patches address common vulnerabilities and exposures before malicious hackers find them. However, patches are sometimes developed as a result of a **zero-day**, which is an exploit that was previously unknown.

## Common update strategies

When software updates become available, clients and users have two installation options:

- Manual updates
    
- Automatic updates
    

As you’ll learn, each strategy has both benefits and disadvantages.

### **Manual updates**

A manual deployment strategy relies on IT departments or users obtaining updates from the developers. Home office or small business environments might require you to find, download, and install updates yourself. In enterprise settings, the process is usually handled with a configuration management tool. These tools offer a range of options to deploy updates, like to all clients on your network or a select group of users.  

**Advantage:** An advantage of manual update deployment strategies is control. That can be useful if software updates are not thoroughly tested by developers, leading to instability issues.

**Disadvantage:** A drawback to manual update deployments is that critical updates can be forgotten or disregarded entirely.

### **Automatic updates**

An automatic deployment strategy takes the opposite approach. With this option, finding, downloading, and installing updates can be done by the system or application.

**Pro tip:** The Cybersecurity and Infrastructure Security Agency (CISA) recommends using automatic options whenever they’re available.

Certain permissions need to be enabled by users or IT groups before updates can be installed, or pushed, when they're available. It is up to the developers to adequately test their patches before release.

**Advantage:** An advantage to automatic updates is that the deployment process is simplified. It also keeps systems and software current with the latest, critical patches.

**Disadvantage:** A drawback to automatic updates is that instability issues can occur if the patches were not thoroughly tested by the vendor. This can result in performance problems and a poor user experience.

## End-of-life software

Sometimes updates are not available for a certain type of software known as end-of-life (EOL) software. All software has a lifecycle. It begins when it’s produced and ends when a newer version is released. At that point, developers must allocate resources to the newer versions, which leads to EOL software. While the older software is still useful, the manufacturer no longer supports it. 

**Note:** Patches and updates are very different from upgrades. _Upgrades_ refer to completely new versions of hardware or software that can be purchased.

[CISA recommends discontinuing the use of EOL software](https://www.cisa.gov/news-events/news/understanding-patches-and-software-updates)

because it poses an unfixable risk to systems. But, this recommendation is not always followed. Replacing EOL technology can be costly for businesses and individual users.

The risks that EOL software presents continues to grow as more connected devices enter the marketplace. For example, there are billions of Internet of Things (IoT) devices, like smart light bulbs, connected to home and work networks. In some business settings, all an attacker needs is a single unpatched device to gain access to the network and cause problems.

## Key takeaways

Updating software and patching vulnerabilities is an important practice that everyone should participate in. Unfortunately, that’s not always the case. Many of the biggest cyber attacks in the world might have been prevented if systems were kept updated. One example is the WannaCry attack of 2017. The attack affected computers in more than 150 countries and caused an estimated $4 billion dollars in damages. Researchers have since found that WannaCry could have been prevented if the infected systems were up-to-date with a security patch that was made available months before the attack. Keeping software updated requires effort. However, the benefits they provide make them worthwhile.


# Penetration testing

An effective security plan relies on regular testing to find an organization's weaknesses. Previously, you learned that **vulnerability assessments**, the internal review process of an organization's security systems, are used to design defense strategies based on system weaknesses. In this reading, you'll learn how security teams evaluate the effectiveness of their defenses using penetration testing.

## Penetration testing

A **penetration test**, or pen test, is a simulated attack that helps identify vulnerabilities in systems, networks, websites, applications, and processes. The simulated attack in a pen test involves using the same tools and techniques as malicious actors in order to mimic a real life attack. Since a pen test is an authorized attack, it is considered to be a form of ethical hacking. Unlike a vulnerability assessment that finds weaknesses in a system's security, a pen test exploits those weaknesses to determine the potential consequences if the system breaks or gets broken into by a threat actor.

For example, the cybersecurity team at a financial company might simulate an attack on their banking app to determine if there are weaknesses that would allow an attacker to steal customer information or illegally transfer funds. If the pen test uncovers misconfigurations, the team can address them and improve the overall security of the app.  

**Note:** Organizations that are regulated by PCI DSS, HIPAA, or GDPR must routinely perform penetration testing to maintain compliance standards.

## Learning from varied perspectives

These authorized attacks are performed by pen testers who are skilled in programming and network architecture. Depending on their objectives, organizations might use a few different approaches to penetration testing:

- Red team tests _simulate attacks_ to identify vulnerabilities in systems, networks, or applications.
    
- Blue team tests focus on _defense_ _and incident response_ to validate an organization's existing security systems.
    
- Purple team tests are _collaborative_, focusing on improving the security posture of the organization by combining elements of red and blue team exercises.
    

Red team tests are commonly performed by independent pen testers who are hired to evaluate internal systems. Although, cybersecurity teams may also have their own pen testing experts. Regardless of the approach, penetration testers must make an important decision before simulating an attack: _How much access and information do I need?_

## Penetration testing strategies

There are three common penetration testing strategies: 

- **Open-box testing** is when the tester has the same privileged access that an internal developer would have—information like system architecture, data flow, and network diagrams. This strategy goes by several different names, including internal, full knowledge, white-box, and clear-box penetration testing.
    
- **Closed-box testing** is when the tester has little to no access to internal systems—similar to a malicious hacker. This strategy is sometimes referred to as external, black-box, or zero knowledge penetration testing.
    
- **Partial knowledge testing** is when the tester has limited access and knowledge of an internal system—for example, a customer service representative. This strategy is also known as gray-box testing.
    

Closed box testers tend to produce the most accurate simulations of a real-world attack. Nevertheless, each strategy produces valuable results by demonstrating how an attacker might infiltrate a system and what information they could access.

## Becoming a penetration tester

Penetration testers are in-demand in the fast growing field of cybersecurity. All of the skills you’re learning in this program can help you advance towards a career in pen testing:

- Network and application security
    
- Experience with operating systems, like Linux
    
- Vulnerability analysis and threat modeling
    
- Detection and response tools
    
- Programming languages, like Python and BASH
    
- Communication skills
    

Programming skills are very helpful in penetration testing because it's often performed on software and IT systems. With enough practice and dedication, cybersecurity professionals at any level can develop the skills needed to be a pen tester.

### **Bug bounty programs**

Organizations commonly run bug bounty programs which offer freelance pen testers financial rewards for finding and reporting vulnerabilities in their products. Bug bounties are great opportunities for amateur security professionals to participate and grow their skills. 

**Pro tip:** [HackerOne](https://hackerone.com/bug-bounty-programs)

is a community of ethical hackers where you can find active bug bounties to participate in.

## Key takeaways

A major risk for organizations is malicious hackers breaking into their systems. Penetration testing is another way for organizations to secure their systems. Security teams use these simulated attacks to get a clearer picture of weaknesses in their defenses. There’s a growing need for specialized security professionals in this field. Even if you start out assisting with these activities, there’s plenty of opportunities to grow and learn the skills to be a pen tester.


![[Pasted image 20250113210305.png]]
# Approach cybersecurity with an attacker mindset

Cybersecurity is a continuously changing field. It's a fast-paced environment where new threats and innovative technologies can disrupt your plans at a moment's notice. As a security professional, it’s up to you to be prepared by anticipating change.

This all starts with identifying vulnerabilities. In a video, you learned about the importance of **vulnerability assessments,** the internal review process of an organization's security systems. In this reading, you will learn how you can use the findings of a vulnerability assessment proactively by analyzing them from the perspective of an attacker.

## Being prepared for anything

Having a plan should things go wrong is important. But how do you figure out what to plan for? In this field, teams often conduct simulations of things that can go wrong as part of their vulnerability management strategy. One way this is done is by applying an attacker mindset to the weaknesses they discover.

Applying an attacker mindset is a lot like conducting an experiment. It's about causing problems in a controlled environment and evaluating the outcome to gain insights. Adopting an attacker mindset is a beneficial skill in security because it offers a different perspective about the challenges you're trying to solve. The insights you gain can be valuable when it's time to establish a security plan or modify an existing one.

![A group of people securing using different technologies.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/OEVXn5TMSE2lS2yaiOiCsQ_19cd9695e35c4cf682148d737815fff1_S36G002.png?expiry=1736899200000&hmac=nru2X8kh4d3pHwsTyS2djFppNrGCUux-t-xnJQBYPmA)

## Simulating threats

One method of applying an attacker mindset is using attack simulations. These activities are normally performed in one of two ways: _proactively_ and _reactively_. Both approaches share a common goal, which is to make systems safer.

- _Proactive simulations_ assume the role of an attacker by exploiting vulnerabilities and breaking through defenses. This is sometimes called a red team exercise.
    
- _Reactive simulations_ assume the role of a defender responding to an attack. This is sometimes called a blue team exercise.
    

Each kind of simulation is a team effort that you might be involved with as an analyst.

Proactive teams tend to spend more time planning their attacks than performing them. If you find yourself engaged in one of these exercises, your team will likely deploy a range of tactics. For example, they might persuade staff into disclosing their login credentials using fictitious emails to evaluate security awareness at the company.

On the other hand, reactive teams dedicate their efforts to gathering information about the assets they're protecting. This is commonly done with the assistance of vulnerability scanning tools. 

## Scanning for trouble

You might recall that a **vulnerability scanner** is software that automatically compares existing common vulnerabilities and exposures against the technologies on the network. Vulnerability scanners are frequently used in the field. Security teams employ a variety of scanning techniques to uncover weaknesses in their defenses. Reactive simulations often rely on the results of a scan to weigh the risks and determine ways to remediate a problem.

For example, a team conducting a reactive simulation might perform an external vulnerability scan of their network. The entire exercise might follow the steps you learned in a video about vulnerability assessments:

- **Identification:** A vulnerable server is flagged because it's running an outdated operating system (OS).
    
- **Vulnerability analysis:** Research is done on the outdated OS and its vulnerabilities.
    
- **Risk assessment:** After doing your due diligence, the severity of each vulnerability is scored and the impact of not fixing it is evaluated.
    
- **Remediation**: Finally, the information that you’ve gathered can be used to address the issue.
    

During an activity like this, you’ll often produce a report of your findings. These can be brought to the attention of service providers or your supervisors. Clearly communicating the results of these exercises to others is an important skill to develop as a security professional.

## Finding innovative solutions

Many security controls that you’ve learned about were created as a reactive response to risks. That’s because criminals are continually looking for ways to bypass existing defenses. Effectively applying an attacker mindset will require you to stay knowledgeable of security trends and emerging technologies.

**Pro tip:** Resources like [NISTs National Vulnerability Database (NVD)](https://nvd.nist.gov/)

can help you remain current on common vulnerabilities.

## Key takeaways

Vulnerability assessments are an important part of security risk planning. As an analyst, you’ll likely participate in proactive and reactive simulations of these activities. Preparing yourself by researching common vulnerabilities only goes so far. It’s equally important that you stay informed about new technologies to be able to think with an innovative mindset.


# Types of threat actors

Anticipating attacks is an important skill you’ll need to be an effective security professional. Developing this skill requires you to have an open and flexible mindset about where attacks can come from. Previously, you learned about **attack surfaces**, which are all the potential vulnerabilities that a threat actor could exploit.

Networks, servers, devices, and staff are examples of attack surfaces that can be exploited. Security teams of all sizes regularly find themselves defending these surfaces due to the expanding digital landscape. The key to defending any of them is to limit access to them.

In this reading, you’ll learn more about threat actors and the types of risks they pose. You’ll also explore the most common features of an attack surface that threat actors can exploit.

## Threat actors

A **threat actor** is any person or group who presents a security risk. This broad definition refers to people inside and outside an organization. It also includes individuals who intentionally pose a threat, and those that accidentally put assets at risk. That’s a wide range of people!

Threat actors are normally divided into five categories based on their motivations:

- **Competitors** refers to rival companies who pose a threat because they might benefit from leaked information.
    
- **State actors** are government intelligence agencies.
    
- **Criminal syndicates** refer to organized groups of people who make money from criminal activity.
    
- **Insider threats** can be any individual who has or had authorized access to an organization’s resources. This includes employees who accidentally compromise assets or individuals who purposefully put them at risk for their own benefit.
    
- **Shadow IT** refers to individuals who use technologies that lack IT governance. A common example is when an employee uses their personal email to send work-related communications.
    

In the digital attack surface, these threat actors often gain unauthorized access by hacking into systems. By definition, a **hacker** is any person who uses computers to gain unauthorized access to computer systems, networks, or data. Similar to the term threat actor, hacker is also an umbrella term. When used alone, the term fails to capture a threat actor’s intentions.

![A group of hackers on a world map carrying assets.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/qM0djAhuTyOsCcLU2xnv2g_59c9d1de562a41ffa500876153431ef1_70bQeQW49S1vPJtUBoCwehHzeSO1vz8jwpAMsz5iZOPFHWLu11seDtKAQrT6geI7ih0yA03D167TjhrCHJz8yxxAJhHuGMIz9LMVt1VsDC0wT7kalG8M-32iThBCM1dxiTZJtVnGZvfbHhbKgHleGCaeRWwMOQIrXPiqw3EHCFiKOYd5LN_jivQc82M69Q?expiry=1736899200000&hmac=rcLFTROlIecCsJa-B76HyQyNJ-XiGLVnbsB_ZFXFCFU)

### **Types of hackers**

Because the formal definition of a hacker is broad, the term can be a bit ambiguous. In security, it applies to three types of individuals based on their intent:

1. Unauthorized hackers 
    
2. Authorized, or ethical, hackers
    
3. Semi-authorized hackers
    

An unauthorized hacker, or unethical hacker, is an individual who uses their programming skills to commit crimes. Unauthorized hackers are also known as malicious hackers. Skill level ranges widely among this category of hacker. For example, there are hackers with limited skills who can’t write their own malicious software, sometimes called _script kiddies_**.** Unauthorized hackers like this carry out attacks using pre-written code that they obtain from other, more skilled hackers.

Authorized, or ethical, hackers refer to individuals who use their programming skills to improve an organization's overall security. These include internal members of a security team who are concerned with testing and evaluating systems to secure the attack surface. They also include external security vendors and freelance hackers that some companies incentivize to find and report vulnerabilities, a practice called **bug bounty** programs.

Semi-authorized hackers typically refer to individuals who might violate ethical standards, but are not considered malicious. For example, a **hacktivist** is a person who might use their skills to achieve a political goal. One might exploit security vulnerabilities of a public utility company to spread awareness of their existence. The intentions of these types of threat actors is often to expose security risks that should be addressed before a malicious hacker finds them.

## Advanced persistent threats

Many malicious hackers find their way into a system, cause trouble, and then leave. But on some occasions, threat actors stick around. These kinds of events are known as advanced persistent threats, or APTs.

An **advanced persistent threat (APT)** refers to instances when a threat actor maintains unauthorized access to a system for an extended period of time. The term is mostly associated with nation states and state-sponsored actors. Typically, an APT is concerned with surveilling a target to gather information. They then use the intel to manipulate government, defense, financial, and telecom services.

Just because the term is associated with state actors does not mean that private businesses are safe from APTs. These kinds of threat actors are stealthy because hacking into another government agency or utility is costly and time consuming. APTs will often target private organizations first as a step towards gaining access to larger entities.

## Access points

Each threat actor has a unique motivation for targeting an organization's assets. Keeping them out takes more than knowing their intentions and capabilities. It’s also important to recognize the types of attack vectors they’ll use.

For the most part, threat actors gain access through one of these attack vector categories:

- **Direct access**, referring to instances when they have physical access to a system
    
- **Removable media**, which includes portable hardware, like USB flash drives
    
- **Social media platforms** that are used for communication and content sharing
    
- **Email**, including both personal and business accounts
    
- **Wireless networks** on premises
    
- **Cloud services** usually provided by third-party organizations
    
- **Supply chains** like third-party vendors that can present a backdoor into systems
    

Any of these attack vectors can provide access to a system. Recognizing a threat actor’s intentions can help you determine which access points they might target and what ultimate goals they could have. For example, remote workers are more likely to present a threat via email than a direct access threat.

## Key takeaways

Defending an attack surface starts with thinking like a threat actor. As a security professional, it’s important to understand _why_ someone would pose a threat to organizational assets. This includes recognizing that every threat actor isn’t intentionally out to cause harm.

It’s equally important to recognize the ways in which a threat actor might gain access to a system. Matching intentions with attack vectors is an invaluable skill as you continue to develop an attacker mindset.

![[Pasted image 20250113211255.png]]![[Pasted image 20250113212217.png]]
![[Pasted image 20250113212712.png]]


# Fortify against brute force cyber attacks

Usernames and passwords are one of the most common and important security controls in use today. They’re like the door lock that organizations use to restrict access to their networks, services, and data. But a major issue with relying on login credentials as a critical line of defense is that they’re vulnerable to being stolen and guessed by attackers.

In a video, you learned that **brute force attacks** are a trial-and-error process of discovering private information. In this reading, you’ll learn about the many tactics and tools used by threat actors to perform brute force attacks. You’ll also learn prevention strategies that organizations can use to defend against them.

## A matter of trial and error

One way of opening a closed lock is trying as many combinations as possible. Threat actors sometimes use similar tactics to gain access to an application or a network.

Attackers use a variety of tactics to find their way into a system:

- _Simple brute force attacks_ are an approach in which attackers guess a user's login credentials. They might do this by entering any combination of username and password that they can think of until they find the one that works.
    
- _Dictionary attacks_ are a similar technique except in these instances attackers use a list of commonly used credentials to access a system. This list is similar to matching a definition to a word in a dictionary.
    
- _Reverse brute force attacks_ are similar to dictionary attacks, except they start with a single credential and try it in various systems until a match is found.
    
- _Credential stuffing_ is a tactic in which attackers use stolen login credentials from previous data breaches to access user accounts at another organization. A specialized type of credential stuffing is called _pass the hash_. These attacks reuse stolen, unsalted hashed credentials to trick an authentication system into creating a new authenticated user session on the network.
    

**Note:** Besides access credentials, encrypted information can sometimes be brute forced using a technique known as _exhaustive key search_.

Each of these methods involve a lot of guess work. Brute forcing your way into a system can be a tedious and time consuming process—especially when it’s done manually. That’s why threat actors often use tools to conduct their attacks.

## Tools of the trade

There are so many combinations that can be used to create a single set of login credentials. The number of characters, letters, and numbers that can be mixed together is truly incredible. When done manually, it could take someone years to try every possible combination.

Instead of dedicating the time to do this, attackers often use software to do the guess work for them. These are some common brute forcing tools:

- Aircrack-ng
    
- Hashcat 
    
- John the Ripper
    
- Ophcrack
    
- THC Hydra
    

Sometimes, security professionals use these tools to test and analyze their own systems. They each serve different purposes. For example, you might use Aircrack-ng to test a Wi-Fi network for vulnerabilities to brute force attack.

## Prevention measures

Organizations defend against brute force attacks with a combination of technical and managerial controls. Each make cracking defense systems through brute force less likely:

- Hashing and salting
    
- Multi-factor authentication (MFA)
    
- CAPTCHA
    
- Password policies
    

Technologies, like multi-factor authentication (MFA), reinforce each login attempt by requiring a second or third form of identification. Other important tools are CAPTCHA and effective password policies.

### **Hashing and salting**

Hashing converts information into a unique value that can then be used to determine its integrity. **Salting** is an additional safeguard that’s used to strengthen hash functions. It works by adding random characters to data, like passwords. This increases the length and complexity of hash values, making them harder to brute force and less susceptible to dictionary attacks.

### **Multi-factor authentication (MFA)**

**Multi-factor authentication** (MFA) is a security measure that requires a user to verify their identity in two or more ways to access a system or network. MFA is a layered approach to protecting information. MFA limits the chances of brute force attacks because unauthorized users are unlikely to meet each authentication requirement even if one credential becomes compromised.

### **CAPTCHA**

CAPTCHA stands for Completely Automated Public Turing test to tell Computers and Humans Apart. It is known as a challenge-response authentication system. CAPTCHA asks users to complete a simple test that proves they are human and not software that’s trying to brute force a password.

Here are common CAPTCHA examples:

![A side by side comparison of a text-based and image-based CAPTCHA verifying if a user is human.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/tPsircWORfqlMVM3Pj3fEw_4ef34f0193e5481e8cac9e2379a02cf1_S36G003.png?expiry=1736899200000&hmac=FBDx2vKOwipD2FO8XXy3XIxtJBAqVji9qWCD01Z83yg)

There are two types of CAPTCHA tests. One scrambles and distorts a randomly generated sequence of letters and/or numbers and asks users to enter them into a text box. The other test asks users to match images to a randomly generated word. You’ve likely had to pass a CAPTCHA test when accessing a web service that contains sensitive information, like an online bank account.

### **Password policy**

Organizations use these managerial controls to standardize good password practices across their business. For example, one of these policies might require users to create passwords that are at least 8 characters long and feature a letter, number, and symbol. Other common requirements can include password lockout policies. For example, a password lockout can limit the number of login attempts before access to an account is suspended and require users to create new, unique passwords after a certain amount of time.

The purpose of each of these requirements is to create more possible password combinations. This lengthens the amount of time it takes an attacker to find one that will work. The [National Institute of Standards and Technology (NIST) Special Publication 800-63B](https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-63b.pdf)

provides detailed guidance that organizations can reference when creating their own password policies.

## Key takeaways

Brute force attacks are simple yet reliable ways to gain unauthorized access to systems. Generally, the stronger a password is, the more resilient it is to being cracked. As a security professional, you might find yourself using the tools described above to test the security of your organization's systems. Recognizing the tactics and tools used to conduct a brute force attack is the first step towards stopping attackers.