#include <stdio.h>

// 전역 변수
// - 함수의 밖에 존재하는 변수
// - 프로그램의 시작 전에 초기화되고, 프로그램이 종료할 때
//   파괴됩니다.
// > 초기화하지 않으면, 0으로 초기화됩니다.
// > 초기화된 전역변수를 사용하면, 실행 파일의 크기에 영향을 줍니다.
// => 인자를 전달하지 않아도 참조할 수 있기 때문에,
//    함수의 복잡도를 낮추는데 도움이 됩니다.
//    하지만, 함수가 재사용되는데 있어서 전역 변수는
//    걸리적 거립니다.
// => 멀티 스레드에서 동기화를 고려해야 하는 요소가 됩니다.

// 지역 변수
// - 함수의 안에 존재하는 변수
// - 함수가 시작될 때 초기화되고, 함수가 종료하면 파괴됩니다.
// > 초기화하지 않으면, 쓰레기값을 가집니다.

// 400000byte
int arr[100000];

// int global = 100;
// 전역 변수
// => linkage(연결)
//  다른 파일에서도 접근이 가능한가?
//  : external linkage를 갖습니다.

//  같은 파일에서만 접근이 가능한가?
// => internal linkage
static int global = 0;

/*
Undefined symbols for architecture arm64:
  "_global", referenced from:
      _print in foo-be750a.o
*/

void foo()
{
    int a = 10;
    printf("A: %d\n", a);
    printf("global: %d\n", global);

    a += 10;
    global += 10;
}

void print(); // foo.c

int main()
{
    int local = 0;
    foo();
    foo();
    foo();

    print();
}