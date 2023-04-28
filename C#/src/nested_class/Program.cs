using System.Threading;

// 중첩 클래스는 그다지 좋은 방법은 아니다. 
class Program
{
    private class CommandLine
    {
        public string? Action {get; }
        public string? Id{get;}
        public string? FirstName{get;}
        public string? LastName{get;}

        
        public CommandLine(string[] arguments)
        {
            for(int argumentCounter=0; argumentCounter <arguments.Length ; argumentCounter++)
            {
                switch(argumentCounter)
                {
                    case 0:
                        Action = arguments[0].ToLower();
                        break;
                    case 1:
                        Id=arguments[1];
                        break;
                    case 2:
                        FirstName = arguments[2];
                        break;
                    case 3:
                        LazyThreadSafetyMode = arguments[3];
                        break;
                
                }
            }
        }
    }

    static void Main(string[] args)
    {
        CommandLine commandLine = new CommandLine(args);
        switch(commandLine.Action)
        {
            case "new":
                System.Console.WriteLine("New!!");
                break;
        }
    }
}