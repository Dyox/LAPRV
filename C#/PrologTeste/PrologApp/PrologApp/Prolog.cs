using System;
using System.Collections.Generic;
using System.Text;
using PrologApp;

namespace PrologApp.Model
{
    public class Prolog
    {
        public static string prlogCommand()
        {
            String s = "";
            try
            {
                Console.WriteLine("here");
                // inicia o motor do prolog
                LPA.IntServer prolog = new LPA.IntServer("", 0, 1, 0);


                // carrega o programa em prolog ('teste.pl')
                s = prolog.InitGoal("load_files(prolog(teste)).\n");
                s = prolog.CallGoal();
                prolog.ExitGoal();

                s = prolog.InitGoal("run3. \n");
                s = prolog.CallGoal();

                prolog.ExitGoal();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                //Console.ReadLine();
                return (ex.Message);
            }

            return s;
        }
    }
}
