// extern "C" int square(int a);

#ifdef __cplusplus // ��� C++ �����Ϸ����� "__cplusplus" ��ũ�ΰ� ���� �Ǿ�����
etern "C" {
#endif

	int square(int a);

#ifdef __cplusplus
}
#endif

// �Լ� �����ε��� ���� ���� ���̴� �����Դϴ�.
// �׷���, ������ "name mangling" ���� ������, C�� C++ ��� ������ ȣȯ�� ������ �ֽ��ϴ�.
// C/C++ �� ��� �����ϴ� ����� ��ó�� ������ �մϴ�.
