// 51 page

// 3. const_cast : "동일 타입의" 상수성 제거를 위한 캐스팅

int main()
{
	const int c = 10;
	
//	int* p1 = &c;							// error. 상수를 상수가 아닌 포인터로 바꿀수 없음.
	int* p2 = (int*)&c;						// ok.	  위험하다.
//	int* p3 = static_cast<int*>(&c);		// error. 합리적이지 않음.
//	int* p4 = reinterpret_cast<int*>(&c);	// error. '상수'를 제거할 능력은 없음.
	int* p5 = const_cast<int*>(&c);			// ok.
											// const int &c 과 <int*> 의 타입이 같아야 함.

}

// 결론 : 용도에 맞게 캐스팅을 사용하자.
//		  그런데, 안전한 코드를 위해서는 "static_cast" 만 사용하자.
//		  그런데, 임베디드 분야는 "reinterpret_cast" 가 필요하긴 하다.


// 50 page 위에서 "dynamic_cast" 는 "상속문법을 알아야 합니다."