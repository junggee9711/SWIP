// 함수 포인터
// : 함수를 가르키는 포인터 변수

#include <stdio.h>

// int n = 10;   // int
// int* p = &n;  // int*

// int *p(int, int)
// => p는 함수 입니다.
//    int 2개를 인자로 받고, int* 반환하는 함수입니다.

// int (*p)(int, int)
// => p는 포인터입니다.
//  [  p  ] -------> int(int, int)
//   8byte
// => 함수 포인터라고 부릅니다.

int add(int a, int b) { return a + b; }
// add의 타입은 무엇일까요?
//  : int(int a, int b)
// => 함수의 타입은 "함수의 반환타입과 인자 정보"에 의해서 결정됩니다.
// => 함수의 타입은 "함수의 시그니처"에 의해서 결정됩니다.
// => 함수의 시그니처가 동일하면 같은 타입입니다.

int sub(int a, int b) { return a - b; }
// : int(int a, int b)

int main()
{
}