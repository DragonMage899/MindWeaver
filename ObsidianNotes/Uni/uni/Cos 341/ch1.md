Of course. Here is a comprehensive set of exam notes for Chapter 1: Lexical Analysis, created using the provided textbook and lecture slides. The notes are structured to aid in constructive problem-solving, focusing on the methods and algorithms you'll need to apply.

---

### **Exam Notes: Chapter 1 - Lexical Analysis**

#### **1. Role of Lexical Analysis in a Compiler**

The lexical analyser, also known as a

**lexer** or **scanner**, is the first phase of a compiler1111. Its primary job is to read the raw source code text and convert it into a sequence of tokens222222.

- **Input:** A string of characters (the program text)3333.
    
- **Core Tasks:**
    
    - Divides the input string into classified tokens (e.g., keywords, identifiers, numbers)4444.
        
    - Filters out non-essential elements like whitespace, layout characters (spaces, newlines), and comments5555.
        
- **Output:** A sequence (or stream) of tokens6666. This stream is then passed to the next phase, Syntax Analysis (Parsing)7777.
    

**Why Separate Lexical and Syntax Analysis?** 8

- **Efficiency:** A specialized lexer can perform simple tasks faster than a general-purpose parser9.
    
- **Modularity:** The syntax description (grammar) doesn't need to be cluttered with details about comments and whitespace10.
    
- **Tradition:** Languages are often designed with this separation in mind11.
    

#### **2. Specifying Tokens: Regular Expressions (REs)**

Regular expressions are an algebraic notation used to describe sets of strings, which we call a

**language**121212121212121212. In lexical analysis, we use one RE for each token class13.

**Core Components of Regular Expressions** 14

Let s and t be regular expressions. The language described by an RE

s is denoted as L(s)15.

|Regular Expression|Informal Description|Language Example for s=texta, t=textb|
|---|---|---|
|epsilon|The empty string16.|epsilon|
|`a`|A single character|`a` from the alphabet17.|`{"a"}`|
|$s|t$|Alternation: Either|s or t18.|
|st|Concatenation: An|s followed by a t19.|L(textab)="textab"|
|s∗|Kleene Star: Zero or more concatenations of|s20.|L(texta∗)=epsilon,text"a",text"aa",...|

**Shorthands and Conventions** 21

To make REs more compact, we use several common shorthands.

|Shorthand|Equivalent To|Description|Example|
|---|---|---|---|
|s+|$ss^\*$|Kleene Plus: One or more occurrences of|s22222222.||`[0-9]+` for non-empty sequences of digits23.|
|s?|$s|\epsilon$|Zero or one occurrence of|s24242424.|
|`[abc]`|`a|b|c`|
|`[0-9]`|`0|1|...|

**Precedence Rules:** The operators have a defined hierarchy to avoid ambiguity25:

1. Highest Precedence: `*`, `+`, `?` (Repetition operators)
    
2. Medium Precedence: Concatenation
    
3. Lowest Precedence: | (Alternation)
    
    For example,
    
    `a|ab*` is equivalent to `a|(a(b*))`26. Parentheses can be used to override this precedence27.
    

**Problem-Solving Examples:**

- **C-style Identifiers:** Must start with a letter or underscore, followed by any number of letters, digits, or underscores28.
    
    - **RE:** `[a-zA-Z_][a-zA-Z_0-9]*` 29
        
- **Integer Constants:** An optional sign followed by a non-empty sequence of digits30.
    
    - **RE:** `[+-]?[0-9]+` 31
        
- **Floating-Point Constants (Simplified):** A sequence of digits, a decimal point, and another sequence of digits32.
    
    - **RE:** `[+-]?[0-9]+.[0-9]+`
        

#### **3. Recognizing Tokens: Finite Automata (FAs)**

Finite Automata are abstract machines used to recognize patterns described by REs33333333. They consist of a finite number of states and transitions between them, triggered by input symbols34.

A. Nondeterministic Finite Automata (NFAs)

35

An NFA is a "machine" that can be in multiple states at once36. This nondeterminism is a useful theoretical step for converting REs to recognizers37.

- **Key Features:**
    
    - Can have multiple transitions from one state on the same symbol38.
        
    - Can have
        
        **epsilon (epsilon) transitions**, which are state changes that occur without consuming any input character39393939.
        
- **Acceptance:** An input string is accepted if there exists _at least one path_ from the start state to an accepting (or final) state that consumes the entire string40.
    

B. Deterministic Finite Automata (DFAs)

41

A DFA is a more restricted, but more practical, type of FA42. Lexical analysers are typically based on DFAs43434343.

- **Restrictions:**
    
    1. There are no
        
        epsilon-transitions44.
        
    2. For any given state, there is at most one transition for each symbol in the alphabet45.
        
- **Why DFAs are efficient:** The next state is uniquely determined by the current state and the next input symbol46. This allows for a very fast implementation using a 2D table (a
    
    `move(state, symbol)` function)47.
    

#### **4. Constructive Problem-Solving: The Algorithms**

This section details the core constructive processes you will likely be tested on.

##### **Process 1: Converting a Regular Expression to an NFA**

This is a compositional process where an NFA fragment is built for each part of the RE and then combined484848.

**Construction Steps (Thompson's Construction)** 49

1. **For `ε`:** A direct link50.
    
2. **For a character `a`:** A start state, a transition on `a` to an end state.
    
3. **For `st` (concatenation):** The NFA for `s` followed by the NFA for `t`51.
    
4. **For `s|t` (alternation):** A new start state with epsilon-transitions to the start states of the NFAs for `s` and `t`. Their end states have
    
    epsilon-transitions to a new final state52.
    
5. **For `s*` (Kleene star):** The NFA for `s` is placed in a loop with epsilon-transitions for entering and exiting the loop, as well as bypassing it entirely53.
    

**Example: NFA for `(a|b)*`**

1. Build NFAs for `a` and `b`.
    
2. Combine them using the `|` rule.
    
3. Apply the `*` rule to the resulting NFA.
    

##### **Process 2: Converting an NFA to a DFA (The Subset Construction)**

This is the most critical algorithm for creating an executable recognizer from an NFA5454. The core idea is that

**each DFA state corresponds to a _set_ of NFA states**55555555.

Step A: Epsilon-Closure (epsilon-closure)

Before the main algorithm, you must understand epsilon-closure.

- **Definition:** For a set of NFA states M, epsilontext−closure(M) is the set containing all states in M plus all states reachable from any state in M using only epsilon-transitions56.
    
- **How to Calculate (Work-list Algorithm):** 57
    
    1. Initialize a set, `result`, with the states from the input set `M`.
        
    2. Initialize a work-list with the states from `M`.
        
    3. While the work-list is not empty:
        
        - Pop a state `s` from the work-list.
            
        - For every state `t` reachable from `s` via an epsilon-transition:
            
            - If `t` is not already in `result`, add `t` to `result` and to the work-list.
                
    4. The final `result` set is the epsilon-closure.
        

**Step B: The Subset Construction Algorithm (Algorithm 1.3)** 58

1. **DFA Start State:** The start state of the DFA, s′_0, is the epsilontext−closure of the NFA's start state, s_0. That is,
    
    s′_0=epsilontext−closure(s_0)59.
    
2. The move function: To find the transition from a DFA state s′ on an input character c:
    
    a. Find the set of all NFA states reachable from any NFA state in s′ by following a transition on c. Let this set be T.
    
    b. The new DFA state is
    
    epsilontext−closure(T)60.
    
3. Build the DFA:
    
    a. Create a list of DFA states to process, initially containing only the start state s′_0.
    
    b. While there are unprocessed DFA states in the list:
    
    * Take one, s′, and mark it as processed.
    
    * For each character c in the alphabet:
    
    * Calculate the destination state t′=textmove(s′,c).
    
    * If t′ is not empty and not already in your list of DFA states, add it as an unprocessed state.
    
    * Record the transition from s′ to t′ on c.
    
4. **Accepting States:** A DFA state is an accepting state if its corresponding set of NFA states contains _at least one_ accepting NFA state61.
    

##### **Process 3: DFA Minimization**

DFAs created via the subset construction are often not minimal62. Minimization reduces the number of states by merging equivalent states63.

**Algorithm 1.4 (DFA Minimization):** 64

1. **Initial Partition:** Create two groups of states: the set of all accepting states (F) and the set of all non-accepting states (SsetminusF)65.
    
2. **Refine Partitions:** For each group `G` in your current partition:
    
    - Check if it is
        
        **consistent**: A group is consistent if for any character `c`, all states in `G` transition to states that are in the _same_ group66.
        
    - If `G` is not consistent, split it into maximal consistent subgroups. For example, if some states in
        
        `G` transition to a state in group `P1` on character `c`, while others transition to a state in group `P2`, you must split `G` into (at least) two new groups based on this distinction67.
        
3. **Termination:** Repeat step 2 until no more groups can be split. The remaining groups are the states of the minimal DFA68. The start state of the new DFA is the group containing the original start state69.
    

**Important Note on Dead States:** A dead state is a non-accepting state from which no accepting state can be reached70. For the algorithm to work correctly, either ensure the DFA has no dead states, or make all transitions total by adding a single, shared dead state that all previously undefined transitions now point to71.

#### **5. Lexer Generators in Practice**

Lexer generators automate the process of creating a lexer from a list of token definitions (REs)72727272.

**Combined DFA Construction:** 73

1. An NFA is built for each token's regular expression74.
    
2. The accepting state of each NFA is marked with its corresponding token name (e.g.,
    
    `ID`, `IF`, `NUM`)75.
    
3. A new global start state is created with
    
    epsilon-transitions to the start state of each individual NFA76.
    
4. This large combined NFA is converted to a single DFA using the subset construction77.
    

Resolving Ambiguity and Overlap

When the lexer must choose between multiple possible tokenizations, it uses two main rules:

1. **Rule of Longest Match:** The lexer will always match the **longest possible prefix** of the input that corresponds to a valid token78.
    
    - **Example:** For the input `if17` and token definitions for keyword `if` and identifier `[a-zA-Z][a-zA-Z0-9]*`, the lexer chooses the single identifier token `if17` because it is longer than the keyword `if`79.
        
    - **Implementation:** This may require the DFA to read past an accepting state and then backtrack if it gets stuck, returning the token from the last accepting state it visited80.
        
2. **Priority Rule:** If two tokens match the same longest string, the token definition that appears **first** in the lexer generator's input file is chosen81.
    
    - **Example:** Keyword definitions (like `if`, `while`, `else`) are almost always placed before the general identifier rule. This ensures that
        
        `if` is tokenized as a keyword, not an identifier82.