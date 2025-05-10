
https://www.youtube.com/watch?v=b6uHw7QW_n4
https://www.youtube.com/watch?v=piF6D6CQxUw

# Genetic algorithm
## **Process**
- Pop init: create randomly
- fitness eval: use fitness function on each individual
- selection: Select parents, often fitter
- Genetic operators
	- Cross over
	- Mutation
- pop update (new gen replaces old, the number varies)
	- generational -> Whole population replaced
	- Steady State -> a specific amount replaced
- termination
	- Stopping criteria
		- Max iteration, near optimal etc...

## **Encoding** 
- Binary
- Real number
- Character


# Genetic Programming
- Explore a program space 
- Aim: evolve fitter computer programs

## Representation 
- Programs represented as syntax trees
	- which can be converted to executable expressions
- Internal Nodes
	- Functions (operators)
- External nodes (leaves)
	- Terminals (inputs to the program)
- Function set
	- Application specific operators '
- Terminal Set
	- Input to GP

## Properties 
- Closure
	- Output must be valid input
- Sufficiency 
	- Elements represent solution

# Process
- Init
	- Randomly generate population
		- Full: all nodes up to maxDepth - 1 are function
		- maxDepth nodes are terminals 
	- Grow Method
		- Tree's of variable lengths (a node at any non max level can be a function or a terminal depending on leave depth)
	- Ramped half and half
		- Maximum depth is user defined  
- Fitness
- Selection
- Genetic operators
	- Subtree crossover
	- Mutation
		- Grow mutation: replace a random terminal 
		- Shrink Mutation: Replace a random subtree with a random terminal
- Population replacement 
	- Steady state: replace one generation based on fitness
- Termination 

![[Pasted image 20250510080838.png]]

# Grammatical Evolution 
Codons: n bit binary string
BNF grammar

## Mapping
- Map variable length linear genomes to executable programs
- ![[Pasted image 20250510081529.png]]

## BNF
$<N , T,  P,  S>$
N -> Non terminals
T -> Production rules 
P -> NxT
S -> Start symbol (SEN)


# Ant Colony Optimisation
- Swarm intelligence algorithm 

Mimic foraging behaviour of ants 
- Pheromones deposited on ground 
- Fade if not reinforced 
- Stronger trails attract more ants

## Process
Init
- Set initial pheromone values and parameters (no. of ants)

Solution construct
- Each ant starts at a random node 
- Each ant then incrementally builds a solution by moving from one vertex to the next
	- Choice of next dependent on:
		- Pheromone value
		- Probability rule 
		![[Pasted image 20250510083058.png]]

Possible local search (optional)

Pheromone update
- Increase pheromones on high quality trails, decrease on low quality 
- Evaporation
	- Reduce pheromones on all trails be evaporation rate
- Deposition
	- Add pheromones to good trails
- Use update rule 
![[Pasted image 20250510083115.png]]
![[Pasted image 20250510083129.png]]


## Parameters
- Number of ants
- p (evap rate)
- Q (pheromone intensity)
- nij (heuristic info)
- a,b 
- local search strat
- Termination criteria 

![[Pasted image 20250510083331.png]]


# Particle swarm optimisation 
Population based optimisation technique 
inspired by behaviour of birds flocking or fish schooling 

Particles: Each particle moves through the solution space and adjusts their position
- Has a position and velocity in the search space
- Move towards optimal particles based on own experience and experience on neighbours 

## Process
- Init
	- Swarm is random particles (with random positions and velocities)
- Eval 
	- Generate fitness values for each particle
- Update pb
	- if current position is better than pb, update pb 
	- Do this for each particle 
- Update global best
- Velocity update
- ![[Pasted image 20250510084510.png]]
	- Next velocity =
	- inertia weight * current velocity 
	- cognitive * random num1 (acceleration coefficients)
	- pb - current pos
	- social * random num2 (acceleration coefficients)
	- global best - current
- Position update
- ![[Pasted image 20250510084736.png]]

## Parameters
- Swarm Size (number of particles)
- Max velocity (prevent overshooting)
- Inertia weight (w) ->exploration vs exploitation 
- C1,C1 (acceleration coefficients) -> influences pb and gb
- Topology -> Particle communication
- Search strat
- Termination criteria 

![[Pasted image 20250510085006.png]]

# KNN
- Assign output to new a instance based on the output of K's closes neighbours

# Process
- Prepare Data
- Choose K
- Calculate Distance from new to all existing 
- Find K nearest
- Make a prediction
	- Classification
		- Assign majority class amongst k nearest 
	- Regression
		- Compute average of target values for K neatest neighbour 
- Characteristics
	- Easy to understand and implement 
	- Resource intensive
	- Vulnerable to noise or poor data
	- Distance metric choice is important 

![[Pasted image 20250510091818.png]]

# Hop field 
- Pattern Association
- Single layer neural network
- Input and output vectors are the same 

**Representation**
- I/O vectors can be inary 