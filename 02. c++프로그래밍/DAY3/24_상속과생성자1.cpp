// 24_상속과생성자1 135 page

#include <iostream>

class Base
{
	int data1;
public:
	Base()		{ std::cout << "Base()"	   << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base()		{ std::cout << "~Base()"   << std::endl; }
};
class Derived : public Base
{
	int data2;
public:
	Derived()	   { std::cout << "Derived()"    << std::endl; }
	Derived(int a) { std::cout << "Derived(int)" << std::endl; }
	~Derived()	   { std::cout << "~Derived()"   << std::endl; }
};

int main()
{
//	Derived d1;
	Derived d1(5);
}

// Base 의 생성자가 먼저 불리고 Derived 의 생성자가 나중에 불리는데, Base 의 생성자는 디폴트 생성자가 불림.