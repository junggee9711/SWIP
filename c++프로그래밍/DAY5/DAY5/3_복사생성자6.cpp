// 3_���������6

#include <iostream>
#include <mutex>

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

	// �Ʒ��� �����Ϸ����� ���� �����ڰ� �ʿ������ ������ ����� ����ϴ� ��
	// => �ڵ����� ���� ���� �����ڸ� delete �϶�� ���
	Buffer(const Buffer&) = delete;
};


int main()
{
	Buffer b1(64);
//	Buffer b2 = b1;		// error. ���� �����ڰ� ���� ������.	

	// Ÿ�Ե��߿��� �������� ���������� "����Ǹ� �ȵǴ� Ÿ��" �� �ֽ��ϴ�.
	// => �̷� ���, "��������ڸ� ���� �մϴ�"
	std::mutex m1;
//	std::mutex m2 = m1; // error. ���ؽ��� ���� �����ڰ� �����Ǿ� �ֽ��ϴ�.
}