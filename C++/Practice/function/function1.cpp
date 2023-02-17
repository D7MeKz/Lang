#include <iostream>
#include <function>

// class 생성 
struct S{
    void operator()(int a, int b){std::cout << "a+b=" <<a + b << std::endl;}
}; 

class Sample
{
private:
    int a_;
public:
    Sample(int a) : _a(a){};
    int func1() { return a_;}
};


int main()
{
    S obj; // S의 클래스의 객체이다. 

    // * std::function<return(params)> 
    // 그러나 객체의 경우에는 operator를 char로 받게 되므로 char이 된다. 
    std::function<void(char)> f2 = S();    
    
    // ! ERROR
    Sample sample(5);
    // ! 이렇게 선언할 경우 함수 입장에서 자신을 호출하는 객체가 무엇인지 알 수 없다.
    // 그러므로 sample에 대한 정보를 추가적으로 전달해야한다. 
    std::function<int()> f3 = sample.func1;
    obj(4,5);

    // ? CORRECT 
    Sample sample(2);
    std::fumction<int(Sample&)> f1 = &Sample::func1; // 함수의 이름만으로도 주소값을 전달한다. 

}

// 함수의 멤버 변수의 경우 암시적 변환이 일어나지 않아 &연산자를 통해 명시적을 주소값을 전달해야한다. 