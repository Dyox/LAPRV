% grafo

% no(NoID,PosX,PosY)
no(a,[musica,rock,pimba,zumba],45,95).
no(b,[musica,rock],90,95).
no(c,[musica],45,95).
no(d,[],90,95).
no(e,[pimba],45,95).
no(f,['c#',zumba],90,95).

% ramo(No1_ID,No2_ID,Tag,Força)
ramo(a,b,[namorada],1).
ramo(b,a,[namorada],1).
ramo(a,c,[amiga],2).
ramo(c,a,[amiga],2).
ramo(a,d,[amiga],1).
ramo(d,a,[amiga],1).
ramo(a,e,[amiga],2).
ramo(e,a,[amiga],2).
ramo(b,e,[amiga],1).
ramo(e,b,[amiga],1).
ramo(d,e,[amiga],1).
ramo(e,d,[amiga],1).
ramo(d,f,[amiga,irma],1).
ramo(f,d,[amiga,irma],1).
ramo(c,d,[],3).
ramo(d,c,[],3).
ramo(e,h,[],3).
ramo(h,e,[],3).
ramo(a,z,[],3).
ramo(z,a,[],3).
ramo(x,e,[],3).
ramo(e,x,[],3).
ramo(x,y,[],3).
ramo(y,x,[],3).
ramo(y,w,[],3).
ramo(w,y,[],3).
ramo(yy,ww,[],3).
ramo(ww,yy,[],3).

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

/*elemento numa possicao da lista*/
item_at( N, L, Item ) :- item_at( N, 0, L, Item ).   
item_at( N, Count, [H|_], Item ) :- CountNew is Count + 1,CountNew = N, Item = H.
item_at( N, Count, [_|T], Item ) :- CountNew is Count + 1,item_at( N, CountNew, T, Item ).

camMaisForte(X,X,Element):-!,write('Nenhum caminho...').
camMaisForte(X,Y,Element):-findall(P,caminhos(X,Y,P),L),findall(F,forca(X,Y,F),LF),
			max_list(LF,T),item_at(POS,LF,T),item_at(POS,L,Element),write(Element);write('Nenhum caminho...').


