%listar_amigos_lista(X,Lista):-Lista = [[a,[a,b,c]],[b,[a,b,c]],[d,[a,b,c]]].
% no(NoID,[TAGS],PosX,PosY)
no(a,[musica],45,95).
%no(b,[musica,rock],90,95).
%no(c,[musica],45,95).
no(d,[music],90,95).


% ramo(No1_ID,No2_ID,[Tag],Força)
ramo(a,b,[namorada],1).
ramo(b,a,[namorada],1).
ramo(a,c,[amiga],2).
ramo(c,a,[amiga],2).
ramo(a,d,[amiga],1).
ramo(d,a,[amiga],1).
ramo(c,b,[amiga],1).
ramo(b,c,[amiga],1).

/*lista uma lista com os amigos de um user*/
listar_amigos(X,Y):-ramo(X,Y,_,_).
listar_amigos_lista(X,Lista):-findall(L,listar_amigos(X,L),Lista).

/*procurar amigos com numa dada tag*/
procurar_tag(Tag,Nos,Res):-!.
procurar_tag(Tag,[ID|Resto],Res):-no(ID,Lista,_,_),member(Tag,Lista)->procurar_tag(Tag,Resto,[Res|ID]);procurar_tag(Tag,Resto,Res).

/*maximo de uma lista*/
max_list([H], H).
max_list([H|T], M2) :- max_list(T, M), M2 is max(H, M).

/*elemento numa possição da lista*/
indexOf([Element|_], Element, 0):- !.
indexOf([_|Tail], Element, Index):- indexOf(Tail, Element, Index1), !, Index is Index1+1.

amigos_tag(Nos,Tag,Res).
amigos_tag([ID|Resto],Tag,Res):listar_amigos(ID,LA),procurar_tag(Tag,LA,LAT),length(LAT,T),amigos_tag(Resto,Tag,[Res|T]).

maven(Tag,Element):-findall(NoID,no(NoID,_,_,_),L),amigos_tag(L,Tag,Ltam),max_list(Ltam,T),indexOf(Ltam,T,POS),indexOf(L, Element, POS),write(Element).
