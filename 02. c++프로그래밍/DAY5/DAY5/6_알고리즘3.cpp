// 5_�˰���3


#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 

int main()
{
	std::list<int>   s = { 1,6,3,4,5 };

	// ex1. s���� ó�������� ¦���� ã�ƺ�����.. "����ǥ����"���� �ϼ���

//	auto p2 = std::find_if(s.begin(), s.end(), [](int n) { return n % 2 == 0; });

	int num;
	std::cin >> num;

	// ex2. s���� 1��° ������ num �� ����� ã�ƺ�����.
	// => ���� ǥ���Ŀ��� ���������� �����Ϸ��� "���������� ĸ��(capture)" �ؾ� �մϴ�.
	// => �������� ĸ�� - [] �ȿ� num �� �ֽ��ϴ�.
	//				   - [a, b, c] : ������ ĸ��
	//				   - [=]       : ��� �������� ĸ��
	//				   - [&a]	   : ������ ĸ��, �������� ���� ����
	//				   - [am &b]   : a�� ���� �ƴ�, b�� ����
	//				   - [&]	   : ��� �������� ���� ĸ��
	//				   - [&, a]    : ��� �������� ���� ĸ��, a�� value ĸ��
	//				   - [=, &b]   : ��� �������� value ĸ��, b�� ���� ĸ��
	auto p2 = std::find_if(s.begin(), s.end(), [num](int n) { return n % num == 0; }); 


	if (p2 == s.end())
		std::cout << "�˻� ���� " << std::endl;
	else
		std::cout << "�˻� ���� " << *p2 << std::endl;

}



