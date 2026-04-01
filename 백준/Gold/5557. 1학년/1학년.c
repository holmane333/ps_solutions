#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int n, ary[101];
	long long int dp[101][21];
	scanf("%d", &n);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ary[i]);
	}

	dp[1][ary[1]]++;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + ary[i] <= 20) dp[i][j + ary[i]] += dp[i - 1][j];
				if (j - ary[i] >= 0) dp[i][j - ary[i]] += dp[i - 1][j];
			}
		}
	}

	printf("%lld\n", dp[n - 1][ary[n]]);

	return 0;
}