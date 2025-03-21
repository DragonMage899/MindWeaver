# Combinatorial Problems
- Mathematical puzzles that focus on counting, arranging or choosing items in a specific way
- Problems deal with a limited amount of items
- Typical goals:
	- How many different arrangements / selections are possible given certain rules or restrictions
- Permutation: Number of ways to arrange a set of objects
- Combinations: Number of  ways to pick a smaller group from a larger group
- Partitioning: Number of ways to divide items amongst people
- Graph Coloring: Number of ways to color a map
- Graph Traversal: Number of routers it's possible to take through a network
- tldr: Finding the best way to order, group or assign a limited set of items while meeting criteria

**Combinatorial optimization problems**
- Goal: Find optimal solution that minimizes or maximizes an objective function
	- e.g.) Total cost, distance, time, profit etc.
- Solution spaces can be huge such that exhaustive methods become non-practical 
- Creates a need for specialized algorithms and techniques to search the solution space 
	- e.g.) heuristics, metaheuristics, dynamic programming to
	- can produce near-optimal solutions
![[Pasted image 20250225095914.png]]

**Problems and Solutions**
Problem instance solution
- Actual solved solution

Abstract problem solution
- Algorithm to solve a problem instance for a problem 

In general
- set of problem instances
- problem instance: pair of input and solution data
- candidate solution: potential solutions that may be encountered during the attempt to solve a given problem instance
- candidate solutions may not satisfy all conditions from problem definitions 
	 - For our shortest round trip example, typically any valid round trip connecting the given set of points, regardless of length, would be a candidate solution, while only candidate round trips with minimal length would qualify as solutions.


**Perturbative and Constructive Solutions**
- **Pertubing**: Modifying components of a candidate solution to create a new candidate solution
- Pertubative search methods: Uses pertubing

Pertubative approaches often involve directly searching candidate solutions and also possibly partial candidate solutions (one or more solution component missing)
Can be iteratively extended to create candidate solutions
	Which can be formulated as a search problem
	constructive search method

VS optimization functions where goodness of solution soley relies on objective function


**Systematic and Local Search**




# CHAT
### **Key Topics & Examinable Sections**

#### **1. Combinatorial Problems**

- **Definition**: Problems involving finding an optimal arrangement, selection, or ordering of a discrete set of elements.
- **Examples**:
    - **Travelling Salesman Problem (TSP)**
    - **Knapsack Problem**
    - **Job Scheduling Problem**
    - **Boolean Satisfiability Problem (SAT)**
- **Types of Solutions**:
    - **Perturbative Solutions**: Modify an existing candidate solution.
    - **Constructive Solutions**: Build solutions step by step.
- **Systematic vs Local Search**:
    - **Systematic Search**: Explores the entire space methodically (e.g., backtracking).
    - **Local Search**: Starts with an initial solution and improves iteratively (e.g., hill climbing).

---

#### **2. Local Search**

- **Definition**: A heuristic approach to find an approximate solution by exploring neighbors of the current solution.
- **Key Characteristics**:
    1. **Iterative Improvement**
    2. **Neighbourhood Exploration**
    3. **Heuristic Nature**
    4. **Problem-Specific Design**

##### **Hill Climbing**

- A local search algorithm that **moves in the direction of increasing value** until no further improvement is possible.
- **Problem**: Gets stuck in **local optima**.

##### **Simulated Annealing**

- **Concept**: Inspired by the annealing process in metallurgy, it allows occasional moves to worse solutions to escape local optima.
- **Algorithm**:
    - Start with an initial solution and a high temperature.
    - Gradually lower the temperature while exploring new solutions.
    - Accept worse solutions with some probability to avoid local optima.
- **Disadvantages**:
    - **Parameter sensitivity** (temperature settings impact performance).
    - **Computational cost** due to extensive exploration.

##### **Tabu Search**

- **Concept**: Uses a **memory-based approach** to avoid revisiting recent solutions and escape local optima.
- **Algorithm**:
    - Maintains a **tabu list** (recently visited solutions).
    - If no improving moves exist, chooses a non-tabu move that worsens the objective function.
- **Disadvantages**:
    - **Can still get stuck in local optima**.
    - **No guarantee of optimality**.
    - **Performance depends on parameters** (tabu list size, stopping conditions).

---

#### **3. Game Playing and Decision Making**

- **Search in Game Playing**: AI makes optimal decisions by searching through a game tree.
- **Minimax Algorithm**:
    - Used in **two-player zero-sum games**.
    - Players: **MAX (tries to maximize score)** and **MIN (tries to minimize opponent's score)**.
    - Evaluates game states by backpropagating values from the leaf nodes.
- **Alpha-Beta Pruning**:
    - **Optimization technique for minimax** that avoids unnecessary branches.
    - Introduces two values:
        - **Alpha (α): Maximum score MAX can achieve**.
        - **Beta (β): Minimum score MIN can force MAX into**.
    - If **α ≥ β**, further exploration of the branch is stopped.
    - **Significantly reduces computation time** while ensuring the same decision as minimax.

---

### **Likely Exam Questions**

1. **Combinatorial Optimization**
    
    - Define **combinatorial problems** and provide examples.
    - Explain the difference between **perturbative and constructive solutions**.
    - Differentiate between **systematic and local search**.
2. **Local Search Techniques**
    
    - Describe **hill climbing** and its limitations.
    - Explain **simulated annealing** and why it is used over hill climbing.
    - Outline the **tabu search algorithm** and its disadvantages.
3. **Game Playing and Search**
    
    - Describe the **Minimax algorithm** and its role in two-player games.
    - Explain the **concept of Alpha-Beta Pruning** and its advantages.
    - Demonstrate a step-by-step application of **Minimax with Alpha-Beta pruning** on a given game tree.

# Test
1. Hill climbing with back track problem
2. What is a pleatue
![[Pasted image 20250317150403.png]]
![[Pasted image 20250317150422.png]]
![[Pasted image 20250317150510.png]]
![[Pasted image 20250317150532.png]]
![[Pasted image 20250317150610.png]]
![[Pasted image 20250317150626.png]]
![[Pasted image 20250317150732.png]]
![[Pasted image 20250317150758.png]]
![[Pasted image 20250317150811.png]]
![[Pasted image 20250317150824.png]]
