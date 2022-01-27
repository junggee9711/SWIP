// 20_this4 129 page

#include <iostream>

class Car
{
	int speed;
public:
	void set(int speed)
	{
		// this 활용 1. 멤버임을 명확히 하고 싶을때
		//	- speed 라고만 하면 지역변수(set 의 인자)의 speed 입니다. (C/C++ 은 가장 가까운 것으로 인식)
		//	- 멤버임을 명확히 하려면 아래와 같이 적음.
//		speed = speed;
		this->speed = speed;				// *(&this).speed = speed;
	}
	// this 활용 2. this 를 반환하는 함수 - 중요!!
	Car* go() { return this; }
	Car& go2() { return *this; }			// ==> 129 page 아래 박스 (참조 리턴)
};

int main()
{
	Car c;
	c.set(10);
	// this 를 반환하는 함수는 함수 호출을 연속적으로 할 수 있습니다.
	// => 자기 자신의 "class/class주소" 를 반환합니다.
	c.go()->go()->go()->go();				// *(*(&c.go())).go()...
	c.go2().go2().go2().go2();				// class 를 return 하기 때문에 . 으로 호출

	std::cout << "A" << "B" << "C";			// 는 아래와 같습니다.
	std::cout.operator<<("A").operator<<("B").operator<<("C");


}