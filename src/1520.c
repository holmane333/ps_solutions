#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int dp[600][600];
int map[600][600];
int n, m;

int DP(int i, int j) {
	if (i > n && j > m && i <= 0 && j <= 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	
	int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	if (map[i - 1][j] > map[i][j]) d1 = DP(i - 1, j);
	if (map[i + 1][j] > map[i][j]) d2 = DP(i + 1, j);
	if (map[i][j - 1] > map[i][j]) d3 = DP(i, j - 1);
	if (map[i][j + 1] > map[i][j]) d4 = DP(i, j + 1);
	dp[i][j] = d1 + d2 + d3 + d4;
	return dp[i][j];
}

int main() {
	scanf("%d %d", &n, &m);
	memset(map, -1, sizeof(map));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[1][1] = 1;
	printf("%d\n", DP(n, m));
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", dp[i][j]);
		}puts("");
	}*/
	
	return 0;
}
