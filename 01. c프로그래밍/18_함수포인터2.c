
// 고차 함수
// => 함수를 반환하거나 함수를 인자로 받는 함수
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

// int (int a, int b)

typedef int (*FP)(int a, int b);
// FP == int(*)(int, int);

FP goo(FP arg)
{
    return &add;
}

// 아무 인자도 받지 않고  "int *(int, int) =  2개의 정수를 받아서 정수를 반환하는 함수"의 포인터를 반환하는 함수
int (*foo(  )) (int a, int b)
{

    return &add; // 함수 포인터를 반환합니다.
}

// 2개의 정수를 받아서 "*p(int, int) = 함수의 포인터를 인자로 받는 함수의" 포인터를 반환하는 함수 => 인자 반대로!
int (*foo(int (*p)(int, int))) (int a, int b)
{

    return &add; // 함수 포인터를 반환합니다.
}



int main()
{
    int result = foo(&add)(10, 20);
    printf("%d\n", result);

    // int (*p)(int, int) = &add;
    // printf("%d\n", (*p)(10, 20));

    int (*p)(int a, int b) = add;
    printf("%d\n", p(10, 20));
    // 함수의 이름은 함수 포인터의 암묵적 변환을 허용합니다.
    // 함수포인터에 대한 호출을 참조 없이 호출 가능합니다.
}

foo(int (*))