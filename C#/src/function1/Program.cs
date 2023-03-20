// C#의 경우 java와 다르게 * 즉 와ㅓ일드카드를 사용해 네임스페이스를 가져올 수 없다. 
// 즉 모두 명시적으로 표현해야한다는 것이다. 

// using static을 사용하면 System을 생략할 수 있다.
// 다만 특정 네임스페이스에 같은 이름의 메소드가 존재한다면 명확성이 떨어지기에
// 잘 판단하고 사용해야한다. 
using static System;
using nickname = System.Timer.Timer; // 별칭 사용 가능 

public class FunctionExample01
{
    static string GetUserInput(string prompt)
    {
        System.Console.Write(prompt);
        return System.Console.ReadLine();
    }
    static (string first, string last) GetName()
    {
        string first, last;
        first = GetUserInput("Enter your firstname: ");
        last = GetUserInput("Enter your lastname: ");
        return (first, last); // return tuple 
    }
    static public void Main()
    {
        (string first, string last) name = GetName();
        nickname timer;
        System.Console.WriteLine($"{name.first} and {name.last}");
    }
}