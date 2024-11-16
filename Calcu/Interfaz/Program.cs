using System;
using System.Windows.Forms;

namespace InterfazEstadistica  // Asegúrate de que este sea el nombre correcto del namespace
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());  // Aquí se debe invocar Form1 como una clase
        }
    }
}