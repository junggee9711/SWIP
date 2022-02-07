// 30_인터페이스1

#include <iostream>


// 1. 강한 결합 (tightly coupling)
//	: 하나의 클래스가 다른 클래스 사용시, 클래스 이름을 직접 사용하는것.
//	=> 다른 기능을 추가, 교체 불가능한 경직된 디자인...

class Camera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};

class People
{
public:
	void useCamera(Camera* p)   { p->take(); }
	void useCamera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);		// useCamera 가 Camera* 를 입력으로 받으므로,
							// void useCamera(HDCamera* p) 를 추가해야 ok.
}