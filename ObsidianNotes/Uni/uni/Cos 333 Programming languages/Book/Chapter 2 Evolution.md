![[Pasted image 20250223132313.png]]

# Zuse's Plankalkul
- Simplest data type: single bit
	- Integer and floating point build from this
	- two's comp fp
- Arrays and records{structs, with nesting}
- iterative "for" statement, no goto, 
	- "Fin" exit for loop / start of new iteration cycle
	- selection statement, no else
- Mathematical expressions showing current relationship between program variables 
	- Expressions stated what would be true  where they appeared
	- similar to assertions on Java
- Notation
	- Each statement has 2/3 lines of code
		- first line standard
		- second line contained subscripts of array references in first line (optional)
		- last line had type name for variables in first line
	- e.g.) A[5] = A[4] + 1
		![[Pasted image 20250223133752.png]]
		- V: subscript
		- S: data type
- Developed during ww2 in isloation
- his other shiz got bombed 


# Pseudocodes 
Early computers were hard to work with
- needed to code in machine code
- absolute addressing 
	- Inserting a program anywhere besides the end would invalidate addressing used by other programs (deletion can be mitigated with "no operation")
	
Assemblers and Assembly languages were invented to address these issues.

Most problems of this time needed indexing for array usage or fp operations which was not possible at the time.

This also lead to the invention of higher level languages



# IBM 704 and Fortran
in 1954 we got IBM 704
- prompted development of Fortran

Slow compute times acceptable since fp hardware non existent 
- Interpretation cost accepted since fp had to be expensively simulated in software
- Alternative was hand coding (assembly)

Then IBM 704 was announced
- it had indexing and floating point  instructions on hardware 
- Ended era of interpretation
- Fortran credited with being the first high level compiled language 

**Fortran**
- Formula Translating system

**Fortran 0**
- Document
- Ease of interpreted with cost of hand code 
- "Eliminate coding errors and debugging" lmao
	- First compilers included little syntax checking
- **Environment**
	- Small Memory, slow and unreliable computers 
	- Mostly used for Scientific computation
	- Programming was not efficient and effective
	- Computers were expensive (compared to programmers)
		- Speed of code generation was the main goal
	- Later versions follow from this environment

**Fortran I**
- Modifications made during implementation of Fortran 0 resulted in Fortran I
- I/O formatting
- 6 Char variable names
- User defined subroutines
- If and Do loops
- Control statements based on 704 instructions
- IJKLMN -> if a var started, it's an int else it's a FP
![[Pasted image 20250323131450.png]]
- About half as efficient has hand code
- About 50% code written on the IBM was Fortran in 1958
- FP and array not in software
	- Idea of compiled languages

**Fortran II**
- Added independent compilation of sub routines 
	- Could now change sub routines without having to recompile entire program
	- Fortran I could not do this and add poor reliability
		- programs were restricted to 300-400 lines
		- longer programs had a low chance of being compiled
	- Independent sub routines enabled longer programs

Fortran IV
- Explicit types declarations
- Logical Selection statements (if)
- Subprogram names could be parameters and passed to other sub programs
- Ansi STANDARD IN 1966

Fortran 77
- Char string handling 
- logical loop control
- if then else

Fortran 90
![[Pasted image 20250323132932.png]]
![[Pasted image 20250323132943.png]]
![[Pasted image 20250323132955.png]]


# Lisp
- Functional language 
	- List processing required by AI applications
	- Processing lists
	- Symbolic data computation (instead of numeric)
	- Recursive operations
	- Automatic dynamic storage handling 
- John McCarthy at MIT
	- FLPL did not support:
		- Conditional expressions
		- dynamic storage allocation
		- implicit deallocation

**Language Overview**
- Pure Lisp 
- Data Structures
	- Atoms 
		- Symbols in the form of identifiers
		- Numeric Literals
	- Lists
		![[Pasted image 20250323134739.png]]
- Functional programming
	- All computation done by applying functions to arguments  
	- No assignment statements or variables 
	- Repetition achieved with recursion (nor for loops)
- Syntax
- (A B C D)
	- Can be interpreted as data or code
	- Data
		- List containing 4 atoms
	- Code
		- Function A that accepts parameters B C D 

Dominated AI applications for 25 years
Was considered inefficient but this was idea was eliminated over time
Pioneered functional languages.

![[Pasted image 20250323135643.png]]

**Descendants**
- Scheme
	- MIT 1970s
	- Small size
	- Use of static scoping 
	- Treats functions as first class entites
		- Functions can be assigned to variables 
		- Passed as params
		- returned by other functions 
		- can be elements of a list

- Common List
	- Combined features of then prominent lisp dialects to fix lack of portability issues
	- Large and hard to use
	- both static and dynamic scoping

# Algol
- **Environment**
	- At the time there was a lack of portability as languages were being developed for a specific machine in mind
	- Fortran had just arrived
	- No universal way to communicate algorithms
	- ALGOL was a way to develop a universal language (for scientific purposes)
- Algorithmic Language
- Goal:
	- Close to mathematical notation
	- Describe algorithms
	- Translatable to machine code

**Algol 58**
- Zurich meeting
![[Pasted image 20250323140620.png]]
Assignment:
- variable := expression (match fortran)


**Algol 60**
![[Pasted image 20250323140903.png]]
![[Pasted image 20250323140921.png]]
![[Pasted image 20250323140937.png]]

# COBOL
![[Pasted image 20250323141007.png]]
![[Pasted image 20250323141037.png]]
![[Pasted image 20250323141107.png]]

**Eval**
- Define
- Macros
- Records (as a DS)
![[Pasted image 20250323142006.png]]
![[Pasted image 20250323141941.png]]
![[Pasted image 20250323141954.png]]

# BASIC
![[Pasted image 20250323142026.png]]
- Designed for liberal arts students

![[Pasted image 20250323142657.png]]

# PL/I
- First attempt at a language that could be used in a broad spectrum of applications
![[Pasted image 20250323142813.png]]
![[Pasted image 20250323142910.png]]
![[Pasted image 20250323142929.png]]
![[Pasted image 20250323142947.png]]

# APL
- A programming language
- Dynamic languages
	- Dynamic typing and dynamic storage allocation
	- Variables are untyped
	- Get's a type when it's assigned a value
	- Storage allocated when it's assigned
- Origins
	- Vehicle for describing computer architecture
![[Pasted image 20250323143338.png]]
![[Pasted image 20250323143347.png]]

# Simula 67
- Start of data abstraction
- Goal: Computer Simulation
- Extension of Algol 60
- Developed a class construct to allow for co routines
- early idea for data abstraction
![[Pasted image 20250323143440.png]]
![[Pasted image 20250323144210.png]]
PL/1 had many operators to do specific things whilst Simula focuses on allowing the user to combine basic concepts to achieve new functionality
![[Pasted image 20250323144328.png]]

# Pascal
![[Pasted image 20250323144420.png]]

# C
![[Pasted image 20250323144431.png]]

# Prolog
![[Pasted image 20250323144459.png]]

# Ada
![[Pasted image 20250323144535.png]]
![[Pasted image 20250323144610.png]]
![[Pasted image 20250323144707.png]]
![[Pasted image 20250323144716.png]]

# Smalltalk
- First lang to support OOP
![[Pasted image 20250323145055.png]]
![[Pasted image 20250323145106.png]]

# c++
![[Pasted image 20250323145242.png]]

# other oop
![[Pasted image 20250323145327.png]]

# Java
![[Pasted image 20250323145414.png]]
![[Pasted image 20250323145436.png]]

# Scripting languages
![[Pasted image 20250323145503.png]]
![[Pasted image 20250323145513.png]]

![[Pasted image 20250323145536.png]]
![[Pasted image 20250323145603.png]]
![[Pasted image 20250323145617.png]]
![[Pasted image 20250323145628.png]]
![[Pasted image 20250323145639.png]]
![[Pasted image 20250323145653.png]]
![[Pasted image 20250323145709.png]]

# Throw Questions into Chat
