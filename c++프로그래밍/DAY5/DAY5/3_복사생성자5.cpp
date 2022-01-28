#include <iostream>
// 1. 복사 생성자 vs 디폴트 생성자
// 2. 복사 생성자가 호출되는 3가지 경우

class Point
{
	int x = 0, y = 0;
public:
	Point() {}

	Point(const Point& pt) : x(pt.x), y(pt.y)
	{
		std::cout << "복사생성자" << std::endl;
	}
};
void f1(Point pt) {} 

int main()
{
	Point p1;
	Point p2(p1);
}

