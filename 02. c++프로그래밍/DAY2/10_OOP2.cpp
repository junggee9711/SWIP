// 10_OOP2

#include <iostream>


// OOP �ٽ� 1. �ʿ��� Ÿ���� ���� ���� ����.
struct Rect
{
	int left;
	int top;
	int right;
	int bottom;
};


int getRectArea(const Rect& rc)				// ����ü�� ����ϱ� ������ const Rect& ���
{
	return (rc.right - rc.left) * (rc.bottom - rc.top);
}

void drawRect(const Rect& rc)				// �� �Լ� ������ ������
{
	std::cout << "draw rect" << std::endl;
}

int main()
{
	Rect rc = { 1,1,10,10 };
	int area = getRectArea(rc);

}