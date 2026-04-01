#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)

int coin, dp[10001] = { 0, };


int main() {
	int n, m;
	dp[0] = 1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin);
		for (int j = 0; j <= m; j++) {
			if (j >= coin) {
				dp[j] += dp[j - coin];
			}
		}
	}

	printf("%d\n", dp[m]);

	return 0;
}