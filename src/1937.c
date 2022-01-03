#include <stdio.h>
#include <memory.h>
#define _CRT_SECURE_NO_WARNINGS
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, map[501][501], dp[501][501];
int dx[5] = {1, -1, 0, 0}, dy[5] = {0, 0, 1, -1};

int DP(int i, int j) {
	if (i <= 0 || i > n || j <= 0 || j > n) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	
	int res = 1;
	for (int t = 0; t < 4; t++) {
		int x = dx[t] + i;
		int y = dy[t] + j;
		if (map[x][y] > map[i][j]) res = max(res, DP(x, y) + 1);
	}
	
	dp[i][j] = res;
	return dp[i][j];
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	int res = -1;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res = max(res, DP(i, j));
		}
	}
	printf("%d\n", res);
	return 0;
}
