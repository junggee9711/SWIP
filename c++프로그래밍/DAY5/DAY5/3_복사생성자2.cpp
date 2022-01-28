// 3_���������2

#include <iostream>

// - ���� �����ڰ� ȣ��Ǵ� 3���� ���
class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {}

	Point(const Point& p) : x(p.x), y(p.y)
	{
		std::cout << "Point(const Point&)" << std::endl;
	}
};
//void f1(Point pt) {}
void f1(const Point& pt) {}

Point pt;
Point f2()
{
	return pt;				// �� ����,
							// ���Ͽ��ӽð�ü temp(pt); ���� <== "���� ������" ȣ��
							// return temp;
}	
Point& f3()					// "������ȯ" �̹Ƿ� �ӽð�ü ���� �ȵ�.
{							// "���� ������" ȣ�� �ȵ�.
	return pt;
}

int main()
{
	// ���� vs ����
	Point p1;		

	// 1. ��ü�� �ڽŰ� ������ Ÿ������ �ʱ�ȭ �ɶ�
	Point p2(p1);			// "���� ������" ȣ��	
	Point p3 = p1;			// "���� ������" ȣ��
	
	// * ���� : �Ʒ� �ڵ�� "����" �Դϴ�.
	Point p4;				// "����Ʈ ������" ȣ��
	p4 = p1;				// "���Կ����ڶ�"�� �Լ� ȣ�� p4.operator=(p1)

	// 2.  �Լ��� ��ü�� call by value �� ������
	f1(p1);					// Point pt = p1 �� ������� f1 �Լ��� ���ڰ� ���޵�.
							// "���� ������" ȣ��
							// f1 �� ���ڸ� const Point& pt �� �ٲٸ� ���� �����ڰ� ȣ�� �ȵ�/

	// 3. �Լ��� ��ü�� ������ ��ȯ�� �� (return by value)
	f2();					// "���� ������" ȣ��
	f3();					


	/* ���蹮�� : ���� �����ڰ� ȣ����� �ʴ� ��츦 ã������ (3���� ȣ��, 1���� ȣ�� �ȵ�)
				  call by value/reference, return by value/reference ���� ������ 1�� �� */

}
