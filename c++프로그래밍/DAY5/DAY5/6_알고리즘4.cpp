// 5_�˰���4


#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 


int foo(int a, int b)
{
	return a + b;
}

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2 = { 1,2,3,4,5 };	// list �� �ٸ� �����̳ʵ� ����
	std::vector<int> v3 = { 0,0,0,0,0 };

	// - transform �˰��� : 2���� �����̳ʸ� "�־��� ����" �Ŀ� �ٸ� �����̳ʿ� �ֱ�

	std::transform(	v1.begin(), v1.end(),
					v2.rbegin(),			// v2 �� ���� ���� ������ ����
					v3.begin(),				// end���� v1 ������ �˼� �ֱ⶧���� v1 �� ����
					//foo);
					// [](int a, int b) {return a * b; });
					[](int a, int b) -> int {return a * b; });	// <== ������ȯŸ�� ���.
	// 1. "�Լ�" ����Ҷ� : �� ��� foo �� return ���� bool �� �ƴ� "int" ���� ��.
	// 2. "����ǥ����" ����,
	//	- ����ǥ���� ��ȯ Ÿ�� 1) ������ �����Ϸ��� return ������ �߷�
	//						 2) ��ȯŸ���� ǥ���Ϸ��� "suffix return type(������ȯŸ��)" ���

	for (auto n : v3)
		std::cout << n << std::endl;
}



