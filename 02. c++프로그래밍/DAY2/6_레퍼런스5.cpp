// 6_���۷���5 45 page


struct Rect
{
	int left;
	int top;
	int right;
	int bottom;
};

// 1. call by value �� ������ ���� �������� �ʰڴٴ� ���.
//	  ������, ���纻�� ���� �޸� ������尡 ���� �Ѵ�.
// 2. const reference �� ����ϸ� ���纻 ����
//	  ������ ���� �������� �ʰڴٰ� ����� �� �ִ�. 
//	  (call by value ó�� �޸𸮸� �߰��� ������� �����鼭)

//void foo(? r)
void foo(const Rect& r)
{
//	r.left = 10;			// error. �߻� ��ų�� ����
}

int main()
{
	Rect r = { 1, 1, 10, 10 };
	foo(r);					// ���� : foo �� ����� r�� ���¸� �����ؼ� �Է� ������ �ȵȴ�.
}




// ������ ���� �ڵ�� ?
void foo(int n) {}			// 1. ���� �ڵ� 
							//	- ���� �������δ� 2���� ���� �ڵ� ������, �ƴ�.
							//  - primitive type �� ��� �޸𸮰� �۰�, ����ȭ�� �� ����Ǳ� ����.
void foo(const int& n) {}	// 2. ���� �ʴ�.


// ��� : �Լ� ���ڸ� �޴� ���
//		1. ���ڰ��� �����Ϸ���,
//		   => �����͵� ����, reference �� �����ϴ�.
//			  ������ "reference �� ���� �θ� ���"
//			  swap(int*, int*)
//			  swap(int&, int&)
//
//		2. ���ڰ��� �������� �ʰڴٸ�,
//		   A. primitive type (int, double..) : "call by value" 
//											=> ex. void foo(int n)
//		   B. user define type (struct..)    : "const reference"
//											=> ex. void foo(const Rect& r)



// ���� "C++ core guideline" �˻��� ������ - 1��°��ũ