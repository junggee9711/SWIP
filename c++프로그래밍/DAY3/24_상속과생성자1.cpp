// 24_��Ӱ�������1 135 page

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

// Base �� �����ڰ� ���� �Ҹ��� Derived �� �����ڰ� ���߿� �Ҹ��µ�, Base �� �����ڴ� ����Ʈ �����ڰ� �Ҹ�.