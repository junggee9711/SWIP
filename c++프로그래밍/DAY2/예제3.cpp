#include <iostream>

// OOP : 객체지향 프로그래밍 (Object Oriented Programming)

// 1. 타입을 먼저 설계 해라!!

//   - 타입에서는 "Rect", "Point", "Person" 같은 것만 있는 것은 아닙니다.
//   - "동적배열" 이라는 타입을 설계해 봅시다.

class Vector
{
	int* buff;
	int size;
public:
	Vector(int sz) : size(sz)
	{
		buff = new int[size];			// 생성자에서 동적 할당으로 메모리를 할당했다면,
	}
	~Vector()
	{
		delete[] buff;					// 소멸자에서 delete[] 해주어야 함.
	}

	void setAt(int idx, int value)
	{
		buff[idx] = value;
	}
	int getAt(int idx)
	{
		return buff[idx];
	}
};

int main()
{
	Vector v(5);						// 배열의 길이가 고정됨

	v.setAt(0, 10);
	
	int n = v.getAt(0);

	std::cout << n << std::endl;
}