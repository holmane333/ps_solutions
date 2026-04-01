#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
	int n, m;
	char str[1000010];
	scanf("%d %d", &n, &m);
	scanf("%s", str);
	int cnt = 0, ci = 0, co = 0;
	for (int i = 0; i < m; ++i) {
		if (str[i] == 'O') {
			if (ci - co == 1) {
				++co;
			}
			else {
				cnt += max(0, ci - 1 - n + 1);
				ci = 0;
				co = 0;
			}
		}
		else {
			if (ci - co == 0) {
				++ci;
			}
			else {
				cnt += max(0, ci - 1 - n + 1);
				ci = 1;
				co = 0;
			}
		}
	}
	cnt += max(0, ci - 1 - n + 1);
	printf("%d\n", cnt);
	return 0;
}
