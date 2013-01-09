using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Diagnostics;
using Rede;
using System.Collections;

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
            //                    "run:- tell('user_comando.txt'),cam_min(a,c,P),told,halt. "+
            //                     ":-run. \n";

            //menorCaminho = cam_min(a,c,P)
            //caminhoMaisForte = camMaisForte(1,7,P)

            //PrologExec p = new PrologExec("user", "caminhoMaisForte");
            //PrologExec p = new PrologExec("user", "menorCaminho");
            //PrologExec p = new PrologExec("user", "recomendaAmizade");
            PrologExec p = new PrologExec("user", "xTagsEmComum");
            
            //string res = p.executaComandoProlog("1,10,P");
            //string res = p.executaComandoProlog("1");
            string res = p.executaComandoProlog("1,1");
            Console.WriteLine(res);

            //sugere_amigos(res);

            xTagsEmComum(res);
           
            //int profileIDA, int profileIDB, int forca, string tag
            //% ramo(No1_ID,No2_ID,Tag,Força)
            //% no(NoID,PosX,PosY)
            IList listaArcos = Rede.Relacao.LoadInfoForArcos();
            //Console.WriteLine(((Rede.Relacao)listaArcos[4]).toFile());
            //Console.WriteLine();
            IList listaNos = Rede.Perfil.LoadInfoForNos();
            //Console.WriteLine(((Rede.Perfil)listaNos[0]).toFile());
            //Console.Read();

            //string txt = "";
            //foreach (Relacao r in listaArcos)
            //{
            //    txt += r.toFile() + " \n";
            //}
            //foreach (Perfil n in listaNos)
            //{
            //    txt += n.toFile() + " \n";
            //}
            //escrverTXT(txt);
            //Console.Write(txt);
            Console.Read();
            
        }

        //cria um dicionário com o user e as suas tags
        private static Dictionary<string, List<string>> dicUserTag (String res)
        {
            List<string> texto = res.Split(',').ToList<string>();
            Dictionary<string, List<string>> dictionary = new Dictionary<string, List<string>>();

            for (int i = 0; i < texto.Count - 1; i++)
            {
                List<string> testeUser = texto[i].ToString().Split('[').ToList<string>();
                String testeTag = testeUser[1].ToString().Split(']')[0];
                //Console.WriteLine("tag teste -> "+testeTag);

                if (!dictionary.ContainsKey(testeUser[0].ToString()))
                {
                    dictionary.Add(testeUser[0].ToString(), new List<String>());
                    dictionary[testeUser[0].ToString()].Add(testeTag);
                }
                else
                {
                    dictionary[testeUser[0].ToString()].Add(testeTag);
                }
            }
            return dictionary;
        }



        private static void xTagsEmComum(String res)
        {
            Dictionary<string, List<string>> dictionary = dicUserTag(res);
            int x=3;
            foreach (var entry in dictionary)
            {
                if (entry.Value.Count == x)
                {
                    Console.WriteLine("O user " + entry.Key + " tem " + x + " tags em comum.");
                    foreach (var tag in entry.Value)
                        Console.WriteLine(tag);
                }
            }
        }

        private static void sugere_amigos(String res)
        {
            Dictionary<string, List<string>> dictionary = dicUserTag(res);
            foreach (var entry in dictionary)
            {
                Console.WriteLine(entry.Key);
                foreach (var tag in entry.Value)
                    Console.WriteLine(tag);              
            }
        }

        private static Boolean escrverTXT(string lines)
        {
            try
            {
                System.IO.File.WriteAllText(@"C:\\WIN-PROLOG 4800\" + "aaaaaaaaaanosArcos" + ".txt", lines);
            }
            catch (System.IO.IOException ex)
            {
                return false;
            }
            return true;
        }

        
    }
}

