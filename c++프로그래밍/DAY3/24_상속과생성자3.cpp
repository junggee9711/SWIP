// 24_상속과생성자3

#include <iostream>

class Base
{
	int data1;
public:
//	Base()		{}
	Base(int a) {}
	~Base()		{}
};
class Derived : public Base
{
	int data2;
public:
	// 기반 클래스에 "디폴트 생성자가 없을 때" 아래 처럼만 만들면 컴파일 에러입니다.
//	Derived()      {}		// Derived() : Base() {}
//	Derived(int a) {}		// Derived(int a) : Base() {}
							// => Base() 가 주석처리여서 error 발생
							// => Base(int a) 까지도 없애서 생성자를 아예 없애면,
							//    컴파일러가 Base() 를 자동 생성해서 ok.
	~Derived()	   {}

	// 해결책은 사용자가 직접 "존재하는" 기반 클래스 생성자를 호출하는 코드를 제공해야 합니다.
	Derived()	   : Base(0) {}
	Derived(int a) : Base(a) {}
};

int main()
{
	//	Derived d1;
	Derived d1(5);
}

// Base 의 생성자가 먼저 불리고 Derived 의 생성자가 나중에 불리는데, Base 의 생성자는 디폴트 생성자가 불림.