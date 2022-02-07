// 21 page


int main()
{
	int x[5] = { 1,2,3,4,5 };


	// 1. auto : 우변의 표현식을 보고 좌변 변수의 타입을 결정해 달라.
	//		     C++11 부터 지원
	//		     컴파일 시간에 결정되기 때문에 실행시 성능 저하 없음
	auto n = x[0]; // 컴파일 하면 "int n = x[0]" 로 변경


	// 2. decltype : () 안의 표현식의 타입을 조사해 달라.
	//		   -> auto     : 우변 표현식으로 타입 결정
	//		   -> decltype : () 안의 표현식으로 타입 결정
	decltype(n) n1; // int n1



	// 3. auto & decltype 이 어려운 이유
	auto a = x; // a 의 타입은? -> int* a
				// int a[5] = x; 였다면 에러이고
				// int* a = x; 였다면 에러가 아니기 때문에

	decltype(x) d; // d 의 타입은? -? int d[5]
				   // int d[5] d; 는 에러가 아니기 때문에 이 경우는 x의 정확한 타입인 int d[5] 로 결정

	const int c = 10;
	auto a1 = c; // c 의 타입은? -> int
}