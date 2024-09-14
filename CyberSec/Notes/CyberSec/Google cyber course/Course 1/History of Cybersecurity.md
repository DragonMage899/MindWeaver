Attackers enhance/improve previous methods
-> Past attacks can provide direction on how to handle current ones

**Virus**
- Code written to damage data/software
- attaches itself to programs/files and spreads

**Malware**
- Type of virus meant to harm devices or networks\

E.g)
Brainvirus
- goal: Track illegal copies of medical software and prevent pirated license
- actual: infect pc with software, but infected other discs also plugged into the machine
	- Virus can spread to another computer of someone inserts that disc
	- Virus spread globally within a few months
	- Slowed down productivity of various company's across the globe

Morirs worm
- Goal: Assess the size of the internet
	- Program crawled web and installed itself to other computers
	- Program then tallied all connected pc's
	- but no failsafe for infecting already infected pc's
	- virus mass installed itself onto the same machine multiple times and consumed all of the disc space

These and other forms of malware lead to the establishment of response teams, commonly referred to as "Computer Security Incident Response teams" (CSIRTs)

## Common attacks and their effectiveness

**Phishing**
- When digital communication is used to trick some one into revealing sensitive information or deploying malicious software 
Common types of phishing
- Business Email Compromise (BEC)
	- Threat actor sends an email that seems to be from a known source requesting information
- Spear Phishing
	- Malicious email seemingly from a trusted source targeting a specific user/group
- Waling
	- Use of spear phishing in order to target company executives
- Vishing
	- Exploitation of electronic voice communication to obtain sensitive information / impersonate a known source
- Smishing
	- Use of text message to trick users in order to obtain sensitive information / impersonate a known source

**Malware**
Software designed to harm devices or networks typically used to obtain money / intelligence

Common types
- Viruses
	- Malicious code written to interfere with compute operations and cause damage to data and software.
	- Initiated by a user(threat actor), who transmits the virus via a malicious attachment.
- Worms
	- Malware that can duplicate and spread itself across systems on its own
- Ransomware
	- Threat actors encrypt organisation data and demand payment to restore access
- Spyware
	- Malware that gathers user information without consent

**Social Engineering**
- Manipulation technique that exploits human error to gain private information / access.
- Threat actors gain false trust through lies

Common
- Social Media Phishing
	- Threat actor collects detailed information on target then initiate an attack
- Watering hole attack
	- Threat actor attacks a website typically visited by a specific group of people
- USB baiting
	- Threat actor leaves a malware USB stick for an employee to find and unknowingly infect a network
- Physical Social Engineering
	- Threat actor impersonates a known entity in order to obtain access to a physical location

Principles of Social Engineering
- People are generally trusting and conditioned to respect authority

Effectiveness of Social Engineering
- Authority
	- Threat actors impersonate individuals with power
- Intimidation
	- Threat actors bully victims into doing something
- Consensus / Social Proof
	- Use of made up situations in order to gain access to private info
- Scarcity
	- Use of "Limited supply"
- Familiarity
	- Fake emotional connection
- Trust
	- Fake emotional connection over time
- Urgency
	- Threat actor persuades other to respond quickly


### Reacting to a breach
- Be cool
- Contain the breach
	- Shutting a server, data centre coms etc 
- Investigate the Breach


## CISSP
Core Security concepts are organised into 8 domains/
Domains are related and each domain needs careful consideration within an org

- Security and Risk Management
- Asset Security
- Security Architecture and Engineering
- Communication and Network Security 
- Identity and Access Management
- Security Assessment and Testing
- Security Operations
- Software Development Security

--- 
### **Security and Risk Management**
- Define Security goals and objectives, risk mitigation, compliance, business continuity and the law
	- e.g) Update company polices to reflect new/updated regulations

### **Asset Security**
- Secures digital and physical assets
- Storage, Maintenance, retention, destruction of data

### **Security Architecture and Engineering**
- Optimizing data security by ensuring effective tool, systems and processes are in place 
	- e.g) firewall

### **Communication and Network Security** 
- Manage and secure physical networks and wireless communication
### **Identity and Access Management**
- Keep data secured by ensuring users follow established policies to control and manage physical and logical assets
	- e.g) Validating employee access, login info etc
### **Security Assessment and Testing**
- Conducting Security control testing, collecting and analysing data and conducting security audits to monitor for risks
	- e.g) Monitor Access to sensitive data
### **Security Operations**
- Conducting investigations and implementing preventative measures 
### **Software Development Security**
- Using guidelines to create safe and secure code

### Types of attacks
- Password attacks (Communication and net sec domain)
	- Attempt to access password secured devices
		- e.g) Brute force, Rainbow table

- Social Engineering attack
	- Sec and risk management

- Physical attack
	- Malicious USB cable
	- Malicious flash drive
	- Card Cloning

- Adversarial artificial intelligence
	- Use of AI and machine learning to conduct attacks
	- Communication and Net Sec + Identity and access management

- Supply Chain Attack
	- Targeting a vulnerable point in the supply chain
	- Can affect multiple organizations
	- Sec and risk management + Sec arch + Sec ops

- Cryptographic attacks 
	- Comm and Net Sec
	- Target comms between sender and recipient
	- Birthdays, Collision, Downgrade

### Attackers
Types of threat actors

- **Advanced Persistent Threats**
	- APTs
	- Experts of infiltration
	- Goal: Damage infrastructure, Gain intelligence

- **Insider Threats**
	- Abuse of authority to harm organisation
	- Sabotage, Corruption, Espionage etc

- **Hacktivists**
	- Threat actors driven by political agendas
	- Demonstrations, Propaganda, Fame etc

- **Hacker Types**
	- Hacker: Use of computers to gain access to computer systems, networks or data
	- Three Types:
	- **Ethical Hackers** (Authorised Hackers)
		- Follow code of ethics to adhere to law and conduct risk evaluations
	- **Researchers** (Semi-Authorized)
		- Search for vulnerabilities but don't take advantage of them
	- **Unethical Hackers** (Unauthorized hackers)
		- Malicious threat actors who don't follow the law
		- Collect and sell confidential data