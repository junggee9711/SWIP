// 9 page

#include <algorithm>
using namespace std;

int count = 10;

int main()
{
	// 모든 C++ 표준은 "std" 라는 namespace 안에 있습니다.
	int n = std::min(10, 30); // C++ 표준 함수. <algorithm> 헤더에 있습니다.

	// int n2 = count; // 왜 에러일까요?
					   // C++ 표준에 "std::count()" 라는 함수가 있습니다.
					   // using namespace std 때문에 전역변수 count 와 이름 충돌
	//	=> 이름 충돌이 많이 발생하는 문법이므로 using 을 사용하지 않는것이 좋음
}