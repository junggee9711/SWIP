// 15_�Ҹ���1 82 page

#include <iostream>

class Point
{
	int x = 0;
	int y = 0;
public:
	Point() { std::cout << "Point()" << std::endl; };

	// 1. �Ҹ��� - "~Ŭ���� �̸�" ����� �Լ�
	//			- ���ڿ� ��ȯ���� ��� ����.
	//			- �Ѱ��� ����� �ִ�.
	//			- ��ü�� "�ı��� ��" ȣ��ȴ�.
	//	=> �ʿ��� ��츸 ����� �ǰ�, �ʿ� ���ٸ� ���� �ʿ� ����. /* ���� ���� : �Ҹ��ڴ� ���ڸ� ������ �ִ�? (false) */
	~Point() { std::cout << "Point()" << std::endl; };
};

int main()
{
	{
		Point pt;
	}	// <== pt �ı�. �Ҹ��ڰ� ȣ���.
	std::cout << "---------------" << std::endl;
}