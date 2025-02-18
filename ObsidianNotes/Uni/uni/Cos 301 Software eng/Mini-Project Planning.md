# Schedule
![[Pasted image 20250218200731.png]]

# Timeline
- 10 weeks

**To-do**
- Structure Meeting

**First Meeting Agenda**:
- Project Overview (Figure out what we're doing)
- GitHub usage
- What needs to get done for the first demo
	- Outline Beta Requirements (key features)
	- UML
	- Set a Deadline to have the first version of the timeline done
- Team Roles (temporary):
	- Front-End
	- Back-End
		- Daemon, Cli, API
	- Security
- Weekly Meetings

**Side Notes**
- Keep development conversation on discord
- Use WhatApp to communicate with entire group
- Beta
	- Testing
	- Docs
	- Uml
	- Basic Usage

# Meeting 1 Notes:
- 

**NoSql db from scratch**

# Playbook notes

## Intro
- MPDB
- full stack, security, testing, CI/CD
- Deliver:
	-  deployed*, working, functional NoSQL database SYSTEM that consists of a daemon (1), cli (2), an API (3) and a UI (4).

- Goal: Efficient Data storage and Retrieval

## System Requirements

tldr rebuild MySql (the cli client, the daemon, UI (mysqlworkbench)) but for a noSQL database

![[Pasted image 20250218211039.png]]

### daemon 
- Engine
- Waits for client requests on a specific port
- accepts a "data" variable
- Start and Stop a DB a server 
- Manage db files
- Process queries
- Hand client connections and auth

cli
- Connects to daemon through the open port and localhost
	- then send a message to this open port
	- daemon will be running in the bg
- daemon authenticates connection if successful it starts a sessions
- can then interact with daemon through predefined commands

REST api
- Expose endpoints that we can interact with (expect json data back)
- Communicate with daemon

JS client lib
- Simplify interaction with api
- Provide a clean user friendly interface
- encapsulate communication logic
- http requests to API with axios 

UI
- Web UI to manage and interact with db
# Other Notes
# RESTful API
<a href = https://www.youtube.com/watch?v=-mN3VyJuCjM>REST Standard</a>

- Organises resources into a set of unique uri's
- Each endpoint has a unique uri which identifies it
- Group by noun not verb
- Use std HTTP codes
- pagantion to reduce data return size
	- ![[Pasted image 20250218213102.png]]
- assume sensible default values 