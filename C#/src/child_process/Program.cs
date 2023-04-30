using System;

// * 대체 기본 클래스를 지정하지 않는 한 모든 클래스는 기본적으로 object에서 파생된다. 
public class PdaItem
{
    // [DisallowNull]
    public string Name{get; set;}
    public DateTime LastUpdated {get; set;}

}

public class Contact : PdaItem
{
    public string Address {get; set;}
    public string Phone{get; set;}
}

public class Program
{
    public static void Main()
    {
        Contact contact = new Contact();
        contact.Name = "Inigo Montoya";
        System.Console.WriteLine(contact.Name);
    }
}