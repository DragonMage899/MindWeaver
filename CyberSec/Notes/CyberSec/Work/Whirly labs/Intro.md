meeting one
**Log4shell**
If a user can interact with the logging it can be exploited 

Heartbleed
openssl
-> remotely read memory
- Can view password in memeory

Shellshock
-> way bash is connected to cgi
can inject 


5 weeks
Post what you're doing, share ideas

Week 1 
hands on training 

Week 2 
revive training, ass

week 3
qna

week 45
work on assignment 


Intern work
- nda

# Tools
Look thru code
find vuln
see if you can exploit it
communicate with customer and inform them
- If the customer doesn't think it's worth it
- Write a poc and showcase what it can do 

After a while you start spotting patterns and learning where to look
- starts to get boring 
- start to ask if it's possible to automate things
- Write code to look for patterns 
- This is where joern.io comes in
https://joern.io/

# Joern
- Fuzzy passer
- Process, find something if we don't understand, we mark it
- robust
- pattern matching, machine learning -> needs lots of data

cpg code property graph

Harder to statically analyse dynamically type languages


**Code property graph** 

![[Pasted image 20250609124423.png]]
Abstract syntax tree 
https://en.wikipedia.org/wiki/Code_property_graph

Can't ask how do the statements interact.

Important question
- Is it possible to get from one statement to other
- What are the conditions that need to be met 
- Trying to reach conditions in the code that's not meant to be reached with input

Flow
- How does the code look
- How can I interact with it 
- Data flow

![[Pasted image 20250609125015.png]]

After loading a project into joern you can start interacting with the cpg.

graph stored as an in memory graph database (flatgraph)
- Done for speed

Flatgraph is good for large graphs with a low disk footprint 
automated traversal language 

After compiling the cpg graph we can use ./joern to load it 


once it loads we get a shell where we can interact with the graph
![[Pasted image 20250609125749.png]]

If it needs a push down atuomata, we can't grep
like so
![[Pasted image 20250609125950.png]]

![[Pasted image 20250609130114.png]]

![[Pasted image 20250609130309.png]]

![[Pasted image 20250609130716.png]]
source is something attacker controlled
sink is where you want to reach
- sample path from source to sink

formulated 



We can preselect a bunch of code
- The preselcted code will meet the minimum requirements for the vuln we're targeting 
- Makes manually scanning alot easier 

--
looking for mallocs with weird arguements
![[Pasted image 20250609131044.png]]
![[Pasted image 20250609131104.png]]

we can use dump to inspect the snippets
![[Pasted image 20250609131131.png]]
and then jump through each occurrence 


we can also dump it into an editor 
![[Pasted image 20250609131241.png]]

## Using joern during the internship
We want to characteristics the vulnerability
Create a description for it
we can then use this description to search other code 

This allows us to have a database of queries that we can run onto any data base 





## Side notes
binary
use ghidra to decompile code to c (kinda like c actually)
we then pass this into the c parser


Don't go thru every string copy, call, memcpy anymore 
Have to be a bit smarter
Look for external and internal api's
Understand the assumptions behind it 