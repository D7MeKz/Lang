// https://twitter.com/checkymander/status/1630947396002643971?s=20
using System.Diagnostics;

class Rce1{
    static void Main()
    {
        string executable = "calc.exe";
        Process process = new Process
        {
            StartInfo = new ProcessStartInfo()
            {
                UseShellExecute=false,
                CreateNoWindow= true,
                WindowStyle = ProcessWindowStyle.Hidden,
                FileName= executable,
                Arguments = "",
                RedirectStandardError = true,
                RedirectStandardOutput=true
            }
        };
        process.Start();
    }
}

