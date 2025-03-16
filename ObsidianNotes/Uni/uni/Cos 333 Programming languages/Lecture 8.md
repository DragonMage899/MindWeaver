ch15 pt2

scheme list functions
- immutable 

List Functions
- quote:
	- In scheme we first eval all the parameters
		- Atoms evaluate to themself
		- List form parameters need to be evaluated as a function 
			- Scheme interpreter:
				- List will be interpreted as a function by default
				- It will look at the first item in the list and look for a function of the same name (which dne)
			- The quote function is used when evaluation is not appropriate 
				- returns parameter without evaluation
				- short hand notation

- list:
	- takes an amount of parameters
	- returns list with parameters
	- Need to quote non numeric parameters
	- maintains order that was given
	- can make nested lists

- car
	- yields first element of list
	- produces an error when used on atoms or non numerics

- cdr
	- yields remainder of list parameter after first element has been removed
	- new list as list are immutable (w/o first)
	- same error thing
	- When processing a list, lists end with an empty list (base case)
	- cdr can be used repeatedly untill an empty list is reached (end of list)

- cons:
	- Put's first parameter and puts it into second parameter as first element
	- Push function that returns a new list with added item
	- empty lists can be inserted into other lists
	- When second elem is atom a dotted pair is produced (useless

- list?
	- check if is a list
- null
	- check if empty [(()) is false]
	- eval base case

- eqv?
	- returns true if the same
	- value comparison, not pointer
- eq?
	- pointer comparison 

- let
	- binds values/expressions
	- to names

- member (not provided, need to be self implemented)
	- 