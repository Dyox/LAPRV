using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

/// <summary>
/// Summary description for Arco
/// </summary>
[DataContract]
public class Arco
{
    [DataMember]
    public int idPrim { get; set; }
    [DataMember]
    public int idSec { get; set; }

    [DataMember]
    public int forca { get; set; }


    public Arco(int idi, int xi, int yi)
    {
        idPrim = idi;
        idSec = xi;
        forca = yi;
    }
}