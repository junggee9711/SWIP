#include <stdio.h>
#include <stdlib.h>

struct Complex {
    double real;
    double imagin;
};

// C언어에서는 구조체를 typedef를 통해 사용하는 경우가
// 많습니다.
typedef struct Complex COMPLEX;

COMPLEX* add1(const COMPLEX* c1, const COMPLEX* c2)
{
    static COMPLEX result;

    result.real = (*c1).real + (*c2).real;
    result.imagin = c1->imagin + c2->imagin;
    // *(p).
    // : p->

    return &result;
}

COMPLEX* add2(const COMPLEX* c1, const COMPLEX* c2)
{
    COMPLEX* result = (COMPLEX*)malloc(sizeof(COMPLEX));

    result->real = (*c1).real + (*c2).real;
    result->imagin = c1->imagin + c2->imagin;

    return result;
}

void add3(const COMPLEX* c1, const COMPLEX* c2,
    COMPLEX* result)
{
    result->real = (*c1).real + (*c2).real;
    result->imagin = c1->imagin + c2->imagin;
}

int main()
{
    COMPLEX a = { .real = 1, .imagin = 1 };
    COMPLEX b = { .real = 2, .imagin = 2 };

    printf("%lu\n", sizeof(a));
    printf("%lu\n", sizeof(COMPLEX));

    COMPLEX* s = add1(&a, &b);
    printf("%lf %lf\n", s->real, s->imagin);

    s = add2(&a, &b);
    printf("%lf %lf\n", s->real, s->imagin);
    free(s); // !!

    COMPLEX result;
    add3(&a, &b, &result);
    printf("%lf %lf\n", result.real, result.imagin);

    return 0;
}