// 3_STL1 - 213 page

#include <iostream>
#include <vector>
#include <list>

int main()
{
	// - �迭 vs vector
	//  1. �迭 ���� : ũ�� ������ �ȵȴ�.
	int x[5] = { 1,2,3,4,5 };

	//  2. vector 
	//	 1) �迭ó�� ���ӵ� �޸�, []�� ���� ����
	std::vector<int> v = { 1,2,3,4,5 };

	v[0] = 10;
	v.resize(10);				// 2) vector �� ũ�� ���� ����

	std::vector<int> v2(10, 2); // ũ�� 10, 10���� ��� 2�� �ʱ�ȭ..


	v2.resize(7);				// ũ�� 7�� ���̱�..
								// ���� �޸𸮴� ����(7�� ���Ҵ�����) �ʽ��ϴ�. 
								// �ٸ�, class �� size ������ 7�� �ٲ�
	std::cout << v2.size()     << std::endl;	// 7
	std::cout << v2.capacity() << std::endl;	// 10 (�޸� ��뷮)

	v2.push_back(5);			// ���� 5 ��� �� �Ѱ� �߰�. ���(expensive) ���� �ϱ��?
								//							��(cheap) ���� �ϱ��?
								//	=> 8��° �ڸ��� �߰��� �ϸ� �ǰ�, ���� �޸��Ҵ� ���� = "��"����
	std::cout << v2.size() << std::endl;		// 8
	std::cout << v2.capacity() << std::endl;	// 10 (�޸� ��뷮)

	v2.shrink_to_fit();			// ������ �޸𸮸� ������ �޶�.
								// => 8�� �޸𸮸� ���� �Ҵ� ��, ���� �����ؼ� ����
	std::cout << v2.size() << std::endl;		// 8
	std::cout << v2.capacity() << std::endl;	// 8 (�޸� ��뷮)

	v2.push_back(3);			// ���� 3 �̶�� �� �Ѱ� �߰�.
								// => �޸𸮸� ���� �Ҵ��ϹǷ� "���"����
								// => �޸𸮸� 1 �ø��� ���� �ƴ϶�, �����Ӱ� 1.5�� or 2��� �÷�����
								// why?) ���� �߰��Ҷ����� �޸𸮸� �Ҵ��ϸ� ��� ������ �ǹǷ�, �̸� �Ҵ�. 
	std::cout << v2.size() << std::endl;		// 9
	std::cout << v2.capacity() << std::endl;	// ?? (�޸� ��뷮)

	// capacity : ���� �޸� ��뷮
	// size		: ����� ����
	// => �� ���� ��� vector class �� �������

	std::vector<int> v3;		// �޸� �Ҵ� ����
	v3.push_back(1);			// �̶� 1�� ���� �Ҵ�
	v3.push_back(1);			// 2�� ����
	v3.push_back(1);			// 4�� ���� (�����Ϸ������� 2�� or 1.5��� �ٸ��� ����)	

	v3.reserve(100);			// �޸𸮴� 100���� Ű�� ���ƶ�!!
								// => ������ ����߰��� �������̶�� ������ �ִٸ� capacity �� Ű��
	std::cout << v3.size()     << std::endl;	// 3
	std::cout << v3.capacity() << std::endl;	// 100 (�޸� ��뷮)

}





