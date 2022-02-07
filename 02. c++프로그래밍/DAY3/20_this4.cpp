// 20_this4 129 page

#include <iostream>

class Car
{
	int speed;
public:
	void set(int speed)
	{
		// this Ȱ�� 1. ������� ��Ȯ�� �ϰ� ������
		//	- speed ��� �ϸ� ��������(set �� ����)�� speed �Դϴ�. (C/C++ �� ���� ����� ������ �ν�)
		//	- ������� ��Ȯ�� �Ϸ��� �Ʒ��� ���� ����.
//		speed = speed;
		this->speed = speed;				// *(&this).speed = speed;
	}
	// this Ȱ�� 2. this �� ��ȯ�ϴ� �Լ� - �߿�!!
	Car* go() { return this; }
	Car& go2() { return *this; }			// ==> 129 page �Ʒ� �ڽ� (���� ����)
};

int main()
{
	Car c;
	c.set(10);
	// this �� ��ȯ�ϴ� �Լ��� �Լ� ȣ���� ���������� �� �� �ֽ��ϴ�.
	// => �ڱ� �ڽ��� "class/class�ּ�" �� ��ȯ�մϴ�.
	c.go()->go()->go()->go();				// *(*(&c.go())).go()...
	c.go2().go2().go2().go2();				// class �� return �ϱ� ������ . ���� ȣ��

	std::cout << "A" << "B" << "C";			// �� �Ʒ��� �����ϴ�.
	std::cout.operator<<("A").operator<<("B").operator<<("C");


}