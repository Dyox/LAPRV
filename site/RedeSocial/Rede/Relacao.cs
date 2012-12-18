using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rede
{
    class Relacao :ActiveRecord
    {
        private string _profileIDA;
        private string _profileIDB;
        private int _forca;
        private string _tag;
        private string _estado;

        public Relacao(string profileIDA, string profileIDB, int forca, string tag, string estado )
        {

            this._profileIDA= profileIDA;
            this._profileIDB= profileIDB;
            this._forca= forca;
            this._tag=  tag;
            this._estado= estado;
        }

        protected Relacao(DataRow row)
        {
            this.myID = (int)row["RelacaoID"];
            this._profileIDA = (string)row["ProfileIDA"];
            this._profileIDB = (string)row["ProfileIDB"];
            this._forca= (int)row["Forca"];
            this._tag = (string)row["Tag"];
            this._estado= (string)row["Estado"];
        }


        public string ProfileIDA { get { return _profileIDA; } set { _profileIDA = value; } }
        public string ProfileIDB { get { return _profileIDB; } set { _profileIDB = value; } }
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



        public override void Save()
        {

            
            
            if (this.ID != 0)
            {
                ExecuteNonQuery("UPDATE TRelacao SET RelacaoID=" + this.ID + ", ProfileIDA='" + this._profileIDA + "', ProfileIDB='"+this._profileIDB+"',Forca="+this._forca+",Tag='"+this._tag+"',Estado='"+this._estado+"'WHERE RelacaoID=" + this.ID);
            }
            else
            {
                this.myID = ExecuteNonQuery("INSERT INTO THumor(ProfileIDA, ProfileIDB, Forca, Tag, Estado) VALUES('" + this.ProfileIDA + "','"+this.ProfileIDB+"',"+this.Forca+",'"+this.TTag+"','"+this.Estado+"')");
            }
        }
    }
    
}
