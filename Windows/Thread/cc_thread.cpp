#include <iostream>
#include <Windows.h>
#include <tchar.h>

DWORD WINAPI ThreadProc(PVOID pParam)
{
    DWORD dwDelay = (DWORD)pParam;
    std::cout << "Current Thread Enter : "<< GetCurrentThreadId()<<std::endl;
    Sleep(dwDelay);
    std::cout << "Current Thread Leave " << GetCurrentThreadId() << std::endl;
    // Entry Function이 return 키워드를 통해 빠져나가는 순간 스레드는 종료된다. 
    // ExitThread를 통해 강제로 종료시킬 수 있지만 소멸자 함수가 호풀되지 않다는 점에서
    // 클린 작업이 실행되지 않는다. 
    // TerminateThread에 실행되는 Thread Handler는 유저 모드상에 코드를 실행할 수 없으며,
    // 스레드에 연결된 DLL은 스레드 종료 통지를 받지 못한다. 

    return dwDelay;
}

void _tmain()
{
    std::cout << "Create Thread"<<std::endl;

    DWORD dwThreadId = 0;
    HANDLE hThread = CreateThread(
        NULL,
        0,
        ThreadProc, // Entry Function에 대한 포인터
        (PVOID)5000, // 넘겨줄 매개변수 값
        0,
        &dwThreadId // out 
    );
    
    if(hThread == NULL)
    {
       std::cout << "CreateThread Failed! Error code"<<GetLastError()<<std::endl;
        return ; 
    }

    // 프로세스가 끝날때까지 기다린다. 
    Sleep(10000);

    DWORD dwExitCode = 0;
    GetExitCodeThread(hThread, &dwExitCode); // Entry Function의 리턴값을 구한다. 

    CloseHandle(hThread);
}


