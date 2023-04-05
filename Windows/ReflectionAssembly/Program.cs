using System;
using System.Reflection;
using System.Security.Permissions;

// @link https://learn.microsoft.com/en-us/dotnet/api/system.reflection.assembly?view=net-7.0
// Obtain the currently executing assembly, invoking one of the type's ow mehods with late binding.
// 쉽게 말해 늦게 파일을 binding 한 실행파일이라고 보면 된다. 
public class ReflectionAssembly
{
    private int factor; 
    public ReflectionAssembly(int f)
    {
        factor = f;
        
    }

    public int SampleMethod(int x)
    {
        Console.WriteLine("\nExample.SampleMethod {0} executes.", x);
        return x * factor;
    }

    public static void Main()
    {
        Assembly assem = typeof(ReflectionAssembly).Assembly;
        Console.WriteLine("Assembly Full Name: {0}",assem.FullName);

        Console.WriteLine("\nAssembly CodeBase:");
        Console.WriteLine(assem.CodeBase);

        // Create an object from the assembly, 
        // @link https://learn.microsoft.com/en-us/dotnet/api/system.reflection.assembly.createinstance?view=net-7.0#system-reflection-assembly-createinstance(system-string-system-boolean-system-reflection-bindingflags-system-reflection-binder-system-object()-system-globalization-cultureinfo-system-object())
        // ReflectionAssembly 라는 이름의 2개의 인자를 가지는 object instance를 가지겠다는 의미.
        Object o = assem.CreateInstance("ReflectionAssembly",false, BindingFlags.ExactBinding,null, new Object[]{2}, null, null);
        
        // Make a late-bound call to an instance method of the object
        // 함수를 call 하도록한다.
        // 실제로 ps1 악성코드에서도 사용되기도 한다. 
        MethodInfo m = assem.GetType("ReflectionAssembly").GetMethod("SampleMethod");
        // 42의 값을 넣어 실행시킨다. 
        Object ret = m.Invoke(o, new Object[]{42});
        Console.WriteLine("\nreturn value: {0}", ret);
        
    }
}