# Semester Project : Phase 1 : Front-End

Attached below is the **Syntax Specification** of this year's version of our "Students' Programming Language" **SPL** (2025).

- The given context-free grammar **_G_**, which describes the language **_L_**(**_G_**) **=** **SPL**, is not in LL1 format.

**Thus you can now begin with the Front-End Phase of your Semester Project :)**

**TO DO**:

- **Inspect** the Syntax thoroughly, together with your project partners.
- **Discuss** with your project partners whether you wish to implement a compiler _with_ a lexer "in front of" the parser, **_or_** whether you wish to create a _lexer-less_ compiler (in which the parser alone plays the double-role of lexing and parsing): _The decision is your's_ **:)**
- **Discuss** with your project partners whether you want to **_try_** _to find_ an _equivalent_ **alternative LL1** grammar **_G'_** with **_L_(****_G'_****) = _L_(_G_) =** **SPL** for the development of a simple _recursive Top-Down_ parser, **_or_** whether you wish to delve straight into the development of a "strong" _Bottom-Up_ parser that suits the grammar **_G_** as it is given: _The decision is your's_ **:)**
- **Discuss** with your project partners in which programming language you wish to implement your SPL compiler: Perhaps in C++, or in Java, or in Python, or in any other programming language which you prefer**?** _The decision is your's_ **:)**
- **Assume** that the SPL programs, which will be "fed" as input to your compiler, will be given in simple plain ***.txt** files, such that your compiler software will also need some kind of _file-reading capability_ even before the input's syntax can be analysed.
- **If you are in doubt**, then go to Tutor's Consultation Hour in the Orange Lab on Tuesdays.
- And then: **HAPPY CODING :)**

**Also note**: Further Project Instructions, about the your compiler's Static Semantic Analysis Phase as well as the code-generating Back-End, will be provided later, after we will have discussed those concepts in our weekly lectures.

- Also the exact Final Deadline for Final Software Submission will be announced somewhat later, although you can already now **assume that it will be quite precisely two weeks before semester-end**, _such that our Tutors will still have enough time to test and mark your software before I'm institutionally obliged to publish all semester-marks_ on the semester-end-day.

**Attachment**:


Meeting 1:
Agenda:
- Project overview, questions idea's
- Choose a language
- Can be automated?
- Work
	- Lexer
		- Create token list
		- Create regex for each token
		- White space handling
		- Output token stream
	- Parser
		- Convert to LL1 and make LL1 parsing table
		- Use table, input and stack to implement parsing algorithm
			- Match and Predict loop
		- Output Syntax Tree
	- Name Scope Rules
		- Design Symbol table and entries for table
		- Create functions for interacting with table
		- Tree Crawling algorithm
			- Searches Syntax Tree from parser for Semantic information
				- Scope information and syntax violation
			- Update Symbol table accordingly
			- Implements rules and violation messages
				- Variable lookup based on precedence rules
				- Scope violations
				- Double declarations (var and func names)
				- Variable shadowing 

