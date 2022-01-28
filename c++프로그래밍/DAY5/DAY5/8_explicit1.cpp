// 8_explicit1

class Vector
{
	int size;
public:
	// explicit ������ : �ش� class �� �����ʱ�ȭ�� ����Ҽ� ����,
	//					 ���� �ʱ�ȭ�� �����մϴ�.
	explicit Vector(int n) : size(n) {}
};

void f(Vector v) {}


int main()
{
	// ���ڷ� int �Ѱ��� ������ �����ڰ� ������ �Ʒ� ó�� 4���� ������� ��ü�����˴ϴ�.
	// C++98 ���� ����,
	Vector v1(10);			// direct initialization - 1
	Vector v2 = 10;			// copy initialization - 2 (�����ʱ�ȭ, = �� ����ϴ� �ʱ�ȭ ���)

	// C++11 ���� ����,
	Vector v3{ 10 };		// direct initialization - 3
	Vector v4 = { 10 };		// copy initialization - 4

	f(10);					// ok. f(Vector v = 10) �̹Ƿ� 2���� ���ؼ� ����
							// => ��, �Լ� ���� ������ "���� �ʱ�ȭ"�� �ϴ� ǥ�����Դϴ�.
							// ��ü f�� �����ڰ� explicit �����ڶ�� error.
}