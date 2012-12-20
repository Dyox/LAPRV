using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rede
{
   public class Humor: ActiveRecord
    {
          private string _desgina;

        public Humor(String des)
        {

            this._desgina = des;

        }

        protected Humor(DataRow row)
        {
            this.myID = (int)row["HumorID"];
            this._desgina = (string)row["Designacao"];

        }


        public string Designacao { get { return _desgina; } set { _desgina = value; } }



        public override string ToString()
        {
            return Designacao;
        }



        public static Humor LoadById(int ID)
        {

            DataSet ds = ExecuteQuery("SELECT * FROM THumor WHERE HumorID=" + ID);
            if (ds.Tables[0].Rows.Count != 1)
                return null;
            else
                return new Humor(ds.Tables[0].Rows[0]);
        }

        public static IList LoadAll()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * from THumor");

                IList ret = new ArrayList();

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Humor hm = new Humor(r);
                    ret.Add(hm);

                }

                return ret;
            }
            catch (Exception ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public static Humor LoadByName(string tipo)
        {

            DataSet ds = ExecuteQuery("SELECT * FROM THumor WHERE Designacao='" + tipo + "'");
            Humor av = new Humor(ds.Tables[0].Rows[0]);

            return av;
        }

        public override void Save()
        {

            //TODO implementar este método
            
            if (this.ID != 0)
            {
                ExecuteNonQuery("UPDATE THumor SET HumorID=" + this.ID + ", Designacao='" + this.Designacao + "'WHERE HumorID=" + this.ID);
            }
            else
            {
                this.myID = ExecuteNonQuery("INSERT INTO THumor(Designacao) VALUES('" + this.Designacao + "')");
            }

            
        }
    }
}