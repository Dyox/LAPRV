using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Rede;
using System.Text;
using System.Web.Security;
using System.Data;

    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //ServiceReference2.ServiceClient proxy = new ServiceReference2.ServiceClient();
            //Service a = new Service();
            //int li = a.validateLogin("RafaUser", "qwert");
            Dimensao_rede();
            Cloud_taguser();
            Cloud_tagrelacao();
            ContarAmizades();
        }

        protected void Cloud_tagrelacao()
        {
            List<string> lst = Rede.Tag.TagCloudRel();

            var tags = (from l in lst
                        group l by l into g
                        select new { Name = g.Key, Count = g.Count() });

            // Sort tags in descending order
            tags = (from t in tags
                    orderby t.Name ascending
                    select t);

            //Minimum Size for Tags, you can set it as per your need
            double minSize = 8;

            //Maximum Size for Tags, you can set it as per your need
            double maxSize = 42;

            //Calculating the step in which increament the fonts
            double steps = (maxSize - minSize) / (double)tags.Count();

            StringBuilder sb = new StringBuilder();
            foreach (var tag in tags)
            {
                //Calculating the Size
                double size = minSize + ((double)tag.Count - 1) * steps;

                //Create the SPAN tag with spefic font size so it looks like cloud
                sb.Append("<span style='font-size:" + size + "pt'>" + tag.Name + " </span>");
            }

            Labelcloudrel.Text = sb.ToString();
        }


        protected void Dimensao_rede()
        {

            int registados = Rede.Perfil.get_UsersRegistados();
            nusers.Text = " " + registados + "";
        }

        protected void Cloud_taguser()
        {
            List<string> lst = Rede.Tag.TagUser();

            var tags = (from l in lst
                        group l by l into g
                        select new { Name = g.Key, Count = g.Count() });

            // Sort tags in descending order
            tags = (from t in tags
                    orderby t.Name descending
                    select t);

            //Minimum Size for Tags, you can set it as per your need
            double minSize = 8;

            //Maximum Size for Tags, you can set it as per your need
            double maxSize = 42;

            //Calculating the step in which increament the fonts
            double steps = (maxSize - minSize) / (double)tags.Count();

            StringBuilder sb = new StringBuilder();
            foreach (var tag in tags)
            {
                //Calculating the Size
                int size = Convert.ToInt32(minSize + ((double)tag.Count) * steps);



                sb.Append("<span style='font-size:" + size + "pt'>" + tag.Name + " </span>");
            }

            Labelclouduser.Text = sb.ToString();
        }
        protected void ContarAmizades()
        {
            if (System.Web.HttpContext.Current.User.Identity.IsAuthenticated)
            {
            MembershipUser currentLoggedInUser = Membership.GetUser();
            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
            Rede.Perfil ProfileIDA = Rede.Perfil.LoadByUserId(id);
            if (ProfileIDA == null)
            {
                namigosp.Text = "Não tem o perfil criado";
            }
            else
            {
                SqlDataSource1.SelectCommand = "SELECT * from [ViewFriends] WHERE ([Nome]='" + ProfileIDA.Name + "' AND [Estado]='Pendente')";
                DataView dvSql = (DataView)SqlDataSource1.Select(DataSourceSelectArguments.Empty);
                namigosp.Text = "Tem " + dvSql.Count.ToString() + " Amizades Pendentes.";
            }
            Download.Text = "Download da aplicação";

            }
        }

    }
