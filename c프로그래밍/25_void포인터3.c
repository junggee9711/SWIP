#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// memcpy
// : 메모리를 복사하는 함수
// => void* memcpy(void *dst, const void *src, size_t);

void xmemcpy(void* dst, void* src, int size)
{
#if 0
	char* s = (char*)src;
	char* d = (char*)dst;

	for (int i = 0; i < size; ++i) {
		*d++ = *s++;
	}
#endif

	while (size--) {
		char* s = (char*)src;
		char* d = (char*)dst;
		while (size--) {
			*d++ = *s++;
		}
	}
}

void swap(void* x, void* y, int size)
{	
	// int temp = *x;
	char* temp = (char*)malloc(size);
	
	// int temp = *x;
	xmemcpy(temp, x, size);
	
	// *x = *y;
	xmemcpy(x, y, size);
	
	// *y = temp;
	xmemcpy(y, x, size);

	free(temp);
}

int main()
{
	int a = 10;
	int b = 20;

	swap(&a, &b, sizeof(a));
	printf("%d %d\n", a, b);

	char str1[32] = "hello";
	char str2[32] = "world";

	swap(str1, str2, sizeof(str1));
	printf("%s, %s\n", str1, str2);

	return 0;

}