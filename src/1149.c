#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int data[1001][4] = { 0, };
int dp[1001][4] = { 0, };

int DP(int n, int i) {
	if (n == 1) {
		dp[1][i] = dp[0][(i + 1) % 3] < dp[0][(i + 2) % 3] ? dp[0][(i + 1) % 3] + data[1][i] : dp[0][(i + 2) % 3] + data[1][i];
		return dp[1][i];
	}
	if (dp[n][i] >= 0) return dp[n][i];

	if (DP(n - 1, (i + 1) % 3) < DP(n - 1, (i + 2) % 3)) {
		dp[n][i] = DP(n - 1, (i + 1) % 3) + data[n][i];
		return dp[n][i];
	}
	else {
		dp[n][i] = DP(n - 1, (i + 2) % 3) + data[n][i];
		return dp[n][i];
	}
}
int ma(int a, int b) {
	return a < b ? a : b;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3;j++) {
			scanf("%d", &data[i][j]);
		}
	}
	if (n == 1) {
		printf("%d", ma(data[0][0], ma(data[0][1], data[0][2])));
	}
	else {
		dp[0][0] = data[0][0];
		dp[0][1] = data[0][1];
		dp[0][2] = data[0][2];
		for (int i = 0; i < 3; i++) {
			DP(n-1, i);
		}
		int min = 999999999;
		for (int i = 0; i < 3; i++) {
			if (min > dp[n - 1][i]) min = dp[n - 1][i];
		}
		printf("%d\n", min);
	}

	return 0;
}