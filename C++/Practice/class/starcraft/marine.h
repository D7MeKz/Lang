#pragma once
#ifndef  MARINE_H
#define MARINE_H
#include<iostream>
#include<string>
class Marine {
private:
	static int marine_cnt; 
	int hp; // ü��
	int coord_x, coord_y; // Position
	int damage; // ���ݷ� 
	bool is_dead;
	std::string name;

public:
	Marine();
	Marine(int x, int y, const std::string name);
	~Marine();

	int attack() const;
	void be_damaged(int damage_earn);
	void move(int x, int y);

	void show_status();
	static void show_total_marine();
};

#endif // ! MARINE_H

