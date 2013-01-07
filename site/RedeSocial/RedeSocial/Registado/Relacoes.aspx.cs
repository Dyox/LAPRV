using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace RedeSocial.Registado
{

    public partial class Relacoes : System.Web.UI.Page
    {
        private List<string> listtag= new List<string>();

        protected void Page_Load(object sender, EventArgs e)
        {
            MembershipUser currentLoggedInUser = Membership.GetUser();
            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
            Rede.Perfil ProfileIDA = Rede.Perfil.LoadByUserId(id);
            
            SqlDataSource2.SelectCommand="SELECT [Avatar], [Nome] from [ViewFriends] WHERE ([ProfileIDA]=" + ProfileIDA.ID+")";

            GridView2.DataBind();
            if (!Page.IsPostBack)
            {
                Session.Add("lista", listtag); 
            }
        else
            listtag = (List<string>)Session.Contents["lista"];

            }
        

        protected void Button1_Click(object sender, EventArgs e)
        {
            SqlDataSource1.SelectCommand = "SELECT [Nome] ,[Nick], [Avatar] FROM [TProfile] WHERE ([Nome] LIKE '%" + TextBox1.Text + "%')";
            GridView1.DataBind();
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
                rel.Estado= "Pendente";
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
    }
}
