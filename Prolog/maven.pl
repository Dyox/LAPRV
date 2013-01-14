% no(NoID,[TAGS],PosX,PosY)
no(a,[rock],45,95).
no(b,[rock,musica],90,95).
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

se_entao_senao(X,Y,Z):-X,!,Y.
se_entao_senao(X,Y,Z):-Z.

/*elemento numa possi??o da lista*/
item_at( N, L, Item ) :- item_at( N, 0, L, Item ).   
item_at( N, Count, [H|_], Item ) :- CountNew is Count + 1,CountNew = N, Item = H.
item_at( N, Count, [_|T], Item ) :- CountNew is Count + 1,item_at( N, CountNew, T, Item ).

/*maximo de uma lista*/
max_list([H], H).
max_list([H|T], M2) :- max_list(T, M), M2 is max(H, M).

/*lista uma lista com os amigos de um user*/
listar_amigos(X,Y):-ramo(X,Y,_,_).
listar_amigos_lista(X,Lista):-findall(L,listar_amigos(X,L),Lista).

/*procurar amigos com numa dada tag*/
procurar_tag(Tag,[],[]):-!.
procurar_tag(Tag,[ID|Resto],Res):-procurar_tag(Tag,Resto,Res1),no(ID,Lista,_,_),
		se_entao_senao(member(Tag,Lista),append([ID],Res1,Res),append([],Res1,Res)),!.

amigos_tag(Tag,[],[]):-!.
amigos_tag(Tag,[ID|Resto],Res):-amigos_tag(Tag,Resto,Res1),listar_amigos_lista(ID,LA),procurar_tag(Tag,LA,LAT),length(LAT,T),append([T],Res1,Res),!.

maven(Tag,Element):-findall(NoID,no(NoID,_,_,_),L),amigos_tag(Tag,L,Ltam),max_list(Ltam,T),
			se_entao_senao(T<2,write('Nenhum Maven...'),(item_at(POS,Ltam,T),item_at(POS,L, Element),write(Element))).