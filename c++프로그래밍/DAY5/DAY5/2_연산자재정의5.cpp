// 2_연산자재정의5 - 1번복사..
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

std::ostream& operator<<(std::ostream& os, const Point& p)	// std::ostream& os 에는 const를 붙일수 없음 (5-1 에서 설명)
{
	os << p.x << ", " << p.y;
	return os;
}

int main()
{
	int n = 10;
	Point p(1, 1);

	std::cout << n; // ok. cout.operator<<(int)
	std::cout << p; // ??. cout.operaotr<<(Point) 가 필요합니다.
					// 그런데, ostream 클래스는 표준에 있는 클래스이므로, 사용자가 멤버함수 추가 불가능
					// 이때, 멤버로 안되면 일반함수로 하면 됩니다.
					// operator<<(cout, p)
					// opeartor<<(ostream, Point) 를 만들면 해결됩니다.
}




