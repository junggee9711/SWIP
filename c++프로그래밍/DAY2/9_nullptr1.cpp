// 9_nullptr 54 page

int main()
{
//	int* p = 10;		// error. 포인터는 0 이외 정수로 초기화 불가.

	int  n1 = 0;
	int* p1 = 0;			// 0은 정수지만, 포인터 (NULL) 로의 암시적 형변환을 허용.
							// 컴파일러에 의해 특별하게 처리됩니다.
							// => '암시적' 형변환은 문제가 많다고 봄!

	// C++11 부터 포인터 0에 해당하는 nullptr 을 만들었습니다.
	int* p2 = nullptr;		// C++11 부터 포인터 초기화시 이 코드 권장.
//	int  n2 = nullptr;		// error. nullptr 은 정수 0 이 아님.
 }