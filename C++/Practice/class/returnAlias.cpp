#include<iostream>

class A {
	int x;

public:
	A(int c) : x(c) {}

	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { std::cout << x << std::endl; }

};

int main()
{
	A a(5);
	a.show_x();

	// 별명을 받아서 새로운 x의 값을 출력하게 된다. 
	int& c = a.access_x();
	c = 4;
	a.show_x(); // 4	
	a.get_x(); // 5

	// Error 
	// int& d = a.get_x();
	// d = 2;
	// a.show_x();
	return 0;

}