/* Task 1 */ 
person(peter).
person(mary).
person(tom).
person(lilly).
person(joseph).
person(rob).

married(peter, mary).
married(lilly, joseph).

invited(mary, tom).

livingTogether(X, Y) :- married(X, Y); married(Y, X).

visiting(X, Y) :- 
    invited(Y, X);
    (livingTogether(Y, Z), invited(Z, X)).

livesAlone(X) :- 
    \+ livingTogether(X, _), \+ visiting(X, _).

/* Task 2*/
countList([], [0]).
countList([_|Tail], [Count]) :- 
    countList(Tail, [TailCount]),
    Count is TailCount + 1.

 getZeroValues([], []).  

getZeroValues([0 | Tail], [0 | X]) :-  
    getZeroValues(Tail, X).          

getZeroValues([Head | Tail], X) :-
    Head \= 0,                      
    getZeroValues(Tail, X).      

/* Task 2*/
monotonicallyDecreasing([]).  

monotonicallyDecreasing([_]). 

monotonicallyDecreasing([Head1, Head2 | Tail]) :-  
    Head1 >= Head2,  
    monotonicallyDecreasing([Head2 | Tail]).
