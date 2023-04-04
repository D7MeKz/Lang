using System;

class Employee
{
    private const int V = 100;
    public string FirstName;
    public string LastName;
    public int salary = 0;

    public void SetName(string firstname, string lastname)
    {
        // 매개변수와 인스턴스 필드명이 같다면 this 붙여도 되지만
        // 가급적이면 쓰지 않는것이 좋다. 
        FirstName = firstname;
        LastName = lastname;
    }
    public string GetName()
    {
        return $"{FirstName} {LastName}";

    }

    public string Name
    {
        get
        {
            return $"{FirstName} {LastName}";
        }
        set
        {
            string[] names;
            names = value.Split(new char[]{' '}); // 공백 단위로 쪼갠다.
            if(names.Length == 2)
            {
                FirstName = names[0];
                LastName = names[1];
            }
            else
            {
                // 이름이 할당되 지않는 경우의 예외를 던진다. 
                // nameof는 변수는 식별자를 해당한다. 이름을 나타내는 문자열 반환
                throw new System.ArgumentException(
                    $"Assigned value '{value}' is invalid nameof(value)"
                );
            }
        }
    }
}
// 변수 명명 규칙
// public attribute Sample
// private attribute _Sample
// function parameter sample 
class Sample
{
    public static int Id; // Id가 모든 개체와 연결될 수 있다.
    private string _SampleString;
    private int _SampleInt;
    private string _SampleName;   
    // 읽기 전용 자동 구현 속성
    public int[,,] intArry {get;} = new int[2,3,4];
    
    // Getter, Seetter
    public Sample()
    {
        Id++;
    }
    public string SampleString
    {
        
        get
        {
            return _SampleString;
        }
        set
        {
            // value는 읽기 속성이기 때문에 쓰기 전용으로 바꾸고 싶다면 setter를 사용해야한다. 
            _SampleString = value;
      
        }
    }

    public int SampleInt
    {
        // 더 간단하게 표현할 수 있다. 
        get => _SampleInt;
        set => _SampleInt = value;
    }

    public string SampleName
    {
        // null을 허용하지 않는다. 
        get => _SampleName!;
        set => _SampleInt = value ?? throw new ArgumentException(nameof(value));
    }

}

class ClassExample1
{
    static void Main()
    {
        Employee employee1 = new Employee();
        employee1.SetName("D7","MeKz");
        // 실제로 이렇게 짜면 안된다..
        System.Console.WriteLine($"{employee1.FirstName}");

        Sample sample1 = new Sample();
        // setter 호출
        sample1.SampleString = "Hello?";
        sample1.SampleInt = 5;
        // getter 호출
        System.Console.WriteLine($"sample string: {sample1.SampleString}, sample int: {sample1.SampleInt}");

    }
}