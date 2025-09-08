**Homework #2**: [2 marks], **to be done alone**, NOT in groups!

- This homework does not depend on the previous H#1
- You can do this H#2 totally independently from H#1 **:)**

**Given** is the following context-free grammar _G_ :

- S ==> PROG **$** _// comment:_ **$** _is the pseudo-symbol that indicates the end-of-file_
- PROG ==> ASSIGN
- PROG ==> WHILE
- ASSIGN ==> VAR **=** TERM **;**
- VAR ==> **a**
- VAR ==> **b**
- VAR ==> **c**
- TERM ==> VAR
- TERM ==> **(** TERM OP TERM **)**
- OP ==> **+**
- OP ==>  **<**
- WHILE ==> **w** COND **{** PROG **}**
- COND ==> **(** TERM OP TERM **)**

For this grammar, a **top-down recursive-descent LL1 parser** without tree-construction must be programmed in **C++**

For the "general idea", see **Textbook sub-section 2.11.1**, **Fig.2.17**

- Because an **LL1** parser can always only "fetch" one token at a time, your **C++** software must have a variable **char next** _into which the Tutor will feed symbols_ which you do not know beforehand, one at a time, _when the Tutor is testing your parser._
- For this purpose your **C++** software must call the command  **std::cin>>next** whenever your parser "needs" another symbol at which it wants to "look".
- Note: In this homework, the Tutor will not enter any _blank_space_ symbol into the character variable **next**.

**Parsing will come to an end**

- **if** a _syntax error_ is detected (in which case an appropriate **_"syntax error" message_** must be emitted), **_or_**
- **if** the Tutor enters the final pseudo-symbol '**$**' which signals the end-of-file.

**If no syntax error was detected** after the final pseudo-symbol '$' was received, an **_"accept" message_** will be emitted.

**For submission you must upload your C++ source code, such that the Tutor can inspect it, onto ClickUp before the deadline.**

- The deadline date itself is given in ClickUp, and will **not** be extended under any circumstances whatsoever.
- You have **only 1 upload attempt**: Therefore you must test your software very thoroughly before you make the upload.

**IF you have any doubts, then go to Tutor's Consultation Hour.**

And now: **HAPPY CODING :)**
