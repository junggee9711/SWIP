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

    // 저장하는 기능을 구현해봅시다.
    FILE* fp = fopen("point.bin", "w+"); // wt, wb
    // r+: Read / Write
    // => 파일이 존재하지 않을 경우 오류가 발생합니다.
    // w+: Read / Write
    // => 파일이 존재하지 않으면 새로운 파일을 생성합니다.
    //    파일이 존재하면, 기존 파일의 크기를 0으로 바꿉니다.

    fwrite(&pt, sizeof pt, 1, fp);

    pt.x = 0;
    pt.y = 0;
    pt.z = 0;

    // fseek(FP*, 오프셋, 기준)
    // SEEK_SET: 시작 위치
    // SEEK_END: 끝 위치
    // SEEK_CUR: 현재 위치
    fseek(fp, 0, SEEK_SET);

    fread(&pt, sizeof pt, 1, fp); // !!!
    printf("%d %d %d\n", pt.x, pt.y, pt.z);

    fclose(fp);
}