#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

long long int n, m, dp[1002][1002];

long long int DP(long long int y, long long int x) {
	if (y < 1 || y > n || x < 1 || x > m) return 0;
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = (DP(y - 1, x) + DP(y - 1, x - 1) + DP(y, x - 1)) % 1000000007LL;
	return dp[y][x];
}

int main() {
	scanf("%lld %lld", &n, &m);
	memset(dp, -1, sizeof(dp));
	dp[1][1] = 1LL;
	printf("%lld\n", DP(n, m));
	return 0;
}
