// 51 page

// 3. const_cast : "���� Ÿ����" ����� ���Ÿ� ���� ĳ����

int main()
{
	const int c = 10;
	
//	int* p1 = &c;							// error. ����� ����� �ƴ� �����ͷ� �ٲܼ� ����.
	int* p2 = (int*)&c;						// ok.	  �����ϴ�.
//	int* p3 = static_cast<int*>(&c);		// error. �ո������� ����.
//	int* p4 = reinterpret_cast<int*>(&c);	// error. '���'�� ������ �ɷ��� ����.
	int* p5 = const_cast<int*>(&c);			// ok.
											// const int &c �� <int*> �� Ÿ���� ���ƾ� ��.

}

// ��� : �뵵�� �°� ĳ������ �������.
//		  �׷���, ������ �ڵ带 ���ؼ��� "static_cast" �� �������.
//		  �׷���, �Ӻ���� �оߴ� "reinterpret_cast" �� �ʿ��ϱ� �ϴ�.


// 50 page ������ "dynamic_cast" �� "��ӹ����� �˾ƾ� �մϴ�."