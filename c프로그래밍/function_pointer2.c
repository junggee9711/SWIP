
// 정렬 알고리즘 구현해봅시다.
// => 버블 정렬

#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

#if 0
void sort(int* arr, int n)
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] < arr[j]) // 정책을 함수 인자로 뽑아내야 합니다.
                swap(&arr[i], &arr[j]);
        }
    }
}
#endif

void sort(int* arr, int n, int (*cmp)(int, int))
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (cmp(arr[i], arr[j]))
                swap(&arr[i], &arr[j]);
        }
    }
}

//------------------------------------

// int(int, int)
// => int(*cmp)(int, int)

int cmp1(int a, int b) { return a > b; }
int cmp2(int a, int b) { return a < b; }

struct Button {
    char name[128];
    void (*onClick)();
};

void click(struct Button* button)
{
    // 사용자가 정의한 동작이 수행되어야 합니다.
    if (button->onClick) {
        button->onClick();
    }
}

void start()
{
    printf("Start\n");
}

void stop()
{
    printf("Stop\n");
}

int main()
{
    struct Button button1 = { .name = "종료", .onClick = &stop };
    struct Button button2 = { .name = "시작", .onClick = &start };

    click(&button1);
    click(&button2);

    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    sort(x, 10, &cmp2);

    for (int i = 0; i < 10; ++i)
        printf("%d\n", x[i]);

    return 0;
}