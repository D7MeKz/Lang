using System;

class Method2
{
    static void Main()
    {
        string firstname = "D7";
        string lastname = "MeKz!";
        test1(ref firstname, ref lastname);
        System.Console.Write($@"{firstname} {lastname}");
    }

    // 참조 
    static void test1(ref string firstname, ref string lastname)
    {
        firstname = firstname + "Ref!!";
        lastname = lastname + "ref!!!!!";
                
    }
}