// 2_������������5 - 1������..
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

std::ostream& operator<<(std::ostream& os, const Point& p)	// std::ostream& os ���� const�� ���ϼ� ���� (5-1 ���� ����)
{
	os << p.x << ", " << p.y;
	return os;
}

int main()
{
	int n = 10;
	Point p(1, 1);

	std::cout << n; // ok. cout.operator<<(int)
	std::cout << p; // ??. cout.operaotr<<(Point) �� �ʿ��մϴ�.
					// �׷���, ostream Ŭ������ ǥ�ؿ� �ִ� Ŭ�����̹Ƿ�, ����ڰ� ����Լ� �߰� �Ұ���
					// �̶�, ����� �ȵǸ� �Ϲ��Լ��� �ϸ� �˴ϴ�.
					// operator<<(cout, p)
					// opeartor<<(ostream, Point) �� ����� �ذ�˴ϴ�.
}




