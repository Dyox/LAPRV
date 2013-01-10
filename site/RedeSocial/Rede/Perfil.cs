using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rede
{
    public class Perfil : ActiveRecord
    {
        private string _userID;
        private string _name;
        private string _nick;
        private DateTime _datanasc;
        private string _morada;
        private int _tlm;
        private string _lk;
        private string _fb;
        private Humor _humor;
        private string _avatar;
        private string _avatar3D;
        private int _x;
        private int _y;
        private IList _tags;

        public Perfil()
        {

        }
        public Perfil(string uid)
        {
           
            this._userID= uid;
            
           
            this._name = "";
            this._nick = "";
            this._datanasc = DateTime.Today.Date;
            this._morada = "";
            this._tlm = 0;
            this._lk = "";
            this._fb = "";
            this._humor = Rede.Humor.LoadById(2);
            this._avatar = "";
            this._avatar3D = "";
            this._x = 1;
            this._y = 2;
        }
        public Perfil(int id, string uID, string Name, string Nick, DateTime dataNasc, string morada, int tlm, string lk, string fb, Humor humor,string avatar3D, string avatar, int x, int y)
        {
            this.myID = id;
            this._userID = uID;
            this._name = Name;
            this._nick = Nick;
            this._datanasc = dataNasc;
            this._morada = morada;
            this._tlm = tlm;
            this._lk = lk;
            this._fb = fb;
            this._humor = humor;
            this._avatar3D = avatar3D;
            this._avatar = avatar;
            this._x = x;
            this._y = y;
        }


        public string UsID
        {
            get { return _userID; }
            set { _userID = value; }
        }

        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        public string Nick
        {
            get { return _nick; }
            set { _nick = value; }
        }

        public DateTime DataNascimento
        {
            get { return _datanasc; }
            set { _datanasc = value; }
        }

        public string Morada
        {
            get { return _morada; }
            set { _morada = value; }
        }

        public int Telemovel
        {
            get { return _tlm; }
            set { _tlm = value; }
        }

        public string FaceBook
        {
            get { return _fb; }
            set { _fb = value; }
        }
        public string Linkedin
        {
            get { return _lk; }
            set { _lk = value; }
        }
        public Humor humor
        {
            get { return _humor; }
            set { _humor = value; }
        }

        public string avatar3D
        {
            get { return _avatar3D; }
            set { _avatar3D = value; }
        }

        public string avatar
        {
            get { return _avatar; }
            set { _avatar = value; }
        }

        public int X
        {
            get { return _x; }
            set { _x = value; }
        }

        public int Y
        {
            get { return _y; }
            set { _y = value; }
        }
        public IList Tags
        {
            get { return _tags; }
            set { _tags = value; }
        }
        protected Perfil(DataRow row)
        {
            this.myID = (int)row["ProfileID"];
            this._userID = (string) row["UserID"];
            this._name = (string)row["Nome"];
            this._nick = (string)row["Nick"];
            this._morada = (string)row["Morada"];
            this._datanasc = (DateTime)row["DataNascimento"];
            this._tlm = (int)row["Telemovel"];
            this._fb = (string)row["Facebook"];
            this._lk = (string)row["Linkedin"];
            this._avatar3D = (string)row["Avatar3D"];
            this._avatar = (string)row["Avatar"];
            this._humor = Humor.LoadById((int)row["HumorID"]);
            this._x = (int)row["X"];
            this._y = (int)row["Y"];
        }
        public Perfil(int ID, int x, int y, IList tags)
        {
            // TODO: Complete member initialization
            this.myID = ID;
            this._x = x;
            this._y = y;
            this._tags = tags;
        }


        public override string ToString()
        {
            return _name;
        }

        public static Perfil LoadById(int customerID)
        {
            DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * FROM TProfile WHERE ProfileID=" + customerID);
            if (ds.Tables[0].Rows.Count != 1)
                return null;
            else
                return new Perfil(ds.Tables[0].Rows[0]);
        }

        public static Perfil LoadByUserId(string customerID)
        {
            DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * FROM TProfile WHERE UserID='" + customerID+"'");
            if (ds.Tables[0].Rows.Count != 1)
                return null;
            else
                return new Perfil(ds.Tables[0].Rows[0]);
        }
        public static Perfil LoadByName(string Nam)
        {
            DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * FROM TProfile WHERE Nome='" + Nam+"'");
            if (ds.Tables[0].Rows.Count != 1)
                return null;
            else
                return new Perfil(ds.Tables[0].Rows[0]);
        }

        public static IList LoadAll()
        {
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * FROM TProfile");

                IList ret = new ArrayList();

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Perfil c = new Perfil(r);
                    ret.Add(c);

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

        public static int get_UsersRegistados()
        {
            int N_users=0;
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT * FROM TProfile");

              

                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    N_users++;
                }

              
            }
            catch (Exception ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }

            return N_users;
         
        }

        public string toFile()
        {   //no(NoID,[listaTags,listaTags],PosX,PosY)
            String txt = "no(";
            txt += ID + ",";
            txt += "[";
            if (Tags.Count == 0)
            {
                txt += "]";
            }
            else
            {
                for (int x = 0; x < Tags.Count; x++)
                {
                    if (x == Tags.Count - 1)
                    {
                        txt += Tags[x] += "]";
                    }
                    else
                    {
                        txt += Tags[x] + ",";
                    }
                }
            }
            txt += ",";
            txt += X + ",";
            txt += Y + ").";
            return txt;
        }
    


        public override void Save()
        {
            if (this.ID != 0)
            {
                ExecuteNonQuery("UPDATE TProfile SET Nome='"+this._name+"',Nick= '"+this._nick+"',Morada= '"+ this._morada +"',DataNascimento='"+this._datanasc.ToString("yyyy-MM-dd") +"',Telemovel="+this._tlm+",Linkedin='"+ this._lk+"', Facebook='"+ this._fb+"',HumorID="+this._humor.ID+", Avatar3D='"+this._avatar3D+"', Avatar='"+this._avatar+"',X="+this._x+", Y="+this._y+"WHERE ProfileID=" + this.ID );
            }
            else
            {
                
                
                this.humor= Humor.LoadById(2);

                this.myID = ExecuteNonQuery("INSERT INTO TProfile(UserID, Nome, Nick, Morada, DataNascimento, Telemovel, Facebook, Linkedin, Avatar3D, Avatar, HumorID, X, Y)   VALUES('" + this.UsID + "','" + this.Name + "','" + this.Nick + "','" + this.Morada + "','" + this.DataNascimento.ToString("yyyy-MM-dd") + "'," + this.Telemovel + ",'" + this.Linkedin + "','" + this.FaceBook + "','" + this.avatar3D+ "','" + this.avatar + "'," + this.humor.ID + "," + this.X + "," + this.Y + ")");

                
            }
        }
        public static IList<string> LoadTagsByUserID(int userID)
        {
            IList<string> ret = new List<string>();
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT TagID FROM TTags where ProfileID=" + userID);

                foreach (DataRow row in ds.Tables[0].Rows)
                {
                    int TagID = (int)row["TagID"];
                    try
                    {
                        DataSet dsTag = ExecuteQuery(GetConnection(false), "SELECT Designacao FROM TTag where TagID=" + TagID);

                        foreach (DataRow r in dsTag.Tables[0].Rows)
                        {
                            string tag = (string)r["Designacao"];
                            ret.Add(tag);
                        }
                    }
                    catch (Exception ex)
                    {
                        //throw new ApplicationException("Erro BD", ex);
                    }
                }

            }
            catch (Exception ex)
            {
                //throw new ApplicationException("Erro BD", ex);
            }

            return ret;
        }
        public static string getHumorByPrefilID(int profileID)
        {
            IList ret = new ArrayList();
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT HumorID FROM TProfile where ProfileID=" + profileID);

                foreach (DataRow row in ds.Tables[0].Rows)
                {
                    int HumorID = (int)row["HumorID"];
                    try
                    {
                        DataSet dsTag = ExecuteQuery(GetConnection(false), "SELECT Designacao FROM THumor where HumorID=" + HumorID);

                        foreach (DataRow r in dsTag.Tables[0].Rows)
                        {
                            string humor = (string)r["Designacao"];
                            return humor;
                        }
                    }
                    catch (Exception ex)
                    {
                        //throw new ApplicationException("Erro BD", ex);
                    }
                }

            }
            catch (Exception ex)
            {
                //throw new ApplicationException("Erro BD", ex);
            }

            return "";
        }
        public static IList LoadInfoForNos()
        {//no(NoID,[listaTags],PosX,PosY)
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT ProfileID,X,Y FROM TProfile");

                IList ret = new ArrayList();

                foreach (DataRow row in ds.Tables[0].Rows)
                {
                    int ID = (int)row["ProfileID"];
                    int x = (int)row["X"];
                    int y = (int)row["Y"];
                    IList tags = TagsByUserID(ID);
                    Perfil c = new Perfil(ID, x, y, tags);
                    ret.Add(c);
                }

                return ret;
            }
            catch (Exception ex)
            {
                throw new ApplicationException("Erro BD", ex);
            }
        }
        public static IList TagsByUserID(int userID)
        {
            IList ret = new ArrayList();
            try
            {
                DataSet ds = ExecuteQuery(GetConnection(false), "SELECT TagID FROM TTags where ProfileID=" + userID);

                foreach (DataRow row in ds.Tables[0].Rows)
                {
                    int TagID = (int)row["TagID"];
                    try
                    {
                        DataSet dsTag = ExecuteQuery(GetConnection(false), "SELECT Designacao FROM TTag where TagID=" + TagID);

                        foreach (DataRow r in dsTag.Tables[0].Rows)
                        {
                            string tag = (string)r["Designacao"];
                            ret.Add(tag);
                        }
                    }
                    catch (Exception ex)
                    {
                        //throw new ApplicationException("Erro BD", ex);
                    }
                }

            }
            catch (Exception ex)
            {
                //throw new ApplicationException("Erro BD", ex);
            }

            return ret;
        }

    }
}
