![[Pasted image 20250114125936.png]]
![[Pasted image 20250114125956.png]]
![[Pasted image 20250114130023.png]]
![[Pasted image 20250114130123.png]]
![[Pasted image 20250114130134.png]]

![[Pasted image 20250114132322.png]]
![[Pasted image 20250114132426.png]]

# Roles in response

So far, you've been introduced to the **National Institute of Standards and Technology (NIST) Incident Response Lifecycle**, which is a framework for incident response consisting of four phases:

- Preparation
    
- Detection and Analysis
    
- Containment, Eradication, and Recovery
    
- Post-incident activity
    

As a security professional, you'll work on a team to monitor, detect, and respond to incidents. Previously, you learned about a **computer security incident response team (CSIRT)** and a **security operations center (SOC)**. This reading explains the different functions, roles, and responsibilities that make up CSIRTs and SOCs.

Understanding the composition of incident response teams will help you navigate an organization’s hierarchy, openly collaborate and communicate with others, and work cohesively to respond to incidents. You may even discover specific roles that you’re interested in pursuing as you begin your security career!

## Command, control, and communication

A **computer security incident response team (CSIRT)** is a specialized group of security professionals that are trained in incident management and response. During incident response, teams can encounter a variety of different challenges. For incident response to be effective and efficient, there must be clear command**,** control, and communication of the situation to achieve the desired goal. 

- **Command** refers to having the appropriate leadership and direction to oversee the response.
    
- **Control** refers to the ability to manage technical aspects during incident response, like coordinating resources and assigning tasks.
    
- **Communication** refers to the ability to keep stakeholders informed.
    

Establishing a CSIRT organizational structure with clear and distinctive roles aids in achieving an effective and efficient response.

## Roles in CSIRTs 

CSIRTs are organization dependent, so they can vary in their structure and operation. Structurally, they can exist as a separate, dedicated team or as a task force that meets when necessary. CSIRTs involve both nonsecurity and security professionals. Nonsecurity professionals are often consulted to offer their expertise on the incident. These professionals can be from external departments, such as human resources, public relations, management, IT, legal, and others. Security professionals involved in a CSIRT typically include three key security related roles: 

1. **Security analyst**
    
2. **Technical lead**
    
3. **Incident coordinator**
    

### **Security analyst**

The job of the **security** **analyst** is to continuously monitor an environment for any security threats. This includes: 

- Analyzing and triaging alerts
    
- Performing root-cause investigations
    
- Escalating or resolving alerts 
    

If a critical threat is identified, then analysts escalate it to the appropriate team lead, such as the technical lead.

### **Technical lead**

The job of the technical lead is to manage all of the technical aspects of the incident response process, such as applying software patches or updates. They do this by first determining the root cause of the incident. Then, they create and implement the strategies for containing, eradicating, and recovering from the incident. Technical leads often collaborate with other teams to ensure their incident response priorities align with business priorities, such as reducing disruptions for customers or returning to normal operations. 

### **Incident coordinator**

Responding to an incident also requires cross-collaboration with nonsecurity professionals. CSIRTs will often consult with and leverage the expertise of members from external departments. The job of the incident coordinator is to coordinate with the relevant departments during a security incident. By doing so, the lines of communication are open and clear, and all personnel are made aware of the incident status. Incident coordinators can also be found in other teams, like the SOC. 

### **Other roles**

Depending on the organization, many other roles can be found in a CSIRT, including a dedicated communications lead, a legal lead, a planning lead, and more. 

**Note**: Teams, roles, responsibilities, and organizational structures can differ for each company. For example, some different job titles for incident coordinator include incident commander and incident manager.

## Security operations center

A **security operations center (SOC)** is an organizational unit dedicated to monitoring networks, systems, and devices for security threats or attacks. Structurally, a SOC (usually pronounced "sock") often exists as its own separate unit or within a CSIRT. You may be familiar with the term _blue team_, which refers to the security professionals who are responsible for defending against all security threats and attacks at an organization. A SOC is involved in various types of blue team activities, such as network monitoring, analysis, and response to incidents.

## SOC organization

A SOC is composed of SOC analysts, SOC leads, and SOC managers. Each role has its own respective responsibilities. SOC analysts are grouped into three different tiers. 

![A triangle with four labeled tiers. From bottom to top: SOC Analyst L1, SOC Analyst L2, SOC Lead L3, and Manager.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/CMDszNSgSryqbipKuGOU2Q_222b5865df5f4a72a785cd94279d99f1_CkqInM-0iDHKapM_2jS_68ZBhx11oR2GR_fCveMT5EI39E4h_dsAwBstgiRAXmj-mLFWXeOLNnSpBeMpDrEOiP9N8P9efbhWwLqNx-nDZFmoa6ue7SuqH0iUjmnMPWmpEcZPjKUY7ONnH6qkmt7wqF1XpuxPDe1zCbwGriZcyQRpSru_CG-tzvFvMDe5cg?expiry=1736985600000&hmac=o2fFwlvNWPL2OpkWU6DS77lMat7FrSZizEOvkNz3rqg)

### **Tier 1 SOC analyst**

The first tier is composed of the least experienced SOC analysts who are known as level 1s (L1s). They are responsible for:

- Monitoring, reviewing, and prioritizing alerts based on criticality or severity
    
- Creating and closing alerts using ticketing systems
    
- Escalating alert tickets to Tier 2 or Tier 3
    

### **Tier 2 SOC analyst**

The second tier comprises the more experienced SOC analysts, or level 2s (L2s). They are responsible for: 

- Receiving escalated tickets from L1 and conducting deeper investigations
    
- Configuring and refining security tools
    
- Reporting to the SOC Lead
    

### **Tier 3 SOC lead**

The third tier of a SOC is composed of the SOC leads, or level 3s (L3s). These highly experienced professionals are responsible for:

- Managing the operations of their team
    
- Exploring methods of detection by performing advanced detection techniques, such as malware and forensics analysis
    
- Reporting to the SOC manager
    

### **SOC manager** 

The SOC manager is at the top of the pyramid and is responsible for: 

- Hiring, training, and evaluating the SOC team members
    
- Creating performance metrics and managing the performance of the SOC team
    
- Developing reports related to incidents, compliance, and auditing
    
- Communicating findings to stakeholders such as executive management   
    

### **Other roles**

SOCs can also contain other specialized roles such as: 

- **Forensic investigators**: Forensic investigators are commonly L2s and L3s who collect, preserve, and analyze digital evidence related to security incidents to determine what happened.
    
- **Threat hunters**: Threat hunters are typically L3s who work to detect, analyze, and defend against new and advanced cybersecurity threats using threat intelligence.
    

**Note**: Just like CSIRTs, the organizational structure of a SOC can differ depending on the organization. 

## Key takeaways

As a security analyst, you will collaborate with your team members and people outside of your immediate team. Recognizing the organizational structure of an incident response team, such as a CSIRT or SOC, will help you understand how incidents move through their lifecycle and the responsibilities of different security roles throughout the process. Knowing the role that you and other professionals have during an incident response event will help you respond to challenging security situations by leveraging different perspectives and thinking of creative solutions. 

## Resources for more information

Here are some resources if you’d like to learn more about SOC organization or explore other incident response roles:

- [The security operations ecosystem](https://chronicle.security/blog/posts/soc-ecosystem-infographic/)
    

- [Cyber career pathways tool](https://niccs.cisa.gov/workforce-development/cyber-career-pathways-tool)
    

- [Detection and Response](https://www.youtube.com/watch?v=QZ0cpBocl3c)
    
at Google: Episode 2 of the [Hacking Google](https://www.youtube.com/playlist?list=PL590L5WQmH8dsxxz7ooJAgmijwOz0lh2H) series of videos


![[Pasted image 20250114133600.png]]
![[Pasted image 20250114133549.png]]
![[Pasted image 20250114134012.png]]
![[Pasted image 20250114134409.png]]
![[Pasted image 20250114135330.png]]
![[Pasted image 20250114135409.png]]

![[Pasted image 20250114140050.png]]
![[Pasted image 20250114140243.png]]
![[Pasted image 20250114140303.png]]

# Overview of detection tools

Previously, you explored **intrusion detection system** (**IDS**) and **intrusion prevention system** (**IPS**) technologies. In this reading, you’ll compare and contrast these tools and learn about **endpoint detection and response** (**EDR**). As a security analyst, you'll likely work with these different tools, so it's important to understand their functions.

## Why you need detection tools

Detection tools work similarly to home security systems. Whereas home security systems monitor and protect homes against intrusion, cybersecurity detection tools help organizations protect their networks and systems against unwanted and unauthorized access. For organizations to protect their systems from security threats or attacks, they must be made aware when there is any indication of an intrusion. Detection tools make security professionals aware of the activity happening on a network or a system. The tools do this by continuously monitoring networks and systems for any suspicious activity. Once something unusual or suspicious is detected, the tool triggers an alert that notifies the security professional to investigate and stop the possible intrusion. 

## Detection tools

As a security analyst, you'll likely encounter **IDS**, **IPS**, and **EDR** detection tools at some point, but it's important to understand the differences between them. Here is a comparison chart for quick reference: 

|**Capability**|**IDS**|**IPS**|**EDR**|
|---|---|---|---|
|Detects malicious activity|✓|✓|✓|
|Prevents intrusions|N/A|✓|✓|
|Logs activity|✓|✓|✓|
|Generates alerts|✓|✓|✓|
|Performs behavioral analysis|N/A|N/A|✓|

## Overview of IDS tools

An **intrusion detection system** (**IDS**) is an application that monitors system activity and alerts on possible intrusions. An IDS provides continuous monitoring of network events to help protect against security threats or attacks. The goal of an IDS is to detect potential malicious activity and generate an alert once such activity is detected. An IDS does _not_ stop or prevent the activity. Instead, security professionals will investigate the alert and act to stop it, if necessary. 

For example, an IDS can send out an alert when it identifies a suspicious user login, such as an unknown IP address logging into an application or a device at an unusual time. But, an IDS will not stop or prevent any further actions, like blocking the suspicious user login. 

Examples of IDS tools include Zeek, Suricata, Snort®, and Sagan. 

### **Detection categories**

As a security analyst, you will investigate alerts that an IDS generates. There are four types of detection categories you should be familiar with:

1. **A true positive** is an alert that correctly detects the presence of an attack.
    
2. **A true negative** is a state where there is no detection of malicious activity. This is when no malicious activity exists and no alert is triggered. 
    
3. **A false positive** is an alert that incorrectly detects the presence of a threat. This is when an IDS identifies an activity as malicious, but it isn't. False positives are an inconvenience for security teams because they spend time and resources investigating an illegitimate alert. 
    
4. **A false negative** is a state where the presence of a threat is not detected. This is when malicious activity happens but an IDS fails to detect it. False negatives are dangerous because security teams are left unaware of legitimate attacks that they can be vulnerable to. 
    

## Overview of IPS tools

An **intrusion prevention system** (**IPS**) is an application that monitors system activity for intrusive activity and takes action to stop the activity. An IPS works similarly to an IDS. But, IPS monitors system activity to detect and alert on intrusions, _and_ it also takes action to _prevent_ the activity and minimize its effects. For example, an IPS can send an alert and modify an access control list on a router to block specific traffic on a server.

**Note:** Many IDS tools can also operate as an IPS. Tools like Suricata, Snort, and Sagan have both IDS and IPS capabilities.

## Overview of EDR tools  

**Endpoint detection and response** (**EDR**) is an application that monitors an endpoint for malicious activity. EDR tools are installed on endpoints. Remember that an **endpoint** is any device connected on a network. Examples include end-user devices, like computers, phones, tablets, and more.

EDR tools monitor, record, and analyze endpoint system activity to identify, alert, and respond to suspicious activity. Unlike IDS or IPS tools, EDRs collect endpoint activity data and perform _behavioral analysis_ to identify threat patterns happening on an endpoint. Behavioral analysis uses the power of machine learning and artificial intelligence to analyze system behavior to identify malicious or unusual activity. EDR tools also use _automation_ to stop attacks without the manual intervention of security professionals. For example, if an EDR detects an unusual process starting up on a user’s workstation that normally is not used, it can automatically block the process from running.

Tools like Open EDR®, Bitdefender™ Endpoint Detection and Response, and FortiEDR™ are examples of EDR tools.

**Note**: Security information and event management (SIEM) tools also have detection capabilities, which you'll explore later.

## Key takeaways

Organizations deploy detection tools to gain awareness into the activity happening in their environments. IDS, IPS, and EDR are different types of detection tools. The value of detection tools is in their ability to detect, log, alert, and stop potential malicious activity.

![[Pasted image 20250114140745.png]]

![[Pasted image 20250114140934.png]]
![[Pasted image 20250114141056.png]]

# Overview of SIEM technology

Previously, you learned about the SIEM process. In this reading, you'll explore more about this process and why SIEM tools are an important part of incident detection and response. As a refresher, a **security information and event management** (**SIEM**) tool is an application that collects and analyzes log data to monitor critical activities in an organization. You might recall that SIEM tools help security analysts perform **log analysis** which is the process of examining logs to identify events of interest.

## SIEM advantages

SIEM tools collect and manage security-relevant data that can be used during investigations. This is important because SIEM tools provide awareness about the activity that occurs between devices on a network. The information SIEM tools provide can help security teams quickly investigate and respond to security incidents. SIEM tools have many advantages that can help security teams effectively respond to and manage incidents. Some of the advantages are:

- **Access to event data:** SIEM tools provide access to the event and activity data that happens on a network, including real-time activity. Networks can be connected to hundreds of different systems and devices. SIEM tools have the ability to ingest all of this data so that it can be accessed.
    
- **Monitoring, detecting, and alerting:** SIEM tools continuously monitor systems and networks in real-time. They then analyze the collected data using detection rules to detect malicious activity. If an activity matches the rule, an alert is generated and sent out for security teams to assess.
    
- **Log storage:** SIEM tools can act as a system for data retention, which can provide access to historical data. Data can be kept or deleted after a period depending on an organization's requirements. 
    

## The SIEM process

The SIEM process consists of three critical steps:

1. **Collect and aggregate data**
    
2. **Normalize data** 
    
3. **Analyze data**
    

By understanding these steps, organizations can utilize the power of SIEM tools to gather, organize, and analyze security event data from different sources. Organizations can later use this information to improve their ability to identify and mitigate potential threats.

### **Collect and aggregate data**

SIEM tools require data for them to be effectively used. During the first step, the SIEM collects event data from various sources like firewalls, servers, routers, and more. This data, also known as logs, contains event details like timestamps, IP addresses, and more. **Logs** are a record of events that occur within an organization’s systems. After all of this log data is collected, it gets aggregated in one location. Aggregation refers to the process of consolidating log data into a centralized place. Through collection and aggregation, SIEM tools eliminate the need for manually reviewing and analyzing event data by accessing individual data sources. Instead, all event data is accessible in one location—the SIEM. 

![Puzzle pieces representing data sources are ingested into a SIEM and processed as a completed puzzle.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/S4RVzsQNTH62x3KYJ85Uxg_95172ee75d1c4665927dcb44cc168ff1_S35G010.png?expiry=1736985600000&hmac=12SykcBmSsjJTHLyLIEsuxhxBRGbcBSLnFl5KHvE0V4)

Parsing can occur during the first step of the SIEM process when data is collected and aggregated. _Parsing_ maps data according to their fields and their corresponding values. For example, the following log example contains fields with values. At first, it might be difficult to interpret information from this log based on its format:

April 3 11:01:21 server sshd[1088]: Failed password for user nuhara from 218.124.14.105 port 5023

In a parsed format, the fields and values are extracted and paired making them easier to read and interpret:

- host = server
    
- process = sshd
    
- source_user = nuhara
    
- source ip = 218.124.14.105
    
- source port = 5023
    

### **Normalize data**

SIEM tools collect data from many different sources. This data must be transformed into a single format so that it can be easily processed by the SIEM. However, each data source is different and data can be formatted in many different ways. For example, a firewall log can be formatted differently than a server log.

![A SIEM solution ingests raw data and normalizes it into structured data.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/sO_SKjBLQ624WVuvgg9p_w_22b55ac3196c4b508dd1df3572065ff1_S35G009.png?expiry=1736985600000&hmac=zuvmGRLByrE3kqJh7Dr_CEVHYX6Ettn57dGDPv7LQxo)

Collected event data should go through the process of normalization. _Normalization_ converts data into a standard, structured format that is easily searchable. 

### **Analyze data**

After log data has been collected, aggregated, and normalized, the SIEM must do something useful with all of the data to enable security teams to investigate threats. During this final step in the process, SIEM tools analyze the data. Analysis can be done with some type of detection logic such as a set of rules and conditions. SIEM tools then apply these rules to the data, and if any of the log activity matches a rule, alerts are sent out to cybersecurity teams.

**Note**: A part of the analysis process includes correlation. _Correlation_ involves the comparison of multiple log events to identify common patterns that indicate potential security threats.

## SIEM tools 

There are many SIEM tools. The following are some SIEM tools commonly used in the cybersecurity industry:

- AlienVault® OSSIM™
    
- Chronicle
    
- Elastic
    
- Exabeam
    
- IBM QRadar® Security Intelligence Platform
    
- LogRhythm
    
- Splunk
    

## Key takeaways

SIEM tools collect and organize enormous amounts of data to create meaningful insights for security teams. By understanding how SIEM tools work, what the process includes, and how organizations leverage them, you can contribute to efforts in detecting and responding to security incidents effectively. With this knowledge, you can assist in analyzing log data, identifying threats, and aiding incident response activities to help improve security posture and protect valuable assets from threats.