#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int dp[1000001];
int data[1000001];
int max(int a, int b) {
	return a > b ? a : b;
}

int DP(int n) {
	if (n <= 0) return 0;
	if (dp[n] != -1) return dp[n];
	dp[n] = max(DP(n - 2) + data[n], max(DP(n - 3) + data[n - 1] + data[n], DP(n - 1)));
	return dp[n];
}

int main() {
	int n,max=-1001;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
	}
	memset(dp, -1, sizeof(dp));
	dp[1] = data[1];
	DP(n);
	for (int i = 1; i <= n; i++) {
		if (max < dp[i]) max = dp[i];
	}

	printf("%d\n", max);
	return 0;
}