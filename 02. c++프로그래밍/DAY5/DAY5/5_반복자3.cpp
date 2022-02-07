// 4_�ݺ���3
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p1 = s.begin();		// 1. �Ǵ� std::begin(s)
	auto p2 = s.end();			// 2. �������� �ƴ�, �������� ���� ��� (��κ� nullptr)
								//   => ���� "past the end" ��� �մϴ�. 
					

	*p2 = 50;					// runtime error...
	int n = *p2;				// runtime error... 
								//   1) �ݺ��� ����, "��" �� �����ߴ��� �Ǵ��ϱ� ���� ����� ��,
								//    ���� "�������� �������" �޸𸮿� �����ϸ� �ȵ˴ϴ�.
								//   2) "*p2" <== �� ǥ����� ������� ������.
	
	//   3) p2 �� ���� �뵵�θ� ����ؾ� �մϴ� (�Ʒ� ó��)
	while (p1 != p2)	// <== �� �뵵
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
	
}


