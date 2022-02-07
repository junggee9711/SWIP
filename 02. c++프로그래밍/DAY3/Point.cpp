// Point.cpp

#include "Point.h"		// .cpp 파일에는 헤더를 포함해 주세요.

Point::Point(int a, int b) : x(a), y(b) {}
Point::~Point() {}
void Point::set(int a, int b)
{
	x = a;
	y = b;
}