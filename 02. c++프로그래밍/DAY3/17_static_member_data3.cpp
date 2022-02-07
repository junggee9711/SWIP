// 17_static_member_data3 112 page 
#include <iostream>


// Car 객체가 몇개나 생성되었는지 조사하고 싶다.

// 방법 3. static 멤버 데이터 (정적멤버데이터)
//		  : (같은이름을) "클래스당 한개씩" 사용가능한 전역변수로 볼 수 있습니다.
//
//	특징 1) 클래스 외부에 선언이 필요
//		 2) class 객체를 만들지 않아도 전역변수와 같은 메모리에 존재 => "접근지정자"를 사용 가능한 전역변수
//		 3) 그러므로, class 객체의 크기에 포함되지 않음

class Car
{
	int speed;
public:
	static int cnt; /* = 0 등으로 초기화가 안됩니다. */
					// static 멤버 데이터

	Car() { ++cnt; }
	~Car() { --cnt; }
};
// static 멤버 데이터는 class 외부에서 선언이 필요합니다. 초기화도 여기서.
// => Car:: 를 빼면 마치 "전역변수" 와 같고, 전역변수와 같은 메모리 영역에 잡혀 수명도 같음!
int Car::cnt = 0;


int main()
{
	// 4) static 멤버 데이터는 객체가 업서도 메모리에 존재하기 때문에 아래와 같이 cnt 를 출력 가능
	std::cout << Car::cnt << std::endl;

	Car c1;
	Car c2;		

	// 5) static 멤버 데잍터 접근 방법
	//  (1) 클래스이름::cnt	=> 권장 !!
	//  (2) 객체이름.cnt		=> static 인지 아닌지 판단이 안됩니다. (가독성 이슈)

	std::cout << Car::cnt << std::endl;	// (1)
	std::cout << c1.cnt << std::endl;	// (2)

	// 다른 객체지향 언어 (C#, java, swift 등) 는 모두
	// "클래스 이름" 으로만 static 멤버에 접근 가능합니다.

}
