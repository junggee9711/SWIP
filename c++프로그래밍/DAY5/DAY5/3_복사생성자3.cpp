#include <iostream>
// ����Ʈ ���� �������� ������
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