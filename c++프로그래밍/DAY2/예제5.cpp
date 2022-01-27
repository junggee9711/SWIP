#include <iostream>
#include <stdlib.h>

// OOP 를 추구하는 이유 - 극상의 재사용성 !!

template<typename T>			// 함수 템플릿이 아닌, 클래스 템플릿!
class Vector
{
	T* buff;
	int size;
public:
	Vector(int sz) : buff = new T[size], size(sz)			// ok. 순서는 지켜야 함.
	{		
//		buff = new T[size];									// ok.
	}
	~Vector()
	{
		delete[] buff;
	}

	void setAt(int idx, T value)
	{
		buff[idx] = value;
	}
	T getAt(int idx)
	{
		return buff[idx];
	}
	void resize(int newsize)
	{
		if (newsize > size) {
			T* temp = new T[newsize];

			memcpy(temp, buff, sizeof(T) * size);

			delete buff;

			buff = temp;

			size = newsize;
		}
	}
};

int main()
{
//	Vector v(5);			// error. T타입이 결정될 수 없습니다.
	Vector<int> v(5);		// 클래스 템플릿 사용.

	v.setAt(0, 10);

	v.resize(10);					

	int n = v.getAt(0);

	std::cout << n << std::endl;
}