using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Web;

/// <summary>
/// Summary description for Arco
/// </summary>
[DataContract]
public class ArcoBD
{
    [DataMember]
    public int idRel { get; set; }
    [DataMember]
    public int idPrim { get; set; }
    [DataMember]
    public int idSec { get; set; }

    [DataMember]
    public int forca { get; set; }
   



    public ArcoBD(int idr,int id1, int id2, int f)
    {
        idRel = idr;
        idPrim = id1;
        idSec = id2;
        forca = f;
    }
}