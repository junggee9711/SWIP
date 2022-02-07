// 16_파일분할 

// - 파일 분할 방법

// 4) 클래스 사용자는 헤더 파일을 포함하고 1), 2) 를 지운뒤 사용하면됩니다.
#include "Point.h"

// 1) Point.h 파일을 만들어서 선언을 넣으세요.
#if 0
class Point
{
	int x;
	int y;
public:
	// 클래스 안에는 멤버함수의 선언만 제공합니다.
	Point(int a, int b);
	~Point();
	void set(int a, int b);
};
#endif


// 2) Point.cpp 파일을 만들어서 아래 세개의 함수를 넣으세요.
// 3) 이때 각 함수이름 앞에는 "Point::" 와 같이 "클래스명::" 을 붙여주어 해당 함수가 포함되어있는 클래스를 알려줍니다.
#if 0
Point::Point(int a, int b) : x(a), y(b) {}
Point::~Point() {}
void Point::set(int a, int b)
{
	x = a;
	y = b;
}
#endif

int main()
{
	Point p(1, 2);
	p.set(10, 20);
}