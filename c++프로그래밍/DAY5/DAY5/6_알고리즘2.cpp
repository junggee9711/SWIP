#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 

int main()
{
	std::list<int>   s = { 1,6,3,4,5 };

	// �־��� �������� 3�� ã�� �ʹ�.  "�� �˻�"
	auto p1 = std::find(s.begin(), s.end(), 3);

	// �־��� �������� ó�� ������ 3�� ����� ã�� �ʹ�. -227page
	auto p2 = std::find(s.begin(), s.end(), ?? );
}



