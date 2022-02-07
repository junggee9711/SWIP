#include <stdio.h>


int* foo() {
	int score = { 10, 20, 30, 40, 50 };
	return score;
}

int main()
{
		
}// 20_동적메모리할당2.c
#include <stdio.h>

// 1. 동적 메모리 할당
//   malloc / free
// 2. 동적 메모리 할당의 결과는 포인터가 반환됩니다.
// 3. 실패할 경우, NULL을 반환합니다.
// 4. 수명 관리를 프로그래머가 직접 할 수 있다.
// 5. 메모리 해지를 하지 않을 경우, 메모리 누수가 발생하고
//    이후에 문제의 원인이 될 수 있습니다.
// 6. malloc은 메모리 할당 중에 가장 많은 시간이 소모됩니다.

#include <stdlib.h> // malloc, free, exit

int* foo()
{
    int score[5] = { 10, 20, 30, 40, 50 };
    return score;
}
// 문제점: 해지된 메모리의 주소를 반환합니다.
//  => 지역 변수의 주소를 반환하면 안됩니다.

// 1. 정적 지역 변수
// => 함수가 전역 변수 또는 정적 지역 변수에 의존하는 경우
//    함수는 재진입이 불가능합니다.
//   : 스레드 안정성, 재귀
int* goo()
{
    static int score[5] = { 10, 20, 30, 40, 50 };
    // ...
    return score;
}

// 2. 동적 메모리 할당
// => 재진입(reentrant) 가능하다.
// : 사용자가 반드시 free 해주어야 합니다.
int* hoo()
{
    // int[5]를 사용하겠다는 의도
    int* score = (int*)malloc(sizeof(int) * 5);

    return score;
}

int main()
{
    int* p2 = hoo();
    p2[0] = 100;

    free(p2);

    // int* p = (int *)malloc(sizeof(int));
    int* p = NULL;

    // 미리 정의된 매크로를 제공합니다.
    // __FILE__ / __LINE__ / __func__
    if (p == NULL) {
        printf("메모리 할당이 실패하였습니다.\n> %s:%d - %s\n",
            __FILE__, __LINE__, __func__);
        exit(1);
    }

    return 0;
}