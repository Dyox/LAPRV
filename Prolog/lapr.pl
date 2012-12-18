% grafo

% no(NoID,PosX,PosY)
no(a,[musica,rock],45,95).
no(b,[musica],90,95).
no(c,[],45,95).
no(d,[],90,95).
no(e,[],45,95).
no(f,[],90,95).

% ramo(No1_ID,No2_ID,Tag,Força)
ramo(a,b,namorada,1).
ramo(a,c,amiga,2).
ramo(a,d,amiga,1).
ramo(a,e,amiga,2).
ramo(b,e,amiga,1).
ramo(d,e,amiga,1).
ramo(c,d,amiga,3).

semantic_eq(['c#','csharp'],['vb','visual basic']).

/*todos os caminhos entre dois pontos*/

go(Orig,Dest,L) :- go(Orig,Dest,[Orig],L). 
go(Dest,Dest,_,[Dest]). 
go(Orig,Dest,LA,[Orig|L]) :- ramo(Orig,X,_), 
not member(X,LA), 
go(X,Dest,[X|LA],L).

/*verifica se dois user são amigos*/
amigos(X,Y):-ramo(X,Y,_);ramo(Y,X,_).

/*lista uma lista com os amigos de um user*/
listar(X):-findall(L,listar_amigos(X,L),Lista),
		write(Lista),nl.

listar_amigos(X,L):-listar_amigos(X,[],L).
listar_amigos(X,L,[Y|L]):-ramo(X,Y,_).

/*listar todos os amigos de uma tag*/
listar_amigos_tag(X,Tag,L):-listar_amigos_tag(X,Tag,[],L).
listar_amigos_tag(X,Tag,L,[Y|L]):-ramo(X,Y,Tag,_).

/*listar_tags(X,L):-listar_tags(X,[],L).
listar_tags(X,L,[Y|L]):-no(X,Y,_,_).*/

listar_tags(X,L):-listar_tags(X,[],L).
listar_tags(X,L,[H|L]):-no(X,[H|T],_,_),compara(X,H,L).

compara(X,H,L):-findall(L,listar_amigos(X,L),Lista),
		no([[A|Lista]|L1],L2,_,_),write(L1).





