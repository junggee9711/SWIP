// 2_연산자재정의2 - 182 
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}

	// 멤버로 만든 operator+() 함수
	// *주의 : 함수 이름이 "operator+" 인것!
	Point operator+(const Point& p)
	{
		std::cout << "member operator+" << std::endl;
		Point temp(x + p.x, y + p.y);
		return temp;
	}
};
int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	Point p3 = p1 + p2;			// C++ 스타일
	/* 시험문제 : + 는 이항연산자 이지만 "멤버 함수로 구현시 인자는 두개 받으면 됩니다." false. 한개 받음*/
}
