// 3_STL5

#include <list>
#include <vector>
#include <iostream>

int main()
{
	std::list<int> s;
	std::cout << sizeof(s) << std::endl;	// 24 byte 
											// - linked list �� ù��° ����� �޸� 
											// - size, capacity �� class ��ü ����� �޸� ����

	s.push_back(10);
	std::cout << sizeof(s) << std::endl;	// 24 byte	
											// - linked list �� ù��° ����� �޸𸮸� ���
	s.push_back(20);
	s.push_back(30);
	std::cout << sizeof(s) << std::endl;    // 24 byte
											// - linked list �� ù��° ����� �޸𸮸� ���
	//------------------------------------
	// �Ʒ� ������ ������ ���ô�.
	std::vector< std::list<int> > v(5);		// list<int> �� 5�� �迭�� 
	std::cout << sizeof(v) << std::endl;    // 32 byte
	v[4].push_back(1);
	v[4].push_back(2);
	v[4].push_back(3);
	std::cout << sizeof(v) << std::endl;	// 24x5 = 120 byte
}