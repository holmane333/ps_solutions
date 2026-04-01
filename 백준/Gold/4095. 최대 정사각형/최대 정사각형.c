#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, map[1010][1010], dp[1010][1010], res;

int main(void) {
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &map[i][j]);
			}
		}
		res = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (map[i][j]) dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				res = max(res, dp[i][j]);
			}
		}
		printf("%d\n", res);
	}
	
	
	
	
	return 0;
}
