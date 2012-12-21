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
        IList<No> GetAllXY();

        [OperationContract]
        void DoWork();
    }
