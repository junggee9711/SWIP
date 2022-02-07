// 24_FILE4.c
#include <stdio.h>

struct Point {
    int x;
    int y;
    int z;
};

// fwrite �Լ��� ���Ͽ� ���̳ʸ� ���·� ����� �����մϴ�.
// fread �Լ��� ������ ���̳ʸ� ������ �Է��� �����մϴ�.
/*
size_t
fread(void * ptr, size_t size, size_t nitems,
    FILE* stream);
size_t
fwrite(const void *ptr, size_t size, size_t nitems,
    FILE * stream);
*/

int main()
{
    struct Point pt = { .x = 10, .y = 20 };
    pt.x += 10;
    pt.y += 20;

    // �����ϴ� ����� �����غ��ô�.
    FILE* fp = fopen("point.bin", "w"); // wt, wb
    fwrite(&pt, sizeof pt, 1, fp);

    pt.x = 0;
    pt.y = 0;
    pt.z = 0;
    fclose(fp);

    // �ε� �մϴ�.
    FILE* fp2 = fopen("point.bin", "r");
    if (fp2 == NULL) {
        perror("fopen");
        return 1;
    }
    fread(&pt, sizeof pt, 1, fp2);

    printf("%d %d %d\n", pt.x, pt.y, pt.z);

    fclose(fp2);
}