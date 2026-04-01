#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int data[102][2], dp[101][100003] = { 0, }, N, w;

int DP(int n, int k) {
	if (n <= 0) return 0;
	if (dp[n][k] != -1) return dp[n][k];
	if (k < data[n][0]) dp[n][k] = DP(n - 1, k);
	else dp[n][k] = max(DP(n - 1, k), DP(n - 1, k - data[n][0]) + data[n][1]);
	
	return dp[n][k];
}

int main() {
	scanf("%d %d", &N, &w);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &data[i][0],&data[i][1]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", DP(N, w));
	return 0;
}