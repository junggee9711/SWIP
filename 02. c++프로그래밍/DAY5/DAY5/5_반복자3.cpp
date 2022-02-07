// 4_반복자3
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p1 = s.begin();		// 1. 또는 std::begin(s)
	auto p2 = s.end();			// 2. 마지막이 아닌, 마지막의 다음 요소 (대부분 nullptr)
								//   => 흔히 "past the end" 라고 합니다. 
					

	*p2 = 50;					// runtime error...
	int n = *p2;				// runtime error... 
								//   1) 반복문 사용시, "끝" 에 도달했는지 판단하기 위한 요소일 뿐,
								//    절대 "마지막의 다음요소" 메모리에 접근하면 안됩니다.
								//   2) "*p2" <== 이 표기법은 사용하지 마세요.
	
	//   3) p2 는 비교의 용도로만 사용해야 합니다 (아래 처럼)
	while (p1 != p2)	// <== 비교 용도
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
	
}


