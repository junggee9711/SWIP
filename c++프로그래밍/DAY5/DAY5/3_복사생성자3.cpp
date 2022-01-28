#include <iostream>
// 디폴트 복사 생성자의 문제점
class Buffer
{
	int* buff;
	int size;
public:
	Buffer(int sz) : size(sz)
	{
		buff = new int[size];
	}

};
int main()
{
	Buffer b1(64);
}