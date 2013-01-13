%listar_amigos_lista(X,Lista):-Lista = [[a,[a,b,c]],[b,[a,b,c]],[d,[a,b,c]]].
% no(NoID,[TAGS],PosX,PosY)
no(a,[rock],45,95).
no(b,[musica,rock],90,95).
no(c,[rock],45,95).
no(d,[musica],90,95).


% ramo(No1_ID,No2_ID,[Tag],Força)
/*ramo(a,b,[namorada],1).
ramo(b,a,[namorada],1).
ramo(a,c,[amiga],2).
ramo(c,a,[amiga],2).
ramo(a,d,[amiga],1).
ramo(d,a,[amiga],1).
ramo(c,b,[amiga],1).
ramo(b,c,[amiga],1).
*/
ramo(b,a,[namorada],1).
ramo(a,b,[namorada],1).
ramo(b,c,[namorada],1).
ramo(c,b,[namorada],1).
ramo(b,d,[namorada],1).
ramo(d,b,[namorada],1).


/*elemento numa possição da lista*/
indexOf([Element|_], Element, 0):- !.
indexOf([_|Tail], Element, Index):- indexOf(Tail, Element, Index1), !, Index is Index1+1.

/*maximo de uma lista*/
max_list([H], H).
max_list([H|T], M2) :- max_list(T, M), M2 is max(H, M).

/*lista uma lista com os amigos de um user*/
listar_amigos(X,Y):-ramo(X,Y,_,_).
listar_amigos_lista(X,Lista):-findall(L,listar_amigos(X,L),Lista).

/*procurar amigos com numa dada tag*/
se_entao_senao(X,Y,Z):-X,!,Y.
se_entao_senao(X,Y,Z):-Z.
procurar_tag(Tag,[],[]):-!.
procurar_tag(Tag,[ID|Resto],Res):-procurar_tag(Tag,Resto,Res1),no(ID,Lista,_,_),se_entao_senao(member(Tag,Lista),append(Res1,[ID],Res),append(Res1,[],Res)),!.

amigos_tag(Tag,[],[]):-!.
amigos_tag(Tag,[ID|Resto],Res):-amigos_tag(Tag,Resto,Res1),listar_amigos_lista(ID,LA),write(ID),write(LA),nl,procurar_tag(Tag,LA,LAT),length(LAT,T),append(Res1,[T],Res),!.

maven(Tag,Element):-findall(NoID,no(NoID,_,_,_),L),amigos_tag(Tag,L,Ltam),max_list(Ltam,T),indexOf(Ltam,T,POS),indexOf(L, Element, POS),write(Element).
