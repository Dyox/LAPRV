﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using Rede;
using System.IO; // this is for the file upload
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;

public partial class Registado_Perfil : System.Web.UI.Page
{
        protected void Page_Load(object sender, EventArgs e)
        {
            TextNome.Enabled = false;
            TextMorada.Enabled = false;
            TextData.Enabled = false;
            TextLinkedin.Enabled = false;
            TextFace.Enabled = false;
            TextNick.Enabled = false;
            TextTlm.Enabled = false;
            DropDownList1.Enabled = false;
            TextTag.Enabled = false;
            //uploadButton0.Enabled = false;
            uploadButton.Enabled = false;
            Button5.Enabled = false;
            DropDownList3.Enabled = false;

            MembershipUser currentLoggedInUser = Membership.GetUser();
            
            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);

            Rede.Perfil prof = Rede.Perfil.LoadByUserId(id);
            if (prof == null)
            {

                prof = new Rede.Perfil(id, currentLoggedInUser.UserName);
                prof.Save();
            }

            if (!Page.IsPostBack)
            {
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
                DropDownList3.SelectedValue = prof.avatar3D;
                DropDownList1.SelectedValue = Convert.ToString(prof.humor.ID);
                SqlDataSource2.SelectParameters["ProfileID"].DefaultValue = Convert.ToString(prof.ID);
            }
            

        }


        protected void Button3_Click(object sender, EventArgs e)
        {
            TextNome.Text = "";
            TextMorada.Text = "";
            TextData.Text = "";
            TextLinkedin.Text = "";
            TextFace.Text = "";
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            MembershipUser currentLoggedInUser = Membership.GetUser();

            string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
            Rede.Perfil prof = Rede.Perfil.LoadByUserId(id);
            
            prof.Nick = TextNick.Text;
            prof.Name = TextNome.Text;
            prof.Morada = TextMorada.Text;
            prof.FaceBook = TextFace.Text;
            if (TextData.Text== "")
            {
                prof.DataNascimento = Convert.ToDateTime(1900-01-01);
                Label13.Text = "Não inseriu a data de nacimento";
            }
            else
                prof.DataNascimento = Convert.ToDateTime(TextData.Text);
            prof.Linkedin = TextLinkedin.Text;
            Rede.Humor h = Rede.Humor.LoadById(Convert.ToInt32(DropDownList1.SelectedValue));
            prof.humor = h;
            prof.Telemovel = Convert.ToInt32(TextTlm.Text);
            prof.avatar3D = DropDownList3.SelectedValue;
            prof.avatar = avatarIMG.Src;
            prof.Save();

        }

        protected void Button4_Click(object sender, EventArgs e)
        {
            TextNome.Enabled = true;
            uploadButton.Enabled = true;
            //uploadButton0.Enabled = true;
            Button5.Enabled = true;
            TextMorada.Enabled = true;
            TextData.Enabled = true;
            TextLinkedin.Enabled = true;
            TextFace.Enabled = true;
            TextNick.Enabled = true;
            TextTlm.Enabled = true;
            Button3.Visible = true;
            DropDownList1.Enabled = true;
            DropDownList3.Enabled = true;
            TextTag.Enabled = true;
        }


        protected void UploadFile(Object s, EventArgs e)
        {
            // First we check to see if the user has selected a file
            if (UploadAvatar.HasFile)
            {
                // Find the fileUpload control
                string filename = UploadAvatar.FileName;

                // Check if the directory we want the image uploaded to actually exists or not
                if (!Directory.Exists(MapPath(@"Avatar")))
                {
                    // If it doesn't then we just create it before going any further
                    Directory.CreateDirectory(MapPath(@"Avatar"));
                }

                // Specify the upload directory
                string directory = Server.MapPath(@"Avatar\");
                //imglabel.Text = directory;
                
                // Create a bitmap of the content of the fileUpload control in memory
                Bitmap originalBMP = new Bitmap(UploadAvatar.FileContent);

                // Calculate the new image dimensions
                int origWidth = originalBMP.Width;
                int origHeight = originalBMP.Height;
                int sngRatio = origWidth / origHeight;
                int newWidth = 100;
                int newHeight = 100;//newWidth / sngRatio;

                // Create a new bitmap which will hold the previous resized bitmap
                Bitmap newBMP = new Bitmap(originalBMP, newWidth, newHeight);
                // Create a graphic based on the new bitmap
                Graphics oGraphics = Graphics.FromImage(newBMP);

                // Set the properties for the new graphic file
                oGraphics.SmoothingMode = SmoothingMode.AntiAlias; oGraphics.InterpolationMode = InterpolationMode.HighQualityBicubic;
                // Draw the new graphic based on the resized bitmap
                oGraphics.DrawImage(originalBMP, 0, 0, newWidth, newHeight);

                // Save the new graphic file to the server
                newBMP.Save(directory + filename);

                // Once finished with the bitmap objects, we deallocate them.
                originalBMP.Dispose();
                newBMP.Dispose();
                oGraphics.Dispose();

                // Write a message to inform the user all is OK
                imglabel.Text = "File Name: <b style='color: red;'>" + filename + "</b><br>";
                // Display the image to the user
                avatarIMG.Visible = true;
             
                avatarIMG.Src = @"/Lapr5/Registado/Avatar/" + filename;
            }
            else
            {
                imglabel.Text = "No file uploaded!";
            }
        }

        protected void Button5_Click(object sender, EventArgs e)
        {
            string tag = TextTag.Text;
            if (tag != "")
            {
                bool existe = Rede.Tag.ExisteTag(tag);

                if (existe == false)
                {
                    Rede.Tag t = new Rede.Tag(tag);
                    t.Save();


                }


                Rede.Tag t2 = Rede.Tag.LoadByName(tag);
                MembershipUser currentLoggedInUser = Membership.GetUser();
                string id = Convert.ToString(currentLoggedInUser.ProviderUserKey);
                Rede.Perfil p = Rede.Perfil.LoadByUserId(id);
                Rede.Tag.insereRelacao(p.ID, t2.ID);
                DropDownList2.DataBind();

            }
        }



        //protected void UploadFile3D(Object s, EventArgs e)
        //{
        //    // First we check to see if the user has selected a file
        //    if (UploadAvatar3D.HasFile)
        //    {
        //        // Find the fileUpload control
        //        string filename = UploadAvatar3D.FileName;
                
        //        // Check if the directory we want the image uploaded to actually exists or not
        //        if (!Directory.Exists(MapPath(@"Avatar3D")))
        //        {
        //            // If it doesn't then we just create it before going any further
        //            Directory.CreateDirectory(MapPath(@"Avatar3D"));
        //        }

        //        // Specify the upload directory

        //        if (UploadAvatar3D.PostedFile.ContentType == "application/x-3ds" || UploadAvatar3D.PostedFile.ContentType == "application/octet-stream")
        //        {
        //            if (UploadAvatar3D.PostedFile.ContentLength < 8485760)
        //            {

        //                string directory = Server.MapPath(@"Avatar3D\");
        //                UploadAvatar3D.SaveAs(directory + filename);
        //                lblfile.Text = filename;
        //                StatusLabel.Text = "Upload status: File uploaded!";

        //            }
        //            else
        //                StatusLabel.Text = "Upload status: The file has to be less than 8 Mb!";
        //            }
        //            else
        //                StatusLabel.Text = "Upload status: Only 3DS, OBJ files are accepted!";           

        //        }
        //    }
        }

