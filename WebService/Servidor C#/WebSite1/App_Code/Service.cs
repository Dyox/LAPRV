using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;
using System.Collections;
using Prolog;

// NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service" in code, svc and config file together.
    public class Service : IService
    {
        public void DoWork()
        {
        }


        public int Add(int x, int y)
        {

            return x + y;
        }

      
        public IList<NoBD> GetAllXY()
        {
            IList<NoBD> ret = new List<NoBD>();
            //IList idl = new ArrayList();
            //IList xl = new ArrayList();
            //IList yl = new ArrayList();
            IList lista = Rede.Perfil.LoadAll();
            ret.Add(new NoBD(lista.Count, 0, 0,"",""));
            for (int i = 0; i < lista.Count; i++)
            {
                int id = ((Rede.Perfil)lista[i]).ID;
                Utilizador nome = GetUtilizadorByID(id);
                ret.Add(new NoBD(id, ((Rede.Perfil)lista[i]).X, ((Rede.Perfil)lista[i]).Y,Rede.Perfil.getHumorByPrefilID(id),nome.nome));
                //idl.Add(((Rede.Perfil)lista[i]).ID);
                //xl.Add(((Rede.Perfil)lista[i]).X);
                //yl.Add(((Rede.Perfil)lista[i]).Y);
            }

            return ret;

        }
        public IList<ArcoBD > GetAllArcoBD()
        {
            IList<ArcoBD> ret = new List<ArcoBD>();
            //IList idl = new ArrayList();
            //IList xl = new ArrayList();
            //IList yl = new ArrayList();

            IList lista = Rede.Relacao.LoadAll();
            ret.Add(new ArcoBD(lista.Count, 0, 0, 0));
            for (int i = 0; i < lista.Count; i++)
            {
                
                ret.Add(new ArcoBD(((Rede.Relacao)lista[i]).ID, ((Rede.Relacao)lista[i]).ProfileIDA, ((Rede.Relacao)lista[i]).ProfileIDB, ((Rede.Relacao)lista[i]).Forca));
                //idl.Add(((Rede.Perfil)lista[i]).ID);
                //xl.Add(((Rede.Perfil)lista[i]).X
                //yl.Add(((Rede.Perfil)lista[i]).Y);
            }

            return ret;

        }

        public Utilizador GetUtilizadorByID(int uid)
        {
            
         

            Rede.Perfil perfil = Rede.Perfil.LoadById(uid);
            Utilizador util = new Utilizador(perfil.Name,perfil.Nick,perfil.Morada,perfil.Telemovel,perfil.DataNascimento.ToString(),perfil.avatar);
            
            

            return util;

        }

        public IList<string> GetTagsByUserID(int uid)
        {
           // IList<Designacao> ret= new List<Designacao>();
            IList<string> tags = Rede.Perfil.LoadTagsByUserID(uid);
            //for (int i = 0; i < tags.Count; i++)
            //{
            //    ret.Add(new Designacao(tags[i]));
            //}
                return tags;

        }
        public string GetHumorByUserID(int uid)
        {

            string humor = Rede.Perfil.getHumorByPrefilID(uid);

            return humor;

        }

        public string getMenorCaminho(int uid)
        {
            PrologExec p = new PrologExec(uid+"", "menorCaminho");
            string res = p.executaComandoProlog("1,10,P");
            return res;
        }

        public string getCaminhoForte(int uid)
        {
            PrologExec p = new PrologExec(uid + "", "caminhoMaisForte");
            string res = p.executaComandoProlog("1,10,P");
            return res;
        }
    }

    

   
