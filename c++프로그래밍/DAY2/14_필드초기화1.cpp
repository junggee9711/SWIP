// 14_�ʵ��ʱ�ȭ1 91 page

class Point
{
	int x = 0;
	int y = 0;		// - �ʵ�(field) �ʱ�ȭ
					//	: C++ ���� �� �ڵ尡 ���˴ϴ�.
public:
	Point()							 {}
	Point(int a) : x(a)				 {}
	Point(int a, int b) : x(a), y(b) {}
};
// �ʵ� �ʱ�ȭ�� ��� �ʱ�ȭ�� �ϴ� ���ϱ�?
// => ��ó�� ����� �����Ϸ��� �Ʒ� ó�� �����ϴ� ���� �Դϴ�.

class Point
{
	int x; /* = 0; */
	int y; /* = 0; */
					
public:
	Point()			    /* : x(0), y(0) */ {}
	Point(int a)		: x(a) /*, y(0) */ {}
	Point(int a, int b) : x(a), y(b) {}
};


int main()
{
	Point p(1);		// x = 1, y = 0
}