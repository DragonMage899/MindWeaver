Overview
- Programming Domains
- Criteria for language constructs and features
- Language Design: Machine architecture and programming design methodologies
- Categories of programming languages
- Trade offs
- General approach implementation
- Programming environments and their impact on software production

![[Pasted image 20250323114549.png]]
![[Pasted image 20250323114558.png]]
![[Pasted image 20250323114608.png]]
![[Pasted image 20250323114618.png]]
![[Pasted image 20250323114624.png]]
![[Pasted image 20250323114636.png]]
![[Pasted image 20250323114644.png]]


# Language evaluation criteria
![[Pasted image 20250223105428.png]]
- also cost which is not as closely linked as the other 3

#### **Readability**
Primary goal being code to maintenance in the 80s/90s.
Ease of maintenance dependent on readability of code

**Simplicity**
- The more basic constructs within a language the harder it is to learn and read, often people only learn a subset of the language.
- feature multiplicity: the amount of ways to complete a certain task/action e.g.) incrementing
- operator overloading: can be nonsensical without docs
- simplicity is not always a good thing: e.g. assembly operands conform to simplicity but it becomes less readable due to the lack of more complex control structures

**Orthogonality** //read up
- Combining a relatively small set of primitive constructs in a small number of ways to build control and data structures of the language
- Every primitive operation combination is legal and meaningful
- e.g.) pointers are able to point to any data type / structure
- Changing one thing does not affect the rest of the system
- Language features are independent and can be combined without restriction
	- Full: Lisp, Algol, Scala
	- Semi: Java, Python
	- Non: C/C++
	https://www.baeldung.com/cs/orthogonality-cs-programming-languages-software-databases
	- More orth = Easier to learn, many ways to do one thing, more user power
	- Complex to compile / int
	

**Data Types**
- defining data types and data structures

**Syntax Design**
- Examples include:
	- Key words
	- form and meaning (appearance should aid to provide meaning)

#### Writability
- Measure of how easily a language can be used to create a program for a domain specific problem
- Closely tied with readability
- Simplicity and Orthogonality: Misuse/Disuse of features if in abundance
- Expressivity

#### Reliability
- A program is reliable if it performs to its specification under all conditions
- Type Checking: checking at run time is expensive, rely on compile time checks
- Exception Handling: Ability to intercept run-time errors
- Aliasing: Having two or more distinct names that can access the same memory cell
- Readability and Writability: Language should support natural ways to write an intended algorithm, unnatural approaches can be prone to issues

#### Cost
- Cost can be categorized into many area's
- Training cost
- Cost of writing 
- Cost of compilation
- Cost of execution
- Cost of language implementation into system
- Cost of maintenance
	- correction, modification and addition

**Portability**
- Ease with which a system can moved between implementations
- Influenced by degree of standardisation 

**Generality****
- The applicability to a wide range of applications

**Well definedness** 
- The completeness and precision of the language’s official defining document

Criteria are neither precisely defined or precisely measurable.
Perspective and goals matters when evaluating criteria


## Influences on Language Design

#### Computer Architecture
- Most prevalent languages are designed around the von Neumann architecture (typically imperative)
![[Pasted image 20250223115112.png]]

#### Design Methodologies
- Cost moved from hardware to software
	- Top-down design and stepwise refinement were a direct result of this
- Shift from procedure to data in the 70s (user related design)
	- focus on adt to solve problems
- Final Shift into Object-oriented software design 80s
	- Data abstraction into data objects and controls to access data
	- Inheritance, dynamic method binding 
	- Inheritance enhances reusability of code 

#### Design Trade offs
- Evaluation Criteria Provide a Framework for language design
	- but it's Self conflicting
	- e.g. Reliability and cost of execution
		- checking array bounds with each access
	- Writability vs readable
		- Having many operations (apl with arrays) allows us to write complex code in a shorter time but decreases readability

#### Implementation Methods
- Compilation: Translating source into machine code 
![[Pasted image 20250223122125.png]]
- Fast execution once translation is complete
![[Pasted image 20250223122259.png]]

#### Pure Interpretation
- Source interpreted by interpreter
- Run time debugging can refer to source level lines
- Can be very slow and space consuming (symbol table)
- Useful for web scripting
![[Pasted image 20250223122546.png]]

#### Hybrid
- Perl
	- Partially compiled to detect errors
- Java
	- Source -> byte code
		- byte code interpreter + run time system = JVM
- JIT compilation
	- translates programs to an intermediate language during execution it compiles intermediate language into machine code which is kept for subsequent calls
![[Pasted image 20250223122906.png]]

#### Preprocessor
- Program that processes a program just before it's compiled.
- PP instructions are embedded in programs
- Used to specify includes, define symbols etc

## Programming Environments
- Collection of tools used in development of software.
- could include: file system, text editor, linker, compiler, other integrated tools within an interface etc.


# Summary
![[Pasted image 20250223123329.png]]

Do questions when studying

