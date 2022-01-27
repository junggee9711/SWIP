// 1_namespace2.cpp - 8 pag

#include <stdio.h>

namespace Video
{
	// Video ���� �Լ�, ����ü, ������������ ��� �̾ȿ��� �����.
	void init()
	{
		printf("Video init\n");
	}
}

// global namespace : Ư�� �̸� ������ ���Ե��� ���� ����.
void init() { printf("global init\n"); }

// using �� �Լ��� �Ǵ� �ۿ� ���� �� �ֽ��ϴ�.
// �Լ� �ȿ� ������ �ش� �Լ������� ����, �ۿ� ������ ��ü �Լ����� ����
using Video::init;

int main()
{
	// namespace �ȿ� �ִ� ��Ҹ� ����ϴ� 3���� ��� - 8page
	Video::init(); // 1. ������ �̸�

	using Video::init; // 2. using ����(declaration) - ���� �Ŀ��� Video �� ���� �ʰ� init() ��� ����.
	init();			   //    init �Լ��� Video �̸� ���� ���.
	::init();		   //	 :: ==> scope resolution ������. global namespace �� ����� �ǹ�

	using namespace Video; // 3. using ���þ�(directive)
	init();				   //	 Video ���� ��� �ɺ��� Video �̸� ���� ���.

	//	 => �̸� �浹�� ���� �߻��ϴ� �����̹Ƿ� using �� ������� �ʴ°��� ����


}