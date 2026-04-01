#include <stdio.h>

int n, m, t;
int map[1010][1010], dp[1010][1010];

void dfs(int x, int y) {
	if (x >= n || y >= m) {
		printf("%d %d\n", x + 1, y + 1);
		return;
	}
	if (map[x][y]) dfs(x, y + 1);
	else dfs(x + 1, y);
}

int main(void) {
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	
	dp[0][0] = t - 1;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i + 1][j] += dp[i][j] / 2;
			dp[i][j + 1] += dp[i][j] / 2;
			if (map[i][j] == 0) dp[i + 1][j] += dp[i][j] % 2;
			else dp[i][j + 1] += dp[i][j] % 2;
			
			map[i][j] = (map[i][j] + dp[i][j]) % 2;
		}
	}
	
	dfs(0, 0);
	
	return 0;
}
