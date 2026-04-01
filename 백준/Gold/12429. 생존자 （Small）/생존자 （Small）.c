#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

typedef struct pair {
	int p, s;
} pair;

int cmp(const void* num1, const void* num2) {
	pair aa = *(pair*)num1;	
	pair bb = *(pair*)num2;
	//if (aa.p == bb.p) return aa.s > bb.s;
	//return aa.p > bb.p;
	return aa.p + aa.s > bb.p + bb.s;
}

int main(void) {
	int tc, n, dp[101010], m, idx;
	pair a[1010];
	scanf("%d", &tc);
	
	for (int test = 1; test <= tc; ++test) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &(a[i].p), &(a[i].s));
		}
		qsort(a, n, sizeof(pair), cmp);
		m = 0;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; ++i) {
			idx = min(m, a[i].p);
			for (int j = idx; j >= 0; --j) {
				if (dp[j]) {
					dp[j + a[i].s] = 1;
					m = max(m, j + a[i].s);
				}
			}
			if (m == 101000) break;
		}
		printf("Case #%d: %d\n", test, m);
	}
	
	return 0;
}
