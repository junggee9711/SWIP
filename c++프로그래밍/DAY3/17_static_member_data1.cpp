// 17_static_member_data1 110 page

#include <iostream>


// Car ��ü�� ��� �����Ǿ����� �����ϰ� �ʹ�.

// ��� 1. ��� ������ (cnt) ���
//		  => ��� ������(cnt)�� ��ü�� �Ѱ� ( 100 page �׸� ) �� �����ȴ�.
//		  => ��ü�� ���� �ľ� ����!
class Car
{
	int speed;
public:
	int cnt = 0;
	Car() { ++cnt; }
	~Car() { --cnt; }
};

int main()
{
	Car c1;
	Car c2;

	std::cout << c1.cnt << std::endl;		// c1 �� c2 �� ���� ���� �ٸ� cnt �� �ֱ� ������,
											// 2�� �ƴ϶� 1�� ���´�. - Ʋ��.

}