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


## Short code
- First of these higher level languages
- Developed for the BINAC
