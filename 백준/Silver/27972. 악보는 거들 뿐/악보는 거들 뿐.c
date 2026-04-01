#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define ll long long

int main(void) {
	int n, preva, a, prevstate = 0, t = 1, ma = 1, mi = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if (i == 0) {
			preva = a;
			continue;
		}
		if (preva > a) {
			if (prevstate == -1) ++t;
			else t = 2;
			prevstate = -1;
		}
		else if (preva < a) {
			if (prevstate == 1) ++t;
			else t = 2;
			prevstate = 1;
		}
		preva = a;
		ma = max(ma, t);
	}
	printf("%d\n", ma);
	return 0;
}
