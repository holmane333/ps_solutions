#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int ary[1001], sum[1001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1, t = 1; i <= 1000; i += t++) {
		for (int j = 0; j < t; ++j) {
			ary[i + j] = t;
		}
	}
	for (int i = 1; i <= 1000; ++i) sum[i] = sum[i - 1] + ary[i];
	printf("%d\n", sum[m] - sum[n - 1]);
	return 0;
}