// 22_�������Լ�4

#include <iostream>

// Point.h
class Point
{
public:
	int x;
	int y;
	Point(int x, int y);
	void set(int a, int b);
	void print() const;							// 1) �����Ϸ��� ������ ���� const ���� �ƴ��� �Ǵ��ϹǷ�,
												//    ���� const �� �־����.
};

// Point.cpp
//#include "Point.h"
Point::Point(int x, int y) : x(x), y(y) {}

void Point::set(int a, int b)
{
	x = a;
	y = b;
}

void Point::print() const						// 2) ��� ��� �Լ��� �ܺ� ������ const �� �ݵ�� �ٿ�����
												//	=> �����Ϸ��� ����� �ƴ� ��� �Լ��� �򰥸��� �ֱ� ������
{
	std::cout << x << ", " << y << std::endl;
}

int main()
{
				
}
