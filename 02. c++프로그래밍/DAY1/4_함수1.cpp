// 4_�Լ�1 28 page

// C�� �ٸ� C++�Լ��� Ư¡ 1. ����Ʈ ����

#include <iostream>

// ���� ���� 1) �Լ��� ����� �������� �и��Ҷ��� �ݵ�� ���𿡸� default ���� ǥ���ؾ� �Ѵ�.
void foo(int a, int b = 0, int c = 0);

int main()
{
	foo(1, 2, 3);
	foo(1, 2);				// 1, 2, 0
	foo(1);					// 1, 0, 0
							// C++ �� ���� �׻� ������ �����ϰ�,
							// ���̽��� default ���� �ٲ��� ������ ���������� �����Ѵ�.
}

// - default parameters
void foo(int a, int b /*= 0*/, int c /*= 0*/)
{
	std::cout << a << ", " << b << ", " << c << std::endl;
}

// ���� ���� 2) ������ ���ں��� ���ʴ�θ� ������ �� �ִ�. /* ���� ���� ����*/
void f1(int a,		int b = 0,	int c	 );			// error.
void f2(int a = 0,	int b,		int c = 0);			// error.
