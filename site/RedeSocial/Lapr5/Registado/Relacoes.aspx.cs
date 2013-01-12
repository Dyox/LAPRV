using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Registado_Relacoes : System.Web.UI.Page
    {
        private List<string> listtag= new List<string>();
        private List<string> listtag_aceitar = new List<string>();

        protected void Page_Load(object sender, EventArgs e)
        {
            Aceitar.Enabled = false;
            Rejeitar.Enabled = false;
            MembershipUser currentLoggedInUser = Membership.GetUser();
            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
            Rede.Perfil ProfileIDA = Rede.Perfil.LoadByUserId(id);
            
            SqlDataSource2.SelectCommand="SELECT [Avatar], [Nome], [Estado] from [ViewFriends] WHERE ([ProfileIDA]=" + ProfileIDA.ID+" AND [Estado]='pendente')";

            SqlDataSource3.SelectCommand = "SELECT [Avatar], [Nome] from [ViewFriends] WHERE ([ProfileIDA]=" + ProfileIDA.ID + " AND [Estado]='feito')";
            SqlDataSource4.SelectCommand = "SELECT [Avatar], [Nome] from [ViewRequest] WHERE ([ProfileIDB]=" + ProfileIDA.ID + " AND [Estado]='pendente')";

            GridView2.DataBind();
            GridView3.DataBind();
            
            
            
            if (!Page.IsPostBack)
            {
                Session.Add("lista", listtag); 
            }
        else
            listtag = (List<string>)Session.Contents["lista"];

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

            string nome = GridView1.SelectedRow.Cells[0].Text;
            Rede.Perfil ProfileIDB = Rede.Perfil.LoadByName(nome);

            ProfileIDB.Premium = CheckBox.Checked;
            ProfileIDB.Save();
            //ja altera na bd, esta OK

        }

        protected void RowCreated(object sender, System.Web.UI.WebControls.GridViewRowEventArgs e)
        {
                if (System.Web.HttpContext.Current.User.IsInRole("Administrador"))
                {
                    //parte do admin, com bugs
                    if (e.Row.RowType == DataControlRowType.DataRow)
                    {
                        CheckBox cmdChk = (CheckBox)e.Row.FindControl("CheckBox1");
                        cmdChk.Visible = true;
                    }      
            }
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            string nome = GridView1.SelectedRow.Cells[0].Text;
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
            string name = GridView3.SelectedRow.Cells[1].Text;
            MembershipUser currentLoggedInUser = Membership.GetUser();
            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
            Rede.Perfil this_user = Rede.Perfil.LoadByUserId(id);
            Rede.Perfil ProfileIDB = Rede.Perfil.LoadByName(name);
            Rede.Relacao.RemoveRelashionship(this_user.ID, ProfileIDB.ID);


            //SqlDataSource3.DeleteCommand = "DELETE from [TRelacao] WHERE [ProfileIDA]=" + this_user.ID + " AND [ProfileIDB]=" + ProfileIDB.ID;
            GridView3.DataBind();
        }


        protected void GridView4_SelectedIndexChanged(object sender, EventArgs e)
        {
            Aceitar.Enabled = true;
            Rejeitar.Enabled = true;
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
            string name = GridView4.SelectedRow.Cells[1].Text;
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
        string name = GridView4.SelectedRow.Cells[1].Text;
        MembershipUser currentLoggedInUser = Membership.GetUser();
        string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
        Rede.Perfil this_user = Rede.Perfil.LoadByUserId(id);
        Rede.Perfil ProfileIDB = Rede.Perfil.LoadByName(name);
        Rede.Relacao.RemoveRelashionship(ProfileIDB.ID,this_user.ID);


        //SqlDataSource3.DeleteCommand = "DELETE from [TRelacao] WHERE [ProfileIDA]=" + this_user.ID + " AND [ProfileIDB]=" + ProfileIDB.ID;
        GridView4.DataBind();
    }
}