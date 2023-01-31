#include<iostream>

template <int N>
struct Factorial{
    // 객체를 생성하지 않더라도, 타입에 어떠한 값을 구현하고 연산할 수 있다. 
    // 타입은 반드시 컴파일 타임에 확정되어야 하므로, 컴파일 타임에 모든 연산이 끝나게 된다. 
    static const int result = N * Factorial<N-1>::result;
}

// result = 1로 만들어주게 되어 재귀적 구조가 끝날 수 있게 해준다. 
template<>
struct Factorial<1>{
    static const int result = 1;
}

int main()
{
    std::cout << Factorial<6>::result<<std::endl;
}