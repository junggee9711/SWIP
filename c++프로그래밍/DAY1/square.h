// extern "C" int square(int a);

#ifdef __cplusplus // 모든 C++ 컴파일러에는 "__cplusplus" 매크로가 정의 되어있음
etern "C" {
#endif

	int square(int a);

#ifdef __cplusplus
}
#endif

// 함수 오버로딩은 아주 쉬워 보이는 문법입니다.
// 그런데, 원리인 "name mangling" 현상 때문에, C와 C++ 언어 사이의 호환성 문제가 있습니다.
// C/C++ 을 모두 지원하는 헤더는 위처럼 만들어야 합니다.
