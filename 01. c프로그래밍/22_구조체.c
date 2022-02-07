// 22_구조체.c
#include <stdio.h>

// 복소수 2개의 합을 구하는 함수를 만들어봅시다.
// => 함수는 하나의 값만 반환하는 것이 가능합니다.
// 1. out parameter
// : 결과를 함수 인자를 통해 받아옵니다.
//   => 주소를 전달해야 합니다.

#if 0
void add(double ar, double ai, double br, double bi,
    double* sr, double* si)
{
    *sr = ar + br;
    *si = ai + bi;
}

int main()
{
    double ar = 1, ai = 1; // 1 + 1i
    double br = 2, bi = 2; // 2 + 2i

    double sr, si;

    add(ar, ai, br, bi, &sr, &si);
    printf("result: %lf %lf\n", sr, si);
}
#endif

// 2. 구조체
//  => 사용자 정의 타입을 만드는 문법입니다.
//  => built-in type / primitive type
//     기본적으로 제공하는 타입을 의미합니다.
//  => 복소수를 나타내기 위해서 필요한 데이터를 구조체로 만들 수 있습니다.

#if 0
struct 타입이름 {};

#endif

// struct Complex [[ real: 8byte ][ image: 8byte]]

struct Complex {
    double real; // 멤버 변수 / 멤버 데이터
    double imagin;
};

struct Complex add(struct Complex c1, struct Complex c2)
{
    // return c1 + c2;
    struct Complex result = {
        .real = c1.real + c2.real,
        .imagin = c1.imagin + c2.imagin
    };

    // result.real = c1.real + c2.real;
    // result.imagin = c1.imagin + c2.imagin;

    return result;
}

int main()
{
    // struct Complex a = { 1, 1 }; // 1 + 1i
    // struct Complex b = { 2, 2 }; // 2 + 2i

    // 멤버 초기화 기능이 제공됩니다. - C99
    struct Complex a = { .real = 1, .imagin = 1 };
    struct Complex b = { .real = 2, .imagin = 2 };

    struct Complex s = add(a, b);

    printf("%lf %lf\n", s.real, s.imagin);
    return 0;
}