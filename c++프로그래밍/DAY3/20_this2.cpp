//20_this2 

#include <iostream>

class Point
{
	int x;
	int y;
public:
	void set(int a, int b)
	{
		x = a;
		y = b;

		// ��� �Լ� �ȿ��� this Ű���带 ����� �� �ֽ��ϴ�.
		// - this : ���� �Լ��� ȣ���Ҷ� ����� ��ü(p1, p2)�� �ּ� �Դϴ�.
		std::cout << this << std::endl;
	}
};

int main()
{
	Point p1;
	Point p2;
	p1.set(10, 20);
	p2.set(10, 20);

	std::cout << &p1 << std::endl;
	std::cout << &p2 << std::endl;
}