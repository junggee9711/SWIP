// 30_인터페이스2

#include <iostream>


// 2. 약한 결합 (loosely coupling)
//	: 하나의 클래스가 다른 클래스 사용시, 기반클래스인 추상 클래스를 통해서 사용하는것.
//	=> 교체 가능한 유연한 디자인..

// - 용어 정리
// 1) 인터페이스 : 지켜야하는 규칙만 제공 ( = 순수가상함수만 들어있는 클래스)
// 2) 추상클래스 : 지켜야하는 규칙 + 물려주기위한 멤버들

// 다른 객체지향 언어는 "interface" 라는 키워드가 있지만,
// C++ 은 추상 클래스 문법으로 인터페이스도 만듭니다.


// 시험문제 : C++ 에서는 "interface" 키워드를 이용해서 인터페이스를 만든다. false //

//---------------------------------------------------------------------------------
// 카메라를 먼저 설계하지 말고, 규칙(기반클래스의 추상클래스)을 설계하자.
// 규칙 : "모든 카메라는 아래 기반클래스로부터 파생되어야 한다." 라고 하지말고,
//		  "모든 카메라는 ICamera 인터페이스를 구현해야 한다." 라고 표현합니다.

class ICamera				// 멤버변수는 제공하지 않고, 규칙만 제공
{							// = "인터페이스"
public:
	virtual void take() = 0;
};


// 아직 카메라는 없지만, 규칙은 있다.. 규칙대로만 사용하면 된다.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};

class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "take UHD picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);		// ok.

	UHDCamera uhc;
	p.useCamera(&uhc);		// ok.
}