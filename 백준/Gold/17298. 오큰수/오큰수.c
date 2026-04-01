#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n;
int ary[1000001], res[1000001], stack[1000001], ft;

int main(void) {
	scanf("%d", &n);
	memset(res, -1, sizeof(res));
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
		while (ft != 0) {
			if (ary[stack[ft - 1]] < ary[i]) {
				res[stack[--ft]] = ary[i];
			}
			else break;
		}
		stack[ft++] = i;
		
	}
	for (int i = 0; i < n; i++) printf("%d ", res[i]);
	puts("");
	return 0;
}