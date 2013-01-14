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
cam_min(X,Y,P):-findall(P,caminhos(X,Y,P),L),menor(L,P).

contar([ ],0).
contar([A|B],N):-contar(B,N1),N is N1+1.

se_entao(X,Y):-X,!,Y;true.

soma_for(_,[],0).
soma_for(A,[H|T],V):-soma_for(H,T,V1),ramo(A,H,_,X),V is V1+X.

grau(X,Y,V):-cam_min(X,Y,[A|P]),contar([A|P],N),soma_for(A,P,N1),V is N1/N,!,write(V);write('Nao existe ligacao...').


