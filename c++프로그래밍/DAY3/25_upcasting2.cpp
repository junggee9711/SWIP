// 25_upcasting2

#include <iostream>
#include <vector>


class Animal
{
public:
	int age;
};

class Dog : public Animal {};
class Cat : public Animal
{
public:
	int color;
};

//void HappyNewYear(Dog* p)		// Dog �� ���� ������ �Լ�
void HappyNewYear(Animal* p)	// "���� ���Ŭ������ ����ϴ�(����)" Ÿ���� ��� ���� ������ �Լ�
{								// => ���ڸ� Animal* p = &c �� �ޱ� ������
	++(p->age);
}

int main()
{
	Dog d;
	HappyNewYear(&d);			// ok.
	Cat c;
	HappyNewYear(&c);			// error. �Լ��� Dog* p �� ���ڷ� �ޱ� ������

	std::vector<Dog*> woori;		// Dog �� �����ϴ� �츮
	std::vector<Animal*> woori;		// ��� ����(����)�� �����ϴ� �����̳� �����
									// 142 page �Ʒ� �κ�
}