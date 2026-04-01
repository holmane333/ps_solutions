#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int dp[300][300];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i][j] += dp[i - 1][j - l];
				dp[i][j] %= 1000000000;
			}
		}
	}
	printf("%d\n", dp[k][n]);

	return 0;
}