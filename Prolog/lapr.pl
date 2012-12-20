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
ramo(a,c,[amiga],2).
ramo(a,d,[amiga],1).
ramo(a,e,[amiga],2).
ramo(b,e,[amiga],1).
ramo(d,e,[amiga],1).
ramo(d,f,[amiga,irma],1).
ramo(c,d,[],3).

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
		write(Lista),nl,
		constroi_lista(Lista,[],L).

listar_amigos(X,L):-listar_amigos(X,[],L).
listar_amigos(X,L,[Y|L]):-ramo(X,Y,_,_).






/*conta os amigos de um user*/
conta_amigos(X):-findall(L,listar_amigos(X,L),Lista),
			conta_elem(Lista,Y),
			write(Y),nl.





/*lista os amigos dos amigos de um user*/
listar_amigos_amigos(X):-findall(L,listar_amigos(X,L),Lista),
				p(Lista).
p([[X|_]|L1]):-listar_amigos2(X,L),p(L1).

/*listar_amigos2(X,L),p(L1).*/

listar_amigos2(X,L):-listar_amigos2(X,[],L).
listar_amigos2(X,L,[Y|L]):-ramo(X,Y,_,_),write(Y),nl.

listar_am_am(X):-findall(_,listar_amigos_amigos(X),Lista),
		nl,write(Lista),nl.






/*dada uma lista conta os seus elementos*/
conta_elem([],0).
conta_elem([_|T],N):-len(T,M),N is M+1.



/*procura amigos com X tags iguais*/
/*User Xtags Lista*/
amigos_tags_iguais(U,X,L):-amigos_tags_iguais(U,X,[],L).
amigos_tags_iguais(U,X,L,[Y|L]):-no(Y,La,_,_),
					no(U,[Tag|L],_,_),
					
					member(Tag,La),write(Tag).
					
