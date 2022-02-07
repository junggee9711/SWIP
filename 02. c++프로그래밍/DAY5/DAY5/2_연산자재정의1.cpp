// 2_������������1 - 182 
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	// �� ���� ������ �ϰ� �ͽ��ϴ�.
	// ������ ���� ���� ���� �ڵ�� ?
	Point p3 = Add(p1, p2);		// C ��� ��Ÿ��
	Point p4 = p1.Add(p2);		// Java ��Ÿ��
	Point p5 = p1 + p2;			// C++ ��Ÿ��  => �̰� ���� ���� ����!! ������ �����Ǹ� �̿��� �ڵ�

	// a+b ��� �Ҷ�,
	// 1. a, b �� ��� primitive Ÿ���̸� �׳� ���� ����
	// 2. user defined �̸�, "����Լ�" a.operator+(b) �� ã�� �˴ϴ�. ������ operator+() ��� �Լ� ȣ��...
	// 3. �Ǵ�, "����Լ� �� �ƴ�" operator+(a, b) �� ã�� �˴ϴ�. ������ ȣ��...
	// 4. 1, 2, 3 �� ��� �����ϸ� error.

}
