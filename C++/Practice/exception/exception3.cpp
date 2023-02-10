#include <iostream>
#include <exception> 

int foo() noexcept {}

int bar() noexcept {throw 1;}

int main()
{
    foo();
    try{
        bar();
    }catch(int x){
        std::cout << x << std::endl;
    }
}

// * 최적화를 위해 프로그래머는 noexcept를 활용해 컴파일러에게 
// * 예외가 처리되지 않음을 알린다.