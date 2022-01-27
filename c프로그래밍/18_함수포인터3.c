#include <stdio.h>

// [ int[5] ][ int[5] ][ int[5] ]
int x[3][5] = {
    0,
};

// int (*foo())[5]
// 1) foo()
/// : foo는 인자가 없는 함수입니다.
// 2) *foo()
//  : 함수의 반환타입은 포인터입니다.
// 3) (*foo())[5]
//  : 5개짜리 배열을 가르키는 포인터입니다.
// 4) int (*foo())[5]
//  :  int 배열의 원소타입은입니다.
int(*foo())[5]
{
    return x; // int (*p)[5] ---> int[5]
}

int add(int a, int b) { return a + b; }

int (*goo())(int, int)
{
    return &add; //  int(*p)(int, int) ----> int(int, int)
}

// int (*goo())(int, int)
// 1. goo()
// : goo는 인자 없는 함수 입니다.
//   반환타입은?
// 2. (*goo())
//  : 반환타입은 포인터 입니다.
//   포인터가 가르키는 타입은?
// 3. (*goo())(int, int)
//  : 포인터가 가르키는 타입은 int 인자 두개를 받는 함수 입니다.
//   함수의 반환타입은?
// 4. int (*goo())(int, int)
//  : 함수의 반환타입은 int 입니다.

int main()
{
}