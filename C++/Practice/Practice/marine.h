#pragma once
#ifndef  MARINE_H
#define MARINE_H
#include<iostream>
#include<string>
class Marine {
private:
	int hp; // 체력
	int coord_x, coord_y; // Position
	int damage; // 공격력 
	bool is_dead;
	std::string name;

public:
	Marine();
	Marine(int x, int y, const std::string name);
	~Marine();

	int attack();
	void be_damaged(int damage_earn);
	void move(int x, int y);

	void show_status();

};

#endif // ! MARINE_H

