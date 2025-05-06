## SWE
- Application of engineering principles to software development 
- Typically used to ensure scalability, efficiency and security 

# Characteristics
- Intangibility 
- Modifiability  
- Complexity 


# Life cycle
- Planning 
- Design
- Implementation
- Testing 
- Maintenance 

# Waterfall
- Linear sequence of steps
- Planning Design maintenance etc...
- Once a step is done you can't go back 

# Agile
- Iterative addition of features starting from some core product 
- Features developed in cycles (sprints) with regular meetings to adjust based on feedback 
- Useful when requirements always change 


# The unified process 
- Framework that guides development of software through iterate cycles 
- Has best practises from various methodologies 
- Reduce risk and improve software quality to ensure stakeholder satisfaction

![[Pasted image 20250504123628.png]]

## Phases
- **Inception**
	- Scope, goals, high level requirements
	- Identify stakeholders, estimate resources and cost, set up project timeline 
	![[Pasted image 20250504124000.png]]
- **Elaboration**
	- Refining requirements and defining architecture 
	- Detailed Design of system components
	- Data models, user interfaces, security protocols 
	![[Pasted image 20250504124011.png]]
- **Construction**
	- System is built iterating over development cycles
	- Code is written and tested
	- Continuations integration and testing 
	![[Pasted image 20250504124626.png]]
- **Transition** 
	- Moving system into production
	- System deployment 
	- User training 
	- Bug fixing 
	![[Pasted image 20250504124718.png]]


## Use case
- Capture functional requirements 
- Each case defines how a user interacts with the system to achieve a specific goal
![[Pasted image 20250504125116.png]]


# Questions 
#### i. How does the Agile methodology differ from the traditional Waterfall model, and when might one be more suitable than the other?

**Differences:**

- **Waterfall Model**: Follows a linear, sequential approach where each phase (planning, design, implementation, testing, maintenance) must be completed before moving to the next. Changes are difficult to incorporate once a phase is finished.
    
- **Agile Methodology**: Emphasizes iterative and incremental development, with frequent feedback loops and adaptability to changing requirements. Work is divided into small cycles (sprints), and features are delivered incrementally.
    

**Suitability:**

- **Waterfall** is suitable for projects with well-defined, stable requirements and where documentation is critical (e.g., NASA's Mars Rover software or construction projects like building a bridge).
    
- **Agile** is better for projects with evolving requirements or where rapid delivery and user feedback are essential (e.g., mobile app development like Uber or video games like Fortnite).
    

---

#### ii. How can the Unified Process be adapted to a small software development team, and what challenges might arise?

**Adaptations for Small Teams:**
- Reduce formal documentation and focus on essential practices.    
- Emphasize communication, shared ownership, and rapid iterations.
- Skip extensive architecture documentation but maintain core phases (Inception, Elaboration, Construction, Transition).
- Use lightweight tools and prioritize working software over exhaustive planning.

**Challenges:**
- Limited resources may make it difficult to balance flexibility with structure.
- Risk of inadequate documentation leading to knowledge gaps or future maintenance issues.
- Ensuring all team members are aligned without overloading them with roles and responsibilities.

**Example:** A small team working on a capstone project might deliver a basic prototype early (Demo 1) and refine it iteratively based on feedback, skipping detailed documentation.

---

#### iii. Discuss a real-world project where you think iterative development would be more beneficial than a linear development approach.

**Example: Development of a Social Media Platform (e.g., Instagram or Twitter)**
- **Why Iterative?** User needs and market trends evolve rapidly. Features like Stories, Reels, or algorithmic feeds require continuous testing and refinement based on user feedback.
- **Benefits of Iterative Development:**
    - Early releases allow for user feedback, reducing the risk of building unwanted features.
    - Bugs and usability issues can be addressed incrementally.
    - Competitive advantage by quickly adapting to trends (e.g., adding short-video features in response to TikTok).
        
- **Linear Approach Limitation:** A rigid plan might fail to accommodate new requirements, leading to outdated features by launch.
    

**Contrast:** A project like NASA's Mars Rover software, with fixed requirements and high stakes, benefits more from the linear Waterfall model.