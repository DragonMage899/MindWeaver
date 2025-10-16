# **Metasploit**
- Exploitation Framework
- Allows us to gather information, scan, exploit, post exploit and more.

## Components
- **msfconsole**: cli
- **Modules**: exploits, scanners, payloads etc
- **Tools**: stand alone, etc msfvenom, pattern_create, pattern_offset etc

# msfconsole

## Basics
- Main interface for interacting with modules 
	- Each module performs a specific task

**Modules**
Found in:
```
/opt/metasploit/modules/auxiliary/
```
**Auxiliary** 
- Supporting modules. Scanners, fuzzers, crawlers etc.
**Encoders**  
- Encode exploit in payload, evaide signature based av
**Evasion** 
- Tries to evade av
**Exploits**  
- Exploits for each target system
**Nops**  
- No operations (Do nothing)
- Consistent payload sizes
**Payloads**  
- Code that runs on a target system
- Use after discovering a vulnerability 
- Payloads can open shells to other systems 
	- **Adapters**: Wrap payloads to different formats (design pattern)
	- **Singles**: Self contained that does a single thing
	- **Stagers**: Set's up connection between metasploit and target system
		- Stages payload: Upload to target, payload then downloads rest of program
	- **Stages**: Downloaded by stagers

**Post** 
 - Post exploitation tools

## Console
Managed by context
i.e.) switching to a different module would undo all settings (unless it was global)

![[Pasted image 20250504155906.png]]
### show options
- See current settings available after using an exploit 
![[Pasted image 20250504155935.png]]

### info
See detailed info on current exploit
![[Pasted image 20250504160511.png]]

### search
Look for exploit
![[Pasted image 20250504160631.png]]
![[Pasted image 20250504160822.png]]
![[Pasted image 20250504160720.png]]

# In action
![[Pasted image 20250504161837.png]]
