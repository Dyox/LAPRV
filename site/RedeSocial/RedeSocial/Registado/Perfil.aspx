<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Perfil.aspx.cs" Inherits="RedeSocial.Registado.Perfil" %>
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
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" runat="server">
    <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Nome" Width="95px"></asp:Label>
<asp:TextBox ID="TextNome" runat="server"></asp:TextBox>
&nbsp;
&nbsp;&nbsp;&nbsp;
<asp:Label ID="Label6" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Facebook" Width="95px"></asp:Label>
<asp:TextBox ID="TextFace" runat="server"></asp:TextBox>
<br />
<asp:Label ID="Label2" runat="server" Font-Bold="True" Font-Size="Medium" Height="39px" Text="Data Nascimento" Width="95px"></asp:Label>
<asp:TextBox ID="TextData" runat="server"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<asp:Label ID="Label5" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Linkedin" Width="95px"></asp:Label>
<asp:TextBox ID="TextLinkedin" runat="server"></asp:TextBox>
<br />
<asp:Label ID="Label3" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Morada" Width="95px"></asp:Label>
<asp:TextBox ID="TextMorada" runat="server"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<asp:Label ID="Label7" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Humor" Width="95px"></asp:Label>
    <asp:DropDownList ID="DropDownList1" runat="server" DataSourceID="SqlDataSource1" DataTextField="Designacao" DataValueField="HumorID" >
    </asp:DropDownList>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>" SelectCommand="SELECT * FROM [THumor]"></asp:SqlDataSource>
<br />
<asp:Label ID="Label4" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Tlm." Width="95px"></asp:Label>
<asp:TextBox ID="TextTlm" runat="server"></asp:TextBox>
&nbsp;&nbsp;&nbsp;
<asp:Label ID="Label8" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Avatar" Width="95px"></asp:Label>
    <asp:FileUpload ID="UploadAvatar" runat="server" />
    <img id="avatarIMG" alt="" class="auto-style1" runat="server"  />
    <br />
    <asp:Label ID="Label9" runat="server" Text="Nick" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px"></asp:Label>
    <asp:TextBox ID="TextNick" runat="server"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:Button ID="uploadButton" runat="server" Text="Upload!" OnClick="UploadFile" CssClass="auto-style2" />
    &nbsp;<asp:Label ID="imglabel" runat="server"></asp:Label>
    &nbsp;<br />
    <br />
    <asp:Label ID="Label10" runat="server" Text="Tags" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px"></asp:Label>
    <asp:DropDownList ID="DropDownList2" runat="server" DataSourceID="SqlDataSource2" DataTextField="Designacao" DataValueField="Designacao">
    </asp:DropDownList>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:Label ID="Label11" runat="server" Text="Add Tags" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px"></asp:Label>
    <asp:TextBox ID="TextTag" runat="server"></asp:TextBox>
&nbsp;&nbsp;
    <asp:Button ID="Button5" runat="server" OnClick="Button5_Click" Text="Adicionar" />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>" SelectCommand="SELECT [Designacao] FROM [ViewTagsUser] WHERE ([ProfileID] = @ProfileID)">
        <SelectParameters>
            <asp:Parameter Name="ProfileID" Type="Int32" />
        </SelectParameters>
    </asp:SqlDataSource>
    <br />
    <br />
<br />
<asp:Button ID="Button2" runat="server" Text="Enviar" OnClick="Button2_Click" />
<asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="Limpar" Visible="False" />
    <asp:Button ID="Button4" runat="server" OnClick="Button4_Click" Text="Editar" />
<br />
<br />
</asp:Content>
