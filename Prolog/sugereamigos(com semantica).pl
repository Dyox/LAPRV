% grafo

% no(NoID,PosX,PosY)
no(a,[csharp,musica,rock,pimba,zumba,'java script'],45,95).
no(b,[musica,rock],90,95).
no(c,[musica],45,95).
no(d,[],90,95).
no(e,[pimba],45,95).
no(f,['c#',zumba,pimba,js],90,95).


% ramo(No1_ID,No2_ID,Tag,For�a)
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

semantic_eq(['c#',csharp]). 
semantic_eq([pimba,popular]). 
semantic_eq([wtv,whatever]).
semantic_eq([fds,'fim de semana', 'fim-de-semana']). 
semantic_eq([vb,'visual basic']). 
semantic_eq([js, 'java script']).

/**/
listar_am(X):-findall(L,listar_amigos(X,L),Lista),
		write(Lista),nl.
listar_amigos(X,Y):-ramo(X,Y,_,_).
listar_amigos_lista(X,Lista):-findall(L,listar_amigos(X,L),Lista).

/*conta os amigos de um user*/
conta_amigos(X):-findall(L,listar_amigos(X,L),Lista),
			conta_elem(Lista,Y),
			write(Y),nl.

/*Lista os amigos dos amigos do user X*/
listar_amigos_amigos(X):-
			findall(L,listar_amigos(X,L),Lista),
			corre(Lista,F),
			elimina_listas(F,F2),
			elimina_repetidos(F2,F3),
			elimina(X,F3,F4),
			write(F4),nl.
				
corre([],[]).
corre([A|List],[Li|Final]):-
			findall(Y,listar_amigos_amigos(A,Y),Li),
			corre(List,Final).

listar_amigos_amigos(X,Y):-ramo(X,Y,_,_).
/*---*/

listar_amigos_amigos_lista(X,F4):-
			findall(L,listar_amigos(X,L),Lista),
		
			corre(Lista,F),
			elimina_listas(F,F2),
			elimina_repetidos(F2,F3),
			elimina(X,F3,F4).


/*elimina lista de lista e mete tudo numa �nica lista*/
elimina_listas([],[]):- !.
elimina_listas([H|T],[H|R]):- \+ is_list(H), !, elimina_listas(T,R).
elimina_listas([H|T],L):- elimina_listas(H,L1), elimina_listas(T,L2), append(L1,L2,L).
/*---*/

/*verifica se � lista*/
is_list(X) :-
        var(X), !,
        fail.
is_list([]).
is_list([_|T]) :-
        is_list(T).
/*--*/

/*elimina os registos repetidos de uma lista*/
member2(X,[X|_]):- !.
member2(X,[_|T]) :- member2(X,T).

elimina_repetidos([],[]).
elimina_repetidos([H|T],[H|Out]) :-
   not(member2(H,T)),
   !,
elimina_repetidos(T,Out).
elimina_repetidos([H|T],Out) :-
   member2(H,T),
   elimina_repetidos(T,Out).
/*---*/

/*elimina o elemento X da lista*/
elimina(_,[],[]).
elimina(X,[X|T],T):-!.
elimina(X,[H|T],[H|L]):-elimina(X,T,L).
/*---*/

listar_amigos_amigos_amigos(X):-
			findall(L,listar_amigos(X,L),Lista),
			corre(Lista,F),
			elimina_listas(F,F2),
			elimina_repetidos(F2,F3),
			elimina(X,F3,F4),
	
			corre(F4,F5),
			elimina_listas(F5,F6),
			elimina_repetidos(F6,F7),
			elimina(X,F7,F8),
			write(F8),nl.

listar_amigos_amigos_amigos_lista(X,F8):-
			findall(L,listar_amigos(X,L),Lista),
			corre(Lista,F),
			elimina_listas(F,F2),
			elimina_repetidos(F2,F3),
			elimina(X,F3,F4),
	
			corre(F4,F5),
			elimina_listas(F5,F6),
			elimina_repetidos(F6,F7),
			elimina(X,F7,F8).

tamanho_rede_user_3(X,N):-
	listar_amigos_lista(X,L1),
	listar_amigos_amigos_lista(X,L2),
	uniao(L1,L2,L3),
	listar_amigos_amigos_amigos_lista(X,L4),
	uniao(L3,L4,L5),
	conta_elem(L5,N).

/*recebe duas listas e junta na terceira, tambem limpa repetidos*/	
uniao([ ],L,L).
uniao([X|L],L1,L2):- member(X,L1),!,uniao(L,L1,L2).
uniao([X|L],L1,[X|L2]):- uniao(L,L1,L2).
/*---*/

/*dada uma lista conta os seus elementos*/
conta_elem([],0).
conta_elem([_|T],N):-len(T,M),N is M+1.
/*---*/


/*sugere users para amizade com o user X q tenham alguma tag comum*/
sugerir_users(X):-
	listar_amigos_amigos_lista(X,L1),
	listar_amigos_amigos_amigos_lista(X,L2),
	uniao(L1,L2,L3),
	no(X,Tags,_,_),
	corre3(X,Tags,L3,Tags,L3),!;true.
	

corre3(X,[A|List],[Li|Final],ListC,FinalC):-
	sugere(X,A,Li),
	Final\==[]->(corre3(X,[A],Final,ListC,FinalC);
		corre3(X,List,FinalC,ListC,FinalC)).

sugere(User1,Tag,User2):-no(User2,Tags,_,_),
			findall(L, semantic_eq(L),Lista),
			lista_de_lista(Tag, Tags, Lista,User2,User1),
			(member(Tag,Tags),\+(ramo(User1,User2,_,_)))->(write(User2),write('['),write(Tag),write('],'));write('').


	
lista_de_lista(X, Tags, [],User2,User1).
lista_de_lista(X, Tags, [L|Lista],User2,User1):-lista_de_lista(X, Tags, Lista,User2,User1),
	((member(X,L),intersects(Tags,L),
	\+(ramo(User1,User2,_,_)),
	\+(ramo(User2,User1,_,_)))->(write(User2),write('['),write(X),write('],'));write('')).

intersects([H|_],List) :-
    member(H,List),
    !.
intersects([_|T],List) :-
    intersects(T,List).