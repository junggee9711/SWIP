#include <stdio.h>

// 1. 조건부 컴파일
// => 정의된 매크로에 따라 컴파일의 코드가 변경되도록 하는 기술
// => 컴파일 단계에서 부터 해당 부분이 코드에 포함될지 안될지를 결정 할 수 있게 해줌

// Windows
// : CreateThread 함수
// Linux
// : pthread_create

// #define WINDOWS
// 컴파일 단계에서 매크로를 주입할 수 있습니다.

// 2. 매크로 심볼의 정의 여부를 체크한다.
//		: #ifdef / #ifndef
//	  매크로 심볼의 값을 체크한다.
//		: #if / #elif


#define VERSION 1000

#if VERSION > 1000
void newFeature()
{
	printf("xxx\n");
}
#endif

void foo() 
{
#ifdef WINDOWS
	printf("Windows - foo\n");
#else
	printf("Linux - foo\n");
#endif
}

void process()
{
#ifdef DEBUG
	printf("Process Start\n");
	printf("Processing---\n");
#endif
}

int main()
{
#if VERSION > 1000
	newFeature();
#endif

	foo();
}