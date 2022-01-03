#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int dp[1001], data[1001];
int n, max;

int DP(int m) {
	if (m == n) return 0;
	dp[m] = 1;
	for (int i = m; i >= 0; i--) {
		if (data[i] < data[m] && dp[i] + 1 > dp[m]) {
			dp[m] = dp[i] + 1;
		}
	}
	max = max < dp[m] ? dp[m] : max;
	return DP(m + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	DP(0);
	printf("%d\n", max);
	return 0;
}