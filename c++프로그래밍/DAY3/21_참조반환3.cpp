// 21_������ȯ3

#include <iostream>

// - �� �ӽð�ü�� �����ؾ� �ұ�?

class Counter
{
public:
	int value = 0;

	Counter increment()
	{
		++value;
		return *this;
	}

	~Counter() { std::cout << "~Counter()" << std::endl; }
};

int main()
{
	Counter c;
	c.increment().increment().increment();	// <== ���⼭ 3���� "���Ͽ��ӽð�ü�ı�"
	std::cout << c.value << std::endl;
} // <== ���⼭ c �ı� 
// �׷��Ƿ� ~Counter()\n ~Counter()\n ~Counter()\n 1\n ~Counter()\n ���� ���

