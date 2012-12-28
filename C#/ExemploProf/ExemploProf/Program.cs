using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Diagnostics;

namespace ExemploProf
{

    class IORedirExample
    {
        public static void Main()
        {
            //string[] lines = { "add(A,B,R):-R is A + B, write(R).",
            //                     "run:- tell('user_comando.txt'),add(1,5,R),told,halt.",
            //                     ":-run." };

            //string[] lines = { "no(a,[musica,rock],45,95). no(b,[musica,rock],90,95). no(c,[musica],45,95). no(d,[],90,95). no(e,[],45,95). no(f,['c#'],90,95).", 
            //                    "ramo(a,b,[namorada],1). ramo(a,c,[amiga],2). ramo(a,d,[amiga],1). ramo(a,e,[amiga],2). ramo(b,e,[amiga],1). ramo(d,e,[amiga],1). ramo(d,f,[amiga,irma],1). ramo(c,d,[],3).",
            //                    "caminhos(X,Y,P):-todos_caminhos(X,Y,[Y],P).",
            //                    "todos_caminhos(X,Y,L,[X|L]):-ramo(X,Y,_,_).",
            //                    "todos_caminhos(X,Y,L,P):-ramo(Z,Y,_,_),Z\\==X,(not member(Z,L)), todos_caminhos(X,Z,[Z|L],P).",
            //                    "lstcaminhos(X,Y,L):-findall(P,caminhos(X,Y,P),L).",
            //                    "menor([X],X).",
            //                    "menor([X|T],X):-menor(T,L),length(X,N),length(L,M),N =< M,!.",
            //                    "menor([X|T],L):-menor(T,L).",
            //                    "cam_min(X,Y,P):-findall(P,caminhos(X,Y,P),L),menor(L,P),write(P),nl.",
            //                    "run:- tell('user_comando.txt'),cam_min(f,d,P),told,halt.",
            //                     ":-run."};
            //string lines =  "no(a,[musica,rock],45,95). no(b,[musica,rock],90,95). no(c,[musica],45,95). no(d,[],90,95). no(e,[],45,95). no(f,['c#'],90,95). "+ 
            //                    "ramo(a,b,[namorada],1). ramo(a,c,[amiga],2). ramo(a,d,[amiga],1). ramo(a,e,[amiga],2). ramo(b,e,[amiga],1). ramo(d,e,[amiga],1). ramo(d,f,[amiga,irma],1). ramo(c,d,[],3). "+
            //                    "caminhos(X,Y,P):-todos_caminhos(X,Y,[Y],P). "+
            //                    "todos_caminhos(X,Y,L,[X|L]):-ramo(X,Y,_,_). "+
            //                    "todos_caminhos(X,Y,L,P):-ramo(Z,Y,_,_),Z\\==X, (not member(Z,L)), todos_caminhos(X,Z,[Z|L],P). "+
            //                    "lstcaminhos(X,Y,L):-findall(P,caminhos(X,Y,P),L). "+
            //                    "menor([X],X). "+
            //                    "menor([X|T],X):-menor(T,L) ,length(X,N),length(L,M),N =< M,!. "+
            //                    "menor([X|T],L):-menor(T,L). "+
            //                    "cam_min(X,Y,P):-findall(P,caminhos(X,Y,P),L),menor(L,P),write(P);write('Nenhum caminho...'). " +
                                "verifica(P):-(P==var(P)->write('nenhum caminho');write(P)),nl. " +
                                "run:- tell('user_comando.txt'),cam_min(a,b,P),told,halt. "+
                                 ":-run. \n";
            
            PrologExec p = new PrologExec(lines, "user", "add","user_comando");
            string res = p.executaComandoProlog();
            Console.Write(res);
            Console.Read();
        }
    }
}

