using System;

class Method2
{
    static void Main()
    {
        string firstname = "D7";
        string lastname = "MeKz!";
        test1(ref firstname, ref lastname);
        // 참조 형식을 사용하기 위해서는 ref 키워드를 붙여야한다. 
        System.Console.Write($@"{firstname} {lastname}");
    }

    // 참조 
    static void test1(ref string firstname, ref string lastname)
    {
        firstname = firstname + "Ref!!";
        lastname = lastname + "ref!!!!!";
    }
}