#include <stdio.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

char data[1002][1002];
int dp[1002][1002], n, m, max = 0;

int min1(int a, int b, int c) {
	return a > b ? b > c ? c : b : a > c ? c : a;
}
int max1(int a, int b) {
	return a > b ? a : b;
}

int main() {
	memset(data, 0, sizeof(data));
	scanf("%d %d", &n,&m);
	
	for (int i = 1; i <= n; i++) {
		scanf("%s", data[i]+1);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = (int)data[i][j] - 48;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] == 0) continue;
			dp[i][j] = min1(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1;
			max = max1(max, dp[i][j]);
		}
	}
	printf("%d\n", max * max);


	return 0;
}