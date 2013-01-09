﻿<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="RedeSocial._Default" %>


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
        <li class="four" runat="Server" id="classF">
            <h5>Tem &nbsp; <asp:Label ID="namigosp" runat="server" Text=""></asp:Label> Amizades Pendentes.</h5>
        </li>
    </ol>

    <ol class="round">
        <li class="one">
            <h5>Dimensão da rede (Utilizadores Registados):&nbsp;&nbsp;&nbsp; <asp:Label ID="nusers" runat="server" Text="Label"></asp:Label>
&nbsp;&nbsp;&nbsp; </h5>
        </li>
    </ol>
    <ol class="round">
        <li class="two">
            <h5 id="Clouduser">Cloud users:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <asp:Label ID="Labelclouduser" runat="server" Text="Label"></asp:Label>
            </h5>
        </li>
    </ol>
    <ol class="round">
        <li class="three">
            <h5>Cloud Relacoes:&nbsp;&nbsp;&nbsp;
                <asp:Label ID="Labelcloudrel" runat="server" Text="Label"></asp:Label>
            </h5>
        </li>
    </ol>
    <h5>&nbsp;</h5>
</asp:Content>
