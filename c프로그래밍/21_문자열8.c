
// ������� �Լ��� �����ϴ� �帧�Դϴ�.
// ���μ���(���� ���� ���α׷�)�� �Ѱ��� �����尡 ��������ϴ�.
// => main thread

#include <pthread.h>
#include <unistd.h>

#include <stdio.h>

void foo()
{
    while (1) {
        sleep(1); // System

        printf("foo\n");
    }
}

void* thread_routine(void* arg)
{
    while (1) {
        printf("goo\n");
        usleep(500000);
    }
    return 0;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, &thread_routine, NULL);

    foo();
}