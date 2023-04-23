using System;

// 정적 클래스의 경우 인스턴스를 생성하지 않고 호출할 수 있다. 
// 런타임시 호출 가능한 정적 메서드 테이블이 존재한다.
// 주로 자주 사용하는 메서드를 빠르고 적은 메모리로 실행시킬 수 있도록 해준다. 
public static class Employee{
    // 정적 생성자의 경우 클래스 자체를 초기화하는 수단으로 많이 사용된다.
    //명시적으로 호출하지 못할 뿐더러 모든 생성자에는 매개변수가 없다. 
    static Employee(){
        Random randomGenrator = new Random();
        NextId = randomGenrator.Next(101,999);
    } 
    
    // 정적 속성 
    // public 보다는 정적 속성을 사용하는 것이 좋다. 
    public static int NextId{
        get{
            return _NextId;
        }
        set{
            _NextId = value;
        }
    }
    
    public static int NextId = 42; 
}