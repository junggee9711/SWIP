
struct Point
{
	int x;
	int y;

	Point(int a, int b) : x(a), y(b) {};
}
// Point p( 1, 1 );, Point p{ 1, 1 };, Point p = { 1, 1 )}; 

struct Point
{
	int x;
	int y;
}
// 1. ()
//  Point p( 1, 1 ); -> �� error?
// => C++ ���� 1) �����ڸ� ȣ���Ͽ� �ʱ�ȭ�ϴ� ����

// 2. {}
// Point p{ 1, 1 };, Point p = { 1, 1 )}; 
// => C ���� 1) struct �ʱ�ȭ �ϴ� ����
//			 2) C++ �� �����鼭 "������"�� ������, �̰� ���� ȣ���Ͽ� �ʱ�ȭ�ϴ� �������� �ٲ�
