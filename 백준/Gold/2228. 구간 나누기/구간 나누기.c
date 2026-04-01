#include <stdio.h>
#include <memory.h>
#pragma warning (disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))


int main(void) {
	int n, m, a[110], dp[110][110], sum[110];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int j = 1; j <= m; ++j) dp[0][j] = -1e9;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j == 1) dp[i][j] = max(dp[i][j], sum[i]);
			for (int k = 0; k <= i - 2; ++k) {
				dp[i][j] = max(dp[i][j], dp[k][j - 1] + sum[i] - sum[k + 1]);
			}
		}
	}
	/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d ", dp[i][j]);
		}puts("");
	}
	*/
	printf("%d\n", dp[n][m]);
	return 0;
}