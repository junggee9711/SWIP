// 메모리 누수 찾기
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

	printf("잘못된 주소 입니다...\n");
}


void debug_check()
{
	int leak = 0;
	int bytes = 0;
	// cnt 안에서 NULL 로 되어 있지 않은 addr 이 있는지 확인합니다.
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
#define free(addr) debug_free(addr) // 치환으로 작동함

int main()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	int* p2 = (int*)malloc(sizeof(int) * 10);
	int* p3 = (int*)malloc(sizeof(int) * 10);

	free(p1);
	free(p2);

	debug_check();
}