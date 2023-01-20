#include<string.h>
#include <iostream>

class Photon_cannon {
    int hp, shiled;
    int coord_x, coord_y;
    int damage;

    char* name; 

public:
    Photon_cannon(int x, int y, const char* name);
    Photon_cannon(const Photon_cannon& pc);

    void show_status();
};

Photon_cannon::Photon_cannon(int x, int y, const char* name)
{
    this->coord_x = x;
    this->coord_y =y;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// pc의 인스턴스를 새로운 변수에 지정할 수 있어도, 값 자체는 바꿀 수 없다. 
// 굳이 일리리 할 필요없이 Photon_cannon pc1 = pc2;를 실행함으로써 
// 디폴트 복사 생성자를 호출할 수 있다.
// Photon_cannon pc3; pc3 = pc2; 는 일반 디폴트 생성자를 호출하므로 주의하길 바란다. 
Photon_cannon::Photon_cannon(const Photon_cannon& pc)
{
    this->hp = pc.hp; // 가능
    // pc.hp = 4; // 불가능
    this->coord_x = pc.coord_x;
    this->coord_y = pc.coord_y;
    this->damage = pc.damage;

    // (깊은 복사) 메모리로 할당해준다. 
    this->name = new char[strlen(pc.name)+1];
    strcpy(this->name, pc.name);
}

void Photon_cannon::show_status(){
  std::cout << "Photon Cannon " << this->name <<  std::endl;
  std::cout << " Location : ( " << this->coord_x << " , " << this->coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << this->hp << std::endl; 
}

int main(){
    Photon_cannon pc1(3,3,"D7MeKz");
    Photon_cannon pc2(pc1);
    Photon_cannon pc3 = pc2; // 디폴트 복사 생성자가 호출 

    // Photon_cannon pc4; // 일반 생성자 호출 
    // pc4 = pc3; 

    pc1.show_status();
    pc2.show_status();
    pc3.show_status();
}