#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

long long int data[501][2], dp[501][501];

long long int DP(int x, int y) {
	if (x >= y) return 0LL;
	if (dp[x][y] != -1) return dp[x][y];
	
	int res = INT_MAX;
	for (int i = x; i < y; i++) {
		res = min(res, DP(x, i) + DP(i + 1, y) + data[x][0] * data[i][1] * data[y][1]);
	}
	
	dp[x][y] = res;
	return res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &data[i][0], &data[i][1]);
	}
	
	printf("%lld\n", DP(0, n - 1));
	
	return 0;
}