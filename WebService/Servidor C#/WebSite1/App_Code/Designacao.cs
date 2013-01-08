using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

/// <summary>
/// Summary description for Designacao
/// </summary>
/// 
[DataContract]
public class Designacao
{
    [DataMember]
    public string txt { get; set; }

	public Designacao(string des)
	{
        txt = des;
		//
		// TODO: Add constructor logic here
		//
	}
}
