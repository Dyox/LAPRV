using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Threading;
using System.Globalization;

public partial class Registado_Relacoes : System.Web.UI.Page
    {
        private List<string> listtag= new List<string>();
        private List<string> listtag_aceitar = new List<string>();

        protected override void InitializeCulture()
        {
            if (Request.Form["Language"] != null)
            {
                String selectedLanguage = Request.Form["Language"];
                UICulture = selectedLanguage;
                Culture = selectedLanguage;

                Thread.CurrentThread.CurrentCulture =
                    CultureInfo.CreateSpecificCulture(selectedLanguage);
                Thread.CurrentThread.CurrentUICulture = new
                    CultureInfo(selectedLanguage);
            }
            base.InitializeCulture();
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            Aceitar.Enabled = false;
            Rejeitar.Enabled = false;
            MembershipUser currentLoggedInUser = Membership.GetUser();
            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
            Rede.Perfil ProfileIDA = Rede.Perfil.LoadByUserId(id);
            if (ProfileIDA != null)
            {

                SqlDataSource2.SelectCommand = "SELECT [Avatar], [Nome], [Estado] from [ViewFriends] WHERE ([ProfileIDA]=" + ProfileIDA.ID + " AND [Estado]='pendente')";

                SqlDataSource3.SelectCommand = "SELECT [Avatar], [Nome] from [ViewFriends] WHERE ([ProfileIDA]=" + ProfileIDA.ID + " AND [Estado]='feito')";
                SqlDataSource4.SelectCommand = "SELECT [Avatar], [Nome] from [ViewRequest] WHERE ([ProfileIDB]=" + ProfileIDA.ID + " AND [Estado]='pendente')";

                GridView2.DataBind();
                GridView3.DataBind();
            }
            
            
            if (!Page.IsPostBack)
            {
                Session.Add("lista", listtag); 
            }
        else
            listtag = (List<string>)Session.Contents["lista"];

            sugestoes();

            }
        

        protected void Button1_Click(object sender, EventArgs e)
        {
            

            SqlDataSource1.SelectCommand = "SELECT [Nome] ,[Nick], [Avatar], [Premium] FROM [TProfile] WHERE ([Nome] LIKE '%" + TextBox1.Text + "%')";
            GridView1.DataBind();

           
        }
        protected void CheckedChanged(object sender, EventArgs e)
        {
            CheckBox CheckBox;
            
            CheckBox = (CheckBox)sender;

            HyperLink l1 = (HyperLink)GridView1.SelectedRow.Cells[0].FindControl("Lknome1");
            string nome = l1.Text;
            Rede.Perfil ProfileIDB = Rede.Perfil.LoadByName(nome);

            ProfileIDB.Premium = CheckBox.Checked;
            ProfileIDB.Save();
            
        }

        protected void RowCreated(object sender, System.Web.UI.WebControls.GridViewRowEventArgs e)
        {
                if (System.Web.HttpContext.Current.User.IsInRole("Administrador"))
                {
                    if (e.Row.RowType == DataControlRowType.DataRow)
                    {
                        CheckBox cmdChk = (CheckBox)e.Row.FindControl("CheckBox1");
                        cmdChk.Visible = true;
                        
                    }      
                }
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            HyperLink l1 = (HyperLink)GridView1.SelectedRow.Cells[0].FindControl("Lknome1");
            string nome = l1.Text;
            Rede.Perfil ProfileIDB = Rede.Perfil.LoadByName(nome);

            MembershipUser currentLoggedInUser = Membership.GetUser();
            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
            Rede.Perfil ProfileIDA = Rede.Perfil.LoadByUserId(id);

            if (ProfileIDA.ID != ProfileIDB.ID)
            {
                Rede.Relacao rel = new Rede.Relacao();
                rel.ProfileIDA = ProfileIDA.ID;
                rel.ProfileIDB = ProfileIDB.ID;
                rel.Forca = Convert.ToInt32(DropDownForca.SelectedValue);
                rel.TagList = this.listtag;
                rel.Estado= "pendente";
                rel.Save();
             }
            GridView2.DataBind();

        }

        protected void Button3_Click(object sender, EventArgs e)
        {

            string tag = TextBoxTag.Text;
            
            this.listtag.Add(tag);

            DropDownTags.DataSource = this.listtag;
            DropDownTags.DataBind();
        }


        protected void GridView3_SelectedIndexChanged(object sender, EventArgs e)
        {
            
            HyperLink l1 = (HyperLink)GridView3.SelectedRow.Cells[1].FindControl("Lknome1");
            string name = l1.Text;
            MembershipUser currentLoggedInUser = Membership.GetUser();
            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
            Rede.Perfil this_user = Rede.Perfil.LoadByUserId(id);
            Rede.Perfil ProfileIDB = Rede.Perfil.LoadByName(name);
            Rede.Relacao.RemoveRelashionship(this_user.ID, ProfileIDB.ID);

            GridView3.DataBind();
        }


        

        protected void Button4_Click(object sender, EventArgs e)
        {
            string tag = TextBoxTag0.Text;

            this.listtag_aceitar.Add(tag);

            DropDownTags0.DataSource = this.listtag_aceitar;
            DropDownTags0.DataBind();
        }
      
    
    protected void Aceitar_Click(object sender, EventArgs e)
        {
            HyperLink l1 = (HyperLink)GridView4.SelectedRow.Cells[1].FindControl("Lknome1");
            string name = l1.Text;
            MembershipUser currentLoggedInUser = Membership.GetUser();
            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
            //perfis
            Rede.Perfil this_user = Rede.Perfil.LoadByUserId(id);
            Rede.Perfil Request_Perfil = Rede.Perfil.LoadByName(name);
            //relacoes 
            Rede.Relacao request_update = Rede.Relacao.LoadByRelacao(Request_Perfil.ID, this_user.ID);

            request_update.Estado = "feito";
            request_update.Save();

            Rede.Relacao request_insert = new Rede.Relacao();
            request_insert.ProfileIDA = this_user.ID;
            request_insert.ProfileIDB = Request_Perfil.ID;
            request_insert.Forca = Convert.ToInt32(DropDownForca0.SelectedValue);
            request_insert.TagList = listtag_aceitar;
            request_insert.Estado = "feito";
            request_insert.Save();



            //SqlDataSource3.DeleteCommand = "DELETE from [TRelacao] WHERE [ProfileIDA]=" + this_user.ID + " AND [ProfileIDB]=" + ProfileIDB.ID;
            GridView3.DataBind();
            GridView4.DataBind();
        }
    protected void Rejeitar_Click(object sender, EventArgs e)
    {
        HyperLink l1 = (HyperLink)GridView4.SelectedRow.Cells[1].FindControl("Lknome1");
        string name = l1.Text;
        MembershipUser currentLoggedInUser = Membership.GetUser();
        string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
        Rede.Perfil this_user = Rede.Perfil.LoadByUserId(id);
        Rede.Perfil ProfileIDB = Rede.Perfil.LoadByName(name);
        Rede.Relacao.RemoveRelashionship(ProfileIDB.ID,this_user.ID);


        //SqlDataSource3.DeleteCommand = "DELETE from [TRelacao] WHERE [ProfileIDA]=" + this_user.ID + " AND [ProfileIDB]=" + ProfileIDB.ID;
        GridView4.DataBind();
    }

    protected void sugestoes()
    {
        Service a = new Service();
        Guid userGuid = (Guid)Membership.GetUser().ProviderUserKey;
        String userID = userGuid.ToString();
        Rede.Perfil prof = Rede.Perfil.LoadByUserId(userID);
        int profileID = 0;
        if (prof == null)
        {
            prof = new Rede.Perfil(userID);
            prof.Save();
        }
        profileID = Rede.Perfil.LoadProfileIDByUserId(userID);
        if (profileID == 0)
        {
        }
        else
        {
            //a.sugereAmigos(profileID);

            String res = a.sugereAmigos(profileID);
            sugere_amigos(res);

            Dictionary<string, List<string>> dictionary = dicUserTag(res);

            foreach (var entry in dictionary)
            {
                //Console.WriteLine(entry.Key);
                TableRow tr = new TableRow();
                TableCell tcNome = new TableCell();
                TableCell tcNick = new TableCell();
                TableCell tcTags = new TableCell();

                String nome = Rede.Perfil.LoadNameByProfileId(Convert.ToInt32(entry.Key));
                String nick = Rede.Perfil.LoadNickByProfileId(Convert.ToInt32(entry.Key));

                //tc1.Text = entry.Key;
                tcNome.Text = nome;
                tcNick.Text = nick;

                CheckBox check = new CheckBox();
                check.ID = entry.Key;

                //Button b = new Button();
                //b.OnClientClick = "convidar";
                //b.ID = "convidar"+entry.Key;
                //b.Text = "Convidar";
                //b.Click += b_Click;

                String tags = "";
                foreach (var tag in entry.Value)
                {
                    if (tags.Equals(""))
                        tags = tag;
                    else
                        tags += ", " + tag;
                }
                tcTags.Text = tags;


                tr.Cells.Add(tcNome);
                tr.Cells.Add(tcNick);
                tr.Cells.Add(tcTags);

                TableCell tcBtn = new TableCell();
                tcBtn.Controls.Add(check);
                tr.Cells.Add(tcBtn);
                Table1.Rows.Add(tr);

            }
        }
    }
    void b_Click(object sender, EventArgs e)
    {

        lblTags.Text = "Convite enviado com sucesso!";
        lblTags.ForeColor = System.Drawing.Color.Blue;
    }


    private static void sugere_amigos(String res)
    {
        Dictionary<string, List<string>> dictionary = dicUserTag(res);
        foreach (var entry in dictionary)
        {
            Console.WriteLine(entry.Key);

            foreach (var tag in entry.Value)
                Console.WriteLine(tag);
        }
    }

    //cria um dicionário com o user e as suas tags
    private static Dictionary<string, List<string>> dicUserTag(String res)
    {
        List<string> texto = res.Split(',').ToList<string>();
        Dictionary<string, List<string>> dictionary = new Dictionary<string, List<string>>();

        for (int i = 0; i < texto.Count - 1; i++)
        {
            List<string> testeUser = texto[i].ToString().Split('[').ToList<string>();
            String testeTag = testeUser[1].ToString().Split(']')[0];
            //Console.WriteLine("tag teste -> "+testeTag);

            if (!dictionary.ContainsKey(testeUser[0].ToString()))
            {
                dictionary.Add(testeUser[0].ToString(), new List<String>());
                if (!dictionary[testeUser[0].ToString()].Contains(testeTag))
                    dictionary[testeUser[0].ToString()].Add(testeTag);
            }
            else
            {
                if (!dictionary[testeUser[0].ToString()].Contains(testeTag))
                    dictionary[testeUser[0].ToString()].Add(testeTag);
            }
        }
        return dictionary;
    }

    protected void Button4_Click1(object sender, EventArgs e)
        {
            bool flag = false;
            foreach (Control control in Table1.Controls)
            {
                if (control is TableRow)
                {
                    foreach (TableCell cell in control.Controls)
                    {
                        if (!(cell is TableHeaderCell))
                        {
                            foreach (Control c in cell.Controls)
                            {
                                if (((CheckBox)c).Checked == true)
                                {
                                    ((CheckBox)c).Checked = false;
                                    flag = true;
                                    try
                                    {
                                        /*----*/

                                        Rede.Perfil ProfileIDB = Rede.Perfil.LoadByProfileId(c.ID);

                                        MembershipUser currentLoggedInUser = Membership.GetUser();
                                        string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
                                        Rede.Perfil ProfileIDA = Rede.Perfil.LoadByUserId(id);



                                        if (ProfileIDA.ID != ProfileIDB.ID)
                                        {
                                            //se já existe relação nao faz o convite
                                            if (Rede.Relacao.VerificaSeExisteRelacao(ProfileIDA.ID, ProfileIDB.ID))
                                            {
                                                lblTags.Text = "Já efectuou estes convites antes! Tem que aguardar a respotas dos convidados.";
                                                lblTags.ForeColor = System.Drawing.Color.Red;
                                            }else{
                                                /*cria relação*/
                                                Rede.Relacao rel = new Rede.Relacao();
                                                rel.ProfileIDA = ProfileIDA.ID;
                                                rel.ProfileIDB = ProfileIDB.ID;
                                                rel.Forca = Convert.ToInt32(1);

                                                rel.TagList = null;
                                                rel.Estado = "pendente";
                                                rel.Save();

                                                lblTags.Text = "Convites enviados com sucesso! Aguarde a aceitação do pedido.";
                                                lblTags.ForeColor = System.Drawing.Color.Blue;
                                            }
                                        }
                                        
                                    }
                                    catch (Exception exc)
                                    {
                                        lblTags.Text = "Surgiu um problema no envio dos convites. Tente novamente mais tarde.";
                                        lblTags.ForeColor = System.Drawing.Color.Red;
                                    }
                                    /*----*/
                                }
                            }
                        }
                    }
                }
            }
            if (flag==false)
                lblTags.Text = "Deve primeiro seleccionar os utilizadores que pretende convidar!";
                lblTags.ForeColor = System.Drawing.Color.Red;
        }

}