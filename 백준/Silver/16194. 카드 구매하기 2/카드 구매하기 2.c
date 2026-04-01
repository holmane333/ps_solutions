#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int price[1001];
int dp[1001];

int DP(int n) {
	if (n == 0) return dp[0];
	if (dp[n] != -1) return dp[n];
	dp[n] = price[n];
	for (int i = 0; i < (n / 2 + n % 2); i++) {
		if ((DP(n - i - 1) + DP(i)) < dp[n]) dp[n] = DP(n - i - 1) + DP(i);
	}
	return dp[n];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &price[i]);
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = price[0];
	printf("%d\n", DP(n - 1));
	/*
	for (int i = 0; i < n; i++) {
		printf("%d ", dp[i]);
	}puts("");
	for (int i = 0; i < n; i++) {
		printf("%d ", price[i]);
	}puts("");*/
	return 0;
}
