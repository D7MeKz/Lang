#include<iostream>

class A
{
    mutable int data_;
public:
    A(int data) : data_(data){}
    
    // const를 선언하는 이유 - 이 함수는 객체 내부 상태에 영향을 주지 않는다.
    // 대체적으로 읽기 작업을 할때 많이 사용된다. 
    // 그러나 내부 정보를 바꿔야하는 경우가 존재하므로 mutable로 선언하면 된다. 
    void DoSomething(int x) const{
        data_ = x; // mutable이 없다면 data_는 변경할 수 없다.(const )
    }
    void PrintData() const { std::cout << "data: " << data_ << std::endl; }
}

int main()
{
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}