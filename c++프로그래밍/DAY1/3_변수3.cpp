// 20 page ����

#include <iostream>
struct Point
{
	int x;
	int y;
};

int main()
{
	int		n = 0;
	Point	p1 = { 0, 0 };
	int		x1[3] = { 1,2,3 };

	// 1. C++11 ���� �߰��� "�ϰ��� �ʱ�ȭ (uniform initialization)" ����
	//	  ���� "�߰�ȣ �ʱ�ȭ" ��� �մϴ�.
	int		n2 = { 0 } ;
	Point	p2 = { 0, 0 };
	int		x2[3] = { 1,2,3 };

	// 2. �����ʱ�ȭ(direct initialization) : '=' �� ���� ���
	//	  �����ʱ�ȭ(copy initialization) : '=' �� �ִ� ���
	//   -> �� 2���� �ణ�� ���̰� �ֽ��ϴ�. (��ü���� ��ﶧ ����)
	int		n3{ 0 };
	Point	p3{ 0, 0 };
	int		x3[3]{ 1,2,3 };


	// 3.
	int n4 = 3.4; // C/C++ ���� ���� (�Ҽ����� ������� ������)
				  // ������, �ʹ� �����ϴ�. �ٸ� ��κ��� ������ ����!

	int n5{ 3.4 }; // error. �߰�ȣ �ʱ�ȭ�� ������ �ս��� �ִ� ��� ����
	char c{ 500 }; // error. 1byte �� 0~255 �� ����.
				   // -> �̷��� ������ ������� �ڵ� �ϴ� ���� prevent narrow ��� �θ��ϴ�. (21 page ��)
}