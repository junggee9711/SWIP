// 18_static_member_function1 114 page

#include <iostream>

class Car
{
	int speed;
	static int cnt;
public:

	Car() { ++cnt; }
	~Car() { --cnt; }

//	int get_count() { return cnt; }			// 1. �ν��Ͻ� �޼ҵ�
											//  1) �ݵ�� ��ü�� �־�� ȣ�� �����ϴ�.
											//  2) c1.get_count()

	static int get_count() { return cnt; }	// 2. ���� �޼ҵ�(Ŭ����)
											//  1) ��ü ���� ȣ�� ������ ��� �Լ�(�޼ҵ�)
											//  2) �Ϲ����� �Լ��� ����. �ٸ�, class�� private �� ���� ����!!
											//  3) Car::get_count() �� ȣ��
};
int Car::cnt = 0;							// * private �� �־ static ��� �������� �ܺ� �ʱ�ȭ�� ���˴ϴ�.
											// * Car::cnt �� �ʱ�ȭ �ϴ� �κ��� "static int get_count()" ������ ������ �ȵ˴ϴ�.


int main()
{
	std::cout << Car::get_count() << std::endl;

	Car c1;
	Car c2;

	//  4) static ��� �Լ��� �Ʒ� �ΰ��� ������� ���� ������
	std::cout << Car::get_count() << std::endl;	 // ����!!
	std::cout << c1.get_count() << std::endl;	

}
