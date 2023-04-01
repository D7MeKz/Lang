#pragma warning restore CS8618

public class Employee
{
    public string Id{get; private set;}
    public string FirstName{get; set;}
    public string LastName {get; set;}
    public string Salary{get; set;} = "Not Enough";

    public Employee(string firstname, string lastname)
    {
        FirstName = firstname;
        LastName = lastname;    
    }

    // Constructor Initializer
    // 생성자에 this를 사용할 매개변수가 무조건 존재해야 한다. 
    // 즉 선언함으로써 컴파일러에게 매개 변수가 있음을 알려야 한다. 
    public Employee(int id, string firstname, string lastname):this(firstname, lastname)
    {
        Id = id;
    }
}
