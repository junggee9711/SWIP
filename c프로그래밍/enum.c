#include <stdio.h>

// C언어에는 사용자 정의 타입은
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
    // C언어는 오류가 없지만,
    // 열거형과 정수 타입간의 암묵적인 변환을 허용하지만
    // C++에서는 허용하지 않습니다.

    // 다른 종류의 값이 들어갈 경우, 컴파일 오류가 발생하지 않는다.
    // int state = STATE_WAIT;
    // int state = OTHER_XXX;

    return 0;
}