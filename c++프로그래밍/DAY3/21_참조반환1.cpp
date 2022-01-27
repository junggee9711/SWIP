// 21_참조반환1

#include <iostream>

struct Point
{
	int x, y;
};

void f1(Point  pt) {}			// call by value : 복사본 생성
void f2(Point& pt) {}			// call by reference : 복사본이 없다.

int main()
{
	Point pt = { 1, 2 };
	f1(pt);
	f2(pt);
}