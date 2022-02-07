#include <iostream>
#include <stdlib.h>

// OOP �� �߱��ϴ� ���� - �ػ��� ���뼺 !!

template<typename T>			// �Լ� ���ø��� �ƴ�, Ŭ���� ���ø�!
class Vector
{
	T* buff;
	int size;
public:
	Vector(int sz) : buff = new T[size], size(sz)			// ok. ������ ���Ѿ� ��.
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
//	Vector v(5);			// error. TŸ���� ������ �� �����ϴ�.
	Vector<int> v(5);		// Ŭ���� ���ø� ���.

	v.setAt(0, 10);

	v.resize(10);					

	int n = v.getAt(0);

	std::cout << n << std::endl;
}