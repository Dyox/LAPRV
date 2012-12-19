using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Rede;
using System.Text;

namespace RedeSocial
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Dimensao_rede();
            Cloud_taguser();
            Cloud_tagrelacao();

          

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
            double maxSize = 32;

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
            double minSize = 10;

            //Maximum Size for Tags, you can set it as per your need
            double maxSize = 26;

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

            Labelclouduser.Text = sb.ToString();
        }

    }
}