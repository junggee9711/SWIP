#include <iostream>
#include <ranges>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	
	// C++20 ���������� range for �� ��� ��� ���Ÿ� �����߽��ϴ�.
	// C++20 ���� ���� ������ ���� �߰��Ǿ����ϴ�. <ranges> ���.
//	for (auto n : x)
//	for (auto n : std::views::reverse(x))
//	for (auto n : std::views::take(x, 3)) 
	for (auto n : std::views::take(std::views::reverse(x), 3)) {
		std::cout << n << std::endl;
	}
}