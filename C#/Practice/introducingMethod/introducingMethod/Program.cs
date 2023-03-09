using System.Reflection.Emit;
using System;

class IntroducingMethod
{
    public static void Main()
    {
        string firstName;

        firstName = GetUserInput("Enter your first name: ");
        System.Console.Write(firstName);
    }

    static string GetUserInput(string question)
    {
        System.Console.Write(question);
        return System.Console.ReadLine();
    }

}