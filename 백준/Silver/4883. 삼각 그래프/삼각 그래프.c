#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int map[100001][4], dp[100001][4];

int DP(int n, int r) {
	if (dp[n][r] != INT_MAX) return dp[n][r];
	switch (r)
	{
	case 0:
		dp[n][r] = min(DP(n - 1, 0), DP(n - 1, 1)) + map[n][r];
		break;
	case 1:
		dp[n][r] = min(DP(n, 0), min(DP(n - 1, 0), min(DP(n - 1, 1), DP(n - 1, 2)))) + map[n][r];
		break;
	case 2:
		dp[n][r] = min(DP(n, 1), min(DP(n - 1, 1), DP(n - 1, 2))) + map[n][r];
	}
	return dp[n][r];
}

int main() {
	int n, cnt = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
			for (int j = 0; j < 3; j++) {
				dp[i][j] = INT_MAX;
			}
		}
		dp[0][0] = map[0][1];
		dp[0][1] = map[0][1];
		dp[0][2] = map[0][1] + map[0][2];

		printf("%d. %d\n", cnt, DP(n - 1, 1));
		cnt++;
	}

	return 0;
}
