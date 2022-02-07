// 20_this3

#include <iostream>

class Test
{
	int data;
public:
	void f1()			// 컴파일 시, void f1(Test* this) 로 변경
	{
		std::cout << this << std::endl;
		data = 10;		// 컴파일 시, this->data = 10; 으로 변경
	}

	static void f2()	// 컴파일 시, void f2() 입니다.
	{
//		std::cout << this << std::endl;		// error. this (객체의 주소)가 없습니다.
//		data = 10;							// error. this->data = 10 으로 변경해야 하는데...
											// this 가 없습니다.
											// 그래서, static 멤버 함수에서는 인스턴스 멤버에 접근이 안되는 겁니다!!!!!!!
	}
};

int main()
{
	Test t;
	t.f1();				// f1을 호출하려면 객체가 필요합니다.
						// 컴파일 시, f1(&t) 로 변경되는 원리 입니다.


	Test::f2();			// 객체 없이 호출했습니다.
						// 따라서, 컴파일 되어도 "f2()" 입니다.
						// 즉, class 객체의 주소 인자가 추가 될수 없습니다.

}