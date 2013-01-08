using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

/// <summary>
/// Summary description for No
/// </summary>

[DataContract]
public class NoBD
{
    [DataMember]
    public int id { get; set; }
    [DataMember]
    public int x { get; set; }

    [DataMember]
    public int y { get; set; }

    [DataMember]
    public string humor { get; set; }

    [DataMember]
    public string nome { get; set; }
    //[DataMember]
    //public int countNos { get; set; }

    public NoBD(int idi, int xi, int yi,string hu, string no)
    {
        id = idi;
        x = xi;
        y = yi;
        humor = hu;
        nome = no; 
        //countNos = counti;
    }
}