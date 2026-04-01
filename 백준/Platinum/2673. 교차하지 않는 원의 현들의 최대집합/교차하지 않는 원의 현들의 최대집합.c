#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, dp[110][110], ary[110][110];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ary[a][b] = 1;
		ary[b][a] = 1;
	}
	for (int j = 1; j <= 100; ++j) {
		for (int i = j; i >= 1; --i) {
			for (int k = i; k < j; ++k) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + ary[i][j]);
			}
		}
	}
	printf("%d\n", dp[1][100]);
	return 0;
}
