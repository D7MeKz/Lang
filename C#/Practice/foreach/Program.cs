using System;

class ForeachSample
{
    static void Main()
    {
        int []cells = {1, 2, 3, 4, 5, 6, 7};
        int add_value=0;
        System.Console.Write("This is foreach Sample\n");
        // ! Foreach를 사용하는 동안 컴파일러가 cell 변수의 수정을 방지한다. 
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