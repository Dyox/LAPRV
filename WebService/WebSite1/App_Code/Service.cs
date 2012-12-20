using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

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

        public IList GetAllXY()
        {
            IList ret = new ArrayList();
            //IList idl = new ArrayList();
            //IList xl = new ArrayList();
            //IList yl = new ArrayList();
            IList lista = Rede.Perfil.LoadAll();
            for (int i = 0; i < lista.Count; i++)
            {
                ret.Add(new No(((Rede.Perfil)lista[i]).ID,((Rede.Perfil)lista[i]).X,((Rede.Perfil)lista[i]).Y));
                //idl.Add(((Rede.Perfil)lista[i]).ID);
                //xl.Add(((Rede.Perfil)lista[i]).X);
                //yl.Add(((Rede.Perfil)lista[i]).Y);
            }
            
                return ret;

        }

    }

    [DataContract]
    public class No
    {
        [DataMember]
        public int id { get; set; }
        [DataMember]
        public int x{ get; set; }

        [DataMember]
        public int y{ get; set; }

        [DataMember]
        public int numNo{ get; set; }

        public No(int idi, int xi,int yi)
        {
            id = idi;
            x = xi;
            y = yi;
        }
    }
 [DataContract]
    public class Arco
    {
        [DataMember]
        public int idPrim { get; set; }
        [DataMember]
        public int idSec{ get; set; }

        [DataMember]
        public int forca{ get; set; }

     
        public Arco(int idi, int xi,int yi)
        {
            idPrim = idi;
            idSec = xi;
            forca = yi;
        }
    }

