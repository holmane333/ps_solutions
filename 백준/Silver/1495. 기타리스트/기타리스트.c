#include <stdio.h>

int main(void) {
	int n, s, m;
	int dp[100][1100] = {0, }, a;
	scanf("%d %d %d", &n, &s, &m);
	dp[0][s] = 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		for (int j = 0; j <= m; ++j) {
			if (!dp[i][j]) continue;
			if (j - a >= 0) dp[i + 1][j - a] = 1;
			if (j + a <= m) dp[i + 1][j + a] = 1;
		}
	}
	for (int i = m; i >= 0; --i) {
		if (dp[n][i]) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
