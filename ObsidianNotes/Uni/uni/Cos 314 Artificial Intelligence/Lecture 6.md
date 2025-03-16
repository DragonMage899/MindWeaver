**Game Theory**
Represent moves in a tree
Ideally materialize the entire tree, this may be too large to generate in a reasonable time frame
Computer assumes the player makes the best move

**Algos**
Minmax
- 2 Players
	- Min and Max
- leaf nodes are score
- players alternate moves, Max moves first
- Players play by traversing the tree
	- e.g.) Max moves, Min evaluates value (updates current to min child), Max (holding -inf initially) and makes a move
	- levels alt between min/max
- Complex games have a large branching factor
- Alpha beta pruning can be used to fight this
- We prune branches that don't need consideration
	- beta < alpha don't consider other side for min node
	- alpha >= beta don't consider other side for max 
	- min doesn't update alpha, thus we can cut
	- alpha and beta's move down not up
- Ideal play leads to a draw