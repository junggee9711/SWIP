// �޸� ���� ã��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alloc_info {
	char file[256];
	char func[256];
	int line;
	void* addr;
	int size;
};

struct alloc_info info[1000];
int cnt = 0;

void* debug_malloc(int size, const char* file, const char* func, int line)
{
	void* p = malloc(size);

	strcpy(info[cnt].file, file);
	strcpy(info[cnt].func, func);
	info[cnt].line = line;
	info[cnt].size = size;
	info[cnt].addr = p;

	++cnt;

	return p;
}

void debug_free(void* addr)
{
	for (int i = 0; i < cnt; ++i) {
		if (info[i].addr == addr) {
			free(addr);
			info[i].addr = NULL;
			return;
		}
	}

	printf("�߸��� �ּ� �Դϴ�...\n");
}


void debug_check()
{
	int leak = 0;
	int bytes = 0;
	// cnt �ȿ��� NULL �� �Ǿ� ���� ���� addr �� �ִ��� Ȯ���մϴ�.
	for (int i = 0; i < cnt; ++i) {
		if (info[i].addr) {
			++leak;
			bytes += info[i].size;
		}
	}
	printf("%d memory leaks - %d\n", leak, bytes);
	return;
}

#define malloc(size) debug_malloc(size, __FILE__, __func__, __LINE__)
#define free(addr) debug_free(addr) // ġȯ���� �۵���

int main()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	int* p2 = (int*)malloc(sizeof(int) * 10);
	int* p3 = (int*)malloc(sizeof(int) * 10);

	free(p1);
	free(p2);

	debug_check();
}