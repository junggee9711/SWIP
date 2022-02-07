// 11_접근지정자 74 page


// 1. 접근지정자 : 멤버데이터를 외부에서 직접 접근하면 객체의 상태가 불안해 질수있다.
//			   데이터를 private 영역에 놓아서 외부에서 잘못된 사용을 막는다.
//			  => 캡슐화(encapsulation), 정보 은닉(information hiding)


// * 용어 정리
//  - 객체 (Object) : 세상에 존재하는 모든 사물.
//					  프로그램에서 변수, 함수등도 모두 Object!!! 지만,
//					  관례적으로,  int n;   => "변수" 라고 함 (primitive).
//								  Bike b;  => "객체(Object)" 라고 함 (user made).


// 2. "C++ 에서" stuct vs class 의 차이점은 아래 단 한가지 입니다.
//  - struct : 접근지정자 생략시 public 이 디폴트
//	- class : 접근지정자 생략시 private 이 디폴트
//   => 이외에 struct 로 할수 있는것은 class 로도 할 수 있음.
//   => C#, java 등의 다른 언어는 차이점이 아주 많습니다.


// struct Bike
class Bike
{
//private:				 	// 1) private 접근 지정자
							// 멤버 함수에서만 접근할수 있고, 외부에서는 접근할 수 없다.
							// == struct / class 내에서만 사용 가능
	int speed;
	int gear;

public:						// 2) public 접근 지정자
							// 아래 모든 멤버는 외부에서 접근 가능하다.
	void setGear(int value)
	{
		if ( value > 1)
			gear = value;	// 인자값의 유효성을 확인후에 상태를 변경하는게 가능!!!
	}
};

int main()
{
	Bike b;
//	b.speed = 30;			// error. 외부에서 접근
//	b.gear = -10;			// error. 외부에서 접근
	b.setGear(-10);			// ok. 하지만 잘못된 값(<= 1)이므로 상태 변경 안됨.
}