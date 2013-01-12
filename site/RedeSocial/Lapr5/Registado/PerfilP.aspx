<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeFile="PerfilP.aspx.cs" Inherits="Registado_PerfilP" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" Runat="Server">
    <style type="text/css">

        .auto-style1
        {
            width: 100px;
            height: 100px;
        }
        </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="FeaturedContent" Runat="Server">
    <asp:Image ID="Image1" runat="server" ImageUrl="~/Images/Premium.png" />
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" Runat="Server">
    <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Nome" Width="95px"></asp:Label>
    <asp:Label ID="TextNome" runat="server"></asp:Label>
    <asp:Label ID="Label6" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Facebook" Width="95px"></asp:Label>
    <asp:Label ID="TextFace" runat="server"></asp:Label>
    <asp:Label ID="Label2" runat="server" Font-Bold="True" Font-Size="Medium" Height="39px" Text="Data Nascimento" Width="95px"></asp:Label>
    <asp:Label ID="TextData" runat="server"></asp:Label>
    <asp:Label ID="Label5" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Linkedin" Width="95px"></asp:Label>
    <asp:Label ID="TextLinkedin" runat="server"></asp:Label>
    <asp:Label ID="Label3" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Morada" Width="95px"></asp:Label>
    <asp:Label ID="TextMorada" runat="server"></asp:Label>
    <asp:Label ID="Label7" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Humor" Width="95px"></asp:Label>
    <asp:Label ID="TextHumor" runat="server"></asp:Label>
&nbsp;<asp:Label ID="Label4" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Tlm." Width="95px"></asp:Label>
    <asp:Label ID="TextTlm" runat="server"></asp:Label>
    <img id="avatarIMG" alt="" class="auto-style1" runat="server"  />
    <asp:Label ID="Label9" runat="server" Text="Nick" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px"></asp:Label>
    <asp:Label ID="TextNick" runat="server"></asp:Label>
    <asp:Label ID="Label10" runat="server" Text="Tags" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px"></asp:Label>
    <asp:DropDownList ID="DropDownList2" runat="server" DataSourceID="SqlDataSource2" DataTextField="Designacao" DataValueField="Designacao">
    </asp:DropDownList>
    <br />
    <br />
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>" SelectCommand="SELECT [Designacao] FROM [ViewTagsUser] WHERE ([ProfileID] = @ProfileID)">
        <SelectParameters>
            <asp:Parameter Name="ProfileID" Type="Int32" />
        </SelectParameters>
    </asp:SqlDataSource>
    <br />
</asp:Content>

