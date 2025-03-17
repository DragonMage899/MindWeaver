#### Blind search
- No info about problem beyond definition
- dfs dfid bfs
- systematic exploration of search space
- follow fixed set of rules w/o heuristics
	- heuristics: Knowledge that can aid in solving the problem

#### Informed / heuristic-driven search
- Best first search, hill climb, branch and bound, A*

**np hard**: non solvable in poly time
**operator**: defines transition

state space: advance vs runtime:
- State space would be too large to generate in advance

### Problem types
#### Possible solution
 - Representation
 - Yes/No
 - Solution path

#### DFS 
- Waste time exploring the wrong side of a long side tree
- Can get "lost"
- long sol path
- more efficient for high branching 

#### BFS
- Suffers time waste for long tree's
- Guaranteed shortest path
- Combinational exploding due to bad branching factor
	-  

### DFS iterative deepening 
- DFS till Depth limit
- Once reached starts BFS at that level


