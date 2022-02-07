// 29_추상클래스

#include <iostream>


// 추상클래스(abstract class) : t순수 가상함수가 한개 이상인 클래스
// -   특징    : 객체를 생성할수 없다.
// - 사용 의도 : 특정한 멤버 함수는 반드시 만들어야 한다고 지시하는 것!!!

class Shape
{
public:
	virtual void draw() = 0;	// 순수 가상함수 (pure virtual function)
								// 구현부가 없고, "=0" 으로 끝난다.
};

class Rect : public Shape
{
public:
	// 파생클래스에서 Shape 으로부터 상속된 "draw()" 순수 가상함수의
	//  1) 구현부를 제공하지 않으면 : Rect 도 추상
	//  2)		   제공하면        : Rect 는 추상 아님.
	virtual void draw() override {}
};



int main()
{
//	Shape s;					// error. 추상 클래스 객체는 만들수 없다.
	Shape* p;					// ok.	  객체가 아닌 포인터는 가능

	Rect r;						// ok.	  파생클래스에서 draw()의 구현부를 제공했으므로
}