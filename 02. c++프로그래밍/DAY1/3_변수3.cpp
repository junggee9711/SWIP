// 20 page 내용

#include <iostream>
struct Point
{
	int x;
	int y;
};

int main()
{
	int		n = 0;
	Point	p1 = { 0, 0 };
	int		x1[3] = { 1,2,3 };

	// 1. C++11 에서 추가된 "일관된 초기화 (uniform initialization)" 문법
	//	  흔히 "중괄호 초기화" 라고도 합니다.
	int		n2 = { 0 } ;
	Point	p2 = { 0, 0 };
	int		x2[3] = { 1,2,3 };

	// 2. 직접초기화(direct initialization) : '=' 이 없는 경우
	//	  복사초기화(copy initialization) : '=' 이 있는 경우
	//   -> 이 2개는 약간의 차이가 있습니다. (객체지향 배울때 설명)
	int		n3{ 0 };
	Point	p3{ 0, 0 };
	int		x3[3]{ 1,2,3 };


	// 3.
	int n4 = 3.4; // C/C++ 에서 가능 (소수점이 사라지긴 하지만)
				  // 하지만, 너무 위험하다. 다른 대부분의 언어에서는 에러!

	int n5{ 3.4 }; // error. 중괄호 초기화는 데이터 손실이 있는 경우 에러
	char c{ 500 }; // error. 1byte 는 0~255 만 가능.
				   // -> 이렇게 안전한 방법으로 코딩 하는 것을 prevent narrow 라고 부릅니다. (21 page 위)
}