<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true"  CodeBehind="Default.aspx.cs" Inherits="RedeSocial._Default" culture="auto" meta:resourcekey="PageResource1" uiculture="auto" %>


<asp:Content runat="server" ID="FeaturedContent" ContentPlaceHolderID="FeaturedContent">
    <section class="featured">
        <div class="content-wrapper">
            <hgroup class="title">
                <h1><%: Title %>.</h1>
                <h2>Modify this template to jump-start your ASP.NET application.</h2>
            </hgroup>
            <p>
                To learn more about ASP.NET, visit <a href="http://asp.net" title="ASP.NET Website">http://asp.net</a>.
                The page features <mark>videos, tutorials, and samples</mark> to help you get the most from ASP.NET.
                If you have any questions about ASP.NET visit
                <a href="http://forums.asp.net/18.aspx" title="ASP.NET Forum">our forums</a>.
            </p>
        </div>
    </section>
</asp:Content>

<asp:Content runat="server" ID="BodyContent" ContentPlaceHolderID="MainContent">
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>">
    </asp:SqlDataSource>
    <ol class="round">
        <li >
            <h5><a href="Registado\Relacoes.aspx"><asp:Label ID="namigosp" runat="server" meta:resourcekey="namigospResource1"></asp:Label></a></h5>
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
    <h5>&nbsp;</h5>
</asp:Content>
