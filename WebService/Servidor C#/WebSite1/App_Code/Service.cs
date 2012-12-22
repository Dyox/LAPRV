using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;
using System.Collections;

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
            for (int i = 0; i < lista.Count; i++)
            {
                ret.Add(new NoBD(lista.Count, 0, 0));
                ret.Add(new NoBD(((Rede.Perfil)lista[i]).ID, ((Rede.Perfil)lista[i]).X, ((Rede.Perfil)lista[i]).Y));
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
            for (int i = 0; i < lista.Count; i++)
            {
                ret.Add(new ArcoBD(lista.Count,0,0,0));
                ret.Add(new ArcoBD(((Rede.Relacao)lista[i]).ID, ((Rede.Relacao)lista[i]).ProfileIDA, ((Rede.Relacao)lista[i]).ProfileIDB, ((Rede.Relacao)lista[i]).Forca));
                //idl.Add(((Rede.Perfil)lista[i]).ID);
                //xl.Add(((Rede.Perfil)lista[i]).X
                //yl.Add(((Rede.Perfil)lista[i]).Y);
            }

            return ret;

        }


    }

    

   
