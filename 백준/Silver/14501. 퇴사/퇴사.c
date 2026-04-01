#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

int data[16][2], dp[16];

int DP(int n,int k) {
	if ((n > k)||(n<=0)) return 0;
	if (dp[n] != -1) return dp[n];
	if (n + data[n][0]-1 <= k) dp[n] = DP(n + data[n][0], k) + data[n][1] > DP(n + 1, k) ? DP(n + data[n][0], k) + data[n][1] : DP(n + 1, k);
	else dp[n] = DP(n + 1, k);
	return DP(n-1,k);
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &data[i][0], &data[i][1]);
	}

	DP(n,n);
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[i]) max = dp[i];
	}
	printf("%d\n", max);
	return 0;
}