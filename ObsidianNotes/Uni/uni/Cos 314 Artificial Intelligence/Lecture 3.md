 - weak search methods
	 - The heuristic may or may no help us to find the goal

Heuristic function computes HV from current state to goal state


Admissible: 
- Never over estimate or we'll never get there
	- Keep on thinking the goal is ahead of us even once we pass it
	- The goal path may be discarded
- rather under estimate
- straight lines are admissible (min distance for travelling)

Tile Reversal
![[Pasted image 20250218104911.png]]
Assume 1 and 7 were swapped.
We'd need to swap 1 and 7 to reach the goal state
tile reversal: 2 times amount of nodes out of place

![[Pasted image 20250218104959.png]]

![[Pasted image 20250218105336.png]]
Jump from F to B since B is in the unvisited queue and has the min HV 


#### Hill climb
- Considers Local states
	- i.e. won't consider B3 at F2 since B3 is not local
		- Can't get it to it from current state
![[Pasted image 20250218105908.png]]
- Go to J from F regardless of the cost
- Hill climb: Next step must go up (improve from current step)

## Greedy Hill Climb
- State we go to must be better than my current state
![[Pasted image 20250218110533.png]]
Backtrack to initial state
If D == 3
- Abort, No new operators are available
- Local Best found (under current config it's assumed that the path as ended)
- Need to find a better state to progress
- if the stars align it can be very quick

## A Algorithm
- 