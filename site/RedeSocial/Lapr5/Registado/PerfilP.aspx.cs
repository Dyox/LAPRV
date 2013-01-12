using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Registado_PerfilP : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        string n = Request.QueryString["Nome"];
        LoadPerf(n);
    }
    protected void LoadPerf(string nome)
    {
        Rede.Perfil prof = Rede.Perfil.LoadByName(nome);

        if (prof.Premium)
                
                    Image1.Visible = true;
                
                else
                    Image1.Visible = false;

                TextNome.Text = prof.Name;
                TextNick.Text = prof.Nick;
                TextMorada.Text = prof.Morada;
                TextFace.Text = prof.FaceBook;
                TextData.Text = prof.DataNascimento.ToShortDateString();
                TextLinkedin.Text = prof.Linkedin;
                TextTlm.Text = prof.Telemovel.ToString();
                avatarIMG.Src = prof.avatar;
                TextHumor.Text = Convert.ToString(prof.humor.Designacao);
                SqlDataSource2.SelectParameters["ProfileID"].DefaultValue = Convert.ToString(prof.ID);
         }
    }
