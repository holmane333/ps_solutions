#include <stdio.h>
#pragma warning(disable:4996)

int dp[12] = { 0, };

int main() {
	for (int i = 0; i < 10; i++) {
		dp[i] = 1;
	}
	int n, count = 0;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) continue;
			dp[j] += dp[j - 1] % 10007;
			dp[j] %= 10007;
		}
	}
	int total = 0;
	for (int i = 0; i < 10; i++) {
		total += dp[i]%10007;
		total %= 10007;
	}
	printf("%d\n", total);
	return 0;
}