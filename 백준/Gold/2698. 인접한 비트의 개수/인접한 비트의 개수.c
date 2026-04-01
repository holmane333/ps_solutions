#include <stdio.h>
#pragma warning(disable:4996)

int dp[101][101][2];

void DP() {
	dp[1][0][1] = 1;
	dp[1][0][0] = 1;
	
	for (int i = 0; i <= 100; i++) {
		for (int j = 2; j <= 100; j++) {
			if (i == 0) dp[j][i][1] += dp[j - 1][i][0];
			else dp[j][i][1] += dp[j - 1][i][0] + dp[j - 1][i - 1][1];
			dp[j][i][0] += dp[j - 1][i][0] + dp[j - 1][i][1];
		}
	}
}

int main(void) {
	int tc, n, k;
	scanf("%d", &tc);
	DP();
	for (int test = 0; test < tc; test++) {
		scanf("%d %d", &n, &k);
		printf("%d\n", dp[n][k][0] + dp[n][k][1]);
	}
	
	return 0;
}
