% no(NoID,[listaTags],PosX,PosY)
no(a,[musica,rock],45,95).
no(b,[musica,rock],90,95).
no(c,[musica],45,95).
no(d,[],90,95).
no(e,[],45,95).
no(f,['c#'],90,95).

% ramo(No1_ID,No2_ID,Tag,Força)
ramo(a,b,[namorada],1).
ramo(a,c,[namorada],8).
ramo(b,c,[namorada],5).


caminhos(X,Y,P):-todos_caminhos(X,Y,[Y],P).
todos_caminhos(X,Y,L,[X|L]):-ramo(X,Y,_,_).
todos_caminhos(X,Y,L,P):-ramo(Z,Y,_,_),Z\==X,(not member(Z,L)),	todos_caminhos(X,Z,[Z|L],P).

forca(X,Y,F):-todos_caminhosForca(X,Y,[Y],P,F).
todos_caminhosForca(X,Y,L,[X|L],F):-ramo(X,Y,_,F).
todos_caminhosForca(X,Y,L,P,F):-ramo(Z,Y,_,FO),Z\==X,(not member(Z,L)),todos_caminhosForca(X,Z,[Z|L],P,F2),F is F2 + FO.

menor([X],X).
menor([X|T],X):-menor(T,L),	length(X,N),length(L,M), 	N =< M,!.
menor([X|T],L):-menor(T,L).

max_list([H], H).
max_list([H|T], M2) :- max_list(T, M), M2 is max(H, M).

max_list([H], H, Pos).
max_list([H|T], M2) :- max_list(T, M), M2 is max(H, M).

indexOf([Element|_], Element, 0):- !.
indexOf([_|Tail], Element, Index):- indexOf(Tail, Element, Index1), !, Index is Index1+1.

cam_min(X,Y,Element):-findall(P,caminhos(X,Y,P),L),findall(F,forca(X,Y,F),LF),
			max_list(LF,T),indexOf(LF,T,POS),indexOf(L, Element, POS),write(Element);write('Nenhum caminho...').


