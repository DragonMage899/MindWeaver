# **Metaheutistics:**
- More general form of a heuristic
	- Can be applies to a variety of problems 
- Balance exploration of new potential solutions 
- Exploitation of promising areas already discovered
- Can escape local optima
- Formal Def:
	- Iterative generation process which guides a subordinate heuristic by combining intelligently different concepts for exploring and exploiting the search space, learning strategies are used to structure information to find efficiently near-optimal solutions
## Characteristics
- Det path and direction of search
- Stochastic (some randomness)
- Can escape local optima
- General and non-specific to a scenario
- Lower level heuristics have domain knowledge

**Classification**
Can be Single point or Multi Point
- Single point algo works on one solution at a time
- Multi point conducts a parallel search

## Single Point
- Walks in search space that move from one neighbour to the next using iterative procedures
- Iterative procedures
	- Generation and replacement from single current solution
- Generation Phase
	- Generate candidate solutions from current solution
- Replacement Phase
	- Set better neighbour as current
	- Loop until stopping criteria met
- Examples:
	- SA, Tabui, ILS, VNS
### Iterated local search
- Improve upon results of a basic local search procedure
- Useful when local optima traps are common
- ILS iteratively perturbs locally optimal solution
	- Applies local search again to explore new areas in solution space
	- Uses diversity and intensification to navigate search landscape more efficiently 
	- Leads to better solutions than normal local searches 
	![[Pasted image 20250325172320.png]]
	![[Pasted image 20250325172401.png]]
### Knapsack Problem
- Select a subset of items, with each item having a weight and value to maximize total total value for a knapksack with limiter weight
![[Pasted image 20250325173245.png]]
![[Pasted image 20250325173253.png]]
![[Pasted image 20250325173303.png]]

## Multipoint search
- Explore multiple regions of the search space
- Population of candidate solution with concurrent evaluation and manipulation of diverse search pathways. 
- Maintain and evolve a collection of potential solutions
- Useful for vast high dimensional search spaces

**Evolutionary Computation**
- Models Darwinian principle of natural selection on computational methods 
- Operate on a selection of candidates
- Population is a collection of individual candidates 
- Each candidate has a fitness value
- Fitness function evaluates how well a candidate solution solves the problem being considered 
- Each iteration of a evolutionary algorithm is called a generation
![[Pasted image 20250325175026.png]]
![[Pasted image 20250325175048.png]]

## Genetic Algorithm
- Individual is a candidate solution
	- Typically encoded as a fixed length linear chromosome
	- Each gene of the chromosome is a binary Bit String
	- Other types of encoding can be used
![[Pasted image 20250325175509.png]]

**Initial Population**
Create initial population randomly 
- Value of each gene is randomly selected from a range of possible values
- Number of chromosomes determined by population size
![[Pasted image 20250325175931.png]]

![[Pasted image 20250325180003.png]]
![[Pasted image 20250325180031.png]]

![[Pasted image 20250325180241.png]]
![[Pasted image 20250325180308.png]]
![[Pasted image 20250325180337.png]]
