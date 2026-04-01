#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int cmp(const void* num1, const void* num2) {
	return *(int*)num2 - *(int*)num1;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(void) {
	int n, ary[1010];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ary[i]);
	}
	qsort(ary, n, sizeof(int), cmp);
	for (int i = 0; i < n - 1; ++i) {
		ary[i] -= ary[i + 1];
	}
	int res = ary[0];
	
	for (int i = 1; i < n - 1; ++i) {
		res = gcd(res, ary[i]);
	}
	printf("%d\n", res);
	return 0;
}
