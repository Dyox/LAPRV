<%@ Page MasterPageFile="~/Site.Master" Language="C#" AutoEventWireup="true" CodeFile="Perfil.aspx.cs" Inherits="Registado_Perfil" culture="auto" meta:resourcekey="PageResource1" uiculture="auto" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
    <style type="text/css">
        .auto-style1
        {
            width: 100px;
            height: 100px;
        }
        .auto-style2
        {
            margin-top: 5px;
        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="FeaturedContent" runat="server">
    <p>
        <asp:Image ID="Image1" runat="server" ImageUrl="~/Images/Premium.png" meta:resourcekey="Image1Resource1" />
</p>
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" runat="server">
    <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Nome" Width="95px" meta:resourcekey="Label1Resource1"></asp:Label>
<asp:TextBox ID="TextNome" runat="server" meta:resourcekey="TextNomeResource1"></asp:TextBox>
&nbsp;
&nbsp;&nbsp;&nbsp;
<asp:Label ID="Label6" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Facebook" Width="95px" meta:resourcekey="Label6Resource1"></asp:Label>
<asp:TextBox ID="TextFace" runat="server" meta:resourcekey="TextFaceResource1"></asp:TextBox>
<br />
<asp:Label ID="Label2" runat="server" Font-Bold="True" Font-Size="Medium" Height="39px" Text="Data Nascimento" Width="95px" meta:resourcekey="Label2Resource1"></asp:Label>
<asp:TextBox ID="TextData" runat="server" meta:resourcekey="TextDataResource1"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<asp:Label ID="Label5" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Linkedin" Width="95px" meta:resourcekey="Label5Resource1"></asp:Label>
<asp:TextBox ID="TextLinkedin" runat="server" meta:resourcekey="TextLinkedinResource1"></asp:TextBox>
<br />
<asp:Label ID="Label3" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Morada" Width="95px" meta:resourcekey="Label3Resource1"></asp:Label>
<asp:TextBox ID="TextMorada" runat="server" meta:resourcekey="TextMoradaResource1"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<asp:Label ID="Label7" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Humor" Width="95px" meta:resourcekey="Label7Resource1"></asp:Label>
    <asp:DropDownList ID="DropDownList1" runat="server" DataSourceID="SqlDataSource1" DataTextField="Designacao" DataValueField="HumorID" meta:resourcekey="DropDownList1Resource1" >
    </asp:DropDownList>
    <br />
    <asp:Label ID="Label13" runat="server" meta:resourcekey="Label13Resource1"></asp:Label>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>" SelectCommand="SELECT * FROM [THumor]"></asp:SqlDataSource>
    <br />
<asp:Label ID="Label12" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Avatar 3D" Width="95px" meta:resourcekey="Label12Resource1"></asp:Label>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:Label ID="StatusLabel" runat="server" meta:resourcekey="StatusLabelResource1"></asp:Label>
    <asp:Label ID="lblfile" runat="server" meta:resourcekey="lblfileResource1"></asp:Label>
<br />
<asp:Label ID="Label4" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Tlm." Width="95px" meta:resourcekey="Label4Resource1"></asp:Label>
<asp:TextBox ID="TextTlm" runat="server" meta:resourcekey="TextTlmResource1"></asp:TextBox>
&nbsp;&nbsp;&nbsp;
<asp:Label ID="Label8" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Avatar" Width="95px" meta:resourcekey="Label8Resource1"></asp:Label>
    <asp:FileUpload ID="UploadAvatar" runat="server" meta:resourcekey="UploadAvatarResource1" />
    <img id="avatarIMG" alt="" class="auto-style1" runat="server"  />
    <br />
    <asp:Label ID="Label9" runat="server" Text="Nick" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px" meta:resourcekey="Label9Resource1"></asp:Label>
    <asp:TextBox ID="TextNick" runat="server" meta:resourcekey="TextNickResource1"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:Button ID="uploadButton" runat="server" Text="Upload!" OnClick="UploadFile" CssClass="auto-style2" meta:resourcekey="uploadButtonResource1" />
    &nbsp;<asp:Label ID="imglabel" runat="server" meta:resourcekey="imglabelResource1"></asp:Label>
    &nbsp;<br />
    <br />
    <asp:Label ID="Label10" runat="server" Text="Tags" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px" meta:resourcekey="Label10Resource1"></asp:Label>
    <asp:DropDownList ID="DropDownList2" runat="server" DataSourceID="SqlDataSource2" DataTextField="Designacao" DataValueField="Designacao" meta:resourcekey="DropDownList2Resource1">
    </asp:DropDownList>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:Label ID="Label11" runat="server" Text="Add Tags" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px" meta:resourcekey="Label11Resource1"></asp:Label>
    <asp:TextBox ID="TextTag" runat="server" meta:resourcekey="TextTagResource1"></asp:TextBox>
&nbsp;&nbsp;
    <asp:Button ID="Button5" runat="server" OnClick="Button5_Click" Text="Adicionar" meta:resourcekey="Button5Resource1" />

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>" SelectCommand="SELECT [Designacao] FROM [ViewTagsUser] WHERE ([ProfileID] = @ProfileID)">
        <SelectParameters>
            <asp:Parameter Name="ProfileID" Type="Int32" />
        </SelectParameters>
    </asp:SqlDataSource>
    <br />
    <br />
<br />
<asp:Button ID="Button2" runat="server" Text="Enviar" OnClick="Button2_Click" meta:resourcekey="Button2Resource1" />
<asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="Limpar" Visible="False" meta:resourcekey="Button3Resource1" />
    <asp:Button ID="Button4" runat="server" OnClick="Button4_Click" Text="Editar" meta:resourcekey="Button4Resource1" />
    <br />
    <br />
<br />
<br />
</asp:Content>
