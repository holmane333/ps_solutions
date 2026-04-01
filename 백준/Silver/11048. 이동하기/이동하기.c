#include <stdio.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

int data[1002][1002];
int dp[1002][1002], n, m, max = 0;

int max1(int a, int b) {
	return a > b ? a : b;
}

int main() {
	memset(data, 0, sizeof(data));
	memset(dp, 0, sizeof(dp));
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &data[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max1(dp[i][j - 1], dp[i - 1][j]) + data[i][j];
		}
	}
	printf("%d\n",dp[n][m]);


	return 0;
}