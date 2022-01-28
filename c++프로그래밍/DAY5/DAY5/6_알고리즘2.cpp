// 5_�˰���2 - 227page


#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 

bool foo(int n)
{
	return n % 3 == 0;
}

int main()
{
	std::list<int>   s = { 1,6,3,4,5 };

	// 1. �־��� �������� 3�� ã�� �ʹ�. => "�� �˻�"
	//	=> std::find() : "�� �˻�"
	auto p1 = std::find(s.begin(), s.end(), 3);

	// 2. �־��� �������� ó�� ������ 3�� ����� ã�� �ʹ�. => "���� �˻�"
	//  => std::find _if() : "���� �˻�"
	// auto p2 = std::find(s.begin(), s.end(), "�Լ�" );
	//  => "����"�� "�Լ�"�� ����

	auto p2 = std::find_if(s.begin(), s.end(), foo );
	//  => foo() �Լ��� ���ڸ� list �� "��� type" ���� �ް�, "bool" �� return �Ѵ�.

	// 3. C++ ����, �Լ� ���� "����ǥ����"�� ����ϴ� ���� �����ϴ�.
	//  => [] : ����ǥ������ ���۵��� �˸��� "lambda introducer"
	auto p2 = std::find_if(s.begin(), s.end(), [](int n) { return n % 3 == 0; });
	//  => "[](�Լ�����) { �Լ����� }" �� ���·� ���� ǥ���� ���
	//  => �������� ����, ��¥ �Լ��� ����ϴ� �ͺ��� �ణ �� �����ϴ�. 
	//     (�����Ϸ��� �ڵ����� �ش� �Լ��� �����, find_if ���ο��� �ζ��� ġȯ�˴ϴ�.)


	if (p2 == s.end())
		std::cout << "�˻� ���� " << std::endl;
	else
		std::cout << "�˻� ���� " << *p2 << std::endl;

}



