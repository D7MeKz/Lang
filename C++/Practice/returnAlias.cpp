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
	// get_x로부터 가져온 변수는 문장이 끝나면 소멸되므로 레퍼런스를 가질 수 없다. (자동으로 소멸되는 임시 객체)
	// int& d = a.get_x();
	// d = 2;
	// a.show_x();

	// a.x = 3 과 같은 의미
	// 레퍼런스를 리턴하는 함수는 그 함수 부분을 리턴하는 원래 변수로 치환해도 된다. 
	a.access_x() = 3;
	return 0;

}