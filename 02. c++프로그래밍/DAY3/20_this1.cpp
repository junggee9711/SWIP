//20_this1 126 page

#include <iostream>


// - this : ���� �Լ��� ȣ���Ҷ� ����� ��ü(p1, p2)�� �ּ� �Դϴ�.
//			=> python ���� "self"

class Point
{
	int x;
	int y;
public:

	void set(int a, int b)
	{
		x = a;
		y = b;
	}
};



int main()
{
	Point p1;
	Point p2;
	p1.set(10, 20);				// set(&p1, 10, 20) 
	p2.set(10, 20);				// set(&p2, 10, 20) ó�� �����Ϸ��� �����մϴ�. ��, 3���� ���� ����
								// => set �Լ��� �޸𸮿� p1, p2 ���� ����Ǵ°��� �ƴϱ� ������,
								//     &p1, &p2 �� ����

								// => ��, �����Ϸ��� ��� �Լ� set �� �Ʒ�ó�� �����մϴ�.
#if 0
								void set(Point * this, int a, int b)
								{
									this->x = a;	// *(&p1).x = a;
									this->y = b;	// *(&p2).y = b;
													/* a->b == *(a).b */
								}
#endif
}