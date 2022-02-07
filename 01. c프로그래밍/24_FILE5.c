// 24_FILE4.c
#include <stdio.h>

struct Point {
    int x;
    int y;
    int z;
};

int main()
{
    struct Point pt = { .x = 10, .y = 20 };
    pt.x += 10;
    pt.y += 20;

    // �����ϴ� ����� �����غ��ô�.
    FILE* fp = fopen("point.bin", "w+"); // wt, wb
    // r+: Read / Write
    // => ������ �������� ���� ��� ������ �߻��մϴ�.
    // w+: Read / Write
    // => ������ �������� ������ ���ο� ������ �����մϴ�.
    //    ������ �����ϸ�, ���� ������ ũ�⸦ 0���� �ٲߴϴ�.

    fwrite(&pt, sizeof pt, 1, fp);

    pt.x = 0;
    pt.y = 0;
    pt.z = 0;

    // fseek(FP*, ������, ����)
    // SEEK_SET: ���� ��ġ
    // SEEK_END: �� ��ġ
    // SEEK_CUR: ���� ��ġ
    fseek(fp, 0, SEEK_SET);

    fread(&pt, sizeof pt, 1, fp); // !!!
    printf("%d %d %d\n", pt.x, pt.y, pt.z);

    fclose(fp);
}