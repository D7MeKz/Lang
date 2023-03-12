using System;
using System.IO;

class PathEx
{
    static void Main()
    {
        string fullName = string.Empty;

        fullName = Combine(Directory.GetCurrentDirectory(), "bin", "config", "index.html");
        Console.WriteLine(fullName);
    }

    // 파라미터를 문자열 배열로 선언할 수 있다.
    static string Combine(params string[] paths)
    {
        string result = string.Empty;
        foreach(string path in paths)
        {
            // Path는 c#에서 제공해주는 객체 
            result = Path.Combine(result,path);
        }
        return result;
    }
}