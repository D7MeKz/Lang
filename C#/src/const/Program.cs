
class ConstAndReadOnly
{
    public const float CentimetersPerInch = 2.54F; // public const의 경우 불변의 경우에마 사용해야한다. Literal만 가능
    public readonly int _Id; // 변할 가능성이 있는 경우 const 대신 readonly를 사용하자
    public static readonly Guid ComIUKnownGuid = new Guid("00000"); // Literal 외의 형식도 지원한다. 
    ConstAndReadOnly(int Id)
    {
        _Id = Id;
    }
}