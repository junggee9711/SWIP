// ���� ������ 92 page �Դϴ�.
#include <iostream>

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	// �Ʒ� 4���� ������ ������
	Point p1;		
	Point p2(1);	
	Point p3(1,2);	
	Point p4(p3);	
}


// 3:00 ���� �̾����ϴ�.
