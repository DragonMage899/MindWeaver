# 8 queens problem
- placing 8 queens on a board such that no queen attacks each other

Initial State : Empty Chess board
Define legal moves
Define heuristic (legal queen placement)
search method: choose best based on criteria 
- greedy hill climb : give up
- hill climb: local min & computation

State: specific arrangement of queens
represented by an array of length 8
array[rol] = col

Legal moves:

Heuristic: Number of pairs of queens attacking each other
- Check diagonals and horizontals

back track

Each node represents a partial config of queens on the board