// 2_������������5-1

#include <cstdio>

namespace std
{
	class ostream
	{
		// ���� ostream �� �پ��� ��� �����Ͱ� �ֽ��ϴ�.
		char* buff;
		int size;
		int count;
	public:
		// �׸���, opeartor<<() �Լ� �ȿ��� ��������͸� �����ϴ� �ڵ尡 �ֽ��ϴ�.
		// => �׷���, operator<<() �Լ��� ��� ��� �Լ��� �� �� �����ϴ�.
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		ostream& operator<<(double d) { printf("%f", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s", s); return *this; }

	};
	ostream cout;		
}

int main()
{
	std::ostream& os = std::cout;

	os << "hello";			// os �� �ᱹ std::cout �� ����

	const std::ostream& os2 = std::cout;

//	os2 << "hello";			// error. os2.operator<<("hello") �ε�.
							// os2 �� ��� ��ü�̹Ƿ� ��� ��� �Լ��� ȣ�� �����մϴ�.
							// �׷���, operator<<(const char*)�� ��� ����Լ��� �ƴմϴ�.
}



