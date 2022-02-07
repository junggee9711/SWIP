// 4_�ݺ���4

#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. ������ �ݺ���
//	auto p1 = s.begin();		
//	auto p2 = s.end();			

	// 2. ������ �ݺ���
//	auto p1 = s.rbegin();		// ���� �ڿ��� ������
//	auto p2 = s.rend();			// ���� ���� ����

	// 3. ���, ������ �ݺ���
	auto p1 = s.cbegin();		// std::cbegine(s) <== �Ϲ��Լ� ����
	auto p2 = s.cend();		

//	*p1 = 10;					// error. ��� �ݺ��ڴ� �б⸸ ����.

	// 4. ���, ������ �ݺ���
	auto p1 = s.crbegin();		// std::crbegin(s)
	auto p2 = s.crend();		

//  *p1 = 10;					// error. ��� ������ �ݺ��ڴ� �б⸸ ����.


	while (p1 != p2)	
	{
		std::cout << *p1 << std::endl;
		++p1;					// p1 �� reverse iterator ��� ++������ ��->������ �̵�
	}

}


