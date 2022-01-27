// 컴파일러는 컴파일러 종류에 따라 미리 정의된 매크로 심볼이 있습니다. (따로 define 할 필요 없음)
// GNU		   => __GNUC__
// Windows(c1) => _MSC_VER

#include <stdio.h>

int main()
{
#ifdef _MSC_VER
	printf("Windows\n");
#else
	printf("Other\n");
#endif

	return 0;
}