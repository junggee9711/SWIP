#include <stdio.h>
#include <stdlib.h>

// 1. ����ü Ÿ���� ũ��
//  => sizeof

// 2. ����ü�� call by value�� �����մϴ�.
//  => ���ڷ� ���޵� ����ü�� ���ؼ� ���簡 ����˴ϴ�.

// 3. struct Complex c;
//     c.imagin
//     c.real
//    struct Complex* c;
//     (*c).imagin  /  c->imagin
//     (*c).real    /  c->real
//   : ��� �����Ϳ� �����ϴ� ����� ����ؾ� �մϴ�.

struct Complex {
    double real;
    double imagin;

    int arr[100];
};

// 1. static �޸��� �ּҸ� ��ȯ�Ѵ�.
// => ������ ������ ����ؾ� �մϴ�.
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
// => free�� ������ �ȵȴ�.
struct Complex* add2(const struct Complex* c1, const struct Complex* c2)
{
    struct Complex* result = (struct Complex*)malloc(sizeof(struct Complex));

    result->real = (*c1).real + (*c2).real;
    result->imagin = c1->imagin + c2->imagin;

    return result;
}

// 3. out parameter
// => �������� �������� ��
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