#include <stdio.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable:4996)

int dp[1000002] = { 0, };

int main() {
	int n, data;
	scanf("%d", &n);
	int max = 0, result;
	for (int i = 1; i < n+1; i++) {
		scanf("%d", &data);
		if (dp[data - 1] && dp[data] < dp[data - 1] + 1) dp[data] = dp[data - 1] + 1;
		else if (dp[data] < 1) dp[data] = 1;
		max = max > dp[data] ? max : dp[data];
	}
	printf("%d\n", n - max);
	return 0;
}
