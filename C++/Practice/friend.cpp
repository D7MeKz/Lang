#include<iostream>
// Class B와 func은 A의 class의 private field에 대한
//  접근 권한을 가지게 된다. 
class A{
private:
    void private_func();
    int private_num;
    friend class B; // B는 A의 친구 
    friend void func();
};

class B{
public:
    void b(){
        A a;
        a.private_func(); // 가능
        a.private_num = 2; 
    }
};

void func()
{
    A a;
    a.private_func();

}

int main()
{
    std::cout << ":)"<<std::endl;
    return 0;
}