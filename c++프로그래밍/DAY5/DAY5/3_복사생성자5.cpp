#include <iostream>
// 1. ���� ������ vs ����Ʈ ������
// 2. ���� �����ڰ� ȣ��Ǵ� 3���� ���

class Point
{
	int x = 0, y = 0;
public:
	Point() {}

	Point(const Point& pt) : x(pt.x), y(pt.y)
	{
		std::cout << "���������" << std::endl;
	}
};
void f1(Point pt) {} 

int main()
{
	Point p1;
	Point p2(p1);
}

