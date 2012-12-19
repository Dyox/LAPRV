% Best first com heurística
% bf(+Origem, +Destino, ?Percurso, ?Custo).

% cidade(Cidade, PosX, PosY).

% Representação dos caminhos: c(Heurística/CustoAcumulado, ListaNós).
bf(Orig,Dest,Perc,Total):-
	time(0,Ti),

	estimativa(Orig,Dest,H),
	bf1([c(H/0,[Orig])],Dest,P,Total),
	reverse(P,Perc),

	time(0,Tf),
	Ti=(_,Ii), Tf=(_,If), T is If-Ii,
	write('Tempo de execução: '),write(T),write(' ms'),nl.

bf1(Percursos,Dest,Percurso,Total):-
	menor_percurso(Percursos,Menor,Restantes),
	percursos_seguintes(Menor,Dest,Restantes,Percurso,Total).

percursos_seguintes(c(_/Dist,Percurso),Dest,_,Percurso,Dist):-
	Percurso=[Dest|_].
percursos_seguintes(c(_,[Dest|_]),Dest,Restantes,Percurso,Total):-
	!,
	bf1(Restantes,Dest,Percurso,Total).
percursos_seguintes(c(_/Dist,[Ult|T]),Dest,Percursos,Percurso,Total):-
	findall(
		c(H1/D1,[Z,Ult|T]),
		proximo_no(Ult,T,Z,Dist,Dest,H1/D1),
		Lista),
	append(Lista,Percursos,NovosPercursos),
	bf1(NovosPercursos,Dest,Percurso,Total).

menor_percurso([Percurso|Percursos],Menor,[Percurso|Resto]):-
	menor_percurso(Percursos,Menor,Resto),
	menor(Menor,Percurso),
	!.
menor_percurso([Percurso|Resto],Percurso,Resto).

menor(c(H1/D1,_),c(H2/D2,_)):-C1 is H1+D1, C2 is H2+D2, C1<C2.

proximo_no(X,T,Y,Dist,Dest,H/Dist1):-
	(estrada(X,Y,Z);estrada(Y,X,Z)),
	not member(Y,T),
	Dist1 is Dist + Z,
	estimativa(Y,Dest,H).

estimativa(C1,C2,Est):-
	cidade(C1,X1,Y1),
	cidade(C2,X2,Y2),
	DX is X1-X2,
	DY is Y1-Y2,
	Est is 0*sqrt(DX*DX+DY*DY). % '0*' para desprezar a heurística.


