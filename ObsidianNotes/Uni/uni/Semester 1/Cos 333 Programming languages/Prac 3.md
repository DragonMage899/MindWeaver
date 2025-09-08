![[Pasted image 20250329110908.png]]

![[Pasted image 20250329111044.png]]

# **SWI-Prolog Cheat Sheet**
### **Basic Syntax**

- **Facts:**
    
    ```prolog
    human(socrates).
    human(plato).
    ```
    
- **Rules:**
    
    ```prolog
    mortal(X) :- human(X).
    ```
    
- **Queries:**
    
    ```prolog
    ?- mortal(socrates).
    true.
    ```
    

### **Variables and Constants**

- Variables start with an uppercase letter or `_`:
    
    ```prolog
    loves(romeo, juliet).
    loves(X, juliet). % X is a variable
    ```
    

### **Lists**

- **Basic List Definition:**
    
    ```prolog
    my_list([1, 2, 3, 4]).
    ```
    
- **Head and Tail:**
    
    ```prolog
    head([H|_], H).
    tail([_|T], T).
    ```
    
- **Membership Check:**
    
    ```prolog
    member(X, [X|_]).
    member(X, [_|T]) :- member(X, T).
    ```
    
- **Concatenation:**
    
    ```prolog
    append([], L, L).
    append([H|T], L, [H|R]) :- append(T, L, R).
    ```
    

### **Recursion Examples**

- **Length of a List:**
    
    ```prolog
    list_length([], 0).
    list_length([_|T], N) :- list_length(T, M), N is M + 1.
    ```
    
- **Sum of List Elements:**
    
    ```prolog
    sum_list([], 0).
    sum_list([H|T], S) :- sum_list(T, Rest), S is H + Rest.
    ```
    

### **Family Relations Example**

```prolog
parent(john, mary).
parent(mary, tom).
ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).
```

### **Arithmetic**

- **Addition:** `?- X is 5 + 3.`
    
- **Multiplication:** `?- X is 4 * 2.`
    
- **Greater than:** `?- 5 > 3.`
    

---

This cheat sheet follows the restriction of using only simple constants, variables, list operations, and basic predicates while avoiding system-built complex predicates.
