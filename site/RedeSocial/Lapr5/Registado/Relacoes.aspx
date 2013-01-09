    <%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Relacoes.aspx.cs" Inherits="RedeSocial.Registado.Relacoes" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="FeaturedContent" runat="server">
</asp:Content>



<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" runat="server">
    <section id="loginForm">
        <h2>titulo</h2>
    <asp:Table runat="server">
        <asp:TableRow>
            <asp:TableCell>
                asd
            </asp:TableCell>
            <asp:TableCell>

                asdfsa
            </asp:TableCell>
        </asp:TableRow>
    </asp:Table>
    <asp:Label ID="Label4" runat="server" Text="Procurar Amigos:"></asp:Label>
    <br />
    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
    <asp:Button ID="Button1" runat="server" Text="Procurar" OnClick="Button1_Click" />
    <br />
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource1">
        <Columns>
            <asp:BoundField DataField="Nome" HeaderText="Nome" SortExpression="Nome" />
            <asp:BoundField DataField="Nick" HeaderText="Nick" SortExpression="Nick" />
            <asp:ImageField DataImageUrlField="Avatar">
            </asp:ImageField>
            <asp:CommandField ButtonType="Button" HeaderText="Selecionar" ShowHeader="True" ShowSelectButton="True" />
        </Columns>
    </asp:GridView>
    <br />
    <asp:Label ID="Label5" runat="server" Text="Tags da Relação:"></asp:Label>
    <br />
<asp:TextBox ID="TextBoxTag" runat="server"></asp:TextBox>
<asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="Juntar" />
<asp:DropDownList ID="DropDownTags" runat="server">
</asp:DropDownList>
<br />
<asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="Large" Text="Força"></asp:Label>
&nbsp;&nbsp;&nbsp;
<asp:DropDownList ID="DropDownForca" runat="server">
    <asp:ListItem>1</asp:ListItem>
    <asp:ListItem>2</asp:ListItem>
    <asp:ListItem>3</asp:ListItem>
    <asp:ListItem>4</asp:ListItem>
    <asp:ListItem>5</asp:ListItem>
</asp:DropDownList>
<br />
<asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Enviar" />
    <br />
    <br />
    <br />
    <br />
    <br />
    <asp:Label ID="Label3" runat="server" Text="Lista de Pedidos de Amizades:"></asp:Label>
    <asp:GridView ID="GridView2" runat="server" AutoGenerateColumns="False" DataSourceID ="SqlDataSource2">
        <Columns>
            <asp:ImageField DataImageUrlField="Avatar"></asp:ImageField>
            <asp:BoundField DataField="Nome" HeaderText="Nome" SortExpression="Nome" />
            <asp:BoundField DataField="Estado" HeaderText="Estado" />
            </Columns>
    </asp:GridView>
    <br />
    <asp:Label ID="Label2" runat="server" Text="Lista de Amigos:"></asp:Label>
    <br />
    <asp:GridView ID="GridView3" runat="server" AutoGenerateColumns="False" DataSourceID ="SqlDataSource3" OnRowDeleting="GridView3_RowDeleting" >
        <Columns>
            <asp:ImageField DataImageUrlField="Avatar"></asp:ImageField>
            <asp:BoundField DataField="Nome" HeaderText="Nome" SortExpression="Nome" />
            <asp:CommandField ButtonType="Button" ShowDeleteButton="True"  />
            </Columns>
    </asp:GridView>
<br />
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>">
    </asp:SqlDataSource>
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>">
    </asp:SqlDataSource>
    <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:ARQSI22ConnectionString %>">
    </asp:SqlDataSource>
    <br />
    <br />
        </section> <section id="Section1">
        <h2>Pessoas que possa conhecer...</h2>

        </section>
</asp:Content>

    
