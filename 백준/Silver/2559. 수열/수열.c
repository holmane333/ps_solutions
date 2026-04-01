#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
	int n, k, res = -1e9, a[100010] = {0, };
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
	for (int i = 1; i + k - 1 <= n; ++i) {
		 res = max(res, a[i + k - 1] - a[i - 1]);
	}
	
	printf("%d\n", res);
	return 0;
}
