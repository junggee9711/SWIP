// 35 page

// C와 다른 C++함수의 특징 5. 함수 삭제



// 2개 정수의 최대 공약수 구하기
int gcd(int a, int b)
{
	return b != 0 ? gcd(b, a % b) : a;
}

// 1)
// double gcd(double a, double b); // 의도적으로 선언만, 구현을 제공하지 않는다.
								   // 사용시 '링크에러' 를 내겠다는 의미.
// 2)
double gcd(double a, double b) = delete; // C++11 에서 도입된, 함수 삭제라는 문법


int main()
{
	gcd(10, 4);
	gcd(3.3, 4.4);				// 선언만 있을때,
								// 1) 의 경우, 컴파일러는 call "double 버전을 링커가 찾아서 주소를 채워달라"
								//		=> '링크 error' 발생
								// 2) 의 경우, "삭제된 함수를 불러오려 합니다"
								//		=> '컴파일 error' 발생 (이 경우가 더 좋음!)
}