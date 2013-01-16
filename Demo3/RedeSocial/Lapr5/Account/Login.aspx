<%@ Page Title="Log in" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="RedeSocial.Account.Login" culture="auto" meta:resourcekey="PageResource1" uiculture="auto" %>
<%@ Register Src="~/Account/OpenAuthProviders.ascx" TagPrefix="uc" TagName="OpenAuthProviders" %>

<asp:Content runat="server" ID="BodyContent" ContentPlaceHolderID="MainContent">
    <hgroup class="title">
        <h1><%: Title %>.</h1>
    </hgroup>
    <section id="loginForm">
        <h2>Use a local account to log in.</h2>
        <asp:Login runat="server" ViewStateMode="Disabled" RenderOuterTable="False" meta:resourcekey="LoginResource1">
            <LayoutTemplate>
                <p class="validation-summary-errors">
                    <asp:Literal runat="server" ID="FailureText" meta:resourcekey="FailureTextResource1" />
                </p>
                <fieldset>
                    <legend>Log in Form</legend>
                    <ol>
                        <li>
                            <asp:Label runat="server" AssociatedControlID="UserName" meta:resourcekey="LabelResource1">User name</asp:Label>
                            <asp:TextBox runat="server" ID="UserName" meta:resourcekey="UserNameResource1" />
                            <asp:RequiredFieldValidator runat="server" ControlToValidate="UserName" CssClass="field-validation-error" ErrorMessage="The user name field is required." meta:resourcekey="RequiredFieldValidatorResource1" />
                        </li>
                        <li>
                            <asp:Label runat="server" AssociatedControlID="Password" meta:resourcekey="LabelResource2">Password</asp:Label>
                            <asp:TextBox runat="server" ID="Password" TextMode="Password" meta:resourcekey="PasswordResource1" />
                            <asp:RequiredFieldValidator runat="server" ControlToValidate="Password" CssClass="field-validation-error" ErrorMessage="The password field is required." meta:resourcekey="RequiredFieldValidatorResource2" />
                        </li>
                        <li>
                            <asp:CheckBox runat="server" ID="RememberMe" meta:resourcekey="RememberMeResource1" />
                            <asp:Label runat="server" AssociatedControlID="RememberMe" CssClass="checkbox" meta:resourcekey="LabelResource3">Remember me?</asp:Label>
                        </li>
                    </ol>
                    <asp:Button runat="server" CommandName="Login" Text="Log in" meta:resourcekey="ButtonResource1" />
                </fieldset>
            </LayoutTemplate>
        </asp:Login>
        <p>
            <asp:HyperLink runat="server" ID="RegisterHyperLink" ViewStateMode="Disabled" meta:resourcekey="RegisterHyperLinkResource1">Register</asp:HyperLink>
            if you don't have an account.
        </p>
    </section>

    <section id="socialLoginForm">
        <h2>Use another service to log in.</h2>
        <uc:OpenAuthProviders runat="server" ID="OpenAuthLogin" />
    </section>
</asp:Content>
