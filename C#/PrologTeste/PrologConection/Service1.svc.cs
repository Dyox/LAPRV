using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace PrologConection
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in code, svc and config file together.
    // NOTE: In order to launch WCF Test Client for testing this service, please select Service1.svc or Service1.svc.cs at the Solution Explorer and start debugging.
    public class Service1 : IService1
    {
        public string GetData(int value)
        {
            return string.Format("You entered: {0}", value);
        }

        public CompositeType GetDataUsingDataContract(CompositeType composite)
        {
            if (composite == null)
            {
                throw new ArgumentNullException("composite");
            }
            if (composite.BoolValue)
            {
                composite.StringValue += "Suffix";
            }
            return composite;
        }

        public string addProlog()
        {
            Console.WriteLine("here");
            return privateAddProlog();
        }

        public void writeConsole()
        {
            Console.WriteLine("here");
        }

        private string privateAddProlog()
        {
            Console.WriteLine("privateAddProlog");
            String s="";
            try
            {
                // inicia o motor do prolog
                LPA.IntServer prolog = new LPA.IntServer("", 0, 1, 0);
                //LPA.IntServer prolog = new LPA.IntServer("/H1024",0,0,0);
                Console.WriteLine("LPA");

                // carrega o programa em prolog ('teste.pl')
                s = prolog.InitGoal("load_files(prolog(teste)).\n");
                Console.WriteLine("Load");
                s = prolog.CallGoal();
                prolog.ExitGoal();

                s = prolog.InitGoal("run3. \n");
                s = prolog.CallGoal();

                prolog.ExitGoal();

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadLine();
            }
            return s;
        }
    }
}
