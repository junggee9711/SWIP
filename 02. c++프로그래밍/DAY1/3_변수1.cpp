// 3_����1 - 18 page

#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	struct Point p1;		// C��Ÿ��
	Point p2;				// 1. C++������ struct ��� �ȴ�.

	int n1 = 0x10;			// 2. 16���� ǥ���
	int n2 = 0b10;			// 3. C++11, C11 ���� 2���� ǥ��� ����.
	int n3 = 1'000'0'0'0;	// 4. C++11 ���� �ڸ��� ǥ��� ����. (1000000 ���� �ν���)
							//	  �ᱹ ' �� �ּ��� ȿ�� - �����Ϸ��� ������ ���ͷ� ������ ' �� �����Ѵ�.

	// 5. ���ο� Ÿ��
	bool b = true;			// �Ǵ� false / 0 �Ǵ� 1. ũ�� 1 byte

	long long n = 0;		// 64bit (8 byte) ����

}