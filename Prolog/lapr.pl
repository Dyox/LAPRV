% grafo

% no(NoID,PosX,PosY)
no(a,[musica,rock],45,95).
no(b,[musica,rock],90,95).
no(c,[musica],45,95).
no(d,[],90,95).
no(e,[],45,95).
no(f,['c#'],90,95).

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

/*ver acertz*/
semantic_eq([['c#','csharp'],['vb','visual basic']]).

/*todos os caminhos entre dois pontos*/

go(Orig,Dest,L) :- go(Orig,Dest,[Orig],L). 
go(Dest,Dest,_,[Dest]). 
go(Orig,Dest,LA,[Orig|L]) :- ramo(Orig,X,_), 
not member(X,LA), 
go(X,Dest,[X|LA],L).

/*verifica se dois user são amigos*/
amigos(X,Y):-ramo(X,Y,_);ramo(Y,X,_).

/*lista uma lista com os amigos de um user*/
/*listar(X):-findall(L,listar_amigos(X,L),Lista),
		write(Lista),nl.

listar_amigos(X,L):-listar_amigos(X,[],L).
listar_amigos(X,L,[Y|L]):-ramo(X,Y,_).*/

/*listar todos os amigos de uma tag*/
listar_amigos_tag(X,Tag,L):-listar_amigos_tag(X,Tag,[],L).
listar_amigos_tag(X,Tag,L,[Y|L]):-ramo(X,Y,Tag,_).

/*listar_tags(X,L):-listar_tags(X,[],L).
listar_tags(X,L,[Y|L]):-no(X,Y,_,_).*/

/*
listar_tags(X,L):-listar_tags(X,[],L).
listar_tags(X,L,[H|L]):-no(X,[H|T],_,_),compara(X,H,L).

compara(X,H,L):-findall(L,listar_amigos(X,L),Lista),
		no([[A|Lista]|L1],L2,_,_),write(L1).
*/


/*procurar users com uma dada tag */
listar_users_tag(Tag,L):-listar_users_tag(Tag,[],L).
listar_users_tag(Tag,L,[Y|L]):-no(Y,Lista,_,_),member(Tag,Lista).

/*
conta_tag(Tag,L):-conta_tag(Tag,[],L).
conta_tag(Tag,L,[Y|L]):-no(_,Lista,_,_),member(Tag,Lista),Y is + 1, write(Y).
*/

/*verifica se um user ja tem aquela tag*/
/*recebe o user e a tag, retorna yes or no*/

verifica_tag(X,Tag):-no(X,L,_,_),member(Tag,L).



/**/
listar_am(X):-findall(L,listar_amigos(X,L),Lista),
		write(Lista),nl.


listar_amigos(X,Y):-ramo(X,Y,_,_).
/*listar_amigos(X,L):-listar_amigos(X,[],L).
listar_amigos(X,L,[Y|L]):-ramo(X,Y,_,_).
*/





/*conta os amigos de um user*/
conta_amigos(X):-findall(L,listar_amigos(X,L),Lista),
			conta_elem(Lista,Y),
			write(Y),nl.

conta_amigos_3nivel(X):-findall(X,listar_amigos_amigos(Lista,X),Lista),
			conta_elem(Lista,Y),
			write(Y),nl.






/*lista os amigos dos amigos de um user*/
/*p([[X|_]|L1]):-listar_amigos2(X,L),p(L1).*/
/*listar_amigos_amigos(X):-findall(L,listar_amigos(X,L),Lista),
				p(Lista).

p([X|L1]):-listar_amigos(X|Y),p(L1).*/

/**a funcionar listar_amigos_amigos(X):-findall(L,listar_amigos(X,L),Lista),
				findall(Y,listar_amigos_amigos(Lista,Y),Li),
				write(Li),nl.

listar_amigos_amigos([X|L],Y):-ramo(X,Y,_,_).*/

/*listar_amigos_amigos(X):-findall(L,listar_amigos(X,L),Lista),corre(Lista),write(Li).
				corre([]).
				corre([A|List]):-
					findall(Y,listar_amigos_amigos(A,Y),Li),write(Li),nl,
				corre(List).

listar_amigos_amigos(X,Y):-ramo(X,Y,_,_).*/

listar_amigos_amigos(X):-findall(L,listar_amigos(X,L),Lista),corre(Lista,F),write(F).
				corre([],[]).
				corre([A|List],[Li|Final]):-
					findall(Y,listar_amigos_amigos(A,Y),Li),
				corre(List,Final).

listar_amigos_amigos(X,Y):-ramo(X,Y,_,_).

limpar([],[]).
limpar([[X|A]|L],[X|Final]):-(A\==[]->(limpar([[A]|L],Final);limpar([L],Final))).

function([],[]):- !.
function([H|T],[H|R]):- \+ is_list(H), !, function(T,R).
function([H|T],L):- function(H,L1), function(T,L2), append(L1,L2,L).

is_list(X) :-
        var(X), !,
        fail.
is_list([]).
is_list([_|T]) :-
        is_list(T).

/*--*/
member2(X,[X|_]):- !.
member2(X,[_|T]) :- member2(X,T).

set([],[]).
set([H|T],[H|Out]) :-
   not(member2(H,T)),
   !,
set(T,Out).
set([H|T],Out) :-
   member2(H,T),
   set(T,Out).



/*listar_amigos2(X,L),p(L1).*/
/*listar_amigos2(X,L):-listar_amigos2(X,[],L).
listar_amigos2(X,L,[Y|L]):-ramo(X,Y,_,_),write(Y),nl.

listar_am_am(X):-findall(_,listar_amigos_amigos(X),Lista),
		nl,write(Lista),nl.

*/

listar_amigos_amigos_amigos(X):-findall(L,listar_amigos(X,L),Lista),
				findall(Y,listar_amigos_amigos(Lista,Y),Li),
				findall(Y,listar_amigos_amigos_amigos(Li,Y),Lis),
				write(Lis),nl.

listar_amigos_amigos_amigos([X|L],Y):-ramo(X,Y,_,_).



/*dada uma lista conta os seus elementos*/
conta_elem([],0).
conta_elem([_|T],N):-len(T,M),N is M+1.



/*procura amigos com X tags iguais*/
/*User Xtags Lista*/
amigos_tags_iguais(U,X,L):-amigos_tags_iguais(U,X,[],L).
amigos_tags_iguais(U,X,L,[Y|L]):-no(Y,La,_,_),
					no(U,[Tag|L],_,_),
					
					member(Tag,La),write(Tag).



/*cam_min(a,b,L) retorna o caminho minimo entre dois pontos*/
caminhos(X,Y,P):-todos_caminhos(X,Y,[Y],P).
todos_caminhos(X,Y,L,[X|L]):-ramo(X,Y,_,_).
todos_caminhos(X,Y,L,P):-ramo(Z,Y,_,_),Z\==X,(not member(Z,L)),
				todos_caminhos(X,Z,[Z|L],P).

lstcaminhos(X,Y,L):-findall(P,caminhos(X,Y,P),L).

menor([X],X).
menor([X|T],X):-menor(T,L),
				length(X,N),
				length(L,M),
				N =< M,!.
menor([X|T],L):-menor(T,L).
cam_min(X,Y,P):-findall(P,caminhos(X,Y,P),L),	
			menor(L,P),write(P);write('Nenhum caminho...').
/*---------------------*/					
