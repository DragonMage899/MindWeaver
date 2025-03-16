[click]
[change slide]
[pause]
[small paise]

# READ WORD BY WORD
# DON'T MOVE ONTO TO NEXT WORD UNTILL READ
### **1. Project Introduction (1 min)**


**Script:**  
I’d like to welcome everyone to team 5's presentation of **MPDB** [change slide], we've been hard at work at realising a lightweight, NoSQL database system [pause] designed to **empower** users [small pause]with seamless database management, effortless sharing, and real-time collaboration.
[click 1]
**M P D B** is being built to address the growing demand for both flexible [small pause]
and efficient database solutions without compromising on ease of use [small pause] 
and allowing for painless sharing and integration. To this effect we've split our database solution into a easy to use suite
[change slide]

including [small pause] 
a **daemon** which acts as the database engine, 
a **command-line interface (CLI)** for direct operations, 
a **REST API** for integration, 
a **JavaScript client library** for developers,
and a **web UI** for visual database management.

Our hope is to provide a user-friendly, secure, and **scalable database** solution [small pause] that can address all your needs. Let’s dive into the details!"

---

### **2. Documentation (2 min)**

**Script:**  
"We’ve created comprehensive documentation in the form of a 
**README**, 
**Requirement Specification** 
and a **Design Specification** to ensure the system is easy to understand, install, and use.

Firstly, we have the **README**, where we can find an overview of the project, information about each team member as well as some short reference material related to each component

Next, we have the **Requirement Specification**, this outlines the functional and non-functional requirements that we've identifies . It covers everything from the Functional Requirements including database management, collaboration features as well as component requirements to Non Functional Requirements such security and scalability.
Each point was carefully considered and debated upon to make sure that **MPDB** touches on every area that it needs to without overextending

Lastly, we have the **Design Specification** which provides an architectural overview of the system, including diagrams and mockups.

This documentation ensures that both users and developers can effectively work with MPDB."

---

### **3. Project Plan (2 min)**

**Script:**  
"Next up on the agenda we have the **project plan**. 

For time and task management [small pause] we've opted to choose the projects tool on Gituhb which [small pause] has been used to **great effect** to manage what needs to be done and the order in which to complete. 

Our team has adopted the **Agile Development Methodology** this ensures iterative progress, continuous feedback, and adaptability regardless of where we are in our development cycle.

We’ve also broken the work into manageable sprints [pause], 
this allows us to quickly **refine** features, 
[small pause] respond to user needs,
[small pause] and maintain an **efficient** workflow. 
The approach has kept us stay on track and allowed us to quickly address complications.

For the development we've split our team is divided into **specialized** groups

- **Frontend**: Responsible for the web UI.
- **Daemon & CLI**: Handles the backend engine and command-line interface.
- **REST API & JavaScript Library**: Manages the API and client library.
- **Documentation**: Ensures all documentation is clear and up-to-date.

---

### **4. Implementation (Progress) (2 min)**

**Script:**  
"Now, let’s discuss **implementation progress**.

We're happy to say that the core components of **M P D B** are already in place:

- The **daemon** is fully functional, handling database operations, authentication, and permissions.
- The **CLI** allows users to interact with the daemon directly, supporting a range of commands
- The **REST API** is operational, enabling seamless integration with other applications.
- [next slide]
- The **JavaScript client library** is complete, providing developers with an easy way to integrate MPDB into their projects.
- The **web UI** is in progress, with the login page, landing page, and database view ready for use.

[next slide]
We’ve also established a clear file structure for the project, ensuring organized and maintainable code. We’re on track to deliver a fully functional system.

---

### **5. Testing (2 min)**
[next slide]
Next up we've got **Testing**

Testing is a **critical** part of our development. 
We’ve aimed to complete both **unit tests** and **integration tests** to ensure the system works as intended.

[next slide]
For **unit testing**, we’ve covered core functionalities like database operations, authentication, and permission management. 
[next slide]
As an example, we’ve tested the daemon’s ability to handle an incoming connection to register a user.

For **integration testing**, we’ve verified that the components do indeed work together. For instance, we’ve tested the flow from user registration to database creation and management through the REST API.

We hope that extensive testing will ensure that MPDB is reliable, secure, and ready for real-world use upon release.

---

### **6. CI/CD (1 min)**

**Script:**  
[Next slide]
"Finally, let’s talk about **CI/CD**. 
Github is being used for version control, we've opted for a **Git flow** branching strategy [small pause] 
where we have a main branch and a development branch [small pause] with feature branches that get merged back into the development branch once the feature has been completed and tested.

We’ve also set up a **continuous integration** [small pause] and **deployment pipeline** to streamline development and ensure code quality.

Our pipeline includes:
- Automated builds and tests for every commit.
- Static code analysis to catch issues early.
- Branch protection to ensure code reviews before merging.

This CI/CD setup allows us to deliver updates **quickly** and **confidently** [small pause], ensuring a **smooth** development process [small pause] and a stable end product."

Finally for deployment we've opted to go with docker where each component of the MPDB system will be containerised using Docker allowing anyone to quickly and easliy get everything up and running.



---

### **Closing (30 seconds)**

I'd like to take a moment and thank you for the your attention. The team has been really eager to share this you.

If you have any questions or feedback, I’d be more than happy to discuss them. Thank you again, and I hope the presentation was insightful!

**Script:**  
"In conclusion, MPDB is a robust, user-friendly NoSQL database system designed to meet the needs of modern developers and teams. With its flexible data management, strong security features, and comprehensive documentation, MPDB is ready to empower users with seamless database management.

Thank you for your attention, and I’m happy to take any questions!"