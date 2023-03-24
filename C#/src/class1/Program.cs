using System;

class Employee
{
    private const int V = 100;
    public string _FirstName;
    public string _LastName;
    public int salary = 0;

    public void SetName(string Firstname, string Lastname)
    {
        // 매개변수와 인스턴스 필드명이 같다면 this 붙여도 되지만
        // 가급적이면 쓰지 않는것이 좋다. 
        _FirstName = Firstname;
        _LastName = Lastname;
    }
    public string GetName()
    {
        return $"{_FirstName} {_LastName}";

    }
}

class Sample
{
    private string _SampleString;
    private int _SampleInt;
    // Getter, Setter 대신 아래와 같이 표현할 수 있다.
    public string SampleString
    {
        get
        {
            return _SampleString;
        }
        set
        {
            _SampleString = value;
      
        }
    }

    public int SampleInt
    {
        // 더 간단하게 표현할 수 있다. 
        get => _SampleInt;
        set => _SampleInt = value;
    }

}

class ClassExample1
{
    static void Main()
    {
        Employee employee1 = new Employee();
        employee1.SetName("D7","MeKz");
        // 실제로 이렇게 짜면 안된다..
        System.Console.WriteLine($"{employee1._FirstName}");

        Sample sample1 = new Sample();
        // setter 호출
        sample1.SampleString = "Hello?";
        sample1.SampleInt = 5;

        // getter 호출
        System.Console.WriteLine($"sample string: {sample1.SampleString}, sample int: {sample1.SampleInt}");

    }
}