using System;
using System.Collections.Generic;
using System.Text;

namespace PrologApp
{
    public class PrologCall
    {
        public static string executeAddProlog()
        {
            String s;
            try
            {

                LPA.IntServer prolog = new LPA.IntServer("", 0, 0, 0);
                //LPA.IntServer prolog = new LPA.IntServer("/H1024",0,0,0);
                

                // carrega o programa em prolog ('teste.pl')
                s = prolog.InitGoal("load_files(prolog(teste)).\n");
                s = prolog.CallGoal();
                prolog.ExitGoal();

                // executa um predicado
                s = prolog.InitGoal("run3. \n");
                s = prolog.CallGoal();
                Console.WriteLine(s);

                prolog.ExitGoal();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return ex.Message;
            }
            return s;
        }
    }
}
