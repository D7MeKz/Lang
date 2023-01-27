#pragma once
#include<iostream>
#include <string>

class EmployeeList {
private:

public:
};


class Employee {
private:
	std::string name;
	int age;
	std::string position;
	int rank;

public:
	Employee(std::string name, int age, std::string position, int rank)
		:name(name), age(age), position(position),rank(rank){}
	
	Employee(const Employee& employee) {
		this->name = name;
		this->age = age;
		this->position = position;
		this->rank = rank;
	}

	void print_info() const;

};
