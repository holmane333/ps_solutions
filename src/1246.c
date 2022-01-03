#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int ary[1001], sum[1001];

int cmp(const void* num1, const void* num2) {
	return *(int*)num1 - *(int*)num2;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &ary[i]);
	}
	qsort(ary + 1, m, sizeof(int), cmp);
	long long res = 0LL, idx = 0;
	for (int i = 1; i <= m; ++i) {
		long long temp = (long long)min(n, m - i + 1) * ary[i];
		if (res < temp) {
			res = temp;
			idx = (long long)ary[i];
		}
	}
	printf("%lld %lld\n", idx, res);
	return 0;
}