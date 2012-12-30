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