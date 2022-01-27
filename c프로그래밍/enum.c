#include <stdio.h>

// C���� ����� ���� Ÿ����
// 1. struct
// 2. enum
// 3. union

// STATE
// #define STATE_READY 0
// #define STATE_RUNNING 1
// #define STATE_WAIT 2

// OTHER STATE
#define OTHER_XXX 100

enum State {
    STATE_READY = 0,
    STATE_RUNNING,
    STATE_WAIT
};

int main()
{
    enum State state = STATE_READY;
    state = OTHER_XXX;
    // C���� ������ ������,
    // �������� ���� Ÿ�԰��� �Ϲ����� ��ȯ�� ���������
    // C++������ ������� �ʽ��ϴ�.

    // �ٸ� ������ ���� �� ���, ������ ������ �߻����� �ʴ´�.
    // int state = STATE_WAIT;
    // int state = OTHER_XXX;

    return 0;
}