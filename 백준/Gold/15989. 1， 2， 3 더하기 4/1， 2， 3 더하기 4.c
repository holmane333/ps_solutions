#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, dp[10004][4];

int main() {
	int tc;
	scanf("%d", &tc);
	memset(dp, 0, sizeof(dp));

	dp[1][0] = 1;

	dp[2][0] = 1;
	dp[2][1] = 1;
	
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;

	for (int i = 4; i < 10001; i++) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}

	for (int t = 0; t < tc; t++) {
		scanf("%d", &n);
		printf("%d\n", dp[n][0] + dp[n][1] + dp[n][2]);
	}
	

	return 0;
}
