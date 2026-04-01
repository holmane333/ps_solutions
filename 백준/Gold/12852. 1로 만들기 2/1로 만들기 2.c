#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))
int dp[1000001], before[1000001];

int DP(int n) {
	if (n <= 1)return 0;
	if (dp[n] != -1) return dp[n];
	if (!(n % 2) && !(n % 3)) {
		dp[n] = min(DP(n - 1) + 1, min(DP(n / 2) + 1, DP(n / 3) + 1));
		if (dp[n] == DP(n - 1) + 1) before[n] = n - 1;
		else if (dp[n] == DP(n / 2) + 1) before[n] = n / 2;
		else before[n] = n / 3;
	}
	else if (!(n % 2)) {
		dp[n] = min(DP(n - 1) + 1, DP(n / 2) + 1);
		if (dp[n] == DP(n - 1) + 1) before[n] = n - 1;
		else before[n] = n / 2;
	}
	else if (!(n % 3)) {
		dp[n] = min(DP(n - 1) + 1, DP(n / 3) + 1);
		if (dp[n] == DP(n - 1) + 1) before[n] = n - 1;
		else before[n] = n / 3;
	}
	else {
		dp[n] = DP(n - 1) + 1;
		before[n] = n - 1;
	}
	
	return dp[n];
}

int main() {
	int n;
	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	memset(before, 0, sizeof(before));
	before[2] = 1;
	before[3] = 1;

	printf("%d\n", DP(n));
	while (n) {
		printf("%d ", n);
		n = before[n];
	}

	return 0;
}
