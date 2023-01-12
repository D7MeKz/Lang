#include<iostream>
// Reference를 쓰는 이유 -> 값을 효율적으로 전달하기 위해서 

void ref();
void arr_ref();
int& local_ret_ref();
int& global_ret_ref(int& p);

void get_ref(int& p)
{
    p = 3;
}

int main()
{
    ref();
    arr_ref();

    // 지역변수 ref return 
    int& ret = local_ret_ref(); // ret_ref ERROR!!
    const int& long_ret = local_ret_ref(); // Reference가 사라질때까지 return 값 연장

    // 전역변수 ref return 
    int a = 2;
    int b = global_ret_ref(a);
    std::cout << b; // 5
    
}

void ref()
{
    int a = 3;
    int b = 10;

    // 레퍼런스는 메모리상에 존재하지 않을 수 있다. 
    // Reference: 별명, 초기화가 필수 
    int& ref_a = a; // ref_a는 a의 참조자다!

    ref_a = 5;
    std::cout << "a: "<< a << std::endl; // 5
    std::cout << "ref_a: " << ref_a << std::endl; // 5

    get_ref(b);
    std::cout << "b: " << b << std::endl; // 3
    
}
void arr_ref()
{
    
    // 레퍼런스의 배열은 illegal하나, 배열의 레퍼런스는 가능하다. 
    // 레퍼런스는 특별한 경우가 아닌 이상 메모리 상에서 공간을 차지하지 않는다. 
    // 하지만 배열은 시작 주소를 의미하며 이는 메모리 상에 존재함을 의미한다. 
    // 그러한 이유로 언어 차원에서 레퍼런스 배열은 금지하고 있다. 
    // int& arr[2] = {a,b}; // ERROR!!

    int arr[3] = {1, 2, 3};
    int(&ref)[3] = arr;

    ref[0] = 10;
    ref[1] = 20;
    ref[2] = 30;
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
}

int& local_ret_ref()
{
    int a = 2;
    return a; 
    // return 시 a가 사라진다. 
    // 참조하고 있는 값도 사라지게 된다. 그리고 별명만 남게 된다. -> Dangling 
    // 지역 변수의 레퍼런스 리턴은 피해야한다. 
    // 단, 상수 레퍼런스 const int&로 리턴값을 받게 되면 리턴값의 생명이 연장된다. (Reference가 사라질때까지)
}

int& global_ret_ref(int& p)
{
    p = 5;
    return p;
}

