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

      
        public IList<No> GetAllXY()
        {
            IList<No> ret = new List<No>();
            //IList idl = new ArrayList();
            //IList xl = new ArrayList();
            //IList yl = new ArrayList();
            IList lista = Rede.Perfil.LoadAll();
            for (int i = 0; i < lista.Count; i++)
            {
                ret.Add(new No(((Rede.Perfil)lista[i]).ID, ((Rede.Perfil)lista[i]).X, ((Rede.Perfil)lista[i]).Y));
                //idl.Add(((Rede.Perfil)lista[i]).ID);
                //xl.Add(((Rede.Perfil)lista[i]).X);
                //yl.Add(((Rede.Perfil)lista[i]).Y);
            }

            return ret;

        }

    }

    

   
