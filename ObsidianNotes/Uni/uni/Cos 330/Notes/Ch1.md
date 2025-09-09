Computer Security
- Measures and controls that ensure confidentiality, integrity, and availability of information system assets including hardware, software, firmware, and information being processed, stored, and communicated.

# CIA 
Conf Integ Av Auth Account (non rep)

Confidentiality
- Preserving the authorised restrictions on information access and disclosure,
- Includes means for protecting personal privacy and proprietary information.

Integrity
- Guarding improper information modification or destruction,
- Including non repudiation and authenticity.

Availability
- Ensuring timely and reliable access and use to information 

# Impact
Low
- limited adverse effect on operations and assets

Moderate
- Serious adverse effect

High
- Severe / Catastrophic effect  


# Security challenges
- Consider potential attacks when designing secure systems
- Counter intuitive procedures can make securing services hard
- Physical and Logical placement of security services need to be determined
- Secret information often required, creation, distribution and protection of secret information becomes important
- Attackers only need to find one weakness
- Security is often an afterthought in most systems
- Regular and constant monitoring
- Tendency to percieve little value untill a failure happens 
- Strong security == less user friend;y is viewed by many people


# Computer Terminology
**Adversary (threat agent)**
- intent to conduct detrimental activities (org/group/individual)

**Attack** 
- malicious activity that attempts to collect, disrupt, deny, degrade or destroy information system resources or the information itself

**Countermeasure**
- impairs threats

**Risk**
- Probability of event occurring x Impact of event
- P.E

**Security Policy**
- Criteria/Provisions for security services
- Defines and constrains activities of data processing 

**System Resource** (Asset)
- Something with importance to business operations

**Threat**
- Circumstance/Event with potential to cause harm on assets

**Vulnerability**
- Weakness in an information system


![[Pasted image 20250908184622.png]]


# Vulnerabilities, Threats and Attacks
**Categories of Vulnerabilities**
- Corrupted (Loss of integrity)
- Leaky (Loss of confidentiality)
- Unavailability (Loss of availability)

**Threats**
- Capable of exploiting vulnerabilities
- potential harm to an asset

**Attacks** (realized)
- Passive
	- attempt to learn/make use of information from system that does not affect syste,
- Active
	- attempt to alter a system / affect operation
- Insider
	- Initiated by an entity inside the security parameter
- Outsider
	- Initiated from the outside the perimeter


# Countermeasures
![[Pasted image 20250908193058.png]]


# Threat Consequences
### Unauthorized disclosure 
- entry to data for which data is not authorized

**Threat Actions**
- Exposure of sensitive data
- **Interception**: travelling between authorised sources
- **Inference**: reasoning the characteristics of byproducts from communication (not data contained in communication) 
- **Intrusion**: Circumventing system security protections

## Deception
- Authorised entity receives altered data and believes it to be real

**Threat Actions**
- **Masquerade**: Access to restricted zone by posing as an authorised entity
- **Falsification**: False data deceive an authorised entity 
- **Repudiation**: Falsely denying responsibility for an act


## Disruption
- Interrupts or prevents the operation of system services and functions

**Threat Actions**
- **Incapacitation**: disabling a component
- **Corruption**: modifying system functions or data
- **Obstruction**: hindering system operation

## Usurpation
- Control of system by unauthorised entity

**Threat actions**
- **Misappropriation**: logical or physical control
- **Misuse**: Causes a component to malfunction


![[Pasted image 20250908201914.png]]

# Passive vs Active Attacks
![[Pasted image 20250908202519.png]]

# Security Requirements
- Access Control
- Awareness and training 
- Audit and Accountability
- Certification, Accreditation and Security Assessments
- Configuration and Management
- Contingency planning 
- Identification and Authentication
- Incident Response
- Maintenance
- Media Protection
- Physical Environmental Protection
- Planning
- Personnel Security 
- Risk Assessment
- Systems and Services Acquisition
- Systems and Communication Protection
- System and Information Integrity


# Design Principles
![[Pasted image 20250908204019.png]]

**Economy of mechanism** – Keep system designs simple and small to reduce errors and vulnerabilities.
**Fail-safe defaults** – Deny access by default, granting permissions only when explicitly allowed.
**Complete mediation** – Always check access rights every time a resource is accessed.
**Open design** – Security should not rely on secrecy of design but on open, tested principles.
**Separation of privilege** – Require multiple conditions or permissions for access, not just one.
**Least privilege** – Grant users and programs the minimum access necessary to perform their tasks.
**Least common mechanism** – Minimize shared mechanisms across users to reduce potential attack surfaces.
**Psychological acceptability** – Security measures should be easy to use and not overly burdensome.
**Isolation** – Separate processes and resources to prevent unauthorized interactions.
**Encapsulation** – Hide implementation details and expose only necessary interfaces.
**Modularity** – Design systems in independent, interchangeable components for easier security management.
**Layering** – Use multiple security layers so that a failure in one does not compromise the whole system.
**Least astonishment** – System behavior should match user expectations to avoid mistakes and confusion.

# Attack Surface
![[Pasted image 20250908204219.png]]
![[Pasted image 20250908204233.png]]

![[Pasted image 20250908204333.png]]
![[Pasted image 20250908204354.png]]
![[Pasted image 20250908204429.png]]
![[Pasted image 20250908204709.png]]
![[Pasted image 20250908204724.png]]

