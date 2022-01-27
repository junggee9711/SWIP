// 24_상속과생성자2 136 page

#include <iostream>

class Base
{
	int data1;
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
	int data2;
public:
	// 사용자가 만든 코드		// 컴파일러가 변경한 코드
	Derived()				// Derived() : Base()		<== 기반 클래스를 멤버 초기화
	{ std::cout << "Derived()" << std::endl; }
	Derived(int a)			// Derived(int a) : Base()  <== 기반 클래스를 멤버 초기화
	{ std::cout << "Derived(int)" << std::endl; }
	~Derived()				
	{ 
		std::cout << "~Derived()" << std::endl; 
		// ~Base();										<== 컴파일러가 추가한 코드
	}
};

int main()
{
	//	Derived d1;			// call Derived::Derived()	<== 자동으로 생성자를 부름
	Derived d1(5);
}

// Base 의 생성자가 먼저 불리고 Derived 의 생성자가 나중에 불리는데, Base 의 생성자는 디폴트 생성자가 불림.