// 25 page

struct Point
{
	int x;
	int y;
};

int main()
{
	Point pt = { 1,2 };
	int arr[3] = { 1,2,3 };

	// 1. C++17 ���� ����ü�� �迭���� ���� ������ �Ʒ�ó�� �����մϴ�.
	//	-> "structure bining" �̶�� �����Դϴ�.
	auto [x, y] = pt;		// int x = pt.x
							// int y = py.y
							// ���̽� : x, y = (1, 2) ==> unpacking
							// ����ü�� ������ x�� y��� ������ �и��ؼ� ����
	// int[x1, y1] = pt;	// error. auto �� �˴ϴ�.

	auto [a, b, c] = arr;	// �迭�� ��쿡�� ����.
							// ��, ������ ��ġ�ؾ� �մϴ�.
	// auto [a2, b2] = arr;	// error. ���� �ٸ�

}