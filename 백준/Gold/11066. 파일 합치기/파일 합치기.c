#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

long long int data[501], dp[501][501], Sum[501];

long long int DP(int x, int y) {
	if (x >= y) return 0LL;
	if (dp[x][y] != -1) return dp[x][y];
	
	int res = INT_MAX;
	for (int i = x; i < y; i++) {
		res = min(res, DP(x, i) + DP(i + 1, y) + Sum[y] - Sum[x - 1]);
	}
	dp[x][y] = res;
	return res;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int test = 0; test < tc; test++) {
		memset(dp, -1, sizeof(dp));
		memset(data, 0, sizeof(data));
		memset(Sum, 0, sizeof(Sum));
		int n;
		scanf("%d", &n);
		int s = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &data[i]);
			s += data[i];
			Sum[i] = s;
		}
		
		printf("%lld\n", DP(0, n - 1));
	}
	return 0;
}