// 8_explicit2

#include <vector>
#include <string>

void f1(std::string s) {}			// std::string s = "hello" ����.
void f2(std::vector<int> v) {}		// std::vector<int> v = 10 �� ������ ����.

int main()
{
	std::string		 s1("hello");	// �׷��Ƿ�, string(const char*) �����ڰ� �ֽ��ϴ�.
	std::vector<int> v1(10);		// �׷��Ƿ�, vector(int) �����ڰ� �ֽ��ϴ�.

	// �Ʒ� 2���� �ڵ尡 ���� �Ǵ°� �������? �ȵǴ°� �������?
	f1("hello");					// ok.
//	f2(10);							// error. �ȵǴ°� ���⶧����, "�Լ��� ���ڷ� ������" explicit���� ������.
}

// ���� : smkang@codenuri.co.kr ����
