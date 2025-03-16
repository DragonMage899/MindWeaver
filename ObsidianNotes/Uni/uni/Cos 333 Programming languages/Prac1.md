Research Questions

# Task 1
- **Question 1**
	An esolang is a computer programming language often created for non functional means such as experimenting with quirky ideas, testing the limits of readability and writability or as a joke [1] 

- **Question 2**
	Funge
	- A stack based[2] programming language that make use of a multi dimensional grid for code execution (i.e. non linear code execution)[2]&[ 3]&[4]
	- Advantages
		- Multi dimensionality provides the programmer with problem solving techniques that linear programming languages do not offer (e.g. self modifying code)
		- looks cool 
	- Disad
		- Hard to read and write unless your familiar already, even then
		- Limited support
		- Initial goal was make a language that was hard to compile[2]
	
	Turing Tarps
	- Languages focused on achieving Turing Completeness while also trying to be as minimalist as possible where language features are concerned[5]
	- Adv
		- Compilers and interpreters are generally small and easy to write
	- Disad
		- Not practical as simple tasks often require complicated code as per the origin of the name[6]


- **Question 3**
	Two languages:
	-  Whitespace
	- Shakespeare
-  their designer(s), year of initial design, and their general syntactic and semantic characteristics. Provide a short example code snippet, to illustrate the language’s general characteristics (you do not have to write the code yourself)

- Whitespace [7]
	- Developed by Edwin Brady and Chris Morris in 2003
	- Stack Based esoland
	- Only uses whitespace, tab and linefeed as syntax
	- All other chars ignored
	- Thus the program is completely hidden like John Cena
	- Turing Complete
	- Commands
		- Can be categorised by Instruction Modification Parameters (IMP)
		- Start with IMP followed by command followed by parameters 
		- (format in a table if possible)
		`|IMP|Command|
		`|---|---|`
		`|[Tab][LF]|I/O|`
		`|[Space]|Stack Manipulation|`
		`|[Tab][Space]|Arithmetic|`
		`|[LF]|Flow control|`
		`|[Tab][Tab]|Heap access|`

		`
		- Numbers
			- Start with a space for positive or tab for negative then have a sequence of spavc-o and 1-tab representing number in binary
			- End with LF
		- IO
			- Read input with Tab/Tab or Space, Print with Space/Tab or Space
		- Stack Manipulation
			- Push,Pop,Duplicate,Discard,copy nth item and slide the stack
		- Arith 
			- Add Sub Mul Int-division and Mod
		- Control Flow
			- Mark, call sub routines, jmp and cond jmp to labels, end sub routine and end program
		- Heap access
			- Look at addresses on stack to retrieve value
		- Hello World
		- (create a blank box with 25 lines)

- Shakespeare[8]
	- created by Karl Hasselström and Jon Åslund in 2001
	- The design goal of Shakespeare was, according to the Manual, to make a language with beautiful source code that resembled Shakespeare plays
	- Instructions are written as play script using char variables. 
	- Variable manipulation done through dialogue
	- Structure
		- Title: Any seq of char + . (no /n)
		- Then need to introduce atleast one characters (from shake play)
			- Name, Description. 
		- Then Define an act (starting at 1 and incrementing)
			- Act _RomanNumeral_: description.
		- Then define a scene which is the goto label
		- Scene I: desc. 
	- Instructions
		- Write a character:
			- Enter "name" and "name2"
				- must 2 char on stage at once
			- Exit "name"
		  - Set speaker:
			- Name: "name" 
		- "Speak your mind." - Outputs the ASCII character corresponding to the value held in the character being spoken to.
		- "Open your heart." - Outputs the numeric value held in the character being spoken to.
		- "Open your mind." - Inputs an ASCII character from the user and stores it in the character being spoken to.
		- "Listen to your heart." - Inputs a number from the user and stores it in the character being spoken to.
	- Char edit each other values using dialogue
		Characters edit each other's values using dialogue. The general form is "You are" followed either by a character, constant expression, operation expression, or simile.  
		Constant expressions consist of a 'positive' (complementing) or 'negative' (insulting) noun, preceded by zero or more adjectives. A noun is equal to either 1 or -1, and each attached adjective doubles its value. A simile is written "as _adjective_ as ", means nothing, and can be followed by a constant expression, character, or an operation expression. Operation expressions are written `the _operation_ of _constant, operation, or character_ and _constant, operation, or character_.`. Characters can be referenced using "yourself" or "thyself" if they are on stage, or by name if they aren't. For example:
	- Hello World
`The Infamous Hello World Program.`

`Romeo, a young man with a remarkable patience.`
`Juliet, a likewise young woman of remarkable grace.`
`Ophelia, a remarkable woman much in dispute with Hamlet.`
`Hamlet, the flatterer of Andersen Insulting A/S.`


                    `Act I: Hamlet's insults and flattery.`

                    `Scene I: The insulting of Romeo.`

`[Enter Hamlet and Romeo]`

`Hamlet:`
 `You lying stupid fatherless big smelly half-witted coward!`
 `You are as stupid as the difference between a handsome rich brave`
 `hero and thyself! Speak your mind!`

 `You are as brave as the sum of your fat little stuffed misused dusty`
 `old rotten codpiece and a beautiful fair warm peaceful sunny summer's`
 `day. You are as healthy as the difference between the sum of the`
 `sweetest reddest rose and my father and yourself! Speak your mind!`

 `You are as cowardly as the sum of yourself and the difference`
 `between a big mighty proud kingdom and a horse. Speak your mind.`

 `Speak your mind!`

`[Exit Romeo]`

                    `Scene II: The praising of Juliet.`

`[Enter Juliet]`

`Hamlet:`
 `Thou art as sweet as the sum of the sum of Romeo and his horse and his`
 `black cat! Speak thy mind!`

`[Exit Juliet]`

                    `Scene III: The praising of Ophelia.`

`[Enter Ophelia]`

`Hamlet:`

 `Thou art as beautiful as the difference between Romeo and the square`
 `of a huge green peaceful tree. Speak thy mind!`

 `Thou art as lovely as the product of a large rural town and my amazing`
 `bottomless embroidered purse. Speak thy mind!`

 `Thou art as loving as the product of the bluest clearest sweetest sky`
 `and the sum of a squirrel and a white horse. Thou art as beautiful as`
 `the difference between Juliet and thyself. Speak thy mind!`

`[Exeunt Ophelia and Hamlet]`


                    `Act II: Behind Hamlet's back.`

                    `Scene I: Romeo and Juliet's conversation.`

`[Enter Romeo and Juliet]`

`Romeo:`
 `Speak your mind. You are as worried as the sum of yourself and the`
 `difference between my small smooth hamster and my nose. Speak your`
 `mind!`

`Juliet:`
 `Speak YOUR mind! You are as bad as Hamlet! You are as small as the`
 `difference between the square of the difference between my little pony`
 `and your big hairy hound and the cube of your sorry little`
 `codpiece. Speak your mind!`

`[Exit Romeo]`

                    `Scene II: Juliet and Ophelia's conversation.`

`[Enter Ophelia]`

`Juliet:`
 `Thou art as good as the quotient between Romeo and the sum of a small`
 `furry animal and a leech. Speak your mind!`

`Ophelia:`
 `Thou art as disgusting as the quotient between Romeo and twice the`
 `difference between a mistletoe and an oozing infected blister! Speak`
 `your mind!`

`[Exeunt]`


- **Question 4**
	- Design by contract[9] is a methodology where components within a system define their interaction by the use of contracts (i.e. bound by a formal agreement). The contracts consist of a pre-condition, a post condition and Invariants. The pre conditions define what requirements must be met before calling the component, the post conditions define the requirements that must be met after calling the component[10]. Invariant are conditions we expect to hold true throughout the execution a routine/sub routine.
	- Languages with native support include: Eiffel and Fortress[11]

- **Question 5**
	- Vibe coding refers to the practise of excessively using AI whilst coding so that one may focus less on finer details and overall quality and maintainability of their code and simply follow their whimsical wherever it may lead
	- Drawbacks:
		- The programmer does not fully understand their system providing which causes a decrease in flexibility and maintenance.
		- AI code tends to be buggy and hard to fix.
		- Over reliance on AI tools may cause skill degradation especially in the long term.
		- Systems built with AI tend to be very unsecure and may be vulnerable to attacks by malicious actors  .
	


sources
1. https://esolangs.org/wiki/Esoteric_programming_language
2. https://esoteric.codes/blog/interview-with-chris-pressey
3. http://www.club.cc.cmu.edu/~ajo/docs/fungus.pdf#page=3&zoom=auto,-278,169
4. https://pythonhosted.org/PyFunge/introduction.html#what-is-funge
5. https://esolangs.org/wiki/Turing_tarpit
6. <a href = "https://iiif.library.cmu.edu/file/Simon_box00075_fld05959_bdl0003_doc0002/Simon_box00075_fld05959_bdl0003_doc0002.pdf#page=1&zoom=auto,-161,1061">Epigrams on Programming by Alan Perlis:</a>
7. https://esolangs.org/wiki/Whitespacec
8. https://esolangs.org/wiki/Shakespeare
9. https://www.sciencedirect.com/topics/computer-science/design-by-contract
10. https://learn.adacore.com/courses/intro-to-ada/chapters/contracts.html
11. https://en.wikipedia.org/wiki/Design_by_contract





notes:
**Befunge**
- Stack based language
- ![[Pasted image 20250227171528.png]]
- goal: as difficult to compile as possible
- move in 4 directions
- arrows work like GOTO

**Forth**
- First stack based prog lang
- 

![[Pasted image 20250227183119.png]]

