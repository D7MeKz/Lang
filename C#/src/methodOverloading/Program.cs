#nullable enable
using System;
using System.IO;

// 다형성을 위해 오버로딩 제공 
public static class LineCounter
{
    public static void Main(string[] args)
    {
        int totalLineCount;
        if(args.Length > 1)
        {
            totalLineCount = DirectoryCountLines(args[0], args[1]);
        }

        if(args.Length > 0 )
        {
            totalLineCount = DirectoryCountLines(args[0]);
        }
        else
        {
            totalLineCount = DirectoryCountLines();
        }

        System.Console.WriteLine(totalLineCount);
    }

    static int DirectoryCountLines()
    {
        return DirectoryCountLines(Directory.GetCurrentDirectory());
    }

    static int DirectoryCountLines(string directory)
    {
        return DirectoryCountLines(directory, "*.cs");
    }

    static int DirectoryCountLines(string directory, string extension)
    {
        int lineCount = 0;
        foreach(string file in Directory.GetFiles(directory, extension))
        {
            lineCount += CountLines(file);
        }

        return lineCount;
    }

    private static int CountLines(string file)
    {
        int lineCount = 0;
        string line;
        FileStream stream = new FileStream(file, FileMode.Open);
        StreamReader reader = new StreamReader(stream);
        line = reader.ReadLine();
        while(line is objet)
        {
            if(line.Trim() != "")
            {
                lineCount++;
            }
            line = reader.ReadLine();
        }
        reader.Close();
        return lineCount; 
    }
}