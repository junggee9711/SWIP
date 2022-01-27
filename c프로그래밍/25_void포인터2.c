#include <stdio.h>

// 타입에 일반적인 swap 을 만들 수 있습니다.
// 1. 매크로 함수 활용
// 2. void* 활용

// 매크로 함수를 작성할 때,
// 여러 개의 구문을 하나의 함수를 작성한다면
// => do-while(0) 를 사용합니다. (공식, 세미콜론 제외)
#define SWAP(a, b, type) do {\
	type temp = a;		\
	a = b;				\
	b = temp;			\
}while(0)

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{

	int a = 10;
	int b = 20;

	SWAP(a, b, int); // 이와같이 int 가 입력으로 들어갈수 있는건 매크로함수가 '치환' 으로 작동하기 때문에!

	printf("%d, %d\n", a, b);

	double da = 10;
	double db = 20;

	SWAP(da, db, double); // define 에서 세미콜론을 제외했기 때문에 세미콜론을 적어줌

	if (b < a)
		SWAP(a, b, int);

	printf("%d, %d\n", a, b);
	return 0;
}
