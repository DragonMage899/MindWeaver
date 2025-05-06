## 🔍 What Are Metaheuristics?

**Metaheuristics** are high-level, problem-independent frameworks that help in finding approximate solutions to **hard optimization problems**, especially where exact methods (like brute force or exhaustive search) are impractical due to time or computational complexity.

### ✅ Key Characteristics:

- **Heuristic-based**: Uses educated guesses to find good-enough solutions.
    
- **Black-box approach**: Treats the problem as unknown; requires minimal domain-specific knowledge.
    
- **Iterative & stochastic**: They use randomness and loops to explore the search space.
    
- **Trade-off**: Balances between **exploration** (trying new solutions) and **exploitation** (refining current good ones).
    

---

## 🧩 Solution Space Concepts

- **Solution Space (Search Space)**: All possible solutions.
    
- **Neighborhood**: Set of solutions reachable by small changes (called "moves").
    
- **Local Optimum**: A solution better than its neighbors but not necessarily the best overall.
    
- **Global Optimum**: Best solution in the entire space.
    

➡️ _Example_: In the **Travelling Salesman Problem (TSP)**, each possible city order is a point in the solution space.

---

## 🧠 Types of Metaheuristics

### 1. **Trajectory-Based Metaheuristics**

- Follow a single solution (trajectory) through the space.
    
- Move from one solution to another based on some rule.
    

#### 🌀 Hill Climbing (Greedy Local Search)

- Move to the best neighbor.
    
- **Problem**: Gets stuck in local optima.
    
- **Variants**:
    
    - **Steepest Ascent**: Picks the best of all neighbors.
        
    - **First Improvement**: Picks the first better neighbor found.
        

#### 🔄 Simulated Annealing

- Inspired by metallurgy (slow cooling of metal).
    
- **Accepts worse solutions** to escape local optima using a probability function based on a **temperature (T)**.
    
- As T → 0, becomes more like Hill Climbing.
    

📌 _Exam Tip_: Know how temperature and acceptance probability work.

---

### 2. **Population-Based Metaheuristics**

- Maintain and evolve **multiple solutions** (population).
    
- Better at **exploration** than trajectory-based methods.
    

#### 🧬 Genetic Algorithms (GA)

- Inspired by natural evolution.
    
- **Key steps**:
    
    1. **Selection** (e.g. tournament, roulette wheel)
        
    2. **Crossover** (combine parents)
        
    3. **Mutation** (introduce small changes)
        
    4. **Replacement** (form next generation)
        
- Use a **fitness function** to evaluate quality.
    

➡️ _Example_: Optimizing a binary string to maximize 1’s.

#### 🐜 Ant Colony Optimization (ACO)

- Inspired by how ants find paths using **pheromones**.
    
- Ants probabilistically choose paths based on pheromone level + heuristic info.
    
- **Evaporation** prevents convergence too early.
    

#### 🐦 Particle Swarm Optimization (PSO)

- Inspired by birds/fish.
    
- Each particle adjusts its position based on:
    
    - Its own best-known position (**pBest**)
        
    - Global best-known position (**gBest**)
        
    - Random exploration component
        

---

## 🧠 Intensification vs Diversification

| Term                | Description                                                     |
| ------------------- | --------------------------------------------------------------- |
| **Intensification** | Focus search on the best regions (exploitation).                |
| **Diversification** | Explore new areas to avoid premature convergence (exploration). |
🧠 _Good metaheuristics balance both_ to avoid local optima and find global solutions.

---

## 🧮 Fitness Landscapes

- Visual metaphor of the solution space.
    
- Peaks = good solutions; valleys = bad.
    
- Metaheuristics try to "climb" peaks without getting stuck on small hills.
    

---

## 🔁 Iterative Improvement Techniques

- **Tabu Search**:
    
    - Remembers recently visited solutions (Tabu List) to avoid cycles.
        
    - Can override Tabu status with **aspiration criteria** if a move is too good to ignore.
        
- **Variable Neighborhood Search (VNS)**:
    
    - Changes neighborhood structure dynamically to escape local optima.
        
    - Switches between different local search strategies.
        
- **Iterated Local Search (ILS)**:
    
    - Repeatedly apply local search + perturbations to escape local minima.
        

---

## 🧩 Hybrid Metaheuristics

Combine multiple techniques for better performance.

➡️ _Example_: GA + Local Search = Memetic Algorithm.

---

## 📝 Example Problems & Metaheuristic Applications

|Problem|Suitable Metaheuristic|
|---|---|
|**Travelling Salesman (TSP)**|SA, GA, ACO|
|**Knapsack Problem**|GA, Hill Climbing, SA|
|**Job Scheduling**|GA, PSO, VNS|
|**Function Optimization**|PSO, SA|
|**Vehicle Routing**|ACO, Tabu Search|