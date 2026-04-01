#include <stdio.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable:4996)

int dp[1002] = { 0, };
int data[1002];

int DP(int n) {
	int result = 1, x = data[n];

	for (int i = 1; i < n+1; i++) {
		if ((x > data[i]) && (result <= dp[i])) {
			result = dp[i] + 1;
		}
	}
	dp[n] = result;
	return result;
}

int main() {
	int n;
	memset(data, -1, sizeof(data));
	scanf("%d", &n);
	for (int i = 1; i < n+1; i++) {
		scanf("%d", &data[i]);
	}
	int max=0,result;
	for (int i = 1; i < n+1; i++) {
		result = DP(i);
		if (max < result) max = result;
	}
	printf("%d", max);
	return 0;
}
