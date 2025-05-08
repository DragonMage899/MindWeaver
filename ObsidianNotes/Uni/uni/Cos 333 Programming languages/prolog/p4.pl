abs(X, X) :- X >= 0.
abs(X, Y) :- X < 0, Y is -X.

stripPositivesAbsNegativesIncZeros([], []).

stripPositivesAbsNegativesIncZeros([H|T], Result) :-
    H > 0,
    stripPositivesAbsNegativesIncZeros(T, Result).

stripPositivesAbsNegativesIncZeros([H|T], [AbsH|Rest]) :-
    H < 0,
    abs(H, AbsH),
    stripPositivesAbsNegativesIncZeros(T, Rest).

stripPositivesAbsNegativesIncZeros([0|T], [1|Rest]) :-
    stripPositivesAbsNegativesIncZeros(T, Rest).