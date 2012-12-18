
run1 :-
	
   member(X, [abc,def,ghi,jkl]),
	
   write(X).
	


run2 :-
	
  input( `Enter a value:`, Input ),
	
  read(X) <~ Input,
	
  member(X, [abc,def,ghi,jkl]).
	
add(A,B,R) :- R is A + B.

r(X, L, L1) :- p(X, L, [ ], L1). 
p(0, L, LA, L1) :- ! , append(LA, L, L1). 
p(N, [X|L], LA, L1) :- N1 is N-1, p(N1, L, [X|LA], L1).

