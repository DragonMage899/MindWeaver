Solution is an answer to a specific problem instance

Representation used to describe nodes needs to be unique

**Local Search**
- Heuristic approach for solving optimization problems
- Works by iteratively improving a candidate solution (guess for best solution) 
- Chances of finding the best solution are improved by searching near the solution (candidate)
	- Find a good spot to search
- Explore in the neighborhood of the current solution
	- Need to define how to explore current neighborhood


How it works
- Start from a random position and improve from there
- Define a neighborhood
- Explore neighborhood of current solution
- If a better neighbor is found make it the new current
- Repeat steps 3 and 4 until a stopping criteria is met (max iteration, no betters etc.)

Key char
- iterative improvement
- neighborhood exploration
- heuristic
- definition and evaluation of neighborhood

**Simulated annealing** 

balance of exploitation and exploration

tabu similar to annealing,
- we keep a visited list (tabu list)
- don't revisit 
- list should be limited as to allow an algo to accept a worse solution