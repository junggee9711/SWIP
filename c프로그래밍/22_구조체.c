// 22_����ü.c
#include <stdio.h>

// ���Ҽ� 2���� ���� ���ϴ� �Լ��� �����ô�.
// => �Լ��� �ϳ��� ���� ��ȯ�ϴ� ���� �����մϴ�.
// 1. out parameter
// : ����� �Լ� ���ڸ� ���� �޾ƿɴϴ�.
//   => �ּҸ� �����ؾ� �մϴ�.

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

// 2. ����ü
//  => ����� ���� Ÿ���� ����� �����Դϴ�.
//  => built-in type / primitive type
//     �⺻������ �����ϴ� Ÿ���� �ǹ��մϴ�.
//  => ���Ҽ��� ��Ÿ���� ���ؼ� �ʿ��� �����͸� ����ü�� ���� �� �ֽ��ϴ�.

#if 0
struct Ÿ���̸� {};

#endif

// struct Complex [[ real: 8byte ][ image: 8byte]]

struct Complex {
    double real; // ��� ���� / ��� ������
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

    // ��� �ʱ�ȭ ����� �����˴ϴ�. - C99
    struct Complex a = { .real = 1, .imagin = 1 };
    struct Complex b = { .real = 2, .imagin = 2 };

    struct Complex s = add(a, b);

    printf("%lf %lf\n", s.real, s.imagin);
    return 0;
}