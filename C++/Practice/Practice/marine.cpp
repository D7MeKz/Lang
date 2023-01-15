#include "marine.h"

Marine::Marine()
{
	this->hp = 50;
	this->coord_x = coord_y = 0;
	this->damage = 5;
	this->is_dead = false;
	this->name = "None";
}

 Marine::Marine(int x, int y, const std::string name)
{
	this->hp = 50;
	this->coord_x = x;
	this->coord_y = y;
	this->damage = 5;
	this->is_dead = false;
	this->name = name;
}

 Marine::~Marine() {
	 std::cout << this->name << " is deleted!!" << std::endl;
 }
 int Marine::attack()
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





