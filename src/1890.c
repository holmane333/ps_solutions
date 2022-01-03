#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n;
long long dp[110][110];
int ary[110][110];

long long DP(int i, int j) {
	if (i == n - 1 && j == n - 1) return 1LL;
	if (i >= n || j >= n) return 0LL;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0LL;
	long long a = DP(i + ary[i][j], j);
	a += DP(i, j + ary[i][j]);
	dp[i][j] = a;
	return dp[i][j];
}

int main(void) {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lld", &ary[i][j]);
		}
	}
	printf("%lld\n", DP(0, 0));
	return 0;
}
