#include <stdio.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable:4996)

int dp[1002][3][5] = { 0, };
int modulo = 1000000;

int main() {
	int n;
	scanf("%d", &n);
	
	dp[1][0][0] = 1;
	dp[1][1][0] = 1;
	dp[1][0][1] = 1;
	
	for (int i = 2; i <= n; i++) {
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % modulo;
		dp[i][0][1] = (dp[i - 1][0][0]) % modulo;
		dp[i][0][2] = (dp[i - 1][0][1]) % modulo;
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % modulo;
		dp[i][1][1] = (dp[i - 1][1][0]) % modulo;
		dp[i][1][2] = (dp[i - 1][1][1]) % modulo;
	}
	printf("%d\n", (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % modulo);
	return 0;
}
