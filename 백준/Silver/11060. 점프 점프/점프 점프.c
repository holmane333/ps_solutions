#include <stdio.h>
#define min(x, y) ((x) > (y) ? (y) : (x))
#pragma warning(disable:4996)

int main(void) {
	int n, DP[1110] = {0, }, a;
	scanf("%d", &n);
	DP[0] = 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if (DP[i]) {
			for (int j = 1; j <= a; ++j) {
				DP[i + j] = min(DP[i + j], DP[i] + 1);
				if (!DP[i + j]) DP[i + j] = DP[i] + 1;
			}
		}
	}
	
	printf("%d\n", DP[n - 1] - 1);
	
	return 0;
}
