// 2_������������4 - 187 page
// 
// #include <iostream>
#include <cstdio>

namespace std
{
	class ostream
	{
	public:
		// ���� cout �� prinf �� �ƴ� "�� OS�� �����ϴ� ȭ�� ��� �Լ�" ���.
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		ostream& operator<<(double d) { printf("%f", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s", s); return *this; }

		// �� �ܿ��� ���� ǥ���� ostream ����
		// ��� ǥ�� Ÿ�Կ� ���ؼ� "opeartor<<" �� �����ϰ� �ֽ��ϴ�.
	};
	ostream cout;		// ostream class �� ������ü cout �� ����
}

int main()
{
	int n = 10;
	double d = 3.4;

	std::cout << n << ", " << d << "\n";

	std::cout << n;		// cout.operator<<(int) ȣ��
	std::cout << d;		// cout.operator<<(double) ȣ��
						// => ������ ������!!
}



