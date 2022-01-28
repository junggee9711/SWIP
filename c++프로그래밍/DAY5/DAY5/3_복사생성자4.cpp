// 3_���������4

#include <iostream>
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

	// 1. ���� ���� (deep copy) �� ������ ���� ������
	// => ���� ���� : �����Ͱ� �ƴ϶� �޸� ��ü�� ���� �Ѱ�. 
	Buffer(const Buffer& buf) : size(buf.size)
	{
		// 1) �����Ͱ� �ƴ� ����� �׳� ���� �Ѵ�
		// size = buf.size;			// <== �ʱ�ȭ����Ʈ���� �ʱ�ȭ�� �� ����
		// 2) ������ ����� �޸� �Ҵ��� �޸� ��ü�� �����Ѵ�.
		//  => b1, b2 �� ���� �ٸ� �ּҸ� ����Ű���� �Ѵ�.
		buff = new int[size];		// <== buff �� ��� ���� buff
		memcpy(buff, buf.buff, sizeof(int) * size);
	}
};

// 2. ���
//  1) class ���������� �����Ͱ��� ����� ���ٸ�.. �����Ϸ��� ���� ���� �����ڸ� ����ص� ���� �����ϴ�
//  2) class ���������� �����Ͱ��� ����� �ִٸ�, �׻� �����մϴ� (�������� ����)
//	  => �ݵ�� ���� �����ڸ� ���� ���� �ذ��ؾ� �մϴ�.
// 
// 3. ���� - �ǵ��� Ŭ���� ����� �����͸� ���� ������.
//  1) char* => string ���
//  2) int* p = new int[10] => vector<int> v(10) ����ϼ���.


/* ���蹮�� : �����Ϸ��� ����� ��������ڴ� "deep copy" �� ����ϹǷ� �����͸�� ���簡 �ʿ� �����ϴ�. false.*/

int main()
{
	Buffer b1(64);
	Buffer b2 = b1;			
}