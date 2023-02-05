#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t; // ! ERROR: 문자열을 입력하면 failbit = 1
    if(std::cin.fail())
    {
        std::cout << "Try Again!!"<<std::endl;
        std::cin.clear(); //* Flag 초기화

        std::cout << "ignore Start!!"<<std::endl; 
        std::cin.ignore(10, '\n'); // 개행 문자가 나올때까지 무시한다. 
    }

    int t2;
    int t3; 
    //* 몇 진법으로 수를 처리할지 보관하는 basefield 값을 초기화한다. 
    std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
    while(true)
    {
        std::cin >> t2; // hex를 (상수)값으로써 받는다. 
        std::cin >> std::hex >> t3; // hex는 함수로써 적용된다.  
        if(std::cin.fail())
        {
            std::cout << "Wrong t2!!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(100,'\n');
            break;
        }
    }
}