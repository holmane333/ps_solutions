#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int tc = 3, n, res, dp[100010];
	for (int t = 0; t < tc; t++) {
		memset(dp, 0, sizeof(dp));
		int coin[101][3], m = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &coin[i][0], &coin[i][1]);
			m += coin[i][0] * coin[i][1];
		}
		if (m & 1) {
			puts("0");
			continue;
		}
		
		m /= 2;
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = m; j >= 0; --j) {
				if (dp[j]) {
					for (int k = 1; k <= coin[i][1]; ++k) {
						if (j + coin[i][0] * k <= m) dp[j + coin[i][0] * k] = 1;
					}
				}
			}
		}
		/*for (int i = 0; i <= 100000; ++i) {
			if (dp[i]) printf("%d ", i);
		}puts("");*/
		printf("%d\n", dp[m]);
	}
	return 0;
}
