// 21_������ȯ1

#include <iostream>

struct Point
{
	int x, y;
};

void f1(Point  pt) {}			// call by value : ���纻 ����
void f2(Point& pt) {}			// call by reference : ���纻�� ����.

int main()
{
	Point pt = { 1, 2 };
	f1(pt);
	f2(pt);
}