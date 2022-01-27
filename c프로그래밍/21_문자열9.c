#include <pthread.h>
#include <stdio.h>
#include <string.h>

// �ٸ� �����尡 ���ÿ� ������ �����մϴ�.
// => ���� ����(Race Condition)
int sum = 0;
// => �Ӱ� ����(Critical Section)
//  : �ΰ� �̻��� �����尡 ���ÿ� �����ؼ�, ���� ������ �߻��ϴ� ����
// => �Ӱ� ���� �ȿ��� ���� �Ѱ��� �����常 ������ �����ϵ���
//    ��ȣ ����(Mutual Exclusion)�� ���־�� �մϴ�.
//   : Mutex

// ������ ������
// : ��Ƽ ������ ȯ�濡�� ���ÿ� ���� ���� �����尡 ������ �Լ���
// ����� ���, ������ �߻��ϴ��� ����

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* foo(void* arg)
{
    // for (int i = 0; i < 1000000; ++i) {
    //     pthread_mutex_lock(&mutex);
    //     sum += 1;
    //     pthread_mutex_unlock(&mutex);
    //     // ������ ���������� �ʽ��ϴ�.
    // }

    char str[] = "hello    world show me the money";

    char* state;

    for (char* p = strtok_r(str, " ", &state);
        p != NULL;
        p = strtok_r(NULL, " ", &state)) {
        printf("%s\n", p);
    }

    return 0;
}

int main()
{
    pthread_t thread[2];
    for (int i = 0; i < 2; ++i) {
        pthread_create(&thread[i], NULL, &foo, NULL);
    }

    // ��� �������� �۾��� ������ �� ���� ����մϴ�.
    // => pthread_join
    for (int i = 0; i < 2; ++i) {
        pthread_join(thread[i], NULL);
    }

    printf("%d\n", sum);
    return 0;
}