// 10_OOP2

#include <iostream>


// OOP 핵심 1. 필요한 타입을 먼저 설계 하자.
struct Rect
{
	int left;
	int top;
	int right;
	int bottom;
};


int getRectArea(const Rect& rc)				// 구조체를 사용하기 때문에 const Rect& 사용
{
	return (rc.right - rc.left) * (rc.bottom - rc.top);
}

void drawRect(const Rect& rc)				// 이 함수 구현은 생략함
{
	std::cout << "draw rect" << std::endl;
}

int main()
{
	Rect rc = { 1,1,10,10 };
	int area = getRectArea(rc);

}