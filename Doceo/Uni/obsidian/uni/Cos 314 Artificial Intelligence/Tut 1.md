1a) Steps taken since goal
b) xr - xs + yr - ys

Q: Does it never overestimate the cost of reaching the goal
	cost estimated is not higher than lowest possible
	lower bound cost
2a) No, shorter path could exist
- proof

3a) yes

4a) BFS
b)5
c)10
d)5

5a) ABCDEFG
b) ABDG
c) ABDG

6A) TRUE

7a) Best search
b) A* algo

8a) explore the sub tree of the minimum h val node

9a) list of possible nodes to visit from current without visited nodes
b) Move from a to b if a road connects the two
c) Distance to next city
d)?

10a)ABCDE
b)ABDHKMNLOE
c)ABDHKLE

11)NoQ
a)ABCDEFGHIJKLMNO --> ACGBDEQ
b)ACBD --> ABDEQ
c) Greedy must improve, Best first will explore unselected even if worse

12a) SBADH
b) Best search but search local mins
- SBEIFADH
c) hn = hi + path length
- SADH - SBADH
d) idk

13a)SBFJ
b)SBFJ
c)SBFJ
d)yes

14a)no
b)no




2 proof
admissibility.

1. Define h(n)=d(n,A)+d(A,goal)h(n)=d(n,A)+d(A,goal).
    
2. Assume h(n)h(n) is admissible, so:
    
    h(n)≤d(n,goal)(1)h(n)≤d(n,goal)(1)
3. By the triangle inequality:
    
    d(n,goal)≤d(n,A)+d(A,goal)d(n,goal)≤d(n,A)+d(A,goal)
4. Substituting h(n)=d(n,A)+d(A,goal)h(n)=d(n,A)+d(A,goal) into (1):
    
    d(n,A)+d(A,goal)≤d(n,goal)d(n,A)+d(A,goal)≤d(n,goal)
5. Combining this with the triangle inequality:
    
    d(n,goal)≤d(n,A)+d(A,goal)andd(n,A)+d(A,goal)≤d(n,goal)d(n,goal)≤d(n,A)+d(A,goal)andd(n,A)+d(A,goal)≤d(n,goal)
6. This implies:
- d(n,goal)=d(n,A)+d(A,goal)
- However, this equality **only holds if the shortest path from nn to the goal goes through AA**. If there exists a shorter path from nn to the goal that does not go through AA, then:
    
    d(n,goal)<d(n,A)+d(A,goal)d(n,goal)<d(n,A)+d(A,goal)
- In this case, h(n)=d(n,A)+d(A,goal)>d(n,goal)h(n)=d(n,A)+d(A,goal)>d(n,goal), which violates the admissibility condition h(n)≤d(n,goal)h(n)≤d(n,goal).
    
- Therefore, h(n)h(n) is **not admissible** in general.

