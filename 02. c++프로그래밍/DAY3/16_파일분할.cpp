// 16_���Ϻ��� 

// - ���� ���� ���

// 4) Ŭ���� ����ڴ� ��� ������ �����ϰ� 1), 2) �� ����� ����ϸ�˴ϴ�.
#include "Point.h"

// 1) Point.h ������ ���� ������ ��������.
#if 0
class Point
{
	int x;
	int y;
public:
	// Ŭ���� �ȿ��� ����Լ��� ���� �����մϴ�.
	Point(int a, int b);
	~Point();
	void set(int a, int b);
};
#endif


// 2) Point.cpp ������ ���� �Ʒ� ������ �Լ��� ��������.
// 3) �̶� �� �Լ��̸� �տ��� "Point::" �� ���� "Ŭ������::" �� �ٿ��־� �ش� �Լ��� ���ԵǾ��ִ� Ŭ������ �˷��ݴϴ�.
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