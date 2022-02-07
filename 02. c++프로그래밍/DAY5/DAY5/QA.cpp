// QA

#include <iostream>

int x = 0;
int f1()  { return x; }
int& f2() { return x; }

int main()
{
	f1();	// ��ȯ���� "�� 5"
	f2();	// ��ȯ���� x �޸��� ����

	int n = 3;

	int ret = ++n * ++n;			// ++n �� return by reference �Դϴ�.

	std::cout << ret << std::endl;  // ��� ������ ������ => undefined. but, ��κ� 25

	std::cout << ++n  << ", " << ++n << std::endl;	// return by reference �̹Ƿ� 5, 5 ���

	// ����ó�� �ݺ��ڻ� �ƴ϶� raw pointer (��¥ ������) �� ���� ����Դϴ�.
	int x[5] = { 1,2,3,4,5 };
	int* p = x;

	std::cout << *p << ", " << *++p << std::endl;	// p�� x[0] �� ���� & return by reference �̹Ƿ� 2, 2 ���


	// *�� ������� ��� ��� undefined �̱⶧���� ������� ������!
}