#include <stdio.h>
#pragma warning(disable:4996)

int w, n, ary[5001], dp[800001];

int main(void) {
	scanf("%d %d", &w, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < n; i++) {
		if (ary[i] >= w) continue;
		for (int j = i + 1; j < n; j++) {
			if (ary[i] + ary[j] > w) continue;
			//printf("%d %d %d %d\n", ary[i], ary[j], w - ary[i] - ary[j], dp[w - ary[i] - ary[j]]);
			if (dp[w - ary[i] - ary[j]] == 1) {
				printf("YES\n");
				return 0;
			}
		}
		for (int j = 0; j < i; j++) {
			if (ary[i] + ary[j] < w) dp[ary[i] + ary[j]] = 1;
		}
	}
	printf("NO\n");
	return 0;
}
