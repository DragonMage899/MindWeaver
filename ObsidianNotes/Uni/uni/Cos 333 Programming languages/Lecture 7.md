**CH15**

- Info from earlier chapters not covered in chapter is in slides


**Functional Programming**
- Focus on Scheme (Not Haskell, lisp as covered in ch2)

Design based on mathematical functions
Nor concerned with machine architecture
- Cost of execution increases since architecture is not considered

Mathematical Function
- Function -> kind of sub program

In functional programming
- Don't call function and pass parameters
- Apply functions functions to parameters 
- Returns a value (compulsory)

Functional side effects
- When a function changes a parameter or global value
- i.e. function modifies variable outside of its scope
- Issue: 
	a = 10
	b = a + fun(&a)
	- Is ambiguous (when a is modified)
- Solution:
	- Disallow functional side effects
	- Fixed evaluation order (left to tight)

Referential Transparency
- Two equivalent expressions
- One cause of referential breakdown
![[Pasted image 20250304085401.png]]
- No side effects
	- Can't modify value and global
	- No problem
- Else
	- result1: a get's modified twice
	- result2: a gets modified once
- Other ways to break returns
	- fun return a random number
	- Things that maintain state (returns will vary)
		- static (c++)
		- constant 

Functional programming languages features
- No variables
	- Thus side effects aren't possible
	- Can't have state thus no breakdown if referential transparency
- Mimics functional programming language
- No memory/variable management
	- memory safe

**Scheme**
- Data objects
	- Atoms
		- Symbols (Not variables, represent some abstract concept where meaning is determined by programmer)
		- Numeric (numbers innit)
	- Lists
		- Sequence of atoms or lists / sub lists
		- (A B (C D ) E)
			- separated by spaces
- Interpreter
![[Pasted image 20250304091044.png]]
![[Pasted image 20250304091304.png]]
Order does not matter since functions don't have side effects
return depends on input and nothing else


![[Pasted image 20250304091435.png]]
(+ 5 2)
- yields result where + is our function

![[Pasted image 20250304091612.png]]

![[Pasted image 20250304092007.png]]
![[Pasted image 20250304092024.png]]
