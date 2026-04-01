#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long long int dp[100][10];

int DP(int n,int i) {
	if (i>n) return 0;
	dp[i][0] = dp[i - 1][1];
	dp[i][9] = dp[i - 1][8];
	for (int j = 1; j < 9; j++) {
		dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
	}
	return DP(n, i + 1);
}

int main() {
	int n;
	scanf("%d", &n);
	n--;
	dp[0][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[0][i] = 1;
	}
	DP(n, 1);
	long long int count = 0;
	for (int i = 0; i < 10; i++) {
		count = (count + dp[n][i]) % 1000000000;
	}
	printf("%lld\n", count);
	return 0;
}