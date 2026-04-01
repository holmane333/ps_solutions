#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, m, a[60][60], v[60][60], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int dp[60][60];

int dfs(int x, int y) {
	//printf(" %d %d\n", x, y);
	if (a[x][y] == -1) return 0;
	if (v[x][y]) {
		dp[x][y] = 1e9;
		//printf("%d %d\n", x, y);
		return dp[x][y];
	}
	if (dp[x][y] != -1) return dp[x][y];
	//printf(" %d %d\n", x, y);
	++v[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int cx = x + dx[i] * a[x][y];
		int cy = y + dy[i] * a[x][y];
		if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
		//printf("%d %d %d %d %d\n", x, y, cx, cy, v[cx][cy]);
		dp[x][y] = max(dp[x][y], dfs(cx, cy) + 1);
	}
	--v[x][y];
	return dp[x][y];
}

int main(void) {
	char s[60];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", &s);
		for (int j = 1; j <= m; ++j) {
			if (s[j - 1] == 'H') a[i][j] = -1;
			else a[i][j] = (int)(s[j - 1] - '0');
		}
	}
	memset(dp, -1, sizeof(dp));
	//printf("%d\n", dfs(1, 1));
	if (dfs(1, 1) >= 1e9) puts("-1");
	else printf("%d\n", dp[1][1]);
	return 0;
}
