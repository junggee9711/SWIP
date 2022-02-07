// 10_OOP3

#include <iostream>


// OOP �ٽ� 1. �ʿ��� Ÿ���� ���� ���� ����.
// OOP �ٽ� 2. ���¸� ��Ÿ���� �����Ϳ� ���¸� ������ ������ �����ϴ� �Լ��� ��� Ÿ���� ��������.
//			  => C++ ����ü�� �Լ��� �����Ҽ� �ִ�. (C�� �Ұ�)
			
struct Rect
{
	int left;
	int top;
	int right;
	int bottom;

	int getArea()
	{
		return (right - left) * (bottom - top);		// ����ü ���� ������ �ٷ� ��� ����
	}

	void draw()
	{
		std::cout << "draw rect" << std::endl;
	}
};


int main()
{
	Rect rc = { 1,1,10,10 };
//	int area = getRectArea(rc);		// 1
	int area = rc.getArea();		// 2 - better!
									// �Լ��� Rect ��� �̸��� ���� �ʿ� ����.
	rc.draw();

}