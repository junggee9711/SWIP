// 17_static_member_data4 
#include <iostream>

// - ��������Ϳ� static ��� �������� ���� 
//	=> class ��ü���� �����ϴ°� �ƴѰ�!

class Car
{
	int speed;				// "��ü�� �Ѱ�"(�����̸��� ��ü�� �Ѱ��� ���), "�ν��Ͻ� �ʵ�(�������Ÿ)" ��� ��� ���.
public:
	static int cnt;			// ��� Car ��ü�� ���� 
							// = Ŭ������ �Ѱ�(�����̸��� Ŭ������ �Ѱ��� ���), "Ŭ���� �ʵ�(���������)" ��� ��� ���.

	Car() { ++cnt; }
	~Car() { --cnt; }
};
int Car::cnt = 0;


class Truck
{
	int speed;
public:
	static int cnt;

	Truck() { ++cnt; }
	~Truck() { --cnt; }
};
int Truck::cnt = 0;



int main()
{
}
