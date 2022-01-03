#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int ary[2000][2], idx, max = INT_MIN;
int dp[2000][20][20];

int DP(int n, int m, int i) {
	if (i >= idx) return 0;
	if (dp[i][n][m] != -1) return dp[i][n][m];
	if (n < 15) 
		dp[i][n][m] = dp[i][n][m] > DP(n + 1, m, i + 1) + ary[i][0] ? dp[i][n][m] : DP(n + 1, m, i + 1) + ary[i][0];
	if (m < 15) 
		dp[i][n][m] = dp[i][n][m] > DP(n, m + 1, i + 1) + ary[i][1] ? dp[i][n][m] : DP(n, m + 1, i + 1) + ary[i][1];
	dp[i][n][m] = dp[i][n][m] > DP(n, m, i + 1) ? dp[i][n][m] : DP(n, m, i + 1);
	return dp[i][n][m];
}

int main() {
	int n, m;
	for (int i = 0;; i++) {
		if (scanf("%d %d", &n, &m) == EOF) break;
		ary[idx][0] = n;
		ary[idx++][1] = m;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", DP(0, 0, 0));
	

	return 0;
}