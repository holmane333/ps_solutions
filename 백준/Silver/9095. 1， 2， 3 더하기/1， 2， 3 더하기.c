#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int dp[1000001];

int min(int a, int b) {
	return a < b ? a : b;
}

int DP(int n) {
	if (n <= 0) return 0;
	if (dp[n] != -1) return dp[n];
	dp[n] = DP(n - 1) + DP(n - 2) + DP(n - 3);
	return dp[n];
}

int main() {
	int testcase,n;
	scanf("%d", &testcase);
	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 0; i < testcase; i++) {
		scanf("%d", &n);
		printf("%d\n", DP(n));
	}

	return 0;
}