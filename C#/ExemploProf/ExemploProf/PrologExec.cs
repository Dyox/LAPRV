using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExemploProf
{
    public class PrologExec
    {
        string _Lines;
        string _User;
        string _Comando;
        string _NomeFich;
        //string _Target;

        private PrologExec()
        {
        }

        public PrologExec(string lines, string user, string comando, string nomeFich)
        {
            this._Lines = lines;
            this._User = user;
            this._Comando= comando;
            NomeFich=Comando+"_"+User;
            //this._NomeFich = nomeFich;
        }

        public PrologExec(string user, string comando)
        {
            this._User = user;
            this._Comando = comando;
            NomeFich = Comando + "_" + User;
        }
        
        public string Lines
        {
            get { return _Lines; }
            set { _Lines = value; }
        }

        public string NomeFich
        {
            get { return _NomeFich; }
            set { _NomeFich = value; }
        }

        public string User
        {
            get { return _User; }
            set { _User = value; }
        }

        public string Comando
        {
            get { return _Comando; }
            set { _Comando = value; }
        }

        private Boolean escrverPL(string target)
        {
            obterLines(target);
            if (Lines == null)
                return false;
            try
            {
                System.IO.File.WriteAllText(@"C:\\WIN-PROLOG 4800\"+NomeFich+".pl", Lines);
            }
            catch (System.IO.IOException ex)
            {
                return false;
            }
            return true;
        }

        private void obterLines(string target)
        {
            //string nos = resultadoFicheiro("readNos");
            //string ramos = resultadoFicheiro("readRamos");
            //menorCaminho = cam_min(a,c,P)
            //caminhoMaisForte = camMaisForte(X,Y)
            //menorCaminho = cam_min(_target_)
            //caminhoMaisForte = camMaisForte(_target_)
            string nos = obterNos();
            string ramos = obterRamos();
            string conteudo = null;
            string metodo = null;
            switch (Comando)
            {
                case "menorCaminho":
                    conteudo = resultadoFicheiro("menorCaminho");
                    metodo = "cam_min(_target_)";
                    break;
                case "caminhoMaisForte":
                    conteudo = resultadoFicheiro("caminhoMaisForte");
                    metodo = "camMaisForte(_target_)";
                    break;
                case "recomendaAmizade":
                    conteudo = resultadoFicheiro("recomendaAmizade");
                    metodo = "sugerir_users(_target_)";
                    break;
                case "xTagsEmComum":
                    conteudo = resultadoFicheiro("xTagsEmComum");
                    metodo = "amigos_com_x_tags_iguais(_target_)";
                    break;
                case "tamanhoRedeUtilizador":
                    conteudo = resultadoFicheiro("tamanhoRedeUtilizador");
                    metodo = "tamanho_rede_user_3(_target_,N)";
                    break;
                case "grafoAmigosComuns":
                    conteudo = resultadoFicheiro("grafoAmigosComuns");
                    metodo = "amigos_comuns(_target_,N)";
                    break;
            }
            string fim ="run:- tell('" + NomeFich + ".txt'),"+metodo+",told,halt."+ "\n" +
                                 ":-run. \n";
            fim = fim.Replace("_target_",target);
            if (nos =="" || ramos =="" || conteudo == null || metodo == null)
            {
                Lines = null;
            }
            else
            {
                Lines = nos + "\n" + ramos + "\n" + conteudo + "\n" + fim;
            }
        }

        private string obterNos()
        {
            IList listaNos = Rede.Perfil.LoadInfoForNos();

            string txt = "";
            foreach (Rede.Perfil n in listaNos)
            {
                txt += n.toFile() + " \n";
            }

            return txt;
        }

        private string obterRamos()
        {
            IList listaArcos = Rede.Relacao.LoadInfoForArcos();

            string txt = "";
            foreach (Rede.Relacao r in listaArcos)
            {
                txt += r.toFile() + " \n";
            }

            return txt;
        }

        private Boolean executaProlog()
        {
            try
            {
                var pProcess = new System.Diagnostics.Process
                {
                    StartInfo =
                    {
                        FileName = "cmd.exe",
                        Arguments = "/C PRO386W.EXE /V1 consult('"+NomeFich+".pl').",
                        UseShellExecute = false,
                        RedirectStandardOutput = true,
                        WorkingDirectory = "C:\\WIN-PROLOG 4800"
                    }
                };
                pProcess.Start();
                string r = pProcess.StandardOutput.ReadToEnd();
                pProcess.Close();
                return true;
            }
            catch (Exception Ex)
            {
                return false;
            }
        }

        private string resultadoFicheiro(string nomeFicheiro)
        {
            try
            {
                string text = System.IO.File.ReadAllText(@"C:\\WIN-PROLOG 4800\" + nomeFicheiro + ".txt");
                return text;
            }
            catch (System.IO.IOException e)
            {
                return null;
            }
            
        }

        private Boolean removeFiles()
        {
            if (System.IO.File.Exists(@"C:\\WIN-PROLOG 4800\" + NomeFich + ".txt"))
            {
                try
                {
                    System.IO.File.Delete(@"C:\\WIN-PROLOG 4800\" + NomeFich + ".txt");
                }
                catch (System.IO.IOException e)
                {
                    Console.WriteLine(e.Message);
                    return false;
                }
            }
            else
            {
                return false;
            }
            if (System.IO.File.Exists(@"C:\\WIN-PROLOG 4800\" + NomeFich + ".pl"))
            {
                try
                {
                    System.IO.File.Delete(@"C:\\WIN-PROLOG 4800\" + NomeFich + ".pl");
                }
                catch (System.IO.IOException e)
                {
                    Console.WriteLine(e.Message);
                    return false;
                }
            }
            else
            {
                return false;
            }
            return true;
        }

        public string executaComandoProlog(string target)
        {
            Boolean pl =escrverPL(target);
            if (pl)
            {
                Boolean exec = executaProlog();
                if (exec)
                {
                    String resultado = resultadoFicheiro(NomeFich);
                    removeFiles();
                    return resultado;
                }
            }
            return "erro";
        }

        private static bool IsFileLocked(string path)
        {
            FileInfo file = new FileInfo(path);
            FileStream stream = null;

            try
            {
                stream = file.Open(FileMode.Open, FileAccess.ReadWrite, FileShare.None);
            }
            catch (IOException)
            {
                //the file is unavailable because it is:
                //still being written to
                //or being processed by another thread
                //or does not exist (has already been processed)
                return true;
            }
            finally
            {
                if (stream != null)
                    stream.Close();
            }

            //file is not locked
            return false;
        }
    
    }
}
