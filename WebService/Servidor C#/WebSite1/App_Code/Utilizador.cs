using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

/// <summary>
/// Summary description for Utilizador
/// </summary>
/// 
[DataContract]
public class Utilizador
{
    [DataMember]
    public string nome { get; set; }
    [DataMember]
    public string nick { get; set; }
    [DataMember]
    public string  morada { get; set; }
    [DataMember]
    public int tele { get; set; }
    [DataMember]
    public string nasc{ get; set; }
    [DataMember]
    public string avatar { get; set; }
	public Utilizador()
	{
		//
		// TODO: Add constructor logic here
		//

	}
    public Utilizador(string no, string ni, string mo,int te, string na,string av)
    {
        nome = no;
        nick = ni;
        morada = mo;
        tele = te;
        nasc = na;
        avatar = av;
    }
}
