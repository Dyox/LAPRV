using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rede
{
    public class Relacao :ActiveRecord
    {
        private int _profileIDA;
        private int _profileIDB;
        private int _forca;
        private string _tag;
        private string _estado;

        public Relacao(int profileIDA, int profileIDB, int forca, string tag, string estado )
        {

            this._profileIDA= profileIDA;
            this._profileIDB= profileIDB;
            this._forca= forca;
            this._tag=  tag;
            this._estado= estado;
        }

        protected Relacao(DataRow row)
        {
            this.myID = (int)row["IDRelacao"];
            this._profileIDA = (int)row["ProfileIDA"];
            this._profileIDB = (int)row["ProfileIDB"];
            this._forca= (int)row["Forca"];
            this._tag = (string)row["Tag"];
            this._estado= (string)row["Estado"];
        }


        public int ProfileIDA { get { return _profileIDA; } set { _profileIDA = value; } }
        public int ProfileIDB { get { return _profileIDB; } set { _profileIDB = value; } }
        public int Forca { get { return _forca; } set { _forca = value; } }
        public string TTag { get { return _tag; } set { _tag = value; } }
        public string Estado { get { return _estado; } set { _estado = value; } }

        public override string ToString()
        {
            return Estado;
        }



        public static Relacao LoadById(int ID)
        {

            DataSet ds = ExecuteQuery("SELECT * FROM TRelacao WHERE RelacaoID=" + ID);
            Relacao m = new Relacao(ds.Tables[0].Rows[0]);

            return m;
        }

        public static IList LoadAll()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * from TRelacao");

                IList ret = new ArrayList();

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Relacao re = new Relacao(r);
                    ret.Add(re);

                }

                return ret;
            }
            catch (Exception ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public static IList LoadByUserA( string ProfileI)
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * from TRelacao WHERE ProfileIDA=" + ProfileI);

                IList ret = new ArrayList();

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Relacao re = new Relacao(r);
                    ret.Add(re);

                }

                return ret;
            }
            catch (Exception ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        public static List<string> TagCloudRel()
        {
            List<string> lst = new List<string>();
           
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * from TRelacao");

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Relacao av = new Relacao(r);
                    lst.Add(av.TTag);
                }


            }
            catch (Exception ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
            return lst;
        }



        public override void Save()
        {

            
            
            if (this.ID != 0)
            {
                ExecuteNonQuery("UPDATE TRelacao SET ProfileIDA=" + this._profileIDA + ", ProfileIDB="+this._profileIDB+",Forca="+this._forca+",Tag='"+this._tag+"',Estado='"+this._estado+"'WHERE RelacaoID=" + this.ID);
            }
            else
            {
                this.myID = ExecuteNonQuery("INSERT INTO TRelacao(ProfileIDA, ProfileIDB, Forca, Tag, Estado) VALUES(" + this.ProfileIDA + ","+this.ProfileIDB+","+this.Forca+",'"+this.TTag+"','"+this.Estado+"')");
            }
        }
    }
    
}
