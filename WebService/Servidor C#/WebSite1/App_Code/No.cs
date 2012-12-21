using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

/// <summary>
/// Summary description for No
/// </summary>

[DataContract]
public class No
{
    [DataMember]
    public int id { get; set; }
    [DataMember]
    public int x { get; set; }

    [DataMember]
    public int y { get; set; }

    [DataMember]
    public int numNo { get; set; }

    public No(int idi, int xi, int yi)
    {
        id = idi;
        x = xi;
        y = yi;
    }
}