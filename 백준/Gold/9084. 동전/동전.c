#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int tc, n, res, dp[10001];
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		memset(dp, 0, sizeof(dp));
		int coin[21];
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &coin[i]);
		}
		scanf("%d", &res);

		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= res; j++) {
				if (dp[j] && coin[i] + j <= 10000) dp[j + coin[i]] += dp[j];
			}
		}
		printf("%d\n", dp[res]);
	}
	return 0;
}
