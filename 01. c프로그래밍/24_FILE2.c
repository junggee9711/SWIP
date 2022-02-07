#include <stdio.h>

// stdin
// stdout => FILE* �Դϴ�.
// stderr
// 1. fopen("���� ���", "���")
//   "r": �б� ���
//   => ��ο� ������ �������� ������, �����մϴ�.
//   "w": ���� ���
//   => ��ο� ������ �������� ������, ���ο� ������ ����ϴ�.
//      ��ο� ������ �����ϸ�, ������ ũ�⸦ 0���� �����ؼ�
//      �����ݴϴ�.

// 2. fprintf(FILE*, format, ...);
// 3. ������ �ڿ��̱� ������, �ݵ�� fclose�� ����
//    �ݾ��־�� �մϴ�.

int main()
{
    FILE* fp = fopen("a.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "File open error...\n");
        return 1;
    }

    for (int i = 0; i < 10; ++i) {
        fprintf(fp, "Hello\n");
    }

    fclose(fp);

    return 0;
}