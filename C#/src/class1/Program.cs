using System;

class Employee
{
    public string FirstName;
    public string LastName;
    public int salary;
    public Employee []EmployeeList = new Employee(100);

    public void SetName(string Firstname, string Lastname)
    {
        // 매개변수와 인스턴스 필드명이 같다면 this 붙여도 되지만
        // 가급적이면 쓰지 않는것이 좋다. 
        this.FirstName = FirstName;
        this.LastName = LastName;
    }
    public string GetName()
    {
        return $"{Firstname} {LastName}";
    }

    public void Store()
    {
        // 객체를 모두 사용할 경우 this를 사용할 수 있다. 
        EmployeeList.Append(this);
    }
}

class ClassExample1
{
    static void Main()
    {
        Employee employee1 = new Employee();
        employee1.FirstName = "D7";
        employee1.LastName = "MeKz";
        System.Console.WriteLine($"{employee1.FirstName}");
    }
}