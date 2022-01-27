// 1_namespace1.cpp - 7 pag

// namespace 상에서 변수명, 함수명 등의 이름이 중복이 가능하다! -> 다수의 인원이 프로젝트를 진행할때 좋음


#include <stdio.h>

namespace Audio
{
	void init()
	{
		printf("Audio init\n");
	}
}

namespace Video
{
	// Video 관련 함수, 구조체, 전역변수등을 모두 이안에서 만든다.
	void init()
	{
		printf("Video init\n");
	}
}



int main()
{
	Video::init();
}