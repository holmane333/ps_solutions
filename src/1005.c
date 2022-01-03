#include <stdio.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, k, data[1001], dir[1001][1001], dp[1001];

int DP(int w) {
	if (dp[w] != -1) return dp[w];
	dp[w] = 0;
	for (int i = 1; i <= n; i++) {
		if (dir[i][w] == 1) {
			int ans = DP(i);
			dp[w] = dp[w] > ans ? dp[w] : ans;
		}
	}
	dp[w] += data[w];
	return dp[w];
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	for (int test = 0; test < tc; test++) {
		scanf("%d %d", &n, &k);
		memset(dp, -1, sizeof(dp));
		memset(data, 0, sizeof(data));
		memset(dir, 0, sizeof(dir));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &data[i]);
		}
		int a, b;
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);
			dir[a][b] = 1;
		}
		int w;
		
		scanf("%d", &w);
		printf("%d\n", DP(w));
	}
	
	return 0;
}
