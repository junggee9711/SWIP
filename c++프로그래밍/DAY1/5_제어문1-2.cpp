#include <iostream>
#include <ranges>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	
	// C++20 이전까지는 range for 는 모든 요소 열거만 가능했습니다.
	// C++20 부터 좋은 도구가 많이 추가되었습니다. <ranges> 헤더.
//	for (auto n : x)
//	for (auto n : std::views::reverse(x))
//	for (auto n : std::views::take(x, 3)) 
	for (auto n : std::views::take(std::views::reverse(x), 3)) {
		std::cout << n << std::endl;
	}
}