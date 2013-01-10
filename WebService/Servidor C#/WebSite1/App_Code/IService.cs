using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;
using System.Collections;

// NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService" in both code and config file together.

    [ServiceContract]
    public interface IService
    {
        [OperationContract]
        int Add(int x, int y);

        [OperationContract]
        IList<NoBD> GetAllXY();
        [OperationContract]
        IList<ArcoBD> GetAllArcoBD();
        [OperationContract]
        Utilizador GetUtilizadorByID(int uid);
        [OperationContract]
        IList<string> GetTagsByUserID(int uid);
        [OperationContract]
        string GetHumorByUserID(int uid);
        [OperationContract]
        string getMenorCaminho(int no1, int no2);
        [OperationContract]
        string getCaminhoForte(int no1, int no2);

        [OperationContract]
        void DoWork();
    }
