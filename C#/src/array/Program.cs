using System.ComponentModel.DataAnnotations;
using System;

class ArrayPractice
{
    static void Main()
    {
        string rev, data;
        char[] temp;

        System.Console.Write("Enter: ");
        data = System.Console.ReadLine();
        System.Console.WriteLine(data);
        
        rev = data.Replace(" ","!");
        rev = rev.ToUpper(); // 대문자로 변경 
        System.Console.WriteLine(rev);        
        
        // 문자열 배열로 변경
        temp  = rev.ToCharArray();
        char[] end3Part = temp[^3 ..^0]; // 끝에서 3번째부터 마지막까지
        System.Console.WriteLine(end3Part);

        System.Array.Reverse(end3Part); // Array Reverse
        System.Console.WriteLine(end3Part);
        
    }
}