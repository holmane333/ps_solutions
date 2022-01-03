#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int data[5001], dp[5001][5001];

int DP(int x, int y) {
	if (x >= y) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	
	if (data[x] == data[y]) dp[x][y] = DP(x + 1, y - 1);
	else dp[x][y] = min(DP(x + 1, y) + 1, DP(x, y - 1) + 1);
	return dp[x][y];
}

int main() {
	memset(dp, -1, sizeof(dp));
	memset(data, 0, sizeof(data));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	
	printf("%d\n", DP(0, n - 1));
	return 0;
}