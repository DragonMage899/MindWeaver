![[Pasted image 20250114155004.png]]
![[Pasted image 20250114155022.png]]![[Pasted image 20250114155308.png]]

# Cybersecurity incident detection methods

Security analysts use detection tools to help them discover threats, but there are additional methods of detection that can be used as well.

Previously, you learned about how detection tools can identify attacks like data exfiltration. In this reading, you’ll be introduced to different detection methods that organizations can employ to discover threats. 

## Methods of detection

During the **Detection and Analysis Phase** of the incident response lifecycle, security teams are notified of a possible incident and work to investigate and verify the incident by collecting and analyzing data. As a reminder, **detection** refers to the prompt discovery of security events and **analysis** involves the investigation and validation of alerts.

As you’ve learned, an intrusion detection system (IDS) can detect possible intrusions and send out alerts to security analysts to investigate the suspicious activity. Security analysts can also use security information and event management (SIEM) tools to detect, collect, and analyze security data.

You’ve also learned that there are challenges with detection. Even the best security teams can fail to detect real threats for a variety of reasons. For example, detection tools can only detect what security teams configure them to monitor. If they aren’t properly configured, they can fail to detect suspicious activity, leaving systems vulnerable to attack. It’s important for security teams to use additional methods of detection to increase their coverage and accuracy.

### **Threat hunting**

Threats evolve and attackers advance their tactics and techniques. Automated, technology-driven detection can be limited in keeping up to date with the evolving threat landscape. Human-driven detection like threat hunting combines the power of technology with a human element to discover hidden threats left undetected by detection tools.

**Threat hunting** is the proactive search for threats on a network. Security professionals use threat hunting to uncover malicious activity that was not identified by detection tools and as a way to do further analysis on detections. Threat hunting is also used to detect threats before they cause damage. For example, fileless malware is difficult for detection tools to identify. It’s a form of malware that uses sophisticated evasion techniques such as hiding in memory instead of using files or applications, allowing it to bypass traditional methods of detection like signature analysis. With threat hunting, the combination of active human analysis and technology is used to identify threats like fileless malware. 

**Note**: Threat hunting specialists are known as threat hunters. Threat hunters perform research on emerging threats and attacks and then determine the probability of an organization being vulnerable to a particular attack. Threat hunters use a combination of threat intelligence, indicators of compromise, indicators of attack, and machine learning to search for threats in an organization.

### **Threat intelligence**

Organizations can improve their detection capabilities by staying updated on the evolving threat landscape and understanding the relationship between their environment and malicious actors. One way to understand threats is by using **threat intelligence**, which is evidence-based threat information that provides context about existing or emerging threats. 

Threat intelligence can come from private or public sources like:

- **Industry reports**: These often include details about attacker's tactics, techniques, and procedures (TTP).
    
- **Government advisories:** Similar to industry reports, government advisories include details about attackers' TTP. 
    
- **Threat data feeds**: Threat data feeds provide a stream of threat-related data that can be used to help protect against sophisticated attackers like **advanced persistent threats (APTs)**. APTs are instances when a threat actor maintains unauthorized access to a system for an extended period of time. The data is usually a list of indicators like IP addresses, domains, and file hashes.
    

It can be difficult for organizations to efficiently manage large volumes of threat intelligence. Organizations can leverage a _threat intelligence platform_ (TIP) which is an application that collects, centralizes, and analyzes threat intelligence from different sources. TIPs provide a centralized platform for organizations to identify and prioritize relevant threats and improve their security posture.

**Note**: Threat intelligence data feeds are best used to add context to detections. They should not drive detections completely and should be assessed before applied to an organization.

### **Cyber deception**

Cyber deception involves techniques that deliberately deceive malicious actors with the goal of increasing detection and improving defensive strategies.

**Honeypots** are an example of an active cyber defense mechanism that uses deception technology. Honeypots are systems or resources that are created as decoys vulnerable to attacks with the purpose of attracting potential intruders. For example, having a fake file labeled _Client_ _Credit Card Information - 2022_ can be used to capture the activity of malicious actors by tricking them into accessing the file because it appears to be legitimate. Once a malicious actor tries to access this file, security teams are alerted.

## Key takeaways

Various detection methods can be implemented to identify and locate security events in an environment. It’s essential for organizations to use a variety of detection methods, tools, and technologies to adapt to the ever evolving threat landscape and better protect assets.

## Resources for more information

If you would like to explore more on threat hunting and threat intelligence, here are some resources:

- An [informational repository about threat hunting from](https://www.threathunting.net/)
    

- The ThreatHunting Project 
    
- Research on [state-sponsored hackers](https://blog.google/threat-analysis-group/)
    
from Threat Analysis Group (TAG)

# Indicators of compromise

In this reading, you’ll be introduced to the concept of the Pyramid of Pain and you'll explore examples of the different types of indicators of compromise. Understanding and applying this concept helps organizations improve their defense and reduces the damage an incident can cause.

## Indicators of compromise

**Indicators of compromise** (**IoCs**) are observable evidence that suggests signs of a potential security incident. IoCs chart specific pieces of evidence that are associated with an attack, like a file name associated with a type of malware. You can think of an IoC as evidence that points to something that's already happened, like noticing that a valuable has been stolen from inside of a car. 

**Indicators of attack** (**IoA**) are the series of observed events that indicate a real-time incident.  IoAs focus on identifying the behavioral evidence of an attacker, including their methods and intentions.

Essentially, IoCs help to identify the _who_ and _what_ of an attack after it's taken place, while IoAs focus on finding the _why_ and _how_ of an ongoing or unknown attack. For example, observing a process that makes a network connection is an example of an IoA. The filename of the process and the IP address that the process contacted are examples of the related IoCs.

**Note**: Indicators of compromise are not always a confirmation that a security incident has happened. IoCs may be the result of human error, system malfunctions, and other reasons not related to security. 

## Pyramid of Pain

Not all indicators of compromise are equal in the value they provide to security teams. It’s important for security professionals to understand the different types of indicators of compromise so that they can quickly and effectively detect and respond to them. This is why security researcher David J. Bianco created the concept of the [Pyramid of Pain](http://detect-respond.blogspot.com/2013/03/the-pyramid-of-pain.html)

, with the goal of improving how indicators of compromise are used in incident detection.

![A triangle divided into six tiers outlines six indicators of compromise each with a corresponding level of difficulty.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/5wpDfG3dRQyt3j7I9Vem3Q_31d63be045bc492e9b94aaeeb809a2f1_b5ndsAVFpYfEQSnQvmCly3Ws1dMEo2js79jF_lmAHf6cke-2RsAJfd2JrQ4GoFZdLOIdxxGx-AyNc-cnn4dolkvJLj1dydB1g0JmArLZWeZy7VJLFagiJ0xcq1oz7oirJA4dN8qjz6CI87yrOt-QSvGE7J28YVbPtj59GiU35sLHgGU8RIqqEkRI-JAk5w?expiry=1736985600000&hmac=Nl8lz7R-tYROrRpDNPVHElKjRnBGF5lMehtPGjkiQuA)

The Pyramid of Pain captures the relationship between indicators of compromise and the level of difficulty that malicious actors experience when indicators of compromise are blocked by security teams. It lists the different types of indicators of compromise that security professionals use to identify malicious activity. 

Each type of indicator of compromise is separated into levels of difficulty. These levels represent the “pain” levels that an attacker faces when security teams block the activity associated with the indicator of compromise. For example, blocking an IP address associated with a malicious actor is labeled as easy because malicious actors can easily use different IP addresses to work around this and continue with their malicious efforts. If security teams are able to block the IoCs located at the top of the pyramid, the more difficult it becomes for attackers to continue their attacks. Here’s a breakdown of the different types of indicators of compromise found in the Pyramid of Pain. 

1. **Hash values**: Hashes that correspond to known malicious files. These are often used to provide unique references to specific samples of malware or to files involved in an intrusion.
    
2. **IP addresses**: An internet protocol address like 192.168.1.1
    
3. **Domain names**: A web address such as www.google.com 
    
4. **Network artifacts**: Observable evidence created by malicious actors on a network. For example, information found in network protocols such as User-Agent strings. 
    
5. **Host artifacts:** Observable evidence created by malicious actors on a host. A host is any device that’s connected on a network. For example, the name of a file created by malware.
    
6. **Tools**: Software that’s used by a malicious actor to achieve their goal. For example, attackers can use password cracking tools like John the Ripper to perform password attacks to gain access into an account.
    
7. **Tactics, techniques, and procedures (TTPs)**: This is the behavior of a malicious actor. Tactics refer to the high-level overview of the behavior. Techniques provide detailed descriptions of the behavior relating to the tactic. Procedures are highly detailed descriptions of the technique. TTPs are the hardest to detect. 
    

## Key takeaways

Indicators of compromise and indicators of attack are valuable sources of information for security professionals when it comes to detecting incidents. The Pyramid of Pain is a concept that can be used to understand the different types of indicators of compromise and the value they have in detecting and stopping malicious activity.

# Analyze indicators of compromise with investigative tools

So far, you've learned about the different types of detection methods that can be used to detect security incidents. This reading explores how investigative tools can be used during investigations to analyze suspicious **indicators of compromise (IoCs)** and build context around alerts. Remember, an IoC is observable evidence that suggests signs of a potential security incident.

## Adding context to investigations

You've learned about the Pyramid of Pain which describes the relationship between indicators of compromise and the level of difficulty that malicious actors experience when indicators of compromise are blocked by security teams. You also learned about different types of IoCs, but as you know, not all IoCs are equal. Malicious actors can manage to evade detection and continue compromising systems despite having their IoC-related activity blocked or limited.

For example, identifying and blocking a single IP address associated with malicious activity does not provide a broader insight on an attack, nor does it stop a malicious actor from continuing their activity. Focusing on a single piece of evidence is like fixating on a single section of a painting: You miss out on the bigger picture.

![A woman observes a single section of a large painting.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/cii_FTSJTp6T9MiUON3QYw_55d2b729f5dc4eac883a774014823de1_umg_H4AHltqDZ8JXSzqzziTdQQhQQ2nidz2cvkE8wZiIG--TeOBj7WiA5pmKthEgHFrySvUi_inxWJXUVjq6TNB-CntB5QPRzlPylsNHvBlZpcvl_g5sDRygyhAjqwSOnTkfTYowlJs1zbxctSDaHcQ?expiry=1736985600000&hmac=Ck89-PfKA1vLjOjSidlKTqtHsklwby2G8-dyFYXkHV8)

Security analysts need a way to expand the use of IoCs so that they can add context to alerts. **Threat intelligence** is evidence-based threat information that provides context about existing or emerging threats. By accessing additional information related to IoCs, security analysts can expand their viewpoint to observe the bigger picture and construct a narrative that helps inform their response actions. 

![A woman views a large painting of an elephant in its entirety.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/NJZv0wovQSKtj9HDjsy_vw_a51597ca2f20481289849bf159c222e1_wq21GsJyPvGERPn-NTfkl9XOMS4dtFHHIBl60TkZsaXBdXxsMfARzwbEQ9_S3iut7w-W4fIUikrnjtC2UvMIADqN0yxD8tnz4SNtJLbA_zpo_ZrEvDiCuU6kWJ3cAT1hfHGU526P9qhzGl6X02sjgNY?expiry=1736985600000&hmac=kR5SK9RWVhXw0_C-eOhfikxAvh_5Tp4CNrquB1qrDeY)

By adding context to an IoC—for instance, identifying other artifacts related to the suspicious IP address, such as suspicious network communications or unusual processes—security teams can start to develop a detailed picture of a security incident. This context can help security teams detect security incidents faster and take a more informed approach in their response.

## The power of crowdsourcing

**Crowdsourcing** is the practice of gathering information using public input and collaboration. Threat intelligence platforms use crowdsourcing to collect information from the global cybersecurity community. Traditionally, an organization's response to incidents was performed in isolation. A security team would receive and analyze an alert, and then work to remediate it without additional insights on how to approach it. Without crowdsourcing, attackers can perform the same attacks against multiple organizations.

![An attacker successfully attacks five different organizations.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/hRQbqDNHSkWbZJMfxaNsQw_21e96120d16f4940839edd5b7d5454e1_davTkHHUevx1nYpQaSF7v_WTPPgga12ByDGjdKWVjVBG9OU_lTX-SZnh7EPzFgdBcYskWLQDmVMZOEgyBuXhbrSha86C_Xu_XraeZ4oLHmGOJWhoF4Omr3AbMQf1VwiLgDkohnH-VVSPb48HB46dQp8?expiry=1736985600000&hmac=VoE7JV2c64iEzdD57z_6y42t467QPEOA8vtzDJmsUb0)

With crowdsourcing, organizations harness the knowledge of millions of other cybersecurity professionals, including cybersecurity product vendors, government agencies, cloud providers, and more. Crowdsourcing allows people and organizations from the global cybersecurity community to openly share and access a collection of threat intelligence data, which helps to continuously improve detection technologies and methodologies. 

Examples of information-sharing organizations include Information Sharing and Analysis Centers (ISACs), which focus on collecting and sharing sector-specific threat intelligence to companies within specific industries like energy, healthcare, and others. **Open-source intelligence (OSINT)** is the collection and analysis of information from publicly available sources to generate usable intelligence. OSINT can also be used as a method to gather information related to threat actors, threats, vulnerabilities, and more.

This threat intelligence data is used to improve the detection methods and techniques of security products, like detection tools or anti-virus software. For example, attackers often perform the same attacks on multiple targets with the hope that one of them will be successful. Once an organization detects an attack, they can immediately publish the attack details, such as malicious files, IP addresses, or URLs, to tools like VirusTotal. This threat intelligence can then help other organizations defend against the same attack.

![An attacker is prevented from attacking organizations due to crowdsourced threat intelligence.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/4nnwqdjMQzmT291E0-hPWA_09adff26a39c40f9aa26ae06cec198e1_ZeTn34K0Nort9Mm0C7fqubtvfqcK_MniMrjOEZoaNou8UKl9Nc-fp48EETQmm6sJk9SvT1TPcTBN8n53R9EoUbx3LvUPg3SJ1GjXead03Pl1tx1y_bQ7Lfurjsu4FQwCwLcQev81ZUm_YLGQ1v4VAFY?expiry=1736985600000&hmac=IJYQVqnexaqb_mJfZMaeKo7DRGfUjrwRvjev3R7PXYs)

## VirusTotal 

[**VirusTotal**](https://www.virustotal.com/gui/home)

is a service that allows anyone to analyze suspicious files, domains, URLs, and IP addresses for malicious content. VirusTotal also offers additional services and tools for enterprise use. This reading focuses on the VirusTotal website, which is available for free and non-commercial use.

It can be used to analyze suspicious files, IP addresses, domains, and URLs to detect cybersecurity threats such as malware. Users can submit and check artifacts, like file hashes or IP addresses, to get VirusTotal reports, which provide additional information on whether an IoC is considered malicious or not, how that IoC is connected or related to other IoCs in the dataset, and more.

![A screenshot of the VirusTotal home page.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/OGF9XULpS4yRE9XWp0_5Ww_28f373819aa5487080f345ee10ed36e1_2UzPkWUVrcbKDLApq0CPB33OaJOORTO260rs4umcRJK6f09s9wrvwlEyczfwmAjHJp34gLdnvhGcz3WYmdSFzV5BRUscBCjBtePStKAA3S_481ILEM_X1AmmoLNi97lkerAtOcFrOuP2K5PT-QGGJ3Q?expiry=1736985600000&hmac=29-E_D_r4Tq6gJOGy1EtOwh-CnyFgY60GU5MUP2O72g)

Here is a breakdown of the reports summary:

![A screenshot of a VirusTotal reports summary.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/G6lzkoezTH--0Ly1-t-gyA_bf5046e9968f4a33b881b46561b750f1_CS_R-129_VirusTotal-reports.png?expiry=1736985600000&hmac=dOKiMmapo7W9rFRaRw4513m_Bwct8dksW92SK_7_OJA)

1. **Detection**: The Detection tab provides a list of third-party security vendors and their detection verdicts on an IoC. For example, vendors can list their detection verdict as malicious, suspicious, unsafe, and more.
    
2. **Details**: The Details tab provides additional information extracted from a static analysis of the IoC. Information such as different hashes, file types, file sizes, headers, creation time, and first and last submission information can all be found in this tab.
    
3. **Relations**: The Relations tab provides related IoCs that are somehow connected to an artifact, such as contacted URLs, domains, IP addresses, and dropped files if the artifact is an executable.
    
4. **Behavior**: The Behavior tab contains information related to the observed activity and behaviors of an artifact after executing it in a controlled or sandboxed environment. This information includes tactics and techniques detected, network communications, registry and file systems actions, processes, and more.
    
5. **Community:** The Community tab is where members of the VirusTotal community, such as security professionals or researchers, can leave comments and insights about the IoC.
    
6. **Vendors’ ratio and community score**: The score displayed at the top of the report is the vendors’ ratio. The vendors’ ratio shows how many security vendors have flagged the IoC as malicious overall. Below this score, there is also the community score, based on the inputs of the VirusTotal community. The more detections a file has and the higher its community score is, the more likely that the file is malicious.
    

**Note**: Data uploaded to VirusTotal will be publicly shared with the entire VirusTotal community. Be careful of what you submit, and make sure you do not upload personal information.

## Other tools

There are other investigative tools that can be used to analyze IoCs. These tools can also share the data that's uploaded to them to the security community.

### **Jotti malware scan**

[Jotti's malware scan](https://virusscan.jotti.org/)

is a free service that lets you scan suspicious files with several antivirus programs. There are some limitations to the number of files that you can submit. 

### **Urlscan.io**

[Urlscan.io](https://urlscan.io/)

is a free service that scans and analyzes URLs and provides a detailed report summarizing the URL information.

### **MalwareBazaar**

[MalwareBazaar](https://bazaar.abuse.ch/browse/)

is a free repository for malware samples. Malware samples are a great source of threat intelligence that can be used for research purposes. 

## Key takeaways

As a security analyst, you'll analyze IoCs. It's important to understand how adding context to investigations can help improve detection capabilities and make informed and effective decisions.

![[Pasted image 20250114163632.png]]
![[Pasted image 20250114163713.png]]
![[Pasted image 20250114163820.png]]
![[Pasted image 20250114163835.png]]
# Best practices for effective documentation

**Documentation** is any form of recorded content that is used for a specific purpose, and it is essential in the field of security. Security teams use documentation to support investigations, complete tasks, and communicate findings. This reading explores the benefits of documentation and provides you with a list of common practices to help you create effective documentation in your security career.

## Documentation benefits

You’ve already learned about many types of security documentation, including playbooks, final reports, and more. As you’ve also learned, effective documentation has three benefits:

1. Transparency
    
2. Standardization
    
3. Clarity
    

### **Transparency**

In security, transparency is critical for demonstrating compliance with regulations and internal processes, meeting insurance requirements, and for legal proceedings. **Chain of custody** is the process of documenting evidence possession and control during an incident lifecycle. Chain of custody is an example of how documentation produces transparency and an audit trail.

### **Standardization**

Standardization through repeatable processes and procedures supports continuous improvement efforts, helps with knowledge transfer, and facilitates the onboarding of new team members. **Standards** are references that inform how to set policies.

You have learned how NIST provides various security frameworks that are used to improve security measures. Likewise, organizations set up their own standards to meet their business needs. An example of documentation that establishes standardization is an **incident response plan**, which is a document that outlines the procedures to take in each step of incident response. Incident response plans standardize an organization’s response process by outlining procedures in advance of an incident. By documenting an organization’s incident response plan, you create a standard that people follow, maintaining consistency with repeatable processes and procedures.

### **Clarity**

Ideally, all documentation provides clarity to its audience. Clear documentation helps people quickly access the information they need so they can take necessary action. Security analysts are required to document the reasoning behind any action they take so that it’s clear to their team why an alert was escalated or closed.

## Best practices

As a security professional, you’ll need to apply documentation best practices in your career. Here are some general guidelines to remember:

### **Know your audience**

Before you start creating documentation, consider your audience and their needs. For instance, an incident summary written for a security operations center (SOC) manager will be written differently than one that's drafted for a chief executive officer (CEO). The SOC manager can understand technical security language but a CEO might not. Tailor your document to meet your audience’s needs.

### **Be concise**

You might be tasked with creating long documentation, such as a report. But when documentation is too long, people can be discouraged from using it. To ensure that your documentation is useful, establish the purpose immediately. This helps people quickly identify the objective of the document. For example, executive summaries outline the major facts of an incident at the beginning of a final report. This summary should be brief so that it can be easily skimmed to identify the key findings. 

### **Update regularly** 

In security, new vulnerabilities are discovered and exploited constantly. Documentation must be regularly reviewed and updated to keep up with the evolving threat landscape. For example, after an incident has been resolved, a comprehensive review of the incident can identify gaps in processes and procedures that require changes and updates. By regularly updating documentation, security teams stay well informed and incident response plans stay updated.

## Key takeaways

Effective documentation produces benefits for everyone in an organization. Knowing how to create documentation is an essential skill to have as a security analyst. As you continue in your journey to become a security professional, be sure to consider these practices for creating effective documentation.

# Playbooks
![[Pasted image 20250114165125.png]]
![[Pasted image 20250114165153.png]]
![[Pasted image 20250114170137.png]]
![[Pasted image 20250114170334.png]]
![[Pasted image 20250114170358.png]]

# The triage process

Previously, you learned that triaging is used to assess alerts and assign priority to incidents. In this reading, you'll explore the triage process and its benefits. As a security analyst, you'll be responsible for analyzing security alerts. Having the skills to effectively triage is important because it allows you to address and resolve security alerts efficiently.

## Triage process

Incidents can have the potential to cause significant damage to an organization. Security teams must respond quickly and efficiently to prevent or limit the impact of an incident before it becomes too late. **Triage** is the prioritizing of incidents according to their level of importance or urgency. The triage process helps security teams evaluate and prioritize security alerts and allocate resources effectively so that the most critical issues are addressed first.

The triage process consists of three steps:

1. Receive and assess 
    
2. Assign priority 
    
3. Collect and analyze
    

### **Receive and assess**

During this first step of the triage process, a security analyst receives an alert from an alerting system like an **intrusion detection system** (IDS). You might recall that an IDS is an application that monitors system activity and alerts on possible intrusions. The analyst then reviews the alert to verify its validity and ensure they have a complete understanding of the alert. 

This involves gathering as much information as possible about the alert, including details about the activity that triggered the alert, the systems and assets involved, and more. Here are some questions to consider when verifying the validity of an alert: 

- **Is the alert a false positive?** Security analysts must determine whether the alert is a genuine security concern or a **false positive**, or an alert that incorrectly detects the presence of a threat.
    
- **Was this alert triggered in the past?** If so, how was it resolved? The history of an alert can help determine whether the alert is a new or recurring issue. 
    
- **Is the alert triggered by a known vulnerability?** If an alert is triggered by a known vulnerability, security analysts can leverage existing knowledge to determine an appropriate response and minimize the impact of the vulnerability. 
    
- **What is the severity of the alert?** The severity of an alert can help determine the priority of the response so that critical issues are quickly escalated.
    

### **Assign priority** 

Once the alert has been properly assessed and verified as a genuine security issue, it needs to be prioritized accordingly. Incidents differ in their impact, size, and scope, which affects the response efforts. To manage time and resources, security teams must prioritize how they respond to various incidents because not all incidents are equal. Here are some factors to consider when determining the priority of an incident:

- **Functional impact:** Security incidents that target information technology systems impact the service that these systems provide to its users. For example, a ransomware incident can severely impact the confidentiality, availability, and integrity of systems. Data can be encrypted or deleted, making it completely inaccessible to users. Consider how an incident impacts the existing business functionality of the affected system.
    
- **Information impact:** Incidents can affect the confidentiality, integrity, and availability of an organization’s data and information. In a data exfiltration attack, malicious actors can steal sensitive data. This data can belong to third party users or organizations. Consider the effects that information compromise can have beyond the organization. 
    
- **Recoverability:** How an organization recovers from an incident depends on the size and scope of the incident and the amount of resources available. In some cases, recovery might not be possible, like when a malicious actor successfully steals proprietary data and shares it publicly. Spending time, effort, and resources on an incident with no recoverability can be wasteful. It’s important to consider whether recovery is possible and consider whether it’s worth the time and cost.
    

**Note**: Security alerts often come with an assigned priority or severity level that classifies the urgency of the alert based on a level of prioritization. 

### **Collect and analyze**

The final step of the triage process involves the security analyst performing a comprehensive analysis of the incident. Analysis involves gathering evidence from different sources, conducting external research, and documenting the investigative process. The goal of this step is to gather enough information to make an informed decision to address it. Depending on the severity of the incident, escalation to a level two analyst or a manager might be required. Level two analysts and managers might have more knowledge on using advanced techniques to address the incident. 

## Benefits of triage

By prioritizing incidents based on their potential impact, you can reduce the scope of impact to the organization by ensuring a timely response. Here are some benefits that triage has for security teams: 

- **Resource management:** Triaging alerts allows security teams to focus their resources on threats that require urgent attention. This helps team members avoid dedicating time and resources to lower priority tasks and might also reduce response time.
    
- **Standardized approach:** Triage provides a standardized approach to incident handling. Process documentation, like playbooks, help to move alerts through an iterative process to ensure that alerts are properly assessed and validated. This ensures that only valid alerts are moved up to investigate.
    

## Key takeaways

Triage allows security teams to prioritize incidents according to their level of importance or urgency. The triage process is important in ensuring that an organization meets their incident response goals. As a security professional, you will likely utilize triage to effectively respond to and resolve security incidents.

![[Pasted image 20250114170623.png]]
![[Pasted image 20250114170648.png]]
![[Pasted image 20250114170701.png]]
# Business continuity considerations

Previously, you learned about how security teams develop incident response plans to help ensure that there is a prepared and consistent process to quickly respond to security incidents. In this reading, you'll explore the importance that business continuity planning has in recovering from incidents.

## Business continuity planning

Security teams must be prepared to minimize the impact that security incidents can have on their normal business operations. When an incident occurs, organizations might experience significant disruptions to the functionality of their systems and services. Prolonged disruption to systems and services can have serious effects, causing legal, financial, and reputational damages. Organizations can use business continuity planning so that they can remain operational during any major disruptions.

Similar to an incident response plan, a **business** **continuity plan (BCP)** is a document that outlines the procedures to sustain business operations during and after a significant disruption. A BCP helps organizations ensure that critical business functions can resume or can be quickly restored when an incident occurs.

Entry level security analysts aren't typically responsible for the development and testing of a BCP. However, it's important that you understand how BCPs provide organizations with a structured way to respond and recover from security incidents.

**Note**: Business continuity plans are not the same as _disaster recovery plans_. Disaster recovery plans are used to recover information systems in response to a major disaster. These disasters can range from hardware failure to the destruction of facilities from a natural disaster, like a flood. 

### **Consider the impacts of ransomware to business continuity**

Impacts of a security incident such as ransomware can be devastating for business operations. Ransomware attacks targeting critical infrastructure such as healthcare can have the potential to cause significant disruption. Depending on the severity of a ransomware attack, the accessibility, availability, and delivery of essential healthcare services can be impacted. For example, ransomware can encrypt data, resulting in disabled access to medical records, which prevents healthcare providers from accessing patient records. At a larger scale, security incidents that target the assets, systems, and networks of critical infrastructure can also undermine national security, economic security, and the health and safety of the public. For this reason, BCPs help to minimize interruptions to operations so that essential services can be accessed.

### **Recovery strategies** 

When an outage occurs due to a security incident, organizations must have some sort of a functional recovery plan set to resolve the issue and get systems fully operational. BCPs can include strategies for recovery that focus on returning to normal operations. Site resilience is one example of a recovery strategy. 

### **Site resilience** 

**Resilience** is the ability to prepare for, respond to, and recover from disruptions. Organizations can design their systems to be resilient so that they can continue delivering services despite facing disruptions. An example is site resilience, which is used to ensure the availability of networks, data centers, or other infrastructure when a disruption happens. There are three types of recovery sites used for site resilience:

- **Hot sites**: A fully operational facility that is a duplicate of an organization's primary environment. Hot sites can be activated immediately when an organization's primary site experiences failure or disruption.
    
- **Warm sites**: A facility that contains a fully updated and configured version of the hot site. Unlike hot sites, warm sites are not fully operational and available for immediate use but can quickly be made operational when a failure or disruption occurs.
    
- **Cold sites**: A backup facility equipped with some of the necessary infrastructure required to operate an organization's site. When a disruption or failure occurs, cold sites might not be ready for immediate use and might need additional work to be operational.
    

## Key takeaways

Security incidents have the potential to seriously disrupt business operations. Having the right plans in place is essential so that organizations can continue to function. Business continuity plans help organizations understand the impact that serious security incidents can have on their operations and work to mitigate these impacts so that regular operations can resume.

# Post incident
![[Pasted image 20250114171603.png]]
![[Pasted image 20250114171615.png]]
![[Pasted image 20250114171732.png]]

# Post-incident review

Previously, you explored the Containment, Eradication and Recovery phase of the NIST Incident Response Lifecycle. This reading explores the activities involved in the final phase of the lifecycle: **Post-incident activity**. As a security analyst, it's important to familiarize yourself with the activities involved in this phase because each security incident will provide you with an opportunity to learn and improve your responses to future incidents.

## Post-incident activity

The Post-incident activity phase of the NIST Incident Response Lifecycle is the process of reviewing an incident to identify areas for improvement during incident handling.

![The four phases of the NIST Incident Response Lifecycle as icons with arrows representing the cyclical order.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/Y3_XY9FnQI-tOxD814iE9A_ab92e32224d44581bbebda615a6928e1_5HQqmTCRyAsk3k7zw33nhwXLDESzbaiKfn6HhDSA8y0CvF_e0HU48EHIbo69MLoLw_xYYPG3L3k0T1aUyMywh34HZzrSJIFvkkcQaezIL1vDK2RLZtT-9UHrCm-QuzQptYyyurePnWXXW-a-LFmo4ytVWGHGZQChMHTFaH_6CKmrYwY7a1YkbtTkEsf6xg?expiry=1736985600000&hmac=p-XI-nak5CCN9jHxHlM2gPA7FNcxYcq2w_ut7eW1fPA)

## Lessons learned 

After an organization has successfully contained, eradicated, and recovered from an incident, the incident comes to a close. However, this doesn’t mean that the work of security professionals is complete. Incidents provide organizations and their security teams with an opportunity to learn from what happened and prioritize ways to improve the incident handling process.

This is typically done through a **lessons learned meeting**, also known as a post-mortem. A lessons learned meeting includes all involved parties after a major incident. Depending on the scope of an incident, multiple meetings can be scheduled to gather sufficient data. The purpose of this meeting is to evaluate the incident in its entirety, assess the response actions, and identify any areas of improvement. It provides an opportunity for an organization and its people to learn and improve, not to assign blame. This meeting should be scheduled no later than two weeks after an incident has been successfully remediated. 

Not all incidents require their own lessons learned meeting; the size and severity of an incident will dictate whether the meeting is necessary. However, major incidents, such as ransomware attacks, should be reviewed in a dedicated lessons learned meeting. This meeting consists of all parties who participated in any aspect of the incident response process. Here are some examples of questions that are addressed in this meeting:

- What happened?
    
- What time did it happen?
    
- Who discovered it?
    
- How did it get contained?
    
- What were the actions taken for recovery?
    
- What could have been done differently?
    

Besides having the opportunity to learn from the incident, there are additional benefits to conducting a lessons learned meeting. For large organizations, lessons learned meetings offer a platform for team members across departments to share information and recommendations for future prevention. 

**Pro tip**: Before a team hosts a lessons learned meeting, organizers should make sure all attendees come prepared. The meeting hosts typically develop and distribute a meeting agenda beforehand, which contains the topics of discussion and ensures that attendees are informed and prepared. Additionally, meeting roles should be assigned in advance, including a moderator to lead and facilitate discussion and a scribe to take meeting notes.

### **Recommendations**

Lessons learned meetings provide opportunities for growth and improvement. For example, security teams can identify errors in response actions, gaps in processes and procedures, or ineffective security controls. A lessons learned meeting should result in a list of prioritized actions or actionable recommendations meant to improve an organization’s incident handling processes and overall security posture. This ensures that organizations are implementing the lessons they’ve learned after an incident so that they are not vulnerable to experiencing the same incident in the future. Examples of changes that can be implemented include updating and improving playbook instructions or implementing new security tools and technologies.

## Final report

Throughout this course, you explored the importance that documentation has in recording details during the incident response lifecycle. At a minimum, incident response documentation should describe the incident by covering the 5 W's of incident investigation: _who_, _what_, _where_, _why_, and _when._ The details that are captured during incident response are important for developing additional documents during the end of the lifecycle.

One of the most essential forms of documentation that gets created during the end of an incident is the **final report**. The final report provides a comprehensive review of an incident. Final reports are not standardized, and their formats can vary across organizations. Additionally, multiple final reports can be created depending on the audience it’s written for. Here are some examples of common elements found in a final report:

- **Executive summary**: A high-level summary of the report including the key findings and essential facts related to the incident
    
- **Timeline**:  A detailed chronological timeline of the incident that includes timestamps dating the sequence of events that led to the incident
    
- **Investigation**: A compilation of the actions taken during the detection and analysis of the incident. For example, analysis of a network artifact such as a packet capture reveals information about what activities happen on a network.
    
- **Recommendations**: A list of suggested actions for future prevention
    

**Pro tip**: When writing the final report, consider the audience that you’re writing the report for. Oftentimes, business executives and other non-security professionals who don’t have the expertise to understand technical details will read post-incident final reports. Considering the audience when writing a final report will help you effectively communicate the most important details.

## Key takeaways

Post-incident actions represent the end of the incident response lifecycle. This phase provides the opportunity for security teams to meet, evaluate the response actions, make recommendations for improvement, and develop the final report.