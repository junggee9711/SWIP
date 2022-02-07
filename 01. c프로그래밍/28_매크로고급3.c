#include <stdio.h>

// 모든 C++ 컴파일러는 __cplusplus 매크로를 제공합니다.

#ifdef __cplusplus
extern "C"
int add(int a, int b) { return a + b; }
#endif

int main()
{
	int rst = add(10, 20);
	printf("%d", rst);
}