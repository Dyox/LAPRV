using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rede
{
    public class Relacao : ActiveRecord
    {
        private int _profileIDA;
        private int _profileIDB;
        private int _forca;
        private string _estado;
        private IList _tagList;

        public Relacao()
        {

        }

        public Relacao(int profileIDA, int profileIDB, int forca, string estado)
        {

            this._profileIDA = profileIDA;
            this._profileIDB = profileIDB;
            this._forca = forca;
            this._estado = estado;
        }

        protected Relacao(DataRow row)
        {
            this.myID = (int)row["IDRelacao"];
            this._profileIDA = (int)row["ProfileIDA"];
            this._profileIDB = (int)row["ProfileIDB"];
            this._forca = (int)row["Forca"];
            this._estado = (string)row["Estado"];
        }
        public Relacao(int _profileIDA, int _profileIDB, int _forca, IList _tag)
        {
            this._profileIDA = _profileIDA;
            this._profileIDB = _profileIDB;
            this._forca = _forca;
            this._tagList = _tag;
        }

        public int ProfileIDA { get { return _profileIDA; } set { _profileIDA = value; } }
        public int ProfileIDB { get { return _profileIDB; } set { _profileIDB = value; } }
        public int Forca { get { return _forca; } set { _forca = value; } }
        public string Estado { get { return _estado; } set { _estado = value; } }
        public IList TagList
        {
            get { return _tagList; }
            set { _tagList = value; }
        }

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


        public static Relacao LoadByRelacao(int IDA,int IDB)
        {

            DataSet ds = ExecuteQuery("SELECT * FROM TRelacao WHERE ProfileIDA=" + IDA + "AND ProfileIDB="+IDB);
            Relacao m = new Relacao(ds.Tables[0].Rows[0]);

            return m;
        }

        public static IList LoadAll()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * from TRelacao WHERE Estado='feito'");

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

        
        public static IList LoadInfoForArcos()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT IDRelacao,ProfileIDA, ProfileIDB, Forca from TRelacao where Estado='feito'");

                IList ret = new ArrayList();

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    int idR = (int)r["IDRelacao"];
                    int _profileIDA = (int)r["ProfileIDA"];
                    int _profileIDB = (int)r["ProfileIDB"];
                    int _forca = (int)r["Forca"];
                    IList _tag = obterTagByIDrelacao(idR);

                    Relacao re = new Relacao(_profileIDA, _profileIDB, _forca, _tag);
                    ret.Add(re);

                }

                return ret;
            }
            catch (Exception ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }

        private static IList obterTagByIDrelacao(int idR)
        {
            IList ret = new ArrayList();
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT ID_Tag FROM Rel_Tag where ID_Rel=" + idR);

                foreach (DataRow row in ds.Tables[0].Rows)
                {
                    int IDrel = (int)row["ID_Tag"];
                    try
                    {
                        DataSet dsTag = ExecuteQuery(GetConnection(false), "SELECT Designacao FROM TTag where TagID=" + IDrel);

                        foreach (DataRow r in dsTag.Tables[0].Rows)
                        {
                            string tag = (string)r["Designacao"];
                            ret.Add(tag);
                        }
                    }
                    catch (Exception ex)
                    {
                        throw new ApplicationException("Erro BD", ex);
                    }
                }
            }
            catch (Exception ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }

            return ret;
        }

        public string toFile()
        {   //ramo(No1_ID,No2_ID,Tag,Força)
            //ramo(d,f,[amiga,irma],1).
            String txt = "ramo(";
            txt += _profileIDA + ",";
            txt += _profileIDB + ",";
            txt += "[";
            if (TagList.Count == 0)
            {
                txt += "]";
            }
            else
            {
                for (int x = 0; x < TagList.Count; x++)
                {
                    if (x == TagList.Count - 1)
                    {
                        txt += TagList[x] += "]";
                    }
                    else
                    {
                        txt += TagList[x] + ",";
                    }
                }
            }
            txt += ",";
            txt += _forca + ").";
            return txt;
        }

        public override void Save()
        {



            if (this.ID != 0)
            {
                ExecuteNonQuery("UPDATE TRelacao SET ProfileIDA=" + this._profileIDA + ", ProfileIDB=" + this._profileIDB + ",Forca=" + this._forca + ",Estado='" + this._estado + "' WHERE IDRelacao=" + this.ID);
            }
            else
            {
                this.myID = ExecuteNonQuery("INSERT INTO TRelacao(ProfileIDA, ProfileIDB, Forca, Estado) VALUES(" + this.ProfileIDA + "," + this.ProfileIDB + "," + this.Forca + ",'" + this.Estado + "')");
                foreach (string s in TagList)
                {
                    Rede.Tag tagnova = new Rede.Tag();
                    if (Rede.Tag.ExisteTag(s) == false)
                    {

                        tagnova.Designacao = s;
                        tagnova.Save();
                    }
                    else { tagnova = Rede.Tag.LoadByName(s); }
                    this.myID = ExecuteNonQuery("INSERT INTO Rel_Tag(ID_Rel, ID_Tag ) VALUES(" + this.ID + "," + tagnova.ID + ")");



                }

            }
        }



        public static void RemoveRelashionship(int user, int amigo)
        {
            int op = ExecuteNonQuery("DELETE from [TRelacao] WHERE [ProfileIDA]=" + user + " AND [ProfileIDB]=" + amigo);

            int op2 = ExecuteNonQuery("DELETE from [TRelacao] WHERE [ProfileIDA]=" + amigo + " AND [ProfileIDB]=" + user);
        }


        public static IList<string> getTagsByUsers(int user1, int user2)
        {
            IList<string> ret = new List<string>();
            DataSet ds = ExecuteQuery(GetConnection(false), "SELECT IDRelacao FROM TRelacao WHERE ProfileIDA=" + user1 + " and ProfileIDB=" + user2);
            if (ds.Tables[0].Rows.Count != 1)
            {
                ret.Add("Sem Tags");
                return ret;
            }
            else
            {
                int rel = (int)ds.Tables[0].Rows[0]["IDRelacao"];
                ds = ExecuteQuery(GetConnection(false), "SELECT ID_Tag FROM Rel_Tag WHERE ID_Rel=" + rel);
                if (ds.Tables[0].Rows.Count != 1)
                {
                    ret.Add("Sem Tags");
                    return ret;
                }
                else
                {
                    int tag = (int)ds.Tables[0].Rows[0]["ID_Tag"];
                    ds = ExecuteQuery(GetConnection(false), "SELECT Designacao FROM TTag where TagID=" + tag);
                    foreach (DataRow r in ds.Tables[0].Rows)
                    {
                        string tagtxt = (string)r["Designacao"];
                        ret.Add(tagtxt);
                    }
                    return ret;
                }
            }
        }

      
    }
}

