// 3_복사생성자3

#include <iostream>
// 1. 디폴트 복사 생성자의 문제점 (컴파일러가 자동으로 생성하는 복사 생성자의 문제점)
//  - 클래스 안에 "포인터 멤버변수가 있다면",
//	  컴파일러가 만드는 복사 생성자는 "얕은 복사 (shallow copy)" 현상을 일으킵니다.
//  - 얕은 복사 : 메모리 자체를 복사하지 않고, 주소만 복사하는 현상

//  - 반드시 "사용자가 복사 생성자를 제공해서 문제를 해결" 해야 합니다.
class Buffer
{
	int* buff;
	int size;
public:
	Buffer(int sz) : size(sz)
	{
		buff = new int[size];
	}
	~Buffer()
	{
		delete[] buff;
	}

};
int main()
{
	Buffer b1(64);
	Buffer b2 = b1;		// runtime error 발생.
						// 에러 나지 않을수도 있지만, 분명 잘못된 코드입니다.
						// => "복사 생성자" 가 호출되어 b1.buff 를 b2.buff 에 복제하면,
						//    b1의 소멸자로 buff 가 delete 된 후에, b2 의 소멸자가 delete 할 buff 가 사라짐
						//   = "얕은 복사 (shallow copy)"
			
}