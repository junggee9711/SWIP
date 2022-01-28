#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 

int main()
{
	std::list<int>   s = { 1,6,3,4,5 };

	// 주어진 구간에서 3을 찾고 싶다.  "값 검색"
	auto p1 = std::find(s.begin(), s.end(), 3);

	// 주어진 구간에서 처음 나오는 3의 배수를 찾고 싶다. -227page
	auto p2 = std::find(s.begin(), s.end(), ?? );
}



