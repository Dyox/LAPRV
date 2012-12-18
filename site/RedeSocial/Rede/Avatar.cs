using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rede
{
   public class Avatar: ActiveRecord
    {
        private string _desgina;

        public Avatar(String des)
        {

            this._desgina = des;

        }

        protected Avatar(DataRow row)
        {
            this.myID = (int)row["AvatarID"];
            this._desgina = (string)row["Designacao"];

        }


        public string Designacao { get { return _desgina; } set { _desgina = value; } }



        public override string ToString()
        {
            return Designacao;
        }



        public static Avatar LoadById(int ID)
        {

            DataSet ds = ExecuteQuery("SELECT * FROM TAvatar WHERE AvatarID=" + ID);
            Avatar m = new Avatar(ds.Tables[0].Rows[0]);

            return m;
        }

        public static IList LoadAll()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * from TAvatar");

                IList ret = new ArrayList();

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Avatar av = new Avatar(r);
                    ret.Add(av);

                    //apagar
                    // save in registry
                    //loaded[p.ID] = p;
                }

                return ret;
            }
            catch (Exception ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public static Avatar LoadByName(string tipo)
        {

            DataSet ds = ExecuteQuery("SELECT * FROM TAvatar WHERE Designacao='" + tipo + "'");
            Avatar av = new Avatar(ds.Tables[0].Rows[0]);

            return av;
        }

        public override void Save()
        {

            //TODO implementar este método
            
            if (this.ID != 0)
            {
                ExecuteNonQuery("UPDATE TAvatar SET AvatarID=" + this.ID + ", Designacao='" + this.Designacao + "'WHERE AvatarID=" + this.ID);
            }
            else
            {
                this.myID = ExecuteNonQuery("INSERT INTO TAvatar(Designacao) VALUES('" + this.Designacao + "')");
            }

            
        }
    }
}
