// 10_OOP4

#include <iostream>

// - ��� �Լ��� �޸�

struct Rect
{
	// 1) ��� ������ (�ٸ� ���� �ʵ�(field) ��� �մϴ�.)
	//   => Rect rc1, Rect rc2 �� �����ϸ� ��� ����Ÿ�� ���� �޸𸮿� �����.
	int left;
	int top;
	int right;
	int bottom;

	// 2) ��� �Լ� (�ٸ� ���� �޼ҵ�(method) ��� �մϴ�.)
	//   => Rect �� ������ �����ص� �Լ��� �޸𸮿� �ѹ��� �����.
	//   => �ϳ��� �Լ��� call �ؼ� '����' �� &rc1, &rc2 �� �ٸ��� �����ϴ� �� ����.
	int getArea()								// int getArea(Rect* this). �����Ϸ��� �ٲ���
	{
		return (right - left) * (bottom - top);	// (this->right - this->left)
	}											// this->right == *this = right

	void draw()									// void draw(Rect* this)
	{
		std::cout << "draw rect" << std::endl;
	}
};


int main()
{
	Rect rc1 = { 1,1,10,10 };
	Rect rc2 = { 2,2,5,5 };

	rc1.getArea();			// C++ �����Ϸ��� ��ü�� "struct reference��" �Լ� ����ó�� ������ �ݴϴ�.
							// getArea(&rc1); / getArea(&rc2);
}