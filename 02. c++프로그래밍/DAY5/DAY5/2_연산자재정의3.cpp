// 2_������������3 
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

	Point p3 = p1 + p2;		// �����Ϸ���, 
							// 1. p1.operator+(p2) �� ã��
							// 2. operatr+(p1, p2) �� ã��  ==> �̰��� "����Լ��� �ƴ�" !!!
							//  => �̶�, �ܺ��Լ����� private ������ ���� friend Ű���带 ���
							//  => �Լ��� �Ѵ� ������, �켱������ ����Լ�(1��)�� ���� �θ�

	// ����� ��������? �Ϲ��Լ��� ��������?
	// ���� 1. private �� �����ϱ⿡�� ����� ���� ������?
	// ���� 2. ����� �ȵɶ��� �ִ�. �ϰ����� ���� �Ϲ��Լ��� ��� ��������.

	// �Ʒ� 3���� ����� ����ٰ� ������ ������
	Point p4 = p1 + p2;		// p1.operator+(Point)
	Point p5 = p1 + 5;		// p1.operator+(int) => ����� ��
	Point p6 = 5 + p1;		// 5.operator(Point) �� �ɼ� �����ϴ�.
							// ��, �̰��� ��� �Լ��� ������ �ȵ˴ϴ�.
							// ������,
							// ����Լ��� �ƴ� operator+(int, Point) �� ����� �˴ϴ�.
}
