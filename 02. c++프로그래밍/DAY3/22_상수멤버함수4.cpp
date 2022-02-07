// 22_상수멤버함수4

#include <iostream>

// Point.h
class Point
{
public:
	int x;
	int y;
	Point(int x, int y);
	void set(int a, int b);
	void print() const;							// 1) 컴파일러가 선언을 보고 const 인지 아닌지 판단하므로,
												//    선언에 const 를 넣어야함.
};

// Point.cpp
//#include "Point.h"
Point::Point(int x, int y) : x(x), y(y) {}

void Point::set(int a, int b)
{
	x = a;
	y = b;
}

void Point::print() const						// 2) 상수 멤버 함수는 외부 구현시 const 를 반드시 붙여야함
												//	=> 컴파일러가 상수가 아닌 멤버 함수와 헷갈리수 있기 때문에
{
	std::cout << x << ", " << y << std::endl;
}

int main()
{
				
}
