Memory stored contig -> efficient iteration
recursion discouraged -> New stack frame per each recursive call
- memory intensive
- processing intensive (execution time)

Data-oriented -> data related to people become more prominent



--- 

### Part 3

**Language categories**
- Imperative
	- Optimized for von Neuman (loops, assignments, statements etc)
- Functional
- Logic
- Markup


## Implementation Methods
- System that takes a program written in a high level language and turns into an executable

### Compilation
- Source code turned into machine language
- Commercial / efficient applications
- Slow translation fast execution
- (Don't memorize diagram)

### Pure Interpretation
- Program interpreted by another program
- Interpreter executes source code portion by portion
- Slow thus usually used for small scripts
- No translation
- Easy implementation
- Error will occur at a specific line (easier to debug)
- More space
- Errors only picked up at runtime
- For loops, each iteration needs to be decoded 
- Web Languages interpreted 
	- Unsure what clients hardware is
	- Interpreters written for each platform
	- Not tied to a specific build

### Hybrid
- Between compilation and interpretation
- Efficiency is not the primary concern
- High level lang to Intermediate language that allows easy interpretation
- Slower than compiled but faster than pure interpreted 
- e.g.) 
	- Perl 
	- Java -> Source to Byte code (.class) which can be interpreted by the JVM
		- Highly portable'
#### Just in time implementation
- Java
	 - Source code to intermediate (byte code)
	 - byte code to machine code (only converts as it's executes)
	 - machine code version is cached for subsequent calls
		 - First time a method is called will be slow, subsequent calls will be faster
		 - First loop is slow, subsequent is faster
 - .Net