// 10_OOP3

#include <iostream>


// OOP 핵심 1. 필요한 타입을 먼저 설계 하자.
// OOP 핵심 2. 상태를 나타내는 데이터와 상태를 가지고 연산을 수행하는 함수를 묶어서 타입을 설계하자.
//			  => C++ 구조체는 함수를 포함할수 있다. (C는 불가)
			
struct Rect
{
	int left;
	int top;
	int right;
	int bottom;

	int getArea()
	{
		return (right - left) * (bottom - top);		// 구조체 안의 변수도 바로 사용 가능
	}

	void draw()
	{
		std::cout << "draw rect" << std::endl;
	}
};


int main()
{
	Rect rc = { 1,1,10,10 };
//	int area = getRectArea(rc);		// 1
	int area = rc.getArea();		// 2 - better!
									// 함수에 Rect 라는 이름도 붙일 필요 없음.
	rc.draw();

}