#include <iostream>
#include <stdlib.h>

class Vector
{
	int* buff;
	int size;
public:
	Vector(int sz) : size(sz)
	{
		buff = new int[size];			
	}
	~Vector()
	{
		delete[] buff;					
	}

	void setAt(int idx, int value)
	{
		buff[idx] = value;
	}
	int getAt(int idx)
	{
		return buff[idx];
	}
	void resize(int newsize)
	{
		if (newsize > size) {
			int* temp = new int[newsize];

			memcpy(temp, buff, sizeof(int) * size);

			delete buff;

			buff = temp;

			size = newsize;
		}
	}
};

int main()
{
	Vector v(5);

	v.setAt(0, 10);

	v.resize(10);					// 버퍼(배열 길이)를 10으로 키우는 함수 추가

	int n = v.getAt(0);

	std::cout << n << std::endl;
}