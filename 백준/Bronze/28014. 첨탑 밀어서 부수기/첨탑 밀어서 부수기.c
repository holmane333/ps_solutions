#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(void) {
	int n, t, prev, cnt = 0;
	scanf("%d", &n);
	prev = -1;
	while (n--) {
		scanf("%d", &t);
		if (prev <= t) ++cnt;
		prev = t;
	}
	printf("%d\n", cnt);
	return 0;
}
