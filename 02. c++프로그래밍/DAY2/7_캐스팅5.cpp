
int main()
{

	// const double �ּҸ� char* �� ���

	const double d = 3.14;

	char* p1 = (char*)&d;							// ok. C �� ���.

	// �� ĳ������ C++ �� �غ�����
//	char* p2 = reinterpret_cast<char*><char*>(&d);	// error. const ���� �ȵ�.
//	char* p2 = const_cast<char*>(&d));				// error. ���� Ÿ���� const �Ӽ��� ����.

	char* p2 = reinterpret_cast<char*>( const_cast<double*>(&d) );
	char* p2 = const_cast<char*>( reinterpret_cast<const char*>(&d) );
}