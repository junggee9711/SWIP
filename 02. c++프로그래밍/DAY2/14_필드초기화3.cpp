// 14_�ʵ��ʱ�ȭ3

#include <iostream>

class Point
{
	int x;
	int y;
public:
//	Point()				{ x = 0; y = 0; std::cout << "Point" << std::endl; }
	Point(int a, int b) { x = 0; y = 0; std::cout << "Point(int, int)" << std::endl; }
};


class Rect
{
//	Point ptFrom(0,0);		// ���� �ؼ��� "��� Ÿ�� �Լ���(����)" �� ���� "�Լ����"���� �ؼ��ؼ� ����
	Point ptFrom{ 0,0 };	// ok. �߰�ȣ ǥ����� ����ϸ� �˴ϴ�.
	Point ptTo{ 0,0 };
public:
	// Point �� ����Ʈ �����ڰ� ���� ������ �������� ������ ������,
	// �����Ϸ��� �ʵ� �ʱ�ȭ�� ���� �Ʒ��� ���� �ٲٱ� ������ ������.
	Rect() /* : ptFrom(0, 0), ptTo(0, 0) */ {}

	Rect(int x1, int y1, int x2, int y2) : ptFrom(x1, y1), ptTo(x2, y2)
	{
		std::cout << "Rect()" << std::endl;
	}
};


int main()
{
	Rect rc1;
	Rect rc2(1, 1, 10, 10);
}

// 91 page �Ʒ��κ� - ��� �����͸� �ʱ�ȭ �ϴ� 3���� ���!
// 1) �ʵ��ʱ�ȭ 2) �ʱ�ȭ����Ʈ 3) ����