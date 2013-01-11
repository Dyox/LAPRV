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
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" Runat="Server">
    <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Nome" Width="95px"></asp:Label>
    <asp:TextBox ID="TextNome" runat="server"></asp:TextBox>
    <asp:Label ID="Label6" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Facebook" Width="95px"></asp:Label>
    <asp:TextBox ID="TextFace" runat="server"></asp:TextBox>
    <asp:Label ID="Label2" runat="server" Font-Bold="True" Font-Size="Medium" Height="39px" Text="Data Nascimento" Width="95px"></asp:Label>
    <asp:TextBox ID="TextData" runat="server"></asp:TextBox>
    <asp:Label ID="Label5" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Linkedin" Width="95px"></asp:Label>
    <asp:TextBox ID="TextLinkedin" runat="server"></asp:TextBox>
    <asp:Label ID="Label3" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Morada" Width="95px"></asp:Label>
    <asp:TextBox ID="TextMorada" runat="server"></asp:TextBox>
    <asp:Label ID="Label7" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Humor" Width="95px"></asp:Label>
    <asp:Label ID="Label4" runat="server" Font-Bold="True" Font-Size="Medium" Height="35px" Text="Tlm." Width="95px"></asp:Label>
    <asp:TextBox ID="TextTlm" runat="server"></asp:TextBox>
    <img id="avatarIMG" alt="" class="auto-style1" runat="server"  /><asp:Label ID="Label9" runat="server" Text="Nick" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px"></asp:Label>
    <asp:TextBox ID="TextNick" runat="server"></asp:TextBox>
    <asp:Label ID="Label10" runat="server" Text="Tags" Font-Bold="True" Font-Size="Medium" Height="35px" Width="95px"></asp:Label>
    <asp:DropDownList ID="DropDownList2" runat="server" DataSourceID="SqlDataSource2" DataTextField="Designacao" DataValueField="Designacao">
    </asp:DropDownList>
</asp:Content>

