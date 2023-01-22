#include "marine.h"

Marine::Marine()
{
	this->hp = 50;
	this->coord_x = coord_y = 0;
	this->damage = 5;
	this->is_dead = false;
	this->name = "None";
	marine_cnt++;
}

 Marine::Marine(int x, int y, const std::string name)
{
	this->hp = 50;
	this->coord_x = x;
	this->coord_y = y;
	this->damage = 5;
	this->is_dead = false;
	this->name = name;
	marine_cnt++;
}

 Marine::~Marine() {
	 std::cout << this->name << " is deleted!!" << std::endl;
 }

// 상수 함수는 다른 변수의 값을 바꾸지 않는다. 
// 상수 함수 내에서는 객체들의 읽기만 수행 
 int Marine::attack() const
 {
	 return 0;
 }

 void Marine::be_damaged(int damage_earn)
 {
	 this->hp -= damage_earn;
	 if (this->hp <=0)
	 {
		 this->is_dead = true;
	 }
 }

 void Marine::move(int x, int y)
 {
	 this->coord_x = x;
	 this->coord_y = y;
 }

 void Marine::show_status()
 {
	 std::cout << " *** Marine *** " << std::endl;
	 std::cout << "Name : " << this->name << std::endl;
	 std::cout << " Location : ( " << this->coord_x << " , " << this->coord_y << " ) "
		 << std::endl;
	 std::cout << " HP : " << this->hp << std::endl;
 }

 int Marine::marine_cnt = 0;
 void Marine::show_total_marine()
{
	std::cout << "Total Marine : " << marine_cnt << std::endl;
}


