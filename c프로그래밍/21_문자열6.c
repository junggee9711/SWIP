#include <stdio.h>
#include <string.h>

// ��ū�� �и��ϴ� �Լ� => strtok
// : ���������� ���� �޸�(���� ����, ���� ���� ����)�� ����մϴ�.
#if 0
char* strtok(char* str, const char* sep);
#endif

int main()
{
    char str[] = "hello    world show me the money";

    for (char* p = strtok(str, " ");
        p != NULL;
        p = strtok(NULL, " ")) {
        printf("%s\n", p);
    }

#if 0
    char* p = strtok(str, " ");
    printf("%s\n", p);

    p = strtok(NULL, " ");
    printf("%s\n", p);

    p = strtok(NULL, " ");
    printf("%s\n", p);
#endif

    return 0;
}