**Homework #1**: [2 marks], **to be done alone**, NOT in groups!

**Given is the NFA** attached below in the picture file:

- Its **alphabet** consists of the ten **digits**, the **small letters** of the roman alphabet, and the **dot** - nothing else.
- The three **Accept-states** with **token classes** are highlighted in **green** colour, for the sake of clarity.
- Empty **Epsilon-transitions** are highlighted in **red** colour, for the sake of clarity.

**A Lexer-Program must be written in** **C++**, to be submitted as source-code which the tutors can see and inspect.

- Your C++ program must contain a **string variable** with the name **tutorInput**, into which the tutors will write some string before test-launching your software.
- The tutor's string will **not** contain any _blank_space_ symbols.

Your Lexer-Program must **tokenize** the given string according to the following **Lexing Strategy**:

- **Highest priority** for the tokenization of **keywords: _"First Match"_**
- **_"Longest Match"_** for the tokenization of **variables** and **numbers**

Your Lexer-Program should also employ some form of **backtracking**, such that some alternative tokenization might perhaps succeed after some previous tokenization attempt might perhaps have failed.

- **IF no tokenization attempt is successful** (even after backtracking and re-try), an appropriate **_"Lexical Error"_ message** must be emitted.
- **Otherwise**, your Lexer software **emits a message with the correct sequence of tokens that it has recognized** - for example: **_"identified: number,keyword,variable,keyword,number"._**

**Upload your C++ source file to ClickUp before the Deadline**. The Deadline itself is given in ClickUp.

- WARNING: You have **only one upload** attempt! Test your software very carefully BEFORE you make the upload**!**
- **NO** deadline extension will be granted under any circumstances whatsoever.

And now: **HAPPY HOME-WORKING :)**



![[Pasted image 20250901184203.png]]