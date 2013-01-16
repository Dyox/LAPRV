using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

/// <summary>
/// Summary description for Ligacao
/// </summary>
/// 

[DataContract]
public class Ligacao
{

    [DataMember]
    public int id1 { get; set; }
    [DataMember]
    public int id2 { get; set; }
    [DataMember]
    public IList<string> tags { get; set; }


    public Ligacao(int idp, int ids, IList<string> t)
    {
        id1 = idp;
        id2 = ids;
        tags = t;

        //
        // TODO: Add constructor logic here
        //
    }
}