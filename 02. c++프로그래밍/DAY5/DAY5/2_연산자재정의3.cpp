// 2_연산자재정의3 
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}


	Point operator+(const Point& p)
	{
		std::cout << "member operator+" << std::endl;
		Point temp(x + p.x, y + p.y);
		return temp;
	}

	friend Point operator+(const Point& p1, const Point& p2);
};

Point operator+(const Point& p1, const Point& p2)
{
	std::cout << "not member operator+" << std::endl;

	Point temp(p1.x + p2.x, p1.y + p2.y);
	return temp;
}

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	Point p3 = p1 + p2;		// 컴파일러가, 
							// 1. p1.operator+(p2) 를 찾음
							// 2. operatr+(p1, p2) 를 찾음  ==> 이것은 "멤버함수가 아님" !!!
							//  => 이때, 외부함수에서 private 접근을 위해 friend 키워드를 사용
							//  => 함수가 둘다 있으면, 우선순위로 멤버함수(1번)을 먼저 부름

	// 멤버가 좋은가요? 일반함수가 좋은가요?
	// 주장 1. private 을 접근하기에는 멤버가 좋지 않을까?
	// 주장 2. 멤버로 안될때가 있다. 일관성을 위해 일반함수로 모두 통일하자.

	// 아래 3줄을 멤버로 만든다고 생각해 보세요
	Point p4 = p1 + p2;		// p1.operator+(Point)
	Point p5 = p1 + 5;		// p1.operator+(int) => 만들면 됨
	Point p6 = 5 + p1;		// 5.operator(Point) 는 될수 없습니다.
							// 즉, 이경우는 멤버 함수로 구현이 안됩니다.
							// 하지만,
							// 멤버함수가 아닌 operator+(int, Point) 로 만들면 됩니다.
}
