
// 스레드는 함수를 실행하는 흐름입니다.
// 프로세스(실행 중인 프로그램)는 한개의 스레드가 만들어집니다.
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