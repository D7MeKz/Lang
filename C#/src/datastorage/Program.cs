using System;
using System.IO;

class Employee
{
    public string firstname;
    public string lastname;

    public void setName(string first, string last)
    {
        firstname = first;
        lastname = last;
    }

}

class DataStorage
{
    public static void Store(Employee employee)
    {
        FileStream stream = new FileStream(employee.firstname + employee.lastname +".dat",FileMode.Create);
        StreamWriter writer = new StreamWriter(stream);

        writer.WriteLine(employee.firstname);
        writer.WriteLine(employee.lastname);
        writer.Close();
    }

    public static Employee Load(Employee employee)
    {
        FileStream stream = new FileStream(employee.firstname + employee.lastname + ".dat",FileMode.Open);
        StreamReader reader = new StreamReader(stream);
        
        // 파일에서 각 줄을 읽어 연결된 속성에 넣는다. 
        employee.firstname = reader.ReadLine() ??
            throw new InvalidOperationException("FirstName cannot be null");
        employee.lastname = reader.ReadLine() ??
            throw new InvalidOperationException("Lastname cannot be null");
            
        reader.Dispose();
        return employee;
    }

}

class Program
{
    static void Main()
    {
        Employee employee;
        Employee employee2 = new Employee();
        employee2.setName("Hello","World");
        DataStorage.Store(employee2);

        employee = DataStorage.Load(employee2);
        Console.WriteLine($"{employee.firstname} and {employee.lastname}");

    }
}