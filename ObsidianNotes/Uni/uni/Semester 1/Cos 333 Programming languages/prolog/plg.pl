/* Play ground*/
list_length([], 0).

list_length([_ | Tail], Length) :-
    list_length(Tail, TailLength), 
    Length is TailLength + 1.

list_sum([], 0).
list_sum([Head | Tail], Sum) :-
    list_sum(Tail, TailSum),
    Sum is TailSum + Head.

list_max([X], X).
list_max([Head | Tail], Max) :-
    list_max(Tail, TailMax),
    Head > TailMax,
    Max is Head.
list_max([Head | Tail], Max) :-
    list_max(Tail, TailMax),
    Head =< TailMax,
    Max is TailMax.

prefix([], _).
prefix([H1 | T1], [H2 | T2]) :-
    H1 == H2,
    prefix(T1, T2).

sqare([], []).
sqare([Head | Tail], [SqH | SqT]) :-
    SqH is Head * Head,
    sqare(Tail, SqT).