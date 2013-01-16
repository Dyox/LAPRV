<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>


<asp:Content runat="server" ID="FeaturedContent" ContentPlaceHolderID="FeaturedContent">
    <section class="featured">
        <div class="auto-style3">
            <p>
                <img alt="Royal Solution" class="auto-style2" src="Images/royal.jpg" /></p>
        </div>
    </section>
</asp:Content>

<asp:Content runat="server" ID="BodyContent" ContentPlaceHolderID="MainContent">
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>">
    </asp:SqlDataSource>
    <ol class="round">
        <li >
            <h5><a href="Registado\Relacoes.aspx"><asp:Label ID="namigosp" runat="server" meta:resourcekey="namigospResource1"></asp:Label></a></h5>
            <h5><a href="Registado\RoyalSolutions.exe"><asp:Label ID="Download" runat="server"> </asp:Label> </a></h5>
        </li>
    </ol>

    <ol class="round">
        <li class="one">
            <h5>Utilizadores Registados:&nbsp;&nbsp;&nbsp; <asp:Label ID="nusers" runat="server" Text="Label" meta:resourcekey="nusersResource1"></asp:Label>
&nbsp;&nbsp;&nbsp; </h5>
        </li>
    </ol>
    <ol class="round">
        <li class="two">
            <h5 id="Clouduser">Cloud Tags users:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <asp:Label ID="Labelclouduser" runat="server" Text="Label" meta:resourcekey="LabelclouduserResource1"></asp:Label>
            </h5>
        </li>
    </ol>
    <ol class="round">
        <li class="three">
            <h5>Cloud Tags Relacoes:&nbsp;&nbsp;&nbsp;
                <asp:Label ID="Labelcloudrel" runat="server" Text="Label" meta:resourcekey="LabelcloudrelResource1"></asp:Label>
            </h5>
        </li>
    </ol>
     <ol class="round">
        <li class="four">
    <asp:Label ID="lb_maven" runat="server" Text="Obter o Maven de uma deter minada Tag"></asp:Label>
        <asp:TextBox ID="txt_maven" runat="server"></asp:TextBox>
         <asp:Button ID="bt_maven" runat="server" Text="Obter Maven" />
        <asp:Label ID="lb_resultado_maven" runat="server"></asp:Label>
</li>
    </ol>
    <h5>&nbsp;</h5>
</asp:Content>
<asp:Content ID="Content1" runat="server" contentplaceholderid="HeadContent">
    <style type="text/css">
        .auto-style2
        {
            width: 950px;
            height: 150px;
        }
        .auto-style3
        {
            max-width: 960px;
            height: 158px;
            width: 954px;
            margin: 0 auto;
            padding-left: 10px;
            padding-right: 10px;
        }
    </style>
</asp:Content>

