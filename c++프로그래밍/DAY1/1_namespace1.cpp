// 1_namespace1.cpp - 7 pag

// namespace �󿡼� ������, �Լ��� ���� �̸��� �ߺ��� �����ϴ�! -> �ټ��� �ο��� ������Ʈ�� �����Ҷ� ����


#include <stdio.h>

namespace Audio
{
	void init()
	{
		printf("Audio init\n");
	}
}

namespace Video
{
	// Video ���� �Լ�, ����ü, ������������ ��� �̾ȿ��� �����.
	void init()
	{
		printf("Video init\n");
	}
}



int main()
{
	Video::init();
}