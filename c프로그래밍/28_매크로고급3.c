#include <stdio.h>

// ��� C++ �����Ϸ��� __cplusplus ��ũ�θ� �����մϴ�.

#ifdef __cplusplus
extern "C"
int add(int a, int b) { return a + b; }
#endif

int main()
{
	int rst = add(10, 20);
	printf("%d", rst);
}