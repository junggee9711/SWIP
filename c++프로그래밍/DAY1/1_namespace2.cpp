// 1_namespace2.cpp - 8 pag

#include <stdio.h>

namespace Video
{
	// Video 관련 함수, 구조체, 전역변수등을 모두 이안에서 만든다.
	void init()
	{
		printf("Video init\n");
	}
}

// global namespace : 특정 이름 공간에 포함되지 않은 공간.
void init() { printf("global init\n"); }

// using 은 함수안 또는 밖에 있을 수 있습니다.
// 함수 안에 있으면 해당 함수에서만 접근, 밖에 있으면 전체 함수에서 접근
using Video::init;

int main()
{
	// namespace 안에 있는 요소를 사용하는 3가지 방법 - 8page
	Video::init(); // 1. 완전한 이름

	using Video::init; // 2. using 선언(declaration) - 선언 후에는 Video 를 적지 않고 init() 사용 가능.
	init();			   //    init 함수만 Video 이름 없이 사용.
	::init();		   //	 :: ==> scope resolution 연산자. global namespace 의 사용을 의미

	using namespace Video; // 3. using 지시어(directive)
	init();				   //	 Video 안의 모든 심볼을 Video 이름 없이 사용.

	//	 => 이름 충돌이 많이 발생하는 문법이므로 using 을 사용하지 않는것이 좋음


}