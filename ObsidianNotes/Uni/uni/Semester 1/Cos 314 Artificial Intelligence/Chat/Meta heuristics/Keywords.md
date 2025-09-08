- **Metaheuristics**  
    General-purpose algorithms used to find good-enough solutions to hard optimization problems when exact methods are impractical.
    
- **Search Space**  
    The set of all possible solutions to a problem.
    
- **Neighborhood**  
    The group of solutions that are similar or reachable from a current solution by a small change.
    
- **Local Optimum**  
    A solution that is better than its neighbors but not necessarily the best overall.
    
- **Global Optimum**  
    The best solution across the entire search space.
    
- **Hill Climbing**  
    A simple local search that keeps moving to a better neighbor until no improvements can be made.
    
- **Simulated Annealing**  
    A technique that allows occasional worse moves (based on temperature) to escape local optima.
    
- **Temperature (SA)**  
    A control parameter in simulated annealing that decreases over time and influences the acceptance of worse solutions.
    
- **Genetic Algorithm (GA)**  
    A population-based algorithm inspired by natural selection using selection, crossover, and mutation to evolve solutions.
    
- **Selection (GA)**  
    A method for choosing which individuals from the population will become parents (e.g., tournament, roulette wheel).
    
- **Crossover (GA)**  
    Combines parts of two parents to produce a new offspring solution.
    
- **Mutation (GA)**  
    Random changes to a solution to maintain diversity in the population.
    
- **Fitness Function**  
    A way to evaluate how good a solution is; higher fitness = better solution.
    
- **Ant Colony Optimization (ACO)**  
    A metaheuristic inspired by ants' pathfinding using pheromones and probabilistic decisions.
    
- **Pheromone (ACO)**  
    Virtual chemical trails laid by ants that influence the probability of selecting certain paths.
    
- **Evaporation (ACO)**  
    Reduces pheromone strength over time to prevent convergence to suboptimal solutions.
    
- **Particle Swarm Optimization (PSO)**  
    A population-based method inspired by bird flocking where particles adjust their positions based on individual and global bests.
    
- **pBest (PSO)**  
    The best position a particle has found so far.
    
- **gBest (PSO)**  
    The best position found by any particle in the swarm.
    
- **Intensification**  
    Focus on searching around the best-known solutions (exploitation).
    
- **Diversification**  
    Exploration of new or less-visited parts of the solution space to avoid local optima.
    
- **Tabu Search**  
    Local search that uses a memory structure (Tabu list) to avoid revisiting recent solutions.
    
- **Tabu List**  
    A short-term memory storing recently visited solutions or moves to prevent cycles.
    
- **Aspiration Criteria (Tabu)**  
    A rule that allows overriding the Tabu status if the move leads to a significantly better solution.
    
- **Variable Neighborhood Search (VNS)**  
    A method that systematically changes the neighborhood structure during search to escape local optima.
    
- **Iterated Local Search (ILS)**  
    Repeated application of local search combined with perturbations to jump out of local minima.
    
- **Hybrid Metaheuristic**  
    Combines two or more metaheuristics to improve performance or adaptability.
    
- **Memetic Algorithm**  
    A GA enhanced with local search techniques applied to some or all individuals (GA + Local Search).
    
- **Exploration**  
    Searching new areas of the solution space to find promising regions.
    
- **Exploitation**  
    Focusing on the most promising area found so far to refine the best solution.
    
- **Fitness Landscape**  
    A metaphor for visualizing solution quality; peaks represent good solutions, valleys poor ones.