#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int data[501][501] = { 0, };
int dp[501][501] = { 0, };

int DP(int n, int i) {
	if (n == 0) return dp[0][0];
	if (dp[n][i] >= 0) return dp[n][i];
	if (i == 0) {
		dp[n][0] = DP(n-1,0) + data[n][0];
		return dp[n][0];
	}
	if (i == n) {
		dp[n][i] = DP(n-1,i-1) + data[n][i];
		return dp[n][i];
	}
	if (DP(n - 1, i-1) > DP(n - 1, i)) {
		dp[n][i] = DP(n - 1, i-1) + data[n][i];
		return dp[n][i];
	}
	else {
		dp[n][i] = DP(n - 1, i) + data[n][i];
		return dp[n][i];
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1;j++) {
			scanf("%d", &data[i][j]);
		}
	}
	if (n == 1) {
		printf("%d",data[0][0]);
	}
	else if (n == 2) {
		printf("%d", data[0][0] + data[1][0] > data[0][0] + data[1][1]?data[0][0] + data[1][0] : data[0][0] + data[1][1]);
	}
	else {
		dp[0][0] = data[0][0];
		for (int i = 0; i < n; i++) {
			DP(n-1, i);
		}
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (max < dp[n - 1][i]) max = dp[n - 1][i];
		}
		printf("%d\n", max);
		
	}
	return 0;
}