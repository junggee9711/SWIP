// 9 page

#include <algorithm>
using namespace std;

int count = 10;

int main()
{
	// ��� C++ ǥ���� "std" ��� namespace �ȿ� �ֽ��ϴ�.
	int n = std::min(10, 30); // C++ ǥ�� �Լ�. <algorithm> ����� �ֽ��ϴ�.

	// int n2 = count; // �� �����ϱ��?
					   // C++ ǥ�ؿ� "std::count()" ��� �Լ��� �ֽ��ϴ�.
					   // using namespace std ������ �������� count �� �̸� �浹
	//	=> �̸� �浹�� ���� �߻��ϴ� �����̹Ƿ� using �� ������� �ʴ°��� ����
}