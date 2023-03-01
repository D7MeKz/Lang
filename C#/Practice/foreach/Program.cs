using System;

class ForeachSample
{
    static void Main()
    {
        int []cells = {1, 2, 3, 4, 5, 6, 7};
        int add_value=0;
        System.Console.Write("This is foreach Sample\n");
        foreach (int cell in cells)
        {   
            add_value += cell;
            if(add_value < 10)
            {
                System.Console.Write($"{add_value}\n");
            }
        }
    }
}