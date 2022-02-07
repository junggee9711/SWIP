#include <stdio.h>
#include <stdlib.h>

// 1. 구조체 타입의 크기
//  => sizeof

// 2. 구조체는 call by value로 동작합니다.
//  => 인자로 전달된 구조체에 대해서 복사가 수행됩니다.

// 3. struct Complex c;
//     c.imagin
//     c.real
//    struct Complex* c;
//     (*c).imagin  /  c->imagin
//     (*c).real    /  c->real
//   : 멤버 데이터에 접근하는 방법을 기억해야 합니다.

struct Complex {
    double real;
    double imagin;

    int arr[100];
};

// 1. static 메모리의 주소를 반환한다.
// => 스레드 안전성 고려해야 합니다.
struct Complex* add1(const struct Complex* c1, const struct Complex* c2)
{
    static struct Complex result;

    result.real = (*c1).real + (*c2).real;
    result.imagin = c1->imagin + c2->imagin;
    // *(p).
    // : p->

    return &result;
}

// 2. malloc
// => free를 잊으면 안된다.
struct Complex* add2(const struct Complex* c1, const struct Complex* c2)
{
    struct Complex* result = (struct Complex*)malloc(sizeof(struct Complex));

    result->real = (*c1).real + (*c2).real;
    result->imagin = c1->imagin + c2->imagin;

    return result;
}

// 3. out parameter
// => 직관성이 떨어지긴 함
void add3(const struct Complex* c1, const struct Complex* c2,
    struct Complex* result)
{
    result->real = (*c1).real + (*c2).real;
    result->imagin = c1->imagin + c2->imagin;
}

int main()
{
    struct Complex a = { .real = 1, .imagin = 1 };
    struct Complex b = { .real = 2, .imagin = 2 };

    printf("%lu\n", sizeof(a));
    printf("%lu\n", sizeof(struct Complex));

    struct Complex* s = add1(&a, &b);
    printf("%lf %lf\n", s->real, s->imagin);

    s = add2(&a, &b);
    printf("%lf %lf\n", s->real, s->imagin);
    free(s); // !!

    struct Complex result;
    add3(&a, &b, &result);
    printf("%lf %lf\n", result.real, result.imagin);

    return 0;
}