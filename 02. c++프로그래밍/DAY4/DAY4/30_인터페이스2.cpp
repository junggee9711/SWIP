// 30_�������̽�2

#include <iostream>


// 2. ���� ���� (loosely coupling)
//	: �ϳ��� Ŭ������ �ٸ� Ŭ���� ����, ���Ŭ������ �߻� Ŭ������ ���ؼ� ����ϴ°�.
//	=> ��ü ������ ������ ������..

// - ��� ����
// 1) �������̽� : ���Ѿ��ϴ� ��Ģ�� ���� ( = ���������Լ��� ����ִ� Ŭ����)
// 2) �߻�Ŭ���� : ���Ѿ��ϴ� ��Ģ + �����ֱ����� �����

// �ٸ� ��ü���� ���� "interface" ��� Ű���尡 ������,
// C++ �� �߻� Ŭ���� �������� �������̽��� ����ϴ�.


// ���蹮�� : C++ ������ "interface" Ű���带 �̿��ؼ� �������̽��� �����. false //

//---------------------------------------------------------------------------------
// ī�޶� ���� �������� ����, ��Ģ(���Ŭ������ �߻�Ŭ����)�� ��������.
// ��Ģ : "��� ī�޶�� �Ʒ� ���Ŭ�����κ��� �Ļ��Ǿ�� �Ѵ�." ��� ��������,
//		  "��� ī�޶�� ICamera �������̽��� �����ؾ� �Ѵ�." ��� ǥ���մϴ�.

class ICamera				// ��������� �������� �ʰ�, ��Ģ�� ����
{							// = "�������̽�"
public:
	virtual void take() = 0;
};


// ���� ī�޶�� ������, ��Ģ�� �ִ�.. ��Ģ��θ� ����ϸ� �ȴ�.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};

class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "take UHD picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);		// ok.

	UHDCamera uhc;
	p.useCamera(&uhc);		// ok.
}