﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;
using System.Collections;
using Prolog;
using System.Web.Security;

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
        ret.Add(new NoBD(lista.Count, 0, 0, "", "", "", 0));
        for (int i = 0; i < lista.Count; i++)
        {
            int id = ((Rede.Perfil)lista[i]).ID;
            Utilizador nome = GetUtilizadorByID(id);
            string avatar3d = Rede.Perfil.getAvatar3DByID(id);
            int numtags = Rede.Perfil.LoadTagsByUserID(id).Count;
            ret.Add(new NoBD(id, ((Rede.Perfil)lista[i]).X, ((Rede.Perfil)lista[i]).Y, Rede.Perfil.getHumorByPrefilID(id), nome.nome, avatar3d, numtags));
            //idl.Add(((Rede.Perfil)lista[i]).ID);
            //xl.Add(((Rede.Perfil)lista[i]).X);
            //yl.Add(((Rede.Perfil)lista[i]).Y);
        }

        return ret;

    }
    public IList<ArcoBD> GetAllArcoBD()
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
        Utilizador util = new Utilizador(perfil.Name, perfil.Nick, perfil.Morada, perfil.Telemovel, perfil.DataNascimento.ToString(), perfil.avatar);



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

    public string getMenorCaminho(int no1, int no2)
    {
        PrologExec p = new PrologExec(no1 + "_" + no2, "menorCaminho");
        string res = p.executaComandoProlog(no1 + "," + no2 + ",P");
        return res;
    }

    public string getCaminhoForte(int no1, int no2)
    {
        PrologExec p = new PrologExec(no1 + "_" + no2, "caminhoMaisForte");
        string res = p.executaComandoProlog(no1 + "," + no2 + ",P");
        return res;
    }

    public int validateLogin(string userName, string password)
    {
        if (Membership.ValidateUser(userName, password))
        {
            var userId = (Guid)(Membership.GetUser(userName, false).ProviderUserKey);
            Rede.Perfil user = Rede.Perfil.LoadByUserId(userId.ToString());
            return user.ID;
        }
        else
        {
            return 0;
        }
    }

    public string xTagsEmComum(int id, int n)
    {
        ///*lista os amigos do User com N tags em comum*/
        PrologExec p = new PrologExec("" + id, "xTagsEmComum");
        string res = p.executaComandoProlog(id + "," + n);
        return res;
    }

    public int tamanhoRedeUtilizador(int id)
    {
        PrologExec p = new PrologExec("" + id, "tamanhoRedeUtilizador");
        string res = p.executaComandoProlog("" + id);
        try
        {
            return Convert.ToInt32(res);
        }
        catch (FormatException e)
        {
            Console.WriteLine("Input string is not a sequence of digits.");
        }
        return -1;
    }

    public string sugereAmigos(int id)
    {
        PrologExec p = new PrologExec(id + "", "recomendaAmizade");
        string res = p.executaComandoProlog(id + "");
        return res;
    }
    public string grafoAmigosComuns(int user1, int user2)
    {
        PrologExec p = new PrologExec(user1 + "_" + user2, "grafoAmigosComuns");
        string res = p.executaComandoProlog(user1 + "," + user2);
        return res;
    }

    public Ligacao getLigacao(int userreg, int user1, int user2)
    {
        if (userreg == user1)
        {
            Ligacao lig = new Ligacao(user1, user2, Rede.Relacao.getTagsByUsers(user1, user2));
            return lig;
        }
        else
        {
            return null;
        }
    }
    public string getAmigosNivel3(int userID)
    {
        PrologExec p = new PrologExec(userID + "", "grafoUser3");
        string res = p.executaComandoProlog(userID + "");
        return res;
    }
    public string getMavenOfTag(string tag)
    {
        PrologExec p = new PrologExec(tag + "", "maven");
        string res = p.executaComandoProlog(tag + "");
        return res;
    }
    public string getSeparacao(int no1, int no2)
    {
        PrologExec p = new PrologExec(no1 + "_" + no2, "separacao");
        string res = p.executaComandoProlog(no1 + "," + no2);
        return res;
    }
    public IList<NoBD> getGrafoNivel3(int userid)
    {
        string ids = getAmigosNivel3(userid);
        ids = ids.Replace("[", "");
        ids = ids.Replace("]", "");
        string[] str = ids.Split(',');

        IList<NoBD> ret = new List<NoBD>();
        ret.Add(new NoBD((str.Count() + 1), 0, 0, "", "", "", 0));

        Rede.Perfil perf = Rede.Perfil.LoadById(userid);
        string avatar3d = Rede.Perfil.getAvatar3DByID(userid);
        int numtags = Rede.Perfil.LoadTagsByUserID(userid).Count;
        NoBD noi = new NoBD(userid, perf.X, perf.Y, Rede.Perfil.getHumorByPrefilID(userid), perf.Name, avatar3d, numtags);
        ret.Add(noi);
        //ids =ids.Remove(0);
        //ids =ids.Remove(ids.Count() - 1);
        if (ids != "")
        {
            for (int i = 0; i < str.Count(); i++)
            {
                int id = Convert.ToInt32(str[i]);
                perf = Rede.Perfil.LoadById(id);
                avatar3d = Rede.Perfil.getAvatar3DByID(id);
                numtags = Rede.Perfil.LoadTagsByUserID(id).Count;
                noi = new NoBD(id, perf.X, perf.Y, Rede.Perfil.getHumorByPrefilID(id), perf.Name, avatar3d, numtags);
                ret.Add(noi);
            }

        }
        else
        {
            ret[0].id = ret[0].id - 1;
        }
        return ret;
    }

    public IList<NoBD> getNosGrafoAmigos(int user1, int user2)
    {
        string ids = grafoAmigosComuns(user1, user2);

        ids = ids.Replace("[", "");
        ids = ids.Replace("]", "");
        string[] str = ids.Split(',');

        IList<NoBD> ret = new List<NoBD>();
        ret.Add(new NoBD((str.Count() + 2), 0, 0, "", "", "", 0));

        Rede.Perfil perf = Rede.Perfil.LoadById(user1);
        string avatar3d = Rede.Perfil.getAvatar3DByID(user1);
        int numtags = Rede.Perfil.LoadTagsByUserID(user1).Count;
        NoBD noi = new NoBD(user1, perf.X, perf.Y, Rede.Perfil.getHumorByPrefilID(user1), perf.Name, avatar3d, numtags);
        ret.Add(noi);

        perf = Rede.Perfil.LoadById(user2);
        avatar3d = Rede.Perfil.getAvatar3DByID(user2);
        numtags = Rede.Perfil.LoadTagsByUserID(user2).Count;
        noi = new NoBD(user2, perf.X, perf.Y, Rede.Perfil.getHumorByPrefilID(user2), perf.Name, avatar3d, numtags);
        ret.Add(noi);


        if (ids != "")
        {

            for (int i = 0; i < str.Count(); i++)
            {
                int id = Convert.ToInt32(str[i]);
                perf = Rede.Perfil.LoadById(id);
                avatar3d = Rede.Perfil.getAvatar3DByID(id);
                numtags = Rede.Perfil.LoadTagsByUserID(id).Count;
                noi = new NoBD(id, perf.X, perf.Y, Rede.Perfil.getHumorByPrefilID(id), perf.Name, avatar3d, numtags);
                ret.Add(noi);
            }
        }
        else
        {
            ret[0].id = ret[0].id - 1;
        }
        return ret;

    }
    public IList<NoBD> getNosGrafo(int userid)
    {
        Boolean prem = Rede.Perfil.verificaPremium(userid);
        if (prem == true)
        {
            return GetAllXY();
        }
        else
        {
            return getGrafoNivel3(userid);
        }


    }
}

     

   
