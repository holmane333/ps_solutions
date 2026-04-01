#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>
#define abs(x) ((x) > (0) ? (x) : (-(x)))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, a, b, m[10010], ary[15][2] = {{1, 1}, {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}, {4, 1}, {4, 2}, {4, 3}};
int dp[10010][13][13];

int dis(int x, int y) {
	return abs(ary[x][0] - ary[y][0]) + abs(ary[x][1] - ary[y][1]);
}

int DP(int i, int idx1, int idx2) {
	if (i == n) return 0;
	if (dp[i][idx1][idx2] != -1) return dp[i][idx1][idx2];
	dp[i][idx1][idx2] = 1e9;
	dp[i][idx1][idx2] = min(dp[i][idx1][idx2], DP(i + 1, m[i], idx2) + dis(idx1, m[i]) + a);
	dp[i][idx1][idx2] = min(dp[i][idx1][idx2], DP(i + 1, idx1, m[i]) + dis(idx2, m[i]) + b);
	
	return dp[i][idx1][idx2];
}

int main(void) {
	scanf("%d %d %d", &n, &a, &b);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m[i]);
	}
	
	printf("%d\n", DP(0, 1, 3));
	return 0;
}
