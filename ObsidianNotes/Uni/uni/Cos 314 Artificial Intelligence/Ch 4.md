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


## **Perturbative and Constructive Solutions**
- **Pertubing**: Modifying components of a candidate solution to create a new candidate solution
- Pertubative search methods: Uses pertubing

Pertubative approaches often involve directly searching candidate solutions and also possibly partial candidate solutions (one or more solution component missing)
Can be iteratively extended to create candidate solutions
	Which can be formulated as a search problem
	constructive search method

VS optimisation functions where goodness of solution solely relies on objective function


## **Systematic and Local Search**
**Search Approaches**
- **Systematic**
	- Search algorithms navigate entire search space
	- Completeness and certainty 
- **Local**
	- Begin at some point in a search space
	- Moves based on some local knowledge
	- Limited number of neighbours
	- Can revisit nodes
	- Incomplete and may get stuck in a part of the search space
	- Can employ special mechanisms to escape 

# Local Search
- Some cases:
	- Goal state has all information we need
		- Don't need to worry about path length too much
	- Find a state of least loss (based on some objective function)
		- Goal state may not be well defined
		- Search space may be too large to fully search
			- State of least loss is sufficient for application
	- Multiple goal states
		- Measure closeness to goal sates with heuristics
			- where goal state = 0 (loss / heuristic value)
		- Sometimes the goal state may be unknown but we can still work towards a candidate solution if we define desirable heuristics and work to minimise that 
- **Optimisation**
	- Define decision variables such that out set objective is the best outcome that adheres to the constraints we set 
	- Take NP-hard problems
		- Each solution is a state with an objective function that we're trying to optimise
		- However the notion of a goal state does not necessarily exist
			- e.g) TSP
				- Find a cycle of min goat (end node doesn't matter)
	- Goal-centric problems can be converted to optimization-centric problems with the use of properly defines loss functions 

## Definition of a local search
- **Local search algorithm**
	- Heuristic approach
	- Get solution by iteratively improving candidate solutions
	- Explores neighbourhood of current solution
		- Looks for better solution nearby
- General approach
![[Pasted image 20250321101611.png]]


## **Characteristics of a local search**
- A local optima occurs where the current state is the best in the neighbourhood BUT a more optimal state does exist outside of the neighbourhood
- Can be solved with backtracking 
	- Keep a list of other promising paths 
	- Allows algorithm to backtrack and explore other paths
- Still might get lost in a plateau area
	- Area in search space where the neighbours and current have the same value
		- Thus a next best direction cannot be found
- Getting stuck on a local optima is a common problem with NP-hard
- Finding real solutions is hard and simple algorithms such as hill climbing fails more often than not
- Alternative is needed
- We call a deterministic hill climb a tabu search 
- **Key Characterisitcs**
![[Pasted image 20250321104020.png]]

**Search Landscape**
- Problem with a way of defining nearby solutions
- Picture a map, where height of a point == goodness
- Points are connected by traversalable lines
- Lowest point on map is the best possible solution in the landscape
- Local search methods attempt to find this point
- Simplest local search (iterative improvement)
	- Only accepts moves to points that are better than current 
	- Stop when no better exists
- First improvement, takes first best
- Best improvement, scans all neighbours then takes best
- Both of these get stuck on a local optima 

**Types of local searches**
- Hill climb
- Simulated annealing
- Tabu search

## **Local search algorithms**
- Straight forward implementation
- Less computational overhead 
- Can tackle large and complex problems
- Preferred to exhaustive where large search spaces are a concern
- Converges to a local optima by iteratively improving on candidate solution through exploration.
- Does not guarantee finding the best solution 
- Results in a satisfactory result within a reasonable time frame 
- Uses fundamental problem solving concepts making it applicable to a large array of problems
- Can easily be tailored to fit other problems
- Can optimise Scheduling, resource allocation, machine learning, engineering design etc... 

## Simulated Annealing
- Flexible version of hill climb
- Allows for selection of worse option
- Temporary decrease on solution quality
	- Helps to avoid getting stuck in a local optima 
	- 
- Metal Annealing
	- Metal is heated to a high temp
	- Then slowly cooled down to form a stable - low energy crystal structure 
- 

![[Pasted image 20250321111144.png]]
Good starting T0 -> Slitght higher than average typical loss difference.
Pick random neighbour
- Accept if better 
- Or if worse and annealing probability met
	- Generate a random number
	- Set next to worse if:
		- **random < acceptance prob**
- Keep track of Best solution found since worse options are selected
- With each iteration reduce temperature (t0 / log(t+1))
	- The lower the temp, the less likely we are to choose a worse solution
- **t** -> Iteration number 
- Temperature can be reduced in various ways
	- consider trade offs for:
		- Time spent to find solution
		- Likely of getting stuck
- Instead of systematically back tracking we randomly jump out

**Disadvantages**
- Heavily dependent of settings
	- Start temp
	- Cooling schedule
	- Exploration technique 
- Getting the best settings can be time consuming
	- trial and error
	- each problem needs it's own best setting 
- Computationally Expensive
	- Explores many possibilities
- Heuristic
	- Best solution not guaranteed
	- stuck on good but not perfect solution
- Finding good solutions can be slow 
- Memory intensive for very large problems
- Finding a good solution can be slow if it cools down too quickly


## Tabu Search
- Similar to hill climb
- Allows solutions to worsen when they reach a local optima or reach a state considered to be almost a local optimum
	- almost: only improvement is in the visited list
![[Pasted image 20250321113520.png]]
- Start with initial guess
- Maintain tabu list (**recently** visited nodes) 
	- avoid repeats
- Pick a random neighbour of **current solution**
	- if neighbour is not in Z
		- remove oldest solution in Z if full
		- add neighbour to Z
	- if neighbour is better than current
		- current = neighbour
	- Consider best non-tabu neighbour
- Loop until a condition is met (e.g. max iteration count, time limit etc)
- Return best

**ALT from paper**
- Start with initial
- Generate neighbours
- Select best neighbour not in tabu lost
- update tabu list
- update best solution 
- repeat until stopping condition is met

**General approach to tabu search**
- Maintains a simple visited and unvisited list
Does not consistently enhance objective function.
Avoid taboo states
- if a taboo state is encountered
	- randomly select alternative state
	- random state can be worse
- Check for unvisited nodes & neighbours 
	- Move if improvement found in unvisited
	- Select random neighbour / unvisited node
- Terminate if no unvisited nodes exist (in current nodes neighbours)
	- current get's returned as result
	- May be a local optimum but typically out performs hill climb

**Enhancing performance**
- select best possible unvisited neighbour (quicker improvements)
- bound number of nodes in taboo  list
	- delete earliest visited node in list
		- more likely to be sub optimal
			- cost value generally improves over time
		- less likely to be visited
- Allow ways to keep short, intermediate and long term memory (list lengths)

Tabu search is a highly parameterised technique
- Influence where search beings in search space
- Effectiveness depends on initial config
- Memory limits allows for memory constraints
- Stopping criteria needs to be carefully selected as search relies on randomness

**Disadvantages**
- Can still get stuck in local optima
- Optimality not guaranteed
- Performance depends on parameters




# Game and Game playing

**Search In-Game playing**
- Look ahead to decide what moves should be made in a two person zero sum game 
	- One Winner
	- Two players

 **Minmax search algorithms**
 - If game tree is small enough we can look ahead to generate the entire tree
 - Then just look ahead to decide what move to make next 
 - Goal:
	 - Maximise score of one player (MAX)
	 - Minimise the score of the other (MIN)
 - MAX tries to get the best score and win the game
 - MIN tries to minmise MAX's score
 - Turn determined by level / depth
 - Look ahead algorithm
	 - Decision making and game theory
 - If small  enough leaf nodes can be allocated win(1), draw(0) or loss(-1)
 - These values are propagated up to determine which node to use.
 - By propagating back up a MAX node is given the maximum vale for all its children
 - Min node is given minimum value for all it's children

## Minmax Algorithm
- If limit of search has been reached
	- compute values for current position relative to player
	- Report Result
	- Else if
- min turn
	- get min child
- max turn
	- get max child

**Goal**
- Want to minimize maximum loss 
- Assumed best move at each level
![[Pasted image 20250324091844.png]]
![[Pasted image 20250324092027.png]]


## Characteristics
- Always finds most optimal path for a finite tree if both player's play normally
- Starts to struggle with a high branching factor 
	- Can be generated up to a particular depth at this point 
	- Since leaf nodes aren't known we have to use a heuristic instead
	- Typically estimates how promising a node is for MAX 
	- Horizon effect: promising paths are discarded due to limited info

## Alpha Beta pruning 
- with min max we examine all nodes until we hit a certain cut off depth
- Alpha beta pruning reduces the amount of nodes explored
![[Pasted image 20250324093332.png]]
**Alpha Cut**
- C is a Min Acceptor
	- Case 1: G < F
		- 3 still get's chosen for A
	- Case 2: F > G
		- 3 get's chosen as F promotes
	- Thus value of G is irrelevant and that branch should not be explored
 **Beta Cut**
 - Opposite

**Algorithm**
Assign two extra values to every nodes
- a -> Max's Best possible
- b -> Min value Max can be forced into'
- a >= b
	- prune branch

![[Pasted image 20250324093922.png]]


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
