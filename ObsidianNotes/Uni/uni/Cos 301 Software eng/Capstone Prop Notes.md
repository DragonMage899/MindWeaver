# AT AT

Compromised API's can
- expose confindential info
- enable unauthorised access
- allows threat actors to manipulate critical processes

Can result in Data breach, financial loss, reputational damage.
Vectors to guard:
- Broken Auth
- injection
- data exposure

Need to secure authentication, encryption, rate limiting, continuous monitoring
# Automated API Threat Assessment Tool
- Enhance efficiency, scalability, accuracy and security of assessments
- 
Automate key aspects of security assessments
  
Should quickly outline common vulnerabilities in:
https://owasp.org/API-Security/editions/2023/en/0x11-t10/


---
### Project Title:

**API Threat Assessment Tool (AT-AT)**

### Context:

Modern APIs expose sensitive data and functionality, making them high-value targets for cyberattacks. Securing them is crucial for operational integrity and client trust.

### Purpose:

The project aims to **build an automated tool** that detects security vulnerabilities in APIs, improving efficiency, scalability, and accuracy of API security assessments for BITM.

### Key Features:

- **Vulnerability Detection**: Automatically identify issues based on the OWASP API Top 10 risks.
    
- **Authentication & Authorization Testing**: Check for broken authentication and access control flaws.
    
- **Injection & Input Validation Testing**: Detect SQL, NoSQL, command, and XML injections.
    
- **Compliance Checking**: Ensure APIs meet standards like PCI-DSS and GDPR.
    
- **Multi-Protocol Support**: Work with REST, SOAP, GraphQL, etc.
    
- **Scalable Deployment**: Containerized (Docker, Kubernetes) with secure storage and access (TLS, AES encryption, RBAC).
    

### Optional Enhancements ("Wow Factors"):

- Collaborative peer-review testing for students.
    
- Real-world attack simulations.
    
- One-click generation of detailed API risk assessment reports.
    

### Technical Expectations:

- Support dynamic and static security analysis.
    
- Simulate real-time API traffic and attacks.
    
- Provide real-time testing feedback and actionable reports.
    
- Integration with GitHub/GitLab for automated scans.
    

### Constraints:

- Enforce role-based access control (RBAC).
    
- Rate limiting to prevent abuse (DoS/DDoS).
    
- Secure handling of third-party integrations.
    

### Delivery:

- Deployment on a VPS provided by BITM.
    
- Infrastructure as code (Dockerfiles, instructions) must be documented.
    
- A guide on how to expand the tool over time is required.
    

---


# System Requirements
![[Pasted image 20250428195127.png]]
![[Pasted image 20250428195225.png]]
![[Pasted image 20250428195304.png]]

# Architecture 
![[Pasted image 20250428195600.png]]

# Design Requirements
![[Pasted image 20250428195617.png]]

# Delivery Requirements
![[Pasted image 20250428195925.png]]

# Constraints
![[Pasted image 20250428200126.png]]

# Budget
![[Pasted image 20250428200226.png]]

# Contact 
![[Pasted image 20250428200246.png]]
