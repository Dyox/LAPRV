using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rede
{
    class Tag :ActiveRecord
    {
        private string _desgina;

        public Tag(String des)
        {

            this._desgina = des;

        }

        protected Tag(DataRow row)
        {
            this.myID = (int)row["TagID"];
            this._desgina = (string)row["Designacao"];

        }


        public string Designacao { get { return _desgina; } set { _desgina = value; } }



        public override string ToString()
        {
            return Designacao;
        }



        public static Tag LoadById(int ID)
        {

            DataSet ds = ExecuteQuery("SELECT * FROM TTag WHERE TagID=" + ID);
            Tag t = new Tag(ds.Tables[0].Rows[0]);

            return t;
        }

        public static IList LoadAll()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * from TTag");

                IList ret = new ArrayList();

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Tag av = new Tag(r);
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

        public static Tag LoadByName(string tipo)
        {

            DataSet ds = ExecuteQuery("SELECT * FROM TTag WHERE Designacao='" + tipo + "'");
            Tag av = new Tag(ds.Tables[0].Rows[0]);

            return av;
        }

        public override void Save()
        {

            //TODO implementar este método
            
            if (this.ID != 0)
            {
                ExecuteNonQuery("UPDATE TTag SET TagID=" + this.ID + ", Designacao='" + this.Designacao + "'WHERE TagID=" + this.ID);
            }
            else
            {
                this.myID = ExecuteNonQuery("INSERT INTO TTag(Designacao) VALUES('" + this.Designacao + "')");
            }

            
        }
    }
}
