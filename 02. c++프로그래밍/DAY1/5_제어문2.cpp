// 5_제어문2 39 page

// 2. 초기화 구문을 가진 제어문

int foo()
{
	return 0;
}

int main()
{
	int ret = foo();
	if (ret == 0) {
	}
	// ----------------------------

	// C++17 부터 "init if" 라는 구문 등장
	// => ret 변수가 함수가 끝날때가 아니라, if 문이 끝날때 바로 파괴됨
	if (int ret = foo(); ret == 0) {
	}

	switch (int n = foo(); n)
	{
		case 1: break;
		case 2: break;
	}
}